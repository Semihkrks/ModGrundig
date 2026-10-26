"""V7 TV candidate: volume and numeric entry only; all menu assets original."""
import hashlib
import json
import os
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v7-tv'
SOURCE=ROOT/'analiz/dosya-sistemleri-tam'
MENU_PREFIX='/rc/ARimages/Grundig/half/homeScreen/icons/'

def sha(raw):return hashlib.sha256(raw).hexdigest()

def guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v7-tv'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):raise ValueError('V7 TV output boundary')
    cursor=path
    while cursor!=ROOT:
        if cursor.is_symlink() or (hasattr(cursor,'is_junction') and cursor.is_junction()):raise ValueError('Aliased V7 TV path')
        if cursor.is_file() and cursor.stat().st_nlink!=1:raise ValueError('Hardlinked V7 TV output')
        cursor=cursor.parent

def expected_payloads():
    from build_native_ui_v7 import verified_records as previous_records
    rows=previous_records();kept=[];excluded=[]
    for row in rows:
        if row['path'].startswith(MENU_PREFIX):
            relative='08_APP'+row['path']
            if sha((SOURCE/relative).read_bytes())!=row['original_sha256']:raise ValueError('Original menu icon changed')
            excluded.append(dict(path=relative,original_sha256=row['original_sha256']))
        else:kept.append(row)
    if len(kept)!=12 or len(excluded)!=12:raise ValueError('Unexpected V7 TV scope')
    payloads={'08_APP'+r['path']:r['candidate'].read_bytes() for r in kept}
    provenance={'08_APP'+r['path']:r['original_sha256'] for r in kept}
    elf=payloads['08_APP/bin/dvbt_board'];original=(SOURCE/'08_APP/bin/dvbt_board').read_bytes()
    words=[i for i in range(0,len(elf)-3,4) if elf[i:i+4]!=original[i:i+4]]
    return payloads,provenance,dict(profile='v7-volume-numeric-only',
        original_menu_icons=excluded,menu_code_modified=False,menu_geometry_modified=False,
        channel_list_modified=False,program_info_modified=False,settings_modified=False,
        new_name_widget_installed=False,elf_changed_words_from_original=len(words),
        source_revision='v7',active_overlay_files=12)

def write_new(path,raw):
    guard(path);path.parent.mkdir(parents=True,exist_ok=True);guard(path)
    with path.open('xb') as f:f.write(raw);f.flush();os.fsync(f.fileno())
    if path.read_bytes()!=raw:raise ValueError('V7 TV write readback mismatch')

def verified_records():
    payloads,provenance,scope=expected_payloads();guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text(encoding='utf-8'))
    if manifest['scope']!=scope or len(manifest['records'])!=12:raise ValueError('V7 TV manifest scope changed')
    result=[];seen=set()
    for row in manifest['records']:
        relative=row['relative_path'];p=OUT/'overlay'/relative;guard(p)
        if relative in seen or relative not in payloads:raise ValueError('V7 TV path allowlist changed')
        seen.add(relative)
        if row['original_sha256']!=provenance[relative] or row['candidate_sha256']!=sha(payloads[relative]) or p.read_bytes()!=payloads[relative]:
            raise ValueError('V7 TV bytes/provenance changed')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,
                           original_sha256=provenance[relative],candidate_sha256=row['candidate_sha256']))
    return result

def verified_packaging_records():
    from native_ui_v7_tv_pins import MANIFEST_SHA,RECORDS
    guard(OUT/'manifest.json');raw=(OUT/'manifest.json').read_bytes()
    if sha(raw)!=MANIFEST_SHA:raise ValueError('V7 TV manifest code pin mismatch')
    manifest=json.loads(raw)
    if [(r['relative_path'],r['original_sha256'],r['candidate_sha256'],r['bytes']) for r in manifest['records']]!=list(RECORDS):
        raise ValueError('V7 TV record code pins mismatch')
    result=[]
    for relative,original,candidate,size in RECORDS:
        p=OUT/'overlay'/relative;guard(p)
        if p.stat().st_size!=size or sha(p.read_bytes())!=candidate:raise ValueError('V7 TV candidate code pin mismatch')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,
                           original_sha256=original,candidate_sha256=candidate))
    return result

def main():
    guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists():
        records=verified_records();verified_packaging_records();print(json.dumps(dict(status='verified_v7_tv',files=len(records))));return
    if OUT.exists() and any(OUT.iterdir()):raise FileExistsError('Refusing partial V7 TV directory')
    payloads,provenance,scope=expected_payloads();records=[]
    for relative,raw in sorted(payloads.items()):
        write_new(OUT/'overlay'/relative,raw)
        records.append(dict(relative_path=relative,original_sha256=provenance[relative],candidate_sha256=sha(raw),bytes=len(raw)))
    raw=(json.dumps(dict(revision='v7-tv',scope=scope,records=records,television_tested=False,flash_ready=False),ensure_ascii=False,indent=2)+'\n').encode('utf-8')
    write_new(OUT/'manifest.json',raw)
    pins=ROOT/'scripts/native_ui_v7_tv_pins.py'
    tuples=tuple((r['relative_path'],r['original_sha256'],r['candidate_sha256'],r['bytes']) for r in records)
    text='# Fixed V7 volume/numeric candidate identities.\nMANIFEST_SHA = '+repr(sha(raw))+'\nRECORDS = '+repr(tuples)+'\n'
    with pins.open('x',encoding='utf-8') as f:f.write(text);f.flush();os.fsync(f.fileno())
    verified_packaging_records();print(json.dumps(dict(files=len(records),new_files=sum(r['original_sha256'] is None for r in records),scope=scope)))

if __name__=='__main__':main()
