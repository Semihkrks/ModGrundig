"""Verify the existing native fast-zapping path, without patching firmware.

The live database and the native Yes/No switch already control the real
200/2000 ms AV-sync timeout. There is deliberately no apply() mutator: forcing
a getter would break the existing Off control, and default-data edits would
not activate a persisted user database.
"""
from __future__ import annotations

import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
APP_HASHES = {
    "51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916",
    "861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea",
}
MODULE_HASHES = {
    "libmsrv_dvb.so": "93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97",
    "libmsrv_system_database.so": "dbdef96fed7bd96d18b44c641203491649a04909d50aa8ecf8d7af4cf6fd4882",
    "libmsrv_common_customer.so": "394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39",
    "libmsrv_common.so": "06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21",
}


def file_offset(image: bytes, va: int, length: int = 4) -> int:
    """Resolve file-backed ELF32 little-endian MIPS PT_LOAD bytes only."""
    if image[:7] != b"\x7fELF\x01\x01\x01" or len(image) < 52:
        raise ValueError("Expected an ELF32 little-endian image")
    if struct.unpack_from("<H", image, 18)[0] != 8:
        raise ValueError("Expected a MIPS ELF")
    ph, = struct.unpack_from("<I", image, 28)
    es, count = struct.unpack_from("<HH", image, 42)
    if es < 32 or ph + es * count > len(image):
        raise ValueError("Invalid ELF program-header bounds")
    matches = []
    for index in range(count):
        kind, off, start, _, size, *_ = struct.unpack_from("<8I", image, ph + es * index)
        if kind == 1 and start <= va and va + length <= start + size:
            result = off + va - start
            if result + length > len(image):
                raise ValueError("PT_LOAD exceeds image")
            matches.append(result)
    if len(matches) != 1:
        raise ValueError(f"Address {va:#x} is not uniquely file-backed")
    return matches[0]


def word(image: bytes, va: int) -> int:
    return struct.unpack_from("<I", image, file_offset(image, va))[0]


def require_words(image: bytes, checks: dict[int, int]) -> list[dict]:
    rows = []
    for va, expected in checks.items():
        actual = word(image, va)
        if actual != expected:
            raise ValueError(f"Instruction mismatch at {va:#x}: {actual:#010x} != {expected:#010x}")
        rows.append({"va": f"0x{va:08x}", "file_offset": file_offset(image, va), "word": f"0x{actual:08x}"})
    return rows


def collect_proof(app: bytes, firmware_root: Path = ROOT / "analiz/dosya-sistemleri-tam") -> dict:
    digest = hashlib.sha256(app).hexdigest()
    if digest not in APP_HASHES:
        raise ValueError("Unsupported app baseline; only original or verified V7.9 is accepted")
    # The handler reads the combo's selected value and passes it in a1.
    app_checks = require_words(app, {
        0x0053D544: 0x93C30034,  # lbu v1,0x34(s8): preserve requested value
        0x0053D54C: 0x00602821,  # move a1,v1: DB setter argument
        0x0053D5D0: 0x00402821,  # move a1,v0: player setter argument
        0x00D23544: 0x24050E39,  # options[0] = Hayir / No
        0x00D23560: 0x2405106C,  # options[1] = Evet / Yes
    })
    checks = {
        "libmsrv_system_database.so": {0x2E578840: 0x923037C8},
        "libmsrv_common_customer.so": {
            0x2DFD34BC: 0x03E00008,  # jr ra
            0x2DFD34C0: 0xA48501D6,  # delay-slot sh a1,0x1d6(a0), real setter
        },
        "libmsrv_common.so": {
            0x2D9DA2DC: 0x240200C8,  # enabled timeout = 200
            0x2D9DA2E0: 0xA60201D6,
            0x2D9DA330: 0x240207D0,  # disabled timeout = 2000
            0x2D9DA338: 0xA60201D6,
            0x2D9CFEAC: 0x03E00008,
            0x2D9CFEB0: 0x948201D6,  # GetAvSyncTimeout returns the same field
            0x2D9D6798: 0x8C590008,  # virtual getter slot +8
            0x2D9D67A4: 0x0054102B,  # timeout < elapsed
        },
        "libmsrv_dvb.so": {
            0x2D4C7574: 0x03E00008,
            0x2D4C7578: 0x00001021,  # separate capability returns 0; not patched
        },
    }
    modules = []
    for name, expected_hash in MODULE_HASHES.items():
        blob = (firmware_root / "07_MSLIB" / name).read_bytes()
        actual_hash = hashlib.sha256(blob).hexdigest()
        if actual_hash != expected_hash:
            raise ValueError(f"Unexpected module identity: {name}")
        modules.append({"name": name, "sha256": actual_hash, "checked_words": require_words(blob, checks[name])})
    return {
        "schema_version": 1,
        "offline_static_only": True,
        "target_executed": False,
        "patch_emitted": False,
        "decision": "Existing native live-database Yes/No control is functional; retain it without forced getters or BasicMode bypass",
        "app_sha256": digest,
        "checked_app_words": app_checks,
        "modules": modules,
        "menu_turkish": ["Ayarlar", "Genel", "Gelişmiş", "Hızlı Kanal Geçişi", "Evet"],
        "selected_value": {"Hayır": 0, "Evet": 1},
        "ui_handler": "0x00cf58d8",
        "db_field": "MSrv_System_Database+0x37c8",
        "db_setter_saves": "SaveUserGeneralSettings",
        "runtime_field": "MW_DTV_AVMonitor+0x1d6",
        "enabled_avsync_timeout_ms": 200,
        "disabled_avsync_timeout_ms": 2000,
        "timeout_condition": "In DoVideoSync, if IsSyncDone()==0 and elapsed<=GetAvSyncTimeout(), return and keep waiting; synchronization may finish earlier",
        "visibility": "No individual Fast Zapping gate found in General OnCreate; Advanced entry is hidden when both service BasicMode and user BasicMode equal 1",
        "limits": [
            "Live device database value and active source are unknown",
            "200/2000 ms is an AV-sync timeout, not an observed channel-switch duration or guaranteed saving",
            "Signal lock, decoded-frame, PCR/audio and file-in waits remain present",
            "Static query data is direct Ghidra output, not REA Evidence or device measurement",
        ],
    }


if __name__ == "__main__":
    source = ROOT / "analiz/native-ui-candidate/v7.9-tv/overlay/08_APP/bin/dvbt_board"
    proof = collect_proof(source.read_bytes())
    destination = ROOT / "analiz/native-features/fast-channel/proof.json"
    destination.write_text(json.dumps(proof, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"proof": str(destination), "patch_emitted": False, "modules_checked": len(proof["modules"])}, ensure_ascii=False))
