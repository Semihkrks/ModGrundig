
undefined4 MDrv_VIF_SetPowerState(int param_1)

{
  if (param_1 != 2) {
    return 0;
  }
  (*(code *)PTR_DRV_VIF_LoadVIFParameter_2f5bdb48)();
  (*(code *)PTR_DRV_VIF_Init_2f5bdabc)(PTR_VIF_InitData_2f5bda80,0xfc);
  return 1;
}

