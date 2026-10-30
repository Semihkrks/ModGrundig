
/* mapi_audio_customer::SetAudioDec(MMA_AUDIO_DEC_ID, AudioSDKDecStatus*) */

undefined4 __thiscall
mapi_audio_customer::SetAudioDec(mapi_audio_customer *this,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_24;
  
  if (((param_3 != 0) && (param_2 != -1)) && (param_2 != 3)) {
    uVar1 = FUN_2dc634d8(param_2);
    MApi_AUDIO_GetDecodeSystem(uVar1,auStack_40);
    local_30 = FUN_2dc6625c(*(undefined4 *)(param_3 + 0xc));
    local_3c = 1;
    local_24 = (uint)(*(int *)(param_3 + 0x14) == 1);
    if ((*(int *)(param_3 + 4) != 1) && (local_3c = 0, *(int *)(param_3 + 4) == 2)) {
      local_3c = 2;
    }
    local_34 = (**(code **)(*(int *)this + 0x13c))(this,*(undefined4 *)(param_3 + 8));
    if (*(int *)(param_3 + 0x10) == 0) {
      local_2c = 0;
      uVar1 = FUN_2dc634d8(param_2);
      MApi_AUDIO_SetDecodeSystem(uVar1,auStack_40);
    }
    else {
      local_2c = 4;
      if (*(int *)(param_3 + 0x10) == 1) {
        local_2c = 1;
      }
      uVar1 = FUN_2dc634d8(param_2);
      MApi_AUDIO_SetDecodeSystem(uVar1,auStack_40);
    }
    return 1;
  }
  return 0;
}

