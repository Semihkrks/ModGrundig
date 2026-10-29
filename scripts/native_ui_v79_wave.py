"""Pinned offline V7.9 native volume-wave selector over the V7.7/V7.8 ELF.

Only transforms bytes. No firmware process, update code, or device is executed.
"""
from __future__ import annotations

import hashlib
import struct

from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v75_name import Assembler, ZERO, V0, V1, S0, RA

ELF = '08_APP/bin/dvbt_board'
INPUT_SHA = '494cfd8dbe9817ff29240d29e5e7e8e31667265da38214d818557e94914dbf87'
HELPER = 0x1161400
HELPER_LIMIT = 0x1162000
HOOK = 0xfb820c
SEGMENT_VA, SEGMENT_OFFSET = 0x1160000, 0xd60000


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def code():
    """Leaf: effective v0 + audible s0 -> image v1; all other registers intact.

    The caller has already folded mute into volume and computed s0. It is the
    inherited mode0 presentation block, after the original volume clamp.
    There are no calls, memory accesses, stack adjustments, or throwing edges.
    """
    a = Assembler(HELPER)
    a.li(V1, 680)
    a.beq(S0, ZERO, 'done')
    a.i(11, V0, V1, 21)  # sltiu: levels 1..20
    a.bne(V1, ZERO, 'low')
    a.i(11, V0, V1, 61)  # sltiu: levels 21..60
    a.bne(V1, ZERO, 'middle')
    a.li(V1, 2183)
    a.b('done')
    a.label('low')
    a.li(V1, 2182)
    a.b('done')
    a.label('middle')
    a.li(V1, 682)
    a.label('done')
    a.r(RA, ZERO, ZERO, 8)
    a.emit(0)
    return a.finish()


def hook_records():
    return [(HOOK, 0x00101840, 0x0c000000 | (HELPER >> 2)),
            (HOOK + 4, 0x246302a8, 0)]


def apply(original: bytes):
    """Return a separately patched ELF and the complete placement/delta proof."""
    if not isinstance(original, bytes) or sha(original) != INPUT_SHA:
        raise ValueError('Exact V7.7/V7.8 ELF required for V7.9 wave selector')
    helper = code()
    if HELPER + len(helper) > HELPER_LIMIT:
        raise ValueError('Wave helper exceeds verified zero-padding slot')
    phoff = struct.unpack_from('<I', original, 28)[0]
    phsize, phcount = struct.unpack_from('<HH', original, 42)
    if (phoff, phsize, phcount) != (SEGMENT_OFFSET, 32, 8):
        raise ValueError('Unexpected installed V7.7 PHDR layout')
    headers = [struct.unpack_from('<8I', original, phoff+i*phsize) for i in range(phcount)]
    segment = next((p for p in headers if p[0] == 1 and p[2] == SEGMENT_VA), None)
    if segment is None or segment[1] != SEGMENT_OFFSET or segment[6:] != (5, 0x10000):
        raise ValueError('Expected preexisting aligned RX helper LOAD')
    if not (HELPER >= segment[2] + 0x100 and HELPER_LIMIT <= segment[2]+segment[4]
            and segment[4] == segment[5] and segment[1]+segment[4] == len(original)):
        raise ValueError('Wave slot outside existing file-backed RX mapping')
    from native_ui_v77_name import CREATE, UPDATE, code_create, code_update, extras
    from native_ui_v77_mute import EXTRA_HELPERS
    known_helpers = [(CREATE, code_create()), (UPDATE, code_update()), *extras(), *EXTRA_HELPERS]
    for va, raw in known_helpers:
        at = elf_va_offset(original, va, len(raw))
        if original[at:at+len(raw)] != raw:
            raise ValueError('Installed numeric/mute helper differs')
        if max(HELPER, va) < min(HELPER_LIMIT, va+len(raw)):
            raise ValueError('Wave padding overlaps an installed helper')
    # Existing custom CIE/FDE payload begins at +0x2000. The GNU search header
    # follows that payload. Neither its bytes nor any PHDR/section bytes move.
    eh = next(p for p in headers if p[0] == 0x6474e550)
    if eh[2] < HELPER_LIMIT or eh[1] < SEGMENT_OFFSET+0x2000:
        raise ValueError('EH header overlaps reserved wave padding')
    at = elf_va_offset(original, HELPER, HELPER_LIMIT-HELPER)
    if any(original[at:at+HELPER_LIMIT-HELPER]):
        raise ValueError('Reserved wave slot is not entirely zero')
    # Both mode0 selector predecessors, including the inherited GP fix, stay.
    context = {0xfb81f8: 0x93d00029, 0xfb81fc: 0x8fc2002c,
               0xfb8200: 0x8fdc0018, 0xfb8204: 0x0010100b,
               0xfb8208: 0x0002802b, 0xfb8214: 0xafc30040,
               0xfb8218: 0x24030884, 0xfb821c: 0x240202a2,
               0xfb8220: 0x0050180b, 0xfb8224: 0xafc30044}
    for va, word in context.items():
        if struct.unpack_from('<I', original, elf_va_offset(original, va, 4))[0] != word:
            raise ValueError('Mode0 icon/background/GP context differs')
    out = bytearray(original)
    allowed = set(range(at, at+len(helper)))
    out[at:at+len(helper)] = helper
    for va, old, new in hook_records():
        pos = elf_va_offset(original, va, 4)
        if struct.unpack_from('<I', original, pos)[0] != old:
            raise ValueError('Original wave hook word differs')
        struct.pack_into('<I', out, pos, new)
        allowed.update(range(pos, pos+4))
    result = bytes(out)
    changed = verify_allowlist(original, result, allowed)
    proof = dict(revision='v7.9-tv', input_sha256=INPUT_SHA, output_sha256=sha(result),
        helper=dict(va=hex(HELPER), file_offset=at, bytes=len(helper), sha256=sha(helper),
                    original_zero_slot=[hex(HELPER), hex(HELPER_LIMIT)],
                    segment_flags=segment[6], existing_segment_extent=segment[4],
                    segment_size_and_headers_unchanged=True),
        hooks=[dict(va=hex(v), old=hex(a), new=hex(b)) for v,a,b in hook_records()],
        allowlist=[dict(offset=elf_va_offset(original, HOOK, 8), size=8),
                   dict(offset=at, size=len(helper))], changed_byte_offsets=changed,
        rule={'mode0_zero_or_mute': 680, 'mode0_1_to_20': 2182,
              'mode0_21_to_60': 682, 'mode0_61_to_100': 2183},
        local_mode_scope='Original mode check at 0xfb7e78 branches nonzero modes to 0xfb8358; only mode0 reaches hook 0xfb820c',
        abi=dict(inputs='v0 effective volume after original clamp/mute; s0 audible boolean',
                 output='v1 image id; existing store FP+0x40 and four MImgSet calls retained',
                 return_address='jal writes RA=0xfb8214; leaf jr RA returns to existing store',
                 clobbers=['v1'], preserved='all registers other than v1; no memory access',
                 no_calls=True, no_stack_frame=True, no_gp_change=True),
        unwind=dict(existing_cie_fde_and_search_header_unchanged=True,
                    new_fde=False,
                    reason='Pure leaf has no stack changes, saved-register changes, calls, throwing operations or synchronous unwind path; no exception cleanup added',
                    limitation='Asynchronous stack unwinding while PC is inside the 72-byte leaf is not established'),
        unchanged=['audio state/control calls', 'mute/zero selection and gray bar',
                   'ARC/CEC mode1/2/3 code', 'numeric/mute helpers', 'ELF size/headers/GOT/EH data'],
        physical_tv_tested=False,
        evidence='Pinned V7.7 ELF bytes, retained direct Ghidra Refresh instructions, separate bounded Unicorn regression',
        limits=['No firmware process or hardware execution; service/UI calls are modeled in tests'])
    return result, proof
