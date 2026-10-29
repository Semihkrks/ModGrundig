
undefined4 _HVD_EX_DemuxTS_ParseHEVCSPS(char *param_1,ushort param_2,uint *param_3)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined2 local_468 [2];
  undefined4 local_464 [6];
  undefined4 local_44c [6];
  byte local_434 [1028];
  undefined4 *local_30;
  undefined4 *local_2c;
  
  memset(local_434,0,0x400);
  while( true ) {
    if (param_2 < 5) {
      return 0;
    }
    if ((((*param_1 == '\0') && (param_1[1] == '\0')) && (param_1[2] == '\x01')) &&
       ((((byte)param_1[3] >> 1 & 0x3f) == 0x21 && (0x10 < param_2)))) break;
    param_1 = param_1 + 1;
    param_2 = param_2 - 1;
  }
  uVar7 = (uint)(ushort)(param_2 - 5);
  local_468[0] = 0;
  if (uVar7 == 0) {
    uVar15 = 0;
  }
  else {
    uVar9 = 0;
    sVar2 = 0;
    uVar15 = 0;
    pbVar11 = local_434;
    do {
      pbVar10 = (byte *)(param_1 + uVar9 + 5);
      if (sVar2 == 2) {
        bVar8 = *pbVar10;
        if (bVar8 < 3) break;
        if (bVar8 == 3) {
          if ((((int)uVar9 < (int)(uVar7 - 1)) && (3 < pbVar10[1])) || (uVar9 == uVar7 - 1)) break;
          bVar8 = pbVar10[1];
          uVar9 = uVar9 + 1 & 0xffff;
          pbVar10 = pbVar10 + 1;
          sVar2 = 0;
        }
      }
      else {
        bVar8 = *pbVar10;
      }
      *pbVar11 = bVar8;
      sVar2 = sVar2 + 1;
      if (*pbVar10 != 0) {
        sVar2 = 0;
      }
      uVar15 = uVar15 + 1 & 0xffff;
      if (uVar15 == 0x401) {
        puts("_HVD_EX_DemuxTS_EBSPtoRBSP failed~ byte is too much than 1024!!");
        uVar15 = 0x400;
        break;
      }
      uVar9 = uVar9 + 1 & 0xffff;
      pbVar11 = pbVar11 + 1;
    } while (uVar9 < uVar7);
  }
  if ((u32UartCtrl & 4) != 0) {
    printf("[HVD][DBG]%s:","_HVD_EX_DemuxTS_ParseHEVCSPS");
    printf("[DemuxTS] valid data len = %d\n",uVar15);
  }
  if (uVar15 == 0) {
    puts("_HVD_EX_DemuxTS_ParseHEVCSPS wrong position");
    uVar3 = 0;
  }
  else {
    (*(code *)&UNK_2d6336b0)(4,local_434,uVar15,local_468,1);
    uVar7 = (*(code *)&UNK_2d6336b0)(3,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(2,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    iVar13 = 0;
    (*(code *)&UNK_2d6336b0)(5,local_434,uVar15,local_468,1);
    do {
      iVar13 = iVar13 + 1;
      (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    } while (iVar13 != 0x20);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(0x2c,local_434,uVar15,local_468,1);
    (*(code *)&UNK_2d6336b0)(8,local_434,uVar15,local_468,1);
    if (uVar7 != 0) {
      puVar16 = local_464;
      puVar14 = local_44c;
      uVar9 = 0;
      local_30 = puVar16;
      local_2c = puVar14;
      do {
        uVar3 = (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
        *puVar16 = uVar3;
        uVar9 = uVar9 + 1;
        uVar3 = (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
        puVar16 = puVar16 + 1;
        *puVar14 = uVar3;
        puVar14 = puVar14 + 1;
        uVar6 = uVar7;
      } while (uVar9 < uVar7);
      for (; uVar6 < 8; uVar6 = uVar6 + 1) {
        (*(code *)&UNK_2d6336b0)(2,local_434,uVar15,local_468,1);
      }
      iVar13 = 0;
      do {
        if (*(int *)((int)local_30 + iVar13) != 0) {
          (*(code *)&UNK_2d6336b0)(2,local_434,uVar15,local_468,1);
          (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          iVar12 = 0;
          (*(code *)&UNK_2d6336b0)(5,local_434,uVar15,local_468,1);
          do {
            iVar12 = iVar12 + 1;
            (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          } while (iVar12 != 0x20);
          (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
          (*(code *)&UNK_2d6336b0)(0x2c,local_434,uVar15,local_468,1);
        }
        if (*(int *)((int)local_2c + iVar13) != 0) {
          (*(code *)&UNK_2d6336b0)(8,local_434,uVar15,local_468,1);
        }
        iVar13 = iVar13 + 4;
      } while (iVar13 != uVar7 << 2);
    }
    FUN_2d633808(local_434,uVar15,local_468,1);
    iVar13 = FUN_2d633808(local_434,uVar15,local_468,1);
    if (iVar13 == 3) {
      (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    }
    iVar13 = FUN_2d633808(local_434,uVar15,local_468,1);
    iVar12 = FUN_2d633808(local_434,uVar15,local_468,1);
    iVar4 = (*(code *)&UNK_2d6336b0)(1,local_434,uVar15,local_468,1);
    if (iVar4 != 0) {
      FUN_2d633808(local_434,uVar15,local_468,1);
      FUN_2d633808(local_434,uVar15,local_468,1);
      FUN_2d633808(local_434,uVar15,local_468,1);
      FUN_2d633808(local_434,uVar15,local_468,1);
    }
    iVar4 = FUN_2d633808(local_434,uVar15,local_468,1);
    iVar5 = FUN_2d633808(local_434,uVar15,local_468,1);
    uVar9 = iVar13 + 0x1fU & 0xffe0;
    uVar15 = iVar12 + 0x1fU & 0xffe0;
    uVar7 = 0x880000;
    if (uVar9 < 0x801) {
      uVar6 = 0x220000;
      if (uVar15 < 0x441) {
        uVar6 = 0x88000;
        uVar7 = 0x220000;
      }
    }
    else {
      uVar6 = 0x220000;
    }
    uVar1 = uVar9 * uVar15;
    if (uVar6 < uVar1) {
      if (uVar7 >> 1 < uVar1) {
        iVar13 = 6;
        if (uVar1 <= uVar7 * 3 >> 2) {
          iVar13 = 8;
        }
      }
      else {
        iVar13 = 0xc;
      }
    }
    else {
      iVar13 = 0x10;
    }
    if (iVar4 == 0 && iVar5 == 0) {
      uVar7 = uVar1 * 3 * iVar13 >> 1;
      *param_3 = uVar7;
    }
    else {
      uVar7 = (uVar1 * 3 * iVar13 >> 1) * 5 >> 2;
      *param_3 = uVar7;
    }
    iVar13 = HAL_HVD_EX_GetEVDHWBuffer();
    *param_3 = uVar7 + iVar13;
    if ((u32UartCtrl & 2) != 0) {
      printf("[HVD][INF]%s:","_HVD_EX_DemuxTS_ParseHEVCSPS");
      printf("[DemuxTS] EVD Memory usage = %ld\n",*param_3);
      if ((u32UartCtrl & 2) != 0) {
        printf("[HVD][INF]%s:","_HVD_EX_DemuxTS_ParseHEVCSPS");
        printf("[DemuxTS]Prog#X:HEVC,Width X Height = %dX%d.\n",uVar9,uVar15);
        return 1;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

