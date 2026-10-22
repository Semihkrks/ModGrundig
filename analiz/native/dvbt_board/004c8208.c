
/* ArAudioManager::SetMute(unsigned char) */

void __thiscall ArAudioManager::SetMute(ArAudioManager *this,uchar param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_t9;
  undefined1 auStack_2e8 [368];
  int iStack_178;
  
  uVar1 = (**(code **)(in_t9 + 0xc031d0))();
  (**(code **)(in_t9 + 0xc012c4))(uVar1,4,param_1,0);
  piVar2 = (int *)(**(code **)(in_t9 + 0xc03428))();
  (**(code **)(*piVar2 + 0xd8))(piVar2,auStack_2e8);
  if (iStack_178 == 2) {
    uVar1 = (**(code **)(in_t9 + 0xc031d0))();
    (**(code **)(in_t9 + 0xc012c4))(uVar1,0x8000,0,0);
  }
  else {
    uVar1 = (**(code **)(in_t9 + 0xc031d0))();
    (**(code **)(in_t9 + 0xc012c4))(uVar1,0x8000,param_1,0);
  }
  return;
}

