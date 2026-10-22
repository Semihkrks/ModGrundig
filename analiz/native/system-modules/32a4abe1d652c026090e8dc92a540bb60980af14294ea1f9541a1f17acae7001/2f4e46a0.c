
undefined4 HAL_PWM_Init(void)

{
  undefined *puVar1;
  ushort uVar2;
  
  uVar2 = (*(code *)PTR_HAL_PWM_Read2Byte_2f4f5db4)(0x20);
  puVar1 = PTR_DAT_2f4f5c68;
  *(ushort *)(PTR_DAT_2f4f5c68 + 0x5e32) = uVar2;
  if ((uVar2 & 0x10) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5a64);
  }
  if ((*(ushort *)(puVar1 + 0x5e32) & 0x20) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5a70);
  }
  if ((*(ushort *)(puVar1 + 0x5e32) & 0x40) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5a7c);
  }
  if ((*(ushort *)(puVar1 + 0x5e32) & 0x80) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5a88);
  }
  if ((*(ushort *)(puVar1 + 0x5e32) & 0x100) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5a94);
  }
  if ((*(ushort *)(puVar1 + 0x5e32) & 0x400) != 0) {
    (*(code *)PTR_puts_2f4f5cbc)(PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5aa0);
  }
  return 1;
}

