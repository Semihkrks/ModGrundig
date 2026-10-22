"""Parse an MStar upgrade header as data; bounded stdlib-only LZMA extraction.

Never interprets shell/bootloader commands and never modifies input artifacts.
Outputs only the designated section directory and JSON manifest.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import lzma
import re
import struct
import zlib
from pathlib import Path

HEADER_LIMIT = 64 * 1024
SECTION_LIMIT = 128 * 1024 * 1024
TOTAL_LIMIT = 512 * 1024 * 1024
MEMORY_LIMIT = 160 * 1024 * 1024


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def file_sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def identify(data: bytes) -> dict:
    result = {"header_hex": data[:64].hex(), "format": "unknown"}
    if data.startswith(b"\x31\x18\x10\x06"):
        result.update(format="UBIFS", node_type=data[20] if len(data) > 20 else None)
        if len(data) >= 24:
            length = struct.unpack_from("<I", data, 16)[0]
            stored_crc = struct.unpack_from("<I", data, 4)[0]
            result["first_node"] = {"length": length, "stored_crc_hex": f"{stored_crc:08x}"}
            if 24 <= length <= len(data):
                computed_crc = zlib.crc32(data[8:length]) ^ 0xFFFFFFFF
                result["first_node"].update(tested_crc_formula="zlib.crc32(node[8:node_length]) XOR 0xffffffff",
                                            computed_crc_hex=f"{computed_crc:08x}",
                                            crc_matches=computed_crc == stored_crc)
    elif data.startswith(b"\x27\x05\x19\x56") and len(data) >= 64:
        fields = struct.unpack_from(">7I4B32s", data)
        result.update(format="uImage", timestamp=fields[2], payload_bytes=fields[3],
                      load_address=hex(fields[4]), entry_address=hex(fields[5]),
                      os_id=fields[7], architecture_id=fields[8], image_type_id=fields[9],
                      compression_id=fields[10], name=fields[11].split(b"\0", 1)[0].decode("ascii", "replace"))
        clean_header = bytearray(data[:64])
        clean_header[4:8] = b"\0" * 4
        result["header_crc32_matches"] = zlib.crc32(clean_header) == fields[1]
        end = 64 + fields[3]
        result["payload_present"] = end <= len(data)
        result["payload_crc32_matches"] = end <= len(data) and zlib.crc32(data[64:end]) == fields[6]
    elif data.startswith(b"\x7fELF"):
        result.update(format="ELF", elf_class=data[4], endian_id=data[5])
    elif data.startswith(b"hsqs"):
        result["format"] = "SquashFS-little-endian"
    elif data.startswith(b"UBI#"):
        result["format"] = "UBI-erase-counter-header"
    elif data.startswith(b"MSTARSEMIUNFDCIS"):
        result["format"] = "MSTAR-NAND-CIS"
    return result


def parse_header(raw: bytes, source_size: int) -> tuple[dict, list[dict]]:
    size_match = re.match(rb"# Script Size = (0x[0-9a-fA-F]+) #", raw)
    if not size_match:
        raise ValueError("Missing bounded MStar script-size declaration")
    header_size = int(size_match[1], 16)
    if not 0 < header_size <= HEADER_LIMIT or header_size > len(raw):
        raise ValueError("Invalid or oversized header declaration")
    header = raw[:header_size]
    sections = []
    current = None
    position = 0
    for line_bytes in header.splitlines(keepends=True):
        line = line_bytes.decode("ascii", "replace").rstrip("\r\n")
        match = re.fullmatch(r"filepartload\s+(0x[0-9a-fA-F]+)\s+\$\(UpgradeImage\)\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+#([A-Za-z_0-9]+)", line)
        if match:
            offset, size = int(match[2], 16), int(match[3], 16)
            if offset < header_size or size <= 0 or offset + size > source_size:
                raise ValueError(f"Section range outside input: {match[4]}")
            current = {"ordinal": len(sections), "label": match[4], "script_offset": position,
                       "source_offset": offset, "compressed_bytes": size,
                       "load_address": match[1], "commands": [line]}
            sections.append(current)
        elif current is not None:
            if line.startswith("# File Partition:"):
                current = None
            elif re.match(r"^(mscompress7|crc32|mw |cmp\.b|ubi write|nand write)", line):
                current["commands"].append(line)
                match = re.match(r"mscompress7 d 0 (0x[0-9a-fA-F]+) ([0-9a-fA-F]+) (0x[0-9a-fA-F]+)", line)
                if match:
                    current["decompress_destination"] = match[3]
                    current["mscompress7_declared_input_bytes"] = int(match[2], 16)
                match = re.match(r"crc32 (0x[0-9a-fA-F]+) (0x[0-9a-fA-F]+) (0x[0-9a-fA-F]+)", line)
                if match:
                    current["crc32_declaration"] = {"address": match[1], "bytes": int(match[2], 16), "destination": match[3]}
                match = re.match(r"mw (0x[0-9a-fA-F]+) (0x[0-9a-fA-F]+) 4", line)
                if match:
                    current["expected_crc32_hex"] = f"{int(match[2], 16):08x}"
                match = re.match(r"ubi write (0x[0-9a-fA-F]+) ([A-Za-z_0-9]+) (0x[0-9a-fA-F]+)", line)
                if match:
                    current["write_target"] = match[2]
                    current["write_bytes"] = int(match[3], 16)
                match = re.match(r"nand write\.e (0x[0-9a-fA-F]+) ([A-Za-z_0-9]+)", line)
                if match:
                    current["write_target"] = match[2]
        position += len(line_bytes)
    if not sections:
        raise ValueError("Header contains no valid bounded filepartload sections")
    return {"declared_script_bytes": header_size, "script_sha256": sha256(header),
            "commands_executed": False}, sections


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--manifest", type=Path, required=True)
    parser.add_argument("--boot-reference", type=Path, help="Optional explicit GM_Boot.bin for byte comparison")
    args = parser.parse_args()
    source = args.source.resolve(strict=True)
    output = args.output.resolve()
    manifest = args.manifest.resolve()
    # Enforce this investigation's explicitly assigned write surface.
    root = Path(__file__).resolve().parents[1]
    if output != root / "analiz" / "bolumler" or manifest != root / "analiz" / "bolum-haritasi.json":
        raise ValueError("Writes are restricted to the assigned output paths")
    if not source.is_file() or source.suffix.lower() != ".bin":
        raise ValueError("Expected an explicit .bin source file")
    original_digest = file_sha256(source)
    with source.open("rb") as stream:
        header, sections = parse_header(stream.read(HEADER_LIMIT), source.stat().st_size)
        output.mkdir(parents=True, exist_ok=True)
        total = 0
        for section in sections:
            stream.seek(section["source_offset"])
            compressed = stream.read(section["compressed_bytes"])
            section.update(compressed_sha256=sha256(compressed), compressed_header_hex=compressed[:32].hex())
            try:
                if len(compressed) < 13:
                    raise ValueError("Truncated LZMA-alone header")
                declared_size = int.from_bytes(compressed[5:13], "little")
                dictionary_size = int.from_bytes(compressed[1:5], "little")
                section["lzma_alone"] = {"property_byte": compressed[0], "dictionary_bytes": dictionary_size,
                                         "declared_output_bytes": declared_size}
                if dictionary_size > MEMORY_LIMIT or declared_size > SECTION_LIMIT or total + declared_size > TOTAL_LIMIT:
                    raise ValueError("Decompression exceeds explicit resource budget")
                decoder = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE, memlimit=MEMORY_LIMIT)
                decoded = decoder.decompress(compressed, max_length=declared_size + 1)
                if len(decoded) != declared_size:
                    raise ValueError(f"Output size mismatch: {len(decoded)} != {declared_size}")
                total += len(decoded)
                filename = f"{section['ordinal']:02d}_{section.get('write_target', section['label'])}.bin"
                destination = output / filename
                destination.write_bytes(decoded)
                section.update(status="decoded", output_path=str(destination), output_bytes=len(decoded),
                               output_sha256=sha256(decoded), lzma_eof=decoder.eof,
                               compressed_unused_bytes=len(decoder.unused_data), identification=identify(decoded))
                crc_declaration = section.get("crc32_declaration")
                if crc_declaration and "expected_crc32_hex" in section:
                    crc_size = crc_declaration["bytes"]
                    if crc_size <= len(decoded):
                        actual_crc = f"{zlib.crc32(decoded[:crc_size]):08x}"
                        section["crc32_validation"] = {"tested_algorithm": "Python zlib.crc32 (CRC-32/ISO-HDLC)",
                            "bytes": crc_size, "actual_hex": actual_crc,
                            "matches_declaration": actual_crc == section["expected_crc32_hex"],
                            "bootloader_implementation": "unknown; not executed or disassembled"}
                    else:
                        section["crc32_validation"] = {"status": "unknown", "reason": "CRC span exceeds decoded output"}
            except (lzma.LZMAError, ValueError) as error:
                section.update(status="not_decoded", error=str(error))
    if file_sha256(source) != original_digest:
        raise RuntimeError("Input changed during analysis")
    boot_reference = None
    if args.boot_reference:
        boot_path = args.boot_reference.resolve(strict=True)
        if boot_path.name != "GM_Boot.bin":
            raise ValueError("Boot comparison is restricted to the explicit GM_Boot.bin")
        boot_reference = {"path": str(boot_path), "bytes": boot_path.stat().st_size,
                          "sha256": file_sha256(boot_path), "comparison": "decompression destination minus first boot destination"}
        boot_sections = [s for s in sections if s["label"] == "mboot" and s["status"] == "decoded"]
        base = min(int(s["decompress_destination"], 16) for s in boot_sections)
        with boot_path.open("rb") as stream:
            for section in boot_sections:
                offset = int(section["decompress_destination"], 16) - base
                stream.seek(offset)
                reference_bytes = stream.read(section["output_bytes"])
                section["boot_reference_comparison"] = {
                    "reference_offset": offset, "compared_bytes": len(reference_bytes),
                    "sha256_matches": sha256(reference_bytes) == section["output_sha256"]}
    report = {"source": str(source), "source_bytes": source.stat().st_size, "source_sha256": original_digest,
              "method": "ASCII command data parsing and stdlib LZMA-alone decompression; no target execution",
              "limits": {"section_output_bytes": SECTION_LIMIT, "total_output_bytes": TOTAL_LIMIT, "lzma_memory_bytes": MEMORY_LIMIT},
              "header": header, "section_count": len(sections), "decoded_bytes_total": total, "sections": sections,
              "boot_reference": boot_reference,
              "limitations": ["No device compatibility or active-OSD conclusion", "No update commands executed",
                              "No key files read", "Only declared filepartload ranges extracted"]}
    manifest.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"manifest": str(manifest), "sections": len(sections), "decoded": sum(s["status"] == "decoded" for s in sections),
                      "decoded_bytes": total, "formats": [s.get("identification", {}).get("format", "not_decoded") for s in sections]}))


if __name__ == "__main__":
    main()
