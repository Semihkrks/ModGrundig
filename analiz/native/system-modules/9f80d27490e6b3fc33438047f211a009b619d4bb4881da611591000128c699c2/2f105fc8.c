
undefined4 direct_initialize(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_2f12a358;
  (*(code *)PTR_pthread_mutex_lock_2f12a47c)(PTR_DAT_2f12a358 + -0x5930);
  iVar2 = *(int *)(PTR_DAT_2f12a358 + -0x5918);
  *(int *)(PTR_DAT_2f12a358 + -0x5918) = iVar2 + 1;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_direct_thread_self_name_2f12a53c)();
    if (iVar2 == 0) {
      (*(code *)PTR_direct_thread_set_name_2f12a4d0)(PTR_LAB_2f12a368 + 0x7a70);
    }
    (*(code *)PTR_direct_signals_initialize_2f12a5d8)();
  }
  (*(code *)PTR_pthread_mutex_unlock_2f12a550)(puVar1 + -0x5930);
  return 0;
}

