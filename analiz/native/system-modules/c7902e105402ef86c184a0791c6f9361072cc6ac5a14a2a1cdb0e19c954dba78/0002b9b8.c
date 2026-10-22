
void ntfs_index_ctx_reinit(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  ntfs_index_ctx_free();
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar1 = param_2[2];
  (*(code *)&memset)(param_2,0,0x1c0);
  param_2[2] = uVar1;
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return;
}

