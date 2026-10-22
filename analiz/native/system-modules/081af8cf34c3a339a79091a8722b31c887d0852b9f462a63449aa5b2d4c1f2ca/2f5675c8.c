
void HAL_SC_Init(char param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar2 = PTR__regSCHWBase_2f578554;
  (*(code *)PTR_puts_2f57855c)(PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7bb4);
  puVar1 = PTR_HAL_SC_PowerCtrl_2f578610;
  *(ushort *)(*(int *)puVar2 + 0x3d40) = *(ushort *)(*(int *)puVar2 + 0x3d40) & 0x7fff;
  (*(code *)puVar1)(param_1,1);
  puVar4 = PTR__regSCBase_2f578574;
  puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2f578514;
  if (param_1 == '\0') {
    *(undefined1 *)(*(int *)PTR__regSCBase_2f578574 + 0xc) = 0x40;
    puVar3 = PTR_puts_2f57855c;
    *(byte *)(*(int *)puVar4 + 0x60) = *(byte *)(*(int *)puVar4 + 0x60) | 0x3e;
    *(undefined1 *)(*(int *)puVar4 + 0x48) = 0;
    (*(code *)puVar3)(puVar1 + 0x7bc4);
    *(ushort *)(*(int *)puVar2 + 0x3c18) = *(ushort *)(*(int *)puVar2 + 0x3c18) | 0x48;
    *(ushort *)(*(int *)puVar2 + 0x3db8) = *(ushort *)(*(int *)puVar2 + 0x3db8) | 0x20;
    *(ushort *)(*(int *)puVar2 + 0x3c48) = *(ushort *)(*(int *)puVar2 + 0x3c48) & 0xfff8;
    *(ushort *)(*(int *)puVar2 + 0x3c0c) = *(ushort *)(*(int *)puVar2 + 0x3c0c) & 0xfcff;
    *(ushort *)(*(int *)puVar2 + 0x3d44) = *(ushort *)(*(int *)puVar2 + 0x3d44) & 0xc7ff;
  }
  else {
    *(undefined1 *)(*(int *)(PTR__regSCBase_2f578574 + 4) + 0xc) = 0x40;
    *(byte *)(*(int *)(puVar4 + 4) + 0x60) = *(byte *)(*(int *)(puVar4 + 4) + 0x60) | 0x3e;
    *(undefined1 *)(*(int *)(puVar4 + 4) + 0x48) = 0;
    if (param_1 == '\x01') {
      (*(code *)PTR_printf_2f57858c)(PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b60,0xeb);
      return;
    }
  }
  return;
}

