
/* MResourcePkg::BuildData(char const*, MResourcePkg::EN_RES_TYPE) */

undefined4 __thiscall MResourcePkg::BuildData(MResourcePkg *this,undefined4 param_1,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_t9;
  code *pcVar6;
  undefined1 auStack_58 [4];
  uint local_54;
  uint local_44;
  uint local_3c;
  
  iVar1 = (**(code **)(in_t9 + 0x7375c))(this,param_1,auStack_58,param_3);
  if (iVar1 == 0) {
    return 1;
  }
  pcVar6 = *(code **)(in_t9 + 0x73840);
  if ((local_44 < local_54) && (local_44 = local_54 - local_44, local_54 != 0)) {
    if (0xffffff < local_44) {
      (**(code **)(in_t9 + 0x7303c))(*(int *)(in_t9 + 0x72a64) + -0x5158,param_1,param_3,local_44);
      (**(code **)(in_t9 + 0x73840))(iVar1);
      return 0;
    }
    iVar2 = (**(code **)(in_t9 + 0x7382c))(local_44,*(undefined4 *)(in_t9 + 0x73dd8));
    if (iVar2 == 0) {
      (**(code **)(in_t9 + 0x72f9c))(*(int *)(in_t9 + 0x72a64) + -0x511c);
      (**(code **)(in_t9 + 0x73840))(iVar1);
      uVar5 = 0x30a;
      pcVar6 = *(code **)(in_t9 + 0x7303c);
      iVar2 = *(int *)(in_t9 + 0x72a64) + -0x73a0;
      iVar3 = *(int *)(in_t9 + 0x72a64) + -0x51fc;
      iVar4 = *(int *)(in_t9 + 0x72a64) + -0x4d60;
    }
    else {
      iVar3 = (**(code **)(in_t9 + 0x73f5c))(iVar2,local_44,1,iVar1);
      if (iVar3 == 1) {
        (**(code **)(in_t9 + 0x73840))(iVar1);
        if (0xffffff < local_3c) {
          (**(code **)(in_t9 + 0x7303c))(*(int *)(in_t9 + 0x72a64) + -0x5158,param_1,param_3);
          (**(code **)(in_t9 + 0x73288))(iVar2);
          return 1;
        }
        if (param_3 < 8) {
                    /* WARNING: Could not recover jumptable at 0x2e24109c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar5 = (*(code *)(*(int *)(*(int *)(in_t9 + 0x72a64) + -0x4e50 + param_3 * 4) +
                            in_t9 + 0x7aa3c))();
          return uVar5;
        }
        pcVar6 = *(code **)(in_t9 + 0x7303c);
        iVar2 = *(int *)(in_t9 + 0x72a64) + -0x73a0;
        iVar3 = *(int *)(in_t9 + 0x72a64) + -0x51fc;
        iVar4 = *(int *)(in_t9 + 0x72a64) + -0x4d60;
        uVar5 = 0x356;
      }
      else {
        (**(code **)(in_t9 + 0x73288))(iVar2);
        (**(code **)(in_t9 + 0x73840))(iVar1);
        uVar5 = 0x317;
        pcVar6 = *(code **)(in_t9 + 0x7303c);
        iVar2 = *(int *)(in_t9 + 0x72a64) + -0x73a0;
        iVar3 = *(int *)(in_t9 + 0x72a64) + -0x51fc;
        iVar4 = *(int *)(in_t9 + 0x72a64) + -0x4d60;
      }
    }
    (*pcVar6)(iVar2,iVar3,iVar4,uVar5);
    pcVar6 = *(code **)(in_t9 + 0x72d24);
    (*pcVar6)();
  }
  (*pcVar6)(iVar1);
  return 1;
}

