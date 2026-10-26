import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath,pathToFileURL} from 'node:url';
import {createRequire} from 'node:module';
const here=path.dirname(fileURLToPath(import.meta.url));
const root=path.resolve(here,'../../..');
const require=createRequire(import.meta.url);
const {chromium}=require('C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const hash=data=>crypto.createHash('sha256').update(data).digest('hex');
const plan=JSON.parse(await fs.readFile(path.join(here,'render-plan.json'),'utf8'));
for(const [file,key]of[['ui-preview/tv-icons.svg','svg_sha256'],['ui-preview/styles.css','css_sha256'],['ui-preview/app.js','app_sha256']]){
 if(hash(await fs.readFile(path.join(root,file)))!==plan[key])throw Error('Approved source drift');
}
const browser=await chromium.launch({executablePath:'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
try{
 const page=await browser.newPage({viewport:{width:1920,height:1080},deviceScaleFactor:1});
 await page.goto('http://127.0.0.1:4174/preview/?menu=1');await page.waitForFunction(()=>window.modGrundig);
 const computed=await page.evaluate(()=>{
  const selected=document.querySelector('#home-items .is-focused svg'),normal=document.querySelector('#home-items button:not(.is-focused) svg'),lower=document.querySelector('#home-secondary svg');
  return {mainBox:parseFloat(getComputedStyle(selected).width),lowerBox:parseFloat(getComputedStyle(lower).width),normalColor:getComputedStyle(normal).color,focusedColor:getComputedStyle(selected).color};
 });
 if(computed.mainBox!==64||computed.lowerBox!==48||computed.normalColor!=='rgb(32, 52, 71)'||computed.focusedColor!=='rgb(5, 111, 194)')throw Error(JSON.stringify(computed));
 await fs.mkdir(path.join(here,'rendered'),{recursive:true});
 for(const row of plan.records){
  const file=path.resolve(root,row.svg);if(!file.startsWith(path.join(here,'sources')+path.sep))throw Error('Source outside approved icon directory');
  if(hash(await fs.readFile(file))!==row.svg_sha256)throw Error('SVG changed');
  await page.setViewportSize({width:190,height:190});await page.goto(pathToFileURL(file).href);
  await page.screenshot({path:path.join(here,'rendered',`icon-${row.old_id}.png`),omitBackground:true,animations:'disabled'});
 }
 await fs.writeFile(path.join(here,'render-environment.json'),JSON.stringify({browser:await browser.version(),computed,records:plan.records.length,deviceScaleFactor:1,externalResources:false},null,2)+'\n');
 console.log(JSON.stringify({status:'pass',rendered:plan.records.length,computed}));
}finally{await browser.close();}
