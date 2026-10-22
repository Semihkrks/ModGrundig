
/* ArAudioManager::SetMainVolume(unsigned char) */

void __thiscall ArAudioManager::SetMainVolume(ArAudioManager *this,uchar param_1)

{
  int *piVar1;
  int in_t9;
  undefined1 auStack_2e8 [121];
  uchar uStack_26f;
  
  piVar1 = (int *)(**(code **)(in_t9 + 0xc045b0))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2e8);
  uStack_26f = param_1;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc045b0))();
  (**(code **)(*piVar1 + 0x1c8))(piVar1,auStack_2e8,0);
  piVar1 = (int *)(**(code **)(in_t9 + 0xc04358))();
  (**(code **)(*piVar1 + 0x3c))(piVar1,uStack_26f);
  return;
}

