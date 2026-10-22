
/* ArAudioManager::SetVRHeadphoneVolumeVolume(unsigned long) */

void __thiscall ArAudioManager::SetVRHeadphoneVolumeVolume(ArAudioManager *this,ulong param_1)

{
  int *piVar1;
  int in_t9;
  undefined1 auStack_2e8 [125];
  undefined1 uStack_26b;
  
  (**(code **)(in_t9 + 0xc029ec))(*(int *)(in_t9 + 0xbfce10) + 0x2758,param_1);
  piVar1 = (int *)(**(code **)(in_t9 + 0xc0410c))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2e8);
  uStack_26b = (undefined1)param_1;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc0410c))();
  (**(code **)(*piVar1 + 0x1c8))(piVar1,auStack_2e8,0);
  return;
}

