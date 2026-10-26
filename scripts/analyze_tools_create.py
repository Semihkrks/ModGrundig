"""Summarize full Tools create C against the retained raw MIPS call inventory."""
from collections import Counter
from pathlib import Path
import hashlib
import json
import re

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native/ui-four/tools'
RUN=OUT/'full256-360s'
START,END=0xf60a64,0xf86234


def main():
    report=json.loads((RUN/'00f60a64.json').read_text(encoding='utf-8'))
    code=(RUN/'00f60a64.c').read_text(encoding='utf-8')
    index=json.loads((ROOT/'analiz/ui-kod-cagrilari.json').read_text(encoding='utf-8'))
    calls=[c for c in index['calls'] if int(c['function_address'],16)==START]
    counts=Counter(c.get('target_name_candidate') or '[unknown]' for c in calls)
    constructors=Counter()
    for name,count in counts.items():
        match=re.match(r'^(\w+)::\1\(',name)
        if match and match[1] not in ('MImg','MString'):
            constructors[match[1]]+=count
    fields=[]
    pattern=r'\*\((\w+) \*\*\)\(param_1 \+ (0x[0-9a-f]+|\d+)\) = (\w+);'
    for match in re.finditer(pattern,code):
        cls,offset,var=match.groups()
        if cls not in constructors:
            continue
        ctor_pattern=rf'{cls}::{cls}\s*\(\s*{re.escape(var)}\s*,(.*?)\);'
        matches=list(re.finditer(ctor_pattern,code[:match.start()],re.S))
        fields.append({'field_offset':hex(int(offset,0)),'class':cls,'variable':var,
                       'C_line':code.count('\n',0,match.start())+1,
                       'preceding_constructor_arguments':matches[-1][1].strip() if matches else None,
                       'evidence':'decompiled_C_field_relationship; API prototype and branch semantics require assembly corroboration'})
    addresses={int(i['address'],16) for i in report['instructions']}
    missing=sorted(set(range(START,END,4))-addresses)
    pcode={int(c['instruction_address'],16):c for c in report['decompiler_pcode_calls']}
    raw_by_site={int(c['site'],16):c for c in calls}
    targets_checked=[]
    for site,call in pcode.items():
        raw=raw_by_site.get(site)
        if not raw or call.get('constant_target_hex') is None:
            continue
        candidate=raw.get('target_candidate') or {}
        if candidate.get('value') is None:
            continue
        # Imported raw GOT symbol identities may bind to modeled external thunks.
        if not candidate.get('symbol_imported'):
            assert int(call['constant_target_hex'],16)==candidate['value'],hex(site)
            targets_checked.append(hex(site))
    source_maps=json.loads((ROOT/'analiz/ui-yapi-haritasi.json').read_text(encoding='utf-8'))
    message_map=next(m for m in source_maps['message_maps'] if m['class_candidate']=='ToolsMenuFrame')
    behavior_terms=('DualWatch','Get3DDisplayMode','IsTvIn4kMode','SetInitialFocus','SwitchFocusTo','GetSleepTimer','HelpWidget::ShowButton')
    behavior=[c for c in calls if any(t in (c.get('target_name_candidate') or '') for t in behavior_terms)]
    result={'entry':hex(START),'end_exclusive':hex(END),'target_sha256':index['target_sha256'],
            'decompile_complete':report['decompile_complete'],'C_sha256':hashlib.sha256((RUN/'00f60a64.c').read_bytes()).hexdigest(),
            'instruction_json_sha256':hashlib.sha256((RUN/'00f60a64.json').read_bytes()).hexdigest(),
            'FDE_bytes':END-START,'instruction_count':len(addresses),'missing_instruction_addresses':[hex(a) for a in missing],
            'pcode_export_complete':report['pcode_export_complete'],'pcode_outside_body':report['decompiler_pcode_addresses_outside_selected_body'],
            'raw_call_candidates':len(calls),'raw_resolution_counts':dict(Counter(c['resolution'] for c in calls)),
            'pcode_calls':len(pcode),'nonimport_target_comparisons':len(targets_checked),
            'constructor_counts':dict(constructors),'widget_field_records':fields,'selected_behavior_calls':behavior,
            'message_map':message_map,'target_executed':False,'target_modified':False,
            'limitations':['Full C completion does not establish all prototypes or virtual targets.',
                           'Raw PIC/GOT targets are static candidates; imports may be rebound.',
                           'C field relationships remain conditional on the creation branch; not all widgets must be visible.',
                           'Resource ids and named logical states are not interchangeable; shared resources require impact analysis.']}
    (OUT/'tools-create-analysis.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    assert report['decompile_complete'] and not missing and not result['pcode_outside_body']
    print(json.dumps({'complete_C':1,'instructions':len(addresses),'raw_calls':len(calls),'pcode_calls':len(pcode),
                      'widget_ctors':sum(constructors.values()),'widget_fields':len(fields),'nonimport_targets_match':len(targets_checked)}))


if __name__=='__main__':
    main()
