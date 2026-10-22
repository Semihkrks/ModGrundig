"""Partition incomplete large-module indexes; creates a queue, not analysis results."""
from pathlib import Path
import hashlib
import json

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT/'analiz/native/system-modules'
OUT = ROOT/'analiz/native/analysis-partitions'


def main():
    manifest = json.loads((BASE/'manifest.json').read_text(encoding='utf-8'))
    names = {r['sha256']:r['module_paths'] for r in manifest['records']}
    OUT.mkdir(exist_ok=True)
    modules = []
    for summary in sorted(BASE.glob('*/summary.json')):
        data = json.loads(summary.read_text(encoding='utf-8'))
        if not data['analysis_timeout']:
            continue
        sha = summary.parent.name
        inventory = summary.parent/'functions.jsonl'
        functions = [json.loads(line) for line in inventory.read_text(encoding='utf-8').splitlines()]
        eligible = [f for f in functions if not f['external'] and not f['thunk']]
        eligible.sort(key=lambda f:int(f['address'],16))
        chunks = []; current = []; size = 0
        for f in eligible:
            if current and (len(current) >= 128 or size+f['body_bytes'] > 65536):
                chunks.append(current); current=[]; size=0
            current.append(f); size+=f['body_bytes']
        if current:
            chunks.append(current)
        records = []
        for index, chunk in enumerate(chunks):
            selection = {'addresses':[f['address'] for f in chunk],
                         'target_sha256':sha,'decompile_timeout_seconds':30,
                         'seed_t9_entry':True,'clamp_to_dynsym_size':False,
                         'status':'planned_not_run',
                         'scope_goals':['bounded follow-up of module analysis timeout; verify bounds/prototypes before semantic claims']}
            selection_path = OUT/(sha[:12]+'__'+str(index).zfill(3)+'.json')
            selection_path.write_text(json.dumps(selection,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
            records.append({'selection':str(selection_path.relative_to(ROOT)).replace('\\','/'),
                            'functions':len(chunk),'listing_body_bytes':sum(f['body_bytes'] for f in chunk),
                            'oversize_single_function':len(chunk)==1 and chunk[0]['body_bytes']>65536,
                            'entries':[{'address':f['address'],'name':f['name'],'body_bytes':f['body_bytes']} for f in chunk]})
        assert sum(len(c) for c in chunks)==len(eligible)
        assert len({f['address'] for c in chunks for f in c})==len(eligible)
        modules.append({'sha256':sha,'module_paths':names[sha],
                        'inventory_sha256':hashlib.sha256(inventory.read_bytes()).hexdigest(),
                        'all_function_records':len(functions),'internal_non_thunk_records':len(eligible),
                        'chunks':records,'status':'planned_not_run'})
    output = {'schema_version':1,'max_entries_per_chunk':128,'body_byte_budget_per_chunk':65536,
              'target_executed':False,'target_bytes_written':False,'modules':modules,
              'limitations':['This queue is not completed analysis or decompile coverage.',
                             'Ghidra function bodies and boundaries may be incomplete after timeout.',
                             'Validate executable range, MIPS PIC context, .pdr/FDE and prototype for each critical function.',
                             'A function larger than budget remains a separately marked task; split CFG/assembly before another identical timeout.']}
    (OUT/'manifest.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'modules':len(modules),'queued_chunks':sum(len(m['chunks']) for m in modules),
                      'queued_internal_functions':sum(m['internal_non_thunk_records'] for m in modules),
                      'queue_executed':False}))


if __name__=='__main__':
    main()
