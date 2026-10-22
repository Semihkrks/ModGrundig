
int _nss_nis_initgroups_dyn
              (undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6,
              int *param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  char *pcVar10;
  int *piVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 auStack_88 [16];
  int *local_78;
  int local_74;
  int *local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined *local_58;
  int **local_54;
  int *local_50;
  int *local_4c;
  uint local_48;
  undefined1 auStack_44 [8];
  int local_3c;
  int *local_38;
  int local_30;
  
  iVar2 = (*(code *)PTR_yp_get_default_domain_0002a0ac)(&local_60);
  if (iVar2 != 0) {
    return -1;
  }
  uVar3 = (*(code *)PTR__nsl_default_nss_0002a0a0)();
  if (((uVar3 & 1) != 0) &&
     (iVar2 = (*(code *)(PTR_DAT_0002a078 + -0x73d0))(param_1,&local_5c), iVar2 == 0)) {
    local_6c = local_60;
    local_74 = param_6;
    local_78 = param_5;
    local_70 = param_7;
    iVar2 = (*(code *)(PTR_DAT_0002a078 + -0x7280))(local_5c,param_2,param_3,param_4);
    if (iVar2 == 1) {
      return 1;
    }
  }
  iVar2 = -1;
  uVar3 = (*(code *)PTR_sysconf_0002a144)(0x46);
  local_58 = PTR__nis_saveit_0002a084;
  local_54 = &local_50;
  local_30 = *param_5;
  local_50 = (int *)0x0;
  local_4c = (int *)0x0;
  local_48 = 0;
  uVar4 = (*(code *)PTR_yp_all_0002a0d4)(local_60,PTR_DAT_0002a078 + -0x674c,&local_58);
  if (uVar4 < *(uint *)PTR___yperr2nss_count_0002a07c) {
    iVar2 = *(int *)(PTR___yperr2nss_tab_0002a080 + uVar4 * 4);
  }
  if (local_4c != (int *)0x0) {
    *(uint *)((int)local_4c + 4) = local_48;
  }
  if (iVar2 != 1) {
    return iVar2;
  }
  iVar2 = -(uVar3 + 0xe & 0xfffffff8);
  local_48 = 0;
  local_4c = local_50;
  puVar12 = &stack0xffffff98 + iVar2;
  puVar13 = auStack_88 + iVar2;
LAB_00019204:
  do {
    do {
      uVar4 = uVar3;
      if (local_50 == (int *)0x0) {
        return 1;
      }
      do {
        if ((uint)local_4c[1] <= local_48) {
          local_4c = (int *)*local_4c;
          piVar11 = local_50;
          if (local_4c == (int *)0x0) goto joined_r0x00019398;
          local_48 = 0;
        }
        piVar11 = local_4c;
        pcVar10 = (char *)((int)local_4c + local_48 + 8);
        piVar5 = (int *)(*(code *)PTR___ctype_b_loc_0002a0f8)();
        while ((*(ushort *)(*piVar5 + *pcVar10 * 2) & 0x2000) != 0) {
          pcVar10 = pcVar10 + 1;
          local_48 = local_48 + 1;
        }
        iVar2 = (*(code *)PTR_strlen_0002a0e0)(pcVar10);
        uVar3 = iVar2 + 1;
        if (uVar4 < uVar3) {
          *param_7 = 0x22;
LAB_000193dc:
          uVar3 = uVar4 * 2;
          iVar2 = -(uVar3 + 0xe & 0xfffffff8);
          puVar14 = puVar13 + iVar2;
          puVar9 = puVar13 + iVar2 + 0x20;
          bVar1 = puVar12 == puVar9 + uVar3;
          puVar12 = puVar9;
          puVar13 = puVar13 + iVar2;
          if (bVar1) {
            uVar3 = uVar4 * 3;
            puVar13 = puVar14;
          }
          goto LAB_00019204;
        }
        uVar6 = (*(code *)PTR_memcpy_0002a0e8)(puVar12,(int)piVar11 + local_48 + 8,uVar3);
        *(int **)(puVar13 + 0x10) = param_7;
        iVar7 = (*(code *)PTR__nss_files_parse_grent_0002a0f4)(uVar6,auStack_44,puVar12,uVar4);
        iVar2 = local_3c;
        if (iVar7 == -1) {
          piVar11 = local_50;
          if (*param_7 == 0x22) goto LAB_000193dc;
          goto joined_r0x00019398;
        }
        local_48 = local_48 + uVar3;
      } while (iVar7 == 0);
      uVar3 = uVar4;
    } while (local_3c == param_2);
    iVar7 = *local_38;
    piVar11 = local_38;
    while (iVar7 != 0) {
      piVar11 = piVar11 + 1;
      iVar7 = (*(code *)PTR_strcmp_0002a09c)(iVar7,param_1);
      if (iVar7 == 0) {
        iVar7 = *param_3;
        if (iVar7 == *param_4) {
          iVar2 = iVar7 << 1;
          if (0 < param_6) {
            piVar11 = local_50;
            if (param_6 == iVar7) goto joined_r0x00019398;
            iVar2 = param_6;
            if (iVar7 << 1 < param_6) {
              iVar2 = iVar7 << 1;
            }
          }
          iVar8 = (*(code *)PTR_realloc_0002a12c)(local_30,iVar2 << 2);
          piVar11 = local_50;
          if (iVar8 == 0) {
joined_r0x00019398:
            while (local_4c = piVar11, local_4c != (int *)0x0) {
              local_50 = (int *)*local_4c;
              (*(code *)PTR_free_0002a100)();
              piVar11 = local_50;
            }
            return 1;
          }
          *param_4 = iVar2;
          iVar7 = *param_3;
          *param_5 = iVar8;
          iVar2 = local_3c;
          local_30 = iVar8;
        }
        *(int *)(local_30 + iVar7 * 4) = iVar2;
        *param_3 = iVar7 + 1;
        break;
      }
      iVar7 = *piVar11;
    }
  } while( true );
}

