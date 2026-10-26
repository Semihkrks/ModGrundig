"""Cross-check the reduced-inference whole C artifact against raw MIPS facts."""
import collections
import hashlib
import json
import re
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/"analiz/native/ui-four/settings"


def main():
    c_path=OUT/"reduced-recovery180/0055b6c0.c"
    text=c_path.read_text()
    lines=text.splitlines()
    gp_var=re.search(r"(\w+) = &_gp;",text).group(1)
    slot_mentions=collections.Counter(int(x,0) for x in re.findall(re.escape(gp_var)+r"\[(-?0x[0-9a-f]+|[0-9]+)\]",text))
    raw=json.loads((OUT/"raw-selected-calls.json").read_text())
    facts=[]
    names=["__dynamic_cast","MMainFrame::SwitchFocusTo(MWidget*)","MWidget::Hide()","MWidget::QueryFlag(unsigned char)",
           "MImg::Set(unsigned short)","ArUIManager::FindScrollLists(Container*, std::vector<ScrollListContainer*, std::allocator<ScrollListContainer*> >*, std::vector<AbsContainer*, std::allocator<AbsContainer*> >*)","abort","_Unwind_Resume"]
    for name in names:
        calls=[x for x in raw["calls"] if x.get("target_name_candidate")==name]
        slot=int(calls[0]["target_candidate"]["got_slot"],16)
        index=(slot-0x10cc310)//4
        count=slot_mentions[index]
        facts.append({"target":name,"GOT_slot":hex(slot),"C_GP_index":hex(index),"raw_call_candidates":len(calls),"C_slot_occurrences":count,"count_matches":count==len(calls),
                      "interpretation":"EH transfer absent from printed normal C; original LSDA/exception semantics are not reconstructed" if name=="_Unwind_Resume" else "static slot occurrence count; argument/type recovery remains disabled"})
        if name!="_Unwind_Resume":assert count==len(calls),(name,count,len(calls))
    cases=[]
    for switch in json.loads((OUT/"switch-cases.json").read_text()):
        for case in switch["cases"]:
            marker="case "+case["target"]+":"
            start=text.index(marker)
            next_case=text.find("case ",start+len(marker))
            close=re.search(r"(?m)^\s{0,8}\}",text[start:])
            stop=min(next_case if next_case>=0 else len(text),start+close.start() if close else len(text))
            body=text[start:stop]
            count=body.count(gp_var+"[-0x244]")
            assert count==4,(case["target"],count)
            cases.append({"raw_dispatch":switch["dispatch_site"],"case_entry":case["target"],"widget_id_from_raw_selector":case["widget_id"],"image_id_from_raw_arguments":case["image_id"],"C_line":text[:start].count("\n")+1,"C_MImg_Set_slot_occurrences":count,"raw_call_sites":case["call_sites"],
                          "argument_limit":"C prints no arguments for these GOT calls; image ID is established by raw instruction arguments, not inferred from empty C call syntax"})
    signature=next((i+1,line) for i,line in enumerate(lines) if "NewUI_Settings(ArUIManager *manager,MMainFrame *frame)" in line)
    focus=next((i+1,line) for i,line in enumerate(lines) if "if (" in line and "+ 0x3c)" in line and "+ 0x180)" in line and "==" in line)
    assert "[-0xda8]" in "\n".join(lines[focus[0]-1:focus[0]+3])
    result={"C_source":str(c_path.relative_to(ROOT)),"C_sha256":hashlib.sha256(c_path.read_bytes()).hexdigest(),"C_bytes":c_path.stat().st_size,"C_lines":len(lines),
            "classification":"full-range C control-flow artifact with protorecovery/protorecovery_b/localrecovery disabled; not fully typed original source or default full-recovery C",
            "input_signature":{"C_line":signature[0],"text":signature[1],"raw_evidence":["0x55b6e8 saves manager a0","0x55b6ec saves frame a1","0x55b718 loads saved frame as MoveWindowTo receiver"]},
            "focus_condition":{"C_line":focus[0],"text":focus[1].strip(),"raw_branch":"0x55f868","raw_call":"0x55f884","C_call_GOT_index":"-0xda8","comparison":"frame+0x3c == frame+0x180"},
            "critical_GOT_call_counts":facts,"switch_cases":cases,
            "goto_Antenna_labels":{"LAB_00566240":"0x566240 fallback test","LAB_005662d4":"0x5662d4 accepted +0x184/+0x188 child identity"},
            "normal_return_C_lines":[i+1 for i,line in enumerate(lines) if line.strip()=="return;"],
            "limitations":["No statement establishes runtime device observations.","C callees often retain zero printed arguments and extraout temporaries; raw assembly/resource map is primary for argument values.","C declares void, but input ABI helper preserved undefined return metadata; original return semantics are not proven by printer inference.","37 raw _Unwind_Resume sites are not printed as normal C calls; implicit exception/LSDA edges remain separate.","C-only mode has no usable HighFunction/pcode; the firstpass flow result is a separate diagnostic query."]}
    (OUT/"C-raw-crosscheck.json").write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n")
    print(json.dumps({"bytes":result["C_bytes"],"lines":result["C_lines"],"verified_cases":len(cases),"critical_matching_call_groups":sum(x["count_matches"] for x in facts),"exception_transfer_printed":facts[-1]["C_slot_occurrences"]}))


if __name__=="__main__":main()
