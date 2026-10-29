"""Read-only focused CONFIG evidence audit; never executes extracted programs."""
import hashlib,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'analiz/dosya-sistemleri-tam'
OUT=ROOT/'analiz/native-4k/config'
FILES=['09_CONFIG/sys.ini','09_CONFIG/buildsetting','09_CONFIG/Flags',
 '09_CONFIG/model/Customer_1.ini','09_CONFIG/model/Customer_2.ini',
 '09_CONFIG/module/Customer_Module.ini','09_CONFIG/module/MStar_Default_Module.ini',
 '09_CONFIG/panel/FullHD_CMO216_H1L01.ini','09_CONFIG/panel/Beko_Panel.ini',
 '09_CONFIG/panel/DACOUT_4K2KP_24.ini','09_CONFIG/panel/DACOUT_1080P_60.ini',
 '09_CONFIG/DBPath/DBPath.ini','09_CONFIG/DBPath/DBPath_CSOT_4K540.ini',
 '09_CONFIG/MM/mm_cfg.ini','09_CONFIG/mmap.ini','09_CONFIG/CommonRule.ini',
 '09_CONFIG/ProjectRule.ini','09_CONFIG/PQ_general/PQConfig.ini',
 '09_CONFIG/directfbrc','09_CONFIG/dfbrc.ini','09_CONFIG/board.ini',
 '11_customer_update/MODIFYINI.sh','11_customer_update/6m30_mode.ini']

def read(relative):
 p=SOURCE/relative
 if not p.resolve().is_relative_to(SOURCE.resolve()) or p.is_symlink():raise ValueError('Escaping source '+relative)
 return p.read_bytes()

def text(relative):return read(relative).decode('utf-8',errors='replace')

def ini(relative):
 rows=[];section=''
 for number,line in enumerate(text(relative).splitlines(),1):
  s=line.strip()
  if not s or s.startswith(('#','//')):continue
  if s.startswith('['):section=s.partition(']')[0][1:];continue
  if '=' not in s:continue
  key,value=s.split('=',1);value=value.split(';',1)[0].split('#',1)[0].strip()
  if value=='\\':continue
  rows.append(dict(section=section,key=key.strip(),value=value,line=number))
 return rows

def write(name,data):
 OUT.mkdir(parents=True,exist_ok=True)
 (OUT/name).write_bytes((json.dumps(data,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))

manifest=[dict(path=relative,bytes=len(read(relative)),sha256=hashlib.sha256(read(relative)).hexdigest()) for relative in FILES]
flags=text('09_CONFIG/Flags');matches=list(re.finditer(r'(?<!\S)([A-Za-z_][A-Za-z_0-9]*)(?:=([^\s]+))?',flags))
flagrows=[dict(name=m.group(1),value=m.group(2),line=flags[:m.start()].count('\n')+1,column=m.start()-flags.rfind('\n',0,m.start())) for m in matches]
flagmap={r['name']:r['value'] for r in flagrows}
assert len(flagmap)==len(flagrows),'Duplicate macro names require explicit resolution'
write('flags.json',dict(source='09_CONFIG/Flags',kind='packaged build flag snapshot; runtime consumption not proven',count=len(flagrows),flags=flagrows))
selected={}
for rel in FILES:
 if not rel.endswith('.ini') or rel.endswith(('MM/mm_cfg.ini','mmap.ini','PQConfig.ini','board.ini','ProjectRule.ini','CommonRule.ini')):continue
 rows=ini(rel)
 if '/model/' in rel:
  rows=[r for r in rows if r['section'] in {'panel','module','DLC','ColorMatrix','PcModeTable','Pip','HDMI_EDID_1','HDMI_EDID_2','HDMI_EDID_3','HDMI_EDID_4','HDMI_EDID_VERSION'}]
 elif '/module/' in rel:rows=[r for r in rows if r['section'] not in {'M_IR'}]
 elif '/panel/' in rel:rows=[r for r in rows if re.search(r'Name|Width|Height|width|height|Aspect|LocalDimm|Panel2D3D|FRC|DCLK|LPLL|osd',r['key'])]
 elif '/DBPath/' in rel:rows=[r for r in rows if r['key'].startswith('SQL_DB_') and ('Router' in r['key'])]
 selected[rel]=rows
write('selected-ini.json',selected)
mmrows=ini('09_CONFIG/MM/mm_cfg.ini');dyn=[]
for row in mmrows:
 if row['key'].startswith('ShareMemKey') and row['value'].lower().startswith('0x'):
  value=int(row['value'],16)
  if value>>32==0x2cd:dyn.append(dict(**row,setting_value=value&0xffffffff,sharemem_enum=hex(value>>32)))
write('dynscaling-profiles.json',dict(source='09_CONFIG/MM/mm_cfg.ini',profiles=dyn,global_disable_ds=next(r for r in mmrows if r['key']=='ms.disable.ds'),limits='App service profiles are generic packaged data; a profile is not evidence its feature/application is enabled. Dynamic scaling does not prove UHD decoder input support.'))
macros=[]
for number,line in enumerate(text('09_CONFIG/mmap.ini').splitlines(),1):
 match=re.match(r'#define\s+(\w+)\s+(0x[0-9a-fA-F]+|\d+)\b',line)
 if not match:continue
 key,value=match.groups()
 if key in {'ENABLE_MIU_1','ENABLE_MIU_2','MIU_DRAM_LEN','MIU_DRAM_LEN0','MIU_DRAM_LEN1','MIU_DRAM_LEN2','CPU_ALIGN','TEST_4K_ALIGN'} or re.match(r'(E_LX_MEM|E_DFB_FRAMEBUFFER|E_MMAP_ID_(VDEC_(CPU|FRAMEBUFFER|BITSTREAM)|XC_MAIN_FB|VDPLAYER_(DATA|BITSTREAM)))_(ADR|LEN)$',key):
  v=int(value,0);macros.append(dict(key=key,value=value,decimal=v,MiB=v/(1024*1024) if key.endswith(('LEN','LEN0','LEN1','LEN2')) else None,line=number))
write('memory-map.json',dict(source='09_CONFIG/mmap.ini',macros=macros,limits='Packaged map, not live DRAM dump. Buffer capacity alone cannot prove maximum decoder dimensions/reference count. TEST_4K_ALIGN is alignment, not video resolution.'))
refs=[]
for rel,rows in selected.items():
 for row in rows:
  value=row['value'].strip('"')
  if value.startswith('/config/'):
   target='09_CONFIG/'+value[len('/config/'):]
   tp=SOURCE/target
   if not tp.resolve().is_relative_to(SOURCE.resolve()) or tp.is_symlink():raise ValueError('Escaping reference '+value)
   refs.append(dict(source=rel,source_line=row['line'],key=row['key'],path=value,packaged_target=target,exists=tp.exists(),kind='file' if tp.is_file() else 'directory' if tp.is_dir() else 'missing'))
write('model-resolution.json',dict(sys=ini('09_CONFIG/sys.ini'),buildsetting=dict(source='09_CONFIG/buildsetting',line=1,value=text('09_CONFIG/buildsetting').strip()),model_references=refs,limits=['sys.ini packaged selection is Customer_1; actual SPI/bootloader/factory/runtime overrides not measured','BEKO_MULTIPANEL_TYPE=1 and runtime databases mean the default panel is not a measured physical-device identification','Missing referenced file in materialized tree does not prove runtime failure or absent hardware']))
# Reuse prior addressed UI evidence; do not invent new code-level proof.
coverage=ROOT/'analiz/ui-modernizasyon/feature-coverage.json';data=json.loads(coverage.read_text(encoding='utf-8'));features={}
def visit(node):
 if isinstance(node,dict):
  key=node.get('id','')
  if isinstance(key,str) and re.search(r'timeshift|recording-|picture-format|picture-local-dimming|picture-memc|picture-micro-dimming|cec|sound-arc|sound-output',key) and 'evidence' in node and key not in features:
   features[key]={k:node[k] for k in ('id','label','evidence','defaultVisible') if k in node}
  for val in node.values():visit(val)
 elif isinstance(node,list):
  for val in node:visit(val)
visit(data)
write('reused-feature-evidence.json',dict(source=coverage.relative_to(ROOT).as_posix(),sha256=hashlib.sha256(coverage.read_bytes()).hexdigest(),features=list(features.values()),limits='Existing addressed UI labels/widget bindings, not new behavior execution or physical availability proof. Game mode not independently established in this bounded config review.'))
checks=dict(flag_count=len(flagrows),assigned=sum(r['value'] is not None for r in flagrows),bare=sum(r['value'] is None for r in flagrows),source_files=len(manifest),selected_ini_rows=sum(map(len,selected.values())),dynscaling_profiles=len(dyn),reused_feature_rows=len(features),checks={'main4kflag_disabled':flagmap['ENABLE_4K2K']=='0','backend4k_module_disabled':all(next(r['value'] for r in selected[p] if r['key']=='F_BACKEND_ENABLE_4K2K')=='0' for p in ['09_CONFIG/module/Customer_Module.ini','09_CONFIG/module/MStar_Default_Module.ini']),'default_model_customer1':any(r['key']=='gModelName' and 'Customer_1.ini' in r['value'] for r in ini('09_CONFIG/sys.ini')),'default_panel1920x1080':all(next(r['value'] for r in selected['09_CONFIG/panel/FullHD_CMO216_H1L01.ini'] if r['key']==k)==v for k,v in [('m_wPanelWidth','1920'),('m_wPanelHeight','1080')])})
assert all(checks['checks'].values())
write('manifest.json',dict(date='2026-10-27',sources=manifest,read_only_originals=True,extracted_programs_executed=False,device_access=False,secrets_read_or_exported=False,results=checks))
print(json.dumps(checks))
