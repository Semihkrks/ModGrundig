
bool MDrv_VBI_SetPowerState(int param_1)

{
  short sVar1;
  code *pcVar2;
  
  pcVar2 = (code *)PTR_MDrv_VBI_Suspend_2f598818;
  if ((param_1 != 1) && (pcVar2 = (code *)PTR_MDrv_VBI_Resume_2f59882c, param_1 != 2)) {
    (*(code *)PTR_printf_2f598780)
              (PTR___DT_MIPS_BASE_ADDRESS_2f598694 + 0x7afc,PTR_DAT_2f598698 + -0x7fe8,0x7e8);
    return true;
  }
  sVar1 = (*pcVar2)();
  return sVar1 != 1;
}

