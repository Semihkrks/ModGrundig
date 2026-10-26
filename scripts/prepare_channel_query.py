"""Select existing channel/OSD entry points from retained FDE evidence, offline."""
from pathlib import Path
import json
ROOT=Path(__file__).resolve().parents[1]
entries=['00fc03e8','00fc1d18','00fbf074','007d4cac','007dc104','0079464c','00774c8c','00d7c7a4']
fde=json.loads((ROOT/'analiz/ui-fde-araliklari.json').read_text(encoding='utf-8'))
bounds={int(r['start'],16):r for r in fde['records']}
out=ROOT/'analiz/native/channel-ui-selection.json'
config={'addresses':entries,'target_sha256':fde['target_sha256'],'decompile_timeout_seconds':60,
        'seed_t9_entry':True,'clamp_to_dynsym_size':True,'export_syntax_tree':False,
        'decompiler_max_payload_mbytes':128,'noreturn_names':['abort','__assert_fail','__cxa_throw','__cxa_rethrow','_Unwind_Resume','__stack_chk_fail'],
        'function_bounds':{a:{'end_exclusive':bounds[int(a,16)]['end_exclusive'],
             'basis':'exact_ELF_eh_frame_FDE_entry_range'} for a in entries},
        'purpose':'Existing numeric zapping, channel list and program-info paths; no invented device channel data'}
out.write_text(json.dumps(config,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print({a:bounds[int(a,16)]['bytes'] for a in entries})
