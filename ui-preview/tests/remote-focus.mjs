import {createRequire} from 'node:module';
import fs from 'node:fs/promises';
import path from 'node:path';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';

const require=createRequire(import.meta.url);
const {chromium}=require(process.env.PLAYWRIGHT_MODULE||'C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const base=process.env.PREVIEW_URL||'http://127.0.0.1:4174/preview/';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..');
const output=path.join(root,'analiz/ui-modernizasyon/menu-v7/remote-focus-tests.json');
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
const page=await browser.newPage({viewport:{width:1920,height:1080}});
const errors=[],checks=[];
page.on('pageerror',e=>errors.push(e.message));
page.on('console',m=>{if(m.type()==='error')errors.push(m.text());});
page.on('response',r=>{if(r.status()>=400)errors.push(`HTTP ${r.status()} ${r.url()}`);});
const state=()=>page.evaluate(()=>window.modGrundig.getState());
const focused=()=>page.evaluate(()=>({id:document.activeElement.id,action:document.activeElement.dataset.action}));
const tvSelection=s=>({view:s.view,home:s.home,homeZone:s.homeZone,category:s.category,path:s.path});
try{
  await page.goto(base+'?menu=1');await page.waitForFunction(()=>window.modGrundig);
  const initial=tvSelection(await state());
  await page.keyboard.press('Tab');assert.equal((await focused()).id,'remote-toggle');
  assert.deepEqual(tvSelection(await state()),initial);
  await page.keyboard.press('Enter');assert.equal(await page.locator('#remote-toggle').getAttribute('aria-expanded'),'true');
  assert.deepEqual(tvSelection(await state()),initial);
  assert.equal((await focused()).id,'remote-toggle');
  await page.keyboard.press('Tab');assert.equal((await focused()).action,'power');
  await page.keyboard.press('Shift+Tab');assert.equal((await focused()).id,'remote-toggle');
  checks.push('Tab reaches native remote toggle; Enter opens it without selecting a TV menu; Shift+Tab returns logically');

  let steps=0;
  while((await focused()).action!=='toggle-arc'&&steps++<100)await page.keyboard.press('Tab');
  assert(steps<100,'ARC must be reachable using Tab alone');
  assert.equal((await state()).arc,false);
  await page.keyboard.press('Enter');assert.equal((await state()).arc,true);
  assert.equal((await focused()).action,'toggle-arc');assert.deepEqual(tvSelection(await state()),initial);
  await page.keyboard.press('Space');assert.equal((await state()).arc,false);
  assert.equal((await focused()).action,'toggle-arc');assert.deepEqual(tvSelection(await state()),initial);
  assert.equal((await state()).playback,null);
  checks.push('Every remote control remains in native Tab order; ARC Enter/Space activates once, retains focus and sends no extra OK/playback command');

  const volume=page.locator('#test-controls [data-action="volume-up"]');await volume.focus();
  const before=(await state()).volume;
  await page.keyboard.press('Space');await page.keyboard.press('Space');
  assert.equal((await state()).volume,before+2);assert.equal((await focused()).action,'volume-up');
  checks.push('Repeated Space on volume-up changes volume twice while retaining keyboard focus');

  await page.keyboard.press('F1');assert.equal(await page.locator('#remote-toggle').getAttribute('aria-expanded'),'false');
  assert.equal((await focused()).id,'remote-toggle');
  await page.keyboard.press('Space');assert.equal(await page.locator('#remote-toggle').getAttribute('aria-expanded'),'true');
  await page.keyboard.press('Space');assert.equal(await page.locator('#remote-toggle').getAttribute('aria-expanded'),'false');
  assert.deepEqual(tvSelection(await state()),initial);
  checks.push('F1 closes remote and restores focus; Space toggles browser remote without TV playback action');

  await page.evaluate(()=>document.activeElement.blur());
  await page.keyboard.press('ArrowRight');assert.equal((await state()).home,initial.home+1);
  await page.keyboard.press('Enter');assert.notEqual((await state()).view,'home');
  checks.push('Arrows and Enter from TV screen retain remote menu navigation/activation');

  await page.goto(base+'?menu=1');await page.waitForFunction(()=>window.modGrundig);
  for(const key of ['ArrowDown','ArrowRight','ArrowRight','Enter','ArrowDown','Enter','ArrowDown','ArrowDown','ArrowRight'])await page.keyboard.press(key);
  assert.equal((await state()).values['channels-service-type'],'Radyo');
  for(const key of ['ArrowUp','ArrowUp','Enter'])await page.keyboard.press(key);
  assert.equal((await state()).view,'list');
  assert.equal(await page.locator('#channel-list-rows button').count(),0);
  const empty=await page.locator('#channel-list-rows .empty-state').innerText();
  assert.match(empty,/Kayıtlı radyo kanalı yok/);assert.match(empty,/Geri.*TV \/ Radyo/);assert.doesNotMatch(empty,/F2|Favori kanal yok/);
  assert.doesNotMatch(await page.locator('#channel-list-footer').innerText(),/F2|İzle/);
  await page.keyboard.press('ArrowRight');assert.equal((await state()).filter,1);
  assert.equal(await page.locator('#channel-list-rows .empty-state').innerText(),empty);
  await page.keyboard.press('Escape');assert.equal((await state()).path.at(-1),'channels');
  for(const key of ['ArrowDown','ArrowDown','ArrowLeft','ArrowUp','ArrowUp','Enter'])await page.keyboard.press(key);
  assert.equal((await state()).values['channels-service-type'],'TV');
  assert(await page.locator('#channel-list-rows button').count()>0);
  checks.push('Empty radio list explains absent radio fixtures and how to return to TV; no false favorite/F2 or Watch hint; returning through TV/Radyo setting restores channels');
  assert.deepEqual(errors,[]);
  await fs.mkdir(path.dirname(output),{recursive:true});
  const result={status:'pass',date:new Date().toISOString(),browser:'installed Chrome via Playwright',base,checks,errors,deviceTested:false,firmwareExecuted:false};
  await fs.writeFile(output,JSON.stringify(result,null,2)+'\n');console.log(JSON.stringify(result,null,2));
}catch(error){console.error(error);process.exitCode=1;}finally{await browser.close();}
