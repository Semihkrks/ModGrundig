
/* MSrv_Control_common::UpdatePQiniFiles() */

void MSrv_Control_common::UpdatePQiniFiles(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_GetInstance_2eace018)();
                    /* WARNING: Could not recover jumptable at 0x2eaa38b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_UpdatePQiniFiles_2eacd538)(uVar1);
  return;
}

