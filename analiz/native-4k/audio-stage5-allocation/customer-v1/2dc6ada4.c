
/* mapi_audio_customer::CloseAudioDec(MMA_AUDIO_DEC_ID) */

undefined4 __thiscall mapi_audio_customer::CloseAudioDec(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != -1) && (param_2 != 3)) {
    uVar1 = FUN_2dc634d8(param_2);
    uVar1 = MApi_AUDIO_ReleaseDecodeSystem(uVar1);
    return uVar1;
  }
  return 0;
}

