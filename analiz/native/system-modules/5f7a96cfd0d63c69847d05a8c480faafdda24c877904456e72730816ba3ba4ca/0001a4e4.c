
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ehci_init(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  piVar7 = param_1 + 0x42;
  param_1[0x85] = param_1[0x85] & 0xffffffbfU | 0x40;
  (*(code *)&init_timer_key)(param_1 + 0x77,0,0);
  param_1[0x7b] = (int)ehci_watchdog;
  param_1[0x7c] = (int)piVar7;
  (*(code *)&init_timer_key)(param_1 + 0x70,0,0);
  param_1[0x75] = (int)piVar7;
  param_1[0x74] = (int)ehci_iaa_watchdog;
  puVar4 = (uint *)((param_1[0x42] + 8U & 0xff) * 2 + (param_1[0x42] + 8U & 0xffffff00));
  uVar3 = *puVar4;
  uVar8 = puVar4[1] << 0x10 | uVar3 & 0xffff;
  param_1[0x54] = (int)(param_1 + 0x53);
  param_1[0x53] = (int)(param_1 + 0x53);
  param_1[0x52] = 100;
  param_1[0x56] = (int)(param_1 + 0x55);
  param_1[0x55] = (int)(param_1 + 0x55);
  param_1[0x4b] = 0x400;
  iVar1 = (*(code *)&dma_pool_create)(&_LC29,*param_1,0x80,0x80,0x1000);
  param_1[0x6d] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  iVar1 = (*(code *)&dma_pool_create)(&_LC30,*param_1,0x80,0x80,0x1000);
  param_1[0x6c] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  iVar1 = ehci_qh_alloc(piVar7,0xd0);
  param_1[0x46] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  iVar1 = (*(code *)&dma_pool_create)(&_LC31,*param_1,0x100,0x80,0x1000);
  param_1[0x6e] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  iVar1 = (*(code *)&dma_pool_create)(&_LC32,*param_1,0x80,0x80,0x1000);
  param_1[0x6f] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  iVar1 = *param_1;
  if ((iVar1 == 0) ||
     (puVar2 = *(undefined4 **)(iVar1 + 0x90), *(undefined4 **)(iVar1 + 0x90) == (undefined4 *)0x0))
  {
    puVar2 = _mips_dma_map_ops;
  }
  iVar1 = (*(code *)*puVar2)(iVar1,param_1[0x4b] << 2,param_1 + 0x4d,0);
  param_1[0x4c] = iVar1;
  if (iVar1 == 0) goto LAB_0001a714;
  if (param_1[0x85] << 0x15 < 0) {
    puVar2 = (undefined4 *)ehci_qh_alloc(piVar7,0xd0);
    param_1[0x47] = (int)puVar2;
    if (puVar2 == (undefined4 *)0x0) goto LAB_0001a714;
    puVar2 = (undefined4 *)*puVar2;
    puVar2[5] = 1;
    *puVar2 = 1;
    puVar2[6] = puVar2[6] & 0xffffff7f;
    puVar2[4] = 1;
    *(undefined4 **)param_1[0x47] = puVar2;
    uVar6 = 0;
    if (param_1[0x4b] == 0) goto LAB_0001a7e8;
    do {
      iVar1 = uVar6 * 4;
      uVar6 = uVar6 + 1;
      *(undefined4 *)(param_1[0x4c] + iVar1) = *(undefined4 *)(param_1[0x47] + 4);
      uVar5 = param_1[0x4b];
    } while (uVar6 < uVar5);
LAB_0001a704:
    if (0x3fffffff < uVar5) {
      param_1[0x4f] = 0;
      goto LAB_0001a714;
    }
  }
  else {
    uVar6 = 0;
    if (param_1[0x4b] != 0) {
      do {
        iVar1 = uVar6 * 4;
        uVar6 = uVar6 + 1;
        *(undefined4 *)(param_1[0x4c] + iVar1) = 1;
        uVar5 = param_1[0x4b];
      } while (uVar6 < uVar5);
      goto LAB_0001a704;
    }
LAB_0001a7e8:
    uVar5 = 0;
  }
  iVar1 = (*(code *)&__kmalloc)(uVar5 << 2,0x80d0);
  param_1[0x4f] = iVar1;
  if (iVar1 != 0) {
    param_1[0x57] = -1;
    param_1[0x50] = -1;
    param_1[0x4e] = 8;
    param_1[0x51] = 0;
    param_1[0x48] = 0;
    *(undefined4 *)(param_1[0x46] + 8) = 0;
    puVar4 = *(uint **)param_1[0x46];
    *puVar4 = ((undefined4 *)param_1[0x46])[1] & 0xffffffe0 | 2;
    puVar4[1] = 0x8000;
    puVar4[6] = 0x40;
    puVar4[4] = 1;
    *(undefined1 *)(param_1[0x46] + 0x2d) = 1;
    puVar4[5] = *(uint *)(*(int *)(param_1[0x46] + 0x14) + 0x34);
    if (6 < log2_irq_thresh) {
      log2_irq_thresh = 0;
    }
    uVar6 = 1 << (log2_irq_thresh + 0x10 & 0x1f);
    if ((int)(uVar8 << 0xd) < 0) {
      uVar6 = uVar6 | 0x8000;
      param_1[0x87] = param_1[0x87] & 0xfffffffbU | 4;
    }
    if (((uVar3 & 4) != 0) && (park != 0)) {
      uVar5 = 3;
      if (park < 4) {
        uVar5 = park;
      }
      uVar6 = uVar6 | uVar5 << 8 | 0x800;
      park = uVar5;
    }
    if ((uVar3 & 2) != 0) {
      uVar6 = uVar6 & 0xfffffff3;
    }
    if ((int)(uVar8 << 0xe) < 0) {
      param_1[0x87] = param_1[0x87] & 0xfffffffdU | 2;
      if (0xf < hird) {
        hird = 0;
      }
      uVar6 = uVar6 | hird << 0x18;
    }
    param_1[0x84] = uVar6;
    if ((param_1[0x45] & 0x10U) != 0) {
      uVar3 = param_1[0x45] & 0xf;
      uVar8 = uVar3;
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1;
        ehci_hub_control(param_1,0x2301,8,uVar8,0,0);
        uVar8 = uVar3 & 0xffff;
      }
      (*(code *)&msleep)(0x14);
    }
    if ((*(uint *)(param_1[0x22] + 0x10) & 2) != 0) {
      return 0;
    }
    param_1[4] = -1;
    return 0;
  }
LAB_0001a714:
  ehci_mem_cleanup(piVar7);
  return 0xfffffff4;
}

