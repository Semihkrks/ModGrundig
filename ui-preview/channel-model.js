// Read-only host model of the verified ChannelControlFrame digit/timer contract.
export function validateChannels(rows){
  const seen=new Set();
  if(!Array.isArray(rows))throw new Error('Kanal listesi bir dizi olmalı');
  return rows.map(r=>{
    if(!Number.isInteger(r.number)||r.number<0||r.number>9999||seen.has(r.number)||typeof r.name!=='string'||!r.name.trim())throw new Error('Geçersiz kanal verisi');
    seen.add(r.number);return{number:r.number,name:r.name,now:typeof r.now==='string'?r.now:'',next:typeof r.next==='string'?r.next:''};
  });
}
export function createChannelState(rows=[]){return{channels:validateChannels(rows),buffer:'',digitCount:0,deadline:null,list:false,index:0,current:null,intent:null,sequence:0};}
export function channelReduce(previous,action,now=0){
  const s={...previous,intent:null};
  const commit=number=>{s.intent={kind:'channel-number-intent',number,sequence:++s.sequence};s.current=s.channels.find(c=>c.number===number)||s.current;s.buffer='';s.digitCount=0;s.deadline=null;s.list=false;};
  if(action.type==='digit'&&/^\d$/.test(String(action.value))){
    s.list=false;s.digitCount++;
    if(s.digitCount<=4){s.buffer+=String(action.value);s.deadline=now+(s.digitCount===4?2000:3000);}
  }else if(action.type==='tick'&&s.deadline!==null&&now>=s.deadline)commit(Number(s.buffer));
  else if(action.type==='ok'){
    if(s.buffer){if(s.digitCount<5)commit(Number(s.buffer));}
    else if(!s.list)s.list=true;
    else if(s.channels[s.index])commit(s.channels[s.index].number);
  }else if(action.type==='back'){s.buffer='';s.digitCount=0;s.deadline=null;s.list=false;}
  else if((action.type==='up'||action.type==='down')&&s.list&&s.channels.length){s.index=Math.max(0,Math.min(s.channels.length-1,s.index+(action.type==='down'?1:-1)));}
  else if(['channel-up','channel-down'].includes(action.type)){
    // No fabricated channel list or tuning when the device's channel data is unavailable.
    if(s.channels.length){const i=s.channels.findIndex(c=>c.number===s.current?.number);const j=i<0?0:(i+(action.type==='channel-up'?1:-1)+s.channels.length)%s.channels.length;commit(s.channels[j].number);}
    else s.intent={kind:'device-channel-data-required',sequence:++s.sequence};
  }
  return s;
}
