
undefined4 fusion_skirmish_init(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_38;
  undefined4 local_34;
  char local_30 [24];
  
  while (iVar2 = (*(code *)PTR_ioctl_2f1586a4)(*(undefined4 *)(param_3 + 0xc),0x80040400,param_1),
        iVar2 != 0) {
    piVar3 = (int *)(*(code *)PTR___errno_location_2f1587b4)();
    if (*piVar3 != 4) {
      if ((**(uint **)PTR_DAT_2f1585bc & 8) == 0) {
        (*(code *)PTR_direct_messages_perror_2f158638)(*piVar3,PTR_LAB_2f1584e8 + 0x746c);
        return 0x16;
      }
      return 0x16;
    }
  }
  local_34 = *param_1;
  local_38 = 4;
  pcVar4 = local_30;
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') break;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (pcVar4 != local_30 + 0x17);
  uVar5 = *(undefined4 *)(param_3 + 0xc);
  *pcVar4 = '\0';
  (*(code *)PTR_ioctl_2f1586a4)(uVar5,0x80200003,&local_38);
  param_1[1] = *(undefined4 *)(param_3 + 8);
  return 0;
}

