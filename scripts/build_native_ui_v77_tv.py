"""Separate V7.7 TV overlay, correcting issues observed on the user's V7 TV.

Original firmware and the physically tested V7 candidate remain untouched.
Native channel feedback and persistent mute resources are updated; no update code runs.
"""
import hashlib
import json
import os
from pathlib import Path

import build_native_ui_v74_tv as previous

ROOT = previous.ROOT
SOURCE = previous.SOURCE
MENU_PREFIX = previous.MENU_PREFIX
OUT = ROOT / 'analiz/native-ui-candidate/v7.7-tv'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def guard(path):
    boundary = ROOT.resolve() / 'analiz/native-ui-candidate/v7.7-tv'
    if OUT.resolve() != boundary or not path.resolve().is_relative_to(boundary):
        raise ValueError('V7.7 output boundary')
    cursor = path
    while cursor != ROOT:
        if cursor.is_symlink() or (hasattr(cursor, 'is_junction') and cursor.is_junction()):
            raise ValueError('Aliased V7.7 output')
        if cursor.is_file() and cursor.stat().st_nlink != 1:
            raise ValueError('Hardlinked V7.7 output')
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
        raise ValueError('V7.7 write readback differs')


def expected_payloads():
    import struct
    from native_ui_v77_name import code_create, code_update, unwind_frames, proof, CREATE, UPDATE, extras, hook_records
    from native_ui_v77_elf import append_payload
    from build_native_volume_patch import elf_va_offset
    rows = previous.verified_packaging_records()
    payloads = {'08_APP' + row['path']: row['candidate'].read_bytes() for row in rows}
    provenance = {'08_APP' + row['path']: row['original_sha256'] for row in rows}
    original = payloads['08_APP/bin/dvbt_board']
    from native_ui_v77_mute import EXTRA_HELPERS, unwind_frames as mute_frames
    extended, placement = append_payload(original, code_create(), code_update(), unwind_frames=unwind_frames()+mute_frames(), extras=extras()+EXTRA_HELPERS)
    patched = bytearray(extended)
    jal = lambda target: 0x0c000000 | ((target >> 2) & 0x03ffffff)
    hooks = hook_records()
    for va, old, new in hooks:
        off = elf_va_offset(original, va, 4)
        if struct.unpack_from('<I', original, off)[0] != old:
            raise ValueError('Numeric original hook differs: ' + hex(va))
        struct.pack_into('<I', patched, off, new)
    for va, word in ((0x8968b4, 0x03c0e821), (0x8957d0, 0), (0x895a70, 0)):
        if struct.unpack_from('<I', original, elf_va_offset(original, va, 4))[0] != word:
            raise ValueError('Numeric hook delay context differs')
    payloads['08_APP/bin/dvbt_board'] = bytes(patched)
    from native_ui_v76_mute import apply as apply_mute
    payloads, mute_proof = apply_mute(payloads)
    provenance.update(mute_proof['added_original_sha256'])
    from native_ui_v77_mute import apply as apply_flow
    payloads, flow_proof = apply_flow(payloads)
    scope = dict(mute_flow=flow_proof, mute_visual=mute_proof, source_revision='v7.4-tv', source_v71_working_base_preserved=True,
                 name_bridge=proof(), elf_placement=placement,
                 hooks=[dict(va=hex(va), old=hex(old), new=hex(new)) for va, old, new in hooks],
                 menus_original=True, settings_original=True,
                 volume_gp_fix_preserved=True, channel_tuning_and_original_timer_0_1_preserved=True, numeric_countdown_removed=True,
                 no_fabricated_channels_in_firmware=True, v77_television_tested=False)
    # DWARF register maps have integer keys; match their serialized JSON form.
    scope = json.loads(json.dumps(scope, ensure_ascii=False))
    return payloads, provenance, scope


def verified_records():
    payloads, provenance, scope = expected_payloads()
    guard(OUT / 'manifest.json')
    manifest = json.loads((OUT / 'manifest.json').read_text(encoding='utf-8'))
    if manifest['scope'] != scope or len(manifest['records']) != len(payloads):
        raise ValueError('V7.7 reconstructed manifest differs')
    result, seen = [], set()
    for row in manifest['records']:
        relative = row['relative_path']
        if relative in seen or relative not in payloads:
            raise ValueError('Unexpected V7.7 record')
        seen.add(relative)
        path = OUT / 'overlay' / relative
        guard(path)
        if row['original_sha256'] != provenance[relative] or sha(payloads[relative]) != row['candidate_sha256'] or path.read_bytes() != payloads[relative]:
            raise ValueError('V7.7 candidate/provenance differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=provenance[relative], candidate_sha256=row['candidate_sha256']))
    return result


def verified_packaging_records():
    from native_ui_v77_tv_pins import MANIFEST_SHA, RECORDS
    guard(OUT / 'manifest.json')
    raw = (OUT / 'manifest.json').read_bytes()
    if sha(raw) != MANIFEST_SHA:
        raise ValueError('V7.7 manifest code pin differs')
    manifest = json.loads(raw)
    if [(r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in manifest['records']] != list(RECORDS):
        raise ValueError('V7.7 record code pins differ')
    result = []
    for relative, original, candidate, size in RECORDS:
        path = OUT / 'overlay' / relative
        guard(path)
        if path.stat().st_size != size or sha(path.read_bytes()) != candidate:
            raise ValueError('V7.7 overlay code pin differs')
        result.append(dict(path='/' + Path(relative).relative_to('08_APP').as_posix(), candidate=path,
                           original_sha256=original, candidate_sha256=candidate))
    return result


def main():
    guard(OUT / 'manifest.json')
    if (OUT / 'manifest.json').exists():
        rows = verified_records()
        verified_packaging_records()
        print(json.dumps(dict(status='verified_v77_tv', files=len(rows))))
        return
    if OUT.exists() and any(OUT.iterdir()):
        raise FileExistsError('Refusing partial V7.7 directory')
    payloads, provenance, scope = expected_payloads()
    records = []
    for relative, raw in sorted(payloads.items()):
        write_new(OUT / 'overlay' / relative, raw)
        records.append(dict(relative_path=relative, original_sha256=provenance[relative],
                            candidate_sha256=sha(raw), bytes=len(raw)))
    raw = (json.dumps(dict(revision='v7.7-tv', scope=scope, records=records,
                           television_tested=False, flash_ready=False), ensure_ascii=False, indent=2) + '\n').encode('utf-8')
    write_new(OUT / 'manifest.json', raw)
    pins = ROOT / 'scripts/native_ui_v77_tv_pins.py'
    tuples = tuple((r['relative_path'], r['original_sha256'], r['candidate_sha256'], r['bytes']) for r in records)
    with pins.open('x', encoding='utf-8') as stream:
        stream.write('# Fixed V7.7 volume/numeric candidate identities.\nMANIFEST_SHA = ' + repr(sha(raw)) + '\nRECORDS = ' + repr(tuples) + '\n')
        stream.flush()
        os.fsync(stream.fileno())
    verified_packaging_records()
    print(json.dumps(dict(status='built_v77_tv', files=len(records))))


if __name__ == '__main__':
    main()
