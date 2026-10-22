
/* SoundSettingsFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
SoundSettingsFrame::OnKey(SoundSettingsFrame *this,void *param_1,void *param_2,void *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_2 == (void *)0xf014) {
    (*(code *)PTR_EnableBubbleHelp_010cabe8)(this);
    return 1;
  }
  if (param_2 != (void *)0xf002) {
    if (param_2 < (void *)0xf003) {
      if (param_2 == (void *)0xd) {
        iVar2 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x1a4));
        if (iVar2 != iVar4) {
          return 0;
        }
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a8),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ac),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b0),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c0),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d0),2,1);
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar2 = (*(code *)PTR_ArTvConf_GetOpticOut_010cb67c)(uVar3);
        if (iVar2 != 0) {
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1dc),2,1);
        }
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e0),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e8),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1bc),2,1);
        iVar2 = (*(code *)PTR_IsTvInFirstTime_010c83c8)();
        if (iVar2 != 0) {
          (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x18c));
          (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x188));
        }
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1ac));
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xf,0xd41);
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xe,0xc81);
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),6,0x10c6);
        return 1;
      }
      if (param_2 < (void *)0xd) {
        return 0;
      }
      if (param_2 < (void *)0xf000) {
        return 0;
      }
      if ((*(int *)(this + 0x3c) == *(int *)(this + 0x1b0)) && (param_2 == (void *)0xf000)) {
        (*(code *)PTR_OnNtyKey_ComboButton_Sound_Type_010c899c)(this,0);
        return 1;
      }
      if ((*(int *)(this + 0x3c) == *(int *)(this + 0x1b0)) && (param_2 == (void *)0xf001)) {
        (*(code *)PTR_OnNtyKey_ComboButton_Sound_Type_010c899c)(this,1);
        return 1;
      }
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x1bc)) {
        iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x3c),1);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00ee8dac to 00ee8db3 has its CatchHandler @ 00ee8dd4 */
          (*(code *)PTR_PictureAdjustApp_010c9f08)(iVar2);
          if (iVar2 == 0) {
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c4460 + -0x5cd8,PTR_DAT_010c4460 + -0x5d14,
                       PTR_DAT_010c4460 + -0x5bec,0x9cf);
            (*(code *)PTR_abort_010cc6c0)();
          }
          (*(code *)PTR_Run_010c7470)(iVar2,0,0x2d);
          uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_hideMenu_010c6a38)(uVar3);
        }
        return 1;
      }
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
        if (*(int *)(this + 0x3c) != *(int *)(this + 0x1a0)) {
          return 0;
        }
        return 1;
      }
      uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      uVar3 = (*(code *)PTR_OnKey_010c7538)(uVar3,param_1,param_2,param_3);
      return uVar3;
    }
    if (param_2 == (void *)0xf012) {
      uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_openMenu_010c57e4)(uVar3,0,0,0);
      return 1;
    }
    if ((void *)0xf012 < param_2) {
      if (param_2 == (void *)0xf062) {
        iVar2 = (*(code *)PTR_IsTvInFirstTime_010c83c8)();
        if (iVar2 == 0) {
          uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_openMenu_010c57e4)(uVar3,0,0,0);
        }
        else {
          uVar3 = (*(code *)PTR_getFrame_010c8a9c)();
          (*(code *)PTR_openMenu_010c8a58)(uVar3,0,0);
        }
        return 1;
      }
      if (param_2 != (void *)0xf075) {
        return 0;
      }
      iVar2 = (*(code *)PTR_IsTvInFirstTime_010c83c8)();
      if (iVar2 != 0) {
        uVar3 = (*(code *)PTR_getFrame_010c8a9c)();
        (*(code *)PTR_openMenu_010c8a58)(uVar3,2,0);
        iVar2 = (*(code *)PTR_getFrame_010c8a9c)();
        uVar5 = *(undefined4 *)(iVar2 + 0x1b8);
        uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x1071);
        (*(code *)PTR_setMenuTitle_010c7c80)(uVar5,uVar3);
        iVar2 = (*(code *)PTR_getFrame_010c8a9c)();
        (*(code *)PTR_Refresh_010c89d8)(*(undefined4 *)(iVar2 + 0x1b8));
        return 1;
      }
      iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 400),2);
      if (iVar2 != 0) {
        *(undefined1 *)(*(int *)(this + 0x180) + 0x38) = 1;
        *(undefined1 *)(*(int *)(this + 0x184) + 0x38) = 1;
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 400));
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xf,0xd41);
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xe,0xc81);
        iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),6,0x10c6);
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1b4));
        uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_hidePopupBC_010c98ac)(uVar3,2);
        (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x184));
        return 1;
      }
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar3,1,0,0);
        return 1;
      }
      iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x1a4),2);
      if (iVar2 != 0) {
        uVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar3,5,0,0);
        return 1;
      }
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar2 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar3);
      if (iVar2 == 1) {
        uVar3 = (*(code *)PTR_getInstance_010cd270)();
        iVar2 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar3);
        if (iVar2 == 1) {
          bVar1 = true;
          goto LAB_00ee889c;
        }
      }
      bVar1 = false;
LAB_00ee889c:
      if (bVar1) {
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
      }
      else {
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a4),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1a8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ac),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1dc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1bc),2,0);
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x18c));
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x188));
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1a4));
      }
      (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x184));
      iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xf,0xd41);
      iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),0xe,0xc81);
      iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar2 + 0x1cc),6,0x10c6);
      return 1;
    }
    if (param_2 != (void *)0xf003) {
      return 0;
    }
    goto LAB_00ee9060;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
    return 1;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x194)) {
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
    return 1;
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar2 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar3);
  if (iVar2 == 1) {
    uVar3 = (*(code *)PTR_getInstance_010cd270)();
    iVar2 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar3);
    if ((iVar2 != 1) || (*(int *)(this + 0x3c) != *(int *)(this + 0x19c))) goto LAB_00ee901c;
    bVar1 = true;
  }
  else {
LAB_00ee901c:
    bVar1 = false;
  }
  if (bVar1) {
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
    return 1;
  }
LAB_00ee9060:
  if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
    return 0;
  }
  (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x184));
  return 1;
}

