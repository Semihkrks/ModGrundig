
void fusion_config_init(void)

{
  undefined1 uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  puVar2 = PTR_fusion_config_2f1586e8;
  iVar5 = *(int *)PTR_fusion_config_2f1586e8;
  if (*(int *)(iVar5 + 4) == 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_malloc_2f1585d8)(5);
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = PTR_LAB_2f1584e8[0x6614];
      *puVar3 = *(undefined4 *)(PTR_LAB_2f1584e8 + 0x6610);
      *(undefined1 *)(puVar3 + 1) = uVar1;
    }
    *(undefined4 **)(iVar5 + 4) = puVar3;
    iVar5 = *(int *)puVar2;
  }
  if (*(int *)(iVar5 + 8) != 0) {
    return;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_malloc_2f1585d8)(9);
  if (puVar3 != (undefined4 *)0x0) {
    uVar4 = *(undefined4 *)(PTR_LAB_2f1584e8 + 0x661c);
    uVar1 = PTR_LAB_2f1584e8[0x6620];
    *puVar3 = *(undefined4 *)(PTR_LAB_2f1584e8 + 0x6618);
    puVar3[1] = uVar4;
    *(undefined1 *)(puVar3 + 2) = uVar1;
  }
  *(undefined4 **)(iVar5 + 8) = puVar3;
  return;
}

