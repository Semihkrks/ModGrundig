"""Pinned static video evidence and isolated framebuffer-size leaf tests.

Never launches a firmware executable or touches TV/hardware. The size-table
leaf and auth control-flow body run in synthetic Unicorn memory. External auth
is mocked; no syscalls, hardware accesses or real authorisation queries run.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

from map_mips_calls import Elf32

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-4k/video-stage6'
SHA = '215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b'
TARGETS = {
    '_MDrv_HVD_AUTH_IPCheck': (0x2d6343e0, 572),
    'MDrv_HVD_EX_GetFrmRateIsSupported': (0x2d5f22a0, 48),
    '_MApi_VDEC_EX_V2_GetErrCode': (0x2d64b230, 1252),
    '_MApi_VDEC_EX_V2_SetDynScalingParams': (0x2d651ad8, 280),
    'MDrv_HVD_EX_SetDynScalingParam': (0x2d5f6114, 384),
    'MDrv_HVD_EX_SetExternalDSBuffer': (0x2d5fe380, 600),
    'MDrv_HVD_EX_SupportRefNumOverMaxDpbSize': (0x2d5f3a80, 292),
    'MDrv_HVD_EX_GetFbMemUsageSize': (0x2d5f2754, 120),
    '_VPU_EX_GetFrameBufferDefaultSize': (0x2d62da30, 132),
}
WORDS = {
    0x2d64b4dc: 0x8f9981b0, 0x2d64b4e0: 0x0320f809,
    0x2d64b4e8: 0x1440ff81, 0x2d64b4f4: 0x3c020100,
    0x2d64b4fc: 0x34420003, 0x2d64b504: 0xac620018,
    0x2d5f22cc: 0x9082013d,
    0x2d5f6260: 0x92660000, 0x2d5f6268: 0x34a5020b,
    0x2d5f626c: 0x0320f809, 0x2d5fe430: 0x2c420c00,
    0x2d5fe510: 0xae220d0c, 0x2d5fe520: 0xae220ce4,
    0x2d5fe534: 0x34a50221, 0x2d5fe538: 0x0320f809,
    0x2d5fe53c: 0x24060001, 0x2d5fe578: 0xac820614,
    0x2d5f3b24: 0x34a5021c, 0x2d5f3b28: 0x0320f809,
    0x2d5f2798: 0x8f9981c0, 0x2d5f27a8: 0x0320f809,
    0x2d652868: 0x8f998cd4,
}


def main():
    source = ROOT / 'analiz/dosya-sistemleri-tam/07_MSLIB/utopia/libapiVDEC.so'
    assert not source.is_symlink(), 'symlink source refused'
    e = Elf32(source)
    assert hashlib.sha256(e.raw).hexdigest() == SHA, 'VDEC source mismatch'
    for va, word in WORDS.items():
        assert e.u32(va) == word, f'word mismatch {va:x}: {e.u32(va):08x}'
    sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))
    import capstone
    from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE
    from unicorn import mips_const as m
    OUT.mkdir(parents=True, exist_ok=True)
    decoder = capstone.Cs(capstone.CS_ARCH_MIPS,
                          capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
    inventory = []
    for name, (va, size) in TARGETS.items():
        symbols = [s for s in e.symbols if s['name'] == name and not s['imported']]
        assert len(symbols) == 1 and symbols[0]['value'] == va and symbols[0]['size'] == size
        raw = e.raw[e.file_offset(va):e.file_offset(va)+size]
        ins = list(decoder.disasm(raw, va))
        assert sum(i.size for i in ins) == size
        path = OUT / (name + '.asm.txt')
        path.write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}'.rstrip()
                                  for i in ins)+'\n', encoding='utf-8')
        inventory.append(dict(name=name, va=hex(va), bytes=size,
                              body_sha256=hashlib.sha256(raw).hexdigest()))

    c_names = ['_MDrv_HVD_AUTH_IPCheck', '_MApi_VDEC_EX_V2_GetErrCode',
               'MDrv_HVD_EX_SetDynScalingParam', 'MDrv_HVD_EX_SetExternalDSBuffer']
    selection = dict(target_sha256=SHA, addresses=[f'{TARGETS[n][0]:08x}' for n in c_names],
                     decompile_timeout_seconds=60, decompiler_max_payload_mbytes=128,
                     export_syntax_tree=True, seed_t9_entry=True,
                     function_bounds={f'{TARGETS[n][0]:08x}': dict(
                         end_exclusive=hex(sum(TARGETS[n])), basis='original_dynsym') for n in c_names})
    (OUT/'selection.json').write_text(json.dumps(selection, indent=2)+'\n', encoding='utf-8')

    # These tests establish only the exact enum->bytes lookup, never hardware
    # capacity or the enum selected by DTV. Unexpected control flow fails closed.
    loaded = [s for s in e.sections if s['flags'] & 2 and s['size']]
    low = min(s['va'] for s in loaded) & ~0xfff
    high = (max(s['va']+s['size'] for s in loaded)+0xfff) & ~0xfff
    stop = 0x70000000

    def synthetic_memory():
        u = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        u.mem_map(low, high-low)
        for section in loaded:
            if section['type'] != 8:
                u.mem_write(section['va'], e.raw[section['offset']:section['offset']+section['size']])
        u.mem_map(stop, 0x1000)
        u.mem_map(0x60000000, 0x2000)
        u.reg_write(m.UC_MIPS_REG_SP, 0x60001000)
        u.reg_write(m.UC_MIPS_REG_RA, stop)
        return u

    cases = []
    entry = TARGETS['_VPU_EX_GetFrameBufferDefaultSize'][0]
    expected_mib = [0, 30, 30, 30, 30, 30, 30, 108, 108, 27, 27, 130, 27, 40, 66, 21, 160, 120]
    for enum in list(range(18)) + [18, 0xffffffff]:
        u = synthetic_memory()
        u.reg_write(m.UC_MIPS_REG_T9, entry)
        u.reg_write(m.UC_MIPS_REG_A0, enum)
        u.emu_start(entry, stop, count=50)
        assert u.reg_read(m.UC_MIPS_REG_PC) == stop, 'lookup did not return'
        value = u.reg_read(m.UC_MIPS_REG_V0)
        assert value == (expected_mib[enum] if enum < 18 else 0) * 1024 * 1024
        cases.append(dict(input_enum=enum, bytes=value, mib=value/(1024*1024)))

    # Pure control-flow experiment: external auth is always intercepted. No
    # actual authorisation data, keys, registers or auth implementation is read.
    symbols = {s['name']: s for s in e.symbols}
    auth = stop + 0x100
    auth_slots = [slot for slot, symbol in e.got_symbols.items() if symbol['name'] == 'MDrv_AUTH_IPCheck']
    assert len(auth_slots) == 1
    auth_entry, auth_size = TARGETS['_MDrv_HVD_AUTH_IPCheck']
    auth_cases = []
    for mandatory, divx4k, divx1080 in [(0, 0, 0), (1, 0, 0), (1, 1, 0), (1, 0, 1), (1, 1, 1)]:
        u = synthetic_memory()
        u.mem_write(auth_slots[0], struct.pack('<I', auth))
        u.mem_write(symbols['u32UartCtrl']['value'], b'\0'*4)
        queries = []
        outcomes = {0x4b: mandatory, 0x55: divx4k, 0x56: divx1080}

        def intercept(machine, address, size, data):
            if address == auth:
                query = machine.reg_read(m.UC_MIPS_REG_A0)
                assert query in outcomes
                queries.append(query)
                machine.reg_write(m.UC_MIPS_REG_V0, outcomes[query])
                machine.reg_write(m.UC_MIPS_REG_PC, machine.reg_read(m.UC_MIPS_REG_RA))
            else:
                assert auth_entry <= address < auth_entry+auth_size, f'unexpected call {address:x}'

        u.hook_add(UC_HOOK_CODE, intercept)
        u.reg_write(m.UC_MIPS_REG_T9, auth_entry)
        u.reg_write(m.UC_MIPS_REG_A0, 7)
        saved = {reg: 0x50000000+i*0x100 for i, reg in enumerate(
            [m.UC_MIPS_REG_S0, m.UC_MIPS_REG_S1, m.UC_MIPS_REG_S2])}
        for reg, value in saved.items():
            u.reg_write(reg, value)
        u.emu_start(auth_entry, stop, count=300)
        assert u.reg_read(m.UC_MIPS_REG_PC) == stop
        assert u.reg_read(m.UC_MIPS_REG_V0) == mandatory
        assert u.reg_read(m.UC_MIPS_REG_SP) == 0x60001000
        assert all(u.reg_read(reg) == value for reg, value in saved.items())
        assert queries == ([0x4b, 0x55, 0x56] if mandatory else [0x4b])
        assert bytes(u.mem_read(0x2d73e804, 1)) == bytes([mandatory])
        assert bytes(u.mem_read(symbols['bModeSupportDivXHEVC_4K']['value'], 1)) == bytes([mandatory and divx4k])
        assert bytes(u.mem_read(symbols['bModeSupportDivXHEVC_1080P']['value'], 1)) == bytes([mandatory and divx1080])
        auth_cases.append(dict(mock_mandatory=mandatory, mock_optional_4k=divx4k,
                               mock_optional_1080=divx1080, queries=queries,
                               returned=mandatory, auth_backend_mocked=True))

    config = ROOT/'analiz/dosya-sistemleri-tam/09_CONFIG/mmap.ini'
    raw_config = config.read_bytes()
    defines = {k: int(v, 16) for k, v in re.findall(
        r'^#define\s+(\w+)\s+(0x[0-9A-Fa-f]+)', raw_config.decode(), re.M)}
    start = defines['E_MMAP_ID_VDEC_FRAMEBUFFER_ADR']
    length = defines['E_MMAP_ID_VDEC_FRAMEBUFFER_LEN']
    dram = defines['MIU_DRAM_LEN0']
    assert (start, length, dram) == (0xe19a000, 0x1e00000, 0x10000000)
    gp = e.tags[3] + 0x7ff0
    assert e.got_symbols[gp-0x732c]['name'] == 'MDrv_HVD_EX_GetFbMemUsageSize'
    assert e.got_symbols[gp-0x7e40]['name'] == '_HVD_EX_DemuxTS_ParseHEVCSPS'
    library_root = ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB'
    checked_elfs, import_matches, parse_errors = [], [], []
    error_apis = {'MApi_VDEC_GetErrCode', 'MApi_VDEC_EX_GetErrCode'}
    for path in sorted(library_root.rglob('*.so*')):
        if path.is_symlink():
            continue
        if path.read_bytes()[:4] != b'\x7fELF':
            continue
        try:
            module = Elf32(path)
        except Exception as error:
            parse_errors.append(dict(path=str(path.relative_to(ROOT)), error=type(error).__name__))
            continue
        row = dict(path=str(path.relative_to(ROOT)).replace('\\', '/'),
                   sha256=hashlib.sha256(module.raw).hexdigest())
        checked_elfs.append(row)
        matches = sorted({s['name'] for s in module.symbols if s['imported'] and s['name'] in error_apis})
        if matches:
            import_matches.append(dict(**row, imported_error_apis=matches))
    assert not parse_errors, parse_errors
    assert len(import_matches) == 1 and import_matches[0]['path'].endswith('/libvdplayer.so')
    consumer_bodies = []
    for name, va, size in [('libMStarSDK.so', 0x2cba4e10, 224),
                           ('libmsrv_common.so', 0x2d9d7364, 32),
                           ('libmsrv_dvb.so', 0x2d4fed30, 3532),
                           ('libvdplayer.so', 0x2dad701c, 452)]:
        module = Elf32(library_root/name)
        symbol = next(s for s in module.symbols if s['value'] == va and not s['imported'] and s['size'])
        assert symbol['size'] == size
        off = module.file_offset(va)
        body = module.raw[off:off+size]
        ins = list(decoder.disasm(body, va))
        assert sum(i.size for i in ins) == size
        path = OUT/f'{name}-{va:08x}.asm.txt'
        path.write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}'.rstrip()
                                 for i in ins)+'\n', encoding='utf-8')
        consumer_bodies.append(dict(module=name, name=symbol['name'], va=hex(va), bytes=size,
                                    source_sha256=hashlib.sha256(module.raw).hexdigest(),
                                    body_sha256=hashlib.sha256(body).hexdigest()))
    ghidra_exports = {}
    summary_path = OUT/'ghidra-v1/summary.json'
    if summary_path.exists():
        summary = json.loads(summary_path.read_text(encoding='utf-8'))
        assert summary['stored_executable_sha256'] == SHA
        assert summary['C_export_complete_count'] == 4 and summary['target_executed'] is False
        for name in c_names:
            path = OUT/'ghidra-v1'/f'{TARGETS[name][0]:08x}.c'
            ghidra_exports[str(path.relative_to(ROOT)).replace('\\', '/')] = hashlib.sha256(path.read_bytes()).hexdigest()
    result = dict(status='PASS_PINNED_STATIC_AND_ISOLATED_NATIVE_CHECKS', source_sha256=SHA,
                  functions=inventory, selected_C_exports=4, completed_C_exports=len(ghidra_exports),
                  C_export_sha256=ghidra_exports,
                  pinned_words={hex(k): hex(v) for k, v in WORDS.items()},
                  native_leaf_cases=cases, native_mocked_auth_cases=auth_cases,
                  consumer_bodies=consumer_bodies,
                  import_scan=dict(scope='07_MSLIB normal non-symlink *.so* ELF dynsym only',
                                   checked_elfs=checked_elfs, matches=import_matches, parse_errors=parse_errors,
                                   excludes='Dlsym, computed pointers, local calls and names without .so'),
                  memory_profile=dict(source=str(config.relative_to(ROOT)).replace('\\', '/'),
                      sha256=hashlib.sha256(raw_config).hexdigest(), dram_bytes=dram,
                      framebuffer_start=start, framebuffer_bytes=length,
                      end_exclusive=start+length, bytes_after_framebuffer=dram-start-length,
                      max_bytes_at_same_address=dram-start,
                      actual_device_profile_observed=False),
                  parser_call_path=['MApi_VDEC_EX_V2_GetControl:0x2d652870',
                                    'MDrv_HVD_EX_GetFbMemUsageSize:0x2d5f27a8',
                                    '_HVD_EX_DemuxTS_ParseHEVCSPS:0x2d633a20'],
                  unresolved=['Runtime video PID/init result/frame count/HEVC error and DSP state',
                              'All DTV error consumers and active memory profile',
                              'Microcode semantics of dynamic scaling commands',
                              'Actual TRT SPS and device UHD50/Main10 capability'],
                  firmware_changed=False, target_hardware_executed=False,
                  whole_firmware_executed=False)
    (OUT/'results.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(status=result['status'], selected_static_functions=len(inventory)+len(consumer_bodies),
                          completed_C_exports=len(ghidra_exports),
                          isolated_native_leaf_cases=len(cases), mocked_auth_cases=len(auth_cases),
                          import_scan_ELFs=len(checked_elfs),
                          firmware_changed=False)))


if __name__ == '__main__':
    main()
