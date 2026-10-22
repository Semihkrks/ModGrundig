
undefined4 MDrv_AVD_SetPowerState(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_res0 [4];
  
  if (*(int *)(PTR_DAT_2efac2f8 + -0x3a3c) != 1) {
    return 0;
  }
  local_res0[0] = param_1;
  uVar1 = (*(code *)PTR_UtopiaIoctl_2efac458)
                    (*(undefined4 *)PTR_ppAVDInstant_2efac41c,0x30,local_res0);
  return uVar1;
}

