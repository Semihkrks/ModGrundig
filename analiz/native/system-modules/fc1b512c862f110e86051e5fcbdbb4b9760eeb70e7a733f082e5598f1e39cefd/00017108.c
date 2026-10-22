
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MDMPPlayer_VolumeUp() */

void MDMPPlayer_VolumeUp(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_GetInstance_00033294)();
                    /* WARNING: Could not recover jumptable at 0x00017140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x40))(piVar1);
  return;
}

