
undefined4 MDrv_HVD_EX_SetDynScalingParam(uint param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((u32UartCtrl & 0x20) != 0) {
    printf("[HVD][TRA]%s:","MDrv_HVD_EX_SetDynScalingParam");
  }
  uVar3 = param_1 >> 0x10 & 0xff;
  if (*(char *)(pHVDDrvContext + uVar3 + 0x40) != '\0') {
    iVar1 = uVar3 * 0x5c4 + pHVDDrvContext;
    *(uint *)(iVar1 + 0x10c) = *(uint *)(iVar1 + 0x10c) | 2;
    if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
      uVar2 = 2;
      if (*(char *)(pHVDDrvContext + uVar3 + 0x40) == '\0') {
        return 2;
      }
    }
    else {
      uVar2 = HAL_HVD_EX_SetCmd(param_1,0x2020b,*param_2);
      uVar2 = FUN_2d5f20f0(uVar2);
    }
    iVar1 = uVar3 * 0x5c4 + pHVDDrvContext;
    *(uint *)(iVar1 + 0x10c) = *(uint *)(iVar1 + 0x10c) & 0xfffffffd;
    return uVar2;
  }
  return 3;
}

