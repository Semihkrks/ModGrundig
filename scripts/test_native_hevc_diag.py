"""Bounded execution of the actual diagnostic veneer; all services mocked."""
import json
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn import mips_const as m
import native_hevc_diag as p

MON, INFO, ERR, STACK, STUB = 0x10000000, 0x10001000, 0x10002000, 0x12008000, 0x11000000
POISON = 0xdedd0123
REG = {i: getattr(m, f'UC_MIPS_REG_{i}') for i in range(32)}


class Harness:
    def __init__(self, raw, *, bias=0, rc=1, codec=7, mode=0, fd=8,
                 stat_result=0, file_mode=0x1180, snprintf_result=None,
                 write_result=None, proc_format_result=None, initial_errno=63,
                 path_mode=0x1180, path_stat_result=0, path_uid=0, fd_uid=0):
        self.u = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.bias, self.rc, self.codec, self.mode = bias, rc, codec, mode
        self.fd, self.stat_result, self.file_mode = fd, stat_result, file_mode
        self.snprintf_result, self.write_result = snprintf_result, write_result
        self.proc_format_result, self.initial_errno = proc_format_result, initial_errno
        self.path_mode, self.path_stat_result = path_mode, path_stat_result
        self.path_uid, self.fd_uid = path_uid, fd_uid
        self.calls, self.lines, self.visited = [], [], []
        ph, = struct.unpack_from('<I', raw, 28)
        es, count = struct.unpack_from('<HH', raw, 42)
        for index in range(count):
            typ, offset, va, _, file_size, memory_size, *_ = struct.unpack_from('<8I', raw, ph+es*index)
            if typ == 1:
                low = (va+bias) & ~0xfff
                high = (va+bias+memory_size+0xfff) & ~0xfff
                self.u.mem_map(low, high-low)
                self.u.mem_write(va+bias, raw[offset:offset+file_size])
        for start in [MON, STACK & ~0xffff, STUB]:
            self.u.mem_map(start, 0x10000)
        self.u.mem_write(MON+0x138, struct.pack('<I', MON+0x4000))
        self.u.mem_write(MON+0x68, struct.pack('<I', 0x23))
        self.u.mem_write(INFO, struct.pack('<II', codec, 6))
        for offset, value in [(0x10, 411), (0x12, 412), (0x1e, 413)]:
            self.u.mem_write(INFO+offset, struct.pack('<H', value))
        self.u.mem_write(INFO+0x26, bytes([mode]))
        self.u.mem_write(ERR, struct.pack('<I', initial_errno))
        self.mon_before = bytes(self.u.mem_read(MON, 0x2000))
        self.saved = {getattr(m, f'UC_MIPS_REG_S{i}'): 0xcafe0000+i for i in range(8)}
        self.saved[m.UC_MIPS_REG_FP] = 0xbeef0022
        self.saved[m.UC_MIPS_REG_S3] = MON
        self.saved[m.UC_MIPS_REG_S4] = INFO
        for reg, value in self.saved.items():
            self.u.reg_write(reg, value)
        self.u.reg_write(m.UC_MIPS_REG_SP, STACK)
        self.u.reg_write(m.UC_MIPS_REG_GP, p.GP_CANON+bias)
        self.u.reg_write(m.UC_MIPS_REG_A2, mode)
        self.u.reg_write(m.UC_MIPS_REG_RA, 0x13570000)
        self.u.reg_write(m.UC_MIPS_REG_HI, 0x77889900)
        self.u.reg_write(m.UC_MIPS_REG_LO, 0xaabbccdd)
        self.stub_names = {}
        for index, (name, delta) in enumerate(p.GOT.items()):
            address = STUB+index*0x100
            self.stub_names[address] = name
            self.u.mem_write(p.GP_CANON+bias+delta, struct.pack('<I', address))
        self.u.hook_add(UC_HOOK_CODE, self.hook)
        self.u.hook_add(UC_HOOK_MEM_WRITE, self.write_hook)

    def cstring(self, address, limit=256):
        data = bytes(self.u.mem_read(address, limit))
        assert b'\0' in data
        return data.split(b'\0', 1)[0]

    def write_hook(self, u, access, address, size, value, data):
        if not (STACK-p.FRAME <= address and address+size <= STACK) and not (ERR <= address and address+size <= ERR+4):
            raise AssertionError(f'Unexpected native write {address:x}/{size}')

    def hook(self, u, address, size, data):
        self.visited.append(address)
        assert len(self.visited) < 1500
        if address in self.stub_names:
            name = self.stub_names[address]
            args = [u.reg_read(getattr(m, f'UC_MIPS_REG_A{i}')) for i in range(4)]
            self.calls.append(name)
            ra = u.reg_read(m.UC_MIPS_REG_RA)
            if name == 'set_type':
                assert args[:3] == [MON+0x4000, self.codec, self.mode]
                result = self.rc
            elif name == 'errno':
                result = ERR
            elif name == 'open':
                assert self.cstring(args[0]) == p.PATH[:-1]
                assert args[1] == p.OPEN_FLAGS
                result = self.fd
                u.mem_write(ERR, struct.pack('<I', 2))
            elif name == 'lxstat64':
                assert args[0] == 3 and self.cstring(args[1]) == p.PATH[:-1]
                u.mem_write(args[2], bytes(0xa0))
                u.mem_write(args[2]+0x18, struct.pack('<I', self.path_mode))
                u.mem_write(args[2]+0x20, struct.pack('<I', self.path_uid))
                result = self.path_stat_result
                u.mem_write(ERR, struct.pack('<I', 2))
            elif name == 'snprintf':
                fmt = self.cstring(args[2])
                if fmt == p.FD_FMT[:-1]:
                    assert args[1] == 64 and args[3] == self.fd
                    line = f'/proc/self/fd/{self.fd}'.encode()
                    result = len(line) if self.proc_format_result is None else self.proc_format_result
                else:
                    assert fmt == p.FMT[:-1] and args[1] == p.MAX_LINE
                    extra = struct.unpack('<7I', u.mem_read(u.reg_read(m.UC_MIPS_REG_SP)+0x10, 28))
                    values = [args[3], *extra]
                    assert values == [self.rc, self.codec, 6, 411, 412, 413, self.mode, 0x23]
                    line = ('MGDIAG 1 '+' '.join(str(x) for x in values)+'\n').encode()
                    result = len(line) if self.snprintf_result is None else self.snprintf_result
                u.mem_write(args[0], line[:args[1]-1]+b'\0')
            elif name == 'xstat':
                assert args[0] == 3
                assert self.cstring(args[1]) == f'/proc/self/fd/{self.fd}'.encode()
                u.mem_write(args[2], bytes(0x90))
                u.mem_write(args[2]+0x14, struct.pack('<I', self.file_mode))
                u.mem_write(args[2]+0x1c, struct.pack('<I', self.fd_uid))
                result = self.stat_result
                u.mem_write(ERR, struct.pack('<I', 5))
            elif name == 'write':
                assert args[0] == self.fd and 0 < args[2] < p.MAX_LINE
                line = bytes(u.mem_read(args[1], args[2]))
                assert line.startswith(b'MGDIAG 1 ') and line.endswith(b'\n')
                self.lines.append(line.decode())
                result = len(line) if self.write_result is None else self.write_result
                u.mem_write(ERR, struct.pack('<I', 11))
            elif name == 'close':
                assert args[0] == self.fd
                result = 0
                u.mem_write(ERR, struct.pack('<I', 4))
            else:
                raise AssertionError(name)
            for register in p.VOLATILE:
                u.reg_write(REG[register], POISON)
            u.reg_write(m.UC_MIPS_REG_GP, POISON)
            u.reg_write(m.UC_MIPS_REG_HI, POISON)
            u.reg_write(m.UC_MIPS_REG_LO, POISON)
            u.reg_write(m.UC_MIPS_REG_V0, result & 0xffffffff)
            u.reg_write(m.UC_MIPS_REG_PC, ra)
            return
        native = address-self.bias
        if not (p.ENTRY <= native < p.CONTINUE or p.HELPER <= native < p.HELPER+len(p.helper_code())):
            raise AssertionError(f'Unexpected execution {address:x}')

    def run(self):
        self.u.emu_start(p.ENTRY+self.bias, p.CONTINUE+self.bias, count=1500)
        assert self.u.reg_read(m.UC_MIPS_REG_PC) == p.CONTINUE+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_SP) == STACK
        assert self.u.reg_read(m.UC_MIPS_REG_GP) == p.GP_CANON+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_RA) == p.CONTINUE+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_V0) == self.rc & 0xffffffff
        for register in p.VOLATILE:
            if register != p.V0:
                assert self.u.reg_read(REG[register]) == POISON, register
        assert self.u.reg_read(m.UC_MIPS_REG_HI) == POISON
        assert self.u.reg_read(m.UC_MIPS_REG_LO) == POISON
        for register, value in self.saved.items():
            assert self.u.reg_read(register) == (0 if register == m.UC_MIPS_REG_S7 else value), register
        assert bytes(self.u.mem_read(MON, 0x2000)) == self.mon_before
        assert struct.unpack('<I', self.u.mem_read(ERR, 4))[0] == self.initial_errno
        return dict(calls=self.calls, lines=self.lines, preserved_ABI=True, preserved_monitor_and_info=True,
                    source_return=self.rc & 0xffffffff, executed_instruction_count=len(self.visited))


class NativeDiagnosticTests(unittest.TestCase):
    cases = []

    @classmethod
    def setUpClass(cls):
        cls.original = p.SOURCE.read_bytes()
        cls.raw, cls.proof = p.apply(cls.original)

    def case(self, label, **kwargs):
        result = Harness(self.raw, **kwargs).run()
        self.cases.append(dict(label=label, inputs=kwargs, result=result))
        return result

    def test_success_and_failure_results_preserved_at_two_biases(self):
        for bias in [0, 0x01000000]:
            for rc in [0, 1, 0xffffffff]:
                for mode in [0, 1]:
                    result = self.case('return_bias_mode', bias=bias, rc=rc, mode=mode)
                    self.assertEqual(len(result['lines']), 1)
                    self.assertEqual(result['calls'], ['set_type', 'errno', 'lxstat64', 'open', 'snprintf', 'xstat', 'snprintf', 'write', 'close'])

    def test_normal_HD_baseline_and_fd_zero(self):
        result = self.case('HD_fd0', codec=2, fd=0)
        self.assertTrue(result['lines'][0].startswith('MGDIAG 1 1 2 '))

    def test_absent_fifo_symlink_denied_open_is_no_op(self):
        for fd in [-1, -13]:
            result = self.case('open_error', fd=fd)
            self.assertEqual(result['calls'], ['set_type', 'errno', 'lxstat64', 'open'])
            self.assertEqual(result['lines'], [])

    def test_regular_files_devices_and_stat_failure_never_written(self):
        for mode in [0x8180, 0xa1ff, 0x2180, 0xc180, 0]:
            result = self.case('wrong_path_type', path_mode=mode)
            self.assertNotIn('open', result['calls'])
            self.assertNotIn('write', result['calls'])
            result = self.case('wrong_file_type', file_mode=mode)
            self.assertNotIn('write', result['calls'])
            self.assertEqual(result['calls'][-1], 'close')
        result = self.case('proc_or_stat_unavailable', stat_result=-1)
        self.assertNotIn('write', result['calls'])
        self.assertEqual(result['calls'][-1], 'close')
        result = self.case('missing_or_denied_path', path_stat_result=-1)
        self.assertNotIn('open', result['calls'])
        self.assertNotIn('write', result['calls'])

    def test_formatter_failures_are_closed_and_fd_closed(self):
        for value in [-1, 0, p.MAX_LINE, p.MAX_LINE+7]:
            result = self.case('bad_record_length', snprintf_result=value)
            self.assertNotIn('write', result['calls'])
            self.assertEqual(result['calls'][-1], 'close')
        for value in [-1, 0, 64]:
            result = self.case('bad_proc_length', proc_format_result=value)
            self.assertNotIn('xstat', result['calls'])
            self.assertNotIn('write', result['calls'])
            self.assertEqual(result['calls'][-1], 'close')

    def test_unsafe_owner_or_permissions_are_rejected(self):
        for uid in [1, 1000]:
            result = self.case('unsafe_path_owner', path_uid=uid)
            self.assertNotIn('open', result['calls'])
            result = self.case('unsafe_descriptor_owner', fd_uid=uid)
            self.assertNotIn('write', result['calls'])
            self.assertEqual(result['calls'][-1], 'close')
        for mode in [0x11a4, 0x11ff, 0x1980]:
            result = self.case('unsafe_path_permissions', path_mode=mode)
            self.assertNotIn('open', result['calls'])
            result = self.case('unsafe_descriptor_permissions', file_mode=mode)
            self.assertNotIn('write', result['calls'])
            self.assertEqual(result['calls'][-1], 'close')
    def test_full_fifo_and_partial_write_never_retry(self):
        for value in [-1, 0, 2]:
            result = self.case('drop_without_retry', write_result=value)
            self.assertEqual(result['calls'].count('write'), 1)
            self.assertEqual(result['calls'][-1], 'close')

    def test_source_identity_and_exact_mutation_boundary(self):
        self.assertEqual(len(self.raw), len(self.original))
        for raw in [b'', self.raw, self.original[:-1]]:
            with self.assertRaises(ValueError):
                p.apply(raw)
        sh, = struct.unpack_from('<I', self.original, 32)
        ss, sn = struct.unpack_from('<HH', self.original, 46)
        self.assertEqual(self.original[:52], self.raw[:52])
        self.assertEqual(self.original[sh:sh+ss*sn], self.raw[sh:sh+ss*sn])

    @classmethod
    def tearDownClass(cls):
        p.OUT.mkdir(parents=True, exist_ok=True)
        (p.OUT/'bounded-native-tests.json').write_text(json.dumps(dict(
            kind='Actual SDK-call veneer instructions; every external function mocked',
            candidate_sha256=p.sha(cls.raw), case_count=len(cls.cases), cases=cls.cases,
            physical_TV_executed=False, hardware_executed=False), indent=2)+'\n', encoding='utf-8')


if __name__ == '__main__':
    unittest.main()
