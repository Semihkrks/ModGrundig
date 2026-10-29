"""Independent on-disk offline candidate readback. Does not execute firmware."""
import hashlib
import argparse
import json
import lzma
from pathlib import Path, PurePosixPath
import re
import stat
import struct
import zlib
from unpack_mstar import parse_header

ROOT=Path(__file__).resolve().parents[1]
PACKAGE=ROOT/'analiz/native-ui-candidate/v2/package'
STOCK_SHA='6d7614730c5f63b9e6727b8b329606b188b581efb366bffde6991aca123852c0'
BOOT_SHA='2a4e909696163e947ceed9106b00ac5512c4c8890a253a623307acd10a7885a1'
APP_SHA='353d4fbb6a255c86fcafb161e02218dab7d68fcc350092db31ef37c10791ad35'
PRIVATE_PNG=re.compile(r'/rc/ARimages/Grundig/modern/(?:v8/)?[a-z0-9][a-z0-9._-]*\.png\Z')
META_FIELDS=('mode','uid','gid','type','nlink','mtime_sec','mtime_nsec')


def validate_metadata(original,current,revision,records=()):
    """Independent metadata policy; no APP-builder or repacker helper used."""
    new_files={r['path']:r for r in records if r['original_sha256'] is None}
    if len(new_files)!=sum(r['original_sha256'] is None for r in records):
        raise ValueError('Duplicate added resource')
    if any(not PRIVATE_PNG.fullmatch(name) for name in new_files):
        raise ValueError('New resource outside private flat PNG directory')
    if new_files and revision not in ('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'):raise ValueError('Old revision cannot add resources')
    parent='/rc/ARimages/Grundig'
    new_dirs=set()
    for name in new_files:
        directory=PurePosixPath(name).parent
        while str(directory) not in original:
            new_dirs.add(str(directory));directory=directory.parent
    expected_paths=set(original)|set(new_files)|new_dirs
    if current.keys()!=expected_paths:raise ValueError('Unexpected re-read APP paths')
    for name,old in original.items():
        for field in META_FIELDS:
            delta=sum(str(PurePosixPath(directory).parent)==name for directory in new_dirs)
            wanted=old[field]+delta if field=='nlink' else old[field]
            if current[name][field]!=wanted:raise ValueError('Original metadata differs: '+name+'/'+field)
    if new_files:
        ancestor=original[parent]
        for name in list(new_files)+sorted(new_dirs):
            row=current[name];is_dir=name in new_dirs
            for field in ('uid','gid','mtime_sec','mtime_nsec'):
                if row[field]!=ancestor[field]:raise ValueError('New resource owner/time differs')
            wanted_mode=ancestor['mode'] if is_dir else stat.S_IFREG|0o644
            wanted_links=2+sum(str(PurePosixPath(directory).parent)==name for directory in new_dirs) if is_dir else 1
            if row['type']!=('directory' if is_dir else 'regular') or row['mode']!=wanted_mode or row['nlink']!=wanted_links:
                raise ValueError('New resource mode/type/nlink differs')
            if not is_dir and row['size']!=Path(new_files[name]['candidate']).stat().st_size:
                raise ValueError('New resource size differs')
    return {'original_metadata_entries_checked':len(original),'new_resource_files_checked':len(new_files),
            'new_directories_checked':len(new_dirs),
            'original_parent_nlink_delta':sum(str(PurePosixPath(directory).parent)==parent for directory in new_dirs)}


def digest(data):return hashlib.sha256(data).hexdigest()


def main(revision='v2'):
    if revision not in ('v2','v3','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'):raise ValueError('Unsupported readback revision')
    PACKAGE=ROOT/f'analiz/native-ui-candidate/{revision}/package'
    stock=(ROOT/'analiz/firmware-dogrulanmis/Target_GM/image/GM_SWImage.bin').read_bytes()
    filename='GM_SWImage_UI_v7_OFFLINE_UNVERIFIED.bin' if revision=='v7-tv' else f'GM_SWImage_UI_{revision}_OFFLINE_UNVERIFIED.bin'
    candidate=(PACKAGE/filename).read_bytes()
    app=(PACKAGE/'08_APP.ubifs').read_bytes()
    assert digest(stock)==STOCK_SHA
    assert digest((ROOT/'analiz/firmware-dogrulanmis/Target_GM/image/GM_Boot.bin').read_bytes())==BOOT_SHA
    assert len(candidate)==len(stock)==42483736
    _,old=parse_header(stock[:0x4000],len(stock))
    _,new=parse_header(candidate[:0x4000],len(candidate))
    assert len(old)==len(new)==14
    all_sections=[]
    for a,b in zip(old,new):
        assert a['source_offset']==b['source_offset']
        chunks=[]
        for blob,row in ((stock,a),(candidate,b)):
            start,length=row['source_offset'],row['compressed_bytes']
            compressed=blob[start:start+length]
            assert compressed[:5]==b'\x5d\x00\x00\x00\x04'
            decoder=lzma.LZMADecompressor(format=lzma.FORMAT_ALONE,memlimit=160*1024*1024)
            out=decoder.decompress(compressed,max_length=128*1024*1024)
            assert decoder.eof and decoder.unused_data==b'\xbe\xef'
            assert len(out)==int.from_bytes(compressed[5:13],'little')
            assert f'{zlib.crc32(out):08x}'==row['expected_crc32_hex']
            chunks.append(out)
        if a['ordinal']==8:
            assert chunks[1]==app
        else:
            assert chunks[0]==chunks[1]
            start,length=a['source_offset'],a['compressed_bytes']
            assert stock[start:start+length]==candidate[start:start+length]
        all_sections.append(dict(ordinal=a['ordinal'],crc_pass=True,unchanged=a['ordinal']!=8,
                                 sha256=digest(chunks[1]),bytes=len(chunks[1])))
    footer=len(candidate)-24
    assert candidate[footer+8:]==b'# Script Size = '
    assert struct.unpack_from('<I',candidate,footer)[0]==zlib.crc32(candidate[:0x4000])
    assert struct.unpack_from('<I',candidate,footer+4)[0]==zlib.crc32(candidate[:footer+4])
    if revision in ('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'):
        from export_ubifs_metadata import inspect_image
        if revision=='v7.10-tv':from build_native_ui_v710_tv import verified_packaging_records
        elif revision=='v7.9-tv':from build_native_ui_v79_tv import verified_packaging_records
        elif revision=='v7.8-tv':from build_native_ui_v78_tv import verified_packaging_records
        elif revision=='v7.7-tv':from build_native_ui_v77_tv import verified_packaging_records
        elif revision=='v7.6-tv':from build_native_ui_v76_tv import verified_packaging_records
        elif revision=='v7.5-tv':from build_native_ui_v75_tv import verified_packaging_records
        elif revision=='v7.4-tv':from build_native_ui_v74_tv import verified_packaging_records
        elif revision=='v7.3-tv':from build_native_ui_v73_tv import verified_packaging_records
        elif revision=='v7.2-tv':from build_native_ui_v72_tv import verified_packaging_records
        elif revision=='v7.1-tv':from build_native_ui_v71_tv import verified_packaging_records
        elif revision=='v7-tv':from build_native_ui_v7_tv import verified_packaging_records
        else:from build_native_ui_v8 import verified_packaging_records
        original_app=ROOT/'analiz/bolumler/08_APP.bin'
        assert digest(original_app.read_bytes())==APP_SHA
        original_meta=inspect_image(original_app)
        current_meta=inspect_image(PACKAGE/'08_APP.ubifs')
        assert not original_meta['issues'] and not current_meta['issues']
        assert not original_meta['unreachable_indexed_inode_count'] and not current_meta['unreachable_indexed_inode_count']
        records=verified_packaging_records()
    else:
        original_meta=next(x for x in json.loads((ROOT/'analiz/ubifs-orijinal-metadata.json').read_text())['images'] if x['image']=='08_APP.bin')
        current_meta=json.loads((PACKAGE/'app-index.json').read_text())
        records=()
    original={x['path']:x for x in original_meta['entries']}
    current={x['path']:x for x in current_meta['entries']}
    metadata=validate_metadata(original,current,revision,records)
    result=dict(status='PASS_OFFLINE_ONLY',container_sha256=digest(candidate),app_sha256=digest(app),
                payloads_checked=14,payloads_unchanged=13,payloads=all_sections,outer_crcs_pass=True,
                boot_file_unchanged=True,metadata_nlink_and_permissions_checked=len(original),metadata=metadata,
                television_tested=False,flash_ready=False,
                method='Independent on-disk readback using original parse_header and stdlib LZMA/CRC; no repacker helpers')
    with (PACKAGE/'independent-readback.json').open('x') as out:json.dump(result,out,indent=2)
    print(json.dumps({k:result[k] for k in ('status','container_sha256','payloads_checked','payloads_unchanged','metadata_nlink_and_permissions_checked')}))


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--revision',choices=('v2','v3','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'),default='v2')
    main(parser.parse_args().revision)
