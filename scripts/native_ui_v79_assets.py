"""Approved V7.9 wave icons and append-only native image resources.

Packaging uses only the standard library and verified retained PNGs. An explicit
rerender uses the V4 Chromium 8x/LANCZOS/OEM P8 pipeline; no TV code is executed.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import struct
import zlib

ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / 'analiz/native-ui-v79/assets'
V78 = ROOT / 'analiz/native-ui-candidate/v7.8-tv/overlay'
IMAGE = '08_APP/rc/rc/bin/Image_res.bin'
IMAGE_SHA = '2ef7d8b0dfc053d524464d996332e0b276601e6168e5288ecd81b52412d45293'
MEDIUM = '08_APP/rc/ARimages/Grundig/volume/volume_icon.png'
MEDIUM_SHA = 'aa1c3918d73338f4065285fbc634fe56169dcc7019af99753b907a897796b099'
MUTE = '08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
MUTE_SHA = '82445d3755d20ba59fa325fc3bebc7505124f59531b0b7dbd3c1470b30a5417c'
SYMBOL_SHA = 'b2f3a2e3392392f1aa4acf207e4c28efa93f9db9c1803a589b3574fc709744bc'
PREVIEW_SOURCE_SHA = '98409f9ae35fb8e381496e5035a2f597b9ebc48ac32f87a9937576fb36298b87'
BODY = 'M4 12h6l7-6v20l-7-6H4Z'
CURVES = {
    'low': [(22, 11, 27, 16, 22, 21)],
    'high': [(21, 12, 25, 16, 21, 20), (24.5, 9.5, 31, 16, 24.5, 22.5),
             (28, 6.5, 37, 16, 28, 25.5)],
}
IDS = {'low': 2182, 'high': 2183}
PATHS = {name: f'08_APP/rc/ARimages/Grundig/modern/volume_{name}.png' for name in IDS}
SVG_SHAS = {
    'low': 'ee3c49f90b8637e7bd0aef19c5a439ce5b4dcfa30438a2631f4da4cbad5d1727',
    'high': '46de14d917554c71ce00ee7ac23ce84a50a015b46b21994c7f952b715c442e95',
}
PNG_SHAS = {
    'low': 'ec0689ecad3e8d27f445e80f12f6fedf425c59b012817622fd62b9c65a274e50',
    'high': 'b4f4f25bde8148dd5c4ba2821adfc8467d3a70bdadf904abbb6173e46a6a6c5d',
}
CHROME = 'C:/Program Files/Google/Chrome/Application/chrome.exe'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def source_svg(name):
    """Byte-identical to the approved low/high SVG; no external references."""
    waves = ''.join(f'M{x} {y}Q{cx} {cy} {ex} {ey}' for x, y, cx, cy, ex, ey in CURVES[name])
    result = ('<svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100">'
              '<rect width="100" height="100" fill="#f5f5f5"/>'
              '<g transform="translate(10 10) scale(2.5)" fill="none" stroke="#1687df" '
              'stroke-width="2" stroke-linecap="round" stroke-linejoin="round">'
              f'<path d="{BODY}"/><path d="{waves}"/></g></svg>')
    if sha(result.encode()) != SVG_SHAS[name]:
        raise ValueError('Approved SVG geometry changed')
    return result


def png_format(raw):
    """Validate complete native PNG framing, palette, alpha and CRCs offline."""
    if raw[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('Invalid PNG signature')
    cursor, chunks = 8, []
    while cursor + 12 <= len(raw):
        size = struct.unpack_from('>I', raw, cursor)[0]
        end = cursor + 12 + size
        if end > len(raw):
            raise ValueError('Truncated PNG chunk')
        tag = raw[cursor+4:cursor+8]
        if zlib.crc32(raw[cursor+4:end-4]) != struct.unpack_from('>I', raw, end-4)[0]:
            raise ValueError('Invalid PNG chunk CRC')
        chunks.append((tag, raw[cursor+8:end-4]))
        cursor = end
        if tag == b'IEND':
            break
    tags = [tag for tag, _ in chunks]
    if cursor != len(raw) or not chunks or tags[0] != b'IHDR' or tags[-1] != b'IEND':
        raise ValueError('Incomplete PNG or trailing bytes')
    if len(chunks[0][1]) != 13 or struct.unpack('>IIBBBBB', chunks[0][1]) != (100, 100, 8, 3, 0, 0, 0):
        raise ValueError('OEM 100x100 P8 format differs')
    if tags.count(b'IHDR') != 1 or tags.count(b'PLTE') != 1 or b'IDAT' not in tags or b'tRNS' in tags:
        raise ValueError('OEM opaque palette/alpha flags differ')
    palette = next(data for tag, data in chunks if tag == b'PLTE')
    if not palette or len(palette) % 3 or len(palette) > 768:
        raise ValueError('Invalid PNG palette')
    return dict(width=100, height=100, bit_depth=8, color_type=3, interlace=0,
                alpha_capability=False, palette_entries=len(palette)//3, chunk_crc_errors=0)


def image_paths(raw):
    """Parse the same variable-length table boundaries as parse_table()."""
    if not isinstance(raw, bytes) or len(raw) < 56:
        raise ValueError('Image resource bytes missing')
    words = struct.unpack_from('<14I', raw)
    count = words[7]
    if (raw[:4] != b'_tsm' or words[1] != len(raw) or words[2] != 5 or
            words[4] != count*4 or words[5:7] != (56, 56) or count > 100000):
        raise ValueError('Unexpected Image_res header')
    cursor, records = 56, []
    for _ in range(count):
        if cursor + 4 > len(raw):
            raise ValueError('Truncated image path length')
        length = struct.unpack_from('<I', raw, cursor)[0]
        end = cursor + 4 + length
        if not length or end > len(raw) or raw[end-1] != 0:
            raise ValueError('Malformed image path')
        path = raw[cursor+4:end-1]
        if b'\0' in path:
            raise ValueError('Embedded NUL in image path')
        records.append(path.decode('utf-8', 'strict'))
        cursor = end
    if cursor != len(raw):
        raise ValueError('Unexpected image table trailing bytes')
    return records


def append_image_table(raw):
    paths = image_paths(raw)
    if sha(raw) != IMAGE_SHA or len(paths) != 2182:
        raise ValueError('Pinned V7.8 Image_res changed')
    result = bytearray(raw)
    for name in IDS:
        path = ('../' + PATHS[name].removeprefix('08_APP/')).encode() + b'\0'
        result.extend(struct.pack('<I', len(path)) + path)
    for offset, value in ((4, len(result)), (16, 2184*4), (28, 2184)):
        struct.pack_into('<I', result, offset, value)
    updated = bytes(result)
    if image_paths(updated)[:2182] != paths or updated[56:len(raw)] != raw[56:]:
        raise ValueError('Existing native image records changed')
    return updated


def retained_assets():
    """Code-pinned retained PNGs, usable without Pillow or a browser."""
    payloads = {}
    for name in IDS:
        raw = (ASSETS / f'volume_{name}.png').read_bytes()
        if sha(raw) != PNG_SHAS[name]:
            raise ValueError('Pinned V7.9 raster changed: ' + name)
        png_format(raw)
        if (ASSETS / f'volume_{name}.svg').read_bytes() != source_svg(name).encode():
            raise ValueError('Retained SVG differs from approved source')
        payloads[PATHS[name]] = raw
    return payloads


def expected_payloads(image_table_bytes):
    """Return (two PNG payloads, appended Image_res bytes, evidence)."""
    table = append_image_table(image_table_bytes)
    payloads = retained_assets()
    proof = dict(source_revision='v7.8-tv', source_table_sha256=IMAGE_SHA,
        before_record_count=2182, after_record_count=2184,
        existing_image_records_byte_identical=True, canvas=[100, 100], symbol_side=80,
        speaker_body=BODY, stroke_width=2, stroke_color='#1687df', background='#f5f5f5',
        rendering='Chromium device_scale_factor=8; LANCZOS downsample; opaque RGB MEDIANCUT P8; no dither',
        approved_preview_source='scripts/preview_volume_wave_icons.py',
        approved_preview_source_sha256=PREVIEW_SOURCE_SHA, symbol_source_sha256=SYMBOL_SHA,
        resources=[dict(name=name, id=IDS[name], path=PATHS[name], wave_count=len(CURVES[name]),
                        svg_sha256=SVG_SHAS[name], png_sha256=PNG_SHAS[name],
                        png_format=png_format(payloads[PATHS[name]])) for name in IDS],
        preserved_resources=[dict(id=682, path=MEDIUM, sha256=MEDIUM_SHA),
                             dict(id=680, path=MUTE, sha256=MUTE_SHA)],
        preservation_scope='Only new PNG paths and appended table are returned; caller retains every existing PNG',
        runtime_or_numeric_changes=False, physical_tv_tested=False)
    return payloads, table, proof


def raster_assets():
    """Explicit offline rebuild; optional Pillow/Playwright only used here."""
    import io
    from PIL import Image
    from playwright.sync_api import sync_playwright

    if sha((ROOT/'ui-preview/tv-icons.svg').read_bytes()) != SYMBOL_SHA:
        raise ValueError('Pinned speaker symbol changed')
    if sha((ROOT/'scripts/preview_volume_wave_icons.py').read_bytes()) != PREVIEW_SOURCE_SHA:
        raise ValueError('Pinned approved preview source changed')
    medium = (V78/MEDIUM).read_bytes()
    if sha(medium) != MEDIUM_SHA or sha((V78/MUTE).read_bytes()) != MUTE_SHA:
        raise ValueError('Pinned existing volume/mute asset changed')
    png_format(medium)
    results, requests = {}, []
    with sync_playwright() as pw:
        browser = pw.chromium.launch(executable_path=CHROME, headless=True)
        try:
            page = browser.new_page(viewport=dict(width=100, height=100), device_scale_factor=8)
            page.on('request', lambda request: requests.append(request.url))
            page.route('**/*', lambda route: route.abort())
            for name in IDS:
                page.set_content('<html><body style="margin:0;background:transparent">'+source_svg(name)+'</body></html>')
                raw = page.screenshot(omit_background=True, animations='disabled')
                image = Image.open(io.BytesIO(raw)).convert('RGBA').resize((100, 100), Image.Resampling.LANCZOS)
                image = image.convert('RGB').quantize(colors=256, method=Image.Quantize.MEDIANCUT,
                                                     dither=Image.Dither.NONE)
                out = io.BytesIO()
                image.save(out, format='PNG', bits=8, compress_level=9)
                results[PATHS[name]] = out.getvalue()
                png_format(out.getvalue())
            if requests:
                raise ValueError('Unexpected external browser request')
        finally:
            browser.close()
    return results


if __name__ == '__main__':
    payloads, table, proof = expected_payloads((V78/IMAGE).read_bytes())
    rebuilt = raster_assets()
    if rebuilt != payloads:
        raise ValueError('Re-render differs from code-pinned native assets')
    print(json.dumps(dict(status='PASS', assets=len(payloads), table_sha256=sha(table),
                          rerender_byte_identical=True), indent=2))
