
/* GetRcEngine::RcGetNum(unsigned int) */

void GetRcEngine::RcGetNum(uint param_1)

{
  if (*(int *)PTR_pkg_2e2b3a44 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e27144c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_GetNum_2e2b3f50)(*(int *)PTR_pkg_2e2b3a44,param_1);
    return;
  }
  (*(code *)PTR_printf_2e2b3ee0)
            (PTR_PTR_2e2b3908 + -0x73a0,PTR_PTR_2e2b3908 + -0x228c,PTR_PTR_2e2b3908 + -0x21d0,0xd6);
                    /* WARNING: Subroutine does not return */
  (*(code *)PTR_abort_2e2b3bc8)();
}

