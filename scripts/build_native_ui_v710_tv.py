"""Offline menu-only SEMIH branding over the preserved V7.9 candidate.

Fast zapping remains the real native user-controlled setting. This candidate
makes no fast-boot, decoder, tuner, power-management or live database changes.
"""
import hashlib
import json
import os
from pathlib import Path

import build_native_ui_v79_tv as previous

ROOT = previous.ROOT
SOURCE = previous.SOURCE
MENU_PREFIX = previous.MENU_PREFIX
OUT = ROOT / 'analiz/native-ui-candidate/v7.10-tv'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def guard(path):
    boundary = ROOT.resolve() / 'analiz/native-ui-candidate/v7.10-tv'
    if OUT.resolve() != boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V7.10 output boundary')
    cursor = path
    while cursor != ROOT:
        if cursor.is_symlink() or (hasattr(cursor, 'is_junction') and cursor.is_junction()):
            raise ValueError('Aliased V7.10 output')
        if cursor.is_file() and cursor.stat().st_nlink != 1:
            raise ValueError('Hardlinked V7.10 output')
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
        raise ValueError('V7.10 write readback differs')


def expected_payloads():
    from native_semih_brand import apply, expected_payloads as brand_assets
    rows = previous.verified_packaging_records()
    payloads = {'08_APP' + row['path']: row['candidate'].read_bytes() for row in rows}
    provenance = {'08_APP' + row['path']: row['original_sha256'] for row in rows}
    payloads['08_APP/bin/dvbt_board'], code_proof = apply(payloads['08_APP/bin/dvbt_board'])
    images, table, asset_proof = brand_assets(payloads['08_APP/rc/rc/bin/Image_res.bin'])
    payloads['08_APP/rc/rc/bin/Image_res.bin'] = table
    for relative, raw in images.items():
        if relative in payloads or (SOURCE/relative).exists():
            raise ValueError('Private menu logo collides with an existing path')
        payloads[relative] = raw
        provenance[relative] = None
    scope = dict(source_revision='v7.9-tv',
                 source_manifest_sha256=sha((previous.OUT/'manifest.json').read_bytes()),
                 menu_brand_code=code_proof, menu_brand_asset=asset_proof,
                 font_exactness='Constructed SEMIH glyphs matching the bitmap style; OEM font not recoverable',
                 native_logo_geometry_preserved=True,
                 fast_zapping_native_setting_available=True,
                 fast_zapping_live_user_setting='Unknown; enable using the existing General/Advanced setting',
                 fast_zapping_forced=False, fast_boot_enabled=False,
                 fast_boot_reason='Compiled standby path suspends; no verified fast-boot conditional path',
                 volume_and_numeric_v79_preserved=True,
                 v78_default_transponder_preserved=True, four_k_decoder_changes=False,
                 television_tested=False)
    scope = json.loads(json.dumps(scope, ensure_ascii=False))
    return payloads, provenance, scope


def verified_records():
    payloads, provenance, scope = expected_payloads()
    guard(OUT / 'manifest.json')
    manifest = json.loads((OUT / 'manifest.json').read_text(encoding='utf-8'))
    if manifest['scope'] != scope or len(manifest['records']) != len(payloads):
        raise ValueError('V7.10 reconstructed manifest differs')
    result, seen = [], set()
    for row in manifest['records']:
        relative = row['relative_path']
        if relative in seen or relative not in payloads:
            raise ValueError('Unexpected V7.10 record')
        seen.add(relative)
        path = OUT / 'overlay' / relative
        guard(path)
        if row['original_sha256'] != provenance[relative] or sha(payloads[relative]) != row['candidate_sha256'] or path.read_bytes() != payloads[relative]:
            raise ValueError('V7.10 candidate/provenance differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=provenance[relative], candidate_sha256=row['candidate_sha256']))
    return result


def verified_packaging_records():
    from native_ui_v710_tv_pins import MANIFEST_SHA, RECORDS
    guard(OUT / 'manifest.json')
    raw = (OUT / 'manifest.json').read_bytes()
    if sha(raw) != MANIFEST_SHA:
        raise ValueError('V7.10 manifest code pin differs')
    manifest = json.loads(raw)
    if [(r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in manifest['records']] != list(RECORDS):
        raise ValueError('V7.10 record code pins differ')
    result = []
    for relative, original, candidate, size in RECORDS:
        path = OUT / 'overlay' / relative
        guard(path)
        if path.stat().st_size != size or sha(path.read_bytes()) != candidate:
            raise ValueError('V7.10 overlay code pin differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=original, candidate_sha256=candidate))
    return result


def main():
    guard(OUT / 'manifest.json')
    if (OUT / 'manifest.json').exists():
        rows = verified_records()
        verified_packaging_records()
        print(json.dumps(dict(status='verified_v710_tv', files=len(rows))))
        return
    if OUT.exists() and any(OUT.iterdir()):
        raise FileExistsError('Refusing partial V7.10 directory')
    payloads, provenance, scope = expected_payloads()
    records = []
    for relative, raw in sorted(payloads.items()):
        write_new(OUT / 'overlay' / relative, raw)
        records.append(dict(relative_path=relative, original_sha256=provenance[relative],
                            candidate_sha256=sha(raw), bytes=len(raw)))
    raw = (json.dumps(dict(revision='v7.10-tv', scope=scope, records=records,
                           television_tested=False, flash_ready=False), ensure_ascii=False, indent=2) + '\n').encode('utf-8')
    write_new(OUT / 'manifest.json', raw)
    pins = ROOT / 'scripts/native_ui_v710_tv_pins.py'
    tuples = tuple((r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in records)
    with pins.open('x', encoding='utf-8') as stream:
        stream.write('# Fixed V7.10 menu-brand candidate identities.\nMANIFEST_SHA = ' + repr(sha(raw)) + '\nRECORDS = ' + repr(tuples) + '\n')
        stream.flush()
        os.fsync(stream.fileno())
    verified_packaging_records()
    print(json.dumps(dict(status='built_v710_tv', files=len(records))))


if __name__ == '__main__':
    main()
