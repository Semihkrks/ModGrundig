
undefined4
IDirectFBSurface_Construct
          (undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,int *param_5,
          int param_6,uint param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar9 = (undefined4 *)*param_1;
  local_30 = *(int *)(param_6 + 0x108);
  local_2c = *(int *)(param_6 + 0x10c);
  local_38 = 0;
  local_34 = 0;
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = calloc(1,0x2e8);
    *param_1 = puVar9;
  }
  uVar1 = *(uint *)(param_6 + 0x114);
  puVar9[3] = 1;
  puVar9[4] = param_7 | uVar1;
  puVar9[0xb1] = param_8;
  iVar2 = fusion_ref_up(param_6 + 0x20,0);
  if (iVar2 != 0) {
LAB_2de4df78:
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
    param_1[1] = 0;
    free(param_1);
    return 1;
  }
  if ((param_2 != (int *)0x0) && (*(char *)(dfb_config + 0x5c4) != '\0')) {
    iVar2 = (*(code *)param_2[2])(param_2);
    if (iVar2 != 0) {
      fusion_ref_down(param_6 + 0x20,0);
      goto LAB_2de4df78;
    }
    iVar2 = *param_2;
    if (iVar2 == 0) {
      return 4;
    }
    pthread_mutex_lock((pthread_mutex_t *)(iVar2 + 0x2d0));
    iVar4 = *(int *)(iVar2 + 0x2cc);
    puVar9[1] = 0;
    if (iVar4 == 0) {
      *(undefined4 **)(iVar2 + 0x2cc) = puVar9;
      puVar9[2] = puVar9;
    }
    else {
      iVar6 = *(int *)(iVar4 + 8);
      puVar9[2] = iVar6;
      *(undefined4 **)(iVar6 + 4) = puVar9;
      *(undefined4 **)(iVar4 + 8) = puVar9;
    }
    *puVar9 = 0x80b1b25;
    pthread_mutex_unlock((pthread_mutex_t *)(iVar2 + 0x2d0));
    puVar9[0xb2] = param_2;
  }
  pthread_mutex_init((pthread_mutex_t *)(puVar9 + 0xb4),(pthread_mutexattr_t *)0x0);
  if (param_5 != (int *)0x0) {
    iVar2 = param_5[1];
    iVar4 = param_5[2];
    iVar6 = param_5[3];
    puVar9[0x11] = *param_5;
    puVar9[0x12] = iVar2;
    puVar9[0x13] = iVar4;
    puVar9[0x14] = iVar6;
    local_30 = (-*param_5 - param_5[2]) + local_30;
    local_2c = (-param_5[1] - param_5[3]) + local_2c;
    local_38 = local_38 + *param_5;
    local_34 = local_34 + param_5[1];
    if ((local_30 < 1) || (local_2c < 1)) {
      local_2c = 0;
      local_30 = 0;
    }
  }
  if (param_3 == (undefined4 *)0x0) {
    puVar9[6] = local_34;
    puVar9[7] = local_30;
    puVar9[5] = local_38;
    puVar9[8] = local_2c;
  }
  else {
    uVar7 = param_3[3];
    uVar3 = param_3[1];
    uVar5 = param_3[2];
    puVar9[5] = *param_3;
    puVar9[6] = uVar3;
    puVar9[7] = uVar5;
    puVar9[8] = uVar7;
  }
  if (param_4 == (undefined4 *)0x0) {
    uVar3 = puVar9[5];
    uVar5 = puVar9[6];
    uVar7 = puVar9[7];
    uVar8 = puVar9[8];
    puVar9[9] = uVar3;
    puVar9[10] = uVar5;
    puVar9[0xb] = uVar7;
    puVar9[0xc] = uVar8;
  }
  else {
    uVar3 = *param_4;
    uVar5 = param_4[1];
    uVar7 = param_4[2];
    uVar8 = param_4[3];
    puVar9[9] = uVar3;
    puVar9[10] = uVar5;
    puVar9[0xb] = uVar7;
    puVar9[0xc] = uVar8;
  }
  puVar9[0xe] = uVar5;
  puVar9[0xf] = uVar7;
  puVar9[0x10] = uVar8;
  puVar9[0xd] = uVar3;
  dfb_rectangle_intersect(puVar9 + 0xd,&local_38);
  puVar9[0x1a] = param_6;
  *(bool *)(puVar9 + 0x15) = param_4 != (undefined4 *)0x0;
  dfb_state_init(puVar9 + 0x2a,0);
  dfb_state_set_destination(puVar9 + 0x2a,param_6);
  iVar4 = puVar9[0xd];
  iVar2 = puVar9[0xf];
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  puVar9[0x3b] = iVar4 + -1 + iVar2;
  iVar6 = puVar9[0xe];
  iVar2 = puVar9[0x10];
  puVar9[0x35] = 0x11f37fff;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  puVar9[0x3c] = iVar6 + -1 + iVar2;
  param_1[3] = &UNK_2de5dde0;
  puVar9[0x39] = iVar4;
  param_1[2] = &UNK_2de5195c;
  param_1[5] = &UNK_2de5157c;
  param_1[4] = &UNK_2de51770;
  param_1[7] = &UNK_2de51194;
  param_1[6] = &UNK_2de51388;
  param_1[9] = &UNK_2de533a4;
  param_1[8] = &UNK_2de50fbc;
  param_1[0xb] = &UNK_2de5d4ec;
  param_1[10] = &UNK_2de5d710;
  param_1[0xd] = &UNK_2de5256c;
  param_1[0xc] = &UNK_2de5d2e4;
  param_1[0xf] = &UNK_2de5d104;
  param_1[0xe] = &UNK_2de50dcc;
  param_1[0x11] = &UNK_2de5cb14;
  param_1[0x10] = &UNK_2de5cd0c;
  param_1[0x13] = &UNK_2de5c3b0;
  param_1[0x12] = &UNK_2de5c6c0;
  param_1[0x15] = &UNK_2de53cb4;
  param_1[0x14] = &UNK_2de50bb4;
  param_1[0x17] = &UNK_2de506d0;
  param_1[0x16] = &UNK_2de50928;
  param_1[0x40] = &UNK_2de50308;
  param_1[0x18] = &UNK_2de504e4;
  puVar9[0x3a] = iVar6;
  param_1[0x41] = &UNK_2de50144;
  param_1[0x42] = &UNK_2de4ff68;
  param_1[0x43] = &UNK_2de4fd64;
  param_1[0x19] = &UNK_2de4fa9c;
  param_1[0x1a] = &UNK_2de5c164;
  param_1[0x1b] = &UNK_2de4f870;
  param_1[0x1c] = &UNK_2de5bef8;
  param_1[0x1d] = &UNK_2de4f628;
  param_1[0x37] = &UNK_2de5bcd8;
  param_1[0x1e] = &UNK_2de4f450;
  param_1[0x1f] = &UNK_2de5b934;
  param_1[0x20] = &UNK_2de5b550;
  param_1[0x21] = &UNK_2de5b368;
  param_1[0x22] = &UNK_2de5aac8;
  param_1[0x4a] = &UNK_2de5a5bc;
  param_1[0x23] = &UNK_2de5a3cc;
  param_1[0x24] = &UNK_2de4f278;
  param_1[0x25] = &UNK_2de52308;
  param_1[0x27] = &UNK_2de5dfbc;
  param_1[0x28] = &UNK_2de54c24;
  param_1[0x26] = &UNK_2de59cd4;
  param_1[0x29] = &UNK_2de596b8;
  param_1[0x2a] = &UNK_2de54a54;
  param_1[0x2b] = &UNK_2de59af4;
  param_1[0x2c] = &UNK_2de594e8;
  param_1[0x2d] = &UNK_2de4f05c;
  param_1[0x2e] = &UNK_2de4ee68;
  param_1[0x2f] = &UNK_2de590b4;
  param_1[0x3f] = &UNK_2de58a38;
  param_1[0x30] = &UNK_2de5824c;
  param_1[0x48] = &UNK_2de5805c;
  param_1[0x31] = &UNK_2de4eca8;
  param_1[0x32] = &UNK_2de4e970;
  param_1[0x33] = &UNK_2de5669c;
  param_1[0x34] = &UNK_2de5641c;
  uVar3 = *(undefined4 *)(param_6 + 0x90);
  param_1[0x35] = &UNK_2de4e798;
  param_1[0x36] = &UNK_2de56064;
  param_1[0x38] = &UNK_2de4e5bc;
  param_1[0x39] = &UNK_2de56244;
  param_1[0x3a] = &UNK_2de55df0;
  param_1[0x3b] = &UNK_2de4e260;
  param_1[0x3c] = &UNK_2de55b94;
  param_1[0x3d] = &UNK_2de55938;
  param_1[0x3e] = &UNK_2de5398c;
  param_1[0x44] = &UNK_2de55150;
  param_1[0x45] = &UNK_2de54e98;
  param_1[0x46] = &UNK_2de54670;
  param_1[0x47] = &UNK_2de54180;
  param_1[0x49] = &UNK_2de52ddc;
  param_1[0x4b] = &UNK_2de53f70;
  param_1[0x4c] = &UNK_2de536e0;
  param_1[0x4d] = &UNK_2de4e0cc;
  param_1[0x4e] = &UNK_2de5311c;
  param_1[0x4f] = FUN_2de5d9e8;
  param_1[0x50] = &UNK_2de52ba4;
  param_1[0x51] = &UNK_2de52830;
  param_1[0x52] = &UNK_2de51fc4;
  param_1[0x53] = &UNK_2de51de4;
  fusion_reactor_attach(uVar3,&UNK_2de4d734,param_1,puVar9 + 0xab);
  return 0;
}

