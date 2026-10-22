
/* MSrv_Control_Customer::GetIRPowerOnKey() */

void MSrv_Control_Customer::GetIRPowerOnKey(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_Get_mapi_system_2f1e3aa0)();
                    /* WARNING: Could not recover jumptable at 0x2f1caf24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_GetIRPowerOnKey_2f1e3a14)(uVar1);
  return;
}

