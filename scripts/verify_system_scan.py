"""Check retained module outputs, source hashes and graph counts, not runtime."""
from pathlib import Path
from collections import Counter
import hashlib
import json

ROOT=Path(__file__).resolve().parents[1]
A=ROOT/'analiz/native/system-modules'

def digest(path):
    with path.open('rb') as stream:return hashlib.file_digest(stream,'sha256').hexdigest()

def main():
    manifest=json.loads((A/'manifest.json').read_text())
    stats=Counter();issues=[];timeouts=[];records=[]
    for r in manifest['records']:
        sha=r['sha256']
        for name in r['module_paths']:
            if digest(ROOT/'analiz/dosya-sistemleri-tam'/name)!=sha:
                issues.append({'module':name,'issue':'source_hash_mismatch'})
            stats['source_module_paths_verified']+=1
        if r['status']=='existing_UI_analysis':continue
        directory=A/sha;summary=directory/'summary.json'
        if not summary.is_file():
            issues.append({'sha256':sha,'issue':'missing_summary'});continue
        s=json.loads(summary.read_text());counts=Counter()
        if s['sha256'].lower()!=sha:issues.append({'sha256':sha,'issue':'summary_hash_mismatch'})
        with (directory/'callgraph.jsonl').open('w',encoding='utf-8') as calls:
            for name in ('functions','symbols','xrefs','computed-calls'):
                with (directory/(name+'.jsonl')).open(encoding='utf-8') as stream:
                    for line in stream:
                        item=json.loads(line);counts[name]+=1
                        if name=='xrefs' and item['call']:
                            counts['call_xrefs']+=1
                            calls.write(json.dumps(item,separators=(',',':'))+'\n')
                        if name=='computed-calls':
                            counts['computed_with_destinations' if item['analyzed_destinations'] else 'computed_without_destinations']+=1
        for field,key in [('functions','functions'),('symbols','symbols'),('xrefs','xrefs'),
                          ('computed-calls','computed_call_instructions'),('call_xrefs','analyzed_call_xrefs')]:
            if counts[field]!=s[key]:issues.append({'sha256':sha,'issue':'count_mismatch','field':field})
        for sample in s['samples']:
            if sample['complete'] and not (directory/(sample['address']+'.c')).is_file():
                issues.append({'sha256':sha,'issue':'missing_C','address':sample['address']})
        if s['analysis_timeout']:timeouts.append({'sha256':sha,'modules':r['module_paths']})
        metadata=directory/'memory-and-loader.json'
        memory=json.loads(metadata.read_text()) if metadata.is_file() else None
        if memory:
            if memory['sha256'].lower()!=sha:issues.append({'sha256':sha,'issue':'loader_metadata_hash'})
            stats['memory_metadata_artifacts']+=1
            for status,count in memory['relocation_status_counts'].items():stats['relocation_status_'+status]+=count
        stats.update({'indexed_artifacts':1,'functions':counts['functions'],'symbols':counts['symbols'],
                      'xrefs':counts['xrefs'],'call_xrefs':counts['call_xrefs'],
                      'computed_calls':counts['computed-calls'],
                      'computed_without_destinations':counts['computed_without_destinations'],
                      'computed_with_destinations':counts['computed_with_destinations'],
                      'sample_C_complete':s['sample_decompile_complete']})
        records.append({'sha256':sha,'modules':r['module_paths'],'counts':dict(counts),
                        'memory_metadata_present':bool(memory),'summary_sha256':digest(summary)})
    expected=sum(r['status']=='queued' for r in manifest['records'])
    report={'counts':dict(stats),'expected_new_artifacts':expected,'issues':issues,'timeouts':timeouts,
            'records':records,'index_integrity_passed':not issues and stats['indexed_artifacts']==expected,
            'all_memory_metadata_present':stats['memory_metadata_artifacts']==expected,
            'limitations':['Checks confirm files, counts and source identity, not decompiler accuracy or behavioral understanding.',
                           'Call xrefs are Ghidra static reference classifications; computed destinations are analysis candidates.',
                           'An analysis timeout retains a partial analyzed database; no completeness is implied.']}
    (ROOT/'analiz/sistem-taramasi-dogrulama.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:report[k] for k in ('counts','index_integrity_passed','all_memory_metadata_present')}))
    if not report['index_integrity_passed']:raise SystemExit(1)

if __name__=='__main__':main()
