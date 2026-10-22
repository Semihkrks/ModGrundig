
undefined4
_nss_hesiod_initgroups_dyn
          (undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int *piVar12;
  char *pcVar13;
  int *piVar14;
  char *local_38 [2];
  int local_30;
  undefined4 *local_2c;
  
  piVar14 = (int *)*param_5;
  iVar3 = (*(code *)PTR_FUN_00024030)();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  local_2c = (undefined4 *)(*(code *)PTR_LAB_00024020)(iVar3,param_1,PTR_00024014 + 0x3c04);
  if (local_2c == (undefined4 *)0x0) {
    (*(code *)PTR_LAB_0002402c)(iVar3);
    piVar14 = (int *)(*(code *)PTR___errno_location_000240d4)();
    if (*piVar14 == 2) {
      return 0;
    }
    return 0xffffffff;
  }
  iVar8 = *param_3;
  if (iVar8 < 1) {
LAB_00011f3c:
    if (iVar8 == *param_4) {
      iVar11 = iVar8 << 1;
      if (0 < param_6) {
        if (iVar8 == param_6) goto LAB_00012088;
        iVar11 = param_6;
        if (iVar8 << 1 < param_6) {
          iVar11 = iVar8 << 1;
        }
      }
      piVar14 = (int *)(*(code *)PTR_realloc_000240c4)(piVar14,iVar11 << 2);
      if (piVar14 == (int *)0x0) goto LAB_00012088;
      *param_4 = iVar11;
      iVar8 = *param_3;
      *param_5 = (int)piVar14;
    }
    piVar14[iVar8] = param_2;
    *param_3 = iVar8 + 1;
  }
  else {
    iVar4 = *piVar14;
    piVar5 = piVar14;
    iVar11 = iVar8;
    while (iVar4 != param_2) {
      iVar11 = iVar11 + -1;
      piVar5 = piVar5 + 1;
      if (iVar11 < 1) goto LAB_00011f3c;
      iVar4 = *piVar5;
    }
  }
  piVar5 = (int *)(*(code *)PTR___errno_location_000240d4)();
  local_30 = *piVar5;
  cVar1 = *(char *)*local_2c;
  pcVar9 = (char *)*local_2c;
joined_r0x00011f8c:
  if (cVar1 == '\0') goto LAB_00012080;
  pcVar13 = pcVar9;
  if ((cVar1 == ':') || (cVar1 == ',')) {
LAB_000120e4:
    *pcVar13 = '\0';
    pcVar13 = pcVar13 + 1;
  }
  else {
    pcVar13 = pcVar9 + 1;
    cVar1 = pcVar9[1];
    while (cVar1 != '\0') {
      if ((cVar1 == ':') || (cVar1 == ',')) goto LAB_000120e4;
      pcVar13 = pcVar13 + 1;
      cVar1 = *pcVar13;
    }
  }
  puVar2 = PTR_strtol_000240a8;
  *piVar5 = 0;
  iVar8 = (*(code *)puVar2)(pcVar9,local_38,10);
  if (*piVar5 != 0) goto LAB_00012074;
  if ((*local_38[0] != '\0') || (pcVar9 == local_38[0])) {
    puVar7 = (undefined4 *)(*(code *)PTR_LAB_00024020)(iVar3,pcVar9,PTR_00024014 + 0x3c0c);
    if (puVar7 == (undefined4 *)0x0) goto LAB_00012074;
    pcVar9 = (char *)*puVar7;
    if (pcVar9 != (char *)0x0) {
      for (; *pcVar9 != '\0'; pcVar9 = pcVar9 + 1) {
        if (*pcVar9 == ':') goto LAB_0001215c;
      }
      goto LAB_00012148;
    }
    cVar1 = *pcVar13;
    pcVar9 = pcVar13;
    goto joined_r0x00011f8c;
  }
  iVar11 = *param_3;
  if (0 < iVar11) {
    iVar6 = *piVar14;
    iVar4 = iVar11;
    piVar12 = piVar14;
    while (iVar8 != iVar6) {
      iVar4 = iVar4 + -1;
      piVar12 = piVar12 + 1;
      if (iVar4 < 1) goto LAB_0001204c;
      iVar6 = *piVar12;
    }
    goto LAB_00012074;
  }
LAB_0001204c:
  if (iVar11 == *param_4) {
    iVar4 = iVar11 << 1;
    if (0 < param_6) {
      if (param_6 == iVar11) goto LAB_00012088;
      iVar4 = param_6;
      if (iVar11 << 1 < param_6) {
        iVar4 = iVar11 << 1;
      }
    }
    piVar14 = (int *)(*(code *)PTR_realloc_000240c4)(piVar14,iVar4 << 2);
    if (piVar14 == (int *)0x0) goto LAB_00012088;
    *param_4 = iVar4;
    iVar11 = *param_3;
    *param_5 = (int)piVar14;
  }
  piVar14[iVar11] = iVar8;
  *param_3 = iVar11 + 1;
  goto LAB_00012074;
LAB_0001215c:
  do {
    pcVar9 = pcVar9 + 1;
  } while (*pcVar9 == ':');
  if (*pcVar9 != '\0') {
    do {
      pcVar10 = pcVar9;
      cVar1 = pcVar10[1];
      if (cVar1 == '\0') goto LAB_00012148;
      pcVar9 = pcVar10 + 1;
    } while (cVar1 != ':');
    do {
      pcVar9 = pcVar10 + 3;
      if (pcVar10[2] != ':') break;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar9 == ':');
  }
LAB_00012148:
  (*(code *)PTR_LAB_0002401c)(iVar3,puVar7);
LAB_00012074:
  cVar1 = *pcVar13;
  pcVar9 = pcVar13;
  goto joined_r0x00011f8c;
LAB_00012080:
  *piVar5 = local_30;
LAB_00012088:
  (*(code *)PTR_LAB_0002401c)(iVar3,local_2c);
  (*(code *)PTR_LAB_0002402c)(iVar3);
  return 1;
}

