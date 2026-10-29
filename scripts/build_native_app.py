"""Offline APP-only UBIFS builder. Run under fakeroot on the Linux host.

Never executes an extracted target or update command. Originals remain read-only.
The committed index and a second extraction must agree before publishing output.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import stat
import struct
import subprocess
import sys
import zlib

ROOT = Path(__file__).resolve().parents[1]
WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1')
SOURCE = Path('/home/semih/.local/share/grundig-analysis/full-v1/files/08_APP')
MKFS = WORK / 'tools/mtd/usr/sbin/mkfs.ubifs'
READER = Path('/home/semih/.local/share/uv/tools/unblob/bin/ubireader_extract_files')
ORIGINAL_APP_SHA = '353d4fbb6a255c86fcafb161e02218dab7d68fcc350092db31ef37c10791ad35'
HOME_BASE = 'rc/ARimages/Grundig/half/homeScreen/icons/'
VOLUME_BASE = 'rc/ARimages/Common/popups/volumeControl/'
ASSET_PATHS = {
    985:HOME_BASE+'l3.icon.video.png',986:HOME_BASE+'l3.icon.video_focus.png',
    973:HOME_BASE+'l3.icon.sound.png',974:HOME_BASE+'l3.icon.sound_focus.png',
    975:HOME_BASE+'l3.icon.source.setup.tv.png',976:HOME_BASE+'l3.icon.source.setup.tv_focus.png',
    967:HOME_BASE+'l3.icon.lock.png',968:HOME_BASE+'l3.icon.lock_focus.png',
    979:HOME_BASE+'l2.icon.scheduleList.png',982:HOME_BASE+'l2.icon.scheduleList.focus.png',
    983:HOME_BASE+'l3.icon.settings.png',984:HOME_BASE+'l3.icon.settings_focus.png',
    674:VOLUME_BASE+'bg.png',685:VOLUME_BASE+'volume_shadow.png',
    4:VOLUME_BASE+'arc_soundDown.png',5:VOLUME_BASE+'arc_soundMute.png',6:VOLUME_BASE+'arc_soundUp.png',
    680:'rc/ARimages/Grundig/volume/mute_icon.png',681:'rc/ARimages/Grundig/volume/volume_ellipse.png',
    682:'rc/ARimages/Grundig/volume/volume_icon.png',
}
REVISIONS = ('v2', 'v3', 'v8', 'v7-tv', 'v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv')
# V8's deterministic overlay verifier owns the exact set of appended IDs/bytes.
# Packaging additionally confines new PNGs to the private modern directory and
# its one versioned Home subdirectory. No arbitrary nested paths are admitted.
V8_ADDED_FILE = re.compile(r'/rc/ARimages/Grundig/modern/(?:v8/)?[a-z0-9][a-z0-9._-]*\.png\Z')


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def save(path, value):
    with path.open('x', encoding='utf-8') as stream:
        json.dump(value, stream, indent=2, ensure_ascii=True)
        stream.write('\n')


def child(base, text):
    """An inert absolute firmware path may not escape its staging root."""
    p = PurePosixPath(text)
    if not p.is_absolute() or '..' in p.parts:
        raise ValueError('Invalid firmware metadata path')
    result = base.joinpath(*p.parts[1:])
    if result != base and not result.parent.resolve().is_relative_to(base.resolve()):
        raise ValueError('Symlink parent or path escape')
    return result


def inventory(base):
    result = {}
    pending = [base]
    while pending:
        path = pending.pop()
        st = path.lstat()
        key = '/' + path.relative_to(base).as_posix() if path != base else '/'
        kind = {stat.S_IFREG:'regular', stat.S_IFDIR:'directory', stat.S_IFLNK:'symlink'}.get(stat.S_IFMT(st.st_mode))
        if kind is None or (kind == 'regular' and st.st_nlink != 1):
            raise ValueError('Unexpected special file or hardlink')
        row = {'type':kind, 'mode':st.st_mode, 'uid':st.st_uid, 'gid':st.st_gid}
        if kind == 'regular':
            row.update(size=st.st_size, sha256=sha(path))
        elif kind == 'symlink':
            row['symlink_target'] = os.readlink(path)
        else:
            pending.extend(sorted(path.iterdir(), reverse=True))
        result[key] = row
    return result


def verify_index_crc(path):
    """Check every committed index child, including DATA payload node CRCs."""
    from ubireader.ubi_io import ubi_file
    from ubireader.ubifs import ubifs,nodes
    from ubireader.ubifs import defines as D
    image_file=ubi_file(str(path),1)
    try:
        fs=ubifs(image_file)
        master=fs.master_node
        pending=[(master.root_lnum,master.root_offs,master.root_len)]
        seen=set()
        counts={}
        while pending:
            lnum,offs,length=pending.pop()
            location=lnum*fs.leb_size+offs
            if location in seen or lnum<0 or offs<0 or offs+length>fs.leb_size or location+length>path.stat().st_size:
                raise ValueError('Invalid committed index node reference')
            seen.add(location)
            image_file.seek(location)
            raw=image_file.read(length)
            header=nodes.common_hdr(raw[:D.UBIFS_COMMON_HDR_SZ])
            if header.magic!=0x06101831 or header.len!=length or (zlib.crc32(raw[8:])^0xffffffff)!=header.crc:
                raise ValueError('Committed UBIFS node CRC/length mismatch')
            counts[str(header.node_type)]=counts.get(str(header.node_type),0)+1
            if header.node_type==D.UBIFS_IDX_NODE:
                index=nodes.idx_node(raw[D.UBIFS_COMMON_HDR_SZ:])
                pending.extend((b.lnum,b.offs,b.len) for b in index.branches)
        return {'committed_nodes_crc_verified':len(seen),'node_type_counts':counts,'journal_replay':False}
    finally:
        image_file.close()


def overlay_records(revision='v2'):
    if revision not in REVISIONS:
        raise ValueError('Unsupported build revision')
    if revision in ('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'):
        # Raster reconstruction is platform-dependent. This stdlib-only API
        # checks the code-pinned output map after full Windows reconstruction.
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
        records = verified_packaging_records()
        validate_overlay_inputs(records, revision)
        return records
    if revision=='v3':
        from build_native_ui_v3 import verified_records
        return verified_records()
    records = []
    assets = json.loads((ROOT/'analiz/native-ui-candidate/v1/assets/manifest.json').read_text(encoding='utf-8'))
    if len(assets['assets'])!=20 or {r['image_id'] for r in assets['assets']}!=ASSET_PATHS.keys():
        raise ValueError('Unexpected native asset ID set')
    for row in assets['assets']:
        relative = Path(row['original_path']).relative_to('analiz/dosya-sistemleri-tam/08_APP').as_posix()
        if row['action']!='replace_asset' or relative!=ASSET_PATHS[row['image_id']]:
            raise ValueError('Asset ID/path/action differs from approved allowlist')
        if row['candidate']!='analiz/native-ui-candidate/v1/assets/candidate/08_APP/'+relative:
            raise ValueError('Asset candidate path differs from approved binding')
        records.append(dict(path='/'+relative, candidate=ROOT/row['candidate'],
                            original_sha256=row['original_sha256'], candidate_sha256=row['candidate_sha256']))
    volume_root = ROOT/'analiz/native-ui-candidate/v1/volume/candidate/08_APP'
    volume = json.loads((volume_root.parents[1]/'manifest.json').read_text(encoding='utf-8'))
    pinned = {'08_APP/bin/dvbt_board':('51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916',
                                    '9b64ca24f6f7ff0833284599f8bdec3db1b90c820d4fdfdb9ff26711c1ad41c2'),
              '08_APP/rc/rc/bin/Num_res.bin':('e20c03cd212f548eb8154e8e49d6cf4daafc5fd5842887c51590bf76cfe613ff',
                                           '281a97c04d9e000b60a0349a10d5eda5c76a91c33f369793347aef126abebe03')}
    if {r['relative_path'] for r in volume['records']}!=pinned.keys() or len(volume['records'])!=2:
        raise ValueError('Unexpected native volume overlay set')
    for row in volume['records']:
        relative = Path(row['relative_path']).relative_to('08_APP').as_posix()
        if (row['original_sha256'],row['candidate_sha256'])!=pinned[row['relative_path']]:
            raise ValueError('Native patch hashes differ from reviewed patch')
        records.append(dict(path='/'+relative,candidate=volume_root/relative,
                            original_sha256=row['original_sha256'],candidate_sha256=row['candidate_sha256']))
    if len({r['path'] for r in records}) != len(records):
        raise ValueError('Duplicate overlay')
    for row in records:
        p = row['candidate']
        if p.is_symlink() or not p.resolve().is_relative_to((ROOT/'analiz/native-ui-candidate/v1').resolve()):
            raise ValueError('Overlay outside candidate directory')
        if p.stat().st_nlink != 1 or sha(p) != row['candidate_sha256']:
            raise ValueError('Overlay hash/hardlink mismatch')
    return records


def validate_overlay_inputs(records, revision):
    """Recheck the version-specific paths and bytes at the packaging boundary."""
    boundary = ROOT/f'analiz/native-ui-candidate/{revision}/overlay/08_APP'
    seen = set()
    for row in records:
        name = row['path']
        path = PurePosixPath(name)
        if not path.is_absolute() or name=='/' or '..' in path.parts or name in seen:
            raise ValueError('Invalid or duplicate overlay path')
        seen.add(name)
        candidate = Path(row['candidate'])
        pinned = child(boundary, name)
        if candidate != pinned or not candidate.is_file() or candidate.is_symlink():
            raise ValueError('Overlay candidate outside version-specific binding')
        if candidate.resolve() != pinned.absolute() or candidate.stat().st_nlink != 1:
            raise ValueError('Aliased overlay candidate')
        if sha(candidate) != row['candidate_sha256']:
            raise ValueError('Overlay candidate changed before packaging')


def expected_with_additions(original, records, revision):
    """Preserve original metadata; declare bounded new resource inodes explicitly.

    New directories inherit mode/owner/timestamp from their original parent.
    A new regular PNG uses0644 and the parent owner/timestamp. An existing
    parent's nlink changes only by its added immediate child-directory count.
    """
    expected = {name:dict(row) for name,row in original.items()}
    additions = []
    seen = set()
    for row in records:
        name = row['path']
        p = PurePosixPath(name)
        if not p.is_absolute() or name=='/' or '..' in p.parts or name in seen:
            raise ValueError('Invalid or duplicate overlay path')
        seen.add(name)
        if name in original:
            if row['original_sha256'] is None or original[name]['type']!='regular':
                raise ValueError('Existing overlay must identify an original regular file')
            continue
        if revision not in ('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv') or not V8_ADDED_FILE.fullmatch(name) or row['original_sha256'] is not None:
            raise ValueError('Unapproved new resource path')
        missing = []
        parent = p.parent
        while str(parent) not in expected:
            missing.append(str(parent));parent=parent.parent
        if expected[str(parent)]['type']!='directory':
            raise ValueError('New resource ancestor is not a directory')
        for directory in reversed(missing):
            parent_name=str(PurePosixPath(directory).parent)
            ancestor=expected[parent_name]
            expected[directory] = {k:ancestor[k] for k in ('mode','uid','gid','mtime_sec','mtime_nsec')}
            expected[directory].update(path=directory,type='directory',nlink=2,size=0)
            expected[parent_name]['nlink']+=1
            additions.append(directory)
        ancestor=expected[str(p.parent)]
        expected[name] = {k:ancestor[k] for k in ('uid','gid','mtime_sec','mtime_nsec')}
        expected[name].update(path=name,type='regular',mode=stat.S_IFREG|0o644,
                              nlink=1,size=Path(row['candidate']).stat().st_size)
        additions.append(name)
    return expected, additions


def compressor_policy(revision, compressor):
    if compressor not in ('lzo','zlib','lzo-raw-elf') or (compressor!='lzo' and revision not in ('v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv')) or (compressor=='zlib' and revision!='v8'):
        raise ValueError('Unsupported filesystem compressor/revision')
    if compressor=='zlib':
        proof=ROOT/'analiz/native-ui-port-v8/kernel-compression.json'
        if sha(proof)!='ad1beba5b60646a2ce50c3280548608d4b7448522a25b372f8e6abe3b1196298':
            raise ValueError('Pinned original kernel ZLIB evidence changed')
        if sha(ROOT/'analiz/bolumler/05_KL.bin')!='d96b0ec70d633751ba8750a1a80aee8cac3a9c5e825744650d749a8862550691':
            raise ValueError('Original kernel identity changed')
    if compressor=='lzo-raw-elf' and sha(ROOT/'analiz/native-ui-port-v8/selective-compression-probe.json')!='9443411c930bb01ae6f74ccd6775b712845c31a5b688ce050a4a415a2362b3b3':
        raise ValueError('Pinned host compressor fixture changed')
    return revision if compressor=='lzo' else revision+'-'+compressor

def main(revision='v2', fs_compressor='lzo'):
    build_tag=compressor_policy(revision,fs_compressor)
    OUTPUT = ROOT/f'analiz/native-ui-candidate/{revision}/package'
    if revision not in REVISIONS:
        raise ValueError('Unsupported build revision')
    if sys.platform != 'linux' or os.environ.get('FAKEROOTKEY') is None:
        raise RuntimeError('Use a single fakeroot session on Linux to preserve original owners')
    if sha(MKFS)!='f424c5cb122bc24a10858512926fbe5a29c74b4b6a80c5e347bd7e9aa07f48bb':
        raise ValueError('Host mkfs.ubifs differs from reviewed official package')
    original = ROOT/'analiz/bolumler/08_APP.bin'
    if sha(original) != ORIGINAL_APP_SHA:
        raise ValueError('Pinned original APP changed')
    from export_ubifs_metadata import inspect_image
    source_meta = inspect_image(original)
    if source_meta['issues'] or source_meta['unreachable_indexed_inode_count']:
        raise ValueError('Original metadata has unresolved entries')
    expected = {r['path']:r for r in source_meta['entries']}
    if len(expected) != 2773 or source_meta['type_counts'] != {'directory':401,'regular':2371,'symlink':1}:
        raise ValueError('Unexpected original APP inventory')
    original_extracted = WORK/f'original-recheck-{build_tag}'
    if original_extracted.exists():
        raise FileExistsError('Original recheck destination already exists')
    with (WORK/f'original-recheck-{build_tag}.log').open('x') as log:
        subprocess.run([str(READER),'-e','126976','-o',str(original_extracted),str(original)],
                       stdout=log,stderr=subprocess.STDOUT,check=True,timeout=300)
    baseline = inventory(original_extracted)
    before = inventory(SOURCE)
    print('Pinned original APP reextracted; checking canonical source and overlay hashes',flush=True)
    if before.keys() != expected.keys():
        raise ValueError('Canonical source path set differs from original index')
    for name, row in before.items():
        old = expected[name]
        if row['type'] != old['type']:
            raise ValueError('Source type mismatch')
        if row['type'] == 'regular':
            if row['size'] != old['size'] or row['sha256'] != baseline[name].get('sha256'):
                raise ValueError('Canonical source differs from pinned original APP reextraction')
        if row['type'] == 'symlink' and row['symlink_target'] != old['symlink_target']:
            raise ValueError('Source symlink differs')
    overlays = overlay_records(revision)
    for row in overlays:
        if before.get(row['path'],{}).get('sha256') != row['original_sha256']:
            raise ValueError('Overlay original hash mismatch')
    expected, additions = expected_with_additions(expected, overlays, revision)
    staging = WORK/f'app-stage-{build_tag}'
    image = WORK/f'08_APP-{build_tag}.ubifs'
    extracted = WORK/f'app-reextracted-{build_tag}'
    if any(p.exists() for p in (staging,image,extracted)) or OUTPUT.exists():
        raise FileExistsError('Refusing to reuse an existing candidate build/output')
    WORK.mkdir(parents=True,exist_ok=True)
    OUTPUT.mkdir(parents=True)
    shutil.copytree(SOURCE,staging,symlinks=True)
    for name in additions:
        if expected[name]['type']=='directory':child(staging,name).mkdir()
    for row in overlays:
        shutil.copyfile(row['candidate'],child(staging,row['path']),follow_symlinks=False)
    # Ownership/mode/timestamps are restored only inside the isolated tree.
    # Apply directories last so restrictive original modes cannot block population.
    for name, row in sorted(expected.items(),key=lambda item:len(PurePosixPath(item[0]).parts),reverse=True):
        target = child(staging,name)
        os.chown(target,row['uid'],row['gid'],follow_symlinks=False)
        if row['type'] != 'symlink':
            os.chmod(target,stat.S_IMODE(row['mode']))
        ts = row['mtime_sec']*1_000_000_000+row['mtime_nsec']
        os.utime(target,ns=(ts,ts),follow_symlinks=False)
    staged = inventory(staging)
    if staged.keys()!=expected.keys():
        raise ValueError('Staged paths differ from reviewed metadata/additions')
    changed = {r['path']:r for r in overlays}
    for name, row in staged.items():
        old = expected[name]
        if any(row[k]!=old[k] for k in ('type','mode','uid','gid')):
            raise ValueError('Restored metadata mismatch')
        if row['type']=='regular' and row['sha256'] != (changed[name]['candidate_sha256'] if name in changed else before[name]['sha256']):
            raise ValueError('Unexpected staged content change')
    print(f'Staging ready: {len(overlays)} allowlisted files overlaid; {len(additions)} declared new inodes',flush=True)
    if fs_compressor=='lzo-raw-elf':
        import fcntl
        # Official mkfs supports LZO per inode through FS_COMPR_FL when the
        # default is none. Only the ELF is stored raw; every file byte remains
        # identical and both DATA codecs already occur in the original APP.
        for name,row in staged.items():
            if row['type']!='regular':continue
            fd=os.open(child(staging,name),os.O_RDONLY)
            try:
                flags=struct.unpack('I',fcntl.ioctl(fd,0x80086601,struct.pack('I',0)))[0]
                flags=flags&~4 if name=='/bin/dvbt_board' else flags|4
                fcntl.ioctl(fd,0x40086602,struct.pack('I',flags))
                actual=struct.unpack('I',fcntl.ioctl(fd,0x80086601,struct.pack('I',0)))[0]
                if bool(actual&4)!=(name!='/bin/dvbt_board'):raise ValueError('Staging compression flag did not persist')
            finally:os.close(fd)
    mkfs_compressor='none' if fs_compressor=='lzo-raw-elf' else fs_compressor
    command = [str(MKFS),'-r',str(staging),'-m','2048','-e','126976','-c','321',
               '-o',str(image),'-x',mkfs_compressor,'-f','8','-l','4','-p','1']
    with (OUTPUT/'mkfs.log').open('x') as log:
        subprocess.run(command,stdout=log,stderr=subprocess.STDOUT,check=True,timeout=300)
    inspected = inspect_image(image)
    crc_report = verify_index_crc(image)
    sb = inspected['superblock']
    if sb['fmt_version']!=4 or sb['flags']!=0 or sb['min_io_size']!=2048 or sb['leb_size']!=126976:
        raise ValueError('Incompatible rebuilt UBIFS superblock')
    if image.stat().st_size>0x2800000 or sb['leb_cnt']>321 or image.stat().st_size % 126976:
        raise ValueError('APP exceeds original volume geometry')
    indexed = {r['path']:r for r in inspected['entries']}
    if inspected['issues'] or inspected['unreachable_indexed_inode_count'] or indexed.keys()!=expected.keys():
        raise ValueError('Rebuilt committed index differs')
    for name, old in expected.items():
        row=indexed[name]
        fields=('type','mode','uid','gid','nlink','mtime_sec','mtime_nsec')
        if any(row[k]!=old[k] for k in fields):
            raise ValueError('Rebuilt inode metadata mismatch: '+name)
        if row['type']=='symlink' and row['symlink_target']!=old['symlink_target']:
            raise ValueError('Rebuilt symlink changed')
    with (OUTPUT/'reextract.log').open('x') as log:
        subprocess.run([str(READER),'-e','126976','-o',str(extracted),str(image)],
                       stdout=log,stderr=subprocess.STDOUT,check=True,timeout=300)
    decoded = inventory(extracted)
    if decoded.keys()!=staged.keys():
        raise ValueError('Second extraction path set mismatch')
    for name,row in staged.items():
        other=decoded[name]
        if row['type']!=other['type'] or (row['type']=='regular' and row['sha256']!=other['sha256']) or (row['type']=='symlink' and row['symlink_target']!=other['symlink_target']):
            raise ValueError('Second extraction content mismatch: '+name)
    if sha(original)!=ORIGINAL_APP_SHA or inventory(SOURCE)!=before:
        raise ValueError('Original data changed during build')
    copied=OUTPUT/'08_APP.ubifs'
    shutil.copyfile(image,copied)
    report = dict(status='offline_app_candidate_roundtrip_verified',television_tested=False,flash_ready=False,
        original_app_sha256=ORIGINAL_APP_SHA,app_sha256=sha(copied),app_bytes=copied.stat().st_size,
        command=command,filesystem_compressor=fs_compressor,
        compressor_evidence='analiz/native-ui-port-v8/kernel-compression.json' if fs_compressor=='zlib' else 'analiz/native-ui-port-v8/selective-compression-probe.json' if fs_compressor=='lzo-raw-elf' else None,
        mkfs_sha256=sha(MKFS),original_superblock=source_meta['superblock'],
        candidate_superblock=sb,files_verified=sum(r['type']=='regular' for r in expected.values()),metadata_entries_verified=len(indexed),
        committed_node_crc=crc_report,
        directories_verified=sum(r['type']=='directory' for r in expected.values()),symlinks_verified=1,unreachable_indexed_inodes=0,
        original_metadata_entries_verified=2773,declared_added_inodes=additions,
        original_directory_nlink_policy='increased only for explicitly added immediate child directories',
        changed_files=[dict(path=r['path'],original_sha256=r['original_sha256'],candidate_sha256=r['candidate_sha256']) for r in overlays],
        unchanged_regular_files=2371-sum(r['original_sha256'] is not None for r in overlays),
        checks=['source hash pinned','canonical source compared with fresh pinned-original APP extraction','all original inode modes/uid/gid/mtime restored',
                'committed index paths/types/metadata roundtrip','all reextracted file bytes and symlink targets match staging',
                'original source hashes unchanged'],
        limitations=['No kernel mount, target execution or television test.',
            'New UBIFS node placement, inode numbers, UUID, and generated filesystem bookkeeping are not byte-identical.',
            'No firmware signature/boot acceptance claim. Native rendering must be checked on target before installation approval.'])
    save(OUTPUT/'app-build-validation.json',report)
    save(OUTPUT/'app-index.json',inspected)
    if revision in ('v3','v8','v7-tv','v7.1-tv','v7.2-tv','v7.3-tv','v7.4-tv','v7.5-tv','v7.6-tv','v7.7-tv','v7.8-tv','v7.9-tv','v7.10-tv'):
        shutil.copyfile(ROOT/f'analiz/native-ui-candidate/{revision}/manifest.json',OUTPUT/'overlay-manifest.json')
        shutil.copyfile(ROOT/'analiz/native-png-probe/decode-result.json',OUTPUT/'png-decoder-validation.json')
    else:
        for name in ('assets','volume'):
            shutil.copyfile(ROOT/f'analiz/native-ui-candidate/v1/{name}/manifest.json',OUTPUT/f'{name}-manifest.json')
    print(json.dumps({k:report[k] for k in ('status','app_bytes','app_sha256','files_verified','metadata_entries_verified','unchanged_regular_files')}),flush=True)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--revision',choices=REVISIONS,default='v2')
    parser.add_argument('--fs-compressor',choices=('lzo','zlib','lzo-raw-elf'),default='lzo')
    args=parser.parse_args();main(args.revision,args.fs_compressor)
