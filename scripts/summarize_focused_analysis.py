"""Count unique (artifact SHA, entry address) focused outputs, including retries."""
from pathlib import Path
from collections import defaultdict
import json

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT/'analiz/native'


def main():
    summaries = (list((BASE/'ui-targeted').glob('*/summary.json'))+
                 list((BASE/'ui-deep').glob('*/summary.json'))+
                 list((BASE/'system-focused').glob('*/*/summary.json'))+
                 list((BASE/'ui-four').glob('*/*/summary.json'))+
                 [BASE/'directfb-callbacks-v1/attempt1/summary.json'])
    selected=defaultdict(set); complete=defaultdict(set); runs=[]
    for summary in summaries:
        if not summary.is_file():
            continue
        if summary.parent.name.startswith('c-only-exporter-check'):
            continue  # tool verification probe, outside the research coverage metric
        s=json.loads(summary.read_text(encoding='utf-8'))
        sha=s.get('stored_executable_sha256')
        if not sha:
            continue
        if 'ui-four' in summary.parts:
            context_path=summary.parent/'selection-and-context.json'
            if not context_path.is_file():
                continue
            context=json.loads(context_path.read_text(encoding='utf-8'))
            expected={'0055b6c0':0x579360,'00d01710':0xd254dc,
                      '00d42150':0xd58d68,'00f60a64':0xf86234}
            full_bounds={r['requested_address'] for r in context.get('requested',[])
                         if r.get('requested_address') in expected
                         and int(r.get('supplied_function_bound',{}).get('end_exclusive','0'),16)==expected[r['requested_address']]}
        else:
            full_bounds=None
        for path in summary.parent.glob('*.json'):
            value=json.loads(path.read_text(encoding='utf-8'))
            if not isinstance(value,dict) or 'address' not in value or 'decompile_complete' not in value:
                continue
            address=value['address']
            if value.get('decompiler_simplification_style','decompile') != 'decompile':
                continue  # normalized/firstpass diagnostic output is not full C recovery
            if full_bounds is not None and address not in full_bounds:
                continue  # fragment/probe output is never promoted to full-function completion
            selected[sha].add(address)
            full_instruction_coverage=True
            if full_bounds is not None:
                expected_words=set(range(int(address,16),expected[address],4))
                actual_words={int(i['address'],16) for i in value.get('instructions',[])}
                full_instruction_coverage=not (expected_words-actual_words)
            c_complete=value.get('C_export_complete',value['decompile_complete'])
            if c_complete and full_instruction_coverage:
                cpath=path.with_suffix('.c')
                assert cpath.is_file() and cpath.stat().st_size, str(cpath)
                complete[sha].add(address)
        runs.append(str(summary.relative_to(ROOT)).replace('\\','/'))
    records=[{'sha256':sha,'unique_selected_entries':len(selected[sha]),
              'unique_complete_entries':len(complete[sha]),
              'incomplete_entries':sorted(selected[sha]-complete[sha])} for sha in sorted(selected)]
    output={'schema_version':1,'deduplication_key':['target_sha256','entry_address'],
            'unique_selected_entries':sum(len(s) for s in selected.values()),
            'unique_complete_entries':sum(len(s) for s in complete.values()),
            'records':records,'source_summaries':runs,
            'limitations':['Focused output count is not fully understood function count.',
                           'Initial 837 system sample outputs and raw boot handlers are separate scopes; do not blindly add as unique functions.',
                           'A later completed retry replaces an earlier timeout only for this deduplicated count.']}
    output['limitations'].append('Settings at 0055b6c0 is included using reduced inference (protorecovery/protorecovery_b/localrecovery disabled); completed C does not mean default full-inference recovery or full EH/argument semantics.')
    (ROOT/'analiz/odakli-analiz-durum.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:output[k] for k in ['unique_selected_entries','unique_complete_entries']}))


if __name__=='__main__':
    main()
