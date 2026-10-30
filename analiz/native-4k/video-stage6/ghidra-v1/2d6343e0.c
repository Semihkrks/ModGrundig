
undefined4 _MDrv_HVD_AUTH_IPCheck(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uRam2d73e804 = 0;
  switch(param_1 & 7) {
  case 0:
    iVar1 = MDrv_AUTH_IPCheck(0x1b);
    if (iVar1 == 1) {
      bModeSelectHD = 1;
      uRam2d73e804 = 1;
      iVar1 = MDrv_AUTH_IPCheck(0x1a);
      if (((iVar1 != 1) && (iVar1 = MDrv_AUTH_IPCheck(0x55), iVar1 != 1)) &&
         (iVar1 = MDrv_AUTH_IPCheck(0x56), iVar1 != 1)) {
        return 1;
      }
      bModeSupportDivXPlus = 1;
      return 1;
    }
    goto code_r0x2d634444;
  case 1:
    uVar2 = 0x21;
    break;
  case 2:
    uVar2 = 0x1c;
    break;
  case 3:
    uVar2 = 0x28;
    break;
  case 4:
    uVar2 = 0x3d;
    break;
  default:
    goto code_r0x2d634444;
  case 7:
    iVar1 = MDrv_AUTH_IPCheck(0x4b);
    if (iVar1 == 1) {
      bModeSelectHD = 1;
      uRam2d73e804 = 1;
      iVar1 = MDrv_AUTH_IPCheck(0x55);
      if (iVar1 == 1) {
        bModeSupportDivXHEVC_4K = 1;
      }
      iVar1 = MDrv_AUTH_IPCheck(0x56);
      if (iVar1 == 1) {
        bModeSupportDivXHEVC_1080P = 1;
        return 1;
      }
      return 1;
    }
    goto code_r0x2d634444;
  }
  iVar1 = MDrv_AUTH_IPCheck(uVar2);
  if (iVar1 == 1) {
    uRam2d73e804 = 1;
    bModeSelectHD = 1;
    return 1;
  }
code_r0x2d634444:
  if ((u32UartCtrl & 1) == 0) {
    return 0;
  }
  printf("[HVD][ERR]%s:","_MDrv_HVD_AUTH_IPCheck");
  printf("[%s]User using invaild key !!!\n","_MDrv_HVD_AUTH_IPCheck");
  return 0;
}

