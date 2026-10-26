"""Reconstruct an immutable native MUF v8 overlay; no device access.

Windows performs full font/PNG reconstruction. Linux packaging uses separately
code-pinned records because FreeType/zlib builds need not emit identical PNGs.
"""
import hashlib
import json
import os
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'analiz/dosya-sistemleri-tam'
OUT=ROOT/'analiz/native-ui-candidate/v8'
ELF_REL='08_APP/bin/dvbt_board'
NUM_REL='08_APP/rc/rc/bin/Num_res.bin'
IMAGE_REL='08_APP/rc/rc/bin/Image_res.bin'

def sha(raw):return hashlib.sha256(raw).hexdigest()

def guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v8'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):raise ValueError('V8 output boundary')
    cursor=path
    while cursor!=ROOT:
        if cursor.is_symlink() or (hasattr(cursor,'is_junction') and cursor.is_junction()):raise ValueError('V8 aliased path')
        if cursor.is_file() and cursor.stat().st_nlink!=1:raise ValueError('V8 hardlinked file')
        cursor=cursor.parent

def append_images(raw,records):
    if len(raw)<56 or struct.unpack_from('<I',raw,28)[0]!=2180:raise ValueError('Expected V7 image table')
    if struct.unpack_from('<I',raw,4)[0]!=len(raw):raise ValueError('Image table size mismatch')
    position=56
    for _ in range(2180):
        length=struct.unpack_from('<I',raw,position)[0];position+=4
        if not length or position+length>len(raw) or raw[position+length-1]!=0:raise ValueError('Malformed inherited image path')
        position+=length
    if position!=len(raw):raise ValueError('Inherited image trailing bytes')
    if [r['id'] for r in records]!=list(range(2180,2180+len(records))):raise ValueError('Image IDs must append contiguously')
    output=bytearray(raw)
    for r in records:
        path=r['path']
        if not path.startswith('../rc/ARimages/Grundig/modern/') or '..' in path[3:].split('/') or '\\' in path or '\0' in path:
            raise ValueError('Invalid private resource path')
        payload=path.encode('utf-8')+b'\0';output.extend(struct.pack('<I',len(payload))+payload)
    struct.pack_into('<I',output,4,len(output));struct.pack_into('<I',output,16,(2180+len(records))*4)
    struct.pack_into('<I',output,28,2180+len(records))
    return bytes(output)

def expected_payloads():
    import build_native_ui_v7 as prior
    import native_ui_v8_home as home
    import native_ui_v8_channels as channels
    import native_ui_v8_settings as settings
    previous=prior.verified_records()
    payloads={'08_APP'+r['path']:r['candidate'].read_bytes() for r in previous}
    provenance={'08_APP'+r['path']:r['original_sha256'] for r in previous}
    num,elf=payloads[NUM_REL],payloads[ELF_REL];changes={}
    original_elf=elf
    for name,module in [('home',home),('channels',channels),('settings',settings)]:
        num,elf,payloads,proof=module.transform(num,elf,payloads)
        if 'code_records' not in proof:
            from build_native_volume_patch import elf_va_offset
            proof['code_records']=[dict(r,file_offset=elf_va_offset(elf,int(r['va'],16),4)) for r in proof['code_patches']]
        if name=='home':proof['scene_spec']=module.scene_spec(num)
        changes[name]=proof
    # IDs2186/2187 were reserved before Home foreground IDs2188..2223. Explicit
    # aliases fill those unused table slots; they add no widget or feature.
    aliases=[dict(id=i,path=channels.IMAGE_RECORDS[0]['path'],role='unused reserved alias') for i in (2186,2187)]
    image_records=sorted([r for p in changes.values() for r in p['image_records']]+aliases,key=lambda r:r['id'])
    if len({r['id'] for r in image_records})!=len(image_records):raise ValueError('Image ID collision')
    for r in image_records:
        relative='08_APP/rc/'+r['path'].removeprefix('../rc/')
        if relative not in payloads:raise ValueError('Private image missing from overlay')
    payloads[NUM_REL]=num;payloads[ELF_REL]=elf
    payloads[IMAGE_REL]=append_images(payloads[IMAGE_REL],image_records)
    offsets=[int(r['file_offset']) for p in changes.values() for r in p['code_records']]
    if len(offsets)!=len(set(offsets)):raise ValueError('Overlapping native patch sites')
    allowed={off+i for off in offsets for i in range(4)}
    from build_native_volume_patch import verify_allowlist
    verify_allowlist(original_elf,elf,allowed)
    for relative in payloads:
        if relative not in provenance:
            if (SOURCE/relative).exists():raise ValueError('New resource shadows an original file')
            provenance[relative]=None
    return payloads,provenance,dict(components=changes,image_records=image_records,
        appended_image_count=len(image_records),local_instruction_count=len(offsets),
        event_handlers_modified=False,channel_database_modified=False,global_color_table_modified=False,
        full_native_startup_verified=False,chrome_pixel_parity_verified=False,
        channel_name_bridge_installed=False)

def write_new(path,raw):
    guard(path);path.parent.mkdir(parents=True,exist_ok=True);guard(path)
    with path.open('xb') as stream:stream.write(raw);stream.flush();os.fsync(stream.fileno())
    if path.read_bytes()!=raw:raise ValueError('V8 persistence readback mismatch')

def verified_records():
    payloads,provenance,changes=expected_payloads();guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text(encoding='utf-8'))
    if manifest['changes']!=changes or len(manifest['records'])!=len(payloads):raise ValueError('V8 manifest differs from reconstruction')
    result=[];seen=set()
    for row in manifest['records']:
        relative=row['relative_path'];p=OUT/'overlay'/relative;guard(p)
        if relative in seen or relative not in payloads:raise ValueError('V8 file allowlist mismatch')
        seen.add(relative)
        if row['original_sha256']!=provenance[relative] or row['candidate_sha256']!=sha(payloads[relative]) or p.read_bytes()!=payloads[relative]:
            raise ValueError('V8 candidate or provenance mismatch')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,
                           original_sha256=provenance[relative],candidate_sha256=row['candidate_sha256']))
    return result

def verified_packaging_records():
    from native_ui_v8_pins import MANIFEST_SHA,RECORDS
    guard(OUT/'manifest.json');raw=(OUT/'manifest.json').read_bytes()
    if sha(raw)!=MANIFEST_SHA:raise ValueError('V8 manifest code pin mismatch')
    manifest=json.loads(raw)
    expected=[(r['relative_path'],r['original_sha256'],r['candidate_sha256'],r['bytes']) for r in manifest['records']]
    if expected!=list(RECORDS):raise ValueError('V8 records differ from code pins')
    result=[]
    for relative,original,candidate,size in RECORDS:
        p=OUT/'overlay'/relative;guard(p)
        if p.stat().st_size!=size or sha(p.read_bytes())!=candidate:raise ValueError('V8 packaging file code pin mismatch')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,
                           original_sha256=original,candidate_sha256=candidate))
    return result

def main():
    guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists():
        records=verified_records();verified_packaging_records()
        print(json.dumps(dict(status='verified_existing_v8',files=len(records))));return
    if OUT.exists() and any(OUT.iterdir()):raise FileExistsError('Refusing partial V8 overlay')
    payloads,provenance,changes=expected_payloads();records=[]
    for relative,raw in sorted(payloads.items()):
        write_new(OUT/'overlay'/relative,raw)
        records.append(dict(relative_path=relative,original_sha256=provenance[relative],candidate_sha256=sha(raw),bytes=len(raw)))
    manifest=dict(revision='v8',artifact='native_MUF_overlay',records=records,changes=changes,
                  television_tested=False,flash_ready=False,originals_preserved=True)
    raw=(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n').encode('utf-8');write_new(OUT/'manifest.json',raw)
    # Fixed Python literals are reviewed code pins, not executable firmware or
    # an editable manifest used as its own integrity authority.
    pins=ROOT/'scripts/native_ui_v8_pins.py'
    tuples=tuple((r['relative_path'],r['original_sha256'],r['candidate_sha256'],r['bytes']) for r in records)
    pin_source='# Generated after full Windows reconstruction; fixed offline artifact identities.\nMANIFEST_SHA = '+repr(sha(raw))+'\nRECORDS = '+repr(tuples)+'\n'
    if pins.exists():raise FileExistsError('Refusing existing V8 pin module')
    with pins.open('x',encoding='utf-8') as f:f.write(pin_source);f.flush();os.fsync(f.fileno())
    verified_packaging_records()
    print(json.dumps(dict(files=len(records),new_files=sum(r['original_sha256'] is None for r in records),
                          code_instructions=changes['local_instruction_count'],appended_images=changes['appended_image_count'],
                          elf_sha256=sha(payloads[ELF_REL]),num_sha256=sha(payloads[NUM_REL]))))

if __name__=='__main__':main()
