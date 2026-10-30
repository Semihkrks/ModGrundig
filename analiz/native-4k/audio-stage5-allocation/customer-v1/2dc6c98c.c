
/* mapi_audio_customer::InputSource_ChangeAudioSource(MAPI_INPUT_SOURCE_TYPE,
   MAPI_AUDIO_PROCESSOR_TYPE) */

void __thiscall
mapi_audio_customer::InputSource_ChangeAudioSource
          (mapi_audio_customer *this,int param_2,int param_3)

{
  mapi_video_customer *this_00;
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20 [2];
  
  printf("\n\n\n %s->line:%d   enInputSourceType:%d  SDK_eAudioCurInputSrc:%d  eProcessor:%d \n\n",
         "InputSource_ChangeAudioSource",0x8f1,param_2,*(undefined4 *)(this + 0x118),param_3);
  this_00 = (mapi_video_customer *)mapi_video_customer::GetInstance();
  uVar1 = mapi_video_customer::getAppPipStatus(this_00);
  printf(" %s->line:%d   AppPIP status:%d  m_bPrevAppPipStatus:%d \n\n\n",
         "InputSource_ChangeAudioSource",0x8f8,uVar1,(uint)(byte)this[0x1c4]);
  iVar2 = mapi_audio::IsAudioInitDone();
  if (iVar2 == 0) {
    printf("\n\x1b[0;31m [Warning!!] [%s] [%s()] IsAudioInitDone() == FALSE, Please Check!!  \x1b[0m \n"
           ,"mapi_audio_customer.cpp","InputSource_ChangeAudioSource");
  }
  uVar1 = 0xff;
  if (param_3 == 1) {
    uVar1 = 1;
  }
  local_20[0] = 0xff;
  if (param_2 == 0x1e) {
    local_20[0] = mapi_audio::_InputSourceTypeToAudioInputType(this,0x1a);
LAB_2dc6cc20:
    (**(code **)(*(int *)this + 0xc0))(this,0x70,uVar1);
    (**(code **)(*(int *)this + 0xc0))(this,0xd1,uVar1);
    if (param_3 != 1) goto LAB_2dc6cab4;
LAB_2dc6cc5c:
    (**(code **)(*(int *)this + 0xc0))(this,0x31,uVar1);
    (**(code **)(*(int *)this + 0x54))(this,*(undefined4 *)(this + 0x130));
    *(int *)(this + 0x158) = param_2;
    *(int *)(this + 0x154) = param_3;
    uVar3 = (**(code **)(*(int *)this + 0x50))(this,this + 0x150);
    *(undefined4 *)(this + 0x130) = uVar3;
    if ((param_2 != 0x22) && (param_2 != 0x26)) {
      (**(code **)(*(int *)this + 0xc0))(this,0x93,uVar1);
    }
    iVar2 = FUN_2dc6aacc(*(undefined4 *)(this + 0x130),local_20);
    if (iVar2 == 1) {
      MApi_AUDIO_InputSwitch(local_20[0],3);
    }
    else {
      local_20[0] = mapi_audio::_InputSourceTypeToAudioInputType(this,param_2);
      MApi_AUDIO_InputSwitch(local_20[0],3);
    }
    if ((param_2 - 0x17U < 4) || (param_2 == 0x1e)) {
      *(undefined4 *)(this + 0x80) = 2;
    }
    if (param_2 == 1) {
      (**(code **)(*(int *)this + 0x44))(this,3,1);
      if (*(int *)(this + 0x114) != 0) {
        MApi_AUDIO_SIF_SetThreshold();
      }
      MDrv_AUDIO_TriggerSifPLL();
      *(undefined4 *)(this + 0x100) = 1;
      (**(code **)(*(int *)this + 0xc0))(this,0x50,1);
      (**(code **)(*(int *)this + 0xc0))(this,0x80,1);
    }
    else if (param_2 == 0x1c) {
      if (param_3 == 1) {
        (**(code **)(*(int *)this + 0x44))(this,0,1);
        MApi_AUDIO_InputSwitch(local_20[0],3);
        MDrv_AUDIO_SetInternalPath(7,1);
        printf("\x1b[1;34m [AUDIO][%s] [%d] [] \x1b[0m \n","InputSource_ChangeAudioSource",0x957);
        iVar2 = *(int *)this;
      }
      else {
        iVar2 = *(int *)this;
      }
      *(undefined4 *)(this + 0x100) = 0x1c;
      (**(code **)(iVar2 + 0xc0))(this,0x80,1);
    }
    else {
      *(int *)(this + 0x100) = param_2;
      (**(code **)(*(int *)this + 0xc0))(this,0x50,1);
      (**(code **)(*(int *)this + 0xc0))(this,0x80,1);
      if (param_2 == 0x2a) {
        (**(code **)(*(int *)this + 0x144))(this);
      }
    }
  }
  else {
    local_20[0] = mapi_audio::_InputSourceTypeToAudioInputType(this,param_2);
    if (0xc < param_2 - 2U) goto LAB_2dc6cc20;
    (**(code **)(*(int *)this + 0xc0))(this,0xd1,uVar1);
    if (param_3 == 1) goto LAB_2dc6cc5c;
LAB_2dc6cab4:
    if (param_3 == 2) {
      (**(code **)(*(int *)this + 0x40))(this,3);
    }
    else if (param_3 == 0) {
      iVar2 = 0x1a;
      if (param_2 != 0x1e) {
        iVar2 = param_2;
      }
      (**(code **)(*(int *)this + 0x6c))(this,iVar2);
      iVar2 = *(int *)(this + 0x130);
      *(int *)(this + 0xfc) = param_2;
      goto joined_r0x2dc6cbb0;
    }
  }
  iVar2 = *(int *)(this + 0x130);
joined_r0x2dc6cbb0:
  if ((iVar2 == -1) && (*(int *)(this + 300) == -1)) {
    if ((*(int *)(this + 0xfc) == 1) || (*(int *)(this + 0x100) == 1)) {
      MApi_AUDIO_SetAC3PInfo(0x10,0,0);
    }
    else {
      MApi_AUDIO_SetAC3PInfo(0x10,1,0);
    }
  }
  if ((param_2 == 0x22) || (param_2 == 0x26)) {
    SetDelaysForUSBSource();
  }
  else if (((param_2 == 0x1c) || (param_2 == 0x25)) || (param_2 == 0x27)) {
    SetDelaysForDTVSource();
  }
  else {
    SetDelaysForOtherSources();
  }
  if (param_2 != 1) {
    (**(code **)(*(int *)this + 0xc0))(this,0x30,uVar1);
  }
  (**(code **)(*(int *)this + 0xc0))(this,0xc0,uVar1);
  (**(code **)(*(int *)this + 0xc0))(this,0xd0,uVar1);
  return;
}

