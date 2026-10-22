
bool MDrv_DMX_TTX_SetPowerState(int param_1)

{
  short sVar1;
  code *pcVar2;
  
  pcVar2 = (code *)PTR_MDrv_DMX_TTX_Suspend_2f5986d0;
  if ((param_1 != 1) && (pcVar2 = (code *)PTR_MDrv_DMX_TTX_Resume_2f5987e4, param_1 != 2)) {
    (*(code *)PTR_printf_2f598780)
              (PTR___DT_MIPS_BASE_ADDRESS_2f598694 + 0x7afc,
               PTR___DT_MIPS_BASE_ADDRESS_2f598694 + 0x7b20,0x2df);
    return true;
  }
  sVar1 = (*pcVar2)();
  return sVar1 != 1;
}

