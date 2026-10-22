
/* SoundSettingsFrame::InitializeMenuItems() */

void __thiscall SoundSettingsFrame::InitializeMenuItems(SoundSettingsFrame *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_160;
  undefined1 auStack_158 [4];
  undefined1 auStack_154 [4];
  undefined1 auStack_150 [4];
  undefined1 auStack_14c [4];
  undefined1 auStack_148 [4];
  undefined1 auStack_144 [4];
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [4];
  undefined1 auStack_138 [4];
  undefined1 auStack_134 [144];
  int iStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  int iStack_90;
  undefined *puStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  int iStack_80;
  undefined *puStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  int iStack_70;
  undefined *puStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined1 *puStack_50;
  int iStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined *puStack_38;
  undefined *puStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined *puStack_28;
  undefined *puStack_24;
  undefined4 uStack_20;
  
  (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c4460 + -0x5e40);
  if ((PTR_DAT_010c4438[-0x73c0] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x73c0), iVar1 != 0))
  {
    uStack_20 = 0;
    puStack_28 = PTR_DAT_010c4438 + -0x72a4;
    puStack_24 = puStack_28;
    for (iStack_2c = 5; iStack_2c != -1; iStack_2c = iStack_2c + -1) {
                    /* try { // try from 00ee46fc to 00ee4703 has its CatchHandler @ 00ee4774 */
      (*(code *)PTR_MString_010c5d38)(puStack_28);
      puStack_28 = puStack_28 + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x73c0);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x415c,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7298,0x1001);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x728c,0xe1c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7280,0xc30);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7274,0xc2b);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7268,4000);
  *(undefined **)(*(int *)(this + 0x194) + 0x250) = PTR_DAT_010c4438 + -0x72a4;
  *(undefined4 *)(*(int *)(this + 0x194) + 0x254) = 6;
  iVar1 = *(int *)(this + 0x194);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetSoundMode_010ca2f4)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  if ((PTR_DAT_010c4438[-0x73b8] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x73b8), iVar1 != 0))
  {
    uStack_30 = 0;
    puStack_38 = PTR_DAT_010c4438 + -0x72bc;
    puStack_34 = puStack_38;
    for (iStack_3c = 1; iStack_3c != -1; iStack_3c = iStack_3c + -1) {
                    /* try { // try from 00ee49b0 to 00ee49b7 has its CatchHandler @ 00ee4a28 */
      (*(code *)PTR_MString_010c5d38)(puStack_38);
      puStack_38 = puStack_38 + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x73b8);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x40d8,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x72bc,0x17);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x72b0,0x54);
  *(undefined **)(*(int *)(this + 0x1ac) + 0x250) = PTR_DAT_010c4438 + -0x72bc;
  *(undefined4 *)(*(int *)(this + 0x1ac) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1ac);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetLocation_010c637c)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  if ((PTR_DAT_010c4438[-0x73b0] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x73b0), iVar1 != 0))
  {
    uStack_40 = 0;
    puStack_48 = PTR_DAT_010c4438 + -0x731c;
    puStack_44 = puStack_48;
    for (iStack_4c = 7; iStack_4c != -1; iStack_4c = iStack_4c + -1) {
                    /* try { // try from 00ee4c10 to 00ee4c17 has its CatchHandler @ 00ee4c88 */
      (*(code *)PTR_MString_010c5d38)(puStack_48);
      puStack_48 = puStack_48 + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x73b0);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x4054,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7310,0x8a);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7304,0x52);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x72f8,0x53);
  (*(code *)PTR_allocator_010c6920)(auStack_138);
                    /* try { // try from 00ee4e00 to 00ee4e07 has its CatchHandler @ 00ee4f10 */
  (*(code *)PTR_string_010c4f9c)(auStack_134,PTR_DAT_010c4460 + -0x5e1c,auStack_138);
                    /* try { // try from 00ee4e20 to 00ee4e27 has its CatchHandler @ 00ee4ea8 */
  (*(code *)PTR_Set_010cb39c)(PTR_DAT_010c4438 + -0x731c,auStack_134);
  puStack_50 = auStack_134;
                    /* try { // try from 00ee4e3c to 00ee4e43 has its CatchHandler @ 00ee4f10 */
  (*(code *)PTR__string_010c5070)(puStack_50);
  (*(code *)PTR__allocator_010c4948)(auStack_138);
  (*(code *)PTR_allocator_010c6920)(auStack_140);
                    /* try { // try from 00ee4e94 to 00ee4e9b has its CatchHandler @ 00ee5038 */
  (*(code *)PTR_string_010c4f9c)(auStack_13c,PTR_DAT_010c4460 + -0x5e14,auStack_140);
                    /* try { // try from 00ee4efc to 00ee4f03 has its CatchHandler @ 00ee4fd0 */
  (*(code *)PTR_Set_010cb39c)(PTR_DAT_010c4438 + -0x72ec,auStack_13c);
  puStack_54 = auStack_13c;
                    /* try { // try from 00ee4f64 to 00ee4f6b has its CatchHandler @ 00ee5038 */
  (*(code *)PTR__string_010c5070)(puStack_54);
  (*(code *)PTR__allocator_010c4948)(auStack_140);
  (*(code *)PTR_allocator_010c6920)(auStack_148);
                    /* try { // try from 00ee4fbc to 00ee4fc3 has its CatchHandler @ 00ee5160 */
  (*(code *)PTR_string_010c4f9c)(auStack_144,PTR_DAT_010c4460 + -0x5e08,auStack_148);
                    /* try { // try from 00ee5024 to 00ee502b has its CatchHandler @ 00ee50f8 */
  (*(code *)PTR_Set_010cb39c)(PTR_DAT_010c4438 + -0x72e0,auStack_144);
  puStack_58 = auStack_144;
                    /* try { // try from 00ee508c to 00ee5093 has its CatchHandler @ 00ee5160 */
  (*(code *)PTR__string_010c5070)(puStack_58);
  (*(code *)PTR__allocator_010c4948)(auStack_148);
  (*(code *)PTR_allocator_010c6920)(auStack_150);
                    /* try { // try from 00ee50e4 to 00ee50eb has its CatchHandler @ 00ee5288 */
  (*(code *)PTR_string_010c4f9c)(auStack_14c,PTR_DAT_010c4460 + -0x5df8,auStack_150);
                    /* try { // try from 00ee514c to 00ee5153 has its CatchHandler @ 00ee5220 */
  (*(code *)PTR_Set_010cb39c)(PTR_DAT_010c4438 + -0x72d4,auStack_14c);
  puStack_5c = auStack_14c;
                    /* try { // try from 00ee51b4 to 00ee51bb has its CatchHandler @ 00ee5288 */
  (*(code *)PTR__string_010c5070)(puStack_5c);
  (*(code *)PTR__allocator_010c4948)(auStack_150);
  (*(code *)PTR_allocator_010c6920)(auStack_158);
                    /* try { // try from 00ee520c to 00ee5213 has its CatchHandler @ 00ee53b0 */
  (*(code *)PTR_string_010c4f9c)(auStack_154,PTR_DAT_010c4460 + -0x5de8,auStack_158);
                    /* try { // try from 00ee5274 to 00ee527b has its CatchHandler @ 00ee5370 */
  (*(code *)PTR_Set_010cb39c)(PTR_DAT_010c4438 + -0x72c8,auStack_154);
  puStack_60 = auStack_154;
                    /* try { // try from 00ee52dc to 00ee52e3 has its CatchHandler @ 00ee53b0 */
  (*(code *)PTR__string_010c5070)(puStack_60);
  (*(code *)PTR__allocator_010c4948)(auStack_158);
  *(undefined **)(*(int *)(this + 0x1b0) + 0x250) = PTR_DAT_010c4438 + -0x731c;
  *(undefined4 *)(*(int *)(this + 0x1b0) + 0x254) = 8;
  iVar1 = *(int *)(this + 0x1b0);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetSoundType_010caabc)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  if ((PTR_DAT_010c4438[-0x73a8] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x73a8), iVar1 != 0))
  {
    uStack_64 = 0;
    puStack_6c = PTR_DAT_010c4438 + -0x7334;
    puStack_68 = puStack_6c;
    for (iStack_70 = 1; iStack_70 != -1; iStack_70 = iStack_70 + -1) {
                    /* try { // try from 00ee544c to 00ee5453 has its CatchHandler @ 00ee54c4 */
      (*(code *)PTR_MString_010c5d38)(puStack_6c);
      puStack_6c = puStack_6c + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x73a8);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x3fd0,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7328,0xe4d);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7334,0xe4c);
  *(undefined **)(*(int *)(this + 0x198) + 0x250) = PTR_DAT_010c4438 + -0x7334;
  *(undefined4 *)(*(int *)(this + 0x198) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x198);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetNightMode_010c8bb4)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  *(undefined **)(*(int *)(this + 0x1b8) + 0x250) = PTR_DAT_010c4438 + -0x7334;
  *(undefined4 *)(*(int *)(this + 0x1b8) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1b8);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetAVL_010ccd48)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  *(undefined **)(*(int *)(this + 0x1c8) + 0x250) = PTR_DAT_010c4438 + -0x7334;
  *(undefined4 *)(*(int *)(this + 0x1c8) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1c8);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetTvSpeaker_010cc7e8)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  *(undefined **)(*(int *)(this + 0x1cc) + 0x250) = PTR_DAT_010c4438 + -0x7334;
  *(undefined4 *)(*(int *)(this + 0x1cc) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1cc);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetARC_010c8684)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  *(undefined **)(*(int *)(this + 0x19c) + 0x250) = PTR_DAT_010c4438 + -0x7334;
  *(undefined4 *)(*(int *)(this + 0x19c) + 0x254) = 2;
  *(undefined4 *)(*(int *)(this + 0x19c) + 0x264) = 0;
  (*(code *)PTR_SetText_010c84a8)
            (*(undefined4 *)(*(int *)(this + 0x1a0) + 0x260),PTR_DAT_010c4460 + -0x5dd8);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a0),1,0);
  if ((PTR_DAT_010c4438[-0x73a0] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x73a0), iVar1 != 0))
  {
    uStack_74 = 0;
    puStack_7c = PTR_DAT_010c4438 + -0x7358;
    puStack_78 = puStack_7c;
    for (iStack_80 = 2; iStack_80 != -1; iStack_80 = iStack_80 + -1) {
                    /* try { // try from 00ee5824 to 00ee582b has its CatchHandler @ 00ee589c */
      (*(code *)PTR_MString_010c5d38)(puStack_7c);
      puStack_7c = puStack_7c + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x73a0);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x3f4c,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7340,0xd9c);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7358,0xc06);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x734c,0xd5e);
  *(undefined **)(*(int *)(this + 0x1d0) + 0x250) = PTR_DAT_010c4438 + -0x7358;
  *(undefined4 *)(*(int *)(this + 0x1d0) + 0x254) = 3;
  iVar1 = *(int *)(this + 0x1d0);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetAudioOut_010c9680)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  if ((PTR_DAT_010c4438[-0x7398] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7398), iVar1 != 0))
  {
    uStack_84 = 0;
    puStack_8c = PTR_DAT_010c4438 + -0x7370;
    puStack_88 = puStack_8c;
    for (iStack_90 = 1; iStack_90 != -1; iStack_90 = iStack_90 + -1) {
                    /* try { // try from 00ee5aa0 to 00ee5aa7 has its CatchHandler @ 00ee5b18 */
      (*(code *)PTR_MString_010c5d38)(puStack_8c);
      puStack_8c = puStack_8c + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7398);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x3ec8,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7370,0xc06);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7364,0xd5e);
  *(undefined **)(*(int *)(this + 0x1d4) + 0x250) = PTR_DAT_010c4438 + -0x7370;
  *(undefined4 *)(*(int *)(this + 0x1d4) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1d4);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetScartOutputStatus_010c645c)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  if ((PTR_DAT_010c4438[-0x7390] == '\0') &&
     (iVar1 = (*(code *)PTR___cxa_guard_acquire_010cb08c)(PTR_DAT_010c4438 + -0x7390), iVar1 != 0))
  {
    uStack_94 = 0;
    puStack_9c = PTR_DAT_010c4438 + -0x7388;
    puStack_98 = puStack_9c;
    for (iStack_a0 = 1; iStack_a0 != -1; iStack_a0 = iStack_a0 + -1) {
                    /* try { // try from 00ee5d00 to 00ee5d07 has its CatchHandler @ 00ee5d78 */
      (*(code *)PTR_MString_010c5d38)(puStack_9c);
      puStack_9c = puStack_9c + 0xc;
    }
    (*(code *)PTR___cxa_guard_release_010c9c40)(PTR_DAT_010c4438 + -0x7390);
    (*(code *)PTR___cxa_atexit_010c7274)(PTR_LAB_010c4474 + 0x3e44,0,PTR_DAT_010c432c);
  }
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x7388,0xaaf);
  (*(code *)PTR_Set_010c61fc)(PTR_DAT_010c4438 + -0x737c,0xbee);
  *(undefined **)(*(int *)(this + 0x1dc) + 0x250) = PTR_DAT_010c4438 + -0x7388;
  *(undefined4 *)(*(int *)(this + 0x1dc) + 0x254) = 2;
  iVar1 = *(int *)(this + 0x1dc);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetOpticOut_010c59ac)(uVar2);
  *(undefined4 *)(iVar1 + 0x264) = uVar2;
  iVar1 = *(int *)(this + 0x1c4);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetHeadphoneVolume_010ca764)(uVar2);
  *(undefined4 *)(iVar1 + 0x268) = uVar2;
  iVar1 = *(int *)(this + 0x1d8);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetScartOutVolume_010cb514)(uVar2);
  *(undefined4 *)(iVar1 + 0x268) = uVar2;
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1d4));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1d8));
  if (*(int *)(*(int *)(this + 0x194) + 0x264) == 5) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),1,1);
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x198),1,0);
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),1,1);
  }
  else {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),1,0);
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),1,0);
  }
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  iVar1 = (*(code *)PTR_GetDualWatchStatus_010ca194)(uVar2);
  if (iVar1 == 1) {
    *(undefined4 *)(*(int *)(this + 0x1d0) + 0x264) = 2;
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d0),1,0);
  }
  uVar2 = (*(code *)PTR_getInstance_010c538c)();
  iVar1 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(this + 0x1c8);
    uVar2 = (*(code *)PTR_getInstance_010c909c)();
    uVar2 = (*(code *)PTR_GetTvSpeaker_010cc7e8)(uVar2);
    *(undefined4 *)(iVar1 + 0x264) = uVar2;
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),1,1);
  }
  else {
    uVar3 = (*(code *)PTR_GetMSrvSystemDatabase_010cb630)();
    iVar1 = (*(code *)PTR_GetARCSetting_010c7e4c)(uVar3);
    if (iVar1 == 0) {
      iVar1 = *(int *)(this + 0x1c8);
      uVar2 = (*(code *)PTR_getInstance_010c909c)();
      uVar2 = (*(code *)PTR_GetTvSpeaker_010cc7e8)(uVar2);
      *(undefined4 *)(iVar1 + 0x264) = uVar2;
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),1,1);
    }
    else {
      iVar1 = (*(code *)PTR_IsARCActive_010c858c)(uVar2);
      if (iVar1 == 0) {
        *(undefined4 *)(*(int *)(this + 0x1c8) + 0x264) = 1;
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),1,1);
        *(undefined4 *)(*(int *)(this + 0x1cc) + 0x264) = 0;
      }
      else {
        *(undefined4 *)(*(int *)(this + 0x1c8) + 0x264) = 0;
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),1,0);
        *(undefined4 *)(*(int *)(this + 0x1cc) + 0x264) = 1;
      }
    }
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),1,1);
  }
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  iVar1 = (*(code *)PTR_GetDualWatchStatus_010ca194)(uVar2);
  if (iVar1 != 0) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),1,0);
  }
  if (*(int *)(*(int *)(this + 0x1d0) + 0x264) == 2) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),1,1);
  }
  else {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),1,0);
  }
  if (*(int *)(*(int *)(this + 0x1d4) + 0x264) == 0) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d8),1,1);
  }
  else {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d8),1,0);
  }
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  iVar1 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_getInstance_010c67ec)();
    iVar1 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
    if (iVar1 != 0xc) {
      uVar2 = (*(code *)PTR_getInstance_010c67ec)();
      iVar1 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
      if (iVar1 != 5) {
        iStack_a4 = 1;
        goto LAB_00ee648c;
      }
    }
  }
  iStack_a4 = 0;
LAB_00ee648c:
  if (iStack_a4 != 0) {
    (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1dc),1,0);
  }
  iVar1 = *(int *)(this + 0x1bc);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetLipsyncUIValue_010ca154)(uVar2);
  *(undefined4 *)(iVar1 + 0x268) = uVar2;
  for (uStack_160 = 0;
      uVar4 = (**(code **)(**(int **)(this + 0x184) + 0x44))(*(undefined4 *)(this + 0x184)),
      uStack_160 < uVar4; uStack_160 = uStack_160 + 1) {
    uVar2 = (**(code **)(**(int **)(this + 0x184) + 0x40))(*(undefined4 *)(this + 0x184),uStack_160)
    ;
    (*(code *)PTR_Invalidate_010c4e28)(uVar2);
  }
  (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c4460 + -0x5dd0);
  return;
}

