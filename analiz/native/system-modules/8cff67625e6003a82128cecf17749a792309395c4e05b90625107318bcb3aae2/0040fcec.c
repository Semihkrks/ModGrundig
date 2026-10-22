
void FUN_0040fcec(int param_1,int param_2,undefined4 param_3,int param_4)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = (short *)(param_1 + param_2 * 2);
  if (*psVar1 == 0) {
    return;
  }
  (*(code *)&UNK_00405040)(&UNK_004c219c,param_3);
  iVar2 = 1;
  for (param_4 = param_4 << 1; param_4 != 0; param_4 = param_4 + -1) {
    if (*(char *)((int)psVar1 + iVar2) == ' ') goto LAB_0040fd80;
    psVar1 = (short *)((int)psVar1 + 1);
    iVar2 = -iVar2;
  }
LAB_0040fd94:
                    /* WARNING: Could not recover jumptable at 0x0040598c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_putchar_unlocked_004ed628)(10);
  return;
LAB_0040fd80:
  for (; (param_4 != 0 && (*(char *)((int)psVar1 + iVar2) != '\0'));
      psVar1 = (short *)((int)psVar1 + 1)) {
    (*(code *)&UNK_0040990c)();
    iVar2 = -iVar2;
    param_4 = param_4 + -1;
  }
  goto LAB_0040fd94;
}

