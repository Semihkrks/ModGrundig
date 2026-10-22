
/* MSrv_Control_Customer::StartBackRoundUpdate() */

void __thiscall MSrv_Control_Customer::StartBackRoundUpdate(MSrv_Control_Customer *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1b4);
  if (iVar1 == 1) {
                    /* WARNING: Could not recover jumptable at 0x2f1caa20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_PostEvent_2f1e3810)(this,0,0xc000001d,0);
    return;
  }
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x2f1caa38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_PostEvent_2f1e3810)(this,0,0xc0000044,0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x2f1caa50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_PostEvent_2f1e3810)(this,0,0xc000001e,0);
  return;
}

