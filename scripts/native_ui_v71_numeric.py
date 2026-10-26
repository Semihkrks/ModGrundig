"""Fix ChannelControl's real 80px outer window, using its existing local height.

Pure byte transformation over the verified V7 TV overlay. Does not execute a
firmware instruction or touch a TV. Volume changes may already be composed into
the input, so this module pins the entire *numeric* code span and resources.
"""
from __future__ import annotations

import hashlib
import io
import json
from pathlib import Path
import struct

from PIL import Image, ImageFont
from build_native_volume_patch import elf_va_offset, verify_allowlist

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-ui-v71/numeric'
ELF = '08_APP/bin/dvbt_board'
NUM = '08_APP/rc/rc/bin/Num_res.bin'
IMAGE = '08_APP/rc/rc/bin/Image_res.bin'
CARD = '08_APP/rc/ARimages/Grundig/modern/numeric_bg.png'
FONT = '08_APP/rc/rc/DejaVuSans.ttf'
FONT_SHA = 'f4d46af3f8b795d13cffe2ab07d639e0f116412a18f9706ee87f94770b1dd5b2'
NUMERIC_SPAN = (0x894e64, 0x897388)
NUMERIC_SPAN_SHA = 'f1ce059ddaeb5e9bbbf36db78c686a681059398351c0fb41b9a9a9161e2bf9f0'
CODE_PATCHES = ((0x89518c, 0x24040050, 0x2404098f,
                 'ChannelControlApp outer window height: RcGetNum(0x50) -> RcGetNum(0x98f)'),)
NUM_VALUES = {
    0x50: 80, 0x51: 1920, 0x52: 0, 0x53: 0,
    0x98f: 312, 0x990: 1920, 0x991: 0, 0x992: 0,
    0x993: 224, 0x994: 310, 0x995: 1538, 0x996: 64,
    0x997: 78, 0x998: 254, 0x999: 1566, 0x99a: 118,
    0x321e: 48, 0x45f5: 3, 0x45f9: 4,
}


def sha(raw: bytes) -> str:
    return hashlib.sha256(raw).hexdigest()


def number(raw: bytes, rid: int) -> int:
    return struct.unpack_from('<I', raw, 56 + 4 * rid)[0]


def intersect(a, b):
    x, y = max(a[0], b[0]), max(a[1], b[1])
    right, bottom = min(a[0] + a[2], b[0] + b[2]), min(a[1] + a[3], b[1] + b[3])
    return [x, y, max(0, right - x), max(0, bottom - y)]


def layout(payloads: dict[str, bytes]) -> dict:
    """Follow the actual App constructor and nested parent rectangles, statically."""
    elf, nums = payloads[ELF], payloads[NUM]
    va = CODE_PATCHES[0][0]
    word = struct.unpack_from('<I', elf, elf_va_offset(elf, va, 4))[0]
    if word not in (0x24040050, 0x2404098f):
        raise ValueError('Unexpected outer-frame height resource instruction')
    # App CreateMainFrame stack24/28/2c/30 = x/y/w/h; constructor0x8951e4.
    outer = [number(nums, i) for i in (0x52, 0x53, 0x51, word & 0xffff)]
    root_local = [number(nums, i) for i in (0x991, 0x992, 0x990, 0x98f)]
    root = [outer[0] + root_local[0], outer[1] + root_local[1], *root_local[2:]]
    card_local = [number(nums, i) for i in (0x995, 0x996, 0x994, 0x993)]
    text_local = [number(nums, i) for i in (0x999, 0x99a, 0x998, 0x997)]
    card = [root[0] + card_local[0], root[1] + card_local[1], *card_local[2:]]
    text = [root[0] + text_local[0], root[1] + text_local[1], *text_local[2:]]
    clip = intersect(outer, root)
    return dict(outer_frame=outer, root=root, background=card, digits=text,
                background_visible=intersect(card, clip), digits_visible=intersect(text, clip),
                outer_height_resource=hex(word & 0xffff),
                parent_relationship='background and TextBox are siblings under root; root under frame client')


def _validate_resources(payloads):
    from native_ui_v7_tv_pins import RECORDS
    pins = {r[0]: (r[2], r[3]) for r in RECORDS}
    for path in (IMAGE, CARD):
        if path not in payloads or (sha(payloads[path]), len(payloads[path])) != pins[path]:
            raise ValueError(f'Pinned V7 numeric resource changed: {path}')
    raw = payloads[IMAGE]
    header = struct.unpack_from('<14I', raw)
    if header[7] != 2180:
        raise ValueError('Expected appended Image table ID2179')
    paths, pos = [], 56
    for _ in range(header[7]):
        length = struct.unpack_from('<I', raw, pos)[0]
        paths.append(raw[pos + 4:pos + 4 + length].decode('utf-8').rstrip('\0'))
        pos += 4 + length
    if pos != len(raw) or paths[2179] != '../rc/ARimages/Grundig/modern/numeric_bg.png':
        raise ValueError('Numeric Image table ID does not resolve to the private card')
    if paths[0x4b0] != '../rc/rc/DejaVuSans.ttf':
        raise ValueError('Numeric font resource changed')
    font_raw = (ROOT / 'analiz/dosya-sistemleri-tam' / FONT).read_bytes()
    if sha(font_raw) != FONT_SHA:
        raise ValueError('Original numeric font changed')
    font = ImageFont.truetype(io.BytesIO(font_raw), 58)
    # Firmware accepts up to four digits; five checked as a conservative bound.
    metrics = {s: dict(width=round(font.getlength(s), 3), bbox=list(font.getbbox(s)))
               for s in ('0', '12', '9999', '99999')}
    if max(v['width'] for v in metrics.values()) + 6 > 254:
        raise ValueError('Numeric glyphs exceed the padded text box')
    if max(v['bbox'][3] for v in metrics.values()) + 6 > 78:
        raise ValueError('Numeric glyph height exceeds the padded text box')
    with Image.open(io.BytesIO(payloads[CARD])) as image:
        image.load()
        if image.size != (310, 224) or image.convert('RGBA').getpixel((0, 0))[3] != 0:
            raise ValueError('Expected native rounded alpha card')
    return dict(image_table_id=2179, image_path=paths[2179], image_size=[310, 224],
                image_enable_store_va='0x89610c', image_enable_store_word='0xa204003a',
                font_id=0x4b0, font_path=FONT, font_sha256=FONT_SHA, font_size=58,
                font_metrics=metrics, alignment=0x11, padding=3)


def apply(payloads: dict[str, bytes]) -> tuple[dict[str, bytes], dict]:
    """Return new payloads and proof; reject stale numeric inputs; no file writes."""
    elf, nums = payloads[ELF], payloads[NUM]
    start, end = NUMERIC_SPAN
    offset = elf_va_offset(elf, start, end - start)
    if sha(elf[offset:offset + end - start]) != NUMERIC_SPAN_SHA:
        raise ValueError('V7 numeric code span changed (or patch already applied)')
    if any(number(nums, rid) != value for rid, value in NUM_VALUES.items()):
        raise ValueError('V7 numeric/global geometry or font resource changed')
    resources = _validate_resources(payloads)
    before = layout(payloads)
    new_elf, code_records, allowed = bytearray(elf), [], set()
    for va, old, new, role in CODE_PATCHES:
        off = elf_va_offset(elf, va, 4)
        if struct.unpack_from('<I', elf, off)[0] != old:
            raise ValueError('Old numeric instruction mismatch')
        struct.pack_into('<I', new_elf, off, new)
        allowed.update(range(off, off + 4))
        code_records.append(dict(va=hex(va), file_offset=off, old_word=hex(old), new_word=hex(new), role=role))
    changed = verify_allowlist(elf, bytes(new_elf), allowed)
    result = dict(payloads)
    result[ELF] = bytes(new_elf)
    after = layout(result)
    if after['background_visible'] != after['background'] or after['digits_visible'] != after['digits']:
        raise ValueError('Numeric widget clipped by actual outer window/root')
    if intersect(after['background'], [72, 54, 1776, 972]) != after['background']:
        raise ValueError('Numeric card outside logical overscan-safe area')
    proof = dict(status='PASS_OFFLINE_STATIC_LAYOUT', code_records=code_records, num_records=[],
                 changed_elf_bytes=changed, changed_paths=[ELF], before=before, after=after,
                 resources=resources, root_cause='outer DirectFB window remained 80px high; card at y64 exposed only16px; digits at y118 were fully clipped',
                 evidence=['analiz/native/ui-targeted/v71-numeric-frame/00895108.c',
                           'analiz/native/ui-targeted/v71-numeric-frame/00895108.json',
                           'analiz/native/ui-four/channels/numeric-v1/00895b84.c',
                           'analiz/native/ui-deep/muf-core35/2e251be4.c'],
                 service_handlers_changed=False, global_num_0x50_changed=False,
                 original_oncreate_executed=False, physical_v71_tested=False,
                 limits=['Static parent-clipping and original font metrics; physical TV V7.1 rendering remains unobserved.',
                         'New Ghidra output is independent readOnly analysis, not REA Evidence.'])
    return result, proof


if __name__ == '__main__':
    from build_native_ui_v7_tv import verified_packaging_records
    inputs = {'08_APP' + r['path']: r['candidate'].read_bytes() for r in verified_packaging_records()}
    _, proof = apply(inputs)
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / 'proof.json').write_text(json.dumps(proof, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(status=proof['status'], changed_paths=proof['changed_paths'], after=proof['after'])))
