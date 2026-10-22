
void MApi_SWI2C_Init(undefined2 *param_1,uint param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  undefined2 *puVar13;
  uint uVar14;
  
  uVar14 = param_2 & 0xff;
  PTR_DAT_2f333968[0x39f0] = (char)param_2;
  puVar4 = PTR_DAT_2f333968;
  if (uVar14 != 0) {
    iVar10 = 0;
    do {
      puVar9 = (undefined4 *)((int)param_1 + iVar10);
      puVar6 = (undefined4 *)(puVar4 + iVar10 + 0x3ad8);
      iVar10 = iVar10 + 6;
      *puVar6 = *puVar9;
      *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(puVar9 + 1);
      *(undefined1 *)((int)puVar6 + 5) = *(undefined1 *)((int)puVar9 + 5);
    } while (iVar10 != ((uVar14 - 1 & 0xff) + 1) * 6);
  }
  puVar12 = PTR_MDrv_COPRO_GetBase_2f333994;
  puVar4 = PTR_DAT_2f333968;
  PTR_DAT_2f333968[0x39f2] = 0;
  (*(code *)puVar12)();
  uVar7 = (*(code *)PTR_MDrv_CPU_QueryClock_2f3339c4)();
  *(uint *)(PTR_DAT_2f333968 + 0x3ad4) = uVar7 / 1000000;
  if (uVar7 / 1000000 == 0) {
    (*(code *)PTR_printf_2f3339a0)
              (PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x37ac,
               PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x37d4,
               PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x37d8,
               PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x38c4,0x2c2);
  }
  if (uVar14 == 0) {
    uVar8 = (*(code *)PTR_MsOS_CreateMutex_2f3339cc)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x37e4,1);
    *(undefined4 *)(PTR_DAT_2f333968 + 0x3938) = uVar8;
  }
  else {
    puVar6 = (undefined4 *)(PTR_DAT_2f333968 + 0x38f8);
    uVar7 = 0;
    puVar12 = PTR_gu8SWI2CMutexName_2f3339a4;
    do {
      uVar8 = (*(code *)PTR_MsOS_CreateMutex_2f3339cc)(1,puVar12,1);
      uVar7 = uVar7 + 1 & 0xff;
      puVar12 = puVar12 + 0xd;
      *puVar6 = uVar8;
      puVar6 = puVar6 + 1;
    } while (uVar7 < uVar14);
    uVar8 = (*(code *)PTR_MsOS_CreateMutex_2f3339cc)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f333974 + 0x37e4,1);
    *(undefined4 *)(PTR_DAT_2f333968 + 0x3938) = uVar8;
    puVar9 = (undefined4 *)(PTR_DAT_2f333968 + 0x3b38);
    puVar6 = (undefined4 *)(PTR_DAT_2f333968 + 0x3b78);
    puVar13 = (undefined2 *)(PTR_DAT_2f333968 + 0x39f4);
    uVar7 = 0;
    do {
      puVar12 = PTR_MApi_SWI2C_Speed_Setting_2f33399c;
      bVar1 = puVar4[0x39f2];
      if (((bVar1 < 0x11) && ((uVar7 & 0xff) < 0x10)) && (param_1 != (undefined2 *)0x0)) {
        uVar2 = param_1[1];
        uVar3 = param_1[2];
        *puVar13 = *param_1;
        puVar5 = PTR_DAT_2f333968;
        puVar13[2] = uVar3;
        puVar13[1] = uVar2;
        puVar5[0x39f2] = bVar1 + 1;
      }
      puVar13 = puVar13 + 3;
      (*(code *)puVar12)(uVar7,param_1[2]);
      uVar11 = uVar7 + 1;
      (*(code *)PTR_MApi_SWI2C_SetBusReadMode_2f3339b4)(uVar7,1);
      *puVar9 = 3;
      *puVar6 = 5;
      puVar9 = puVar9 + 1;
      puVar6 = puVar6 + 1;
      param_1 = param_1 + 3;
      uVar7 = uVar11;
    } while ((uVar11 & 0xff) < uVar14);
  }
  return;
}

