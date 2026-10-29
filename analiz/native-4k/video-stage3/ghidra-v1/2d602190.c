
int MDrv_HVD_EX_Init(uint param_1,undefined4 *param_2,uint *param_3,undefined1 param_4,byte param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  void *local_38;
  uint local_34;
  int local_30;
  int *local_2c;
  
  iVar8 = pHVDDrvContext;
  local_34 = (uint)param_5;
  if ((u32UartCtrl & 0x20) != 0) {
    printf("[HVD][TRA]%s:","MDrv_HVD_EX_Init");
  }
  *(undefined1 *)(pHVDDrvContext + 0x5ea8) = param_4;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (uint *)0x0)) {
    if ((u32UartCtrl & 1) == 0) {
      return 2;
    }
    printf("[HVD][ERR]%s:","MDrv_HVD_EX_Init");
    puts("Init params are invalid");
    return 2;
  }
  iVar2 = _MDrv_HVD_AUTH_IPCheck(*param_3);
  if (iVar2 == 0) {
    if ((u32UartCtrl & 1) != 0) {
      printf("[HVD][ERR]%s:","MDrv_HVD_EX_Init");
      printf("[%s]User using invaild key !!!\n","MDrv_HVD_EX_Init");
      return 2;
    }
    return 2;
  }
  HAL_HVD_EX_SetDrvCtrlsBase(pHVDDrvContext + 0x60);
  local_48 = 0;
  local_44 = 0;
  iVar2 = MDrv_MMIO_GetBASE(&local_44,&local_48,0);
  if (iVar2 == 0) {
    if ((u32UartCtrl & 1) == 0) {
      return 0;
    }
    printf("[HVD][ERR]%s:","MDrv_HVD_EX_Init");
    puts("MMIO_GetBASE failure");
    return 0;
  }
  if ((u32UartCtrl & 4) != 0) {
    printf("[HVD][DBG]%s:","MDrv_HVD_EX_Init");
    printf("u32RiuBaseAdd=0x%lx\n",local_44);
  }
  HAL_HVD_EX_InitRegBase(local_44);
  HAL_HVD_EX_SetHwRegBase(param_1,*param_3);
  if ((u32UartCtrl & 4) != 0) {
    printf("[HVD][DBG]%s:","MDrv_HVD_EX_Init");
    printf("system call type: Mutex:%d clock:%d delay:%d asm_sync:%d\n",1,1,2,3);
  }
  if ((u32UartCtrl & 2) != 0) {
    iVar2 = MsOS_GetSystemTime();
    MsOS_DelayTask(5);
    iVar5 = MsOS_GetSystemTime();
    if ((u32UartCtrl & 4) != 0) {
      printf("[HVD][DBG]%s:","MDrv_HVD_EX_Init");
      printf("MSOS API check: 1st:%lu 2nd:%lu delay:%lu dif:%lu\n",iVar2,iVar5,5,iVar5 - iVar2);
    }
  }
  uVar11 = param_1 >> 0x10 & 0xff;
  if ((*(char *)(uVar11 * 0x5c4 + pHVDDrvContext + 0x60) != '\0') && ((u32UartCtrl & 1) != 0)) {
    printf("[HVD][ERR]%s:","MDrv_HVD_EX_Init");
    puts("re-init HVD Driver");
  }
  if ((*param_3 & 0xf) == 7) {
    iVar2 = MDrv_HVD_checkISR(param_1,uVar11,2);
  }
  else {
    iVar2 = MDrv_HVD_checkISR(param_1,uVar11,1);
  }
  if (iVar2 == 0) {
    HAL_HVD_EX_EnableISR(param_1,0);
  }
  uVar3 = HAL_VPU_EX_GetSHMAddr();
  iVar2 = uVar11 * 0x5c4;
  HAL_VPU_EX_SetShareInfoAddr(param_1,uVar3);
  iVar5 = pHVDDrvContext;
  local_38 = (void *)(pHVDDrvContext + iVar2 + 0x60);
  memset(local_38,0,0x5c4);
  *(undefined1 *)(iVar5 + iVar2 + 0x13d) = 1;
  uVar9 = iVar5 + iVar2 + 0xcc;
  HAL_HVD_EX_SetPreCtrlVariables(param_1,pHVDDrvContext + uVar11 * 0x20 + 0x5ca8);
  if (((uVar9 | (uint)param_3) & 3) == 0) {
    iVar2 = 0;
    puVar4 = param_3;
    do {
      puVar6 = (uint *)(uVar9 + iVar2);
      iVar2 = iVar2 + 4;
      *puVar6 = *puVar4;
      puVar4 = (uint *)((int)param_3 + iVar2);
    } while (iVar2 != 0x30);
    iVar2 = param_2[7];
  }
  else {
    iVar2 = 0;
    puVar4 = param_3;
    do {
      puVar7 = (undefined1 *)(uVar9 + iVar2);
      iVar2 = iVar2 + 1;
      *puVar7 = (char)*puVar4;
      puVar4 = (uint *)((int)param_3 + iVar2);
    } while (iVar2 != 0x30);
    iVar2 = param_2[7];
  }
  if (iVar2 == 0) {
    uVar3 = __hal_miu1_base();
    iVar2 = uVar11 * 0x5c4 + iVar5;
    *(undefined4 *)(iVar2 + 100) = uVar3;
    uVar3 = __hal_miu1_base();
    *(undefined4 *)(iVar2 + 0x68) = uVar3;
  }
  else {
    *(int *)(uVar11 * 0x5c4 + iVar5 + 100) = iVar2;
  }
  iVar2 = uVar11 * 0x5c4 + iVar5;
  *(undefined4 *)(iVar2 + 0xc0) = *param_2;
  *(undefined4 *)(iVar2 + 0x6c) = param_2[1];
  *(undefined4 *)(iVar2 + 0x70) = param_2[2];
  *(undefined4 *)(iVar2 + 0x74) = param_2[3];
  *(undefined4 *)(iVar2 + 0x78) = param_2[4];
  *(undefined4 *)(iVar2 + 0x7c) = param_2[5];
  *(undefined4 *)(iVar2 + 0x80) = param_2[6];
  *(undefined4 *)(iVar2 + 0x84) = param_2[8];
  *(undefined4 *)(iVar2 + 0x88) = param_2[9];
  *(undefined4 *)(iVar2 + 0x8c) = param_2[10];
  *(undefined4 *)(iVar2 + 0x90) = param_2[0xb];
  *(undefined4 *)(iVar2 + 0x94) = param_2[0xc];
  *(undefined4 *)(iVar2 + 0x98) = param_2[0xd];
  *(undefined4 *)(iVar2 + 0xc4) = param_2[0x14];
  *(undefined4 *)(iVar2 + 200) = param_2[0x15];
  if (((*(uint *)(iVar2 + 0xcc) & 0xf) == 3) && ((*(uint *)(iVar2 + 0xcc) & 0x400) != 0)) {
    local_3c = uVar11 + 1;
    iVar2 = local_3c * 0x5c4;
    local_40 = pHVDDrvContext;
    memset((void *)(pHVDDrvContext + iVar2 + 0x60),0,0x5c4);
    uVar9 = local_40 + iVar2 + 0xcc;
    if (((uVar9 | (uint)param_3) & 3) == 0) {
      iVar2 = 0;
      puVar4 = param_3;
      do {
        puVar6 = (uint *)(uVar9 + iVar2);
        iVar2 = iVar2 + 4;
        *puVar6 = *puVar4;
        puVar4 = (uint *)((int)param_3 + iVar2);
      } while (iVar2 != 0x30);
      iVar2 = param_2[7];
    }
    else {
      iVar2 = 0;
      puVar4 = param_3;
      do {
        puVar7 = (undefined1 *)(uVar9 + iVar2);
        iVar2 = iVar2 + 1;
        *puVar7 = (char)*puVar4;
        puVar4 = (uint *)((int)param_3 + iVar2);
      } while (iVar2 != 0x30);
      iVar2 = param_2[7];
    }
    if (iVar2 == 0) {
      uVar3 = __hal_miu1_base();
      iVar2 = local_40 + local_3c * 0x5c4;
      *(undefined4 *)(iVar2 + 100) = uVar3;
      uVar3 = __hal_miu1_base();
      *(undefined4 *)(iVar2 + 0x68) = uVar3;
    }
    else {
      *(int *)(local_40 + local_3c * 0x5c4 + 100) = iVar2;
    }
    iVar10 = uVar11 * 0x5c4 + iVar5;
    *(undefined4 *)(iVar10 + 0x9c) = param_2[0xe];
    *(undefined4 *)(iVar10 + 0xa0) = param_2[0xf];
    iVar2 = local_40 + local_3c * 0x5c4;
    *(uint *)(iVar10 + 0xa4) = (uint)param_2[0x10] >> 1;
    *(uint *)(iVar2 + 0x9c) = ((uint)param_2[0x10] >> 1) + param_2[0xe];
    *(uint *)(iVar2 + 0xa0) = ((uint)param_2[0x10] >> 1) + param_2[0xf];
    *(uint *)(iVar2 + 0xa4) = (uint)param_2[0x10] >> 1;
    uVar3 = param_2[0x11];
    *(undefined4 *)(iVar2 + 0xa8) = uVar3;
    *(undefined4 *)(iVar10 + 0xa8) = uVar3;
    uVar3 = param_2[0x12];
    *(undefined4 *)(iVar2 + 0xac) = uVar3;
    *(undefined4 *)(iVar10 + 0xac) = uVar3;
    uVar3 = param_2[0x13];
    *(undefined4 *)(iVar2 + 0xb0) = uVar3;
    *(undefined4 *)(iVar10 + 0xb0) = uVar3;
    *(undefined4 *)(iVar2 + 0x84) = param_2[8];
    *(undefined4 *)(iVar2 + 0x88) = param_2[9];
    *(undefined4 *)(iVar2 + 0x8c) = param_2[10];
    if ((u32UartCtrl & 2) == 0) goto LAB_2d60260c;
    local_30 = iVar10;
    printf("[HVD][INF]%s:","_HVD_EX_InitVariables");
    printf("[MVC] Bitstream buffer: 1st = [0x%lx, 0x%lx, 0x%lx], 2nd = [0x%lx, 0x%lx, 0x%lx].\n",
           *(undefined4 *)(local_30 + 0x9c),*(undefined4 *)(local_30 + 0xa0),
           *(undefined4 *)(local_30 + 0xa4),*(undefined4 *)(iVar2 + 0x9c),
           *(undefined4 *)(iVar2 + 0xa0),*(undefined4 *)(iVar2 + 0xa4));
  }
  else {
    iVar2 = uVar11 * 0x5c4 + iVar5;
    *(undefined4 *)(iVar2 + 0x9c) = param_2[0xe];
    *(undefined4 *)(iVar2 + 0xa0) = param_2[0xf];
    *(undefined4 *)(iVar2 + 0xa4) = param_2[0x10];
    *(undefined4 *)(iVar2 + 0xa8) = param_2[0x11];
    *(undefined4 *)(iVar2 + 0xac) = param_2[0x12];
    *(undefined4 *)(iVar2 + 0xb0) = param_2[0x13];
  }
  if ((u32UartCtrl & 2) != 0) {
    printf("[HVD][INF]%s:","_HVD_EX_InitVariables");
    iVar2 = uVar11 * 0x5c4 + iVar5;
    printf("HVD mmap: MIU1base:0x%lx, MIU2base:0x%lx,FW(type:%d addr=0x%lx size=0x%lx), VLC(addr=0x%lx size=0x%lx), Code(addr=0x%lx size=0x%lx), FB(addr=0x%lx size=0x%lx), Bit(addr=0x%lx size=0x%lx), Drv(addr=0x%lx size=0x%lx)\n"
           ,*(undefined4 *)(iVar2 + 100),*(undefined4 *)(iVar2 + 0x68),*(undefined4 *)(iVar2 + 0xc0)
           ,*(undefined4 *)(iVar2 + 0x70),*(undefined4 *)(iVar2 + 0x74),
           *(undefined4 *)(iVar2 + 0x7c),*(undefined4 *)(iVar2 + 0x80),*(undefined4 *)(iVar2 + 0x88)
           ,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(iVar2 + 0x94),
           *(undefined4 *)(iVar2 + 0x98),*(undefined4 *)(iVar2 + 0xa0),*(undefined4 *)(iVar2 + 0xa4)
           ,*(undefined4 *)(iVar2 + 0xac),*(undefined4 *)(iVar2 + 0xb0));
  }
LAB_2d60260c:
  uVar1 = HAL_HVD_EX_GetCorretClock((short)param_3[7]);
  iVar2 = uVar11 * 0x5c4 + iVar5;
  *(undefined2 *)(iVar2 + 0xe8) = uVar1;
  uVar1 = MDrv_SYS_GetChipRev();
  *(undefined2 *)(iVar2 + 0xea) = uVar1;
  if ((u32UartCtrl & 2) != 0) {
    printf("[HVD][INF]%s:","_HVD_EX_InitVariables");
    printf("[VDEC]pCtrl->InitParams.u16ChipECONum : %d \n ",(uint)*(ushort *)(iVar2 + 0xea));
  }
  iVar2 = uVar11 * 0x5c4 + iVar5;
  *(undefined4 *)(iVar2 + 0x200) = 0;
  *(undefined4 *)(iVar2 + 0x1fc) = *(undefined4 *)(iVar2 + 0x200);
  *(undefined4 *)(iVar2 + 0x1e4) = 0;
  *(undefined1 *)(iVar2 + 0x1cd) = 0xff;
  *(undefined4 *)(iVar2 + 0x1ec) = 0;
  *(undefined4 *)(iVar2 + 0x100) = 100;
  *(undefined4 *)(iVar2 + 500) = 0;
  *(undefined1 *)(iVar2 + 0x1d1) = 0;
  *(undefined4 *)(iVar2 + 0x1e8) = 0;
  *(undefined1 *)(iVar2 + 0x1d0) = 0;
  *(undefined4 *)(iVar2 + 0x1f0) = 0;
  *(undefined1 *)(iVar2 + 0x1ce) = 0;
  *(undefined4 *)(iVar2 + 0x204) = 0;
  *(undefined4 *)(iVar2 + 0x208) = 0;
  *(undefined4 *)(iVar2 + 0x1d4) = 0;
  *(undefined4 *)(iVar2 + 0x1dc) = 0;
  *(undefined1 *)(iVar2 + 0x1d2) = 0;
  *(undefined4 *)(iVar2 + 0x1d8) = 0;
  *(undefined4 *)(iVar2 + 0x1e0) = 0;
  *(undefined4 *)(iVar2 + 0x1f8) = 0;
  *(undefined1 *)(iVar2 + 0x1d3) = 0;
  *(undefined1 *)(iVar2 + 0x1cf) = 0;
  *(undefined1 *)(iVar2 + 0xfd) = 1;
  if ((*(byte *)((int)param_3 + 0x1a) & 8) != 0) {
    *(undefined1 *)(iVar2 + 0x1a4) = 1;
  }
  HAL_HVD_EX_SetMiuBurstLevel(local_38,0xffffffff);
  iVar8 = iVar8 + uVar11 * 0x5c4;
  *(undefined4 *)(iVar5 + uVar11 * 0x5c4 + 0x60c) = 0;
  *(char *)(iVar8 + 0x61d) = (char)local_34;
  if ((*param_3 & 0xf) == 7) {
    *(undefined4 *)(iVar8 + 0x1bc) = 2;
  }
  else {
    *(undefined4 *)(iVar8 + 0x1bc) = 1;
  }
  iVar8 = uVar11 * 0x5c4;
  *(uint *)(pHVDDrvContext + iVar8 + 0x10c) = *(uint *)(pHVDDrvContext + iVar8 + 0x10c) | 2;
  iVar5 = FUN_2d5fea94(param_1,1);
  iVar2 = pHVDDrvContext;
  local_2c = &pHVDDrvContext;
  if (iVar5 == 1) {
    uVar3 = HAL_HVD_EX_GetBBUId(param_1);
    *(undefined4 *)(iVar2 + iVar8 + 0x620) = uVar3;
    if (*(int *)(*local_2c + iVar8 + 0x620) == -1) {
      if ((u32UartCtrl & 1) != 0) {
        printf("[HVD][ERR]%s:","MDrv_HVD_EX_Init");
        puts("driver init failed due to no valid bbu id.");
      }
      iVar8 = uVar11 * 0x5c4 + pHVDDrvContext;
      *(uint *)(iVar8 + 0x10c) = *(uint *)(iVar8 + 0x10c) & 0xfffffffd;
      return 0;
    }
    iVar5 = _HVD_EX_Init_(param_1);
    if (iVar5 == 1) {
      iVar5 = *local_2c;
      iVar10 = *(int *)(iVar5 + iVar8 + 0x88);
      iVar2 = HAL_HVD_EX_GetData(param_1,0x4006);
      uVar3 = MsOS_PA2KSEG1(iVar2 + iVar10);
      *(undefined4 *)(iVar5 + iVar8 + 0x110) = uVar3;
      *(uint *)(*local_2c + iVar8 + 0x10c) = *(uint *)(*local_2c + iVar8 + 0x10c) | 1;
      *(undefined1 *)(*local_2c + iVar8 + 0x60) = 1;
      *(uint *)(*local_2c + iVar8 + 0x1c0) = param_1;
      if ((*param_3 & 0xf) == 3) {
        iVar8 = (uVar11 + 1) * 0x5c4;
        *(uint *)(*local_2c + iVar8 + 0x10c) = *(uint *)(*local_2c + iVar8 + 0x10c) | 1;
        *(undefined1 *)(*local_2c + iVar8 + 0x60) = 1;
        *(uint *)(*local_2c + iVar8 + 0x1c0) = param_1 + 0x11000;
        *(undefined1 *)(*local_2c + uVar11 + 1 + 0x40) = 1;
      }
      *(undefined1 *)(pHVDDrvContext + uVar11 + 0x40) = 1;
      if ((u32UartCtrl & 2) != 0) {
        printf("[HVD][INF]%s:","MDrv_HVD_EX_Init");
        puts("driver Init successfully.");
      }
      iVar8 = uVar11 * 0x5c4 + pHVDDrvContext;
      *(uint *)(iVar8 + 0x10c) = *(uint *)(iVar8 + 0x10c) & 0xfffffffd;
      return 1;
    }
  }
  *(uint *)(*local_2c + iVar8 + 0x10c) = *(uint *)(*local_2c + iVar8 + 0x10c) & 0xfffffffd;
  return iVar5;
}

