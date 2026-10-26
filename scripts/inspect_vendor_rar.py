"""Read-only vendor RAR audit; never execute embedded scripts or programs."""
from pathlib import Path, PurePosixPath
import hashlib
import json
import re
import subprocess
import zipfile
import zlib

ROOT = Path(__file__).resolve().parents[1]
RAR = ROOT / 'devir-paketi/Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar'
EXTRACTED = ROOT / 'analiz/firmware-dogrulanmis'
REPORT = ROOT / 'analiz/vendor-rar-inspection.json'
EXPECTED_SHA = 'dd0d297d0611f240e1336042483ee46ec73a7b9f669510f45664677f4950a46c'


def wsl_path(path):
    absolute = path.resolve()
    return '/mnt/' + absolute.drive[0].lower() + absolute.as_posix()[2:]


def archive_command(action):
    result = subprocess.run(
        ['wsl', '-d', 'Ubuntu', '--', wsl_path(ROOT / 'tools/7zip-linux/7zz'),
         action, *(['-slt'] if action == 'l' else []), wsl_path(RAR)],
        check=True, capture_output=True, encoding='utf-8')
    return result.stdout


def inspect():
    archive_sha = hashlib.sha256(RAR.read_bytes()).hexdigest()
    if archive_sha != EXPECTED_SHA:
        raise ValueError('Original RAR differs from recorded source')
    listing = archive_command('l')
    tested = archive_command('t')
    if 'Everything is Ok' not in tested:
        raise ValueError('RAR integrity check did not report success')
    entries = []
    for block in re.split(r'\r?\n\s*\r?\n', listing.split('----------', 1)[1]):
        fields = dict(line.split(' = ', 1) for line in block.splitlines() if ' = ' in line)
        if 'Path' not in fields:
            continue
        relative = PurePosixPath(fields['Path'])
        if relative.is_absolute() or '..' in relative.parts or '\\' in fields['Path']:
            raise ValueError('Unsafe archive member path')
        local = EXTRACTED.joinpath(*relative.parts)
        if not local.resolve().is_relative_to(EXTRACTED.resolve()) or local.is_symlink():
            raise ValueError('Extracted member escapes expected root')
        item = {'path': relative.as_posix(), 'directory': fields['Folder'] == '+',
                'bytes': int(fields['Size']), 'archive_crc32': fields['CRC']}
        if item['directory']:
            item['extracted_directory_present'] = local.is_dir()
        else:
            content = local.read_bytes()
            item['extracted_crc32_matches'] = f'{zlib.crc32(content):08X}' == fields['CRC']
            item['extracted_size_matches'] = len(content) == item['bytes']
            if not item['extracted_crc32_matches'] or not item['extracted_size_matches']:
                raise ValueError('Existing extracted member differs from RAR: ' + str(relative))
            item['sha256'] = hashlib.sha256(content).hexdigest()
        entries.append(item)
    member_paths = {e['path'] for e in entries if not e['directory']}
    scripts = []
    for item in entries:
        if item['directory'] or not item['path'].startswith('Target_GM/script/'):
            continue
        rows, references = [], []
        for number, line in enumerate((EXTRACTED / item['path']).read_text(errors='replace').splitlines(), 1):
            if line.lstrip().startswith('#'):
                continue
            command = re.match(r'^\s*([a-z][a-z0-9_]{0,24})(?:\s|$)', line)
            if command:
                rows.append({'line': number, 'command': command[1]})
            for found in re.findall(r'/?Target_GM/[A-Za-z0-9_./\[\]-]+', line):
                reference = found.lstrip('/')
                references.append({'line': number, 'path': reference,
                                   'file_present_in_rar': reference in member_paths})
        scripts.append({'path': item['path'], 'commands_without_arguments': rows,
                        'references': references})
    missing = sorted({ref['path'] for script in scripts for ref in script['references']
                      if ref['path'].startswith('Target_GM/BIN_FILES/') and not ref['file_present_in_rar']})
    current_zip = ROOT / 'analiz/native-ui-candidate/v7-tv/package/V7_INCELEME_ADAYI.zip'
    with zipfile.ZipFile(current_zip) as bundle:
        if bundle.testzip() is not None:
            raise ValueError('V7 review ZIP CRC failed')
        zip_members = sorted(bundle.namelist())
        candidate_sha = hashlib.sha256(bundle.read('Target_GM/image/GM_SWImage.bin')).hexdigest()
    if candidate_sha != '3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71':
        raise ValueError('V7 ZIP contains an unexpected candidate')
    result = {
        'observed_date': '2026-10-25', 'method': '7-Zip 26.04 archive listing/test; local static text parsing',
        'rea_evidence': False, 'archive': str(RAR.relative_to(ROOT)), 'archive_sha256': archive_sha,
        'archive_test': 'PASS', 'files': sum(not e['directory'] for e in entries),
        'directories': sum(e['directory'] for e in entries),
        'all_extracted_files_match_archive_crc_and_size': True,
        'entries': entries, 'script_inventory': scripts,
        'absent_external_service_inputs': missing,
        'review_zip': {'members': zip_members, 'image_sha256': candidate_sha,
                       'vendor_files_not_in_review_zip': sorted(member_paths - set(zip_members)),
                       'complete_vendor_package': False},
        'limits': ['No embedded script/program or device-write command executed.',
                   'No secret values, certificates, or device identities included in this report.',
                   'Service script names/commands do not prove ordinary update prerequisites.',
                   'Original SWImage itself carries bootloader and other partition update operations.',
                   'USB discovery/entry procedure and acceptance on physical TV remain unverified.']}
    REPORT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: result[k] for k in ('archive_test', 'files', 'directories',
                      'all_extracted_files_match_archive_crc_and_size', 'absent_external_service_inputs')}, ensure_ascii=False))


if __name__ == '__main__':
    inspect()
