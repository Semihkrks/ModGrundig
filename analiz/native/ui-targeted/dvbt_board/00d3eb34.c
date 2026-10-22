
/* HomePageFrame::OnKey(void*, void*, void*) */

undefined4 HomePageFrame::OnKey(void *param_1,void *param_2,void *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iStack_1dc;
  undefined4 uStack_1bc;
  undefined1 auStack_1a4 [4];
  undefined1 auStack_1a0 [4];
  undefined1 auStack_19c [4];
  undefined1 auStack_198 [4];
  undefined1 auStack_194 [4];
  undefined1 auStack_190 [4];
  undefined1 auStack_18c [4];
  undefined1 auStack_188 [4];
  undefined1 auStack_184 [4];
  undefined1 auStack_180 [4];
  undefined1 auStack_17c [4];
  undefined1 auStack_178 [2];
  undefined2 uStack_176;
  undefined1 uStack_174;
  byte bStack_173;
  undefined1 auStack_16c [2];
  undefined2 uStack_16a;
  undefined1 uStack_168;
  byte bStack_167;
  undefined1 auStack_160 [2];
  undefined2 uStack_15e;
  undefined1 uStack_15c;
  byte bStack_15b;
  undefined1 auStack_154 [12];
  undefined1 auStack_148 [184];
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  uint uStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  void *pvStack_20;
  
  if (param_3 == (void *)0xf045) {
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar3 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
    if (iVar3 == 1) {
      uVar2 = (*(code *)PTR_getInstance_010cd270)();
      uVar4 = (*(code *)PTR_getInstance_010cd270)();
      iVar3 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar4);
      (*(code *)PTR_SetBasicMode_010c8f14)(uVar2,iVar3 == 0);
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      uVar4 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
      uVar4 = (*(code *)PTR_GetPrivateData_010ca218)(uVar4);
      (*(code *)PTR_RestartHomePage_010c4c80)(uVar2,uVar4);
      return 1;
    }
  }
  if (param_3 == (void *)0xf014) {
    (*(code *)PTR_EnableBubbleHelp_010cabe8)(param_1);
    return 1;
  }
  iVar3 = (*(code *)PTR_size_010cbda0)((int)param_1 + 0x2a0);
  if ((param_3 != (void *)0xf052) && ((param_3 < (void *)0x30 || ((void *)0x39 < param_3)))) {
    *(undefined1 *)((int)param_1 + 0x2b0) = 0;
  }
  pvStack_20 = param_3;
  if (param_3 == (void *)0xf012) {
LAB_00d4132c:
    uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
    return 1;
  }
  if ((void *)0xf012 < param_3) {
    if (param_3 == (void *)0xf075) {
      iVar3 = (**(code **)(**(int **)((int)param_1 + 400) + 0x44))
                        (*(undefined4 *)((int)param_1 + 400));
      for (iStack_1dc = 0; iStack_1dc < iVar3; iStack_1dc = iStack_1dc + 1) {
        iVar5 = (**(code **)(**(int **)((int)param_1 + 400) + 0x40))
                          (*(undefined4 *)((int)param_1 + 400),iStack_1dc);
        *(undefined1 *)(iVar5 + 0x38) = 1;
      }
      iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)((int)param_1 + 0x194),2);
      if (iVar3 == 0) {
        iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)((int)param_1 + 0x198),2);
        if (iVar3 == 0) {
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
          return 1;
        }
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)((int)param_1 + 0x198));
        (*(code *)PTR_SetText_010c78b4)(*(undefined4 *)((int)param_1 + 0x19c),0x11a6);
        (*(code *)PTR_Show_010cc98c)(*(undefined4 *)((int)param_1 + 0x19c));
        (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)((int)param_1 + 0x1b0));
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)((int)param_1 + 0x1b0),8,0);
        return 1;
      }
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)((int)param_1 + 0x194));
      (*(code *)PTR_SetText_010c78b4)(*(undefined4 *)((int)param_1 + 0x19c),0xf49);
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)((int)param_1 + 0x19c));
      (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)((int)param_1 + 0x1c8));
      (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)((int)param_1 + 0x1c8),8,0);
      return 1;
    }
    if ((void *)0xf075 < param_3) {
      if (5 < (int)param_3 - 0xf551U) {
        return 0;
      }
      return 1;
    }
    if (param_3 == (void *)0xf052) {
      *(undefined1 *)((int)param_1 + 0x2b0) = 1;
      return 0;
    }
    if (param_3 != (void *)0xf062) {
      return 0;
    }
    goto LAB_00d4132c;
  }
  if ((void *)0x39 < param_3) {
    if (3 < (int)param_3 - 0xf000U) {
      return 0;
    }
    uVar2 = (*(code *)PTR_HandleFocus_010c68bc)(param_1,param_3,0,0x3d);
    return uVar2;
  }
  if (param_3 < (void *)0x30) {
    if (param_3 != (void *)0xd) {
      return 0;
    }
    iVar7 = *(int *)((int)param_1 + 0x3c);
    iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x4c);
    if (iVar7 != iVar5) {
      iVar7 = *(int *)((int)param_1 + 0x3c);
      iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x40);
      if (iVar7 == iVar5) {
        piVar6 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
        iVar3 = (**(code **)(*piVar6 + 0x84))(piVar6);
        if ((iVar3 != 0x1c) && (iVar3 != 1)) {
          return 0;
        }
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
        iStack_2c = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00d3f00c to 00d3f013 has its CatchHandler @ 00d3f034 */
        (*(code *)PTR_FavoriteSelectionApp_010ca1c8)(iStack_2c);
        iVar3 = iStack_2c;
        if (iStack_2c == 0) {
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                     PTR_DAT_010c43ec + -0x14ac,0x870);
          (*(code *)PTR_abort_010cc6c0)();
        }
        (*(code *)PTR_Run_010c7470)(iVar3,0x1000,0);
        return 1;
      }
      iVar7 = *(int *)((int)param_1 + 0x3c);
      iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x3d);
      if (iVar7 == iVar5) {
        (*(code *)(PTR_LAB_010c4418 + 0x5ec4))(auStack_178);
                    /* try { // try from 00d3f13c to 00d3f267 has its CatchHandler @ 00d3f454 */
        iVar3 = (*(code *)PTR_GetPinnedChannel_010c4de4)(0,auStack_178);
        if (iVar3 == 0) {
          uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
          if (iVar3 == 0) {
            (*(code *)PTR_Clean_010c8be8)();
            (*(code *)PTR_ostringstream_010c9ac8)(auStack_148,0x10);
                    /* try { // try from 00d3f274 to 00d3f307 has its CatchHandler @ 00d3f3ec */
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x1187);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,PTR_DAT_010c43ec + -0x1534);
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x10a7);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_str_010c961c)(auStack_17c,auStack_148);
                    /* try { // try from 00d3f320 to 00d3f327 has its CatchHandler @ 00d3f390 */
            (*(code *)PTR_operator__010c84b8)(PTR_informationData_010c9aa0 + 4,auStack_17c);
                    /* try { // try from 00d3f338 to 00d3f383 has its CatchHandler @ 00d3f3ec */
            (*(code *)PTR__string_010c5070)(auStack_17c);
            *(undefined4 *)PTR_informationData_010c9aa0 = 2;
            *PTR_handleBackInPopUp_010cb2e4 = 1;
            *(void **)PTR_parentFrame_010cbd4c = param_1;
            *(undefined4 *)PTR_timeout_010c6c90 = 6;
            (*(code *)PTR_Summon_010c5990)(0xb);
                    /* try { // try from 00d3f3d8 to 00d3f3df has its CatchHandler @ 00d3f454 */
            (*(code *)PTR__ostringstream_010cc6a8)(auStack_148);
          }
        }
        else {
          uVar2 = (*(code *)PTR_getInstance_010c909c)();
          (*(code *)PTR_SetSwitchToDtv_010c7464)(uVar2,1);
          (*(code *)PTR_CloseDMP_010cbcb4)();
          if (bStack_173 < 4) {
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x157c,bStack_173,uStack_176,uStack_174);
            (*(code *)PTR_SelectChannelByRoute_010cafd8)(bStack_173,uStack_176,uStack_174,0);
          }
        }
        uStack_24 = 1;
        (*(code *)(PTR_LAB_010c4418 + 0x5dac))(auStack_178);
        return uStack_24;
      }
      iVar7 = *(int *)((int)param_1 + 0x3c);
      iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x3e);
      if (iVar7 == iVar5) {
        (*(code *)(PTR_LAB_010c4418 + 0x5ec4))(auStack_16c);
                    /* try { // try from 00d3f500 to 00d3f62b has its CatchHandler @ 00d3f818 */
        iVar3 = (*(code *)PTR_GetPinnedChannel_010c4de4)(1,auStack_16c);
        if (iVar3 == 0) {
          uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
          if (iVar3 == 0) {
            (*(code *)PTR_Clean_010c8be8)();
            (*(code *)PTR_ostringstream_010c9ac8)(auStack_148,0x10);
                    /* try { // try from 00d3f638 to 00d3f6cb has its CatchHandler @ 00d3f7b0 */
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x1187);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,PTR_DAT_010c43ec + -0x1534);
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x10a7);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_str_010c961c)(auStack_180,auStack_148);
                    /* try { // try from 00d3f6e4 to 00d3f6eb has its CatchHandler @ 00d3f754 */
            (*(code *)PTR_operator__010c84b8)(PTR_informationData_010c9aa0 + 4,auStack_180);
                    /* try { // try from 00d3f6fc to 00d3f747 has its CatchHandler @ 00d3f7b0 */
            (*(code *)PTR__string_010c5070)(auStack_180);
            *(undefined4 *)PTR_informationData_010c9aa0 = 2;
            *PTR_handleBackInPopUp_010cb2e4 = 1;
            *(void **)PTR_parentFrame_010cbd4c = param_1;
            *(undefined4 *)PTR_timeout_010c6c90 = 6;
            (*(code *)PTR_Summon_010c5990)(0xb);
                    /* try { // try from 00d3f79c to 00d3f7a3 has its CatchHandler @ 00d3f818 */
            (*(code *)PTR__ostringstream_010cc6a8)(auStack_148);
          }
        }
        else {
          uVar2 = (*(code *)PTR_getInstance_010c909c)();
          (*(code *)PTR_SetSwitchToDtv_010c7464)(uVar2,1);
          (*(code *)PTR_CloseDMP_010cbcb4)();
          if (bStack_167 < 4) {
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x157c,bStack_167,uStack_16a,uStack_168);
            (*(code *)PTR_SelectChannelByRoute_010cafd8)(bStack_167,uStack_16a,uStack_168,0);
          }
        }
        uStack_24 = 1;
        (*(code *)(PTR_LAB_010c4418 + 0x5dac))(auStack_16c);
        return uStack_24;
      }
      iVar7 = *(int *)((int)param_1 + 0x3c);
      iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x3f);
      if (iVar7 == iVar5) {
        (*(code *)(PTR_LAB_010c4418 + 0x5ec4))(auStack_160);
                    /* try { // try from 00d3f8c4 to 00d3f9ef has its CatchHandler @ 00d3fbdc */
        iVar3 = (*(code *)PTR_GetPinnedChannel_010c4de4)(2,auStack_160);
        if (iVar3 == 0) {
          uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
          if (iVar3 == 0) {
            (*(code *)PTR_Clean_010c8be8)();
            (*(code *)PTR_ostringstream_010c9ac8)(auStack_148,0x10);
                    /* try { // try from 00d3f9fc to 00d3fa8f has its CatchHandler @ 00d3fb74 */
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x1187);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,PTR_DAT_010c43ec + -0x1534);
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x10a7);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_str_010c961c)(auStack_184,auStack_148);
                    /* try { // try from 00d3faa8 to 00d3faaf has its CatchHandler @ 00d3fb18 */
            (*(code *)PTR_operator__010c84b8)(PTR_informationData_010c9aa0 + 4,auStack_184);
                    /* try { // try from 00d3fac0 to 00d3fb0b has its CatchHandler @ 00d3fb74 */
            (*(code *)PTR__string_010c5070)(auStack_184);
            *(undefined4 *)PTR_informationData_010c9aa0 = 2;
            *PTR_handleBackInPopUp_010cb2e4 = 1;
            *(void **)PTR_parentFrame_010cbd4c = param_1;
            *(undefined4 *)PTR_timeout_010c6c90 = 6;
            (*(code *)PTR_Summon_010c5990)(0xb);
                    /* try { // try from 00d3fb60 to 00d3fb67 has its CatchHandler @ 00d3fbdc */
            (*(code *)PTR__ostringstream_010cc6a8)(auStack_148);
          }
        }
        else {
          uVar2 = (*(code *)PTR_getInstance_010c909c)();
          (*(code *)PTR_SetSwitchToDtv_010c7464)(uVar2,1);
          (*(code *)PTR_CloseDMP_010cbcb4)();
          if (bStack_15b < 4) {
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x157c,bStack_15b,uStack_15e,uStack_15c);
            (*(code *)PTR_SelectChannelByRoute_010cafd8)(bStack_15b,uStack_15e,uStack_15c,0);
          }
        }
        uStack_24 = 1;
        (*(code *)(PTR_LAB_010c4418 + 0x5dac))(auStack_160);
        return uStack_24;
      }
      if (*(int *)((int)param_1 + 0x3c) == *(int *)((int)param_1 + 0x254)) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,9,0,0);
        return 0;
      }
      if (*(int *)((int)param_1 + 0x3c) != *(int *)((int)param_1 + 0x248)) {
        if (*(int *)((int)param_1 + 0x3c) != *(int *)((int)param_1 + 0x264)) {
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x4d);
          if (iVar7 == iVar5) {
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            cVar1 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
            if (cVar1 == '\0') {
              (*(code *)PTR_vector_010c64c0)(auStack_154);
              uStack_1bc = 0;
                    /* try { // try from 00d3feb4 to 00d3febb has its CatchHandler @ 00d40384 */
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0xc0f);
              (*(code *)PTR_allocator_010c6920)(auStack_18c);
                    /* try { // try from 00d3fef4 to 00d3fefb has its CatchHandler @ 00d3fff8 */
              (*(code *)PTR_string_010c4f9c)(auStack_188,uVar2,auStack_18c);
                    /* try { // try from 00d3ff14 to 00d3ff1b has its CatchHandler @ 00d3ff70 */
              (*(code *)PTR_push_back_010cd044)(auStack_154,auStack_188);
              puStack_38 = auStack_188;
                    /* try { // try from 00d3ff30 to 00d3ff37 has its CatchHandler @ 00d3fff8 */
              (*(code *)PTR__string_010c5070)(puStack_38);
              (*(code *)PTR__allocator_010c4948)(auStack_18c);
                    /* try { // try from 00d3ff5c to 00d3ff63 has its CatchHandler @ 00d40384 */
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0xcdd);
              (*(code *)PTR_allocator_010c6920)(auStack_194);
                    /* try { // try from 00d3ffe4 to 00d3ffeb has its CatchHandler @ 00d4012c */
              (*(code *)PTR_string_010c4f9c)(auStack_190,uVar2,auStack_194);
                    /* try { // try from 00d40048 to 00d4004f has its CatchHandler @ 00d400a4 */
              (*(code *)PTR_push_back_010cd044)(auStack_154,auStack_190);
              puStack_3c = auStack_190;
                    /* try { // try from 00d40064 to 00d4006b has its CatchHandler @ 00d4012c */
              (*(code *)PTR__string_010c5070)(puStack_3c);
              (*(code *)PTR__allocator_010c4948)(auStack_194);
                    /* try { // try from 00d40090 to 00d40097 has its CatchHandler @ 00d40384 */
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0xece);
              (*(code *)PTR_allocator_010c6920)(auStack_19c);
                    /* try { // try from 00d40118 to 00d4011f has its CatchHandler @ 00d40230 */
              (*(code *)PTR_string_010c4f9c)(auStack_198,uVar2,auStack_19c);
                    /* try { // try from 00d4017c to 00d40183 has its CatchHandler @ 00d401d4 */
              (*(code *)PTR_push_back_010cd044)(auStack_154,auStack_198);
              puStack_40 = auStack_198;
                    /* try { // try from 00d40198 to 00d4019f has its CatchHandler @ 00d40230 */
              (*(code *)PTR__string_010c5070)(puStack_40);
              (*(code *)PTR__allocator_010c4948)(auStack_19c);
                    /* try { // try from 00d401c0 to 00d401c7 has its CatchHandler @ 00d40384 */
              iVar3 = (*(code *)PTR_GetFilterType_010cb254)();
              if (iVar3 == 1) {
                uStack_1bc = 1;
              }
              else if (iVar3 == 2) {
                uStack_1bc = 2;
              }
                    /* try { // try from 00d40298 to 00d4035f has its CatchHandler @ 00d40384 */
              (*(code *)PTR_Clean_010c8be8)();
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0xd59);
              (*(code *)PTR_operator__010c90f4)(PTR_itemSelectData_010cb0d4,uVar2);
              (*(code *)PTR_operator__010c5494)(PTR_itemSelectData_010cb0d4 + 8,auStack_154);
              *(undefined4 *)(PTR_itemSelectData_010cb0d4 + 4) = uStack_1bc;
              *(void **)PTR_parentFrame_010cbd4c = param_1;
              *PTR_handleBackInPopUp_010cb2e4 = 1;
              *(undefined4 *)PTR_popupID_010c6d00 = 0x2a;
              (*(code *)PTR_ShowButton_010c85b0)(0xe,0xc42);
              (*(code *)PTR_ShowButton_010c85b0)(7,0xf37);
              (*(code *)PTR_Summon_010c5990)(1);
              (*(code *)PTR__vector_010c4e7c)(auStack_154);
            }
            else {
              (*(code *)PTR_Clean_010c8be8)();
              (*(code *)PTR_ostringstream_010c9ac8)(auStack_148,0x10);
                    /* try { // try from 00d403fc to 00d4043f has its CatchHandler @ 00d40524 */
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x11d0);
              (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
              (*(code *)PTR_str_010c961c)(auStack_1a0,auStack_148);
                    /* try { // try from 00d40458 to 00d4045f has its CatchHandler @ 00d404c8 */
              (*(code *)PTR_operator__010c84b8)(PTR_informationData_010c9aa0 + 4,auStack_1a0);
                    /* try { // try from 00d40470 to 00d404bb has its CatchHandler @ 00d40524 */
              (*(code *)PTR__string_010c5070)(auStack_1a0);
              *(undefined4 *)PTR_informationData_010c9aa0 = 2;
              *PTR_handleBackInPopUp_010cb2e4 = 1;
              *(void **)PTR_parentFrame_010cbd4c = param_1;
              *(undefined4 *)PTR_timeout_010c6c90 = 2;
              (*(code *)PTR_Summon_010c5990)(0xb);
              (*(code *)PTR__ostringstream_010cc6a8)(auStack_148);
            }
            return 1;
          }
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x46);
          if (iVar7 == iVar5) {
            uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
            uVar2 = (*(code *)PTR_getInstance_010c71c4)();
            iVar3 = (*(code *)PTR_CanStartEPG_010cb108)(uVar2);
            if (iVar3 != 0) {
              iStack_44 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
              if (iStack_44 != 0) {
                    /* try { // try from 00d40644 to 00d4064b has its CatchHandler @ 00d40660 */
                (*(code *)PTR_ProgramGuideApp_010c67dc)(iStack_44);
              }
              iVar3 = iStack_44;
              iStack_48 = iStack_44;
              if (iStack_44 == 0) {
                (*(code *)PTR_printf_010c9f10)
                          (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                           PTR_DAT_010c43ec + -0x14ac,0x992);
                (*(code *)PTR_abort_010cc6c0)();
              }
              (*(code *)PTR_Run_010c7470)(iVar3,0,0);
            }
            return 1;
          }
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x45);
          if (iVar7 == iVar5) {
            uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            iVar3 = (*(code *)PTR_GetDualWatchStatus_010ca194)(uVar2);
            if (iVar3 != 1) {
              iStack_4c = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
              if (iStack_4c != 0) {
                    /* try { // try from 00d40804 to 00d4080b has its CatchHandler @ 00d40820 */
                (*(code *)PTR_InputSourceSelectApp_010cd010)(iStack_4c);
              }
              iVar3 = iStack_4c;
              iStack_50 = iStack_4c;
              if (iStack_4c == 0) {
                (*(code *)PTR_printf_010c9f10)
                          (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                           PTR_DAT_010c43ec + -0x14ac,0x9b3);
                (*(code *)PTR_abort_010cc6c0)();
              }
              (*(code *)PTR_Run_010c7470)(iVar3,0,0);
              return 1;
            }
            return 1;
          }
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x52);
          if (iVar7 == iVar5) {
            (*(code *)PTR_CloseDMP_010cbcb4)();
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            iVar3 = (*(code *)PTR_FavSourceChange_010cab80)(uVar2);
            if (iVar3 == 0) {
              (*(code *)PTR_Clean_010c8be8)();
              uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0x110b);
              (*(code *)PTR_operator__010c90f4)(PTR_informationData_010c9aa0 + 4,uVar2);
              *(undefined4 *)PTR_informationData_010c9aa0 = 2;
              *PTR_handleBackInPopUp_010cb2e4 = 1;
              *(void **)PTR_parentFrame_010cbd4c = param_1;
              *(undefined4 *)PTR_timeout_010c6c90 = 2;
              *(undefined4 *)PTR_popupID_010c6d00 = 0x52;
              (*(code *)PTR_Summon_010c5990)(0xb);
            }
            else {
              (*(code *)PTR_Summon_010c78d8)(1,1,1);
            }
            return 1;
          }
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x4b);
          if (iVar7 == iVar5) {
            uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
            iStack_54 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
            if (iStack_54 != 0) {
                    /* try { // try from 00d40ac0 to 00d40ac7 has its CatchHandler @ 00d40adc */
              (*(code *)PTR_ToolsMenuApp_010c4e00)(iStack_54);
            }
            iVar3 = iStack_54;
            iStack_58 = iStack_54;
            if (iStack_54 == 0) {
              (*(code *)PTR_printf_010c9f10)
                        (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                         PTR_DAT_010c43ec + -0x14ac,0x9d3);
              (*(code *)PTR_abort_010cc6c0)();
            }
            (*(code *)PTR_Run_010c7470)(iVar3,0,0);
            return 1;
          }
          iVar7 = *(int *)((int)param_1 + 0x3c);
          iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x49);
          if (((iVar7 == iVar5) ||
              (iVar7 = *(int *)((int)param_1 + 0x3c),
              iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x48), iVar7 == iVar5)) ||
             (iVar7 = *(int *)((int)param_1 + 0x3c),
             iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x44), iVar7 == iVar5)) {
            iStack_5c = 1;
          }
          else {
            iStack_5c = 0;
          }
          if (iStack_5c == 0) {
            iVar7 = *(int *)((int)param_1 + 0x3c);
            iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x47);
            if (iVar7 == iVar5) {
              uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
              (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
              iStack_70 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00d41068 to 00d4106f has its CatchHandler @ 00d41090 */
              (*(code *)PTR_ArScheduleListApp_010c8ad8)(iStack_70);
              iVar3 = iStack_70;
              if (iStack_70 == 0) {
                (*(code *)PTR_printf_010c9f10)
                          (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                           PTR_DAT_010c43ec + -0x14ac,0xa3a);
                (*(code *)PTR_abort_010cc6c0)();
              }
              (*(code *)PTR_Run_010c7470)(iVar3,0,0);
              return 1;
            }
            iVar7 = *(int *)((int)param_1 + 0x3c);
            iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x4e);
            if (iVar7 == iVar5) {
              if (0 < iVar3) {
                (*(code *)PTR_ChangeToChannelHistory_010c64b0)(param_1,0);
              }
              return 1;
            }
            iVar7 = *(int *)((int)param_1 + 0x3c);
            iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x4f);
            if (iVar7 == iVar5) {
              if (1 < iVar3) {
                (*(code *)PTR_ChangeToChannelHistory_010c64b0)(param_1,1);
              }
              return 1;
            }
            iVar7 = *(int *)((int)param_1 + 0x3c);
            iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x50);
            if (iVar7 != iVar5) {
              iVar7 = *(int *)((int)param_1 + 0x3c);
              iVar5 = (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x51);
              if (iVar7 != iVar5) {
                return 0;
              }
              if (3 < iVar3) {
                (*(code *)PTR_ChangeToChannelHistory_010c64b0)(param_1,3);
              }
              return 1;
            }
            if (2 < iVar3) {
              (*(code *)PTR_ChangeToChannelHistory_010c64b0)(param_1,2);
            }
            return 1;
          }
          if (((*(int *)PTR_MMBrowser_010c8f78 == 0) &&
              (iVar3 = (*(code *)PTR_GetDMPPhotoPlayerFrame_010ca7e8)(), iVar3 == 0)) &&
             ((iVar3 = (*(code *)PTR_GetDMPMoviePlayerFrame_010c7548)(), iVar3 == 0 &&
              (iVar3 = (*(code *)PTR_GetDMPMusicPlayerFrame_010c5558)(), iVar3 == 0)))) {
            iStack_60 = 1;
          }
          else {
            iStack_60 = 0;
          }
          if (iStack_60 == 0) {
            return 1;
          }
          (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x49);
          (*(code *)PTR_GetWdgInsByID_010c6f88)(param_1,0x48);
          if (*(int *)PTR_MMBrowser_010c8f78 == 0) {
            uVar2 = (*(code *)PTR_GetSystemDatabase_010c86e8)();
            iVar3 = (*(code *)PTR_GetFactNonConnectedMode_010c7a04)(uVar2);
            if (iVar3 == 1) {
              iStack_64 = 1;
              goto LAB_00d40d4c;
            }
          }
          iStack_64 = 0;
LAB_00d40d4c:
          if (iStack_64 == 0) {
            (*(code *)PTR_ostringstream_010c9ac8)(auStack_148,0x10);
                    /* try { // try from 00d40eb4 to 00d40ef7 has its CatchHandler @ 00d40f8c */
            uVar2 = (*(code *)PTR_RcGetString_010cb7dc)(0xff8);
            (*(code *)PTR_operator<<_010c9b74)(auStack_148,uVar2);
            (*(code *)PTR_str_010c961c)(auStack_1a4,auStack_148);
                    /* try { // try from 00d40f0c to 00d40f13 has its CatchHandler @ 00d40f50 */
            (*(code *)PTR_ShowInformationPopup_010c662c)(auStack_1a4,0x59);
                    /* try { // try from 00d40f24 to 00d40f2b has its CatchHandler @ 00d40f8c */
            (*(code *)PTR__string_010c5070)(auStack_1a4);
            (*(code *)PTR__ostringstream_010cc6a8)(auStack_148);
          }
          else {
            uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
            iStack_68 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
            if (iStack_68 != 0) {
                    /* try { // try from 00d40db8 to 00d40dbf has its CatchHandler @ 00d40dd4 */
              (*(code *)PTR_DMPlayerApp_010c6fc8)(iStack_68);
            }
            iVar3 = iStack_68;
            iStack_6c = iStack_68;
            if (iStack_68 == 0) {
              (*(code *)PTR_printf_010c9f10)
                        (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                         PTR_DAT_010c43ec + -0x14ac,0xa02);
              (*(code *)PTR_abort_010cc6c0)();
            }
            (*(code *)PTR_Run_010c7470)(iVar3,0,3);
          }
          return 1;
        }
        uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
        if (iVar3 != 0) {
          uVar2 = (*(code *)PTR_getInstance_010cd270)();
          iVar3 = (*(code *)PTR_GetHotelAdmin_010c9c8c)(uVar2);
          if (iVar3 == 0) {
            iStack_34 = 1;
            goto LAB_00d3fdd0;
          }
        }
        iStack_34 = 0;
LAB_00d3fdd0:
        if (iStack_34 == 0) {
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_openMenu_010c57e4)(uVar2,6,0,0);
          return 0;
        }
        return 1;
      }
      uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
      if (iVar3 != 0) {
        uVar2 = (*(code *)PTR_getInstance_010cd270)();
        iVar3 = (*(code *)PTR_GetHotelAdmin_010c9c8c)(uVar2);
        if (iVar3 == 0) {
          iStack_30 = 1;
          goto LAB_00d3fcf8;
        }
      }
      iStack_30 = 0;
LAB_00d3fcf8:
      if (iStack_30 == 0) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,6,0,0);
        return 0;
      }
      return 1;
    }
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar3 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
    if (iVar3 == 1) {
      uVar2 = (*(code *)PTR_getInstance_010cd270)();
      iVar3 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar2);
      if (iVar3 == 1) {
        iStack_28 = 1;
        goto LAB_00d3eeb4;
      }
    }
    iStack_28 = 0;
LAB_00d3eeb4:
    if (iStack_28 == 0) {
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_openMenu_010c57e4)(uVar2,4,1,0);
    }
    else {
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_openMenu_010c57e4)(uVar2,0xf,1,0);
    }
    return 0;
  }
  *(uint *)((int)param_1 + 0x2ac) = *(int *)((int)param_1 + 0x2ac) << 4 | (int)param_3 - 0x30U;
  uStack_74 = *(uint *)((int)param_1 + 0x2ac) & 0xffff;
  if (uStack_74 == 0x4658) {
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar3 = (*(code *)PTR_ArSystemConf_GetHotel_010c60f8)(uVar2);
    if (iVar3 == 0) {
      return 1;
    }
    uVar2 = (*(code *)PTR_getInstance_010cd270)();
    (*(code *)PTR_SetHotelAdmin_010c86f4)(uVar2,1);
    iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_InitMenuBarOptions_010c82e8)(*(undefined4 *)(iVar3 + 0x1c8));
    iVar3 = *(int *)((int)param_1 + 0x26c);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x7c) = uVar2;
    iVar3 = *(int *)((int)param_1 + 0x26c);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x80) = uVar2;
    iVar3 = *(int *)((int)param_1 + 0x26c);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x84) = uVar2;
    iVar3 = *(int *)((int)param_1 + 0x250);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x7c) = uVar2;
    iVar3 = *(int *)((int)param_1 + 0x250);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x80) = uVar2;
    iVar3 = *(int *)((int)param_1 + 0x250);
    uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
    *(undefined4 *)(iVar3 + 0x84) = uVar2;
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)((int)param_1 + 0x26c));
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)((int)param_1 + 0x250));
    return 1;
  }
  if (0x4658 < uStack_74) {
    if (uStack_74 == 0x8500) {
      uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar3 = (*(code *)PTR_ArTvConf_GetOsdSelection_010cba28)(uVar2);
      if (iVar3 != 0) {
        return 1;
      }
      iStack_7c = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00d41870 to 00d41877 has its CatchHandler @ 00d41898 */
      (*(code *)PTR_Factory_Conf_MenuApp_010c8b80)(iStack_7c);
      iVar3 = iStack_7c;
      if (iStack_7c == 0) {
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14ac,
                   0xb3e);
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_Run_010c7470)(iVar3,0,0);
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
      return 1;
    }
    if (uStack_74 != 0x9301) {
      if (uStack_74 != 0x8427) {
        return 1;
      }
      (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c43ec + -0x1530);
      uVar2 = (*(code *)PTR_getInstance_010cafac)();
      (*(code *)PTR_SetScreenShotActivateFlag_010cd1c0)(uVar2,1);
      return 1;
    }
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar3 = (*(code *)PTR_ArTvConf_GetOsdSelection_010cba28)(uVar2);
    if (iVar3 == 0) {
      return 1;
    }
    iStack_78 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00d41720 to 00d41727 has its CatchHandler @ 00d41748 */
    (*(code *)PTR_Factory_Conf_MenuApp_010c8b80)(iStack_78);
    iVar3 = iStack_78;
    if (iStack_78 == 0) {
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14ac,
                 0xb2f);
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_Run_010c7470)(iVar3,0,0);
    uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
    return 1;
  }
  if (uStack_74 == 0x1628) {
    if (*(int *)PTR_InformationFrame_010c4f10 == 0) {
      iStack_80 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
      if (iStack_80 != 0) {
                    /* try { // try from 00d419ac to 00d419b3 has its CatchHandler @ 00d419c8 */
        (*(code *)PTR_InformationApp_010c8858)(iStack_80);
      }
      *(int *)PTR_InformationFrame_010c4f10 = iStack_80;
      iStack_84 = iStack_80;
      (*(code *)PTR_Run_010c7470)(*(undefined4 *)PTR_InformationFrame_010c4f10,0xff,0);
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
    }
    else {
      (*(code *)PTR_Kill_010c4dec)(*(undefined4 *)PTR_InformationFrame_010c4f10);
      *(undefined4 *)PTR_InformationFrame_010c4f10 = 0;
    }
    return 1;
  }
  if (uStack_74 != 0x2477) {
    return 1;
  }
  piVar6 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
  iVar3 = (**(code **)(*piVar6 + 0x84))(piVar6);
  if (iVar3 != 0x1c) {
    return 1;
  }
  uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar3 = (*(code *)PTR_ArTvConf_GetBissKey_010ca0f4)(uVar2);
  if (iVar3 == 1) {
    uVar2 = (*(code *)PTR_getInstance_010c67ec)();
    iVar3 = (*(code *)PTR_GetCurrentDvbAntennaType_010c90b8)(uVar2);
    if (iVar3 == 3) {
      iStack_88 = 1;
      goto LAB_00d41b70;
    }
  }
  iStack_88 = 0;
LAB_00d41b70:
  if (iStack_88 == 0) {
    return 1;
  }
  iStack_8c = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
  if (iStack_8c != 0) {
                    /* try { // try from 00d41bac to 00d41bb3 has its CatchHandler @ 00d41bc8 */
    (*(code *)PTR_BISS_MenuApp_010c9298)(iStack_8c);
  }
  iVar3 = iStack_8c;
  iStack_90 = iStack_8c;
  if (iStack_8c == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14ac,
               0xb65);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Run_010c7470)(iVar3,0,0);
  uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
  (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
  return 1;
}

