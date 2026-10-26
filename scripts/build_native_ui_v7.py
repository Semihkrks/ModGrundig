"""Immutable spacing correction over v6; no package or device access."""
import hashlib
import json
import os
from pathlib import Path
import struct
import build_native_ui_v6 as v6

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v7'

def sha(data):return hashlib.sha256(data).hexdigest()

def expected_payloads():
    rows=v6.verified_records()
    payloads={'08_APP'+r['path']:r['candidate'].read_bytes() for r in rows}
    raw=payloads['08_APP/rc/rc/bin/Num_res.bin']
    out=bytearray(raw);offset=56+4*0x99a
    if struct.unpack_from('<I',raw,offset)[0]!=106:raise ValueError('Unexpected prior digit y')
    struct.pack_into('<I',out,offset,118)
    payloads['08_APP/rc/rc/bin/Num_res.bin']=bytes(out)
    return payloads

def guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v7'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):raise ValueError('V7 output boundary')
    cursor=path
    while cursor!=ROOT:
        if cursor.is_symlink() or (hasattr(cursor,'is_junction') and cursor.is_junction()):raise ValueError('Aliased V7 output')
        if cursor.is_file() and cursor.stat().st_nlink!=1:raise ValueError('Hardlinked V7 output')
        cursor=cursor.parent

def verified_records():
    payloads=expected_payloads();guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text())
    prior={r['relative_path']:r for r in json.loads((v6.OUT/'manifest.json').read_text())['records']}
    if len(manifest['records'])!=24 or {r['relative_path'] for r in manifest['records']}!=payloads.keys():raise ValueError('Unexpected V7 records')
    result=[]
    for row in manifest['records']:
        relative=row['relative_path'];p=OUT/'overlay'/relative;guard(p)
        if row['original_sha256']!=prior[relative]['original_sha256']:raise ValueError('V7 original provenance mismatch')
        if sha(payloads[relative])!=row['candidate_sha256'] or p.read_bytes()!=payloads[relative]:raise ValueError('V7 output mismatch')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,candidate_sha256=row['candidate_sha256'],original_sha256=row['original_sha256']))
    return result

def main():
    guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists():print(json.dumps({'status':'verified_existing_v7','files':len(verified_records())}));return
    if OUT.exists() and any(OUT.iterdir()):raise FileExistsError('Refusing partial V7 directory')
    payloads=expected_payloads()
    prior={r['relative_path']:r for r in json.loads((v6.OUT/'manifest.json').read_text())['records']}
    records=[]
    for relative,data in payloads.items():
        p=OUT/'overlay'/relative;guard(p);p.parent.mkdir(parents=True,exist_ok=True)
        with p.open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())
        if p.read_bytes()!=data:raise ValueError('V7 readback failed')
        records.append(dict(relative_path=relative,original_sha256=prior[relative]['original_sha256'],candidate_sha256=sha(data),bytes=len(data)))
    manifest=dict(revision='v7',records=records,num_changes=[dict(id=0x99a,old=106,new=118)],
                  description='Digit top12px lower; proposed rehost name field moves16px lower to preserve separate widget bounds',
                  new_name_native_bridge_installed=False,television_tested=False,firmware_repacked=False,flash_ready=False)
    with (OUT/'manifest.json').open('x',encoding='utf-8') as f:json.dump(manifest,f,indent=2);f.flush();os.fsync(f.fileno())
    print(json.dumps({'files':len(verified_records()),'num_sha256':sha(payloads['08_APP/rc/rc/bin/Num_res.bin'])}))

if __name__=='__main__':main()
