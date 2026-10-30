
/* mapi_audio_customer::OpenAudioDec(AudioSDKDecStatus*) */

undefined4 __thiscall
mapi_audio_customer::OpenAudioDec(mapi_audio_customer *this,AudioSDKDecStatus *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  
  if ((param_1 != (AudioSDKDecStatus *)0x0) &&
     ((((((iVar2 = *(int *)(param_1 + 8), iVar2 == 1 || (iVar2 == 0x1c)) || (iVar2 == 0x25)) ||
        ((iVar2 == 0x17 || (iVar2 == 0x18)))) ||
       ((iVar2 == 0x19 || ((iVar2 == 0x1a || (iVar2 == 0x1e)))))) ||
      ((iVar2 == 0x22 || (iVar2 == 0x26)))))) {
    local_38 = (uint)(byte)*param_1 << 0x18;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_28 = FUN_2dc6625c(*(undefined4 *)(param_1 + 0xc));
    local_2c = (**(code **)(*(int *)this + 0x13c))(this,*(undefined4 *)(param_1 + 8));
    local_34 = 1;
    if ((*(int *)(param_1 + 4) != 1) && (local_34 = 0, *(int *)(param_1 + 4) == 2)) {
      local_34 = 2;
    }
    local_24 = 0;
    if ((*(int *)(param_1 + 0x10) != 0) && (local_24 = 4, *(int *)(param_1 + 0x10) == 1)) {
      local_24 = 1;
    }
    local_1c = (uint)(*(int *)(param_1 + 0x14) == 1);
    uVar1 = MApi_AUDIO_OpenDecodeSystem(&local_38);
    uVar1 = FUN_2dc63550(uVar1);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    return uVar1;
  }
  return 0xffffffff;
}

