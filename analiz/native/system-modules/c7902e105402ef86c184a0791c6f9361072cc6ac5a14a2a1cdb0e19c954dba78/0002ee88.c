
undefined4 ntfs_init_locked_inode(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = *param_2;
  (*(code *)&memset)(param_1 + -0x70,0,0x70);
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + -0x70) = *param_2;
  *(undefined4 *)(param_1 + -0x6c) = uVar1;
  *(undefined4 *)(param_1 + -0xc) = param_2[3];
  *(undefined4 *)(param_1 + -8) = param_2[4];
  *(undefined4 *)(param_1 + -0x10) = param_2[2];
  return 0;
}

