"""Bounded offline extension of v2: native number panel and volume capsule.

No new firmware widgets/services, no boot script, and no TV access. Decoder
evidence proves PNG parsing only; it does not prove DirectFB/device rendering.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import build_native_volume_patch as volume

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v3'
BASE_ASSETS=ROOT/'analiz/native-ui-candidate/v2/package/assets-manifest.json'
BASE_ASSETS_SHA='c60a8bb39168cc3e984ce9c1dbf630d6bc60ab9eb621b70bb3deccfaef184e8d'
CAPSULE_SHA='db95b29b413e60c2e7d6a9de3497cecd417c3edf5dc3224820e8da250b32b7f6'
NUM_PATCHES=(
    (0x98f,80,176),(0x993,80,112),(0x994,1920,310),
    (0x995,0,1538),(0x996,0,64),(0x997,70,72),
    (0x998,200,254),(0x999,860,1566),(0x99a,5,84),
)
COLOR_PATCHES=((0x896100,18,94),(0x896120,18,94),(0x896140,18,94),(0x896160,18,94),
               (0x896548,94,0),(0x896568,94,0),(0x896588,94,0),(0x8965a8,94,0))
BORDER_VA=0xfbd38c


def sha(data):return hashlib.sha256(data).hexdigest()


def output_guard(path):
    boundary=ROOT.resolve()/'analiz/native-ui-candidate/v3'
    if OUT.resolve()!=boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V3 output escapes pinned physical directory')
    current=path
    while current!=ROOT:
        if current.is_symlink() or (hasattr(current,'is_junction') and current.is_junction()):
            raise ValueError('Symlink/junction in V3 output path')
        if current.exists() and current.is_file() and current.stat().st_nlink!=1:
            raise ValueError('Hardlinked V3 output')
        current=current.parent


def construct(num,elf):
    num2,elf2,previous=volume.construct(num,elf)
    new_num,new_elf=bytearray(num2),bytearray(elf2)
    records=[]
    for rid,old,new in NUM_PATCHES:
        off=56+4*rid
        if struct.unpack_from('<I',num,off)[0]!=old:
            raise ValueError('Unexpected numeric layout resource')
        struct.pack_into('<I',new_num,off,new)
        records.append(dict(id=rid,file_offset=off,old=old,new=new))
    code=[]
    for va,old,new in COLOR_PATCHES:
        off=volume.elf_va_offset(elf,va,4)
        old_word,new_word=0x24040000|old,0x24040000|new
        if struct.unpack_from('<I',elf,off)[0]!=old_word:
            raise ValueError('Unexpected local color instruction')
        struct.pack_into('<I',new_elf,off,new_word)
        code.append(dict(va=hex(va),file_offset=off,old_word=hex(old_word),new_word=hex(new_word),role='numeric color argument'))
    off=volume.elf_va_offset(elf,BORDER_VA,4)
    if struct.unpack_from('<I',elf,off)[0]!=0x24070008:
        raise ValueError('Unexpected speaker border edge mask instruction')
    struct.pack_into('<I',new_elf,off,0x24070000)
    code.append(dict(va=hex(BORDER_VA),file_offset=off,old_word='0x24070008',new_word='0x24070000',role='speaker bottom-edge mask disabled'))
    num_allowed=set()
    for rid,*_ in volume.NUM_PATCHES+NUM_PATCHES:num_allowed.update(range(56+4*rid,60+4*rid))
    elf_allowed=set(range(volume.PATCH_OFF,volume.PATCH_OFF+len(volume.NEW)))
    for row in code:elf_allowed.update(range(row['file_offset'],row['file_offset']+4))
    volume.verify_allowlist(num,bytes(new_num),num_allowed)
    volume.verify_allowlist(elf,bytes(new_elf),elf_allowed)
    return bytes(new_num),bytes(new_elf),dict(inherited_volume_records=previous,numeric_records=records,code_records=code)


def expected_assets():
    raw=BASE_ASSETS.read_bytes()
    if sha(raw)!=BASE_ASSETS_SHA:raise ValueError('Reviewed v2 asset snapshot changed')
    return json.loads(raw)['assets']


def verified_records():
    """Read-only allowlist for APP rebuild; independently reconstruct native bytes."""
    from build_native_app import ASSET_PATHS
    output_guard(OUT/'manifest.json')
    manifest=json.loads((OUT/'manifest.json').read_text())
    original_num=(volume.SOURCE/volume.NUM_REL).read_bytes()
    original_elf=(volume.SOURCE/volume.ELF_REL).read_bytes()
    num,elf,_=construct(original_num,original_elf)
    expected={'08_APP/rc/rc/bin/Num_res.bin':(volume.NUM_SHA,sha(num)),
              '08_APP/bin/dvbt_board':(volume.ELF_SHA,sha(elf))}
    assets=expected_assets()
    if len(assets)!=20 or {a['image_id'] for a in assets}!=ASSET_PATHS.keys():
        raise ValueError('Unexpected original asset set')
    for asset in assets:
        relative='08_APP/'+ASSET_PATHS[asset['image_id']]
        if asset['original_path']!='analiz/dosya-sistemleri-tam/'+relative:
            raise ValueError('Unexpected reviewed asset path')
        expected[relative]=(asset['original_sha256'],CAPSULE_SHA if asset['image_id']==674 else asset['candidate_sha256'])
    rows=manifest['records']
    if len(rows)!=22 or {r['relative_path'] for r in rows}!=expected.keys():
        raise ValueError('Unexpected v3 overlay set')
    result=[]
    for row in rows:
        relative=row['relative_path']
        if (row['original_sha256'],row['candidate_sha256'])!=expected[relative]:
            raise ValueError('V3 overlay differs from reconstructed patch')
        p=OUT/'overlay'/relative
        output_guard(p)
        if p.is_symlink() or not p.resolve().is_relative_to(OUT.resolve()) or p.stat().st_nlink!=1 or sha(p.read_bytes())!=row['candidate_sha256']:
            raise ValueError('V3 output path/hash/alias mismatch')
        result.append(dict(path='/'+Path(relative).relative_to('08_APP').as_posix(),candidate=p,
                           original_sha256=row['original_sha256'],candidate_sha256=row['candidate_sha256']))
    return result


def main():
    output_guard(OUT/'manifest.json')
    if (OUT/'manifest.json').exists() or (OUT/'overlay').exists():
        raise FileExistsError('Refusing to overwrite v3 overlay')
    num=(volume.SOURCE/volume.NUM_REL).read_bytes()
    elf=(volume.SOURCE/volume.ELF_REL).read_bytes()
    new_num,new_elf,proof=construct(num,elf)
    probe=json.loads((ROOT/'analiz/native-png-probe/decode-result.json').read_text())
    if not probe['passed'] or not probe['isolation_passed'] or probe['inputs']['rounded']!=CAPSULE_SHA:
        raise ValueError('Original MIPS PNG decoder proof missing')
    capsule=ROOT/'analiz/native-png-probe/rounded-bg674-experimental.png'
    if sha(capsule.read_bytes())!=CAPSULE_SHA:raise ValueError('Rounded PNG changed')
    payloads={volume.NUM_REL:(num,new_num),volume.ELF_REL:(elf,new_elf)}
    for asset in expected_assets():
        relative=Path(asset['original_path']).relative_to('analiz/dosya-sistemleri-tam').as_posix()
        source=ROOT/asset['original_path']
        candidate=capsule if asset['image_id']==674 else ROOT/asset['candidate']
        before,after=source.read_bytes(),candidate.read_bytes()
        if sha(before)!=asset['original_sha256'] or sha(after)!=(CAPSULE_SHA if asset['image_id']==674 else asset['candidate_sha256']):
            raise ValueError('Reviewed asset hash mismatch')
        payloads[relative]=(before,after)
    records=[]
    for relative in payloads:output_guard(OUT/'overlay'/relative)
    for relative,(before,after) in payloads.items():
        target=OUT/'overlay'/relative
        target.parent.mkdir(parents=True,exist_ok=True)
        output_guard(target)
        with target.open('xb') as out:out.write(after)
        records.append(dict(relative_path=relative,original_sha256=sha(before),candidate_sha256=sha(after),bytes=len(after)))
    proof.update(records=records,status='offline_candidate_not_full_UI_port',revision='v3',
                 numeric_panel='existing digits only; root1920x176 background310x112 at1538,64',
                 capsule='P4+tRNS alpha addition; original libpng decoded it; MUF/device output not observed',
                 border='mask8 is bottom edge, not radius; only speaker mask disabled',
                 full_preview_ported=False,screen_rendered=False,television_tested=False,flash_ready=False,
                 unchanged=['channel change algorithms','digit timers and key events','ARC routing','global font/color/image/Clrkey tables','Home surfaces','native animation gate'])
    with (OUT/'manifest.json').open('x') as out:json.dump(proof,out,indent=2)
    verified_records()
    print(json.dumps(dict(status=proof['status'],files=len(records),numeric_records=9,local_color_arguments=8,TV_tested=False)))


if __name__=='__main__':
    argparse.ArgumentParser(description=__doc__).parse_args()
    main()
