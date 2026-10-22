
int candidate_cmd_filepartload(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uStack_98;
  undefined1 auStack_96 [126];
  
  uStack_98 = uRam8e388a80;
  func_0x8e287854(auStack_96,0,0x7e);
  if ((uRam8e3ca000 & 4) != 0) {
    func_0x8e2599a0(0x8e389450,0x8e390608);
    func_0x8e2599a0(0x8e389468);
  }
  if (param_3 < 5) {
    func_0x8e258e8c(param_1);
    return -1;
  }
  uVar1 = func_0x8e21328c();
  switch(uVar1) {
  case 1:
    iVar6 = func_0x8e2882c8(*(undefined4 *)(param_4 + 4),0,0x10);
    iVar2 = func_0x8e2882c8(*(undefined4 *)(param_4 + 0xc),0,0x10);
    func_0x8e36d084(&uStack_98,0x80,0x8e390104,iVar6 - iVar2,*(undefined4 *)(param_4 + 8));
    if ((uRam8e3ca000 & 8) != 0) {
      uVar1 = 0x2e2;
code_r0x8e2138b4:
      func_0x8e2599a0(0x8e3894c0,0x8e390608,uVar1);
      func_0x8e2599a0(0x8e38f330,&uStack_98);
    }
    break;
  case 2:
    func_0x8e36d084(&uStack_98,0x80,0x8e390088,uRam8e3eb7c0,uRam8e3eb7bc,
                    *(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                    *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x10));
    if ((uRam8e3ca000 & 8) != 0) {
      uVar1 = 0x2d0;
      goto code_r0x8e2138b4;
    }
    break;
  case 3:
  case 4:
    if ((uRam8e3ca000 & 8) == 0) {
      uVar1 = *(undefined4 *)(param_4 + 4);
    }
    else {
      func_0x8e2599a0(0x8e3894c0,0x8e390608,0x2e7);
      func_0x8e2599a0(0x8e390114,*(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                      *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x10));
      uVar1 = *(undefined4 *)(param_4 + 4);
    }
    uVar1 = func_0x8e288154(uVar1,0,0x10);
    uVar3 = func_0x8e288154(*(undefined4 *)(param_4 + 0xc),0,0x10);
    uVar4 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
    uVar5 = func_0x8e21316c();
    func_0x8e216f40(uVar5);
    iVar6 = func_0x8e21743c(uVar1,*(undefined4 *)(param_4 + 8),uVar3,uVar4);
    goto code_r0x8e213988;
  case 5:
    func_0x8e36d084(&uStack_98,0x80,0x8e3900d8,uRam8e3eb7c0,uRam8e3eb7bc,
                    *(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                    *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x10));
    if ((uRam8e3ca000 & 8) != 0) {
      uVar1 = 0x2db;
      goto code_r0x8e2138b4;
    }
    break;
  case 6:
    uVar1 = func_0x8e21316c();
    func_0x8e216f40(uVar1);
    func_0x8e36d084(&uStack_98,0x80,0x8e3900ac,uRam8e3eb7c0,uRam8e3eb7bc,
                    *(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                    *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x10));
    if ((uRam8e3ca000 & 8) != 0) {
      uVar1 = 0x2d6;
      goto code_r0x8e2138b4;
    }
    break;
  default:
    iVar6 = 0;
    goto code_r0x8e213998;
  }
  iVar6 = func_0x8e25f5d0(&uStack_98,0);
code_r0x8e213988:
  iVar6 = -(uint)(iVar6 == -1);
code_r0x8e213998:
  if ((uRam8e3ca000 & 4) != 0) {
    func_0x8e2599a0(0x8e389450,0x8e390608);
    func_0x8e2599a0(0x8e3a3b78);
  }
  return iVar6;
}

