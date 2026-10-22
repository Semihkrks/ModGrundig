
undefined4
_nss_compat_initgroups_dyn
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,int *param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  char *pcVar14;
  char *pcVar15;
  undefined1 *puVar16;
  code *pcVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 auStack_90 [40];
  undefined1 auStack_60 [12];
  char *local_54 [4];
  int local_44;
  uint *local_40;
  undefined1 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  char **local_2c;
  
  puVar1 = PTR_DAT_000280f8;
  uVar4 = (*(code *)PTR_sysconf_000281a4)(0x46);
  local_44 = 1;
  local_40 = (uint *)0x0;
  local_3c = (undefined1 *)0x0;
  local_38 = 0;
  local_34 = 0;
  if (*(int *)(puVar1 + -0x7da0) == 0) {
    if (((PTR___pthread_mutex_lock_00028158 == (undefined *)0x0) ||
        ((*(code *)PTR___pthread_mutex_lock_00028158)(PTR_DAT_000280f8 + -0x7d8c),
        *(int *)(puVar1 + -0x7da0) == 0)) &&
       (iVar11 = (*(code *)PTR___nss_database_lookup_000281a0)
                           (PTR_00028108 + 0x742c,0,PTR_00028108 + 0x743c,puVar1 + -0x7da0),
       puVar1 = PTR_DAT_000280f8, -1 < iVar11)) {
      uVar7 = (*(code *)PTR___nss_lookup_function_00028118)
                        (*(undefined4 *)(PTR_DAT_000280f8 + -0x7da0),PTR_00028108 + 30000);
      puVar10 = PTR___nss_lookup_function_00028118;
      puVar2 = PTR_00028108;
      uVar13 = *(undefined4 *)(puVar1 + -0x7da0);
      *(undefined4 *)(PTR_DAT_000280f8 + -0x7d9c) = uVar7;
      uVar7 = (*(code *)puVar10)(uVar13,puVar2 + 0x744c);
      puVar10 = PTR___nss_lookup_function_00028118;
      puVar2 = PTR_00028108;
      uVar13 = *(undefined4 *)(puVar1 + -0x7da0);
      *(undefined4 *)(PTR_DAT_000280f8 + -0x7d98) = uVar7;
      uVar7 = (*(code *)puVar10)(uVar13,puVar2 + 0x7458);
      puVar10 = PTR___nss_lookup_function_00028118;
      puVar2 = PTR_00028108;
      uVar13 = *(undefined4 *)(puVar1 + -0x7da0);
      *(undefined4 *)(PTR_DAT_000280f8 + -0x7d94) = uVar7;
      uVar7 = (*(code *)puVar10)(uVar13,puVar2 + 0x7464);
      *(undefined4 *)(PTR_DAT_000280f8 + -0x7d90) = uVar7;
    }
    if (PTR___pthread_mutex_unlock_00028148 != (undefined *)0x0) {
      (*(code *)PTR___pthread_mutex_unlock_00028148)(PTR_DAT_000280f8 + -0x7d8c);
    }
  }
  if (local_3c == (undefined1 *)0x0) {
    local_38 = 0;
    local_40 = (uint *)(*(code *)PTR_fopen_00028134)(PTR_00028108 + 0x747c,PTR_00028108 + 0x7488);
  }
  else {
    local_38 = 1;
    *local_3c = 0x7c;
    puVar2 = PTR_fopen_00028134;
    puVar1 = PTR_00028108;
    puVar10 = PTR_00028108 + 0x747c;
    local_3c[1] = 0;
    local_40 = (uint *)(*(code *)puVar2)(puVar10,puVar1 + 0x7488);
  }
  puVar1 = PTR_DAT_0002810c;
  if (local_40 == (uint *)0x0) {
    piVar6 = (int *)(*(code *)PTR___errno_location_000281a8)(0);
    uVar7 = 0xffffffff;
    if (*piVar6 == 0xb) {
      uVar7 = 0xfffffffe;
    }
    return uVar7;
  }
  if (*(int *)PTR_DAT_0002810c < 1) {
    uVar7 = (*(code *)PTR_fileno_unlocked_00028168)();
    uVar12 = (*(code *)PTR_fcntl_00028124)(uVar7,1,0);
    if ((int)uVar12 < 0) {
LAB_00016e8c:
      (*(code *)PTR_fclose_00028160)(local_40);
      return 0xffffffff;
    }
    iVar11 = *(int *)puVar1;
    uVar7 = 0xffffffff;
    if (iVar11 == 0) {
      if ((uVar12 & 1) != 0) {
        uVar7 = 1;
      }
      *(undefined4 *)puVar1 = uVar7;
      iVar11 = *(int *)puVar1;
    }
    if (iVar11 < 0) {
      uVar7 = (*(code *)PTR_fileno_unlocked_00028168)(local_40);
      iVar11 = (*(code *)PTR_fcntl_00028124)(uVar7,2,uVar12 | 1);
      if (iVar11 < 0) goto LAB_00016e8c;
    }
  }
  *local_40 = *local_40 & 0xffff7fff | 0x8000;
  iVar11 = -(uVar4 + 0xe & 0xfffffff8);
  puVar18 = auStack_90 + iVar11;
  local_30 = &local_44;
  local_2c = local_54;
  puVar8 = (undefined1 *)((int)local_54 + iVar11 + -0x14);
  iVar11 = local_44;
LAB_00016ba0:
  uVar12 = uVar4;
  puVar19 = puVar18;
  puVar20 = puVar18;
  if (iVar11 == 0) goto LAB_00016d20;
LAB_00016ba8:
  if (uVar12 < 3) {
LAB_00016ce0:
    *param_7 = 0x22;
    puVar16 = puVar8;
    uVar4 = uVar12;
    puVar8 = puVar19;
    goto LAB_00016cec;
  }
  pcVar15 = puVar8 + (uVar12 - 1);
LAB_00016bbc:
  do {
    do {
      (*(code *)PTR_fgetpos_00028194)(local_40,auStack_60);
      puVar3 = local_40;
      *pcVar15 = -1;
      pcVar5 = (char *)(*(code *)PTR_fgets_unlocked_00028128)(puVar8,uVar12,puVar3);
      puVar18 = puVar19;
      if (pcVar5 == (char *)0x0) {
        iVar9 = 0;
        if ((*local_40 & 0x10) == 0) goto LAB_00016ccc;
        goto LAB_00016d7c;
      }
      if (*pcVar15 != -1) goto LAB_00016ccc;
      *pcVar15 = '\0';
      piVar6 = (int *)(*(code *)PTR___ctype_b_loc_00028170)();
      do {
        pcVar14 = pcVar5;
        iVar11 = (int)*pcVar14;
        pcVar5 = pcVar14 + 1;
      } while ((*(ushort *)(*piVar6 + iVar11 * 2) & 0x2000) != 0);
    } while ((iVar11 == 0) || (iVar11 == 0x23));
    *(int **)(puVar19 + 0x10) = param_7;
    iVar11 = (*(code *)PTR__nss_files_parse_grent_0002816c)(pcVar14,local_2c,puVar8,uVar12);
    piVar6 = local_30;
  } while (iVar11 == 0);
  if (iVar11 == -1) {
LAB_00016ccc:
    (*(code *)PTR_fsetpos_0002817c)(local_40,auStack_60);
    iVar11 = local_44;
    goto LAB_00016ce0;
  }
  if (*local_54[0] == '+') {
    if (local_54[0][1] == '\0') goto LAB_00017050;
    if (local_54[0][1] == '@') goto LAB_00016bbc;
    pcVar5 = local_54[0] + 1;
    uVar7 = (*(code *)PTR_strlen_00028150)(pcVar5);
    iVar11 = (*(code *)(PTR_00028108 + 0x63b0))(pcVar5,uVar7,local_30);
    if (iVar11 != 0) goto LAB_00016bbc;
    (*(code *)(PTR_00028108 + 0x6460))(local_54[0] + 1,local_30);
    pcVar17 = *(code **)(PTR_DAT_000280f8 + -0x7d98);
    if (pcVar17 == (code *)0x0) {
      iVar9 = -1;
      goto LAB_00016d7c;
    }
    *(int **)(puVar19 + 0x10) = param_7;
    iVar11 = (*pcVar17)(local_54[0] + 1,local_2c,puVar8,uVar12);
    if (iVar11 != 1) goto LAB_00016bbc;
  }
  else if (*local_54[0] == '-') {
    if ((local_54[0][1] != '\0') && (local_54[0][1] != '@')) {
      (*(code *)(PTR_00028108 + 0x6460))(local_54[0] + 1,local_30);
    }
    goto LAB_00016bbc;
  }
  *(undefined4 *)(puVar19 + 0x10) = param_5;
  *(undefined4 *)(puVar19 + 0x14) = param_6;
  *(char ***)(puVar19 + 0x18) = local_2c;
  (*(code *)(PTR_00028108 + 0x65bc))(param_1,param_2,param_3,param_4);
  iVar9 = 1;
  goto LAB_00016d7c;
LAB_00017050:
  local_44 = 0;
  *(undefined4 *)(puVar19 + 0x10) = param_2;
  *(undefined4 *)(puVar19 + 0x14) = param_3;
  *(undefined4 *)(puVar19 + 0x18) = param_4;
  *(undefined4 *)(puVar19 + 0x1c) = param_5;
  *(undefined4 *)(puVar19 + 0x20) = param_6;
  *(int **)(puVar19 + 0x24) = param_7;
  puVar20 = puVar19;
  while( true ) {
    iVar9 = (*(code *)(PTR_00028108 + 0x6708))(piVar6,puVar8,uVar12,param_1);
    puVar18 = puVar20;
    if (iVar9 != -2) goto LAB_00016d7c;
    iVar11 = local_44;
    puVar16 = puVar8;
    uVar4 = uVar12;
    puVar8 = puVar20;
    if (*param_7 != 0x22) goto LAB_00016d9c;
LAB_00016cec:
    uVar12 = uVar4 * 2;
    iVar9 = -(uVar12 + 0xe & 0xfffffff8);
    puVar18 = puVar8 + iVar9;
    puVar19 = puVar8 + iVar9;
    puVar20 = puVar8 + iVar9;
    puVar8 = puVar8 + iVar9 + 0x28;
    uVar4 = uVar4 * 3;
    if (puVar16 == puVar8 + uVar12) goto LAB_00016ba0;
    if (iVar11 != 0) break;
LAB_00016d20:
    piVar6 = local_30;
    *(undefined4 *)(puVar20 + 0x10) = param_2;
    *(undefined4 *)(puVar20 + 0x14) = param_3;
    *(undefined4 *)(puVar20 + 0x18) = param_4;
    *(undefined4 *)(puVar20 + 0x1c) = param_5;
    *(undefined4 *)(puVar20 + 0x20) = param_6;
    *(int **)(puVar20 + 0x24) = param_7;
  }
  goto LAB_00016ba8;
LAB_00016d7c:
  iVar11 = local_44;
  uVar4 = uVar12;
  if (iVar9 != 1) {
LAB_00016d9c:
    if (local_40 != (uint *)0x0) {
      (*(code *)PTR_fclose_00028160)();
    }
    if (local_3c == (undefined1 *)0x0) {
      return 1;
    }
    *local_3c = 0x7c;
    local_3c[1] = 0;
    return 1;
  }
  goto LAB_00016ba0;
}

