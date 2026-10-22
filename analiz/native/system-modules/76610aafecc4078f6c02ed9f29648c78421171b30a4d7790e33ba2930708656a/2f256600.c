
undefined4 inflateBackInit_(int param_1,uint param_2,int param_3,char *param_4,int param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  if (param_4 == (char *)0x0) {
    uVar2 = 0xfffffffa;
  }
  else {
    uVar2 = 0xfffffffa;
    if ((((*param_4 == '1') && (uVar2 = 0xfffffffa, param_5 == 0x38)) &&
        (uVar2 = 0xfffffffe, param_1 != 0)) &&
       (((param_3 != 0 && (uVar2 = 0xfffffffe, 7 < (int)param_2)) &&
        (uVar2 = 0xfffffffe, (int)param_2 < 0x10)))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      puVar1 = PTR_zcalloc_2f275828;
      pcVar4 = *(code **)(param_1 + 0x20);
      if (*(code **)(param_1 + 0x20) == (code *)0x0) {
        *(undefined4 *)(param_1 + 0x28) = 0;
        *(undefined **)(param_1 + 0x20) = puVar1;
        pcVar4 = (code *)puVar1;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined **)(param_1 + 0x24) = PTR_zcfree_2f27582c;
      }
      iVar3 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x1bcc);
      uVar2 = 0xfffffffc;
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x14) = 0x8000;
        *(int *)(param_1 + 0x1c) = iVar3;
        *(int *)(iVar3 + 0x28) = 1 << (param_2 & 0x1f);
        *(int *)(iVar3 + 0x34) = param_3;
        *(undefined4 *)(iVar3 + 0x2c) = 0;
        *(uint *)(iVar3 + 0x24) = param_2;
        *(undefined4 *)(iVar3 + 0x30) = 0;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

