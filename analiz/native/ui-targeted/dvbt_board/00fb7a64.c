
undefined4 FUN_00fb7a64(int param_1)

{
  (*(code *)PTR_KillTimer_010c786c)(param_1,0);
  if (*(int *)(param_1 + 0x1bc) != 0) {
    *(undefined4 *)(param_1 + 0x1bc) = 0;
  }
  *(undefined4 *)PTR_pApp_010c60d8 = 0;
  return 1;
}

