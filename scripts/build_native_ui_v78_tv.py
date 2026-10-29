"""Separate V7.8 default transponder overlay over the physically tested V7.7.

Original firmware and the physically tested V7.7 candidate remain untouched.
Only the default RF transponder table is added over the verified V7.7 overlay.
"""
import hashlib
import json
import os
from pathlib import Path

import build_native_ui_v77_tv as previous

ROOT = previous.ROOT
SOURCE = previous.SOURCE
MENU_PREFIX = previous.MENU_PREFIX
OUT = ROOT / 'analiz/native-ui-candidate/v7.8-tv'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def guard(path):
    boundary = ROOT.resolve() / 'analiz/native-ui-candidate/v7.8-tv'
    if OUT.resolve() != boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V7.8 output boundary')
    cursor = path
    while cursor != ROOT:
        if cursor.is_symlink() or (hasattr(cursor, 'is_junction') and cursor.is_junction()):
            raise ValueError('Aliased V7.8 output')
        if cursor.is_file() and cursor.stat().st_nlink != 1:
            raise ValueError('Hardlinked V7.8 output')
        cursor = cursor.parent


def write_new(path, raw):
    guard(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    guard(path)
    with path.open('xb') as stream:
        stream.write(raw)
        stream.flush()
        os.fsync(stream.fileno())
    if path.read_bytes() != raw:
        raise ValueError('V7.8 write readback differs')


def expected_payloads():
    from native_ui_v78_transponder import RELATIVE, SOURCE_SHA, transform
    rows = previous.verified_packaging_records()
    payloads = {'08_APP' + row['path']: row['candidate'].read_bytes() for row in rows}
    provenance = {'08_APP' + row['path']: row['original_sha256'] for row in rows}
    source = SOURCE / RELATIVE
    candidate, tp_proof = transform(source.read_bytes())
    payloads[RELATIVE] = candidate
    provenance[RELATIVE] = SOURCE_SHA
    scope = dict(source_revision='v7.7-tv',
                 source_manifest_sha256=sha((previous.OUT/'manifest.json').read_bytes()),
                 transponder_update=tp_proof,
                 all_existing_v77_overlay_files_unchanged=True,
                 original_channel_database_untouched=True,
                 tuner_code_unchanged=True, decoder_code_unchanged=True,
                 ui_code_and_assets_unchanged=True,
                 no_verified_4k_decode_unlock_claim=True,
                 v78_television_tested=False)
    return payloads, provenance, scope


def verified_records():
    payloads, provenance, scope = expected_payloads()
    guard(OUT / 'manifest.json')
    manifest = json.loads((OUT / 'manifest.json').read_text(encoding='utf-8'))
    if manifest['scope'] != scope or len(manifest['records']) != len(payloads):
        raise ValueError('V7.8 reconstructed manifest differs')
    result, seen = [], set()
    for row in manifest['records']:
        relative = row['relative_path']
        if relative in seen or relative not in payloads:
            raise ValueError('Unexpected V7.8 record')
        seen.add(relative)
        path = OUT / 'overlay' / relative
        guard(path)
        if row['original_sha256'] != provenance[relative] or sha(payloads[relative]) != row['candidate_sha256'] or path.read_bytes() != payloads[relative]:
            raise ValueError('V7.8 candidate/provenance differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=provenance[relative], candidate_sha256=row['candidate_sha256']))
    return result


def verified_packaging_records():
    from native_ui_v78_tv_pins import MANIFEST_SHA, RECORDS
    guard(OUT / 'manifest.json')
    raw = (OUT / 'manifest.json').read_bytes()
    if sha(raw) != MANIFEST_SHA:
        raise ValueError('V7.8 manifest code pin differs')
    manifest = json.loads(raw)
    if [(r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in manifest['records']] != list(RECORDS):
        raise ValueError('V7.8 record code pins differ')
    result = []
    for relative, original, candidate, size in RECORDS:
        path = OUT / 'overlay' / relative
        guard(path)
        if path.stat().st_size != size or sha(path.read_bytes()) != candidate:
            raise ValueError('V7.8 overlay code pin differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=original, candidate_sha256=candidate))
    return result


def main():
    guard(OUT / 'manifest.json')
    if (OUT / 'manifest.json').exists():
        rows = verified_records()
        verified_packaging_records()
        print(json.dumps(dict(status='verified_v78_tv', files=len(rows))))
        return
    if OUT.exists() and any(OUT.iterdir()):
        raise FileExistsError('Refusing partial V7.8 directory')
    payloads, provenance, scope = expected_payloads()
    records = []
    for relative, raw in sorted(payloads.items()):
        write_new(OUT / 'overlay' / relative, raw)
        records.append(dict(relative_path=relative, original_sha256=provenance[relative],
                            candidate_sha256=sha(raw), bytes=len(raw)))
    raw = (json.dumps(dict(revision='v7.8-tv', scope=scope, records=records,
                           television_tested=False, flash_ready=False), ensure_ascii=False, indent=2) + '\n').encode('utf-8')
    write_new(OUT / 'manifest.json', raw)
    pins = ROOT / 'scripts/native_ui_v78_tv_pins.py'
    tuples = tuple((r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in records)
    with pins.open('x', encoding='utf-8') as stream:
        stream.write('# Fixed V7.8 volume/numeric candidate identities.\nMANIFEST_SHA = ' + repr(sha(raw)) + '\nRECORDS = ' + repr(tuples) + '\n')
        stream.flush()
        os.fsync(stream.fileno())
    verified_packaging_records()
    print(json.dumps(dict(status='built_v78_tv', files=len(records))))


if __name__ == '__main__':
    main()
