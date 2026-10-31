"""Build distinct second-stage filesystems, preserving every previous release."""
import argparse
import json
from pathlib import Path
import build_native_hevc_diag as build


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('partition', choices=['mslib', 'customer'])
    args = parser.parse_args()
    build.REVISION = 'v7.9-hevc-diag2'
    build.OUT = build.ROOT/f'analiz/native-ui-candidate/{build.REVISION}/package'
    build.HOOK = build.ROOT/'analiz/native-4k/diag-hooks/stage2-sync/libmsrv_common.so'
    proof = json.loads((build.HOOK.parent/'patch-proof.json').read_text())
    build.HOOK_SHA = proof['candidate_sha256']
    build.COLLECTOR = build.ROOT/'analiz/native-4k/diag-sink/build-v3/modgrundig-diag-sink'
    build.WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1/customer-v79-hevc-diag2')
    build.configure()
    build.m.WORK = Path('/home/semih/.local/share/grundig-analysis/native-build-v1/mslib-v79-hevc-diag2')
    if args.partition == 'mslib':
        build.m.main(build.HOOK, build.HOOK_SHA)
    else:
        build.customer()


if __name__ == '__main__': main()
