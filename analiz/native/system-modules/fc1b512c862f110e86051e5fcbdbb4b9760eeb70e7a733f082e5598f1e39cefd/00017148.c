
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MDMPPlayer_ToggleMute() */

void MDMPPlayer_ToggleMute(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_GetInstance_00033294)();
                    /* WARNING: Could not recover jumptable at 0x00017180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x30))(piVar1);
  return;
}

