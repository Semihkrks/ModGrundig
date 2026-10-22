
undefined4 callback_2de50308(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (100 < (g_dfb_lock_flag & 0xffff)) {
    printf(" exec lock count overflow...%s:dfb_lock_flag:%x\n","_IDirectFBSurface_SetAlphaCmpMode",
           g_dfb_lock_flag);
  }
  while ((g_dfb_lock_flag & 0xffff0000) != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
    printf("dfb api blocked by dfb destroying thread...%s:%08x\n",
           "_IDirectFBSurface_SetAlphaCmpMode",g_dfb_lock_flag);
    usleep(30000);
    pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  }
  g_dfb_lock_flag = g_dfb_lock_flag + 1;
  uVar2 = 0x13;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    uVar2 = 4;
    if ((iVar1 != 0) && (uVar2 = 0, param_2 != *(int *)(iVar1 + 0x110))) {
      *(int *)(iVar1 + 0x110) = param_2;
      *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) | 0x100000;
      uVar2 = 0;
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if ((g_dfb_lock_flag & 0xffff) == 0) {
    printf("error:unlock count equal to zero...%s:%d\n","_IDirectFBSurface_SetAlphaCmpMode",0xf90);
  }
  g_dfb_lock_flag = g_dfb_lock_flag - 1;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  return uVar2;
}

