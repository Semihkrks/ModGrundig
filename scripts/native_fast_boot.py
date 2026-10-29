"""Read-only, hash-pinned checks for the shipped fast-boot implementation.

This module deliberately provides no patch/apply operation: a UI flag cannot
restore code omitted by the build. It never executes a firmware program.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "analiz/native-features/fast-boot"
SOURCES = {
    "original_app": ("08_APP/bin/dvbt_board", "51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916"),
    "control": ("07_MSLIB/libmsrv_control.so", "0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea"),
    "database": ("07_MSLIB/libmsrv_system_database.so", "dbdef96fed7bd96d18b44c641203491649a04909d50aa8ecf8d7af4cf6fd4882"),
    "power": ("07_MSLIB/libmsrv_common_customer.so", "394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39"),
}
V79_SHA = "861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea"


def checked_bytes(path: Path, expected: str) -> bytes:
    if path.is_symlink():
        raise ValueError("Symlink source refused")
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError(f"Source identity mismatch: {path.name}")
    return data


class Elf32:
    """Only ELF32 LE MIPS layout needed for bounded static byte comparisons."""

    def __init__(self, data: bytes):
        if len(data) < 52 or data[:7] != b"\x7fELF\x01\x01\x01":
            raise ValueError("ELF32 little endian required")
        if struct.unpack_from("<H", data, 18)[0] != 8:
            raise ValueError("MIPS required")
        self.data = data
        phoff, shoff = struct.unpack_from("<II", data, 28)
        phsize, phnum, shsize, shnum = struct.unpack_from("<4H", data, 42)
        if phsize != 32 or shsize != 40 or not phnum or not shnum:
            raise ValueError("Unsupported ELF tables")
        self._span(phoff, phsize * phnum)
        self._span(shoff, shsize * shnum)
        self.loads = [struct.unpack_from("<8I", data, phoff + i * 32)
                      for i in range(phnum)
                      if struct.unpack_from("<I", data, phoff + i * 32)[0] == 1]
        self.sections = [struct.unpack_from("<10I", data, shoff + i * 40)
                         for i in range(shnum)]

    def _span(self, off: int, size: int) -> bytes:
        if off < 0 or size < 0 or off + size > len(self.data):
            raise ValueError("ELF range outside source")
        return self.data[off:off + size]

    def at(self, va: int, size: int) -> bytes:
        for p in self.loads:
            if p[2] <= va and va + size <= p[2] + p[4]:
                return self._span(p[1] + va - p[2], size)
        raise ValueError("Address is not fully file-backed")

    def symbol(self, name: str) -> dict:
        found = []
        for sec in self.sections:
            if sec[1] != 11:  # SHT_DYNSYM
                continue
            if sec[9] != 16 or sec[5] % 16 or sec[6] >= len(self.sections):
                raise ValueError("Malformed dynamic symbols")
            self._span(sec[4], sec[5])
            strings = self.sections[sec[6]]
            table = self._span(strings[4], strings[5])
            for off in range(sec[4], sec[4] + sec[5], 16):
                n, va, size, info, _, shndx = struct.unpack_from("<IIIBBH", self.data, off)
                if n >= len(table):
                    raise ValueError("Symbol string outside table")
                end = table.find(b"\0", n)
                if end < 0:
                    raise ValueError("Unterminated symbol")
                if table[n:end] == name.encode() and shndx and info & 15 == 2:
                    found.append({"symbol": name, "elf_va": f"0x{va:x}", "size": size,
                                  "hex": self.at(va, size).hex()})
        if len(found) != 1:
            raise ValueError(f"Expected exactly one defined function: {name}")
        return found[0]


def inspect_sources(root: Path = ROOT) -> dict:
    views = {}
    for key, (relative, sha) in SOURCES.items():
        views[key] = Elf32(checked_bytes(root / "analiz/dosya-sistemleri-tam" / relative, sha))
    current = Elf32(checked_bytes(root / "analiz/native-ui-candidate/v7.9-tv/overlay/08_APP/bin/dvbt_board", V79_SHA))
    stubs = []
    for name in ("_ZN12MSrv_Control18Normal2FakeStandbyEv",
                 "_ZN12MSrv_Control18FakeStandby2NormalEv",
                 "_ZN12MSrv_Control26FakeStandby2ScheduledEventEv"):
        row = views["control"].symbol(name)
        if row["size"] != 8 or row["hex"] != "0800e00300000000":
            raise ValueError("Expected return-only compiled fast-boot transition changed")
        row["meaning"] = "jr ra; nop; no transition or state write"
        stubs.append(row)
    fake = views["power"].symbol("_ZN17ArSrvPowerManager11FakeStandbyEv")
    if fake["size"] != 8 or fake["hex"] != "0800e00301000224":
        raise ValueError("Expected success-only FakeStandby stub changed")
    # These original runtime ranges must also be unchanged in the V7.9 base.
    app_ranges = []
    for va, size in ((0xcf576c, 364), (0x53bf20, 96), (0x53bf80, 112),
                     (0x532d8c, 104), (0x532f24, 708), (0xea019c, 1860)):
        original = views["original_app"].at(va, size)
        if current.at(va, size) != original:
            raise ValueError(f"V7.9 fast-boot/power range changed: {va:x}")
        app_ranges.append({"va": f"0x{va:x}", "bytes": size,
                           "sha256": hashlib.sha256(original).hexdigest(),
                           "v79_identical": True})
    evidence = root / "analiz/native-features/fast-boot"
    queries = []
    for run, expected, count in (("ui-v1", SOURCES["original_app"][1], 5),
                                 ("db-v1", SOURCES["database"][1], 5),
                                 ("control-v1", SOURCES["control"][1], 3),
                                 ("power-v1", SOURCES["power"][1], 5),
                                 ("app-power-v1", SOURCES["original_app"][1], 2),
                                 ("app-resume-v1", SOURCES["original_app"][1], 2),
                                 ("startup-v1", SOURCES["power"][1], 2)):
        summary = json.loads((evidence / run / "summary.json").read_text(encoding="utf-8"))
        if (summary["stored_executable_sha256"] != expected
                or summary["requested_count"] != count
                or summary["decompile_complete_count"] != count
                or summary["target_executed"] or summary["target_bytes_written"]):
            raise ValueError(f"Incomplete or wrong-source static query: {run}")
        queries.append({"run": run, "target_sha256": expected, "complete_functions": count})
    inventory_path = root / "analiz/envanter-v2/elf-envanteri.json"
    inventory_bytes = inventory_path.read_bytes()
    inventory = json.loads(inventory_bytes)
    if inventory["elf_count"] != 226 or len(inventory["elfs"]) != 226:
        raise ValueError("Expected original 226-ELF inventory")
    imports = [{"path": item["path"],
                "symbols": [s for s in item["dynamic_imports"] if "FastBoot" in s]}
               for item in inventory["elfs"]
               if any("FastBoot" in s for s in item["dynamic_imports"])]
    flags = (root / "analiz/dosya-sistemleri-tam/09_CONFIG/Flags").read_text().split()
    metadata_flags = {key: key + "=0" in flags for key in
                      ("FAST_BOOT_ENABLE", "ACTIVE_STANDBY_MODE_ENABLE")}
    return {
        "schema_version": 1,
        "method": "hash-pinned offline ELF byte checks plus retained direct Ghidra queries",
        "source_sha256": {key: sha for key, (_, sha) in SOURCES.items()},
        "v79_app_sha256": V79_SHA,
        "compiled_transition_stubs": stubs,
        "customer_FakeStandby_success_stub": fake,
        "v79_unchanged_ranges": app_ranges,
        "retained_direct_ghidra_queries": queries,
        "dynamic_import_inventory_sha256": hashlib.sha256(inventory_bytes).hexdigest(),
        "fast_boot_dynamic_imports_in_original_226_ELFs": imports,
        "build_metadata_flags_equal_zero": metadata_flags,
        "decision": "do_not_enable_fast_boot_setting",
        "reason": "UI and persistent fields exist, but the selected power path lacks a verified fast-boot setting consumer; legacy transition entry points are stubs.",
        "patch_emitted": False,
        "firmware_executed": False,
        "firmware_bytes_modified": False,
        "device_speed_measured": False,
    }


def main() -> None:
    proof = inspect_sources()
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / "byte-proof.json").write_text(json.dumps(proof, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    edge_rows = []
    selections = [(OUT / q["run"], q["target_sha256"]) for q in proof["retained_direct_ghidra_queries"]]
    selections.append((ROOT / "analiz/native/ui-four/general/bounded300", SOURCES["original_app"][1]))
    for directory, sha in selections:
        for path in sorted(directory.glob("*.json")):
            row = json.loads(path.read_text(encoding="utf-8"))
            if not isinstance(row, dict) or "instructions" not in row:
                continue
            instructions = row["instructions"]
            for call in row.get("decompiler_pcode_calls", []):
                target = call.get("target_function", {}).get("name", "")
                if not any(term in target for term in ("FastBoot", "SetPowerState", "SuspendSystem", "StartStandby", "SaveUserGeneralSettings", "SaveFactoryTvConfigurationSetting")):
                    continue
                va = int(call["instruction_address"], 16)
                context = [{"va": ins["address"], "instruction": ins["instruction"]}
                           for ins in instructions if va - 20 <= int(ins["address"], 16) <= va + 20]
                edge_rows.append({"source_report": path.relative_to(ROOT).as_posix(), "source_sha256": sha,
                                  "caller": row.get("name"), "call": call, "nearby_instructions": context})
    (OUT / "static-edges.json").write_text(json.dumps(edge_rows, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"decision": proof["decision"], "compiled_stubs": len(proof["compiled_transition_stubs"]),
                      "patch_emitted": False}, ensure_ascii=False))


if __name__ == "__main__":
    main()
