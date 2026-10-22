"""Build an offline, read-only UI/resource/keymap evidence map.

Reads extracted APP and CONFIG regular files plus the user's twenty PNG assets.
It executes no firmware, shell scripts, device commands, or configuration data.
The only output is analiz/ui-kaynak-haritasi.json.
"""
from __future__ import annotations

import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VOLUMES = ROOT / "analiz" / "dosya-sistemleri-tam"
APP = VOLUMES / "08_APP"
CONFIG = VOLUMES / "09_CONFIG"
OUTPUT = ROOT / "analiz" / "ui-kaynak-haritasi.json"
KEYMAPS = ("mufirkeymap", "mufirkeymapTP6", "mufirkeymapTP7_P1", "mufirkeymapTP7_P2",
           "mufirkeymapTS1_NET", "mufirkeymapTS1_SHR")
ASSET_DIRS = (
    ROOT / "devir-paketi" / "Kaynaklar" / "Grundig_GMGRMR_Ses_Arayuzu_Kaynaklari" / "volumeControl",
    ROOT / "devir-paketi" / "Kaynaklar" / "Grundig_Mavi_Panel_Aday_Dosyalar",
)
HASH_CACHE: dict[Path, str] = {}


def relative(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


def digest(path: Path) -> str:
    path = path.resolve(strict=True)
    if path not in HASH_CACHE:
        h = hashlib.sha256()
        with path.open("rb") as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b""):
                h.update(chunk)
        HASH_CACHE[path] = h.hexdigest()
    return HASH_CACHE[path]


def metadata(path: Path) -> dict:
    return {"path": relative(path), "bytes": path.stat().st_size, "sha256": digest(path)}


def image_metadata(path: Path) -> dict:
    result = metadata(path)
    with path.open("rb") as stream:
        header = stream.read(24)
    if header[:8] == b"\x89PNG\r\n\x1a\n" and header[12:16] == b"IHDR":
        result.update(png_signature=True, width=int.from_bytes(header[16:20], "big"),
                      height=int.from_bytes(header[20:24], "big"))
    return result


def parse_images(path: Path) -> dict:
    raw = path.read_bytes()
    if len(raw) < 56 or raw[:4] != b"_tsm":
        raise ValueError(f"Unexpected image resource header: {path}")
    declared_bytes = struct.unpack_from("<I", raw, 4)[0]
    count = struct.unpack_from("<I", raw, 28)[0]
    if declared_bytes != len(raw) or count > 10000:
        raise ValueError("Resource table size/count exceeds validated layout")
    pos, records = 56, []
    for index in range(count):
        if pos + 4 > len(raw):
            raise ValueError("Truncated resource record length")
        length = struct.unpack_from("<I", raw, pos)[0]
        end = pos + 4 + length
        if length < 1 or end > len(raw) or raw[end - 1] != 0:
            raise ValueError("Invalid resource path range or terminator")
        value = raw[pos + 4:end - 1].decode("utf-8", "strict")
        record = {"index_zero_based": index, "length_field_offset": pos,
                  "path_offset": pos + 4, "record_string_bytes_including_nul": length,
                  "resource_path": value, "path_bytes_sha256": hashlib.sha256(raw[pos + 4:end]).hexdigest()}
        # Tables use paths relative to /applications/bin. Reject traversal outside APP.
        resolved = (APP / "bin" / value).resolve()
        if not resolved.is_relative_to(APP.resolve()):
            record.update(resolution_status="outside_APP_not_read", asset_sha256=None)
        elif resolved.is_file() and not resolved.is_symlink():
            record.update(resolution_status="regular_file_present", resolved_path=relative(resolved),
                          asset_bytes=resolved.stat().st_size, asset_sha256=digest(resolved))
        else:
            record.update(resolution_status="absent_from_regular_file_export", resolved_path=relative(resolved),
                          asset_sha256=None)
        records.append(record)
        pos = end
    if pos != len(raw):
        raise ValueError("Resource table did not consume complete file")
    return {**metadata(path), "record_count": count, "fully_consumed": True,
            "format_observation": "56-byte header; uint32_le byte length then NUL-terminated UTF-8 path",
            "index_semantics": "record position; application resource-ID translation not proven",
            "records": records}


SEMANTICS = {
    "HOME": r"(?:^|_)HOME(?:_|$)",
    "BACK": r"(?:^|_)(?:BACK|RETURN|CHANNEL_RETURN)(?:_|$)",
    "OK": r"(?:^|_)(?:OK|SELECT|ENTER)(?:_|$)",
    "DIRECTIONS": r"^MVK_(?:UP|DOWN|LEFT|RIGHT)$",
    "VOLUME": r"(?:^|_)VOLUME(?:_|$)",
    "MUTE": r"(?:^|_)MUTE(?:_|$)",
    "MENU": r"(?:^|_)MENU(?:_|$)",
    "SOURCE": r"(?:^|_)(?:INPUT_SOURCE|SOURCE)(?:_|$)",
    "CEC": r"(?:^|_)CEC(?:_|$)",
    "TOOLS": r"(?:^|_)TOOLS(?:_|$)",
    "INTERNET": r"(?:^|_)INTERNET(?:_|$)",
    "EXIT": r"(?:^|_)EXIT(?:_|$)",
}


def parse_keymap(path: Path) -> dict:
    rows, other = [], []
    lines = path.read_text(encoding="utf-8").splitlines()
    pattern = re.compile(r"^\s*keycode\s+(0x[0-9a-fA-F]+)\s*=\s*([A-Za-z0-9_]+)\s*=\s*(0x[0-9a-fA-F]+)\s*(?:#(.*))?$")
    for line_no, line in enumerate(lines, 1):
        active = line.strip() and not line.lstrip().startswith("#")
        match = pattern.match(line) if active else None
        if match:
            comment = (match[4] or "").strip()
            semantic = re.search(r"\b(MVK_[A-Z0-9_]+)\b", comment)
            rows.append({"line": line_no, "raw": line, "hardware_keycode": int(match[1], 16),
                         "hardware_keycode_hex": match[1], "directfb_key_id": match[2],
                         "key_symbol": int(match[3], 16), "key_symbol_hex": match[3],
                         "mvk_comment_name": semantic[1] if semantic else None, "comment": comment})
        elif active:
            other.append({"line": line_no, "raw": line})
    summary = {}
    for category, expression in SEMANTICS.items():
        summary[category] = [row for row in rows if re.search(expression, row["mvk_comment_name"] or "")]
    duplicates = {}
    for row in rows:
        duplicates.setdefault(row["hardware_keycode_hex"].lower(), []).append(row["line"])
    return {**metadata(path), "lines": [{"line": n, "raw": line} for n, line in enumerate(lines, 1)],
            "row_count": len(rows), "rows": rows, "unparsed_active_lines": other,
            "duplicate_hardware_codes": {k: v for k, v in duplicates.items() if len(v) > 1},
            "semantic_summary": summary,
            "limitations": ["MVK names are table comments", "BACK category may contain channel-return; meaning not assumed",
                            "HOME absence means absent from these tables only", "Runtime-selected map is unknown"]}


def text_record(path: Path) -> dict:
    lines = path.read_text(encoding="utf-8").splitlines()
    return {**metadata(path), "lines": [{"line": i, "text": s} for i, s in enumerate(lines, 1)]}


def elf_brand_candidates(path: Path) -> dict:
    raw = path.read_bytes()
    if raw[:5] != b"\x7fELF\x01":
        raise ValueError("Expected ELF32 source")
    endian = "<" if raw[5] == 1 else ">"
    shoff = struct.unpack_from(endian + "I", raw, 32)[0]
    entsize, count = struct.unpack_from(endian + "HH", raw, 46)
    sections = [struct.unpack_from(endian + "10I", raw, shoff + i * entsize) for i in range(count)]
    symbols = []
    pattern = re.compile(r"ArResourceManager.*(?:Brand|Remote)|ArTvConf_.*Remote|CecSettingsFrame.*OnKey|OnNtyClick.*Digilink|ArCecController.*StartDeviceSearch")
    for table in sections:
        if table[1] not in (2, 11):
            continue
        strings = sections[table[6]]
        names = raw[strings[4]:strings[4] + strings[5]]
        for pos in range(table[4], table[4] + table[5], table[9]):
            name_offset, value, size, info, other, index = struct.unpack_from(endian + "IIIBBH", raw, pos)
            name = names[name_offset:names.find(b"\0", name_offset)].decode("ascii", "replace")
            if pattern.search(name):
                symbols.append({"symbol": name, "virtual_address": value, "virtual_address_hex": hex(value),
                                "bytes": size, "defined": index != 0, "symbol_table_type": table[1]})
    strings = []
    for match in re.finditer(rb"[\x20-\x7e]{5,}", raw):
        value = match.group().decode("ascii")
        if re.search(r"\.\./rc/rc(?:_Beko|_Arcelik)?/bin|OSD Selection Grundig|/config/mufirkeymap", value):
            strings.append({"file_offset": match.start(), "file_offset_hex": hex(match.start()), "text": value})
    return {**metadata(path), "symbols": symbols, "path_string_candidates": strings,
            "evidence_scope": "ELF symbol definitions and literal strings; no disassembly or call/xref proof"}


def main() -> None:
    image_tables = [parse_images(APP / "rc" / brand / "bin" / "Image_res.bin")
                    for brand in ("rc", "rc_Beko", "rc_Arcelik")]
    hash_index: dict[str, list[dict]] = {}
    for png in sorted((APP / "rc" / "ARimages").rglob("*.png")):
        if png.is_file() and not png.is_symlink():
            info = image_metadata(png)
            hash_index.setdefault(info["sha256"], []).append(info)
    matches = []
    for directory in ASSET_DIRS:
        for png in sorted(directory.glob("*.png")):
            if "preview" in png.name.lower():
                continue
            info = image_metadata(png)
            found = hash_index.get(info["sha256"], [])
            refs = []
            for table in image_tables:
                for record in table["records"]:
                    if record["asset_sha256"] == info["sha256"]:
                        refs.append({"table": table["path"], "index_zero_based": record["index_zero_based"],
                                     "path_offset": record["path_offset"], "resource_path": record["resource_path"]})
            matches.append({"supplied": info, "match_count": len(found), "firmware_matches": found,
                            "resource_table_references": refs,
                            "all_matched_basenames_differ": bool(found) and all(Path(x["path"]).name != png.name for x in found)})
    profiles = [text_record(p) for p in sorted((APP / "rc").glob("*/ResProfile"))]
    profiles.extend(text_record(APP / "rc" / name) for name in ("ResProfile", "ResList"))
    keymaps = [parse_keymap(CONFIG / name) for name in KEYMAPS]
    flags = (CONFIG / "Flags").read_text(encoding="utf-8").split()
    selected_flags = [token for token in flags if token.startswith(("CEC_ENABLE=", "ARC_ENABLE=", "USE_ARCHITECT_LAYER=", "USE_ARCHITECT_UI_LAYER="))]
    report = {"schema_version": 1, "source_tree": relative(VOLUMES),
              "method": "Static local parsing and SHA256 comparison; target code never executed",
              "active_device_theme": "unknown", "runtime_selected_remote_map": "unknown",
              "limits": ["Regular-file Windows export does not preserve Linux symlink behavior",
                         "Resource record indexes are not proven application resource IDs",
                         "String/symbol matches do not prove calls or active feature selection"],
              "asset_match_summary": {"supplied_count": len(matches), "matched_count": sum(bool(x["firmware_matches"]) for x in matches),
                                      "renamed_asset_count": sum(x["all_matched_basenames_differ"] for x in matches)},
              "asset_matches": matches, "image_resource_tables": image_tables,
              "profiles_and_lists": profiles, "keymaps": keymaps,
              "build_flags": {**metadata(CONFIG / "Flags"), "selected_ui_flags": selected_flags},
              "brand_and_remote_selection_candidates": elf_brand_candidates(APP / "bin" / "dvbt_board")}
    if len(matches) != 20 or report["asset_match_summary"]["matched_count"] != 20:
        raise ValueError("Expected all twenty supplied UI assets to match extracted firmware")
    if any(table["record_count"] != 2179 for table in image_tables):
        raise ValueError("Unexpected resource table record count")
    if any(table["unparsed_active_lines"] for table in keymaps):
        raise ValueError("One or more active keymap lines could not be parsed")
    OUTPUT.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"output": str(OUTPUT), "asset_match_summary": report["asset_match_summary"],
                      "resource_records": sum(t["record_count"] for t in image_tables),
                      "keymap_rows": {Path(t["path"]).name: t["row_count"] for t in keymaps}}))


if __name__ == "__main__":
    main()
