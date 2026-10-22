
/* ArAudioManager::GetHeadphoneVolume() */

undefined1 ArAudioManager::GetHeadphoneVolume(void)

{
  int *piVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  int in_t9;
  int iVar2;
  undefined1 auStack_2e8 [122];
  undefined1 uStack_26e;
  
  iVar2 = in_t9 + 0xc05824;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc04b44))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2e8,in_a2,in_a3,iVar2);
  return uStack_26e;
}

