
void HAL_MSPI_Init(void)

{
  undefined *puVar1;
  int iVar2;
  
  if (*PTR__u8MSPIDbgLevel_2f494ed0 != '\0') {
    (*(code *)PTR_puts_2f494e60)(PTR___DT_MIPS_BASE_ADDRESS_2f494e14 + 0x4d18);
  }
  puVar1 = PTR_DAT_2f494e08;
  *(undefined2 *)(*(int *)(PTR_DAT_2f494e08 + 0x4df4) + 0x5c) = 0;
  iVar2 = *(int *)(puVar1 + 0x4df0);
  if (puVar1[0x4f81] == '\0') {
    *(undefined2 *)(iVar2 + 0x24) = 3;
    return;
  }
  *(undefined2 *)(iVar2 + 0x24) = 7;
  return;
}

