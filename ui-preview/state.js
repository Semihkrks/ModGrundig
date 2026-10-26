// Offline interaction model. Never sends audio, CEC or firmware commands.
import {PROFILE} from './native-profile.js';
export const AUTO_HIDE_MS = 3000;
export const CARD_TITLES = PROFILE.cards.map(card=>card.label.text);
const clamp = value => Math.max(0, Math.min(100, Math.round(Number(value) || 0)));
export function createState() {
  return { volume:32, muted:false, arcMuted:false, arc:false, cec:false, hdmi:false, handled:true,
    menu:true, tab:0, card:1, zone:'cards', detail:null, volumeVisible:true,
    deadline:AUTO_HIDE_MS, lastArcCommand:null, effect:null, sequence:0 };
}
export function route(state) { return state.arc && state.cec && state.hdmi ? 'arc' : 'local'; }
export function mode(state) { return route(state)==='arc' ? (state.arcMuted?3:2) : (state.muted?1:0); }
export function reduce(previous, action, now=0) {
  const state={...previous, effect:null};
  const show=()=>{state.volumeVisible=true;state.deadline=now+AUTO_HIDE_MS;};
  const emit=(kind,command)=>{state.effect={kind,command,sequence:++state.sequence};};
  if (action.type==='tick') {
    if(now>=state.deadline) state.volumeVisible=false;
  } else if (action.type==='connection') {
    for(const key of ['arc','cec','hdmi','handled']) if(key in action) state[key]=Boolean(action[key]);
    state.lastArcCommand=null; show();
  } else if (['volume-up','volume-down','mute'].includes(action.type)) {
    show();
    if(route(state)==='arc') {
      // Demonstration of outbound intent only. No invented ARC absolute-volume report.
      state.lastArcCommand=action.type;
      if(action.type==='mute'&&state.handled) state.arcMuted=!state.arcMuted;
      emit('simulated-cec',action.type);
      state.effect.accepted=state.handled;
    } else {
      if(action.type==='mute') state.muted=!state.muted;
      else state.volume=clamp(state.volume+(action.type==='volume-up'?1:-1));
      emit('simulated-local-audio',action.type);
    }
  } else if(action.type==='set-volume') {
    if(route(state)==='local') {state.volume=clamp(action.value); show();}
  } else if(action.type==='menu') {
    state.menu=!state.menu;state.detail=null;state.zone='cards';
  } else if(action.type==='back') {
    if(state.detail!==null) state.detail=null;
    else state.menu=false;
  } else if(action.type==='tab' && state.menu) {
    state.tab=0;state.zone='tabs';state.detail=null;
  } else if(action.type==='card' && state.menu && state.tab===0) {
    state.card=Math.max(0,Math.min(CARD_TITLES.length-1,Number(action.value)||0));state.zone='cards';
  } else if(action.type==='ok' && state.menu) {
    if(state.zone==='tabs') {if(state.tab===0)state.zone='cards';}
    else if(state.tab===0 && state.detail===null)state.detail=state.card;
  } else if(['left','right','up','down'].includes(action.type) && state.menu && state.detail===null) {
    if(action.type==='up') state.zone='tabs';
    else if(action.type==='down' && state.tab===0) state.zone='cards';
    else if(action.type==='left'||action.type==='right') {
      const delta=action.type==='right'?1:-1;
      if(state.zone==='tabs') state.tab=0;
      else state.card=Math.max(0,Math.min(CARD_TITLES.length-1,state.card+delta));
    }
  }
  return state;
}

// Retarget from the currently drawn position, never queue rapid remote repeats.
export class SmoothLevel {
  constructor(value=32,duration=150) {this.from=this.target=clamp(value);this.start=0;this.duration=Math.max(0,duration);}
  at(now) {
    if(!this.duration)return this.target;
    const t=Math.max(0,Math.min(1,(now-this.start)/this.duration));
    return this.from+(this.target-this.from)*(1-(1-t)**3);
  }
  retarget(value,now) {
    value=clamp(value);
    if(value===this.target)return;
    this.from=this.at(now);this.target=value;this.start=now;
  }
}
