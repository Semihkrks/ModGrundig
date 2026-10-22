
undefined4 fusion_property_init(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  do {
    iVar1 = (*(code *)PTR_ioctl_2f1586a4)(*(undefined4 *)(param_2 + 0xc),0x80040500,param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 8);
      return 0;
    }
    piVar2 = (int *)(*(code *)PTR___errno_location_2f1587b4)();
  } while (*piVar2 == 4);
  if ((**(uint **)PTR_DAT_2f1585bc & 8) != 0) {
    return 1;
  }
  (*(code *)PTR_direct_messages_perror_2f158638)(*piVar2,PTR_LAB_2f1584e8 + 0x7770);
  return 1;
}

