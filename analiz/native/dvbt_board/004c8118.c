
/* ArAudioManager::SetAudioDescriptionVolume(unsigned long) */

void __thiscall ArAudioManager::SetAudioDescriptionVolume(ArAudioManager *this,ulong param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_t9;
  undefined1 auStack_2e8 [145];
  undefined1 uStack_257;
  
  uVar1 = (**(code **)(in_t9 + 0xc032c0))();
  (**(code **)(in_t9 + 0xc013e0))(uVar1,param_1 & 0xff);
  piVar2 = (int *)(**(code **)(in_t9 + 0xc03518))();
  (**(code **)(*piVar2 + 0xd4))(piVar2,auStack_2e8);
  uStack_257 = (undefined1)param_1;
  piVar2 = (int *)(**(code **)(in_t9 + 0xc03518))();
  (**(code **)(*piVar2 + 0x1c4))(piVar2,auStack_2e8);
  return;
}

