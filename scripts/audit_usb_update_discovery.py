"""Offline USB discovery audit. Does not run firmware or any update command."""
from pathlib import Path
import hashlib
import json
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-ui-candidate/v7-tv'
IMAGE_SHA = '3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71'
STOCK_SHA = '6d7614730c5f63b9e6727b8b329606b188b581efb366bffde6991aca123852c0'
EXPECTED_PATH = 'Target_GM/image/GM_SWImage.bin'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def main():
    evidence = json.loads((ROOT / 'analiz/native/ui-targeted/usb-update-v1/discovery-and-error-evidence.json').read_text(encoding='utf-8'))
    native_path = ROOT / 'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board'
    raw = native_path.read_bytes()
    if sha(raw) != '51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916':
        raise ValueError('Original application differs')
    if raw[0xbe67bc:0xbe67bc + len(EXPECTED_PATH) + 1] != ('/' + EXPECTED_PATH).encode():
        raise ValueError('USB path constant differs')
    usb_root = OUT / 'vendor-rar-readback'
    if sha((usb_root / EXPECTED_PATH).read_bytes()) != IMAGE_SHA:
        raise ValueError('Extracted V7 USB root does not contain V7')
    rar = ROOT / 'devir-paketi/Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar'
    original_rar_hash = sha(rar.read_bytes())
    exe = '/mnt/c/Users/Semih/Desktop/grundig/tools/7zip-linux/7zz'
    linux_rar = '/mnt/c/Users/Semih/Desktop/grundig/' + rar.relative_to(ROOT).as_posix()
    listing = subprocess.run(['wsl', '-d', 'Ubuntu', '--', exe, 'l', '-slt', linux_rar],
                             check=True, capture_output=True, encoding='utf-8').stdout
    members = []
    for block in re.split(r'\r?\n\s*\r?\n', listing.split('----------', 1)[1]):
        fields = dict(line.split(' = ', 1) for line in block.splitlines() if ' = ' in line)
        if fields.get('Path', '').endswith('/GM_SWImage.bin'):
            members.append(fields['Path'])
    images = []
    for name in members:
        content = subprocess.run(['wsl', '-d', 'Ubuntu', '--', exe, 'e', '-so', linux_rar, name],
                                 check=True, capture_output=True).stdout
        digest = sha(content)
        images.append(dict(member=name, sha256=digest, is_v7=digest == IMAGE_SHA,
                           is_original=digest == STOCK_SHA, expected_root_path=name == EXPECTED_PATH))
    if sha(rar.read_bytes()) != original_rar_hash:
        raise ValueError('Working RAR changed during audit; rerun for a coherent snapshot')
    result = dict(observed_date='2026-10-25', method='offline source constants, retained Ghidra and host archive inspection',
                  rea_evidence=False, expected_usb_root_relative_path=EXPECTED_PATH,
                  expected_path_va='0x00fe67bc', expected_path_file_offset='0x00be67bc',
                  discovery_function='ArTvSettingsManager::CheckUSBUpdate @ 0x005432f8',
                  usb_click_handler='SoftwareUpdateFrame USB handler @ 0x00ed09ac',
                  version_comparison_in_discovery=False,
                  error_string_id='0x0e44', error_return_codes=[1, 2],
                  no_file_return_code=1, environment_failure_return_code=2,
                  localized_error='Daha yeni sürümün güncelleme verisi yoktur.',
                  working_rar_sha256=original_rar_hash, working_archive_images=images,
                  prepared_usb_root=str(usb_root.relative_to(ROOT)), prepared_root_v7_sha256=IMAGE_SHA,
                  prepared_layout_matches_static_lookup=True,
                  source_evidence='analiz/native/ui-targeted/usb-update-v1/discovery-and-error-evidence.json',
                  source_evidence_present=bool(evidence),
                  versions_changed=False, bootloader_changed=False,
                  firmware_executed=False, device_write_performed=False, television_tested=False,
                  limits=['File lookup success does not establish subsequent bootloader acceptance.',
                          'The same popup also covers unavailable environment manager.',
                          'Host folder checks do not observe the actual USB device or mount.'])
    (OUT / 'package/usb-discovery-audit.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({key: result[key] for key in ('expected_usb_root_relative_path', 'working_archive_images',
                     'prepared_layout_matches_static_lookup', 'versions_changed', 'television_tested')}, ensure_ascii=False))


if __name__ == '__main__':
    main()
