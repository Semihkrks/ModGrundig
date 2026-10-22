
/* WARNING: Removing unreachable block (ram,0x2e23f110) */
/* MResourceManager::RenderImageToSurface(MImg&, _IDirectFBSurface*, DFBRectangle*, MWidget*) */

undefined4 __thiscall
MResourceManager::RenderImageToSurface
          (MResourceManager *this,MImg *param_1,_IDirectFBSurface *param_2,DFBRectangle *param_3,
          MWidget *param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  vector *pvVar5;
  int iVar6;
  char *__s;
  int *piVar7;
  uint uVar8;
  int iVar9;
  _IDirectFBSurface *p_Var10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  code *pcVar14;
  ulong local_10c;
  _IDirectFBSurface *local_108;
  _IDirectFBSurface *local_104;
  vector *local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4;
  void *local_f0;
  int local_ec;
  int local_e8;
  uint local_e4;
  int local_e0;
  int local_dc;
  _Rect a_Stack_d0 [8];
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
  local_108 = (_IDirectFBSurface *)0x0;
  if (param_2 == (_IDirectFBSurface *)0x0) {
    return 0;
  }
  iVar6 = MImg::QueryFlag(param_1,'\x04');
  if ((iVar6 == 0) || (param_4 == (MWidget *)0x0)) {
    iVar6 = FindCachedSurface(this,param_1,&local_108,&local_10c);
    bVar2 = iVar6 != 0;
    if ((!bVar2) && (iVar6 = DoRenderImageToSurface(this,param_1,&local_108,&local_10c), iVar6 != 1)
       ) {
      return 0;
    }
  }
  else {
    local_100 = (vector *)0x0;
    iVar6 = FindCachedVideo(this,param_1,(_IDirectFBVideoProvider **)&local_104,&local_100,
                            &local_108);
    bVar2 = iVar6 != 0;
    if (bVar2) {
      local_fc = 0;
      (**(code **)(local_104 + 0x24))(local_104,&local_fc);
      if (local_fc == 2) {
        (**(code **)(local_104 + 0x1c))(local_104,local_108,0,_MUF_PlayGifCallback,local_100);
      }
    }
    else {
      local_104 = (_IDirectFBSurface *)GetDFBVideo(this,param_1);
      if (local_104 == (_IDirectFBSurface *)0x0) {
        return 0;
      }
      (**(code **)(local_104 + 0x40))(local_104,2);
      iVar6 = MSystem::GetInstance();
      iVar6 = *(int *)(iVar6 + 4);
      if (iVar6 == 0) {
        uVar12 = 0x3a9;
        goto LAB_2e23f0b0;
      }
      iVar9 = (**(code **)(local_104 + 0x14))(local_104,&local_a0);
      if (iVar9 != 0) {
        (**(code **)(local_104 + 0xc))();
        return 0;
      }
      local_a0 = local_a0 | 1;
      local_9c = 4;
      iVar6 = (**(code **)(iVar6 + 0x20))(iVar6,&local_a0,&local_108);
      p_Var10 = local_104;
      if (iVar6 != 0) {
LAB_2e23ecb0:
        (**(code **)(p_Var10 + 0xc))();
        return 0;
      }
      (**(code **)(local_108 + 0x48))(local_108,0,0,0,0);
      (**(code **)(local_108 + 0x78))(local_108,1);
      local_100 = operator_new(0xc);
      *(undefined4 *)local_100 = 0;
      *(undefined4 *)(local_100 + 4) = 0;
      *(undefined4 *)(local_100 + 8) = 0;
      iVar6 = (**(code **)(local_104 + 0x1c))(local_104,local_108,0,_MUF_PlayGifCallback,local_100);
      pvVar5 = local_100;
      if (iVar6 != 0) {
        if (local_100 != (vector *)0x0) {
          if (*(void **)local_100 != (void *)0x0) {
            operator_delete(*(void **)local_100);
          }
          operator_delete(pvVar5);
        }
        local_100 = (vector *)0x0;
        (**(code **)(local_104 + 0xc))();
        p_Var10 = local_108;
        goto LAB_2e23ecb0;
      }
    }
    puVar11 = *(undefined4 **)(local_100 + 4);
    piVar7 = *(int **)local_100;
    uVar13 = (int)puVar11 - (int)piVar7 >> 2;
    if (uVar13 == 0) {
LAB_2e23eb14:
      if (puVar11 == *(undefined4 **)(local_100 + 8)) {
        std::vector<MWidget*,std::allocator<MWidget*>>::_M_insert_aux
                  ((vector<MWidget*,std::allocator<MWidget*>> *)local_100,puVar11,&param_4);
      }
      else {
        iVar6 = 0;
        if (puVar11 != (undefined4 *)0x0) {
          *puVar11 = param_4;
          iVar6 = *(int *)(local_100 + 4);
        }
        *(int *)(local_100 + 4) = iVar6 + 4;
      }
    }
    else if ((MWidget *)*piVar7 != param_4) {
      uVar8 = 0;
      do {
        uVar8 = uVar8 + 1;
        if (uVar13 <= uVar8) goto LAB_2e23eb14;
        piVar1 = piVar7 + 1;
        piVar7 = piVar7 + 1;
      } while ((MWidget *)*piVar1 != param_4);
    }
    if (!bVar2) {
      UpdateVideoCache(this,param_1,(_IDirectFBVideoProvider *)local_104,local_100,local_108);
    }
  }
  iVar6 = MSystem::GetInstance();
  iVar6 = *(int *)(iVar6 + 4);
  if (iVar6 == 0) {
    uVar12 = 0x3fd;
LAB_2e23f0b0:
    printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
           "BOOL MResourceManager::RenderImageToSurface(MImg&, IDirectFBSurface*, DFBRectangle*, MWidget*)"
           ,uVar12);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  local_60 = 4;
  local_64 = 0xf;
  (**(code **)(param_2 + 0x18))(param_2,auStack_5c,auStack_58);
  (**(code **)(param_2 + 0x20))(param_2,&local_f4);
  local_54 = local_f4;
  (**(code **)(param_2 + 0x50))(param_2,&local_e0);
  local_f0 = (void *)0x2c828ac4;
  if ((local_e0 != 0) || (local_dc != 0)) {
    iVar9 = *(int *)(param_1 + 8);
    local_ec = 0;
    local_e8 = 0;
    if (iVar9 != 0) {
                    /* try { // try from 2e23e7cc to 2e23ea1b has its CatchHandler @ 2e23f0ec */
      (**(code **)(iVar9 + 0x18))(iVar9,&local_ec,&local_e8);
    }
    local_c8 = 0;
    local_c4 = 0;
    if (param_4 != (MWidget *)0x0) {
      MWnd::GetRect((MWnd *)param_4,a_Stack_d0);
    }
    local_e4 = 0xffffffff;
    iVar9 = MImg::QueryFlag(param_1,'\x01');
    if (iVar9 == 0) {
      std::string::assign((string *)&local_f0);
    }
    else {
                    /* try { // try from 2e23ed00 to 2e23ef43 has its CatchHandler @ 2e23f0ec */
      __s = (char *)GetRcEngine::RcGetImage((uint)*(ushort *)param_1,&local_e4);
      strlen(__s);
      std::string::assign((char *)&local_f0,(uint)__s);
    }
    iVar9 = MImg::QueryFlag(param_1,0x80);
    if (iVar9 != 0) {
      if ((((*(size_t *)((int)local_f0 + -0xc) == *(size_t *)((int)*(void **)(param_1 + 0xc) + -0xc)
            ) && (iVar9 = memcmp(local_f0,*(void **)(param_1 + 0xc),
                                 *(size_t *)((int)local_f0 + -0xc)), iVar9 == 0)) &&
          (local_c8 == local_ec)) && (local_c4 == local_e8)) {
        local_f8 = *(int *)(param_1 + 8);
        bVar3 = false;
        bVar4 = true;
        goto joined_r0x2e23e8b0;
      }
    }
    iVar6 = (**(code **)(iVar6 + 0x20))(iVar6,&local_64,&local_f8);
    if (iVar6 == 0) {
      (**(code **)(local_f8 + 0x48))(local_f8,0,0,0,0);
      bVar3 = true;
      bVar4 = false;
      goto joined_r0x2e23e8b0;
    }
  }
  bVar3 = false;
  bVar4 = false;
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
    if (bVar4 || bVar3) {
      (**(code **)(local_f8 + 0x78))(local_f8,8);
    }
    else {
      (**(code **)(param_2 + 0x78))(param_2,8);
    }
  }
  iVar6 = MImg::QueryFlag(param_1,'\b');
  if (iVar6 != 0) {
    if (bVar3) {
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
  if (bVar3) {
    (**(code **)(local_f8 + 0x88))(local_f8,local_108,&local_b0,&local_c0);
    (**(code **)(local_f8 + 0xd8))();
    (**(code **)(param_2 + 0x7c))(param_2,local_f8,0,0,0);
    (**(code **)(param_2 + 0xd8))(param_2);
    iVar6 = MImg::QueryFlag(param_1,0x80);
    if (iVar6 == 0) {
                    /* try { // try from 2e23f008 to 2e23f00f has its CatchHandler @ 2e23f0ec */
      (**(code **)(local_f8 + 0xc))();
    }
    else {
      if (*(int *)(param_1 + 8) != 0) {
        (**(code **)(*(int *)(param_1 + 8) + 0xc))();
      }
      *(int *)(param_1 + 8) = local_f8;
      std::string::assign((string *)(param_1 + 0xc));
    }
  }
  else {
    if (bVar4) {
      (**(code **)(param_2 + 0x7c))(param_2,local_f8,0,0,0);
      pcVar14 = *(code **)(param_2 + 0xd8);
    }
    else {
      (**(code **)(param_2 + 0x88))(param_2,local_108,&local_b0,&local_c0);
      pcVar14 = *(code **)(param_2 + 0xd8);
    }
    (*pcVar14)(param_2);
  }
  iVar6 = MImg::QueryFlag(param_1,'\b');
  if ((iVar6 == 0) || (bVar3)) {
    pcVar14 = *(code **)(param_2 + 0xd8);
  }
  else {
                    /* try { // try from 2e23ef84 to 2e23ef8b has its CatchHandler @ 2e23f0ec */
    (**(code **)(param_2 + 0x10c))(param_2,0,0);
    pcVar14 = *(code **)(param_2 + 0xd8);
  }
  (*pcVar14)(param_2);
  if ((!bVar2) && (iVar6 = MImg::QueryFlag(param_1,'\x04'), iVar6 == 0)) {
    UpdateImageCache(this,param_1,local_108,local_10c);
  }
  if ((allocator *)((int)local_f0 + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar6 = *(int *)((int)local_f0 + -4);
    *(int *)((int)local_f0 + -4) = iVar6 + -1;
    SYNC(0);
    if (iVar6 < 1) {
      std::string::_Rep::_M_destroy((allocator *)((int)local_f0 + -0xc));
      return 1;
    }
  }
  return 1;
}

