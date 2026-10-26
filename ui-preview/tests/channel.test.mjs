import test from'node:test';import assert from'node:assert/strict';
import{createChannelState,channelReduce,validateChannels}from'../channel-model.js';
test('native digit timers: first three 3000ms, fourth 2000ms',()=>{
  let s=createChannelState();for(let i=1;i<=4;i++){s=channelReduce(s,{type:'digit',value:i},100*i);assert.equal(s.deadline,100*i+(i===4?2000:3000));}
  assert.equal(channelReduce(s,{type:'tick'},2399).intent,null);s=channelReduce(s,{type:'tick'},2400);assert.equal(s.intent.number,1234);
});
test('Enter, fifth-digit guard and cancellation retain native distinctions',()=>{
  let s=channelReduce(createChannelState(),{type:'digit',value:0});s=channelReduce(s,{type:'ok'});assert.equal(s.intent.number,0);
  s=createChannelState();for(const n of '12345')s=channelReduce(s,{type:'digit',value:n});assert.equal(s.buffer,'1234');assert.equal(channelReduce(s,{type:'ok'}).intent,null);
  s=channelReduce(s,{type:'back'});assert.equal(s.buffer,'');assert.equal(s.deadline,null);
});
test('missing device data never invents a successful tune or program name',()=>{
  let s=channelReduce(createChannelState(),{type:'ok'});assert.equal(s.list,true);assert.deepEqual(s.channels,[]);
  s=channelReduce(s,{type:'channel-up'});assert.equal(s.intent.kind,'device-channel-data-required');assert.equal(s.current,null);
});
test('data adapter accepts real records; selection/navigation and invalid data',()=>{
  const rows=[{number:1,name:'test fixture A'},{number:2,name:'test fixture B'}];
  let s=channelReduce(createChannelState(rows),{type:'ok'});s=channelReduce(s,{type:'down'});s=channelReduce(s,{type:'ok'});assert.equal(s.current.number,2);
  assert.throws(()=>validateChannels([...rows,{number:1,name:'duplicate'}]));assert.throws(()=>validateChannels([{number:10000,name:'invalid'}]));
});
