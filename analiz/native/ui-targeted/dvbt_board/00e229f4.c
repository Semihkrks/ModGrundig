
/* PictureSettingsFrame::InitializeMenuItems() */

void __thiscall PictureSettingsFrame::InitializeMenuItems(PictureSettingsFrame *this)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uStack_198;
  uint uStack_194;
  int iStack_c0;
  undefined *puStack_bc;
  int iStack_b0;
  undefined *puStack_ac;
  int iStack_a0;
  undefined *puStack_9c;
  int iStack_90;
  undefined *puStack_8c;
  int iStack_80;
  undefined *puStack_7c;
  int iStack_70;
  undefined *puStack_6c;
  int iStack_5c;
  undefined *puStack_58;
  int iStack_48;
  undefined *puStack_44;
  int iStack_38;
  undefined *puStack_34;
  int iStack_28;
  undefined *puStack_24;
  
  if (PTR_DAT_010c4438[-0x7ad0] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7ad0);
    if (iVar2 != 0) {
      puStack_24 = PTR_DAT_010c4438 + -0x7864;
      for (iStack_28 = 6; iStack_28 != -1; iStack_28 = iStack_28 + -1) {
                    /* try { // try from 00e22a88 to 00e22a8f has its CatchHandler @ 00e22b00 */
        (*(code *)PTR_MString_010c5d38)(puStack_24);
        puStack_24 = puStack_24 + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7ad0);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x1b74,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7864,0xe4c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7858,0xbd2);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x784c,0xbdb);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7840,0x97c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7834,0xa81);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7828,0xad3);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x781c,0xafc);
  *(undefined **)(*(int *)(this + 0x20c) + 0x250) = PTR_DAT_010c4438 + -0x7864;
  *(undefined4 *)(*(int *)(this + 0x20c) + 0x254) = 7;
  iVar2 = *(int *)(this + 0x20c);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_Is3DSuitable_010c9590)(uVar3);
  if (iVar2 == 0) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x20c),1,0);
  }
  if (PTR_DAT_010c4438[-0x7ac8] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7ac8);
    if (iVar2 != 0) {
      puStack_34 = PTR_DAT_010c4438 + -0x7888;
      for (iStack_38 = 2; iStack_38 != -1; iStack_38 = iStack_38 + -1) {
                    /* try { // try from 00e22dcc to 00e22dd3 has its CatchHandler @ 00e22e44 */
        (*(code *)PTR_MString_010c5d38)(puStack_34);
        puStack_34 = puStack_34 + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7ac8);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x1af0,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7888,0xdc8);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x787c,0xc85);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7870,0xd96);
  *(undefined **)(*(int *)(this + 0x21c) + 0x250) = PTR_DAT_010c4438 + -0x7888;
  *(undefined4 *)(*(int *)(this + 0x21c) + 0x254) = 3;
  iVar2 = *(int *)(this + 0x21c);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_Get3DDepth_010cb2f4)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  if (PTR_DAT_010c4438[-0x7ac0] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7ac0);
    if (iVar2 != 0) {
      puStack_44 = PTR_DAT_010c4438 + -0x78e8;
      for (iStack_48 = 7; iStack_48 != -1; iStack_48 = iStack_48 + -1) {
                    /* try { // try from 00e23048 to 00e2304f has its CatchHandler @ 00e230c0 */
        (*(code *)PTR_MString_010c5d38)(puStack_44);
        puStack_44 = puStack_44 + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7ac0);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x1a6c,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78e8,0xbee);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78dc,1);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78d0,0);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78c4,0xf);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78b8,0x3b);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78ac,0xfb8);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78a0,0x43);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7894,0x37);
  *(undefined **)(*(int *)(this + 0x198) + 0x250) = PTR_DAT_010c4438 + -0x78e8;
  *(undefined4 *)(*(int *)(this + 0x198) + 0x254) = 8;
  iVar2 = *(int *)(this + 0x198);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetPictureFormat_010cb698)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  uVar3 = (*(code *)PTR_getInstance_010c67ec)();
  iVar2 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar3);
  if (iVar2 == 0xc) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x198),1,0);
  }
  else {
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
    iVar2 = (*(code *)PTR_GetDualWatchStatus_010ca194)(uVar3);
    if (iVar2 == 0) {
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x198),1,1);
    }
    else {
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x198),1,0);
    }
  }
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_IsTvIn4kMode_010c5aa4)(uVar3);
  if (iVar2 == 0) {
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    iVar2 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar3);
    if (iVar2 != 0) {
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar2 = (*(code *)PTR_ArMainScaler_GetPanelParameter_010c9dc0)(uVar3);
      if (iVar2 != 0) goto LAB_00e23450;
    }
    bVar1 = false;
  }
  else {
LAB_00e23450:
    bVar1 = true;
  }
  if (bVar1) {
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x198));
  }
  if (PTR_DAT_010c4438[-0x7ab8] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7ab8);
    if (iVar2 != 0) {
      puStack_58 = PTR_DAT_010c4438 + -0x7924;
      for (iStack_5c = 4; iStack_5c != -1; iStack_5c = iStack_5c + -1) {
                    /* try { // try from 00e234f8 to 00e234ff has its CatchHandler @ 00e23570 */
        (*(code *)PTR_MString_010c5d38)(puStack_58);
        puStack_58 = puStack_58 + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7ab8);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x19e8,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7924,0x1049);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -31000,0xe1c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x790c,0x1001);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7900,0xd82);
  piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
  iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
  if (iVar2 == 0x17) {
LAB_00e23890:
    bVar1 = true;
  }
  else {
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x18) goto LAB_00e23890;
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x19) goto LAB_00e23890;
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x1a) goto LAB_00e23890;
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x10) goto LAB_00e23890;
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x11) goto LAB_00e23890;
    piVar4 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    iVar2 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if (iVar2 == 0x12) goto LAB_00e23890;
    bVar1 = false;
  }
  if (bVar1) {
    (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x78f4,0xd70);
    *(undefined4 *)(*(int *)(this + 0x19c) + 0x254) = 5;
  }
  else {
    *(undefined4 *)(*(int *)(this + 0x19c) + 0x254) = 4;
  }
  *(undefined **)(*(int *)(this + 0x19c) + 0x250) = PTR_DAT_010c4438 + -0x7924;
  iVar2 = *(int *)(this + 0x19c);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetPictureMode_010c9acc)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  if (PTR_DAT_010c4438[-0x7ab0] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7ab0);
    if (iVar2 != 0) {
      puStack_6c = PTR_DAT_010c4438 + -0x793c;
      for (iStack_70 = 1; iStack_70 != -1; iStack_70 = iStack_70 + -1) {
                    /* try { // try from 00e239a4 to 00e239ab has its CatchHandler @ 00e23a1c */
        (*(code *)PTR_MString_010c5d38)(puStack_6c);
        puStack_6c = puStack_6c + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7ab0);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x1964,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x793c,0xe4c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7930,0xe4d);
  *(undefined **)(*(int *)(this + 0x1a8) + 0x250) = PTR_DAT_010c4438 + -0x793c;
  *(undefined4 *)(*(int *)(this + 0x1a8) + 0x254) = 2;
  uVar3 = (*(code *)PTR_GetSystemDatabase_010c86e8)();
  iVar2 = (*(code *)PTR_GetFactALSEnabled_010ca9f4)(uVar3);
  if (iVar2 != 0) {
    iVar2 = *(int *)(this + 0x1a8);
    uVar3 = (*(code *)PTR_GetSystemDatabase_010c86e8)();
    uVar3 = (*(code *)PTR_GetALSEnabled_010c55c8)(uVar3);
    *(undefined4 *)(iVar2 + 0x264) = uVar3;
    uVar3 = (*(code *)PTR_getInstance_010cd270)();
    iVar2 = (*(code *)PTR_GetShopMode_010c7314)(uVar3);
    if (iVar2 == 0) {
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x1a8));
    }
    else {
      *(undefined4 *)(*(int *)(this + 0x1a8) + 0x264) = 0;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1a8));
    }
    if (*(int *)(*(int *)(this + 0x1a8) + 0x264) == 1) {
      uVar3 = (*(code *)PTR_GetSystemDatabase_010c86e8)();
      (*(code *)PTR_SetALSEnabled_010c4b5c)(uVar3,1);
      (*(code *)PTR_SkipItem_010cc264)(*(undefined4 *)(this + 0x1a0),1,1);
      (*(code *)PTR_SkipItem_010cc264)(*(undefined4 *)(this + 0x1a0),2,1);
    }
    else {
      uVar3 = (*(code *)PTR_GetSystemDatabase_010c86e8)();
      (*(code *)PTR_SetALSEnabled_010c4b5c)(uVar3,0);
      (*(code *)PTR_ClearSkipState_010c982c)(*(undefined4 *)(this + 0x1a0));
    }
  }
  if (PTR_DAT_010c4438[-0x7aa8] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7aa8);
    if (iVar2 != 0) {
      puStack_7c = PTR_DAT_010c4438 + -0x7978;
      for (iStack_80 = 4; iStack_80 != -1; iStack_80 = iStack_80 + -1) {
                    /* try { // try from 00e23d8c to 00e23d93 has its CatchHandler @ 00e23e04 */
        (*(code *)PTR_MString_010c5d38)(puStack_7c);
        puStack_7c = puStack_7c + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7aa8);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x18e0,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7978,4000);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x796c,0x31);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7960,0x32);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7954,0x2f);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7948,0x33);
  *(undefined **)(*(int *)(this + 0x1a0) + 0x250) = PTR_DAT_010c4438 + -0x7978;
  *(undefined4 *)(*(int *)(this + 0x1a0) + 0x254) = 5;
  iVar2 = *(int *)(this + 0x1a0);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetBacklight_010cb868)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_GetBacklight_010cb868)(uVar3);
  if (iVar2 == 0) {
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    iVar2 = (*(code *)PTR_isActive3DModeEnable_010c991c)(uVar3);
    if (iVar2 == 0) {
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),1,1);
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),2,1);
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x1a4));
    }
    else {
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),1,0);
      (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1a4));
    }
  }
  else {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),1,0);
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),2,0);
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1a4));
  }
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_isActive3DModeEnable_010c991c)(uVar3);
  if (iVar2 != 0) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a0),1,0);
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1a0));
  }
  if (PTR_DAT_010c4438[-0x7aa0] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7aa0);
    if (iVar2 != 0) {
      puStack_8c = PTR_DAT_010c4438 + -0x799c;
      for (iStack_90 = 2; iStack_90 != -1; iStack_90 = iStack_90 + -1) {
                    /* try { // try from 00e24234 to 00e2423b has its CatchHandler @ 00e242ac */
        (*(code *)PTR_MString_010c5d38)(puStack_8c);
        puStack_8c = puStack_8c + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7aa0);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x185c,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7984,0xc86);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7990,0xe3b);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x799c,0xc84);
  *(undefined **)(*(int *)(this + 0x1c8) + 0x250) = PTR_DAT_010c4438 + -0x799c;
  *(undefined4 *)(*(int *)(this + 0x1c8) + 0x254) = 3;
  iVar2 = *(int *)(this + 0x1c8);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetColourTemperature_010cc02c)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  if (PTR_DAT_010c4438[-0x7a98] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7a98);
    if (iVar2 != 0) {
      puStack_9c = PTR_DAT_010c4438 + -0x7a38;
      for (iStack_a0 = 0xc; iStack_a0 != -1; iStack_a0 = iStack_a0 + -1) {
                    /* try { // try from 00e244b0 to 00e244b7 has its CatchHandler @ 00e24528 */
        (*(code *)PTR_MString_010c5d38)(puStack_9c);
        puStack_9c = puStack_9c + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7a98);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x17d8,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a38,2);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a2c,3);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a20,4);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a14,5);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a08,6);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79fc,7);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79f0,8);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79e4,9);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79d8,10);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79cc,0xb);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79c0,0xc);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79b4,0xd);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x79a8,0xe);
  *(undefined **)(*(int *)(this + 0x1d0) + 0x250) = PTR_DAT_010c4438 + -0x7a38;
  *(undefined4 *)(*(int *)(this + 0x1d0) + 0x254) = 0xd;
  iVar2 = *(int *)(this + 0x1d0);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetGamma_010c7014)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  if (PTR_DAT_010c4438[-0x7a90] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7a90);
    if (iVar2 != 0) {
      puStack_ac = PTR_DAT_010c4438 + -0x7a68;
      for (iStack_b0 = 3; iStack_b0 != -1; iStack_b0 = iStack_b0 + -1) {
                    /* try { // try from 00e24844 to 00e2484b has its CatchHandler @ 00e248bc */
        (*(code *)PTR_MString_010c5d38)(puStack_ac);
        puStack_ac = puStack_ac + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7a90);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x1754,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a68,0xe4c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a5c,0xdc8);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a50,0xc85);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a44,0xd96);
  *(undefined **)(*(int *)(this + 0x1cc) + 0x250) = PTR_DAT_010c4438 + -0x7a68;
  *(undefined4 *)(*(int *)(this + 0x1cc) + 0x254) = 4;
  iVar2 = *(int *)(this + 0x1cc);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetVibrantColour_010c59c8)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1dc) + 0x250) = PTR_DAT_010c4438 + -0x7a68;
  *(undefined4 *)(*(int *)(this + 0x1dc) + 0x254) = 4;
  iVar2 = *(int *)(this + 0x1dc);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetDynamicContrast_010c4d94)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1f8) + 0x250) = PTR_DAT_010c4438 + -0x7a68;
  *(undefined4 *)(*(int *)(this + 0x1f8) + 0x254) = 4;
  iVar2 = *(int *)(this + 0x1f8);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetNoiseReduction_010cb0dc)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1fc) + 0x250) = PTR_DAT_010c4438 + -0x7a68;
  *(undefined4 *)(*(int *)(this + 0x1fc) + 0x254) = 4;
  iVar2 = *(int *)(this + 0x1fc);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetBlockNoiseReduction_010c9d40)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1ec) + 0x250) = PTR_DAT_010c4438 + -0x7a68;
  *(undefined4 *)(*(int *)(this + 0x1ec) + 0x254) = 4;
  iVar2 = *(int *)(this + 0x1ec);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetMEMC_010ca944)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar2 = (*(code *)PTR_ArPanelConf_GetUrsaSelection_010c8e4c)(uVar3);
  if (iVar2 == 0) {
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1ec));
  }
  if (PTR_DAT_010c4438[-0x7a88] == '\0') {
    iVar2 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7a88);
    if (iVar2 != 0) {
      puStack_bc = PTR_DAT_010c4438 + -0x7a80;
      for (iStack_c0 = 1; iStack_c0 != -1; iStack_c0 = iStack_c0 + -1) {
                    /* try { // try from 00e24c7c to 00e24c83 has its CatchHandler @ 00e24cf4 */
        (*(code *)PTR_MString_010c5d38)(puStack_bc);
        puStack_bc = puStack_bc + 0xc;
      }
      (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7a88);
      (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c444c + 0x16d0,0,PTR_DAT_010c432c);
    }
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a74,0xe4d);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7a80,0xe4c);
  *(undefined **)(*(int *)(this + 0x224) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x224) + 0x254) = 2;
  iVar2 = *(int *)(this + 0x224);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_Get3DLRCorrection_010ca49c)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar3);
  if (iVar2 == 1) {
LAB_00e24f04:
    bVar1 = true;
  }
  else {
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    iVar2 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar3);
    if (iVar2 == 2) goto LAB_00e24f04;
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    iVar2 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar3);
    if (iVar2 == 0) goto LAB_00e24f04;
    bVar1 = false;
  }
  if (bVar1) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x224),1,0);
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x224));
  }
  else {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x224),1,1);
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x224));
  }
  *(undefined **)(*(int *)(this + 0x214) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x214) + 0x254) = 2;
  iVar2 = *(int *)(this + 0x214);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_Get3DEffectMode_010c53e4)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  (*(code *)PTR_OnNtyKey_ComboButton_3D_Mode_010ca9c8)(this,0,0,0);
  *(undefined **)(*(int *)(this + 0x1e8) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x1e8) + 0x254) = 2;
  iVar2 = *(int *)(this + 0x1e8);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetFilmMode_010c536c)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1d8) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x1d8) + 0x254) = 2;
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d8),2,0);
  *(undefined **)(*(int *)(this + 0x1e0) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x1e0) + 0x254) = 2;
  iVar2 = *(int *)(this + 0x1e0);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetPerfectClear_010cbb94)(uVar3);
  *(undefined4 *)(iVar2 + 0x264) = uVar3;
  *(undefined **)(*(int *)(this + 0x1e4) + 0x250) = PTR_DAT_010c4438 + -0x7a80;
  *(undefined4 *)(*(int *)(this + 0x1e4) + 0x254) = 2;
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_GetFPGAExistence_010c4d54)(uVar3);
  if (iVar2 == 1) {
    iVar2 = *(int *)(this + 0x1e4);
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    uVar3 = (*(code *)PTR_GetMicroDimming_010c84ac)(uVar3);
    *(undefined4 *)(iVar2 + 0x264) = uVar3;
  }
  else {
    *(undefined4 *)(*(int *)(this + 0x1e4) + 0x264) = 0;
  }
  iVar2 = *(int *)(this + 0x1b8);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetBrightness_010c7e68)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  iVar2 = *(int *)(this + 0x1bc);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetContrast_010ca630)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  iVar2 = *(int *)(this + 0x1c0);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetColour_010caca4)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  iVar2 = *(int *)(this + 0x1c4);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetTint_010c9c74)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  iVar2 = *(int *)(this + 500);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetSharpness_010cca34)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  iVar6 = *(int *)(this + 0x218);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  iVar2 = (*(code *)PTR_Get3DPerpective_010c9da8)(uVar3);
  *(int *)(iVar6 + 0x268) = iVar2 + -5;
  iVar2 = *(int *)(this + 0x1a4);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  uVar3 = (*(code *)PTR_GetBacklightManual_010cae80)(uVar3);
  *(undefined4 *)(iVar2 + 0x268) = uVar3;
  *(undefined4 *)(*(int *)(this + 0x1ac) + 0xac) = *(undefined4 *)(this + 0x1ac);
  *(undefined4 *)(*(int *)(this + 0x1ac) + 0xa8) = *(undefined4 *)(this + 0x1ac);
  *(undefined4 *)(*(int *)(this + 0x1b0) + 0xac) = *(undefined4 *)(this + 0x1b0);
  *(undefined4 *)(*(int *)(this + 0x1b0) + 0xa8) = *(undefined4 *)(this + 0x1b0);
  uVar3 = (*(code *)PTR_getInstance_010c67ec)();
  iVar2 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar3);
  if (iVar2 != 2) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),2,0);
  }
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ac),1,1);
  (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1ac));
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar2 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar3);
  if (iVar2 == 1) {
    uVar3 = (*(code *)PTR_getInstance_010cd270)();
    iVar2 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar3);
    if (iVar2 == 1) {
      bVar1 = true;
      goto LAB_00e2546c;
    }
  }
  bVar1 = false;
LAB_00e2546c:
  if (bVar1) {
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x198));
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x19c));
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1a0));
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1a4));
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1ac));
  }
  (**(code **)(**(int **)(this + 0x184) + 0x48))(*(undefined4 *)(this + 0x184));
  (**(code **)(**(int **)(this + 400) + 0x48))(*(undefined4 *)(this + 400));
  for (uStack_194 = 0;
      uVar5 = (**(code **)(**(int **)(this + 0x184) + 0x44))(*(undefined4 *)(this + 0x184)),
      uStack_194 < uVar5; uStack_194 = uStack_194 + 1) {
    uVar3 = (**(code **)(**(int **)(this + 0x184) + 0x40))(*(undefined4 *)(this + 0x184),uStack_194)
    ;
    (*(code *)PTR_Invalidate_010c4e28)(uVar3);
  }
  for (uStack_198 = 0;
      uVar5 = (**(code **)(**(int **)(this + 400) + 0x44))(*(undefined4 *)(this + 400)),
      uStack_198 < uVar5; uStack_198 = uStack_198 + 1) {
    uVar3 = (**(code **)(**(int **)(this + 400) + 0x40))(*(undefined4 *)(this + 400),uStack_198);
    (*(code *)PTR_Invalidate_010c4e28)(uVar3);
  }
  return;
}

