// Retained firmware UI catalogue, extended by host-only interaction policy.
// Presence in a firmware string/widget path does not prove device availability.
const FILE='analiz/ui-kod-cagrilari.json';
const GENERAL='analiz/native/ui-four/general/widget-resource-groups.json';
const functions={picture:['PictureSettingsFrame','0xe28b14'],sound:['SoundSettingsFrame','0xee9afc'],source:['SourceSetupFrame','0xf0dd24'],general:['GeneralSettingsFrame','0xd01710'],quick:['QuickSettingsFrame','0xea4118']};
Object.assign(functions,{cec:['CecSettingsFrame','0x885268'],antenna:['AntennaSetupFrame','0x7604f0'],timer:['TimerSettingsFrame','0xf404b8'],pvr:['PVRFrame','0xe703cc'],media:['DMPFileSelectorFrame','0x8fcac8']});
function evidence(group,stringId,site,extra={}){const [sourceFunction,sourceAddress]=functions[group];return {sourceFile:group==='general'?GENERAL:FILE,sourceFunction,sourceAddress,stringId,stringCallsite:site,labelBasis:'retained_static_string_call',defaults:'demo',rangeAndOptionGrouping:'simulator_policy',interaction:'offline_simulator',deviceAvailabilityVerified:false,...extra};}
function item(id,label,type,value,group,sid,site,extra={}){return {id,label,type,value,evidence:evidence(group,sid,site),...extra};}
const choice=(id,label,value,options,g,sid,site)=>item(id,label,'choice',value,g,sid,site,{options});
const toggle=(id,label,value,g,sid,site)=>item(id,label,'toggle',value,g,sid,site);
const action=(id,label,name,g,sid,site)=>item(id,label,'action',null,g,sid,site,{action:name});
const link=(id,label,key,g,sid,site)=>item(id,label,'submenu',null,g,sid,site,{menu:key});
const range=(id,label,value,min,max,g,sid,site)=>item(id,label,'range',value,g,sid,site,{min,max,step:1});
export const CONDITIONAL_FEATURES=[];
export function extendMenus(m){
  m.picture.rows.push(link('picture-advanced','Gelişmiş','pictureAdvanced','picture',0x80,'0xe2e3a0'));
  m.pictureAdvanced={title:'Gelişmiş Görüntü Ayarları',source:{file:FILE,function:'PictureSettingsFrame',address:'0xe28b14'},rows:[
    range('picture-manual-backlight','Manuel Ekran Işığı',70,0,100,'picture',0xc44,'0xe2d3f4'),
    toggle('picture-ambient-light','Ortam Işığı',false,'picture',0xc13,'0xe2dcd8'),
    range('picture-hue','Ton',0,-50,50,'picture',0xda7,'0xe31168'),
    choice('picture-vivid-color','Canlı Renk','Kapalı',['Kapalı','Düşük','Orta','Yüksek'],'picture',0x1041,'0xe32330'),
    choice('picture-gamma','Gama','2.2',['1.8','2.0','2.2','2.4'],'picture',0x39,'0xe32c14'),
    choice('picture-local-dimming','Local Dimming','Kapalı',['Kapalı','Düşük','Orta','Yüksek'],'picture',0x9e2,'0xe33848'),
    choice('picture-perfect-clear','Mükemmel Netlik','Kapalı',['Kapalı','Düşük','Orta','Yüksek'],'picture',0xe9d,'0xe34a10'),
    toggle('picture-micro-dimming','Microdimming',false,'picture',0x1150,'0xe352f4'),
    toggle('picture-film-mode','Film Modu',false,'picture',0xd58,'0xe35bd8'),
    choice('picture-memc','MEMC','Kapalı',['Kapalı','Düşük','Orta','Yüksek'],'picture',0x3f,'0xe364bc'),
    choice('picture-digital-noise','Dijital Gürültü Azaltımı','Kapalı',['Kapalı','Düşük','Orta','Yüksek'],'picture',0x27,'0xe382a8')
  ]};
  m.sound.rows.push(
    choice('sound-tv-location','TV Konumu','Masa Üstü',['Masa Üstü','Duvar'],'sound',0xfdc,'0xeee944'),
    choice('sound-type','Ses Tipi','Stereo',['Mono','Stereo','Dual I','Dual II'],'sound',0xf9f,'0xeef278'),
    range('sound-delay','Ses Gecikmesi',0,0,250,'sound',0xc07,'0xef0c28'),
    toggle('sound-arc','ARC',false,'sound',0x8a3,'0xef2ad4'),
    choice('sound-output','Ses Çıkışı','TV Hoparlörü',['TV Hoparlörü','HDMI ARC'],'sound',0xc2e,'0xef3408'),
    choice('sound-scart-output','Scart Çıkışı','TV',['TV','AV'],'sound',0xf12,'0xef3d3c'),
    range('sound-scart-volume','Scart Ses Seviyesi',50,0,100,'sound',0xf13,'0xef466c')
  );
  m.tv.rows.splice(2,0,link('tv-accessories','Aksesuarlar','accessories','general',0x1071,'0xd07e54'));
  m.accessories={title:'Aksesuarlar',source:{file:GENERAL,function:'GeneralSettingsFrame',address:'0xd01710'},rows:[
    toggle('accessories-cec','DIGI LINK',true,'quick',0x24,'0xea89e0'),
    action('accessories-device-list','DIGI LINK Aygıtları','cec-devices','quick',0x24,'0xea89e0'),
    action('accessories-keyboard','USB Klavye','usb-keyboard','general',0x1012,'0xd16070'),
    action('accessories-mouse','USB Fare','usb-mouse','general',0x1013,'0xd16500')
  ]};
  m.advanced.rows.push(toggle('advanced-shop-logo','Mağaza Logosu Görünümü',false,'general',0x11b7,'0xd17d4c'),toggle('advanced-timeshift','Sürekli Kayıt',false,'general',0x1183,'0xd1978c'));
  m.about.rows.push(
    action('about-updates','Yazılım Güncellemeleri','software-update','general',0xef0,'0xd1c814'),
    action('about-reset-images','Seçili İmajları Eski Haline Döndür','reset-images','general',0x10e9,'0xd1dcb4'),
    link('about-recovery','Ayar Yedekleme','recovery','general',0x11b4,'0xd1e394'),
    choice('about-country','Ülke','Türkiye',['Türkiye','Almanya','İngiltere'],'general',0xca1,'0xd1ecd4'),
    action('about-license','Lisans Anlaşması','license','general',0x114a,'0xd1f358')
  );
  m.recovery={title:'Ayar Yedekleme',source:{file:GENERAL,function:'GeneralSettingsFrame',address:'0xd01710'},rows:[
    action('recovery-save','Ayarları Yedekle','backup-settings','general',0x11b4,'0xd1e394'),
    action('recovery-restore','Ayarları Geri Yükle','restore-settings','general',0x11b4,'0xd1e394')
  ]};
  // The following labels are simulator subdivisions of a proven family, not recovered widget labels.
  for(const r of m.recovery.rows)r.evidence.labelBasis='simulator_subdivision_of_retained_family';
  m.source.rows.push(
    link('source-antenna-settings','Anten Ayarları','antenna','source',0xbca,'0xf14e14'),
    action('source-ca','CA-Modülü','ca-module','source',0xbcd,'0xf15730'),
    toggle('source-auto-update','Oto Servis Güncelleme',false,'source',0xbcc,'0xf168d4'),
    action('source-oad','OAD','oad','source',0xa45,'0xf171b8'),
    toggle('source-active-antenna','Aktif Anten',false,'source',0xbc9,'0xf18198'),
    toggle('source-digital-teletext','Dijital Teletext',true,'source',0xcdc,'0xf19318'),
    action('source-tkgs','Türksat TKGS','tkgs','source',0xfcd,'0xf12640')
  );
  m.antenna={title:'Anten Ayarları',source:{file:FILE,function:'SourceSetupFrame',address:'0xf0dd24'},rows:[
    choice('antenna-mode','Anten / Kablo / Uydu','Anten',['Anten','Kablo','Uydu'],'source',0xbca,'0xf14e14'),
    action('antenna-search','Otomatik Kanal Arama','scan-channels','source',0xc3d,'0xf11180'),
    link('antenna-manual','Elle Kanal Arama','manualSearch','source',0xbca,'0xf14e14'),
    action('antenna-signal','Sinyal Bilgileri','signal-info','source',0xf84,'0xf14734')
  ]};
  m.antenna.rows[0].evidence.labelBasis='simulator_subdivision_of_retained_family';
  m.antenna.rows[2].evidence.labelBasis='simulator_subdivision_of_retained_family';
  m.accessories.rows.push(link('accessories-digilink','DIGI LINK Ayarları','digilink','quick',0x24,'0xea89e0'));
  m.digilink={title:'DIGI LINK Ayarları',source:{file:FILE,function:'CecSettingsFrame',address:'0x885268'},rows:[
    action('digilink-device','Aygıt','cec-devices','cec',0x22,'0x886644'),
    choice('digilink-control','Kumanda Davranışı','TV',['TV','Aygıt'],'cec',0x7a,'0x886ee0'),
    action('digilink-standby','Aygıtı Beklemeye Al','cec-standby','cec',0x77,'0x887540')
  ]};
  m.antenna.rows.push(
    choice('antenna-satellite','Uydu','Türksat',['Türksat','Astra','Hotbird'],'antenna',0xf07,'0x7632ac'),
    choice('antenna-lnb-type','LNB Tipi','Universal',['Universal','Tekli','Unicable'],'antenna',0xdc7,'0x764200'),
    toggle('antenna-lnb-power','LNB Gücü',true,'antenna',0xdc5,'0x764ae4'),
    choice('antenna-lnb-selection','LNB Seçimi','LNB 1',['LNB 1','LNB 2','LNB 3','LNB 4'],'antenna',0xdc6,'0x7653c8'),
    range('antenna-user-band','Kullanıcı Bandı',1,1,8,'antenna',0x101c,'0x765ccc'),
    choice('antenna-diseqc','DISEqC Modu','Kapalı',['Kapalı','1.0','1.1','1.2'],'antenna',0xcab,'0x766c20'),
    action('antenna-diseqc12','DiSEqC 1.2 Ayarları','diseqc-info','antenna',0xeb5,'0x7672a4'),
    choice('antenna-lnb-frequency','LNB Frekansı','9750 / 10600',['9750 / 10600','9750','10600'],'antenna',0xdc4,'0x76fd34')
  );
  m.timer.rows.push(link('timer-recorder','Kaydedici','recording','timer',0xed7,'0xf45fd0'),link('timer-alarm','Alarm','programTimer','timer',0xc0c,'0xf466f4'),link('timer-clock','Tarih & Saat','clock','timer',0xcc0,'0xf47168'));
  m.clock={title:'Tarih & Saat',source:{file:FILE,function:'TimerSettingsFrame',address:'0xf404b8'},rows:[
    choice('clock-mode','Zaman Ayarı','Otomatik',['Otomatik','Manuel'],'timer',0xfe3,'0xf47aec'),
    choice('clock-zone','Saat Dilimi','UTC+3',['UTC+0','UTC+1','UTC+2','UTC+3'],'timer',0xc7d,'0xf48414'),
    toggle('clock-daylight','Günışığı Tasarrufu',false,'timer',0xcc3,'0xf48d1c'),
    action('clock-current','Tarih Saat','clock-info','timer',0xcc1,'0xf493e4')
  ]};
  m.programTimer={title:'Alarm',source:{file:FILE,function:'TimerSettingsFrame',address:'0xf404b8'},rows:[
    choice('program-mode','Mod','Hatırlatıcı',['Hatırlatıcı','Kaydet'],'timer',0xdf8,'0xf49ad4'),
    choice('program-source','Sinyal Kaynağı','Dijital',['Dijital','Uydu','Kablo'],'timer',0xdb0,'0xf4a3b8'),
    choice('program-service','Servis Tipi','TV',['TV','Radyo'],'timer',0xf3f,'0xf4ac9c'),
    range('program-channel','Kanal',1,1,9999,'timer',0xc6f,'0xf4b580'),
    range('program-volume','Ses Ayarı',20,0,100,'timer',0x104e,'0xf4be54'),
    choice('program-repeat','Tekrar','Bir kez',['Bir kez','Her gün','Pzt–Cum','Pzt–Cmt','Cmt–Pzr','Pazar'],'timer',0xfe9,'0xf4fb98'),
    choice('program-delay','Başlangıç','1 dk.',['1 dk.','5 dk.','15 dk.','30 dk.','60 dk.'],'timer',0xc0c,'0xf466f4'),
    action('program-add','Alarmı Ekle','timer-add','timer',0xc0c,'0xf466f4'),
    action('program-list','Zamanlayıcı Listesi','timer-list','timer',0xc0c,'0xf466f4')
  ]};
  for(const id of ['program-delay','program-add','program-list'])m.programTimer.rows.find(r=>r.id===id).evidence.labelBasis='simulator_subdivision_of_retained_family';
  m.recording={title:'Kayıt',source:{file:FILE,function:'PVRFrame',address:'0xe703cc'},rows:[
    action('recording-start','Kayıt','record-toggle','pvr',0xed8,'0xe83424'),
    choice('recording-duration','Kayıt Süresi','30 dk.',['15 dk.','30 dk.','60 dk.','120 dk.'],'pvr',0xed3,'0xe8a220'),
    toggle('recording-standby','Beklemede Kayda Devam',false,'pvr',0xe68,'0xe89cf0'),
    toggle('recording-last-memory','Son Hafıza',true,'pvr',0xdcb,'0xe838e0'),
    action('recording-list','Kayıt Listesi','recordings-list','media',0x1195,'0x918064'),
    action('recording-timeshift','Sürekli Kayıt','timeshift','general',0x1183,'0xd1978c')
  ]};
  m.mediaSettings={title:'Medya Oynatıcı',source:{file:FILE,function:'DMPFileSelectorFrame',address:'0x8fcac8'},rows:[
    action('media-open','Medya Oynatıcı','media-open','media',0xdec,'0x91357c'),
    action('media-device','Cihaz Seçimi','media-device','media',0xcd6,'0x9197cc'),
    choice('media-type','Tip','Tümü',['Tümü','Film','Müzik','Fotoğraf'],'media',0x1000,'0x919f68')
  ]};
  // Package-wide image processing flags have not been proven for this television.
  const conditionalIds=new Set(['picture-local-dimming','picture-perfect-clear','picture-micro-dimming','picture-memc']);
  for(const r of m.pictureAdvanced.rows)if(conditionalIds.has(r.id))CONDITIONAL_FEATURES.push({...r,defaultVisible:false});
  m.pictureAdvanced.rows=m.pictureAdvanced.rows.filter(r=>!conditionalIds.has(r.id));
  m.quickAudio={title:'Ses Dili',source:{...m.language.source},rows:[
    {...m.language.rows.find(r=>r.id==='language-audio'),id:'quick-audio-language'},
    {...m.sound.rows.find(r=>r.id==='sound-type'),id:'quick-audio-type'},
    {...m.accessibility.rows.find(r=>r.id==='accessibility-audio-description'),id:'quick-audio-description'}
  ].filter(r=>r.label)};
  m.subtitles={title:'Altyazı',source:{...m.accessibility.source},rows:[
    {...m.accessibility.rows.find(r=>r.id==='accessibility-subtitles'),id:'quick-subtitle-enabled'},
    {...m.language.rows.find(r=>r.id==='language-subtitle'),id:'quick-subtitle-language'},
    {...m.accessibility.rows.find(r=>r.id==='accessibility-subtitle-mode'),id:'quick-subtitle-mode'}
  ].filter(r=>r.label)};
  m.manualSearch={title:'Elle Kanal Arama',source:{file:FILE,function:'AntennaSetupFrame / SourceSetupFrame',address:'0x7604f0 / 0xf0dd24'},rows:[
    choice('search-source','Sinyal Kaynağı','Dijital',['Dijital','Kablo','Uydu'],'timer',0xdb0,'0xf4a3b8'),
    range('search-frequency','Frekans (MHz)',474,45,900,'source',0xbca,'0xf14e14'),
    range('search-symbol-rate','Sembol Oranı (kSym/s)',6875,1000,45000,'source',0xbca,'0xf14e14'),
    choice('search-polarization','Polarizasyon','Yatay',['Yatay','Dikey'],'source',0xbca,'0xf14e14'),
    action('search-start','Aramayı Başlat','scan-settings','source',0xbca,'0xf14e14')
  ]};
  for(const r of m.manualSearch.rows)r.evidence.labelBasis='simulator_subdivision_of_retained_family';
  const manual=m.source.rows.find(r=>r.id==='source-manual-search');
  if(manual){manual.type='submenu';manual.menu='manualSearch';delete manual.action;}
  // Quick-settings source records enumerate these options explicitly; timing effects remain host policy.
  const sleep=m.timer.rows.find(r=>r.id==='timer-sleep');
  sleep.options=['Kapalı','10 dk.','20 dk.','30 dk.','60 dk.','90 dk.','120 dk.','180 dk.','240 dk.'];
  sleep.evidence.optionSource={file:'analiz/native/ui-targeted/dvbt_board/00ea4118.c',function:'QuickSettingsFrame',address:'0xea4118',callsites:'0xea9388..0xea9468'};
  const format=m.picture.rows.find(r=>r.id==='picture-format');
  if(format)format.options=['Otomatik','16:9','14:9','4:3','Letterbox','Altyazı','Panorama','Tam Ekran'];
  // These user-facing row names adapt retained options/empty states/families;
  // their resource IDs are evidence anchors, not literal recovered row labels.
  for(const [menu,id,basis,retainedText] of [
    ['programTimer','program-repeat','host_label_adaptation_of_option','Bir kez'],
    ['recording','recording-list','host_label_adaptation_of_empty_state','Kayıt Listesi Boş'],
    ['accessories','accessories-device-list','simulator_subdivision_of_retained_family','Digilink'],
    ['accessories','accessories-digilink','simulator_subdivision_of_retained_family','Digilink'],
  ]){
    const row=m[menu]?.rows.find(r=>r.id===id);
    if(row){row.evidence.labelBasis=basis;row.evidence.retainedText=retainedText;}
  }
  return m;
}
