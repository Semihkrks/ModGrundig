
void MDrv_PQ_Init(undefined4 *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  uint uVar20;
  undefined1 auStack_d8 [184];
  
  puVar2 = PTR__s32LastPQIPMemFormatMain_2f0382b8;
  *(undefined4 *)PTR__s32LastPQIPMADiMain_2f0380f8 = 0xffffffff;
  puVar3 = PTR__s32LastPQIPHSDYMain_2f0382c4;
  *(undefined4 *)puVar2 = 0xffffffff;
  puVar2 = PTR__s32LastPQIPHSDCMain_2f0380fc;
  *(undefined4 *)puVar3 = 0xffffffff;
  puVar4 = PTR__s32LastPQIPMADiSub_2f038208;
  puVar3 = PTR__u16LastPQSrcType_2f0381b0;
  *(undefined4 *)puVar2 = 0xffffffff;
  *(undefined4 *)puVar4 = 0xffffffff;
  puVar7 = PTR__bUFSCPQEn_2f038348;
  puVar2 = PTR__s32LastPQIPMADiMotMain_2f038320;
  puVar6 = PTR__bCustomerMainPQEn_2f038300;
  puVar5 = PTR__bCustomerSubPQEn_2f038238;
  *(undefined4 *)PTR__s32LastPQIPMemFormatSub_2f0383bc = 0xffffffff;
  *(undefined4 *)puVar2 = 0xffffffff;
  puVar4 = PTR__s32LastPQIPMADiMotSub_2f0381d8;
  puVar2 = PTR_DAT_2f0380d8;
  *(undefined2 *)(puVar3 + 2) = 0xffff;
  *(undefined2 *)puVar3 = 0xffff;
  puVar8 = PTR_MsOS_CreateMutex_2f03845c;
  puVar3 = PTR_LAB_2f0380e8;
  *(undefined4 *)puVar4 = 0xffffffff;
  puVar2[-0x7b0c] = 0;
  *puVar6 = 0;
  *puVar5 = 0;
  *puVar7 = 0;
  iVar10 = (*(code *)puVar8)(1,puVar3 + 0x7354,1);
  *(int *)PTR__PQ_Mutex_2f038338 = iVar10;
  if (iVar10 == -1) {
    (*(code *)PTR_printf_2f038298)(PTR_LAB_2f0380e8 + 0x7360,0x18d);
    return;
  }
  (*(code *)PTR_memset_2f0383a8)(auStack_d8,0,0xb8);
  puVar2 = PTR_DAT_2f0380d8;
  PTR_DAT_2f0380d8[-0x7b0f] = 1;
  puVar2[-0x7b10] = 1;
  if (*(char *)((int)param_1 + 0x1b) == '\0') {
    *PTR_gbEnablePQTextBin_2f038390 = 0;
  }
  else {
    *PTR_gbEnablePQTextBin_2f038390 = 1;
    puVar2 = PTR_stPQTextBinHeaderInfo_2f038260;
    if (*(char *)((int)param_1 + 0x1b) != '\0') {
      uVar13 = 0;
      do {
        puVar3 = PTR_MDrv_PQTextBin_Parsing_2f038120;
        pbVar19 = puVar2 + (uint)*(byte *)(param_1 + uVar13 * 3 + 0x1d) * 0x94;
        *pbVar19 = *(byte *)(param_1 + uVar13 * 3 + 0x1d);
        *(undefined4 *)(pbVar19 + 4) = param_1[uVar13 * 3 + 0x1f];
        (*(code *)puVar3)(pbVar19);
        uVar13 = uVar13 + 1 & 0xff;
      } while (uVar13 < *(byte *)((int)param_1 + 0x1b));
      cVar1 = *(char *)((int)param_1 + 0x1a);
      goto joined_r0x2f01fd24;
    }
  }
  cVar1 = *(char *)((int)param_1 + 0x1a);
joined_r0x2f01fd24:
  puVar2 = PTR_MDrv_PQ_Init_DisplayType_2f038414;
  if (cVar1 == '\0') {
    *PTR_gbPQBinEnable_2f03822c = 0;
    (*(code *)puVar2)(*(undefined2 *)((int)param_1 + 0x12),0);
  }
  else {
    *PTR_gbPQBinEnable_2f03822c = 1;
    (*(code *)puVar2)(*(undefined2 *)((int)param_1 + 0x12),0);
    puVar2 = PTR_stPQBinHeaderInfo_2f03811c;
    uVar13 = (uint)*(byte *)((int)param_1 + 0x1a);
    if (2 < uVar13) {
      uVar20 = 2;
      do {
        puVar3 = PTR_MDrv_PQBin_Parsing_2f038158;
        pbVar19 = puVar2 + (uint)*(byte *)(param_1 + uVar20 * 3 + 8) * 200;
        *pbVar19 = *(byte *)(param_1 + uVar20 * 3 + 8);
        *(undefined4 *)(pbVar19 + 4) = param_1[uVar20 * 3 + 10];
        (*(code *)puVar3)(pbVar19);
        uVar11 = (*(code *)PTR_MDrv_PQBin_GetPanelIdx_2f0381b8)();
        (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(uVar11,pbVar19);
        uVar13 = (uint)*(byte *)((int)param_1 + 0x1a);
        uVar20 = uVar20 + 1 & 0xff;
      } while (uVar20 < uVar13);
    }
    puVar2 = PTR_MDrv_PQBin_Parsing_2f038158;
    if (*(char *)(param_1 + 7) == '\x02') {
      pbVar19 = PTR_stPQBinHeaderInfo_2f03811c + (uint)*(byte *)(param_1 + 0x17) * 200;
      *pbVar19 = *(byte *)(param_1 + 0x17);
      *(undefined4 *)(pbVar19 + 4) = param_1[0x19];
      (*(code *)puVar2)(pbVar19);
      (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(0,pbVar19);
      *puVar5 = 1;
      uVar13 = (uint)*(byte *)((int)param_1 + 0x1a);
    }
    puVar2 = PTR_stPQBinHeaderInfo_2f03811c;
    uVar20 = 0;
    while( true ) {
      puVar3 = PTR_MDrv_PQBin_Parsing_2f038158;
      uVar12 = 2;
      if (uVar13 < 3) {
        uVar12 = uVar13;
      }
      if (uVar12 <= uVar20) break;
      pbVar19 = puVar2 + (uint)*(byte *)(param_1 + uVar20 * 3 + 8) * 200;
      *pbVar19 = *(byte *)(param_1 + uVar20 * 3 + 8);
      *(undefined4 *)(pbVar19 + 4) = param_1[uVar20 * 3 + 10];
      (*(code *)puVar3)(pbVar19);
      uVar11 = (*(code *)PTR_MDrv_PQBin_GetPanelIdx_2f0381b8)();
      (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(uVar11,pbVar19);
      uVar13 = (uint)*(byte *)((int)param_1 + 0x1a);
      uVar20 = uVar20 + 1 & 0xff;
    }
    if (*(char *)(param_1 + 7) != '\0') {
      pbVar19 = PTR_stPQBinHeaderInfo_2f03811c + (uint)*(byte *)(param_1 + 0x14) * 200;
      *pbVar19 = *(byte *)(param_1 + 0x14);
      *(undefined4 *)(pbVar19 + 4) = param_1[0x16];
      (*(code *)puVar3)(pbVar19);
      (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(0,pbVar19);
      *puVar6 = 1;
    }
    puVar2 = PTR_MDrv_PQBin_Parsing_2f038158;
    if (*(char *)((int)param_1 + 0x1d) == '\x01') {
      pbVar19 = PTR_stPQBinHeaderInfo_2f03811c + (uint)*(byte *)(param_1 + 0x1a) * 200;
      *pbVar19 = *(byte *)(param_1 + 0x1a);
      *(undefined4 *)(pbVar19 + 4) = param_1[0x1c];
      (*(code *)puVar2)(pbVar19);
      (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(0,pbVar19);
      *puVar7 = 1;
    }
  }
  (*(code *)PTR_Hal_PQ_set_memfmt_doublebuffer_2f038124)(1);
  puVar17 = param_1;
  puVar9 = (undefined4 *)PTR__stPQ_Info_2f03835c;
  do {
    puVar18 = puVar9;
    puVar16 = puVar17;
    uVar11 = puVar16[1];
    uVar14 = puVar16[2];
    uVar15 = puVar16[3];
    puVar17 = puVar16 + 4;
    *puVar18 = *puVar16;
    puVar18[1] = uVar11;
    puVar18[2] = uVar14;
    puVar18[3] = uVar15;
    puVar2 = PTR_bw_info_2f0383c0;
    puVar9 = puVar18 + 4;
  } while (puVar17 != param_1 + 0x20);
  uVar11 = *puVar17;
  uVar14 = puVar16[5];
  puVar18[6] = puVar16[6];
  puVar18[5] = uVar14;
  puVar18[4] = uVar11;
  *(undefined4 *)(puVar2 + 4) = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 0x10) = 0;
  *(undefined4 *)(puVar2 + 0x1c) = 0;
  *(undefined4 *)(puVar2 + 0x20) = 0;
  *(undefined4 *)(puVar2 + 0x24) = 0;
  *(undefined4 *)puVar2 = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  *(undefined4 *)(puVar2 + 0x14) = 0;
  *(undefined4 *)(puVar2 + 0x18) = 0;
  *(undefined4 *)(puVar2 + 0x28) = 0;
  *(undefined4 *)(puVar2 + 0x2c) = 0;
  *(undefined4 *)(puVar2 + 0x30) = 0;
  *(undefined4 *)(puVar2 + 0x34) = 0;
  puVar3 = PTR_DAT_2f0380d8;
  puVar2[0x1e] = *(undefined1 *)param_1;
  puVar4 = PTR_DAT_2f0380d8;
  *(undefined4 *)(puVar2 + 0x20) = param_1[3];
  puVar6 = PTR__bRWNumIsReset_2f03846c;
  puVar5 = PTR_DAT_2f0380d8;
  puVar2[0x24] = *(undefined1 *)(param_1 + 4);
  *(undefined2 *)(puVar2 + 8) = *(undefined2 *)((int)param_1 + 0x16);
  *(undefined2 *)(puVar2 + 6) = *(undefined2 *)((int)param_1 + 0x12);
  *(undefined2 *)(puVar2 + 0x12) = *(undefined2 *)(param_1 + 6);
  *(undefined4 *)(puVar2 + 0x28) = param_1[1];
  uVar11 = param_1[2];
  *(undefined4 *)(puVar3 + -0x7af8) = 1;
  *puVar6 = 1;
  *(undefined4 *)(puVar2 + 0x2c) = uVar11;
  puVar6[1] = 1;
  puVar3[-0x7b00] = 1;
  puVar4[-0x7af4] = 0;
  puVar4[-0x7af0] = 0;
  *(undefined2 *)(puVar5 + -0x7aec) = 0;
  *(undefined4 *)(puVar3 + -0x7afc) = 1;
  puVar3[-0x7aff] = 1;
  puVar4[-0x7af3] = 0;
  puVar4[-0x7aef] = 0;
  *(undefined2 *)(puVar5 + -0x7aea) = 0;
  return;
}

