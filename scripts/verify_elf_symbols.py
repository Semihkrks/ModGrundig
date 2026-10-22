"""Validate readelf inventory against raw ELF32 symbol bytes, without execution."""
from pathlib import Path
from collections import Counter
import hashlib
import json
import struct

ROOT = Path(__file__).resolve().parents[1]


def main():
    source = ROOT/'analiz/envanter-v2/elf-envanteri.json'
    report = json.loads(source.read_text(encoding='utf-8'))
    stats = Counter()
    mismatches = []
    for elf in report['elfs']:
        raw = (ROOT/'analiz/dosya-sistemleri-tam'/elf['path']).read_bytes()
        if hashlib.sha256(raw).hexdigest()!=elf['sha256']:
            raise ValueError('Changed target ELF')
        if raw[:6]!=b'\x7fELF\x01\x01':
            raise ValueError('Unexpected ELF identity')
        shoff = struct.unpack_from('<I',raw,32)[0]
        shsize,shnum,shstr = struct.unpack_from('<HHH',raw,46)
        sections = [struct.unpack_from('<10I',raw,shoff+i*shsize) for i in range(shnum)]
        strings = raw[sections[shstr][4]:sections[shstr][4]+sections[shstr][5]]
        def name(data,offset):
            return data[offset:data.index(0,offset)].decode('utf-8',errors='replace')
        rows = {(s['table'],s['index']):s for s in elf['symbols']}
        raw_rows = 0
        for s in sections:
            if s[1] not in (2,11):
                continue
            table = name(strings,s[0])
            st = sections[s[6]]
            names = raw[st[4]:st[4]+st[5]]
            for i in range(s[5]//s[9]):
                n,value,size,info,other,index = struct.unpack_from('<IIIBBH',raw,s[4]+i*s[9])
                raw_rows += 1
                row = rows.get((table,i))
                if row is None:
                    mismatches.append({'path':elf['path'],'table':table,'index':i,'kind':'missing_row'})
                    continue
                expected_name = name(names,n)
                if not expected_name and info&15==3 and index<len(sections):
                    # readelf prints the referenced section name for unnamed STT_SECTION.
                    expected_name = name(strings,sections[index][0])
                # GNU version suffixes are readelf presentation, not st_name bytes.
                names_match = row['name']==expected_name or (expected_name and row['name'].startswith(expected_name+'@'))
                section_match = (row['section']=='UND') if index==0 else (row['section']==str(index) if index<0xff00 else True)
                if int(row['value'],16)!=value or row['size']!=size or not section_match or not names_match:
                    mismatches.append({'path':elf['path'],'table':table,'index':i,
                                       'name_matches':bool(names_match),'section_matches':section_match,
                                       'value_matches':int(row['value'],16)==value,'size_matches':row['size']==size})
                stats['symbol_rows_compared'] += 1
                stats['MIPS_annotated_rows'] += bool(row.get('other_annotations'))
        if raw_rows!=len(rows):
            mismatches.append({'path':elf['path'],'kind':'table_count','raw_rows':raw_rows,'inventory_rows':len(rows)})
        stats['ELFs_compared'] += 1
    out = {'inventory_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
           'method':'readelf parsed rows versus raw ELF section/st_name/st_value/st_size/st_shndx',
           'stats':dict(stats),'mismatches':mismatches,
           'limitations':['Special reserved section indices other than UND are not text-normalized.',
                          'Symbol type/binding/visibility and runtime bindings are outside this comparison.']}
    (ROOT/'analiz/elf-envanter-v2-dogrulama.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'stats':dict(stats),'mismatches':len(mismatches)}))
    if mismatches:
        raise SystemExit(1)


if __name__=='__main__':
    main()
