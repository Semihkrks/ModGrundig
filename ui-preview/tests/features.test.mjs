import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {MENUS} from '../firmware-menu-data.js';
import {CONDITIONAL_FEATURES} from '../extra-menu-data.js';
import {createTVState,tvReduce,mediaItems,MEDIA_TABS,audioRoute,rangeBounds} from '../tv-model.js';
const channels=[{number:1,name:'Bir',favorite:true,now:'Örnek program'},{number:2,name:'İki'}];
const fresh=()=>createTVState(MENUS,channels);
const act=(s,type,now=0,extra={})=>tvReduce(s,{type,...extra},MENUS,now);
const command=(s,name,now=0)=>act(s,'action',now,{name});
function setting(s,menu,id,direction='right',now=0){const row=MENUS[menu].rows.findIndex(r=>r.id===id);assert(row>=0);return act({...s,view:'settings',path:[menu],stack:[],row},direction,now);}
const usb=s=>act(s,'usb-toggle');

test('returning from HDMI to TV retains the selected tuner in the source settings',()=>{
  let s=setting(fresh(),'source','source-input');assert.equal(s.tunerType,'Uydu');
  s=act({...s,view:'source'},'activate-source',0,{index:1});assert.equal(s.source,'HDMI 1');
  s=act({...s,view:'source'},'activate-source',0,{index:0});assert.equal(s.source,'TV');assert.equal(s.values['source-input'],'Uydu');
  s=act(s,'channel-up');assert.equal(s.values['source-input'],'Uydu');
});

test('extended catalogue retains evidence, unique IDs and valid submenu destinations',()=>{
  const ids=new Set();
  for(const menu of Object.values(MENUS))for(const row of menu.rows){
    assert(!ids.has(row.id),`Duplicate ${row.id}`);ids.add(row.id);
    assert(row.evidence.sourceFile);assert(fs.existsSync(new URL('../../'+row.evidence.sourceFile,import.meta.url)));
    assert(row.evidence.sourceAddress);assert(row.evidence.stringId!==undefined);
    assert.equal(row.evidence.deviceAvailabilityVerified,false);
    if(row.type==='submenu')assert(MENUS[row.menu],row.menu);
  }
  assert(ids.size>=150);assert.equal(MENUS.timer.rows.find(r=>r.id==='timer-sleep').options[1],'10 dk.');
  for(const conditional of CONDITIONAL_FEATURES){assert.equal(conditional.defaultVisible,false);assert(!ids.has(conditional.id));}
  assert(!Object.values(MENUS).some(m=>/Wi-Fi|Tarayıcı|Web|Bluetooth/.test(m.title)));
});

test('all menu families are reachable from the home categories or real feature shortcuts',()=>{
  const seen=new Set(['picture','sound','source','parental','timer','tv','mediaSettings','quickAudio','subtitles']);
  for(let size=-1;size!==seen.size;){size=seen.size;for(const k of [...seen])for(const row of MENUS[k].rows)if(row.menu)seen.add(row.menu);}
  assert.deepEqual([...seen].sort(),Object.keys(MENUS).sort());
});

test('DIGI LINK and ARC settings control routing and preserve local volume',()=>{
  let s=setting(fresh(),'sound','sound-arc');assert.equal(audioRoute(s),'arc');assert.equal(s.volume,32);
  s=setting(s,'accessories','accessories-cec');assert.equal(s.cec,false);assert.equal(audioRoute(s),'local');
  s=setting(s,'accessories','accessories-cec');assert.equal(audioRoute(s),'arc');
  s=setting(s,'sound','sound-output');assert.equal(audioRoute(s),'local');assert.equal(s.values['sound-arc'],false);
  s=command(s,'cec-devices');assert.equal(s.flow.kind,'operation');assert.match(s.flow.rows.at(-1).value,/Donanım/);
  s=act(s,'ok');assert.equal(s.view,'settings');assert.equal(s.flow,null);
});

test('media device, type filtering, playback clock, transport and back are coherent',()=>{
  let s=command(fresh(),'media-open');assert.deepEqual(mediaItems(s),[]);
  s=act(s,'ok');assert.match(s.notice,/USB/);
  s=usb(s);assert.equal(mediaItems(s).length,6);
  s=act(s,'media-tab',0,{index:MEDIA_TABS.indexOf('Müzik')});assert.equal(mediaItems(s).length,2);
  s=act(s,'activate-media',100,{index:1});assert.equal(s.view,'playback');assert.equal(s.playback.type,'Müzik');
  s=act(s,'tick',10100);assert.equal(s.playback.position,10);
  s=act(s,'play-pause',10100);assert.equal(s.playback.paused,true);
  s=act(s,'tick',20100);assert.equal(s.playback.position,10);
  s=act(s,'forward',20100);assert.equal(s.playback.position,25);
  s=act(s,'rewind',20100);assert.equal(s.playback.position,10);
  s=act(s,'play',20100);s=act(s,'tick',21100);assert.equal(s.playback.position,11);
  s=act(s,'stop',21100);assert.equal(s.view,'media');assert.equal(s.playback,null);
  s=act(s,'yellow');assert.equal(s.path.at(-1),'mediaSettings');s=act(s,'back');assert.equal(s.view,'media');
});

test('photo rotation, next, repeat and shuffle alter playback without decoding any media',()=>{
  let s=usb(command(fresh(),'media-open'));s=act(s,'media-tab',0,{index:3});s=act(s,'ok');
  assert.equal(s.playback.type,'Fotoğraf');s=act(s,'right');assert.equal(s.playback.rotation,90);
  const first=s.playback.id;s=act(s,'next');assert.notEqual(s.playback.id,first);s=act(s,'previous');assert.equal(s.playback.id,first);
  s=act(s,'stop');s=act(s,'media-tab',0,{index:1});s=act(s,'ok',100);
  s=act(s,'red');s=act(s,'tick',181000);assert.equal(s.playback.position,0);assert.equal(s.playback.paused,false);
  s=act(s,'red');s=act(s,'green');const id=s.playback.id;s=act(s,'tick',362000);assert.notEqual(s.playback.id,id);assert.equal(s.playback.position,0);
});

test('recording requires USB and TV, captures metadata only and blocks unsupported channel changes',()=>{
  let s=act(fresh(),'record');assert.equal(s.recording.active,false);assert.match(s.notice,/USB/);
  s=usb(s);s=act(s,'record',100);assert.equal(s.recording.active,true);
  const original=s;s=act(s,'channel-up',200);assert.equal(s.channelIndex,0);assert.match(s.notice,/kaydı durdurunuz/);
  s=act(s,'record',10100);assert.equal(s.recording.active,false);assert.equal(s.recording.items.length,1);assert.equal(s.recording.items[0].duration,10);assert.equal(original.recording.items.length,0);
  s=command(s,'recordings-list');s=act(s,'ok',11000);assert.equal(s.playback.kind,'recording');
  s=act(s,'stop');assert.equal(s.view,'recordings');s=act(s,'red');assert.equal(s.recording.items.length,0);
});

test('timeshift requires USB and transport ends safely on USB removal',()=>{
  let s=command(fresh(),'timeshift');assert.equal(s.playback,null);
  s=usb(s);s=command(s,'timeshift',500);assert.equal(s.playback.kind,'timeshift');assert.equal(s.playback.paused,true);
  s=act(s,'play',500);s=act(s,'tick',10500);assert.equal(s.playback.position,10);
  s=act(s,'usb-toggle',11000);assert.equal(s.playback,null);assert.equal(s.view,'tv');assert.equal(s.values['advanced-timeshift'],false);
});

test('recording deadlines and standby policy finish host recordings with correct duration',()=>{
  let s=usb(fresh());s=act(s,'record',100);s=act(s,'tick',1800100);assert.equal(s.recording.active,false);assert.equal(s.recording.items[0].duration,1800);
  s=act(s,'record',1800200);s=act(s,'power',1801200);assert.equal(s.recording.active,false);assert.equal(s.recording.items[1].duration,1);
  s=act(s,'power');s=setting(s,'recording','recording-standby');s=act(s,'record',2000000);s=act(s,'power',2001000);assert.equal(s.recording.active,true);
});

test('program alarms validate channels, require USB for recording and can be inspected or removed',()=>{
  let s=fresh();s.values['program-channel']=99;s=command(s,'timer-add');assert.equal(s.programTimers.length,0);assert.match(s.notice,/kayıtlı değil/);
  s.values['program-channel']=2;s=command(s,'timer-add',100);assert.equal(s.programTimers[0].at,60100);
  s=act(s,'tick',60100);assert.equal(s.programTimers.length,0);assert.match(s.notice,/İki.*hatırlatıcısı/);
  s.values['program-mode']='Kaydet';s=command(s,'timer-add');assert.equal(s.programTimers.length,0);
  s=usb(s);s=command(s,'timer-add',1000);s=act(s,'tick',61000);assert.equal(s.recording.active,true);assert.equal(s.recording.channelNumber,2);
  s=act(s,'record',62000);s.values['program-mode']='Hatırlatıcı';s=command(s,'timer-add',63000);s=command(s,'timer-list');s=act(s,'ok');assert.equal(s.flow.kind,'operation');s=act(s,'back');assert.equal(s.view,'timers');s=act(s,'red');assert.equal(s.programTimers.length,0);
});

test('backup/restore is in-memory only, requires the demo USB and honors cancellation',()=>{
  let s=command(fresh(),'backup-settings');assert.equal(s.settingsBackup,null);
  s=usb(s);s.values['picture-brightness']=21;s=command(s,'backup-settings');assert.equal(s.settingsBackup.values['picture-brightness'],21);assert.equal(s.flow.kind,'operation');s=act(s,'ok');
  s.values['picture-brightness']=80;s=command(s,'restore-settings');s=act(s,'ok');assert.equal(s.values['picture-brightness'],80);
  s=command(s,'restore-settings');s=act(s,'confirm-choice',0,{index:1});assert.equal(s.values['picture-brightness'],21);
});

test('teletext numeric/color-key navigation stays separate from TV channel entry',()=>{
  let s=act(fresh(),'teletext');assert.equal(s.view,'teletext');
  for(const value of '345')s=act(s,'digit',0,{value});
  assert.equal(s.teletext.page,'345');assert.equal(s.digits,'');assert.equal(s.digitDeadline,null);
  s=act(s,'red');assert.equal(s.teletext.page,'100');s=act(s,'blue');assert.equal(s.teletext.page,'400');
  s=act(s,'right');assert.equal(s.teletext.subpage,2);s=act(s,'ok');assert.equal(s.teletext.hold,true);s=act(s,'back');assert.equal(s.view,'tv');
});

test('quick audio/subtitle adjustments synchronize their original settings and return to TV',()=>{
  let s=act(fresh(),'audio');assert.equal(s.path.at(-1),'quickAudio');s=setting(s,'quickAudio','quick-audio-language');assert.equal(s.values['language-audio'],'English');s=act(s,'back');assert.equal(s.view,'tv');
  s=act(s,'subtitles');assert.equal(s.path.at(-1),'subtitles');s=setting(s,'subtitles','quick-subtitle-enabled');assert.equal(s.values['accessibility-subtitles'],true);s=act(s,'back');assert.equal(s.view,'tv');
});

test('manual RF settings report absent hardware and never invent scan results',()=>{
  let s=fresh();const count=s.channels.length;s.values['search-frequency']=578;s=command(s,'scan-settings');assert.equal(s.view,'operation');assert.match(s.flow.rows.at(-1).value,/tarama yapılmadı/);assert.equal(s.channels.length,count);
  s=act(s,'back');s=command(s,'signal-info');assert.equal(s.flow.strength,null);assert.equal(s.flow.quality,null);
});

test('repeating program timers use a real calendar and the simulated clock zone/daylight',()=>{
  const now=10000,epoch=Date.UTC(2026,9,23,23,58); // Friday 23:58 UTC, Saturday in UTC+3.
  const day=86400000;
  for(const[zone,daylight,repeat,expectedDays]of[
    ['UTC+0',false,'Pzt–Cum',3],['UTC+3',false,'Pzt–Cum',2],
    ['UTC+0',true,'Pzt–Cum',2],['UTC+0',false,'Pazar',2],['UTC+3',false,'Pazar',1]
  ]){
    let s=createTVState(MENUS,channels,now);
    assert(Math.abs((s.wallClockBase+now)-Date.now())<1000);
    s.wallClockBase=epoch-now;
    s.values['clock-zone']=zone;s.values['clock-daylight']=daylight;s.values['program-repeat']=repeat;
    s=command(s,'timer-add',now);const due=s.programTimers[0].at,before=s;
    s=act(s,'tick',due);
    assert.equal(s.programTimers[0].at,due+expectedDays*day,`${zone}, daylight=${daylight}, ${repeat}`);
    assert.equal(before.programTimers[0].at,due);
    assert.equal(s.programTimers.length,1);
  }
});

test('RF manual search changes frequency bounds with the selected band and clamps at each limit',()=>{
  const frequency=MENUS.manualSearch.rows.find(r=>r.id==='search-frequency');
  let s=fresh();assert.deepEqual(rangeBounds(s,frequency),{min:45,max:900,step:1});
  s=setting(s,'manualSearch','search-source');assert.equal(s.values['search-source'],'Kablo');assert.equal(s.values['search-frequency'],474);
  s=setting(s,'manualSearch','search-source');assert.equal(s.values['search-source'],'Uydu');assert.equal(s.values['search-frequency'],11054);
  assert.deepEqual(rangeBounds(s,frequency),{min:10700,max:12750,step:1});
  s.values['search-frequency']=12750;s=setting(s,'manualSearch','search-frequency');assert.equal(s.values['search-frequency'],12750);
  s.values['search-frequency']=10700;s=setting(s,'manualSearch','search-frequency','left');assert.equal(s.values['search-frequency'],10700);
  s=setting(s,'manualSearch','search-source','left');assert.equal(s.values['search-source'],'Kablo');assert.equal(s.values['search-frequency'],474);
  s.values['search-frequency']=900;s=setting(s,'manualSearch','search-frequency');assert.equal(s.values['search-frequency'],900);
  s.values['search-frequency']=45;s=setting(s,'manualSearch','search-frequency','left');assert.equal(s.values['search-frequency'],45);
  assert.equal(s.channels.length,channels.length);
});

test('both picture backlight controls stay effective through backup, restore and reset',()=>{
  let s=setting(fresh(),'picture','picture-backlight');
  assert.equal(s.values['picture-backlight'],71);
  assert.equal(s.values['picture-manual-backlight'],71);
  s=setting(s,'pictureAdvanced','picture-manual-backlight','left');
  assert.equal(s.values['picture-backlight'],70);
  assert.equal(s.values['picture-manual-backlight'],70);
  s=usb(s);s=command(s,'backup-settings');s=act(s,'ok');
  s=setting(s,'picture','picture-backlight');
  s=command(s,'restore-settings');s=act(s,'confirm-choice',0,{index:1});
  assert.equal(s.values['picture-backlight'],70);
  assert.equal(s.values['picture-manual-backlight'],70);
  s=setting(s,'pictureAdvanced','picture-manual-backlight');
  s=command(s,'reset-all');s=act(s,'confirm-choice',0,{index:1});
  assert.equal(s.values['picture-backlight'],70);
  assert.equal(s.values['picture-manual-backlight'],70);
});

test('base/quick settings and antenna aliases stay synchronized after changes, restore and resets',()=>{
  let s=fresh();
  s=setting(s,'source','source-antenna');assert.equal(s.values['source-antenna'],s.values['antenna-mode']);
  s=setting(s,'antenna','antenna-mode');assert.equal(s.values['source-antenna'],s.values['antenna-mode']);
  s=setting(s,'quickAudio','quick-audio-type');assert.equal(s.values['quick-audio-type'],s.values['sound-type']);
  s=setting(s,'language','language-audio');assert.equal(s.values['quick-audio-language'],s.values['language-audio']);
  s=setting(s,'subtitles','quick-subtitle-enabled');assert.equal(s.values['quick-subtitle-enabled'],s.values['accessibility-subtitles']);
  s=usb(s);s=command(s,'backup-settings');s=act(s,'ok');
  const saved={...s.values};
  s=setting(s,'accessibility','accessibility-subtitles');s=setting(s,'source','source-antenna');s=setting(s,'quickAudio','quick-audio-language');
  s=command(s,'restore-settings');s=act(s,'confirm-choice',0,{index:1});
  assert.deepEqual(s.values,saved);
  s=setting(s,'quickAudio','quick-audio-type');s=command(s,'reset-sound');s=act(s,'confirm-choice',0,{index:1});
  assert.equal(s.values['quick-audio-type'],s.values['sound-type']);assert.equal(s.values['sound-type'],'Stereo');
  s=command(s,'reset-all');s=act(s,'confirm-choice',0,{index:1});
  for(const[alias,canonical]of[
    ['antenna-mode','source-antenna'],['quick-audio-language','language-audio'],['quick-audio-type','sound-type'],
    ['quick-audio-description','accessibility-audio-description'],['quick-subtitle-enabled','accessibility-subtitles'],
    ['quick-subtitle-language','language-subtitle'],['quick-subtitle-mode','accessibility-subtitle-mode']
  ])assert.equal(s.values[alias],s.values[canonical],`${alias} / ${canonical}`);
});
