
void MDrv_PQ_Init_DisplayType(short param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(ushort *)PTR__u16PQDbgSwitch_2e6cd9d8 & 0x40) != 0) {
    (*(code *)PTR_printf_2e6cdbd4)
              (PTR_DAT_2e6ccdcc + -0x532c,PTR_DAT_2e6ccdcc + -0x4d58,param_2,param_1);
  }
  if (*PTR_gbPQBinEnable_2e6cd890 != '\0') {
    uVar1 = 1;
    if ((param_1 != 0x556) && (uVar1 = 0, param_1 == 0xf00)) {
      uVar1 = 2;
    }
    (*(code *)PTR_MDrv_PQBin_SetPanelID_2e6cd6c4)(uVar1);
    uVar1 = 0;
    if ((param_2 != 0) && (uVar1 = 2, param_2 == 1)) {
      uVar1 = 1;
    }
    (*(code *)PTR_MDrv_PQBin_SetDisplayType_2e6ccf98)(uVar1);
    return;
  }
  (*(code *)(PTR_LAB_2e6ccdc8 + 0x1cec))(param_1,param_2,0);
  return;
}

