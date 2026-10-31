"""Independent stdlib envelope verifier for the V7.9 numeric diagnostic build."""
import hashlib
import json
from pathlib import Path
import struct
import zlib
from unpack_mstar import parse_header
from verify_native_audio_test import decode

ROOT = Path(__file__).resolve().parents[1]
BASE_SHA = 'ae6a322861e3b288294b0e4a5f5faf33cb41864439508b2fcee4f6d89ddba496'
APP_SHA = '438caad4b1fed4a908d018e154da7939f21a20c4440eab5bc9c6238f104ee4c1'


def require(ok, why):
    if not ok:
        raise ValueError(why)


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def normalize(rows):
    output = []
    for i, row in enumerate(rows):
        commands = []
        counts = dict.fromkeys(['filepartload', 'mscompress7', 'crc32', 'mw']+(['ubi'] if i == 7 else []), 0)
        for line in row['commands']:
            tokens = line.split()
            if i in (7, 11) and tokens[0] in counts and (tokens[0] != 'ubi' or tokens[1:2] == ['write']):
                key = tokens[0]
                index = {'filepartload': 4, 'mscompress7': 4, 'crc32': 2, 'mw': 2, 'ubi': 4}[key]
                tokens[index] = '<size-or-crc>'
                if key == 'ubi':
                    require(len(tokens) == 7 and tokens[3] == 'MSLIB', 'MSLIB write syntax differs')
                    tokens[5] = '<size-or-crc>'
                counts[key] += 1
            commands.append(tokens)
        if i in (7, 11):
            require(all(v == 1 for v in counts.values()), 'Changed command count differs')
        output.append(commands)
    return output


def normalize_entire_header(blob, rows):
    text = blob[:0x4000].split(b'\0', 1)[0]
    starts = {rows[i]['script_offset']: i for i in (7, 11)}
    result, offset, active = [], 0, None
    for line in text.splitlines(keepends=True):
        plain = line.rstrip(b'\r\n'); ending = line[len(plain):]
        if offset in starts:
            active = starts[offset]
        elif plain.startswith(b'# File Partition:'):
            active = None
        tokens = plain.split(b' ')
        key = tokens[0]
        if active is not None and key in (b'filepartload', b'mscompress7', b'crc32', b'mw'):
            tokens[4 if key in (b'filepartload', b'mscompress7') else 2] = b'<allowed-number>'
        if active == 7 and key == b'ubi' and tokens[1:2] == [b'write']:
            require(len(tokens) == 7 and tokens[1:4] == [b'write', b'0x80200000', b'MSLIB'], 'MSLIB write syntax differs')
            tokens[4] = tokens[5] = b'<allowed-number>'
        result.append(b' '.join(tokens)+ending)
        offset += len(line)
    return b''.join(result)


def verify(base, candidate, images):
    require(sha(base) == BASE_SHA, 'V7.9 baseline hash differs')
    require(len(base) == len(candidate) == 42483736, 'Container extent changed')
    parsed = []
    for blob in (base, candidate):
        footer = len(blob)-24
        require(blob[footer+8:] == b'# Script Size = ', 'Footer marker differs')
        require(struct.unpack_from('<I', blob, footer)[0] == zlib.crc32(blob[:0x4000]), 'Header CRC differs')
        require(struct.unpack_from('<I', blob, footer+4)[0] == zlib.crc32(blob[:footer+4]), 'Container CRC differs')
        text, pad = blob[:0x4000].split(b'\0', 1)
        require(not any(pad), 'Header padding nonzero')
        _, rows = parse_header(blob[:0x4000], footer)
        require(len(rows) == 14, 'Payload count differs')
        parsed.append(rows)
    require(normalize(parsed[0]) == normalize(parsed[1]), 'Update semantics changed beyond permitted lengths/CRCs')
    require(normalize_entire_header(base, parsed[0]) == normalize_entire_header(candidate, parsed[1]),
            'Header text changed beyond allowed numeric fields')
    report = []
    for i, (before, after) in enumerate(zip(*parsed)):
        require(before['source_offset'] == after['source_offset'], 'Payload relocated')
        end = parsed[0][i+1]['source_offset'] if i < 13 else len(base)-24
        for blob, row in ((base, before), (candidate, after)):
            require(row['source_offset']+row['compressed_bytes'] <= end, 'Fixed compressed slot overflow')
            require(not any(blob[row['source_offset']+row['compressed_bytes']:end]), 'Nonzero slot padding')
        old, new = decode(base, before), decode(candidate, after)
        if i in (7, 11):
            require(new == images[i] and len(new) <= 0x1c00000, 'Decoded candidate or RAM bound differs')
            require(int(after['load_address'], 16) == 0x81e00000 and
                    int(after['decompress_destination'], 16) == 0x80200000, 'Loader addresses changed')
            require(before['write_target'] == after['write_target'], 'UBI target changed')
            if i == 11:
                require(after['write_bytes'] == before['write_bytes'] == 0x300000 and len(new) <= 0x300000,
                        'Customer volume write extent changed')
            else:
                require(after['write_bytes'] == len(new), 'MSLIB write extent differs')
                write = next(line.split() for line in after['commands'] if line.startswith('ubi write '))
                require(int(write[4], 16) == int(write[5], 16) == len(new), 'Both MSLIB write lengths must match')
        else:
            require(old == new and base[before['source_offset']:end] == candidate[after['source_offset']:end],
                    'Unrelated compressed slot changed')
            require(before['commands'] == after['commands'], 'Unrelated commands changed')
        if i == 8:
            require(sha(new) == APP_SHA, 'V7.9 UI APP is not exact')
        report.append(dict(ordinal=i, decoded_sha256=sha(new), decoded_bytes=len(new), unchanged=i not in (7, 11)))
    return dict(status='PASS_OFFLINE_ONLY', container_sha256=sha(candidate), app_sha256=APP_SHA,
                payloads_checked=14, unchanged_from_v79_payloads=12, changed_payloads=[7, 11],
                all_offsets_preserved=True, outer_crcs_pass=True, payloads=report,
                purpose='Numeric diagnostic telemetry; not a 4K decoding fix', television_tested=False,
                firmware_update_executed=False, flash_ready=False)


if __name__ == '__main__':
    out = ROOT/'analiz/native-ui-candidate/v7.9-hevc-diag/package'
    base = ROOT/'analiz/native-ui-candidate/v7.9-tv/package/GM_SWImage_UI_v7.9-tv_OFFLINE_UNVERIFIED.bin'
    image = out/'GM_SWImage_UI_v7.9-hevc-diag_OFFLINE_UNVERIFIED.bin'
    proof = verify(base.read_bytes(), image.read_bytes(), {7: (out/'07_MSLIB.ubifs').read_bytes(), 11: (out/'11_customer_update.ubifs').read_bytes()})
    print(json.dumps({k: proof[k] for k in ['status', 'container_sha256', 'payloads_checked', 'changed_payloads']}))
