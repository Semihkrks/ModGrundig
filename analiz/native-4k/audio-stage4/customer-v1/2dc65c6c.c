
/* mapi_audio_customer::DECODER_SwitchAudioDSPSystem(AUDIO_DSP_SYSTEM_, MAPI_AUDIO_PROCESSOR_TYPE)
    */

void __thiscall
mapi_audio_customer::DECODER_SwitchAudioDSPSystem
          (mapi_audio_customer *this,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x130);
  if ((iVar1 == -1) && (*(int *)(this + 300) == -1)) {
    (**(code **)(*(int *)this + 0x40))();
  }
  else {
    if (param_3 == 0) {
      if (*(int *)(this + 300) != -1) {
        *(undefined4 *)(this + 0x140) = param_2;
        (**(code **)(*(int *)this + 0x58))(this,*(int *)(this + 300),this + 0x134);
      }
    }
    else if ((param_3 == 1) && (iVar1 != -1)) {
      *(undefined4 *)(this + 0x15c) = param_2;
      (**(code **)(*(int *)this + 0x58))(this,iVar1,this + 0x150);
    }
    mapi_audio::SPDIF_SetMode(this,*(undefined4 *)(this + 0x11c));
  }
  return;
}

