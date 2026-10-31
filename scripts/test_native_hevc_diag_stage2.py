"""Actual stage2 MIPS instructions, synthetic memory and mocked native services."""
import json
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn import mips_const as m
import native_hevc_diag_stage2 as p
import native_hevc_diag as old

MON, ERR, STACK, STUB = 0x10000000, 0x10008000, 0x12008000, 0x11000000
REG = {i: getattr(m, f'UC_MIPS_REG_{i}') for i in range(32)}
POISON = 0xdedd0123


class Harness:
    def __init__(self, raw, *, bias=0, frames=0, lock=1, audio=1, ready=0,
                 fd=8, path_mode=0x1180, fd_mode=0x1180, path_uid=0, fd_uid=0,
                 stat_result=0, path_result=0, write_result=None, length_override=None):
        self.u = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.bias, self.frames, self.lock, self.mon = bias, frames, lock, MON
        self.fd, self.path_mode, self.fd_mode = fd, path_mode, fd_mode
        self.path_uid, self.fd_uid, self.stat_result, self.path_result = path_uid, fd_uid, stat_result, path_result
        self.write_result, self.length_override = write_result, length_override
        self.calls, self.lines, self.samples, self.visited, self.now = [], [], [], [], 0
        ph, = struct.unpack_from('<I', raw, 28)
        es, count = struct.unpack_from('<HH', raw, 42)
        for idx in range(count):
            typ, offset, va, _, fs, ms, *_ = struct.unpack_from('<8I', raw, ph+es*idx)
            if typ == 1:
                low, high = (va+bias)&~0xfff, (va+bias+ms+0xfff)&~0xfff
                self.u.mem_map(low, high-low)
                self.u.mem_write(va+bias, raw[offset:offset+fs])
        for start in [MON, STACK&~0xffff, STUB]:
            self.u.mem_map(start, 0x10000)
        for offset, value in [(0xc, 0x1c), (0x1c8, 0), (0xa0, 7), (0xa4, 6),
                              (0x68, 3), (0x138, MON+0x4000)]:
            self.set32(offset, value)
        for offset, value in [(0xb0, 4855), (0xb2, 4955)]:
            self.set16(offset, value)
        for offset, value in [(0x110, 1), (0x111, audio), (0x92, ready), (0x6e, 0)]:
            self.set8(offset, value)
        self.u.mem_write(ERR, struct.pack('<I', 73))
        self.saved = {getattr(m, f'UC_MIPS_REG_S{i}'): 0xcafe0000+i for i in range(8)}
        self.saved[m.UC_MIPS_REG_FP] = 0xbeef0022
        self.saved[m.UC_MIPS_REG_S0] = self.mon
        self.stub_names = {}
        for index, (name, delta) in enumerate(p.GOT.items()):
            address = STUB+index*0x100
            self.stub_names[address] = name
            self.u.mem_write(p.GP_CANON+bias+delta, struct.pack('<I', address))
        self.u.hook_add(UC_HOOK_CODE, self.hook)
        self.u.hook_add(UC_HOOK_MEM_WRITE, self.write_hook)

    def set32(self, off, value):
        self.u.mem_write(self.mon+off, struct.pack('<I', value))

    def set16(self, off, value):
        self.u.mem_write(self.mon+off, struct.pack('<H', value))

    def set8(self, off, value):
        self.u.mem_write(self.mon+off, bytes([value]))

    def word(self, address):
        return struct.unpack('<I', self.u.mem_read(address, 4))[0]

    def byte(self, offset):
        return bytes(self.u.mem_read(self.mon+offset, 1))[0]

    def half(self, offset):
        return struct.unpack('<H', self.u.mem_read(self.mon+offset, 2))[0]

    def string(self, address):
        raw = bytes(self.u.mem_read(address, 256))
        assert b'\0' in raw
        return raw.split(b'\0', 1)[0]

    def write_hook(self, u, access, address, size, value, data):
        allowed = STACK-p.FRAME <= address and address+size <= STACK
        allowed |= ERR <= address and address+size <= ERR+4
        allowed |= p.KEY+self.bias <= address and address+size <= p.KEY+self.bias+12
        allowed |= p.CLOCK+self.bias <= address and address+size <= p.CLOCK+self.bias+8
        if not allowed:
            raise AssertionError(f'Unexpected native write {address:x}/{size}')

    def hook(self, u, address, size, data):
        if address == getattr(self, 'stop', None):
            u.emu_stop()
            return
        self.visited.append(address)
        assert len(self.visited) < 50000
        if address in self.stub_names:
            name = self.stub_names[address]
            args = [u.reg_read(REG[4+i]) for i in range(4)]
            self.calls.append(name)
            ret = u.reg_read(m.UC_MIPS_REG_RA)
            if name == 'checkpoint':
                assert args[0] == self.mon
                result = 0x12345678
            elif name == 'time':
                result = self.now
            elif name == 'frames':
                assert args[0] == self.word(self.mon+0x138)
                result = self.frames
            elif name == 'mad':
                assert args[0] == self.mon
                result = self.lock
            elif name == 'errno':
                result = ERR
            elif name in ['lxstat64', 'xstat']:
                assert args[0] == 3
                if name == 'lxstat64':
                    assert self.string(args[1]) == old.PATH[:-1]
                    mode, uid, off, result = self.path_mode, self.path_uid, 0x18, self.path_result
                else:
                    assert self.string(args[1]) == f'/proc/self/fd/{self.fd}'.encode()
                    mode, uid, off, result = self.fd_mode, self.fd_uid, 0x14, self.stat_result
                u.mem_write(args[2], bytes(0xa0))
                u.mem_write(args[2]+off, struct.pack('<I', mode))
                u.mem_write(args[2]+off+8, struct.pack('<I', uid))
                u.mem_write(ERR, struct.pack('<I', 5))
            elif name == 'open':
                assert self.string(args[0]) == old.PATH[:-1]
                assert args[1] == old.OPEN_FLAGS
                result = self.fd
                u.mem_write(ERR, struct.pack('<I', 2))
            elif name == 'snprintf':
                fmt = self.string(args[2])
                if fmt == old.FD_FMT[:-1]:
                    assert args[1] == 64 and args[3] == self.fd
                    text = f'/proc/self/fd/{self.fd}'.encode()
                    result = len(text)
                else:
                    assert fmt == p.FMT[:-1] and args[1] == old.MAX_LINE
                    fields = [args[3], *struct.unpack('<10I', u.mem_read(u.reg_read(m.UC_MIPS_REG_SP)+0x10, 40))]
                    assert fields[1:4] == [self.word(self.mon+0xa0), self.half(0xb0), self.half(0xb2)]
                    assert fields[6:] == [self.byte(0x92), self.byte(0x6e), self.word(self.mon+0x68), self.byte(0x110), self.byte(0x111)]
                    self.samples.append(fields)
                    text = ('MGDIAG 4 '+' '.join(str(v) for v in fields)+'\n').encode()
                    result = len(text) if self.length_override is None else self.length_override
                u.mem_write(args[0], text[:args[1]-1]+b'\0')
            elif name == 'write':
                assert args[0] == self.fd and 0 < args[2] < old.MAX_LINE
                line = bytes(u.mem_read(args[1], args[2])).decode()
                assert line.startswith('MGDIAG 4 ') and line.endswith('\n')
                self.lines.append(line)
                result = len(line) if self.write_result is None else self.write_result
                u.mem_write(ERR, struct.pack('<I', 11))
            elif name == 'close':
                assert args[0] == self.fd
                result = 0
                u.mem_write(ERR, struct.pack('<I', 4))
            else:
                raise AssertionError(name)
            for register in old.VOLATILE:
                u.reg_write(REG[register], POISON)
            u.reg_write(m.UC_MIPS_REG_GP, POISON)
            u.reg_write(m.UC_MIPS_REG_HI, POISON)
            u.reg_write(m.UC_MIPS_REG_LO, POISON)
            u.reg_write(m.UC_MIPS_REG_V0, result & 0xffffffff)
            u.reg_write(m.UC_MIPS_REG_PC, ret)
            return
        native = address-self.bias
        allowed = p.ENTRY <= native < p.ENTRY+20 or p.HELPER <= native < p.HELPER+len(p.helper_code())
        allowed |= native == p.ZERO_PATH
        if not allowed:
            raise AssertionError(f'Unexpected native execution {address:x}')

    def run_at(self, now):
        self.now = now & 0xffffffff
        before = bytes(self.u.mem_read(self.mon, 0x200))
        for register, value in self.saved.items():
            self.u.reg_write(register, value)
        self.u.reg_write(m.UC_MIPS_REG_S0, self.mon)
        self.u.reg_write(m.UC_MIPS_REG_SP, STACK)
        self.u.reg_write(m.UC_MIPS_REG_GP, p.GP_CANON+self.bias)
        self.u.reg_write(m.UC_MIPS_REG_RA, 0x13570000)
        self.u.mem_write(STACK+0x10, struct.pack('<I', p.GP_CANON+self.bias))
        stop = p.NONZERO_PATH if self.byte(0x92) else p.ZERO_PATH+4
        self.stop = stop+self.bias
        start_count = len(self.calls)
        self.u.emu_start(p.ENTRY+self.bias, 0x13000000, count=3000)
        assert self.u.reg_read(m.UC_MIPS_REG_PC) == stop+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_SP) == STACK
        assert self.u.reg_read(m.UC_MIPS_REG_GP) == p.GP_CANON+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_RA) == p.ORIGINAL_RA+self.bias
        assert self.u.reg_read(m.UC_MIPS_REG_V0) == self.byte(0x92)
        for register in old.VOLATILE:
            if register != p.V0:
                assert self.u.reg_read(REG[register]) == POISON, register
        for register, value in self.saved.items():
            assert self.u.reg_read(register) == (self.mon if register == m.UC_MIPS_REG_S0 else value)
        assert self.u.reg_read(m.UC_MIPS_REG_HI) == POISON
        assert self.u.reg_read(m.UC_MIPS_REG_LO) == POISON
        assert bytes(self.u.mem_read(self.mon, 0x200)) == before
        assert self.word(ERR) == 73
        return dict(now=self.now, calls=self.calls[start_count:], branch=hex(stop), state_stage=self.word(p.CLOCK+self.bias+4))


class SnapshotTests(unittest.TestCase):
    cases = []

    @classmethod
    def setUpClass(cls):
        cls.original = p.SOURCE.read_bytes()
        cls.raw, cls.proof = p.apply(cls.original)

    def record(self, label, harness, times):
        result = [harness.run_at(time) for time in times]
        self.cases.append(dict(label=label, results=result, samples=harness.samples[:], lines=harness.lines[:]))
        return result

    def test_three_thresholds_and_no_continuous_getters(self):
        h = Harness(self.raw, frames=25)
        self.record('thresholds', h, [100, 2099, 2100, 4099, 4100, 6100, 8100, 10000])
        self.assertEqual([v[0] for v in h.samples], [2000, 4000, 6000])
        self.assertEqual([v[4:6] for v in h.samples], [[25, 1]]*3)
        self.assertEqual(h.calls.count('frames'), 3)
        self.assertEqual(h.calls.count('mad'), 3)
        self.assertEqual(h.calls.count('checkpoint'), 8)

    def test_rebased_code_and_clock_rollover(self):
        for bias in [0, 0x01000000]:
            h = Harness(self.raw, bias=bias)
            first = 0xffffff00
            self.record('rollover_'+hex(bias), h, [first, first+1999, first+2000, first+4000, first+6000])
            self.assertEqual([s[0] for s in h.samples], [2000, 4000, 6000])

    def test_key_changes_each_reset_state(self):
        h = Harness(self.raw)
        self.record('initial_key', h, [0, 2000])
        for field, value in [('codec', 2), ('video_pid', 100), ('audio_pid', 200), ('monitor_pointer', MON+0x5000)]:
            if field == 'codec':
                h.set32(0xa0, value)
            elif field == 'video_pid':
                h.set16(0xb0, value)
            elif field == 'audio_pid':
                h.set16(0xb2, value)
            else:
                data = bytes(h.u.mem_read(h.mon, 0x200))
                h.mon = value
                h.u.mem_write(h.mon, data)
            before = len(h.samples)
            self.record('reset_'+field, h, [5000, 6999, 7000])
            self.assertEqual(len(h.samples), before+1)
            self.assertEqual(h.samples[-1][0], 2000)

    def test_main_live_guards_and_ready_branch(self):
        for offset, value in [(0xc, 0x25), (0x1c8, 1), (0x1be, 1)]:
            h = Harness(self.raw)
            h.set8(offset, value) if offset == 0x1be else h.set32(offset, value)
            self.record('guard_'+hex(offset), h, [0, 2000, 4000, 6000])
            self.assertEqual(h.samples, [])
            self.assertNotIn('time', h.calls)
        for audio in [0, 1]:
            for ready in [0, 1]:
                h = Harness(self.raw, audio=audio, ready=ready)
                self.record(f'branch_audio{audio}_ready{ready}', h, [0, 2000])
                self.assertEqual(h.samples[0][6], ready)
                self.assertEqual(h.samples[0][5], 1 if audio else 255)

    def test_unavailable_getters_are_explicit_sentinels(self):
        for field, value in [('decoder', 0), ('audio_pid', 0x1fff), ('audio_codec', 255)]:
            h = Harness(self.raw)
            if field == 'decoder':
                h.set32(0x138, value)
            elif field == 'audio_pid':
                h.set16(0xb2, value)
            else:
                h.set32(0xa4, value)
            self.record('unavailable_'+field, h, [0, 2000])
            if field == 'decoder':
                self.assertEqual(h.samples[0][4], 0xffffffff)
                self.assertNotIn('frames', h.calls)
            else:
                self.assertEqual(h.samples[0][5], 255)
                self.assertNotIn('mad', h.calls)

    def test_ready_video_audio_and_healthy_empty_frame_matrix(self):
        for ready in [0, 1]:
            for video in [0, 1]:
                for audio in [0, 1]:
                    for frames in [0, 32]:
                        h = Harness(self.raw, ready=ready, audio=audio, frames=frames)
                        h.set8(0x110, video)
                        h.set8(0x6e, 1)
                        self.record(f'matrix_ready{ready}_video{video}_audio{audio}_frames{frames}', h, [0, 2000])
                        self.assertEqual(h.samples[0][4], frames if video else 0xffffffff)
                        self.assertEqual(h.samples[0][5], 1 if audio else 255)
                        self.assertEqual(h.samples[0][6:], [ready, 1, 3, video, audio])
                        self.assertEqual(h.calls.count('frames'), video)
                        self.assertEqual(h.calls.count('mad'), audio)
        h = Harness(self.raw, lock=0)
        self.record('real_mocked_zero_lock_preserved', h, [0, 2000])
        self.assertEqual(h.samples[0][5], 0)

    def test_transport_failures_drop_without_retries_or_monitor_mutation(self):
        variants = [dict(fd=-1), dict(path_result=-1), dict(stat_result=-1),
                    dict(path_mode=0x8180), dict(fd_mode=0x8180), dict(path_uid=1000),
                    dict(fd_uid=1000), dict(write_result=-1), dict(write_result=2),
                    dict(length_override=-1), dict(length_override=192)]
        for kwargs in variants:
            h = Harness(self.raw, **kwargs)
            self.record('drop_'+str(kwargs), h, [0, 2000, 2001, 4000, 6000, 10000])
            self.assertEqual(h.calls.count('frames'), 3)
            self.assertLessEqual(h.calls.count('write'), 3)
            self.assertEqual(h.word(p.CLOCK+4), 3)

    def test_native_branch_and_register_contract_matches_original(self):
        for audio in [0, 1]:
            for ready in [0, 1]:
                stock = Harness(self.original, audio=audio, ready=ready)
                stock_result = stock.run_at(0)
                hooked = Harness(self.raw, audio=audio, ready=ready)
                result = hooked.run_at(0)
                self.assertEqual(stock_result['branch'], result['branch'])
                self.assertEqual(stock.calls, ['checkpoint'])
                self.cases.append(dict(label=f'original_branch_reference_audio{audio}_ready{ready}',
                                       results=[result], samples=[], lines=[], native_reference=stock_result))

    def test_exact_allowlist_and_old_init_hook_preserved(self):
        self.assertEqual(len(self.original), len(self.raw))
        off = p.va_offset(self.original, old.HELPER, old.LIMIT-old.HELPER)
        self.assertEqual(self.original[off:off+old.LIMIT-old.HELPER], self.raw[off:off+old.LIMIT-old.HELPER])
        for source in [b'', self.raw, self.original[:-1]]:
            with self.assertRaises(ValueError):
                p.apply(source)

    @classmethod
    def tearDownClass(cls):
        p.OUT.mkdir(parents=True, exist_ok=True)
        (p.OUT/'bounded-native-tests.json').write_text(json.dumps(dict(
            candidate_sha256=p.sha(cls.raw), scenarios=cls.cases,
            native_hook_invocations=sum(len(c['results']) for c in cls.cases),
            original_control_block_invocations=sum('native_reference' in c for c in cls.cases),
            external_services_mocked=True, hardware_executed=False,
            whole_firmware_executed=False), indent=2)+'\n', encoding='utf-8')


if __name__ == '__main__':
    unittest.main()
