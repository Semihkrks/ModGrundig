"""Home-only native MUF resource/argument transform over the v7 candidate.

No HTML, native navigation replacement, global color mutation or device access.
Private Image IDs prevent whitening other consumers of OEM Home resources.
"""
from __future__ import annotations
import hashlib
import io
import json
from pathlib import Path
import struct
from PIL import Image, ImageDraw
from build_native_volume_patch import elf_va_offset

ROOT=Path(__file__).resolve().parents[1]
PLAN=ROOT/'analiz/native-ui-port-v8/home-plan.json'
PLAN_SHA='24df71e8ce0bfcaa9d14bc879ab4d72a6714b09c571e2b629a20cca76b3256e4'
SOURCE=ROOT/'analiz/dosya-sistemleri-tam'
ICON_MANIFEST=ROOT/'analiz/native-ui-port-v8/approved-icons/manifest.json'
ICON_MANIFEST_SHA='290faf5f385bfbe25364fed74b0ed56731c0cecd15adadc0985574998002abd7'
FOCUSED={951,953,955,960,962,964,966,968,970,972,974,976,978,981,982,984,986,988}

def sha(data):return hashlib.sha256(data).hexdigest()

def plan():
    raw=PLAN.read_bytes()
    if sha(raw)!=PLAN_SHA:raise ValueError('Untrusted Home patch plan')
    return json.loads(raw)

def _source(row):
    p=SOURCE/row['source_relative']
    if not p.resolve().is_relative_to(SOURCE.resolve()) or p.is_symlink():raise ValueError('Home source boundary')
    raw=p.read_bytes()
    if sha(raw)!=row['source_sha256']:raise ValueError('Home original PNG mismatch')
    return raw

def approved_icons():
    raw=ICON_MANIFEST.read_bytes()
    if sha(raw)!=ICON_MANIFEST_SHA:raise ValueError('Approved icon manifest changed')
    data=json.loads(raw)
    if sha((ROOT/'ui-preview/tv-icons.svg').read_bytes())!=data['svg_sha256']:
        raise ValueError('Approved SVG source changed')
    return {r['old_id']:r for r in data['records']}

def _image(row,rows,assets):
    source=_source(row);original=Image.open(io.BytesIO(source));old=row['old_id']
    if old==991:
        im=Image.new('RGBA',original.size)
        for y in range(im.height):
            t=y/max(1,im.height-1);im.putpixel((0,y),(round(250-10*t),round(252-8*t),round(253-6*t),246))
    elif old in (946,947,948):
        im=Image.new('RGBA',original.size,(246,249,252,255));d=ImageDraw.Draw(im)
        focus=old==947
        d.rounded_rectangle((1,1,im.width-2,im.height-2),radius=14,
                            fill=(220,239,255,255) if focus else (246,249,252,255),
                            outline=(20,143,240,255) if focus else (220,228,237,255),width=2 if focus else 1)
    else:
        approved=approved_icons()
        if old in approved:
            record=approved[old];path=ROOT/record['png']
            if not path.resolve().is_relative_to((ICON_MANIFEST.parent/'rendered').resolve()) or path.is_symlink():
                raise ValueError('Approved icon path escaped')
            raw=path.read_bytes()
            if sha(raw)!=record['png_sha256']:raise ValueError('Approved icon pixels changed')
            im=Image.open(io.BytesIO(raw)).convert('RGBA')
            if sha(im.tobytes())!=record['rgba_sha256']:raise ValueError('Approved RGBA identity mismatch')
        else:
            # Preserve the OEM silhouette for families without an approved
            # active Chrome counterpart; never invent a new glyph.
            ink=(5,111,194,255) if old in FOCUSED else (32,52,71,255)
            im=Image.new('RGBA',original.size,ink)
            im.putalpha(original.convert('RGBA').getchannel('A'))
    # Preserve original IHDR mode, bit depth and dimensions; private P8 cards stay opaque.
    if original.mode=='P':im=im.convert('RGB').quantize(colors=256)
    elif original.mode=='LA':im=im.convert('LA')
    elif original.mode!='RGBA':raise ValueError('Unexpected Home PNG mode')
    output=io.BytesIO();im.save(output,format='PNG',bits=source[24],optimize=True);raw=output.getvalue()
    if raw[16:26]!=source[16:26]:raise ValueError('Home PNG IHDR changed')
    return raw

def transform(num:bytes,elf:bytes,assets:dict[str,bytes]):
    """Return independent native candidate values; originals/inherited assets stay untouched."""
    p=plan();changed=bytearray(elf);updated=dict(assets)
    for row in p['code_patches']:
        va=int(row['va'],16);off=elf_va_offset(elf,va,4);old=int(row['old_word'],16)
        if struct.unpack_from('<I',elf,off)[0]!=old:raise ValueError(f'Home instruction mismatch at {va:#x}')
        struct.pack_into('<I',changed,off,int(row['new_word'],16))
    rows={r['old_id']:r for r in p['assets']};records=[]
    for row in p['assets']:
        if row['relative_path'] in updated:raise ValueError('Home private path collision')
        raw=_image(row,rows,assets);updated[row['relative_path']]=raw
        records.append(dict(row,candidate_sha256=sha(raw),bytes=len(raw),original_sha256=None))
    if '08_APP/bin/dvbt_board' in updated:updated['08_APP/bin/dvbt_board']=bytes(changed)
    if '08_APP/rc/rc/bin/Num_res.bin' in updated:updated['08_APP/rc/rc/bin/Num_res.bin']=num
    return num,bytes(changed),updated,dict(code_patches=p['code_patches'],num_patches=[],
        image_records=[dict(id=r['id'],path=r['path']) for r in records],assets=records,
        geometry_policy=p['geometry_policy'],native_navigation_modified=False,
        global_colors_modified=False,private_images=40,runtime_text_updates_verified=False,
        approved_icon_source='ui-preview/tv-icons.svg',approved_icon_manifest_sha256=ICON_MANIFEST_SHA,
        approved_active_icons=22,oem_silhouette_icons=14)

def scene_spec(num):
    """Retained OnCreate coordinates, not a final runtime Home screen reconstruction."""
    p=plan();source=ROOT/p['source_widgets'];raw=source.read_bytes()
    if sha(raw)!=p['source_widgets_sha256']:raise ValueError('Untrusted Home widget trace')
    widgets=json.loads(raw);idmap={r['old_id']:r['id'] for r in p['assets']}
    allocations={w['allocation']:w['stored_fields'][0]['field'] for w in widgets if w['stored_fields']}
    result=[]
    for w in widgets:
        rect=w.get('rectangle',{});values=rect.get('xywh',[])
        if len(values)!=4:continue
        coords=[struct.unpack_from('<I',num,56+4*int(v[4:-1]))[0] if isinstance(v,str) and v.startswith('num[') else v for v in values]
        field=w['stored_fields'][0]['field'] if w['stored_fields'] else w['allocation']
        result.append(dict(field=field,
            constructor=w['constructor'],constructor_va=w['constructor_va'],rect=coords,
            parent=allocations.get(w['parent'],w['parent']),images=[2181,2182] if field=='this+0x204' else [idmap.get(i,i) for i in w.get('image_ids',[])],
            foregrounds=[[idmap.get(i,i) for i in group] for group in w.get('foreground_ids',[])],labels=w.get('labels',[])))
    return dict(basis='retained_OnCreate_parent_local_coordinates',runtime_position_verified=False,
                source=p['source_widgets'],widgets=result)
