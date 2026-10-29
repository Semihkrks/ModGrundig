
undefined4 HAL_VPU_EX_Init(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((u32VpuUartCtrl & 4) != 0) {
    printf("[VPU][DBG]%s:","HAL_VPU_EX_Init");
    printf("Inv=%d, clk=%d\n",(uint)(byte)param_1[1],*param_1);
  }
  iVar1 = iRam2d73d120;
  *(ushort *)(iRam2d73d120 + 0x16c0) = *(ushort *)(iRam2d73d120 + 0x16c0) & 0xfffd;
  uVar2 = *param_1;
  if ((uVar2 < 0x1d) && ((1 << (uVar2 & 0x1f) & 0x11111111U) != 0)) {
    *(ushort *)(iVar1 + 0x16c0) = *(ushort *)(iVar1 + 0x16c0) & 0xff83 | (ushort)uVar2 & 0x7c;
    HAL_VPU_EX_PowerCtrl(1);
    return 1;
  }
  *(ushort *)(iVar1 + 0x16c0) = *(ushort *)(iVar1 + 0x16c0) & 0xff83 | 0x1c;
  HAL_VPU_EX_PowerCtrl(1);
  return 1;
}

