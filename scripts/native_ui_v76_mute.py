"""V7.6 larger native standalone mute badge and legacy Image401 fallback.

Pure bytes transform. It does not execute or alter the firmware application.
The reported device's old-icon route is not established by a runtime trace.
"""
import hashlib
import io
import struct
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v74_badge import ELF, NUM, IMAGE, BADGE, ICON_PATCHES, SHADOW_PATCHES
from native_ui_v75_tv_pins import RECORDS

LEGACY = '08_APP/rc/ARimages/Grundig/volume/mute_button_grundig.png'
PANEL_ICON = '08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
LEGACY_ORIGINAL_SHA = '9facafe621ba0052c30c67650320d634dc3686ea921f1114a4a9b4055c607bb7'
ORIGINALS = {LEGACY: LEGACY_ORIGINAL_SHA}
BADGE_SIZE = 64
GLYPH_SIZE = 32
SCREEN_ICON = (1772, 74, 64, 64)
NUM_PATCHES = ((0x4219, 56, 44), (0x4218, 52, 64), (0x4217, 52, 64))


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def png(image):
    stream = io.BytesIO()
    image.quantize(colors=256, method=Image.Quantize.FASTOCTREE,
                   dither=Image.Dither.NONE).save(stream, format='PNG', bits=8, compress_level=9)
    return stream.getvalue()


def badge_png():
    scale = 8
    size = BADGE_SIZE * scale
    image = Image.new('RGBA', (size, size), (0, 0, 0, 0))
    draw = ImageDraw.Draw(image)
    draw.rounded_rectangle((0, 0, size - 1, size - 1), radius=20 * scale,
                           fill=(249, 251, 252, 242))
    border = Image.new('RGBA', image.size)
    ImageDraw.Draw(border).rounded_rectangle((0, 0, size - 1, size - 1),
        radius=20 * scale, outline=(255, 255, 255, 153), width=scale)
    image.alpha_composite(border)
    draw = ImageDraw.Draw(image)
    width = round(1.65 * scale)
    color = (82, 113, 133, 255)
    def point(p):
        return tuple(round((16 + v) * scale) for v in p)
    def line(points, closed=False):
        points = [point(p) for p in points]
        if closed:
            points.append(points[0])
        draw.line(points, fill=color, width=width, joint='curve')
        for x, y in points:
            r = width / 2
            draw.ellipse((x-r, y-r, x+r, y+r), fill=color)
    line([(4,12),(10,12),(17,6),(17,26),(10,20),(4,20)], True)
    line([(23,13),(29,19)])
    line([(29,13),(23,19)])
    return png(image.resize((BADGE_SIZE, BADGE_SIZE), Image.Resampling.LANCZOS))


def legacy_png(modern):
    """Retain original Image401 dimensions; remove its old glyph and background."""
    tile = Image.open(io.BytesIO(modern)).convert('RGBA')
    canvas = Image.new('RGBA', (85, 95), (0, 0, 0, 0))
    canvas.alpha_composite(tile, ((85 - BADGE_SIZE)//2, (95 - BADGE_SIZE)//2))
    return png(canvas)


def apply(payloads):
    """Return (new_payloads, proof); accepts V75-derived numeric ELF additions.

    Only badge PNG, legacy401 PNG and three native geometry resources change.
    Every normal standalone image state must already use2181, shadow states1485.
    """
    required = (ELF, NUM, IMAGE, BADGE, PANEL_ICON)
    if any(p not in payloads or not isinstance(payloads[p], bytes) for p in required):
        raise ValueError('V7.5 mute inputs missing')
    pins = {p:digest for p,_,digest,_ in RECORDS}
    for p in (BADGE, PANEL_ICON):
        if sha(payloads[p]) != pins[p]:
            raise ValueError('Pinned mute asset differs: '+p)
    original_elf = payloads[ELF]
    for va, _ in ICON_PATCHES:
        off = elf_va_offset(original_elf, va, 12)
        if struct.unpack_from('<I', original_elf, off)[0] != 0x24050885 or struct.unpack_from('<I', original_elf, off+8)[0] != 0x0320f809:
            raise ValueError('Existing standalone2181 state differs')
    for _, addresses in SHADOW_PATCHES:
        for va in addresses:
            if struct.unpack_from('<I', original_elf, elf_va_offset(original_elf, va, 4))[0] != 0x240505cd:
                raise ValueError('Legacy standalone shadow must remain null1485')
    if struct.unpack_from('<I', original_elf, elf_va_offset(original_elf, 0xfb8200, 4))[0] != 0x8fdc0018:
        raise ValueError('Required volume GP recovery missing')
    table = payloads[IMAGE]
    if table[:4] != b'_tsm' or struct.unpack_from('<I',table,4)[0] != len(table):
        raise ValueError('Image resource header differs')
    pos = 56
    for _ in range(401):
        size = struct.unpack_from('<I',table,pos)[0]
        if size < 1 or pos+4+size > len(table):
            raise ValueError('Image resource range differs')
        pos += 4 + size
    size = struct.unpack_from('<I',table,pos)[0]
    if table[pos+4:pos+4+size] != b'../rc/ARimages/Grundig/volume/mute_button_grundig.png\0':
        raise ValueError('Legacy Image401 path not established')
    nums = bytearray(payloads[NUM])
    readnum = lambda i: struct.unpack_from('<I', nums, 56+4*i)[0]
    if tuple(readnum(i) for i in (0x5b38,0x5b39,0x5b37,0x5b36)) != (1728,19,160,230):
        raise ValueError('Existing mute frame bounds differ')
    allowed = set()
    for rid, old, new in NUM_PATCHES:
        off = 56 + 4 * rid
        if readnum(rid) != old:
            raise ValueError('Existing badge geometry differs')
        struct.pack_into('<I', nums, off, new)
        allowed.update(range(off, off+4))
    verify_allowlist(payloads[NUM], bytes(nums), allowed)
    result = dict(payloads)
    result[NUM] = bytes(nums)
    result[BADGE] = badge_png()
    result[LEGACY] = legacy_png(result[BADGE])
    assert result[ELF] == original_elf and result[PANEL_ICON] == payloads[PANEL_ICON]
    proof = dict(source_revision='v7.5-tv', changed_paths=[NUM, BADGE, LEGACY],
        screen_icon=list(SCREEN_ICON), badge_size=[64,64], glyph_size=[32,32], radius=20,
        right_margin=84, top_margin=74, original_screen_icon=[1784,74,52,52],
        geometry_resources=[dict(id=hex(i),old=a,new=b) for i,a,b in NUM_PATCHES],
        normal_image_id=2181, normal_image_state_addresses=[hex(v) for v,_ in ICON_PATCHES],
        legacy_image_id=401, legacy_asset=LEGACY, legacy_original_sha256=LEGACY_ORIGINAL_SHA,
        added_original_sha256=ORIGINALS,
        legacy_canvas=[85,95], legacy_glyph_replaced=True,
        shared_volume_image680_unchanged=True, volume_gp_recovery_preserved=True,
        elf_bytes_unchanged=True, routing_and_lifecycle_unchanged=True,
        reported_old_icon_root_cause='Unproven without installed-image identity or device runtime trace',
        fallback_scope='Image401 original asset now carries the same modern badge; normal four states remain2181',
        physical_tv_tested=False)
    return result, proof
