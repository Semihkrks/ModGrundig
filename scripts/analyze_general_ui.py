"""Offline, source-bound GeneralSettingsFrame create call inventory."""
import collections
import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native/ui-four/general'
SOURCE = ROOT / 'analiz/ui-kod-cagrilari.json'
cached = OUT/'raw-call-inventory.json'
data = json.loads(SOURCE.read_text(encoding='utf-8')) if not cached.exists() else None
start, end = 0xD01710, 0xD254DC
calls = [c for c in data['calls'] if start <= int(c['site'], 16) < end] if data else []
rows = []
for call in calls:
    args = call['argument_candidates_a0_a3']
    rows.append({
        'site': call['site'], 'target': call.get('target_name_candidate'),
        'resolution': call['resolution'], 'args_a0_a3': args,
        'target_candidate': call.get('target_candidate'),
    })
counts = collections.Counter(c.get('target_name_candidate') or '<unresolved>' for c in calls)
resource_calls = [r for r in rows if r['target'] and ('RcGet' in r['target'] or 'SetImage' in r['target'] or 'SetColor' in r['target'])]
result = {
    'target_sha256': data['target_sha256'],
    'source': str(SOURCE.relative_to(ROOT)),
    'source_sha256': hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
    'function': {'entry': hex(start), 'end_exclusive': hex(end), 'range_basis': 'exact_ELF_eh_frame_FDE_entry_range', 'bytes': end-start},
    'coverage': next(c for c in data['coverage'] if int(c['address'],16)==start),
    'call_target_counts': dict(counts.most_common()),
    'resource_call_count': len(resource_calls),
    'limitations': data['limitations'],
    'calls': rows,
} if data else json.loads(cached.read_text(encoding='utf-8'))
OUT.mkdir(parents=True, exist_ok=True)
(OUT/'raw-call-inventory.json').write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding='utf-8')
if data:
    (OUT/'resource-calls.json').write_text(json.dumps(resource_calls, ensure_ascii=False, indent=2),encoding='utf-8')

native_path = OUT/'bounded300/00d01710.json'
if not native_path.exists():
    print(json.dumps({'status':'native_query_pending','raw_call_count':len(result['calls'])}))
    raise SystemExit(0)
native = json.loads(native_path.read_text(encoding='utf-8'))
ins = native['instructions']
addresses = {int(row['address'],16) for row in ins}
missing = [hex(a) for a in range(start,end,4) if a not in addresses]
outside = [hex(a) for a in addresses if not start <= a < end]
pcalls = native.get('decompiler_pcode_calls',[])
scope = {
    'entry':hex(start),'end_exclusive':hex(end),'FDE_bytes':end-start,
    'FDE_section_offset':'0x2b6fc',
    'actual_C_count':int(bool(native.get('decompile_complete') and (native_path.with_suffix('.c')).exists())),
    'decompile_complete':native.get('decompile_complete'),'decompile_error':native.get('decompile_error'),
    'instruction_count':len(ins),'instruction_bytes':len(addresses)*4,
    'expected_instruction_count':(end-start)//4,
    'missing_instruction_count':len(missing),'missing_instruction_addresses':missing,
    'outside_instruction_addresses':outside,
    'raw_call_count':len(result['calls']),'raw_resolutions':result['coverage']['resolutions'],
    'pcode_call_count':len(pcalls),'pcode_export_complete':native.get('pcode_export_complete'),
    'pcode_outside_body':native.get('decompiler_pcode_addresses_outside_selected_body'),
    'pcode_within_body':native.get('decompiler_pcode_within_selected_body'),
    'native_source':str(native_path.relative_to(ROOT)),'native_sha256':hashlib.sha256(native_path.read_bytes()).hexdigest(),
    'target_sha256':result['target_sha256'],'target_executed':False,'target_modified':False,
    'evidence_kind':'direct_Ghidra_static_query_and_raw_MIPS_candidates_not_REA_Evidence',
}
def write(name, obj):
    (OUT/name).write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
write('scope-edges.json',scope)
write('pcode-calls.json',pcalls)
write('assembly-minimal.json',[{'address':x['address'],'instruction':x['instruction'],'flow_type':x['flow_type']} for x in ins])
(OUT/'assembly.txt').write_text('\n'.join(x['address']+' '+x['instruction'] for x in ins)+'\n',encoding='utf-8')

# Contiguous constructor groups are source-address groups, not runtime paths.
ctor_types = ['Button','Image','ScrollListContainer','AbsContainer','TextBox','ImageButton','ComboButton','SpinButton']
raw = result['calls']
constructors = [(i,r) for i,r in enumerate(raw) if any((r['target'] or '').startswith(t+'::'+t+'(') for t in ctor_types)]
tables = {}
for brand in ['rc','rc_Beko','rc_Arcelik']:
    for kind in ['Num','Color']:
        path = ROOT/f'analiz/dosya-sistemleri-tam/08_APP/rc/{brand}/bin/{kind}_res.bin'
        if not path.exists():
            # Beko/Arcelik profiles explicitly share rc/Num.rc.
            if kind != 'Num':
                raise FileNotFoundError(path)
            path = ROOT/'analiz/dosya-sistemleri-tam/08_APP/rc/rc/bin/Num_res.bin'
        blob = path.read_bytes()
        count = struct.unpack_from('<I',blob,28)[0]
        assert len(blob) == 56+4*count
        tables[(brand,kind)] = list(struct.unpack_from(f'<{count}I',blob,56))
def bind(kind, value):
    return [{'brand':b,'kind':k,'id':value,'file_offset':56+value*4,'value':vals[value],'hex':hex(vals[value])}
            for (b,k),vals in tables.items() if k==kind and isinstance(value,int) and 0 <= value < len(vals)]
widgets = []
ctext = native_path.with_suffix('.c').read_text(encoding='utf-8')
cctors = list(re.finditer(r'(?P<cls>Button|Image|ScrollListContainer|AbsContainer|TextBox|ImageButton|ComboButton|SpinButton)::(?P=cls)\((?P<args>[^;]+)\)\s*;',ctext))
assert len(cctors)==len(constructors)==66
pby = {int(x['instruction_address'],16):x for x in pcalls}
structure = json.loads((ROOT/'analiz/ui-yapi-haritasi.json').read_text(encoding='utf-8'))
msg = next(r for r in structure['message_maps'] if r['class_candidate']=='GeneralSettingsFrame')
msg['snapshot_source']='analiz/ui-yapi-haritasi.json'
msg['historical_analysis_metadata_note']='Embedded handler ghidra_function bodies/signatures are the earlier snapshot. Current create body and prototype caveats are in bounded300/00d01710.json and scope-edges.json; raw map words/VA remain separate evidence.'
write('message-map.json',msg)
del structure
def parse_strings(path):
    blob=path.read_bytes(); count=struct.unpack_from('<I',blob,28)[0];pos=56;out=[]
    for _ in range(count):
        size=struct.unpack_from('<I',blob,pos)[0];pos+=4
        out.append(blob[pos:pos+size-1].decode('utf-8','replace'));pos+=size
    assert pos==len(blob)
    return out
text_tables={lang:parse_strings(ROOT/f'analiz/dosya-sistemleri-tam/08_APP/rc/rc_{lang}/bin/Str_res.bin') for lang in ['English','Turkish']}
for index,(i,r) in enumerate(constructors):
    site = int(r['site'],16)
    last = constructors[index+1][0] if index+1 < len(constructors) else len(raw)
    previous = raw[:i]
    rect = next((x for x in reversed(previous) if (x['target'] or '').startswith('_Rect::set(')),None)
    rsite = int(rect['site'],16) if rect else site
    nums = [x for x in previous if rsite-160 <= int(x['site'],16)<rsite and (x['target'] or '').startswith('GetRcEngine::RcGetNum(')]
    rect_args=[]
    for x in nums:
        value=(x['args_a0_a3'][0] or {}).get('value')
        rect_args.append({'site':x['site'],'resource_id':value,'table_values':bind('Num',value)})
    following = [x for x in ins if site < int(x['address'],16) < site+40]
    stores = [{'site':x['address'],'instruction':x['instruction']} for x in following if re.fullmatch(r'sw v1,0x[0-9a-f]+\(v0\)',x['instruction'])]
    parent = r['args_a0_a3'][1] or {}
    segment = raw[i+1:last]
    resources=[]
    for x in segment:
        name=x['target'] or ''
        kind = 'Num' if 'RcGetNum(' in name else 'Color' if 'RcGetColor(' in name else None
        if kind:
            value=(x['args_a0_a3'][0] or {}).get('value')
            resources.append({'site':x['site'],'kind':kind,'id':value,'table_values':bind(kind,value)})
        elif name.startswith(('MImg::Set(','MString::Set(')):
            resources.append({'site':x['site'],'kind':'Image' if name.startswith('MImg') else 'Str','id':(x['args_a0_a3'][1] or {}).get('value')})
    cmatch=cctors[index]
    field = re.search(r'\*\(\w+ \*\*\)\(param_1 \+ (0x[0-9a-f]+|[0-9]+)\) = ',ctext[cmatch.end():cmatch.end()+200])
    assert field
    field_hex=hex(int(field[1],0))
    field_store_ins = [x for x in ins if site < int(x['address'],16) < site+256 and re.fullmatch(r'sw \w+,'+field_hex+r'\(\w+\)',x['instruction'])]
    assert len(field_store_ins)==1,(r['site'],field_hex)
    stores=[{'site':x['address'],'instruction':x['instruction']} for x in field_store_ins]
    pcall=pby[site]
    args=pcall['arguments']
    widget_id=int(args[4]['constant_hex'],16) if len(args)>4 and args[4]['constant_hex'] else None
    labels=[]
    for resource in resources:
        if resource['kind']=='Str' and isinstance(resource['id'],int):
            rid=resource['id']
            labels.append({'id':rid,'site':resource['site'],'texts':{lang:vals[rid] for lang,vals in text_tables.items() if rid<len(vals)}})
    bindings=[{'record_va':m['record_va'],'event_value':m['event_value'],'selector_fields_raw':m['selector_fields_raw'],'handler_va':m['handler']['address']}
        for m in msg['records'] if m['event_value']=='0x00000016' and m['selector_fields_raw'][0] in (16,19) and m['selector_fields_raw'][1:3]==[widget_id,widget_id]]
    widgets.append({'constructor_site':r['site'],'class':r['target'].split('::')[0],
        'context_field':field_hex,'constructor_ulong_arguments':[a['constant_hex'] for a in args[3:5]],'widget_id':widget_id,
        'C_line':ctext.count('\n',0,cmatch.start())+1,
        'context_store_candidates':stores,'parent_context_field_candidate':hex(parent['memory_offset']) if parent.get('memory_base_register')==2 else None,
        'parent_basis':parent,'rectangle_set_site':rect['site'] if rect else None,
        'rectangle_getter_order_x_y_w_h_candidates':rect_args,
        'rectangle_limit':'Argument order checked in assembly; Num table profile candidates are logical geometry, not observed TV pixels.',
        'source_group_end_exclusive':raw[last]['site'] if last<len(raw) else hex(end),
        'resources_in_source_group':resources,'label_string_candidates':labels,
        'event_0x16_selector_handler_candidates':bindings})
write('widget-resource-groups.json',{'widgets':widgets,'limitations':['Source-address groups include preparation for the next rectangle; property ownership must be checked in C/assembly.','Constructor parent field and context store are static instruction candidates, not recovered C++ member names.','All brand profile values are candidates; active TV profile unknown.']})
psites = {int(x['instruction_address'],16) for x in pcalls}
missing_calls = [r for r in raw if int(r['site'],16) not in psites]
write('raw-pcode-call-gaps.json',{'raw_count':len(raw),'pcode_count':len(pcalls),'raw_call_sites_absent_from_pcode':len(missing_calls),'absent_target_counts':dict(collections.Counter(r['target'] or '<unresolved>' for r in missing_calls)),'calls':missing_calls,'interpretation':'Unreachable exception landing pads or other excluded paths can be absent after decompiler/noreturn analysis; complete-C does not mean each raw instruction is present as C.'})
unknown=[]
byins={int(x['address'],16):i for i,x in enumerate(ins)}
for r in raw:
    if r['target'] is not None: continue
    i=byins[int(r['site'],16)]
    window=ins[max(i-14,0):i+2]
    slots=[re.search(r'addiu v0,v0,(0x[0-9a-f]+)',x['instruction']) for x in window]
    slots=[m[1] for m in slots if m]
    unknown.append({'site':r['site'],'vtable_slot_candidate':slots[-1] if slots else None,'assembly':[x['address']+' '+x['instruction'] for x in window]})
write('indirect-call-slots.json',{'counts':dict(collections.Counter(x['vtable_slot_candidate'] for x in unknown)),'calls':unknown,'limit':'Virtual slot access recovered; concrete dynamic dispatch target remains unknown.'})
write('callback-bindings.json',{'message_map_va':msg['map_va'],'message_map_records':len(msg['records']),
    'widget_selector_matches':[{'widget_id':w['widget_id'],'context_field':w['context_field'],'constructor_site':w['constructor_site'],'records':w['event_0x16_selector_handler_candidates']} for w in widgets if w['event_0x16_selector_handler_candidates']],
    'static_MString_destructor_registrations':[r for r in raw if r['target']=='__cxa_atexit'],
    'custom_event':{'send_site':'0xd2486c','event':'0xc0000020','handler_va':'0x00d01400','map_record_va':'0x010be0d0','condition':'IsTvInFirstTime()==0; target and sender are param_1; event data words are zero'},
    'limit':'Message-map selector matches are static dispatch candidates. __cxa_atexit entries are lifetime cleanup registrations, not UI event handlers.'})
assert {w['widget_id'] for w in widgets}==set(range(66))
lines=['# GeneralSettingsFrame: 66 widget / kaynak / handler bağı','',
    'Kaynak: `bounded300/00d01710.c`, ham MIPS çağrıları ve `message-map.json`. Geometri `rc/Num` tablosunun mantıksal başlangıç değerleridir; sonraki NewUI_Settings çağrısı ve runtime düzeni bunları değiştirebilir. Son constructor ulong argümanı ile map selector ID eşleşmesi statik adaydır.', '',
    '| ID | Alan / parent alanı | Tür / ilk etiket | Constructor VA | rc başlangıç Rect (x,y,w,h) | 0x16 selector → handler |',
    '|---:|---|---|---|---|---|']
for w in widgets:
    label = next((r['texts'].get('Turkish','') for r in w['label_string_candidates']), '')
    rect = ','.join(str(x['table_values'][0]['value']) for x in w['rectangle_getter_order_x_y_w_h_candidates'])
    handlers = '; '.join(str(m['selector_fields_raw'][0])+':'+m['handler_va']+' @'+m['record_va'] for m in w['event_0x16_selector_handler_candidates'])
    lines.append(f"| {w['widget_id']} | {w['context_field']} / {w['parent_context_field_candidate']} | {w['class']} {label} | {w['constructor_site']} | {rect} | {handlers} |")
(OUT/'widget-table.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
write('behavior-assembly.json',{'ranges':[{'start':hex(lo),'end_exclusive':hex(hi),'instructions':[{'address':x['address'],'instruction':x['instruction']} for x in ins if lo<=int(x['address'],16)<hi]} for lo,hi in [(0xd24600,0xd24894),(0xd248a0,0xd24928),(0xd24bf0,0xd24e8c),(0xd250d0,0xd25450)]], 'call_scope':'Critical prototypes and conditional paths are checked against assembly, not C argument text alone.'})
firmware_path=ROOT/'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board'
actual_sha=hashlib.sha256(firmware_path.read_bytes()).hexdigest()
assert actual_sha==result['target_sha256']
write('validation.json',{'firmware_sha256':actual_sha,'C_sha256':hashlib.sha256(native_path.with_suffix('.c').read_bytes()).hexdigest(),
    'full_FDE_instruction_coverage':not missing and not outside,'pcode_addresses_inside_FDE':native.get('decompiler_pcode_within_selected_body'),
    '66_unique_constructor_IDs_0_through_65':True,'all_66_context_field_stores_checked_in_assembly':True,
    'event_selector_bound_widgets':sum(bool(w['event_0x16_selector_handler_candidates']) for w in widgets),
    'C_warning_counts':dict(collections.Counter(re.findall(r'WARNING: ([^\n]+)',ctext))),
    'target_execution':False,'device_observation':False})
print(json.dumps(scope,ensure_ascii=False,indent=2))
