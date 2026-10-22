
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MDMPPlayer_VolumeDown() */

void MDMPPlayer_VolumeDown(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_GetInstance_00033294)();
                    /* WARNING: Could not recover jumptable at 0x00017100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x44))(piVar1);
  return;
}

