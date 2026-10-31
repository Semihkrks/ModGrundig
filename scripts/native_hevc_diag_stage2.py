"""Bounded, read-only post-DoVideoSync telemetry on the pinned v3 candidate.

One main live monitor is sampled at >=2/4/6 seconds after its codec/PID key is
first seen. Only two previously unused writable padding gaps hold our state.
Original monitoring/branch policy and every byte of the v3 init hook remain.
"""
from __future__ import annotations
import hashlib
import json
import struct
from pathlib import Path

import native_hevc_diag as old
from native_hevc_audio_test import va_offset
from native_ui_v75_name import Assembler, ZERO, V0, V1, A0, A1, A2, A3, T0, T1, T9, S0, GP, SP, RA

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT/'analiz/native-4k/diag-hooks/fifo-v3/libmsrv_common.so'
OUT = ROOT/'analiz/native-4k/diag-hooks/stage2-sync'
INPUT_SHA = '6967d9da7c95b79664924aa8c308380e6d985d57c814aa5ff5dd37670f864f7a'
ENTRY, ZERO_PATH, NONZERO_PATH, ORIGINAL_RA = 0x2d9d6cec, 0x2d9d6d00, 0x2d9d6d44, 0x2d9d6cf8
HELPER, FORMAT, LIMIT = 0x2d957800, 0x2d958400, 0x2d958500
KEY, CLOCK = 0x2da89f94, 0x2da8d0b4
GP_CANON = old.GP_CANON
FRAME, BUFFER, PROC_BUFFER, STAT_BUFFER = 0x300, 0x40, 0x100, 0x140
SAVE, HI_SLOT, LO_SLOT, FD_SLOT = 0x240, 0x284, 0x288, 0x290
ERRPTR_SLOT, ERR_SLOT, GP_SLOT, RA_SLOT = 0x298, 0x29c, 0x2f8, 0x2fc
ELAPSED, FRAMES, MAD, BRANCH_READY, NOW = 0x2a0, 0x2a4, 0x2a8, 0x2ac, 0x2b0
GOT = dict(old.GOT, checkpoint=-0x6730, time=-0x775c, frames=-0x6228, mad=-0x5090)
OLD = (0x8f9998d0, 0x0320f809, 0x02002021, 0x92020092, 0x14400011)
FMT = b'MGDIAG 4 %u %u %u %u %u %u %u %u %u %u %u\n\0'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def addr(a, register, address):
    old.runtime_address(a, register, address)


def trampoline():
    a = Assembler(ENTRY)
    addr(a, T9, HELPER)
    a.r(T9, ZERO, RA, 9)
    a.emit(0)
    result = a.finish()
    assert len(result) == 20
    return result


def helper_code():
    a = Assembler(HELPER)
    a.addiu(SP, SP, -FRAME)
    a.sw(RA, RA_SLOT)
    a.sw(GP, GP_SLOT)

    def call(name):
        a.lw(T9, GOT[name], GP)
        a.r(T9, ZERO, RA, 9)
        a.emit(0)
        a.lw(GP, GP_SLOT)

    a.move(A0, S0)
    call('checkpoint')
    # The replaced native lbu/branch observes this byte immediately after the
    # native DoVideoSync. Preserve that decision across diagnostics.
    a.lbu(V0, 0x92, S0)
    a.sw(V0, BRANCH_READY)
    for i, register in enumerate(old.VOLATILE):
        a.sw(register, SAVE+i*4)
    a.r(ZERO, ZERO, T0, 0x10)
    a.sw(T0, HI_SLOT)
    a.r(ZERO, ZERO, T0, 0x12)
    a.sw(T0, LO_SLOT)
    call('errno')
    a.beq(V0, ZERO, 'restore')
    a.sw(V0, ERRPTR_SLOT)
    a.lw(V1, 0, V0)
    a.sw(V1, ERR_SLOT)
    # Native constructor identifies main monitor/window; exclude PVR controls.
    a.lw(V0, 0xc, S0)
    a.li(V1, 0x1c)
    a.bne(V0, V1, 'restore_errno')
    a.lw(V0, 0x1c8, S0)
    a.bne(V0, ZERO, 'restore_errno')
    a.lbu(V0, 0x1be, S0)
    a.bne(V0, ZERO, 'restore_errno')
    call('time')
    a.sw(V0, NOW)
    # KEY={monitor pointer, stored codec, packed video/audio PID}.
    addr(a, T0, KEY)
    a.lw(V1, 0, T0)
    a.bne(V1, S0, 'reset')
    a.lw(V1, 4, T0)
    a.lw(T1, 0xa0, S0)
    a.bne(V1, T1, 'reset')
    a.lhu(V1, 0xb0, S0)
    a.r(ZERO, V1, V1, 0, 16)
    a.lhu(T1, 0xb2, S0)
    a.r(V1, T1, V1, 0x25)
    a.lw(T1, 8, T0)
    a.bne(V1, T1, 'reset')
    addr(a, T0, CLOCK)
    a.lw(V1, 4, T0)
    a.i(11, V1, T1, 3)
    a.beq(T1, ZERO, 'restore_errno')
    a.lw(T1, 0, T0)
    a.lw(V0, NOW)
    a.r(V0, T1, V0, 0x23)  # unsigned delta handles natural GetTime0 rollover.
    a.sw(V0, ELAPSED)
    a.addiu(V1, V1, 1)
    a.li(T1, 2000)
    a.r(V1, T1, ZERO, 0x19)  # multu: index(1..3)*2000, no overflow.
    a.r(ZERO, ZERO, T1, 0x12)
    a.r(V0, T1, T1, 0x2b)
    a.bne(T1, ZERO, 'restore_errno')
    # Reserve one of at most3 attempts before I/O/getters. Loss never retries.
    a.sw(V1, 4, T0)
    a.li(V0, -1)
    a.sw(V0, FRAMES)
    a.lbu(V0, 0x110, S0)
    a.beq(V0, ZERO, 'skip_frames')
    a.lw(A0, 0x138, S0)
    a.beq(A0, ZERO, 'skip_frames')
    call('frames')
    a.sw(V0, FRAMES)
    a.label('skip_frames')
    a.li(V0, 255)  # explicit query-not-issued sentinel, not a false lock.
    a.sw(V0, MAD)
    a.lbu(V0, 0x111, S0)
    a.beq(V0, ZERO, 'transport')
    a.lhu(V0, 0xb2, S0)
    a.li(V1, 0x1fff)
    a.beq(V0, V1, 'transport')
    a.lw(V0, 0xa4, S0)
    a.li(V1, 255)
    a.beq(V0, V1, 'transport')
    a.move(A0, S0)
    call('mad')
    a.i(12, V0, V0, 255)
    a.sw(V0, MAD)
    a.b('transport')
    a.label('reset')
    addr(a, T0, KEY)
    a.sw(S0, 0, T0)
    a.lw(V0, 0xa0, S0)
    a.sw(V0, 4, T0)
    a.lhu(V0, 0xb0, S0)
    a.r(ZERO, V0, V0, 0, 16)
    a.lhu(V1, 0xb2, S0)
    a.r(V0, V1, V0, 0x25)
    a.sw(V0, 8, T0)
    addr(a, T0, CLOCK)
    a.lw(V0, NOW)
    a.sw(V0, 0, T0)
    a.sw(ZERO, 4, T0)
    a.b('restore_errno')
    a.label('transport')
    # Reuse v3 FIFO/owner/mode contract with no device/USB I/O in this thread.
    a.li(A0, 3)
    addr(a, A1, old.FIFO_PATH)
    a.addiu(A2, SP, STAT_BUFFER)
    call('lxstat64')
    a.bne(V0, ZERO, 'restore_errno')
    a.lw(V0, STAT_BUFFER+0x18)
    a.i(12, V0, V0, 0xffff)
    a.li(V1, 0x1180)
    a.bne(V0, V1, 'restore_errno')
    a.lw(V0, STAT_BUFFER+0x20)
    a.bne(V0, ZERO, 'restore_errno')
    addr(a, A0, old.FIFO_PATH)
    a.li(A1, old.OPEN_FLAGS)
    call('open')
    a.r(V0, ZERO, V1, 0x2a)
    a.bne(V1, ZERO, 'restore_errno')
    a.sw(V0, FD_SLOT)
    a.move(A3, V0)
    a.addiu(A0, SP, PROC_BUFFER)
    a.li(A1, 64)
    addr(a, A2, old.FD_FORMAT)
    call('snprintf')
    a.r(ZERO, V0, V1, 0x2a)
    a.beq(V1, ZERO, 'close')
    a.i(11, V0, V1, 64)
    a.beq(V1, ZERO, 'close')
    a.li(A0, 3)
    a.addiu(A1, SP, PROC_BUFFER)
    a.addiu(A2, SP, STAT_BUFFER)
    call('xstat')
    a.bne(V0, ZERO, 'close')
    a.lw(V0, STAT_BUFFER+0x14)
    a.i(12, V0, V0, 0xffff)
    a.li(V1, 0x1180)
    a.bne(V0, V1, 'close')
    a.lw(V0, STAT_BUFFER+0x1c)
    a.bne(V0, ZERO, 'close')
    a.addiu(A0, SP, BUFFER)
    a.li(A1, old.MAX_LINE)
    addr(a, A2, FORMAT)
    a.lw(A3, ELAPSED)
    # elapsed is a3; remaining10 unsigned args occupy sp+10..34.
    for slot, kind, offset in [
        (0x10, 'lw', 0xa0), (0x14, 'lhu', 0xb0), (0x18, 'lhu', 0xb2),
        (0x24, 'lbu', 0x92), (0x28, 'lbu', 0x6e),
        (0x2c, 'lw', 0x68), (0x30, 'lbu', 0x110), (0x34, 'lbu', 0x111),
    ]:
        getattr(a, kind)(T0, offset, S0)
        a.sw(T0, slot)
    a.lw(T0, FRAMES)
    a.sw(T0, 0x1c)
    a.lw(T0, MAD)
    a.sw(T0, 0x20)
    call('snprintf')
    a.r(ZERO, V0, V1, 0x2a)
    a.beq(V1, ZERO, 'close')
    a.i(11, V0, V1, old.MAX_LINE)
    a.beq(V1, ZERO, 'close')
    a.move(A2, V0)
    a.lw(A0, FD_SLOT)
    a.addiu(A1, SP, BUFFER)
    call('write')
    a.label('close')
    a.lw(A0, FD_SLOT)
    call('close')
    a.label('restore_errno')
    a.lw(V0, ERRPTR_SLOT)
    a.lw(V1, ERR_SLOT)
    a.sw(V1, 0, V0)
    a.label('restore')
    a.lw(T0, HI_SLOT)
    a.r(T0, ZERO, ZERO, 0x11)
    a.lw(T0, LO_SLOT)
    a.r(T0, ZERO, ZERO, 0x13)
    for i, register in enumerate(old.VOLATILE):
        a.lw(register, SAVE+i*4)
    a.lw(GP, GP_SLOT)
    # AT is reserved assembler scratch, never a C ABI live register. Restore
    # the original call's RA and branch using AT without altering saved T9/V0.
    addr(a, RA, ORIGINAL_RA)
    a.beq(V0, ZERO, 'fall')
    addr(a, 1, NONZERO_PATH)
    a.b('resume')
    a.label('fall')
    addr(a, 1, ZERO_PATH)
    a.label('resume')
    a.r(1, ZERO, ZERO, 8)
    a.addiu(SP, SP, FRAME)
    result = a.finish()
    assert HELPER+len(result) <= FORMAT
    return result


def verify_padding(original):
    ph, = struct.unpack_from('<I', original, 28)
    es, count = struct.unpack_from('<HH', original, 42)
    segments = [struct.unpack_from('<8I', original, ph+es*i) for i in range(count)]
    sh, = struct.unpack_from('<I', original, 32)
    ss, count = struct.unpack_from('<HH', original, 46)
    sections = [struct.unpack_from('<10I', original, sh+ss*i) for i in range(count)]
    regions = [(HELPER, LIMIT, 5), (KEY, KEY+12, 6), (CLOCK, CLOCK+12, 6)]
    evidence = []
    for start, end, flags in regions:
        matches = [s for s in segments if s[0] == 1 and s[6] == flags and s[2] <= start and end <= s[2]+s[5]]
        if len(matches) != 1:
            raise ValueError('Gap is not inside exact native LOAD permissions')
        if any(s[2] & 2 and s[5] and s[3] < end and start < s[3]+s[5] for s in sections):
            raise ValueError('Gap overlaps allocated section')
        if any(s[0] == 0x6474e552 and s[2] < end and start < s[2]+s[5] for s in segments):
            raise ValueError('Gap overlaps GNU_RELRO')
        segment = matches[0]
        file_end = segment[2]+segment[4]
        if start < file_end:
            backed_end = min(end, file_end)
            offset = segment[1]+start-segment[2]
            if original[offset:offset+backed_end-start] != bytes(backed_end-start):
                raise ValueError('Gap file bytes are nonzero')
        if end > file_end and start < file_end:
            raise ValueError('State region unexpectedly straddles file tail')
        evidence.append(dict(start=hex(start), end_exclusive=hex(end), load_flags=flags,
                             initialized='file-backed zero' if end <= file_end else 'PT_LOAD implicit zero tail',
                             allocated_section_overlap=False, GNU_RELRO_overlap=False))
    return dict(regions=evidence, GNU_RELRO_program_header_count=sum(s[0] == 0x6474e552 for s in segments))


def apply(original):
    if sha(original) != INPUT_SHA:
        raise ValueError('Exact immutable fifo-v3 Common required')
    if original[va_offset(original, ENTRY, 20):va_offset(original, ENTRY, 20)+20] != struct.pack('<5I', *OLD):
        raise ValueError('Native monitoring block differs')
    gap_evidence = verify_padding(original)
    from map_mips_calls import Elf32
    e = Elf32(old.SOURCE)
    if old.sha(e.raw) != old.INPUT_SHA:
        raise ValueError('Stock evidence source differs')
    for name, fragment in [('checkpoint', '11DoVideoSync'), ('frames', '11GetFrameCnt'),
                           ('mad', '9IsMadLock'), ('time', 'GetTime0')]:
        if fragment not in e.got_symbols[GP_CANON+GOT[name]]['name']:
            raise ValueError('Getter GOT identity mismatch: '+name)
    for symbol in e.symbols:
        if not symbol['imported'] and symbol['size'] and any(
                symbol['value'] < start+12 and start < symbol['value']+symbol['size'] for start in [KEY, CLOCK]):
            raise ValueError('Telemetry state overlaps a defined symbol')
    # No direct branch may enter the middle of the five-word replacement.
    text = e.by_name['.text']
    for off in range(text['offset'], text['offset']+text['size'], 4):
        word = struct.unpack_from('<I', e.raw, off)[0]
        pc = text['va']+off-text['offset']
        op = word >> 26
        if op in [1, 4, 5, 6, 7, 20, 21, 22, 23]:
            imm = word & 0xffff
            target = pc+4+4*(imm-65536 if imm & 0x8000 else imm)
            if ENTRY < target < ENTRY+20:
                raise ValueError('Branch enters replaced block')
    # REL32 targets must not cover either independent state gap.
    for section in e.sections:
        if section['type'] == 9:
            for offset in range(section['offset'], section['offset']+section['size'], section['entsize']):
                target = struct.unpack_from('<I', e.raw, offset)[0]
                if any(target < start+12 and start < target+4 for start in [KEY, CLOCK]):
                    raise ValueError('Relocation touches telemetry state')
    result = bytearray(original)
    writes = [(ENTRY, trampoline()), (HELPER, helper_code()), (FORMAT, FMT)]
    allowlist = []
    for va, content in writes:
        offset = va_offset(original, va, len(content))
        result[offset:offset+len(content)] = content
        allowlist.append(dict(va=hex(va), offset=offset, bytes=len(content)))
    result = bytes(result)
    if len(result) != len(original) or any(not any(v['offset'] <= i < v['offset']+v['bytes'] for v in allowlist)
                                         for i, (x, y) in enumerate(zip(original, result)) if x != y):
        raise ValueError('Mutation exceeds exact allowlist')
    old_start = va_offset(original, old.HELPER, old.LIMIT-old.HELPER)
    assert original[old_start:old_start+old.LIMIT-old.HELPER] == result[old_start:old_start+old.LIMIT-old.HELPER]
    proof = dict(kind='Post-native-DoVideoSync main live diagnostic snapshots; no decode policy change',
                 input_sha256=INPUT_SHA, candidate_sha256=sha(result), helper_bytes=len(helper_code()),
                 helper_va=hex(HELPER), allowlist=allowlist,
                 writable_gap_and_RELRO_evidence=gap_evidence,
                 schema='MGDIAG 4 elapsed_ms video_codec video_pid audio_pid frames mad_lock ready92 sync_pending mute_mask video_started audio_started',
                 state=dict(key_va=hex(KEY), key_bytes=12, timer_va=hex(CLOCK), timer_bytes_used=8,
                            file_backed_key_zero=True, timer_LOAD_tail_implicit_zero=True,
                            key='monitor pointer, codec, packed video/audio PID',
                            reset='first matching monitor or any key change', thresholds_ms=[2000, 4000, 6000],
                            counter='attempts advance before getters/I/O; no retries after drop'),
                 sentinels=dict(frames_no_decoder=4294967295, mad_query_not_issued=255),
                 original_branch=dict(call='DoVideoSync', stored_ready92='captured immediately after native call',
                                      zero=hex(ZERO_PATH), nonzero=hex(NONZERO_PATH), original_call_ra=hex(ORIGINAL_RA)),
                 preserved=['old fifo-v3 init hook and helper bytes', 'native DoVideoSync call',
                            'ready92 branch', 'monitor AVInfo/flags', 'caller volatile values except AT scratch',
                            'callee-saved registers', 'errno', 'SP/GP/HI/LO'],
                 limits=['Physical TV execution not performed', 'All native external services mocked in tests',
                         'GetTime0 delta starts at first DoMonitor seeing this key, not exact zap/SDK init timestamp',
                         'Late DoMonitor scheduling may deliver thresholds late; actual elapsed is recorded',
                         'Only source1c,window0,non-PVR monitors sampled',
                         'Native GetAVInfo failure before DoVideoSync still skips this checkpoint',
                         'Repeated init of identical monitor/codec/PIDs without a key change does not reset',
                         'Main monitor serialization assumed; no new mutex or atomic synchronization added',
                         'New helper lacks FDE; exceptional/asynchronous unwind not supported',
                         'Getter values are observations; no decoder success or mute state is forced'])
    return result, proof


def main():
    if SOURCE.is_symlink():
        raise ValueError('Source symlink refused')
    candidate, proof = apply(SOURCE.read_bytes())
    OUT.mkdir(parents=True, exist_ok=True)
    path = OUT/'libmsrv_common.so'
    if path.exists():
        raise FileExistsError('Never overwrite a candidate')
    path.write_bytes(candidate)
    (OUT/'patch-proof.json').write_text(json.dumps(proof, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(candidate_sha256=proof['candidate_sha256'], helper_bytes=proof['helper_bytes'])))


if __name__ == '__main__':
    main()
