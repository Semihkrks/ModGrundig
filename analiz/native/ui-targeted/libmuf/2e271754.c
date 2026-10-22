
/* GetRcEngine::RcGetColor(unsigned int) */

void GetRcEngine::RcGetColor(uint param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  code *pcVar4;
  
  if (*(int *)PTR_pkg_2e2b3a44 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e271784. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_GetColor_2e2b497c)(*(int *)PTR_pkg_2e2b3a44,param_1);
    return;
  }
  puVar1 = PTR_PTR_2e2b3908 + -0x73a0;
  (*(code *)PTR_printf_2e2b3ee0)(puVar1,PTR_PTR_2e2b3908 + -0x228c,PTR_PTR_2e2b3908 + -0x20b0,0xa7);
  puVar3 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  if (**(int **)(puVar3 + 0x42284) != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2717f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(puVar3 + 0x424ec))(**(int **)(puVar3 + 0x42284),puVar1);
    return;
  }
  puVar2 = (undefined4 *)(*(int *)(puVar3 + 0x42148) + -0x73a0);
  (**(code **)(puVar3 + 0x42720))
            (puVar2,*(int *)(puVar3 + 0x42148) + -0x228c,*(int *)(puVar3 + 0x42148) + -0x2074,0x9f);
  pcVar4 = *(code **)(puVar3 + 0x42408);
  (*pcVar4)();
  if (**(int **)(pcVar4 + 0x42218) != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e271850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(pcVar4 + 0x4268c))(**(int **)(pcVar4 + 0x42218),*puVar2);
    return;
  }
  return;
}

