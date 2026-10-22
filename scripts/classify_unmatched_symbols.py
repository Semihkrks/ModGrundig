"""Classify unresolved declarations without inventing loader/runtime bindings."""
from pathlib import Path
from collections import Counter
import hashlib
import json
import re
from map_symbol_domains import symbol_identity, dependency_graph, closure_paths, export_rows
from map_mips_calls import Elf32

ROOT=Path(__file__).resolve().parents[1]

def main():
    path=ROOT/'analiz/envanter-v2/sembol-baglantilari.json'
    bindings=json.loads(path.read_text())
    inv=json.loads((ROOT/'analiz/envanter-v2/elf-envanteri.json').read_text())
    by_path={e['path']:e for e in inv['elfs']}
    syms={(e['path'],s['index']):s for e in inv['elfs'] for s in e['symbols'] if s['table']=='.dynsym'}
    counts=Counter(); modules=Counter(); rows=[]; loaders=[]
    for u in bindings['unmatched_imports']:
        s=syms[(u['source'],u['import_symbol_index'])]
        weak=s['binding']=='WEAK'
        outside=bool(u['global_name_match_outside_closure'])
        category=('weak_' if weak else 'nonweak_')+('provider_outside_candidate_closure' if outside else 'no_global_export_candidate')
        rows.append({**u,'declaration':s,'classification':category,'runtime_required_or_missing':'unknown'})
        counts[category]+=1;modules[u['source']]+=1
    for e in inv['elfs']:
        imports=[]
        for s in e['symbols']:
            if s['table']=='.dynsym' and s['section']=='UND' and symbol_identity(s['name'])[0] in ('dlopen','dlsym','dlclose','dlerror'):
                imports.append({'index':s['index'],'name':s['name'],'value':s['value']})
        if imports:loaders.append({'module':e['path'],'sha256':e['sha256'],'declarations':imports})
    dep=json.loads((ROOT/'analiz/envanter-v2/bagimliliklar.json').read_text())
    graph,_=dependency_graph(by_path,dep)
    root='08_APP/bin/dvbt_board'
    scope_paths=closure_paths(root,graph)
    scope={root,*scope_paths}
    exporters={}
    for module in sorted(scope):
        for s in export_rows(by_path[module]):
            base,version=symbol_identity(s['name'])
            exporters.setdefault(base,[]).append((module,s,version))
    scoped=[];scoped_counts=Counter()
    for u in rows:
        if u['source'] not in scope:continue
        base,version=symbol_identity(u['import_name'])
        providers=[{'module':module,'name':s['name'],'address':s['value'],'symbol_index':s['index'],
                    'root_dependency_candidate_path':scope_paths.get(module,[root])}
                   for module,s,v in exporters.get(base,[]) if version is None or version==v]
        kind='provider_in_rooted_candidate_union' if providers else 'no_provider_in_rooted_candidate_union'
        scoped_counts[kind]+=1
        scoped.append({'source':u['source'],'import_name':u['import_name'],
                       'import_symbol_index':u['import_symbol_index'],'classification':kind,
                       'provider_candidates':providers,'runtime_binding_verified':False})
    call_records=[]
    for filename in ('ui-kod-cagrilari.json','ui-muf-kod-cagrilari.json'):
        graph=json.loads((ROOT/'analiz'/filename).read_text())
        elf=None
        for c in graph['calls']:
            name=c.get('target_name_candidate') or ''
            if name not in ('dlopen','dlsym','dlclose','dlerror'):continue
            if elf is None:elf=Elf32(ROOT/graph['target'])
            r={'module':graph['target'],'source_graph':filename,'site':c['site'],
               'function':c['function'],'target_candidate':name,'arguments':c['argument_candidates_a0_a3']}
            ix=1 if name=='dlsym' else 0
            a=c['argument_candidates_a0_a3'][ix]
            value=a.get('value') if a else None
            if value is not None and name in ('dlopen','dlsym'):
                try:
                    offset=elf.file_offset(value); end=elf.raw.find(b'\0',offset,offset+1024)
                    text=elf.raw[offset:end].decode('ascii') if end>=0 else ''
                    if text and re.fullmatch(r'[A-Za-z0-9_./+@$?=-]+',text):
                        r.update(literal_symbol_or_library_candidate=text,file_offset=offset)
                except (ValueError,UnicodeError):pass
            call_records.append(r)
    out={'schema_version':1,'source_binding_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),
         'counts':dict(counts),'unmatched_total':len(rows),'unmatched_by_module':dict(modules),
         'unmatched_declarations':rows,'dynamic_loader_import_modules':loaders,
         'focused_UI_loader_call_candidates':call_records,'unresolved_DT_NEEDED':bindings['unresolved_DT_NEEDED'],
         'main_rooted_scope':{'root':root,'module_candidate_count':len(scope),'counts':dict(scoped_counts),
                              'reclassified_previously_unmatched_imports':scoped,
                              'method':'union of all DT_NEEDED file/SONAME candidates rooted at main; not loader search order'},
         'limitations':['Weak classification does not prove a call is guarded or an import is safely optional.',
                        'Providers outside DT_NEEDED closure can be process-global/dlopen candidates; no runtime binding is claimed.',
                        'Literal loader arguments are static call-site candidates from only the two deeply indexed UI modules.',
                        'No network, target code, dlopen, dlsym or firmware helper is executed.']}
    (ROOT/'analiz/cozulemeyen-semboller.json').write_text(json.dumps(out,ensure_ascii=True,separators=(',',':'))+'\n')
    lines=['# Bağımlılık ve dinamik bağlama araştırması','',
           f"Güncel v2 envanterde {len(rows)} eşleşmeyen import beyanı sınıflandırıldı. Bunlar çalışma zamanında eksik sembol hükmü değildir.",'',
           '| Sınıf | Adet |','|---|---:|']+[f'| `{k}` | {v} |' for k,v in sorted(counts.items())]
    lines += ['',f"dlopen/dlsym/dlclose/dlerror import eden modül: {len(loaders)}. İki UI instruction indeksinde loader çağrı adayı: {len(call_records)}.",'',
              f"Ana uygulama köklü DT_NEEDED aday birleşimi {len(scope)} modül içerir. Bu kapsamdaki önceki eşleşmesiz importlar: `{json.dumps(dict(scoped_counts))}`.",
              'Bu genişletme yalnız statik aday kapsamını değiştirir; runtime arama sırası veya fiilî sağlayıcı seçimi kanıtı değildir.','',
              '[Tam kayıt, import indeksleri ve adaylar](../../analiz/cozulemeyen-semboller.json).',
              '[Güncel sembol bağlama adayları](../../analiz/envanter-v2/sembol-baglantilari.json).','',
              'Weak import için çağıranın sıfır kontrolü ayrıca incelenmelidir. Closure-dışı sağlayıcılar process-global veya plugin kapsamına ancak loader/callback kaydı ve çağıran bağlamıyla bağlanabilir. '
              'Loader import beyanı, belirli bir dosyanın gerçekten yüklendiğini kanıtlamaz. Ghidra sistem taraması external library binding yapılandırmadan yapıldığından onun unresolved external uyarıları bu kayıtlarla karıştırılmaz.','',
              '## Öncelikli modüller','', '| Modül | Eşleşmeyen import |','|---|---:|']
    lines += [f'| `{m}` | {n} |' for m,n in modules.most_common(20)]+['']
    (ROOT/'docs/bilgi-tabani/BAGIMLILIKLAR.md').write_text('\n'.join(lines),encoding='utf-8')
    print(json.dumps({'unmatched':len(rows),'categories':dict(counts),'loader_import_modules':len(loaders),'focused_loader_calls':len(call_records),
                      'main_scope_modules':len(scope),'rooted_scope_counts':dict(scoped_counts)}))

if __name__=='__main__':main()
