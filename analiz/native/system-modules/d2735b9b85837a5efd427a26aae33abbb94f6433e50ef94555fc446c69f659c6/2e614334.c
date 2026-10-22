
ushort HAL_TSP_STC_Update_Disable(undefined4 param_1,char param_2)

{
  ushort uVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    iVar2 = *(int *)(PTR_UtopiaResourceObtain_2e64c808 + -0x2b78);
    *(undefined2 *)(iVar2 + 0x168) = *(undefined2 *)(iVar2 + 0x168);
    uVar1 = *(ushort *)(iVar2 + 0x16c) | 0x100;
    *(ushort *)(iVar2 + 0x16c) = uVar1;
    return uVar1;
  }
  iVar2 = *(int *)(PTR_UtopiaResourceObtain_2e64c808 + -0x2b78);
  *(undefined2 *)(iVar2 + 0x168) = *(undefined2 *)(iVar2 + 0x168);
  *(ushort *)(iVar2 + 0x16c) = *(ushort *)(iVar2 + 0x16c) & 0xfeff;
  return *(ushort *)(iVar2 + 0x168);
}

