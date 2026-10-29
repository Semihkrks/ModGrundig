"""Menu-only private bitmap branding; offline bytes and fresh SVG artwork only.

The OEM wordmark is a bitmap, not a font-backed label. The constructed SEMIH
glyphs approximate its heavy geometric style; no exact recovered font is claimed.
"""
from __future__ import annotations
import hashlib
import io
import json
from pathlib import Path
import struct
import zlib

from build_native_volume_patch import elf_va_offset
from native_ui_v79_assets import image_paths

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-features/semih-brand'
ELF_SHA = '861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea'
TABLE_SHA = '3319b2a33d2950396bb181a558214d901575c82ca2ab8df2a91f52316dfce467'
RESOURCE = '08_APP/rc/ARimages/Grundig/modern/semih_menu_brand.png'
IMAGE_ID = 2184
PATCHES = (0xdb56e4, 0xdb5708, 0xdb572c, 0xdb5750,
           0xdbebd4, 0xdbebf8, 0xdbec1c, 0xdbec40)
# Filled after the explicit Chromium SVG render, then used by packaging/tests.
PNG_SHA = 'fdfd41d53f5f1979d9021ec1942b9d015396bb65be8bbf6a638e103d2c6131e5'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def source_svg():
    """Editable independent paths; no raster tracing, font dependency or network."""
    return '''<svg xmlns="http://www.w3.org/2000/svg" width="400" height="120" viewBox="0 0 400 120" role="img" aria-label="SEMIH">
<title>SEMIH menu wordmark proposal</title>
<desc>Constructed heavy geometric capitals; approximate OEM bitmap style, not an exact recovered font. Native canvas and cap-height retained.</desc>
<g fill="#fff" transform="translate(98 43)">
<path d="M35 0H12C4 0 0 4 0 10C0 17 5 21 14 21H23C26 21 27 22 27 24C27 26 25 27 22 27H1V34H24C32 34 37 30 37 23C37 16 32 12 23 12H14C11 12 10 11 10 9C10 7 12 7 15 7H35Z"/>
<path transform="translate(49)" d="M0 0H32V8H10V13H29V21H10V26H32V34H0Z"/>
<path transform="translate(93)" d="M0 34V0H11L21 17L31 0H42V34H32V15L25 28H17L10 15V34Z"/>
<path transform="translate(147)" d="M0 0H10V34H0Z"/>
<path transform="translate(169)" d="M0 0H10V13H25V0H35V34H25V22H10V34H0Z"/>
</g></svg>'''


def apply(original: bytes):
    """Patch eight menu image arguments; every other ELF byte is preserved."""
    if not isinstance(original, bytes) or sha(original) != ELF_SHA:
        raise ValueError('Exact V7.9 ELF required before composing other features')
    result = bytearray(original)
    records = []
    for va in PATCHES:
        at = elf_va_offset(original, va, 4)
        if struct.unpack_from('<I', original, at)[0] != 0x24050393:
            raise ValueError(f'Menu logo argument differs at {va:#x}')
        # Same a1 register/immediate instruction, same call and delay slots.
        struct.pack_into('<I', result, at, 0x24050000 | IMAGE_ID)
        records.append(dict(va=hex(va), offset=at, old_word='0x24050393',
                            new_word=hex(0x24050000 | IMAGE_ID)))
    return bytes(result), dict(source_sha256=sha(original), output_sha256=sha(result),
        instruction_patches=records, private_image_id=IMAGE_ID, original_image_id=915,
        consumer='MenuBackgroundFrame Image field this+0x1b8',
        methods=['OnCreate 0xdbb4f8', 'SetBreadCrumbs 0xdb5328 normal branch'],
        widget_rectangle=[0, 8, 260, 78], native_texture=[400, 120],
        num_ids_xywh=['0x4015', '0x4016', '0x4014', '0x4013'],
        geometry_modified=False, navigation_modified=False, helpers_added=False,
        target_executed=False, exact_font_recovered=False,
        font_policy='independent constructed geometric capitals approximating bitmap OEM style')


def png_format(raw):
    """Strict native 400x120 P8 white palette with transparency and CRC checks."""
    if raw[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('PNG signature differs')
    at, chunks = 8, []
    while at + 12 <= len(raw):
        n = struct.unpack_from('>I', raw, at)[0]
        end = at + n + 12
        if end > len(raw): raise ValueError('Truncated PNG')
        tag, data = raw[at+4:at+8], raw[at+8:end-4]
        if zlib.crc32(tag + data) != struct.unpack_from('>I', raw, end-4)[0]:
            raise ValueError('PNG CRC differs')
        chunks.append((tag, data)); at = end
        if tag == b'IEND': break
    tags = [t for t, _ in chunks]
    if at != len(raw) or tags[0] != b'IHDR' or tags[-1] != b'IEND':
        raise ValueError('Incomplete PNG')
    if struct.unpack('>IIBBBBB', chunks[0][1]) != (400, 120, 8, 3, 0, 0, 0):
        raise ValueError('Native canvas/P8 format differs')
    if tags.count(b'PLTE') != 1 or tags.count(b'tRNS') != 1 or b'IDAT' not in tags:
        raise ValueError('Native palette transparency absent')
    palette = next(d for t, d in chunks if t == b'PLTE')
    if palette != b'\xff' * 768: raise ValueError('Palette must stay white')
    if next(d for t, d in chunks if t == b'tRNS') != bytes(range(256)):
        raise ValueError('Alpha palette mapping differs')
    return dict(width=400, height=120, bit_depth=8, color_type=3,
                white_palette=True, transparency=True, chunk_crc_errors=0)


def expected_payloads(image_table_bytes):
    """Append one private image, keeping all existing records byte-identical."""
    if sha(image_table_bytes) != TABLE_SHA or len(image_paths(image_table_bytes)) != IMAGE_ID:
        raise ValueError('Exact V7.9 Image_res table required')
    raw = (OUT/'semih_menu_brand.png').read_bytes()
    if sha(raw) != PNG_SHA: raise ValueError('Retained SEMIH raster differs')
    if (OUT/'semih_menu_brand.svg').read_bytes() != source_svg().encode():
        raise ValueError('Retained editable source differs')
    fmt = png_format(raw)
    result = bytearray(image_table_bytes)
    path = ('../'+RESOURCE.removeprefix('08_APP/')).encode()+b'\0'
    result.extend(struct.pack('<I', len(path))+path)
    for at, n in ((4, len(result)), (16, (IMAGE_ID+1)*4), (28, IMAGE_ID+1)):
        struct.pack_into('<I', result, at, n)
    table = bytes(result)
    if table[56:len(image_table_bytes)] != image_table_bytes[56:]:
        raise ValueError('Existing image records changed')
    return {RESOURCE: raw}, table, dict(source_table_sha256=TABLE_SHA,
        output_table_sha256=sha(table), before_record_count=IMAGE_ID,
        after_record_count=IMAGE_ID+1, original_915_unchanged=True,
        existing_records_byte_identical=True, resource_id=IMAGE_ID,
        resource_path=RESOURCE, png_sha256=sha(raw), svg_sha256=sha(source_svg().encode()),
        format=fmt, label='SEMIH', exact_font_recovered=False,
        preview='analiz/native-features/semih-brand/proposal.html')


def raster_asset():
    """Explicit fresh SVG→Chromium8x→LANCZOS→white P8+tRNS pipeline."""
    from PIL import Image
    from playwright.sync_api import sync_playwright
    requests = []
    with sync_playwright() as pw:
        browser = pw.chromium.launch(executable_path='C:/Program Files/Google/Chrome/Application/chrome.exe', headless=True)
        try:
            page = browser.new_page(viewport=dict(width=400, height=120), device_scale_factor=8)
            page.on('request', lambda request: requests.append(request.url))
            page.route('**/*', lambda route: route.abort())
            page.set_content('<html><body style="margin:0;background:transparent">'+source_svg()+'</body></html>')
            screenshot = page.screenshot(omit_background=True, animations='disabled')
            alpha = Image.open(io.BytesIO(screenshot)).convert('RGBA').resize((400, 120), Image.Resampling.LANCZOS).getchannel('A')
            # OEM alpha uses 16-step coverage; this also removes faint resampling
            # rings beyond the SVG's 34px cap-height without editing OEM pixels.
            alpha = alpha.point(lambda value: 0 if value < 24 else min(255, round(value/16)*16))
            indexed = Image.frombytes('P', alpha.size, alpha.tobytes())
            indexed.putpalette([255]*768)
            out = io.BytesIO(); indexed.save(out, format='PNG', bits=8, transparency=bytes(range(256)), compress_level=9)
            if requests: raise ValueError('Unexpected network request')
            raw = out.getvalue(); png_format(raw)
            return raw, dict(browser=browser.version, device_scale_factor=8,
                downsample='LANCZOS', requests=requests, alpha_bbox=alpha.getbbox())
        finally:
            browser.close()


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(); parser.add_argument('--render', action='store_true')
    args = parser.parse_args()
    if args.render:
        OUT.mkdir(parents=True, exist_ok=True)
        raw, proof = raster_asset()
        (OUT/'semih_menu_brand.svg').write_bytes(source_svg().encode())
        (OUT/'semih_menu_brand.png').write_bytes(raw)
        (OUT/'render.json').write_text(json.dumps(dict(proof, png_sha256=sha(raw)), indent=2)+'\n')
        print(json.dumps(dict(proof, png_sha256=sha(raw)), indent=2))
