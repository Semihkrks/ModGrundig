"""Pinned, offline main/proc audio decoder allocation audit; no target execution."""
from pathlib import Path
import hashlib
import json
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from map_mips_calls import Elf32
import capstone

SHA = '4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949'
OUT = ROOT/'analiz/native-4k/audio-stage5-allocation'
TARGETS = {0x2dc6ed7c:372, 0x2dc6ae10:396, 0x2dc6ada4:108,
           0x2dc6cf38:4472, 0x2dc6c98c:1452}


def build():
    e = Elf32(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libMStarSDK_customer.so')
    assert hashlib.sha256(e.raw).hexdigest() == SHA
    summary = json.loads((OUT/'customer-v1/summary.json').read_text(encoding='utf-8'))
    assert summary['requested_count'] == summary['C_export_complete_count'] == 5
    assert summary['stored_executable_sha256'] == SHA
    dis = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
    bodies = []
    for va, size in TARGETS.items():
        symbol = next(s for s in e.symbols if s['value']==va and not s['imported'] and s['type']==2)
        assert symbol['size'] == size
        raw = e.raw[e.file_offset(va):e.file_offset(va)+size]
        instructions = list(dis.disasm(raw, va)); assert len(instructions)*4 == size
        text = '\n'.join(f'{i.address:08x}: {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in instructions)+'\n'
        assert (OUT/f'{va:08x}.asm.txt').read_text(encoding='utf-8') == text
        assert (OUT/f'customer-v1/{va:08x}.c').is_file()
        bodies.append(dict(va=hex(va),size=size,symbol=symbol['name'],sha256=hashlib.sha256(raw).hexdigest()))
    expected_words = {
        0x2dc6edfc:0x2404ffff, 0x2dc6ee10:0xae040130, 0x2dc6ee20:0xae04012c,
        0x2dc6cf70:0x8c820118, 0x2dc6cf78:0x1045010e,
        0x2dc6d020:0x8e25012c, 0x2dc6d024:0x8c590054,
        0x2dc6d044:0x8c790050, 0x2dc6d050:0x26250134,
        0x2dc6d05c:0xae22012c, 0x2dc6d06c:0xae320118,
        0x2dc6cc78:0x8e050130, 0x2dc6cc7c:0x8c590054,
        0x2dc6cc8c:0xae110158, 0x2dc6cc90:0xae130154,
        0x2dc6cc94:0x8c590050, 0x2dc6cca0:0x26050150,
        0x2dc6cca8:0xae020130,
    }
    for va, word in expected_words.items(): assert e.u32(va) == word, hex(va)
    vtable = []
    for slot, target in [(0x50,0x2dc6ae10),(0x54,0x2dc6ada4),(0x58,0x2dc6ac08),(0x6c,0x2dc6cf38),(0x13c,0x2dc62954)]:
        assert e.u32(0x2dcf96b0+slot) == target
        vtable.append(dict(slot=hex(slot),target=hex(target)))
    # These are transcription cases, not execution of native allocator code.
    cases = []
    for current, requested, old_id, allocated, expect_open, expect_id in [
        (0x1c,0x1c,-1,1,False,-1), (0x1c,0x1c,1,2,False,1),
        (0x17,0x1c,1,2,True,2), (0x17,0x1c,1,-1,True,-1),
    ]:
        opened = current != requested; result = allocated if opened else old_id
        assert (opened,result)==(expect_open,expect_id)
        cases.append(dict(current_source=current,requested_source=requested,old_id=old_id,
            mocked_open_result=allocated,open_called=opened,resulting_main_id=result,
            resulting_current_source=requested if opened else current))
    report = dict(date='2026-10-30',user_feedback='Normal HD audio works after returning from TRT UltraHD; no global persistent allocation failure established',status='PASS_STATIC_AND_HOST_TRANSCRIPTIONS',source_sha256=SHA,
        target_executed=False,firmware_modified=False,counts=dict(new_C_exports=5,selected_function_bodies=5,
        pinned_instruction_words=len(expected_words),pinned_vtable_slots=len(vtable),host_transcription_cases=len(cases)),
        bodies=bodies,vtable=vtable,instruction_words={hex(k):hex(v) for k,v in expected_words.items()},
        constructor=dict(main_ID='+0x12c=-1',secondary_ID='+0x130=-1',main_status_source='+0x13c=0x1c',secondary_status_source='+0x158=0x25',initial_DSP_main='+0x140=0',initial_DSP_secondary='+0x15c=0'),
        allocation=dict(main_call='0x2dc6d04c virtual+0x50(status+0x134)',main_store='0x2dc6d05c stores returned V0 to+0x12c',
            secondary_call='0x2dc6cc9c virtual+0x50(status+0x150)',secondary_store='0x2dc6cca8 stores returnedV0 to+0x130',
            selected_ID_is_literal=False,underlying_API_allocation_policy_unresolved=True),
        open=dict(va='0x2dc6ae10',reject_null_status=True,allowed_source_values=[1,0x17,0x18,0x19,0x1a,0x1c,0x1e,0x22,0x25,0x26],reject_return='-1',
            API_call='0x2dc6af30 MApi_AUDIO_OpenDecodeSystem',returned_ID_converter='0x2dc63550',source_info_converter='virtual+0x13c ->0x2dc62954',
            converter_numeric_outputs_not_inspected=True),
        close=dict(va='0x2dc6ada4',ID_minus1_or3_returns0=True,valid_path='ID converter0x2dc634d8 then MApi_AUDIO_ReleaseDecodeSystem',caller_ignores_release_success=True),
        main_source_change=dict(va='0x2dc6cf38',same_source_early_return='0x2dc6cf70..0x2dc6cf78',
            open_failure_not_checked_before_source_update=True,source_update='0x2dc6d06c +0x118=requested',
            source1c_later_default_DSP_switch='virtual+0x44(this,0,0)',HEVC_specific_allocation_condition_found=False,
            DSP_field_reused_on_later_source_changes=True),
        host_cases=cases,
        implications=['Constructor does not preassign a valid mainID','Allocation result is stored unconditionally; this layer does not force ID0/1/2',
            'Same-source calls return even when mainID remains-1','Failure may persist until another source change; not observed on TV',
            'Previous switch skips proc0 when mainID-1 but otherID valid; if both-1 it uses legacy fallback instead',
            'WorkingHD followed by silentUHD on same mainDTV source would not by itself imply reallocation in this selected main function'],
        unresolved=['Live main/secondary IDs and allocation return','Underlying OpenDecodeSystem fixed-vs-dynamic selection policy','Numeric source/returned-ID converters beyond resolved targets','All callers/order of source switching and active PIP state','Whether TV ever enters selected allocation-failure state'])
    (OUT/'results.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(status=report['status'],**report['counts'])))


if __name__ == '__main__': build()
