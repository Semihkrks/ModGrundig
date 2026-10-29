"""Read only original ELF code/metadata; never run firmware or hardware commands."""
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path[:0] = [str(ROOT / 'scripts'), str(ROOT / 'tools/native-volume-venv/Lib/site-packages')]
from map_mips_calls import Elf32
import capstone

OUT = Path(__file__).resolve().parent
D = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
FILES = {'dvb': '07_MSLIB/libmsrv_dvb.so', 'customer': '07_MSLIB/libmsrv_dvb_customer.so',
         'satellite': '07_MSLIB/libmsrv_dvbs_customer.so'}
TARGETS = {'dvb': [0x2d4d32e0, 0x2d4d3990], 'customer': [0x2e1a7c44],
           'satellite': [0x2e9623a8, 0x2e970748]}
result = {'date': '2026-10-27', 'evidence_kind': 'original_ELF_assembly_and_direct_Ghidra_static_not_REA',
          'modules': [], 'functions': [], 'firmware_executed': False, 'original_bytes_changed': False,
          'parser_constructor_import_inventory': []}

def signed16(n):
    return n - 0x10000 if n & 0x8000 else n

for key, path in FILES.items():
    e = Elf32(ROOT / 'analiz/dosya-sistemleri-tam' / path)
    result['modules'].append({'path': path, 'sha256': hashlib.sha256(e.raw).hexdigest()})
    result['parser_constructor_import_inventory'].append({'path': path,
        'constructors': [{'got': hex(slot), 'symbol': s['name'], 'imported': s['imported']}
                         for slot, s in e.got_symbols.items() if 'SI_PSI_Parser' in s['name']
                         and ('C1Ev' in s['name'] or 'C2Ev' in s['name'])]})
    for va in TARGETS[key]:
        s = next(s for s in e.symbols if s['value'] == va and s['type'] == 2)
        raw = e.raw[e.file_offset(va):e.file_offset(va) + s['size']]
        ins = list(D.disasm(raw, va))
        words = [int.from_bytes(i.bytes, 'little') for i in ins]
        gp = (va + ((words[0] & 0xffff) << 16) + signed16(words[1] & 0xffff)) & 0xffffffff
        refs = []
        for i, w in zip(ins, words):
            if w >> 26 == 35 and (w >> 21) & 31 == 28 and (w >> 16) & 31 == 25:
                slot = (gp + signed16(w & 0xffff)) & 0xffffffff
                refs.append({'load_at': hex(i.address), 'got': hex(slot), 'raw_value': hex(e.u32(slot)),
                             'symbol': e.got_symbols.get(slot, {}).get('name')})
        (OUT / (key + '-' + hex(va) + '.asm.txt')).write_text(
            '\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins) + '\n', encoding='utf-8')
        result['functions'].append({'path': path, 'va': hex(va), 'name': s['name'], 'bytes': len(raw),
                                    'body_sha256': hashlib.sha256(raw).hexdigest(), 'gp': hex(gp), 'GOT_loads': refs})
    if key == 'dvb':
        # Find import-backed construction and direct initialization callers conservatively.
        selected = {slot: s for slot, s in e.got_symbols.items()
                    if 'SI_PSI_Parser_CustomerC1' in s['name'] or 'DoInit_EpgAndCmdbAndSiParser' in s['name']}
        callers = []
        for s in e.symbols:
            if s['type'] != 2 or s['imported'] or s['size'] < 12:
                continue
            raw = e.raw[e.file_offset(s['value']):e.file_offset(s['value']) + s['size']]
            ins = list(D.disasm(raw, s['value']))
            words = [int.from_bytes(i.bytes, 'little') for i in ins]
            if len(words) < 2 or words[0] >> 26 != 15 or (words[0] >> 16) & 31 != 28:
                continue
            gp = (s['value'] + ((words[0] & 0xffff) << 16) + signed16(words[1] & 0xffff)) & 0xffffffff
            for i, w in zip(ins, words):
                if w >> 26 == 35 and (w >> 21) & 31 == 28 and (w >> 16) & 31 == 25:
                    slot = (gp + signed16(w & 0xffff)) & 0xffffffff
                    if slot in selected:
                        callers.append({'function': s['name'], 'entry': hex(s['value']), 'load_at': hex(i.address),
                                        'got': hex(slot), 'symbol': selected[slot]['name'],
                                        'kind': 'named_GOT_load_candidate_inspect_call_delay_slot'})
        result['constructor_and_init_GOT_call_candidates'] = callers

summaries = [json.loads((OUT / key / 'summary.json').read_text(encoding='utf-8')) for key in ['dvb', 'customer']]
assert sum(s['decompile_complete_count'] for s in summaries) == 3
assert all(not s['target_executed'] and not s['target_bytes_written'] for s in summaries)
result['new_decompiled_functions'] = 3
result['new_full_assembly_bodies'] = 5
result['new_runtime_tests'] = 0
result['customer_vptr'] = '0x2e1e1420'
result['confirmed_selected_call_edges'] = [
    {'from': '0x2d4d34a0', 'to_symbol': '_ZnwjRKSt9nothrow_t', 'behavior': 'allocate 0xd3920 bytes for parser'},
    {'from': '0x2d4d34b8', 'to': '0x2e1a7c44', 'via_GOT': '0x2d5db52c', 'behavior': 'CustomerC1 on new parser'},
    {'from': '0x2d4d3f3c', 'to_symbol': '_ZnwjRKSt9nothrow_t', 'behavior': 'allocate 0xd3920 bytes for parser'},
    {'from': '0x2d4d3f54', 'to': '0x2e1a7c44', 'via_GOT': '0x2d5db52c', 'behavior': 'CustomerC1 on new parser'},
    {'from': '0x2e1a7c78', 'to_symbol': '_ZN20MW_DVB_SI_PSI_ParserC2Ev', 'via_GOT': '0x2e1e1e9c', 'behavior': 'base constructor before customer vptr overwrite'},
    {'from': '0x2e96245c', 'to': '0x2e970748', 'via': 'Customer scan vtable+0x12c',
     'binding_at': '0x2e99d3b4', 'behavior': 'same player+0xfc parser passed as stack argument+0x14'}
]
sat = Elf32(ROOT / 'analiz/dosya-sistemleri-tam' / FILES['satellite'])
assert sat.u32(0x2e99d3b4) == 0x2e970748
result['scan_parser_pointer_flow'] = {'DoScanInit': '0x2e9623a8', 'player_parser_load': '0x2e96242c',
    'stack_argument_store': '0x2e96243c', 'call': '0x2e96245c', 'SetInitData': '0x2e970748',
    'callee_stack_argument_load': '0x2e970764', 'callee_parser_store': '0x2e970798',
    'scanner_member': '+0x134', 'parser_member': 'player+0xfc',
    'certainty': 'static pointer forwarding through matching customer scan vtable; not physical runtime trace'}
result['confirmed_selected_call_edge_count'] = len(result['confirmed_selected_call_edges'])
result['known_unresolved_indirect_links'] = [
    {'from_function': '0x2d4d32e0', 'slot': 'player_vptr+0x710', 'example_load_at': '0x2d4d3528',
     'impact': 'operator variable argument; no selection between base and customer constructor here'},
    {'from_function': '0x2d4d32e0', 'slot': 'player_vptr+0x8c8',
     'impact': 'country-dependent setup before construction; target not resolved in this bounded task'},
    {'from_function': '0x2d4d3990', 'slot': 'player_vptr+0x840',
     'impact': 'post-parser initialization target not resolved in this bounded task'}
]
result['known_unresolved_link_count_scope'] = '3 explicitly tracked links, not exhaustive whole-function/callgraph count'
result['source_of_existing_customer_dispatch_bindings'] = '../tuner/customer-vtable-bindings.json'
result['limitations'] = [
    'Static construction and vptr stores prove code choices on these paths, not that physical TV reached each branch.',
    'An already non-null parser member skips allocation; other writes/live runtime state are not exhaustively excluded.',
    'Named GOT load candidates alone are not counted as executed calls; inspect retained assembly.',
    'Decompiler can misrecover argument types; raw MIPS instructions retained for cross-check.'
]
(OUT / 'results.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
print(json.dumps({'functions': 5, 'decompiled': 3, 'assembly_bodies': 5,
                  'GOT_candidates': len(result['constructor_and_init_GOT_call_candidates'])}))
