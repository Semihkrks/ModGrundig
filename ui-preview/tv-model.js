// TV interaction controller for the offline test environment. No device transport.
import {LICENSE_PAGES} from './license-data.js';
export const HOME=[
  {label:'Ayarlar',icon:'sliders',action:'settings'},
  {label:'Medya Oynatıcı',icon:'media',action:'media'},
  {label:'Kanal Düzenleyici',icon:'edit',action:'editor'},
  {label:'Zamanlayıcı',icon:'timer',action:'timer'},
  {label:'Kanal Listesi',icon:'channels',action:'list'}
];
HOME.splice(2,0,{label:'Kayıt',icon:'timer',action:'recording'});
export const MEDIA_TABS=['Tümü','Film','Müzik','Fotoğraf'];
// Descriptors are intentionally synthetic: no user files, broadcasts or codecs are read.
export const DEMO_MEDIA=[
  {id:'film-1',title:'Doğadan Kareler',type:'Film',duration:180,description:'Örnek video akışı',demo:true},
  {id:'film-2',title:'Şehirden Görüntüler',type:'Film',duration:240,description:'Örnek video akışı',demo:true},
  {id:'music-1',title:'Yumuşak Ritimler',type:'Müzik',duration:210,description:'Örnek müzik akışı',demo:true},
  {id:'music-2',title:'Akşam Melodisi',type:'Müzik',duration:195,description:'Örnek müzik akışı',demo:true},
  {id:'photo-1',title:'Dağ Manzarası',type:'Fotoğraf',duration:0,description:'Örnek fotoğraf',demo:true},
  {id:'photo-2',title:'Deniz Manzarası',type:'Fotoğraf',duration:0,description:'Örnek fotoğraf',demo:true}
];
export function mediaItems(s){return s.usb?DEMO_MEDIA.filter(c=>s.media.tab==='Tümü'||c.type===s.media.tab):[];}
export const CATEGORIES=[
  {menu:'picture',label:'Görüntü Ayarları',icon:'picture'},
  {menu:'sound',label:'Ses Ayarları',icon:'speaker'},
  {menu:'source',label:'Kaynak Ayarları',icon:'hdmi'},
  {menu:'parental',label:'Ebeveyn Ayarları',icon:'lock'},
  {menu:'timer',label:'Zamanlayıcı',icon:'timer'},
  {menu:'tv',label:'TV Ayarları',icon:'sliders'}
];
// Demonstration port list; physical connector availability is unverified.
export const INPUTS=['TV','HDMI 1','HDMI 2','HDMI 3','HDMI 4','Scart','AV','USB'];
const clamp=(n,min,max)=>Math.max(min,Math.min(max,n));
const SETTING_ALIASES={
  'quick-audio-language':'language-audio','quick-audio-type':'sound-type',
  'quick-audio-description':'accessibility-audio-description','quick-subtitle-enabled':'accessibility-subtitles',
  'quick-subtitle-language':'language-subtitle','quick-subtitle-mode':'accessibility-subtitle-mode',
  'antenna-mode':'source-antenna',
  // Host preview policy: both backlight controls drive the same test image.
  'picture-manual-backlight':'picture-backlight'
};
function syncSettingAliases(values,changedId){
  for(const[alias,canonical]of Object.entries(SETTING_ALIASES)){
    if(changedId===alias)values[canonical]=values[alias];
    else if(canonical in values)values[alias]=values[canonical];
  }
}
export function defaults(menus){
  const values=Object.fromEntries(Object.values(menus).flatMap(m=>m.rows).filter(r=>'value'in r).map(r=>[r.id,r.value]));
  syncSettingAliases(values);return values;
}
// Band limits and defaults are host policy; RF hardware is never tuned.
export function rangeBounds(s,row){
  if(row.id==='search-frequency')return s.values['search-source']==='Uydu'?{min:10700,max:12750,step:1}:{min:45,max:900,step:1};
  return {min:row.min??0,max:row.max??100,step:row.step||1};
}
function clockOffset(s){
  const match=/^UTC([+-])(\d{1,2})(?::(\d{2}))?$/.exec(s.values['clock-zone']??'UTC+3');
  const zone=match?(Number(match[2])*60+Number(match[3]??0))*(match[1]==='-'?-1:1):180;
  return (zone+(s.values['clock-daylight']?60:0))*60000;
}
function timerWeekday(s,monotonicTime){return new Date(s.wallClockBase+monotonicTime+clockOffset(s)).getUTCDay();}
export function createTVState(menus,channels,now=0){
  if(!channels.length)throw new Error('TV demo requires explicit demo channel data');
  return {view:'tv',home:0,homeZone:'main',category:0,path:[],row:0,stack:[],values:defaults(menus),
    channels:channels.map(c=>({...c,skip:false,locked:false,favorite:Boolean(c.favorite)})),channelIndex:0,previousIndex:0,
    listFocus:0,filter:0,editorMoving:false,source:'TV',sourceFocus:0,
    volume:32,muted:false,arc:false,cec:true,hdmi:true,handled:true,arcMuted:false,lastArc:null,volumeUntil:0,
    digits:'',digitCount:0,digitDeadline:null,infoUntil:now+5500,infoExpanded:false,
    notice:'',noticeUntil:0,confirm:null,confirmChoice:0,usb:false,mediaFocus:0,
    standby:false,sleepAt:null,shutdownAt:null,startupAt:null,autoOffAt:null,scanStarted:null,scanProgress:0,scanNumber:null,scanReturn:null,
    flow:null,overlayReturn:null,pin:'0000',parentalAccess:{menu:false,source:false,channels:[]},history:[],
    media:{tab:'Tümü',index:0,repeat:false,shuffle:false},playback:null,
    recording:{active:false,startedAt:null,channelNumber:null,items:[],stopAt:null},programTimers:[],nextTimerId:1,
    teletext:{page:'100',digits:'',subpage:1,hold:false},settingsBackup:null,wallClockBase:Date.now()-now,
    initialChannels:channels.map(c=>({...c})),sequence:0,effect:null};
}
// OnKey 0xfb91ac..0xfb91d4 returns from rejected CEC as well: no local fallback.
export function audioRoute(s){return s.arc&&s.cec&&s.hdmi?'arc':'local';}
// Zero volume is silent without creating a latent manual-mute flag.
// Receiver volume is unknown in ARC mode, so local zero must not mute ARC.
export function audioMuted(s){return audioRoute(s)==='arc'?s.arcMuted:s.muted||s.volume===0;}
export function currentChannel(s){return s.channels[s.channelIndex];}
export function filteredChannels(s){return s.channels.map((c,index)=>({...c,index})).filter(c=>(s.filter!==1||c.favorite)&&(s.values['channels-service-type']!=='Radyo'||c.serviceType==='Radyo'));}
function notice(s,text,now){s.notice=text;s.noticeUntil=now+2400;}
function snapshot(s){return {view:s.view,path:[...s.path],row:s.row,stack:[...s.stack],home:s.home,homeZone:s.homeZone,category:s.category,filter:s.filter,listFocus:s.listFocus};}
function restore(s,target){if(target)Object.assign(s,target,{path:[...target.path],stack:[...target.stack]});else s.view='tv';}
function pinFlow(s,pending,purpose='verify'){
  s.flow={kind:'pin',step:purpose==='change-pin'?'current':'verify',purpose,pending,digits:'',error:'',title:purpose==='change-pin'?"PIN'i Değiştir":'PIN Giriş',returnView:s.view,returnState:snapshot(s)};
  s.view='pin';s.digits='';s.digitCount=0;s.digitDeadline=null;
}
function ratingLocked(s,channel){const rating=parseInt(String(s.values['parental-rating']));return rating>0&&Number(channel.ageRating)>rating;}
function tune(s,index,now,authorized=false){
  index=clamp(index,0,s.channels.length-1);
  const channel=s.channels[index];
  if(s.recording.active&&channel.number!==s.recording.channelNumber){notice(s,'Kanal değiştirmek için örnek kaydı durdurunuz.',now);s.digits='';s.digitCount=0;s.digitDeadline=null;return;}
  if(!authorized&&(channel.locked||s.values['parental-channel-lock']||ratingLocked(s,channel))&&!s.parentalAccess.channels.includes(channel.number)){pinFlow(s,{kind:'tune',index});return;}
  if(s.source!=='TV'&&s.values['parental-source-lock']&&!s.parentalAccess.source&&!authorized){pinFlow(s,{kind:'tune',index});return;}
  s.previousIndex=s.channelIndex;s.channelIndex=index;s.view='tv';s.source='TV';s.values['source-input']=s.tunerType??'Dijital';s.infoUntil=now+5500;s.infoExpanded=false;s.digits='';s.digitCount=0;s.digitDeadline=null;
  s.history=[channel.number,...s.history.filter(n=>n!==channel.number)].slice(0,30);s.overlayReturn=null;
  s.playback=null;s.effect={kind:'demo-channel',number:s.channels[index].number,sequence:++s.sequence};
}
function commitDigits(s,now){const index=s.channels.findIndex(c=>c.number===Number(s.digits));if(index>=0)tune(s,index,now);else{notice(s,'Bu numarada kayıtlı kanal yok.',now);s.digits='';s.digitCount=0;s.digitDeadline=null;}}
function openMenu(s,key,menus,push=false,authorized=false){
  if(!menus[key])return;
  if(s.values['parental-menu-lock']&&!s.parentalAccess.menu&&!authorized){pinFlow(s,{kind:'menu',key,push});return;}
  if(push&&s.view==='settings')s.stack.push({key:s.path.at(-1),row:s.row});else s.stack=[];
  s.path=push?[...s.path,key]:[key];s.row=0;s.view='settings';s.infoUntil=0;
}
function valueChange(s,row,delta,now){
  if(/^(sound-volume|main-volume|volume)$/.test(row.id)&&audioRoute(s)==='arc'){
    s.lastArc=delta>0?'volume-up':'volume-down';s.volumeUntil=now+3000;
    s.effect={kind:'demo-cec',command:s.lastArc,accepted:s.handled,sequence:++s.sequence};return;
  }
  if(row.type==='range'){const {min,max,step}=rangeBounds(s,row);s.values[row.id]=clamp(Number(s.values[row.id]??row.value)+delta*step,min,max);}
  else if(row.type==='toggle')s.values[row.id]=!s.values[row.id];
  else if(row.type==='choice'&&row.options?.length){const i=Math.max(0,row.options.indexOf(s.values[row.id]));s.values[row.id]=row.options[(i+delta+row.options.length)%row.options.length];}
  if(/^(sound-volume|main-volume|volume)$/.test(row.id)){s.volume=Number(s.values[row.id]);s.volumeUntil=now+3000;}
  if(row.id==='accessories-cec')s.cec=!!s.values[row.id];
  if(row.id==='sound-arc')s.arc=!!s.values[row.id];
  if(row.id==='sound-output'){s.arc=s.values[row.id]==='HDMI ARC';s.values['sound-arc']=s.arc;}
  if(row.id==='sound-arc')s.values['sound-output']=s.arc?'HDMI ARC':'TV Hoparlörü';
  if(row.id==='media-type'){s.media.tab=s.values[row.id];s.media.index=0;}
  syncSettingAliases(s.values,row.id);
  if(row.id==='search-source'){
    const bounds=rangeBounds(s,{id:'search-frequency'}),frequency=Number(s.values['search-frequency']);
    if(!Number.isFinite(frequency)||frequency<bounds.min||frequency>bounds.max)s.values['search-frequency']=s.values[row.id]==='Uydu'?11054:474;
  }
  if(row.id==='advanced-timeshift'&&!s.usb){s.values[row.id]=false;notice(s,'Sürekli kayıt için USB aygıtı gereklidir.',now);}
  const timerFields={'timer-sleep':'sleepAt','timer-shutdown':'shutdownAt','timer-startup':'startupAt','advanced-auto-off':'autoOffAt'};
  if(timerFields[row.id]){const text=String(s.values[row.id]),minutes=parseInt(text)*(/saat/i.test(text)?60:1);s[timerFields[row.id]]=minutes>0?now+minutes*60000:null;}
}
function selectSource(s,value,now,authorized=false){
  if(s.values['parental-source-lock']&&!s.parentalAccess.source&&!authorized){pinFlow(s,{kind:'source',value});return;}
  if(['Dijital','Uydu','Kablo'].includes(value)){s.tunerType=value;s.source='TV';}else s.source=value;
  s.values['source-input']=value==='TV'?(s.tunerType??'Dijital'):value;s.view=s.source==='USB'?'media':'tv';s.infoUntil=s.source==='TV'?now+5500:0;
}
function startScan(s,now,number=null){s.scanReturn=snapshot(s);s.view='scan';s.scanStarted=now;s.scanProgress=0;s.scanNumber=number;}
function operation(s,title,rows){s.flow={kind:'operation',title,rows,returnState:snapshot(s)};s.view='operation';}
function finishRecording(s,now){
  if(!s.recording.active)return;
  const c=s.channels.find(c=>c.number===s.recording.channelNumber);
  s.recording.items.push({id:`record-${s.recording.startedAt}`,title:c?.now||c?.name||'Örnek kayıt',channelNumber:s.recording.channelNumber,channelName:c?.name||'Demo kanal',duration:Math.max(0,(now-s.recording.startedAt)/1000),demo:true});
  Object.assign(s.recording,{active:false,startedAt:null,channelNumber:null,stopAt:null});
}
function record(s,now){
  if(s.recording.active){finishRecording(s,now);notice(s,'Örnek kayıt durduruldu.',now);return;}
  if(!s.usb){notice(s,'Kayıt için USB aygıtı bağlayınız.',now);return;}
  if(s.source!=='TV'){notice(s,'Kayıt TV kaynağında kullanılabilir.',now);return;}
  const mins=parseInt(s.values['recording-duration'])||30;
  Object.assign(s.recording,{active:true,startedAt:now,channelNumber:currentChannel(s).number,stopAt:now+mins*60000});
  notice(s,'Örnek kayıt başlatıldı.',now);
}
function startPlayback(s,item,kind,now){s.playback={kind,title:item.title,duration:item.duration,position:0,paused:false,rate:1,rotation:0,type:item.type||'Film',id:item.id,updatedAt:now,returnState:snapshot(s),demo:true};s.view='playback';s.infoUntil=0;}
function nextMedia(s,direction,now){
  const list=mediaItems(s);if(!list.length)return;
  const at=Math.max(0,list.findIndex(item=>item.id===s.playback?.id));
  const step=s.media.shuffle&&direction>0&&list.length>1?1+(s.sequence++%(list.length-1)):direction;
  const index=(at+step+list.length)%list.length,back=s.playback?.returnState;
  s.media.index=index;startPlayback(s,list[index],'media',now);if(back)s.playback.returnState=back;
}
function action(s,name,menus,now){
  if(name==='license'){operation(s,'Lisans Anlaşması',[{label:'Kapsam',value:'Paketteki açık font lisansları; ürün sözleşmesinin tamamı değildir'}]);s.flow.license=true;s.flow.page=0;return;}
  if(name==='reset-images'){operation(s,'Seçili İmajları Eski Haline Döndür',[{label:'Özel imajlar',value:'Önizlemeye özel imaj yüklenmedi'},{label:'İşlem',value:'Değiştirilecek imaj bulunmadı'}]);return;}
  if(name==='scan-settings'){operation(s,'Elle Kanal Arama',[{label:'Sinyal Kaynağı',value:s.values['search-source']},{label:'Frekans',value:`${s.values['search-frequency']} MHz`},{label:'Sembol Oranı',value:`${s.values['search-symbol-rate']} kSym/s`},{label:'Polarizasyon',value:s.values['search-polarization']},{label:'Donanım',value:'RF aygıtı bağlı değil; tarama yapılmadı'}]);return;}
  if(name==='scan-channels'){startScan(s,now);return;}
  if(name==='manual-scan'){s.flow={kind:'manual-scan',digits:'',error:'',title:'Elle Kanal Arama',returnView:s.view,returnState:snapshot(s)};s.view='manual-scan';return;}
  if(name==='change-pin'){pinFlow(s,null,'change-pin');return;}
  if(name==='signal-info'){s.flow={kind:'signal',channel:{...currentChannel(s)},strength:null,quality:null,demo:true,title:'Sinyal Bilgileri',returnView:s.view,returnState:snapshot(s)};s.view='signal';return;}
  if(name==='record-toggle'){record(s,now);return;}
  if(name==='timeshift'){if(!s.usb){notice(s,'Zaman kaydırma için USB aygıtı bağlayınız.',now);return;}if(s.source!=='TV'){notice(s,'Zaman kaydırma TV kaynağında kullanılabilir.',now);return;}startPlayback(s,{title:currentChannel(s).name,duration:3600},'timeshift',now);s.playback.paused=true;return;}
  if(name==='media-open'){s.view='media';s.media.index=0;return;}
  if(name==='media-device'){operation(s,'Cihaz Seçimi',[{label:'USB aygıtı',value:s.usb?'Örnek aygıt bağlı':'Aygıt bağlı değil'},{label:'Kaynak',value:'Yalnız örnek dosya kataloğu'}]);return;}
  if(name==='recordings-list'){s.overlayReturn=snapshot(s);s.view='recordings';s.listFocus=0;return;}
  if(name==='timer-add'){
    const number=Number(s.values['program-channel']),channel=s.channels.find(c=>c.number===number);
    if(!channel){notice(s,'Seçilen kanal kayıtlı değil.',now);return;}
    if(s.values['program-mode']==='Kaydet'&&!s.usb){notice(s,'Kayıt zamanlayıcısı için USB aygıtı bağlayınız.',now);return;}
    if(s.programTimers.length>=20){notice(s,'Zamanlayıcı listesi dolu.',now);return;}
    s.programTimers.push({id:s.nextTimerId++,channelNumber:number,channelName:channel.name,kind:s.values['program-mode'],repeat:s.values['program-repeat'],volume:Number(s.values['program-volume']),at:now+(parseInt(s.values['program-delay'])||1)*60000,demo:true});
    notice(s,'Örnek zamanlayıcı eklendi.',now);return;
  }
  if(name==='timer-list'){s.overlayReturn=snapshot(s);s.view='timers';s.listFocus=0;return;}
  if(name==='backup-settings'){
    if(!s.usb){notice(s,'Yedekleme için USB aygıtı bağlayınız.',now);return;}
    s.settingsBackup={values:{...s.values},demo:true};operation(s,'Ayar Yedekleme',[{label:'Önizleme ayarları',value:'Bellek içi kopya saklandı'},{label:'USB / Firmware',value:'Dosya yazılmadı'}]);return;
  }
  if(name==='restore-settings'){
    if(!s.usb){notice(s,'Geri yükleme için USB aygıtı bağlayınız.',now);return;}
    if(!s.settingsBackup){notice(s,'Önizlemede kayıtlı ayar yedeği yok.',now);return;}
    s.confirm={action:'restore-settings',title:'Önizleme Ayarlarını Geri Yükle',returnView:s.view};s.confirmChoice=0;return;
  }
  const details={
    'cec-devices':['DIGI LINK Aygıtları',[['HDMI bağlantısı',s.hdmi?'Örnek bağlantı açık':'Bağlı değil'],['DIGI LINK',s.cec?'Açık':'Kapalı'],['Aygıt taraması','Donanım bağlantısı yok']]],
    'cec-standby':['Aygıtı Beklemeye Al',[['Komut','Donanıma gönderilmedi'],['DIGI LINK',s.cec?'Örnek kumanda etkin':'Kapalı']]],
    'usb-keyboard':['USB Klavye',[['Aygıt','Donanım algılaması yapılmıyor'],['Test girişi','Bilgisayar klavyesi → TV tuşları']]],
    'usb-mouse':['USB Fare',[['Aygıt','Donanım algılaması yapılmıyor'],['Test girişi','İşaretçi → kumanda seçimi']]],
    'software-update':['Yazılım Güncellemeleri',[['Yazılım','GMGRMR V03.017.04'],['USB paketi','Doğrulanmış güncelleme bağlı değil'],['İşlem','Güncelleme veya firmware yazımı yapılmıyor']]],
    oad:['OAD',[['Yayın üzerinden güncelleme','Canlı yayın bağlantısı yok'],['İşlem','Güncelleme başlatılmadı']]],
    tkgs:['Türksat TKGS',[['Servis','Canlı uydu bağlantısı yok'],['Kanal verisi','Yerel örnek kanal listesi']]],
    'ca-module':['CA-Modülü',[['Ortak arabirim','CA modülü bağlı değil'],['Abonelik','Bilgi okunmadı']]],
    'diseqc-info':['DiSEqC 1.2 Ayarları',[['Motor / anten','Donanım bağlantısı yok'],['İşlem','Motor komutu gönderilmez']]],
    license:['Lisans Anlaşması',[['Firmware kaynağı','Genel ayarlar / Lisans Anlaşması'],['Metin','Lisans metninin tamamı bu önizlemeye aktarılmadı']]],
    'clock-info':['Tarih & Saat',[['Saat kaynağı',s.values['clock-mode']||'Otomatik'],['Saat dilimi',s.values['clock-zone']||'UTC+3'],['Donanım saati','Okunmadı; test saati bilgisayara aittir']]]
  };
  if(details[name]){const[title,rows]=details[name];operation(s,title,rows.map(([label,value])=>({label,value})));return;}
  if(name==='source'||name==='select-source'){s.view='source';s.sourceFocus=Math.max(0,INPUTS.indexOf(s.source));return;}
  if(['channel-list','open-channels','open-favorites'].includes(name)){s.overlayReturn=snapshot(s);s.view='list';s.filter=name==='open-favorites'?1:0;s.listFocus=Math.max(0,filteredChannels(s).findIndex(c=>c.index===s.channelIndex));return;}
  if(name==='channel-editor'){s.view='editor';s.listFocus=s.channelIndex;return;}
  if(name?.startsWith('reset')||name==='clear-history'){s.confirm={action:name,title:name==='reset-all'?'Fabrika Ayarlarına Dönüş':name==='clear-history'?'Kanal Geçmişini Temizle':'Ayarları Sıfırla',returnView:s.view};s.confirmChoice=0;return;}
  if(name==='standby'){s.standby=true;return;}
  if(name==='usb-toggle'){s.usb=!s.usb;return;}
  notice(s,'Bu işlem için simülasyon bulunamadı.',now);
}
function pendingPinAction(s,pending,menus,now){
  if(!pending)return;
  if(pending.kind==='tune'){s.parentalAccess.channels.push(s.channels[pending.index].number);s.parentalAccess.source=true;tune(s,pending.index,now,true);}
  else if(pending.kind==='menu'){s.parentalAccess.menu=true;openMenu(s,pending.key,menus,pending.push,true);}
  else if(pending.kind==='source'){s.parentalAccess.source=true;selectSource(s,pending.value,now,true);}
  else if(pending.kind==='unlock-channel')s.channels[pending.index].locked=false;
}
export function tvReduce(previous,input,menus,now=0){
  const s={...previous,values:{...previous.values},channels:previous.channels.map(c=>({...c})),path:[...previous.path],stack:[...previous.stack],history:[...previous.history],parentalAccess:{...previous.parentalAccess,channels:[...previous.parentalAccess.channels]},flow:previous.flow?{...previous.flow}:null,media:{...previous.media},playback:previous.playback?{...previous.playback}:null,recording:{...previous.recording,items:[...previous.recording.items]},programTimers:previous.programTimers.map(t=>({...t})),teletext:{...previous.teletext},effect:null};
  const type=input.type;
  if(type==='tick'){
    if(s.recording.active&&now>=s.recording.stopAt)finishRecording(s,s.recording.stopAt);
    if(s.playback){const p=s.playback;if(!p.paused&&p.duration>0)p.position=clamp(p.position+Math.max(0,now-p.updatedAt)/1000*p.rate,0,p.duration);p.updatedAt=now;
      if(p.position>=p.duration&&p.duration>0){if(s.media.repeat)p.position=0;else if(p.kind==='media'&&s.media.shuffle)nextMedia(s,1,now);else p.paused=true;}}
    for(const timer of [...s.programTimers])if(now>=timer.at){
      if(timer.kind==='Kaydet'){
        if(s.usb&&!s.recording.active){s.recording={...s.recording,active:true,startedAt:timer.at,channelNumber:timer.channelNumber,stopAt:timer.at+(parseInt(s.values['recording-duration'])||30)*60000};notice(s,'Örnek zamanlanmış kayıt başladı.',now);}
        else notice(s,s.usb?'Başka bir kayıt sürüyor.':'Zamanlanmış kayıt: USB aygıtı bağlı değil.',now);
      }else{notice(s,`${timer.channelName} için program hatırlatıcısı.`,now);}
      if(timer.repeat==='Bir kez')s.programTimers=s.programTimers.filter(t=>t.id!==timer.id);
      else{const days=timer.repeat==='Pazar'?[0]:timer.repeat==='Pzt–Cum'?[1,2,3,4,5]:timer.repeat==='Pzt–Cmt'?[1,2,3,4,5,6]:timer.repeat==='Cmt–Pzr'?[0,6]:[0,1,2,3,4,5,6];
        do{timer.at+=86400000;}while(timer.at<=now||!days.includes(timerWeekday(s,timer.at)));}
    }
    const timers=[['sleepAt','timer-sleep'],['shutdownAt','timer-shutdown'],['autoOffAt','advanced-auto-off'],['startupAt','timer-startup']]
      .filter(([key])=>s[key]!==null&&now>=s[key]).sort((a,b)=>s[a[0]]-s[b[0]]);
    for(const[key,id]of timers){s[key]=null;s.values[id]='Kapalı';s.standby=key!=='startupAt';s.flow=null;s.confirm=null;s.digits='';s.digitCount=0;s.digitDeadline=null;
      s.parentalAccess={menu:false,source:false,channels:[]};s.view='tv';s.overlayReturn=null;
      if(s.standby){s.playback=null;if(!s.values['recording-standby'])finishRecording(s,now);}
      if(!s.standby){s.volume=clamp(Number(s.values['timer-start-volume'])||0,0,100);s.values['sound-volume']=s.volume;s.infoUntil=now+5500;}}
    if(!s.standby&&s.digitDeadline!==null&&now>=s.digitDeadline)commitDigits(s,now);
    if(!s.standby&&s.view==='scan'){s.scanProgress=Math.min(100,Math.max(0,Math.floor((now-s.scanStarted)/40)));if(s.scanProgress===100){
      if(s.scanNumber!==null&&!s.channels.some(c=>c.number===s.scanNumber)){s.channels.push({number:s.scanNumber,name:`Demo ${s.scanNumber}`,genre:'Demo',now:'Örnek yayın',next:'Örnek program',description:'Elle arama için yerel olarak üretilmiş demo kanal.',favorite:false,locked:false,skip:false,demo:true});}
      s.view='list';s.filter=0;s.listFocus=s.scanNumber===null?0:s.channels.findIndex(c=>c.number===s.scanNumber);s.overlayReturn=s.scanReturn;s.scanReturn=null;notice(s,`${s.scanNumber===null?s.channels.length:1} demo kanal bulundu.`,now);}}
    return s;
  }
  if(type==='power'){s.standby=!s.standby;s.flow=null;s.confirm=null;s.parentalAccess={menu:false,source:false,channels:[]};s.digits='';s.digitCount=0;s.digitDeadline=null;if(s.standby){s.playback=null;if(!s.values['recording-standby'])finishRecording(s,now);}else{s.view='tv';s.infoUntil=now+5500;}return s;}
  if(s.standby)return s;
  if(s.flow){
    const flow=s.flow;
    if(type==='back'){restore(s,flow.returnState);s.flow=null;return s;}
    if(flow.kind==='operation'){if(flow.license&&(type==='up'||type==='down'))flow.page=clamp(flow.page+(type==='down'?1:-1),0,LICENSE_PAGES.length-1);if(type==='ok'){restore(s,flow.returnState);s.flow=null;}return s;}
    if(flow.kind==='signal'){if(type==='ok'){restore(s,flow.returnState);s.flow=null;}return s;}
    if(type==='digit'&&/^\d$/.test(String(input.value))){if(flow.digits.length<4)flow.digits+=String(input.value);flow.error='';return s;}
    if(type==='backspace'||type==='left'){flow.digits=flow.digits.slice(0,-1);flow.error='';return s;}
    if(type!=='ok')return s;
    if(flow.kind==='manual-scan'){
      const number=Number(flow.digits);if(!Number.isInteger(number)||number<1||number>9999){flow.error='1–9999 arasında kanal numarası giriniz.';return s;}
      restore(s,flow.returnState);s.flow=null;startScan(s,now,number);return s;
    }
    if(flow.digits.length!==4){flow.error='Dört haneli PIN giriniz.';return s;}
    if(flow.step==='verify'||flow.step==='current'){
      if(flow.digits!==s.pin){flow.error='Yanlış PIN';flow.digits='';return s;}
      if(flow.step==='current'){flow.step='new';flow.title='Yeni PIN';flow.digits='';flow.error='';return s;}
      restore(s,flow.returnState);s.flow=null;pendingPinAction(s,flow.pending,menus,now);return s;
    }
    if(flow.step==='new'){flow.newPin=flow.digits;flow.step='confirm';flow.title="Yeni PIN'i Tekrar Giriniz";flow.digits='';flow.error='';return s;}
    if(flow.digits!==flow.newPin){flow.error='PIN eşleşmiyor';flow.digits='';return s;}
    s.pin=flow.newPin;restore(s,flow.returnState);s.flow=null;notice(s,'Demo PIN değiştirildi.',now);return s;
  }
  if(type==='action'){action(s,input.name,menus,now);return s;}
  if(type==='record'){record(s,now);return s;}
  if(type==='audio'){s.overlayReturn=snapshot(s);openMenu(s,'quickAudio',menus);return s;}
  if(type==='subtitle'||type==='subtitles'){s.overlayReturn=snapshot(s);openMenu(s,'subtitles',menus);return s;}
  if(type==='teletext'){if(s.source!=='TV'){notice(s,'Teletext TV kaynağında kullanılabilir.',now);return s;}if(s.view==='teletext'){restore(s,s.overlayReturn);s.overlayReturn=null;}else{s.overlayReturn=snapshot(s);s.view='teletext';}return s;}
  if(type==='media-tab'){s.media.tab=MEDIA_TABS[clamp(Number(input.index)||0,0,MEDIA_TABS.length-1)];s.values['media-type']=s.media.tab;s.media.index=0;return s;}
  if(type==='play'||type==='pause'||type==='play-pause'){
    if(s.playback){s.playback.updatedAt=now;s.playback.paused=type==='play'?false:type==='pause'?true:!s.playback.paused;s.playback.rate=1;return s;}
    if(s.view==='media'){const item=mediaItems(s)[s.media.index];if(item)startPlayback(s,item,'media',now);else notice(s,'USB aygıtı veya oynatılacak örnek dosya yok.',now);return s;}
    action(s,'timeshift',menus,now);return s;
  }
  if(type==='stop'){if(s.playback){restore(s,s.playback.returnState);s.playback=null;}else if(s.recording.active){finishRecording(s,now);notice(s,'Örnek kayıt durduruldu.',now);}return s;}
  if((type==='rewind'||type==='forward')&&s.playback){s.playback.position=clamp(s.playback.position+(type==='forward'?15:-15),0,s.playback.duration);s.playback.updatedAt=now;return s;}
  if((type==='next'||type==='previous')&&s.playback?.kind==='media'){nextMedia(s,type==='next'?1:-1,now);return s;}
  if(type==='set-volume'){if(audioRoute(s)==='local'){s.volume=clamp(Math.round(Number(input.value)||0),0,100);s.values['sound-volume']=s.volume;s.volumeUntil=now+3000;}return s;}
  if(type==='connection'){for(const k of['arc','cec','hdmi','handled'])if(k in input)s[k]=!!input[k];s.values['accessories-cec']=s.cec;s.values['sound-arc']=s.arc;s.values['sound-output']=s.arc?'HDMI ARC':'TV Hoparlörü';s.volumeUntil=now+3000;return s;}
  if(['volume-up','volume-down','mute'].includes(type)){
    s.volumeUntil=now+3000;
    if(audioRoute(s)==='arc'){s.lastArc=type;if(type==='mute'&&s.handled)s.arcMuted=!s.arcMuted;s.effect={kind:'demo-cec',command:type,accepted:s.handled,sequence:++s.sequence};}
    else{if(type==='mute'){if(s.volume>0)s.muted=!s.muted;}else s.volume=clamp(s.volume+(type==='volume-up'?1:-1),0,100);s.effect={kind:'demo-audio',command:type,sequence:++s.sequence};
      for(const row of Object.values(menus).flatMap(m=>m.rows))if(row.type==='range'&&/^(main-volume|sound-volume|volume)$/.test(row.id))s.values[row.id]=s.volume;}
    return s;
  }
  if(type==='menu'){s.view=s.view==='home'?'tv':'home';s.homeZone='main';s.confirm=null;s.overlayReturn=null;s.parentalAccess.menu=false;s.infoUntil=0;s.digits='';s.digitDeadline=null;s.digitCount=0;return s;}
  if(s.confirm){
    if(type==='confirm-choice'){
      const choice=Number(input.index);if(choice!==0&&choice!==1)return s;
      s.confirmChoice=choice;return tvReduce(s,{type:'ok'},menus,now);
    }
    if(type==='back')s.confirm=null;
    else if(type==='left'||type==='right')s.confirmChoice=1-s.confirmChoice;
    else if(type==='ok'){
      if(s.confirmChoice===1){const name=s.confirm.action;const fresh=defaults(menus);for(const[key,value]of Object.entries(fresh)){if(name==='reset-all'||(name.includes('picture')&&key.startsWith('picture-'))||(name.includes('sound')&&(key.startsWith('sound-')||key.startsWith('equalizer-'))))s.values[key]=value;}
        if(name==='reset-all'||name==='reset-sound'){s.volume=Number(s.values['sound-volume']??32);s.muted=false;s.arcMuted=false;}
        if(name==='reset-all'){s.source='TV';s.sleepAt=null;s.shutdownAt=null;s.startupAt=null;s.autoOffAt=null;s.pin='0000';s.parentalAccess={menu:false,source:false,channels:[]};s.channels=s.initialChannels.map(c=>({...c,favorite:!!c.favorite,skip:false,locked:false}));s.channelIndex=0;s.previousIndex=0;s.history=[];s.view='tv';s.path=[];s.stack=[];s.overlayReturn=null;s.programTimers=[];s.playback=null;finishRecording(s,now);}
        if(name==='restore-settings'&&s.settingsBackup){s.values={...s.settingsBackup.values};s.volume=Number(s.values['sound-volume']);s.cec=!!s.values['accessories-cec'];s.arc=!!s.values['sound-arc'];s.sleepAt=null;s.shutdownAt=null;s.startupAt=null;s.autoOffAt=null;}
        if(name==='reset-all'||name==='reset-sound'){s.arc=!!s.values['sound-arc'];s.cec=!!s.values['accessories-cec'];}
        syncSettingAliases(s.values);
        if(name==='clear-history'){s.history=[];s.previousIndex=s.channelIndex;}
        notice(s,name==='clear-history'?'Kanal geçmişi temizlendi.':'Demo ayarları sıfırlandı.',now);}
      s.confirm=null;
    }
    return s;
  }
  if(type==='source'){if(s.view==='source'){restore(s,s.overlayReturn);s.overlayReturn=null;}else{s.overlayReturn=snapshot(s);s.view='source';}s.sourceFocus=Math.max(0,INPUTS.indexOf(s.source));s.infoUntil=0;return s;}
  if(type==='info'&&s.source==='TV'){s.infoUntil=now+8000;s.infoExpanded=!s.infoExpanded;return s;}
  if(type==='guide'){s.view=s.view==='guide'?'tv':'guide';s.listFocus=s.channelIndex;s.filter=0;return s;}
  if(type==='usb-toggle'){s.usb=!s.usb;if(!s.usb){finishRecording(s,now);s.values['advanced-timeshift']=false;if(s.playback){restore(s,s.playback.returnState);s.playback=null;}}notice(s,s.usb?'Örnek USB aygıtı bağlandı.':'Örnek USB aygıtı çıkarıldı.',now);return s;}
  if(s.view==='teletext'){
    if(type==='back'){restore(s,s.overlayReturn);s.overlayReturn=null;return s;}
    if(type==='digit'&&/^\d$/.test(String(input.value))){s.teletext.digits+=String(input.value);if(s.teletext.digits.length===3){const n=Number(s.teletext.digits);if(n>=100&&n<=899)s.teletext.page=s.teletext.digits;else notice(s,'Teletext sayfası 100–899 arasında olmalıdır.',now);s.teletext.digits='';}return s;}
    if(type==='up'||type==='down')s.teletext.page=String(clamp(Number(s.teletext.page)+(type==='up'?1:-1),100,899));
    if(type==='left'||type==='right')s.teletext.subpage=clamp(s.teletext.subpage+(type==='right'?1:-1),1,99);
    if(type==='ok')s.teletext.hold=!s.teletext.hold;
    if(['red','green','yellow','blue'].includes(type))s.teletext.page=String(100*(1+['red','green','yellow','blue'].indexOf(type)));
    return s;
  }
  if(type==='digit'&&/^\d$/.test(String(input.value))){
    if(s.source!=='TV'){notice(s,'Kanal seçimi TV kaynağında kullanılabilir.',now);return s;}
    s.view='tv';s.infoUntil=0;s.digitCount++;
    if(s.digitCount<=4){s.digits+=String(input.value);s.digitDeadline=now+(s.digitCount===4?2000:3000);}return s;
  }
  if(type==='backspace'){
    s.digits=s.digits.slice(0,-1);s.digitCount=s.digits.length;
    s.digitDeadline=s.digitCount?now+(s.digitCount===4?2000:3000):null;return s;
  }
  if(['channel-up','channel-down','recall'].includes(type)){
    if(s.source!=='TV'){notice(s,'Kanal seçimi TV kaynağında kullanılabilir.',now);return s;}
    const available=s.channels.map((c,i)=>({c,i})).filter(x=>!x.c.skip);
    if(!available.length){notice(s,'İzlenebilir kanal yok.',now);return s;}
    if(type==='recall'){tune(s,s.previousIndex,now);return s;}
    const at=available.findIndex(x=>x.i===s.channelIndex),delta=type==='channel-up'?1:-1;
    tune(s,available[(at+delta+available.length)%available.length].i,now);return s;
  }
  if(type==='back'){
    if(s.digits){s.digits='';s.digitCount=0;s.digitDeadline=null;}
    else if(s.playback){restore(s,s.playback.returnState);s.playback=null;}
    else if(s.view==='scan'){restore(s,s.scanReturn);s.scanReturn=null;s.scanStarted=null;s.scanProgress=0;}
    else if(s.overlayReturn){restore(s,s.overlayReturn);s.overlayReturn=null;s.editorMoving=false;}
    else if(s.view==='settings'){
      if(s.stack.length){const back=s.stack.pop();s.path.pop();s.path[s.path.length-1]=back.key;s.row=back.row;}
      else{s.view='home';s.home=0;s.homeZone='secondary';s.parentalAccess.menu=false;}
    }else if(s.view==='home'&&s.homeZone==='secondary')s.homeZone='main';
    else{s.view='tv';s.infoUntil=0;s.infoExpanded=false;s.editorMoving=false;}
    return s;
  }
  if(s.view==='tv'){
    if(type==='ok'){if(s.digits){if(s.digitCount<5)commitDigits(s,now);}else if(s.source==='TV'){s.view='list';s.filter=0;s.listFocus=s.channelIndex;}else notice(s,'Kanal listesi TV kaynağında açılır.',now);}
    else if(type==='up'||type==='down')return tvReduce(s,{type:type==='up'?'channel-up':'channel-down'},menus,now);
  }else if(s.view==='home'){
    if(type==='up')s.homeZone='main';
    if(type==='down'&&s.home===0)s.homeZone='secondary';
    if(type==='left'||type==='right'){const delta=type==='right'?1:-1;if(s.homeZone==='secondary')s.category=clamp(s.category+delta,0,CATEGORIES.length-1);else s.home=clamp(s.home+delta,0,HOME.length-1);}
    if(type==='activate-home'){s.home=input.index;s.homeZone='main';return tvReduce(s,{type:'ok'},menus,now);}
    if(type==='activate-category'){s.category=input.index;s.homeZone='secondary';return tvReduce(s,{type:'ok'},menus,now);}
    if(type==='ok'){
      if(s.homeZone==='secondary')openMenu(s,CATEGORIES[s.category].menu,menus);
      else{const name=HOME[s.home].action;if(name==='settings')s.homeZone='secondary';else if(name==='timer'||name==='recording')openMenu(s,name,menus);else{s.view=name;s.listFocus=s.channelIndex;s.filter=0;}}
    }
  }else if(s.view==='settings'){
    const menu=menus[s.path.at(-1)];if(!menu)return s;
    if(type==='up'||type==='down')s.row=clamp(s.row+(type==='down'?1:-1),0,menu.rows.length-1);
    if(type==='activate-row'){s.row=clamp(input.index,0,menu.rows.length-1);return tvReduce(s,{type:'ok'},menus,now);}
    const row=menu.rows[s.row];
    if((type==='left'||type==='right')&&row){if(row.id==='source-input'){const i=row.options.indexOf(s.values[row.id]),delta=type==='right'?1:-1;selectSource(s,row.options[(Math.max(0,i)+delta+row.options.length)%row.options.length],now);}else valueChange(s,row,type==='right'?1:-1,now);}
    if(type==='ok'&&row){if(row.type==='submenu')openMenu(s,row.menu,menus,true);else if(row.type==='action')action(s,row.action,menus,now);else if(row.type==='info')notice(s,String(row.valueText??row.value??'GMGRMR V03.017.04'),now);else if(row.id==='source-input'){const i=row.options.indexOf(s.values[row.id]);selectSource(s,row.options[(Math.max(0,i)+1)%row.options.length],now);}else valueChange(s,row,1,now);}
  }else if(['list','editor','guide'].includes(s.view)){
    let channels=filteredChannels(s);s.listFocus=clamp(s.listFocus,0,Math.max(0,channels.length-1));
    if(type==='left'||type==='right'||type==='filter'){
      const direct=type==='filter'&&input.index!==undefined;
      const next=direct?input.index:1-s.filter;
      if(next===0||next===1){if(next!==s.filter){s.filter=next;s.listFocus=0;s.editorMoving=false;}channels=filteredChannels(s);}
    }
    const change=type==='down'?1:type==='up'?-1:type==='page-down'?8:type==='page-up'?-8:0;
    if(change){const next=clamp(s.listFocus+change,0,Math.max(0,channels.length-1));
      if(s.view==='editor'&&s.editorMoving&&channels[next]){const a=channels[s.listFocus].index,b=channels[next].index;
        const currentNumber=s.channels[s.channelIndex].number,previousNumber=s.channels[s.previousIndex].number;
        [s.channels[a],s.channels[b]]=[s.channels[b],s.channels[a]];
        s.channelIndex=s.channels.findIndex(c=>c.number===currentNumber);s.previousIndex=s.channels.findIndex(c=>c.number===previousNumber);}
      s.listFocus=next;}
    if(type==='activate-channel'){s.listFocus=clamp(input.index,0,Math.max(0,channels.length-1));return tvReduce(s,{type:'ok'},menus,now);}
    const selected=filteredChannels(s)[s.listFocus];
    if(type==='favorite'&&selected)s.channels[selected.index].favorite=!selected.favorite;
    if(type==='skip'&&selected&&s.view==='editor')s.channels[selected.index].skip=!selected.skip;
    if(type==='lock'&&selected&&s.view==='editor'){if(selected.locked)pinFlow(s,{kind:'unlock-channel',index:selected.index});else s.channels[selected.index].locked=true;}
    if(type==='ok'&&selected){if(s.view==='editor')s.editorMoving=!s.editorMoving;else tune(s,selected.index,now);}
  }else if(s.view==='source'){
    if(type==='left'||type==='right')s.sourceFocus=clamp(s.sourceFocus+(type==='right'?1:-1),0,INPUTS.length-1);
    if(type==='up'||type==='down'){const next=s.sourceFocus+(type==='down'?4:-4);if(next>=0&&next<INPUTS.length)s.sourceFocus=next;}
    if(type==='activate-source'){s.sourceFocus=clamp(Number(input.index)||0,0,INPUTS.length-1);return tvReduce(s,{type:'ok'},menus,now);}
    if(type==='ok')selectSource(s,INPUTS[s.sourceFocus],now);
  }else if(s.view==='media'){
    if(type==='left'||type==='right'){const i=MEDIA_TABS.indexOf(s.media.tab);s.media.tab=MEDIA_TABS[(i+(type==='right'?1:-1)+MEDIA_TABS.length)%MEDIA_TABS.length];s.media.index=0;}
    const list=mediaItems(s);
    if(type==='up'||type==='down')s.media.index=clamp(s.media.index+(type==='down'?1:-1),0,Math.max(0,list.length-1));
    if(type==='activate-media'){s.media.index=clamp(Number(input.index)||0,0,Math.max(0,list.length-1));return tvReduce(s,{type:'ok'},menus,now);}
    if(type==='ok'){const item=list[s.media.index];if(item)startPlayback(s,item,'media',now);else notice(s,'USB aygıtı bağlı değil. F1 kumandasından örnek aygıt bağlayınız.',now);}
    if(type==='red'){s.media.repeat=!s.media.repeat;notice(s,s.media.repeat?'Tekrar açık':'Tekrar kapalı',now);}
    if(type==='green'){s.media.shuffle=!s.media.shuffle;notice(s,s.media.shuffle?'Karışık çalma açık':'Karışık çalma kapalı',now);}
    if(type==='yellow'){s.overlayReturn=snapshot(s);openMenu(s,'mediaSettings',menus);}
  }else if(s.view==='playback'&&s.playback){
    if(type==='ok')s.playback.paused=!s.playback.paused;
    if(type==='left'||type==='right'){if(s.playback.type==='Fotoğraf')s.playback.rotation=(s.playback.rotation+(type==='right'?90:270))%360;else s.playback.position=clamp(s.playback.position+(type==='right'?15:-15),0,s.playback.duration);s.playback.updatedAt=now;}
    if(type==='red')s.media.repeat=!s.media.repeat;
    if(type==='green')s.media.shuffle=!s.media.shuffle;
    if((type==='blue'||type==='yellow')&&s.playback.kind==='media')nextMedia(s,type==='blue'?1:-1,now);
  }else if(s.view==='recordings'||s.view==='timers'){
    const list=s.view==='recordings'?s.recording.items:s.programTimers;
    if(type==='up'||type==='down')s.listFocus=clamp(s.listFocus+(type==='down'?1:-1),0,Math.max(0,list.length-1));
    if(type==='activate-item'){s.listFocus=clamp(Number(input.index)||0,0,Math.max(0,list.length-1));return tvReduce(s,{type:'ok'},menus,now);}
    if(type==='ok'&&list[s.listFocus]){if(s.view==='recordings'){if(!s.usb){notice(s,'Kaydı oynatmak için USB aygıtı bağlayınız.',now);return s;}startPlayback(s,list[s.listFocus],'recording',now);}else operation(s,'Zamanlayıcı Ayrıntıları',Object.entries({Kanal:list[s.listFocus].channelName,Mod:list[s.listFocus].kind,Tekrar:list[s.listFocus].repeat}).map(([label,value])=>({label,value})));}
    if(type==='red'&&list[s.listFocus]){list.splice(s.listFocus,1);s.listFocus=clamp(s.listFocus,0,Math.max(0,list.length-1));notice(s,'Örnek liste girdisi silindi.',now);}
  }
  return s;
}
