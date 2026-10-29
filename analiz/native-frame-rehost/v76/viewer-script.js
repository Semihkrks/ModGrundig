
const $=id=>document.getElementById(id);
const state={variant:'v7.6-tv',scene:'volume',volume:35,mute:false,digits:'12'};
let desired=0,busy=false,currentUrl=null,digitTime=0,currentMatch=null,confirmRevision=null,renderedRevision=0,timerRefresh=null,renderedElapsed=0;
function requestFrame(){clearTimeout(timerRefresh);currentMatch=null;confirmRevision=null;desired++;pump()}
function confirmSelection(){
 if(state.scene!=='numeric')return;
 if(busy){confirmRevision=desired;return}
 if(renderedRevision!==desired){$('status').textContent='Önizleme hazır değil';return}
 if(currentMatch===null){$('status').textContent='Bu sürümde kanal adı eşleştirmesi yok';return}
 if(currentMatch?.matched && currentMatch.number===Number(state.digits))$('status').textContent='Test seçimi '+state.digits+' · '+currentMatch.name;
 else $('status').textContent='Kayıtlı test kanalı yok';
 digitTime=0;
}
async function pump(){
 if(busy)return;busy=true;
 try{while(true){
  const revision=desired;
  const query=new URLSearchParams({...state,mute:state.mute?'1':'0'});
  if(state.variant==='v7.6-tv'&&state.scene==='numeric'){
   const duration=state.digits.length===4?2000:3000;
   query.set('elapsed_ms',String(digitTime?Math.min(duration,Math.floor((Date.now()-digitTime)/50)*50):0));
  }
  try{
   const res=await fetch('/frame.png?'+query);
   if(!res.ok)throw new Error('Native çizim tamamlanamadı ('+res.status+').');
   const blob=await res.blob();
   const channelHeader=res.headers?.get('X-Channel-Resolution');
   const channel=channelHeader?JSON.parse(decodeURIComponent(channelHeader)):null;
   if(revision===desired){const next=URL.createObjectURL(blob);$('frame').src=next;if(currentUrl)URL.revokeObjectURL(currentUrl);currentUrl=next;currentMatch=channel;renderedRevision=revision;renderedElapsed=Number(query.get('elapsed_ms')||0);$('error').textContent='';$('status').textContent=state.scene==='resources'?'v8 · native kaynak örnekleri':state.scene==='volume'?'Ses '+state.volume+(state.mute?' · mute':''):state.scene==='mute'?'Mevcut mute ikonu · zamanlayıcı ve gölge çalıştırılmaz':'Numara '+state.digits+(channel?.matched?' · '+channel.name+' (örnek)':'');break}
  }catch(error){if(revision===desired)throw error}
 }}catch(error){$('error').textContent=error.message}finally{busy=false;if(confirmRevision===desired){confirmRevision=null;confirmSelection()}
 if(state.variant==='v7.6-tv'&&state.scene==='numeric'&&digitTime&&(Date.now()-digitTime<(state.digits.length===4?2000:3000)||renderedElapsed<(state.digits.length===4?2000:3000)))timerRefresh=setTimeout(requestFrame,80);
 }
}
function changeVolume(delta){digitTime=0;state.scene='volume';$('scene').value='volume';state.volume=Math.max(0,Math.min(100,state.volume+delta));requestFrame()}
$('up').onclick=()=>changeVolume(1);$('down').onclick=()=>changeVolume(-1);
$('mute').onclick=()=>{digitTime=0;state.mute=!state.mute;state.scene='volume';$('scene').value='volume';requestFrame()};
$('variant').onchange=e=>{state.variant=e.target.value;if(['v7.5-tv','v7.6-tv'].includes(state.variant))state.digits=state.digits.slice(0,4);requestFrame()};
$('scene').onchange=e=>{digitTime=e.target.value==='numeric'?Date.now():0;state.scene=e.target.value;requestFrame()};
document.addEventListener('keydown',e=>{
 if(e.ctrlKey||e.metaKey||e.altKey)return;
 if(e.target instanceof HTMLSelectElement)return;
 if(['ArrowRight','ArrowUp','ArrowLeft','ArrowDown'].includes(e.key)){e.preventDefault();changeVolume(['ArrowRight','ArrowUp'].includes(e.key)?1:-1)}
 else if(e.key.toLowerCase()==='m'){e.preventDefault();$('mute').click()}
 else if(/^[0-9]$/.test(e.key)){e.preventDefault();const now=Date.now();state.digits=now-digitTime>1800?'':state.digits;digitTime=now;if(state.digits.length<(['v7.5-tv','v7.6-tv'].includes(state.variant)?4:5))state.digits+=e.key;state.scene='numeric';$('scene').value='numeric';requestFrame()}
 else if(e.key==='Backspace'&&state.scene==='numeric'){e.preventDefault();state.digits=state.digits.slice(0,-1);digitTime=Date.now();if(!state.digits){state.digits='0';state.scene='volume';$('scene').value='volume'}requestFrame()}
 else if(e.key==='Enter'&&state.scene==='numeric'){e.preventDefault();confirmSelection()}
 else if(e.key==='Escape'){digitTime=0;state.scene='volume';$('scene').value='volume';requestFrame()}
});
requestFrame();
