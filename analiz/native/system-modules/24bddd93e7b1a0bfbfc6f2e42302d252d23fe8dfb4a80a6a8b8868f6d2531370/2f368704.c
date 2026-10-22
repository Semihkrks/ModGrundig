
void AESDMA_Set_OddInitVector(undefined2 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(PTR_DAT_2f379278 + -0x6db0);
  *(undefined2 *)(iVar1 + 0x24) = param_1[1];
  *(undefined2 *)(iVar1 + 0x20) = *param_1;
  *(undefined2 *)(iVar1 + 0x2c) = param_1[3];
  *(undefined2 *)(iVar1 + 0x28) = param_1[2];
  *(undefined2 *)(iVar1 + 0x34) = param_1[5];
  *(undefined2 *)(iVar1 + 0x30) = param_1[4];
  *(undefined2 *)(iVar1 + 0x3c) = param_1[7];
  *(undefined2 *)(iVar1 + 0x38) = param_1[6];
  return;
}

