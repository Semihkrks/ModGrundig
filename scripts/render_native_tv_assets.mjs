// Only rasterize pinned new SVGs into the dedicated offline asset directory.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath, pathToFileURL} from 'node:url';
import {createRequire} from 'node:module';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const base=path.join(root,'analiz/native-ui-candidate/v1/assets');
const require=createRequire(import.meta.url);
const playwright=require('C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const hash=data=>crypto.createHash('sha256').update(data).digest('hex');
async function within(p,b,exists=false){
  const target=path.resolve(p), boundary=await fs.realpath(b);
  let cursor=target;
  while(true){try{cursor=await fs.realpath(cursor);break;}catch(e){if(e.code!=='ENOENT')throw e;cursor=path.dirname(cursor);}}
  for(const value of [target,cursor]){const r=path.relative(boundary,value);if(r.startsWith('..')||path.isAbsolute(r))throw new Error('Path escapes candidate directory');}
  if(exists)await fs.access(target);
  try{if((await fs.stat(target)).nlink>1)throw new Error('Hardlinked target');}catch(e){if(e.code!=='ENOENT')throw e;}
  return target;
}
export async function validateRenderPlan(plan){
  if(plan.assets?.length!==20||new Set(plan.assets.map(a=>a.image_id)).size!==20)throw new Error('Unexpected resource set');
  if(plan.approved_symbols_path!=='ui-preview/tv-icons.svg'||hash(await fs.readFile(path.join(root,plan.approved_symbols_path)))!==plan.approved_symbols_sha256)throw new Error('Approved icons changed');
  const targets=new Set();
  for(const a of plan.assets){
    if(a.action==='preserve_original'){if(a.image_id!==681||a.kind!=='volume-knob')throw new Error('Unexpected preserved resource');continue;}
    if(a.action!=='replace_asset'||!/^[a-z0-9-]+$/.test(a.key))throw new Error('Unexpected action');
    for(const [field,sub,ext] of [['source','sources','svg'],['rendered','rendered','png']]){
      const wanted=path.join(base,sub,`${a.key}.${ext}`);
      if(path.resolve(root,a[field])!==wanted)throw new Error('Untrusted render path');
      await within(wanted,path.join(base,sub),field==='source');
    }
    if(hash(await fs.readFile(path.join(root,a.source)))!==a.source_sha256)throw new Error('SVG hash mismatch');
    if(targets.has(a.rendered))throw new Error('Duplicate output');targets.add(a.rendered);
    const {width,height}=a.original_geometry;
    if(!Number.isInteger(width)||!Number.isInteger(height)||width<1||height<1||width>2048||height>2048)throw new Error('Unexpected dimensions');
  }
  await within(path.join(base,'render-environment.json'),base);
}
async function main(){
  const plan=JSON.parse(await fs.readFile(path.join(base,'build-plan.json'),'utf8'));
  await validateRenderPlan(plan);
  const browser=await playwright.chromium.launch({executablePath:'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
  try{
    const page=await browser.newPage({deviceScaleFactor:1});
    for(const a of plan.assets.filter(a=>a.action==='replace_asset')){
      await page.setViewportSize({width:a.original_geometry.width,height:a.original_geometry.height});
      await page.goto(pathToFileURL(path.join(root,a.source)).href);
      await within(path.join(root,a.rendered),path.join(base,'rendered'));
      await page.screenshot({path:path.join(root,a.rendered),omitBackground:true,animations:'disabled'});
    }
    await fs.writeFile(path.join(base,'render-environment.json'),JSON.stringify({browser:await browser.version(),scale:1,count:plan.assets.filter(a=>a.action==='replace_asset').length},null,2)+'\n');
    console.log('Rasterized approved-symbol native assets');
  }finally{await browser.close();}
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url))await main();
