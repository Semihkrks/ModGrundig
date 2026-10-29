"""Compare independently re-extracted APP trees, V7.7 to V7.8; no target execution."""
import json
from pathlib import Path

from build_native_app import ROOT, WORK, inventory, sha
from build_native_ui_v78_tv import OUT, guard, verified_packaging_records


def main():
    before_image = ROOT / 'analiz/native-ui-candidate/v7.7-tv/package/08_APP.ubifs'
    after_image = OUT / 'package/08_APP.ubifs'
    if sha(before_image) != 'a2580820eaa30e453378095f30d69c6d25507a82e5e5701363dddb187688c9a6':
        raise ValueError('V7.7 APP differs from the physically tested package')
    before = inventory(WORK / 'app-reextracted-v7.7-tv-lzo-raw-elf')
    after = inventory(WORK / 'app-reextracted-v7.8-tv-lzo-raw-elf')
    if before.keys() != after.keys():
        raise ValueError('V7.8 differs in filesystem paths')
    changed, files, links = [], 0, 0
    for name, old in before.items():
        current = after[name]
        if old['type'] != current['type']:
            raise ValueError('Filesystem type differs: '+name)
        if old['type'] == 'regular':
            files += 1
            if old['sha256'] != current['sha256']:
                changed.append(name)
        elif old['type'] == 'symlink':
            links += 1
            if old['symlink_target'] != current['symlink_target']:
                raise ValueError('Symlink target differs')
    if changed != ['/defaults/frequency_tables.tar.gz']:
        raise ValueError('V7.8 changes other than the RF table: '+repr(changed))
    records = verified_packaging_records()
    table = next(r for r in records if r['path'] == changed[0])
    if (after[changed[0]]['sha256'] != table['candidate_sha256'] or
            before[changed[0]]['sha256'] != table['original_sha256']):
        raise ValueError('Re-extracted RF table differs from pinned overlay')
    report = dict(status='PASS_REEXTRACTED_V77_V78_DATA_ONLY_DELTA',
                  compared_regular_files=files, unchanged_regular_files=files-1,
                  changed_files=changed, symlinks_compared=links,
                  app_v77_sha256=sha(before_image), app_v78_sha256=sha(after_image),
                  all_v77_native_code_and_ui_file_bytes_preserved=True,
                  metadata_validation='Separate app-build-validation.json and independent-readback.json',
                  firmware_executed=False, device_written=False, four_k_unlock_proven=False)
    destination = OUT / 'package/v77-v78-delta-validation.json'
    guard(destination)
    with destination.open('x', encoding='utf-8') as stream:
        json.dump(report, stream, ensure_ascii=False, indent=2)
        stream.write('\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
