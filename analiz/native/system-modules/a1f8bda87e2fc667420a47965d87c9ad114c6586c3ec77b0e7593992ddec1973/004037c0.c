
int open_socket(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined2 local_80;
  undefined1 auStack_7e [114];
  
  iVar1 = (*(code *)&UNK_00401450)(1,2,0);
  if (iVar1 < 0) {
    pcVar4 = "cannot create unix domain socket";
    goto LAB_004038bc;
  }
  ndelay_on(iVar1);
  close_on_exec(iVar1);
  local_80 = 1;
  (*(code *)&UNK_00401550)(auStack_7e,param_1);
  (*(code *)&UNK_00401530)(param_1);
  iVar2 = (*(code *)&UNK_00401580)(iVar1,&local_80,0x6e);
  if (iVar2 < 0) {
    pcVar4 = "bind(%s)";
LAB_00403888:
    iVar3 = perror_and_die(pcVar4,param_1);
  }
  else {
    iVar2 = (*(code *)&UNK_004013e0)(param_1,0x1b6);
    iVar3 = 0x410000;
    if (iVar2 < 0) {
      pcVar4 = "chmod(%s)";
      goto LAB_00403888;
    }
  }
  iVar2 = (*(code *)&UNK_00401370)(iVar1,*(uint *)(iVar3 + 0x6b74) >> 3 | 1);
  if (-1 < iVar2) {
    return iVar1;
  }
  pcVar4 = "listen";
LAB_004038bc:
  perror_and_die(pcVar4);
  return iVar1;
}

