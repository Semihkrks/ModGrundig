"""Join Home assembly candidates with parsed resource tables, read-only."""
from __future__ import annotations
import hashlib
import json
import re
from pathlib import Path
from map_ui_asset_dependencies import RC, Elf, parse_table

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "analiz/native/ui-four/home"


def main() -> None:
    trace = json.loads((BASE / "home-widget-trace.json").read_text())
    resource = json.loads((BASE / "home-create-analysis.json").read_text())
    lookup = {(x["kind"], x["id"]): x["table_candidates"] for x in resource["resources"]}
    strings = {}
    for language in ("Turkish", "English"):
        path = RC / f"rc_{language}" / "bin/Str_res.bin"
        info, records = parse_table(path)
        assert info["status"] == "fully_parsed"
        raw = path.read_bytes()
        strings[language] = (info, records, raw)
    by_allocation = {w["allocation"]: w["stored_fields"][0]["field"] for w in trace["widgets"]}
    widgets = []
    for item in trace["widgets"]:
        widget = dict(item)
        widget["parent_field"] = by_allocation.get(item["parent"], item["parent"])
        widget["rectangle"]["xywh_candidate_values_rc"] = [lookup[("Num", int(re.fullmatch(r"num\[(\d+)\]", value)[1]))][0]["value"] for value in item["rectangle"]["xywh"]]
        widget["background_images"] = []
        widget["foreground_image_setters"] = []
        widget["string_setters"] = []
        for call in trace["selected_setters_and_indirect_calls"]:
            args = call["arguments_o32_a0_a3_stack10"]
            if args[0] == item["allocation"] and call["target"].startswith("ImageButton::SetImg("):
                widget["foreground_image_setters"].append({"site": call["site"], "ids_in_SetImg_argument_order": call["image_argument_resource_ids"], "candidate_profiles": [lookup.get(("Image", value), []) for value in call["image_argument_resource_ids"]]})
            if not isinstance(args[0], str) or not args[0].startswith(item["allocation"] + "+"):
                continue
            if call["target"].startswith("MImg::Set("):
                widget["background_images"].append({"site": call["site"], "object": args[0], "id": args[1], "table_candidates": lookup.get(("Image", args[1]), [])})
            if call["target"].startswith("MString::Set("):
                labels = {}
                for language, (info, records, raw) in strings.items():
                    record = records[args[1]]
                    pos = record["payload_offset"]
                    labels[language] = {"text": raw[pos:pos + record["bytes_including_nul"] - 1].decode("utf-8"), "table": info["path"], "payload_offset": pos}
                widget["string_setters"].append({"site": call["site"], "object": args[0], "id": args[1], "candidate_languages": labels})
        widget["color_field_writes"] = []
        for store in trace["resource_field_stores"]:
            if store["destination"].startswith(item["allocation"] + "+") and store["resource_expression"].startswith("color["):
                value = int(re.fullmatch(r"color\[(\d+)\]", store["resource_expression"])[1])
                widget["color_field_writes"].append({**store, "id": value, "table_candidates": lookup.get(("Color", value), [])})
        widgets.append(widget)
    mufpath = ROOT / "analiz/dosya-sistemleri-tam/07_MSLIB/libmuf.so"
    muf = Elf(mufpath)
    evidence = [(0x2e21791c, "lw v0,0x38(sp): incoming last constructor argument after -0x28 frame"),
                (0x2e217928, "jalr t9: Container C2 candidate via GOT slot 0x2e2b490c"),
                (0x2e21792c, "sw v0,0x10(sp): forwards last argument in delay slot"),
                (0x2e21a728, "lw v0,0x38(sp): Container receives last argument"),
                (0x2e21a734, "jalr t9: MWidget C2 candidate via GOT slot 0x2e2b4b40"),
                (0x2e21a738, "sw v0,0x10(sp): forwards last argument in delay slot"),
                (0x2e258904, "move s5,a0: preserve this"),
                (0x2e258914, "lw s4,0x60(sp): last incoming argument after -0x50 frame"),
                (0x2e258acc, "sw s4,0x1a8(s5): stores last argument in widget ID field"),
                (0x2e24d420, "jr ra: MWidget::GetID"),
                (0x2e24d424, "lw v0,0x1a8(a0): ID return in delay slot")]
    bubble_pairs = []
    for pair in trace["bubble_help_pair_candidates"]:
        labels = {}
        for language, (info, records, raw) in strings.items():
            record = records[pair["field1"]]
            pos = record["payload_offset"]
            labels[language] = {"candidate_text": raw[pos:pos + record["bytes_including_nul"] - 1].decode("utf-8"), "table": info["path"], "payload_offset": pos}
        bubble_pairs.append({**pair, "field1_as_string_id_candidates": labels})
    output = {"target_sha256": trace["target_sha256"], "widget_count": len(widgets), "widgets": widgets, "bubble_help_pair_candidates": bubble_pairs,
              "last_constructor_argument_ID_evidence": {"module": str(mufpath.relative_to(ROOT)).replace('\\', '/'), "module_sha256": hashlib.sha256(mufpath.read_bytes()).hexdigest(), "kind": "raw_ELF_instruction_words_and_symbol_candidates", "instructions": [{"va": hex(a), "word": hex(muf.word(a)), "interpretation": text} for a, text in evidence]},
              "limitations": trace["limitations"] + ["Resource profile/language values are candidate table contents, not runtime selection.", "Widget ID role directly corroborated for AbsContainer->Container->MWidget chain; other subclass forwarding is not independently inspected here.", "Rectangles are initial local coordinates; LayoutItems may update them."]}
    (BASE / "home-widget-map.json").write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print("widgets", len(widgets), "background images", sum(len(x["background_images"]) for x in widgets), "string setters", sum(len(x["string_setters"]) for x in widgets), "color stores", sum(len(x["color_field_writes"]) for x in widgets))
    for widget in widgets:
        labels = [x["candidate_languages"]["Turkish"]["text"] for x in widget["string_setters"]]
        print(widget["stored_fields"][0]["field"], widget["id_candidate_last_argument"], widget["parent_field"], widget["rectangle"]["xywh_candidate_values_rc"], labels)


if __name__ == "__main__":
    main()
