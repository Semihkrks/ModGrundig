
/* ArAudioManager::SetHeadphoneVolume(unsigned char) */

void __thiscall ArAudioManager::SetHeadphoneVolume(ArAudioManager *this,uchar param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_t9;
  undefined1 auStack_2e8 [122];
  uchar uStack_26e;
  
  piVar1 = (int *)(**(code **)(in_t9 + 0xc00f0c))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2e8);
  uStack_26e = param_1;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc00f0c))();
  (**(code **)(*piVar1 + 0x1c8))(piVar1,auStack_2e8,0);
  uVar2 = (**(code **)(in_t9 + 0xc00cb4))();
  (**(code **)(in_t9 + 0xbfd028))(uVar2,uStack_26e);
  return;
}

