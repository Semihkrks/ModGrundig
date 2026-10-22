
/* WARNING: Type propagation algorithm not settling */
/* MResourceManager::RenderImageToSurface(MImg&, _IDirectFBSurface*, DFBRectangle*, MWidget*) */

undefined4 __thiscall
MResourceManager::RenderImageToSurface
          (MResourceManager *this,MImg *param_1,_IDirectFBSurface *param_2,DFBRectangle *param_3,
          MWidget *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  int in_t9;
  code *pcVar13;
  int iVar14;
  undefined1 auStack_110 [4];
  uint local_10c;
  int local_108;
  int local_104;
  int *local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  undefined1 auStack_d0 [8];
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined4 local_54;
  
  local_10c = 0xffffffff;
  local_108 = 0;
  if (param_2 == (_IDirectFBSurface *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(in_t9 + 0x75530))(param_1,4);
  if ((iVar5 == 0) || (param_4 == (MWidget *)0x0)) {
    iVar5 = (**(code **)(in_t9 + 0x75acc))(this,param_1,&local_108,&local_10c);
    bVar2 = iVar5 != 0;
    if (bVar2) goto LAB_2e23e724;
    iVar5 = (**(code **)(in_t9 + 0x76068))(this,param_1,&local_108,&local_10c);
    if (iVar5 != 1) {
      return 0;
    }
    pcVar13 = *(code **)(in_t9 + 0x752d4);
  }
  else {
    local_100 = (int *)0x0;
    iVar5 = (**(code **)(in_t9 + 0x75fe4))(this,param_1,&local_104,&local_100,&local_108);
    bVar2 = iVar5 != 0;
    if (bVar2) {
      local_fc = 0;
      (**(code **)(local_104 + 0x24))(local_104,&local_fc);
      if (local_fc == 2) {
        (**(code **)(local_104 + 0x1c))
                  (local_104,local_108,0,*(undefined4 *)(in_t9 + 0x75ae0),local_100);
      }
    }
    else {
      local_104 = (**(code **)(in_t9 + 0x7593c))(this,param_1);
      if (local_104 == 0) {
        return 0;
      }
      (**(code **)(local_104 + 0x40))(local_104,2);
      iVar5 = (**(code **)(in_t9 + 0x752d4))();
      iVar5 = *(int *)(iVar5 + 4);
      if (iVar5 == 0) goto LAB_2e23f0c8;
      iVar14 = (**(code **)(local_104 + 0x14))(local_104,&local_a0);
      if (iVar14 != 0) {
        (**(code **)(local_104 + 0xc))();
        return 0;
      }
      local_a0 = local_a0 | 1;
      local_9c = 4;
      iVar14 = (**(code **)(iVar5 + 0x20))(iVar5,&local_a0,&local_108);
      iVar5 = local_104;
      if (iVar14 != 0) {
LAB_2e23ecb0:
        (**(code **)(iVar5 + 0xc))();
        return 0;
      }
      (**(code **)(local_108 + 0x48))(local_108,0,0,0,0);
      (**(code **)(local_108 + 0x78))(local_108,1);
      local_100 = (int *)(**(code **)(in_t9 + 0x767b0))(0xc);
      *local_100 = 0;
      local_100[1] = 0;
      local_100[2] = 0;
      iVar5 = (**(code **)(local_104 + 0x1c))
                        (local_104,local_108,0,*(undefined4 *)(in_t9 + 0x75ae0),local_100);
      piVar8 = local_100;
      if (iVar5 != 0) {
        if (local_100 != (int *)0x0) {
          if (*local_100 != 0) {
            (**(code **)(in_t9 + 0x75e60))();
          }
          (**(code **)(in_t9 + 0x75e60))(piVar8);
        }
        local_100 = (int *)0x0;
        (**(code **)(local_104 + 0xc))();
        iVar5 = local_108;
        goto LAB_2e23ecb0;
      }
    }
    puVar11 = (undefined4 *)local_100[1];
    piVar8 = (int *)*local_100;
    uVar12 = (int)puVar11 - (int)piVar8 >> 2;
    if (uVar12 == 0) {
LAB_2e23eb14:
      if (puVar11 == (undefined4 *)local_100[2]) {
        (**(code **)(in_t9 + 0x75b0c))(local_100,puVar11,&param_4);
      }
      else {
        iVar5 = 0;
        if (puVar11 != (undefined4 *)0x0) {
          *puVar11 = param_4;
          iVar5 = local_100[1];
        }
        local_100[1] = iVar5 + 4;
      }
    }
    else if ((MWidget *)*piVar8 != param_4) {
      uVar9 = 0;
      do {
        uVar9 = uVar9 + 1;
        if (uVar12 <= uVar9) goto LAB_2e23eb14;
        piVar1 = piVar8 + 1;
        piVar8 = piVar8 + 1;
      } while ((MWidget *)*piVar1 != param_4);
    }
    pcVar13 = *(code **)(in_t9 + 0x752d4);
    if (!bVar2) {
      (**(code **)(in_t9 + 0x76308))(this,param_1,local_104,local_100,local_108);
LAB_2e23e724:
      pcVar13 = *(code **)(in_t9 + 0x752d4);
    }
  }
  iVar5 = (*pcVar13)();
  iVar5 = *(int *)(iVar5 + 4);
  if (iVar5 == 0) {
    iVar5 = *(int *)(in_t9 + 0x75284);
    iVar14 = *(int *)(in_t9 + 0x75284);
    iVar10 = *(int *)(in_t9 + 0x75284);
    pcVar13 = *(code **)(in_t9 + 0x7585c);
    uVar6 = 0x3fd;
    do {
      (*pcVar13)(iVar5 + -0x73a0,iVar14 + -0x5610,iVar10 + -0x54e0,uVar6);
      (**(code **)(in_t9 + 0x75544))();
LAB_2e23f0c8:
      iVar5 = *(int *)(in_t9 + 0x75284);
      iVar14 = *(int *)(in_t9 + 0x75284);
      iVar10 = *(int *)(in_t9 + 0x75284);
      pcVar13 = *(code **)(in_t9 + 0x7585c);
      uVar6 = 0x3a9;
    } while( true );
  }
  local_60 = 4;
  local_64 = 0xf;
  (**(code **)(param_2 + 0x18))(param_2,auStack_5c,auStack_58);
  (**(code **)(param_2 + 0x20))(param_2,&local_f4);
  iVar14 = *(int *)(in_t9 + 0x7660c);
  local_54 = local_f4;
  (**(code **)(param_2 + 0x50))(param_2,&local_e0);
  local_f0 = iVar14 + 0xc;
  if ((local_e0 != 0) || (local_dc != 0)) {
    iVar10 = *(int *)(param_1 + 8);
    local_ec = 0;
    local_e8 = 0;
    if (iVar10 != 0) {
                    /* try { // try from 2e23e7cc to 2e23ea1b has its CatchHandler @ 2e23f0ec */
      (**(code **)(iVar10 + 0x18))(iVar10,&local_ec,&local_e8);
    }
    local_c8 = 0;
    local_c4 = 0;
    if (param_4 != (MWidget *)0x0) {
      (**(code **)(in_t9 + 0x763b4))(param_4,auStack_d0);
    }
    local_e4 = 0xffffffff;
    iVar10 = (**(code **)(in_t9 + 0x75530))(param_1,1);
    if (iVar10 == 0) {
      (**(code **)(in_t9 + 0x75a8c))(&local_f0,param_1 + 4);
    }
    else {
                    /* try { // try from 2e23ed00 to 2e23ef43 has its CatchHandler @ 2e23f0ec */
      uVar6 = (**(code **)(in_t9 + 0x760e8))(*(undefined2 *)param_1,&local_e4);
      uVar7 = (**(code **)(in_t9 + 0x762f0))(uVar6);
      (**(code **)(in_t9 + 0x764b8))(&local_f0,uVar6,uVar7);
    }
    iVar10 = (**(code **)(in_t9 + 0x75530))(param_1,0x80);
    if ((((iVar10 != 0) && (*(int *)(local_f0 + -0xc) == *(int *)(*(int *)(param_1 + 0xc) + -0xc)))
        && (iVar10 = (**(code **)(in_t9 + 0x76048))(), iVar10 == 0)) &&
       ((local_c8 == local_ec && (local_c4 == local_e8)))) {
      local_f8 = *(int *)(param_1 + 8);
      uVar3 = false;
      uVar4 = true;
      goto joined_r0x2e23e8b0;
    }
    iVar5 = (**(code **)(iVar5 + 0x20))(iVar5,&local_64,&local_f8);
    if (iVar5 == 0) {
      (**(code **)(local_f8 + 0x48))(local_f8,0,0,0,0);
      uVar3 = true;
      uVar4 = false;
      goto joined_r0x2e23e8b0;
    }
  }
  uVar3 = false;
  uVar4 = false;
joined_r0x2e23e8b0:
  if (local_10c == 0xffffffff) {
    (**(code **)(param_2 + 0x5c))(param_2,5);
    (**(code **)(param_2 + 0x60))(param_2,6);
    (**(code **)(param_2 + 0x78))(param_2,1);
    (**(code **)(param_2 + 0x100))(param_2,1);
    (**(code **)(param_2 + 0x78))(param_2,1);
  }
  else {
    (**(code **)(local_108 + 0x68))
              (local_108,(local_10c & 0xffffff) >> 0x10,(local_10c & 0xffff) >> 8,local_10c & 0xff);
    if ((bool)uVar4 || (bool)uVar3) {
      (**(code **)(local_f8 + 0x78))(local_f8,8);
    }
    else {
      (**(code **)(param_2 + 0x78))(param_2,8);
    }
  }
  iVar5 = (**(code **)(in_t9 + 0x75530))(param_1,8);
  if (iVar5 != 0) {
    if ((bool)uVar3) {
      (**(code **)(local_f8 + 0x10c))(local_f8,1,0);
    }
    else {
      (**(code **)(param_2 + 0x10c))(param_2,1,0);
    }
  }
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  if (param_3 != (DFBRectangle *)0x0) {
    local_b4 = *(int *)(param_3 + 0xc);
    local_c0 = *(int *)param_3;
    local_bc = *(int *)(param_3 + 4);
    local_b8 = *(int *)(param_3 + 8);
  }
  (**(code **)(local_108 + 0x18))(local_108,&local_a8,&local_a4);
  if (local_c0 < 0) {
    local_b0 = (-local_c0 * local_a8) / local_b8;
    if (local_b8 == 0) {
      trap(7);
    }
  }
  else {
    local_b0 = 0;
  }
  if (local_bc < 0) {
    local_ac = (-local_bc * local_a4) / local_b4;
    if (local_b4 == 0) {
      trap(7);
    }
  }
  else {
    local_ac = 0;
  }
  local_c0 = 0;
  local_bc = 0;
  if ((bool)uVar3) {
    (**(code **)(local_f8 + 0x88))(local_f8,local_108,&local_b0,&local_c0);
    (**(code **)(local_f8 + 0xd8))();
    (**(code **)(param_2 + 0x7c))(param_2,local_f8,0,0,0);
    (**(code **)(param_2 + 0xd8))(param_2);
    iVar5 = (**(code **)(in_t9 + 0x75530))(param_1,0x80);
    if (iVar5 == 0) {
                    /* try { // try from 2e23f008 to 2e23f00f has its CatchHandler @ 2e23f0ec */
      (**(code **)(local_f8 + 0xc))();
    }
    else {
      if (*(int *)(param_1 + 8) != 0) {
        (**(code **)(*(int *)(param_1 + 8) + 0xc))();
      }
      pcVar13 = *(code **)(in_t9 + 0x75a8c);
      *(int *)(param_1 + 8) = local_f8;
      (*pcVar13)(param_1 + 0xc,&local_f0);
    }
  }
  else {
    if ((bool)uVar4) {
      (**(code **)(param_2 + 0x7c))(param_2,local_f8,0,0,0);
      pcVar13 = *(code **)(param_2 + 0xd8);
    }
    else {
      (**(code **)(param_2 + 0x88))(param_2,local_108,&local_b0,&local_c0);
      pcVar13 = *(code **)(param_2 + 0xd8);
    }
    (*pcVar13)(param_2);
  }
  iVar5 = (**(code **)(in_t9 + 0x75530))(param_1,8);
  if ((iVar5 == 0) || ((bool)uVar3)) {
    pcVar13 = *(code **)(param_2 + 0xd8);
  }
  else {
                    /* try { // try from 2e23ef84 to 2e23ef8b has its CatchHandler @ 2e23f0ec */
    (**(code **)(param_2 + 0x10c))(param_2,0,0);
    pcVar13 = *(code **)(param_2 + 0xd8);
  }
  (*pcVar13)(param_2);
  if ((!bVar2) && (iVar5 = (**(code **)(in_t9 + 0x75530))(param_1,4), iVar5 == 0)) {
    (**(code **)(in_t9 + 0x75bec))(this,param_1,local_108,local_10c);
  }
  if (iVar14 != local_f0 + -0xc) {
    if (*(int *)(in_t9 + 0x76514) == 0) {
      iVar5 = *(int *)(local_f0 + -4);
      *(int *)(local_f0 + -4) = iVar5 + -1;
    }
    else {
      SYNC(0);
      iVar5 = *(int *)(local_f0 + -4);
      *(int *)(local_f0 + -4) = iVar5 + -1;
      SYNC(0);
    }
    if (iVar5 < 1) {
      (**(code **)(in_t9 + 0x76054))(local_f0 + -0xc,auStack_110);
      return 1;
    }
  }
  return 1;
}

