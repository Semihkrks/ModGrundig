
uint MDrv_HWI2C_Init_U2K(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  byte local_60 [4];
  undefined4 local_5c;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  undefined4 local_50 [4];
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  char local_30;
  
  puVar1 = PTR_DAT_2f4346e8;
  puVar8 = (undefined4 *)(PTR_DAT_2f4346e8 + 0x4990);
  *(undefined4 **)(PTR_DAT_2f4346e8 + 0x4610) = puVar8;
  uVar12 = param_1[0x48];
  uVar14 = param_1[0x49];
  uVar11 = param_1[0x4a];
  uVar10 = param_1[0x4b];
  local_5c = 0xffffffff;
  *(undefined4 *)(puVar1 + 0x4ac0) = param_1[0x4c];
  *(undefined4 *)(puVar1 + 0x4ab8) = uVar11;
  *(undefined4 *)(puVar1 + 0x4ab0) = uVar12;
  *(undefined4 *)(puVar1 + 0x4abc) = uVar10;
  *(undefined4 *)(puVar1 + 0x4ab4) = uVar14;
  puVar13 = param_1;
  do {
    uVar10 = *puVar13;
    uVar11 = puVar13[1];
    uVar12 = puVar13[2];
    uVar14 = puVar13[3];
    puVar13 = puVar13 + 4;
    *puVar8 = uVar10;
    puVar8[1] = uVar11;
    puVar8[2] = uVar12;
    puVar8[3] = uVar14;
    puVar8 = puVar8 + 4;
  } while (puVar13 != param_1 + 8);
  iVar9 = *(int *)(puVar1 + 0x4610);
  puVar13 = param_1 + 9;
  *puVar8 = param_1[8];
  puVar8 = (undefined4 *)(iVar9 + 0x24);
  do {
    uVar10 = *puVar13;
    uVar11 = puVar13[1];
    uVar12 = puVar13[2];
    uVar14 = puVar13[3];
    puVar13 = puVar13 + 4;
    *puVar8 = uVar10;
    puVar8[1] = uVar11;
    puVar8[2] = uVar12;
    puVar8[3] = uVar14;
    puVar8 = puVar8 + 4;
  } while (puVar13 != param_1 + 0x11);
  *puVar8 = *puVar13;
  puVar13 = param_1 + 0x12;
  puVar8 = (undefined4 *)(*(int *)(puVar1 + 0x4610) + 0x48);
  do {
    uVar10 = *puVar13;
    uVar11 = puVar13[1];
    uVar12 = puVar13[2];
    uVar14 = puVar13[3];
    puVar13 = puVar13 + 4;
    *puVar8 = uVar10;
    puVar8[1] = uVar11;
    puVar8[2] = uVar12;
    puVar8[3] = uVar14;
    puVar8 = puVar8 + 4;
  } while (puVar13 != param_1 + 0x1a);
  *puVar8 = *puVar13;
  puVar13 = param_1 + 0x1b;
  puVar8 = (undefined4 *)(*(int *)(puVar1 + 0x4610) + 0x6c);
  do {
    uVar10 = *puVar13;
    uVar11 = puVar13[1];
    uVar12 = puVar13[2];
    uVar14 = puVar13[3];
    puVar13 = puVar13 + 4;
    *puVar8 = uVar10;
    puVar8[1] = uVar11;
    puVar8[2] = uVar12;
    puVar8[3] = uVar14;
    puVar1 = PTR_DAT_2f4346e8;
    puVar8 = puVar8 + 4;
  } while (puVar13 != param_1 + 0x23);
  *puVar8 = *puVar13;
  if (puVar1[0x4830] == '\0') {
    iVar9 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f4347ac)(&local_5c,auStack_58,0x10a);
    if (iVar9 == 0) {
      uVar15 = 0;
    }
    else {
      (*(code *)PTR_HAL_HWI2C_SetIOMapBase_2f434750)(local_5c);
      uVar4 = (*(code *)PTR_HAL_HWI2C_Init_Chip_2f43472c)();
      puVar2 = PTR___DT_MIPS_BASE_ADDRESS_2f4346f4;
      local_60[0] = 0;
      local_54 = 0;
      puVar13 = param_1;
      puVar8 = local_50;
      do {
        uVar10 = *puVar13;
        uVar11 = puVar13[1];
        uVar12 = puVar13[2];
        uVar14 = puVar13[3];
        puVar13 = puVar13 + 4;
        *puVar8 = uVar10;
        puVar8[1] = uVar11;
        puVar8[2] = uVar12;
        puVar8[3] = uVar14;
        puVar8 = puVar8 + 4;
      } while (puVar13 != param_1 + 8);
      *puVar8 = *puVar13;
      if ((local_30 == '\0') ||
         (iVar9 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x28d4))(local_3c),
         puVar3 = PTR_DAT_2f4346e8, iVar9 == 0)) {
        uVar15 = 1;
      }
      else {
        uVar5 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x2754))
                          (PTR_DAT_2f4346e8[0x4838],local_38);
        if (puVar3[0x4838] == '\0') {
          uVar16 = 0;
          if (local_34 < 3) {
            uVar16 = 1;
            *(uint *)(PTR_DAT_2f4346e8 + 0x4980) = local_34;
          }
        }
        else {
          uVar16 = 0;
        }
        uVar6 = (*(code *)PTR_HAL_HWI2C_GetPortIdxByPort_2f434754)(local_3c,local_60);
        if (local_60[0] == 0) {
          uVar15 = (*(code *)PTR_HAL_HWI2C_SetPortRegOffset_2f4347a4)
                             (*(undefined4 *)(PTR_DAT_2f4346e8 + 0x4984),&local_54);
          uVar15 = uVar15 & uVar5 & uVar16 & uVar6;
        }
        else {
          uVar15 = 0;
        }
        uVar5 = (*(code *)PTR_HAL_HWI2C_Master_Enable_2f434764)(local_54);
        uVar16 = (*(code *)PTR_HAL_HWI2C_DMA_Init_2f4347a8)(local_54,local_50);
        PTR_DAT_2f4346e8[local_60[0] + 0x498c] = local_40[0];
        uVar15 = uVar16 & uVar5 & uVar15;
      }
      iVar9 = (*(code *)(puVar2 + 0x28d4))(param_1[0x4b]);
      puVar2 = PTR_DAT_2f4346e8;
      if (iVar9 != 0) {
        uVar5 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x2754))
                          (PTR_DAT_2f4346e8[0x4838],param_1[0x4a]);
        if (puVar2[0x4838] == '\0') {
          uVar16 = 0;
          if ((uint)param_1[0x4c] < 3) {
            uVar16 = 1;
            *(undefined4 *)(PTR_DAT_2f4346e8 + 0x4980) = param_1[0x4c];
          }
        }
        else {
          uVar16 = 0;
        }
        uVar6 = (*(code *)PTR_HAL_HWI2C_GetPortIdxByPort_2f434754)(param_1[0x4b],local_60);
        if (local_60[0] == 0) {
          uVar7 = (*(code *)PTR_HAL_HWI2C_SetPortRegOffset_2f4347a4)
                            (*(undefined4 *)(PTR_DAT_2f4346e8 + 0x4984),&local_54);
          uVar15 = uVar7 & uVar5 & uVar15 & uVar16 & uVar6;
        }
        else {
          uVar15 = 0;
        }
        uVar5 = (*(code *)PTR_HAL_HWI2C_Master_Enable_2f434764)(local_54);
        uVar15 = uVar15 & uVar5;
      }
      uVar15 = uVar4 & 1 & uVar15;
      (*(code *)PTR_HAL_HWI2C_Init_ExtraProc_2f434740)();
      *(undefined4 *)(PTR_DAT_2f4346e8 + 0x4840) = local_5c;
      *(undefined4 *)(PTR_DAT_2f4346e8 + 0x4978) = 5;
      puVar2 = PTR_DAT_2f4346e8;
      *(undefined4 *)(PTR_DAT_2f4346e8 + 0x497c) = 0x3c;
      puVar3 = PTR_DAT_2f4346e8;
      *(undefined4 *)(puVar2 + 0x483c) = 0;
      puVar13 = (undefined4 *)(puVar3 + 0x4844);
      puVar8 = param_1 + 0x4c;
      do {
        uVar10 = *param_1;
        uVar11 = param_1[1];
        uVar12 = param_1[2];
        uVar14 = param_1[3];
        param_1 = param_1 + 4;
        *puVar13 = uVar10;
        puVar13[1] = uVar11;
        puVar13[2] = uVar12;
        puVar13[3] = uVar14;
        puVar3 = PTR_MsOS_CreateMutex_2f434800;
        puVar2 = PTR_DAT_2f4346e8;
        puVar13 = puVar13 + 4;
      } while (param_1 != puVar8);
      *puVar13 = *param_1;
      puVar1[0x4830] = 1;
      uVar10 = (*(code *)puVar3)(1,puVar2 + 0x4664,1);
      puVar2 = PTR_MsOS_CreateMutex_2f434800;
      puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2f4346f4;
      *(undefined4 *)(PTR_DAT_2f4346e8 + 0x461c) = uVar10;
      uVar10 = (*(code *)puVar2)(1,puVar1 + 0x44d0,1);
      *(undefined4 *)(PTR_DAT_2f4346e8 + 0x463c) = uVar10;
    }
    return uVar15;
  }
  return 1;
}

