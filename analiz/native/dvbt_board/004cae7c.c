
/* ArAudioManager::MainVolumeUp(unsigned long) */

undefined4 __thiscall ArAudioManager::MainVolumeUp(ArAudioManager *this,ulong param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_t9;
  undefined1 auStack_2f4 [121];
  byte bStack_27b;
  byte bStack_27a;
  int iStack_184;
  int iStack_17c;
  int iStack_18;
  int iStack_10;
  
  piVar2 = (int *)(**(code **)(in_t9 + 0xc007b4))();
  (**(code **)(*piVar2 + 0xd8))(piVar2,auStack_2f4);
  bStack_27b = bStack_27b + (char)param_1;
  if (100 < bStack_27b) {
    bStack_27b = 100;
  }
  (**(code **)(in_t9 + 0xc021e8))(this,0);
  if (iStack_17c == 0) {
    if (iStack_184 == 2) {
      uVar3 = (**(code **)(in_t9 + 0xc007b4))();
      iVar4 = (**(code **)(&LAB_00bfd7c8 + in_t9))(uVar3);
      if (iVar4 == 0) goto LAB_004caf7c;
      iStack_10 = 1;
    }
    else {
LAB_004caf7c:
      iStack_10 = 0;
    }
    if (iStack_10 != 0) {
      if (bStack_27a < 100) {
        bStack_27a = bStack_27a + 1;
      }
      (**(code **)(in_t9 + 0xbfbab4))(this,bStack_27a);
      return 1;
    }
  }
  uVar3 = (**(code **)(in_t9 + 0xc007b4))();
  iVar4 = (**(code **)(in_t9 + 0xc0169c))(uVar3);
  if (iVar4 != 0) {
    uVar3 = (**(code **)(in_t9 + 0xc007b4))();
    iVar4 = (**(code **)(in_t9 + 0xbfc840))(uVar3);
    if (iVar4 == 0) {
      iStack_18 = 1;
      goto LAB_004cb044;
    }
  }
  iStack_18 = 0;
LAB_004cb044:
  if (iStack_18 != 0) {
    uVar3 = (**(code **)(in_t9 + 0xc007b4))();
    bVar1 = (**(code **)(in_t9 + 0xc010ac))(uVar3);
    if (bVar1 < bStack_27b) {
      bStack_27b = bVar1;
    }
  }
  piVar2 = (int *)(**(code **)(in_t9 + 0xc007b4))();
  (**(code **)(*piVar2 + 0x1c8))(piVar2,auStack_2f4,0);
  piVar2 = (int *)(**(code **)(in_t9 + 0xc0055c))();
  uVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2,bStack_27b);
  return uVar3;
}

