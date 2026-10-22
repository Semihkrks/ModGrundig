
/* GetRcEngine::RcGetString(unsigned int) */

void GetRcEngine::RcGetString(uint param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  if (*(int *)PTR_pkg_2e2b3a44 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2717f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_GetString_2e2b3cac)(*(int *)PTR_pkg_2e2b3a44,param_1);
    return;
  }
  puVar1 = (undefined4 *)(PTR_PTR_2e2b3908 + -0x73a0);
  (*(code *)PTR_printf_2e2b3ee0)(puVar1,PTR_PTR_2e2b3908 + -0x228c,PTR_PTR_2e2b3908 + -0x2074,0x9f);
  puVar2 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  if (**(int **)(puVar2 + 0x42218) != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e271850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(puVar2 + 0x4268c))(**(int **)(puVar2 + 0x42218),*puVar1);
    return;
  }
  return;
}

