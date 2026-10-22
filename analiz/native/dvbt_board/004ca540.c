
/* ArAudioManager::GetMainVolume() */

undefined1 ArAudioManager::GetMainVolume(void)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_t9;
  undefined1 auStack_2f0 [121];
  undefined1 uStack_277;
  undefined1 uStack_276;
  int iStack_180;
  int iStack_178;
  
  piVar2 = (int *)(**(code **)(in_t9 + 0xc010f0))();
  (**(code **)(*piVar2 + 0xd8))(piVar2,auStack_2f0);
  if (iStack_178 != 0) {
    return uStack_277;
  }
  if (iStack_180 == 2) {
    uVar3 = (**(code **)(in_t9 + 0xc010f0))();
    iVar4 = (**(code **)(in_t9 + 0xbfe104))(uVar3);
    if (iVar4 != 0) {
      bVar1 = true;
      goto LAB_004ca5f8;
    }
  }
  bVar1 = false;
LAB_004ca5f8:
  if (bVar1) {
    uStack_277 = uStack_276;
  }
  return uStack_277;
}

