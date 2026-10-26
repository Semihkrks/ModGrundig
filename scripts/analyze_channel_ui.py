"""Centralize retained channel UI code/resource evidence; no target execution."""
from pathlib import Path
from collections import Counter
import hashlib,json,re,struct
ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'analiz/native/ui-four/channels'
num_path=ROOT/'analiz/dosya-sistemleri-tam/08_APP/rc/rc/bin/Num_res.bin'
num=num_path.read_bytes();count=struct.unpack_from('<I',num,28)[0]
nums=struct.unpack_from(f'<{count}I',num,56)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
records=[];rectangles=[];timers=[]
for summary_path in sorted(BASE.glob('*/summary.json')):
    summary=json.loads(summary_path.read_text(encoding='utf-8'))
    selection=json.loads((summary_path.parent/'selection.json').read_text(encoding='utf-8'))
    for address in selection['addresses']:
        p=summary_path.parent/f'{address}.json';d=json.loads(p.read_text(encoding='utf-8'))
        cpath=p.with_suffix('.c');end=int(selection['function_bounds'][address]['end_exclusive'],16)
        words={int(i['address'],16)for i in d.get('instructions',[])}
        missing=set(range(int(address,16),end,4))-words
        complete=d.get('C_export_complete',False)and cpath.is_file()and cpath.stat().st_size>0
        records.append({'entry':address,'name':d.get('name'),'C_complete':bool(complete),
            'C_path':cpath.relative_to(ROOT).as_posix()if complete else None,'C_sha256':sha(cpath)if complete else None,
            'instructions':len(words),'FDE_slots':(end-int(address,16))//4,'listing_missing':len(missing),
            'pcode_scope':'unavailable_C_only','run':summary_path.parent.relative_to(ROOT).as_posix()})
        if not complete:continue
        # Only resolve direct RcGetNum assignments; expressions/branches remain unresolved.
        variables={}
        for lineno,line in enumerate(cpath.read_text(encoding='utf-8').splitlines(),1):
            m=re.search(r'(\w+) = GetRcEngine::RcGetNum\((0x[0-9a-f]+)\)',line)
            if m:variables[m[1]]=int(m[2],16)
            m=re.search(r'_Rect::set\([^,]+,([^;]+)\);',line)
            if m:
                args=[x.strip()for x in m[1].split(',')]
                ids=[variables.get(x)for x in args]
                if len(ids)==4 and all(i is not None and i<len(nums)for i in ids):
                    rectangles.append({'function':address,'C_line':lineno,'num_ids':ids,'xywh':[nums[i]for i in ids],
                        'evidence':'direct_C_Num_assignment_sequence; parent transforms/runtime_layout_not_verified'})
            if 'SetTimer('in line:timers.append({'function':address,'C_line':lineno,'code':line.strip()})
raw=json.loads((ROOT/'analiz/ui-kod-cagrilari.json').read_text(encoding='utf-8'))
owners={int(r['entry'],16)for r in records}
calls=[c for c in raw['calls']if int(c['function_address'],16)in owners]
timer_calls=[]
for c in calls:
    if 'SetTimer('in (c.get('target_name_candidate')or''):
        timer_calls.append({'function':c['function_address'],'site':c['site'],'target':c['target_name_candidate'],
                            'arguments_a0_a3':c['argument_candidates_a0_a3']})
result={'target_sha256':raw['target_sha256'],'unique_entries':len({r['entry']for r in records}),
        'C_complete':sum(r['C_complete']for r in records),'records':records,
        'instruction_slots_retained':sum(r['instructions']for r in records),
        'raw_call_candidates':len(calls),'raw_resolutions':dict(Counter(c['resolution']for c in calls)),
        'native_rect_sequences':rectangles,'C_timer_sites':timers,'raw_timer_call_candidates':timer_calls,
        'Num_table_sha256':sha(num_path),'target_executed':False,'firmware_changed':False,
        'TV_parity_verified':False,'limitations':['Static code and decoded resources are not runtime device observation.',
        'C-only has no pcode scope; complete C is not full semantic recovery.',
        'Direct rectangle values do not establish final placement after parent offsets, scaling or LayoutItems.',
        'No device channel database exists in this input; preview does not invent channel names or EPG.',
        'Browser and native renderers have not been compared on the actual TV.']}
(ROOT/'analiz/channel-ui-evidence.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print({k:result[k]for k in ['unique_entries','C_complete','instruction_slots_retained','raw_call_candidates']})
