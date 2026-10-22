
int inflateInit2_(int param_1,undefined4 param_2,char *param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if (param_3 == (char *)0x0) {
    iVar3 = -6;
  }
  else {
    iVar3 = -6;
    if (((*param_3 == '1') && (param_4 == 0x38)) && (iVar3 = -2, param_1 != 0)) {
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
      iVar2 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x1bcc);
      puVar1 = PTR_inflateReset2_2f275890;
      iVar3 = -4;
      if (iVar2 != 0) {
        *(int *)(param_1 + 0x1c) = iVar2;
        *(undefined4 *)(iVar2 + 0x34) = 0;
        iVar3 = (*(code *)puVar1)(param_1,param_2);
        if (iVar3 != 0) {
          (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar2);
          *(undefined4 *)(param_1 + 0x1c) = 0;
        }
      }
    }
  }
  return iVar3;
}

