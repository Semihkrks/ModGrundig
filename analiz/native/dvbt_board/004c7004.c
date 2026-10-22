
/* ArAudioManager::SetScartOutVolume(unsigned char) */

void ArAudioManager::SetScartOutVolume(uchar param_1)

{
  int *piVar1;
  undefined1 in_a1;
  undefined4 in_a2;
  undefined4 in_a3;
  int in_t9;
  int iVar2;
  
  iVar2 = in_t9 + 0xc0530c;
  piVar1 = (int *)(**(code **)(in_t9 + 0xc043d4))();
  (**(code **)(*piVar1 + 0x98))(piVar1,in_a1,in_a2,in_a3,iVar2);
  return;
}

