#!/usr/bin/env python3
"""Build and verify an offline APP-only research candidate; never execute it.

The accepted stock SHA and fixed container layout are deliberately specific to
this investigation. Output is restricted to analiz/native-ui-candidate and is
never labelled flash-ready. UBIFS mountability and target compatibility require
separate checks; this tool verifies its envelope and the 14 compressed payloads.
"""
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import hashlib
import json
import lzma
import os
from pathlib import Path
import re
import stat
import struct
import zlib

from unpack_mstar import parse_header

ROOT = Path(__file__).resolve().parents[1]
OUTPUT_ROOT = ROOT / "analiz" / "native-ui-candidate"
STOCK_SHA256 = "6d7614730c5f63b9e6727b8b329606b188b581efb366bffde6991aca123852c0"
HEADER_SIZE = 0x4000
APP_ORDINAL = 8
SECTION_COUNT = 14
ALIGNMENT = 0x10000
MAX_IMAGE = 64 * 1024 * 1024
MAX_SECTION = 128 * 1024 * 1024
MAX_TOTAL = 512 * 1024 * 1024
LZMA_MEMORY_LIMIT = 160 * 1024 * 1024
TRAILER = b"\xbe\xef"
FOOTER_MARKER = b"# Script Size = "
ENCODING_PRESETS = {"6": 6, "9": 9, "9e": 0x80000009}


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def require(condition: bool, reason: str) -> None:
    if not condition:
        raise ValueError(reason)


def regular(path: Path) -> Path:
    """Reject direct symlinks and non-files before reading their contents."""
    require(stat.S_ISREG(path.lstat().st_mode), f"Not a regular input: {path}")
    return path.resolve(strict=True)


def new_output(path: Path) -> Path:
    resolved = path.resolve()
    require(resolved.is_relative_to(OUTPUT_ROOT.resolve()), "Output outside isolated candidate directory")
    require(resolved != OUTPUT_ROOT.resolve(), "Output must be a file")
    require(not path.exists() and not path.is_symlink(), "Refusing to overwrite output")
    # resolve() also catches existing parent symlinks that escape the boundary.
    require(not resolved.exists(), "Output alias already exists")
    return resolved


def ubifs_profile(data: bytes) -> dict:
    require(len(data) >= 4096, "Truncated UBIFS superblock")
    magic, crc = struct.unpack_from("<II", data)
    length = struct.unpack_from("<I", data, 16)[0]
    require(magic == 0x06101831 and data[20] == 6 and length == 4096,
            "Expected an original-style UBIFS superblock")
    require((zlib.crc32(data[8:length]) ^ 0xFFFFFFFF) == crc, "UBIFS superblock CRC mismatch")
    flags, min_io, leb, leb_cnt, max_leb = struct.unpack_from("<IIIII", data, 28)
    fmt_version = struct.unpack_from("<I", data, 80)[0]
    require(min_io == 2048 and leb == 126976 and max_leb == 321,
            "APP UBIFS geometry differs from stock")
    require(flags == 0 and fmt_version == 4, "Unsupported APP UBIFS feature flags/version")
    require(0 < leb_cnt <= max_leb and len(data) == leb_cnt * leb,
            "UBIFS length and LEB count disagree")
    return {"min_io_size": min_io, "leb_size": leb, "leb_count": leb_cnt,
            "max_leb_count": max_leb, "format_version": fmt_version, "flags": flags,
            "superblock_crc_pass": True,
            "scope": "superblock only; full filesystem/content verification is separate"}


def decode_section(data: bytes, section: dict) -> bytes:
    start, size = section["source_offset"], section["compressed_bytes"]
    stream = data[start:start + size]
    require(len(stream) >= 15 and stream[0] == 0x5D, "Unexpected LZMA-alone properties")
    dictionary = int.from_bytes(stream[1:5], "little")
    declared = int.from_bytes(stream[5:13], "little")
    require(dictionary == 64 * 1024 * 1024 and 0 < declared <= MAX_SECTION,
            "Unexpected LZMA dictionary/output budget")
    decoder = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE, memlimit=LZMA_MEMORY_LIMIT)
    decoded = decoder.decompress(stream, max_length=declared + 1)
    require(decoder.eof and len(decoded) == declared and decoder.unused_data == TRAILER,
            "LZMA output size, EOF or BE EF trailer mismatch")
    return decoded


def inspect_package(data: bytes) -> dict:
    """Validate the observed envelope without interpreting any update commands."""
    require(HEADER_SIZE + 24 < len(data) <= MAX_IMAGE, "Unexpected container size")
    require(data[-16:] == FOOTER_MARKER, "Unexpected footer marker")
    body_end = len(data) - 24
    require((body_end - HEADER_SIZE) % ALIGNMENT == 0, "Container alignment mismatch")
    header_crc, image_crc = struct.unpack_from("<II", data, body_end)
    require(header_crc == zlib.crc32(data[:HEADER_SIZE]), "Outer header CRC mismatch")
    require(image_crc == zlib.crc32(data[:body_end + 4]), "Outer image CRC mismatch")
    header, sections = parse_header(data[:HEADER_SIZE], body_end)
    require(header["declared_script_bytes"] == HEADER_SIZE and len(sections) == SECTION_COUNT,
            "Unexpected script size or payload count")
    require(sections[APP_ORDINAL].get("write_target") == "APP", "Unexpected APP ordinal")
    records = []
    total = 0
    cursor = HEADER_SIZE
    for i, section in enumerate(sections):
        require(section["source_offset"] == cursor, "Payload overlap, gap or offset change")
        end = section["source_offset"] + section["compressed_bytes"]
        # APP may shrink by several alignment blocks. The next stock offset
        # still owns the slot boundary; do not infer relocation from its new size.
        slot_end = sections[i + 1]["source_offset"] if i + 1 < len(sections) else body_end
        require(end <= slot_end <= body_end and (slot_end - HEADER_SIZE) % ALIGNMENT == 0,
                "Invalid or overlapping payload slot")
        require(not any(data[end:slot_end]), "Nonzero payload padding")
        require(section.get("mscompress7_declared_input_bytes") == section["compressed_bytes"],
                "mscompress7 input length differs from filepartload")
        decoded = decode_section(data, section)
        total += len(decoded)
        require(total <= MAX_TOTAL, "Decoded container budget exceeded")
        declaration = section.get("crc32_declaration", {})
        require(declaration.get("bytes") == len(decoded), "Section CRC span differs from output length")
        require(section.get("expected_crc32_hex") == f"{zlib.crc32(decoded):08x}",
                "Section payload CRC mismatch")
        records.append({**section, "decoded_bytes": len(decoded), "decoded_sha256": sha(decoded),
                        "slot_end": slot_end, "compressed_sha256": sha(data[section["source_offset"]:end])})
        cursor = slot_end
    require(cursor == body_end, "Unexpected data between last payload and footer")
    return {"sections": records, "header_crc32": f"{header_crc:08x}",
            "image_crc32": f"{image_crc:08x}", "footer_offset": body_end}


def compress_app(app: bytes, preset: str | int = "6") -> bytes:
    """Use host liblzma's LZMA1EXT encoder, with no end-of-payload marker.

    Stock uses a known-size LZMA-alone header. Python's FORMAT_ALONE encoder
    always emits an end marker for unknown size; patching that header alone is
    rejected by the decoder. LZMA1EXT (ext_flags=0) encodes the matching raw
    stream. liblzma allocates/initializes its own options structure, avoiding a
    handwritten ABI structure or firmware SDK dependency. Run under Linux/WSL
    if the host does not provide a discoverable liblzma shared library.
    """
    require(str(preset) in ENCODING_PRESETS, "Unsupported host compression preset")
    library = ctypes.util.find_library("lzma")
    require(library is not None, "Host liblzma required; run this script with Linux/WSL Python")
    lib = ctypes.CDLL(library)

    class Filter(ctypes.Structure):
        _fields_ = [("id", ctypes.c_uint64), ("options", ctypes.c_void_p)]

    lib.lzma_properties_decode.argtypes = [ctypes.POINTER(Filter), ctypes.c_void_p,
                                           ctypes.c_void_p, ctypes.c_size_t]
    lib.lzma_properties_decode.restype = ctypes.c_int
    lib.lzma_lzma_preset.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
    lib.lzma_lzma_preset.restype = ctypes.c_uint8
    lib.lzma_raw_buffer_encode.argtypes = [ctypes.POINTER(Filter), ctypes.c_void_p,
                                           ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p,
                                           ctypes.POINTER(ctypes.c_size_t), ctypes.c_size_t]
    lib.lzma_raw_buffer_encode.restype = ctypes.c_int
    lib.lzma_filters_free.argtypes = [ctypes.POINTER(Filter), ctypes.c_void_p]
    lib.lzma_filters_free.restype = None
    filters = (Filter * 2)()
    filters[0].id = 0x4000000000000001  # LZMA_FILTER_LZMA1
    filters[1].id = 0xFFFFFFFFFFFFFFFF  # LZMA_VLI_UNKNOWN terminator
    properties = b"\x5d\x00\x00\x00\x04"  # lc=3/lp=0/pb=2, dictionary=64 MiB
    ret = lib.lzma_properties_decode(filters, None, properties, len(properties))
    require(ret == 0, f"liblzma properties decoder failed: {ret}")
    try:
        require(lib.lzma_lzma_preset(filters[0].options, ENCODING_PRESETS[str(preset)]) == 0, "liblzma preset failed")
        # These host presets retain lc3/lp0/pb2 and zero ext_flags. The decoder
        # properties remain stock64MiB; higher encoder effort relocates nothing.
        # dict_size is the documented first uint32_t member.
        ctypes.cast(filters[0].options, ctypes.POINTER(ctypes.c_uint32))[0] = 64 * 1024 * 1024
        filters[0].id = 0x4000000000000002  # LZMA_FILTER_LZMA1EXT, no end marker
        capacity = len(app) + len(app) // 3 + 65536
        encoded = ctypes.create_string_buffer(capacity)
        written = ctypes.c_size_t(0)
        ret = lib.lzma_raw_buffer_encode(filters, None, app, len(app), encoded,
                                         ctypes.byref(written), capacity)
        require(ret == 0, f"liblzma LZMA1EXT encoder failed: {ret}")
        result = properties + len(app).to_bytes(8, "little") + encoded.raw[:written.value] + TRAILER
        require(decode_section(result, {"source_offset": 0, "compressed_bytes": len(result)}) == app,
                "Known-size LZMA roundtrip mismatch")
        return result
    finally:
        lib.lzma_filters_free(filters, None)


def rewrite_header(original: bytes, section: dict, app_size: int, packed_size: int, crc: int) -> bytes:
    header = original[:HEADER_SIZE]
    text_end = header.find(b"\x00")
    require(text_end > 0 and not any(header[text_end:]), "Unexpected non-ASCII script padding")
    lines = header[:text_end].splitlines(keepends=True)
    changed = []
    counts = {"filepartload": 0, "mscompress7": 0, "crc32": 0, "mw": 0, "ubi": 0}
    offset = 0
    in_app = False
    for line in lines:
        plain = line.rstrip(b"\r\n")
        ending = line[len(plain):]
        if offset == section["script_offset"]:
            in_app = True
        elif in_app and plain.startswith(b"# File Partition:"):
            in_app = False
        if in_app:
            if plain.startswith(b"filepartload "):
                match = re.fullmatch(rb"(filepartload 0x[0-9a-fA-F]+ \$\(UpgradeImage\) 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( #applications)", plain)
                require(match is not None, "Unexpected APP filepartload syntax")
                plain = match[1] + f"0x{packed_size:x}".encode() + match[2]
                counts["filepartload"] += 1
            elif plain.startswith(b"mscompress7 "):
                match = re.fullmatch(rb"(mscompress7 d 0 0x[0-9a-fA-F]+ )[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #applications)", plain)
                require(match is not None, "Unexpected APP mscompress7 syntax")
                plain = match[1] + f"{packed_size:x}".encode() + match[2]
                counts["mscompress7"] += 1
            elif plain.startswith(b"crc32 "):
                match = re.fullmatch(rb"(crc32 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #applications)", plain)
                require(match is not None, "Unexpected APP CRC syntax")
                plain = match[1] + f"0x{app_size:x}".encode() + match[2]
                counts["crc32"] += 1
            elif plain.startswith(b"mw "):
                match = re.fullmatch(rb"(mw 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 4 #applications)", plain)
                require(match is not None, "Unexpected APP CRC comparison syntax")
                plain = match[1] + f"0x{crc:08X}".encode() + match[2]
                counts["mw"] += 1
            elif plain.startswith(b"ubi write "):
                match = re.fullmatch(rb"(ubi write 0x[0-9a-fA-F]+ APP )0x[0-9a-fA-F]+ 0x[0-9a-fA-F]+( #applications)", plain)
                require(match is not None, "Expected both APP ubi write length fields")
                plain = match[1] + f"0x{app_size:x} 0x{app_size:x}".encode() + match[2]
                counts["ubi"] += 1
        changed.append(plain + ending)
        offset += len(line)
    require(all(n == 1 for n in counts.values()), "Missing or repeated APP update field")
    rebuilt = b"".join(changed)
    require(len(rebuilt) < HEADER_SIZE, "Rebuilt script exceeds header allocation")
    return rebuilt.ljust(HEADER_SIZE, b"\x00")


def unchanged_header_lines(header: bytes) -> list[bytes]:
    return [line for line in header[:HEADER_SIZE].split(b"\x00", 1)[0].splitlines()
            if not (line.endswith(b"#applications") and line.startswith(
                (b"filepartload ", b"mscompress7 ", b"crc32 ", b"mw ", b"ubi write ")))]


def verify_candidate(original: bytes, candidate: bytes, app: bytes, stock: dict | None = None) -> dict:
    stock = inspect_package(original) if stock is None else stock
    rebuilt = inspect_package(candidate)
    require(len(candidate) == len(original), "Container length changed")
    require(unchanged_header_lines(original) == unchanged_header_lines(candidate),
            "Non-APP update commands changed")
    checks = []
    for before, after in zip(stock["sections"], rebuilt["sections"]):
        require(before["source_offset"] == after["source_offset"] and before["slot_end"] == after["slot_end"],
                "Section offset or slot changed")
        if before["ordinal"] == APP_ORDINAL:
            require(after["decoded_sha256"] == sha(app) and after["decoded_bytes"] == len(app),
                    "Rebuilt APP content differs from supplied image")
            app_commands = after["commands"]
            writes = [line for line in app_commands if line.startswith("ubi write ")]
            require(len(writes) == 1 and re.fullmatch(
                rf"ubi write 0x[0-9a-fA-F]+ APP 0x{len(app):x} 0x{len(app):x} #applications", writes[0]) is not None,
                "Rebuilt APP write lengths mismatch")
        else:
            start, end = before["source_offset"], before["slot_end"]
            require(original[start:end] == candidate[start:end], "Non-APP compressed payload/padding changed")
            require(before["decoded_sha256"] == after["decoded_sha256"], "Non-APP decompressed payload changed")
            require(before["commands"] == after["commands"], "Non-APP section commands changed")
        checks.append({"ordinal": before["ordinal"], "target": before.get("write_target", before["label"]),
                       "source_offset": before["source_offset"], "decoded_bytes": after["decoded_bytes"],
                       "decoded_sha256": after["decoded_sha256"], "payload_crc32_pass": True,
                       "lzma_eof_and_beef_pass": True, "unchanged": before["ordinal"] != APP_ORDINAL})
    expected_header = rewrite_header(original, stock["sections"][APP_ORDINAL], len(app),
                                     rebuilt["sections"][APP_ORDINAL]["compressed_bytes"], zlib.crc32(app))
    require(candidate[:HEADER_SIZE] == expected_header,
            "APP commands differ beyond reviewed size/CRC substitutions")
    return {"payloads_decoded": len(checks), "unchanged_payloads": 13, "checks": checks,
            "outer_header_crc32": rebuilt["header_crc32"], "outer_image_crc32": rebuilt["image_crc32"],
            "outer_crc32_pass": True, "zero_padding_pass": True,
            "all_offsets_preserved": True, "non_app_commands_preserved": True,
            "app_sha256": sha(app), "container_sha256": sha(candidate)}


def build_bytes(original: bytes, app: bytes, compression_preset: str | int = "6") -> tuple[bytes, dict]:
    require(sha(original) == STOCK_SHA256, "Unexpected original firmware SHA-256")
    stock = inspect_package(original)
    profile = ubifs_profile(app)
    section = stock["sections"][APP_ORDINAL]
    packed = compress_app(app, compression_preset)
    capacity = section["slot_end"] - section["source_offset"]
    require(len(packed) <= capacity, f"Compressed APP exceeds its stock slot: {len(packed)} > {capacity} bytes; refusing to relocate payloads")
    result = bytearray(original)
    result[:HEADER_SIZE] = rewrite_header(original, section, len(app), len(packed), zlib.crc32(app))
    start = section["source_offset"]
    result[start:section["slot_end"]] = packed.ljust(capacity, b"\x00")
    footer = stock["footer_offset"]
    struct.pack_into("<I", result, footer, zlib.crc32(result[:HEADER_SIZE]))
    struct.pack_into("<I", result, footer + 4, zlib.crc32(result[:footer + 4]))
    candidate = bytes(result)
    verification = verify_candidate(original, candidate, app, stock)
    report = {"schema_version": 1, "artifact_kind": "offline APP-only research candidate",
              "flash_ready": False, "tv_verified": False, "firmware_executed": False,
              "original_sha256": sha(original), "original_bytes": len(original),
              "candidate_bytes": len(candidate), "app_bytes": len(app),
              "app_compressed_bytes": len(packed), "app_slot_bytes": capacity,
              "app_slot_free_bytes": capacity-len(packed), "host_compression_preset": str(compression_preset),
              "ubifs_superblock": profile, "verification": verification,
              "limitations": ["No target program or update command executed",
                              "No cryptographic acceptance or physical-device compatibility claim",
                              "UBIFS contents/metadata/mountability require a separate filesystem comparison",
                              "Browser simulator feature parity is not implied by this container"]}
    return candidate, report


def build(source: Path, app_path: Path, output: Path, report_path: Path, compression_preset: str | int = "6") -> dict:
    source, app_path = regular(source), regular(app_path)
    output, report_path = new_output(output), new_output(report_path)
    require(len({source, app_path, output, report_path}) == 4, "Input/output paths alias each other")
    require(source.stat().st_size <= MAX_IMAGE and app_path.stat().st_size <= 321 * 126976,
            "Input size exceeds source/APP budgets")
    original = source.read_bytes()
    # Validate the expected source before reading arbitrary candidate content.
    require(sha(original) == STOCK_SHA256, "Unexpected original firmware SHA-256")
    with app_path.open("rb") as stream:
        require(stream.read(4) == b"\x31\x18\x10\x06", "APP input is not UBIFS")
    app = app_path.read_bytes()
    candidate, report = build_bytes(original, app, compression_preset)
    require(sha(source.read_bytes()) == STOCK_SHA256 and sha(app_path.read_bytes()) == sha(app),
            "Input changed during build")
    report.update(source_path=str(source), app_path=str(app_path), output_path=str(output))
    # No writes occur until every in-memory format/CRC/14-payload check passes.
    for path in (output, report_path):
        path.parent.mkdir(parents=True, exist_ok=True)
        new_output(path)
    with output.open("xb") as stream:
        stream.write(candidate)
        stream.flush()
        os.fsync(stream.fileno())
    require(sha(output.read_bytes()) == report["verification"]["container_sha256"], "Output readback hash mismatch")
    with report_path.open("x", encoding="utf-8", newline="\n") as stream:
        json.dump(report, stream, ensure_ascii=False, indent=2)
        stream.write("\n")
    return report


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--app", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--compression-preset", choices=tuple(ENCODING_PRESETS), default="6",
                        help="Host encoder effort only; stock decoder properties/offsets remain fixed")
    args = parser.parse_args()
    report = build(args.source, args.app, args.output, args.report, args.compression_preset)
    print(json.dumps({"status": "PASS", "output": report["output_path"],
                      "payloads_decoded": 14, "unchanged_payloads": 13,
                      "flash_ready": False, "tv_verified": False,
                      "sha256": report["verification"]["container_sha256"]}))


if __name__ == "__main__":
    main()
