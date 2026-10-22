
undefined4 callback_2de506d0(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (100 < (g_dfb_lock_flag & 0xffff)) {
    printf(" exec lock count overflow...%s:dfb_lock_flag:%x\n",
           "_IDirectFBSurface_SetSrcBlendFunction",g_dfb_lock_flag);
  }
  while ((g_dfb_lock_flag & 0xffff0000) != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
    printf("dfb api blocked by dfb destroying thread...%s:%08x\n",
           "_IDirectFBSurface_SetSrcBlendFunction",g_dfb_lock_flag);
    usleep(30000);
    pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  }
  g_dfb_lock_flag = g_dfb_lock_flag + 1;
  uVar2 = 0x13;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    uVar2 = 4;
    if (iVar1 != 0) {
      if (param_2 - 1 < 0xc) {
        if (param_2 != *(uint *)(iVar1 + 0x104)) {
          *(uint *)(iVar1 + 0x104) = param_2;
          *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) | 0x10;
        }
        if (*(int *)(iVar1 + 0x10c) != 0) {
          *(undefined4 *)(iVar1 + 0x10c) = 0;
          *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) | 0x1000000;
          uVar2 = 0;
          goto LAB_2de50834;
        }
      }
      else {
        uVar2 = 9;
        if ((param_2 & 0x100) == 0) goto LAB_2de50834;
        if (*(int *)(iVar1 + 0x104) != 2) {
          *(undefined4 *)(iVar1 + 0x104) = 2;
          *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) | 0x10;
        }
        if (param_2 != *(uint *)(iVar1 + 0x10c)) {
          *(uint *)(iVar1 + 0x10c) = param_2;
          *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) | 0x1000000;
          uVar2 = 0;
          goto LAB_2de50834;
        }
      }
      uVar2 = 0;
    }
  }
LAB_2de50834:
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if ((g_dfb_lock_flag & 0xffff) == 0) {
    printf("error:unlock count equal to zero...%s:%d\n","_IDirectFBSurface_SetSrcBlendFunction",
           0xf85);
  }
  g_dfb_lock_flag = g_dfb_lock_flag - 1;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  return uVar2;
}

