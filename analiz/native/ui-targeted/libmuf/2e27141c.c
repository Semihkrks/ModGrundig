
/* GetRcEngine::RcGetNum(unsigned int) */

uint GetRcEngine::RcGetNum(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  code *pcVar10;
  code *pcVar11;
  
  if (*(int *)PTR_pkg_2e2b3a44 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e27144c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_GetNum_2e2b3f50)(*(int *)PTR_pkg_2e2b3a44,param_1);
    return uVar1;
  }
  puVar4 = PTR_PTR_2e2b3908 + -0x73a0;
  (*(code *)PTR_printf_2e2b3ee0)(puVar4,PTR_PTR_2e2b3908 + -0x228c,PTR_PTR_2e2b3908 + -0x21d0,0xd6);
  puVar9 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  if (**(int **)(puVar9 + 0x425bc) != 0) {
    iVar2 = (**(code **)(puVar9 + 0x43218))(**(int **)(puVar9 + 0x425bc),puVar4);
    return (uint)(iVar2 != 0);
  }
  iVar2 = *(int *)(puVar9 + 0x42480) + -0x73a0;
  puVar5 = (undefined4 *)(*(int *)(puVar9 + 0x42480) + -0x228c);
  (**(code **)(puVar9 + 0x42a58))(iVar2,puVar5,*(int *)(puVar9 + 0x42480) + -0x21a0,0xd0);
  pcVar10 = *(code **)(puVar9 + 0x42740);
  (*pcVar10)();
  piVar3 = *(int **)(pcVar10 + 0x42540);
  if (*piVar3 == 0) {
    iVar2 = *(int *)(pcVar10 + 0x42404);
    iVar6 = *(int *)(pcVar10 + 0x42404);
    iVar7 = *(int *)(pcVar10 + 0x42404);
    pcVar11 = *(code **)(pcVar10 + 0x429dc);
    uVar8 = 0xc3;
    goto LAB_2e271578;
  }
  pcVar11 = *(code **)(pcVar10 + 0x42ef4);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0;
  }
  uVar1 = (*pcVar11)(*piVar3,iVar2);
  if (uVar1 != 0) {
    return uVar1;
  }
  do {
    iVar2 = *(int *)(pcVar10 + 0x42404);
    iVar6 = *(int *)(pcVar10 + 0x42404);
    iVar7 = *(int *)(pcVar10 + 0x42404);
    pcVar11 = *(code **)(pcVar10 + 0x429dc);
    uVar8 = 0xca;
LAB_2e271578:
    (*pcVar11)(iVar2 + -0x73a0,iVar6 + -0x228c,iVar7 + -0x216c,uVar8);
    (**(code **)(pcVar10 + 0x426c4))();
  } while( true );
}

