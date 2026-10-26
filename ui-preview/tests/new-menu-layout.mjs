import {createRequire} from 'node:module';
import fs from 'node:fs/promises';
import path from 'node:path';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';
import {MENUS} from '../firmware-menu-data.js';
import {CATEGORIES} from '../tv-model.js';

const require=createRequire(import.meta.url);
const {chromium}=require(process.env.PLAYWRIGHT_MODULE||'C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const base=process.env.PREVIEW_URL||'http://127.0.0.1:4174/preview/';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..');
const output=path.join(root,'analiz/ui-modernizasyon/menu-v7');
await fs.mkdir(output,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
const page=await browser.newPage({viewport:{width:1920,height:1080}});
const errors=[],checks=[],visited=[];
page.on('pageerror',e=>errors.push(e.message));
page.on('console',m=>{if(m.type()==='error')errors.push(m.text());});
page.on('response',r=>{if(r.status()>=400)errors.push(`HTTP ${r.status()} ${r.url()}`);});
const state=()=>page.evaluate(()=>window.modGrundig.getState());
const key=k=>page.keyboard.press(k);
async function settle(){await page.evaluate(()=>Promise.all(document.getAnimations().map(a=>a.finished)));}
async function fresh(menu=false){await page.goto(base+(menu?'?menu=1':''));await page.waitForFunction(()=>window.modGrundig);await page.evaluate(()=>document.fonts.ready);await settle();}
async function snap(name){await settle();await page.screenshot({path:path.join(output,`${name}.png`)});}
const routes=new Map(CATEGORIES.map((c,i)=>[c.menu,{category:i,rows:[]}]));
routes.set('quickAudio',{shortcut:'a',rows:[]});
routes.set('subtitles',{shortcut:'b',rows:[]});
routes.set('mediaSettings',{shortcut:'media',rows:[]});
for(let size=-1;size!==routes.size;){size=routes.size;for(const [name,route]of [...routes])MENUS[name].rows.forEach((r,i)=>{if(r.type==='submenu'&&!routes.has(r.menu))routes.set(r.menu,{...route,rows:[...route.rows,i]});});}
async function openMenu(name){
  await fresh();const route=routes.get(name);assert(route,`Unreachable menu ${name}`);
  if(route.shortcut==='a'||route.shortcut==='b')await key(route.shortcut);
  else if(route.shortcut==='media'){await key('m');await page.locator('#home-items button').filter({hasText:'Medya Oynatıcı'}).click();await key('F7');}
  else{await key('m');await key('ArrowDown');for(let i=0;i<route.category;i++)await key('ArrowRight');await key('Enter');}
  for(const index of route.rows){for(let i=0;i<index;i++)await key('ArrowDown');await key('Enter');}
  assert.equal((await state()).path.at(-1),name);
  await settle();
}
try{
  await fresh(true);assert.equal((await state()).view,'home');
  assert.equal(await page.locator('#home-items button').count(),6);
  assert.equal(await page.locator('#home-secondary button').count(),6);
  const home=await page.locator('#menu').evaluate(n=>({height:n.offsetHeight,overflow:n.scrollHeight>n.clientHeight,footer:document.querySelector('#home-footer').getBoundingClientRect().bottom}));
  assert.equal(home.height,456);assert.equal(home.overflow,false);assert(home.footer<=1051);
  assert.match(await page.locator('.simulator-caption').innerText(),/Tasarım önizlemesi.*Test kanalları/);
  await snap('01-main-menu');
  await key('ArrowDown');await snap('02-settings-categories');await key('Enter');
  assert.equal((await state()).path.at(-1),'picture');await snap('03-picture-settings');
  const before=(await state()).values;await key('ArrowRight');assert.notDeepEqual((await state()).values,before);
  checks.push('Initial menu flag, six original main actions/six setting categories, compact safe layout, real arrows/Enter change picture setting');

  await openMenu('picture');
  const backlightRow=MENUS.picture.rows.findIndex(r=>r.id==='picture-backlight');
  for(let i=0;i<backlightRow;i++)await key('ArrowDown');
  const imageFilter=()=>page.locator('#tv-scene').evaluate(n=>n.style.filter);
  const initialFilter=await imageFilter();await key('ArrowRight');
  const baseFilter=await imageFilter();assert.notEqual(baseFilter,initialFilter);
  let values=(await state()).values;assert.equal(values['picture-backlight'],values['picture-manual-backlight']);
  const advancedRow=MENUS.picture.rows.findIndex(r=>r.id==='picture-advanced');
  for(let i=backlightRow;i<advancedRow;i++)await key('ArrowDown');
  await key('Enter');assert.equal((await state()).path.at(-1),'pictureAdvanced');await key('ArrowRight');
  assert.notEqual(await imageFilter(),baseFilter);
  values=(await state()).values;assert.equal(values['picture-backlight'],values['picture-manual-backlight']);
  checks.push('Both base/advanced backlight controls change the rendered test image through real arrow keys; shared value is host preview policy');

  assert.equal(routes.size,Object.keys(MENUS).length);
  for(const [name,menu]of Object.entries(MENUS)){
    await openMenu(name);assert.equal(await page.locator('#settings-title').innerText(),menu.title);
    for(let i=0;i<menu.rows.length;i++){
      const focused=page.locator('#settings-rows .is-focused');
      assert.equal(await focused.locator('.row-label').innerText(),menu.rows[i].label);
      assert.equal(await focused.getAttribute('aria-current'),'true');
      const g=await focused.evaluate(n=>{const r=n.getBoundingClientRect(),footer=document.querySelector('#settings-footer').getBoundingClientRect(),list=document.querySelector('#settings-rows');return {top:r.top,bottom:r.bottom,footer:footer.top,left:r.left,right:r.right,overflow:list.scrollHeight>list.clientHeight};});
      assert(g.bottom<=g.footer+1,`${name}/${i} overlaps footer`);assert(g.left>=72&&g.right<=1848,`${name}/${i} outside side margins`);assert.equal(g.overflow,false,`${name}/${i} list overflows`);
      if(i<menu.rows.length-1)await key('ArrowDown');
    }
    visited.push({menu:name,rows:menu.rows.length});
  }
  checks.push('Every row in all 24 menus reachable by real remote navigation; seven-row viewport, visible focus and no footer/side overlap');

  await fresh();await key('Enter');assert.equal((await state()).view,'list');await snap('04-channel-list');
  for(const index of [0,1,1,0]){await page.locator('#channel-list-tabs button').nth(index).click();assert.equal((await state()).filter,index);assert.equal(await page.locator('#channel-list-tabs button').nth(index).getAttribute('aria-pressed'),'true');}
  await key('ArrowDown');await key('F2');await snap('05-channel-favorite');await key('Enter');assert.equal((await state()).view,'tv');
  checks.push('Channel list/details, favorite editing and tuning; direct filter buttons are idempotent and announce state');

  await fresh();await page.keyboard.type('1234');
  const number=await page.locator('#channel-number-osd').evaluate(n=>{const label=n.querySelector('.number-label').getBoundingClientRect(),digits=n.querySelector('#number-digits').getBoundingClientRect();return {gap:digits.top-label.bottom,font:parseFloat(getComputedStyle(n.querySelector('#number-digits')).fontSize),overflow:n.scrollHeight>n.clientHeight};});
  assert(number.gap>=16);assert.equal(number.font,58);assert.equal(number.overflow,false);await snap('06-numeric-spacing');await key('Escape');
  await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:36}));
  await page.waitForFunction(()=>document.querySelector('#volume-icon').complete&&document.querySelector('#volume-icon').naturalWidth>0);
  assert.deepEqual(await page.locator('#volume-panel').evaluate(n=>[n.offsetWidth,n.offsetHeight]),[68,450]);
  assert.equal(await page.evaluate(()=>document.fonts.check('36px NativeDIN')),true);await snap('07-native-font-volume');
  await key('s');assert.match(await page.locator('#volume-icon').getAttribute('src'),/volume-mute\.png$/);await key('s');
  checks.push('Numeric label/digits gap ≥16px at actual 58px font, no overflow; native local DIN font and PNG icon assets in 68×450 volume capsule');

  for(const viewport of [{width:1280,height:720},{width:390,height:844}]){
    await page.setViewportSize(viewport);await fresh(true);await snap(`08-main-${viewport.width}`);await key('ArrowDown');await key('Enter');await snap(`09-picture-${viewport.width}`);
    const g=await page.evaluate(()=>({overflow:document.documentElement.scrollWidth>innerWidth,stage:document.querySelector('#stage').getBoundingClientRect().width,screen:document.querySelector('#screen').getBoundingClientRect().width}));
    assert.equal(g.overflow,false);assert(Math.abs(g.stage-g.screen)<2);
  }
  await page.emulateMedia({reducedMotion:'reduce'});await fresh(true);await key('ArrowDown');await key('Enter');assert.equal(await page.evaluate(()=>document.getAnimations().length),0);
  checks.push('1280×720 and 390×844 preserve the 16:9 TV viewport without document overflow; reduced-motion disables transitions');
  assert.deepEqual(errors,[]);
  const result={status:'pass',date:new Date().toISOString(),browser:'installed Chrome via Playwright',base,menus:visited.length,rows:visited.reduce((n,m)=>n+m.rows,0),visited,checks,errors,deviceTested:false,firmwareExecuted:false};
  await fs.writeFile(path.join(output,'browser-tests.json'),JSON.stringify(result,null,2)+'\n');console.log(JSON.stringify(result,null,2));
}catch(error){await snap('failure');console.error(error);process.exitCode=1;}finally{await browser.close();}
