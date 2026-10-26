"""Summarize existing offline Home create evidence; never executes target code."""
from __future__ import annotations

import collections
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
from map_ui_asset_dependencies import RC, parse_table  # read-only parser

BASE = ROOT / "analiz/native/ui-four/home"
START, END = 0xD42150, 0xD58D68


def main() -> None:
    run = BASE / (sys.argv[1] if len(sys.argv) > 1 else "conly600")
    report = json.loads((run / "00d42150.json").read_text(encoding="utf-8"))
    raw = json.loads((BASE / "raw-calls.json").read_text(encoding="utf-8"))
    instructions = report["instructions"]
    covered = {int(x["address"], 16) for x in instructions}
    missing = sorted(set(range(START, END, 4)) - covered)
    gaps = []
    for value in missing:
        if gaps and value == gaps[-1][1]:
            gaps[-1][1] += 4
        else:
            gaps.append([value, value + 4])
    calls = raw["calls"]
    counts = collections.Counter(x.get("target_name_candidate") or "[unknown]" for x in calls)
    tables = {}
    for profile in ("rc", "rc_Arcelik", "rc_Beko"):
        for kind in ("Num", "Color", "Image"):
            path = RC / profile / "bin" / f"{kind}_res.bin"
            if not path.exists():
                continue
            info, records = parse_table(path)
            assert info["status"] == "fully_parsed"
            tables[(profile, kind)] = (info, records)
    resources = []
    widgets = []
    previous_rect = None
    ctor_names = ("AbsContainer::AbsContainer(", "ScrollListContainer::ScrollListContainer(",
                  "TextBox::TextBox(", "ImageButton::ImageButton(", "Button::Button(")
    pcode_by_site = {int(x["instruction_address"], 16): x for x in report.get("decompiler_pcode_calls", [])}
    for call in calls:
        name = call.get("target_name_candidate") or "[unknown]"
        site = int(call["site"], 16)
        args = call["argument_candidates_a0_a3"]
        if name.startswith("_Rect::set("):
            previous_rect = call
        if name.startswith(ctor_names):
            widgets.append({"callsite": hex(site), "constructor": name,
                            "raw_arguments": args, "pcode_call": pcode_by_site.get(site),
                            "preceding_rect_call": previous_rect,
                            "scope": "preceding rect association is a sequential candidate; parent/field require C and assembly confirmation"})
        kind = "Num" if "RcGetNum(" in name else "Color" if "RcGetColor(" in name else "Image" if "MImg::Set(" in name or "MImg::MImg(" in name else None
        if kind is None:
            continue
        argument_index = 1 if kind == "Image" else 0
        value = (args[argument_index] or {}).get("value")
        candidates = []
        if value is not None:
            for profile in ("rc", "rc_Arcelik", "rc_Beko"):
                if (profile, kind) not in tables:
                    continue
                info, records = tables[(profile, kind)]
                if value < len(records):
                    record = records[value]
                    candidates.append({"profile": profile, "table": info["path"],
                                       "value": record if kind != "Image" else record["resource_path"]})
        resources.append({"site": hex(site), "kind": kind, "id": value, "id_argument_index": argument_index,
                          "target": name, "argument": args[argument_index], "table_candidates": candidates})
    selected_terms = ("Hide()", "Show()", "SetFlag(", "BasicMode", "Hotel", "NetFlix", "Usb", "HomePageFrame::", "HelpWidget::", "Register", "Animation", "AddTimer")
    semantic = [x for x in calls if any(term in (x.get("target_name_candidate") or "") for term in selected_terms)]
    summary = {
        "target_sha256": raw["target_sha256"], "evidence_kind": "direct_Ghidra_static_and_raw_MIPS_candidates_not_REA_Evidence",
        "source_run": run.name,
        "entry": hex(START), "end_exclusive": hex(END), "fde_bytes": END - START,
        "decompile_complete": report["decompile_complete"], "decompile_error": report["decompile_error"],
        "signature_inferred_unverified": report["signature"],
        "instruction_count": len(instructions), "expected_aligned_instruction_slots": (END - START) // 4,
        "missing_instruction_bytes": len(missing) * 4, "missing_instruction_ranges": [[hex(a), hex(b)] for a, b in gaps],
        "call_count_raw": len(calls), "raw_unknown_call_targets": counts["[unknown]"],
        "call_counts_by_target": dict(counts), "widget_constructor_count": len(widgets),
        "computed_call_count_ghidra": report["computed_callsite_count"],
        "pcode_call_count": len(report.get("decompiler_pcode_calls", [])),
        "pcode_export_complete": report.get("pcode_export_complete"),
        "pcode_outside_body": report.get("decompiler_pcode_addresses_outside_selected_body"),
        "pcode_body_check_status": "unavailable_syntax_tree_disabled_or_export_incomplete" if report.get("syntax_tree_requested") is False or not report.get("pcode_export_complete") else "available",
        "resource_calls": len(resources), "resource_unknown_ids": sum(x["id"] is None for x in resources),
        "resource_unique_ids": {k: sorted({x["id"] for x in resources if x["kind"] == k and x["id"] is not None}) for k in ("Num", "Color", "Image")},
        "resources": resources, "widget_constructor_candidates": widgets, "selected_behavior_calls": semantic,
        "input_report_sha256": hashlib.sha256((run / "00d42150.json").read_bytes()).hexdigest(),
        "target_executed": False, "target_modified": False,
        "limitations": ["Static target candidates are not runtime binding observations.",
                        "Widget hierarchy, rectangle stack values and virtual slot semantics require corroborating C/assembly.",
                        "Resource tables are candidate profiles; active device profile is unobserved.",
                        "Decompiler completion is not proof of recovered prototypes or all dynamic targets."]}
    output = BASE / "home-create-analysis.json"
    output.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in summary.items() if k not in ("resources", "widget_constructor_candidates", "selected_behavior_calls", "call_counts_by_target", "resource_unique_ids")}, ensure_ascii=False))


if __name__ == "__main__":
    main()
