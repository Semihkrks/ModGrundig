
undefined4 fusion_call_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_2c = param_2;
  local_28 = param_3;
  do {
    iVar2 = (*(code *)PTR_ioctl_2f1586a4)(*(undefined4 *)(param_4 + 0xc),0x800c0200,&local_30);
    puVar1 = PTR_fusion_id_2f1586fc;
    if (iVar2 == 0) {
      param_1[3] = param_2;
      param_1[4] = param_3;
      param_1[1] = local_30;
      *param_1 = 0;
      param_1[2] = 0;
      uVar4 = (*(code *)puVar1)(param_4);
      uVar5 = *(undefined4 *)(param_4 + 8);
      param_1[2] = uVar4;
      *param_1 = uVar5;
      return 0;
    }
    piVar3 = (int *)(*(code *)PTR___errno_location_2f1587b4)();
  } while (*piVar3 == 4);
  if ((**(uint **)PTR_DAT_2f1585bc & 8) != 0) {
    return 1;
  }
  (*(code *)PTR_direct_messages_perror_2f158638)(*piVar3,PTR_LAB_2f1584e8 + 0x6334);
  return 1;
}

