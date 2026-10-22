"""Expand kernel payload and four factory-data archives without execution."""
from pathlib import Path
import hashlib
import json
import lzma
import shutil
import tarfile
import zipfile
import zlib

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / 'analiz/ic-arsivler'
LIMIT = 64 * 1024 * 1024

def checked_target(root, name):
    target = (root / name).resolve()
    if not target.is_relative_to(root.resolve()):
        raise ValueError('Archive path escapes output')
    if target.exists():
        raise FileExistsError(target)
    return target

if __name__ == '__main__':
    OUTPUT.mkdir(parents=True, exist_ok=True)
    records = []
    defaults = ROOT / 'analiz/dosya-sistemleri-tam/08_APP/defaults'
    for archive in sorted(defaults.iterdir()):
        if not archive.name.endswith(('.zip', '.tar.gz')):
            continue
        destination = OUTPUT / archive.name.replace('.', '_')
        entries = []
        total = 0
        if zipfile.is_zipfile(archive):
            with zipfile.ZipFile(archive) as source:
                for entry in source.infolist():
                    if entry.is_dir():
                        continue
                    total += entry.file_size
                    if total > LIMIT:
                        raise ValueError('Archive exceeds extraction limit')
                    target = checked_target(destination, entry.filename)
                    data = source.read(entry)
                    target.parent.mkdir(parents=True, exist_ok=True)
                    target.write_bytes(data)
                    entries.append({'path': entry.filename, 'bytes': len(data),
                                    'sha256': hashlib.sha256(data).hexdigest()})
        elif archive.suffix == '.zip' and archive.read_bytes().startswith(b'\x78\x9c'):
            decoder = zlib.decompressobj()
            decoded = decoder.decompress(archive.read_bytes(), LIMIT + 1)
            if len(decoded) > LIMIT or not decoder.eof:
                raise ValueError('Invalid/oversized zlib stream')
            extension = '.xml' if decoded.lstrip().startswith(b'<') else '.bin'
            target = checked_target(destination, 'zlib-decoded' + extension)
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(decoded)
            entries.append({'path': target.name, 'bytes': len(decoded),
                            'format': 'zlib stream despite .zip filename',
                            'sha256': hashlib.sha256(decoded).hexdigest()})
        else:
            with tarfile.open(archive) as source:
                for entry in source:
                    if not entry.isfile():
                        entries.append({'path': entry.name, 'type': entry.type.decode(), 'extracted': False})
                        continue
                    total += entry.size
                    if total > LIMIT:
                        raise ValueError('Archive exceeds extraction limit')
                    target = checked_target(destination, entry.name)
                    target.parent.mkdir(parents=True, exist_ok=True)
                    with source.extractfile(entry) as input_stream, target.open('xb') as stream:
                        shutil.copyfileobj(input_stream, stream)
                    entries.append({'path': entry.name, 'bytes': entry.size,
                                    'sha256': hashlib.sha256(target.read_bytes()).hexdigest()})
        records.append({'archive': str(archive), 'entries': entries})
    kernel = ROOT / 'analiz/bolumler/05_KL.bin'
    packed = kernel.read_bytes()
    decoder = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE, memlimit=96*1024*1024)
    unpacked = decoder.decompress(packed[0x13c0:], max_length=LIMIT)
    if not decoder.eof:
        raise ValueError('Kernel payload did not reach LZMA EOF')
    digest = hashlib.sha256(unpacked).hexdigest()
    if digest != '43e9cf9a68cefafb14beb936cd37f801a69412b69cfc127bd7c866fe431c3426':
        raise ValueError('Kernel decode differs from independent analysis')
    kernel_output = ROOT / 'analiz/kernel-mips-unpacked.bin'
    if kernel_output.exists():
        raise FileExistsError(kernel_output)
    kernel_output.write_bytes(unpacked)
    report = {'nested_archives': records, 'kernel': {'source': str(kernel),
              'lzma_source_offset': '0x13c0', 'output': str(kernel_output),
              'bytes': len(unpacked), 'sha256': digest, 'lzma_eof': decoder.eof},
              'target_code_executed': False}
    (ROOT / 'analiz/ek-acilimlar.json').write_text(
        json.dumps(report, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({'nested_archives': len(records), 'kernel_bytes': len(unpacked)}))
