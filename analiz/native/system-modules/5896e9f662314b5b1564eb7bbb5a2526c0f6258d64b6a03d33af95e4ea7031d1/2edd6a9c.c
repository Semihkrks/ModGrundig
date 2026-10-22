
/* CABLE_FREQ_RANGE::Init() */

void __thiscall CABLE_FREQ_RANGE::Init(CABLE_FREQ_RANGE *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 8);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2edd6ac8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_operator_delete_2edf4cac)(iVar1);
    return;
  }
  return;
}

