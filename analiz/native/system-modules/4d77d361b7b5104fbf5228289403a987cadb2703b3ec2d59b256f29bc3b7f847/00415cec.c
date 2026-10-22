
undefined4 FUN_00415cec(undefined4 param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) && (iVar5 = *param_2, iVar5 == *param_3))
  {
    if (((iVar5 == 0x7f2bb70a) || (iVar5 == 0x7f2bb708)) || (iVar5 == 0x7f2bb709)) {
      uVar3 = FUN_00428330(iVar5,param_1,param_2,param_3);
      return uVar3;
    }
    if (iVar5 + 0x80d44893U < 3) {
      if (param_3[4] != param_2[4]) {
        return param_1;
      }
      if (param_3[5] != param_2[5]) {
        return param_1;
      }
      uVar4 = param_2[6];
      uVar6 = param_2[7];
      if (param_3[6] != uVar4) {
        return param_1;
      }
      if (param_3[7] != uVar6) {
        return param_1;
      }
      uVar1 = uVar4 - (uVar4 - param_2[4] & 7);
      uVar7 = uVar6 - (uVar4 < uVar1);
      if (uVar7 <= uVar6) {
        if ((uVar7 == uVar6) && (uVar4 < uVar1 != 0)) {
          return 0;
        }
        do {
          iVar5 = FUN_00415aa8(param_2);
          iVar2 = FUN_00415aa8(param_3);
          uVar4 = uVar1 + 1;
          uVar7 = (uVar4 < uVar1) + uVar7;
          if (iVar5 != iVar2) {
            return param_1;
          }
        } while ((uVar7 <= (uint)param_2[7]) &&
                ((uVar1 = uVar4, param_2[7] != uVar7 || (uVar4 <= (uint)param_2[6]))));
      }
      return 0;
    }
  }
  return 0x16;
}

