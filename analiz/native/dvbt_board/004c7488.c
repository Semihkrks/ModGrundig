
/* ArAudioManager::GetVRHeadphoneVolumeVolume() */

undefined1 ArAudioManager::GetVRHeadphoneVolumeVolume(void)

{
  int *piVar1;
  int in_t9;
  undefined1 auStack_2e8 [125];
  undefined1 uStack_26b;
  
  piVar1 = (int *)(**(code **)(in_t9 + 0xc041a8))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2e8);
  (**(code **)(in_t9 + 0xc02a88))(*(int *)(in_t9 + 0xbfceac) + 0x2730,uStack_26b);
  return uStack_26b;
}

