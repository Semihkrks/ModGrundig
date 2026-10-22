"""All-module raw C++ metadata, with file offsets and unresolved relocations."""
from pathlib import Path
from collections import Counter,defaultdict
import argparse
import hashlib
import json
import struct
from map_ui_structure import Elf, demangle

ROOT=Path(__file__).resolve().parents[1]

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source-root',type=Path,required=True)
    args=parser.parse_args()
    invpath=ROOT/'analiz/envanter-v2/elf-envanteri.json'
    inv=json.loads(invpath.read_text())
    pointers=defaultdict(list)
    for e in inv['elfs']:
        for s in e['symbols']:
            if s['section']!='UND' and int(s['value'],16):
                row={'module':e['path'],'name':s['name'],'type':s['type']}
                if row not in pointers[int(s['value'],16)]:pointers[int(s['value'],16)].append(row)
    names={s['name'] for e in inv['elfs'] for s in e['symbols'] if s['name'].startswith(('_ZTV','_ZTI','_ZTS','_ZTT','_ZTC'))}
    decoded=demangle(names,'/usr/bin/c++filt')
    records=[];counts=Counter();module_counts={}
    for e in inv['elfs']:
        elf=Elf(args.source_root,e)
        if hashlib.sha256(elf.path.read_bytes()).hexdigest()!=e['sha256']:raise ValueError('Changed ELF')
        seen=set();local=Counter()
        relocations=defaultdict(list)
        for r in e['relocations']:
            relocations[int(r['offset'],16)].append(r)
        try:
            for s in elf.symbols:
                if not s['defined'] or not s['name'].startswith(('_ZTV','_ZTI','_ZTS','_ZTT','_ZTC')):continue
                identity=(s['value'],s['name'])
                if identity in seen:continue
                seen.add(identity)
                kind={'_ZTV':'vtable','_ZTI':'RTTI','_ZTS':'type_name','_ZTT':'VTT','_ZTC':'construction_vtable'}[s['name'][:4]]
                row={'module':e['path'],'module_sha256':e['sha256'],'name':s['name'],
                     'demangled':decoded.get(s['name'],s['name']),'kind':kind,'va':hex(s['value']),
                     'declared_bytes':s['size'],'symbol_record_offset':s['symbol_record_offset'],
                     'evidence':'raw_defined_ELF_metadata_not_runtime_dispatch'}
                try:
                    if not 0<s['size']<=65536:raise ValueError('Zero or excessive declared size; not guessed')
                    offset=elf.file_offset(s['value'],s['size'])
                    raw=elf.read(offset,s['size'])
                    row.update(file_offset=offset,payload_sha256=hashlib.sha256(raw).hexdigest(),status='file_backed')
                    if kind!='type_name':
                        row['words']=[]
                        for i in range(0,len(raw)-3,4):
                            value=struct.unpack_from('<I',raw,i)[0];va=s['value']+i
                            row['words'].append({'offset':i,'va':hex(va),'file_offset':offset+i,'u32':hex(value),
                                                 'relocations':relocations.get(va,[]),
                                                 'numeric_symbol_candidates':pointers.get(value,[]) if value else []})
                        if kind=='vtable' and len(raw)>=8:
                            row['primary_header_candidate']={'offset_to_top_signed':struct.unpack_from('<i',raw)[0],
                                                             'typeinfo_pointer':hex(struct.unpack_from('<I',raw,4)[0]),
                                                             'address_point':hex(s['value']+8)}
                    # Type names are identified by symbol; no arbitrary byte strings exported.
                except (ValueError,struct.error) as exc:
                    row.update(status='unresolved_or_not_file_backed',reason=str(exc))
                records.append(row);counts[kind]+=1;local[kind]+=1
                counts['unresolved_records']+=row['status']!='file_backed'
        finally:elf.stream.close()
        module_counts[e['path']]=dict(local)
    out={'schema_version':1,'inventory_sha256':hashlib.sha256(invpath.read_bytes()).hexdigest(),
         'module_count':len(inv['elfs']),'counts':dict(counts),'module_counts':module_counts,'records':records,
         'firmware_executed':False,'firmware_modified':False,
         'limitations':['Numeric pointer matches are candidates and can collide across DSOs; relocation and runtime binding remain separate.',
                        'Only the first Itanium vtable header is tentatively labeled; secondary headers and multiple inheritance remain raw words.',
                        'Zero-size, ET_REL section-relative and non-file-backed data are not assigned fabricated payloads.',
                        'A defined class/type does not prove that an instance is created or an override dispatched.']}
    path=ROOT/'analiz/cpp-metadata.json'
    path.write_text(json.dumps(out,ensure_ascii=True,separators=(',',':'))+'\n')
    print(json.dumps({'module_count':len(inv['elfs']),'counts':dict(counts)}))

if __name__=='__main__':main()
