
/* MSrv_Control_Customer::IsStandbyUpdateStarted() */

void MSrv_Control_Customer::IsStandbyUpdateStarted(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_GetMSrvSystemDatabase_2f1e3878)();
                    /* WARNING: Could not recover jumptable at 0x2f1c8a38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x120))(piVar1);
  return;
}

