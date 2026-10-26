import test from 'node:test';
import assert from 'node:assert/strict';
import {createTVState,tvReduce,filteredChannels,currentChannel,INPUTS,audioMuted} from '../tv-model.js';
import {MENUS} from '../firmware-menu-data.js';

const channels=[
  {number:1,name:'Bir',favorite:true},
  {number:2,name:'İki',favorite:false},
  {number:3,name:'Üç',favorite:true},
];
const create=()=>createTVState(MENUS,channels);
const act=(s,type,now=0,extra={})=>tvReduce(s,{type,...extra},MENUS,now);
const command=(s,name,now=0)=>act(s,'action',now,{name});

test('direct channel tabs select idempotently while directional filters toggle',()=>{
  let s={...create(),view:'list',filter:0,listFocus:1};
  s=act(s,'filter',0,{index:0});assert.equal(s.filter,0);assert.equal(s.listFocus,1);
  s=act(s,'filter',0,{index:1});assert.equal(s.filter,1);assert.equal(s.listFocus,0);
  s={...s,listFocus:1};s=act(s,'filter',0,{index:1});assert.equal(s.filter,1);assert.equal(s.listFocus,1);
  s=act(s,'left');assert.equal(s.filter,0);
  s=act(s,'filter',0,{index:99});assert.equal(s.filter,0);
});
function enter(s,digits,now=0){for(const digit of digits)s=act(s,'digit',now,{value:digit});return s;}
function setting(s,menu,id,now=0,direction='right'){
  const row=MENUS[menu].rows.findIndex(r=>r.id===id);assert(row>=0);
  return act({...s,view:'settings',path:[menu],stack:[],row},direction,now);
}
function approve(s){return act(act(s,'right'),'ok');}

test('zero volume is automatically silent and raising it clears only automatic silence',()=>{
  let s=act(create(),'set-volume',0,{value:0});
  assert.equal(audioMuted(s),true);assert.equal(s.muted,false);
  s=act(s,'mute');assert.equal(audioMuted(s),true);assert.equal(s.muted,false);
  s=act(s,'volume-up');assert.equal(s.volume,1);assert.equal(audioMuted(s),false);
  s=act(s,'mute');assert.equal(audioMuted(s),true);
  s=act(s,'volume-down');s=act(s,'volume-up');
  assert.equal(s.volume,1);assert.equal(s.muted,true);assert.equal(audioMuted(s),true);
  s=act(s,'mute');assert.equal(audioMuted(s),false);
});

test('sound row zero, rapid repeats and ARC all respect automatic silence boundaries',()=>{
  let s=act(create(),'set-volume',0,{value:1});s=setting(s,'sound','sound-volume',0,'left');
  assert.equal(s.volume,0);assert.equal(audioMuted(s),true);
  s=setting(s,'sound','sound-volume',0,'right');assert.equal(audioMuted(s),false);
  for(let i=0;i<160;i++)s=act(s,'volume-up',i);assert.equal(s.volume,100);
  for(let i=0;i<220;i++)s=act(s,'volume-down',i);assert.equal(s.volume,0);assert.equal(audioMuted(s),true);
  s=act(s,'connection',300,{arc:true,cec:true,hdmi:true,handled:true});
  assert.equal(audioMuted(s),false);s=act(s,'mute');assert.equal(s.arcMuted,true);assert.equal(audioMuted(s),true);
  s=act(s,'mute');assert.equal(audioMuted(s),false);assert.equal(s.volume,0);
  s=act(s,'connection',400,{handled:false});assert.equal(audioMuted(s),false);
  s=act(s,'mute');assert.equal(s.arcMuted,false);assert.equal(s.volume,0);assert.equal(s.effect.accepted,false);
  s=act(s,'connection',500,{arc:false});assert.equal(audioMuted(s),true);
});

test('all exported menu actions have a concrete local flow',()=>{
  const expected={
    'reset-picture':s=>assert.equal(s.confirm?.action,'reset-picture'),
    'reset-sound':s=>assert.equal(s.confirm?.action,'reset-sound'),
    'reset-all':s=>assert.equal(s.confirm?.action,'reset-all'),
    'clear-history':s=>assert.equal(s.confirm?.action,'clear-history'),
    'scan-channels':s=>assert.equal(s.view,'scan'),
    'change-pin':s=>assert.equal(s.flow?.step,'current'),
    'open-channels':s=>assert.equal(s.view,'list'),
    'open-favorites':s=>assert.equal(s.filter,1),
    'signal-info':s=>assert.equal(s.flow?.kind,'signal'),
    'reset-images':s=>assert.equal(s.view,'operation'),
    'media-open':s=>assert.equal(s.view,'media'),
    'recordings-list':s=>assert.equal(s.view,'recordings'),
    'timer-list':s=>assert.equal(s.view,'timers'),
    'timer-add':s=>assert.equal(s.programTimers.length,1),
    'record-toggle':s=>assert.match(s.notice,/USB/),
    timeshift:s=>assert.match(s.notice,/USB/),
    'backup-settings':s=>assert.match(s.notice,/USB/),
    'restore-settings':s=>assert.match(s.notice,/USB/),
  };
  for(const name of ['cec-devices','cec-standby','usb-keyboard','usb-mouse','software-update','oad','tkgs','ca-module','diseqc-info','license','clock-info','media-device','scan-settings'])expected[name]=s=>{assert.equal(s.view,'operation');assert.equal(s.flow.kind,'operation');assert(s.flow.rows.length>0);};
  const names=new Set(Object.values(MENUS).flatMap(m=>m.rows).filter(r=>r.type==='action').map(r=>r.action));
  assert.deepEqual([...names].sort(),Object.keys(expected).sort());
  for(const name of names)expected[name](command(create(),name));
});

test('manual scan validates a number, creates only a demo channel and returns to its settings row',()=>{
  const before={...create(),view:'settings',path:['source'],row:4};
  let s=command(before,'manual-scan',100);
  assert.equal(s.view,'manual-scan');assert.equal(s.flow.returnView,'settings');
  s=act(s,'ok');assert.match(s.flow.error,/1–9999/);
  s=enter(s,'0042');s=act(s,'ok',1000);
  assert.equal(s.view,'scan');assert.equal(s.scanNumber,42);
  s=act(s,'tick',4999);assert.equal(s.scanProgress,99);
  s=act(s,'tick',5000);assert.equal(s.view,'list');
  assert.equal(s.channels.length,4);assert.equal(s.channels.at(-1).demo,true);assert.equal(s.channels.at(-1).number,42);
  assert.equal(before.channels.length,3);
  s=act(s,'back');assert.equal(s.view,'settings');assert.equal(s.row,4);
});

test('manual/automatic scan cancellation and repeat scans never duplicate channels',()=>{
  let s=command(create(),'manual-scan');s=enter(s,'0001');s=act(s,'ok');s=act(s,'tick',4000);
  assert.equal(s.channels.length,3);
  s=command(s,'scan-channels',5000);s=act(s,'back');assert.equal(s.view,'list');assert.equal(s.scanStarted,null);
  s=command({...s,view:'settings',path:['source'],row:3},'manual-scan');s=enter(s,'1234');s=act(s,'back');
  assert.equal(s.view,'settings');assert.equal(s.row,3);assert.equal(s.flow,null);
});

test('PIN change requires old PIN, matching new PIN and preserves prior state',()=>{
  let s=command({...create(),view:'settings',path:['parental'],row:4},'change-pin');
  const before=s;s=enter(s,'1111');s=act(s,'ok');assert.equal(s.flow.step,'current');assert.equal(s.flow.error,'Yanlış PIN');
  s=enter(s,'0000');s=act(s,'ok');assert.equal(s.flow.step,'new');
  s=enter(s,'1234');s=act(s,'ok');assert.equal(s.flow.step,'confirm');
  s=enter(s,'4321');s=act(s,'ok');assert.equal(s.flow.error,'PIN eşleşmiyor');
  s=enter(s,'1234');s=act(s,'ok');assert.equal(s.pin,'1234');assert.equal(s.view,'settings');assert.equal(s.row,4);
  assert.equal(before.pin,'0000');assert.equal(before.flow.digits,'');
});

test('channel lock gates tuning and editor unlocking behind a PIN',()=>{
  let s=create();s.channels[1].locked=true;
  s=act(s,'channel-up');assert.equal(s.flow.kind,'pin');assert.equal(s.channelIndex,0);
  s=act(enter(s,'9999'),'ok');assert.equal(s.channelIndex,0);assert.equal(s.flow.error,'Yanlış PIN');
  s=act(enter(s,'0000'),'ok');assert.equal(s.channelIndex,1);assert.equal(s.view,'tv');assert.deepEqual(s.history,[2]);
  s={...s,view:'editor',listFocus:1,filter:0};s=act(s,'lock');assert.equal(s.flow.kind,'pin');
  s=act(enter(s,'0000'),'ok');assert.equal(s.channels[1].locked,false);assert.equal(s.view,'editor');
});

test('menu, source and global channel locks honor cancellation and successful verification',()=>{
  let s=create();s.values['parental-menu-lock']=true;s={...s,view:'home'};
  s=act(s,'activate-category',0,{index:0});assert.equal(s.flow.kind,'pin');
  s=act(s,'back');assert.equal(s.view,'home');
  s=act(s,'activate-category',0,{index:0});s=act(enter(s,'0000'),'ok');assert.equal(s.view,'settings');assert.deepEqual(s.path,['picture']);
  s=act(s,'menu');s.values['parental-source-lock']=true;s=act(s,'source');
  s=act(s,'activate-source',0,{index:INPUTS.indexOf('HDMI 1')});assert.equal(s.flow.kind,'pin');assert.equal(s.source,'TV');
  s=act(enter(s,'0000'),'ok');assert.equal(s.source,'HDMI 1');
  s=act(s,'power');s=act(s,'power');assert.equal(s.parentalAccess.source,false);
  s.source='TV';s.values['parental-channel-lock']=true;s=act(s,'channel-up');assert.equal(s.flow.kind,'pin');
  s=act(s,'back');assert.equal(s.channelIndex,0);
});

test('sleep/shutdown/startup use deadlines and startup volume never changes current volume early',()=>{
  let s=create();s=setting(s,'timer','timer-sleep',1000);assert.equal(s.sleepAt,601000);
  s=setting(s,'timer','timer-startup',1000);assert.equal(s.startupAt,901000);
  s=setting(s,'timer','timer-start-volume',1000);assert.equal(s.values['timer-start-volume'],21);assert.equal(s.volume,32);
  s=act(s,'tick',600999);assert.equal(s.standby,false);
  s=act(s,'tick',601000);assert.equal(s.standby,true);
  s=act(s,'tick',901000);assert.equal(s.standby,false);assert.equal(s.volume,21);assert.equal(s.startupAt,null);assert.equal(s.sleepAt,null);
  s=setting(s,'timer','timer-shutdown',902000);assert.equal(s.shutdownAt,2702000);
  s=act(s,'tick',2702000);assert.equal(s.standby,true);assert.equal(s.values['timer-shutdown'],'Kapalı');
  assert.equal(act(s,'channel-up').channelIndex,s.channelIndex);
});

test('startup wakes standby and simultaneous overdue timers apply chronologically',()=>{
  let s=create();s=setting(s,'timer','timer-startup',100);s=act(s,'power');assert.equal(s.standby,true);
  s=act(s,'tick',900100);assert.equal(s.standby,false);assert.equal(s.view,'tv');assert.equal(s.volume,20);
  s=create();s=setting(s,'timer','timer-startup',100);s=setting(s,'timer','timer-shutdown',100);
  s=act(s,'tick',1800100);assert.equal(s.standby,true);
});

test('automatic power off is separate from shutdown and choices can disable timers',()=>{
  let s=setting(create(),'advanced','advanced-auto-off',100);assert.equal(s.autoOffAt,7200100);assert.equal(s.shutdownAt,null);
  s=setting(s,'advanced','advanced-auto-off',200,'left');assert.equal(s.autoOffAt,null);
  s=setting(s,'timer','timer-sleep',300);s=setting(s,'timer','timer-sleep',400,'left');assert.equal(s.sleepAt,null);
});

test('favorites and signal info restore the invoking settings location',()=>{
  const base={...create(),view:'settings',path:['channels'],row:1};
  let s=command(base,'open-favorites');assert.deepEqual(filteredChannels(s).map(c=>c.number),[1,3]);
  s=act(s,'back');assert.equal(s.view,'settings');assert.equal(s.row,1);
  s=command(s,'signal-info');assert.equal(s.flow.demo,true);assert.equal(s.flow.channel.number,1);
  s=act(s,'ok');assert.equal(s.view,'settings');assert.equal(s.row,1);
});

test('clear history cancellation and acceptance alter only local history',()=>{
  let s=act(act(create(),'channel-up'),'channel-up');assert.deepEqual(s.history,[3,2]);
  s=command(s,'clear-history');s=act(s,'ok');assert.deepEqual(s.history,[3,2]);
  s=approve(command(s,'clear-history'));assert.deepEqual(s.history,[]);assert.equal(s.previousIndex,s.channelIndex);
  assert.equal(currentChannel(s).number,3);
});

test('sound reset synchronizes volume/EQ and factory reset clears all demo state',()=>{
  let s=create();s.volume=87;s.values['sound-volume']=87;s.values['equalizer-120']=10;s.values['picture-brightness']=20;
  s=approve(command(s,'reset-sound'));assert.equal(s.volume,32);assert.equal(s.values['equalizer-120'],0);assert.equal(s.values['picture-brightness'],20);
  s.pin='1234';s.channels.push({number:99,name:'Demo 99'});s.sleepAt=1234;s.shutdownAt=5555;s.startupAt=6666;s.autoOffAt=7777;s.history=[2];
  s=approve(command(s,'reset-all'));assert.equal(s.pin,'0000');assert.equal(s.channels.length,3);assert.equal(s.view,'tv');assert.equal(s.values['picture-brightness'],50);
  assert.deepEqual([s.sleepAt,s.shutdownAt,s.startupAt,s.autoOffAt],[null,null,null,null]);assert.deepEqual(s.history,[]);
});

test('source choice controls the local source and radio filtering has an honest empty state',()=>{
  let s=setting(create(),'source','source-input');assert.equal(s.tunerType,'Uydu');assert.equal(s.source,'TV');
  s=setting(s,'channels','channels-service-type');assert.equal(s.values['channels-service-type'],'Radyo');assert.deepEqual(filteredChannels(s),[]);
  s={...s,view:'list'};s=act(s,'ok');assert.equal(s.channelIndex,0);
});

test('ARC menu volume sends relative intents without inventing an absolute receiver volume',()=>{
  let s=act(create(),'connection',0,{arc:true,cec:true,hdmi:true,handled:true});
  const before=s;
  s=setting(s,'sound','sound-volume',100,'right');
  assert.equal(s.volume,32);assert.equal(s.values['sound-volume'],32);
  assert.equal(s.lastArc,'volume-up');assert.equal(s.effect.kind,'demo-cec');assert.equal(s.effect.command,'volume-up');
  assert.equal(s.volumeUntil,3100);assert.equal(before.sequence,0);
  s=setting(s,'sound','sound-volume',200,'left');
  assert.equal(s.volume,32);assert.equal(s.values['sound-volume'],32);assert.equal(s.effect.command,'volume-down');
  assert.equal(s.effect.sequence,2);
  s=act(s,'connection',300,{handled:false});
  s=setting(s,'sound','sound-volume',400,'right');assert.equal(s.volume,32);assert.equal(s.values['sound-volume'],32);assert.equal(s.effect.accepted,false);
  for(const type of ['volume-up','volume-down','mute']){s=act(s,type,450);assert.equal(s.volume,32);assert.equal(s.arcMuted,false);assert.equal(s.effect.accepted,false);}
});

test('numeric backspace deletes real digits, repairs count and rearms or clears the deadline',()=>{
  let s=enter(create(),'1234',100);assert.equal(s.digitDeadline,2100);
  s=act(s,'backspace',500);assert.equal(s.digits,'123');assert.equal(s.digitCount,3);assert.equal(s.digitDeadline,3500);
  s=act(s,'backspace',600);assert.equal(s.digits,'12');assert.equal(s.digitCount,2);assert.equal(s.digitDeadline,3600);
  s=act(s,'backspace',700);s=act(s,'backspace',800);
  assert.equal(s.digits,'');assert.equal(s.digitCount,0);assert.equal(s.digitDeadline,null);
  s=act(s,'tick',5000);assert.equal(s.channelIndex,0);assert.equal(s.notice,'');
  s=enter(s,'00012',6000);assert.equal(s.digitCount,5);
  s=act(s,'backspace',6500);assert.equal(s.digits,'000');assert.equal(s.digitCount,3);assert.equal(s.digitDeadline,9500);
  s=act(s,'digit',6600,{value:'2'});s=act(s,'ok',6700);assert.equal(currentChannel(s).number,2);
});

test('editor reordering preserves the identities of both current and recall channels',()=>{
  let s=act(act(create(),'channel-up'),'channel-up');
  assert.equal(currentChannel(s).number,3);assert.equal(s.channels[s.previousIndex].number,2);
  const before={...s,view:'editor',listFocus:1,filter:0,editorMoving:true};
  s=act(before,'up');
  assert.deepEqual(s.channels.map(c=>c.number),[2,1,3]);
  assert.equal(currentChannel(s).number,3);assert.equal(s.channels[s.previousIndex].number,2);
  assert.deepEqual(before.channels.map(c=>c.number),[1,2,3]);
  s=act(s,'recall');assert.equal(currentChannel(s).number,2);
  assert.equal(s.channels[s.previousIndex].number,3);
  s=act(s,'recall');assert.equal(currentChannel(s).number,3);
});

test('confirmation pointer choices activate the selected button independently of prior focus',()=>{
  let s=create();s.values['picture-brightness']=12;
  s=command(s,'reset-picture');assert.equal(s.confirmChoice,0);
  s=act(s,'confirm-choice',0,{index:1});assert.equal(s.confirm,null);assert.equal(s.values['picture-brightness'],50);
  s.values['picture-brightness']=23;s=command(s,'reset-picture');s.confirmChoice=1;
  s=act(s,'confirm-choice',0,{index:0});assert.equal(s.confirm,null);assert.equal(s.values['picture-brightness'],23);
  s=command(s,'reset-picture');s=act(s,'confirm-choice',0,{index:2});assert.equal(s.confirm.action,'reset-picture');
});

test('source remote navigation follows the four-column demonstration port grid',()=>{
  let s=act(create(),'source');assert.equal(s.sourceFocus,0);
  s=act(s,'right');assert.equal(s.sourceFocus,1);
  s=act(s,'down');assert.equal(s.sourceFocus,5);
  s=act(s,'down');assert.equal(s.sourceFocus,5);
  s=act(s,'up');assert.equal(s.sourceFocus,1);
  s=act(s,'up');assert.equal(s.sourceFocus,1);
  s=act(s,'left');assert.equal(s.sourceFocus,0);
  s=act(s,'down');assert.equal(s.sourceFocus,4);
  s=act(s,'ok');assert.equal(s.source,'HDMI 4');
});
