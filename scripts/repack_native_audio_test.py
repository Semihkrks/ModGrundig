"""Replace only MSLIB in the byte-pinned V7.9 SWImage; never execute its script."""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import re
import struct
import zlib

from build_native_mslib import ROOT, OUT, MSLIB_SHA, APP_SHA, MAX_DECODED, require, sha, digest, write_new, save_new
from repack_native_swimage import inspect_package, compress_app

BASE = ROOT/'analiz/native-ui-candidate/v7.9-tv/package/GM_SWImage_UI_v7.9-tv_OFFLINE_UNVERIFIED.bin'
BASE_SHA = 'ae6a322861e3b288294b0e4a5f5faf33cb41864439508b2fcee4f6d89ddba496'
FILENAME = 'GM_SWImage_UI_v7.9-audio-test_OFFLINE_UNVERIFIED.bin'


def rewrite_header(base, section, raw_size, packed_size, crc):
    """Permit only five length/CRC substitutions in the selected MSLIB block."""
    header = base[:0x4000]
    text, padding = header.split(b'\0', 1)
    require(not any(padding), 'Nonzero update header padding')
    output, offset, active = [], 0, False
    counts = dict.fromkeys(('filepartload','mscompress7','crc32','mw','ubi'), 0)
    for line in text.splitlines(keepends=True):
        plain = line.rstrip(b'\r\n'); ending = line[len(plain):]
        if offset == section['script_offset']:
            active = True
        elif active and plain.startswith(b'# File Partition:'):
            active = False
        if active:
            substitutions = (
                ('filepartload', rb'(filepartload 0x[0-9a-fA-F]+ \$\(UpgradeImage\) 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( #mslib)', f'0x{packed_size:x}'),
                ('mscompress7', rb'(mscompress7 d 0 0x[0-9a-fA-F]+ )[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #mslib)', f'{packed_size:x}'),
                ('crc32', rb'(crc32 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 0x[0-9a-fA-F]+ #mslib)', f'0x{raw_size:x}'),
                ('mw', rb'(mw 0x[0-9a-fA-F]+ )0x[0-9a-fA-F]+( 4 #mslib)', f'0x{crc:08X}'),
                ('ubi', rb'(ubi write 0x[0-9a-fA-F]+ MSLIB )0x[0-9a-fA-F]+ 0x[0-9a-fA-F]+( #mslib)', f'0x{raw_size:x} 0x{raw_size:x}'))
            for key, pattern, value in substitutions:
                prefix = b'ubi write ' if key == 'ubi' else key.encode()+b' '
                if plain.startswith(prefix):
                    match = re.fullmatch(pattern, plain)
                    require(match is not None, 'Unexpected MSLIB command syntax')
                    plain = match[1]+value.encode()+match[2]
                    counts[key] += 1
                    break
        output.append(plain+ending); offset += len(line)
    require(all(n == 1 for n in counts.values()), 'MSLIB update field count differs')
    result = b''.join(output)
    require(len(result) < 0x4000, 'Header allocation exceeded')
    return result.ljust(0x4000, b'\0')


def build_bytes(base, mslib, preset='9e'):
    require(digest(base) == BASE_SHA, 'Exact V7.9 base container required')
    parsed = inspect_package(base)
    section = parsed['sections'][7]
    require(section['write_target'] == 'MSLIB' and section['decoded_sha256'] == MSLIB_SHA, 'V7.9 MSLIB baseline differs')
    require(parsed['sections'][8]['decoded_sha256'] == APP_SHA, 'V7.9 APP baseline differs')
    require(len(mslib) >= 4096 and mslib[:4] == bytes.fromhex('31181006'), 'MSLIB UBIFS required')
    require(len(mslib) <= MAX_DECODED, 'MSLIB would overlap compressed input/CRC scratch during decode')
    flags, io, leb, count, maximum = struct.unpack_from('<5I', mslib, 28)
    require((flags,io,leb,maximum) == (0,2048,126976,480) and count <= maximum and len(mslib) == count*leb,
            'Candidate MSLIB geometry differs')
    require(struct.unpack_from('<I', mslib, 80)[0] == 4, 'Unsupported UBIFS format')
    packed = compress_app(mslib, preset)
    capacity = section['slot_end']-section['source_offset']
    require(len(packed) <= capacity, f'MSLIB compressed slot overflow: {len(packed)} > {capacity}; no relocation permitted')
    result = bytearray(base)
    result[:0x4000] = rewrite_header(base, section, len(mslib), len(packed), zlib.crc32(mslib))
    result[section['source_offset']:section['slot_end']] = packed.ljust(capacity, b'\0')
    footer = parsed['footer_offset']
    struct.pack_into('<I', result, footer, zlib.crc32(result[:0x4000]))
    struct.pack_into('<I', result, footer+4, zlib.crc32(result[:footer+4]))
    from verify_native_audio_test import verify_container_bytes
    proof = verify_container_bytes(base, bytes(result), mslib)
    proof.update(host_compression_preset=preset, mslib_compressed_bytes=len(packed), mslib_slot_bytes=capacity)
    return bytes(result), proof


def main(preset):
    require(sha(BASE) == BASE_SHA, 'V7.9 release identity changed')
    image = OUT/'07_MSLIB.ubifs'
    validation = json.loads((OUT/'mslib-build-validation.json').read_text())
    require(validation['status'] == 'PASS_OFFLINE_ONLY' and sha(image) == validation['mslib_sha256'], 'MSLIB builder proof differs')
    raw, proof = build_bytes(BASE.read_bytes(), image.read_bytes(), preset)
    write_new(OUT/FILENAME, raw)
    from verify_native_audio_test import verify_container_bytes
    verify_container_bytes(BASE.read_bytes(), (OUT/FILENAME).read_bytes(), image.read_bytes())
    save_new(OUT/'repack-validation.json', proof)
    print(json.dumps(dict(status='PASS_OFFLINE_ONLY', container_sha256=digest(raw), mslib_compressed_bytes=proof['mslib_compressed_bytes'])))


if __name__ == '__main__':
    p=argparse.ArgumentParser(description=__doc__); p.add_argument('--preset',choices=('6','9','9e'),default='9e')
    main(p.parse_args().preset)
