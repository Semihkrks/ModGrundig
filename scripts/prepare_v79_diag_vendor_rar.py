"""Reuse exact vendor RAR block preservation for a distinct diagnostic release."""
import json
from pathlib import Path
import build_native_mslib as guard_module

ROOT = Path(__file__).resolve().parents[1]


def main():
    revision = 'v7.9-hevc-diag'
    guard_module.REVISION = revision
    import prepare_v79_audio_vendor_rar as archive
    out = ROOT/f'analiz/native-ui-candidate/{revision}'
    proof = json.loads((out/'package/independent-readback.json').read_text())
    if proof['status'] != 'PASS_OFFLINE_ONLY' or proof['changed_payloads'] != [7, 11]:
        raise ValueError('Reviewed diagnostic container proof required')
    archive.OUT = out
    archive.IMAGE_SHA = proof['container_sha256']
    archive.IMAGE_NAME = 'GM_SWImage_UI_v7.9-hevc-diag_OFFLINE_UNVERIFIED.bin'
    archive.DEST = out/'package/GMGRMR.-.-.-.-.V03.017.04_V7.9_HEVC_DIAG.rar'
    archive.EXTRACTED = out/'vendor-rar-readback'
    archive.REPORT = out/'package/vendor-rar-validation.json'
    archive.prepare()


if __name__ == '__main__':
    main()
