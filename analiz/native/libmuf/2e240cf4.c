
/* MResourcePkg::Prepare(char const*, MResourcePkg::MResBinaryHeader*, MResourcePkg::EN_RES_TYPE)
   const */

int __thiscall MResourcePkg::Prepare(MResourcePkg *this,undefined4 param_1,int *param_2,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int in_t9;
  code *pcVar6;
  
  iVar1 = (**(code **)(in_t9 + 0x73ef0))(param_1,*(int *)(in_t9 + 0x72c14) + -0x5160);
  if (iVar1 == 0) {
    if ((this[0x2c] == (MResourcePkg)0x0) ||
       (iVar2 = (**(code **)(in_t9 + 0x73a88))
                          (**(undefined4 **)(this + 0x28),
                           *(undefined4 *)(*(int *)(in_t9 + 0x72c04) + 0x3a90)), iVar2 != 0)) {
      return 0;
    }
    pcVar6 = *(code **)(in_t9 + 0x731ec);
    iVar2 = *(int *)(in_t9 + 0x72c14) + -0x73a0;
    iVar3 = *(int *)(in_t9 + 0x72c14) + -0x51fc;
    iVar4 = *(int *)(in_t9 + 0x72c14) + -0x4cf0;
    uVar5 = 0x293;
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x7410c))(param_2,0x38,1,iVar1);
    if (iVar2 != 1) goto LAB_2e240e10;
    if (*param_2 == 0x6d73745f) {
      if (param_2[2] == param_4) {
        return iVar1;
      }
      (**(code **)(in_t9 + 0x739f0))(iVar1);
      uVar5 = 0x2b4;
      pcVar6 = *(code **)(in_t9 + 0x731ec);
      iVar2 = *(int *)(in_t9 + 0x72c14) + -0x73a0;
      iVar3 = *(int *)(in_t9 + 0x72c14) + -0x51fc;
      iVar4 = *(int *)(in_t9 + 0x72c14) + -0x4cf0;
    }
    else {
      (**(code **)(in_t9 + 0x739f0))(iVar1);
      uVar5 = 0x2aa;
      pcVar6 = *(code **)(in_t9 + 0x731ec);
      iVar2 = *(int *)(in_t9 + 0x72c14) + -0x73a0;
      iVar3 = *(int *)(in_t9 + 0x72c14) + -0x51fc;
      iVar4 = *(int *)(in_t9 + 0x72c14) + -0x4cf0;
    }
  }
  do {
    (*pcVar6)(iVar2,iVar3,iVar4,uVar5);
    (**(code **)(in_t9 + 0x72ed4))();
LAB_2e240e10:
    (**(code **)(in_t9 + 0x739f0))(iVar1);
    uVar5 = 0x2a2;
    pcVar6 = *(code **)(in_t9 + 0x731ec);
    iVar2 = *(int *)(in_t9 + 0x72c14) + -0x73a0;
    iVar3 = *(int *)(in_t9 + 0x72c14) + -0x51fc;
    iVar4 = *(int *)(in_t9 + 0x72c14) + -0x4cf0;
  } while( true );
}

