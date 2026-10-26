"""Native v8 channel surfaces: exact local MIPS arguments, private images.

No original files, channel services, native filter policy or event code changes.
The left list retains its original dark row styles. This is a deliberate bounded
two-tone port, not a claim that the complete browser design is native.
"""
from __future__ import annotations

import io
import struct
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset, verify_allowlist

IMAGE_RECORDS = (
    {'id': 2184, 'path': '../rc/ARimages/Grundig/modern/v8_channel_panel.png'},
    {'id': 2185, 'path': '../rc/ARimages/Grundig/modern/v8_program_band.png'},
)

PATCHES = tuple(
    (va, 0x2404004b, 0x2404005e, 'channel-list main panel fallback Color75 -> Color94')
    for va in (0x799b0c, 0x799b2c, 0x799b4c, 0x799b6c)
) + (
    (0x799c6c, 0x24050042, 0x24050888, 'channel-list panel normal Image66 -> private2184'),
    (0x799c90, 0x24050027, 0x24050888, 'channel-list panel state1 Image39 -> private2184'),
    (0x799cb4, 0x24050027, 0x24050888, 'channel-list panel state2 Image39 -> private2184'),
    (0x799cd8, 0x24050027, 0x24050888, 'channel-list panel state3 Image39 -> private2184'),
) + tuple(
    (va, 0x24040045, 0x24040000, 'channel-list right detail normal text Color69 -> Color0')
    for va in (0x79d164, 0x79d5c8, 0x79da38, 0x79de98, 0x79e2f8)
) + tuple(
    (va, 0x240501a7, 0x24050889, 'program-info local Image423 -> private2185')
    for va in (0x7deb74, 0x7deb98, 0x7debbc, 0x7debe0,
               0x7deeb8, 0x7deedc, 0x7def00, 0x7def24,
               0x7dfe98, 0x7dfebc, 0x7dfee0, 0x7dff04)
)


def resource_relative(path):
    if not path.startswith('../rc/ARimages/Grundig/modern/v8_'):
        raise ValueError('Private channel image path outside fixed scope')
    return '08_APP/rc/' + path.removeprefix('../rc/')


def encode(image):
    out = io.BytesIO()
    image.save(out, format='PNG', compress_level=9)
    return out.getvalue()


def image_payloads():
    # A small texture is stretched by the existing native image renderer. The
    # 353x138 panel follows the old ID66 dimensions; no 1720x770 source texture.
    panel = Image.new('RGBA', (353, 138), (245, 248, 251, 0))
    draw = ImageDraw.Draw(panel)
    draw.rounded_rectangle((0, 0, 352, 137), radius=6, fill=(245, 248, 251, 255))
    draw.rounded_rectangle((1, 1, 351, 136), radius=5, outline=(255, 255, 255, 210), width=1)
    # Existing program info contains white text and icon assets in many states.
    # Keep their contrast on a soft blue-grey band instead of an unsafe partial
    # white conversion; this image is private to twelve local MImg arguments.
    band = Image.new('RGBA', (2, 250))
    for y in range(250):
        t = y / 249
        rgba = tuple(round(a + (b-a)*t) for a, b in zip((35, 55, 75, 245), (27, 44, 62, 240)))
        for x in range(2):
            band.putpixel((x, y), rgba)
    return {resource_relative(IMAGE_RECORDS[0]['path']): encode(panel),
            resource_relative(IMAGE_RECORDS[1]['path']): encode(band)}


def scene_spec(num):
    def rect(ids):
        return [struct.unpack_from('<I', num, 56+4*rid)[0] for rid in ids]
    # Parent-local constructor rectangles, NOT final runtime layout. A caller
    # may paint these with NativePainter and show this limitation explicitly.
    return {
        'coordinate_basis': 'retained constructor rectangles; later layout not run',
        'channel_list': {
            'function': '0x7995b0',
            'panel': {'field': 'this+0x184', 'parent': 'frame root',
                      'num_ids_xywh': [404,405,403,402], 'rect': rect([404,405,403,402]),
                      'image_id': 2184, 'fallback_color_id': 94},
            'list': {'field': 'this+0x1b4', 'parent': 'this+0x184',
                     'num_ids_xywh': [572,573,571,570], 'rect': rect([572,573,571,570]),
                     'image_id': 496, 'native_rows_retained': True},
            'detail_title': {'field': 'this+0x1b8', 'parent': 'this+0x184',
                             'num_ids_xywh': [664,665,663,662], 'rect': rect([664,665,663,662]),
                             'font_id': 0x4af, 'size_num_id': 0x3215,
                             'size': struct.unpack_from('<I',num,56+4*0x3215)[0],
                             'color_id': 0, 'align': 0x41, 'text_resource_id': 3439,
                             'text_basis': 'native initial Hazır Değil placeholder; real EPG unbound'},
        },
        'program_info': {
            'function': '0x7de53c',
            'band': {'field': 'this+0x188', 'parent': 'this+0x180',
                     'num_ids_xywh': [850,851,849,848], 'rect': rect([850,851,849,848]),
                     'image_id': 2185},
            'channel_box': {'field': 'this+0x184', 'parent': 'this+0x180',
                            'num_ids_xywh': [758,759,757,756], 'rect': rect([758,759,757,756]),
                            'image_id': 2185, 'native_visibility_initially_disabled': True},
        },
        'real_channel_database': False, 'fake_channels_embedded': False,
        'native_filter_count_preserved': 7, 'full_native_frame_executed': False,
    }


def transform(num: bytes, elf: bytes, assets: dict[str, bytes] | None = None):
    """Compose after v7/Home; return num, ELF, assets and exact local changes.

    Whole-file identity is pinned by the parent builder because another v8
    module may already have changed disjoint Home instructions. Every instruction
    in this module must still match the original local argument word.
    """
    output = bytearray(elf)
    records = []
    allowed = set()
    for va, old, new, role in PATCHES:
        off = elf_va_offset(elf, va, 4)
        if struct.unpack_from('<I', elf, off)[0] != old:
            raise ValueError(f'Unexpected native channel instruction at {va:#x}')
        struct.pack_into('<I', output, off, new)
        allowed.update(range(off, off+4))
        records.append({'va': hex(va), 'file_offset': off, 'old_word': hex(old),
                        'new_word': hex(new), 'role': role,
                        'function': '0x7995b0' if va < 0x7de53c else '0x7de53c'})
    verify_allowlist(elf, bytes(output), allowed)
    copied = dict(assets or {})
    for relative, payload in image_payloads().items():
        if relative in copied:
            raise ValueError('Private channel asset collision')
        copied[relative] = payload
    return num, bytes(output), copied, {
        'code_records': records, 'num_records': [],
        'image_records': [dict(r) for r in IMAGE_RECORDS],
        'scene_spec': scene_spec(num),
        'unchanged': ['native channel DB and selection', 'all seven filters',
                      'list item/focus logic', 'original global Color table',
                      'original shared image entries/files', 'all event handlers'],
        'limits': ['two-tone channel-list subset; dynamic left row theme retained',
                   'program-info retains native layout, white text and icons on dark band',
                   'no claim of full Chrome visual parity or device validation'],
    }
