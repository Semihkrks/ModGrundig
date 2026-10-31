"""Change only MSLIB and customer_update inside exact V7.9 fixed slots."""
import json
from pathlib import Path
import struct
import zlib
from repack_native_swimage import inspect_package, compress_app
from verify_native_hevc_diag import verify, require, sha, ROOT, BASE_SHA

OUT = ROOT/'analiz/native-ui-candidate/v7.9-hevc-diag/package'
BASE = ROOT/'analiz/native-ui-candidate/v7.9-tv/package/GM_SWImage_UI_v7.9-tv_OFFLINE_UNVERIFIED.bin'
FILENAME = 'GM_SWImage_UI_v7.9-hevc-diag_OFFLINE_UNVERIFIED.bin'


def rewrite_header(base, rows, replacements):
    text, pad = base[:0x4000].split(b'\0', 1)
    require(not any(pad), 'Header padding nonzero')
    starts = {rows[i]['script_offset']: i for i in replacements}
    counts = {i: dict.fromkeys(['filepartload', 'mscompress7', 'crc32', 'mw']+(['ubi'] if i == 7 else []), 0)
              for i in replacements}
    offset, active, result = 0, None, []
    for line in text.splitlines(keepends=True):
        plain = line.rstrip(b'\r\n'); ending = line[len(plain):]
        if offset in starts:
            active = starts[offset]
        elif plain.startswith(b'# File Partition:'):
            active = None
        if active is not None:
            tokens = plain.split(b' ')
            key = tokens[0].decode('ascii')
            if key in counts[active] and (key != 'ubi' or tokens[1:2] == [b'write']):
                raw, packed = replacements[active]
                if key == 'filepartload': tokens[4] = f'0x{len(packed):x}'.encode()
                elif key == 'mscompress7': tokens[4] = f'{len(packed):x}'.encode()
                elif key == 'crc32': tokens[2] = f'0x{len(raw):x}'.encode()
                elif key == 'mw': tokens[2] = f'0x{zlib.crc32(raw):08X}'.encode()
                elif key == 'ubi':
                    require(tokens[1:4] == [b'write', b'0x80200000', b'MSLIB'], 'MSLIB command differs')
                    tokens[4] = tokens[5] = f'0x{len(raw):x}'.encode()
                plain = b' '.join(tokens)
                counts[active][key] += 1
        result.append(plain+ending); offset += len(line)
    require(all(v == 1 for c in counts.values() for v in c.values()), 'Changed command counts differ')
    header = b''.join(result)
    require(len(header) < 0x4000, 'Header overflow')
    return header.ljust(0x4000, b'\0')


def main():
    base = BASE.read_bytes(); require(sha(base) == BASE_SHA, 'Base identity differs')
    rows = inspect_package(base)['sections']
    images = {7: (OUT/'07_MSLIB.ubifs').read_bytes(), 11: (OUT/'11_customer_update.ubifs').read_bytes()}
    for i, name, key in [(7, 'mslib', 'mslib'), (11, 'customer', 'customer')]:
        proof = json.loads((OUT/f'{name}-build-validation.json').read_text())
        require(proof['status'] == 'PASS_OFFLINE_ONLY' and sha(images[i]) == proof[key+'_sha256'], 'Filesystem proof differs')
    replacements = {}
    result = bytearray(base)
    for i, image in images.items():
        require(len(image) <= 0x1c00000, 'Decoded image RAM overflow')
        packed = compress_app(image, '9e')
        row = rows[i]; capacity = row['slot_end']-row['source_offset']
        require(len(packed) <= capacity, f'Compressed slot {i} overflow {len(packed)}>{capacity}')
        replacements[i] = (image, packed)
        result[row['source_offset']:row['slot_end']] = packed.ljust(capacity, b'\0')
    result[:0x4000] = rewrite_header(base, rows, replacements)
    footer = len(base)-24
    struct.pack_into('<I', result, footer, zlib.crc32(result[:0x4000]))
    struct.pack_into('<I', result, footer+4, zlib.crc32(result[:footer+4]))
    proof = verify(base, bytes(result), images)
    image = OUT/FILENAME; require(not image.exists(), 'No artifact overwrite')
    with image.open('xb') as stream: stream.write(result)
    require(image.read_bytes() == result, 'Write readback differs')
    for name in ['repack-validation.json', 'independent-readback.json']:
        path = OUT/name; require(not path.exists(), 'No proof overwrite')
        path.write_text(json.dumps(proof, indent=2)+'\n')
    print(json.dumps(dict(status=proof['status'], container_sha256=proof['container_sha256'],
                         compressed_bytes={i: len(v[1]) for i, v in replacements.items()})))


if __name__ == '__main__':
    main()
