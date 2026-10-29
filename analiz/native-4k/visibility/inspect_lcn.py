"""Bounded local MIPS metadata tests. No TV process, hardware or updater execution."""
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path[:0] = [str(ROOT / 'scripts'), str(ROOT / 'tools/native-volume-venv/Lib/site-packages')]
from map_mips_calls import Elf32
import capstone
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE
from unicorn import mips_const as r

OUT = Path(__file__).resolve().parent
E = {k: Elf32(ROOT / 'analiz/dosya-sistemleri-tam/07_MSLIB' / n) for k, n in
     [('base', 'libmsrv_dvb.so'), ('customer', 'libmsrv_dvb_customer.so')]}
assert hashlib.sha256(E['base'].raw).hexdigest() == '93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97'
assert hashlib.sha256(E['customer'].raw).hexdigest() == '67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761'
D = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
targets = [('base', 0x2d53d010), ('base', 0x2d53db70), ('customer', 0x2e19c210)]
functions = []
for key, va in targets:
    e = E[key]
    s = next(s for s in e.symbols if s['value'] == va and s['size'])
    raw = e.raw[e.file_offset(va):e.file_offset(va) + s['size']]
    ins = list(D.disasm(raw, va))
    (OUT / (key + '-' + hex(va) + '.asm.txt')).write_text('\n'.join(
        f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins) + '\n', encoding='utf-8')
    functions.append(dict(source=key, name=s['name'], va=hex(va), bytes=s['size'],
                          body_sha256=hashlib.sha256(raw).hexdigest()))

def guest(key, start, size, args):
    e = E[key]
    u = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
    phoff = struct.unpack_from('<I', e.raw, 28)[0]
    phsize, count = struct.unpack_from('<HH', e.raw, 42)
    for j in range(count):
        typ, off, va, _, fs, ms, _, _ = struct.unpack_from('<8I', e.raw, phoff + phsize*j)
        if typ == 1:
            lo, hi = va & ~4095, (va + ms + 4095) & ~4095
            u.mem_map(lo, hi-lo)
            u.mem_write(va, e.raw[off:off+fs])
    for va, n in [(0x10000000, 0x100000), (0x11000000, 0x10000), (0x12000000, 0x10000)]:
        u.mem_map(va, n)
    u.reg_write(r.UC_MIPS_REG_SP, 0x12008000)
    u.reg_write(r.UC_MIPS_REG_RA, 0x11000000)
    u.reg_write(r.UC_MIPS_REG_T9, start)
    for reg, val in zip([r.UC_MIPS_REG_A0, r.UC_MIPS_REG_A1, r.UC_MIPS_REG_A2, r.UC_MIPS_REG_A3], args):
        u.reg_write(reg, val)
    seen = []
    def guard(uc, va, n, data):
        assert start <= va < start+size, hex(va)
        seen.append(hex(va))
    u.hook_add(UC_HOOK_CODE, guard)
    return u, seen

P, T, N, DB = 0x100e0000, 0x10000000, 0x100d8000, 0x100e1000
cases = []
u, seen = guest('base', 0x2d53d010, 120, [T, P])
u.mem_write(P, bytes([0xa5])*0x200)
u.emu_start(0x2d53d010, 0x11000000, count=1000)
assert u.reg_read(r.UC_MIPS_REG_PC) == 0x11000000
assert bytes(u.mem_read(P+0x1c, 2)) == b'\xff\xff'
assert bytes(u.mem_read(P+3, 2)) == b'\x01\x01'
cases.append(dict(case='base_reset_initializes_lcn_ffff_not_zero', lcn=65535, instructions=len(seen)))

for case, enabled, found, lcn in [('disabled', False, False, 0), ('missing_sid', True, False, 0),
                                  ('valid_sid', True, True, 12), ('zero_lcn_sid', True, True, 0)]:
    u, seen = guest('customer', 0x2e191b98, 176, [T, N, P, 321])
    u.mem_write(T+0x1114, bytes([0 if enabled else 255]))
    u.mem_write(P+0x1c, b'\xff\xff')
    u.mem_write(P+3, b'\x01\x01')
    if found:
        u.mem_write(N+0x1ea, struct.pack('<HHH', 321, lcn, 99))
        u.mem_write(N+0x1f0, b'\x01\x01')
    u.emu_start(0x2e191b98, 0x11000000, count=5000)
    assert u.reg_read(r.UC_MIPS_REG_PC) == 0x11000000
    result = struct.unpack('<H', u.mem_read(P+0x1c, 2))[0]
    assert result == (lcn if enabled and found else 65535)
    cases.append(dict(case='GetNitLCN_'+case, lcn=result, instructions=len(seen)))

# These selected CheckService cases avoid its data-service virtual callback.
for case, mode, country, operator, sort, lcn, expected in [
    ('sat_unknown_lcn', 2, 1, 0, 0, 65535, True),
    ('sat_zero_lcn', 2, 1, 0, 0, 0, False),
    ('zero_exception_country8_sat_sort12', 2, 8, 0, 12, 0, True),
    ('zero_exception_country12_mode0', 0, 12, 0, 0, 0, True),
    ('mode1_operator4_1023', 1, 1, 4, 0, 1023, True),
    ('mode1_operator4_1024', 1, 1, 4, 0, 1024, False),
    ('mode1_operator7_999', 1, 1, 7, 0, 999, True),
    ('mode1_operator7_1000', 1, 1, 7, 0, 1000, False),
]:
    u, seen = guest('customer', 0x2e191888, 528, [T, N, P])
    for off, val in [(0x168, country), (0x170, mode), (0xd2d6c, operator), (0x1d8, sort)]:
        u.mem_write(T+off, struct.pack('<I', val))
    u.mem_write(P+0xe, b'\x01')
    u.mem_write(P+4, b'\x01')
    u.mem_write(P+0x16, struct.pack('<H', 101))
    u.mem_write(P+0x1c, struct.pack('<H', lcn))
    u.emu_start(0x2e191888, 0x11000000, count=1000)
    assert u.reg_read(r.UC_MIPS_REG_PC) == 0x11000000
    actual = bool(u.reg_read(r.UC_MIPS_REG_V0))
    assert actual == expected, case
    cases.append(dict(case=case, mode=mode, country_value=country, operator_value=operator,
                      sort_value=sort, lcn=lcn, accepted=actual, instructions=len(seen)))

customer_gp = 0x2e19c210 + 0x50000 - 0x2660
slot = customer_gp - 0x7758
assert E['customer'].got_symbols[slot]['name'] == '_ZN20MW_DVB_SI_PSI_Parser17_ResetServiceInfoER19MW_DVB_PROGRAM_INFO'
report = dict(status='PASS_BOUNDED_METADATA_ONLY', new_raw_function_bodies=3,
              unique_new_function_bodies=2, revisited_function_bodies=1,
              revisited_functions=['base_UpdateProgInfoByServiceType_0x2d53db70_previously_decompiled_in_tuner_stage1'],
              new_decompiled_functions=0, bounded_cases=len(cases), functions=functions, cases=cases,
              customer_reset_to_base_GOT=dict(load='0x2e19c22c', call='0x2e19c230', slot=hex(slot),
                  target_symbol=E['customer'].got_symbols[slot]['name']),
              limitations=['No full firmware process or hardware execution.',
                           'LCN initialization and selected cases are proven; caller ordering and live broadcast LCN remain unobserved.',
                           'Country/operator numeric meanings are not inferred from these raw values.'])
(OUT/'lcn-evidence.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
print(json.dumps(dict(status=report['status'], raw_bodies=3, unique_new_raw_functions=2, revisited_raw_functions=1, cases=len(cases))))
