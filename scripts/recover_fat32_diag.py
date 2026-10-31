"""Read-only FAT32 orphan inspection of the explicitly authorised D: USB.

Never repairs/opens the volume for writing. Raw recovered data stays under
ignored tools/, and only strictly numeric MGDIAG lines are returned in reports.
"""
from array import array
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT/'tools/usb-recovery-2026-11-01'


def numeric_records(raw):
    result = []
    for match in re.finditer(rb'(?m)^(MGDIAG(?:_META)? [0-9]+(?: [0-9]+)*)\n', raw):
        line = match[1].decode('ascii'); fields = line.split()
        if any(len(v) > 10 or int(v) > 0xffffffff for v in fields[1:]):
            continue
        if fields[0] == 'MGDIAG_META' and len(fields) == 6:
            result.append(line)
        elif fields[0] == 'MGDIAG' and len(fields) == {'1': 10, '2': 4, '3': 5, '4': 13}.get(fields[1]):
            result.append(line)
    return result


def inspect(stream):
    stream.seek(0); boot = stream.read(512)
    if len(boot) != 512 or boot[510:] != b'\x55\xaa':
        raise ValueError('Invalid FAT boot sector')
    sector = struct.unpack_from('<H', boot, 11)[0]
    spc, fats = boot[13], boot[16]
    reserved = struct.unpack_from('<H', boot, 14)[0]
    per_fat, root = struct.unpack_from('<II', boot, 36)[0], struct.unpack_from('<I', boot, 44)[0]
    total = struct.unpack_from('<I', boot, 32)[0]
    if sector != 512 or spc not in [1, 2, 4, 8, 16, 32, 64, 128] or fats != 2:
        raise ValueError('Unexpected USB FAT geometry')
    data_start = (reserved+fats*per_fat)*sector
    cluster_bytes = sector*spc
    cluster_count = (total-reserved-fats*per_fat)//spc
    if not 65525 <= cluster_count <= 16000000:
        raise ValueError('Expected a bounded FAT32 USB')
    if per_fat*sector > 64*1024*1024:
        raise ValueError('FAT allocation exceeds read-only inspection budget')
    stream.seek(reserved*sector); raw_fat = stream.read(per_fat*sector)
    stream.seek((reserved+per_fat)*sector); mirror = stream.read(per_fat*sector)
    if raw_fat != mirror:
        raise ValueError('Mirrored FATs differ; no implicit choice or repair')
    fat = array('I'); fat.frombytes(raw_fat)
    if sys.byteorder != 'little': fat.byteswap()
    if len(fat) < cluster_count+2: raise ValueError('FAT shorter than volume geometry')

    def chain(start):
        seen = set()
        while 2 <= start < cluster_count+2:
            if start in seen: raise ValueError('Cluster loop; no recovery mutation')
            seen.add(start); yield start
            nxt = fat[start] & 0x0fffffff
            if nxt >= 0x0ffffff8: break
            if nxt in (0, 1, 0x0ffffff7): raise ValueError('Broken referenced cluster chain')
            start = nxt

    def read_cluster(cluster):
        stream.seek(data_start+(cluster-2)*cluster_bytes)
        raw = stream.read(cluster_bytes)
        if len(raw) != cluster_bytes: raise ValueError('Short cluster read')
        return raw

    reachable, seen_dirs, pending = set(), set(), [root]
    directory_entries = 0
    while pending:
        first = pending.pop()
        if first in seen_dirs: continue
        seen_dirs.add(first)
        clusters = list(chain(first)); reachable.update(clusters)
        ended = False
        for cluster in clusters:
            if ended: break
            block = read_cluster(cluster)
            for off in range(0, len(block), 32):
                entry = block[off:off+32]
                if entry[0] == 0: ended = True; break
                if entry[0] == 0xe5 or entry[11] & 0x0f == 0x0f or entry[11] & 8: continue
                if entry[:11] in (b'.          ', b'..         '): continue
                directory_entries += 1
                start = (struct.unpack_from('<H', entry, 20)[0]<<16)|struct.unpack_from('<H', entry, 26)[0]
                if start:
                    reachable.update(chain(start))
                    if entry[11] & 0x10: pending.append(start)
    orphan = {i for i in range(2, cluster_count+2)
              if fat[i] & 0x0fffffff not in (0, 0x0ffffff7) and i not in reachable}
    if len(orphan)*cluster_bytes > 1024*1024:
        raise ValueError('Orphan data exceeds diagnostic recovery budget')
    targeted = {fat[i] & 0x0fffffff for i in orphan}
    starts = sorted(orphan-targeted)
    if orphan and not starts: raise ValueError('Orphan cycle; no implicit repair')
    recovered, seen = [], set()
    for start in starts:
        clusters = list(chain(start))
        if not set(clusters).issubset(orphan): raise ValueError('Orphan links into live file')
        seen.update(clusters)
        raw = b''.join(read_cluster(c) for c in clusters)
        recovered.append(dict(start_cluster=start, clusters=clusters, raw=raw,
                              sha256=hashlib.sha256(raw).hexdigest(), numeric_records=numeric_records(raw)))
    if seen != orphan: raise ValueError('Not all orphan clusters accounted for')
    stream.seek(reserved*sector)
    if stream.read(len(raw_fat)) != raw_fat: raise ValueError('Volume changed during read')
    return dict(cluster_bytes=cluster_bytes, directory_entries=directory_entries,
                orphan_clusters=len(orphan), recovered=recovered, volume_open_mode='rb',
                volume_modified=False)


def main():
    if OUT.exists(): raise FileExistsError('Keep earlier recovered evidence')
    with open(r'\\.\D:', 'rb', buffering=0) as stream:
        result = inspect(stream)
    OUT.mkdir(parents=True)
    for row in result['recovered']:
        raw = row.pop('raw')
        row['raw_local_only_file'] = f"cluster-{row['start_cluster']}.raw"
        (OUT/row['raw_local_only_file']).write_bytes(raw)
    (OUT/'report.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__': main()
