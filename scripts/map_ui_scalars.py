"""Decode observed fixed-width MUF resource tables without modifying firmware."""
from pathlib import Path
import hashlib
import json
import struct

ROOT = Path(__file__).resolve().parents[1]
TREE = ROOT/'analiz/dosya-sistemleri-tam/08_APP/rc'
TYPES = {'Num_res.bin': 1, 'Color_res.bin': 2, 'Clrkey_res.bin': 6}
VOLUME_IDS = (0x5a46, 0x5a47, 0x5a48, 0x5a49, 0x5a6a, 0x5a6d,
              0x5a6e, 0x5a6f, 0x5a70, 0x5a72, 0x5a73, 0x5a74, 0x5a75)

if __name__ == '__main__':
    tables = []
    for path in sorted(TREE.rglob('*_res.bin')):
        if path.name not in TYPES:
            continue
        raw = path.read_bytes()
        if len(raw) < 56:
            raise ValueError(f'Truncated resource header: {path}')
        header = struct.unpack_from('<14I', raw)
        if header[1] != len(raw) or header[2] != TYPES[path.name]:
            raise ValueError(f'Header size/type mismatch: {path}')
        count = header[7]
        # Offsets are observed independently in all admitted files; no packed structs guessed.
        if header[5] != 56 or header[6] != 56 or len(raw) != 56 + count*4:
            raise ValueError(f'Unexpected scalar resource layout: {path}')
        records = [{'id': i, 'id_hex': hex(i), 'file_offset': 56+i*4,
                    'u32': struct.unpack_from('<I', raw, 56+i*4)[0],
                    'u32_hex': hex(struct.unpack_from('<I', raw, 56+i*4)[0])}
                   for i in range(count)]
        tables.append({'path': path.relative_to(ROOT).as_posix(),
                       'sha256': hashlib.sha256(raw).hexdigest(), 'bytes': len(raw),
                       'header_magic_hex': hex(header[0]), 'type_id': header[2],
                       'header_bytes': 56, 'record_count': count, 'fully_consumed': True,
                       'records': records,
                       'volume_refresh_ids': [records[i] for i in VOLUME_IDS if path.name == 'Num_res.bin' and i < count]})
    report = {'schema_version': 1, 'tables': tables,
              'source_function': {'module': 'libmuf.so', 'function': 'MResourcePkg::GetU32',
                                  'address': '0x2e2403a4',
                                  'observed_rule': 'if table != null and id < count: table[id], else fallback'},
              'limits': ['Raw u32 values; semantic coordinates/colors require caller evidence.',
                         'Profile reference resolution and active TV profile are separate facts.',
                         'No firmware, image or UI behavior was changed.']}
    (ROOT/'analiz/ui-deger-tablolari.json').write_text(
        json.dumps(report, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({'tables': len(tables), 'records': sum(t['record_count'] for t in tables),
                      'counts': {t['path']: t['record_count'] for t in tables}}, ensure_ascii=False))
