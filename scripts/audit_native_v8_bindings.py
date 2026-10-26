"""Recheck native message/constructor bindings against actual ELF bytes.

Preserved static wiring is not a completed runtime/TV acceptance test.
"""
import hashlib
import json
from pathlib import Path
import struct
from build_native_volume_patch import elf_va_offset
from build_native_ui_v8 import verified_packaging_records

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-port-v8'
def sha(b):return hashlib.sha256(b).hexdigest()

def data_offset(raw,va,length):
    phoff=struct.unpack_from('<I',raw,28)[0]
    size,count=struct.unpack_from('<HH',raw,42)
    for i in range(count):
        kind,off,base,_,file_size,_,_,_=struct.unpack_from('<8I',raw,phoff+i*size)
        if kind==1 and base<=va and va+length<=base+file_size and off+va-base+length<=len(raw):
            return off+va-base
    raise ValueError('Table is outside file-backed ELF load segments')

def main():
    verified_packaging_records()
    source=ROOT/'analiz/ui-yapi-haritasi.json';data=json.loads(source.read_text(encoding='utf-8'))
    original=(ROOT/'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board').read_bytes()
    previous=(ROOT/'analiz/native-ui-candidate/v7/overlay/08_APP/bin/dvbt_board').read_bytes()
    candidate=(ROOT/'analiz/native-ui-candidate/v8/overlay/08_APP/bin/dvbt_board').read_bytes()
    maps=[];functions={};unresolved=[]
    for m in data['message_maps']:
        if m['module']!='08_APP/bin/dvbt_board' or not m.get('records'):continue
        records=[]
        for r in m['records']:
            va=int(r['record_va'],16);off=data_offset(original,va,28)
            if off!=r['record_file_offset']:raise ValueError('Retained map offset disagrees with ELF load mapping')
            expected=struct.pack('<7I',*r['raw_u32'])
            if original[off:off+28]!=expected or candidate[off:off+28]!=expected:
                raise ValueError('Message table changed or snapshot disagrees: '+hex(va))
            h=r['handler'];entry=int(h['address'],16);extent=h.get('fde_range')
            if entry not in functions:
                row=dict(address=hex(entry),executable_range_candidate=h.get('owning_module_executable_range',False))
                if extent and int(extent['start'],16)==entry:
                    length=int(extent['end_exclusive'],16)-entry;start=elf_va_offset(original,entry,length)
                    row.update(bytes=length,basis='exact_retained_ELF_eh_frame_FDE',
                        original_sha256=sha(original[start:start+length]),
                        v7_sha256=sha(previous[start:start+length]),v8_sha256=sha(candidate[start:start+length]),
                        unchanged_since_v7=previous[start:start+length]==candidate[start:start+length],
                        unchanged_from_original=original[start:start+length]==candidate[start:start+length])
                else:
                    row.update(basis='entry_only_no_verified_function_extent',unchanged_since_v7=None)
                    unresolved.append(dict(kind='handler_body_extent',class_name=m['class_candidate'],address=hex(entry)))
                functions[entry]=row
            records.append(dict(record_va=hex(va),event=r['event_value'],selectors=r['selector_fields_raw'],
                                handler=hex(entry),roles=r.get('event_role_candidates_from_named_handlers',[]),
                                table_bytes_verified=True,member_adjustment=r['member_pointer_adjustment_raw']))
        maps.append(dict(class_name=m['class_candidate'],map_va=m.get('map_va'),records=records))
    factories=[]
    for link in data['application_to_frame_constructor_links']:
        va=int(link['constructor_call_site_va'],16)
        off=elf_va_offset(original,va,4)
        if original[off:off+4]!=candidate[off:off+4]:raise ValueError('Native frame constructor call changed')
        factories.append(dict(apps=link['application_class_candidates'],frame=link['frame_class_candidate'],
            factory=link['factory_function_address'],callsite=hex(va),constructor=link['constructor_target'],
            call_instruction_verified=True,basis=link['evidence']))
    navigation=[]
    for edge in data['navigation_and_constructor_calls']:
        va=int(edge['call_site_va'],16)
        try:off=elf_va_offset(original,va,4)
        except ValueError:
            unresolved.append(dict(kind='navigation_call_outside_main_ELF',callsite=hex(va)));continue
        if original[off:off+4]!=candidate[off:off+4]:raise ValueError('Native navigation instruction changed')
        navigation.append(dict(source_function=edge['function_address'],callsite=hex(va),
            target=edge['target_name_candidate'],kind=edge['edge_kind'],call_instruction_verified=True,
            basis='retained_symbolic_call_candidate_plus_actual_call_word_preservation'))
    summary=dict(classes=len(maps),message_bindings=sum(len(m['records']) for m in maps),
        distinct_handlers=len(functions),handler_extents_verified=sum('bytes' in f for f in functions.values()),
        handler_bodies_unchanged_since_v7=sum(f['unchanged_since_v7'] is True for f in functions.values()),
        changed_visual_handler_bodies=[f['address'] for f in functions.values() if f['unchanged_since_v7'] is False],
        application_frame_factories=len(factories),navigation_call_instructions=len(navigation),unresolved_static_byte_ranges=len(unresolved))
    report=dict(date='2026-10-25',source=source.relative_to(ROOT).as_posix(),source_sha256=sha(source.read_bytes()),
        original_elf_sha256=sha(original),candidate_elf_sha256=sha(candidate),summary=summary,
        maps=maps,handlers=list(functions.values()),factories=factories,navigation=navigation,unresolved=unresolved,
        runtime_dispatch_verified=False,runtime_indirect_targets='not fully resolved or executed',television_tested=False,repairs_applied=0,
        conclusion='Native tables and existing navigation call words retained; no invented Chrome route or substitute service',
        limits=['Message roles/selectors and constructor targets are static candidates; actual code bytes corroborated',
                'Preserving call words does not resolve every runtime function pointer or prove device availability',
                'No full native event loop, actual channel tuning, media decode or physical TV test'])
    OUT.mkdir(parents=True,exist_ok=True);(OUT/'menu-bindings.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    lines=['# Native menü bağlantıları — v8','',
        '25 Ekim 2026. Tarayıcıdaki24 menü modeli bağlantı otoritesi değildir. Gerçek ELF message tabloları ve eski native çağrı noktaları tekrar okundu. Yeni veya sahte servis eklenmedi; bu statik koruma denetimidir.','',
        '| Ölçüm | Sonuç |','|---|---|']+[f'| {k} | {v} |' for k,v in summary.items()]
    lines+=['','Gerçek fonksiyon/map/callsite adresleri ve çözülemeyen kapsam [JSON](menu-bindings.json) içindedir. OnCreate görsel gövdelerindeki değişiklikler normaldir; statik tablo korunması bütün menülerin TV’de çalıştırıldığı anlamına gelmez.','',
        '## Çekirdek ekranlar','', '| Sınıf | Map VA | Kayıt |','|---|---|']
    for m in maps:
        if any(s in m['class_name'] for s in ('Home','GeneralSettings','PictureSettings','SoundSettings','SourceSetup','Parental','Timer','ArChannelList','ChannelControl','ArProgramInfo','DMP','PVR')):
            lines.append(f"| {m['class_name']} | {m['map_va']} | {len(m['records'])} |")
    (OUT/'menu-bindings.md').write_text('\n'.join(lines)+'\n',encoding='utf-8');print(json.dumps(summary))

if __name__=='__main__':main()
