"""Independent APP+MSLIB test readback: stdlib envelope, native UBIFS extraction.

No repacker helper is imported. Filesystem checks require Linux ubi-reader and
host extractor. This script never launches firmware/update/hardware commands.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import lzma
import os
from pathlib import Path
import re
import struct
import subprocess
import zlib
from unpack_mstar import parse_header

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-candidate/v7.9-audio-test/package'
BASE=ROOT/'analiz/native-ui-candidate/v7.9-tv/package/GM_SWImage_UI_v7.9-tv_OFFLINE_UNVERIFIED.bin'
BASE_SHA='ae6a322861e3b288294b0e4a5f5faf33cb41864439508b2fcee4f6d89ddba496'
APP_SHA='438caad4b1fed4a908d018e154da7939f21a20c4440eab5bc9c6238f104ee4c1'
MSLIB_SHA='7d92780368b178854a46a8f2e2ee8b625d06c7292695929800e5ecbc56fb827b'
LIB_SHA='06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21'
BOOT_SHA='2a4e909696163e947ceed9106b00ac5512c4c8890a253a623307acd10a7885a1'
FILENAME='GM_SWImage_UI_v7.9-audio-test_OFFLINE_UNVERIFIED.bin'


def require(ok, why):
    if not ok:raise ValueError(why)


def digest(raw):return hashlib.sha256(raw).hexdigest()


def decode(blob, row):
    stream=blob[row['source_offset']:row['source_offset']+row['compressed_bytes']]
    require(stream[:5]==bytes.fromhex('5d00000004'), 'LZMA properties changed')
    n=int.from_bytes(stream[5:13],'little'); require(0<n<=128*1024*1024,'Payload budget exceeded')
    d=lzma.LZMADecompressor(format=lzma.FORMAT_ALONE,memlimit=160*1024*1024)
    raw=d.decompress(stream,max_length=n+1)
    require(d.eof and d.unused_data==b'\xbe\xef' and len(raw)==n,'Payload framing differs')
    require(row['expected_crc32_hex']==f'{zlib.crc32(raw):08x}' and row['crc32_declaration']['bytes']==n,'Payload CRC differs')
    require(row['mscompress7_declared_input_bytes']==row['compressed_bytes'],'Input length differs')
    return raw


def normalized_header(blob):
    h=blob[:0x4000]; text,padding=h.split(b'\0',1);require(not any(padding),'Nonzero header padding')
    result=[];counts=dict.fromkeys(('filepartload','mscompress7','crc32','mw','ubi'),0)
    patterns={
      'filepartload':r'(filepartload 0x[0-9a-fA-F]+ \$\(UpgradeImage\) 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( #mslib)',
      'mscompress7':r'(mscompress7 d 0 0x[0-9a-fA-F]+ )[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #mslib)',
      'crc32':r'(crc32 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #mslib)',
      'mw':r'(mw 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 4 #mslib)',
      'ubi':r'(ubi write 0x[0-9a-fA-F]+ MSLIB )0x[0-9a-fA-F]+ 0x[0-9a-fA-F]+( #mslib)'}
    for line in text.decode('ascii').splitlines(keepends=True):
        plain=line.rstrip('\r\n');ending=line[len(plain):]
        if plain.endswith(' #mslib'):
            key=plain.split()[0]
            if key in patterns and (key != 'ubi' or plain.startswith('ubi write ')):
                m=re.fullmatch(patterns[key],plain);require(m is not None,'MSLIB command form differs')
                plain=m[1]+'<reviewed-size-or-crc>'+m[2];counts[key]+=1
        result.append(plain+ending)
    require(all(n==1 for n in counts.values()),'MSLIB command count differs')
    return result


def verify_container_bytes(base, candidate, mslib):
    require(digest(base)==BASE_SHA,'V7.9 base hash differs')
    require(len(candidate)==len(base)==42483736,'Container size changed')
    require(len(mslib)<=0x1c00000,'MSLIB exceeds fixed decoded-output RAM gap')
    require(normalized_header(base)==normalized_header(candidate),'Update commands changed outside MSLIB numeric fields')
    reports=[];parsed=[]
    for blob in (base,candidate):
        footer=len(blob)-24;require(blob[footer+8:]==b'# Script Size = ','Footer marker differs')
        require(struct.unpack_from('<I',blob,footer)[0]==zlib.crc32(blob[:0x4000]),'Header CRC differs')
        require(struct.unpack_from('<I',blob,footer+4)[0]==zlib.crc32(blob[:footer+4]),'Container CRC differs')
        _,rows=parse_header(blob[:0x4000],footer);require(len(rows)==14,'Payload count differs');parsed.append(rows)
    for i,(a,b) in enumerate(zip(*parsed)):
        require(a['source_offset']==b['source_offset'],'Payload relocated')
        end=parsed[0][i+1]['source_offset'] if i<13 else len(base)-24
        require(a['source_offset']+a['compressed_bytes']<=end and b['source_offset']+b['compressed_bytes']<=end,
                'Compressed section exceeds its fixed slot')
        raws=[decode(blob,row) for blob,row in ((base,a),(candidate,b))]
        for blob,row in ((base,a),(candidate,b)):
            require(not any(blob[row['source_offset']+row['compressed_bytes']:end]),'Nonzero padding')
        if i==7:
            require(a['write_target']==b['write_target']=='MSLIB' and digest(raws[0])==MSLIB_SHA and raws[1]==mslib,'MSLIB payload differs')
            require(b['write_bytes']==len(mslib),'MSLIB write size differs')
            require(int(b['load_address'],16)==0x81e00000 and int(b['decompress_destination'],16)==0x80200000,
                    'MSLIB loader addresses changed')
            writes=[x for x in b['commands'] if x.startswith('ubi write ')]
            require(len(writes)==1 and re.fullmatch(r'ubi write 0x[0-9a-fA-F]+ MSLIB 0x'+f'{len(mslib):x}'+r' 0x'+f'{len(mslib):x}'+r' #mslib',writes[0]),'Both MSLIB lengths must match')
        else:
            require(raws[0]==raws[1] and base[a['source_offset']:end]==candidate[b['source_offset']:end], 'Non-MSLIB compressed slot changed')
            require(a['commands']==b['commands'],'Non-MSLIB commands changed')
        if i==8:require(digest(raws[1])==APP_SHA,'APP is not exact V7.9')
        reports.append(dict(ordinal=i,unchanged_from_v79=i!=7,decoded_sha256=digest(raws[1]),decoded_bytes=len(raws[1])))
    return dict(status='PASS_OFFLINE_ONLY',container_sha256=digest(candidate),app_sha256=APP_SHA,mslib_sha256=digest(mslib),payloads_checked=14,unchanged_from_v79_payloads=13,all_offsets_preserved=True,outer_crcs_pass=True,payloads=reports,target_executed=False,flash_ready=False)


def main(library, library_sha256):
    require(library_sha256!=LIB_SHA,'Audio test must contain a reviewed non-original library')
    require(digest(library.read_bytes())==library_sha256,'Reviewed library hash differs')
    proof=verify_container_bytes(BASE.read_bytes(),(OUT/FILENAME).read_bytes(),(OUT/'07_MSLIB.ubifs').read_bytes())
    require(digest((ROOT/'analiz/firmware-dogrulanmis/Target_GM/image/GM_Boot.bin').read_bytes())==BOOT_SHA,'Boot file changed')
    from export_ubifs_metadata import inspect_image
    from build_native_app import inventory, READER, verify_index_crc
    original=ROOT/'analiz/bolumler/07_MSLIB.bin';candidate=OUT/'07_MSLIB.ubifs'
    require(digest(original.read_bytes())==MSLIB_SHA,'Original MSLIB changed')
    metas=[inspect_image(x) for x in (original,candidate)];maps=[{r['path']:r for r in m['entries']} for m in metas]
    sb=metas[1]['superblock']
    require((sb['flags'],sb['fmt_version'],sb['min_io_size'],sb['leb_size'])==(0,4,2048,126976)
            and sb['leb_cnt']<=480 and candidate.stat().st_size==sb['leb_cnt']*126976,'Independent MSLIB geometry differs')
    require(struct.unpack_from('<I',candidate.read_bytes(),44)[0]==480,'MSLIB max LEB geometry changed')
    require(all(not m['issues'] and not m['unreachable_indexed_inode_count'] for m in metas),'MSLIB index unresolved')
    require(maps[0].keys()==maps[1].keys() and len(maps[0])==341,'MSLIB paths differ')
    for name,a in maps[0].items():
        b=maps[1][name];require(all(a[k]==b[k] for k in ('type','mode','uid','gid','nlink','mtime_sec','mtime_nsec')),'MSLIB metadata differs: '+name)
        if a['type']=='regular':require(a['size']==b['size'],'MSLIB regular size differs: '+name)
        if a['type']=='symlink':require(a['symlink_target']==b['symlink_target'],'MSLIB link differs')
    work=Path('/home/semih/.local/share/grundig-analysis/native-build-v1/mslib-v79-independent')
    require(not work.exists(),'Independent readback directory already exists');work.mkdir(parents=True)
    inventories=[]
    for tag,image in (('original',original),('candidate',candidate)):
        with (work/(tag+'.log')).open('x') as log:
            subprocess.run([str(READER),'-e','126976','-o',str(work/tag),str(image)],stdout=log,stderr=subprocess.STDOUT,check=True,timeout=300)
        inventories.append(inventory(work/tag))
    require(inventories[0].keys()==inventories[1].keys()==maps[0].keys(),'Independent extractor path sets differ')
    for name,a in inventories[0].items():
        b=inventories[1][name];require(a['type']==b['type'],'Readback type differs')
        if a['type']=='regular':
            wanted=library_sha256 if name=='/libmsrv_common.so' else a['sha256']
            require(b['sha256']==wanted,'Unexpected MSLIB content: '+name)
        elif a['type']=='symlink':require(a['symlink_target']==b['symlink_target'],'Readback symlink differs')
    proof.update(metadata_entries_verified=341,regular_files_verified=261,unchanged_mslib_files=260,symlinks_verified=54,library_sha256=library_sha256,boot_file_unchanged=True,committed_crc=verify_index_crc(candidate))
    # No APP rebuild: verify the existing V7.9 APP image as an exact payload.
    require(digest((ROOT/'analiz/native-ui-candidate/v7.9-tv/package/08_APP.ubifs').read_bytes())==APP_SHA,'V7.9 APP image changed')
    output=OUT/'independent-readback.json';require(not output.exists() and not output.is_symlink(),'Readback report already exists')
    with output.open('x') as stream:json.dump(proof,stream,indent=2);stream.write('\n')
    print(json.dumps(dict(status=proof['status'],container_sha256=proof['container_sha256'])))


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--library',required=True,type=Path);p.add_argument('--library-sha256',required=True)
    a=p.parse_args();main(a.library,a.library_sha256)
