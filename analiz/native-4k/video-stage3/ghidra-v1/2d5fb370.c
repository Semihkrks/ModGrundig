
uint MDrv_HVD_EX_GetErrCode(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort local_38;
  ushort local_36;
  
  uVar3 = param_1 >> 0x10 & 0xff;
  if (*(char *)(pHVDDrvContext + uVar3 + 0x40) == '\0') {
    return 0;
  }
  uVar1 = HAL_HVD_EX_GetData(param_1,0x1205);
  if (uVar1 < 0x1008) {
    if (uVar1 < 0x1001) {
      if (uVar1 == 0) {
LAB_2d5fb410:
        uVar1 = HAL_HVD_EX_GetData(param_1,0x122c);
        if (((uVar1 & 1) == 0) || (bModeSupportDivXPlus != '\0')) {
          uVar1 = HAL_HVD_EX_GetData(param_1,0x122c);
          if (((uVar1 & 2) == 0) || (iVar2 = FUN_2d5faf30(param_1,&local_38,1), iVar2 != 1)) {
LAB_2d5fb444:
            uVar1 = 0;
            goto LAB_2d5fb44c;
          }
          if ((int)((uint)local_36 * (uint)local_38) < 0x1fe001) {
            uVar1 = 0;
            if ((bModeSupportDivXHEVC_4K != '\0') || (bModeSupportDivXHEVC_1080P != '\0'))
            goto LAB_2d5fb44c;
            uVar1 = 8;
          }
          else {
            uVar1 = 8;
            if (bModeSupportDivXHEVC_4K != '\0') goto LAB_2d5fb444;
          }
        }
        else {
          uVar1 = 8;
        }
      }
      else if (6 < uVar1) {
        if (uVar1 != 8) goto LAB_2d5fb410;
        uVar1 = 7;
      }
    }
  }
  else if ((uVar1 != 0x2001) && ((uVar1 < 0x2001 || (8 < uVar1 - 0x3001)))) goto LAB_2d5fb410;
  HAL_HVD_EX_SetData(param_1,0x1102,0);
LAB_2d5fb44c:
  *(uint *)(uVar3 * 0x5c4 + pHVDDrvContext + 0x138) = uVar1;
  return uVar1;
}

