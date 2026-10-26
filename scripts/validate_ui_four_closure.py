"""Check retained UI artifacts and summarizer contract, without running firmware."""
from pathlib import Path
import ast
import contextlib
import hashlib
import importlib.util
import io
import json
import re
import tempfile
from urllib.parse import unquote

ROOT=Path(__file__).resolve().parents[1]

def read(path):
    return json.loads(path.read_text(encoding='utf-8'))

def main():
    status=read(ROOT/'analiz/ui-dort-buyuk-durum.json')
    assert status['full_function_C_complete']==4
    assert status['default_full_inference_C_complete']==3
    assert status['modified_inference_C_complete']==1
    canonical=[]
    for record in status['records']:
        value=record['canonical']
        c=ROOT/value['C_file']
        data=read(ROOT/value['function_json'])
        assert hashlib.sha256(c.read_bytes()).hexdigest()==value['C_sha256']
        assert value['exact_FDE_bound'] and value['missing_word_count']==0
        assert value['instruction_count']==record['expected_instruction_slots']
        if value['pcode_export_available']:
            assert not value['pcode_outside_body']
        else:
            assert value['pcode_call_count'] is None
            # New exporter explicitly uses null when no syntax tree was requested.
            if 'C_export_complete' in data:
                assert data['decompiler_pcode_within_selected_body'] is None
        canonical.append({'key':record['key'],'C_sha256':value['C_sha256'],
                          'C_bytes':c.stat().st_size,'instructions':value['instruction_count'],
                          'inference_profile':value['inference_profile']})
    fragments=read(ROOT/'analiz/native/ui-four/settings-fragments/fragment-validation.json')
    assert fragments['valid_bounded_fragment_C_count']==12
    assert fragments['original_owned_instruction_count']==30504
    assert fragments['original_instruction_missing_count']==0
    assert fragments['original_instruction_overlap_count']==0
    assert fragments['whole_function_C_complete_count']==0
    expected={
        'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board':status['target_sha256'],
        'analiz/dosya-sistemleri-tam/07_MSLIB/libmuf.so':'494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96',
        'analiz/firmware-dogrulanmis/Target_GM/image/GM_SWImage.bin':'6d7614730c5f63b9e6727b8b329606b188b581efb366bffde6991aca123852c0',
        'analiz/firmware-dogrulanmis/Target_GM/image/GM_Boot.bin':'2a4e909696163e947ceed9106b00ac5512c4c8890a253a623307acd10a7885a1'}
    for name,sha in expected.items():
        assert hashlib.sha256((ROOT/name).read_bytes()).hexdigest()==sha,name
    source_paths=[ROOT/'scripts'/name for name in [
        'summarize_ui_four.py','summarize_focused_analysis.py','update_knowledge_base.py',
        'analyze_tools_create.py','analyze_general_ui.py','analyze_home_create.py',
        'analyze_home_validation.py','analyze_home_widget_map.py','analyze_home_widget_trace.py',
        'analyze_settings_ui.py','analyze_settings_phases.py','analyze_settings_c_crosscheck.py',
        'validate_ui_four_closure.py']]
    for path in source_paths:
        ast.parse(path.read_text(encoding='utf-8'),filename=str(path))
    spec=importlib.util.spec_from_file_location('focused',ROOT/'scripts/summarize_focused_analysis.py')
    module=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    # Regression: native success + C explicitly disabled must not assert a missing C file.
    with tempfile.TemporaryDirectory(prefix='grundig-ui-counter-') as tmp:
        base=Path(tmp); run=base/'analiz/native/ui-targeted/no-c'
        run.mkdir(parents=True)
        (run/'summary.json').write_text(json.dumps({'stored_executable_sha256':'fixture'}))
        (run/'00001000.json').write_text(json.dumps({'address':'00001000',
            'decompile_complete':True,'C_export_complete':False}))
        module.ROOT=base; module.BASE=base/'analiz/native'
        with contextlib.redirect_stdout(io.StringIO()):
            module.main()
        result=read(base/'analiz/odakli-analiz-durum.json')
        assert result['unique_selected_entries']==1 and result['unique_complete_entries']==0
    broken=[]; checked=0
    docs=[ROOT/'README.md',*sorted((ROOT/'docs').rglob('*.md')),
          ROOT/'analiz/native/ui-four/settings-fragments/README.md']
    for doc in docs:
        for target in re.findall(r'\]\(([^)]+)\)',doc.read_text(encoding='utf-8')):
            target=target.strip().strip('<>')
            if re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*:',target) or target.startswith('#'):
                continue
            target=unquote(target.split('#',1)[0])
            if not target:
                continue
            checked+=1
            if not (doc.parent/target).exists():
                broken.append({'doc':doc.relative_to(ROOT).as_posix(),'target':target})
    assert not broken,broken
    result={'date':'2026-10-23','status':'pass','canonical':canonical,
            'original_instruction_count':sum(r['instructions'] for r in canonical),
            'source_sha256_checks':expected,'python_AST_files_checked':len(source_paths),
            'native_success_without_C_counter_regression':'pass','local_markdown_targets_checked':checked,
            'broken_markdown_targets':broken,'valid_synthetic_fragments':12,
            'target_executed':False,'firmware_modified':False,
            'limitations':['Static artifact validation does not establish runtime binding, device compatibility or complete semantics.',
                           'Settings whole-range C uses reduced recovery; fragment pcode is not a substitute for whole-range C-only scope validation.']}
    (ROOT/'analiz/ui-dort-buyuk-dogrulama.json').write_text(
        json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['status','original_instruction_count',
                     'python_AST_files_checked','local_markdown_targets_checked']}))

if __name__=='__main__':
    main()
