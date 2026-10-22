
/* init_rs(int, int, int, int, int, int) */

uint * init_rs(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  uint *puVar11;
  int iVar12;
  
  puVar1 = PTR_uleb128_2f0c0a38;
  for (puVar11 = *(uint **)(PTR_uleb128_2f0c0a38 + 0xd4c); puVar11 != (uint *)0x0;
      puVar11 = (uint *)puVar11[0xb]) {
    if ((((puVar11[9] == param_6) && (puVar11[5] == param_5)) && (*puVar11 == param_1)) &&
       (((puVar11[10] == param_2 && (puVar11[6] == param_3)) && (puVar11[7] == param_4)))) {
      return puVar11;
    }
  }
  if (8 < (uint)param_1) {
    return (uint *)0x0;
  }
  if (param_3 < 0) {
    return (uint *)0x0;
  }
  uVar3 = 1 << (param_1 & 0x1fU);
  if ((int)uVar3 <= param_3) {
    return (uint *)0x0;
  }
  if (param_4 < 1) {
    return (uint *)0x0;
  }
  if ((int)uVar3 <= param_4) {
    return (uint *)0x0;
  }
  if (param_5 < 0) {
    return (uint *)0x0;
  }
  if ((int)uVar3 <= param_5) {
    return (uint *)0x0;
  }
  if (param_6 < 0) {
    return (uint *)0x0;
  }
  if ((int)((uVar3 - 1) - param_5) <= param_6) {
    return (uint *)0x0;
  }
  puVar11 = (uint *)(*(code *)PTR_calloc_2f0c0be0)(1,0x30);
  puVar2 = PTR_malloc_2f0c0aec;
  if (puVar11 == (uint *)0x0) {
    return (uint *)0x0;
  }
  *puVar11 = param_1;
  puVar11[9] = param_6;
  puVar11[1] = uVar3 - 1;
  uVar4 = (*(code *)puVar2)(uVar3);
  puVar11[2] = uVar4;
  if (uVar4 == 0) {
    (*(code *)PTR_free_2f0c0b98)(puVar11);
    return (uint *)0x0;
  }
  puVar5 = (undefined1 *)(*(code *)PTR_malloc_2f0c0aec)(puVar11[1] + 1);
  puVar11[3] = (uint)puVar5;
  if (puVar5 == (undefined1 *)0x0) {
    uVar3 = puVar11[2];
    goto LAB_2f0abd4c;
  }
  uVar4 = puVar11[1];
  uVar6 = puVar11[2];
  *puVar5 = (char)uVar4;
  *(undefined1 *)(uVar6 + uVar4) = 0;
  uVar4 = 1;
  if ((int)puVar11[1] < 1) {
LAB_2f0abb90:
    uVar3 = (*(code *)PTR_malloc_2f0c0aec)(param_5 + 1);
    puVar11[4] = uVar3;
    if (uVar3 != 0) {
      if (param_4 == 0) {
        trap(7);
      }
      puVar11[10] = param_2;
      puVar11[6] = param_3;
      puVar11[7] = param_4;
      puVar11[5] = param_5;
      iVar8 = 1;
      if (1 % param_4 != 0) {
        uVar3 = puVar11[1];
        iVar8 = uVar3 + 1;
        do {
          iVar12 = iVar8 % param_4;
          if (param_4 == 0) {
            trap(7);
          }
          iVar8 = iVar8 + uVar3;
        } while (iVar12 != 0);
        iVar8 = iVar8 - uVar3;
      }
      if (param_4 == 0) {
        trap(7);
      }
      puVar11[8] = iVar8 / param_4;
      *(undefined1 *)puVar11[4] = 1;
      if (0 < param_5) {
        iVar8 = param_4 * param_3;
        iVar12 = 0;
        while( true ) {
          *(undefined1 *)(puVar11[4] + iVar12 + 1) = 1;
          if (iVar12 != 0) {
            iVar9 = iVar12 + -1;
            do {
              uVar3 = puVar11[4];
              pbVar10 = (byte *)(uVar3 + iVar9 + 1);
              if (*pbVar10 == 0) {
                *pbVar10 = *(byte *)(uVar3 + iVar9);
              }
              else {
                uVar4 = puVar11[1];
                iVar7 = (uint)*(byte *)(puVar11[3] + (uint)*pbVar10) + iVar8;
                if ((int)uVar4 <= iVar7) {
                  uVar6 = iVar7 - uVar4;
                  do {
                    iVar7 = (uVar6 & uVar4) + ((int)uVar6 >> (*puVar11 & 0x1f));
                    uVar6 = iVar7 - uVar4;
                  } while ((int)uVar4 <= iVar7);
                }
                *pbVar10 = *(byte *)(uVar3 + iVar9) ^ *(byte *)(puVar11[2] + iVar7);
              }
              iVar9 = iVar9 + -1;
            } while (iVar9 != -1);
          }
          uVar3 = puVar11[1];
          iVar9 = iVar8 + (uint)*(byte *)(puVar11[3] + (uint)*(byte *)puVar11[4]);
          if ((int)uVar3 <= iVar9) {
            uVar4 = iVar9 - uVar3;
            do {
              iVar9 = (uVar4 & uVar3) + ((int)uVar4 >> (*puVar11 & 0x1f));
              uVar4 = iVar9 - uVar3;
            } while ((int)uVar3 <= iVar9);
            iVar9 = uVar4 + uVar3;
          }
          iVar12 = iVar12 + 1;
          *(byte *)puVar11[4] = *(byte *)(puVar11[2] + iVar9);
          if (param_5 <= iVar12) break;
          iVar8 = iVar8 + param_4;
        }
      }
      iVar8 = 0;
      do {
        pbVar10 = (byte *)(puVar11[4] + iVar8);
        iVar8 = iVar8 + 1;
        *pbVar10 = *(byte *)(puVar11[3] + (uint)*pbVar10);
      } while (iVar8 <= param_5);
      uVar3 = *(uint *)(puVar1 + 0xd4c);
      *(uint **)(puVar1 + 0xd4c) = puVar11;
      puVar11[0xb] = uVar3;
      return puVar11;
    }
  }
  else {
    iVar8 = 0;
    do {
      uVar6 = uVar4 << 1;
      *(char *)(puVar11[3] + uVar4) = (char)iVar8;
      if ((uVar3 & uVar6) != 0) {
        uVar6 = uVar6 ^ param_2;
      }
      *(char *)(puVar11[2] + iVar8) = (char)uVar4;
      iVar8 = iVar8 + 1;
      uVar4 = uVar6 & puVar11[1];
    } while (iVar8 < (int)puVar11[1]);
    if (uVar4 == 1) goto LAB_2f0abb90;
  }
  (*(code *)PTR_free_2f0c0b98)(puVar11[2]);
  uVar3 = puVar11[3];
LAB_2f0abd4c:
  (*(code *)PTR_free_2f0c0b98)(uVar3);
  (*(code *)PTR_free_2f0c0b98)(puVar11);
  return (uint *)0x0;
}

