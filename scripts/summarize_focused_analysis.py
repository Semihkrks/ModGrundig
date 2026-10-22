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
                 [BASE/'directfb-callbacks-v1/attempt1/summary.json'])
    selected=defaultdict(set); complete=defaultdict(set); runs=[]
    for summary in summaries:
        if not summary.is_file():
            continue
        s=json.loads(summary.read_text(encoding='utf-8'))
        sha=s.get('stored_executable_sha256')
        if not sha:
            continue
        for path in summary.parent.glob('*.json'):
            value=json.loads(path.read_text(encoding='utf-8'))
            if not isinstance(value,dict) or 'address' not in value or 'decompile_complete' not in value:
                continue
            address=value['address']; selected[sha].add(address)
            if value['decompile_complete']:
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
    (ROOT/'analiz/odakli-analiz-durum.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:output[k] for k in ['unique_selected_entries','unique_complete_entries']}))


if __name__=='__main__':
    main()
