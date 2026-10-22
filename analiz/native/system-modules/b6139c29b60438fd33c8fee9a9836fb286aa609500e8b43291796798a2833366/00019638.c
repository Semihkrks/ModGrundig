
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* initList() */

int initList(void)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  int aiStack_80 [17];
  
  iVar1 = (**(code **)PTR_real_malloc_0002125c)(0x48);
  puVar7 = (uint *)PTR_list_000212ac;
  *(int *)PTR_list_000212ac = iVar1;
  if (iVar1 != 0) {
    iVar4 = iVar1;
    do {
      *(int *)(iVar4 + 8) = iVar1;
      iVar4 = iVar4 + 4;
    } while (iVar1 + 0x40 != iVar4);
    *(undefined4 *)((int)puVar7 + 4) = 0;
    return iVar1;
  }
  (*(code *)PTR_puts_000211c0)(PTR_cie_00020000_00020f38 + -0x1840);
  uVar6 = 1;
  puVar11 = PTR_exit_00021170;
  (*(code *)PTR_exit_00021170)();
  puVar10 = *(undefined4 **)(puVar11 + 0x7bf4);
  puVar8 = (uint *)*puVar10;
  iVar1 = puVar10[1];
  puVar2 = puVar8;
  if (-1 < iVar1) {
    piVar3 = aiStack_80 + iVar1;
    iVar4 = iVar1 + 2;
    puVar5 = puVar8;
LAB_00019730:
    do {
      puVar2 = puVar5;
      puVar5 = (uint *)puVar2[iVar4];
      if (puVar8 != puVar5) {
        if (*puVar5 < uVar6) goto LAB_00019730;
      }
      iVar9 = iVar1 + -1;
      *piVar3 = (int)puVar2;
      iVar4 = iVar1 + 1;
      piVar3 = piVar3 + -1;
      puVar5 = puVar2;
      iVar1 = iVar9;
    } while (-1 < iVar9);
  }
  if ((puVar8 == (uint *)puVar2[2]) || (iVar1 = 2, *(uint *)puVar2[2] != uVar6)) {
    for (iVar4 = 0;
        (iVar1 = (**(code **)(puVar11 + 0x7af4))(), iVar1 < 0x3fffffff && (iVar4 != 0xf));
        iVar4 = iVar4 + 1) {
    }
    if ((int)puVar10[1] < iVar4) {
      iVar1 = **(int **)(puVar11 + 0x7bf4);
      piVar3 = aiStack_80 + puVar10[1];
      do {
        piVar3[1] = iVar1;
        piVar3 = piVar3 + 1;
      } while (piVar3 != aiStack_80 + iVar4);
      puVar10[1] = iVar4;
    }
    puVar2 = (uint *)(*(code *)**(undefined4 **)(puVar11 + 0x7ba4))((iVar4 + 3) * 4);
    iVar1 = 1;
    if (puVar2 != (uint *)0x0) {
      *puVar2 = uVar6;
      piVar3 = aiStack_80;
      puVar2[1] = *puVar7;
      iVar1 = 0;
      puVar7 = puVar2;
      do {
        puVar8 = (uint *)(*piVar3 + (iVar1 + 2) * 4);
        iVar1 = iVar1 + 1;
        puVar7[2] = *puVar8;
        piVar3 = piVar3 + 1;
        *puVar8 = (uint)puVar2;
        puVar7 = puVar7 + 1;
      } while (iVar1 <= iVar4);
      iVar1 = 0;
    }
  }
  return iVar1;
}

