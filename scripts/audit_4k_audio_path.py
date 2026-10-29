"""Offline audio conversion/mute audit. No emulation or firmware execution."""
from __future__ import annotations
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
import capstone

OUT = ROOT / 'analiz/native-4k/audio-stage3'
SOURCES = {
 'libmsrv_dvb.so': '93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97',
 'libmsrv_common.so': '06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21',
 'libMStarSDK.so': '00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb',
 'libMStarSDK_customer.so': '4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949',
}
DIS = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)


def finish_clears_audio_mute(*, video_active, audio_active, old_video_kept, ready92,
                            sync_pending, audio_requested=True, video_requested=True):
    """Host transcription of DoStart's end predicates, not a native test."""
    return bool((audio_active and (not video_active or
        (old_video_kept and video_active and ready92 and not sync_pending))) or
        (audio_requested and not video_requested))


def build():
    OUT.mkdir(parents=True, exist_ok=True)
    es = {}
    for name, sha in SOURCES.items():
        e = Elf32(ROOT / 'analiz/dosya-sistemleri-tam/07_MSLIB' / name)
        assert hashlib.sha256(e.raw).hexdigest() == sha, f'Changed source: {name}'
        es[name] = e
    # Eight selected bodies: four newly exported C, one reused C and three
    # additional small raw-only bodies. DoStart/converter were old stage2 ASM.
    selected = {
      'libmsrv_dvb.so': [0x2d4d6a08],
      'libmsrv_common.so': [0x2d9d7e40, 0x2d9d3e04, 0x2d9d6124,
                           0x2d9d6270, 0x2d9d6c44, 0x2d9d1be0, 0x2d9d4a90],
    }
    functions = []
    for name, vas in selected.items():
        e = es[name]
        for va in vas:
            sym = next(s for s in e.symbols if s['value'] == va and s['type'] == 2 and not s['imported'])
            off = e.file_offset(va)
            raw = e.raw[off:off + sym['size']]
            ins = list(DIS.disasm(raw, va))
            assert sum(i.size for i in ins) == len(raw)
            hi, lo = [e.u32(va + x) & 65535 for x in [0, 4]]
            gp = (va + (hi << 16) + (lo if lo < 32768 else lo - 65536)) & 0xffffffff
            calls = []
            for i in ins:
                w = int.from_bytes(i.bytes, 'little')
                if w >> 26 == 35 and (w >> 21) & 31 == 28 and (w >> 16) & 31 == 25:
                    imm = w & 65535
                    slot = gp + (imm if imm < 32768 else imm - 65536)
                    if slot in e.got_symbols:
                        calls.append(dict(load_at=hex(i.address), slot=hex(slot), symbol=e.got_symbols[slot]['name']))
            filename = name + '-' + hex(va) + '.asm.txt'
            (OUT / filename).write_text('\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins) + '\n', encoding='utf8')
            functions.append(dict(module=name, va=hex(va), name=sym['name'], bytes=len(raw),
                function_sha256=hashlib.sha256(raw).hexdigest(), gp=hex(gp), assembly=filename, named_GOT_load_candidates=calls))
    # Derive each primary-audio table row from its original case instructions.
    e = es['libmsrv_dvb.so']; gp = 0x2d5dfc20
    table = e.u32(gp - 0x7fd0) + 0x4720
    conversions = []
    expected = [0,1,255,4,6,4] + [255]*10 + [4]*5 + [18]
    for typ in range(22):
        target = (e.u32(table + 4 * typ) + gp) & 0xffffffff
        value = None; store = None
        for va in range(target, target + 12, 4):
            w = e.u32(va)
            if w >> 26 == 9 and (w >> 21) & 31 == 0 and (w >> 16) & 31 == 2:
                value = w & 65535
            if w >> 26 == 43 and (w >> 21) & 31 == 16 and w & 65535 == 4:
                if (w >> 16) & 31 == 0:
                    value = 0
                assert value is not None
                store = va
                break
        assert store is not None and value == expected[typ]
        conversions.append(dict(db_audio_type=typ, avinfo_audio_codec=value, case_target=hex(target), store_va=hex(store)))
    # Named audio virtual-method candidates in both base and customer tables.
    vtables = []
    for name, table_va in [('libMStarSDK.so',0x2cd752e8),('libMStarSDK_customer.so',0x2dcf96a8)]:
        e = es[name]
        for slot in [0x20,0x38,0x44,0x50,0x5c,0x64]:
            target = e.u32(table_va + 8 + slot)
            sym = next(s for s in e.symbols if not s['imported'] and s['value'] == target)
            vtables.append(dict(module=name, vptr=hex(table_va+8), slot=hex(slot), target=hex(target), symbol=sym['name'],
                runtime_instance_selection_proven=False))
    inputs = [
      ('new_video_started_no_ready',1,1,0,0,0,1,1,False),
      ('old_video_no_ready',1,1,1,0,0,1,1,False),
      ('ready_but_sync_pending',1,1,1,1,1,1,1,False),
      ('old_video_ready_no_sync',1,1,1,1,0,1,1,True),
      ('new_video_ready_still_needs_async_path',1,1,0,1,0,1,1,False),
      ('no_video_audio_active',0,1,0,0,0,1,1,True),
      ('explicit_audio_only_request',1,1,0,0,0,1,0,True),
      ('no_active_audio_or_video',0,0,0,0,0,0,0,False),
    ]
    cases = []
    keys = ['video_active','audio_active','old_video_kept','ready92','sync_pending','audio_requested','video_requested']
    for label, *values in inputs:
        wanted = values.pop()
        args = dict(zip(keys, map(bool, values)))
        actual = finish_clears_audio_mute(**args)
        assert actual == wanted
        cases.append(dict(label=label, inputs=args, clears_mute2=actual, expected=wanted))
    recovery = []
    for elapsed, ready, pending, lock, expected in [(3000,False,False,True,False),(3000,True,False,False,False),(3000,True,False,True,True)]:
        actual = elapsed > 2000 and not pending and ready and lock
        assert actual == expected
        recovery.append(dict(elapsed_ms=elapsed, ready92=ready, sync_pending=pending, audio_MAD_lock=lock, clears_mute2=actual))
    assert 0x1a0ce & 2 and 0x15002 & 2  # mute2 qualifies for audio in both modes
    report = dict(schema_version=1, offline_static_only=True, target_executed=False, native_emulation=False,
      patch_proposed=False, sources=SOURCES, functions=functions,
      counts=dict(new_C_exports=4, reused_C_outputs=1, additional_small_raw_bodies=3,
                  selected_unique_function_bodies=8, previously_covered_unique_bodies=3,
                  new_focused_unique_bodies=5, primary_audio_table_rows=22,
                  host_predicate_cases=len(cases)+len(recovery)),
      conversion_table_va=hex(table), primary_audio_conversion=conversions,
      invalid_audio_pid=dict(value='0x1fff', check_va='0x2d4d6aa4', output_codec='0xff'),
      pid_fields=dict(db_audio_pid='program+0x54+14*selected_index', db_audio_type='program+0x56+14*selected_index',
        db_pcr_pid='program+0x2e', avinfo_main_audio_pid='+0x12', avinfo_AD_audio_pid='+0x14',
        avinfo_BMA_audio_pid='+0x16', avinfo_PCR_pid='+0x1e'),
      audio_vtable_candidates=vtables, host_DoStart_predicate_cases=cases, host_audio_recovery_cases=recovery,
      conclusion='Video initialization return values do not gate audio initialization, but video/readiness synchronization gates can leave initialized audio muted',
      critical_addresses=dict(video_SetVdecType='0x2d9d9308', video_Play='0x2d9d9334', unconditional_video_active_store='0x2d9d9350',
        set_audio_mute2='0x2d9d8200-0x2d9d820c', audio_DSP_switch='0x2d9d82e8-0x2d9d82f0',
        DoStart_unmute_predicates='0x2d9d8a1c-0x2d9d8a64,0x2d9d8d94-0x2d9d8db8',
        CheckAudioStatus_ready_gate='0x2d9d6178-0x2d9d617c', CheckAudioStatus_unmute='0x2d9d61bc-0x2d9d61d0',
        DoVideoSync_entry='0x2d9d6270'),
      unresolved=['Live TRT service/audio/PCR PIDs and selected audio type/index are unknown',
        'Audio codec labels on the TV do not prove PMT enum identity or decoder success',
        'Audio factory concrete instance and all virtual demux/control call targets remain unproven',
        'Readiness flag0x92 is kept as an address-named flag, not assumed to prove a decoded frame',
        'Host predicate cases only transcribe verified branches; no tuner, audio decoder or hardware runs',
        'A forced-unmute patch lacks independent audio-ready/PCR invariants and is not proposed'])
    (OUT/'results.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='PASS_STATIC_AND_HOST_PREDICATES',**report['counts']),ensure_ascii=False))
    return report


if __name__ == '__main__':
    build()
