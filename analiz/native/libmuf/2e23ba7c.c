
/* MResourceManager::DoRenderImageToSurface(unsigned long, _IDirectFBSurface**, unsigned long&) */

undefined4 __thiscall
MResourceManager::DoRenderImageToSurface
          (MResourceManager *this,ulong param_1,_IDirectFBSurface **param_2,ulong *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_t9;
  code *pcVar7;
  code *pcVar8;
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [4];
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 auStack_b0 [9];
  ulong *puStack_8c;
  int iStack_88;
  MResourceManager *pMStack_84;
  ulong uStack_80;
  _IDirectFBSurface **pp_Stack_7c;
  uint local_58 [16];
  
  iVar1 = (**(code **)(in_t9 + 0x77edc))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    iVar2 = *(int *)(in_t9 + 0x77e8c) + -0x73a0;
    (**(code **)(in_t9 + 0x78464))
              (iVar2,*(int *)(in_t9 + 0x77e8c) + -0x5610,*(int *)(in_t9 + 0x77e8c) + -0x5430,0x23e);
    pcVar7 = *(code **)(in_t9 + 0x7814c);
    (*pcVar7)();
    uStack_d0 = 0;
    uStack_cc = 0;
    uStack_c8 = 0;
    uStack_c4 = 0;
    uStack_c0 = 0;
    uStack_bc = 0;
    uStack_b8 = 0;
    uStack_b4 = 0;
    puStack_8c = param_3;
    iStack_88 = iVar1;
    pMStack_84 = this;
    uStack_80 = param_1;
    pp_Stack_7c = param_2;
    (**(code **)(pcVar7 + 0x78140))(0xf,*(int *)(pcVar7 + 0x77cf0) + -0x55f4);
    (**(code **)(pcVar7 + 0x78140))(0x10,&uStack_d0);
    (**(code **)(pcVar7 + 0x782c8))(*(int *)(pcVar7 + 0x77cf0) + -0x55dc,&uStack_d0);
    if (iVar2 == 0) {
      pcVar8 = *(code **)(pcVar7 + 0x782c8);
      iVar1 = *(int *)(pcVar7 + 0x77cf0) + -0x73a0;
      iVar2 = *(int *)(pcVar7 + 0x77cf0) + -0x5610;
      iVar3 = *(int *)(pcVar7 + 0x77cf0) + -0x5288;
      uVar4 = 0xaf;
    }
    else {
      iVar1 = (**(code **)(pcVar7 + 0x77fe0))();
      if (iVar1 != 0) {
        iVar2 = (**(code **)(pcVar7 + 0x78aa4))();
        if (iVar2 == 0) goto LAB_2e23bde8;
        auStack_b0[0] = 0xb2;
        auStack_b0[1] = 0xc1;
        auStack_b0[2] = 0xb3;
        auStack_b0[3] = 0xc3;
        auStack_b0[4] = 0xc6;
        auStack_b0[5] = 0xc2;
        auStack_b0[6] = 0xc4;
        auStack_b0[7] = 199;
        puVar5 = auStack_b0;
        do {
          uVar4 = *puVar5;
          puVar5 = puVar5 + 1;
          (**(code **)(pcVar7 + 0x79060))(iVar2,uVar4,auStack_d4,auStack_d8);
        } while (auStack_b0 + 8 != puVar5);
        iVar3 = 10;
        do {
          iVar6 = iVar3 + 1;
          (**(code **)(pcVar7 + 0x78d1c))(iVar2,0x11,iVar3,*(undefined4 *)(iVar1 + 0xfc));
          iVar3 = iVar6;
        } while (iVar6 != 0x29);
        return 0;
      }
      pcVar8 = *(code **)(pcVar7 + 0x782c8);
      iVar1 = *(int *)(pcVar7 + 0x77cf0) + -0x73a0;
      iVar2 = *(int *)(pcVar7 + 0x77cf0) + -0x5610;
      iVar3 = *(int *)(pcVar7 + 0x77cf0) + -0x5288;
      uVar4 = 0xb1;
    }
    do {
      (*pcVar8)(iVar1,iVar2,iVar3,uVar4);
      (**(code **)(pcVar7 + 0x77fb0))();
LAB_2e23bde8:
      pcVar8 = *(code **)(pcVar7 + 0x782c8);
      iVar1 = *(int *)(pcVar7 + 0x77cf0) + -0x73a0;
      iVar2 = *(int *)(pcVar7 + 0x77cf0) + -0x5610;
      iVar3 = *(int *)(pcVar7 + 0x77cf0) + -0x5288;
      uVar4 = 0xb3;
    } while( true );
  }
  iVar2 = (**(code **)(in_t9 + 0x789a4))(this,param_1,param_3);
  if (iVar2 != 0) {
    iVar3 = (**(code **)(iVar2 + 0x10))(iVar2,local_58);
    if (iVar3 == 0) {
      local_58[0] = local_58[0] | 1;
      local_58[1] = 4;
      iVar1 = (**(code **)(iVar1 + 0x20))(iVar1,local_58,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(iVar2 + 0x18))(iVar2,*param_2,0);
        if (iVar1 != 0) {
          (**(code **)(iVar2 + 0xc))(iVar2);
          (**(code **)(*param_2 + 0xc))();
          *param_2 = (_IDirectFBSurface *)0x0;
          return 0;
        }
        (**(code **)(iVar2 + 0xc))(iVar2);
        return 1;
      }
    }
    (**(code **)(iVar2 + 0xc))(iVar2);
  }
  return 0;
}

