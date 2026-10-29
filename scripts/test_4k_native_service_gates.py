"""Bounded original MIPS service gates with synthetic objects; no TV process runs.

The one virtual edge is explicitly wired to the independently resolved customer
vtable target. No dynamic loader, RF data, driver or external call is emulated.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE
from unicorn import mips_const as reg

FILES = {
    'customer': ('07_MSLIB/libmsrv_dvb_customer.so',
                 '67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761'),
    'dvb': ('07_MSLIB/libmsrv_dvb.so',
            '93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97'),
}
RETURN = 0x11000000
OBJ = 0x10000000
VTABLE = 0x10100000
DATA = 0x10102000
STACK = 0x12008000
RECORDS = []


def instance(kind, allowed):
    relative, expected = FILES[kind]
    elf = Elf32(ROOT / 'analiz/dosya-sistemleri-tam' / relative)
    if hashlib.sha256(elf.raw).hexdigest() != expected:
        raise ValueError('Original source hash mismatch')
    u = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
    phoff = struct.unpack_from('<I', elf.raw, 28)[0]
    width, count = struct.unpack_from('<HH', elf.raw, 42)
    for j in range(count):
        typ, off, va, _, fs, ms, _, _ = struct.unpack_from('<8I', elf.raw, phoff+j*width)
        if typ == 1:
            lo, hi = va & ~4095, (va+ms+4095) & ~4095
            u.mem_map(lo, hi-lo)
            u.mem_write(va, elf.raw[off:off+fs])
    u.mem_map(OBJ, 0x110000)
    u.mem_map(RETURN, 4096)
    u.mem_map(0x12000000, 0x10000)
    u.reg_write(reg.UC_MIPS_REG_SP, STACK)
    u.reg_write(reg.UC_MIPS_REG_RA, RETURN)
    seen = []

    def bounded(uc, address, size, _):
        if not any(start <= address < end for start, end in allowed):
            raise AssertionError(f'Unexpected code/external call at {address:#x}')
        seen.append(address)

    u.hook_add(UC_HOOK_CODE, bounded)
    return u, seen


def put32(u, address, value):
    u.mem_write(address, struct.pack('<I', value))


class ServiceGates(unittest.TestCase):
    def test_customer_gate_and_classifier(self):
        # Real gate plus classifier including case bodies outside short symbol size.
        cases = [(2, op, typ, result) for op in (0, 8)
                 for typ, result in ((1, (1, 3)), (0x19, (1, 1)), (0x1f, (1, 0)))]
        # A genuine operator condition is retained as a negative control.
        cases += [(1, 8, 0x1f, (7, 2)), (1, 8, 1, (1, 3))]
        for mode, operator, typ, expected in cases:
            with self.subTest(mode=mode, operator=operator, service_type=typ):
                u, seen = instance('customer', [(0x2e192540, 0x2e1926cc),
                                               (0x2e19784c, 0x2e197c40)])
                put32(u, OBJ, VTABLE)
                put32(u, VTABLE+0x2bc, 0x2e19784c)
                put32(u, OBJ+0x170, mode)
                put32(u, OBJ+0xd2d6c, operator)
                u.mem_write(DATA, b'\xcc\xcc')
                for r, val in ((reg.UC_MIPS_REG_A0, OBJ), (reg.UC_MIPS_REG_A1, DATA),
                               (reg.UC_MIPS_REG_A2, DATA+1), (reg.UC_MIPS_REG_A3, typ),
                               (reg.UC_MIPS_REG_T9, 0x2e192540)):
                    u.reg_write(r, val)
                u.emu_start(0x2e192540, RETURN, count=1000)
                self.assertEqual(u.reg_read(reg.UC_MIPS_REG_PC), RETURN)
                self.assertIn(0x2e19784c, seen)
                actual = tuple(u.mem_read(DATA, 2))
                self.assertEqual(actual, expected)
                RECORDS.append(dict(gate='customer_service_classifier', mode=mode,
                                    operator=operator, service_type=typ, output=list(actual),
                                    instructions=len(seen), result='PASS'))

    def test_list_visibility_flags_do_not_depend_on_codec(self):
        # Flags are kept as raw fields, without assuming unwitnessed writer semantics.
        flags = [(0, 0, 1, 1, True), (1, 0, 1, 1, False),
                 (0, 1, 1, 1, False), (0, 0, 0, 1, False), (0, 0, 1, 0, False)]
        for codec in (0, 1, 5):
            for f15, f11, f0f, f10, expected in flags:
                with self.subTest(codec=codec, flags=(f15, f11, f0f, f10)):
                    u, seen = instance('dvb', [(0x2d50280c, 0x2d50284c)])
                    for offset, val in ((0x19, codec), (0x15, f15), (0x11, f11),
                                        (0xf, f0f), (0x10, f10)):
                        u.mem_write(DATA+offset, bytes([val]))
                    u.reg_write(reg.UC_MIPS_REG_A0, OBJ)
                    u.reg_write(reg.UC_MIPS_REG_A1, DATA)
                    u.emu_start(0x2d50280c, RETURN, count=100)
                    self.assertEqual(u.reg_read(reg.UC_MIPS_REG_PC), RETURN)
                    actual = u.reg_read(reg.UC_MIPS_REG_V0)
                    self.assertEqual(actual, int(expected))
                    RECORDS.append(dict(gate='base_listable', codec=codec,
                                        flags_15_11_0f_10=[f15, f11, f0f, f10],
                                        output=actual, instructions=len(seen), result='PASS'))


if __name__ == '__main__':
    result = unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(ServiceGates))
    if result.wasSuccessful():
        report = dict(status='PASS_BOUNDED_NATIVE_GATES', test_methods=result.testsRun,
                      bounded_cases=len(RECORDS), sources=FILES, cases=RECORDS,
                      virtual_slot=dict(offset='0x2bc', target='0x2e19784c',
                                        basis='static customer vtable relocation; synthetic object wiring'),
                      limits='Synthetic fields and original instructions only. No actual tuner, parser lifetime, RF/TS input, channel DB or hardware. No full-firmware absence claim.')
        out = ROOT / 'analiz/native-4k/service-gate-tests.json'
        out.write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
        print(f'{len(RECORDS)} bounded cases PASS; {out}')
    sys.exit(not result.wasSuccessful())
