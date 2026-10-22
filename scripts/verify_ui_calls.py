"""Cross-check independent raw MIPS call index against retained Ghidra p-code."""
from pathlib import Path
from collections import Counter
import hashlib
import json

ROOT = Path(__file__).resolve().parents[1]


def main(module='main'):
    graph_path = ROOT/('analiz/ui-kod-cagrilari.json' if module=='main' else 'analiz/ui-muf-kod-cagrilari.json')
    graph = json.loads(graph_path.read_text(encoding='utf-8'))
    target = ROOT/graph['target']
    if hashlib.sha256(target.read_bytes()).hexdigest()!=graph['target_sha256']:
        raise ValueError('Graph target digest changed')
    calls = {int(c['site'],16):c for c in graph['calls']}
    stats = Counter()
    mismatches = []
    folder = ROOT/('analiz/native/ui-targeted/dvbt_board' if module=='main' else 'analiz/native/ui-deep/muf-core35')
    for path in sorted(folder.glob('*.json')):
        d = json.loads(path.read_text(encoding='utf-8'))
        if 'decompiler_pcode_calls' not in d:
            continue
        stats['function_files'] += 1
        for pc in d['decompiler_pcode_calls']:
            stats['ghidra_call_records'] += 1
            site = int(pc['instruction_address'],16)
            ours = calls.get(site)
            if not ours:
                stats['no_index_site'] += 1
                continue
            stats['matched_sites'] += 1
            expected = pc.get('constant_target_hex')
            actual = (ours.get('target_candidate') or {}).get('value')
            if expected is not None and actual is not None:
                stats['target_constants_compared'] += 1
                if int(expected,16)!=actual:
                    mismatches.append({'site':hex(site),'kind':'target','raw_MIPS':hex(actual),
                                       'Ghidra':expected,'ghidra_file':path.name})
            else:
                stats['target_comparison_unknown'] += 1
            for arg in pc.get('arguments',[]):
                ix = arg['argument_index_zero_based']
                if ix>3:
                    continue
                expected = arg.get('constant_hex')
                actual = (ours['argument_candidates_a0_a3'][ix] or {}).get('value')
                if expected is not None and actual is not None:
                    stats['argument_constants_compared'] += 1
                    if int(expected,16)!=actual:
                        mismatches.append({'site':hex(site),'kind':'argument','argument':ix,
                                           'raw_MIPS':hex(actual),'Ghidra':expected,
                                           'ghidra_file':path.name})
    report = {'target_sha256':graph['target_sha256'],
              'graph_sha256':hashlib.sha256(graph_path.read_bytes()).hexdigest(),
              'method':'independent raw MIPS index versus retained Ghidra decompiler p-code',
              'stats':dict(stats),'mismatches':mismatches,
              'limitations':['Both methods are static and use explicit PIC entry assumptions.',
                             'Agreement does not prove runtime binding or complete call coverage.',
                             'Unknown values are counted and excluded from equality checks.']}
    out = ROOT/('analiz/ui-kod-cagrilari-dogrulama.json' if module=='main' else 'analiz/ui-muf-kod-cagrilari-dogrulama.json')
    out.write_text(
        json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'stats':dict(stats),'mismatch_count':len(mismatches)}))
    if mismatches or not stats['target_constants_compared'] or not stats['argument_constants_compared']:
        raise SystemExit(1)


if __name__=='__main__':
    import argparse
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--module',choices=('main','muf'),default='main')
    main(parser.parse_args().module)
