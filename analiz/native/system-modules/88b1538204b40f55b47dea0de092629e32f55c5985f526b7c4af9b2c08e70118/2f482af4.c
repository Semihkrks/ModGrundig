
uint MDrv_MSPI_Init_Ext(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [8];
  
  puVar4 = PTR_gbInitFlag_2f494f04;
  puVar1 = PTR_DAT_2f494e08;
  if (*PTR_gbInitFlag_2f494f04 == '\x01') {
    (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x477c);
    return 1;
  }
  if (*(int *)(PTR_DAT_2f494e08 + 0x4de0) < 0) {
    iVar5 = (*(code *)PTR_MsOS_CreateMutex_2f494f38)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x46d0,1);
    *(int *)(puVar1 + 0x4de0) = iVar5;
    if (iVar5 < 0) {
      (*(code *)PTR_printf_2f494e98)
                (PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x46dc,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4704,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x471c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4944,0x10f);
    }
  }
  puVar2 = PTR_MDrv_MSPI_HW_Support_2f494edc;
  puVar1 = PTR__u8MSPIDbgLevel_2f494ed0;
  *PTR__u8MSPIDbgLevel_2f494ed0 = 0;
  iVar5 = (*(code *)puVar2)();
  if (iVar5 == 0) {
    *puVar4 = 0;
    uVar6 = 0x80;
  }
  else {
    iVar5 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f494ed4)(&local_24,auStack_1c,300);
    if ((iVar5 == 0) && (3 < (byte)*puVar1)) {
      (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4728);
    }
    iVar5 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f494ed4)(&local_28,auStack_20,0);
    if (iVar5 == 0) {
      if (*puVar1 != '\0') {
        (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4754);
      }
      return 0x40;
    }
    if (*puVar1 != '\0') {
      (*(code *)PTR_printf_2f494e98)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4798,local_24,local_28)
      ;
    }
    (*(code *)PTR_HAL_MSPI_MMIOConfig_2f494e3c)(local_24,local_28,param_1);
    puVar3 = PTR_gu8MSPICurConfig_2f494ea0;
    puVar2 = PTR___DT_MIPS_BASE_ADDRESS_2f494e14;
    PTR_gu8MSPICurConfig_2f494ea0[2] = 0;
    *(undefined2 *)puVar3 = 0;
    (*(code *)(puVar2 + 0x2690))(0);
    (*(code *)PTR_HAL_MSPI_IntEnable_2f494f28)(0);
    (*(code *)PTR_HAL_MSPI_Init_2f494eac)();
    if (*(int *)(PTR_DAT_2f494e08 + 0x4f74) != 0) {
      (*(code *)PTR_HAL_MSPI_CLOCK_Config_2f494e6c)();
    }
    if (*puVar1 != '\0') {
      (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x47b8);
    }
    pcVar7 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x1a50);
    *puVar4 = 1;
    uVar6 = (*pcVar7)(0);
    if (*puVar1 != '\0') {
      (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x47cc);
    }
    if ((uVar6 == 0) &&
       (uVar6 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x1ac4))(0), uVar6 == 0)) {
      (*(code *)PTR_HAL_MSPI_CLKConfigMax_2f494e2c)(2);
      (*(code *)PTR_HAL_MSPI_SetCLKTiming_2f494e34)(2,0);
      uVar6 = 0;
    }
    else {
      uVar6 = uVar6 | 1;
      if (3 < (byte)*puVar1) {
        (*(code *)PTR_printf_2f494e98)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4640,uVar6);
      }
    }
  }
  return uVar6;
}

