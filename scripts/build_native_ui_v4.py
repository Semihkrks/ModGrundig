"""Offline v4 overlay: local volume typography and larger approved TV icons.

No firmware package, boot code, device access, or global table/font replacement.
The original 22-file v3 overlay is verified and copied to a separate directory.
"""
from __future__ import annotations
import hashlib
import io
import json
import os
from pathlib import Path
import struct
from PIL import Image, ImageFont
import build_native_ui_v3 as v3
import build_native_volume_patch as volume
from build_native_tv_assets import approved_symbol
from build_soft_ui_assets import table
from map_ui_asset_dependencies import geometry

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v4'
SYMBOL_SHA='b2f3a2e3392392f1aa4acf207e4c28efa93f9db9c1803a589b3574fc709744bc'
FONT_REL='08_APP/rc/font/Lucida Sans Bold.ttf'
FONT_SHA='347e36d73e5db9b791c4ad385e391bf6fceeb0e17e830634d5fe35ca7da5f0bb'
FONT_VAS=(0xfbbe18,0xfbbe28,0xfbbe38,0xfbbe48)
COLOR_VAS=(0xfbbc30,0xfbbc50,0xfbbc70,0xfbbc90)
ICON_PATHS={680:'08_APP/rc/ARimages/Grundig/volume/mute_icon.png',
            682:'08_APP/rc/ARimages/Grundig/volume/volume_icon.png'}
ICON_SHAS={680:'703208975d4b1424f003a2998e89c164116968e47e6d05dac6551e3f38698696',
           682:'aa1c3918d73338f4065285fbc634fe56169dcc7019af99753b907a897796b099'}
CHROME='C:/Program Files/Google/Chrome/Application/chrome.exe'

def sha(data):return hashlib.sha256(data).hexdigest()

def guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v4'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V4 output escapes pinned directory')
    current=path
    while current!=ROOT:
        if current.is_symlink() or (hasattr(current,'is_junction') and current.is_junction()):
            raise ValueError('Symlink/junction in V4 output')
        if current.exists() and current.is_file() and current.stat().st_nlink!=1:
            raise ValueError('Hardlinked V4 output')
        current=current.parent

def write_new(path,payload):
    """Exclusive output plus flush, so interrupted writes cannot pass verification."""
    guard(path)
    path.parent.mkdir(parents=True,exist_ok=True)
    guard(path)
    with path.open('xb') as stream:
        stream.write(payload)
        stream.flush()
        os.fsync(stream.fileno())
    if path.read_bytes()!=payload:raise ValueError('Persisted output differs from written bytes')

def construct(num,elf):
    new_num,base,previous=v3.construct(num,elf)
    result=bytearray(base)
    records=[]
    for vas,old,new,role in ((FONT_VAS,0x240204ae,0x240204af,'volume number font ID'),
                             (COLOR_VAS,0x24040025,0x24040000,'volume number color ID')):
        for va in vas:
            off=volume.elf_va_offset(elf,va,4)
            if struct.unpack_from('<I',base,off)[0]!=old:
                raise ValueError('Unexpected local volume instruction')
            struct.pack_into('<I',result,off,new)
            records.append(dict(va=hex(va),file_offset=off,old_word=hex(old),new_word=hex(new),role=role))
    allowed={r['file_offset']+i for r in records for i in range(4)}
    volume.verify_allowlist(base,bytes(result),allowed)
    return new_num,bytes(result),dict(inherited_v3=previous,code_records=records)

def source_svg(rid,width,height):
    if sha((ROOT/'ui-preview/tv-icons.svg').read_bytes())!=SYMBOL_SHA:
        raise ValueError('Approved symbol source changed')
    background=(f'<rect width="{width}" height="{height}" fill="#f5f5f5"/>' if rid==682 else
                f'<rect x="1" y="1" width="{width-2}" height="{height-2}" rx="24" fill="#f5f5f5"/>')
    symbol=approved_symbol('speaker' if rid==682 else 'mute','#1687df',(width-80)/2,(height-80)/2,80)
    return f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}">{background}{symbol}</svg>\n'

def raster_icons():
    """Rasterize only validated local geometry at 8x, then quantize OEM P8."""
    from playwright.sync_api import sync_playwright
    results={}
    with sync_playwright() as pw:
        browser=pw.chromium.launch(executable_path=CHROME,headless=True)
        try:
            page=browser.new_page(device_scale_factor=8)
            page.route('**/*',lambda route:route.abort())
            for rid,relative in ICON_PATHS.items():
                original=(volume.SOURCE/relative).read_bytes()
                g=geometry(original)
                with Image.open(io.BytesIO(original)) as im:
                    if im.mode!='P' or g['bit_depth']!=8:
                        raise ValueError('Unexpected OEM palette format')
                    alpha='transparency' in im.info
                svg=source_svg(rid,g['width'],g['height'])
                page.set_viewport_size(dict(width=g['width'],height=g['height']))
                page.set_content('<html><body style="margin:0;background:transparent">'+svg+'</body></html>')
                raw=page.screenshot(omit_background=True,animations='disabled')
                image=Image.open(io.BytesIO(raw)).convert('RGBA').resize((g['width'],g['height']),Image.Resampling.LANCZOS)
                if not alpha:image=image.convert('RGB')
                image=image.quantize(colors=256,method=Image.Quantize.FASTOCTREE if alpha else Image.Quantize.MEDIANCUT,dither=Image.Dither.NONE)
                out=io.BytesIO();image.save(out,format='PNG',bits=8,compress_level=9)
                payload=out.getvalue();cg=geometry(payload)
                for key in ('width','height','bit_depth','color_type','interlace'):
                    if cg[key]!=g[key]:raise ValueError('OEM PNG geometry mismatch')
                if cg['chunk_crc_errors'] or not cg['iend_present'] or cg['trailing_bytes']:
                    raise ValueError('Invalid candidate PNG')
                results[rid]=dict(payload=payload,source=svg,browser=browser.version,
                                  geometry=cg,alpha_capability=alpha,glyph_bbox=glyph_bbox(payload))
        finally:browser.close()
    return results

def glyph_bbox(payload):
    with Image.open(io.BytesIO(payload)) as im:
        rgb=im.convert('RGBA').convert('RGB')
        mask=Image.new('1',im.size)
        mask.putdata([b>r+30 and b>g+10 for r,g,b in rgb.get_flattened_data()])
        box=mask.getbbox()
        if box is None:raise ValueError('Missing blue symbol')
        return list(box)

def font_metrics():
    _,resources=table()
    if resources[0x4af]['resource_path']!='../rc/font/Lucida Sans Bold.ttf':
        raise ValueError('Existing native font resource ID changed')
    raw=(volume.SOURCE/FONT_REL).read_bytes()
    if sha(raw)!=FONT_SHA:raise ValueError('Original Lucida font changed')
    f=ImageFont.truetype(io.BytesIO(raw),36)
    widths={s:round(f.getlength(s),3) for s in ('0','35','100')}
    if widths['100']>76:raise ValueError('Volume number overflows widget')
    return dict(resource_id=1199,resource_id_hex='0x4af',path=FONT_REL,sha256=FONT_SHA,
                pixel_size=36,measured_widths=widths,widget_width=76,
                source='Pillow FreeType metrics; target DirectFB rasterization remains unverified')

def expected_payloads(icons):
    prior=v3.verified_records()
    num=(volume.SOURCE/volume.NUM_REL).read_bytes();elf=(volume.SOURCE/volume.ELF_REL).read_bytes()
    new_num,new_elf,proof=construct(num,elf)
    payloads={'08_APP'+row['path']:row['candidate'].read_bytes() for row in prior}
    payloads[volume.ELF_REL]=new_elf
    if payloads[volume.NUM_REL]!=new_num:raise ValueError('V3 Num changed')
    for rid,relative in ICON_PATHS.items():payloads[relative]=icons[rid]['payload']
    return payloads,proof

def verified_records(rebuild_icons=False):
    guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text())
    if rebuild_icons:
        icons=raster_icons()
    else:
        # These code-pinned hashes came from the reviewed deterministic SVG build,
        # not from the editable manifest. Runtime verification needs no browser.
        icons={rid:dict(payload=(OUT/'overlay'/relative).read_bytes()) for rid,relative in ICON_PATHS.items()}
    if any(sha(icons[rid]['payload'])!=ICON_SHAS[rid] for rid in ICON_PATHS):
        raise ValueError('V4 icon differs from pinned raster output')
    payloads,_=expected_payloads(icons)
    rows=manifest['records']
    if len(rows)!=22 or {r['relative_path'] for r in rows}!=payloads.keys():
        raise ValueError('Unexpected v4 overlay set')
    result=[]
    for row in rows:
        relative=row['relative_path'];target=OUT/'overlay'/relative;guard(target)
        original=(volume.SOURCE/relative).read_bytes()
        if (row['original_sha256']!=sha(original) or row['candidate_sha256']!=sha(payloads[relative]) or
            target.read_bytes()!=payloads[relative]):raise ValueError('V4 overlay differs from reconstructed inputs')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=target,
                           original_sha256=row['original_sha256'],candidate_sha256=row['candidate_sha256']))
    return result

def build():
    guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists():
        return dict(status='verified_existing_v4',files=len(verified_records()))
    if OUT.exists() and any(p.is_file() for p in OUT.rglob('*')):raise FileExistsError('Refusing partial/existing V4 files')
    icons=raster_icons();payloads,proof=expected_payloads(icons);metrics=font_metrics()
    for relative in payloads:guard(OUT/'overlay'/relative)
    records=[]
    for relative,payload in payloads.items():
        target=OUT/'overlay'/relative
        write_new(target,payload)
        records.append(dict(relative_path=relative,original_sha256=sha((volume.SOURCE/relative).read_bytes()),
                            candidate_sha256=sha(payload),bytes=len(payload),
                            changed_from_v3=payload!=(v3.OUT/'overlay'/relative).read_bytes()))
    asset_rows=[]
    for rid,icon in icons.items():
        source=OUT/'sources'/f'{rid}.svg'
        write_new(source,icon['source'].encode('utf-8'))
        asset_rows.append(dict(image_id=rid,path=ICON_PATHS[rid],sha256=sha(icon['payload']),
                               glyph_bbox=icon['glyph_bbox'],source_sha256=sha(icon['source'].encode()),
                               geometry=icon['geometry'],alpha_capability=icon['alpha_capability'],
                               rasterizer=icon['browser'],svg_side=80,previous_svg_side=54))
    proof.update(revision='v4',status='offline_visual_overlay_not_flashable',records=records,
                 icons=asset_rows,font=metrics,approved_symbols_sha256=SYMBOL_SHA,
                 changed_from_v3_files=3,television_tested=False,flash_ready=False,firmware_repacked=False,
                 limits=['Eight local argument instructions and two volume PNGs changed from v3.',
                         'Other menu fonts/icons and native background geometry are inherited unchanged.',
                         'Raster assets and FreeType metrics are verified; full application/TV output is not.'])
    write_new(OUT/'manifest.json',json.dumps(proof,indent=2).encode('utf-8'))
    verified_records()
    return dict(status=proof['status'],files=len(records),changed_from_v3_files=3,
                font_resource_id=1199,volume_icon_source_side=80)

def recover_zero_outputs():
    """Recover only the precisely known all-zero outputs of an interrupted build.

    Any nonzero file or unknown path stops recovery before the first removal.
    Original and v3 trees are never mutation targets.
    """
    guard(OUT/'manifest.json')
    expected={OUT/'overlay'/('08_APP'+r['path']) for r in v3.verified_records()}
    expected.update((OUT/'manifest.json',*(OUT/'sources'/f'{rid}.svg' for rid in ICON_PATHS)))
    files={p for p in OUT.rglob('*') if p.is_file()}
    if files!=expected:raise ValueError('Recovery requires the exact known interrupted output set')
    audit=[]
    for p in sorted(files):
        guard(p)
        raw=p.read_bytes()
        if not raw or raw.count(b'\0')!=len(raw):raise ValueError('Recovery refuses nonzero or empty output')
        audit.append(dict(path=p.relative_to(OUT).as_posix(),bytes=len(raw),sha256=sha(raw)))
    for p in sorted(files):
        guard(p)
        if any(p.read_bytes()):raise ValueError('Recovery source changed during validation')
        p.unlink()
    result=build()
    write_new(OUT/'interruption-recovery.json',json.dumps(dict(
        reason='Persisted interrupted v4 outputs contained only NUL bytes; independently reconstructed from pinned original/v3 inputs.',
        replaced_zero_outputs=audit,original_or_v3_files_modified=False),indent=2).encode('utf-8'))
    return result

if __name__=='__main__':
    import argparse
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--recover-zero-outputs',action='store_true')
    args=parser.parse_args()
    print(json.dumps(recover_zero_outputs() if args.recover_zero_outputs else build()))
