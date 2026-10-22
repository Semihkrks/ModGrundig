
void HAL_SC_PowerCtrl(char param_1,char param_2)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR__regSCHWBase_2f578554;
  if (param_1 == '\0') {
    if (param_2 == '\0') {
      *(ushort *)(*(int *)PTR__regSCHWBase_2f578554 + 0x17b0) =
           *(ushort *)(*(int *)PTR__regSCHWBase_2f578554 + 0x17b0) | 1;
      iVar2 = *(int *)puVar1;
      *(ushort *)(iVar2 + 0x17b0) = *(ushort *)(iVar2 + 0x17b0) | 0x100;
      return;
    }
    *(ushort *)(*(int *)PTR__regSCHWBase_2f578554 + 0x17b0) =
         *(ushort *)(*(int *)PTR__regSCHWBase_2f578554 + 0x17b0) & 0xffe2 | 8;
    iVar2 = *(int *)puVar1;
    *(ushort *)(iVar2 + 0x17b0) = *(ushort *)(iVar2 + 0x17b0) & 0xfeff;
  }
  else if (param_1 == '\x01') {
    (*(code *)PTR_printf_2f57858c)(PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b60,0x10a);
    return;
  }
  return;
}

