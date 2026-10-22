
undefined4 MDrv_HWI2C_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_2f4346e8;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f4346e8 + 0x4614) = 1;
    puVar1[0x4830] = 0;
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f4346e8 + 0x4614) != 1) {
      (*(code *)PTR_printf_2f43477c)
                (PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x44e4,
                 PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x4534,0x4c5);
      return 3;
    }
    (*(code *)PTR_MDrv_HWI2C_Init_2f434708)(*(undefined4 *)(PTR_DAT_2f4346e8 + 0x4610));
    uVar2 = 1;
    *(undefined4 *)(puVar1 + 0x4614) = 2;
  }
  else {
    (*(code *)PTR_printf_2f43477c)
              (PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x451c,
               PTR___DT_MIPS_BASE_ADDRESS_2f4346f4 + 0x4534,0x4cb,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

