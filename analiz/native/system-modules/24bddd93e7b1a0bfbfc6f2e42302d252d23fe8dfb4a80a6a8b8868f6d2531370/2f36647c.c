
void AESDMA_Set_InitVector(undefined2 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(PTR_DAT_2f379278 + -0x6dbc);
  *(undefined2 *)(iVar1 + 100) = param_1[1];
  *(undefined2 *)(iVar1 + 0x60) = *param_1;
  *(undefined2 *)(iVar1 + 0x6c) = param_1[3];
  *(undefined2 *)(iVar1 + 0x68) = param_1[2];
  *(undefined2 *)(iVar1 + 0x74) = param_1[5];
  *(undefined2 *)(iVar1 + 0x70) = param_1[4];
  *(undefined2 *)(iVar1 + 0x7c) = param_1[7];
  *(undefined2 *)(iVar1 + 0x78) = param_1[6];
  return;
}

