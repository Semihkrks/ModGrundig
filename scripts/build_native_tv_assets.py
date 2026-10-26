"""Build offline OEM-format resources from approved TV symbols; never firmware images.

python scripts/build_native_tv_assets.py prepare
node scripts/render_native_tv_assets.mjs
python scripts/build_native_tv_assets.py finalize
"""
from __future__ import annotations
import argparse
import hashlib
import json
import re
import shutil
import sys
import xml.etree.ElementTree as ET
from pathlib import Path
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from build_soft_ui_assets import CARDS, TABLE_SHA, specifications as base_specifications, table
from map_ui_asset_dependencies import geometry

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-ui-candidate/v1/assets'
ORIGINALS = ROOT / 'analiz/dosya-sistemleri-tam'
SYMBOLS = ROOT / 'ui-preview/tv-icons.svg'
NS = 'http://www.w3.org/2000/svg'
ET.register_namespace('', NS)
SYMBOL_MAP = dict(video='picture', sound='speaker', source='source', lock='lock', schedule='timer', settings='settings')
SHADOW_SHA = '9a095d761869c488870b5f8fd6d179a222e3293cd443f96fdbb43845b5c946f4'

def specifications():
    return base_specifications() + [('volume-shadow', 685, 0)]

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def guard(p, base, exists=False):
    p, base = Path(p), Path(base).absolute()
    if not p.resolve(strict=exists).is_relative_to(base):
        raise ValueError(f'Outside pinned boundary: {p}')
    return p

def write(path, text):
    guard(path, OUT)
    path.parent.mkdir(parents=True, exist_ok=True)
    guard(path, OUT)
    if path.exists() and path.stat().st_nlink > 1:
        raise ValueError('Refusing a hardlinked output')
    path.write_text(text, encoding='utf-8', newline='\n')

def json_write(path, data):
    write(path, json.dumps(data, ensure_ascii=False, indent=2) + '\n')

def approved_symbol(name, ink, x, y, side):
    root = ET.fromstring(SYMBOLS.read_text(encoding='utf-8'))
    found = [e for e in root if e.attrib.get('id') == 'icon-' + name]
    if len(found) != 1:
        raise ValueError(f'Missing approved symbol: {name}')
    sym = found[0]
    if sym.attrib.get('viewBox') != '0 0 32 32':
        raise ValueError('Unexpected symbol coordinates')
    allowed_tags = {'symbol','path','rect','circle','ellipse','g','line','polyline','polygon'}
    for element in sym.iter():
        if element.tag.rsplit('}',1)[-1] not in allowed_tags:
            raise ValueError('Only static local SVG geometry may be rasterized')
        for key, value in element.attrib.items():
            if key.lower().startswith('on') or 'href' in key or re.search(r'url\s*\(',value,re.I):
                raise ValueError('External or active SVG content is forbidden')
    attrs = {k: v for k, v in sym.attrib.items() if k not in ('id', 'viewBox')}
    group = ET.Element('g', attrs)
    group.extend(sym)
    body = ET.tostring(group, encoding='unicode').replace('currentColor', ink)
    return f'<svg x="{x}" y="{y}" width="{side}" height="{side}" viewBox="0 0 32 32">{body}</svg>'

def drawing(name, w, h, focus):
    # Native shelves are blue/dark. Preserve transparent icon silhouettes rather
    # than introducing white browser cards or low-contrast dark contours.
    if name in CARDS:
        body = approved_symbol(SYMBOL_MAP[name], '#48bfff' if focus else '#eef4fa', 27, 27, 136)
    elif name == 'volume-background':
        # Opaque P4 cannot encode transparent rounded corners. The surrounding
        # native widget remains unchanged; do not fake alpha in an opaque PNG.
        # The existing native progress widget draws the actual track. A baked
        # line would be stretched beneath the number and speaker as well.
        body = f'<rect width="{w}" height="{h}" fill="#f5f5f5"/>'
    elif name in ('volume-knob', 'volume-shadow'):
        # Parent authorized hiding the approved unwanted thumb after finding
        # four literal state bindings in VolumeControlFrame::OnCreate. This
        # changes a global resource; dynamically computed consumers remain unknown.
        body = f'<rect width="{w}" height="{h}" fill="#ffffff" fill-opacity="0"/>'
    elif name in ('volume', 'mute'):
        body = (f'<rect width="{w}" height="{h}" fill="#f5f5f5"/>' if name == 'volume' else
                f'<rect x="1" y="1" width="{w-2}" height="{h-2}" rx="24" fill="#f5f5f5"/>')
        body += approved_symbol('mute' if name == 'mute' else 'speaker', '#1687df', 23, (h-54)/2, 54)
    elif name.startswith('arc-'):
        body = approved_symbol('mute' if name == 'arc-mute' else 'speaker', '#f3f6fa', 16, 17, 54)
        if name != 'arc-mute':
            body += '<g fill="none" stroke="#f3f6fa" stroke-width="3" stroke-linecap="round"><path d="M107 44h24"/>'
            body += '<path d="M119 32v24"/>' if name == 'arc-up' else ''
            body += '</g>'
    else:
        raise ValueError(name)
    return f'<svg xmlns="{NS}" width="{w}" height="{h}" viewBox="0 0 {w} {h}">{body}</svg>\n'

def prepare():
    _, records = table()
    thumb_code = ROOT / 'analiz/native/ui-targeted/dvbt_board/00fb9780.c'
    if thumb_code.read_text(encoding='utf-8').count(',0x2a9);') != 4:
        raise ValueError('Transparent thumb requires re-review of its four literal OnCreate bindings')
    if thumb_code.read_text(encoding='utf-8').count(',0x2ad);') != 4:
        raise ValueError('Transparent shadow requires re-review of its four literal OnCreate bindings')
    # Original hashes were recorded before this new candidate existed. Reusing
    # their manifest as an additional read-only pin does not reuse old artwork.
    prior = json.loads((ROOT / 'ui-assets/manifest.json').read_text(encoding='utf-8'))
    pinned = {a['image_id']: a for a in prior['assets']}
    pinned[685] = {'original_sha256': SHADOW_SHA}
    assets = []
    for kind, rid, focus in specifications():
        rp = records[rid]['resource_path']
        if not rp.startswith('../rc/ARimages/'):
            raise ValueError('Unexpected OEM resource path')
        relative = Path('08_APP/rc') / rp.removeprefix('../rc/')
        original = guard(ORIGINALS / relative, ORIGINALS, True)
        if sha(original) != pinned[rid]['original_sha256']:
            raise ValueError('OEM input differs from preexisting hash record')
        g = geometry(original.read_bytes())
        with Image.open(original) as im:
            im.load()
            mode, alpha = im.mode, ('A' in im.getbands() or 'transparency' in im.info)
        key = kind + ('-focus' if focus else '-normal')
        preserved = False
        src, rendered = OUT / 'sources' / f'{key}.svg', OUT / 'rendered' / f'{key}.png'
        if not preserved:
            write(src, drawing(kind, g['width'], g['height'], bool(focus)))
        assets.append(dict(key=key, kind=kind, image_id=rid, focus_variant=bool(focus), resource_path=rp,
            original_path=original.relative_to(ROOT).as_posix(), original_sha256=sha(original),
            original_geometry=g, original_mode=mode, alpha_capability=alpha,
            action='preserve_original' if preserved else 'replace_asset',
            source=None if preserved else src.relative_to(ROOT).as_posix(),
            source_sha256=None if preserved else sha(src),
            rendered=None if preserved else rendered.relative_to(ROOT).as_posix(),
            candidate=(OUT / 'candidate' / relative).relative_to(ROOT).as_posix()))
    (OUT / 'rendered').mkdir(parents=True, exist_ok=True)
    json_write(OUT / 'build-plan.json', dict(schema_version=1, image_table_sha256=TABLE_SHA,
        previous_hash_manifest_sha256=sha(ROOT / 'ui-assets/manifest.json'),
        thumb_binding_code_path=thumb_code.relative_to(ROOT).as_posix(), thumb_binding_code_sha256=sha(thumb_code),
        approved_symbols_path=SYMBOLS.relative_to(ROOT).as_posix(), approved_symbols_sha256=sha(SYMBOLS), assets=assets))
    print('Prepared 20 native SVG drawings; white volume, transparent thumb and obsolete halo')

def validate_plan(plan):
    _, records = table()
    if plan['image_table_sha256'] != TABLE_SHA or plan['approved_symbols_sha256'] != sha(SYMBOLS):
        raise ValueError('Pinned source changed')
    thumb_code = ROOT / 'analiz/native/ui-targeted/dvbt_board/00fb9780.c'
    if plan['thumb_binding_code_path'] != thumb_code.relative_to(ROOT).as_posix() or sha(thumb_code) != plan['thumb_binding_code_sha256']:
        raise ValueError('Thumb usage evidence changed')
    expected = {rid: (kind, bool(focus)) for kind, rid, focus in specifications()}
    assets = plan['assets']
    if len(assets) != 20 or {a['image_id'] for a in assets} != set(expected):
        raise ValueError('Unexpected candidate set')
    for a in assets:
        kind, focus = expected[a['image_id']]
        key = kind + ('-focus' if focus else '-normal')
        rp = records[a['image_id']]['resource_path']
        relative = Path('08_APP/rc') / rp.removeprefix('../rc/')
        expected_original = (ORIGINALS / relative).relative_to(ROOT).as_posix()
        expected_output = (OUT / 'candidate' / relative).relative_to(ROOT).as_posix()
        if (a['kind'],a['key'],a['focus_variant'],a['resource_path'],a['original_path'],a['candidate']) != (kind,key,focus,rp,expected_original,expected_output):
            raise ValueError('Untrusted resource binding')
        original = guard(ROOT / a['original_path'], ORIGINALS, True)
        target = guard(ROOT / a['candidate'], OUT / 'candidate')
        if target.exists() and target.stat().st_nlink > 1:
            raise ValueError('Hardlinked target')
        if sha(original) != a['original_sha256'] or geometry(original.read_bytes()) != a['original_geometry']:
            raise ValueError('OEM resource changed')
        preserved = False
        if a['action'] != ('preserve_original' if preserved else 'replace_asset'):
            raise ValueError('Unexpected action')
        if not preserved:
            for field, sub, ext in [('source','sources','svg'),('rendered','rendered','png')]:
                p = OUT / sub / f'{key}.{ext}'
                if a[field] != p.relative_to(ROOT).as_posix():
                    raise ValueError('Unexpected render path')
                guard(p, OUT / sub, True)
            if sha(ROOT / a['source']) != a['source_sha256']:
                raise ValueError('SVG source changed')

def finalize():
    plan = json.loads((OUT / 'build-plan.json').read_text(encoding='utf-8'))
    validate_plan(plan)  # Full preflight before the first candidate write.
    for a in plan['assets']:
        original, target = ROOT / a['original_path'], ROOT / a['candidate']
        target.parent.mkdir(parents=True, exist_ok=True)
        guard(target, OUT / 'candidate')
        if a['action'] == 'preserve_original':
            shutil.copyfile(original, target)
        else:
            with Image.open(ROOT / a['rendered']) as im:
                im.load()
                image = im.convert('RGBA')
            g, mode = a['original_geometry'], a['original_mode']
            if image.size != (g['width'],g['height']):
                raise ValueError('Render dimensions differ')
            if mode == 'P':
                if not a['alpha_capability']:
                    base = Image.new('RGBA',image.size,'#f5f5f5')
                    base.alpha_composite(image)
                    image = base.convert('RGB')
                method = Image.Quantize.FASTOCTREE if a['alpha_capability'] else Image.Quantize.MEDIANCUT
                image = image.quantize(colors=1 << g['bit_depth'], method=method, dither=Image.Dither.NONE)
                image.save(target,format='PNG',bits=g['bit_depth'],compress_level=9)
            else:
                image.convert(mode).save(target,format='PNG',compress_level=9)
        cg = geometry(target.read_bytes())
        with Image.open(target) as im:
            im.load()
            alpha = 'A' in im.getbands() or 'transparency' in im.info
            if im.mode != a['original_mode'] or alpha != a['alpha_capability']:
                raise ValueError('Pixel mode/alpha mismatch')
            rgba = im.convert('RGBA')
            a['alpha_extrema'] = rgba.getchannel('A').getextrema()
        for field in ('width','height','color_type','bit_depth','interlace'):
            if cg[field] != a['original_geometry'][field]:
                raise ValueError(f'PNG invariant mismatch: {field}')
        if cg['chunk_crc_errors'] or not cg['iend_present'] or cg['trailing_bytes']:
            raise ValueError('Invalid PNG container')
        if sha(original) != a['original_sha256']:
            raise ValueError('OEM changed during build')
        a.update(candidate_sha256=sha(target), candidate_bytes=target.stat().st_size,
                 candidate_geometry=cg, decoded_pixels_verified=True)
    plan.update(status='offline_native_resource_candidate_not_installable', firmware_repacked=False,
        original_files_changed=False, resource_tables_changed=False, television_tested=False,
        preserved_resource_ids=[], replaced_count=20, verified_count=20,
        volume_theme='approved_soft_white_opaque_png_background_blue_speaker',
        baked_volume_track=False,
        thumb_hidden=True, thumb_evidence=dict(function='VolumeControlFrame::OnCreate', address='0x00fb9780',
            code_path='analiz/native/ui-targeted/dvbt_board/00fb9780.c', code_lines=[650,651,652,653],
            literal_state_binding_count=4, resource_id=681, dynamically_computed_consumers='unresolved'),
        shadow_hidden=True, shadow_evidence=dict(function='VolumeControlFrame::OnCreate', address='0x00fb9780',
            code_path='analiz/native/ui-targeted/dvbt_board/00fb9780.c', code_lines=[118,119,120,121],
            literal_state_binding_count=4, resource_id=685, dynamically_computed_consumers='unresolved'),
        native_render_evidence=dict(function='MResourceManager::RenderImageToSurface',address='0x2e23e684',
            code_path='analiz/native/libmuf/2e23e684.c', target_rectangle_copy='param_3 width/height copied; scaling/compositing path has indirect DirectFB calls',
            capsule_alpha_verified=False),
        limitations=['Approved SVG geometry rasterized into existing native slots; browser and TV are not pixel-identical.',
            'Native menu blue/dark surfaces retained: normal icons use light ink, focus uses cyan.',
            'Volume P4 background is soft white but remains opaque rectangular PNG; native borders/widget clipping need separate proof for rounded capsule parity.',
            'Global thumb 681 is fully transparent P8/tRNS after four literal OnCreate bindings; dynamically computed consumers remain unresolved.',
            'Old volume halo 685 is transparent RGBA after four literal OnCreate bindings; native shadow widget and memory allocation remain.',
            'ARC LA8 remains monochrome. Font, text color, Num resources and widget layout untouched.'])
    json_write(OUT / 'manifest.json', plan)
    print('Verified 20 replacement PNGs; white volume and transparent thumb/halo; no firmware repack')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('step', choices=['prepare','finalize'])
    globals()[parser.parse_args().step]()
