// Rendering only. All actions go through the TV model, never a device transport.
import {LICENSE_PAGES} from './license-data.js';
export function renderFeature(state,ui){
  const {$,el,row,button,svg,hints,mediaItems,mediaTabs}=ui;
  const rows=$('settings-rows');
  const header=title=>{$('settings-title').textContent=title;$('settings-breadcrumb').textContent='TV';rows.replaceChildren();};
  const summary=text=>rows.append(el('p',text,'feature-summary'));
  const duration=value=>{const seconds=Math.max(0,Math.floor(Number(value)||0));return `${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`;};
  if(state.view!=='playback')delete rows.dataset.playbackKey;
  if(state.view==='operation'){
    header(state.flow?.title??'Bilgi');
    if(state.flow?.license){const page=LICENSE_PAGES[state.flow.page??0];summary('Paketteki açık font lisansları');const text=el('pre',page.text,'license-text');rows.append(text);hints('settings-footer',[['▲ ▼',`${(state.flow.page??0)+1} / ${LICENSE_PAGES.length}`],['OK','Tamam'],['↶','Geri']]);return true;}
    for(const item of state.flow?.rows??[])rows.append(row(item.label,item.value));
    hints('settings-footer',[['OK','Tamam'],['↶','Geri']]);return true;
  }
  if(state.view==='media'){
    header('Medya Oynatıcı');
    const tabs=el('div',undefined,'feature-tabs');
    (mediaTabs??['Tümü','Video','Müzik','Fotoğraf']).forEach((label,i)=>{const b=button(label,'media-tab',i,'',state.media?.tab===label);b.textContent=label;tabs.append(b);});rows.append(tabs);
    if(!state.usb){summary('USB aygıtı bağlı değil.');hints('settings-footer',[['↶','Geri']]);return true;}
    summary('Örnek USB içerikleri');
    const items=mediaItems(state),index=state.media?.index??0,start=Math.max(0,index-3);
    items.slice(start,start+5).forEach((item,i)=>{const name=item.title??item.name??'Örnek içerik';const n=row(name,item.type??item.kind,index===start+i,'activate-media',start+i);n.prepend(svg(item.type==='Fotoğraf'?'picture':'media'));rows.append(n);});
    if(!items.length)summary('Bu kategoride içerik yok.');
    hints('settings-footer',[['◀ ▶','Kategori'],['OK','Aç'],['Sarı','Ayarlar'],['Kırmızı','Tekrar'],['Yeşil','Karışık'],['↶','Geri']]);return true;
  }
  if(state.view==='playback'){
    const p=state.playback??{},key=JSON.stringify([p.kind,p.title,p.paused,p.rate,p.rotation]);
    const update=()=>{const bar=$('playback-progress');if(bar)bar.firstElementChild.style.width=`${p.duration?Math.max(0,Math.min(100,p.position/p.duration*100)):0}%`;const counter=$('playback-time');if(counter)counter.textContent=`${duration(p.position)} / ${duration(p.duration)}`;};
    if(rows.dataset.playbackKey===key&&$('playback-progress')){update();return true;}
    header(p.kind==='timeshift'?'Zaman Kaydırma':p.kind==='recording'?'Kayıt Oynatma':'Medya Oynatıcı');rows.dataset.playbackKey=key;
    const top=el('div',undefined,'feature-preview');top.append(svg(p.kind==='timeshift'?'timer':'media'),el('strong',p.title??'Örnek yayın'),el('small',`${p.paused?'Duraklatıldı':'Oynatılıyor'}${p.rate&&p.rate!==1?` · ${p.rate}×`:''} · Demo`));rows.append(top);
    const progress=el('div',undefined,'feature-progress');progress.id='playback-progress';const fill=el('span');progress.append(fill);const counter=el('p',undefined,'feature-summary');counter.id='playback-time';rows.append(progress,counter);update();
    const photo=p.type==='Fotoğraf';const actions=el('div',undefined,'feature-actions');for(const [type,label]of [[photo?'left':'rewind',photo?'Sola çevir':'Geri sar'],['play-pause',p.paused?'Oynat':'Duraklat'],[photo?'right':'forward',photo?'Sağa çevir':'İleri sar'],['stop','Durdur']]){const b=button(label,type,undefined,'',type==='play-pause');b.textContent=label;actions.append(b);}rows.append(actions);
    hints('settings-footer',[['◀ ▶','Sar'],['OK / ▶Ⅱ','Oynat / Duraklat'],['■','Durdur'],['↶','Geri']]);return true;
  }
  if(state.view==='teletext'){
    const t=state.teletext??{};header('Teletekst');
    summary(`P${t.digits||t.page||'100'} · Alt sayfa ${t.subpage??1}${t.hold?' · Bekletiliyor':''}`);
    const preview=el('div',undefined,'feature-preview');preview.append(el('strong','Örnek teletekst'),el('small','Canlı teletekst verisi bağlı değil.'));rows.append(preview);
    const actions=el('div',undefined,'feature-actions');for(const [type,label]of [['red','100 · Ana Sayfa'],['green','200 · Haber'],['yellow','300 · Spor'],['blue','400 · Program']]){const b=button(label,type,undefined,'');b.textContent=label;actions.append(b);}rows.append(actions);
    hints('settings-footer',[['0–9','Sayfa'],['▲ ▼','Önceki / Sonraki'],['OK','Beklet'],['↶','Geri']]);return true;
  }
  if(state.view==='recordings'||state.view==='timers'){
    const recordings=state.view==='recordings',items=recordings?state.recording.items:state.programTimers,index=state.listFocus??0,start=Math.max(0,index-3);
    header(recordings?'Kayıt Listesi':'Zamanlayıcı Listesi');
    summary(recordings?'Örnek kayıtlar · Görüntü/ses dosyası yazılmaz.':'Program hatırlatıcıları ve kayıt zamanlayıcıları');
    if(!items.length)summary(recordings?'Henüz kayıt yok.':'Zamanlayıcı eklenmedi.');
    items.slice(start,start+6).forEach((item,i)=>rows.append(row(recordings?item.title:item.channelName,recordings?duration(item.duration):`${item.kind} · ${item.repeat}`,index===start+i,'activate-item',start+i)));
    hints('settings-footer',[['▲ ▼','Seç'],['OK',recordings?'Oynat':'Ayrıntılar'],['Kırmızı','Sil'],['↶','Geri']]);return true;
  }
  return false;
}
