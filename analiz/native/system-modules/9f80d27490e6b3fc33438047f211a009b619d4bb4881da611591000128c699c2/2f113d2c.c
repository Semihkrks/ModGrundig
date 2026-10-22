
void direct_thread_remove_init_handler(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_2f12a358;
  (*(code *)PTR_pthread_mutex_lock_2f12a47c)(PTR_DAT_2f12a358 + -0x5158);
  puVar2 = PTR_DAT_2f12a358;
  iVar4 = param_1[1];
  iVar5 = param_1[2];
  if (iVar4 == 0) {
    *(int *)(*(int *)(PTR_DAT_2f12a358 + -0x5140) + 8) = iVar5;
    puVar3 = *(undefined4 **)(puVar2 + -0x5140);
  }
  else {
    *(int *)(iVar4 + 8) = iVar5;
    puVar3 = *(undefined4 **)(puVar2 + -0x5140);
  }
  if (param_1 == puVar3) {
    *(int *)(PTR_DAT_2f12a358 + -0x5140) = iVar4;
  }
  else {
    *(int *)(iVar5 + 4) = iVar4;
  }
  puVar2 = PTR_pthread_mutex_unlock_2f12a550;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  (*(code *)puVar2)(puVar1 + -0x5158);
  param_1[3] = 0;
                    /* WARNING: Could not recover jumptable at 0x2f113dbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_free_2f12a584)(param_1);
  return;
}

