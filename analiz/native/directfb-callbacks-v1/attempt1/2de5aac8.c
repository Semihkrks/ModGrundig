
undefined4 callback_2de5aac8(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (100 < (g_dfb_lock_flag & 0xffff)) {
    printf(" exec lock count overflow...%s:dfb_lock_flag:%x\n","_IDirectFBSurface_StretchBlit",
           g_dfb_lock_flag);
  }
  while ((g_dfb_lock_flag & 0xffff0000) != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
    printf("dfb api blocked by dfb destroying thread...%s:%08x\n","_IDirectFBSurface_StretchBlit",
           g_dfb_lock_flag);
    usleep(30000);
    pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  }
  g_dfb_lock_flag = g_dfb_lock_flag + 1;
  uVar6 = 0x13;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if (param_1 == (int *)0x0) goto LAB_2de5aec4;
  iVar8 = *param_1;
  uVar6 = 4;
  if ((iVar8 == 0) || (uVar6 = 0x15, *(int *)(iVar8 + 0x68) == 0)) goto LAB_2de5aec4;
  if (*(int *)(iVar8 + 0x3c) != 0) {
    uVar6 = 8;
    if (((*(int *)(iVar8 + 0x40) == 0) || (uVar6 = 0xc, *(char *)(iVar8 + 0x6c) != '\0')) ||
       (uVar6 = 9, param_2 == (int *)0x0)) goto LAB_2de5aec4;
    iVar7 = *param_2;
    if ((*(int *)(iVar7 + 0x3c) == 0) || (*(int *)(iVar7 + 0x40) == 0)) goto LAB_2de5aec0;
    if (param_4 != (int *)0x0) {
      if ((0 < param_4[2]) && (0 < param_4[3])) {
        iStack_38 = *param_4 + *(int *)(iVar8 + 0x14);
        iStack_34 = param_4[1] + *(int *)(iVar8 + 0x18);
        iStack_30 = param_4[2];
        iStack_2c = param_4[3];
        goto LAB_2de5ac88;
      }
LAB_2de5af78:
      uVar6 = 9;
      goto LAB_2de5aec4;
    }
    iStack_38 = *(int *)(iVar8 + 0x14);
    iStack_34 = *(int *)(iVar8 + 0x18);
    iStack_30 = *(int *)(iVar8 + 0x1c);
    iStack_2c = *(int *)(iVar8 + 0x20);
LAB_2de5ac88:
    if (param_3 == (int *)0x0) {
      iStack_48 = *(int *)(iVar7 + 0x14);
      iStack_44 = *(int *)(iVar7 + 0x18);
      iStack_40 = *(int *)(iVar7 + 0x1c);
      iStack_3c = *(int *)(iVar7 + 0x20);
    }
    else {
      if ((param_3[2] < 1) || (param_3[3] < 1)) goto LAB_2de5af78;
      iStack_48 = *param_3 + *(int *)(iVar7 + 0x14);
      iStack_44 = param_3[1] + *(int *)(iVar7 + 0x18);
      iStack_40 = param_3[2];
      iStack_3c = param_3[3];
    }
    iVar4 = iStack_3c;
    iVar3 = iStack_40;
    iVar2 = iStack_44;
    iVar1 = iStack_48;
    iVar5 = dfb_rectangle_intersect(&iStack_48,iVar7 + 0x34);
    if (iVar5 != 0) {
      if (iVar1 != iStack_48) {
        iStack_38 = iStack_38 +
                    (int)(((float)iStack_30 / (float)iVar3) * (float)(iStack_48 - iVar1) + 0.5);
      }
      if (iVar2 != iStack_44) {
        iStack_34 = iStack_34 +
                    (int)(((float)iStack_2c / (float)iVar4) * (float)(iStack_44 - iVar2) + 0.5);
      }
      if (iVar3 != iStack_40) {
        fVar9 = ((float)iStack_40 / (float)iVar3) * (float)iStack_30;
        iStack_30 = ((int)(fVar9 + 12582912.0) + 1) - (int)(12582912.0 - fVar9) >> 1;
      }
      if (iVar4 != iStack_3c) {
        fVar9 = ((float)iStack_3c / (float)iVar4) * (float)iStack_2c;
        iStack_2c = ((int)(fVar9 + 12582912.0) + 1) - (int)(12582912.0 - fVar9) >> 1;
      }
      dfb_state_set_source(iVar8 + 0xa8,*(undefined4 *)(iVar7 + 0x68));
      if (((*(uint *)(iVar8 + 0xe0) & 8) != 0) &&
         (*(int *)(iVar7 + 0x2a0) != *(int *)(iVar8 + 0x118))) {
        *(int *)(iVar8 + 0x118) = *(int *)(iVar7 + 0x2a0);
        *(uint *)(iVar8 + 0xd4) = *(uint *)(iVar8 + 0xd4) | 0x40;
      }
      uVar6 = dfb_gfxcard_stretchblit(&iStack_48,&iStack_38,iVar8 + 0xa8);
      goto LAB_2de5aec4;
    }
  }
LAB_2de5aec0:
  uVar6 = 8;
LAB_2de5aec4:
  pthread_mutex_lock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  if ((g_dfb_lock_flag & 0xffff) == 0) {
    printf("error:unlock count equal to zero...%s:%d\n","_IDirectFBSurface_StretchBlit",0x10f2);
  }
  g_dfb_lock_flag = g_dfb_lock_flag - 1;
  pthread_mutex_unlock((pthread_mutex_t *)g_dfb_lock_counter_mutex);
  return uVar6;
}

