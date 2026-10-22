
undefined4 candidate_cmd_mscompress7(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_3 < 6) {
    func_0x8e2599a0(0x8e389738,*(undefined4 *)(param_1 + 0x10));
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    uVar6 = 0;
    iVar1 = 0;
    iVar2 = 1;
    do {
      switch(iVar1) {
      case 0:
        if (**(char **)(param_4 + 4) != 'd') {
          return 1;
        }
        break;
      case 1:
        iVar1 = func_0x8e2882c8(*(undefined4 *)(param_4 + 8),0,10);
        if (iVar1 != 0) {
          return 1;
        }
        break;
      case 2:
        uVar6 = func_0x8e2882c8(*(undefined4 *)(param_4 + 0xc),0,0x10);
        break;
      case 3:
        uVar4 = func_0x8e2882c8(*(undefined4 *)(param_4 + 0x10),0,0x10);
        break;
      case 4:
        uVar5 = func_0x8e2882c8(*(undefined4 *)(param_4 + 0x14),0,0x10);
      }
      iVar3 = iVar2 + 1;
      iVar1 = iVar2;
      iVar2 = iVar3;
    } while (iVar3 != param_3);
    iVar1 = func_0x8e215b5c(uVar6,uVar5,uVar4);
    if (iVar1 == 1) {
      return 0;
    }
    func_0x8e2599a0(0x8e390c2c,0x8e390fdc,0x11d);
  }
  return 1;
}

