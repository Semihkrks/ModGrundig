"""One V7.9 native video-init diagnostic hook; never changes decode policy.

Pure, pinned transformation of stock Common. Runtime output is one bounded
numeric record to an existing nonblocking FIFO, with descriptor-type checking.
No application/firmware container is built here. No original is overwritten.
"""
from __future__ import annotations
import hashlib
import json
import struct
from pathlib import Path

from native_ui_v75_name import Assembler, ZERO, V0, V1, A0, A1, A2, A3, T0, T1, T9, S3, S4, GP, SP, RA
from native_hevc_audio_test import va_offset

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_common.so'
OUT = ROOT/'analiz/native-4k/diag-hooks/fifo-v3'
INPUT_SHA = '06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21'
BASE_APP_SHA = '861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea'
ENTRY = 0x2d9d92fc
CONTINUE = ENTRY + 20
HELPER = 0x2d957000
LIMIT = HELPER + 0x800
FORMAT = HELPER + 0x600
FIFO_PATH = HELPER + 0x680
FD_FORMAT = HELPER + 0x6c0
GP_CANON = 0x2da91f90
FRAME = 0x2a0
BUFFER = 0x30
MAX_LINE = 192
PROC_BUFFER = 0xf0
STAT_BUFFER = 0x130
SAVE_START = 0x230
HI_SLOT, LO_SLOT, LEN_SLOT, FD_SLOT = 0x274, 0x278, 0x27c, 0x280
ERRPTR_SLOT, ERR_SLOT, GP_SLOT, RA_SLOT = 0x288, 0x28c, 0x298, 0x29c
VOLATILE = [V0, V1, A0, A1, A2, A3] + list(range(8, 16)) + [24, 25]
GOT = {'set_type': -0x5854, 'snprintf': -0x63b0, 'open': -0x579c,
       'close': -0x5524, 'write': -0x7874, 'xstat': -0x6c50, 'errno': -0x6938,
       'lxstat64': -0x7ebc}
OLD = (0x8f99a7ac, 0x8e640138, 0x8e850000, 0x0320f809, 0x0000b821)
FMT = b'MGDIAG 1 %u %u %u %u %u %u %u %u\n\0'
PATH = b'/tmp/modgrundig-diag.fifo\0'
FD_FMT = b'/proc/self/fd/%u\0'
# Linux v3.1 arch/mips/include/asm/fcntl.h plus asm-generic/fcntl.h.
OPEN_FLAGS = 0x20082  # O_NOFOLLOW | O_NONBLOCK | O_RDWR; no create/truncate.


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def runtime_address(a, register, address):
    delta = address - GP_CANON
    a.li(register, delta & 0xffffffff)
    a.r(register, GP, register, 0x21)


def trampoline():
    a = Assembler(ENTRY)
    runtime_address(a, T9, HELPER)
    a.r(T9, ZERO, RA, 9)
    a.emit(0)
    raw = a.finish()
    assert len(raw) == 20
    return raw


def helper_code():
    a = Assembler(HELPER)
    a.addiu(SP, SP, -FRAME)
    a.sw(RA, RA_SLOT)
    a.sw(GP, GP_SLOT)
    # Original call block: a2 was already established by the native branch;
    # s3/s4 are live callee-saved monitor/AVInfo pointers in DoStart.
    a.lw(T9, GOT['set_type'], GP)
    a.lw(A0, 0x138, S3)
    a.lw(A1, 0, S4)
    a.r(T9, ZERO, RA, 9)
    a.move(23, ZERO)  # original delay slot s7=0
    a.lw(GP, GP_SLOT)
    for index, register in enumerate(VOLATILE):
        a.sw(register, SAVE_START + index*4)
    a.r(ZERO, ZERO, T0, 0x10)  # mfhi
    a.sw(T0, HI_SLOT)
    a.r(ZERO, ZERO, T0, 0x12)  # mflo
    a.sw(T0, LO_SLOT)

    def call(name):
        a.lw(T9, GOT[name], GP)
        a.r(T9, ZERO, RA, 9)
        a.emit(0)
        a.lw(GP, GP_SLOT)

    call('errno')
    a.beq(V0, ZERO, 'restore')
    a.sw(V0, ERRPTR_SLOT)
    a.lw(V1, 0, V0)
    a.sw(V1, ERR_SLOT)
    # Reject ordinary pre-existing non-FIFO nodes before opening them at all.
    a.li(A0, 3)
    runtime_address(a, A1, FIFO_PATH)
    a.addiu(A2, SP, STAT_BUFFER)
    call('lxstat64')
    a.bne(V0, ZERO, 'restore_errno')
    a.lw(V0, STAT_BUFFER+0x18)
    a.i(12, V0, V0, 0xf000)
    a.li(V1, 0x1000)
    a.bne(V0, V1, 'restore_errno')
    a.lw(V0, STAT_BUFFER+0x18)
    a.i(12, V0, V0, 0x0fff)
    a.li(V1, 0x180)  # exactly owner read/write (0600), no special bits
    a.bne(V0, V1, 'restore_errno')
    a.lw(V0, STAT_BUFFER+0x20)  # ABI32 stat64 st_uid
    a.bne(V0, ZERO, 'restore_errno')
    runtime_address(a, A0, FIFO_PATH)
    a.li(A1, OPEN_FLAGS)
    call('open')
    # Signed negative fd means absent/denied/no-follow failure: no retries.
    a.r(V0, ZERO, V1, 0x2a)
    a.bne(V1, ZERO, 'restore_errno')
    a.sw(V0, FD_SLOT)
    a.move(A3, V0)
    a.addiu(A0, SP, PROC_BUFFER)
    a.li(A1, 64)
    runtime_address(a, A2, FD_FORMAT)
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
    a.lw(V0, STAT_BUFFER + 0x14)
    a.i(12, V0, V0, 0xf000)
    a.li(V1, 0x1000)
    a.bne(V0, V1, 'close')
    a.lw(V0, STAT_BUFFER+0x14)
    a.i(12, V0, V0, 0x0fff)
    a.li(V1, 0x180)
    a.bne(V0, V1, 'close')
    a.lw(V0, STAT_BUFFER+0x1c)  # ABI32 stat st_uid
    a.bne(V0, ZERO, 'close')
    # Fixed numeric-only event; no strings, pointers or private data.
    a.addiu(A0, SP, BUFFER)
    a.li(A1, MAX_LINE)
    runtime_address(a, A2, FORMAT)
    a.lw(A3, SAVE_START)  # exact original SetVdecType v0
    for off, load, source_off in [
        (0x10, 'lw', 0), (0x14, 'lw', 4),
        (0x18, 'lhu', 0x10), (0x1c, 'lhu', 0x12),
        (0x20, 'lhu', 0x1e), (0x24, 'lbu', 0x26),
    ]:
        getattr(a, load)(T0, source_off, S4)
        a.sw(T0, off)
    a.lw(T0, 0x68, S3)
    a.sw(T0, 0x28)
    call('snprintf')
    a.r(ZERO, V0, V1, 0x2a)
    a.beq(V1, ZERO, 'close')
    a.i(11, V0, V1, MAX_LINE)
    a.beq(V1, ZERO, 'close')
    a.move(A2, V0)
    a.lw(A0, FD_SLOT)
    a.addiu(A1, SP, BUFFER)
    call('write')  # one bounded nonblocking write; loss is preferable to retry.
    a.label('close')
    a.lw(A0, FD_SLOT)
    call('close')
    a.label('restore_errno')
    a.lw(V0, ERRPTR_SLOT)
    a.lw(V1, ERR_SLOT)
    a.sw(V1, 0, V0)
    a.label('restore')
    a.lw(T0, HI_SLOT)
    a.r(T0, ZERO, ZERO, 0x11)  # mthi
    a.lw(T0, LO_SLOT)
    a.r(T0, ZERO, ZERO, 0x13)  # mtlo
    for index, register in enumerate(VOLATILE):
        a.lw(register, SAVE_START + index*4)
    a.lw(GP, GP_SLOT)
    a.lw(RA, RA_SLOT)
    a.r(RA, ZERO, ZERO, 8)
    a.addiu(SP, SP, FRAME)
    raw = a.finish()
    assert HELPER+len(raw) <= FORMAT, 'code overlaps data'
    return raw


def apply(original):
    if sha(original) != INPUT_SHA:
        raise ValueError('Exact unmodified V7.9 stock Common required')
    hook = va_offset(original, ENTRY, 20)
    cave = va_offset(original, HELPER, LIMIT-HELPER)
    if original[hook:hook+20] != struct.pack('<5I', *OLD):
        raise ValueError('Original SDK call block changed')
    if original[cave:cave+LIMIT-HELPER] != bytes(LIMIT-HELPER):
        raise ValueError('Cave is not empty stock padding')
    ph, = struct.unpack_from('<I', original, 28)
    es, count = struct.unpack_from('<HH', original, 42)
    segments = [struct.unpack_from('<8I', original, ph+es*i) for i in range(count)]
    if not any(p[0] == 1 and p[6] == 5 and p[2] <= HELPER and LIMIT <= p[2]+p[4] for p in segments):
        raise ValueError('Cave is not existing file-backed R-X')
    sh, = struct.unpack_from('<I', original, 32)
    ss, sn = struct.unpack_from('<HH', original, 46)
    for idx in range(sn):
        sec = struct.unpack_from('<10I', original, sh+ss*idx)
        if sec[1] != 8 and sec[5] and sec[3] < LIMIT and HELPER < sec[3]+sec[5]:
            raise ValueError('Cave overlaps an ELF section')
    # Assert actual imported bindings and native ABI evidence before patching.
    from map_mips_calls import Elf32
    e = Elf32(SOURCE)
    expected = {'set_type': '_ZN9mapi_vdec11SetVdecTypeEN27mapi_video_dtv_cfg_datatype10CODEC_TYPEEh',
                'snprintf': 'snprintf', 'open': 'open', 'write': 'write',
                'close': 'close', 'xstat': '__xstat', 'errno': '__errno_location',
                'lxstat64': '__lxstat64'}
    for name, symbol in expected.items():
        if e.got_symbols[GP_CANON+GOT[name]]['name'] != symbol:
            raise ValueError('GOT mismatch: '+name)
    pinned = {0x2da1cb34: 0x24040003, 0x2da1cb38: 0x8f9993b0,
              0x2da1cb40: 0x27a60024, 0x2da1cb68: 0x8fa20038,
              0x2da1cb70: 0x3042f000, 0x2da0ac10: 0x27a20050,
              0x2da0ac18: 0xafa200f8, 0x2da0acf0: 0x8f998144,
              0x2da0acf8: 0x8fa600f8, 0x2da0acfc: 0x24040003,
              0x2da0ad38: 0x8fa20068, 0x2da0ad40: 0x3042f000}
    if any(e.u32(va) != word for va, word in pinned.items()):
        raise ValueError('Native __xstat ABI evidence changed')
    result = bytearray(original)
    writes = [(ENTRY, trampoline()), (HELPER, helper_code()),
              (FORMAT, FMT), (FIFO_PATH, PATH), (FD_FORMAT, FD_FMT)]
    allowlist = []
    for va, data in writes:
        offset = va_offset(original, va, len(data))
        result[offset:offset+len(data)] = data
        allowlist.append(dict(va=hex(va), offset=offset, bytes=len(data)))
    result = bytes(result)
    if len(result) != len(original) or any(not any(x['offset'] <= i < x['offset']+x['bytes'] for x in allowlist)
                                         for i, (before, after) in enumerate(zip(original, result)) if before != after):
        raise ValueError('Changes exceed exact allowlist')
    proof = dict(kind='V7.9 numeric native video-init telemetry only', source_sha256=INPUT_SHA,
                 candidate_sha256=sha(result), base_APP_ELF_sha256=BASE_APP_SHA,
                 helper_va=hex(HELPER), helper_bytes=len(helper_code()), allowlist=allowlist,
                 schema='MGDIAG 1 rc video_codec audio_codec video_pid audio_pid pcr_pid mode mute_mask',
                 transport=dict(path=PATH[:-1].decode(), open_flags=hex(OPEN_FLAGS),
                     path_test='__lxstat64(3,path,buffer); st_mode+0x18 & 0xf000 == 0x1000 before open',
                     descriptor_test='__xstat(3,/proc/self/fd/N,buffer); st_mode+0x14 & 0xf000 == 0x1000',
                     owner_and_permissions='both path and descriptor require uid0 and exact0600 including no special bits',
                     syscall_flags_sources=[
                       'https://raw.githubusercontent.com/torvalds/linux/v3.1/arch/mips/include/asm/fcntl.h',
                       'https://raw.githubusercontent.com/torvalds/linux/v3.1/include/asm-generic/fcntl.h',
                       'https://github.com/torvalds/linux/blob/v3.1/arch/mips/include/asm/stat.h'],
                     max_bytes=MAX_LINE-1, write_attempts=1, nonblocking=True,
                     missing_fifo='drop', fifo_full='drop', regular_file='reject before write',
                     symlink='O_NOFOLLOW rejects final component', proc_unavailable='drop and close'),
                 native_ABI_evidence={hex(va): hex(word) for va, word in pinned.items()},
                 preserved=['original SetVdecType args/return', 'post-call volatile registers',
                            'HI/LO','callee-saved registers except original s7=0',
                            'stack', 'errno', 'native video/audio/mute policy'],
                 limits=['No physical TV execution', 'Native logging calls mocked in isolated tests',
                         'No new FDE/unwind information; exceptional/asynchronous unwind unsupported in helper',
                         'Records SDK init result only, not decoded frame or actual lower-level hardware success',
                         'FIFO/proc filesystem runtime integration still needs device verification'],
                 firmware_container_modified=False, original_modified=False, load_bias_independent=True)
    return result, proof


def main():
    if SOURCE.is_symlink():
        raise ValueError('Source symlink refused')
    original = SOURCE.read_bytes()
    candidate, proof = apply(original)
    OUT.mkdir(parents=True, exist_ok=True)
    path = OUT/'libmsrv_common.so'
    if path.exists():
        raise FileExistsError('Never overwrite an existing diagnostic candidate')
    path.write_bytes(candidate)
    (OUT/'patch-proof.json').write_text(json.dumps(proof, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(candidate_sha256=proof['candidate_sha256'], helper_bytes=proof['helper_bytes'])))


if __name__ == '__main__':
    main()
