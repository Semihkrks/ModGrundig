"""Prepare a resource-only half-margin review; no package or icon runtime change.

The exact V7.8 NUM is accepted. Only normal-volume root X resource0x5a41
changes80→40. Full V7.7/V7.8 releases and original files stay untouched.
"""
import hashlib
import json
from pathlib import Path
import struct

from build_native_ui_v78_tv import ROOT, verified_packaging_records
from native_ui_v71_volume import layout

OUT = ROOT / 'analiz/native-ui-candidate/v7.9-margin-review'
RELATIVE = '08_APP/rc/rc/bin/Num_res.bin'
INPUT_SHA = '7ec3f2236f8b6061fdf22c65af37042a84b713805fac823bc228d74d9e39047a'
RESOURCE = 0x5a41
OFFSET = 56 + RESOURCE*4


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def transform(raw):
    if sha(raw) != INPUT_SHA or struct.unpack_from('<I', raw, OFFSET)[0] != 80:
        raise ValueError('Expected exact V7.8 NUM with normal root margin80')
    changed = bytearray(raw)
    struct.pack_into('<I', changed, OFFSET, 40)
    changed = bytes(changed)
    different = [i for i, (a, b) in enumerate(zip(raw, changed)) if a != b]
    if not different or any(not OFFSET <= i < OFFSET+4 for i in different):
        raise ValueError('Margin delta escaped the one resource')
    before, after = layout(raw), layout(changed)
    for name in ('root', 'panel', 'speaker', 'number', 'track'):
        if after[name] != [before[name][0]-40, *before[name][1:]]:
            raise ValueError('Unexpected child geometry change: '+name)
    n = lambda rid: struct.unpack_from('<I', changed, 56+rid*4)[0]
    outer = [n(rid) for rid in (0x5bf0, 0x5bf1, 0x5bef, 0x5bee)]
    rx, ry, rw, rh = after['root']
    if outer != [0,160,160,725] or rx < 0 or ry < 0 or rx+rw > outer[2] or ry+rh > outer[3]:
        raise ValueError('Root no longer contained in original native window')
    px, py, pw, ph = after['panel']
    for name in ('speaker', 'number', 'track'):
        x,y,w,h = after[name]
        if x < px or y < py or x+w > px+pw or y+h > py+ph:
            raise ValueError('Child outside panel: '+name)
    proof = dict(status='PASS_RESOURCE_ONLY_HALF_MARGIN_REVIEW', resource_id=hex(RESOURCE),
                 byte_offset=OFFSET, changed_byte_offsets=different,
                 source_sha256=INPUT_SHA, candidate_sha256=sha(changed),
                 before_geometry=before, after_geometry=after,
                 outer_frame=outer, left_gap_before=80, left_gap_after=40,
                 basis='1920x1080 logical resources; real TV scaling/overscan unmeasured',
                 icons_changed=False, runtime_icon_thresholds_installed=False,
                 requested_icon_proposal=dict(low='1..20', medium='21..60', high='61..100', mute='0 or mute'),
                 icon_approval_pending=True, firmware_packaged=False, television_written=False)
    return changed, proof


def candidate():
    records = verified_packaging_records()
    record = next(r for r in records if r['path'] == '/rc/rc/bin/Num_res.bin')
    return transform(record['candidate'].read_bytes())


def guard(path):
    if not path.resolve().is_relative_to(OUT.resolve()):
        raise ValueError('Review path escape')
    current = path
    while current != ROOT:
        if current.is_symlink() or (hasattr(current,'is_junction') and current.is_junction()):
            raise ValueError('Aliased review output')
        if current.is_file() and current.stat().st_nlink != 1:
            raise ValueError('Hardlinked review output')
        current = current.parent


def verified_margin_resource():
    raw, proof = candidate()
    path = OUT / 'overlay' / RELATIVE
    guard(path)
    if path.read_bytes() != raw:
        raise ValueError('Review NUM differs from derived single-resource transform')
    return raw, path, proof


def main():
    raw, proof = candidate()
    files = {OUT/'overlay'/RELATIVE:raw,
             OUT/'margin-proof.json':(json.dumps(proof,indent=2,ensure_ascii=False)+'\n').encode('utf-8')}
    for path,data in files.items():
        guard(path)
        path.parent.mkdir(parents=True,exist_ok=True)
        guard(path)
        if path.exists():
            if path.read_bytes() != data:
                raise FileExistsError('Existing review output differs')
        else:
            with path.open('xb') as stream:stream.write(data)
    verified_margin_resource()
    print(json.dumps(proof))


if __name__ == '__main__':
    main()
