
/* mapi_audio_customer::mapi_audio_customer() */

void __thiscall mapi_audio_customer::mapi_audio_customer(mapi_audio_customer *this)

{
  mapi_audio_customer *pmVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  mapi_audio_customer *pmVar6;
  undefined4 *puVar7;
  
  mapi_audio::mapi_audio((mapi_audio *)this);
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined ***)this = &PTR__mapi_audio_customer_2dcf96b0;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  SDK_Audio_Monitor_Cnt = 0;
  SDK_AUD_wLimitedTimeOfMute = 0;
  this[0x128] = (mapi_audio_customer)0x1;
  *(undefined4 *)(this + 0x13c) = 0x1c;
  *(undefined4 *)(this + 0x158) = 0x25;
  *(undefined4 *)(this + 0x130) = 0xffffffff;
  *(undefined4 *)(this + 0x168) = 2;
  *(undefined4 *)(this + 0x1b0) = 1;
  this[0x129] = (mapi_audio_customer)0x0;
  *(undefined4 *)(this + 300) = 0xffffffff;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  pmVar1 = this + 0xc;
  puVar2 = (undefined4 *)&UNK_2dccd068;
  do {
    puVar7 = puVar2;
    pmVar6 = pmVar1;
    uVar3 = puVar7[1];
    uVar4 = puVar7[2];
    uVar5 = puVar7[3];
    *(undefined4 *)pmVar6 = *puVar7;
    *(undefined4 *)(pmVar6 + 4) = uVar3;
    *(undefined4 *)(pmVar6 + 8) = uVar4;
    *(undefined4 *)(pmVar6 + 0xc) = uVar5;
    pmVar1 = pmVar6 + 0x10;
    puVar2 = puVar7 + 4;
  } while (puVar7 + 4 != (undefined4 *)&UNK_2dccd088);
  *(undefined4 *)(pmVar6 + 0x14) = puVar7[5];
  *(undefined4 *)(pmVar6 + 0x10) = 0x7a0000a;
  *(undefined4 *)(this + 0xcf) = 0x20202020;
  *(undefined4 *)(this + 0xd3) = 0x4020;
  *(undefined4 *)(this + 0xd7) = 0;
  this[0xdc] = (mapi_audio_customer)0x0;
  this[0xdb] = (mapi_audio_customer)0x0;
  this[0x182] = (mapi_audio_customer)0x4;
  this[0x183] = (mapi_audio_customer)0x5;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined2 *)(this + 0xe0) = 0;
  *(undefined2 *)(this + 0xe2) = 0;
  this[0x1b4] = (mapi_audio_customer)0x0;
  this[0x1a8] = (mapi_audio_customer)0x0;
  this[0x1c4] = (mapi_audio_customer)0x0;
  this[0x1c5] = (mapi_audio_customer)0x0;
  return;
}

