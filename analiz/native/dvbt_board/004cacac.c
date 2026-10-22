
/* ArAudioManager::MainVolumeDown(unsigned long) */

undefined4 __thiscall ArAudioManager::MainVolumeDown(ArAudioManager *this,ulong param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  undefined1 auStack_2f0 [121];
  byte bStack_277;
  char cStack_276;
  int iStack_180;
  int iStack_178;
  int iStack_c;
  
  piVar1 = (int *)(**(code **)(in_t9 + 0xc00984))();
  (**(code **)(*piVar1 + 0xd8))(piVar1,auStack_2f0);
  bStack_277 = bStack_277 - (char)param_1;
  if (99 < bStack_277) {
    bStack_277 = 0;
  }
  if (iStack_178 != 0) goto LAB_004cade8;
  if (iStack_180 == 2) {
    uVar2 = (**(code **)(in_t9 + 0xc00984))();
    iVar3 = (**(code **)(in_t9 + 0xbfd998))(uVar2);
    if (iVar3 == 0) goto LAB_004cad90;
    iStack_c = 1;
  }
  else {
LAB_004cad90:
    iStack_c = 0;
  }
  if (iStack_c != 0) {
    if (cStack_276 != '\0') {
      cStack_276 = cStack_276 + -1;
    }
    (**(code **)(in_t9 + 0xbfbc84))(this,cStack_276);
    return 1;
  }
LAB_004cade8:
  piVar1 = (int *)(**(code **)(in_t9 + 0xc00984))();
  (**(code **)(*piVar1 + 0x1c8))(piVar1,auStack_2f0,0);
  piVar1 = (int *)(**(code **)(in_t9 + 0xc0072c))();
  uVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,bStack_277);
  return uVar2;
}

