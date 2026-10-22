
bool FUN_0047dcec(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30);
  bVar2 = true;
  if (iVar3 < (int)param_2) {
    (*(code *)&UNK_004053d0)
              (*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x30),iVar3);
    *(undefined4 *)(param_1 + 0x30) = 0;
    iVar1 = FUN_0040a78c(*(undefined4 *)(param_1 + 0xc),*(int *)(param_1 + 0x24) + iVar3,
                         0x4000 - iVar3);
    *(int *)(param_1 + 0x34) = iVar1;
    if (iVar1 < 0) {
      FUN_004088a4("read error");
      bVar2 = false;
    }
    else {
      bVar2 = param_2 <= (uint)(iVar1 + iVar3);
      *(int *)(param_1 + 0x34) = iVar1 + iVar3;
    }
  }
  return bVar2;
}

