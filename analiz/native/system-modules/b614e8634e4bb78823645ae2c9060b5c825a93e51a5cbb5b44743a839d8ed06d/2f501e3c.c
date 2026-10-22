
undefined4 MDrv_PWS_IpPowerControl(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x14) && (param_2 != 0)) {
    (*(code *)PTR_MDrv_PWS_Init_2f513e10)(*(undefined4 *)(PTR_DAT_2f513d18 + 0x3e44));
    uVar1 = (*(code *)PTR_HAL_PWS_IpPowerControl_2f513d78)(param_1,param_2);
    return uVar1;
  }
  return 0;
}

