
/* ArAudioManager::GetAudioDescriptionVolume() */

undefined1 ArAudioManager::GetAudioDescriptionVolume(void)

{
  int *piVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  int in_t9;
  int iVar2;
  undefined1 auStack_2e8 [145];
  undefined1 uStack_257;
  
  iVar2 = in_t9 + 0xc05a54;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc04d74))();
  (**(code **)(*piVar1 + 0xd4))(piVar1,auStack_2e8,in_a2,in_a3,iVar2);
  return uStack_257;
}

