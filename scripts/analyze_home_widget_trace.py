"""Conservative sequential candidate trace of Home create widget setup.

This is an offline evidence aid, not an executable model or CFG interpreter.
Every emitted field relationship requires confirmation in the retained assembly.
"""
from __future__ import annotations
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "analiz/native/ui-four/home"


def main() -> None:
    report = json.loads((BASE / "bounded300/00d42150.json").read_text())
    raw = json.loads((BASE / "raw-calls.json").read_text())
    calls = {int(c["site"], 16): c for c in raw["calls"]}
    regs = {"a0": "this", "a1": "entry_a1", "a2": "entry_a2", "a3": "entry_a3", "sp": 0x10000000, "zero": 0}
    memory, rects, widgets, returned, setters, resource_stores, image_objects, bubble_pairs = {}, {}, [], {}, [], [], {}, []
    pending = None
    def add(value, amount):
        if value is None or amount is None:
            return None
        if isinstance(value, int):
            return value + amount
        if amount == 0:
            return value
        return f"{value}+{hex(amount)}"
    def number(text):
        try:
            return int(text, 0)
        except ValueError:
            return None
    def location(text):
        match = re.fullmatch(r"(-?0x[0-9a-f]+|[-0-9]+)\((\w+)\)", text)
        return add(regs.get(match[2]), number(match[1])) if match else None
    def call_at(site):
        call = calls.get(site)
        name = (call or {}).get("target_name_candidate") or "[unknown]"
        args = [regs.get(x) for x in ("a0", "a1", "a2", "a3")]
        args.append(memory.get(add(regs.get("sp"), 0x10)))
        if "vector<bubblehelppair" in name:
            bubble_pairs.append({"site": hex(site), "vector": args[0], "record_pointer": args[1], "field0": memory.get(args[1]), "field1": memory.get(add(args[1], 4))})
        if name == "[unknown]" or any(term in name for term in ("SetFlag(", "SetImg(", "MImg::Set(", "MString::Set(", "Hide()", "Show()", "HomePageFrame::", "BasicMode", "Hotel", "NetFlix")):
            row = {"site": hex(site), "target": name, "computed_target_expression": regs.get("t9"), "arguments_o32_a0_a3_stack10": args}
            if "ImageButton::SetImg(" in name:
                row["image_argument_resource_ids"] = [image_objects.get(value) for value in args[1:5]]
            setters.append(row)
        result = f"result@{hex(site)}"
        if "RcGetNum(" in name:
            result = f"num[{args[0]}]"
        elif "RcGetColor(" in name:
            result = f"color[{args[0]}]"
        elif name.startswith("operator new("):
            result = f"new@{hex(site)}"
        elif name.startswith("MImg::MImg("):
            image_objects[args[0]] = args[1]
        elif name.startswith("_Rect::set("):
            rects[args[0]] = {"callsite": hex(site), "xywh": args[1:5]}
        elif any(name.startswith(n) for n in ("AbsContainer::AbsContainer(", "ImageButton::ImageButton(", "TextBox::TextBox(", "ScrollListContainer::ScrollListContainer(", "Button::Button(")):
            widget = {"constructor_va": hex(site), "constructor": name, "allocation": args[0], "parent": args[1], "rectangle": rects.get(args[2]), "constructor_arg3": args[3], "constructor_arg4": args[4], "id_candidate_last_argument": args[4], "stored_fields": []}
            widgets.append(widget)
            returned[args[0]] = widget
        for reg in ("v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9"):
            regs.pop(reg, None)
        regs["v0"] = result
    for ins in report["instructions"]:
        mnemonic = ins["mnemonic"].lstrip("_")
        ops = [x["display"] for x in ins["operands"]]
        site = int(ins["address"], 16)
        if mnemonic in ("li", "lui"):
            regs[ops[0]] = number(ops[1])
            if mnemonic == "lui" and isinstance(regs[ops[0]], int):
                regs[ops[0]] <<= 16
        elif mnemonic in ("move", "clear"):
            regs[ops[0]] = regs.get(ops[1]) if mnemonic == "move" else 0
        elif mnemonic == "addiu":
            regs[ops[0]] = add(regs.get(ops[1]), number(ops[2]))
        elif mnemonic in ("addu", "or"):
            left, right = regs.get(ops[1]), regs.get(ops[2])
            regs[ops[0]] = add(left, right) if isinstance(right, int) else add(right, left) if isinstance(left, int) else None
        elif mnemonic == "lw":
            loc = location(ops[1])
            regs[ops[0]] = memory.get(loc, f"load({loc})" if isinstance(loc, str) else None)
        elif mnemonic == "sw":
            loc, value = location(ops[1]), regs.get(ops[0])
            if loc is not None:
                memory[loc] = value
                if isinstance(value, str) and value.startswith(("num[", "color[")) and isinstance(loc, str) and loc.startswith("new@"):
                    resource_stores.append({"site": hex(site), "destination": loc, "resource_expression": value})
                if isinstance(value, str) and value in returned and isinstance(loc, str) and loc.startswith("this+"):
                    returned[value]["stored_fields"].append({"store_va": hex(site), "field": loc})
        elif ops and ops[0] in regs and mnemonic not in ("jalr", "jr", "b", "beq", "bne", "bltz", "bgez", "blez", "bgtz", "nop") and not mnemonic.startswith("s"):
            regs.pop(ops[0], None)
        if pending is not None:
            call_at(pending)
            pending = None
        if site in calls:
            pending = site
    output = {"target_sha256": raw["target_sha256"], "evidence": "sequential_assembly_candidate_trace_not_CFG_execution", "widgets": widgets, "selected_setters_and_indirect_calls": setters, "resource_field_stores": resource_stores, "bubble_help_pair_candidates": bubble_pairs,
              "limitations": ["Only simple register and stack transfers are modeled; unsupported writes invalidate selected registers.", "Branch merges are not modeled. Relationships must be corroborated against assembly/C.", "No virtual setter semantics or event callback names are inferred.", "Integer IDs remain constructor arguments until their API role is corroborated."]}
    (BASE / "home-widget-trace.json").write_text(json.dumps(output, indent=2) + "\n")
    print("widgets", len(widgets), "field-bound", sum(bool(x["stored_fields"]) for x in widgets))


if __name__ == "__main__":
    main()
