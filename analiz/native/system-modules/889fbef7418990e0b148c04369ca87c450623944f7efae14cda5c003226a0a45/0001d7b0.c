
nis_error nis_verifygroup(const_nis_name __group)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  nis_error *pnVar7;
  uint uVar8;
  undefined4 uVar9;
  nis_error nVar10;
  
  if ((__group != (const_nis_name)0x0) && (*__group != '\0')) {
    iVar3 = (*(code *)PTR_strlen_00035260)();
    uVar8 = iVar3 + 0x10U & 0xfffffff8;
    iVar1 = -(iVar3 + 0x40U & 0xfffffff8);
    uVar4 = (*(code *)PTR_nis_leaf_of_r_00035074)
                      (__group,&stack0xffffffd8 + (iVar1 - uVar8),iVar3 + 1);
    puVar5 = (undefined4 *)(*(code *)PTR_stpcpy_000352d4)(&stack0xffffffd8 + iVar1,uVar4);
    puVar2 = PTR_nis_domain_of_r_00035124;
    uVar4 = *(undefined4 *)(PTR_LAB_00035018 + 0x3c24);
    uVar9 = *(undefined4 *)(PTR_LAB_00035018 + 0x3c28);
    *puVar5 = *(undefined4 *)(PTR_LAB_00035018 + 0x3c20);
    puVar5[1] = uVar4;
    puVar5[2] = uVar9;
    pcVar6 = (char *)(*(code *)puVar2)(__group,&stack0xffffffd8 + uVar8 * -2 + iVar1,iVar3 + 1);
    puVar2 = PTR_strcpy_00035248;
    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
      *(undefined1 *)((int)puVar5 + 0xb) = 0x2e;
      (*(code *)puVar2)(puVar5 + 3,pcVar6);
    }
    pnVar7 = (nis_error *)(*(code *)PTR_nis_lookup_0003514c)(&stack0xffffffd8 + iVar1,0);
    nVar10 = *pnVar7;
    (*(code *)PTR_nis_freeresult_0003507c)(pnVar7);
    return nVar10;
  }
  return NIS_FAIL;
}

