
/* MSrv_Control_common::UpdatePQParameterViaUsbKey() */

void MSrv_Control_common::UpdatePQParameterViaUsbKey(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_GetInstance_2eace018)();
                    /* WARNING: Could not recover jumptable at 0x2eaa3948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_UpdatePQParameterViaUsbKey_2eacd540)(uVar1);
  return;
}

