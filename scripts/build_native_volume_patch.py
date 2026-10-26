"""Guarded offline native volume overlay; never a flashable image or TV command.

Use tools/native-volume-venv/Scripts/python.exe on Windows. Validation requires
capstone==5.0.6 and unicorn==2.1.4. Unicorn executes only the selected UI branch
and a synthetic ABI stub; the firmware executable itself is never launched.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "analiz/dosya-sistemleri-tam"
OUT = ROOT / "analiz/native-ui-candidate/v1/volume"
NUM_REL = "08_APP/rc/rc/bin/Num_res.bin"
ELF_REL = "08_APP/bin/dvbt_board"
NUM_SHA = "e20c03cd212f548eb8154e8e49d6cf4daafc5fd5842887c51590bf76cfe613ff"
ELF_SHA = "51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916"
PATCH_VA = 0xFB81F8
PATCH_OFF = 0xBB81F8
OLD = bytes.fromhex("000000001800dc8f2900c2932700401000000000")
NEW = bytes.fromhex("2900d0932c00c28f0b101000270040141800dc8f")
# Logical widget coordinates, not an assertion of active TV scaling/rendering.
NUM_PATCHES = (
    (0x5A40, 140, 76, "normal root width"),
    (0x5A3F, 460, 540, "normal root height; contains 20+500 panel"),
    (0x5A43, 100, 76, "panel width"),
    (0x5A3E, 420, 500, "panel height"),
    (0x5A68, 0, 23, "speaker/mute x"),
    (0x5A69, 320, 444, "speaker/mute y"),
    (0x5A67, 100, 30, "speaker/mute width"),
    (0x5A66, 100, 30, "speaker/mute height"),
    (0x5A77, 100, 76, "number width"),
    (0x5A79, 20, 18, "number y"),
    (0x5A6C, 45, 35, "track x"),
    (0x5A6D, 88, 92, "track y"),
    (0x5A6B, 10, 6, "track and progress width"),
    (0x5A6A, 200, 320, "track and progress height"),
)


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def elf_va_offset(data: bytes, va: int, length: int) -> int:
    if data[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("Expected ELF32 little endian")
    if struct.unpack_from("<H", data, 18)[0] != 8:
        raise ValueError("Expected MIPS machine")
    if struct.unpack_from("<I", data, 36)[0] != 0x70001005:
        raise ValueError("Unexpected pinned MIPS32r2 flags")
    phoff = struct.unpack_from("<I", data, 28)[0]
    size, count = struct.unpack_from("<HH", data, 42)
    if size != 32:
        raise ValueError("Unexpected ELF program header size")
    matches = []
    for i in range(count):
        kind, off, addr, _, filesz, _, flags, _ = struct.unpack_from("<8I", data, phoff + i * size)
        if kind == 1 and flags & 1 and addr <= va and va + length <= addr + filesz:
            matches.append(off + va - addr)
    if len(matches) != 1:
        raise ValueError("Patch must fit one executable file-backed PT_LOAD")
    return matches[0]


def changed_offsets(before: bytes, after: bytes) -> list[int]:
    if len(before) != len(after):
        raise ValueError("Patch changed file length")
    return [i for i, (a, b) in enumerate(zip(before, after)) if a != b]


def verify_allowlist(before: bytes, after: bytes, allowed: set[int]) -> list[int]:
    changed = changed_offsets(before, after)
    if not set(changed).issubset(allowed) or not changed:
        raise ValueError("Changes outside exact byte allowlist, or empty patch")
    return changed


def construct(num: bytes, elf: bytes) -> tuple[bytes, bytes, list[dict]]:
    if sha(num) != NUM_SHA or sha(elf) != ELF_SHA:
        raise ValueError("Original source SHA256 mismatch; refusing patch")
    header = struct.unpack_from("<14I", num)
    if num[:4] != b"_tsm" or header[1] != len(num) or header[2] != 1 or header[5:8] != (56, 56, 23558):
        raise ValueError("Unexpected pinned Num resource header")
    if len(num) != 56 + header[7] * 4:
        raise ValueError("Unexpected Num table length")
    new_num = bytearray(num)
    changes = []
    for resource_id, old, new, role in NUM_PATCHES:
        off = 56 + resource_id * 4
        if struct.unpack_from("<I", num, off)[0] != old:
            raise ValueError(f"Unexpected Num value: {resource_id:#x}")
        struct.pack_into("<I", new_num, off, new)
        changes.append(dict(id=resource_id, id_hex=hex(resource_id), file_offset=off,
                            original_value=old, candidate_value=new, role=role))
    off = elf_va_offset(elf, PATCH_VA, len(OLD))
    if off != PATCH_OFF or elf[off:off + len(OLD)] != OLD:
        raise ValueError("Original branch bytes/PT_LOAD mapping mismatch")
    new_elf = bytearray(elf)
    new_elf[off:off + len(NEW)] = NEW
    verify_allowlist(num, new_num, {56 + i * 4 + k for i, *_ in NUM_PATCHES for k in range(4)})
    verify_allowlist(elf, new_elf, set(range(off, off + len(NEW))))
    return bytes(new_num), bytes(new_elf), changes


def direct_entry_scan(elf: bytes) -> dict:
    """Bounded raw direct branches and literal pointers; not computed-target proof."""
    shoff = struct.unpack_from("<I", elf, 32)[0]
    size, count = struct.unpack_from("<HH", elf, 46)
    if size != 40:
        raise ValueError("Unexpected section header size")
    span = set(range(PATCH_VA, PATCH_VA + len(NEW), 4))
    incoming = []
    executable_bytes = 0
    for i in range(count):
        section = struct.unpack_from("<10I", elf, shoff + i * size)
        if not section[2] & 4:
            continue
        addr, off, length = section[3:6]
        executable_bytes += length
        for p in range(off, off + length - 3, 4):
            word = struct.unpack_from("<I", elf, p)[0]
            pc = addr + p - off
            op = word >> 26
            imm = word & 0xFFFF
            imm = imm - 65536 if imm & 32768 else imm
            target = None
            if op in (2, 3):
                target = ((pc + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
            elif op in (1, 4, 5, 6, 7, 20, 21, 22, 23) or (op in (16, 17, 18) and (word >> 21) & 31 == 8):
                target = pc + 4 + imm * 4
            if target in span:
                incoming.append(dict(site=hex(pc), target=hex(target)))
    literals = {hex(v): elf.count(struct.pack("<I", v)) for v in sorted(span)}
    if incoming or any(literals.values()):
        raise ValueError("Unexpected entry into inline replacement window")
    return dict(executable_bytes_scanned=executable_bytes, direct_incoming=incoming,
                literal_va_counts=literals, computed_entries_resolved=False)


def validate_host(elf: bytes, candidate: bytes) -> dict:
    import capstone
    import unicorn
    from unicorn import mips_const as m

    if capstone.__version__ != "5.0.6" or unicorn.__version__ != "2.1.4":
        raise ValueError("Host validation engine versions differ from pinned versions")
    dis = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
    decoded = list(dis.disasm(NEW, PATCH_VA))
    if len(decoded) != 5 or [x.mnemonic for x in decoded] != ["lbu", "lw", "movn", "bnez", "lw"]:
        raise ValueError("Independent instruction decoding mismatch")
    frame, stub, sentinel = 0x20000800, 0x10000000, 0x10001000
    expected_gp, saved_s0 = 0x10D00000, 0x11223344
    start, epilogue = 0xFB81EC, 0xFB8B0C
    code_page = 0xFB8000
    page = bytearray(0x1000)
    offset = elf_va_offset(elf, code_page, len(page))
    page[:] = candidate[offset:offset + len(page)]
    cases = 0
    for volume in range(101):
        for muted in (0, 1):
            uc = unicorn.Uc(unicorn.UC_ARCH_MIPS, unicorn.UC_MODE_MIPS32 | unicorn.UC_MODE_LITTLE_ENDIAN)
            uc.mem_map(code_page, 0x1000)
            uc.mem_write(code_page, bytes(page))
            uc.mem_map(stub, 0x2000)
            # Synthetic callee: jr ra / nop. No firmware function is executed.
            uc.mem_write(stub, bytes.fromhex("0800e00300000000"))
            uc.mem_map(0x20000000, 0x2000)
            uc.reg_write(m.UC_MIPS_REG_SP, frame)
            uc.reg_write(m.UC_MIPS_REG_S8, frame)
            uc.reg_write(m.UC_MIPS_REG_T9, stub)
            uc.reg_write(m.UC_MIPS_REG_S0, saved_s0)
            uc.reg_write(m.UC_MIPS_REG_GP, expected_gp)
            uc.reg_write(m.UC_MIPS_REG_V0, 0x66778899)
            uc.reg_write(m.UC_MIPS_REG_V1, 0x22334455)
            uc.reg_write(m.UC_MIPS_REG_A0, 0x30000000)
            uc.reg_write(m.UC_MIPS_REG_A3, frame + 0x40)
            uc.mem_write(frame + 0x18, struct.pack("<I", expected_gp))
            uc.mem_write(frame + 0x29, bytes([muted]))
            uc.mem_write(frame + 0x2C, struct.pack("<I", volume))
            uc.mem_write(frame + 0xAC, struct.pack("<5I", saved_s0, 0x55667788,
                                                 0x12345678, 0x20000020, sentinel))
            trace = []
            selected = []

            def hook(machine, address, size, _):
                trace.append(address)
                if address == stub:
                    if machine.reg_read(m.UC_MIPS_REG_S0) != muted:
                        raise AssertionError("jalr delay slot did not load mute into callee-saved s0")
                    args = [machine.reg_read(r) for r in (m.UC_MIPS_REG_A0, m.UC_MIPS_REG_A1,
                                                         m.UC_MIPS_REG_A2, m.UC_MIPS_REG_A3)]
                    if args != [0x30000000, 0x22334455, 0x66778899, frame + 0x40]:
                        raise AssertionError("Existing virtual call arguments changed")
                    # Stress volatile registers and gp while preserving standard callee-saved state.
                    for reg in (m.UC_MIPS_REG_V0, m.UC_MIPS_REG_V1, m.UC_MIPS_REG_A0,
                                m.UC_MIPS_REG_A1, m.UC_MIPS_REG_A2, m.UC_MIPS_REG_A3,
                                m.UC_MIPS_REG_T0, m.UC_MIPS_REG_T1, m.UC_MIPS_REG_T9,
                                m.UC_MIPS_REG_GP):
                        machine.reg_write(reg, 0xDEADBEEF)
                elif address in (0xFB820C, 0xFB82A4):
                    if machine.reg_read(m.UC_MIPS_REG_GP) != expected_gp:
                        raise AssertionError("Branch delay slot did not restore gp")
                    selected.append(address)
                    machine.emu_stop()
                elif address == sentinel:
                    machine.emu_stop()

            uc.hook_add(unicorn.UC_HOOK_CODE, hook)
            uc.emu_start(start, sentinel, count=50)
            expected = 0xFB82A4 if volume > 0 and not muted else 0xFB820C
            if selected != [expected] or PATCH_VA not in trace or 0xFB8208 not in trace:
                raise AssertionError(f"Incorrect branch/delay execution at volume={volume}, mute={muted}")
            if uc.mem_read(frame + 0x29, 1) != bytes([muted]) or uc.mem_read(frame + 0x2C, 4) != struct.pack("<I", volume):
                raise AssertionError("UI snippet modified mute or volume state")
            uc.emu_start(epilogue, sentinel, count=30)
            if (uc.reg_read(m.UC_MIPS_REG_S0) != saved_s0 or
                    uc.reg_read(m.UC_MIPS_REG_SP) != frame + 0xC0 or
                    uc.reg_read(m.UC_MIPS_REG_S8) != 0x20000020):
                raise AssertionError("Existing function epilogue failed to restore callee-saved state")
            cases += 1
    return dict(capstone_version=capstone.__version__, unicorn_version=unicorn.__version__,
                decoded=[dict(address=hex(i.address), mnemonic=i.mnemonic, operands=i.op_str,
                              bytes=i.bytes.hex()) for i in decoded],
                emulator_cases=cases, volume_range=[0, 100], mute_states=[0, 1],
                delay_slots_verified=True, virtual_call_arguments_preserved=True,
                volatile_register_clobber_test=True, gp_restore_verified=True,
                saved_s0_and_epilogue_verified=True, original_state_unchanged=True,
                hardware_or_service_code_executed=False,
                limitation="Synthetic callee preserves MIPS ABI s0; actual widget callee not emulated")


def output_guard(path: Path) -> Path:
    path = Path(path).absolute()
    # Resolve boundary against the physical repository, never a symlinked OUT.
    boundary = ROOT.resolve() / "analiz/native-ui-candidate/v1/volume"
    if not path.resolve().is_relative_to(boundary):
        raise ValueError("Output leaves dedicated candidate boundary")
    current = path
    while current != ROOT:
        if current.is_symlink() or (hasattr(current, "is_junction") and current.is_junction()):
            raise ValueError("Symlink/junction output component forbidden")
        if current.exists() and current.is_file() and current.stat().st_nlink > 1:
            raise ValueError("Hardlinked output forbidden")
        current = current.parent
    if path.exists() and path.is_file() and any(path.samefile(SOURCE / r) for r in (NUM_REL, ELF_REL)):
        raise ValueError("Output aliases an original source")
    return path


def build() -> dict:
    # Resolve every destination before creating or writing any output file.
    targets = [OUT / "candidate" / NUM_REL, OUT / "candidate" / ELF_REL,
               OUT / "manifest.json", OUT / "validation.json"]
    for p in targets:
        output_guard(p)
    num = (SOURCE / NUM_REL).read_bytes()
    elf = (SOURCE / ELF_REL).read_bytes()
    new_num, new_elf, num_changes = construct(num, elf)
    entry_check = direct_entry_scan(elf)
    host = validate_host(elf, new_elf)
    records = []
    for rel, before, after in ((NUM_REL, num, new_num), (ELF_REL, elf, new_elf)):
        changed = changed_offsets(before, after)
        records.append(dict(relative_path=rel, original_sha256=sha(before),
                            candidate_sha256=sha(after), original_bytes=len(before), candidate_bytes=len(after),
                            changed_byte_count=len(changed), changed_byte_offsets=changed,
                            candidate=(OUT / "candidate" / rel).relative_to(ROOT).as_posix()))
    report = dict(schema_version=1, status="offline_candidate_not_TV_validated", records=records,
                  num_patches=num_changes,
                  elf_patch=dict(virtual_address=hex(PATCH_VA), file_offset=PATCH_OFF,
                                 original_hex=OLD.hex(), candidate_hex=NEW.hex(),
                                 scope="normal volume branch icon selection only; volume zero uses mute image",
                                 service_mute_flags_changed=False, arc_routing_changed=False,
                                 no_codecave_or_trampoline=True),
                  sources=dict(num=NUM_REL, elf=ELF_REL), direct_entry_check=entry_check,
                  host_validation=host, originals_modified=False, firmware_repacked=False,
                  target_executed=False, TV_tested=False, flashable=False,
                  unchanged=["ARC branches", "hardware mute flags", "font and color tables", "event maps", "PNG assets"],
                  unresolved=["Active TV firmware/profile match", "native image fitting and ShowBorder semantics",
                              "30px icon appearance and final window clipping/scaling", "on-device timing and recovery"])
    validation = dict(status="PASS_HOST_ONLY", host_validation=host,
                      changed_bytes_allowlist_pass=True, original_sha256_unchanged=True,
                      direct_entry_check=entry_check, TV_tested=False)
    for p in targets:
        output_guard(p)
    for p, content in zip(targets, (new_num, new_elf,
                                  (json.dumps(report, ensure_ascii=False, indent=2) + "\n").encode(),
                                  (json.dumps(validation, ensure_ascii=False, indent=2) + "\n").encode())):
        p.parent.mkdir(parents=True, exist_ok=True)
        output_guard(p)
        p.write_bytes(content)
    if sha((SOURCE / NUM_REL).read_bytes()) != NUM_SHA or sha((SOURCE / ELF_REL).read_bytes()) != ELF_SHA:
        raise ValueError("Original source changed during build")
    for rec in records:
        if sha((ROOT / rec["candidate"]).read_bytes()) != rec["candidate_sha256"]:
            raise ValueError("Written candidate hash mismatch")
    return report


if __name__ == "__main__":
    argparse.ArgumentParser(description=__doc__).parse_args()
    result = build()
    print(json.dumps(dict(status=result["status"], files=len(result["records"]),
                          num_records=len(result["num_patches"]), elf_window_bytes=len(NEW),
                          emulator_cases=result["host_validation"]["emulator_cases"],
                          manifest=(OUT / "manifest.json").relative_to(ROOT).as_posix(), TV_tested=False)))
