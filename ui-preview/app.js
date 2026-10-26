import {MENUS} from './firmware-menu-data.js';
import {HOME,CATEGORIES,INPUTS,MEDIA_TABS,mediaItems,rangeBounds,createTVState,tvReduce,audioRoute,audioMuted,currentChannel,filteredChannels} from './tv-model.js';
import {SmoothLevel} from './state.js';
import {renderFeature} from './feature-renderer.js';
const $=id=>document.getElementById(id);
const data=await fetch('./channels.json').then(r=>{if(!r.ok)throw Error('Kanal verisi yüklenemedi');return r.json();});
if(!data.demo)throw Error('Demonstration channel data must be labelled');
let state=createTVState(MENUS,data.channels,performance.now());
const reduced=matchMedia('(prefers-reduced-motion: reduce)').matches;
const level=new SmoothLevel(state.volume,reduced?0:150),stage=$('stage'),screen=$('screen');
let lastInput=performance.now(),lastRender=0,lastFrame=0,lastModelTick=0,renderedState=null;
function el(tag,text,cls){const n=document.createElement(tag);if(text!==undefined)n.textContent=text;if(cls)n.className=cls;return n;}
const tvSymbols=new Set(['settings','picture','speaker','mute','source','tv','channels','edit','media','timer','lock','record','usb','back','play','pause']);
function svg(name){const s=document.createElementNS('http://www.w3.org/2000/svg','svg');s.setAttribute('aria-hidden','true');const u=document.createElementNS(s.namespaceURI,'use');u.setAttribute('href',`./${tvSymbols.has(name)?'tv-icons':'icons'}.svg#icon-${name}`);s.append(u);return s;}
function button(label,action,index,cls='tv-row',focused=false){const n=el('button',undefined,`${cls}${focused?' is-focused':''}`);n.type='button';n.tabIndex=-1;n.dataset.action=action;if(index!==undefined)n.dataset.index=index;n.setAttribute('aria-label',label);if(focused)n.setAttribute('aria-current','true');return n;}
function hints(target,items){$(target).replaceChildren(...items.map(([key,label])=>{const s=el('span');s.append(el('b',key),document.createTextNode(label));return s;}));}
function row(label,value,focused=false,action='ok',index){const n=button(value!==undefined&&value!==''&&value!=='›'?`${label}, ${value}`:label,action,index,'tv-row',focused);n.append(el('span',label,'row-label'));if(value!==undefined)n.append(el('span',String(value),'row-value'));return n;}
function show(id,yes){$(id).hidden=!yes;}
const time=()=>{const offset=(parseInt(String(state.values['clock-zone']??'UTC+3').replace('UTC',''))||0)+(state.values['clock-daylight']?1:0);return new Date(Date.now()+offset*3600000).toISOString().slice(11,16);};
function renderHome(){
  const homeIcons={settings:'settings',recording:'record',editor:'edit',list:'channels',timer:'timer'};
  $('home-items').replaceChildren(...HOME.map((c,i)=>{const n=button(c.label,'activate-home',i,'home-item',state.homeZone==='main'&&state.home===i);n.append(svg(homeIcons[c.action]??c.icon),el('span',c.label));return n;}));
  const icons={picture:'picture',sound:'speaker',source:'source',parental:'lock',timer:'timer',tv:'settings'};
  $('home-secondary').replaceChildren(...CATEGORIES.map((c,i)=>{const focus=state.homeZone==='secondary'&&state.category===i,n=button(c.label,'activate-category',i,'setting-card',focus);n.append(svg(icons[c.menu]),el('span',c.label));return n;}));
  $('home-secondary').style.opacity=state.home===0?'1':'.52';
  $('home-secondary').inert=state.home!==0;$('home-secondary').setAttribute('aria-hidden',String(state.home!==0));
  hints('home-footer',[['◀ ▶','Gezin'],['▼','Ayarlar'],['OK','Seç'],['↶','TV’ye dön']]);
}
function renderSettings(){
  const menu=MENUS[state.path.at(-1)];if(!menu)return;
  $('settings-title').textContent=menu.title;$('settings-breadcrumb').textContent=['Ayarlar',...state.path.slice(0,-1).map(k=>MENUS[k].title)].join('  /  ');
  const start=Math.max(0,Math.min(state.row-3,menu.rows.length-7));
  $('settings-rows').replaceChildren(...menu.rows.slice(start,start+7).map((r,i)=>{
    const value=state.values[r.id],arcVolume=r.id==='sound-volume'&&audioRoute(state)==='arc',text=arcVolume?'HDMI ARC':r.type==='submenu'?'›':r.type==='action'?'':r.type==='toggle'?(value?'Açık':'Kapalı'):r.valueText??value??'';
    const n=row(r.label,text,state.row===start+i,'activate-row',start+i);
    if(r.type==='range'&&!arcVolume){const bounds=rangeBounds(state,r),bar=el('span',undefined,'row-bar'),fill=el('span');fill.style.width=`${100*(value-bounds.min)/(bounds.max-bounds.min)}%`;bar.append(fill);n.insertBefore(bar,n.lastChild);}
    if(['range','choice','toggle'].includes(r.type))n.append(el('span','◀  ▶','row-arrow'));
    return n;
  }));hints('settings-footer',[['▲ ▼',`${state.row+1} / ${menu.rows.length}`],['◀ ▶','Değiştir'],['OK','Seç'],['↶','Geri']]);
}
function renderChannels(){
  const list=filteredChannels(state),focus=Math.max(0,Math.min(state.listFocus,list.length-1)),selected=list[focus];
  $('channel-list-title').textContent=state.view==='editor'?'Kanal Düzenleyici':state.view==='guide'?'TV Rehberi':'Kanal Listesi';
  $('channel-list-tabs').replaceChildren(...['Tüm Kanallar','Favoriler'].map((title,i)=>{const b=button(title,'filter',i,'',state.filter===i);b.textContent=title;b.setAttribute('aria-pressed',String(state.filter===i));return b;}));
  const start=Math.max(0,Math.min(focus-3,list.length-8));
  $('channel-list-rows').replaceChildren(...list.slice(start,start+8).map((c,i)=>{const n=button(c.name,'activate-channel',start+i,'tv-row',focus===start+i);n.append(el('span',String(c.number).padStart(3,'0'),'channel-number'),el('span',c.name,'channel-name'));if(c.favorite)n.append(el('span','★','channel-favorite'));if(c.skip)n.append(el('span','Atla','channel-badge'));if(c.locked)n.append(svg('lock'));if(c.index===state.channelIndex)n.append(el('span','İzleniyor','channel-badge'));return n;}));
  if(!list.length){const radio=state.values['channels-service-type']==='Radyo',noRadio=radio&&!state.channels.some(c=>c.serviceType==='Radyo');const message=noRadio?'Kayıtlı radyo kanalı yok. Geri dönüp Program Tablosu > TV / Radyo ayarını TV seçin.':state.filter===1?`Favori${radio?' radyo':''} kanal yok. Tüm Kanallar bölümünden F2 ile ekleyin.`:'Kayıtlı kanal yok. Kaynak Ayarları bölümünden kanal araması yapabilirsiniz.';$('channel-list-rows').append(el('p',message,'empty-state'));}
  $('channel-list-details').replaceChildren();if(selected)$('channel-list-details').append(el('p',`Kanal ${String(selected.number).padStart(3,'0')} · Örnek program`,'program-time'),el('h3',selected.name),el('p','Şimdi','program-label'),el('p',selected.now,'program-title'),el('p',selected.description,'program-description'),el('p',`Sıradaki: ${selected.next}`,'program-next'),el('small',`${selected.genre} · Dijital TV · Test yayın bilgileri`));
  hints('channel-list-footer',!list.length?[['◀ ▶','Liste / Favoriler'],['↶','Geri']]:state.view==='editor'?[['OK',state.editorMoving?'Taşımayı bitir':'Taşı'],['F2','Favori'],['F3','Atla'],['F4','Kilitle'],['↶','Geri']]:[['OK','İzle'],['◀ ▶','Liste / Favoriler'],['F2','Favori'],['↶','Geri']]);
}
function renderAuxiliary(){
  if(!state.confirm&&renderFeature(state,{$,el,row,button,svg,hints,mediaItems,mediaTabs:MEDIA_TABS}))return;
  let title='',items=[];const f=state.flow;
  if(state.view==='media'){title='Medya Oynatıcı';items=[[state.usb?'USB aygıtı bağlı':'USB aygıtı bağlı değil',state.usb?'Test USB’si':'USB bağlayın'],['Fotoğraf / Müzik / Video','Dosya kaynağı bağlı değil']];}
  if(state.view==='scan'){title='Otomatik Kanal Arama';items=[['Örnek kanallar taranıyor',`${state.scanProgress}%`],['Kayıtlı demo kanallar',String(state.channels.length)]];}
  if(state.view==='signal'){title='Sinyal Bilgileri';items=[['Kanal',currentChannel(state).name],['Sinyal gücü','Gerçek ölçüm yok'],['Sinyal kalitesi','Gerçek ölçüm yok']];}
  if(state.view==='manual-scan'){title='Manuel Kanal Arama';items=[['Kanal numarası',f?.digits||'—'],['Aramayı Başlat','Numara + OK']];}
  if(state.view==='pin'){title=f?.title||'PIN';const count=f?.digits?.length??0;items=[['PIN kodu','●'.repeat(count)+'—'.repeat(Math.max(0,4-count))],['Adım',({verify:'PIN doğrulama',current:'Geçerli PIN',new:'Yeni PIN',confirm:'Yeni PIN’i tekrar girin'})[f?.step]??'PIN doğrulama']];}
  if(f?.error)items.push([f.error,'']);
  if(state.confirm){title=state.confirm.title;items=[['Vazgeç',state.confirmChoice===0?'◀ Seçili':''],['Onayla',state.confirmChoice===1?'Seçili ▶':'']];}
  $('settings-title').textContent=title;$('settings-breadcrumb').textContent='TV';$('settings-rows').replaceChildren(...items.map(([label,value],i)=>row(label,value,state.confirm?state.confirmChoice===i:i===0,state.confirm?'confirm-choice':'ok',state.confirm?i:undefined)));
  hints('settings-footer',state.confirm?[['◀ ▶','Seç'],['OK','Onayla'],['↶','Vazgeç']]:[['0–9','Numara'],['OK','Seç'],['↶','Geri']]);
}
function renderNumber(now){
  const visible=!state.standby&&!!state.digits;show('channel-number-osd',visible);
  if(!visible)return;
  const match=state.channels.find(c=>c.number===Number(state.digits));
  const digits=$('number-digits');if(!digits)return;
  digits.textContent=state.digits;
  $('number-channel').textContent=match?match.name:'Kayıtlı kanal yok';
  $('channel-number-osd').dataset.match=String(!!match);
  $('channel-number-osd').setAttribute('aria-label',`Kanal seçimi ${state.digits}, ${match?.name??'Kayıtlı kanal yok'}`);
  updateNumberCountdown(now);
}
function updateNumberCountdown(now){
  if(!state.digits||!$('number-hint'))return;
  const remaining=Math.max(0,(state.digitDeadline??now)-now),duration=state.digits.length===4?2000:3000;
  $('number-hint').textContent=state.digitCount>=5?'Sil veya sürenin dolmasını bekle':`OK ile seç · ${Math.ceil(remaining/1000)} sn`;
  $('number-progress').firstElementChild.style.transform=`scaleX(${Math.min(1,remaining/duration)})`;
}
function renderPicture(){
  const v=state.values,mode=v['picture-mode'],warm=v['picture-temperature']==='Sıcak',cool=v['picture-temperature']==='Soğuk';
  const backlight=Number(v['picture-manual-backlight']??v['picture-backlight']??70);
  const brightness=(.6+Number(v['picture-brightness']??50)/125)*(.6+backlight/175)*(2.2/Number(v['picture-gamma']??2.2));
  const contrast=(.65+Number(v['picture-contrast']??70)/200)*(mode==='Canlı'?1.12:1);
  const saturation=Number(v['picture-color']??50)/50*(mode==='Canlı'?1.18:mode==='Film'?.92:1);
  const scene=$('tv-scene');scene.style.filter=`brightness(${brightness}) contrast(${contrast}) saturate(${saturation}) sepia(${warm?.12:0}) hue-rotate(${Number(v['picture-hue']??0)+(warm?-4:cool?7:0)}deg)`;
  const rotation=state.view==='playback'&&state.playback?.type==='Fotoğraf'?state.playback.rotation??0:0;scene.style.transform=`rotate(${rotation}deg) scale(${rotation%180===0?1:.5625})`;
  const format=v['picture-format'];scene.style.width=format==='4:3'?'1440px':'1920px';scene.style.height=format==='Letterbox'?'810px':'1080px';scene.style.left=format==='4:3'?'240px':'0';scene.style.top=format==='Letterbox'?'135px':'0';
}
function render(now=performance.now()){
  const awake=!state.standby,view=state.view,aux=['media','playback','operation','teletext','recordings','timers','scan','signal','manual-scan','pin'].includes(view)||!!state.confirm;
  show('menu',awake&&view==='home'&&!state.confirm);stage.dataset.menu=awake&&view==='home'&&!state.confirm?'open':'closed';
  show('settings-panel',awake&&(view==='settings'||aux));show('channel-list-panel',awake&&['list','editor','guide'].includes(view)&&!state.confirm);show('source-panel',awake&&view==='source'&&!state.confirm);
  const contentChanged=renderedState!==state;
  if(contentChanged){if(view==='home')renderHome();if(view==='settings'&&!state.confirm)renderSettings();if(aux)renderAuxiliary();if(['list','editor','guide'].includes(view))renderChannels();}
  if(view==='source'&&contentChanged)$('source-items').replaceChildren(...INPUTS.map((name,i)=>{const n=button(name,'activate-source',i,'tv-row',state.sourceFocus===i);n.append(svg(name==='TV'?'tv':name==='USB'?'usb':'source'),el('span',name));return n;}));
  $('menu-time').textContent=time();const channel=currentChannel(state);$('broadcast-label').textContent=state.source==='TV'?channel.name:state.source;$('broadcast-label').hidden=!awake;
  const recording=$('recording-indicator');if(recording){recording.hidden=!awake||!state.recording?.active;recording.textContent='Kayıt · Örnek';}
  const subtitle=$('broadcast-subtitle');if(subtitle){const enabled=state.values['accessibility-subtitles']||state.values['subtitle-enabled']||state.values['subtitles-enabled'];subtitle.hidden=!awake||!enabled||state.source!=='TV'||view!=='tv';subtitle.textContent='Bu, önizleme için hazırlanmış örnek altyazıdır.';}
  const photo=view==='playback'&&state.playback?.type==='Fotoğraf';
  $('tv-scene').style.opacity=awake&&(state.source==='TV'||photo)?'1':'0';if(photo)$('broadcast-label').textContent='Örnek fotoğraf';
  renderPicture();
  const info=awake&&view==='tv'&&state.source==='TV'&&now<state.infoUntil&&!state.digits;show('channel-info-panel',info);
  if(info){const n=$('channel-info-panel'),top=el('div',undefined,'info-top');top.append(el('h2',`${String(channel.number).padStart(3,'0')}   ${channel.name}`),el('span',time()));const progress=el('div',undefined,'program-progress'),fill=el('span');fill.style.width=`${new Date().getMinutes()/60*100}%`;progress.append(fill);n.replaceChildren(top,el('p',channel.now),progress,el('small',`Sıradaki: ${channel.next}`));if(state.infoExpanded)n.append(el('p',channel.description));}
  if(subtitle)subtitle.style.bottom=info?'280px':'72px';
  renderNumber(now);show('notice',awake&&now<state.noticeUntil);$('notice').textContent=state.notice;
  const route=audioRoute(state),muted=audioMuted(state);stage.dataset.route=route;stage.dataset.muted=String(awake&&muted);stage.dataset.zeroVolume=String(route==='local'&&state.volume===0);stage.dataset.volumeVisible=String(awake&&now<state.volumeUntil);
  $('volume-number').textContent=route==='arc'?(state.lastArc==='volume-up'?'+':state.lastArc==='volume-down'?'−':'—'):String(state.volume);$('volume-route').textContent=route==='arc'?'HDMI ARC':'TV';$('volume-track').style.visibility=route==='arc'?'hidden':'visible';
  $('volume-icon').src=`./native-assets/volume-${muted?'mute':'speaker'}.png`;
  $('volume-panel').setAttribute('aria-label',route==='arc'?`HDMI ARC${muted?' · Sessiz':''}`:`Ses ${state.volume}${muted?' · Sessiz':''}`);
  document.querySelector('[data-action="mute"]').setAttribute('aria-pressed',String(muted));$('key-help').hidden=!awake||view!=='tv'||info||!!state.digits||now<state.volumeUntil;
  for(const key of ['arc','cec','hdmi','handled'])document.querySelector(`[data-action="toggle-${key}"]`)?.setAttribute('aria-pressed',String(state[key]));
  document.querySelector('[data-action="usb-toggle"]')?.setAttribute('aria-pressed',String(state.usb));
  $('status-output').textContent=state.noticeUntil>now?state.notice:state.standby?'Bekleme':view==='settings'?MENUS[state.path.at(-1)]?.title:`${channel.number} ${channel.name}`;
  screen.dataset.view=view;stage.dataset.standby=String(state.standby);lastRender=now;renderedState=state;
}
function dispatch(input){lastInput=performance.now();document.body.classList.remove('is-idle');if(input.type.startsWith('toggle-')){const key=input.type.slice(7);if(['arc','cec','hdmi','handled'].includes(key))input={type:'connection',[key]:!state[key]};}const before=state;state=tvReduce(state,input,MENUS,lastInput);level.retarget(state.volume,lastInput);render(lastInput);if(before.view!==state.view&&!reduced){const panel=state.view==='home'?$('menu'):state.view==='settings'?$('settings-panel'):null;panel?.animate([{opacity:.2,transform:'translateY(18px)'},{opacity:1,transform:'translateY(0)'}],{duration:160,easing:'ease-out'});}}
function toggleRemote(){const controls=$('test-controls'),open=controls.hidden,restoreFocus=!open&&controls.contains(document.activeElement);controls.hidden=!open;$('remote-toggle').setAttribute('aria-expanded',String(open));if(restoreFocus)$('remote-toggle').focus();lastInput=performance.now();document.body.classList.remove('is-idle');}
$('remote-toggle').addEventListener('click',toggleRemote);
document.addEventListener('click',event=>{const b=event.target.closest('button[data-action]');if(!b)return;const keepFocus=event.detail===0&&!!b.closest('#test-controls'),a=b.dataset.action;if(a==='filter'&&Number(b.dataset.index)===state.filter){if(!keepFocus)b.blur();return;}dispatch(/^\d$/.test(a)?{type:'digit',value:a}:{type:a,index:Number(b.dataset.index)});if(!keepFocus)b.blur();});
const keys={ArrowUp:'up',ArrowDown:'down',ArrowLeft:'left',ArrowRight:'right',Enter:'ok',Escape:'back',Backspace:'backspace',m:'menu',M:'menu','+':'volume-up','=':'volume-up','-':'volume-down',AudioVolumeUp:'volume-up',AudioVolumeDown:'volume-down',AudioVolumeMute:'mute',s:'mute',S:'mute',i:'info',I:'info',v:'source',V:'source',PageUp:'channel-up',PageDown:'channel-down',g:'guide',G:'guide',r:'recall',R:'recall',p:'power',P:'power',F2:'favorite',F3:'skip',F4:'lock',u:'usb-toggle',U:'usb-toggle',t:'teletext',T:'teletext',a:'audio',A:'audio',b:'subtitles',B:'subtitles',c:'record',C:'record',' ':'play-pause',x:'stop',X:'stop',j:'rewind',J:'rewind',l:'forward',L:'forward',F5:'red',F6:'green',F7:'yellow',F8:'blue'};
document.addEventListener('keydown',event=>{if(event.ctrlKey||event.metaKey||event.altKey)return;if(event.key==='F1'){event.preventDefault();if(!event.repeat)toggleRemote();return;}if(event.key==='Tab')return;
  // Browser controls keep their native activation; TV shortcuts still work from the screen.
  if((event.key==='Enter'||event.key===' ')&&event.target.closest('#test-controls, #remote-toggle'))return;
  const a=keys[event.key];if(!a&&!/^\d$/.test(event.key))return;event.preventDefault();if(event.repeat&&['menu','ok','mute','info','source','power','back'].includes(a))return;dispatch(a?{type:a}:{type:'digit',value:event.key});});
document.addEventListener('pointermove',()=>{lastInput=performance.now();document.body.classList.remove('is-idle');},{passive:true});
new ResizeObserver(()=>stage.style.setProperty('--scale',stage.clientWidth/1920)).observe(stage);
function frame(now){stage.style.setProperty('--display-volume',level.at(now)/100);if(state.digits)updateNumberCountdown(now);if(now-lastFrame>80){const periodic=(state.playback||state.recording?.active||state.programTimers?.length)&&now-lastModelTick>250;const tick=periodic||state.digitDeadline!==null&&now>=state.digitDeadline||state.view==='scan'||['sleepAt','shutdownAt','startupAt','autoOffAt'].some(k=>state[k]!=null&&now>=state[k]);if(tick){state=tvReduce(state,{type:'tick'},MENUS,now);level.retarget(state.volume,now);lastModelTick=now;}const expired=[state.volumeUntil,state.infoUntil,state.noticeUntil].some(deadline=>deadline>lastRender&&now>=deadline);if(tick||expired||now-lastRender>1000)render(now);document.body.classList.toggle('is-idle',now-lastInput>5000);lastFrame=now;}requestAnimationFrame(frame);}
window.modGrundig=Object.freeze({getState:()=>structuredClone(state),dispatch,metadata:Object.freeze({demo:true,tvVerified:false,menuCount:Object.keys(MENUS).length})});render();if(new URLSearchParams(location.search).get('menu')==='1')dispatch({type:'menu'});requestAnimationFrame(frame);
