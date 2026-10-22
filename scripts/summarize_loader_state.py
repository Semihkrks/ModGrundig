"""Reconcile ELF addresses with Ghidra image bases and retain loader caveats."""
from pathlib import Path
from collections import Counter
import json
import struct

ROOT=Path(__file__).resolve().parents[1]

def main():
    inv=json.loads((ROOT/'analiz/envanter-v2/elf-envanteri.json').read_text())
    manifest=json.loads((ROOT/'analiz/native/system-modules/manifest.json').read_text())
    by_path={e['path']:e for e in inv['elfs']}; records=[];counts=Counter();badtypes=Counter()
    for r in manifest['records']:
        if r['status']=='existing_UI_analysis':continue
        folder=ROOT/'analiz/native/system-modules'/r['sha256']
        meta=json.loads((folder/'memory-and-loader.json').read_text())
        e=by_path[r['module_paths'][0]]
        raw=(ROOT/'analiz/dosya-sistemleri-tam'/e['path']).read_bytes()
        phoff=struct.unpack_from('<I',raw,28)[0]
        phsize,phnum=struct.unpack_from('<HH',raw,42)
        segments=[struct.unpack_from('<8I',raw,phoff+i*phsize) for i in range(phnum)]
        bases=[p[2] for p in segments if p[0]==1]
        original_base=min(bases) if bases else None
        delta=int(meta['image_base'],16)-original_base if original_base is not None else None
        funcs=[json.loads(line) for line in (folder/'functions.jsonl').open()]
        actual={int(f['address'],16) for f in funcs if not f['external']}
        declared={int(s['value'],16) for s in e['symbols'] if s['type']=='FUNC' and s['section']!='UND' and int(s['value'],16)}
        missing=sorted(v for v in declared if v+delta not in actual) if delta is not None else None
        reltypes={int(x['offset'],16):x['type'] for x in e['relocations']}
        exceptional=[]
        for line in (folder/'relocations.jsonl').open():
            v=json.loads(line)
            if v['status'] in ('APPLIED','APPLIED_OTHER'):continue
            rawva=int(v['address'],16)-delta if delta is not None else None
            v['ELF_type_candidate']=reltypes.get(rawva)
            exceptional.append(v);badtypes[(v['status'],v.get('ELF_type_candidate') or str(v['type']))]+=1
        row={'sha256':r['sha256'],'modules':r['module_paths'],'raw_min_PT_LOAD_va':hex(original_base) if original_base is not None else None,
             'Ghidra_image_base':meta['image_base'],'address_delta':hex(delta) if delta is not None else None,
             'declared_unique_FUNC_addresses':len(declared),'declared_function_entries_missing_in_Ghidra':
              [hex(v) for v in missing] if missing is not None else None,
             'relocation_status_counts':meta['relocation_status_counts'],'exceptional_relocations':exceptional,
             'caveat':'Address normalization is unavailable for section-relative ET_REL; no global VA fabricated.' if delta is None else None}
        records.append(row);counts['artifacts']+=1
        if delta is not None:
            counts['address_normalized_artifacts']+=1;counts['declared_FUNC_entries_compared']+=len(declared)
            counts['declared_FUNC_entries_missing']+=len(missing)
            counts['rebased_artifacts']+=delta!=0
        else:counts['section_relative_artifacts']+=1
    out={'counts':dict(counts),'exceptional_relocation_type_counts':
         [{'status':k[0],'type':k[1],'count':v} for k,v in badtypes.most_common()],
         'records':records,'limitations':['Ghidra loader failures do not establish that the TV firmware loader fails.',
                                        'PARTIAL/UNSUPPORTED/FAILURE data must not be treated as successfully relocated.',
                                        'Declared function entry presence does not prove analyzed body or correct prototype.']}
    (ROOT/'analiz/loader-durum.json').write_text(json.dumps(out,separators=(',',':'))+'\n')
    lines=['# Ghidra adresleri ve loader sınırları','',
           'Ham ELF adresi ile Ghidra adresi, image-base farkı kontrol edilmeden karşılaştırılmaz. '
           'ET_REL nesnelerinde bölüm kimliği gerekir; tek VA üretilmez.','',
           '```json',json.dumps(dict(counts),indent=2),'```','',
           '| Durum | Relocation tipi | Adet |','|---|---|---:|']
    lines += [f'| {k[0]} | `{k[1]}` | {v} |' for k,v in badtypes.most_common(12)]
    lines += ['', '[Tüm adres normalizasyonları, eksik declared girişler ve relocation kayıtları](../../analiz/loader-durum.json).',
              '[Bağımsız çıktı/bütünlük denetimi](../../analiz/sistem-taramasi-dogrulama.json).','',
              'Bu durumlar TV loader hatası diye sunulmaz. Ghidra programları external library binding yapılandırmadan açıldı. '
              'Dolaylı hedefler ve data pointer değerleri, relocation durumu kontrol edilmeden kesin sayılmaz. '
              'Decompile örneklerinin tamamlanması, prototype veya çalışma zamanı etkisinin doğru anlaşıldığı anlamına gelmez.','']
    (ROOT/'docs/bilgi-tabani/ARAC_SINIRLARI.md').write_text('\n'.join(lines),encoding='utf-8')
    print(json.dumps(dict(counts)))

if __name__=='__main__':main()
