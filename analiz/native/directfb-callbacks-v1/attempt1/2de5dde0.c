
undefined4 callback_2de5dde0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (100 < (g_dfb_lock_flag & 0xffff)) {
    printf(" exec lock count overflow...%s:dfb_lock_flag:%x\n","_IDirectFBSurface_Release",
           g_dfb_lock_flag);
  }
  while ((g_dfb_lock_flag & 0xffff0000) != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
    printf("dfb api blocked by dfb destroying thread...%s:%08x\n","_IDirectFBSurface_Release",
           g_dfb_lock_flag);
    usleep(30000);
    pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  }
  g_dfb_lock_flag = g_dfb_lock_flag + 1;
  uVar3 = 0x13;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    uVar3 = 4;
    if (iVar2 != 0) {
      uVar3 = 0;
      iVar1 = *(int *)(iVar2 + 0xc) + -1;
      *(int *)(iVar2 + 0xc) = iVar1;
      if (iVar1 == 0) {
        uVar3 = 0;
        IDirectFBSurface_Destruct(param_1);
      }
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if ((g_dfb_lock_flag & 0xffff) == 0) {
    printf("error:unlock count equal to zero...%s:%d\n","_IDirectFBSurface_Release",0xe3c);
  }
  g_dfb_lock_flag = g_dfb_lock_flag - 1;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  return uVar3;
}

