
int MDrv_MasterSPI_Init(int param_1,byte param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = (*(code *)PTR_MDrv_MSPI_HW_Support_2f494edc)();
  if (iVar3 == 0) {
    iVar3 = 0x80;
    *PTR_gbInitFlag_2f494f04 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_MsOS_CreateMutex_2f494f38)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x46d0,1);
    *(int *)(PTR_DAT_2f494e08 + 0x4de0) = iVar3;
    if (iVar3 < 0) {
      (*(code *)PTR_printf_2f494e98)
                (PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x46dc,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4704,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x471c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4908,0x28f);
    }
    puVar2 = PTR_MDrv_MMIO_GetBASE_2f494ed4;
    puVar1 = PTR__u8MSPIDbgLevel_2f494ed0;
    *PTR__u8MSPIDbgLevel_2f494ed0 = 0;
    iVar3 = (*(code *)puVar2)(&local_1c,auStack_14,300);
    if ((iVar3 == 0) && (3 < (byte)*puVar1)) {
      (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4728);
    }
    iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f494ed4)(&local_20,auStack_18,0);
    if ((iVar3 == 0) && (3 < (byte)*puVar1)) {
      (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4754);
    }
    if (2 < param_2) {
      return 0x20;
    }
    (*(code *)PTR_HAL_MSPI_MMIOConfig_2f494e3c)(local_1c,local_20,param_2);
    puVar2 = PTR_gu8MSPICurConfig_2f494ea0;
    *PTR_gu8MSPICurConfig_2f494ea0 = *(undefined1 *)(param_1 + 0x5d);
    puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2f494e14;
    puVar2[1] = *(undefined1 *)(param_1 + 0x5e);
    puVar2[2] = *(undefined1 *)(param_1 + 0x5f);
    iVar3 = (*(code *)(puVar1 + 0x2690))(*(undefined1 *)(param_1 + 0x54));
    if (iVar3 == 0) {
      (*(code *)PTR_HAL_MSPI_IntEnable_2f494f28)(*(undefined1 *)(param_1 + 0x5c));
      (*(code *)PTR_HAL_MSPI_Init_2f494eac)();
      *PTR_gbInitFlag_2f494f04 = 1;
    }
  }
  return iVar3;
}

