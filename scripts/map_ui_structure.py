#!/usr/bin/env python3
"""Inventory UI class declarations, RTTI/vtables and 7-u32 message-map candidates.

Reads original ELF section/symbol records, not readelf's display annotations.
No target execution, Ghidra session, file extraction or symlink following.
Only a tiny straight-line constant getter is interpreted symbolically; general
MIPS call-site analysis belongs to map_mips_calls.py, not this tool.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import stat
import struct
import subprocess


PROJECT = Path(__file__).resolve().parents[1]
APP = "08_APP/bin/dvbt_board"
CLASS_PATTERN = re.compile(
    r"(?:Frame|Screen|Applet|Application|Dialog|Popup|PopUp|Window|Menu|Page|App|AppMan|AppManager|FrameManager)$"
)
CORE_CLASSES = {"ArUIManager", "UIAppMan", "CommonFrame", "MMainFrame", "MApplet", "MApplication", "MApp"}
FOCUS_CLASSES = {
    "CommonFrame", "HomePageFrame", "ToolsMenuFrame", "GeneralSettingsFrame",
    "QuickSettingsFrame", "SoundSettingsFrame", "PictureSettingsFrame",
    "InputSourceSelectFrame", "SourceSetupFrame", "VolumeControlFrame",
}
NAV_PATTERN = re.compile(r"Create|New|Run|Show|Hide|Kill|Close|Open|Activate|Switch|Navigate|Push|Pop|GetFrame|Animation|Swipe")
NAV_CALL_PATTERN = re.compile(
    r"CreateFrame|RunFrame|ShowFrame|HideFrame|KillFrame|CloseFrame|NewUI_Settings|"
    r"ShowWithSwipe|CloseWithSwipe|GetFrame|AddFrame|ActivateFrame|SetMainFrame|"
    r"RunApp|ExitApp|GetAnimationEnabled"
)


def hx(value: int) -> str:
    return f"0x{value:08x}"


def digest(path: Path) -> str:
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def stream_calls(path: Path, expected_target_hash: str):
    """Yield producer call rows without loading its ~194 MB JSON in memory.

    The producer's metadata/coverage precedes one top-level calls array. Search
    only its exact serialized property; bound both the prefix and each record.
    Nested quoted JSON keys would contain escaped quotes and do not match.
    """
    decoder = json.JSONDecoder()
    with path.open("r", encoding="utf-8") as stream:
        buffer = ""
        while True:
            chunk = stream.read(65536)
            if not chunk:
                raise ValueError("No calls array in static call inventory")
            buffer += chunk
            match = re.search(r'"calls"\s*:\s*\[', buffer)
            if match:
                source_hash = re.search(r'"target_sha256"\s*:\s*"([a-f0-9]{64})"', buffer)
                if not source_hash or source_hash.group(1) != expected_target_hash:
                    raise ValueError("Static call inventory target identity mismatch")
                buffer = buffer[match.end():]
                break
            if len(buffer) > 16 * 1024 * 1024:
                raise ValueError("Excessive call inventory prefix")
        while True:
            buffer = buffer.lstrip(" \t\r\n,")
            if buffer.startswith("]"):
                return
            try:
                row, consumed = decoder.raw_decode(buffer)
            except json.JSONDecodeError:
                chunk = stream.read(65536)
                if not chunk:
                    raise ValueError("Truncated calls array") from None
                buffer += chunk
                if len(buffer) > 2 * 1024 * 1024:
                    raise ValueError("Excessive call record")
                continue
            if not isinstance(row, dict):
                raise ValueError("Unexpected call inventory row")
            yield row
            buffer = buffer[consumed:]


def safe_source(root: Path, relative: str) -> Path:
    parts = PurePosixPath(relative).parts
    if not parts or PurePosixPath(relative).is_absolute() or any(p in {".", ".."} for p in parts):
        raise ValueError("Unsafe inventory path")
    current = root
    for part in parts:
        current /= part
        if stat.S_ISLNK(current.lstat().st_mode):
            raise ValueError("Source symlink refused: " + relative)
    if not stat.S_ISREG(current.lstat().st_mode):
        raise ValueError("ELF input is not a regular file")
    return current


class Elf:
    """Bounded ELF32 little-endian reader; st_shndx is authoritative."""
    def __init__(self, root: Path, inventory_row: dict):
        self.module = inventory_row["path"]
        self.path = safe_source(root, self.module)
        self.size = self.path.stat().st_size
        self.expected_hash = inventory_row["sha256"]
        self.stream = self.path.open("rb")
        header = self.read(0, 52)
        if header[:7] != b"\x7fELF\x01\x01\x01":
            raise ValueError("Unsupported ELF class/encoding")
        h = struct.unpack_from("<HHIIIIIHHHHHH", header, 16)
        if h[1] != 8:
            raise ValueError("Expected MIPS ELF")
        self.kind = h[0]
        phoff, shoff, phentsize, phnum, shentsize, shnum, shstr = h[4], h[5], h[8], h[9], h[10], h[11], h[12]
        if (phnum and phentsize != 32) or shentsize != 40 or not shnum or shstr >= shnum:
            raise ValueError("Unsupported extended/invalid ELF table layout")
        self.segments = [struct.unpack("<8I", self.read(phoff + i * phentsize, 32)) for i in range(phnum)]
        sections = [struct.unpack("<10I", self.read(shoff + i * shentsize, 40)) for i in range(shnum)]
        shnames = self.read(sections[shstr][4], sections[shstr][5])
        self.sections = []
        for index, values in enumerate(sections):
            name = self.string(shnames, values[0])
            self.sections.append(dict(zip(
                ("name_offset", "type", "flags", "va", "offset", "size", "link", "info", "alignment", "entry_size"), values
            ), name=name, index=index))
        self.symbols = []
        self.symbol_metadata = []
        for section in self.sections:
            if section["type"] not in (2, 11):
                continue
            if section["entry_size"] != 16 or section["link"] >= shnum or section["size"] % 16:
                raise ValueError("Invalid symbol table geometry")
            table = self.read(section["offset"], section["size"])
            strings = self.sections[section["link"]]
            names = self.read(strings["offset"], strings["size"])
            self.symbol_metadata.append({
                "section": section["name"], "offset": section["offset"],
                "entries": len(table) // 16, "table_sha256": hashlib.sha256(table).hexdigest(),
                "string_table_sha256": hashlib.sha256(names).hexdigest(),
            })
            for index in range(len(table) // 16):
                nameoff, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", table, index * 16)
                name = self.string(names, nameoff)
                if not name:
                    continue
                self.symbols.append({
                    "module": self.module, "table": section["name"], "symbol_index": index,
                    "symbol_record_offset": section["offset"] + index * 16,
                    "name": name, "value": value, "size": size,
                    "type": info & 15, "binding": info >> 4,
                    "other": other, "shndx": shndx, "defined": shndx != 0,
                })

    def read(self, offset: int, length: int) -> bytes:
        if offset < 0 or length < 0 or length > 64 * 1024 * 1024 or offset + length > self.size:
            raise ValueError("ELF read out of bounds")
        self.stream.seek(offset)
        data = self.stream.read(length)
        if len(data) != length:
            raise ValueError("Short ELF read")
        return data

    @staticmethod
    def string(table: bytes, offset: int) -> str:
        if offset >= len(table):
            raise ValueError("String table offset out of bounds")
        end = table.find(b"\0", offset, min(len(table), offset + 16384))
        if end < 0:
            raise ValueError("Unterminated or excessive symbol name")
        return table[offset:end].decode("utf-8", "surrogateescape")

    def file_offset(self, va: int, size: int = 4) -> int:
        # Relocatable objects use section-relative symbols; do not invent a VA.
        if self.kind == 1:
            raise ValueError("ET_REL address needs a section identity")
        for kind, offset, address, _, file_size, _, _, _ in self.segments:
            if kind == 1 and address <= va and va + size <= address + file_size:
                return offset + va - address
        raise ValueError("Address is not file backed: " + hx(va))

    def words(self, va: int, count: int = 1) -> tuple[int, ...]:
        return struct.unpack("<" + "I" * count, self.read(self.file_offset(va, count * 4), count * 4))

    def executable(self, va: int) -> bool:
        return any(kind == 1 and flags & 1 and base <= va < base + file_size
                   for kind, _, base, _, file_size, _, flags, _ in self.segments)


def demangle(names: set[str], command: str) -> dict[str, str]:
    ordered = sorted(names)
    result = {}
    for start in range(0, len(ordered), 1000):
        batch = ordered[start:start + 1000]
        proc = subprocess.run([command, "--format=gnu-v3"], input="\n".join(batch) + "\n",
                              text=True, capture_output=True, check=True, timeout=60)
        decoded = proc.stdout.splitlines()
        if len(decoded) != len(batch):
            raise ValueError("Demangler line count mismatch")
        result.update(zip(batch, decoded))
    return result


def identify_class(name: str, decoded: str) -> tuple[str | None, str | None]:
    for prefix, kind in (("typeinfo for ", "rtti"), ("vtable for ", "vtable"), ("typeinfo name for ", "rtti_name")):
        if decoded.startswith(prefix):
            return decoded[len(prefix):], kind
    text = re.sub(r"^(?:non-virtual|virtual) thunk to ", "", decoded).split("(", 1)[0]
    if "::" not in text:
        return None, None
    owner, method = text.rsplit("::", 1)
    if method == owner.rsplit("::", 1)[-1]:
        kind = "constructor"
    elif method == "~" + owner.rsplit("::", 1)[-1]:
        kind = "destructor"
    elif method in {"GetThisMessageMap", "GetMessageMap"}:
        kind = "message_map_getter"
    else:
        kind = "method"
    return owner, kind


def compact(symbol: dict) -> dict:
    return {
        "module": symbol["module"], "address": hx(symbol["value"]),
        "size": symbol["size"], "name": symbol["name"],
        "demangled": symbol.get("demangled", symbol["name"]),
        "defined": symbol["defined"], "st_shndx": symbol["shndx"],
        "st_type": symbol["type"], "st_binding": symbol["binding"], "st_other": symbol["other"],
        "symbol_table": symbol["table"], "symbol_index": symbol["symbol_index"],
        "symbol_record_file_offset": symbol["symbol_record_offset"],
        "role": symbol.get("role"),
    }


def constant_getter(elf: Elf, symbol: dict) -> dict:
    """Symbolically evaluate a small, call-free MIPS constant-return getter."""
    registers: list[int | None] = [None] * 32
    registers[0], registers[25] = 0, symbol["value"]
    evidence = []
    end_after_delay = False
    try:
        length = min(symbol["size"] or 128, 256)
        for relative in range(0, length - 3, 4):
            va = symbol["value"] + relative
            word = elf.words(va)[0]
            opcode, rs, rt, rd, function = word >> 26, (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, word & 63
            immediate = word & 65535
            signed = immediate - 65536 if immediate & 32768 else immediate
            evidence.append({"va": hx(va), "file_offset": elf.file_offset(va), "word": hx(word)})
            returning = False
            if word == 0:
                pass
            elif opcode == 15:
                registers[rt] = immediate << 16
            elif opcode == 9:
                registers[rt] = None if registers[rs] is None else (registers[rs] + signed) & 0xFFFFFFFF
            elif opcode == 0 and function in (33, 37):
                a, b = registers[rs], registers[rt]
                registers[rd] = None if a is None or b is None else ((a + b) if function == 33 else (a | b)) & 0xFFFFFFFF
            elif opcode == 35:
                base = registers[rs]
                registers[rt] = None if base is None else elf.words((base + signed) & 0xFFFFFFFF)[0]
            elif opcode == 43 and rs in (29, 30):
                pass  # A stack save has no bearing on the returned constant.
            elif opcode == 0 and function == 8 and rs == 31:
                returning = True
            else:
                return {"status": "not_a_supported_call_free_getter", "instructions": evidence}
            registers[0] = 0
            if end_after_delay:
                if registers[2] is None:
                    return {"status": "return_value_unknown", "instructions": evidence}
                return {"status": "constant_return_resolved", "return_va": hx(registers[2]), "instructions": evidence}
            if returning:
                end_after_delay = True
        return {"status": "no_return_in_bounded_getter", "instructions": evidence}
    except (ValueError, struct.error) as error:
        return {"status": "unresolved", "reason": str(error), "instructions": evidence}


def build(args):
    inventory_path = PROJECT / "analiz/elf-envanteri.json"
    inventory = json.loads(inventory_path.read_text(encoding="utf-8"))
    functions_path = PROJECT / "analiz/native/dvbt_board/functions.json"
    ghidra_functions = json.loads(functions_path.read_text(encoding="utf-8"))
    ghidra_by_address = {int(row["address"], 16): row for row in ghidra_functions if not row["external"]}
    fde_path = PROJECT / "analiz/ui-fde-araliklari.json"
    fdes = json.loads(fde_path.read_text())["records"] if fde_path.exists() else []
    fde_by_start = {int(row["start"], 16): row for row in fdes}
    selection_path = PROJECT / "analiz/native/ui-targeted/main-selection.json"
    old_selection = json.loads(selection_path.read_text()) if selection_path.exists() else {"addresses": []}
    selected = {int(va, 16) for va in old_selection["addresses"]}
    elfs = {}
    issues = []
    try:
        for item in sorted(inventory["elfs"], key=lambda row: row["path"]):
            elfs[item["path"]] = Elf(args.source_root, item)
        cpp_names = {s["name"] for elf in elfs.values() for s in elf.symbols if s["name"].startswith("_Z")}
        decoded_names = demangle(cpp_names, args.cxxfilt)
        symbols, unique = [], set()
        for elf in elfs.values():
            for symbol in elf.symbols:
                # Prefer dynsym when the same declaration also exists in symtab.
                identity = (symbol["module"], symbol["name"], symbol["value"], symbol["shndx"])
                if identity in unique:
                    continue
                unique.add(identity)
                symbol["demangled"] = decoded_names.get(symbol["name"], symbol["name"])
                symbol["owner"], symbol["role"] = identify_class(symbol["name"], symbol["demangled"])
                if symbol["role"] == "method" and symbol["type"] != 2:
                    symbol["role"] = "static_data_or_nonfunction_member"
                symbols.append(symbol)
        event_classes = {s["owner"] for s in symbols if s["role"] == "message_map_getter" and s["owner"]}

        def is_ui(name):
            return name in CORE_CLASSES or name in event_classes or bool(CLASS_PATTERN.search(name.rsplit("::", 1)[-1]))

        classes = defaultdict(list)
        by_address = defaultdict(list)
        for symbol in symbols:
            if symbol["defined"] and symbol["value"]:
                by_address[(symbol["module"], symbol["value"])].append(symbol)
            if symbol["owner"] and is_ui(symbol["owner"]):
                classes[symbol["owner"]].append(symbol)

        global_by_address = defaultdict(list)
        for symbol in symbols:
            if symbol["defined"] and symbol["value"]:
                global_by_address[symbol["value"]].append(symbol)

        def pointer_targets(module, address):
            targets = by_address.get((module, address), []) or global_by_address.get(address, [])
            return [compact(s) for s in targets]

        def function_info(module, address):
            info = {"address": hx(address), "symbol_candidates": pointer_targets(module, address)}
            if module == APP and address in ghidra_by_address:
                info["ghidra_function"] = ghidra_by_address[address]
            if module == APP and address in fde_by_start:
                info["fde_range"] = fde_by_start[address]
            info["owning_module_executable_range"] = elfs[module].executable(address)
            return info

        class_records, rtti_records, vtable_records, message_maps = [], [], [], []
        getter_keys, map_by_key = set(), {}
        for classname, members in sorted(classes.items()):
            definitions = [s for s in members if s["defined"]]
            kinds = Counter(s["role"] for s in definitions)
            class_records.append({
                "class_candidate": classname,
                "ui_classification": "message_map_declaration" if classname in event_classes else "class_spelling_candidate",
                "declared_modules": sorted({s["module"] for s in members}),
                "definition_role_counts": dict(sorted(kinds.items())),
                "has_defined_rtti": bool(kinds["rtti"]), "has_defined_vtable": bool(kinds["vtable"]),
                "members": [compact(s) for s in sorted(members, key=lambda s: (s["module"], s["value"], s["name"]))],
            })
            for symbol in definitions:
                elf, role = elfs[symbol["module"]], symbol["role"]
                if role == "rtti":
                    record = {"class_candidate": classname, "symbol": compact(symbol)}
                    try:
                        words = elf.words(symbol["value"], symbol["size"] // 4)
                        record.update(file_offset=elf.file_offset(symbol["value"], symbol["size"]), raw_words=[hx(w) for w in words])
                        if symbol["size"] == 12:
                            record["layout"] = "Itanium_single_inheritance_typeinfo_candidate"
                            record["base_typeinfo_pointer"] = hx(words[2])
                            record["base_typeinfo_symbols"] = pointer_targets(symbol["module"], words[2])
                        elif symbol["size"] == 8:
                            record["layout"] = "Itanium_class_typeinfo_candidate"
                        else:
                            record["layout"] = "other_or_multiple_inheritance_raw_only"
                        record["status"] = "file_backed_rtti_metadata"
                    except (ValueError, struct.error) as error:
                        record.update(status="not_file_backed_or_unsupported", reason=str(error))
                    rtti_records.append(record)
                elif role == "vtable":
                    record = {"class_candidate": classname, "symbol": compact(symbol)}
                    try:
                        words = elf.words(symbol["value"], symbol["size"] // 4)
                        record.update(status="file_backed_vtable_words", file_offset=elf.file_offset(symbol["value"], symbol["size"]),
                                      offset_to_top_raw=hx(words[0]), typeinfo_pointer=hx(words[1]), slots=[])
                        for index, value in enumerate(words[2:]):
                            record["slots"].append({
                                "slot_offset_from_primary_address_point": index * 4,
                                "slot_va": hx(symbol["value"] + 8 + index * 4),
                                "slot_file_offset": elf.file_offset(symbol["value"] + 8 + index * 4),
                                "value": hx(value), "function_or_symbol_candidates": pointer_targets(symbol["module"], value),
                                "owning_module_executable_range": elf.executable(value),
                            })
                    except (ValueError, struct.error) as error:
                        record.update(status="not_file_backed_or_unsupported", reason=str(error))
                    vtable_records.append(record)
                elif role == "message_map_getter" and symbol["type"] == 2:
                    key = (symbol["module"], symbol["value"])
                    if key in getter_keys:
                        continue
                    getter_keys.add(key)
                    getter = constant_getter(elf, symbol)
                    record = {"module": symbol["module"], "class_candidate": classname,
                              "getter": compact(symbol), "getter_analysis": getter, "records": []}
                    if getter["status"] == "constant_return_resolved":
                        mp = int(getter["return_va"], 16)
                        try:
                            base_getter, entries = elf.words(mp, 2)
                            record.update(map_va=hx(mp), map_file_offset=elf.file_offset(mp, 8),
                                          base_getter=function_info(symbol["module"], base_getter),
                                          entries_va=hx(entries))
                            for index in range(10000):
                                va = entries + index * 28
                                words = elf.words(va, 7)
                                if not any(words):
                                    record.update(status="terminated_7u32_map_candidate", terminator_va=hx(va), terminator_file_offset=elf.file_offset(va, 28))
                                    break
                                record["records"].append({
                                    "index": index, "record_va": hx(va), "record_file_offset": elf.file_offset(va, 28),
                                    "raw_u32": list(words), "event_value": hx(words[0]),
                                    "selector_fields_raw": list(words[1:5]),
                                    "handler": function_info(symbol["module"], words[5]),
                                    "member_pointer_adjustment_raw": hx(words[6]),
                                    "evidence": "binary_7u32_table_pointer_candidate_not_runtime_dispatch",
                                })
                            else:
                                record["status"] = "record_limit_without_terminator"
                        except (ValueError, struct.error) as error:
                            record.update(status="map_read_failed_or_partial", reason=str(error))
                    else:
                        record["status"] = "getter_not_resolved"
                    map_by_key[(symbol["module"], classname)] = record
                    message_maps.append(record)

        for record in message_maps:
            if record["status"] == "getter_not_resolved":
                record["same_class_static_map_candidates"] = [
                    {"getter_address": other["getter"]["address"], "map_va": other["map_va"],
                     "evidence": "same_class_GetThisMessageMap_declaration_not_runtime_virtual_dispatch"}
                    for other in message_maps
                    if other["module"] == record["module"] and other["class_candidate"] == record["class_candidate"]
                    and other["status"] == "terminated_7u32_map_candidate"
                ]

        event_roles = defaultdict(list)
        for record in message_maps:
            for entry in record["records"]:
                for symbol in entry["handler"]["symbol_candidates"]:
                    name = symbol["demangled"]
                    method = name.split("(", 1)[0].rsplit("::", 1)[-1]
                    if method in {"OnCreate", "OnDestroy", "OnKey", "OnPaint", "OnTimer", "TimerEventHandler",
                                  "OnMouseMotion", "OnMouseButtonDown", "OnMouseButtonUp", "OnMouseWheel", "OnPickOn"}:
                        observation = {
                            "named_handler": name, "module": record["module"],
                            "map_record_va": entry["record_va"], "handler_va": entry["handler"]["address"],
                            "method_role": method,
                        }
                        if observation not in event_roles[entry["event_value"]]:
                            event_roles[entry["event_value"]].append(observation)
        for record in message_maps:
            for entry in record["records"]:
                entry["event_role_candidates_from_named_handlers"] = sorted({
                    row["method_role"] for row in event_roles.get(entry["event_value"], [])
                })

        # Independent bounded strings: pure class-like identifiers only. These
        # are not promoted to class declarations, and no arbitrary data is output.
        string_candidates = []
        string_re = re.compile(rb"[A-Za-z_0-9:]{5,128}(?=\x00)")
        identifier_re = re.compile(r"^\d*([A-Za-z_][A-Za-z_0-9:]{3,95})$")
        for elf in elfs.values():
            if elf.kind == 1:
                continue
            for section in elf.sections:
                if section["name"] not in {".rodata", ".data.rel.ro", ".data"} or section["type"] == 8:
                    continue
                data = elf.read(section["offset"], section["size"])
                for match in string_re.finditer(data):
                    if match.start() and data[match.start() - 1] != 0:
                        continue
                    text = match.group().decode("ascii")
                    identifier = identifier_re.fullmatch(text)
                    if not identifier:
                        continue
                    possible_class = identifier.group(1)
                    if not CLASS_PATTERN.search(possible_class) and possible_class not in CORE_CLASSES:
                        continue
                    string_candidates.append({
                        "module": elf.module, "section": section["name"], "file_offset": section["offset"] + match.start(),
                        "va": hx(section["va"] + match.start()), "text": text,
                        "class_name_candidate": possible_class,
                        "also_declared_by_symbol": possible_class in classes,
                        "evidence": "identifier_string_only_not_class_definition_or_xref",
                    })

        navigation_apis = [compact(s) for s in symbols if s["owner"] in CORE_CLASSES and s["defined"] and s["role"] in {"method", "constructor", "destructor"}
                           and NAV_PATTERN.search(s["demangled"])]
        vtable_function_contexts = defaultdict(list)
        for table in vtable_records:
            if table["symbol"]["module"] != APP:
                continue
            for slot in table.get("slots", []):
                if not slot["owning_module_executable_range"]:
                    continue
                vtable_function_contexts[int(slot["value"], 16)].append({
                    "class_candidate": table["class_candidate"],
                    "vtable_va": table["symbol"]["address"], "slot_va": slot["slot_va"],
                    "slot_offset": slot["slot_offset_from_primary_address_point"],
                    "evidence": "raw_defined_vtable_slot_code_pointer_not_runtime_instance",
                })
        callback_contexts = defaultdict(list)
        for message_map in message_maps:
            if message_map["module"] != APP:
                continue
            for entry in message_map["records"]:
                context = {"class_candidate": message_map["class_candidate"],
                           "event_value": entry["event_value"],
                           "map_record_va": entry["record_va"]}
                callback_contexts[int(entry["handler"]["address"], 16)].append(context)
        declared_function_owners = defaultdict(set)
        for symbol in symbols:
            if symbol["module"] == APP and symbol["defined"] and symbol["type"] == 2 and symbol["owner"] in classes:
                declared_function_owners[symbol["value"]].add(symbol["owner"])
        calls_path = PROJECT / "analiz/ui-kod-cagrilari.json"
        navigation_calls, call_count = [], 0
        if calls_path.exists():
            for ordinal, call in enumerate(stream_calls(calls_path, elfs[APP].expected_hash)):
                call_count += 1
                name = call.get("target_name_candidate") or ""
                target = call.get("target_candidate") or {}
                owner, role = identify_class(target.get("symbol", ""), name)
                frame_constructor = role == "constructor" and owner in classes and (
                    owner in CORE_CLASSES or CLASS_PATTERN.search(owner.rsplit("::", 1)[-1])
                )
                core_navigation = owner in CORE_CLASSES and bool(NAV_PATTERN.search(name.split("::", 1)[-1]))
                if not frame_constructor and not core_navigation and not NAV_CALL_PATTERN.search(name):
                    continue
                source_address = int(call["function_address"], 16)
                navigation_calls.append({
                    "source_call_record_ordinal": ordinal,
                    "function_address": hx(source_address), "function_name": call["function"],
                    "source_declared_class_candidates": sorted(declared_function_owners.get(source_address, [])),
                    "source_vtable_contexts": vtable_function_contexts.get(source_address, []),
                    "source_message_map_contexts": callback_contexts.get(source_address, []),
                    "call_site_va": call["site"], "call_site_file_offset": elfs[APP].file_offset(int(call["site"], 16)),
                    "target_name_candidate": name, "target_class_candidate": owner,
                    "edge_kind": "class_constructor_call_candidate" if frame_constructor else "navigation_API_call_candidate",
                    "target_candidate": target, "resolution": call["resolution"],
                    "argument_candidates_a0_a3": call.get("argument_candidates_a0_a3", []),
                    "evidence": "existing_static_call_inventory_including_its_PIC_ABI_and_path_feasibility_limitations",
                })
        creation_links = []
        for call in navigation_calls:
            target_class = call["target_class_candidate"] or ""
            app_owners = sorted({owner for owner in call["source_declared_class_candidates"]
                                 if owner.endswith(("App", "Applet", "Application"))} |
                                {row["class_candidate"] for row in call["source_vtable_contexts"]
                                 if row["class_candidate"].endswith(("App", "Applet", "Application"))})
            if call["edge_kind"] != "class_constructor_call_candidate" or not target_class.endswith("Frame") or not app_owners:
                continue
            creation_links.append({
                "application_class_candidates": app_owners, "frame_class_candidate": target_class,
                "factory_function_address": call["function_address"], "factory_function_name": call["function_name"],
                "constructor_call_site_va": call["call_site_va"],
                "constructor_target": call["target_name_candidate"],
                "source_call_record_ordinal": call["source_call_record_ordinal"],
                "source_vtable_contexts": call["source_vtable_contexts"],
                "evidence": "application_method_symbol_or_vtable_code_pointer_then_declared_frame_constructor_call_candidate",
            })
        applet_base_slots = [
            dict(slot, base_vtable_module=table["symbol"]["module"], base_vtable_va=table["symbol"]["address"])
            for table in vtable_records if table["class_candidate"] == "MApplet"
            for slot in table.get("slots", [])
        ]
        for link in creation_links:
            offsets = {row["slot_offset"] for row in link["source_vtable_contexts"]}
            link["MApplet_base_slot_comparison_candidates"] = [
                {"module": slot["base_vtable_module"], "base_vtable_va": slot["base_vtable_va"],
                 "slot_va": slot["slot_va"], "offset": slot["slot_offset_from_primary_address_point"],
                 "named_target_candidates": [symbol["demangled"] for symbol in slot["function_or_symbol_candidates"]],
                 "evidence": "same_virtual_slot_offset_of_MApplet_base_not_runtime_dispatch"}
                for slot in applet_base_slots if slot["slot_offset_from_primary_address_point"] in offsets
            ]
        snippets, pseudocode_inputs = [], []
        # Preserve line evidence rather than guessing indirect calls from text.
        for directory in ("analiz/native/dvbt_board", "analiz/native/ui-targeted/dvbt_board"):
            for source in sorted((PROJECT / directory).glob("*.c")):
                address = int(source.stem, 16)
                function = ghidra_by_address.get(address, {})
                if not re.search(r"CommonFrame|ArUIManager|HomePageFrame|ToolsMenuFrame|SettingsFrame|SourceSelectFrame", function.get("name", "")):
                    continue
                source_bytes = source.read_bytes()
                pseudocode_inputs.append({"path": str(source.relative_to(PROJECT)).replace("\\", "/"),
                                          "bytes": len(source_bytes), "sha256": hashlib.sha256(source_bytes).hexdigest()})
                for line_number, line in enumerate(source_bytes.decode("utf-8", errors="replace").splitlines(), 1):
                    if re.search(r"(?:[A-Za-z_]\w*::)?(?:RunFrame|ShowFrame|HideFrame|KillFrame|CreateFrame|NewUI_Settings|GetFrame|ShowWithSwipe|CloseWithSwipe|SetAnimation|StartAnimation)\s*\(", line):
                        snippets.append({"source": str(source.relative_to(PROJECT)).replace("\\", "/"), "line": line_number,
                                         "function_address": hx(address), "text": line.strip(),
                                         "evidence": "decompiler_text_reference_not_runtime_or_new_machine_xref"})

        candidates = {}
        def candidate(module, address, priority, reason, owner=None, event=None):
            if module != APP or address in selected or not elfs[module].executable(address):
                return
            info = function_info(module, address)
            size = (fde_by_start.get(address) or {}).get("bytes") or ghidra_by_address.get(address, {}).get("body_bytes", 0)
            key = (module, address)
            row = candidates.setdefault(key, dict(info, module=module, priority=priority,
                                                  body_size_candidate=size, reasons=[], contexts=[]))
            row["priority"] = max(row["priority"], priority)
            if reason not in row["reasons"]:
                row["reasons"].append(reason)
            context = {"class_candidate": owner, "event_value": event}
            if context not in row["contexts"]:
                row["contexts"].append(context)

        for record in message_maps:
            owner, module = record["class_candidate"], record["module"]
            if owner not in FOCUS_CLASSES:
                continue
            for item in record["records"]:
                event, fields, address = int(item["event_value"], 16), item["selector_fields_raw"], int(item["handler"]["address"], 16)
                if owner == "CommonFrame":
                    candidate(module, address, 110, "shared_CommonFrame_event_handler", owner, hx(event))
                elif owner in {"ToolsMenuFrame", "QuickSettingsFrame"} and event == 0x16 and fields[0] == 0x13:
                    candidate(module, address, 105, "menu_click_notification_navigation_candidate", owner, hx(event))
                elif event in {1, 2, 0x14, 0x18}:
                    candidate(module, address, 100 if event in {1, 0x14} else 85, "focus_screen_lifecycle_key_timer_candidate", owner, hx(event))
                elif owner == "HomePageFrame":
                    candidate(module, address, 95, "home_page_notification_candidate", owner, hx(event))
        for symbol in symbols:
            if symbol["module"] == APP and symbol["owner"] in CORE_CLASSES and symbol["defined"] and symbol["type"] == 2:
                if NAV_PATTERN.search(symbol["demangled"].split("::", 1)[-1]) and symbol["size"] <= 8192:
                    priority = 115 if symbol["owner"] == "ArUIManager" and "::GetFrame(" in symbol["demangled"] else 95
                    candidate(APP, symbol["value"], priority, "small_shared_navigation_api", symbol["owner"])
        for link in creation_links:
            if link["frame_class_candidate"] in FOCUS_CLASSES:
                candidate(APP, int(link["factory_function_address"], 16), 108,
                          "focus_application_vtable_factory_calls_frame_constructor",
                          ",".join(link["application_class_candidates"]))
        ordered_candidates = sorted(candidates.values(), key=lambda row: (-row["priority"], row["body_size_candidate"] or 1 << 30, row["address"]))
        shortlist = ordered_candidates[:args.selection_limit]
        selection = {
            "schema_version": 1, "target": APP, "target_sha256_from_inventory": elfs[APP].expected_hash,
            "existing_selection": "analiz/native/ui-targeted/main-selection.json",
            "existing_selection_count": len(selected), "available_new_candidates": len(ordered_candidates),
            "addresses": [row["address"][2:] for row in shortlist],
            "decompile_timeout_seconds": 30, "seed_t9_entry": True,
            "candidate_evidence": shortlist,
            "function_boundary_candidates": {
                row["address"][2:]: {"bytes": row["fde_range"]["bytes"],
                                        "end_exclusive": row["fde_range"]["end_exclusive"],
                                        "basis": "existing_eh_frame_FDE_not_dynsym"}
                for row in shortlist if row.get("fde_range")
            },
            "limitations": ["Candidates are outside the existing 54-address selection; no decompilation is run here.",
                            "Sizes from FDE/Ghidra are boundary candidates; large or unbounded callback bodies need a separate query budget."],
        }
        output = {
            "schema_version": 1, "tool": "map_ui_structure.py", "firmware_executed": False,
            "symlinks_followed": False, "ghidra_project_opened": False,
            "inputs": {"elf_inventory_sha256": digest(inventory_path), "ghidra_functions_sha256": digest(functions_path),
                       "existing_selection_sha256": digest(selection_path) if selection_path.exists() else None,
                       "static_call_inventory_sha256": digest(calls_path) if calls_path.exists() else None,
                       "pseudocode_text_snapshots": pseudocode_inputs},
            "scope": "Exhaustive candidate inventory within available ELF symbols, supported constant getters and bounded class-identifier strings",
            "modules": [{"path": elf.module, "source_size": elf.size, "sha256_from_existing_inventory_not_recomputed": elf.expected_hash,
                         "raw_dynsym_import_count": sum(s["table"] == ".dynsym" and not s["defined"] and s["binding"] != 0 for s in elf.symbols),
                         "raw_dynsym_export_count": sum(s["table"] == ".dynsym" and s["defined"] and s["binding"] in (1, 2, 10) and s["other"] & 3 in (0, 3) for s in elf.symbols),
                         "raw_symbol_tables": elf.symbol_metadata} for elf in elfs.values()],
            "coverage": {"elf_modules_parsed": len(elfs), "raw_symbol_declarations_deduplicated": len(symbols),
                         "cpp_names_demangled": len(decoded_names), "ui_class_candidates": len(class_records),
                         "defined_rtti_records": len(rtti_records), "defined_vtable_records": len(vtable_records),
                         "defined_unique_message_map_getters": len(message_maps),
                         "message_map_status_counts": dict(sorted(Counter(m["status"] for m in message_maps).items())),
                         "message_map_entry_count": sum(len(m["records"]) for m in message_maps),
                         "unresolved_getters_with_same_class_static_map_candidate": sum(bool(m.get("same_class_static_map_candidates")) for m in message_maps),
                         "unique_message_map_handler_candidates": len({(m["module"], r["handler"]["address"]) for m in message_maps for r in m["records"]}),
                         "identifier_string_candidates": len(string_candidates), "navigation_api_declarations": len(navigation_apis),
                         "static_call_records_scanned": call_count, "navigation_and_constructor_call_candidates": len(navigation_calls),
                         "application_to_frame_constructor_link_candidates": len(creation_links),
                         "new_callback_shortlist": len(shortlist)},
            "class_candidates": class_records,
            "rtti_metadata": sorted(rtti_records, key=lambda row: (row["symbol"]["module"], row["symbol"]["address"])),
            "vtable_metadata": sorted(vtable_records, key=lambda row: (row["symbol"]["module"], row["symbol"]["address"])),
            "message_maps": sorted(message_maps, key=lambda row: (row["module"], row["getter"]["address"])),
            "event_role_observations": dict(sorted(event_roles.items())),
            "identifier_string_candidates": string_candidates,
            "navigation_api_declarations": sorted(navigation_apis, key=lambda row: (row["module"], row["address"], row["name"])),
            "navigation_and_constructor_calls": navigation_calls,
            "application_to_frame_constructor_links": creation_links,
            "existing_decompiler_navigation_text": snippets,
            "issues": issues,
            "limitations": [
                "A class name or method declaration does not prove that the class is an active UI screen.",
                "Stripped/local/anonymous classes with no recognized declaration can remain absent.",
                "Imported nonzero-valued MIPS PLT symbols remain imports because raw st_shndx is zero.",
                "RTTI/vtable metadata is static; copied BSS RTTI and secondary vtables can require relocation/runtime resolution.",
                "Seven-u32 event/member-pointer field roles are format candidates; named handler observations corroborate specific event roles but are not original enum source.",
                "Constant getters are bounded and call-free; unsupported getters remain explicit gaps.",
                "Pointer values, symbol declarations and decompiler text are different evidence; no runtime dispatch or screen-transition claim is made.",
                "No Ghidra process/project is opened. General MIPS call-site resolution is delegated to map_mips_calls.py.",
                "Source image hashes are inherited from the existing inventory; parsed symbol-section hashes are recomputed.",
            ],
        }
        v2_path = PROJECT / "analiz/envanter-v2/elf-envanteri.json"
        if v2_path.exists():
            v2 = json.loads(v2_path.read_text(encoding="utf-8"))
            modules = {m["path"]: m for m in output["modules"]}
            mismatches = []
            for item in v2["elfs"]:
                for expected, actual in (("dynamic_imports", "raw_dynsym_import_count"), ("dynamic_exports", "raw_dynsym_export_count")):
                    if modules[item["path"]][actual] != item["counts"][expected]:
                        mismatches.append({"module": item["path"], "kind": expected,
                                           "raw": modules[item["path"]][actual], "inventory_v2": item["counts"][expected]})
            output["independent_inventory_v2_comparison"] = {
                "path": "analiz/envanter-v2/elf-envanteri.json", "sha256": digest(v2_path),
                "modules_compared": len(v2["elfs"]), "mismatches": mismatches,
            }
        return output, selection
    finally:
        for elf in elfs.values():
            elf.stream.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source-root", type=Path, required=True)
    parser.add_argument("--cxxfilt", default="c++filt")
    parser.add_argument("--selection-limit", type=int, default=32)
    args = parser.parse_args()
    if not 1 <= args.selection_limit <= 64:
        parser.error("selection-limit must be in 1..64")
    output, selection = build(args)
    for path, content in ((PROJECT / "analiz/ui-yapi-haritasi.json", output),
                          (PROJECT / "analiz/ui-navigation-selection-candidates.json", selection)):
        with path.open("w", encoding="utf-8", newline="\n") as stream:
            json.dump(content, stream, ensure_ascii=True, indent=2)
            stream.write("\n")
    print(json.dumps({"coverage": output["coverage"], "issues": len(output["issues"]),
                      "selection_count": len(selection["addresses"])}))


if __name__ == "__main__":
    main()
