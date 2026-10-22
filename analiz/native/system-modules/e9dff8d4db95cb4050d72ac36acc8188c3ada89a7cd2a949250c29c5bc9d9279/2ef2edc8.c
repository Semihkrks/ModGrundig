
undefined4 MApi_GFX_SetPowerState(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)PTR_pGEInstance_2ef4c3b4 == 0) {
    (*(code *)PTR_puts_2ef4c144)(PTR_DAT_2ef4c098 + -0x51ec);
    return 0x104;
  }
  local_18 = 0;
  local_10 = 0;
  local_c = 0;
  local_14 = param_1;
  iVar1 = (*(code *)PTR_UtopiaIoctl_2ef4c270)(*(int *)PTR_pGEInstance_2ef4c3b4,10,&local_18);
  if (iVar1 == 0) {
    return 0;
  }
  (*(code *)PTR_printf_2ef4c208)(PTR_DAT_2ef4c098 + -0x51c8,PTR_DAT_2ef4c098 + -0x5104,0xd61);
  return 1;
}

