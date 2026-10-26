"""Offline NewUI_Settings evidence index; never executes firmware code."""
import argparse
import collections
import hashlib
import json
import re
from datetime import datetime
from pathlib import Path
from map_ui_asset_dependencies import Elf, parse_table, table_bindings

ROOT = Path(__file__).resolve().parents[1]
START, END = 0x55B6C0, 0x579360


def write(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def classify_output(directory, metadata=None):
    """Keep native diagnostic completion separate from a real standard C file."""
    metadata=metadata or {}
    options_path=directory/"selection.json"
    options=json.loads(options_path.read_text(encoding="utf-8-sig")) if options_path.exists() else {}
    style=metadata.get("decompiler_simplification_style",options.get("decompiler_simplification_style","decompile"))
    emit=metadata.get("C_code_requested",options.get("emit_c_code",True))
    c_path=directory/"0055b6c0.c"
    contents=c_path.read_bytes() if c_path.is_file() else b""
    nonempty=bool(contents.strip())
    native_complete=metadata.get("decompile_complete",metadata.get("decompile_complete_count",0)>0)
    action_groups=metadata.get("decompiler_action_group_overrides",metadata.get("decompiler_action_groups",options.get("decompiler_action_groups",{})))
    reduced_recovery=any(action_groups.get(name) is False for name in ("protorecovery","protorecovery_b","localrecovery"))
    actual_c=int(nonempty and style=="decompile" and bool(emit))
    return {
        "native_decompile_complete":native_complete,
        "native_decompile_complete_count":int(bool(native_complete)),
        "decompiler_simplification_style":style,
        "C_code_requested":bool(emit),
        "C_file_exists":c_path.is_file(),"C_file_bytes":len(contents),"C_file_nonempty":nonempty,
        "standard_C_style":style=="decompile",
        "actual_C_count":actual_c,
        "C_output_count":actual_c,
        "default_full_recovery_C_count":int(actual_c and not reduced_recovery),
        "reduced_inference_C_count":int(actual_c and reduced_recovery),
        "C_output_classification":"full_range_reduced_inference_C_controlflow" if actual_c and reduced_recovery else ("standard_C_output" if actual_c else "no_standard_C_file"),
        "diagnostic_native_complete_count":int(bool(native_complete) and (style!="decompile" or not emit)),
        "diagnostic_C_file_count":int(nonempty and (style!="decompile" or not emit)),
        "analysis_option_overrides":metadata.get("analysis_option_overrides",{}),
        "decompiler_action_groups":action_groups,
        "C_count_basis":"real nonempty 0055b6c0.c AND decompile style AND emit_c_code=true; native completion is separate",
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--run", default="fde300")
    args = parser.parse_args()
    out = ROOT / "analiz/native/ui-four/settings"
    raw_path = ROOT / "analiz/ui-kod-cagrilari.json"
    selected_path = out / "raw-selected-calls.json"
    if selected_path.exists():
        selected = json.loads(selected_path.read_text(encoding="utf-8"))
    else:
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        selected = {
            "source": str(raw_path.relative_to(ROOT)),
            "source_sha256": hashlib.sha256(raw_path.read_bytes()).hexdigest(),
            "target_sha256": raw["target_sha256"],
            "coverage": [x for x in raw["coverage"] if int(x["address"], 16) == START],
            "calls": [x for x in raw["calls"] if int(x["function_address"], 16) == START],
            "incoming_calls": [x for x in raw["calls"] if (x.get("target_candidate") or {}).get("value") == START],
            "nonlink_jump_candidates": [x for x in raw["nonlink_jump_candidates"] if int(x["function_address"], 16) == START],
            "limitations": raw["limitations"],
        }
        write(selected_path, selected)
        del raw
    run = out / args.run
    native_path = run / "0055b6c0.json"
    if not native_path.exists():
        native_path = ROOT / "analiz/native/ui-targeted/dvbt_board/0055b6c0.json"
    native = json.loads(native_path.read_text(encoding="utf-8"))
    output_classification=classify_output(run,native)
    if int(native["address"],16) != START:
        raise ValueError("Wrong native function")
    ins = native["instructions"]
    counts = collections.Counter(x.get("target_name_candidate") or "UNRESOLVED" for x in selected["calls"])
    pcode = native.get("decompiler_pcode_calls", [])
    addresses = {int(x["address"], 16) for x in ins}
    missing = [hex(a) for a in range(START, END, 4) if a not in addresses]
    gaps = []
    for missing_address in map(lambda x:int(x,16), missing):
        if gaps and int(gaps[-1]["end_exclusive"],16) == missing_address:
            gaps[-1]["end_exclusive"] = hex(missing_address+4)
            gaps[-1]["bytes"] += 4
        else:
            gaps.append({"start":hex(missing_address),"end_exclusive":hex(missing_address+4),"bytes":4})
    evidence = {
        "function": "ArUIManager::NewUI_Settings", "start": hex(START), "end_exclusive": hex(END),
        "declared_bytes": END-START, "bound_basis": "ELF eh_frame FDE offset 0x15024 and matching dynamic symbol size",
        "native_source": str(native_path.relative_to(ROOT)),
        "native_source_sha256": hashlib.sha256(native_path.read_bytes()).hexdigest(),
        **output_classification,
        "decompile_complete": native.get("decompile_complete"), "decompile_error": native.get("decompile_error"),
        "instruction_count": len(ins), "instruction_bytes": len(addresses)*4,
        "expected_instruction_count": (END-START)//4, "missing_instruction_count": len(missing),
        "missing_instruction_addresses": missing,
        "missing_instruction_ranges": gaps,
        "raw_calls_in_listing_gaps": [x for x in selected["calls"] if int(x["site"],16) not in addresses],
        "raw_call_candidate_count": len(selected["calls"]),
        "raw_resolution_counts": dict(collections.Counter(x["resolution"] for x in selected["calls"])),
        "raw_call_target_counts": dict(counts.most_common()),
        "computed_callsite_count": native.get("computed_callsite_count"),
        "pcode_call_count": len(pcode),
        "pcode_export_complete": native.get("pcode_export_complete"),
        "pcode_addresses_outside_selected_body": native.get("decompiler_pcode_addresses_outside_selected_body") if pcode and native.get("decompile_complete") else None,
        "pcode_within_selected_body": native.get("decompiler_pcode_within_selected_body") if pcode and native.get("decompile_complete") else None,
        "pcode_scope_status": "available" if pcode and native.get("decompile_complete") else ("unavailable_C_only" if native.get("syntax_tree_requested") is False else "failed_or_no_exported_pcode_not_verified"),
        "incoming_calls": selected["incoming_calls"],
        "target_executed": False, "target_modified": False,
        "evidence_kind": "direct_Ghidra_static_query_and_raw_MIPS_candidates_not_REA_Evidence",
    }
    write(out / "scope-edges.json", evidence)
    if output_classification["diagnostic_native_complete_count"] and pcode:
        write(out/"firstpass-flow-scope.json",evidence)
        write(out/"firstpass-pcode-calls.json",pcode)
    attempts=[]
    for directory in sorted(x for x in out.iterdir() if x.is_dir() and (x/"selection.json").exists()):
        attempt={"run":directory.name}
        options=json.loads((directory/"selection.json").read_text(encoding="utf-8-sig"))
        attempt["timeout_seconds"]=options.get("decompile_timeout_seconds")
        attempt["syntax_tree_requested"]=options.get("export_syntax_tree",True)
        attempt["jumptable_gap_fill"]=(directory/"settings-gap-decode.json").exists()
        attempt["explicit_input_ABI"]=(directory/"settings-abi-correction.json").exists()
        if (directory/"summary.json").exists():
            summary=json.loads((directory/"summary.json").read_text(encoding="utf-8"))
            if summary["stored_executable_sha256"] != selected["target_sha256"]:
                raise ValueError("Native/RAW target digest mismatch")
            attempt.update(classify_output(directory,summary))
            attempt["reported_C_export_complete_count"]=summary.get("C_export_complete_count")
            attempt["status"]="finished"
        else:
            attempt.update(classify_output(directory))
            attempt["native_decompile_complete"]=None
            attempt["native_decompile_complete_count"]=None
            attempt["status"]="started_without_final_summary"
        if (directory/"ghidra.log").exists():
            stamps=re.findall(r"(?m)^(\d{4}-\d\d-\d\d \d\d:\d\d:\d\d)", (directory/"ghidra.log").read_text(encoding="utf-8",errors="replace"))
            if stamps:
                attempt["log_first_time"]=stamps[0]
                attempt["log_last_time"]=stamps[-1]
                attempt["log_window_seconds"]=(datetime.fromisoformat(stamps[-1])-datetime.fromisoformat(stamps[0])).total_seconds()
                attempt["log_window_is_CPU_measurement"]=False
                attempt["host_inactivity_or_clock_jump_possible"]=attempt["log_window_seconds"]>attempt["timeout_seconds"]+120
        attempts.append(attempt)
    write(out/"attempts.json",attempts)
    c_path = run / "0055b6c0.c"
    if c_path.exists():
        c_text=c_path.read_text(encoding="utf-8")
        write(out/"c-output-audit.json",{
            "source":str(c_path.relative_to(ROOT)),"sha256":hashlib.sha256(c_path.read_bytes()).hexdigest(),
            "classification":output_classification,
            "bytes":c_path.stat().st_size,"lines":len(c_text.splitlines()),
            "warning_lines":[{"line":i,"text":line.strip()} for i,line in enumerate(c_text.splitlines(),1) if "WARNING" in line or "halt_baddata" in line],
            "switch_token_count":len(re.findall(r"\bswitch\s*\(",c_text)),
            "case_labels":re.findall(r"(?m)^\s*case\s+([^:]+):",c_text),
            "literal_case_icon_id_counts":{hex(i):len(re.findall(r"\b"+hex(i)+r"\b",c_text)) for i in (0x124,0x127,0x128,0x129,0x12b)},
            "pcode_scope_verified":evidence["pcode_within_selected_body"],
            "limitations":"Decompiler C token audit alone does not prove semantic completeness, switch feasibility or correct ABI prototype"
        })
    write(out / "assembly-minimal.json", [{"address":x["address"], "instruction":x["instruction"], "flow_type":x["flow_type"]} for x in ins])
    write(out / "pcode-calls.json", pcode)
    write(out / "defined-strings.json", native.get("decompiler_constant_defined_strings", []) + native.get("directly_referenced_defined_strings", []))
    casts = []
    for call in selected["calls"]:
        if call.get("target_name_candidate") != "__dynamic_cast":
            continue
        arguments = call["argument_candidates_a0_a3"]
        site = int(call["site"], 16)
        casts.append({"site":call["site"], "from_type":(arguments[1] or {}).get("symbol_demangled"),
                      "to_type":(arguments[2] or {}).get("symbol_demangled"),
                      "assembly_after": [{"address":x["address"], "instruction":x["instruction"]} for x in ins if site+4 <= int(x["address"],16) <= site+64]})
    write(out / "type-dispatch.json", casts)
    lookups = {}
    table_provenance = []
    for profile in ("rc", "rc_Beko", "rc_Arcelik"):
        for kind in ("Num", "Color", "Image"):
            path = ROOT / "analiz/dosya-sistemleri-tam/08_APP/rc" / profile / "bin" / (kind + "_res.bin")
            if not path.exists():
                continue
            if path.is_symlink():
                raise ValueError("Resource symlink excluded: " + str(path))
            info, records = parse_table(path)
            if info["status"] != "fully_parsed":
                raise ValueError(str(info))
            lookups[kind, str(path.relative_to(ROOT))] = records
            table_provenance.append({k:v for k,v in info.items() if k!="path_records"})
    for language in ("rc_English","rc_Turkish"):
        path = ROOT / "analiz/dosya-sistemleri-tam/08_APP/rc" / language / "bin/Str_res.bin"
        if path.is_symlink():
            raise ValueError("String table symlink excluded")
        info,records = parse_table(path)
        if info["status"] != "fully_parsed":
            raise ValueError("String table parse incomplete")
        lookups["Str",str(path.relative_to(ROOT))] = records
        table_provenance.append({k:v for k,v in info.items() if k!="path_records"})
    resource_uses = []
    for call in selected["calls"]:
        name = call.get("target_name_candidate") or ""
        kind, index = (None, None)
        if "RcGetNum(" in name:
            kind, index = "Num", 0
        elif "RcGetColor(" in name:
            kind, index = "Color", 0
        elif name in {"MImg::Set(unsigned short)", "MImg::MImg(unsigned short)"}:
            kind, index = "Image", 1
        elif name == "MString::Set(unsigned short)":
            kind, index = "Str", 1
        if kind is None:
            continue
        candidate = call["argument_candidates_a0_a3"][index] or {}
        resource_uses.append({"site":call["site"],"target":name,"kind":kind,"id":candidate.get("value"),"basis":candidate.get("basis")})
    resource_groups = []
    phases = [("AutoSearch_initial",0x55b768,0x560f18),("ManualSearch_initial",0x560f18,0x562ea0),
              ("AntennaSettings_initial",0x562ea0,0x5635f4),("SourceSetup_initial",0x5635f4,0x5642dc),
              ("FTI_BasicSetup_initial",0x5642dc,0x565e60),("common_child_styling",0x565e60,0x568650),
              ("AutoSearch_final",0x568650,0x570ab0),("ManualSearch_final",0x570ab0,END)]
    for use in resource_uses:
        use["thematic_address_phase_candidate"] = next((name for name,lo,hi in phases if lo <= int(use["site"],16) < hi),"entry")
    for kind, rid in sorted({(x["kind"],x["id"]) for x in resource_uses if x["id"] is not None}):
        sites = [x["site"] for x in resource_uses if x["kind"] == kind and x["id"] == rid]
        resource_groups.append({"kind":kind,"id":rid,"id_hex":hex(rid),"call_sites":sites,"use_count":len(sites),"thematic_address_phases":sorted({x["thematic_address_phase_candidate"] for x in resource_uses if x["kind"]==kind and x["id"]==rid}),"package_candidates":table_bindings(kind,rid,lookups)})
    write(out / "resource-bindings.json", {"tables":table_provenance,"uses":resource_uses,"groups":resource_groups,"active_package":"unknown","basis":"raw callsite basic-block constant candidates; package index lookup corroborated separately by MUF getter analysis"})
    labels = []
    for group in resource_groups:
        if group["kind"] != "Str":
            continue
        candidates = []
        for record in group["package_candidates"]:
            raw = (ROOT / record["table"]).read_bytes()
            text = raw[record["payload_offset"]:record["payload_offset"]+record["bytes_including_nul"]-1].decode("utf-8","strict")
            candidates.append({"table":record["table"],"payload_offset":record["payload_offset"],"payload_sha256":record["payload_sha256"],"text":text})
        labels.append({"id":group["id_hex"],"call_sites":group["call_sites"],"texts":candidates})
    write(out / "search-result-labels.json",{"scope":"Only 13 ordinary UI label IDs explicitly set by this function; no device/credential content", "labels":labels})
    windows = [
        ("entry_abi_and_position", 0x55b6c0, 0x55b738, "a0 saved as this, a1 as frame; frame passed to MoveWindowTo with x=0 and computed y"),
        ("autosearch_gate", 0x55b738, 0x55b890, "RTTI AutoSearchFrame; null cast skips to ManualSearch gate; frame child +0x1d4 hidden and flag-2 state sampled on +0x1d8/+0x1dc/+0x1e0"),
        ("focus_preservation", 0x55f858, 0x55f890, "AutoSearch +0x3c == +0x180 permits SwitchFocusTo; destination comes from stack +0x14c"),
        ("common_frame_family_gate", 0x565e60, 0x565fac, "AutoSearch/ManualSearch/Antenna/SourceSetup/Sound type checks OR together before child-container traversal"),
        ("antenna_special_containers", 0x5661ac, 0x5663bc, "Antenna +0x184/+0x188 child identity selects special layout; selected container flags/rect updated and first child hidden"),
        ("shared_scroll_discovery", 0x566430, 0x5664c0, "FindScrollLists is called on frame child +0x38 to collect shared scroll/abs container vectors"),
        ("widget_type_styling", 0x5676d0, 0x568118, "RTTI differentiates ComboButton/ImageButton/SpinButton/NumberEdit/TickBox/AbsContainer; no input-event dispatch implied"),
        ("manual_header_exception", 0x568120, 0x5685e4, "ManualSearch frame +0x200 container chooses a special child layout; ordinary header child receives image0x6d; both converge on Invalidate"),
        ("search_progress_styling",0x568e50,0x569280,"AutoSearch progress appearance uses RcGetNum/RcGetColor then ProgressBar::SetBarImg and SetBarColor"),
        ("allocated_container_guard",0x5692bc,0x5693b4,"operator new(0x264) and AbsContainer construction under frame+0x38; null allocation-derived object checks printf/abort; exception path deletes allocated storage"),
        ("normal_cleanup_and_return",0x579250,0x5792b8,"ScrollList/AbsContainer temporary vector destructors precede register restoration and jr ra"),
        ("exception_cleanup_tail",0x5792b8,END,"Exception landing pads destroy remaining temporary vectors and call noreturn _Unwind_Resume at0x579358; included in exact FDE, not a second UI entry"),
    ]
    write(out / "critical-branches.json", [{"id":key,"start":hex(first),"end_exclusive":hex(last),"interpretation":claim,"evidence_level":"static_assembly_with_raw_GOT_and_RTTI_candidates","assembly":[{"address":x["address"],"instruction":x["instruction"]} for x in ins if first <= int(x["address"],16) < last],"call_candidates":[x for x in selected["calls"] if first <= int(x["site"],16) < last]} for key,first,last,claim in windows])
    controls = []
    for instruction in ins:
        if instruction["flow_type"] == "FALL_THROUGH" or "CALL" in instruction["flow_type"]:
            continue
        controls.append({"address":instruction["address"],"instruction":instruction["instruction"],"flow_type":instruction["flow_type"],"literal_destinations":re.findall(r"0x[0-9a-f]{7,8}",instruction["instruction"]),"delay_slot_depth":instruction.get("delay_slots",0)})
    write(out / "control-transfers.json", {"scope":"listing control-transfer inventory; computed destinations and exception edges not resolved", "records":controls})
    elf = Elf(ROOT / "analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board")
    if hashlib.sha256(elf.data).hexdigest() != selected["target_sha256"]:
        raise ValueError("Current ELF digest mismatch")
    gp = 0x10cc310
    table_base = elf.word(gp-0x7fdc)
    switches = []
    for dispatch,offset,exit_address in ((0x55e82c,0x7c80,0x55ead4),(0x55f590,0x7c94,0x55f838)):
        table_address = table_base + offset
        targets = [(elf.word(table_address+i*4)+gp)&0xffffffff for i in range(5)]
        cases = []
        for i,target in enumerate(targets):
            end = targets[i+1] if i+1<len(targets) else exit_address
            calls = [x for x in selected["calls"] if target<=int(x["site"],16)<end]
            ids = {(x["argument_candidates_a0_a3"][1] or {}).get("value") for x in calls}
            if len(calls)!=4 or any(x.get("target_name_candidate")!="MImg::Set(unsigned short)" for x in calls) or len(ids)!=1:
                raise ValueError("Switch case differs from four-state image assignment evidence")
            cases.append({"widget_id":hex(0x50+i),"table_word_address":hex(table_address+i*4),
                          "raw_table_word":hex(elf.word(table_address+i*4)),"target":hex(target),"end_exclusive":hex(end),
                          "raw_words":[{"address":hex(a),"word":hex(elf.word(a))} for a in range(target,end,4)],
                          "image_id":hex(next(iter(ids))),"call_sites":[x["site"] for x in calls]})
        switches.append({"dispatch_site":hex(dispatch),"selector":"unsigned(GetID()-0x50)<5","default_target":hex(exit_address),
                         "gp":hex(gp),"GOT_base_slot":hex(gp-0x7fdc),"GOT_base_value":hex(table_base),
                         "table_address":hex(table_address),"cases":cases,"basis":"raw ELF table words plus instruction index callsite and literal ID candidates"})
    write(out / "switch-cases.json",switches)
    print(json.dumps({k:v for k,v in evidence.items() if k not in {"raw_call_target_counts", "missing_instruction_addresses", "incoming_calls", "raw_calls_in_listing_gaps"}}, ensure_ascii=False))


if __name__ == "__main__":
    main()
