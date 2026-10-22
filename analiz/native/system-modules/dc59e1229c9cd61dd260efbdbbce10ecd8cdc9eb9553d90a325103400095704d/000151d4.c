
undefined4
sawman_update_window(int param_1,int param_2,int *param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  iVar6 = *(int *)(param_2 + 0x74);
  if ((((((*(uint *)(iVar6 + 0xb4) & 4) == 0) ||
        (iVar7 = (*(code *)PTR_sawman_window_border_0002c118)(*(undefined4 *)(iVar6 + 0x178)),
        iVar7 != 0)) && (0 < *(int *)(iVar6 + 200))) && ((*(uint *)(iVar6 + 0xb0) & 8) == 0)) &&
     ((*(int *)(iVar6 + 0x198) == 0 || (0 < *(int *)(*(int *)(iVar6 + 0x198) + 200))))) {
    uVar1 = *(uint *)(param_2 + 0x68);
  }
  else {
    if ((param_5 & 2) == 0) {
      return 0;
    }
    uVar1 = *(uint *)(param_2 + 0x68);
  }
  if ((uVar1 & 1) != 0) {
    iVar7 = *(int *)(param_1 + 0x6c);
    if (iVar7 != 0) {
      uVar1 = *(uint *)(iVar7 + 0x14);
      while (((1 << (*(uint *)(iVar6 + 0xcc) & 0x1f) & uVar1) == 0 &&
             (iVar7 = *(int *)(iVar7 + 4), iVar7 != 0))) {
        uVar1 = *(uint *)(iVar7 + 0x14);
      }
    }
    if (param_3 == (int *)0x0) {
      if (((param_5 & 8) == 0) ||
         (iVar6 = (*(code *)PTR_sawman_window_border_0002c118)(param_2), iVar6 == 0)) {
        local_30 = *(int *)(param_2 + 0x54);
        local_2c = *(int *)(param_2 + 0x58);
        iVar5 = *(int *)(param_2 + 0x5c);
        iVar6 = *(int *)(param_2 + 0x60);
      }
      else {
        local_30 = *(int *)(param_2 + 0x34);
        local_2c = *(int *)(param_2 + 0x38);
        iVar5 = *(int *)(param_2 + 0x3c);
        iVar6 = *(int *)(param_2 + 0x40);
      }
      local_28 = local_30 + iVar5 + -1;
      local_24 = local_2c + iVar6 + -1;
    }
    else if (((param_5 & 4) == 0) || (-1 < *(int *)(iVar6 + 0xd0) << 0xf)) {
      local_30 = *(int *)(param_2 + 0x54) + *param_3;
      local_2c = *(int *)(param_2 + 0x58) + param_3[1];
      local_28 = *(int *)(param_2 + 0x54) + param_3[2];
      local_24 = *(int *)(param_2 + 0x58) + param_3[3];
    }
    else {
      iVar4 = *(int *)(param_2 + 0x4c);
      iVar6 = *(int *)(param_2 + 0x5c);
      iVar2 = *(int *)(param_2 + 0x50);
      iVar5 = *(int *)(param_2 + 0x60);
      if (iVar4 < iVar6) {
        local_28 = ((param_3[2] + 1) * iVar6) / iVar4;
        if (iVar4 == 0) {
          trap(7);
        }
        local_30 = ((*param_3 + -1) * iVar6) / iVar4;
        if (iVar4 == 0) {
          trap(7);
        }
      }
      else {
        if (iVar4 == 0) {
          trap(7);
        }
        local_28 = (iVar6 * param_3[2]) / iVar4 + 1;
        if (iVar4 == 0) {
          trap(7);
        }
        local_30 = (iVar6 * *param_3) / iVar4 + -1;
      }
      if (iVar2 < iVar5) {
        local_24 = ((param_3[3] + 1) * iVar5) / iVar2;
        if (iVar2 == 0) {
          trap(7);
        }
        local_2c = ((param_3[1] + -1) * iVar5) / iVar2;
        if (iVar2 == 0) {
          trap(7);
        }
      }
      else {
        if (iVar2 == 0) {
          trap(7);
        }
        local_24 = (iVar5 * param_3[3]) / iVar2 + 1;
        if (iVar2 == 0) {
          trap(7);
        }
        local_2c = (iVar5 * param_3[1]) / iVar2 + -1;
      }
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1;
      if (local_30 < 0) {
        local_30 = 0;
      }
      if (local_2c < 0) {
        local_2c = 0;
      }
      if (local_28 <= iVar6) {
        iVar6 = local_28;
      }
      if (local_24 <= iVar5) {
        iVar5 = local_24;
      }
      local_28 = iVar6 + *(int *)(param_2 + 0x54);
      local_24 = iVar5 + *(int *)(param_2 + 0x58);
      local_30 = local_30 + *(int *)(param_2 + 0x54);
      local_2c = local_2c + *(int *)(param_2 + 0x58);
    }
    iVar6 = (*(code *)PTR_dfb_unsafe_region_intersect_0002c1b4)
                      (&local_30,0,0,*(int *)(iVar7 + 0x4c) + -1,*(int *)(iVar7 + 0x50) + -1);
    if (iVar6 != 0) {
      if ((param_5 & 1) == 0) {
        iVar6 = *(int *)(param_1 + 0x60) + -1;
        if (iVar6 < 0) {
LAB_00015394:
          iVar5 = -0x20000000;
        }
        else {
          iVar5 = iVar6;
          if (param_2 != *(int *)(*(int *)(param_1 + 0x5c) + iVar6 * 4)) {
            piVar3 = (int *)(*(int *)(param_1 + 0x5c) + (*(int *)(param_1 + 0x60) + -2) * 4);
            do {
              iVar5 = iVar5 + -1;
              if (iVar5 == -1) goto LAB_00015394;
              iVar2 = *piVar3;
              piVar3 = piVar3 + -1;
            } while (param_2 != iVar2);
          }
        }
        (*(code *)(PTR_0002c044 + 0x38c0))(param_1,iVar7,&local_30,param_4,iVar6,iVar5);
      }
      else {
        (*(code *)PTR_dfb_updates_add_0002c124)(iVar7 + 0x54,&local_30);
      }
    }
  }
  return 0;
}

