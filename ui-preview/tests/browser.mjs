import {createRequire} from 'node:module';
import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import assert from 'node:assert/strict';
const require=createRequire(import.meta.url);
const {chromium}=require(process.env.PLAYWRIGHT_MODULE||'C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright');
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..'),output=path.join(root,'analiz/ui-modernizasyon');await fs.mkdir(output,{recursive:true});
const browser=await chromium.launch({executablePath:'C:/Program Files/Google/Chrome/Application/chrome.exe',headless:true});
const page=await browser.newPage({viewport:{width:1920,height:1080}}),errors=[],dialogs=[],checks=[];
page.on('response',r=>{if(r.status()>=400)console.error('HTTP '+r.status()+' '+r.url());});page.on('pageerror',e=>errors.push(e.message));page.on('console',m=>{if(m.type()==='error')errors.push(m.text()+' '+JSON.stringify(m.location()));});page.on('dialog',async d=>{dialogs.push(d.type());await d.dismiss();});
const state=()=>page.evaluate(()=>window.modGrundig.getState()),key=k=>page.keyboard.press(k);
async function snap(name){await page.waitForTimeout(180);return page.screenshot({path:path.join(output,`tv-${name}.png`),fullPage:true});}
async function view(v){await page.waitForFunction(v=>window.modGrundig.getState().view===v,v);}
async function home(){if((await state()).view!=='home')await key('m');await view('home');}
try{
await page.goto(process.env.PREVIEW_URL||'http://127.0.0.1:4174/preview/');await page.waitForFunction(()=>window.modGrundig);await view('tv');
assert.equal(await page.locator('input,select,textarea,[role="dialog"]').count(),0);assert.equal(await page.locator('button').filter({hasText:/^[×✕✖X]$/}).count(),0);
await key('Escape');await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:36}));await snap('volume-slim-tv');
await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:0}));await snap('volume-slim-zero');
await page.locator('#volume-panel').waitFor({state:'hidden',timeout:3300});
assert.equal(await page.locator('#mute-badge').isVisible(),true);
await key('+');assert.equal((await state()).volume,1);assert.equal(await page.locator('#mute-badge').isVisible(),false);
assert.equal(await page.locator('#stage').getAttribute('data-muted'),'false');
await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:32}));
checks.push('zero silence survives panel auto-hide; volume-up clears automatic silence');
await home();assert.ok(await page.locator('#home-items button').count()>1);assert.ok(await page.locator('#home-secondary button').count()>4);await snap('home-1920');await key('ArrowDown');assert.equal((await state()).homeZone,'secondary');await key('Enter');await view('settings');assert.equal((await state()).path.at(-1),'picture');assert.ok(await page.locator('#settings-rows .tv-row').count()>1);await snap('picture-1920');
const before=(await state()).values;await key('ArrowDown');await key('ArrowRight');assert.notDeepEqual((await state()).values,before);checks.push('M two shelves; Down/OK picture; arrows change setting');
await key('Escape');await home();await key('ArrowDown');await key('ArrowRight');await key('Enter');await view('settings');assert.equal((await state()).path.at(-1),'sound');await snap('sound-1920');checks.push('Back/Home and sound category');
await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:0}));await key('-');assert.equal((await state()).volume,0);
assert.equal(await page.locator('#stage').getAttribute('data-muted'),'true');
assert.equal(await page.locator('#volume-icon').getAttribute('src'),'./native-assets/volume-mute.png');
assert.equal(await page.locator('#volume-thumb').count(),0);
assert.equal(await page.locator('#mute-badge').isVisible(),false);
await snap('volume-0');await key('+');assert.equal((await state()).volume,1);
assert.equal(await page.locator('#stage').getAttribute('data-muted'),'false');await page.evaluate(()=>window.modGrundig.dispatch({type:'set-volume',value:100}));await key('+');assert.equal((await state()).volume,100);assert.equal(await page.locator('#volume-panel').evaluate(n=>n.offsetHeight),450);assert.equal(await page.locator('#volume-panel').evaluate(n=>n.offsetWidth),68);
await snap('volume-100');await key('s');assert.equal((await state()).muted,true);await snap('mute');await key('s');assert.equal((await state()).muted,false);checks.push('volume 0/100, 68x450 logical size, native PNG icon, no thumb, automatic zero mute, mute');
await page.evaluate(()=>{window.modGrundig.dispatch({type:'set-volume',value:100});window.modGrundig.dispatch({type:'action',name:'reset-sound'});});
await page.locator('#settings-rows button').filter({hasText:'Onayla'}).click();assert.equal((await state()).volume,32);assert.equal((await state()).confirm,null);
await page.evaluate(()=>{window.modGrundig.dispatch({type:'set-volume',value:67});window.modGrundig.dispatch({type:'action',name:'reset-sound'});});
await page.locator('#settings-rows button').filter({hasText:'Vazgeç'}).click();assert.equal((await state()).volume,67);assert.equal((await state()).confirm,null);checks.push('confirmation row click commits sound reset; cancel preserves volume');
await page.evaluate(()=>{window.modGrundig.dispatch({type:'set-volume',value:36});window.modGrundig.dispatch({type:'menu'});window.modGrundig.dispatch({type:'menu'});});
await key('m');await key('m');await view('tv');await page.keyboard.type('12');assert.equal(await page.locator('#number-digits').innerText(),'12');await snap('number');await key('Enter');await view('tv');let s=await state();assert.equal(s.channels[s.channelIndex].number,12);await key('Enter');await view('list');assert.ok(await page.locator('#channel-list-rows .tv-row').count()>1);const old=(await state()).channelIndex;await key('ArrowUp');await snap('channels-1920');await key('Enter');await view('tv');assert.notEqual((await state()).channelIndex,old);checks.push('12/Enter tune and OK list Up/OK tune');
await key('i');assert.equal(await page.locator('#channel-info-panel').isVisible(),true);await snap('info-1920');await key('v');await view('source');await key('ArrowRight');await key('Enter');assert.equal((await state()).source,'HDMI 1');await key('v');await key('ArrowLeft');await key('Enter');assert.equal((await state()).source,'TV');checks.push('info and input source');
await key('F1');assert.equal(await page.locator('#test-controls').isVisible(),true);await snap('remote');
const local=(await state()).volume;
await page.locator('[data-action="toggle-arc"]').click();assert.equal(await page.locator('[data-action="toggle-arc"]').getAttribute('aria-pressed'),'true');
await page.locator('#test-controls [data-action="volume-up"]').click();assert.equal((await state()).volume,local);assert.equal(await page.locator('#stage').getAttribute('data-route'),'arc');await snap('arc');
await page.locator('[data-action="toggle-handled"]').click();await page.locator('#test-controls [data-action="volume-down"]').click();assert.equal((await state()).volume,local);assert.equal(await page.locator('#stage').getAttribute('data-route'),'arc');assert.equal((await state()).effect.accepted,false);
await page.locator('[data-action="toggle-arc"]').click();checks.push('F1 ARC preserves local volume; rejected CEC returns without local fallback (native OnKey)');
await page.locator('#test-controls [data-action="menu"]').click();await view('home');await key('F1');assert.equal(await page.locator('#test-controls').isVisible(),false);checks.push('F1 remote and menu click');
for(const viewport of [{width:1920,height:1080},{width:1280,height:720},{width:390,height:844}]){await page.setViewportSize(viewport);await home();await page.waitForTimeout(200);const g=await page.evaluate(()=>({overflow:document.documentElement.scrollWidth>innerWidth,stage:document.querySelector('#stage').getBoundingClientRect().width,screen:document.querySelector('#screen').getBoundingClientRect().width}));assert.equal(g.overflow,false);assert.ok(g.stage>100&&g.stage<=viewport.width);assert.ok(Math.abs(g.screen-g.stage)<2);await snap(`home-${viewport.width}x${viewport.height}`);await key('ArrowDown');await key('Enter');await view('settings');await snap(`settings-${viewport.width}x${viewport.height}`);await key('Escape');}checks.push('1920x1080 / 1280x720 / 390x844 scale, no overflow');
assert.deepEqual(dialogs,[]);assert.deepEqual(errors,[]);const result={status:'pass',browser:'installed Chrome via Playwright',checks,pageErrors:errors,dialogs,firmware_tested:false,tv_tested:false};await fs.writeFile(path.join(output,'browser-tests.json'),JSON.stringify(result,null,2)+'\n');console.log(JSON.stringify(result,null,2));
}catch(error){await snap('failure');console.error(error);process.exitCode=1;}finally{await browser.close();}






