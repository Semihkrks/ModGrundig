"""Emit bounded, non-function CFG phases of the complete Settings listing."""
import json
import re
from pathlib import Path
from analyze_settings_ui import classify_output

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/"analiz/native/ui-four/settings"
SOURCE=OUT/"abi_filled_conly600/0055b6c0.json"
PHASES=[
    ("entry_position",0x55b6c0,0x55b734),
    ("autosearch_initial",0x55b734,0x560f18),
    ("manualsearch_initial",0x560f18,0x562ea0),
    ("antenna_initial",0x562ea0,0x5635f4),
    ("source_initial",0x5635f4,0x5642dc),
    ("fti_initial",0x5642dc,0x565e04),
    ("root_containers",0x565e04,0x56643c),
    ("scroll_collection_and_style",0x56643c,0x5674fc),
    ("child_controls_and_scroll_tail",0x5674fc,0x568650),
    ("autosearch_results",0x568650,0x570ab0),
    ("manualsearch_results",0x570ab0,0x579250),
    ("normal_cleanup",0x579250,0x5792b8),
    ("exception_cleanup",0x5792b8,0x579360),
]
CONTEXT={0x16e0:"original manager input a0",0x16e4:"original frame input a1",0x20:"saved PIC gp",
         0x150:"AutoSearchFrame pointer initial phase",0x100:"ManualSearchFrame pointer initial phase",
         0xf8:"AntennaSettingsFrame pointer",0xf0:"SourceSetupFrame pointer",0xe8:"FTI_BasicSetupFrame pointer",
         0x11e4:"working rect object",0x11f4:"AbsContainer vector A",0x1240:"AbsContainer vector B",
         0x124c:"ScrollListContainer vector",0x1258:"scroll vector iterator",0xd8:"current ScrollListContainer",
         0xd0:"child index",0xcc:"current child widget",0xa8:"AutoSearchFrame pointer results phase",
         0x12b4:"AutoSearch temporary TextBox vector",0x64:"ManualSearchFrame pointer results phase",
         0x1330:"ManualSearch temporary TextBox vector",0x16bc:"exception context saved a1",0x16c0:"exception context saved a0"}


def main():
    native=json.loads(SOURCE.read_text())
    instructions=native["instructions"]
    assert len(instructions)==30504
    assert {int(i["address"],16) for i in instructions}==set(range(0x55b6c0,0x579360,4))
    calls=json.loads((OUT/"raw-selected-calls.json").read_text())["calls"]
    switches={int(s["dispatch_site"],16):[int(c["target"],16) for c in s["cases"]] for s in json.loads((OUT/"switch-cases.json").read_text())}
    def phase_at(address):
        return next((name for name,start,end in PHASES if start<=address<end),None)
    edges=[]
    for instruction in instructions:
        at=int(instruction["address"],16)
        flow=instruction["flow_type"]
        if "CALL" in flow:
            continue
        if "JUMP" not in flow and "TERMINATOR" not in flow:
            continue
        targets=[int(x,16) for x in re.findall(r"0x[0-9a-f]{7,8}",instruction["instruction"])]
        if at in switches:
            targets=switches[at]
        for target in targets:
            edges.append({"from":hex(at),"to":hex(target),"from_phase":phase_at(at),"to_phase":phase_at(target),"kind":"switch_case" if at in switches else "branch","instruction":instruction["instruction"]})
        if "CONDITIONAL" in flow and "UNCONDITIONAL" not in flow:
            target=at+4*(1+instruction.get("delay_slots",0))
            edges.append({"from":hex(at),"to":hex(target),"from_phase":phase_at(at),"to_phase":phase_at(target),"kind":"conditional_fallthrough","instruction":instruction["instruction"]})
        if not targets:
            edges.append({"from":hex(at),"to":None,"from_phase":phase_at(at),"to_phase":None,"kind":"return" if instruction["instruction"]=="jr ra" else "unresolved_indirect_transfer","instruction":instruction["instruction"]})
    for name,start,end in PHASES[:-1]:
        prior=next(i for i in instructions if int(i["address"],16)==end-8)
        last=next(i for i in instructions if int(i["address"],16)==end-4)
        # A branch's post-delay fallthrough is already explicit above. Do not
        # invent a second phase-exit edge from its final delay-slot instruction.
        prior_controls_exit="JUMP" in prior["flow_type"] or "TERMINATOR" in prior["flow_type"]
        if not prior_controls_exit and last["flow_type"]=="FALL_THROUGH":
            edges.append({"from":hex(end-4),"to":hex(end),"from_phase":name,"to_phase":phase_at(end),"kind":"phase_sequential_fallthrough","instruction":last["instruction"]})
    phases=[]
    for name,start,end in PHASES:
        selected=[i for i in instructions if start<=int(i["address"],16)<end]
        reads=set();writes=set();taken=set();stored=set();early=set()
        for i in selected:
            text=i["instruction"]
            for offset,base in re.findall(r",(-?0x[0-9a-f]+|0)\((s8|sp)\)",text):
                value=int(offset,0)
                if i["mnemonic"] in {"lw","lbu","lb","lh","lhu","lwc1","ldc1","lwl","lwr"}:
                    reads.add(value)
                    if value not in stored:early.add(value)
                elif i["mnemonic"] in {"sw","sb","sh","swc1","sdc1","swl","swr"}:
                    writes.add(value);stored.add(value)
            for base,offset in re.findall(r"addiu [a-z0-9]+,(s8|sp),(-?0x[0-9a-f]+)",text):taken.add(int(offset,0))
        def slots(values):return [{"offset":hex(v),"known_role":CONTEXT.get(v)} for v in sorted(values)]
        p_calls=[c for c in calls if start<=int(c["site"],16)<end]
        phases.append({"id":name,"start":hex(start),"end_exclusive":hex(end),"bytes":end-start,"instruction_count":len(selected),
                       "common_context":["s8 is original function stack-frame base, allocated size 0x16e0","gp=0x10cc310 under PIC entry invariant; saved at stack+0x20"],
                       "register_inputs":["a0 manager","a1 frame","t9 function entry"] if name=="entry_position" else (["a0 exception object","a1 exception selector"] if name=="exception_cleanup" else []),
                       "stack_reads_conservative_context_superset":slots(reads),"stack_writes":slots(writes),"stack_addresses_taken":slots(taken),
                       "linear_reads_before_first_direct_store_candidates":slots(early),
                       "input_limitations":"All stack reads retained as a conservative context superset; linear early-read candidates are NOT path-sensitive liveness. Pointer-output calls and aliased frame/object memory require original context. Exception landing-pad entries from LSDA are not reconstructed.",
                       "outgoing_branches":[e for e in edges if e["from_phase"]==name and e["to_phase"]!=name],
                       "incoming_branches":[e for e in edges if e["to_phase"]==name and e["from_phase"]!=name],
                       "raw_call_candidate_count":len(p_calls),"unresolved_call_count":sum(c["resolution"]=="unresolved_indirect" for c in p_calls),
                       "noreturn_call_candidates":[{"site":c["site"],"target":c.get("target_name_candidate")} for c in p_calls if c.get("target_name_candidate") in {"abort","_Unwind_Resume","__cxa_throw","__cxa_rethrow","__stack_chk_fail"}]})
    c_run=OUT/"reduced-recovery180"
    c_status=classify_output(c_run,json.loads((c_run/"summary.json").read_text()) if (c_run/"summary.json").exists() else {})
    result={"source":str(SOURCE.relative_to(ROOT)),"target_sha256":"51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916",
            "function_start":"0x55b6c0","function_end_exclusive":"0x579360","phase_count":len(phases),"instruction_count":len(instructions),
            "whole_C_status":{key:c_status[key] for key in ("actual_C_count","default_full_recovery_C_count","reduced_inference_C_count","C_output_classification")},
            "status":"proposed natural CFG phases, NOT independent original functions or whole-function decompilation",
            "important_cross_phase_loop":"scroll_collection_and_style 0x56643c-0x5674fc and child_controls_and_scroll_tail 0x5674fc-0x568650 share outer iterator. Child tail at0x568648 returns to0x5664c8; do not model as sequential independent functions.",
            "phases":phases,"control_edges":edges}
    (OUT/"phase-plan.json").write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n")
    print(json.dumps([{"id":p["id"],"start":p["start"],"end_exclusive":p["end_exclusive"],"bytes":p["bytes"],"instructions":p["instruction_count"],"outgoing_cross_edges":len(p["outgoing_branches"]),"early_stack_input_candidates":[x["offset"] for x in p["linear_reads_before_first_direct_store_candidates"]]} for p in phases],ensure_ascii=False))


if __name__=="__main__":main()
