
undefined4 candidate_cmd_crc32(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_3 < 3) {
    func_0x8e2599a0(0x8e3a74b0,*param_1,param_1[4]);
    func_0x8e2599a0(0x8e3a74bc,*param_1);
    if (param_1[5] == 0) {
      func_0x8e259978(0x8e3a74c8);
    }
    else {
      func_0x8e259978();
      func_0x8e259948(10);
    }
    return 1;
  }
  iVar1 = func_0x8e288154(*(undefined4 *)(param_4 + 4),0,0x10);
  iVar1 = iVar1 + iRam8e64dde0;
  iVar2 = func_0x8e288154(*(undefined4 *)(param_4 + 8),0,0x10);
  uVar3 = func_0x8e285fe0(0,iVar1,iVar2);
  func_0x8e2599a0(0x8e3a0688,iVar1,iVar2 + -1 + iVar1,uVar3);
  if (param_3 != 3) {
    puVar4 = (undefined4 *)func_0x8e288154(*(undefined4 *)(param_4 + 0xc),0,0x10);
    *puVar4 = uVar3;
  }
  return 0;
}

