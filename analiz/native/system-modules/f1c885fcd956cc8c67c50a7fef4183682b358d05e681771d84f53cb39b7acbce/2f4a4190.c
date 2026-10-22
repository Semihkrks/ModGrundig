
void _MDrv_PCMCIA_InitHW(char param_1)

{
  (*(code *)PTR_HAL_PCMCIA_ClkCtrl_2f4b6e5c)(1);
  (*(code *)PTR_HAL_PCMCIA_Read_Byte_2f4b6de4)(0x10);
  (*(code *)PTR_HAL_PCMCIA_Write_Byte_2f4b6ddc)(0x10,0x41);
  (*(code *)PTR_HAL_PCMCIA_Write_Byte_2f4b6ddc)(10,0x7c);
  if (param_1 == '\0') {
    (*(code *)PTR_MsOS_DisableInterrupt_2f4b6d74)(0x15);
    (*(code *)PTR_MsOS_DetachInterrupt_2f4b6d9c)(0x15);
    (*(code *)PTR_MsOS_AttachInterrupt_2f4b6dcc)(0x15,PTR___DT_MIPS_BASE_ADDRESS_2f4b6d14 + 0x4254);
  }
  (*(code *)PTR_MsOS_EnableInterrupt_2f4b6e84)(0x15);
  return;
}

