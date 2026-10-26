import test from 'node:test';
import assert from 'node:assert/strict';
import {createState,reduce,route,mode,SmoothLevel}from '../state.js';
test('volume boundaries and rapid repeats preserve every input',()=>{
  let s=createState();for(let i=0;i<200;i++)s=reduce(s,{type:'volume-up'},i);
  assert.equal(s.volume,100);for(let i=0;i<200;i++)s=reduce(s,{type:'volume-down'},i);
  assert.equal(s.volume,0);s=reduce(s,{type:'set-volume',value:32});
  for(let i=0;i<1000;i++)s=reduce(s,{type:i%2?'volume-down':'volume-up'},i);
  assert.equal(s.volume,32);assert.equal(s.sequence,1400);
});
test('mute toggles independently and survives auto-close',()=>{
  let s=reduce(createState(),{type:'mute'},100);assert.equal(mode(s),1);
  assert.equal(reduce(s,{type:'tick'},3099).volumeVisible,true);
  s=reduce(s,{type:'tick'},3100);assert.equal(s.volumeVisible,false);assert.equal(s.muted,true);
  assert.equal(reduce(s,{type:'mute'},3200).muted,false);
});
test('ARC requires every gate and never changes local volume',()=>{
  for(let mask=0;mask<8;mask++){
    let s=reduce(createState(),{type:'connection',arc:!!(mask&1),cec:!!(mask&2),hdmi:!!(mask&4)},0);
    assert.equal(route(s),mask===7?'arc':'local');s=reduce(s,{type:'volume-up'},20);
    assert.equal(s.volume,mask===7?32:33);
    if(mask===7){assert.equal(s.effect.kind,'simulated-cec');s=reduce(s,{type:'mute'},50);assert.equal(mode(s),3);s=reduce(s,{type:'connection',hdmi:false},70);assert.equal(route(s),'local');assert.equal(s.volume,32);assert.equal(s.muted,false);}
  }
});
test('remote menu, tabs, OK/back and rapid reopening',()=>{
  let s=createState();s=reduce(s,{type:'right'});assert.equal(s.card,2);
  s=reduce(s,{type:'ok'});assert.equal(s.detail,2);s=reduce(s,{type:'back'});assert.equal(s.detail,null);
  s=reduce(s,{type:'up'});s=reduce(s,{type:'right'});assert.equal(s.tab,0);
  s=reduce(s,{type:'ok'});assert.equal(s.detail,null);s=reduce(s,{type:'back'});assert.equal(s.menu,false);
  for(let i=0;i<200;i++)s=reduce(s,{type:'menu'});assert.equal(s.menu,false);
});
test('unsupported network/web/apps cannot be reached by remote or direct selection',()=>{
  let s=reduce(createState(),{type:'tab',value:2});assert.equal(s.tab,0);
  s=reduce(s,{type:'down'});for(let i=0;i<20;i++)s=reduce(s,{type:'right'});
  assert.equal(s.card,3);s=reduce(s,{type:'ok'});assert.equal(s.detail,3);
});
test('a CEC rejected key returns without changing local volume',()=>{
  let s=reduce(createState(),{type:'connection',arc:true,cec:true,hdmi:true,handled:false});
  s=reduce(s,{type:'volume-up'});assert.equal(s.volume,32);assert.equal(route(s),'arc');assert.equal(s.effect.accepted,false);
});
test('animation retargets continuously, settles and cannot overshoot',()=>{
  const m=new SmoothLevel(0,150);m.retarget(100,0);assert.equal(m.at(0),0);
  const before=m.at(50);m.retarget(0,50);assert.equal(m.at(50),before);assert.equal(m.at(200),0);
  for(let i=0;i<1000;i++){m.retarget(i%2?100:0,i*5);assert.ok(m.at(i*5)>=0&&m.at(i*5)<=100);}
  m.retarget(100,6000);m.retarget(100,6100);assert.equal(m.at(6150),100);
  const immediate=new SmoothLevel(0,0);immediate.retarget(50,10);assert.equal(immediate.at(10),50);
});
