
int sawman_config_init(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined4 auStack_38 [2];
  
  puVar12 = PTR_DAT_0002c048;
  piVar5 = (int *)PTR_sawman_config_0002c1c0;
  if (*(int *)PTR_sawman_config_0002c1c0 == 0) goto LAB_0001aa58;
  do {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    if (param_2 == (int *)0x0) {
      return 0;
    }
    iVar6 = *param_1;
    if (iVar6 < 2) {
      return 0;
    }
    iVar9 = *param_2;
    iVar7 = 1;
    puVar13 = PTR_DAT_0002c048 + -0x4328;
    puVar12 = PTR_DAT_0002c048 + -0x4318;
    iVar3 = iVar6;
LAB_0001a8b8:
    while( true ) {
      iVar10 = iVar7 * 4;
      piVar5 = *(int **)(iVar9 + iVar10);
      iVar1 = (*(code *)PTR_strcmp_0002c070)(piVar5,puVar13);
      if (iVar1 == 0) break;
      iVar1 = (*(code *)PTR_strncmp_0002c09c)(piVar5,puVar12,5);
      if (iVar1 != 0) goto LAB_0001a8a8;
      iVar6 = (*(code *)(PTR_DAT_0002c048 + -0x59b8))((undefined *)((int)piVar5 + 5));
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar7 = iVar7 + 1;
      iVar9 = *param_2;
      iVar6 = *param_1;
      *(undefined4 *)(iVar9 + iVar10) = 0;
      iVar3 = iVar6;
      if (iVar6 <= iVar7) goto LAB_0001a940;
    }
    (*(code *)PTR_fprintf_0002c104)
              (*(undefined4 *)PTR_stderr_0002c14c,*(undefined4 *)(PTR_DAT_0002c038 + -0x3fec));
    puVar12 = (undefined *)0x1;
    (*(code *)PTR_exit_0002c06c)(1);
LAB_0001aa58:
    iVar6 = (*(code *)PTR_getenv_0002c1cc)(puVar12 + -0x43a4);
    if (*piVar5 == 0) {
      piVar2 = (int *)(*(code *)PTR_calloc_0002c1c8)(1,0xf8);
      *piVar5 = (int)piVar2;
      puVar12 = PTR_DAT_0002c048;
      if (piVar2 == (int *)0x0) {
        (*(code *)PTR_direct_messages_warn_0002c114)
                  (PTR_DAT_0002c048 + -0x41e0,PTR_DAT_0002c048 + -0x439c,0x6f,
                   PTR_DAT_0002c048 + -0x438c);
        return 10;
      }
      *piVar2 = (int)(piVar2 + 1);
      iVar3 = *(int *)(puVar12 + -0x41d0);
      piVar2[1] = 4;
      piVar2[0xc] = iVar3;
      puVar12 = PTR_DAT_0002c048;
      piVar2[5] = *(int *)(PTR_DAT_0002c048 + -0x41b4);
      puVar13 = PTR_DAT_0002c048;
      piVar2[6] = *(int *)(puVar12 + -0x41b8);
      puVar12 = PTR_DAT_0002c048;
      piVar2[7] = *(int *)(puVar13 + -0x41bc);
      puVar13 = PTR_DAT_0002c048;
      piVar2[8] = *(int *)(puVar12 + -0x41c0);
      puVar12 = PTR_DAT_0002c048;
      piVar2[9] = *(int *)(puVar13 + -0x41c4);
      puVar13 = PTR_DAT_0002c048;
      piVar2[10] = *(int *)(puVar12 + -0x41c8);
      piVar2[0xb] = *(int *)(puVar13 + -0x41cc);
    }
    pcVar11 = (code *)(PTR_DAT_0002c048 + -0x5b60);
    iVar3 = (*pcVar11)(PTR_DAT_0002c048 + -0x437c);
    if ((iVar3 != 0) && (iVar3 != 0xf)) {
      return iVar3;
    }
    if (iVar6 != 0) {
      iVar3 = (*(code *)PTR_strlen_0002c140)(iVar6);
      (*(code *)PTR_snprintf_0002c074)
                (&stack0xffffffd0 + -(iVar3 + 0x19U & 0xfffffff8),iVar3 + 0xb,
                 PTR_DAT_0002c048 + -0x4368,iVar6);
      iVar3 = (*pcVar11)(&stack0xffffffd0 + -(iVar3 + 0x19U & 0xfffffff8));
      if ((iVar3 != 0) && (iVar3 != 0xf)) {
        return iVar3;
      }
    }
    pcVar8 = (char *)0x0;
    if ((((param_1 != (int *)0x0) && (*param_1 != 0)) && (param_2 != (int *)0x0)) &&
       ((undefined4 *)*param_2 != (undefined4 *)0x0)) {
      pcVar8 = *(char **)*param_2;
      iVar3 = (*(code *)PTR_strrchr_0002c1a4)(pcVar8,0x2f);
      if (iVar3 != 0) {
        pcVar8 = (char *)(iVar3 + 1);
      }
      if ((pcVar8 != (char *)0x0) && (*pcVar8 != '\0')) {
        iVar3 = (*(code *)PTR_strlen_0002c140)(pcVar8);
        (*(code *)PTR_snprintf_0002c074)
                  (&stack0xffffffd0 + -(iVar3 + 0x20U & 0xfffffff8),iVar3 + 0x12,
                   PTR_DAT_0002c048 + -0x4358,pcVar8);
        iVar3 = (*pcVar11)(&stack0xffffffd0 + -(iVar3 + 0x20U & 0xfffffff8));
        if ((iVar3 != 0) && (iVar3 != 0xf)) {
          return iVar3;
        }
      }
    }
    if (((iVar6 != 0) && (pcVar8 != (char *)0x0)) && (*pcVar8 != '\0')) {
      iVar7 = (*(code *)PTR_strlen_0002c140)(iVar6);
      iVar9 = (*(code *)PTR_strlen_0002c140)(pcVar8);
      iVar3 = -(iVar7 + iVar9 + 0x1aU & 0xfffffff8);
      *(char **)((int)auStack_38 + iVar3) = pcVar8;
      (*(code *)PTR_snprintf_0002c074)
                (&stack0xffffffd0 + iVar3,iVar7 + iVar9 + 0xc,PTR_DAT_0002c048 + -0x4344,iVar6);
      iVar6 = (*pcVar11)(&stack0xffffffd0 + iVar3);
      if ((iVar6 != 0) && (iVar6 != 0xf)) {
        return iVar6;
      }
    }
    iVar6 = (*(code *)PTR_getenv_0002c1cc)(PTR_DAT_0002c048 + -0x4334);
    if ((iVar6 != 0) && (iVar6 = (*(code *)(PTR_DAT_0002c048 + -0x59b8))(iVar6), iVar6 != 0)) {
      return iVar6;
    }
  } while( true );
LAB_0001a8a8:
  iVar7 = iVar7 + 1;
  if (iVar6 <= iVar7) {
LAB_0001a940:
    if (iVar6 < 2) {
      return 0;
    }
    iVar7 = 1;
    goto LAB_0001a950;
  }
  goto LAB_0001a8b8;
LAB_0001a950:
  piVar5 = (int *)(iVar9 + iVar7 * 4);
  iVar1 = iVar7;
  do {
    if (*piVar5 != 0) break;
    iVar1 = iVar1 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar1 < iVar3);
  if (iVar7 < iVar1) {
    iVar10 = (iVar1 - iVar7) + iVar7;
    if (iVar10 < iVar3) {
      iVar4 = iVar7 << 2;
      iVar3 = iVar10 * 4;
      iVar6 = *param_1;
      do {
        iVar10 = iVar10 + 1;
        *(undefined4 *)(iVar9 + iVar4) = *(undefined4 *)(iVar9 + iVar3);
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 4;
      } while (iVar10 < iVar6);
    }
    iVar6 = iVar6 - (iVar1 - iVar7);
    *param_1 = iVar6;
  }
  else {
    iVar6 = *param_1;
  }
  iVar7 = iVar7 + 1;
  iVar3 = iVar6;
  if (iVar6 <= iVar7) {
    return 0;
  }
  goto LAB_0001a950;
}

