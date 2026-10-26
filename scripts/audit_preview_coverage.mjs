// Offline evidence cross-check. Reads retained UI analysis, never target executables.
import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {MENUS} from '../ui-preview/firmware-menu-data.js';
import {CONDITIONAL_FEATURES} from '../ui-preview/extra-menu-data.js';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const raw=JSON.parse(await fs.readFile(path.join(root,'analiz/ui-kod-cagrilari.json'),'utf8'));
const sites=new Map(raw.calls.map(c=>[c.site,c]));
const table=await fs.readFile(path.join(root,'analiz/dosya-sistemleri-tam/08_APP/rc/rc_Turkish/bin/Str_res.bin'));
let offset=56;const labels=[];for(let i=0;i<table.readUInt32LE(28);i++){const length=table.readUInt32LE(offset);labels.push(table.subarray(offset+4,offset+3+length).toString('utf8'));offset+=length+4;}
const rows=[],errors=[],proofs={};
for(const [menu,m]of Object.entries(MENUS))for(const r of m.rows){
  const e=r.evidence??{},basis=e.labelBasis??'unknown';proofs[basis]=(proofs[basis]??0)+1;
  const result={menu,id:r.id,label:r.label,type:r.type,evidence:e,callsiteChecked:false};
  if(e.stringCallsite){
    const call=sites.get(e.stringCallsite),value=call?.argument_candidates_a0_a3?.[1]?.value;
    result.callsiteChecked=!!call&&call.function_address===e.sourceAddress&&value===e.stringId&&call.target_name_candidate?.startsWith('MString::Set');
    if(!result.callsiteChecked)errors.push({id:r.id,site:e.stringCallsite,expected:e.stringId,actual:value,function:call?.function_address});
    const inherited=basis==='simulator_subdivision_of_retained_family';
    result.originalLabel=labels[e.stringId];
    if(!inherited&&result.originalLabel!==r.label)result.displayLabelAdapted=true;
  }
  if(r.type==='submenu'&&!MENUS[r.menu])errors.push({id:r.id,reason:'missing submenu'});
  if(r.type==='choice'&&!r.options.includes(r.value))errors.push({id:r.id,reason:'choice default outside options'});
  rows.push(result);
}
if(new Set(rows.map(r=>r.id)).size!==rows.length)errors.push({reason:'duplicate row IDs'});
const result={date:'2026-10-23',baseline:{menus:12,rows:68},current:{menus:Object.keys(MENUS).length,rows:rows.length,proofs,checkedCallsites:rows.filter(r=>r.callsiteChecked).length},conditionalFeatures:CONDITIONAL_FEATURES,excluded:['Ağ','Web','APP','hotel/factory/service menus'],limitations:['Row count is not a count of all firmware capabilities.','All control defaults, option groupings and processing effects are host policy.','Physical model availability is unverified.','Package has 71 message-mapped Frame classes; they are not all user menus.','No target execution, device write or codec/RF/CEC measurement.'],errors,menus:MENUS,rows};
await fs.writeFile(path.join(root,'analiz/ui-modernizasyon/feature-coverage.json'),JSON.stringify(result,null,2)+'\n');
console.log(JSON.stringify({current:result.current,errors},null,2));if(errors.length)process.exitCode=1;
