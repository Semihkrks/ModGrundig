
/* MSrv_Control_common::QueryPowerOnMode() */

void MSrv_Control_common::QueryPowerOnMode(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_Get_mapi_system_2eace0dc)();
                    /* WARNING: Could not recover jumptable at 0x2eaa64a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_QueryPowerOnMode_2eacd798)(uVar1);
  return;
}

