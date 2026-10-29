
undefined4 HAL_VPU_EX_LoadCode(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  
  puVar7 = (undefined4 *)*param_1;
  puVar8 = (undefined4 *)param_1[3];
  uVar10 = param_1[2];
  iVar11 = param_1[1];
  iVar2 = HAL_VPU_EX_GetFWReload();
  if (iVar2 == 0) {
    if (*(char *)(pVPUHalContext + 0xb1) == '\0') {
      if ((u32VpuUartCtrl & 2) != 0) {
        printf("[VPU][INF]%s:","HAL_VPU_EX_LoadCode");
        puts("Never load fw successfully, load it anyway!");
      }
    }
    else {
      iVar2 = (*(code *)&UNK_2d62ceac)(puVar7);
      if (iVar2 == 0) {
        if ((u32VpuUartCtrl & 2) == 0) {
          return 1;
        }
        printf("[VPU][INF]%s:","HAL_VPU_EX_LoadCode");
        puts("Skip loading fw this time!!!");
        return 1;
      }
      if ((u32VpuUartCtrl & 1) != 0) {
        printf("[VPU][ERR]%s:","HAL_VPU_EX_LoadCode");
        puts("Wrong prefix: reload fw!");
      }
    }
  }
  if (*(char *)(param_1 + 4) == '\x02') goto LAB_2d6304e8;
  if (*(char *)(param_1 + 4) == '\x01') {
    if ((puVar8 == (undefined4 *)0x0) || (uVar10 == 0)) goto LAB_2d6304e8;
    iVar2 = (*(code *)&UNK_2d6302e4)(puVar8,uVar10,puVar7,(int)puVar7 + iVar11 + -0x1000);
    if (iVar2 != 1) {
      if ((((uint)puVar8 | (uint)puVar7) & 3) == 0) {
        uVar6 = uVar10 >> 2;
        if (uVar6 != 0) {
          uVar4 = 0;
          puVar3 = puVar7;
          puVar9 = puVar8;
          do {
            uVar4 = uVar4 + 1;
            *puVar3 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar3 = puVar3 + 1;
          } while (uVar4 < uVar6);
        }
        if ((uVar10 & 3) != 0) {
          uVar4 = 0;
          puVar3 = puVar8 + uVar6;
          do {
            iVar2 = uVar4 + uVar6 * 4;
            uVar4 = uVar4 + 1;
            *(undefined1 *)((int)puVar7 + iVar2) = *(undefined1 *)puVar3;
            puVar3 = (undefined4 *)((int)(puVar8 + uVar6) + uVar4);
          } while (uVar4 < (uVar10 & 3));
        }
      }
      else {
        uVar6 = 0;
        puVar3 = puVar8;
        do {
          puVar5 = (undefined1 *)(uVar6 + (int)puVar7);
          uVar6 = uVar6 + 1;
          *puVar5 = *(undefined1 *)puVar3;
          puVar3 = (undefined4 *)(uVar6 + (int)puVar8);
        } while (uVar6 < uVar10);
      }
      goto LAB_2d630478;
    }
    iVar2 = (*(code *)&UNK_2d62ceac)(puVar7);
joined_r0x2d630874:
    if (iVar2 == 0) {
      if ((u32VpuUartCtrl & 2) != 0) {
        printf("[VPU][INF]%s:","HAL_VPU_EX_LoadCode");
        puts("Decompress ok!!!");
      }
    }
    else if ((u32VpuUartCtrl & 2) != 0) {
      printf("[VPU][INF]%s:","HAL_VPU_EX_LoadCode");
      puts("Decompress fail!!!");
    }
LAB_2d630478:
    MAsm_CPU_Sync();
    MsOS_FlushMemory();
    cVar1 = *(char *)((int)puVar7 + 6);
  }
  else {
    if ((u32VpuUartCtrl & 2) != 0) {
      printf("[VPU][INF]%s:","HAL_VPU_EX_LoadCode");
      printf("Load FW inD2D: dest=0x%lx, source=0x%lx, size=%ld\n",puVar7,&UNK_2d66c2dc,0x9b3e0);
    }
    puVar8 = (undefined4 *)&UNK_2d66c2dc;
    iVar2 = (*(code *)&UNK_2d6302e4)(&UNK_2d66c2dc,0x9b3e0,puVar7,(int)puVar7 + iVar11 + -0x1000);
    if (iVar2 == 1) {
      iVar2 = (*(code *)&UNK_2d62ceac)(puVar7);
      goto joined_r0x2d630874;
    }
    if (((uint)puVar7 & 3) != 0) {
      iVar2 = 0;
      do {
        iVar11 = iVar2 + 1;
        *(undefined1 *)(iVar2 + (int)puVar7) = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)(&UNK_2d66c2dd + iVar2);
        iVar2 = iVar11;
      } while (iVar11 != 0x9b3e0);
      goto LAB_2d630478;
    }
    iVar2 = 0;
    do {
      iVar11 = iVar2 + 4;
      *(undefined4 *)(iVar2 + (int)puVar7) = *puVar8;
      puVar8 = (undefined4 *)(&UNK_2d66c2e0 + iVar2);
      iVar2 = iVar11;
    } while (iVar11 != 0x9b3e0);
    MAsm_CPU_Sync();
    MsOS_FlushMemory();
    cVar1 = *(char *)((int)puVar7 + 6);
  }
  if ((cVar1 == 'R') && (*(char *)((int)puVar7 + 7) == '2')) {
    *(undefined1 *)(pVPUHalContext + 0xb1) = 1;
    return 1;
  }
  if ((u32VpuUartCtrl & 1) != 0) {
    printf("[VPU][ERR]%s:","HAL_VPU_EX_LoadCode");
    printf("FW is not R2 version! _%x_ _%x_\n",(uint)*(byte *)((int)puVar7 + 6),
           (uint)*(byte *)((int)puVar7 + 7));
  }
LAB_2d6304e8:
  *(undefined1 *)(pVPUHalContext + 0xb1) = 0;
  return 0;
}

