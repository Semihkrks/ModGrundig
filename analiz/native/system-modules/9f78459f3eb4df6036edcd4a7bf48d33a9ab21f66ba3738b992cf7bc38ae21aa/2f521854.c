
undefined4 MDrv_RTC_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_2f532c68;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f532c68 + 0x2c30) = 1;
    puVar1[0x2d40] = 0;
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f532c68 + 0x2c30) != 1) {
      (*(code *)PTR_printf_2f532ccc)
                (PTR___DT_MIPS_BASE_ADDRESS_2f532c74 + 0x2a5c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f532c74 + 0x2b9c,0x1ee);
      return 3;
    }
    (*(code *)PTR_MDrv_RTC_Init_2f532ce8)
              (*(undefined4 *)(PTR_DAT_2f532c68 + 0x2d44),*(undefined4 *)(PTR_DAT_2f532c68 + 0x2d48)
               ,*(undefined4 *)(PTR_DAT_2f532c68 + 0x2d4c),
               *(undefined4 *)(PTR_DAT_2f532c68 + 0x2d50),*(undefined4 *)(PTR_DAT_2f532c68 + 0x2d54)
              );
    uVar2 = 1;
    *(undefined4 *)(puVar1 + 0x2c30) = 2;
  }
  else {
    (*(code *)PTR_printf_2f532ccc)
              (PTR___DT_MIPS_BASE_ADDRESS_2f532c74 + 0x2a94,
               PTR___DT_MIPS_BASE_ADDRESS_2f532c74 + 0x2b9c,500,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

