"""Separate immutable offline v6 visual overlay, reconstructed from verified v5.

Only the existing numeric widget and speaker geometry change. No channel-name
widget/handler bridge, firmware repack, target execution, or device write.
"""
from __future__ import annotations

import io
import json
import os
from pathlib import Path
import struct

from PIL import Image, ImageDraw, ImageFont
import build_native_ui_v5 as v5

ROOT = v5.ROOT
OUT = ROOT / 'analiz/native-ui-candidate/v6'
volume = v5.volume
sha = v5.sha
CARD_REL = v5.CARD_REL
IMAGE_REL = v5.IMAGE_REL
NUM_PATCHES = (
    (0x5a67, 42, 44), (0x5a66, 42, 44),
    (0x5a68, 13, 12), (0x5a69, 394, 393),
    (0x98f, 176, 312), (0x993, 112, 224),
    (0x997, 72, 78), (0x99a, 84, 106),
)
NUMERIC_SIZE_VAS = (0x896784, 0x8967a8, 0x8967cc, 0x8967f0)
ALIGN_VA = 0x896800
CODE_PATCHES = tuple((va, 0x3042ffff, 0x2402003a, 'local numeric font size 58')
                     for va in NUMERIC_SIZE_VAS) + (
    (ALIGN_VA, 0x24020042, 0x24020011, 'numeric left/top alignment'),
)


def guard(path):
    boundary = ROOT.resolve() / 'analiz/native-ui-candidate/v6'
    if OUT.resolve() != boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V6 output escapes pinned directory')
    cursor = path
    while cursor != ROOT:
        if cursor.is_symlink() or (hasattr(cursor, 'is_junction') and cursor.is_junction()):
            raise ValueError('Symlink/junction in V6 output')
        if cursor.exists() and cursor.is_file() and cursor.stat().st_nlink != 1:
            raise ValueError('Hardlinked V6 output')
        cursor = cursor.parent


def write_new(path, payload):
    guard(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    guard(path)
    with path.open('xb') as stream:
        stream.write(payload)
        stream.flush()
        os.fsync(stream.fileno())
    if path.read_bytes() != payload:
        raise ValueError('Persisted output differs from written bytes')


def construct(num, elf):
    previous_num, previous_elf, inherited = v5.construct(num, elf)
    new_num, new_elf = bytearray(previous_num), bytearray(previous_elf)
    num_records, code_records = [], []
    for rid, old, new in NUM_PATCHES:
        off = 56 + 4 * rid
        if struct.unpack_from('<I', previous_num, off)[0] != old:
            raise ValueError(f'Unexpected v5 Num resource {rid:#x}')
        struct.pack_into('<I', new_num, off, new)
        num_records.append(dict(id=rid, file_offset=off, old=old, new=new))
    for va, old, new, role in CODE_PATCHES:
        off = volume.elf_va_offset(elf, va, 4)
        if struct.unpack_from('<I', previous_elf, off)[0] != old:
            raise ValueError(f'Unexpected v5 local instruction {va:#x}')
        struct.pack_into('<I', new_elf, off, new)
        code_records.append(dict(va=hex(va), file_offset=off, old_word=hex(old),
                                 new_word=hex(new), role=role))
    volume.verify_allowlist(previous_num, bytes(new_num),
                            {r['file_offset'] + k for r in num_records for k in range(4)})
    volume.verify_allowlist(previous_elf, bytes(new_elf),
                            {r['file_offset'] + k for r in code_records for k in range(4)})
    return bytes(new_num), bytes(new_elf), dict(inherited_v5=inherited,
                                              num_records=num_records, code_records=code_records)


def pinned_font_bytes():
    raw = (volume.SOURCE / v5.DEJAVU_REL).read_bytes()
    if sha(raw) != v5.DEJAVU_SHA:
        raise ValueError('Pinned original DejaVu font changed')
    return raw


def card_png():
    scale = 4
    image = Image.new('RGBA', (310 * scale, 224 * scale), (245, 245, 245, 0))
    draw = ImageDraw.Draw(image)
    draw.rounded_rectangle((0, 0, 310 * scale - 1, 224 * scale - 1),
                           radius=24 * scale, fill=(245, 245, 245, 255))
    draw.rounded_rectangle((scale, scale, 309 * scale - 1, 223 * scale - 1),
                           radius=23 * scale, outline=(255, 255, 255, 200), width=scale)
    raw = pinned_font_bytes()
    font = lambda size: ImageFont.truetype(io.BytesIO(raw), size * scale)
    muted = (98, 121, 140, 255)
    draw.text((28 * scale, 22 * scale), 'KANAL SEÇİMİ', font=font(16), fill=muted, anchor='lt')
    draw.text((28 * scale, 183 * scale), 'OK ile seç', font=font(18), fill=muted, anchor='lt')
    draw.rounded_rectangle((234 * scale, 20 * scale, 282 * scale, 45 * scale),
                           radius=8 * scale, fill=(226, 235, 242, 255))
    draw.text((258 * scale, 32.5 * scale), 'TV', font=font(12), fill=(82, 106, 126, 255), anchor='mm')
    image = image.resize((310, 224), Image.Resampling.LANCZOS)
    out = io.BytesIO()
    image.save(out, format='PNG', compress_level=9)
    return out.getvalue()


def font_metrics():
    result = v5.font_metrics()
    font = ImageFont.truetype(io.BytesIO(pinned_font_bytes()), 58)
    widths = {text: round(font.getlength(text), 3) for text in ('1', '1234', '99999')}
    if max(widths.values()) > 254:
        raise ValueError('Five digits overflow numeric widget')
    result['0x4b0'] = dict(size=58, widget_width=254, measured_widths=widths,
                           sha256=v5.DEJAVU_SHA, scope='four local numeric widget states')
    return result


def expected_payloads():
    prior = v5.verified_records()
    payloads = {'08_APP' + row['path']: row['candidate'].read_bytes() for row in prior}
    num, elf, proof = construct((volume.SOURCE / volume.NUM_REL).read_bytes(),
                                (volume.SOURCE / volume.ELF_REL).read_bytes())
    payloads[volume.NUM_REL], payloads[volume.ELF_REL] = num, elf
    payloads[CARD_REL] = card_png()
    font_metrics()
    return payloads, proof


def verified_records():
    guard(OUT / 'manifest.json')
    manifest = json.loads((OUT / 'manifest.json').read_text(encoding='utf-8'))
    payloads, _ = expected_payloads()
    rows = manifest['records']
    if len(rows) != 24 or {r['relative_path'] for r in rows} != payloads.keys():
        raise ValueError('Unexpected v6 overlay set')
    if {p.relative_to(OUT / 'overlay').as_posix() for p in (OUT / 'overlay').rglob('*') if p.is_file()} != payloads.keys():
        raise ValueError('Unexpected files in v6 overlay')
    result = []
    for row in rows:
        relative = row['relative_path']
        target = OUT / 'overlay' / relative
        guard(target)
        original = None if relative == CARD_REL else sha((volume.SOURCE / relative).read_bytes())
        if (row['original_sha256'] != original or row['candidate_sha256'] != sha(payloads[relative])
                or target.read_bytes() != payloads[relative]):
            raise ValueError('V6 output differs from reconstructed inputs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=target,
                           original_sha256=original, candidate_sha256=row['candidate_sha256']))
    return result


def build():
    guard(OUT / 'manifest.json')
    if (OUT / 'manifest.json').exists():
        return dict(status='verified_existing_v6', files=len(verified_records()))
    if OUT.exists() and any(p.is_file() for p in OUT.rglob('*')):
        raise FileExistsError('Refusing partial/existing V6 outputs')
    payloads, proof = expected_payloads()
    records = []
    for relative, payload in payloads.items():
        write_new(OUT / 'overlay' / relative, payload)
        original = None if relative == CARD_REL else sha((volume.SOURCE / relative).read_bytes())
        records.append(dict(relative_path=relative, original_sha256=original,
                            candidate_sha256=sha(payload), bytes=len(payload)))
    proof.update(revision='v6', status='offline_visual_overlay_not_flashable', records=records,
                 volume_font=dict(id=0x4ae, size=36, color_id=0),
                 numeric_font=dict(id=0x4b0, path=v5.DEJAVU_REL, size=58, sha256=v5.DEJAVU_SHA,
                                   global_num_0x321e=48, local_fields=['0x13a', '0x146', '0x152', '0x15e']),
                 font_metrics=font_metrics(),
                 volume_geometry=dict(root=[68, 490], panel=[68, 450], speaker=[12, 393, 44, 44],
                                      number_width=68, track=[31, 86, 6, 276]),
                 rounded_numeric=dict(image_id=v5.CARD_ID, path=CARD_REL, resource_path=v5.CARD_RESOURCE,
                                      size=[310, 224], radius=24, background_rect=[1538, 64, 310, 224],
                                      digit_rect=[1566, 106, 254, 78], alignment=0x11,
                                      static_header='KANAL SEÇİMİ', static_footer='OK ile seç'),
                 matched_channel_name=dict(implemented_in_overlay=False,
                     status='Dynamic matched name needs additional native widget/handler bridge, rehost test only currently'),
                 television_tested=False, firmware_repacked=False, flash_ready=False,
                 limits=['Original OnCreate is not executed by this builder; patched arguments are statically verified.',
                         'Image_res and all existing font files/global font sizes remain unchanged from verified v5.',
                         'Static text is baked into the background; matched-channel names are not implemented by this overlay.',
                         'Host software rendering and full television behavior remain separate evidence scopes.'])
    write_new(OUT / 'manifest.json', json.dumps(proof, indent=2, ensure_ascii=False).encode('utf-8'))
    verified_records()
    return dict(status=proof['status'], files=len(records), new_image_id=v5.CARD_ID)


if __name__ == '__main__':
    print(json.dumps(build()))
