import {createChannelState,channelReduce}from './channel-model.js';
export async function createChannelUI(screen,status){
  const response=await fetch('./channels.json');if(!response.ok)throw new Error('Kanal veri dosyası okunamadı');
  const data=await response.json();let state=createChannelState(data.channels);
  const numeric=document.createElement('div');numeric.id='channel-number-osd';numeric.hidden=true;numeric.setAttribute('aria-live','polite');screen.append(numeric);
  const list=document.createElement('section');list.id='channel-list-panel';list.hidden=true;list.setAttribute('aria-label','KANAL LİSTESİ');screen.append(list);
  const info=document.createElement('section');info.id='channel-info-panel';info.hidden=true;screen.append(info);
  function render(){
    numeric.hidden=!state.buffer;numeric.textContent=state.buffer;
    list.hidden=!state.list||!data.geometry_verified;list.replaceChildren();
    const title=document.createElement('h2');title.textContent='KANAL LİSTESİ';list.append(title);
    if(!state.channels.length){const p=document.createElement('p');p.textContent='Kanal verisi bulunamadı.';list.append(p);}
    else state.channels.forEach((channel,index)=>{const row=document.createElement('button');row.textContent=`${channel.number}  ${channel.name}`;row.className=index===state.index?'focused':'';row.addEventListener('click',()=>{state={...state,index};act({type:'ok'});});list.append(row);});
    info.hidden=!state.current||!data.geometry_verified||!data.device_data_verified;info.replaceChildren();
    if(state.current){const h=document.createElement('h2');h.textContent=`${state.current.number}  ${state.current.name}`;info.append(h);for(const text of [state.current.now,state.current.next]){if(text){const p=document.createElement('p');p.textContent=text;info.append(p);}}}
    if(state.intent)status.textContent=state.intent.kind==='device-channel-data-required'?'Gerçek kanal verisi bekleniyor; örnek kanal listesi kullanılmıyor.':`Kanal ${state.intent.number} seçme isteği · tuner bağlantısı yok`;
    else if(state.list&&!data.geometry_verified)status.textContent='OK → kanal listesi yolu hazır. Gerçek kanal verisi ve native son yerleşim doğrulanmadan farklı bir liste görünümü gösterilmiyor.';
  }
  function act(action){state=channelReduce(state,action,performance.now());render();}
  function handleKey(event,idle){
    if(!idle)return false;
    const key=event.key;
    if(/^\d$/.test(key)){act({type:'digit',value:key});return true;}
    if(key==='Enter'){act({type:'ok'});return true;}
    if(['Escape','Backspace'].includes(key)&&(state.list||state.buffer)){act({type:'back'});return true;}
    if(['ArrowUp','ArrowDown'].includes(key)&&state.list){act({type:key==='ArrowDown'?'down':'up'});return true;}
    if(['PageUp','PageDown'].includes(key)){act({type:key==='PageUp'?'channel-up':'channel-down'});return true;}
    return false;
  }
  return{act,handleKey,getState:()=>structuredClone(state),tick:now=>{if(state.deadline!==null&&now>=state.deadline){state=channelReduce(state,{type:'tick'},now);render();}}};
}
