
/* MResourceManager::DoRenderImageToSurface(MImg&, _IDirectFBSurface**, unsigned long&) */

undefined4 __thiscall
MResourceManager::DoRenderImageToSurface
          (MResourceManager *this,MImg *param_1,_IDirectFBSurface **param_2,ulong *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _IDirectFBSurface *p_Var5;
  int iVar6;
  int in_t9;
  code *pcVar7;
  undefined1 auStack_78 [4];
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  ulong local_64;
  uint local_60 [3];
  int local_54;
  
  iVar1 = (**(code **)(in_t9 + 0x77520))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    (**(code **)(in_t9 + 0x77aa8))
              (*(int *)(in_t9 + 0x774d0) + -0x73a0,*(int *)(in_t9 + 0x774d0) + -0x5610,
               *(int *)(in_t9 + 0x774d0) + -0x5480,0x283);
    (**(code **)(in_t9 + 0x77790))();
LAB_2e23c838:
                    /* try { // try from 2e23c840 to 2e23c857 has its CatchHandler @ 2e23c874 */
    (**(code **)(*param_2 + 0x3c))();
    (**(code **)(in_t9 + 0x782ac))(param_1);
    (**(code **)(in_t9 + 0x779a4))(this);
    uVar3 = 1;
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x7777c))(param_1,2);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(in_t9 + 0x7867c))(this,param_1,param_3);
      if (iVar2 != 0) {
        iVar6 = (**(code **)(iVar2 + 0x10))(iVar2,local_60);
        if (iVar6 == 0) {
          local_60[0] = local_60[0] | 1;
          local_60[1] = 4;
          iVar1 = (**(code **)(iVar1 + 0x20))(iVar1,local_60,param_2);
          if (iVar1 == 0) {
            iVar1 = (**(code **)(iVar2 + 0x18))(iVar2,*param_2,0);
            if (iVar1 == 0) {
              (**(code **)(iVar2 + 0xc))(iVar2);
              return 1;
            }
            (**(code **)(iVar2 + 0xc))(iVar2);
            (**(code **)(*param_2 + 0xc))();
            *param_2 = (_IDirectFBSurface *)0x0;
            return 0;
          }
        }
        (**(code **)(iVar2 + 0xc))(iVar2);
        return 0;
      }
    }
    else {
      iVar6 = *(int *)(in_t9 + 0x78858);
      local_68 = iVar6 + 0xc;
      local_64 = 0xffffffff;
                    /* try { // try from 2e23c4c4 to 2e23c58f has its CatchHandler @ 2e23c874 */
      iVar2 = (**(code **)(in_t9 + 0x7777c))(param_1,1);
      if (iVar2 == 0) {
                    /* try { // try from 2e23c6a8 to 2e23c78b has its CatchHandler @ 2e23c874 */
        (**(code **)(in_t9 + 0x77cd8))(&local_68,param_1 + 4);
      }
      else {
        uVar3 = (**(code **)(in_t9 + 0x78334))(*(undefined2 *)param_1,&local_64);
        uVar4 = (**(code **)(in_t9 + 0x7853c))(uVar3);
        (**(code **)(in_t9 + 0x78704))(&local_68,uVar3,uVar4);
      }
      this = (MResourceManager *)&local_68;
      iVar2 = *(int *)(in_t9 + 0x774d0);
      pcVar7 = *(code **)(in_t9 + 0x787ac);
      *param_3 = local_64;
      param_1 = (MImg *)(*pcVar7)(local_68,iVar2 + -0x402c);
      if (param_1 != (MImg *)0x0) {
        (**(code **)(in_t9 + 0x778bc))(local_60,0,0x3c);
        iVar2 = (**(code **)(in_t9 + 0x789c8))(&local_74,4,1,param_1);
        if (((iVar2 == 1) &&
            (iVar2 = (**(code **)(in_t9 + 0x78170))(param_1,local_74,1), iVar2 == 0)) &&
           (iVar2 = (**(code **)(in_t9 + 0x789c8))(local_60,0x3c,1,param_1), iVar2 == 1)) {
          (**(code **)(iVar1 + 0x20))(iVar1,local_60,param_2);
          p_Var5 = *param_2;
          if (p_Var5 != (_IDirectFBSurface *)0x0) {
            (**(code **)(p_Var5 + 0x48))(p_Var5,0,0,0,0);
            iVar1 = (**(code **)(*param_2 + 0x34))(*param_2,2,&local_70,&local_6c);
            if (iVar1 == 0) {
              if (((local_6c != 0) && (0 < local_54)) &&
                 (iVar1 = (**(code **)(in_t9 + 0x789c8))(local_70,local_6c,local_54,param_1),
                 iVar1 == local_54)) goto LAB_2e23c838;
              (**(code **)(*param_2 + 0x3c))();
            }
          }
        }
        (**(code **)(in_t9 + 0x782ac))(param_1);
      }
      if (iVar6 != local_68 + -0xc) {
        if (*(int *)(in_t9 + 0x78760) == 0) {
          iVar1 = *(int *)(local_68 + -4);
          *(int *)(local_68 + -4) = iVar1 + -1;
        }
        else {
          SYNC(0);
          iVar1 = *(int *)(local_68 + -4);
          *(int *)(local_68 + -4) = iVar1 + -1;
          SYNC(0);
        }
        if (iVar1 < 1) {
          (**(code **)(in_t9 + 0x782a0))(local_68 + -0xc,auStack_78);
          return 0;
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

