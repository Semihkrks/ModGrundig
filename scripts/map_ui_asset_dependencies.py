"""Inventory OEM UI resources and static resource-call candidates, offline.

Only analiz/ui-asset-bagimliliklari.json is written. Firmware, extracted
programs, configuration scripts, and Ghidra are never executed.
"""
from __future__ import annotations

import collections
import hashlib
import json
import re
import struct
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TREE = ROOT / "analiz/dosya-sistemleri-tam"
RC = TREE / "08_APP/rc"
NATIVE = ROOT / "analiz/native"
OUTPUT = ROOT / "analiz/ui-asset-bagimliliklari.json"
CACHE: dict[Path, bytes] = {}
TYPE_NAMES = {0: "Bool_or_opaque", 1: "Num", 2: "Color", 3: "Str", 4: "font", 5: "Image", 6: "Clrkey"}


def rel(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


def read(path: Path) -> bytes:
    if path not in CACHE:
        CACHE[path] = path.read_bytes()
    return CACHE[path]


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def meta(path: Path) -> dict:
    data = read(path)
    return {"path": rel(path), "bytes": len(data), "sha256": sha(data)}


def geometry(data: bytes) -> dict:
    if data.startswith(b"\x89PNG\r\n\x1a\n"):
        result = {"format": "PNG", "signature_valid": True}
        if len(data) < 33 or data[12:16] != b"IHDR" or int.from_bytes(data[8:12], "big") != 13:
            return {**result, "status": "invalid_IHDR"}
        result.update(width=int.from_bytes(data[16:20], "big"), height=int.from_bytes(data[20:24], "big"),
                      bit_depth=data[24], color_type=data[25], interlace=data[28],
                      ihdr_crc_valid=zlib.crc32(data[12:29]) == int.from_bytes(data[29:33], "big"))
        pos, chunks, errors, iend = 8, 0, 0, False
        while pos + 12 <= len(data) and chunks < 10000:
            length = int.from_bytes(data[pos:pos + 4], "big")
            end = pos + 12 + length
            if end > len(data):
                break
            if zlib.crc32(data[pos + 4:end - 4]) != int.from_bytes(data[end - 4:end], "big"):
                errors += 1
            kind = data[pos + 4:pos + 8]
            chunks += 1
            pos = end
            if kind == b"IEND":
                iend = True
                break
        return {**result, "chunks": chunks, "chunk_crc_errors": errors, "iend_present": iend,
                "parsed_bytes": pos, "trailing_bytes": len(data) - pos,
                "status": "parsed_container" if iend and errors == 0 else "container_incomplete_or_crc_error",
                "pixels_decoded": False}
    if data[:6] in (b"GIF87a", b"GIF89a") and len(data) >= 10:
        return {"format": "GIF", "width": int.from_bytes(data[6:8], "little"),
                "height": int.from_bytes(data[8:10], "little"), "status": "header_only", "pixels_decoded": False}
    if data.startswith(b"\xff\xd8"):
        return {"format": "JPEG", "status": "signature_only", "pixels_decoded": False}
    return {"format": "unknown", "status": "not_decoded"}


def font_directory(data: bytes) -> dict:
    if len(data) < 12 or data[:4] not in (b"\0\x01\0\0", b"OTTO", b"true"):
        return {"status": "unrecognized_sfnt"}
    count = int.from_bytes(data[4:6], "big")
    if count > 512 or 12 + count * 16 > len(data):
        return {"status": "invalid_sfnt_directory"}
    records = []
    for i in range(count):
        tag, checksum, offset, size = struct.unpack_from(">4sIII", data, 12 + i * 16)
        records.append({"tag": tag.decode("ascii", "replace"), "offset": offset, "bytes": size,
                        "within_file": offset + size <= len(data)})
    return {"status": "sfnt_directory_parsed", "table_count": count, "tables": records,
            "glyphs_executed_or_rendered": False}


def parse_table(path: Path) -> tuple[dict, list]:
    data = read(path)
    info = meta(path)
    if len(data) < 56 or data[:4] != b"_tsm":
        return {**info, "status": "unrecognized_header"}, []
    words = struct.unpack_from("<14I", data)
    kind, count = words[2], words[7]
    info.update(type_id=kind, resource_kind=TYPE_NAMES.get(kind, "unknown"), declared_bytes=words[1],
                declared_record_count=count, data_offset=words[6], header_bytes=56,
                unmapped_header_fields="Opaque build-time values; not interpreted as portable pointers")
    if words[1] != len(data) or words[5:7] != (56, 56) or count > 100000:
        return {**info, "status": "header_boundary_mismatch"}, []
    records, pos = [], 56
    if kind in (1, 2, 6):
        if len(data) != 56 + count * 4:
            return {**info, "status": "scalar_size_mismatch"}, []
        records = list(struct.unpack_from(f"<{count}I", data, 56)) if count else []
        pos = len(data)
    elif kind in (3, 5) or (kind == 4 and count == 0):
        for index in range(count):
            if pos + 4 > len(data):
                return {**info, "status": "truncated_record_length", "parsed_records": index}, records
            size = struct.unpack_from("<I", data, pos)[0]
            end = pos + 4 + size
            if size < 1 or end > len(data) or data[end - 1] != 0:
                return {**info, "status": "invalid_string_range_or_nul", "parsed_records": index}, records
            raw = data[pos + 4:end - 1]
            record = {"id": index, "length_field_offset": pos, "payload_offset": pos + 4,
                      "bytes_including_nul": size, "payload_sha256": sha(raw)}
            if kind == 5:
                record["resource_path"] = raw.decode("utf-8", "strict")
            else:
                try:
                    raw.decode("utf-8", "strict")
                    record["utf8_valid"] = True
                except UnicodeDecodeError:
                    record["utf8_valid"] = False
            records.append(record)
            pos = end
    else:
        return {**info, "status": "opaque_header_only_count_not_validated" if len(data) == 56 else "opaque_payload",
                "body_bytes": len(data) - 56}, []
    status = "fully_parsed" if pos == len(data) else "trailing_unparsed_bytes"
    info.update(status=status, parsed_records=len(records), parsed_bytes=pos, trailing_bytes=len(data) - pos,
                body_sha256=sha(data[56:]), record_content_policy="String text omitted; hashes/boundaries only")
    if kind == 5:
        info["path_records"] = records
    return info, records


def parse_binary_profile(path: Path) -> dict:
    data = read(path)
    info = meta(path)
    if len(data) < 12 or data[:4] != b"_tsm":
        return {**info, "status": "unrecognized_binary_profile"}
    size, count = struct.unpack_from("<II", data, 4)
    if size != len(data) or count > 1000:
        return {**info, "status": "binary_profile_size_or_count_mismatch"}
    pos, entries = 12, []
    for index in range(count):
        if pos + 4 > len(data):
            return {**info, "status": "truncated_binary_profile"}
        length = struct.unpack_from("<I", data, pos)[0]
        end = pos + 4 + length
        if length < 1 or end > len(data) or data[end - 1] != 0:
            return {**info, "status": "binary_profile_record_boundary_mismatch"}
        entries.append({"index": index, "path_offset": pos + 4, "bytes_including_nul": length,
                        "path": data[pos + 4:end - 1].decode("utf-8", "strict")})
        pos = end
    return {**info, "header_bytes": 12, "record_count": count, "records": entries,
            "parsed_bytes": pos, "status": "fully_parsed" if pos == len(data) else "trailing_bytes",
            "scope": "Stored path records; their two runtime roles are not established here"}


class Elf:
    def __init__(self, path: Path):
        self.path, self.data = path, read(path)
        b = self.data
        if b[:6] != b"\x7fELF\x01\x01":
            raise ValueError("Not ELF32 little endian")
        po = struct.unpack_from("<I", b, 28)[0]
        pe, pn = struct.unpack_from("<HH", b, 42)
        self.loads = [struct.unpack_from("<8I", b, po + i * pe) for i in range(pn)]
        so = struct.unpack_from("<I", b, 32)[0]
        se, sn = struct.unpack_from("<HH", b, 46)
        sections = [struct.unpack_from("<10I", b, so + i * se) for i in range(sn)]
        self.symbols = []
        for table in sections:
            if table[1] != 11 or table[9] != 16:
                continue
            strings = sections[table[6]]
            names = b[strings[4]:strings[4] + strings[5]]
            for at in range(table[4], table[4] + table[5], 16):
                no, value, size, _, _, index = struct.unpack_from("<IIIBBH", b, at)
                if index and value:
                    end = names.find(b"\0", no)
                    self.symbols.append((value, names[no:end].decode("ascii", "replace")))

    def word(self, address: int) -> int | None:
        for kind, offset, va, _, file_size, _, _, _ in self.loads:
            if kind == 1 and va <= address and address + 4 <= va + file_size:
                return struct.unpack_from("<I", self.data, offset + address - va)[0]
        return None


def arguments(text: str, start: int) -> tuple[list[str], int]:
    depth, pieces, begin, quote, escape = 1, [], start, None, False
    for pos in range(start, min(len(text), start + 20000)):
        char = text[pos]
        if quote:
            if escape:
                escape = False
            elif char == "\\":
                escape = True
            elif char == quote:
                quote = None
            continue
        if char in ('"', "'"):
            quote = char
        elif char in "([{":
            depth += 1
        elif char in ")]}":
            depth -= 1
            if depth == 0:
                pieces.append(text[begin:pos].strip())
                return pieces, pos
        elif char == "," and depth == 1:
            pieces.append(text[begin:pos].strip())
            begin = pos + 1
    return [], start


def constant(expression: str) -> int | None:
    clean = re.sub(r"\((?:u?int|u?long|u?short|undefined[1248]|uchar)\)", "", expression).strip()
    return int(clean, 0) if re.fullmatch(r"(?:0x[0-9a-fA-F]+|[0-9]+)", clean) else None


def classify(symbol: str) -> tuple[str, int] | None:
    if "GetRcEngine" in symbol:
        for api, kind in (("RcGetNum", "Num"), ("RcGetColor", "Color"), ("RcGetImage", "Image"),
                          ("RcGetString", "Str"), ("RcGetFont", "font"), ("RcGetBool", "Bool")):
            if api in symbol:
                return kind, 0
    if "MResourcePkg" in symbol:
        for api, kind in (("GetNum", "Num"), ("GetColorKey", "Clrkey"), ("GetColor", "Color"),
                          ("GetImgPath", "Image"), ("GetString", "Str"), ("GetFontPath", "font")):
            if api in symbol:
                return kind, 1
    if re.search(r"_ZN4MImg(?:3SetE|C[12]E)[tjm]$", symbol):
        return "Image", 1
    if re.search(r"_ZN7MString(?:3SetE|C[12]E)[tjm]$", symbol):
        return "Str", 1
    if "MImageProperty" in symbol and "3SetE" in symbol:
        return "Image_property_argument_candidate", 1
    return None


def code_candidates(elfs: dict[str, Elf], symbols: dict[int, list[str]]) -> tuple[list, list, list, list]:
    uses, groups, mode_calls, code_files = [], [], [], []
    patterns = (
        ("named_pointer", re.compile(r"\(\*\(code \*\)(PTR_[A-Za-z0-9_]+_([0-9a-fA-F]{8}))\)\s*\(")),
        ("unseeded_t9_pointer", re.compile(r"\(\*\*\(code \*\*\)\(in_t9 \+ (0x[0-9a-f]+)\)\)\s*\(")),
    )
    for path in sorted(NATIVE.rglob("*.c")):
        text = read(path).decode("utf-8", "replace")
        module = "libmuf" if any(part.startswith(("libmuf", "muf-")) for part in path.parts) else "dvbt_board"
        if module not in elfs or not re.fullmatch(r"[0-9a-fA-F]{8}", path.stem):
            continue
        start = int(path.stem, 16)
        header = re.search(r"/\*\s*([^*]+?)\s*\*/", text)
        function = header[1].strip() if header and "WARNING" not in header[1] else f"function_{path.stem}"
        variant = "canonical_targeted" if path.parent == NATIVE / "ui-targeted" / module else "legacy_or_auxiliary_variant"
        file_info = {**meta(path), "module": module, "function": function, "entry": hex(start),
                     "variant": variant, "warning_markers": text.count("WARNING:"),
                     "evidence_scope": "auxiliary_pseudocode_snapshot_not_primary_resource_impact_evidence"}
        code_files.append(file_info)
        selected = []
        for style, pattern in patterns:
            for match in pattern.finditer(text):
                args, _ = arguments(text, match.end())
                slot = int(match[2], 16) if style == "named_pointer" else start + int(match[1], 16)
                target = elfs[module].word(slot)
                candidates = symbols.get(target, [])
                typed = [item for item in candidates if classify(item)]
                line = text.count("\n", 0, match.start()) + 1
                record = {"source_file": rel(path), "line": line, "function": function, "entry": hex(start),
                          "module": module, "variant": variant, "source_warning_markers": file_info["warning_markers"],
                          "got_slot": hex(slot), "stored_target": hex(target) if target is not None else None,
                          "resolved_symbols": candidates, "arguments": args, "pointer_method": style,
                          "evidence_level": "static_GOT_symbol_and_decompiler_argument_candidate",
                          "address_assumption": "PIC t9 equals selected function entry" if style == "unseeded_t9_pointer" else "GOT slot named by existing Ghidra pseudocode",
                          "runtime_observed": False,
                          "evidence_scope": "auxiliary_pseudocode_snapshot_not_primary_resource_impact_evidence"}
                if typed:
                    kind, index = classify(typed[0])
                    if index >= len(args):
                        continue
                    value = constant(args[index])
                    item = {**record, "resource_kind": kind, "id_argument_index": index,
                            "id_expression": args[index], "constant_id": value,
                            "constant_id_hex": hex(value) if value is not None else None,
                            "id_status": "literal_static_candidate" if value is not None else "dynamic_or_expression_unresolved"}
                    uses.append(item)
                    selected.append(item)
                if any(re.search(r"Hotel|ArCecController|InputSource|SourceType|ActiveSource|GetCurrentSource", name) for name in candidates):
                    mode_calls.append({**record, "mode_categories": [category for category, expression in (
                        ("hotel", r"Hotel"), ("cec_arc", r"ArCecController"),
                        ("input_source", r"InputSource|SourceType|ActiveSource|GetCurrentSource"))
                        if any(re.search(expression, name) for name in candidates)]})
        # Four repeated MImg fields are observed slots. Semantic state labels require Draw/QueryVisualState evidence.
        grouped = collections.defaultdict(list)
        for item in selected:
            if item["resource_kind"] != "Image" or len(item["arguments"]) < 2:
                continue
            expression = item["arguments"][0]
            match = re.fullmatch(r"(.+)\+\s*(0x[0-9a-fA-F]+|[0-9]+)", expression)
            if match:
                offset = int(match[2], 0)
                for family, base in (("background_MImg_slots", 0xB8), ("Image_content_MImg_slots", 0x260)):
                    if offset in (base, base + 20, base + 40, base + 60):
                        grouped[(family, match[1].strip())].append({"slot": (offset - base) // 20,
                            "field_offset": hex(offset), "id": item["constant_id"], "line": item["line"]})
        for (family, expression), assignments in grouped.items():
            if len({x["slot"] for x in assignments}) == 4:
                groups.append({"source_file": rel(path), "function": function, "variant": variant,
                               "object_expression": expression, "family": family, "assignments": assignments,
                               "state_labels": ["slot0", "slot1", "slot2", "slot3"],
                               "semantic_mapping": "normal/focus/pressed/disabled order not established by these assignments"})
    return uses, groups, mode_calls, code_files


def table_bindings(kind: str, value: int, lookups: dict) -> list[dict]:
    results = []
    for (table_kind, path), records in lookups.items():
        if table_kind != kind or value < 0 or value >= len(records):
            continue
        entry = records[value]
        result = {"table": path, "id": value, "index_mapping_scope": "static table-index lookup; active package unknown"}
        if isinstance(entry, int):
            result.update(file_offset=56 + 4 * value, u32=entry, u32_hex=hex(entry))
        else:
            result.update(entry)
        results.append(result)
    return results


def instruction_candidates(lookups: dict, expected_target_sha256: str) -> dict:
    path = ROOT / "analiz/ui-kod-cagrilari.json"
    if not path.is_file():
        return {"status": "source_graph_unavailable", "resource_call_count": 0, "buckets": []}
    # This graph can be large; do not retain a second raw-byte copy in CACHE.
    with path.open("r", encoding="utf-8") as stream:
        source = json.load(stream)
    if source.get("target_sha256") != expected_target_sha256:
        raise ValueError("Instruction graph target SHA256 does not match the analyzed OEM main ELF")
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    buckets, bindings, function_names = {}, {}, {}
    literal_count, unknown_count, resource_count = 0, 0, 0
    for source_index, call in enumerate(source.get("calls", [])):
        target = call.get("target_candidate") or {}
        symbol = target.get("symbol") or ""
        classification = classify(symbol)
        if not classification:
            continue
        kind, argument_index = classification
        name = call.get("target_name_candidate") or symbol
        key = (kind, symbol, argument_index)
        bucket = buckets.setdefault(key, {"resource_kind": kind, "target_symbol": symbol, "target_name_candidate": name,
            "assumed_id_argument_register": f"a{argument_index}",
            "abi_assumption": "O32 public static getters use a0; typed C++ member numeric-resource overloads use a1 after this",
            "columns": ["source_call_index", "site", "function_address", "id_value_candidate", "id_defined_at",
                        "id_argument_basis", "target_resolution", "function_range_basis", "unresolved_memory_base", "unresolved_memory_offset"],
            "rows": []})
        arguments = call.get("argument_candidates_a0_a3") or []
        candidate = arguments[argument_index] if argument_index < len(arguments) else None
        candidate = candidate if isinstance(candidate, dict) else {}
        value = candidate.get("value")
        if not isinstance(value, int):
            value = None
        row = [source_index, call.get("site"), call.get("function_address"), value,
               candidate.get("defined_at"), candidate.get("basis", "unknown"), call.get("resolution"),
               call.get("range_basis"), candidate.get("memory_base_register"), candidate.get("memory_offset")]
        bucket["rows"].append(row)
        resource_count += 1
        function_names[call.get("function_address")] = call.get("function")
        if value is None:
            unknown_count += 1
            continue
        literal_count += 1
        group = bindings.setdefault((kind, value), {"count": 0, "functions": set(), "sites": []})
        group["count"] += 1
        group["functions"].add(call.get("function_address"))
        group["sites"].append(call.get("site"))
    resolved_bindings = []
    for (kind, value), group in sorted(bindings.items()):
        matches = table_bindings(kind, value, lookups)
        resolved_bindings.append({"resource_kind": kind, "id": value, "id_hex": hex(value),
            "instruction_candidate_count": group["count"], "function_count": len(group["functions"]),
            "function_addresses": sorted(group["functions"]), "call_sites": group["sites"],
            "table_comparison_status": "in_bounds_candidate" if matches else "no_in_bounds_parsed_table_candidate",
            "table_candidates": matches,
            "impact_scope": "shared_static_call_candidates" if len(group["functions"]) > 1 else "global_impact_unknown"})
    return {"status": "parsed", "source": {"path": rel(path), "bytes": path.stat().st_size, "sha256": digest.hexdigest()},
            "source_target_sha256": source["target_sha256"], "source_graph_stats": source.get("stats"),
            "source_uncovered_text_ranges": source.get("uncovered_text_ranges", []),
            "source_nonlink_jump_count": len(source.get("nonlink_jump_candidates", [])),
            "source_input_metadata": source.get("inputs"),
            "source_limitations": source.get("limitations"), "resource_call_count": resource_count,
            "constant_argument_candidates": literal_count, "unknown_argument_candidates": unknown_count,
            "evidence_level": "instruction basic-block constant propagation and symbolic GOT target candidates; not runtime argument proof",
            "source_call_index_scope": "zero-based position in source graph calls array", "function_names": function_names,
            "buckets": list(buckets.values()), "id_bindings": resolved_bindings,
            "unresolved_policy": "Unknown ID candidates are retained in rows with null value and their argument basis; never coerced into resource IDs"}


def main() -> None:
    files, tables, lookups = [], [], {}
    fonts, images = [], []
    for path in sorted(RC.rglob("*")):
        if not path.is_file() or path.is_symlink():
            continue
        item = meta(path)
        if path.suffix.lower() in (".png", ".gif", ".jpg", ".jpeg"):
            item["geometry"] = geometry(read(path))
            images.append(item)
        elif path.suffix.lower() in (".ttf", ".otf"):
            item["font_directory"] = font_directory(read(path))
            fonts.append(item)
        files.append(item)
        if path.name.endswith("_res.bin"):
            table, records = parse_table(path)
            tables.append(table)
            lookups[(table.get("resource_kind"), rel(path))] = records
    profiles = []
    for path in sorted(RC.glob("*/ResProfile")):
        declarations = []
        for line_no, line in enumerate(read(path).decode("utf-8").splitlines(), 1):
            parts = line.split(";", 1)
            declaration = {"line": line_no, "raw": line, "kind": parts[0],
                           "value": parts[1] if len(parts) == 2 else None}
            if len(parts) == 2 and parts[0] in ("Str", "Color", "Image", "Num", "Mba"):
                source_path = RC / parts[1]
                compiled_path = source_path.parent / "bin" / (source_path.stem + "_res.bin")
                declaration.update(declared_source_path=rel(source_path), declared_source_file_present=source_path.is_file(),
                                   compiled_name_candidate=rel(compiled_path), compiled_candidate_present=compiled_path.is_file(),
                                   resolution_method="Observed naming correspondence; profile reader behavior is separate code evidence")
            declarations.append(declaration)
        profiles.append({**meta(path), "declarations": declarations,
                         "resolution_scope": "Source design declaration; runtime render target and active profile unknown"})
    profile_lists = [{**meta(RC / name), "lines": read(RC / name).decode("utf-8").splitlines()}
                     for name in ("ResList", "ResProfile")]
    binary_profiles = [parse_binary_profile(p) for p in sorted(RC.rglob("ResProfile.bin"))]
    main_elf = Elf(TREE / "08_APP/bin/dvbt_board")
    muf_elf = Elf(TREE / "07_MSLIB/libmuf.so")
    elfs = {"dvbt_board": main_elf, "libmuf": muf_elf}
    symbol_index = collections.defaultdict(list)
    for elf in elfs.values():
        for address, name in elf.symbols:
            symbol_index[address].append(elf.path.name + ":" + name)
    # Additional OEM service libraries resolve mode-condition call targets; never run them.
    for name in ("libmsrv_control.so", "libmsrv_system_database.so", "libmsrv_common.so"):
        for address, symbol in Elf(TREE / "07_MSLIB" / name).symbols:
            symbol_index[address].append(name + ":" + symbol)
    uses, groups, modes, code_files = code_candidates(elfs, symbol_index)
    shared = collections.defaultdict(list)
    for index, item in enumerate(uses):
        value = item["constant_id"]
        if value is not None:
            shared[(item["resource_kind"], value)].append(index)
    bindings = []
    for (kind, value), indices in sorted(shared.items()):
        resolved = table_bindings(kind, value, lookups)
        canonical = [i for i in indices if uses[i]["variant"] == "canonical_targeted"]
        functions = sorted({uses[i]["module"] + ":" + uses[i]["entry"] for i in canonical})
        bindings.append({"resource_kind": kind, "id": value, "id_hex": hex(value), "use_indices": indices,
                         "canonical_use_count": len(canonical), "canonical_function_count": len(functions),
                         "canonical_functions": functions, "table_candidates": resolved,
                         "modification_impact": "shared_across_selected_functions" if len(functions) > 1 else "coverage_limited_unknown_global_impact"})
    instruction_scope = instruction_candidates(lookups, sha(main_elf.data))
    configs = []
    for name in ("directfbrc", "dfbrc.ini", "SN_DFBRC_Marlon_MST120B_10ALSQ.ini"):
        path = TREE / "09_CONFIG" / name
        configs.append({**meta(path), "lines": [{"line": i, "text": line} for i, line in enumerate(read(path).decode("utf-8").splitlines(), 1)],
                        "scope": "Packaged option values; active device application not observed"})
    analysis_context = []
    for path in sorted(NATIVE.rglob("summary.json")):
        data = json.loads(read(path).decode("utf-8"))
        analysis_context.append({**meta(path), "context": {key: data[key] for key in (
            "program", "stored_executable_sha256", "requested_count", "processed_count", "decompile_complete_count",
            "ephemeral_context_seed_count", "target_executed", "target_bytes_written", "evidence_kind", "limitations") if key in data}})
    options = NATIVE / "dvbt_board/analysis-options.json"
    if options.is_file():
        analysis_context.append({**meta(options), "context": json.loads(read(options).decode("utf-8"))})
    index_bridge_evidence = []
    for filename, observation in (
        ("2e2403a4.c", "GetU32 returns param_2[param_1] after nonnull/count bound check"),
        ("2e2408a0.c", "GetSTR indexes its built offset array with the supplied ID; prototype inference is imperfect"),
        ("2e24097c.c", "GetImgPath forwards the supplied ID to the string/path table accessor"),
        ("2e27141c.c", "RcGetNum nonnull-package path forwards its public argument to package GetNum"),
        ("2e271658.c", "RcGetImage forwards its public argument to GetImgPath and GetColorKey"),
        ("2e271754.c", "RcGetColor nonnull-package path forwards its public argument to package GetColor")):
        path = NATIVE / "ui-targeted/libmuf" / filename
        if path.is_file():
            index_bridge_evidence.append({**meta(path), "observation": observation,
                                          "evidence_level": "existing_static_decompiler_output_not_runtime_observation"})
    counts = collections.Counter(t["status"] for t in tables)
    stats = {"ui_regular_files": len(files), "profiles": len(profiles), "fonts": len(fonts), "images": len(images),
             "png": sum(x["geometry"]["format"] == "PNG" for x in images), "resource_tables": len(tables),
             "table_parse_status": dict(counts), "declared_resource_records": sum(t.get("declared_record_count", 0) for t in tables),
             "parsed_resource_records": sum(t.get("parsed_records", 0) for t in tables),
             "binary_profiles": len(binary_profiles),
             "decompiled_files_scanned": len(code_files), "resource_call_candidates": len(uses),
             "literal_call_candidates": sum(x["constant_id"] is not None for x in uses),
             "dynamic_call_candidates": sum(x["constant_id"] is None for x in uses), "four_slot_groups": len(groups),
             "mode_condition_call_candidates": len(modes), "distinct_literal_resource_ids_by_kind": dict(collections.Counter(k for k, _ in shared))}
    stats.update(decompiled_variant_counts=dict(collections.Counter(x["variant"] for x in code_files)),
                 unique_module_entry_functions=len({(x["module"], x["entry"]) for x in code_files}),
                 canonical_unique_module_entry_functions=len({(x["module"], x["entry"]) for x in code_files if x["variant"] == "canonical_targeted"}))
    stats.update(instruction_resource_call_candidates=instruction_scope.get("resource_call_count", 0),
                 instruction_constant_argument_candidates=instruction_scope.get("constant_argument_candidates", 0),
                 instruction_unknown_argument_candidates=instruction_scope.get("unknown_argument_candidates", 0))
    report = {"schema_version": 1, "source": "OEM APP/rc regular-file export plus existing Ghidra pseudocode", "stats": stats,
              "decision_evidence_scope": {"primary": "instruction_resource_scope: 114342 static callsite candidates, with explicit ABI/register and basic-block assumptions",
                  "secondary": "C pseudocode variants are auxiliary snapshots; incomplete/decompiler-abort overrun and duplicate versions are not promoted to primary impact evidence",
                  "function_uniqueness": "module plus entry; variant counts are not unique functions or widgets",
                  "device_runtime": "unobserved"},
              "active_theme": "unknown", "active_language": "unknown", "device_observed": False,
              "evidence_levels": {"inventory": "SHA256 and binary/container boundary checks", "resource_id_use": "literal or dynamic decompiler argument with static GOT/dynamic-symbol target matching",
                                  "bindings": "offline ID-index candidate lookup; MResourcePkg GetU32/GetSTR provide separate code evidence",
                                  "runtime": "not observed"},
              "inventory": files, "resource_table_formats": tables, "profiles": profiles, "profile_lists": profile_lists,
              "binary_profiles": binary_profiles,
              "font_files": fonts, "code_files": code_files, "resource_uses": uses, "resource_bindings_and_shared_use": bindings,
              "native_analysis_context": analysis_context,
              "id_table_index_code_evidence": index_bridge_evidence,
              "instruction_resource_scope": instruction_scope,
              "four_slot_widget_groups": groups, "mode_condition_calls": modes, "directfb_configuration": configs,
              "parsing_boundaries": ["String payload text is not copied; length/range/NUL/UTF-8 checks and SHA256 are retained",
                    "Image path tables parsed fully; actual runtime load success is separate", "Fonts validate sfnt table-directory ranges only; glyphs not rendered",
                    "PNG chunks and CRCs parsed; pixel streams not decompressed", "Font resource tables are empty; nonempty font payload format remains unproven",
                    "Bool type0 header has no payload despite count2; no invented boolean entries", "No raw unknown header words interpreted as valid pointers"],
              "limitations": ["All existing C variants inventoried; legacy/failed-run/smoke variants can duplicate a function. Shared-use counts use canonical targeted variants only",
                    "No full-program callgraph claim: original autoanalysis timed out and MIPS constant analyzer was disabled",
                    "Decompiled constants are candidates, with warnings recorded; computed/dynamic IDs remain unknown",
                    "Opaque C++ member offsets show four slots, not a proven normal/focus/pressed/disabled order",
                    "Logical resource geometry, DirectFB surface geometry, and physical TV pixels are different observations",
                    "Shared palette/Num IDs can affect other widgets; single-OSD isolation is not established",
                    "No certificate, cryptographic key, or unique device identity contents read; no external data transfer",
                    "No target execution, firmware modification, image edit, deployment, or device write"]}
    OUTPUT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"output": str(OUTPUT), "bytes": OUTPUT.stat().st_size, "stats": stats}))


if __name__ == "__main__":
    main()
