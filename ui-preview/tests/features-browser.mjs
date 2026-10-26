import {createRequire} from 'node:module';
import fs from 'node:fs/promises';
import path from 'node:path';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';
import {MENUS} from '../firmware-menu-data.js';
import {CATEGORIES} from '../tv-model.js';
const require=createRequire(import.meta.url);
const {chromium}=require(process.env.PLAYWRIGHT_MODULE||'C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..'),out=path.join(root,'analiz/ui-modernizasyon');
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
const page=await browser.newPage({viewport:{width:1920,height:1080}}),errors=[],checks=[],visited=[];
page.on('pageerror',e=>errors.push(e.message));page.on('console',m=>{if(m.type()==='error')errors.push(m.text());});
const key=k=>page.keyboard.press(k),state=()=>page.evaluate(()=>window.modGrundig.getState());
const snap=async name=>{await page.waitForTimeout(180);await page.screenshot({path:path.join(out,`features-${name}.png`)});};
const ready=()=>page.waitForFunction(()=>window.modGrundig);
async function fresh(){await page.goto('http://127.0.0.1:4173/');await ready();await key('Escape');}
const routes=new Map(CATEGORIES.map((c,i)=>[c.menu,{category:i,rows:[]} ]));
routes.set('quickAudio',{shortcut:'a',rows:[]});routes.set('subtitles',{shortcut:'b',rows:[]});routes.set('mediaSettings',{shortcut:'media',rows:[]});
for(let size=-1;size!==routes.size;){size=routes.size;for(const [name,route]of [...routes])MENUS[name].rows.forEach((r,i)=>{if(r.type==='submenu'&&!routes.has(r.menu))routes.set(r.menu,{...route,rows:[...route.rows,i]});});}
async function openMenu(name){
  await fresh();const route=routes.get(name);assert(route,`Unreachable menu ${name}`);
  if(route.shortcut==='a'||route.shortcut==='b')await key(route.shortcut);
  else if(route.shortcut==='media'){await key('m');await page.locator('#home-items button').filter({hasText:'Medya Oynatıcı'}).click();await key('F7');}
  else{await key('m');await key('ArrowDown');for(let i=0;i<route.category;i++)await key('ArrowRight');await key('Enter');}
  for(const index of route.rows){for(let i=0;i<index;i++)await key('ArrowDown');await key('Enter');}
  assert.equal((await state()).path.at(-1),name);
}
try{
  await fs.mkdir(out,{recursive:true});assert.equal(routes.size,Object.keys(MENUS).length);
  for(const [name,menu]of Object.entries(MENUS)){
    await openMenu(name);assert.equal(await page.locator('#settings-title').innerText(),menu.title);
    for(let i=0;i<menu.rows.length;i++){
      assert.equal(await page.locator('#settings-rows .is-focused .row-label').innerText(),menu.rows[i].label);
      const geometry=await page.locator('#settings-rows .is-focused').evaluate(n=>({bottom:n.getBoundingClientRect().bottom,footer:document.querySelector('#settings-footer').getBoundingClientRect().top}));
      assert(geometry.bottom<=geometry.footer+1,`${name} row ${i} overlaps footer`);if(i<menu.rows.length-1)await key('ArrowDown');
    }
    visited.push({menu:name,rows:menu.rows.length});if(['pictureAdvanced','manualSearch','programTimer','accessories'].includes(name))await snap(name);
  }
  checks.push('All exported menus and every row reached by real remote navigation; no footer overlap');
  await fresh();await page.keyboard.type('12');assert.equal(await page.locator('#number-digits').innerText(),'12');assert.equal(await page.locator('#number-channel').innerText(),'TRT Müzik');
  const progress=await page.locator('#number-progress>span').evaluate(n=>getComputedStyle(n).transform);await page.waitForTimeout(180);assert.notEqual(await page.locator('#number-progress>span').evaluate(n=>getComputedStyle(n).transform),progress);await snap('numeric-match');
  await key('Backspace');assert.equal(await page.locator('#number-digits').innerText(),'1');await key('Escape');assert.equal(await page.locator('#channel-number-osd').isVisible(),false);
  await page.keyboard.type('99');assert.equal(await page.locator('#number-channel').innerText(),'Kayıtlı kanal yok');await snap('numeric-missing');await key('Escape');checks.push('Numeric match/missing, countdown, delete and cancel');
  await fresh();await key('u');await key('m');await page.locator('#home-items button').filter({hasText:'Medya Oynatıcı'}).click();
  assert.equal((await state()).view,'media');assert.equal(await page.locator('#settings-rows .tv-row').count(),5);
  await page.locator('.feature-tabs button').filter({hasText:'Müzik'}).click();assert.equal((await state()).media.tab,'Müzik');await snap('media');
  await key('Enter');assert.equal((await state()).view,'playback');await key('Space');assert.equal((await state()).playback.paused,true);await key('l');assert((await state()).playback.position>=15);await snap('playback');await key('x');assert.equal((await state()).view,'media');checks.push('Demo USB media category, play/pause, seek, stop');
  await page.locator('.feature-tabs button').filter({hasText:'Fotoğraf'}).click();await key('Enter');await page.locator('.feature-actions button').filter({hasText:'Sağa çevir'}).click();assert.equal((await state()).playback.rotation,90);assert.match(await page.locator('#tv-scene').getAttribute('style'),/rotate\(90deg\)/);await key('x');checks.push('Photo rotation changes the displayed example image');
  await fresh();await key('c');assert.equal((await state()).recording.active,false);await key('u');await key('c');assert.equal((await state()).recording.active,true);assert(await page.locator('#recording-indicator').isVisible());await page.waitForTimeout(1100);await key('x');assert.equal((await state()).recording.active,false);assert.equal((await state()).recording.items.length,1);
  await key('m');await page.locator('#home-items button').filter({hasText:/^Kayıt$/}).click();for(let i=0;i<4;i++)await key('ArrowDown');await key('Enter');assert.equal((await state()).view,'recordings');await snap('recordings');await key('Enter');assert.equal((await state()).playback.kind,'recording');await key('x');checks.push('Recording USB guard, indicator, stop, recording list and playback');
  await fresh();await key('b');await key('Enter');await key('Escape');assert(await page.locator('#broadcast-subtitle').isVisible());await key('a');assert.equal((await state()).path.at(-1),'quickAudio');await key('Escape');await key('t');assert.equal((await state()).view,'teletext');await page.keyboard.type('234');assert.equal((await state()).teletext.page,'234');await key('F5');assert.equal((await state()).teletext.page,'100');await snap('teletext');await key('Escape');assert.equal((await state()).view,'tv');checks.push('Subtitle visibility, audio menu, teletext numeric/color keys and back');
  await openMenu('programTimer');for(let i=0;i<7;i++)await key('ArrowDown');await key('Enter');assert.equal((await state()).programTimers.length,1);await key('ArrowDown');await key('Enter');assert.equal((await state()).view,'timers');await key('Enter');assert.equal((await state()).flow.title,'Zamanlayıcı Ayrıntıları');await key('Escape');await key('F5');assert.equal((await state()).programTimers.length,0);checks.push('Program timer add/list/details/delete via actual menu and color key');
  await openMenu('about');for(let i=0;i<9;i++)await key('ArrowDown');await key('Enter');assert.equal((await state()).flow.license,true);assert.match(await page.locator('.license-text').innerText(),/Bitstream/);const firstPage=await page.locator('.license-text').innerText();await key('ArrowDown');assert.notEqual(await page.locator('.license-text').innerText(),firstPage);await snap('license');await key('Escape');checks.push('Bundled public license text and remote pagination');
  await openMenu('manualSearch');await key('ArrowRight');await key('ArrowRight');assert.equal((await state()).values['search-source'],'Uydu');await key('ArrowDown');assert.equal(await page.locator('#settings-rows .is-focused .row-value').innerText(),'11054');const width=await page.locator('#settings-rows .is-focused .row-bar>span').evaluate(n=>parseFloat(n.style.width));assert(width>=0&&width<=100);checks.push('Satellite RF bounds and displayed progress agree');
  for(const viewport of [{width:1280,height:720},{width:390,height:844}]){await page.setViewportSize(viewport);await openMenu('manualSearch');await snap(`manual-${viewport.width}`);assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);}
  assert.deepEqual(errors,[]);
  const result={status:'pass',menus:visited.length,rows:visited.reduce((n,m)=>n+m.rows,0),visited,checks,consoleErrors:errors,deviceTested:false,codecTested:false};await fs.writeFile(path.join(out,'features-browser-tests.json'),JSON.stringify(result,null,2)+'\n');console.log(JSON.stringify(result,null,2));
}catch(error){await snap('failure');console.error(error);process.exitCode=1;}finally{await browser.close();}
