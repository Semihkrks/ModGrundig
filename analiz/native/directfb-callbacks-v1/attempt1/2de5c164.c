
undefined4 callback_2de5c164(int *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (100 < (g_dfb_lock_flag & 0xffff)) {
    printf(" exec lock count overflow...%s:dfb_lock_flag:%x\n","_IDirectFBSurface_SetSrcColorKey",
           g_dfb_lock_flag);
  }
  while ((g_dfb_lock_flag & 0xffff0000) != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
    printf("dfb api blocked by dfb destroying thread...%s:%08x\n","_IDirectFBSurface_SetSrcColorKey"
           ,g_dfb_lock_flag);
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
      iVar1 = *(int *)(iVar2 + 0x68);
      uVar3 = 0x15;
      if (iVar1 != 0) {
        *(undefined1 *)(iVar2 + 0x29c) = param_2;
        *(undefined1 *)(iVar2 + 0x29d) = param_3;
        *(undefined1 *)(iVar2 + 0x29e) = param_4;
        if (*(int *)(iVar1 + 0x110) << 1 < 0) {
          uVar3 = dfb_palette_search(*(undefined4 *)(iVar1 + 0x1c4),param_2,param_3,param_4,0x80);
          *(undefined4 *)(iVar2 + 0x2a0) = uVar3;
          uVar3 = 0;
        }
        else {
          uStack_30 = 0;
          uStack_2f = param_2;
          uStack_2e = param_3;
          uStack_2d = param_4;
          uVar3 = dfb_pixel_from_color(*(int *)(iVar1 + 0x110),&uStack_30);
          *(undefined4 *)(iVar2 + 0x2a0) = uVar3;
          uVar3 = 0;
        }
      }
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if ((g_dfb_lock_flag & 0xffff) == 0) {
    printf("error:unlock count equal to zero...%s:%d\n","_IDirectFBSurface_SetSrcColorKey",0xfd5);
  }
  g_dfb_lock_flag = g_dfb_lock_flag - 1;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  return uVar3;
}

