"""Volume-only delta over the exact, pinned V7 TV overlay.

This module only constructs bytes. It never writes firmware, launches target
code, runs update scripts, or accesses a TV. Retained Ghidra output is direct
static evidence, not a REA Evidence record or an on-device measurement.
"""
from __future__ import annotations

import hashlib
import io
import struct

from PIL import Image, ImageDraw

from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v7_tv_pins import RECORDS

ELF = '08_APP/bin/dvbt_board'
NUM = '08_APP/rc/rc/bin/Num_res.bin'
BACKGROUND = '08_APP/rc/ARimages/Common/popups/volumeControl/bg.png'
ROOT_X_ID = 0x5A41
ROOT_Y_ID = 0x5A42
LEFT_MARGIN = 80  # 4.17% of1920; root ends148, inside the160-wide outer window.
ROOT_TOP = 126  # Move the panel24 logical pixels upward; preserve its450px height.
CODE_PATCHES = (
    (0xFBB550, 0x2404005E, 0x24040001, 'local ignored normal-state color argument / flag value'),
    (0xFBB55C, 0x00000000, 0xA204003A, 'enable panel image in RcGetColor jalr delay slot'),
)


def sha(raw: bytes) -> str:
    return hashlib.sha256(raw).hexdigest()


def background_png() -> bytes:
    """Exact widget-sized capsule with an explicit RGBA alpha channel."""
    scale = 4
    image = Image.new('RGBA', (68 * scale, 450 * scale), (245, 245, 245, 0))
    ImageDraw.Draw(image).rounded_rectangle(
        (0, 0, image.width - 1, image.height - 1), radius=34 * scale,
        fill=(245, 245, 245, 255))
    image = image.resize((68, 450), Image.Resampling.LANCZOS)
    out = io.BytesIO()
    image.save(out, format='PNG', compress_level=9)
    return out.getvalue()


def layout(raw: bytes) -> dict:
    def n(rid):
        return struct.unpack_from('<I', raw, 56 + rid * 4)[0]
    root = [n(0x5A41), n(0x5A42), n(0x5A40), n(0x5A3F)]
    panel = [root[0] + n(0x5A44), root[1] + n(0x5A45), n(0x5A43), n(0x5A3E)]
    def child(ids):
        x, y, w, h = map(n, ids)
        return [panel[0] + x, panel[1] + y, w, h]
    return dict(root=root, panel=panel,
                speaker=child((0x5A68, 0x5A69, 0x5A67, 0x5A66)),
                number=child((0x5A78, 0x5A79, 0x5A77, 0x5A76)),
                track=child((0x5A6C, 0x5A6D, 0x5A6B, 0x5A6A)))


def apply(payloads: dict[str, bytes]) -> tuple[dict[str, bytes], dict]:
    """Reject anything other than the exact 12-file V7 TV input; return a copy.

    Run this before other v7.1 helpers. Full-file pins and local old words are
    both enforced, so a previously patched or unexpected source cannot pass.
    """
    expected = {p: (digest, size) for p, _, digest, size in RECORDS}
    if payloads.keys() != expected.keys():
        raise ValueError('Expected exact pinned 12-file V7 TV overlay')
    for relative, raw in payloads.items():
        digest, size = expected[relative]
        if not isinstance(raw, bytes) or len(raw) != size or sha(raw) != digest:
            raise ValueError(f'Pinned V7 TV input mismatch: {relative}')
    result = dict(payloads)
    before_num = payloads[NUM]
    num = bytearray(before_num)
    num_records, num_allowed = [], set()
    for rid, old, new, role in ((ROOT_X_ID, 0, LEFT_MARGIN, 'normal-volume root x'),
                               (ROOT_Y_ID, 150, ROOT_TOP, 'normal-volume root y, raised24px')):
        off = 56 + 4 * rid
        if struct.unpack_from('<I', before_num, off)[0] != old:
            raise ValueError('Unexpected prior normal-volume root position')
        struct.pack_into('<I', num, off, new)
        num_allowed.update(range(off, off + 4))
        num_records.append(dict(id=rid, id_hex=hex(rid), file_offset=off,
                                old=old, new=new, role=role))
    result[NUM] = bytes(num)
    num_changes = verify_allowlist(before_num, result[NUM], num_allowed)

    before_elf = payloads[ELF]
    elf = bytearray(before_elf)
    # s0 is the panel object, not the root or any unrelated widget. Preserve
    # the call and gp restoration, and require their exact original words.
    for va, word in ((0xFBB548, 0x8FC20130), (0xFBB54C, 0x8C5001A4),
                     (0xFBB554, 0x8F99A798), (0xFBB558, 0x0320F809),
                     (0xFBB560, 0x8FDC0020), (0xFBB564, 0xAE02004C)):
        if struct.unpack_from('<I', before_elf, elf_va_offset(before_elf, va, 4))[0] != word:
            raise ValueError(f'Unexpected panel constructor context: {va:#x}')
    patches = []
    allowed = set()
    for va, old, new, role in CODE_PATCHES:
        offset = elf_va_offset(before_elf, va, 4)
        if struct.unpack_from('<I', before_elf, offset)[0] != old:
            raise ValueError(f'Unexpected panel instruction: {va:#x}')
        struct.pack_into('<I', elf, offset, new)
        allowed.update(range(offset, offset + 4))
        patches.append(dict(va=hex(va), file_offset=offset, old_word=hex(old),
                            new_word=hex(new), role=role))
    result[ELF] = bytes(elf)
    elf_changes = verify_allowlist(before_elf, result[ELF], allowed)
    result[BACKGROUND] = background_png()
    changed = sorted(k for k in result if result[k] != payloads[k])
    if changed != sorted((ELF, NUM, BACKGROUND)):
        raise ValueError('Volume delta escaped exact three-file scope')
    proof = dict(
        revision='v7.1-volume', input_profile='exact pinned v7-tv 12-file overlay',
        changed_paths=changed,
        num_records=num_records,
        code_records=patches, num_changed_byte_offsets=num_changes,
        elf_changed_byte_offsets=elf_changes,
        before_geometry=layout(before_num), after_geometry=layout(result[NUM]),
        outer_frame=dict(rect=[0, 160, 160, 725],
                         ids=['0x5bf0', '0x5bf1', '0x5bef', '0x5bee'],
                         factory='0xfb601c', constructor_call='0xfb60f8',
                         normal_root_screen_rect=[80, 286, 68, 490],
                         panel_screen_rect=[80, 306, 68, 450],
                         root_right=148, root_bottom=616,
                         source='Factory reads outer rect; MMainFrame constructor saves it then zeros client rect xy; CreateDFBWindow consumes saved outer rect.'),
        capsule=dict(image_id=674, path=BACKGROUND, size=[68, 450], radius=34,
                     png_color_type=6, explicit_alpha=True,
                     image_enabled_byte='panel+0x3a=1',
                     sha256=sha(result[BACKGROUND])),
        evidence=[
            dict(kind='retained direct Ghidra static output',
                 path='analiz/native/ui-targeted/dvbt_board/00fb9780.c',
                 address='0xfb9780', finding='normal root frame+0x184; panel frame+0x1a4 belongs to root; speaker/number/track belong to panel; panel defines image674 but has no explicit image-enable store'),
            dict(kind='retained direct Ghidra static output',
                 path='analiz/native/ui-deep/muf-core35/2e251be4.c',
                 address='0x2e251be4', finding='MWidget::DrawBackground chooses RenderImageToSurface only when background byte+0x39 is nonzero AND image byte+0x3a equals1; otherwise draws solid color'),
            dict(kind='static source discrepancy', path='scripts/native_frame_rehost.py',
                 finding='render() unconditionally supplies image674 to paint(); does not construct actual OnCreate flag; also paints root685 even though OnCreate later resets all root images to null1485'),
            dict(kind='direct ELF static disassembly', address='0x2e234ef4..0x2e234f58',
                 finding='MMainFrame constructor calls MWnd::SetRect with outer rect, then zeroes supplied xy before creating client container; outer y160 adds to the resource-selected client-local root y'),
            dict(kind='direct ELF static disassembly', address='0x2e2334d8..0x2e2335ec',
                 finding='CreateDFBWindow loads saved outerxywh into window description and passes it to layer CreateWindow; later optional scaling branch uses device ratios'),
        ],
        geometry_basis='1920x1080 logical resource coordinates;80 is4.17% left design margin; root right148 stays inside original outer width160; physical active-surface scaling/overscan not measured',
        unchanged=['all other payloads', 'Image_res table and all image IDs',
                   'ChannelControl numeric resource IDs0x98f..0x99a',
                   'RefreshVolumeUI body, volume value/mute/timeout handlers',
                   'ARC/source routing and their geometry', 'normal-volume child geometry'],
        limits=['Original full OnCreate not executed; exact local words and object context checked.',
                'Panel normal-state color changes94 to1 only to reuse a0=1 in the delay slot; it is ignored by enabled image mode.',
                'MWidget default image flag comes from MSystem default widget style; prior host image preparation bypassed it.',
                'No physical TV rendering/compositor verification of this revision.'],
        television_tested=False, target_process_executed=False)
    return result, proof
