"""Cross-check completed Home C against retained assembly candidates."""
import hashlib
import json
import re
from pathlib import Path
from map_ui_asset_dependencies import arguments, constant

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "analiz/native/ui-four/home"
RUN = BASE / "conly600"


def main() -> None:
    cpath = RUN / "00d42150.c"
    c = cpath.read_text(encoding="utf-8")
    report = json.loads((RUN / "00d42150.json").read_text(encoding="utf-8"))
    previous = json.loads((BASE / "bounded300/00d42150.json").read_text(encoding="utf-8"))
    trace = json.loads((BASE / "home-widget-trace.json").read_text(encoding="utf-8"))
    pattern = r"\b(AbsContainer|ImageButton|TextBox|ScrollListContainer|Button)::\1\s*\("
    constructors = list(re.finditer(pattern, c))
    checks = []
    for match, widget in zip(constructors, trace["widgets"]):
        args, end = arguments(c, match.end())
        expected_field = widget["stored_fields"][0]["field"].split("+")[1]
        store = re.search(r"\*\([^;]*?\*\*\)\(param_1 \+ (0x[0-9a-f]+|[0-9]+)\)\s*=\s*" + re.escape(args[0]) + r"\s*;", c[end:end + 220])
        checks.append({"constructor_va": widget["constructor_va"], "c_line": c.count("\n", 0, match.start()) + 1,
                       "constructor_class_matches": match[1] == widget["constructor"].split("::")[0],
                       "c_arguments": args, "five_arguments_present": len(args) == 5,
                       "last_two_arguments_match_assembly": len(args) == 5 and [constant(x) for x in args[-2:]] == [widget["constructor_arg3"], widget["constructor_arg4"]],
                       "ownership_store_matches_assembly": bool(store) and constant(store[1]) == constant(expected_field)})
    markers = sorted({int(value, 16) for value in re.findall(r"(?:LAB_|from |to |@ )([0-9a-f]{8})", c)})
    outside = [hex(value) for value in markers if not 0xd42150 <= value < 0xd58d68]
    target = ROOT / "analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board"
    result = {"target_sha256_actual": hashlib.sha256(target.read_bytes()).hexdigest(),
              "target_sha256_expected": "51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916",
              "decompile_complete": report["decompile_complete"], "c_bytes": cpath.stat().st_size, "c_lines": len(c.splitlines()), "c_sha256": hashlib.sha256(cpath.read_bytes()).hexdigest(),
              "c_entry_prototype": c.splitlines()[1],
              "instruction_inventory_identical_between_runs": [(x["address"], x["instruction"]) for x in report["instructions"]] == [(x["address"], x["instruction"]) for x in previous["instructions"]],
              "instruction_count": report["instruction_count"], "constructor_c_count": len(constructors), "constructor_assembly_count": len(trace["widgets"]),
              "constructor_checks": checks, "constructor_mismatch_count": sum(not all(x[k] for k in ("constructor_class_matches", "five_arguments_present", "last_two_arguments_match_assembly", "ownership_store_matches_assembly")) for x in checks),
              "c_control_flow_markers_checked": len(markers), "c_control_flow_markers_outside_fde": outside,
              "pcode_body_check": "unavailable_syntax_tree_false",
              "raw_run_caveat": "Run JSON high_function_present=true/decompiler_pcode_within_selected_body=true are empty/prototype-object artifacts. pcode_export_complete=false and syntax_tree_requested=false take precedence; no pcode containment claim is made.",
              "prototype_caveats": ["MImg::Set and MString::Set C omit the explicit numeric resource argument; use raw MIPS O32 argument evidence.", "ImageButton::SetImg C lists only three image references after an incorrectly inferred this; raw assembly passes widget plus four references, including stack+0x10.", "Inferred entry prototype agrees with a0 object use and normal v0=0 return, but event framework parameters are not fully reconstructed."],
              "target_executed": False, "target_modified": False}
    assert result["target_sha256_actual"] == result["target_sha256_expected"]
    assert result["decompile_complete"] and result["instruction_inventory_identical_between_runs"]
    assert result["constructor_c_count"] == result["constructor_assembly_count"] == 60
    assert result["constructor_mismatch_count"] == 0, [{k: v for k, v in row.items() if k != "c_arguments"} for row in checks if not all(row[k] for k in ("constructor_class_matches", "five_arguments_present", "last_two_arguments_match_assembly", "ownership_store_matches_assembly"))]
    assert not outside
    (BASE / "home-validation.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in result.items() if k not in ("constructor_checks", "prototype_caveats")}, indent=2))


if __name__ == "__main__":
    main()
