"""Verify recorded source hashes, extracted regular files and PNG chunk CRCs."""
from pathlib import Path
import hashlib
import json
import struct
import zlib

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = {
    'Grundig_Tum_Proje_Devir_Paketi.zip': '299cb13a2fe939c531224321952a0be196d3e19fa51441ac4e928a9e30d55f6a',
    'devir-paketi/Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar': 'dd0d297d0611f240e1336042483ee46ec73a7b9f669510f45664677f4950a46c',
    'analiz/firmware-dogrulanmis/Target_GM/image/GM_SWImage.bin': '6d7614730c5f63b9e6727b8b329606b188b581efb366bffde6991aca123852c0',
    'analiz/firmware-dogrulanmis/Target_GM/image/GM_Boot.bin': '2a4e909696163e947ceed9106b00ac5512c4c8890a253a623307acd10a7885a1',
}

def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()

def check_png(path):
    raw = path.read_bytes()
    if not raw.startswith(b'\x89PNG\r\n\x1a\n'):
        raise ValueError('PNG signature mismatch')
    position = 8
    count = 0
    ended = False
    while position + 12 <= len(raw):
        size = struct.unpack_from('>I', raw, position)[0]
        end = position + size + 12
        if end > len(raw):
            raise ValueError('Truncated PNG chunk')
        chunk_type = raw[position+4:position+8]
        expected = struct.unpack_from('>I', raw, position+8+size)[0]
        if zlib.crc32(raw[position+4:position+8+size]) != expected:
            raise ValueError(f'Chunk CRC mismatch: {chunk_type!r}')
        count += 1
        position = end
        if chunk_type == b'IEND':
            ended = True
            break
    if not ended:
        raise ValueError('Missing PNG IEND')
    return {'chunks': count, 'trailing_bytes': len(raw)-position}

if __name__ == '__main__':
    report = {'sources': [], 'payloads': [], 'regular_files': {'verified': 0, 'skipped': 0, 'mismatches': []},
              'png': {'verified': 0, 'failed': []}, 'limitations': [
                  'Checks compare published outputs with recorded manifests, not TV runtime.',
                  'PNG chunk checks do not decode pixels or establish active resource usage.',
                  'Sensitive candidates and symlinks are not followed/read.']}
    for name, expected in EXPECTED.items():
        actual = digest(ROOT/name)
        report['sources'].append({'path': name, 'sha256': actual, 'matches': actual == expected})
    sections = json.loads((ROOT/'analiz/bolum-haritasi.json').read_text(encoding='utf-8'))
    for section in sections['sections']:
        path = Path(section['output_path'])
        report['payloads'].append({'path': str(path.relative_to(ROOT)),
                                  'sha256_matches': digest(path) == section['output_sha256'],
                                  'script_crc_matches': section['crc32_validation']['matches_declaration']})
    files = json.loads((ROOT/'analiz/dosya-envanteri.json').read_text(encoding='utf-8'))
    view = ROOT/'analiz/dosya-sistemleri-tam'
    for entry in files['files']:
        if entry['type'] != 'regular':
            continue
        if not entry.get('sha256'):
            report['regular_files']['skipped'] += 1
            continue
        path = view/entry['path']
        if not path.is_file() or digest(path) != entry['sha256']:
            report['regular_files']['mismatches'].append(entry['path'])
        else:
            report['regular_files']['verified'] += 1
    images = list((ROOT/'devir-paketi').rglob('*.png')) + list((view/'08_APP/rc').rglob('*.png'))
    for path in images:
        try:
            check_png(path)
            report['png']['verified'] += 1
        except ValueError as error:
            report['png']['failed'].append({'path': str(path.relative_to(ROOT)), 'error': str(error)})
    report['core_integrity_passed'] = (
        all(row['matches'] for row in report['sources'])
        and all(row['sha256_matches'] and row['script_crc_matches'] for row in report['payloads'])
        and not report['regular_files']['mismatches'])
    (ROOT/'analiz/dogrulama-raporu.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({'core_integrity_passed': report['core_integrity_passed'],
                      'regular_files': report['regular_files'], 'png': report['png']}, ensure_ascii=False))
    if not report['core_integrity_passed']:
        raise SystemExit(1)
