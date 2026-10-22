"""Inventory extracted firmware without following links or executing targets.

Run with the host's Linux Python, for example:
  python3 scripts/inventory_firmware.py
  python3 scripts/inventory_firmware.py --self-test
Only /usr/bin/readelf is launched, against an already opened regular-file FD.
"""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import stat
import struct
import subprocess
import tempfile
from typing import Any


PROJECT = Path(__file__).resolve().parents[1]
CANONICAL_ROOT = Path("/home/semih/.local/share/grundig-analysis/full-v1/files")
READELF = "/usr/bin/readelf"
SENSITIVE_EXTENSIONS = {".pem", ".key", ".p12", ".pfx", ".crt", ".cer", ".der", ".jks", ".keystore"}
SENSITIVE_COMPONENT = re.compile(
    r"(?:^|[._-])(?:private|privkey|secret|secrets|certificate|certificates|"
    r"serial|serialnumber|serialno|serialid|deviceid|devicekey|keystore|"
    r"credentials|password|shadow|ssh_host|id_rsa|id_dsa|id_ecdsa|id_ed25519)"
    r"(?:$|[._-])", re.IGNORECASE,
)
FILE_TYPES = (
    (stat.S_ISREG, "regular"), (stat.S_ISDIR, "directory"),
    (stat.S_ISLNK, "symlink"), (stat.S_ISCHR, "character_device"),
    (stat.S_ISBLK, "block_device"), (stat.S_ISFIFO, "fifo"),
    (stat.S_ISSOCK, "socket"),
)


def sensitive_reason(relative_path: str) -> str | None:
    """Name-based candidates are skipped before any content read, including ELF magic."""
    for component in PurePosixPath(relative_path).parts:
        if Path(component).suffix.lower() in SENSITIVE_EXTENSIONS:
            return "sensitive_extension"
        if SENSITIVE_COMPONENT.search(component):
            return "sensitive_filename_or_directory"
        if component.lower() in {"cert", "certs", "ssl", "keys", "key", "serial_number", "serialnumber"}:
            return "sensitive_filename_or_directory"
    return None


def open_directory_chain(path: Path) -> int:
    """Open every absolute path component without traversing a symlink."""
    absolute = Path(os.path.abspath(path))
    descriptor = os.open("/", os.O_RDONLY | os.O_DIRECTORY)
    try:
        for component in absolute.parts[1:]:
            next_descriptor = os.open(
                component, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW,
                dir_fd=descriptor,
            )
            os.close(descriptor)
            descriptor = next_descriptor
        return descriptor
    except BaseException:
        os.close(descriptor)
        raise


def identity(metadata: os.stat_result) -> tuple[int, int, int, int]:
    return metadata.st_dev, metadata.st_ino, metadata.st_size, metadata.st_mtime_ns


def parse_readelf(lines: Any) -> dict[str, Any]:
    result: dict[str, Any] = {
        "header": {}, "interpreter": None, "needed": [], "rpath": [],
        "runpath": [], "soname": None, "symbols": [], "relocations": [],
        "symbol_tables": [], "relocation_sections": [],
    }
    symbol_table = None
    relocation_section = None
    relocation_types: Counter[str] = Counter()
    for line in lines:
        text = line.strip()
        if not text:
            continue
        for header in ("Class", "Data", "Type", "Machine", "Flags", "Entry point address", "OS/ABI", "ABI Version"):
            if text.startswith(header + ":"):
                result["header"][header] = text.split(":", 1)[1].strip()
                break
        interpreter = re.search(r"\[Requesting program interpreter: (.*)\]", text)
        if interpreter:
            result["interpreter"] = interpreter.group(1)
        dynamic = re.match(r"0x[0-9a-fA-F]+\s+\((NEEDED|RPATH|RUNPATH|SONAME)\).*?\[(.*)\]", text)
        if dynamic:
            kind, value = dynamic.groups()
            if kind == "SONAME":
                result["soname"] = value
            else:
                result[{"NEEDED": "needed", "RPATH": "rpath", "RUNPATH": "runpath"}[kind]].append(value)
        table = re.match(r"Symbol table '(.*)' contains (\d+) entr(?:y|ies):", text)
        if table:
            symbol_table = table.group(1)
            relocation_section = None
            result["symbol_tables"].append({"name": symbol_table, "declared_entries": int(table.group(2))})
            continue
        reloc = re.match(r"Relocation section '(.*)' at offset (0x[0-9a-fA-F]+) contains (\d+) entr(?:y|ies):", text)
        if reloc:
            relocation_section = reloc.group(1)
            symbol_table = None
            result["relocation_sections"].append({
                "name": relocation_section, "file_offset": reloc.group(2),
                "declared_entries": int(reloc.group(3)),
            })
            continue
        if symbol_table is not None:
            symbol = re.match(r"(\d+):\s+([0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+|\d+)\s+(\S+)\s+(\S+)\s+(\S+)\s+((?:\[[^\]]*\]\s+)*)(\S+)(?:\s+(.*))?$", text)
            if symbol:
                number, value, size, kind, binding, visibility, annotations, section, name = symbol.groups()
                result["symbols"].append({
                    "table": symbol_table, "index": int(number), "value": "0x" + value,
                    "size": int(size, 16 if size.startswith("0x") else 10), "type": kind, "binding": binding,
                    "visibility": visibility, "section": section, "name": name or "",
                    "other_annotations": re.findall(r"\[([^\]]*)\]", annotations),
                })
        if relocation_section is not None:
            relocation = re.match(r"([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+(R_\S+)(?:\s+(.*))?$", text)
            if relocation:
                offset, info, kind, details = relocation.groups()
                relocation_types[kind] += 1
                result["relocations"].append({
                    "section": relocation_section, "offset": "0x" + offset,
                    "info": "0x" + info, "type": kind, "symbol_and_addend": details or "",
                })
    dynamic_symbols = [item for item in result["symbols"] if item["table"] == ".dynsym"]
    imports = [item for item in dynamic_symbols if item["section"] == "UND" and item["name"] and item["binding"] != "LOCAL"]
    exports = [item for item in dynamic_symbols if item["section"] != "UND" and item["name"] and item["binding"] in {"GLOBAL", "WEAK", "UNIQUE"} and item["visibility"] in {"DEFAULT", "PROTECTED"}]
    result["counts"] = {
        "symbols": len(result["symbols"]), "dynamic_symbols": len(dynamic_symbols),
        "dynamic_imports": len(imports), "dynamic_exports": len(exports),
        "relocations": len(result["relocations"]),
    }
    result["dynamic_imports"] = [item["name"] for item in imports]
    result["dynamic_exports"] = [item["name"] for item in exports]
    result["relocation_type_counts"] = dict(sorted(relocation_types.items()))
    result["coverage"] = {
        "symbols_complete": all(
            sum(item["table"] == table["name"] for item in result["symbols"]) == table["declared_entries"]
            for table in result["symbol_tables"]
        ),
        "relocations_complete": all(
            sum(item["section"] == section["name"] for item in result["relocations"]) == section["declared_entries"]
            for section in result["relocation_sections"]
        ),
        "runtime_bindings_verified": False,
    }
    return result


def inspect_elf(descriptor: int) -> dict[str, Any]:
    # pass_fds hands the exact O_NOFOLLOW-opened inode to trusted host readelf.
    command = [READELF, "--wide", "--file-header", "--program-headers", "--dynamic", "--symbols", "--relocs", f"/proc/self/fd/{descriptor}"]
    with tempfile.TemporaryFile(mode="w+t", encoding="utf-8", errors="replace") as output:
        completed = subprocess.run(
            command, stdout=output, stderr=subprocess.PIPE, pass_fds=(descriptor,),
            timeout=180, check=False, env={"LC_ALL": "C", "PATH": "/usr/bin:/bin"},
        )
        output.seek(0)
        result = parse_readelf(output)
    result["readelf_exit_code"] = completed.returncode
    result["diagnostics"] = completed.stderr.decode("utf-8", "replace")[:8192]
    result["diagnostics_truncated"] = len(completed.stderr) > 8192
    return result


def elf_identity_header(descriptor: int) -> dict[str, Any]:
    """Retain numeric ELF declaration facts independently of readelf wording."""
    header = os.pread(descriptor, 64, 0)
    result: dict[str, Any] = {}
    if len(header) < 20 or header[:4] != b"\x7fELF":
        return result
    elf_class, encoding = header[4], header[5]
    result["class_bits"] = {1: 32, 2: 64}.get(elf_class)
    result["byte_order"] = {1: "little", 2: "big"}.get(encoding)
    if encoding not in {1, 2}:
        return result
    byte_order = "<" if encoding == 1 else ">"
    result["type_numeric"] = struct.unpack_from(byte_order + "H", header, 16)[0]
    result["machine_numeric"] = struct.unpack_from(byte_order + "H", header, 18)[0]
    flag_offset = {1: 36, 2: 48}.get(elf_class)
    if flag_offset is not None and len(header) >= flag_offset + 4:
        result["flags_numeric"] = struct.unpack_from(byte_order + "I", header, flag_offset)[0]
        result["flags_hex"] = hex(result["flags_numeric"])
    return result


def inventory(root: Path) -> tuple[list[dict[str, Any]], list[dict[str, Any]], list[dict[str, str]]]:
    files: list[dict[str, Any]] = []
    elfs: list[dict[str, Any]] = []
    errors: list[dict[str, str]] = []

    def visit(directory_fd: int, relative_directory: PurePosixPath) -> None:
        with os.scandir(directory_fd) as iterator:
            names = sorted(item.name for item in iterator)
        for name in names:
            relative = str(relative_directory / name)
            try:
                before = os.stat(name, dir_fd=directory_fd, follow_symlinks=False)
                kind = next((label for predicate, label in FILE_TYPES if predicate(before.st_mode)), "unknown")
                record: dict[str, Any] = {
                    "path": relative, "volume": PurePosixPath(relative).parts[0],
                    "type": kind, "size": before.st_size,
                    "mode": oct(stat.S_IMODE(before.st_mode)),
                    "uid": before.st_uid, "gid": before.st_gid,
                    "sha256": None,
                }
                files.append(record)
                if kind == "symlink":
                    record["target"] = os.readlink(name, dir_fd=directory_fd)
                    record["content_status"] = "symlink_not_followed"
                elif kind == "directory":
                    child_fd = os.open(name, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW, dir_fd=directory_fd)
                    try:
                        if (os.fstat(child_fd).st_dev, os.fstat(child_fd).st_ino) != (before.st_dev, before.st_ino):
                            raise OSError("Directory changed during inventory")
                        visit(child_fd, PurePosixPath(relative))
                    finally:
                        os.close(child_fd)
                elif kind == "regular":
                    reason = sensitive_reason(relative)
                    if reason:
                        record["content_status"] = "skipped_sensitive_candidate"
                        record["skip_reason"] = reason
                        continue
                    descriptor = os.open(name, os.O_RDONLY | os.O_NOFOLLOW | os.O_NONBLOCK, dir_fd=directory_fd)
                    try:
                        opened = os.fstat(descriptor)
                        if not stat.S_ISREG(opened.st_mode) or identity(opened) != identity(before):
                            raise OSError("Regular file changed before opening")
                        digest = hashlib.sha256()
                        magic = b""
                        while True:
                            chunk = os.read(descriptor, 1024 * 1024)
                            if not chunk:
                                break
                            if not magic:
                                magic = chunk[:4]
                            digest.update(chunk)
                        record["sha256"] = digest.hexdigest()
                        record["content_status"] = "hashed"
                        if magic == b"\x7fELF":
                            os.lseek(descriptor, 0, os.SEEK_SET)
                            elf = {"path": relative, "volume": record["volume"], "sha256": record["sha256"], "size": before.st_size}
                            elf.update(elf_identity_header(descriptor))
                            try:
                                elf.update(inspect_elf(descriptor))
                            except (OSError, subprocess.TimeoutExpired) as error:
                                elf["error"] = str(error)
                                errors.append({"path": relative, "stage": "readelf", "error": str(error)})
                            elfs.append(elf)
                        if identity(os.fstat(descriptor)) != identity(before):
                            record["content_status"] = "changed_during_read"
                            record["sha256"] = None
                            if magic == b"\x7fELF":
                                elf["sha256"] = None
                                elf["error"] = "File changed during hashing/ELF inspection; observations are not bound to a stable artifact"
                            raise OSError("File changed during hashing/ELF inspection")
                    finally:
                        os.close(descriptor)
                else:
                    record["content_status"] = "special_file_not_opened"
            except OSError as error:
                errors.append({"path": relative, "stage": "inventory", "error": str(error)})

    root_fd = open_directory_chain(root)
    try:
        visit(root_fd, PurePosixPath())
    finally:
        os.close(root_fd)
    return files, elfs, errors


def dependencies(files: list[dict[str, Any]], elfs: list[dict[str, Any]]) -> dict[str, Any]:
    candidates: dict[str, dict[str, dict[str, Any]]] = defaultdict(dict)
    for item in files:
        if item["type"] in {"regular", "symlink"}:
            candidates[PurePosixPath(item["path"]).name][item["path"]] = {
                "path": item["path"], "volume": item["volume"], "type": item["type"],
                "sha256": item["sha256"], "match": ["basename"],
                **({"symlink_target": item["target"]} if "target" in item else {}),
            }
    for elf in elfs:
        soname = elf.get("soname")
        if soname:
            existing = candidates[soname].get(elf["path"])
            if existing:
                existing["match"].append("soname")
            else:
                candidates[soname][elf["path"]] = {
                    "path": elf["path"], "volume": elf["volume"], "type": "regular",
                    "sha256": elf["sha256"], "match": ["soname"],
                }
    edges = []
    for elf in elfs:
        for name in elf.get("needed", []):
            matches = sorted(candidates.get(name, {}).values(), key=lambda item: item["path"])
            edges.append({
                "source": elf["path"], "needed": name, "candidates": matches,
                "status": "candidate_matches_mount_map_unverified" if matches else "no_candidate_in_extracted_inventory",
                "resolved": False,
            })
    return {
        "edges": edges,
        "counts": {"edges": len(edges), "with_candidates": sum(bool(edge["candidates"]) for edge in edges), "without_candidates": sum(not edge["candidates"] for edge in edges)},
        "limitations": [
            "DT_NEEDED links describe static declarations, not observed runtime loading.",
            "Mount layout, loader search order, symlink chains and environment are unverified; basename/SONAME candidates are never claimed resolved.",
            "dlopen/dlsym, scripts, IPC, kernel interfaces and network connections are outside this dependency inventory.",
        ],
    }


def write_json(output_directory: Path, name: str, document: dict[str, Any]) -> None:
    directory_fd = open_directory_chain(output_directory)
    temporary_name = "." + name + ".inventory-partial"
    try:
        descriptor = os.open(temporary_name, os.O_WRONLY | os.O_CREAT | os.O_EXCL | os.O_NOFOLLOW, 0o600, dir_fd=directory_fd)
        try:
            with os.fdopen(descriptor, "w", encoding="utf-8") as stream:
                json.dump(document, stream, ensure_ascii=True, indent=2)
                stream.write("\n")
                stream.flush()
                os.fsync(stream.fileno())
            os.replace(temporary_name, name, src_dir_fd=directory_fd, dst_dir_fd=directory_fd)
        except BaseException:
            os.unlink(temporary_name, dir_fd=directory_fd)
            raise
    finally:
        os.close(directory_fd)


def self_test() -> None:
    sample = [
        "  Class: ELF32\n", "  Data: 2's complement, little endian\n", "  Machine: MIPS R3000\n",
        " 0x00000001 (NEEDED) Shared library: [libtest.so]\n",
        " 0x0000000e (SONAME) Library soname: [libself.so]\n",
        "Symbol table '.dynsym' contains 5 entries:\n",
        " 0: 00000000 0 NOTYPE LOCAL DEFAULT UND \n",
        " 1: 00000000 0 FUNC GLOBAL DEFAULT UND imported\n",
        " 2: 00401000 0x10000 FUNC GLOBAL DEFAULT 12 exported\n",
        " 3: 004aa320 24 FUNC GLOBAL DEFAULT [MIPS PLT] UND _ZN9Container17GetThisMessageMapEv\n",
        " 4: 00401040 16 FUNC GLOBAL DEFAULT [MIPS16] 12 mips_export\n",
        "Relocation section '.rel.dyn' at offset 0x100 contains 1 entry:\n",
        "00402000 00000103 R_MIPS_REL32 00000000 imported\n",
        "Relocation section '.rel.plt' at offset 0x200 contains 1 entry:\n",
        "00403000 00000103 R_MIPS_REL32 00000000 imported\n",
    ]
    parsed = parse_readelf(sample)
    assert parsed["needed"] == ["libtest.so"]
    assert parsed["counts"]["dynamic_imports"] == 2
    assert parsed["counts"]["dynamic_exports"] == 2
    assert parsed["symbols"][3]["section"] == "UND"
    assert parsed["symbols"][3]["name"] == "_ZN9Container17GetThisMessageMapEv"
    assert parsed["symbols"][3]["other_annotations"] == ["MIPS PLT"]
    assert parsed["symbols"][2]["size"] == 0x10000
    assert parsed["counts"]["relocations"] == 2
    assert parsed["coverage"]["symbols_complete"]
    assert parsed["coverage"]["relocations_complete"]
    with tempfile.TemporaryDirectory(prefix="firmware-inventory-test-") as temporary:
        root = Path(temporary)
        (root / "volume").mkdir()
        (root / "volume" / "normal").write_bytes(b"fixture")
        (root / "volume" / "device.key").write_bytes(b"must not read")
        (root / "volume" / "host-link").symlink_to("/etc/passwd")
        (root / "volume" / "host-directory").symlink_to("/etc", target_is_directory=True)
        os.mkfifo(root / "volume" / "pipe")
        records, elfs, errors = inventory(root)
        by_path = {item["path"]: item for item in records}
        assert not errors and not elfs
        assert by_path["volume/normal"]["sha256"] == hashlib.sha256(b"fixture").hexdigest()
        assert by_path["volume/device.key"]["content_status"] == "skipped_sensitive_candidate"
        assert by_path["volume/host-link"]["target"] == "/etc/passwd"
        assert by_path["volume/host-directory"]["type"] == "symlink"
        assert by_path["volume/pipe"]["content_status"] == "special_file_not_opened"
        assert not any(item["path"].startswith("volume/host-directory/") for item in records)
        try:
            inventory(root / "volume" / "host-directory")
        except OSError:
            pass
        else:
            raise AssertionError("Symlink input root was followed")
    # Resolve only this explicitly trusted host fixture, never an inventory path.
    descriptor = os.open(os.path.realpath("/usr/bin/true"), os.O_RDONLY | os.O_NOFOLLOW)
    try:
        inspected = inspect_elf(descriptor)
        assert inspected["readelf_exit_code"] == 0
        assert inspected["header"]["Class"].startswith("ELF")
        assert inspected["coverage"]["symbols_complete"]
        assert inspected["coverage"]["relocations_complete"]
    finally:
        os.close(descriptor)
    print(json.dumps({"self_test": "passed", "checks": ["readelf_parser", "hash", "sensitive_skip", "symlink_no_follow", "special_fifo_no_open", "root_symlink_refusal", "host_ELF_static_readelf"]}))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=CANONICAL_ROOT)
    parser.add_argument("--output", type=Path, default=PROJECT / "analiz")
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    if os.name != "posix" or not hasattr(os, "O_NOFOLLOW"):
        raise SystemExit("Run using host Linux Python3 (WSL Ubuntu), never firmware Python.")
    if args.self_test:
        self_test()
        return
    files, elfs, errors = inventory(args.root)
    common = {
        "schema_version": 1, "generated_at_utc": datetime.now(timezone.utc).isoformat(),
        "source_root": str(args.root.absolute()), "offline_static_only": True,
        "symlinks_followed": False, "firmware_executed": False,
    }
    limitations = [
        "Inventory describes extracted files, not filesystem completeness; consult extraction logs and original images.",
        "Extracted uid/gid/modes can reflect extraction defaults; not authoritative original firmware metadata.",
        "Sensitive candidate detection is filename-based. Matching files are not opened or hashed; unrecognized secrets may exist.",
        "String and symbol inventories do not establish runtime behavior or complete original source recovery.",
    ]
    write_json(args.output, "dosya-envanteri.json", {
        **common, "counts": dict(Counter(item["type"] for item in files)),
        "sensitive_skipped": sum(item.get("content_status") == "skipped_sensitive_candidate" for item in files),
        "files": files, "errors": errors, "limitations": limitations,
    })
    write_json(args.output, "elf-envanteri.json", {
        **common, "tool": READELF, "elf_count": len(elfs), "elfs": elfs,
        "errors": [error for error in errors if error["stage"] == "readelf"],
        "limitations": limitations + ["Exports/imports count .dynsym declarations; static symtab rows are retained separately.", "Readelf parser coverage compares retained counts with declared table counts; check diagnostics and nonzero exits."],
    })
    write_json(args.output, "bagimliliklar.json", {**common, **dependencies(files, elfs)})
    print(json.dumps({"files": len(files), "elfs": len(elfs), "errors": len(errors), "outputs": ["dosya-envanteri.json", "elf-envanteri.json", "bagimliliklar.json"]}))


if __name__ == "__main__":
    main()
