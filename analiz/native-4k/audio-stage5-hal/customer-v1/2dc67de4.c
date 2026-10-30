
/* mapi_audio_customer::MMA_getAudioInfo2(MMA_AUDIO_DEC_ID, MM_AUDIO_INFO_TYPE, unsigned long) */

undefined4
mapi_audio_customer::MMA_getAudioInfo2
          (int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 3) {
    uVar1 = FUN_2dc634d8(param_2);
    switch(param_3) {
    case 0:
      uVar1 = 1;
      *param_4 = *(undefined4 *)(param_1 + (param_2 + 0x24) * 4);
      break;
    case 1:
      uVar1 = MApi_AUDIO_GetAudioInfo2(uVar1,0,param_4);
      break;
    default:
      printf("%s: Err! COMMAND(%d) is out of Range\n","MMA_getAudioInfo2",param_3);
      uVar1 = 0;
      break;
    case 8:
      uVar1 = MApi_AUDIO_GetAudioInfo2(uVar1,9,param_4);
      break;
    case 0xd:
      uVar1 = MApi_AUDIO_GetAudioInfo2(uVar1,0xf,param_4);
      break;
    case 0xe:
      uVar1 = MApi_AUDIO_GetAudioInfo2(uVar1,0x10,param_4);
    }
  }
  else {
    printf("%s: Err! AID is out of Range\n","MMA_getAudioInfo2");
    uVar1 = 0;
  }
  return uVar1;
}

