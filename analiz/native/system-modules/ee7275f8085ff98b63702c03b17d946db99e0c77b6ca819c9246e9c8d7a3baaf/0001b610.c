
int _nss_nisplus_initgroups_dyn
              (undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6,
              undefined4 *param_7)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_58 [16];
  undefined4 auStack_48 [2];
  char *local_38 [2];
  undefined1 *local_30;
  char **local_2c;
  
  puVar11 = PTR_DAT_0002d024;
  if ((*(int *)PTR_DAT_0002d024 == 0) && (iVar5 = (*(code *)PTR_FUN_0002d030)(param_7), iVar5 != 1))
  {
    return iVar5;
  }
  iVar1 = (*(code *)PTR_strlen_0002d0a0)(param_1);
  iVar3 = *(int *)PTR_DAT_0002d028;
  iVar5 = -(iVar1 + iVar3 + 0x1aU & 0xfffffff8);
  puVar12 = auStack_58 + iVar5;
  *(undefined4 *)((int)auStack_48 + iVar5) = *(undefined4 *)puVar11;
  (*(code *)PTR_snprintf_0002d058)
            (&stack0xffffffc0 + iVar5,iVar1 + iVar3 + 0xc,PTR_DAT_0002d018 + -0x3e4c,param_1);
  puVar2 = (uint *)(*(code *)PTR_nis_list_0002d054)(&stack0xffffffc0 + iVar5,0xb,0,0);
  if (puVar2 == (uint *)0x0) {
    *param_7 = 0xc;
    iVar5 = -2;
  }
  else {
    iVar5 = -1;
    if ((*puVar2 < *(uint *)PTR___niserr2nss_count_0002d01c) &&
       (iVar5 = *(int *)(PTR___niserr2nss_tab_0002d020 + *puVar2 * 4), iVar5 == 1)) {
      uVar6 = puVar2[1];
      if (uVar6 == 0) {
LAB_0001b868:
        (*(code *)PTR_nis_freeresult_0002d0e8)(puVar2);
        return 0;
      }
      uVar9 = puVar2[2];
      puVar11 = PTR_DAT_0002d018 + -0x3f24;
      local_2c = local_38;
      iVar5 = *param_5;
      uVar10 = 0;
      do {
        if (((*(int *)(uVar9 + 0x20) == 5) &&
            (iVar1 = (*(code *)PTR_strcmp_0002d050)(*(undefined4 *)(uVar9 + 0x24),puVar11),
            iVar1 == 0)) && (3 < *(uint *)(uVar9 + 0x28))) {
          iVar1 = *(int *)(*(int *)(uVar9 + 0x2c) + 0x1c);
          pcVar4 = *(char **)(*(int *)(uVar9 + 0x2c) + 0x20);
          if ((iVar1 != 0) && (*pcVar4 != '\0')) {
            if (pcVar4[iVar1 + -1] == '\0') {
              iVar1 = (*(code *)PTR_strtoul_0002d0a4)(pcVar4,local_2c,10);
              if (*local_38[0] == '\0') {
LAB_0001b7d8:
                if (iVar1 != param_2) {
                  iVar3 = *param_3;
                  if (iVar3 == *param_4) {
                    iVar7 = iVar3 << 1;
                    if (0 < param_6) {
                      if (iVar3 == param_6) break;
                      iVar7 = param_6;
                      if (iVar3 << 1 < param_6) {
                        iVar7 = iVar3 << 1;
                      }
                    }
                    iVar5 = (*(code *)PTR_realloc_0002d0ec)(iVar5,iVar7 << 2);
                    if (iVar5 == 0) goto LAB_0001b868;
                    *param_4 = iVar7;
                    iVar3 = *param_3;
                    *param_5 = iVar5;
                  }
                  *(int *)(iVar5 + iVar3 * 4) = iVar1;
                  uVar6 = puVar2[1];
                  *param_3 = iVar3 + 1;
                  goto LAB_0001b74c;
                }
              }
              uVar6 = puVar2[1];
            }
            else {
              puVar8 = puVar12 + (0x18 - (iVar1 + 0xfU & 0xfffffff8));
              local_30 = puVar12;
              (*(code *)PTR_memcpy_0002d0a8)(puVar8,pcVar4,iVar1);
              puVar8[iVar1] = 0;
              iVar1 = (*(code *)PTR_strtoul_0002d0a4)(puVar8,local_2c,10);
              puVar12 = local_30;
              if (*local_38[0] == '\0') goto LAB_0001b7d8;
              uVar6 = puVar2[1];
            }
          }
        }
LAB_0001b74c:
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 + 0x40;
      } while (uVar10 < uVar6);
      (*(code *)PTR_nis_freeresult_0002d0e8)(puVar2);
      iVar5 = 1;
    }
    else {
      (*(code *)PTR_nis_freeresult_0002d0e8)(puVar2);
    }
  }
  return iVar5;
}

