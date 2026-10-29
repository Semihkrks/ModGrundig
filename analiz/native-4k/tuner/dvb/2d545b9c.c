
/* MW_DVB_SI_PSI_Parser::_AddProgram(MW_DVB_TS_INFO*, MW_DVB_PROGRAM_INFO*, unsigned char) */

void MW_DVB_SI_PSI_Parser::_AddProgram
               (MW_DVB_TS_INFO *param_1,MW_DVB_PROGRAM_INFO *param_2,uchar param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined3 in_register_00000019;
  MW_DVB_PROGRAM_INFO *pMVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  MW_DVB_PROGRAM_INFO *pMVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 local_278;
  undefined2 uStack_272;
  undefined2 local_270;
  undefined2 uStack_26e;
  undefined4 local_26c [11];
  undefined4 local_240;
  undefined4 local_23c [13];
  undefined4 local_208 [5];
  undefined2 local_1f4 [26];
  _DVB_PROGRAMINFO a_Stack_1c0 [14];
  undefined1 local_1b2;
  undefined4 local_60 [4];
  undefined2 local_50 [28];
  
  pMVar7 = (MW_DVB_PROGRAM_INFO *)CONCAT31(in_register_00000019,param_3);
  memset(a_Stack_1c0,0,0x1a4);
  puVar8 = *(undefined4 **)(param_1 + 0x158);
  puVar12 = puVar8;
  puVar4 = &local_278;
  do {
    puVar11 = puVar4;
    puVar9 = puVar12;
    uVar1 = puVar9[1];
    uVar3 = puVar9[2];
    uVar5 = puVar9[3];
    puVar12 = puVar9 + 4;
    *puVar11 = *puVar9;
    puVar11[1] = uVar1;
    puVar11[2] = uVar3;
    puVar11[3] = uVar5;
    puVar4 = puVar11 + 4;
  } while (puVar12 != puVar8 + 0xc);
  uVar1 = *puVar12;
  uStack_26e = *(undefined2 *)(param_2 + 2);
  uStack_272 = *(undefined2 *)(param_2 + 4);
  local_270 = *(undefined2 *)param_2;
  puVar8 = *(undefined4 **)(param_1 + 0x160);
  puVar11[5] = puVar9[5];
  puVar11[4] = uVar1;
  local_26c[2] = 0;
  local_26c[4] = 0;
  puVar12 = puVar8;
  puVar4 = &local_240;
  do {
    puVar11 = puVar4;
    puVar9 = puVar12;
    uVar1 = puVar9[1];
    uVar3 = puVar9[2];
    uVar5 = puVar9[3];
    puVar12 = puVar9 + 4;
    *puVar11 = *puVar9;
    puVar11[1] = uVar1;
    puVar11[2] = uVar3;
    puVar11[3] = uVar5;
    puVar4 = puVar11 + 4;
  } while (puVar12 != puVar8 + 0xc);
  puVar4 = *(undefined4 **)(param_1 + 0x164);
  uVar1 = puVar9[5];
  puVar11[4] = *puVar12;
  puVar11[5] = uVar1;
  if (puVar4 != (undefined4 *)0x0) {
    puVar12 = puVar4;
    puVar8 = local_208;
    do {
      puVar11 = puVar8;
      puVar9 = puVar12;
      uVar1 = puVar9[1];
      uVar3 = puVar9[2];
      uVar5 = puVar9[3];
      puVar12 = puVar9 + 4;
      *puVar11 = *puVar9;
      puVar11[1] = uVar1;
      puVar11[2] = uVar3;
      puVar11[3] = uVar5;
      puVar8 = puVar11 + 4;
    } while (puVar12 != puVar4 + 0x10);
    puVar11[4] = *puVar12;
    *(undefined2 *)(puVar11 + 5) = *(undefined2 *)(puVar9 + 5);
  }
  local_240._2_2_ = uStack_26e;
  _AddCommonProgramInfo((MW_DVB_SI_PSI_Parser *)param_1,a_Stack_1c0,pMVar7);
  pMVar10 = pMVar7 + 0x132;
  local_1b2 = *(undefined1 *)(*(int *)(param_1 + 0x150) + 0xe);
  puVar12 = local_60;
  do {
    uVar1 = *(undefined4 *)pMVar10;
    uVar3 = *(undefined4 *)(pMVar10 + 4);
    uVar5 = *(undefined4 *)(pMVar10 + 8);
    uVar6 = *(undefined4 *)(pMVar10 + 0xc);
    pMVar10 = pMVar10 + 0x10;
    *puVar12 = uVar1;
    puVar12[1] = uVar3;
    puVar12[2] = uVar5;
    puVar12[3] = uVar6;
    puVar12 = puVar12 + 4;
  } while (pMVar10 != pMVar7 + 0x162);
  iVar2 = *(int *)(param_1 + 0x164);
  *(undefined2 *)puVar12 = *(undefined2 *)pMVar10;
  if (iVar2 != 0) {
    (**(code **)(**(int **)(param_1 + 0x154) + 0x18))
              (*(int **)(param_1 + 0x154),1,a_Stack_1c0,&local_278,&local_240,local_208,0);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x154) + 0x14))
            (*(int **)(param_1 + 0x154),1,a_Stack_1c0,&local_278,&local_240,0);
  return;
}

