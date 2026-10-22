
/* GeneralSettingsFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
GeneralSettingsFrame::OnKey(GeneralSettingsFrame *this,void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uStack_1e0;
  int iStack_1dc;
  uint uStack_1d8;
  int iStack_1d4;
  undefined1 auStack_1cc [4];
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined1 auStack_1bc [4];
  undefined1 auStack_1b8 [4];
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined1 auStack_1a8 [4];
  undefined1 auStack_1a4 [12];
  undefined1 auStack_198 [4];
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined1 auStack_188 [4];
  undefined1 auStack_184 [4];
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined1 auStack_174 [4];
  undefined1 auStack_170 [12];
  undefined1 auStack_164 [4];
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined1 auStack_154 [4];
  undefined1 auStack_150 [4];
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [12];
  undefined1 auStack_130 [4];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [12];
  undefined1 auStack_fc [12];
  undefined1 auStack_f0 [12];
  undefined1 auStack_e4 [12];
  undefined1 auStack_d8 [12];
  undefined1 auStack_cc [100];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  
  if (param_2 == (void *)0xf014) {
    (*(code *)PTR_EnableBubbleHelp_010cabe8)(this);
    return 1;
  }
  iVar1 = (*(code *)PTR_IsTvInFirstTime_010c83c8)();
  if (iVar1 != 0) {
    pvStack_24 = param_2;
    if (param_2 == (void *)0xf003) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar4 = (*(code *)PTR_getFrame_010c8a9c)();
        (*(code *)PTR_focusToBar_010c5f9c)(uVar4,0);
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x198));
        return 1;
      }
    }
    else if (param_2 < (void *)0xf004) {
      if ((void *)0xefff < param_2) {
        if (param_2 < (void *)0xf002) {
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
            uVar4 = (*(code *)PTR_getFrame_010c8a9c)();
            uVar4 = (*(code *)PTR_OnKey_010c4c00)(uVar4,param_1,param_2,param_3);
            return uVar4;
          }
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x1fc)) {
            return 1;
          }
        }
        else {
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
            return 1;
          }
          for (uStack_1d8 = 0;
              uVar2 = (**(code **)(**(int **)(this + 0x198) + 0x44))(*(undefined4 *)(this + 0x198)),
              uStack_1d8 < uVar2; uStack_1d8 = uStack_1d8 + 1) {
            iStack_1d4 = (**(code **)(**(int **)(this + 0x198) + 0x40))
                                   (*(undefined4 *)(this + 0x198),uStack_1d8);
            iVar1 = (*(code *)PTR_QueryFlag_010ca574)(iStack_1d4,2);
            if ((iVar1 == 0) || (*(char *)(iStack_1d4 + 0x38) != '\x01')) {
              iStack_2c = 0;
            }
            else {
              iStack_2c = 1;
            }
            if (iStack_2c != 0) break;
          }
          iVar1 = (*(code *)PTR_QueryFlag_010ca574)(iStack_1d4,4);
          if (iVar1 != 0) {
            return 1;
          }
        }
      }
    }
    else {
      if (param_2 == (void *)0xf062) {
        uVar4 = (*(code *)PTR_getFrame_010c8a9c)();
        (*(code *)PTR_openMenu_010c8a58)(uVar4,0,0);
        return 1;
      }
      if (param_2 == (void *)0xf075) {
        uVar4 = (*(code *)PTR_getFrame_010c8a9c)();
        uVar4 = (*(code *)PTR_OnKey_010c4c00)(uVar4,param_1,0xf075,param_3);
        return uVar4;
      }
      if (param_2 == (void *)0xf045) {
        uVar4 = (*(code *)PTR_getFrame_010c8a9c)();
        uVar4 = (*(code *)PTR_OnKey_010c4c00)(uVar4,param_1,0xf045,param_3);
        return uVar4;
      }
    }
  }
  pvStack_20 = param_2;
  if (param_2 == (void *)0xf003) {
    if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
      return 0;
    }
    uVar4 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar1 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar4);
    if (iVar1 == 1) {
      uVar4 = (*(code *)PTR_getInstance_010cd270)();
      iVar1 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar4);
      if (iVar1 == 1) {
        iStack_34 = 1;
        goto LAB_00cffcf8;
      }
    }
    iStack_34 = 0;
LAB_00cffcf8:
    if (iStack_34 == 0) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1a8));
    }
    else {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1ac));
    }
    uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_focusToBar_010c7724)(uVar4,0);
    return 1;
  }
  if ((void *)0xf003 < param_2) {
    if (param_2 == (void *)0xf043) {
      if (*(int *)(this + 0x294) == 1) {
        puVar6 = (undefined4 *)(*(code *)PTR_at_010c9a98)(this + 0x288,param_3);
        (*(code *)PTR_SetSecondaryAudioLanguage_010cb4f8)(*puVar6);
        (*(code *)PTR_vector_010c64c0)(auStack_e4);
                    /* try { // try from 00d00b2c to 00d00b33 has its CatchHandler @ 00d00e88 */
        (*(code *)PTR_PushSubtitleAudioLanguagetoVector_010ca904)(auStack_170,this);
                    /* try { // try from 00d00b4c to 00d00b53 has its CatchHandler @ 00d00bd0 */
        (*(code *)PTR_operator__010c5494)(auStack_e4,auStack_170);
                    /* try { // try from 00d00b64 to 00d00bc3 has its CatchHandler @ 00d00e88 */
        (*(code *)PTR__vector_010c4e7c)(auStack_170);
        (*(code *)PTR_begin_010cbe64)(&uStack_178,this + 0x288);
        (*(code *)PTR_end_010c4d70)(&uStack_17c,this + 0x288);
        uStack_180 = (*(code *)PTR_GetPrimaryAudioLanguage_010c8494)();
        (*(code *)
          PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
        )(auStack_174,uStack_178,uStack_17c,&uStack_180);
        (*(code *)PTR_begin_010cbe64)(auStack_184,this + 0x288);
        uVar4 = (*(code *)PTR_operator__010cbc64)(auStack_174,auStack_184);
        (*(code *)PTR_begin_010cbe64)(&uStack_18c,this + 0x288);
        (*(code *)PTR_end_010c4d70)(&uStack_190,this + 0x288);
                    /* try { // try from 00d00ccc to 00d00e5b has its CatchHandler @ 00d00e88 */
        uStack_194 = (*(code *)PTR_GetSecondaryAudioLanguage_010c4d48)();
        (*(code *)
          PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
        )(auStack_188,uStack_18c,uStack_190,&uStack_194);
        (*(code *)PTR_begin_010cbe64)(auStack_198,this + 0x288);
        uVar5 = (*(code *)PTR_operator__010cbc64)(auStack_188,auStack_198);
        uStack_54 = (*(code *)PTR_RcGetString_010cb7dc)(0xec1);
        uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_e4,uVar4);
        uStack_58 = (*(code *)PTR_c_str_010c56fc)(uVar4);
        uStack_5c = (*(code *)PTR_RcGetString_010cb7dc)(0xf20);
        uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_e4,uVar5);
        uVar4 = (*(code *)PTR_c_str_010c56fc)(uVar4);
        (*(code *)PTR_sprintf_010c97b4)
                  (auStack_cc,PTR_DAT_010c43ec + -0x1ad4,uStack_54,uStack_58,uStack_5c,uVar4);
        (*(code *)PTR_operator__010c90f4)(PTR_gridSelectData_010c5e04 + 0xc,auStack_cc);
        uVar4 = (*(code *)PTR_GetInstance_010ca4d0)();
        (*(code *)PTR_RefreshGridInfo_010c5b08)(uVar4);
        uStack_28 = 1;
        (*(code *)PTR__vector_010c4e7c)(auStack_e4);
        return uStack_28;
      }
      if (*(int *)(this + 0x294) != 2) {
        return 0;
      }
      puVar6 = (undefined4 *)(*(code *)PTR_at_010c9a98)(this + 0x288,param_3);
      (*(code *)PTR_SetSecondarySubtitleLanguage_010c54b0)(*puVar6);
      (*(code *)PTR_vector_010c64c0)(auStack_d8);
                    /* try { // try from 00d00f48 to 00d00f4f has its CatchHandler @ 00d012a4 */
      (*(code *)PTR_PushSubtitleAudioLanguagetoVector_010ca904)(auStack_1a4,this);
                    /* try { // try from 00d00f68 to 00d00f6f has its CatchHandler @ 00d00fec */
      (*(code *)PTR_operator__010c5494)(auStack_d8,auStack_1a4);
                    /* try { // try from 00d00f80 to 00d00fdf has its CatchHandler @ 00d012a4 */
      (*(code *)PTR__vector_010c4e7c)(auStack_1a4);
      (*(code *)PTR_begin_010cbe64)(&uStack_1ac,this + 0x288);
      (*(code *)PTR_end_010c4d70)(&uStack_1b0,this + 0x288);
      uStack_1b4 = (*(code *)PTR_GetPrimarySubtitleLanguage_010cc198)();
      (*(code *)
        PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
      )(auStack_1a8,uStack_1ac,uStack_1b0,&uStack_1b4);
      (*(code *)PTR_begin_010cbe64)(auStack_1b8,this + 0x288);
      uVar4 = (*(code *)PTR_operator__010cbc64)(auStack_1a8,auStack_1b8);
      (*(code *)PTR_begin_010cbe64)(&uStack_1c0,this + 0x288);
      (*(code *)PTR_end_010c4d70)(&uStack_1c4,this + 0x288);
                    /* try { // try from 00d010e8 to 00d01277 has its CatchHandler @ 00d012a4 */
      uStack_1c8 = (*(code *)PTR_GetSecondarySubtitleLanguage_010c72dc)();
      (*(code *)
        PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
      )(auStack_1bc,uStack_1c0,uStack_1c4,&uStack_1c8);
      (*(code *)PTR_begin_010cbe64)(auStack_1cc,this + 0x288);
      uVar5 = (*(code *)PTR_operator__010cbc64)(auStack_1bc,auStack_1cc);
      uStack_60 = (*(code *)PTR_RcGetString_010cb7dc)(0xec1);
      uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_d8,uVar4);
      uStack_64 = (*(code *)PTR_c_str_010c56fc)(uVar4);
      uStack_68 = (*(code *)PTR_RcGetString_010cb7dc)(0xf20);
      uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_d8,uVar5);
      uVar4 = (*(code *)PTR_c_str_010c56fc)(uVar4);
      (*(code *)PTR_sprintf_010c97b4)
                (auStack_cc,PTR_DAT_010c43ec + -0x1ad4,uStack_60,uStack_64,uStack_68,uVar4);
      (*(code *)PTR_operator__010c90f4)(PTR_gridSelectData_010c5e04 + 0xc,auStack_cc);
      uVar4 = (*(code *)PTR_GetInstance_010ca4d0)();
      (*(code *)PTR_RefreshGridInfo_010c5b08)(uVar4);
      uStack_28 = 1;
      (*(code *)PTR__vector_010c4e7c)(auStack_d8);
      return uStack_28;
    }
    if ((void *)0xf043 < param_2) {
      if (param_2 == (void *)0xf062) {
        if (*(int *)(this + 0x294) == 0) {
          uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_openMenu_010c57e4)(uVar4,0,0,0);
          return 1;
        }
        (*(code *)PTR_ClosePopUp_010c7270)();
        *(undefined4 *)(this + 0x294) = 0;
        return 1;
      }
      if (param_2 != (void *)0xf075) {
        return 0;
      }
      if (*(int *)(this + 0x294) == 0) {
        if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
          uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_openMenu_010c57e4)(uVar4,1,0,0);
        }
        else {
          uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          iVar1 = (*(code *)PTR_getBackgroundMode_010c8738)(uVar4);
          if (iVar1 == 2) {
            iVar1 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x194),2);
            if (iVar1 == 0) {
              iVar1 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x198),2);
              if (iVar1 == 0) {
                iVar1 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x19c),2);
                if (iVar1 == 0) {
                  iVar1 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x1a0),2);
                  if (iVar1 == 0) {
                    (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,3,*(undefined4 *)(this + 0x1a8))
                    ;
                  }
                  else {
                    (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,3,*(undefined4 *)(this + 0x1b8))
                    ;
                  }
                }
                else {
                  (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,3,*(undefined4 *)(this + 0x1b4));
                }
              }
              else {
                (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,3,*(undefined4 *)(this + 0x1b0));
              }
            }
            else {
              (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,3,*(undefined4 *)(this + 0x1ac));
            }
            uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_hideBarSubmenuTitle_010c5b9c)(uVar4);
          }
          else {
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x18c),2,1);
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 400),2,0);
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x194),2,0);
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x198),2,0);
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x19c),2,0);
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a0),2,0);
            (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
            uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_focusToBar_010c7724)(uVar4,1);
            (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x18c));
            (*(code *)PTR_PostEvent_010cabec)(this,this,0xc0000020,0,0);
            uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_hideBarSubmenuTitle_010c5b9c)(uVar4);
          }
        }
      }
      else {
        (*(code *)PTR_ClosePopUp_010c7270)();
        *(undefined4 *)(this + 0x294) = 0;
      }
      return 1;
    }
    if (param_2 == (void *)0xf012) {
      if (*(int *)PTR_popupType_010c6df0 == 0) {
        return 0;
      }
      return 1;
    }
    if (param_2 != (void *)0xf042) {
      return 0;
    }
    if (*(int *)(this + 0x294) == 1) {
      puVar6 = (undefined4 *)(*(code *)PTR_at_010c9a98)(this + 0x288,param_3);
      (*(code *)PTR_SetPrimaryAudioLanguage_010ccc14)(*puVar6);
      (*(code *)PTR_vector_010c64c0)(auStack_fc);
                    /* try { // try from 00d002f4 to 00d002fb has its CatchHandler @ 00d00650 */
      (*(code *)PTR_PushSubtitleAudioLanguagetoVector_010ca904)(auStack_108,this);
                    /* try { // try from 00d00314 to 00d0031b has its CatchHandler @ 00d00398 */
      (*(code *)PTR_operator__010c5494)(auStack_fc,auStack_108);
                    /* try { // try from 00d0032c to 00d0038b has its CatchHandler @ 00d00650 */
      (*(code *)PTR__vector_010c4e7c)(auStack_108);
      (*(code *)PTR_begin_010cbe64)(&uStack_110,this + 0x288);
      (*(code *)PTR_end_010c4d70)(&uStack_114,this + 0x288);
      uStack_118 = (*(code *)PTR_GetPrimaryAudioLanguage_010c8494)();
      (*(code *)
        PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
      )(auStack_10c,uStack_110,uStack_114,&uStack_118);
      (*(code *)PTR_begin_010cbe64)(auStack_11c,this + 0x288);
      uVar4 = (*(code *)PTR_operator__010cbc64)(auStack_10c,auStack_11c);
      (*(code *)PTR_begin_010cbe64)(&uStack_124,this + 0x288);
      (*(code *)PTR_end_010c4d70)(&uStack_128,this + 0x288);
                    /* try { // try from 00d00494 to 00d00623 has its CatchHandler @ 00d00650 */
      uStack_12c = (*(code *)PTR_GetSecondaryAudioLanguage_010c4d48)();
      (*(code *)
        PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
      )(auStack_120,uStack_124,uStack_128,&uStack_12c);
      (*(code *)PTR_begin_010cbe64)(auStack_130,this + 0x288);
      uVar5 = (*(code *)PTR_operator__010cbc64)(auStack_120,auStack_130);
      uStack_3c = (*(code *)PTR_RcGetString_010cb7dc)(0xec1);
      uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_fc,uVar4);
      uStack_40 = (*(code *)PTR_c_str_010c56fc)(uVar4);
      uStack_44 = (*(code *)PTR_RcGetString_010cb7dc)(0xf20);
      uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_fc,uVar5);
      uVar4 = (*(code *)PTR_c_str_010c56fc)(uVar4);
      (*(code *)PTR_sprintf_010c97b4)
                (auStack_cc,PTR_DAT_010c43ec + -0x1ad4,uStack_3c,uStack_40,uStack_44,uVar4);
      (*(code *)PTR_operator__010c90f4)(PTR_gridSelectData_010c5e04 + 0xc,auStack_cc);
      uVar4 = (*(code *)PTR_GetInstance_010ca4d0)();
      (*(code *)PTR_RefreshGridInfo_010c5b08)(uVar4);
      uStack_28 = 1;
      (*(code *)PTR__vector_010c4e7c)(auStack_fc);
      return uStack_28;
    }
    if (*(int *)(this + 0x294) != 2) {
      return 0;
    }
    puVar6 = (undefined4 *)(*(code *)PTR_at_010c9a98)(this + 0x288,param_3);
    (*(code *)PTR_SetPrimarySubtitleLanguage_010cb874)(*puVar6);
    (*(code *)PTR_vector_010c64c0)(auStack_f0);
                    /* try { // try from 00d00710 to 00d00717 has its CatchHandler @ 00d00a6c */
    (*(code *)PTR_PushSubtitleAudioLanguagetoVector_010ca904)(auStack_13c,this);
                    /* try { // try from 00d00730 to 00d00737 has its CatchHandler @ 00d007b4 */
    (*(code *)PTR_operator__010c5494)(auStack_f0,auStack_13c);
                    /* try { // try from 00d00748 to 00d007a7 has its CatchHandler @ 00d00a6c */
    (*(code *)PTR__vector_010c4e7c)(auStack_13c);
    (*(code *)PTR_begin_010cbe64)(&uStack_144,this + 0x288);
    (*(code *)PTR_end_010c4d70)(&uStack_148,this + 0x288);
    uStack_14c = (*(code *)PTR_GetPrimarySubtitleLanguage_010cc198)();
    (*(code *)
      PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
    )(auStack_140,uStack_144,uStack_148,&uStack_14c);
    (*(code *)PTR_begin_010cbe64)(auStack_150,this + 0x288);
    uVar4 = (*(code *)PTR_operator__010cbc64)(auStack_140,auStack_150);
    (*(code *)PTR_begin_010cbe64)(&uStack_158,this + 0x288);
    (*(code *)PTR_end_010c4d70)(&uStack_15c,this + 0x288);
                    /* try { // try from 00d008b0 to 00d00a3f has its CatchHandler @ 00d00a6c */
    uStack_160 = (*(code *)PTR_GetSecondarySubtitleLanguage_010c72dc)();
    (*(code *)
      PTR_find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>_010c935c
    )(auStack_154,uStack_158,uStack_15c,&uStack_160);
    (*(code *)PTR_begin_010cbe64)(auStack_164,this + 0x288);
    uVar5 = (*(code *)PTR_operator__010cbc64)(auStack_154,auStack_164);
    uStack_48 = (*(code *)PTR_RcGetString_010cb7dc)(0xec1);
    uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_f0,uVar4);
    uStack_4c = (*(code *)PTR_c_str_010c56fc)(uVar4);
    uStack_50 = (*(code *)PTR_RcGetString_010cb7dc)(0xf20);
    uVar4 = (*(code *)PTR_operator___010cb2dc)(auStack_f0,uVar5);
    uVar4 = (*(code *)PTR_c_str_010c56fc)(uVar4);
    (*(code *)PTR_sprintf_010c97b4)
              (auStack_cc,PTR_DAT_010c43ec + -0x1ad4,uStack_48,uStack_4c,uStack_50,uVar4);
    (*(code *)PTR_operator__010c90f4)(PTR_gridSelectData_010c5e04 + 0xc,auStack_cc);
    uVar4 = (*(code *)PTR_GetInstance_010ca4d0)();
    (*(code *)PTR_RefreshGridInfo_010c5b08)(uVar4);
    uStack_28 = 1;
    (*(code *)PTR__vector_010c4e7c)(auStack_f0);
    return uStack_28;
  }
  if (param_2 < (void *)0xf002) {
    if ((void *)0xefff < param_2) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        uVar4 = (*(code *)PTR_OnKey_010c7538)(uVar4,param_1,param_2,param_3);
        return uVar4;
      }
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x1fc)) {
        return 0;
      }
      return 1;
    }
    if (param_2 != (void *)0xd) {
      return 0;
    }
    iVar1 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x18c));
    iVar3 = (*(code *)PTR_GetChildIdx_010caea4)
                      (*(undefined4 *)(this + 0x18c),*(undefined4 *)(this + 0x1a8));
    if (iVar1 == iVar3) {
      (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,4,*(undefined4 *)(this + 0x1d0));
      uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0x1147);
      (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar4,uVar5);
      return 1;
    }
    iVar1 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x18c));
    iVar3 = (*(code *)PTR_GetChildIdx_010caea4)
                      (*(undefined4 *)(this + 0x18c),*(undefined4 *)(this + 0x1ac));
    if (iVar1 == iVar3) {
      (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,5,*(undefined4 *)(this + 0x1e4));
      uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0xbf2);
      (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar4,uVar5);
      return 1;
    }
    iVar1 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x18c));
    iVar3 = (*(code *)PTR_GetChildIdx_010caea4)
                      (*(undefined4 *)(this + 0x18c),*(undefined4 *)(this + 0x1b0));
    if (iVar1 != iVar3) {
      iVar1 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x18c));
      iVar3 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(this + 0x18c),*(undefined4 *)(this + 0x1b4));
      if (iVar1 == iVar3) {
        (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,7,*(undefined4 *)(this + 0x240));
        uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0x80);
        (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar4,uVar5);
        return 1;
      }
      iVar1 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x18c));
      iVar3 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(this + 0x18c),*(undefined4 *)(this + 0x1b8));
      if (iVar1 != iVar3) {
        return 0;
      }
      (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,8,*(undefined4 *)(this + 0x264));
      uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0x106e);
      (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar4,uVar5);
      return 1;
    }
    for (uStack_1e0 = 0;
        uVar2 = (**(code **)(**(int **)(this + 0x198) + 0x44))(*(undefined4 *)(this + 0x198)),
        uStack_1e0 < uVar2; uStack_1e0 = uStack_1e0 + 1) {
      iStack_1dc = (**(code **)(**(int **)(this + 0x198) + 0x40))
                             (*(undefined4 *)(this + 0x198),uStack_1e0);
      iVar1 = (*(code *)PTR_QueryFlag_010ca574)(iStack_1dc,2);
      if ((iVar1 == 0) || (*(char *)(iStack_1dc + 0x38) != '\x01')) {
        iStack_38 = 0;
      }
      else {
        iStack_38 = 1;
      }
      if (iStack_38 != 0) break;
    }
    (*(code *)PTR_HideAllShowSubmenu_010c4c84)(this,6,iStack_1dc);
    uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0x1071);
    (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar4,uVar5);
    return 1;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
    return 1;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x1a8)) {
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
    uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_focusToBar_010c7724)(uVar4,1);
    return 1;
  }
  uVar4 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar1 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar4);
  if (iVar1 == 1) {
    uVar4 = (*(code *)PTR_getInstance_010cd270)();
    iVar1 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar4);
    if ((iVar1 == 1) && (*(int *)(this + 0x3c) == *(int *)(this + 0x1ac))) {
      iStack_30 = 1;
      goto LAB_00cffbfc;
    }
  }
  iStack_30 = 0;
LAB_00cffbfc:
  if (iStack_30 == 0) {
    return 0;
  }
  (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
  uVar4 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
  (*(code *)PTR_focusToBar_010c7724)(uVar4,1);
  return 1;
}

