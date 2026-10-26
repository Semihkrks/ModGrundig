"""Existing MuteControlFrame gets the prior ModGrundig badge and safe bounds."""
import hashlib
import io
import struct
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v73_tv_pins import RECORDS

ELF = '08_APP/bin/dvbt_board'
NUM = '08_APP/rc/rc/bin/Num_res.bin'
IMAGE = '08_APP/rc/rc/bin/Image_res.bin'
BADGE = '08_APP/rc/ARimages/Grundig/modern/mute_badge.png'
BADGE_ID = 2181
ICON_PATCHES = ((0xdf9324, 680), (0xdf9348, 401), (0xdf936c, 401), (0xdf9390, 401))
SHADOW_PATCHES = (
    (570, (0xdf9648, 0xdf966c, 0xdf9690, 0xdf96b4)),
    (571, (0xdf996c, 0xdf9990, 0xdf99b4, 0xdf99d8)),
    (566, (0xdf9c90, 0xdf9cb4, 0xdf9cd8, 0xdf9cfc)),
    (573, (0xdf9fb4, 0xdf9fd8, 0xdf9ffc, 0xdfa020)),
    (568, (0xdfa2d8, 0xdfa2fc, 0xdfa320, 0xdfa344)),
)
NUM_PATCHES = ((0x5b38, 0, 1728), (0x5b39, 435, 19),
               (0x4208, 165, 160), (0x4219, 0, 56),
               (0x4218, 100, 52), (0x4217, 100, 52))


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def badge_png():
    """Pre-render the retained CSS/SVG geometry; no browser/blur needed on TV."""
    scale = 8
    size = 52 * scale
    image = Image.new('RGBA', (size, size), (0, 0, 0, 0))
    draw = ImageDraw.Draw(image)
    draw.rounded_rectangle((0, 0, size - 1, size - 1), radius=16 * scale,
                           fill=(249, 251, 252, 242))
    border = Image.new('RGBA', image.size, (0, 0, 0, 0))
    ImageDraw.Draw(border).rounded_rectangle((0, 0, size - 1, size - 1),
        radius=16 * scale, outline=(255, 255, 255, 153), width=scale)
    image.alpha_composite(border)
    # ui-preview/tv-icons.svg icon-mute: viewBox32, shown at26px in52px tile.
    draw = ImageDraw.Draw(image)
    color = (82, 113, 133, 255)
    width = round(1.65 * 26 / 32 * scale)
    def point(xy):
        return tuple(round((13 + value * 26 / 32) * scale) for value in xy)
    def line(points, closed=False):
        points = [point(p) for p in points]
        if closed:
            points.append(points[0])
        draw.line(points, fill=color, width=width, joint='curve')
        for x, y in points:
            r = width / 2
            draw.ellipse((x - r, y - r, x + r, y + r), fill=color)
    line([(4, 12), (10, 12), (17, 6), (17, 26), (10, 20), (4, 20)], True)
    line([(23, 13), (29, 19)])
    line([(29, 13), (23, 19)])
    image = image.resize((52, 52), Image.Resampling.LANCZOS)
    image = image.quantize(colors=256, method=Image.Quantize.FASTOCTREE,
                           dither=Image.Dither.NONE)
    stream = io.BytesIO()
    image.save(stream, format='PNG', bits=8, compress_level=9)
    return stream.getvalue()


def apply(payloads):
    # The progress helper changes only the ELF before this helper. Every other
    # input stays pinned, and the complete MuteControl OnCreate span is checked.
    expected = {p: (digest, size) for p, _, digest, size in RECORDS}
    if payloads.keys() != expected.keys():
        raise ValueError('Expected fourteen V7.3 paths')
    for path, raw in payloads.items():
        digest, size = expected[path]
        if len(raw) != size or (path != ELF and sha(raw) != digest):
            raise ValueError('Unexpected badge input: ' + path)
    original = payloads[ELF]
    # Local old words and field contexts are additionally verified per patch.
    result = dict(payloads)
    elf = bytearray(original)
    patches, allowed = [], set()
    targets = [(va, old, BADGE_ID) for va, old in ICON_PATCHES]
    targets += [(va, rid, 1485) for rid, addresses in SHADOW_PATCHES for va in addresses]
    for va, old_id, new_id in targets:
        off = elf_va_offset(original, va, 4)
        old_word, new_word = 0x24050000 | old_id, 0x24050000 | new_id
        if struct.unpack_from('<I', original, off)[0] != old_word:
            raise ValueError('Unexpected MuteControl image argument')
        if struct.unpack_from('<I', original, off + 8)[0] != 0x0320f809:
            raise ValueError('MImgSet call context differs')
        struct.pack_into('<I', elf, off, new_word)
        allowed.update(range(off, off + 4))
        patches.append(dict(va=hex(va), old_image_id=old_id, new_image_id=new_id,
                            old_word=hex(old_word), new_word=hex(new_word)))
    result[ELF] = bytes(elf)
    verify_allowlist(original, result[ELF], allowed)
    nums = bytearray(payloads[NUM])
    for rid, old, new in NUM_PATCHES:
        off = 56 + rid * 4
        if struct.unpack_from('<I', nums, off)[0] != old:
            raise ValueError('Unexpected MuteControl geometry')
        struct.pack_into('<I', nums, off, new)
    result[NUM] = bytes(nums)
    table = payloads[IMAGE]
    header = struct.unpack_from('<14I', table)
    if header[1] != len(table) or header[7] != 2181 or header[4] != 2181 * 4:
        raise ValueError('Unexpected V7.3 image table')
    path = b'../rc/ARimages/Grundig/modern/mute_badge.png\0'
    table = bytearray(table + struct.pack('<I', len(path)) + path)
    for off, value in ((4, len(table)), (16, 2182 * 4), (28, 2182)):
        struct.pack_into('<I', table, off, value)
    result[IMAGE] = bytes(table)
    result[BADGE] = badge_png()
    proof = dict(source_design='ui-preview/styles.css #mute-badge and tv-icons.svg #icon-mute',
        code_records=patches, num_records=[dict(id=hex(i), old=a, new=b) for i, a, b in NUM_PATCHES],
        outer=[1728, 19, 160, 230], root=[0, 0, 160, 230], panel=[0, 25, 158, 165],
        icon=[56, 30, 52, 52], screen_icon=[1784, 74, 52, 52], right_margin=84, top_margin=74,
        badge_id=BADGE_ID, badge_size=[52, 52], glyph_size=[26, 26], radius=16,
        white_background='#f9fbfcf2', glyph_color='#527185',
        shadows_cleared_with_original_null_id=1485,
        routing_and_lifecycle_code_changed=False,
        shared_arc_window_position_also_moves=True,
        limits=['Logical1920x1080 layout only; physical scaling/overscan unmeasured',
                'Numeric-popup dependent CSS badge movement is not installed in firmware',
                'Original lifecycle still requires actual IsMuted; zero alone does not open standalone badge',
                'No physical TV rendering or runtime lifecycle test'])
    return result, proof
