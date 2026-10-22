
bool MDrv_DSCMB2_SetPowerState(int param_1)

{
  short sVar1;
  code *pcVar2;
  
  pcVar2 = (code *)PTR_MDrv_DSCMB_Exit_2f3f8398;
  if ((param_1 != 1) && (pcVar2 = (code *)PTR_MDrv_DSCMB_Init_2f3f8320, param_1 != 2)) {
    (*(code *)PTR_printf_2f3f834c)
              (PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x7a28,
               PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x7b44,0xb71);
    return true;
  }
  sVar1 = (*pcVar2)();
  return sVar1 != 1;
}

