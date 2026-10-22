
undefined4 MDrv_MSPI_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_gbInitFlag_2f494f04;
  puVar1 = PTR_DAT_2f494e08;
  if (param_1 == 1) {
    iVar3 = *(int *)(PTR_DAT_2f494e08 + 0x4de0);
    *(undefined4 *)(PTR_DAT_2f494e08 + 0x4dec) = 1;
    *puVar2 = 0;
    if (0 < iVar3) {
      (*(code *)PTR_MsOS_DeleteMutex_2f494f24)();
      return 0;
    }
  }
  else {
    if (param_1 != 2) {
      (*(code *)PTR_printf_2f494e98)
                (PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4820,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x491c,0x277,param_1);
      return 1;
    }
    if (*(int *)(PTR_DAT_2f494e08 + 0x4dec) != 1) {
      (*(code *)PTR_printf_2f494e98)
                (PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x47e8,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x491c,0x271);
      return 1;
    }
    (*(code *)PTR_MDrv_MSPI_Init_Ext_2f494e38)(0);
    *(undefined4 *)(puVar1 + 0x4dec) = 2;
  }
  return 0;
}

