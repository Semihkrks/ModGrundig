
void __aio_init(aioinit *init)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  (*(code *)PTR_pthread_mutex_lock_2f777104)(PTR___aio_requests_mutex_2f777068);
  puVar1 = PTR_DAT_2f777058;
  if (*(int *)(PTR_DAT_2f777058 + 0x7230) == 0) {
    uVar4 = init->aio_num;
    iVar2 = 1;
    if (0 < init->aio_threads) {
      iVar2 = init->aio_threads;
    }
    *(int *)(PTR_DAT_2f777058 + 0x7018) = iVar2;
    uVar3 = 0x20;
    if (0x1f < (int)uVar4) {
      uVar3 = uVar4 & 0xffffffdf;
    }
    *(uint *)(puVar1 + 0x701c) = uVar3;
  }
  if (init->aio_idle_time != 0) {
    *(int *)(PTR_DAT_2f777058 + 0x7030) = init->aio_idle_time;
  }
                    /* WARNING: Could not recover jumptable at 0x2f761ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_pthread_mutex_unlock_2f777154)(PTR___aio_requests_mutex_2f777068);
  return;
}

