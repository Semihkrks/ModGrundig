
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MDMPPlayer_GetMuteFlag() */

void MDMPPlayer_GetMuteFlag(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_GetInstance_00033294)();
  (**(code **)(*piVar1 + 0x28))(piVar1);
  return;
}

