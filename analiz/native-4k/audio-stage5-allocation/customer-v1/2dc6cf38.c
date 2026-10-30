
/* WARNING: Type propagation algorithm not settling */
/* mapi_audio_customer::InputSource_ChangeAudioSource(MAPI_INPUT_SOURCE_TYPE) */

void __thiscall
mapi_audio_customer::InputSource_ChangeAudioSource(mapi_audio_customer *this,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  mapi_audio_customer mVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 local_30 [3];
  
  if (*(int *)(this + 0x118) == param_2) {
    return;
  }
  (**(code **)(*(int *)this + 0xc0))(this,0x160,0xff);
  (**(code **)(*(int *)this + 0xc0))(this,0xd1,0);
  MDrv_AUDIO_WriteByte(0x2d50,0x55);
  iVar1 = mapi_audio::IsAudioInitDone();
  if (iVar1 == 0) {
    printf("\n\x1b[0;31m [Warning!!] [%s] [%s()] IsAudioInitDone() == FALSE, Please Check!!  \x1b[0m \n"
           ,"mapi_audio_customer.cpp","InputSource_ChangeAudioSource");
  }
  local_30[0] = 0xff;
  piVar2 = (int *)mapi_syscfg_fetch::GetInstance();
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))(piVar2);
  MApi_AUDIO_SetAC3PInfo(6,0,0);
  (**(code **)(*(int *)this + 0x54))(this,*(undefined4 *)(this + 300));
  *(undefined4 *)(this + 0x148) = 1;
  *(int *)(this + 0x13c) = param_2;
  *(undefined4 *)(this + 0x138) = 0;
  uVar3 = (**(code **)(*(int *)this + 0x50))(this,this + 0x134);
  *(undefined4 *)(this + 300) = uVar3;
  *(int *)(this + 0x118) = param_2;
  *(int *)(this + 0xfc) = param_2;
  mapi_audio::SND_ProcessEnable(this,7,0);
  (**(code **)(*(int *)this + 0xc0))(this,0x110,0);
  switch(param_2) {
  case 0:
    uVar6 = (uint)(byte)this[0xd3];
    mVar5 = this[0xda];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 1:
    uVar6 = (uint)(byte)this[0xd0];
    mVar5 = this[0xd7];
    MApi_AUDIO_SetSourceInfo(1);
    if (*(int *)(this + 0x114) != 0) {
      MApi_AUDIO_SIF_SetThreshold();
    }
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    iVar1 = FUN_2dc6aacc(*(undefined4 *)(this + 300),local_30);
    if (iVar1 == 1) {
      MApi_AUDIO_InputSwitch(local_30[0],0);
    }
    else {
      uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
      MApi_AUDIO_InputSwitch(uVar3,0);
    }
    (**(code **)(*(int *)this + 0x44))(this,3,0);
    (**(code **)(*(int *)this + 0x98))(this);
    MDrv_AUDIO_TriggerSifPLL();
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0xff);
    (**(code **)(*(int *)this + 0xc0))(this,0x50,0xff);
    (**(code **)(*(int *)this + 0xc0))(this,0x31,0);
    mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,0);
    SDK_Audio_Scart_Input_Select = piVar2[2];
    goto code_r0x2dc6d0a8;
  case 2:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    MApi_AUDIO_InputSwitch(uVar3,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x50,0);
    mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,1);
    SDK_Audio_Scart_Input_Select = piVar2[6];
    goto code_r0x2dc6d0a8;
  case 3:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  default:
    mVar5 = (mapi_audio_customer)0x0;
    uVar6 = 0;
    goto code_r0x2dc6d0a8;
  case 0xb:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 0x10:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 0x11:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 0x14:
    uVar6 = (uint)(byte)this[0xd1];
    mVar5 = this[0xd8];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 0x15:
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    mVar5 = (mapi_audio_customer)0x0;
    uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    uVar6 = 0;
    MApi_AUDIO_InputSwitch(uVar3,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    pcVar7 = *(code **)(*(int *)this + 0xc0);
    goto code_r0x2dc6d6d0;
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1e:
    uVar6 = (uint)(byte)this[0xd2];
    mVar5 = this[0xd9];
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    MApi_AUDIO_SetSourceInfo(2);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    iVar1 = FUN_2dc6aacc(*(undefined4 *)(this + 300),local_30);
    if (iVar1 == 1) {
      MApi_AUDIO_InputSwitch(local_30[0],0);
      iVar1 = *(int *)this;
    }
    else {
      uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
      MApi_AUDIO_InputSwitch(uVar3,0);
      iVar1 = *(int *)this;
    }
    *(undefined4 *)(this + 0x80) = 2;
    (**(code **)(iVar1 + 0xc0))(this,0x50,0);
    mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,1);
    goto code_r0x2dc6d0a8;
  case 0x1c:
    uVar6 = (uint)(byte)this[0xcf];
    mVar5 = this[0xd6];
    MApi_AUDIO_SetSourceInfo(0);
    (**(code **)(*(int *)this + 0x44))(this,0,0);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    iVar1 = FUN_2dc6aacc(*(undefined4 *)(this + 300),local_30);
    if (iVar1 == 1) {
      MApi_AUDIO_InputSwitch(local_30[0],0);
    }
    else {
      uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
      MApi_AUDIO_InputSwitch(uVar3,0);
    }
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    SDK_Audio_Scart_Input_Select = *piVar2;
    piVar4 = (int *)mapi_syscfg_fetch::GetInstance();
    iVar1 = (**(code **)(*piVar4 + 0x104))(piVar4,8);
    if (iVar1 == 0) {
      mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,3);
      piVar4 = (int *)mapi_syscfg_fetch::GetInstance();
      iVar1 = (**(code **)(*piVar4 + 0x104))(piVar4,0x10);
      if (iVar1 != 0) {
        piVar4 = (int *)mapi_syscfg_fetch::GetInstance();
        iVar1 = (**(code **)(*piVar4 + 100))(piVar4);
        if (iVar1 == 3) {
          puts("==> DTV DVB Dolby Line Mode");
        }
      }
    }
    else {
      mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,4);
      puts("==> DTV ATSC Dolby Line Mode");
    }
    goto code_r0x2dc6d0a8;
  case 0x1d:
    uVar6 = (uint)(byte)this[0xd3];
    mVar5 = this[0xda];
    MApi_AUDIO_SetSourceInfo(3);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    break;
  case 0x22:
    uVar6 = (uint)(byte)this[0xd4];
    if (uVar6 < 0x40) {
      printf("main_procBuf should be great than 64 ms in MM mode (%d)\r\n",uVar6);
      uVar6 = 0x40;
    }
    mVar5 = this[0xdb];
    MApi_AUDIO_SetSourceInfo(7);
    (**(code **)(*(int *)this + 0x44))(this,0,0);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    MApi_AUDIO_InputSwitch(uVar3,0);
    usleep(50000);
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x50,0);
    mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,1);
    mapi_audio::DECODER_SetADEnable((uchar)this);
    (**(code **)(*(int *)this + 0xc0))(this,0x111,0);
    goto code_r0x2dc6d0a8;
  case 0x23:
    uVar6 = (uint)(byte)this[0xd4];
    mVar5 = this[0xdb];
    MApi_AUDIO_SetSourceInfo(6);
    (**(code **)(*(int *)this + 0x44))(this,0,0);
    iVar1 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    if (iVar1 == 0xff) {
      (**(code **)(*(int *)this + 0xc0))(this,0x161,0xff);
    }
    uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    MApi_AUDIO_InputSwitch(uVar3,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
    (**(code **)(*(int *)this + 0xc0))(this,0x50,0);
    mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,1);
    mapi_audio::SND_ProcessEnable(this,7,0);
    goto code_r0x2dc6d0a8;
  }
  uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
  MApi_AUDIO_InputSwitch(uVar3,0);
  (**(code **)(*(int *)this + 0xc0))(this,0x80,0);
  pcVar7 = *(code **)(*(int *)this + 0xc0);
code_r0x2dc6d6d0:
  (*pcVar7)(this,0x50,0);
  mapi_audio::SPDIF_ChannelStatus_CTRL(this,0,1);
code_r0x2dc6d0a8:
  if ((((param_2 == 1) || (param_2 == 0x1c)) || (param_2 == 0x25)) || (param_2 == 0x27)) {
    MApi_AUDIO_SetAC3Info(5,1,0);
  }
  else {
    mapi_audio::DECODER_SetMpegInfo(this,4,2,0);
    mapi_audio::DECODER_SetOutputMode(this,0);
    SetSoundModeType(this,0);
    MApi_AUDIO_SetAC3Info(5,1,0);
  }
  if (*(int *)(this + 0x11c) == 0) {
    uVar3 = mapi_audio::GetInstance();
    mapi_audio::SPDIF_SetMode(uVar3,0);
  }
  else {
    uVar3 = mapi_audio::GetInstance();
    mapi_audio::SPDIF_SetMode(uVar3,2);
  }
  piVar4 = (int *)mapi_syscfg_fetch::GetInstance();
  iVar1 = (**(code **)(*piVar4 + 0x68))(piVar4);
  if ((iVar1 == 0) && (piVar2[2] == SDK_Audio_Scart_Input_Select)) {
    (**(code **)(*(int *)this + 0x3c))(this,1);
  }
  if (*(int *)(this + 0x50) != SDK_Audio_Scart_Input_Select) {
    uVar3 = mapi_audio::_u32PortToAudioInputType((ulong)this);
    MApi_AUDIO_InputSwitch(uVar3,1);
  }
  *(int *)(this + 0x50) = SDK_Audio_Scart_Input_Select;
  if ((param_2 != 0x1c) && (param_2 != 0x22)) {
    (**(code **)(*(int *)this + 0x28))(this,500,0);
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
  if ((byte)mVar5 < 0x14) {
    mVar5 = (mapi_audio_customer)0x14;
  }
  if (uVar6 < 0x20) {
    uVar6 = 0x20;
  }
  mapi_video_customer::GetInstance();
  iVar1 = mapi_video_customer::ARapi_GetUrsaType();
  if (iVar1 == 9) {
    uVar3 = mapi_video_customer::ARapi_GetUrsaType();
    printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [URSA type = %d] \x1b[0m \n","mapi_audio_customer.cpp",
           "InputSource_ChangeAudioSource",0x8af,uVar3);
    mVar5 = (mapi_audio_customer)((char)mVar5 + 'A');
    uVar6 = uVar6 + 0x41 & 0xff;
    iVar1 = GetArcStatus(this);
  }
  else {
    uVar3 = mapi_video_customer::ARapi_GetUrsaType();
    printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [URSA type = %d] \x1b[0m \n","mapi_audio_customer.cpp",
           "InputSource_ChangeAudioSource",0x8b6,uVar3);
    iVar1 = GetArcStatus(this);
  }
  if (iVar1 != 0) {
    mapi_audio::HDMI_ARC_PINControl(this,0x17,0,0);
    usleep(100000);
    mapi_audio::HDMI_ARC_PINControl(this,0x17,1,1);
  }
  if ((uVar6 - 0x14 & 0xff) < 0xe6) {
    MApi_AUDIO_SetBufferProcess(uVar6);
  }
  if ((byte)((char)mVar5 - 5U) < 0xf5) {
    MApi_AUDIO_SetCommAudioInfo(0x2a,mVar5,0);
  }
  if (param_2 != 1) {
    (**(code **)(*(int *)this + 0xc0))(this,0x30,0);
  }
  piVar2 = (int *)mapi_syscfg_fetch::GetInstance();
  iVar1 = (**(code **)(*piVar2 + 0x104))(piVar2,8);
  if ((iVar1 != 0) && (0x11 < param_2 - 2U)) {
    (**(code **)(*(int *)this + 0xc0))(this,0x70,0xff);
  }
  (**(code **)(*(int *)this + 0xc0))(this,0xc0,0);
  (**(code **)(*(int *)this + 0xc0))(this,0xd0,0);
  iVar1 = mapi_gpio::GetGPIO_Dev(0x8f);
  if (iVar1 != 0) {
    mapi_gpio::SetOn();
  }
  return;
}

