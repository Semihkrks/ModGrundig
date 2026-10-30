
undefined4 MDrv_HVD_EX_SetExternalDSBuffer(uint param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = param_1 >> 0x10 & 0xff;
  iVar1 = HAL_HVD_EX_GetShmAddr();
  iVar6 = pHVDDrvContext;
  uVar8 = *param_2;
  if ((u32UartCtrl & 0x20) != 0) {
    printf("[HVD][TRA]%s:","MDrv_HVD_EX_SetExternalDSBuffer");
  }
  if (*(char *)(pHVDDrvContext + uVar7 + 0x40) == '\0') {
    return 3;
  }
  iVar5 = uVar7 * 0x5c4;
  *(uint *)(pHVDDrvContext + iVar5 + 0x10c) = *(uint *)(pHVDDrvContext + iVar5 + 0x10c) | 2;
  if (((iVar1 == 0) || (iVar6 + iVar5 + 0x60 == 0)) || (param_2[1] < 0xc00)) {
    return 0;
  }
  uVar4 = *(uint *)(iVar6 + iVar5 + 100);
  if (*(uint *)(iVar6 + iVar5 + 0x88) < uVar4) {
    iVar5 = 0;
LAB_2d5fe4e4:
    if ((*param_2 < uVar4) || (iVar2 = 1, uVar4 == 0)) {
      iVar2 = 0;
    }
    else {
      uVar8 = uVar8 - uVar4;
    }
    if (iVar5 != iVar2) {
      iVar5 = HAL_VPU_EX_MIU1BASE();
      *(uint *)(iVar1 + 0xd0c) = iVar5 + uVar8;
      goto LAB_2d5fe514;
    }
  }
  else if (uVar4 != 0) {
    iVar5 = 1;
    goto LAB_2d5fe4e4;
  }
  *(uint *)(iVar1 + 0xd0c) = uVar8;
LAB_2d5fe514:
  *(uint *)(iVar1 + 0xce4) = param_2[1];
  MsOS_FlushMemory();
  uVar3 = HAL_HVD_EX_SetCmd(param_1,0x20221,1);
  uVar3 = FUN_2d5f20f0(uVar3);
  iVar6 = iVar6 + uVar7 * 0x5c4;
  *(byte *)(iVar6 + 0x611) = *(byte *)(iVar6 + 0x611) | 1;
  *(uint *)(iVar6 + 0x614) = *param_2;
  iVar6 = pHVDDrvContext + uVar7 * 0x5c4;
  *(uint *)(iVar6 + 0x10c) = *(uint *)(iVar6 + 0x10c) & 0xfffffffd;
  return uVar3;
}

