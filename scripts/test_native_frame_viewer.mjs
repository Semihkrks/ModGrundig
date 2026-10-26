// Exercise the actual viewer script against controlled fetch completions.
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import test from 'node:test';
import vm from 'node:vm';
const html=readFileSync(new URL('../native-ui/frame-viewer/index.html',import.meta.url),'utf8');
const script=html.match(/<script>([\s\S]*?)<\/script>/)[1];
const flush=()=>new Promise(resolve=>setImmediate(resolve));
function setup(){
 const elements=Object.fromEntries(['variant','scene','up','down','mute','status','frame','error'].map(id=>[id,{value:'',textContent:''}]));
 const requests=[];
 const listeners={};
 const context=vm.createContext({document:{getElementById:id=>elements[id],addEventListener:(name,fn)=>listeners[name]=fn},
  fetch:url=>new Promise((resolve,reject)=>requests.push({url,resolve,reject})),
  URLSearchParams,URL:{createObjectURL:()=> 'blob:frame',revokeObjectURL(){}},HTMLSelectElement:class{},console});
 vm.runInContext(script,context);
 const press=key=>listeners.keydown({key,preventDefault(){},target:null});
 return {elements,requests,context,press};
}
const ok=channel=>({ok:true,blob:async()=>({}),headers:{get:()=>channel?encodeURIComponent(JSON.stringify(channel)):null}});
test('a failed obsolete frame cannot discard the newest key input',async()=>{
 const {elements,requests,context}=setup();
 vm.runInContext('changeVolume(1)',context);
 requests[0].resolve({ok:false,status:500});
 await flush();
 assert.equal(requests.length,2);
 assert.match(requests[1].url,/volume=36/);
 requests[1].resolve(ok());await flush();
 assert.equal(elements.status.textContent,'Ses 36');
 assert.equal(elements.error.textContent,'');
});
test('a current render error is reported once without infinite retries',async()=>{
 const {elements,requests}=setup();
 requests[0].reject(new Error('offline'));await flush();
 assert.equal(requests.length,1);
 assert.equal(elements.error.textContent,'offline');
});
test('rapid key inputs coalesce and preserve both endpoint limits',async()=>{
 const {elements,requests,context}=setup();
 vm.runInContext('for(let i=0;i<150;i++)changeVolume(1)',context);
 requests[0].resolve(ok());await flush();
 assert.equal(requests.length,2);
 assert.match(requests[1].url,/volume=100/);
 requests[1].resolve(ok());await flush();
 assert.equal(elements.status.textContent,'Ses 100');
 vm.runInContext('for(let i=0;i<150;i++)changeVolume(-1)',context);
 requests[2].resolve(ok());await flush();
 assert.equal(requests.length,4);
 assert.match(requests[3].url,/volume=0/);
 requests[3].resolve(ok());await flush();
 assert.equal(elements.status.textContent,'Ses 0');
});
test('Enter waits for the latest matched destination instead of the old frame',async()=>{
 const {elements,requests,press}=setup();
 press('1');press('2');press('Enter');
 requests[0].resolve(ok({number:1,name:'TRT 1',matched:true}));await flush();
 assert.equal(requests.length,2);
 assert.match(requests[1].url,/digits=12/);
 assert.doesNotMatch(elements.status.textContent,/Test seçimi/);
 requests[1].resolve(ok({number:12,name:'TRT Müzik',matched:true}));await flush();
 assert.equal(elements.status.textContent,'Test seçimi 12 · TRT Müzik');
});
test('typing after an earlier Enter cancels that stale selection intent',async()=>{
 const {elements,requests,press}=setup();
 press('1');press('Enter');press('2');
 requests[0].resolve(ok({number:1,name:'TRT 1',matched:true}));await flush();
 requests[1].resolve(ok({number:12,name:'TRT Müzik',matched:true}));await flush();
 assert.equal(elements.status.textContent,'Numara 12 · TRT Müzik (örnek)');
});
test('Backspace edits digits and extra digit cannot discard the entered prefix',async()=>{
 const {requests,context,press}=setup();
 press('1');press('2');press('Backspace');
 assert.equal(vm.runInContext('state.digits',context),'1');
 press('2');press('3');press('4');press('5');press('6');
 assert.equal(vm.runInContext('state.digits',context),'12345');
 requests[0].resolve(ok());await flush();requests[1].resolve(ok());await flush();
});
test('unmatched numeric input cannot confirm an unrelated channel',async()=>{
 const {elements,requests,press}=setup();
 press('9');press('9');press('9');press('Enter');
 requests[0].resolve(ok({number:12,name:'TRT Müzik',matched:true}));await flush();
 requests[1].resolve(ok({number:999,name:'Kayıtlı kanal yok',matched:false}));await flush();
 assert.equal(elements.status.textContent,'Kayıtlı test kanalı yok');
});
test('Escape and successful confirmation both end the numeric entry session',async()=>{
 const {requests,context,press}=setup();
 press('1');press('2');press('Escape');press('3');
 assert.equal(vm.runInContext('state.digits',context),'3');
 requests[0].resolve(ok());await flush();
 requests[1].resolve(ok({number:3,name:'ATV',matched:true}));await flush();
 press('Enter');press('4');
 assert.equal(vm.runInContext('state.digits',context),'4');
 requests[2].resolve(ok({number:4,name:'Kanal D',matched:true}));await flush();
});
test('failed current resolution cannot be misreported as an unregistered channel',async()=>{
 const {elements,requests,press}=setup();
 press('1');press('Enter');requests[0].resolve(ok());await flush();
 requests[1].reject(new Error('offline'));await flush();
 assert.equal(elements.error.textContent,'offline');
 assert.equal(elements.status.textContent,'Önizleme hazır değil');
});
