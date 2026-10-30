
/* mapi_audio_customer::DECODER_SwitchAudioDSPSystem(AUDIO_DSP_SYSTEM_) */

void __thiscall
mapi_audio_customer::DECODER_SwitchAudioDSPSystem(mapi_audio_customer *this,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  switch(param_2) {
  default:
    *(undefined4 *)(this + 0x7c) = 1;
    MApi_AUDIO_SetSystem(1);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 1:
    *(undefined4 *)(this + 0x7c) = 2;
    MApi_AUDIO_SetSystem(2);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 2:
    *(undefined4 *)(this + 0x7c) = 0x32;
    MApi_AUDIO_SetSystem(0x32);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 3:
    break;
  case 4:
    *(undefined4 *)(this + 0x7c) = 4;
    MApi_AUDIO_SetSystem(4);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 5:
    *(undefined4 *)(this + 0x7c) = 0x31;
    MApi_AUDIO_SetSystem(0x31);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 6:
    *(undefined4 *)(this + 0x7c) = 3;
    MApi_AUDIO_SetSystem(3);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 7:
    *(undefined4 *)(this + 0x7c) = 0x35;
    MApi_AUDIO_SetSystem(0x36);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 8:
    *(undefined4 *)(this + 0x7c) = 0x34;
    MApi_AUDIO_SetSystem(0x34);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  case 0x12:
    *(undefined4 *)(this + 0x7c) = 0x14;
    MApi_AUDIO_SetSystem(0x14);
    *(undefined4 *)(this + 0x8c) = param_2;
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
    return;
  }
  MApi_AUDIO_SIF_SendCmd(0,0,0);
  piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
  iVar2 = (**(code **)(*piVar1 + 0x104))(piVar1,0x10);
  if (iVar2 == 0) {
code_r0x2dc65f94:
    piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
    iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
    if (iVar2 != 1) {
      piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
      iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
      if (iVar2 != 0) goto code_r0x2dc65fdc;
      piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
      iVar2 = (**(code **)(*piVar1 + 0x68))(piVar1);
      if (iVar2 == 0) goto code_r0x2dc66240;
      piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
      iVar2 = (**(code **)(*piVar1 + 0x68))(piVar1);
      if (iVar2 != 1) goto code_r0x2dc65fdc;
    }
    *(undefined4 *)(this + 0x7c) = 0xb3;
    MApi_AUDIO_SetSystem(0xb3);
  }
  else {
    piVar1 = (int *)mapi_syscfg_fetch::GetInstance();
    iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
    if (iVar2 != 3) goto code_r0x2dc65f94;
code_r0x2dc66240:
    *(undefined4 *)(this + 0x7c) = 0xb1;
    MApi_AUDIO_SetSystem(0xb1);
  }
code_r0x2dc65fdc:
  if (*(int *)(this + 0x114) != 0) {
    MApi_AUDIO_SIF_SetThreshold();
  }
  (**(code **)(*(int *)this + 0x98))(this);
  MApi_AUDIO_SIF_SendCmd(1,0,0);
  *(undefined4 *)(this + 0x8c) = param_2;
  mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
  return;
}

