
/* PictureSettingsFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
PictureSettingsFrame::OnKey(PictureSettingsFrame *this,void *param_1,void *param_2,void *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_2 == (void *)0xf014) {
    (*(code *)PTR_EnableBubbleHelp_010cabe8)(this);
    return 1;
  }
  if (param_2 == (void *)0xf002) {
    if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
      return 1;
    }
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar3 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
    if (iVar3 == 1) {
      uVar2 = (*(code *)PTR_getInstance_010cd270)();
      iVar3 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar2);
      if ((iVar3 != 1) || (*(int *)(this + 0x3c) != *(int *)(this + 0x1b0))) goto LAB_00e2796c;
      bVar1 = true;
    }
    else {
LAB_00e2796c:
      bVar1 = false;
    }
    if (bVar1) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
      return 1;
    }
    if (*(int *)(this + 0x3c) == *(int *)(this + 0x194)) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
      return 1;
    }
    iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x194),2);
    if ((iVar3 == 0) && (*(int *)(this + 0x3c) == *(int *)(this + 0x198))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
      return 1;
    }
  }
  else {
    if (param_2 < (void *)0xf003) {
      if (param_2 == (void *)0xd) {
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x1ac));
        if (iVar3 == iVar4) {
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ac),2,0);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1bc),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c0),2,1);
          uVar2 = (*(code *)PTR_getInstance_010c67ec)();
          iVar3 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
          if (iVar3 == 2) {
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),2,1);
          }
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d0),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d4),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1dc),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e0),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d8),2,0);
          uVar2 = (*(code *)PTR_getInstance_010cab20)();
          iVar3 = (*(code *)PTR_GetFPGAExistence_010c4d54)(uVar2);
          if (iVar3 == 0) {
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,0);
          }
          else {
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,1);
          }
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e8),2,1);
          uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar3 = (*(code *)PTR_ArPanelConf_GetUrsaSelection_010c8e4c)(uVar2);
          if (iVar3 != 0) {
            (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ec),2,1);
          }
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1f0),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 500),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1f8),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1fc),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x200),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x204),2,1);
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x208),2,1);
          (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1b8));
          iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),0xf,0xd41);
          iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),0xe,0xc81);
          iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),6,0x10c6);
          iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(iVar3 + 0x1cc));
          return 1;
        }
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x198));
        if ((iVar3 == iVar4) &&
           (iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x198),1), iVar3 != 0))
        {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          iVar3 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00e283d8 to 00e283df has its CatchHandler @ 00e28400 */
          (*(code *)PTR_PictureFormatApp_010c80e0)(iVar3);
          if (iVar3 == 0) {
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + 0x64a4,PTR_DAT_010c43ec + 0x6484,PTR_DAT_010c43ec + 0x65f0
                       ,0x9de);
            (*(code *)PTR_abort_010cc6c0)();
          }
          (*(code *)PTR_Run_010c7470)(iVar3,0,0);
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_hideMenu_010c6a38)(uVar2);
          return 0;
        }
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x194));
        if ((iVar3 == iVar4) &&
           (iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x194),1), iVar3 != 0))
        {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          (*(code *)PTR_HideAllShowSubmenu_010cc9f0)(this,4,*(undefined4 *)(this + 0x20c));
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0xbd9);
          (*(code *)PTR_showBarSubmenuTitle_010c5c30)(uVar2,uVar5);
          return 0;
        }
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 400));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 400),*(undefined4 *)(this + 0x20c));
        if ((iVar3 == iVar4) &&
           (iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x20c),1), iVar3 != 0))
        {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          iVar3 = (*(code *)PTR_RunPictureAdjustFrame_010c95dc)(this);
          if (iVar3 == 0) {
            return 0;
          }
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_hideMenu_010c6a38)(uVar2);
          return 1;
        }
        iVar3 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
        if (iVar3 == 0) {
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + 0x64a4,PTR_DAT_010c43ec + 0x6484,PTR_DAT_010c43ec + 0x65f0,
                     0x9ed);
          (*(code *)PTR_abort_010cc6c0)();
        }
        else {
                    /* try { // try from 00e2868c to 00e28693 has its CatchHandler @ 00e286a8 */
          (*(code *)PTR_ThreeDSelectMenuApp_010c81a0)(iVar3);
        }
        (*(code *)PTR_Run_010c7470)(iVar3,0,0);
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_hideMenu_010c6a38)(uVar2);
        return 1;
      }
      if (param_2 < (void *)0xd) {
        return 0;
      }
      if (param_2 < (void *)0xf000) {
        return 0;
      }
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        uVar2 = (*(code *)PTR_OnKey_010c7538)(uVar2,param_1,param_2,param_3);
        return uVar2;
      }
      iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
      iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x198));
      if (iVar3 != iVar4) {
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x194));
        if (iVar3 == iVar4) {
          return 1;
        }
        iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 400));
        iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                          (*(undefined4 *)(this + 400),*(undefined4 *)(this + 0x20c));
        if ((iVar3 == iVar4) &&
           (iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x20c),1), iVar3 != 0))
        {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          iVar3 = (*(code *)PTR_RunPictureAdjustFrame_010c95dc)(this);
          if (iVar3 == 0) {
            return 0;
          }
          uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
          (*(code *)PTR_hideMenu_010c6a38)(uVar2);
          return 1;
        }
        iVar3 = (*(code *)PTR_operator_new_010c6e6c)(0x3c,PTR_DAT_010cc2b0);
        if (iVar3 == 0) {
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + 0x64a4,PTR_DAT_010c43ec + 0x6484,PTR_DAT_010c43ec + 0x65f0,
                     0x94c);
          (*(code *)PTR_abort_010cc6c0)();
        }
        else {
                    /* try { // try from 00e27758 to 00e2775f has its CatchHandler @ 00e27774 */
          (*(code *)PTR_ThreeDSelectMenuApp_010c81a0)(iVar3);
        }
        (*(code *)PTR_Run_010c7470)(iVar3,0,0);
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_hideMenu_010c6a38)(uVar2);
        return 1;
      }
      return 1;
    }
    if (param_2 == (void *)0xf042) {
      iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(this + 0x184));
      iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(this + 0x184),*(undefined4 *)(this + 0x198));
      if (iVar3 != iVar4) {
        return 0;
      }
      uVar2 = (*(code *)PTR_getInstance_010cab20)();
      iVar3 = (*(code *)PTR_IsTvIn4kMode_010c5aa4)(uVar2);
      if (iVar3 == 0) {
        uVar2 = (*(code *)PTR_getInstance_010cab20)();
        iVar3 = (*(code *)PTR_Get3DDisplayMode_010cc868)(uVar2);
        if (iVar3 == 0) {
          bVar1 = false;
          goto LAB_00e27cb4;
        }
      }
      bVar1 = true;
LAB_00e27cb4:
      if (bVar1) {
        iVar3 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00e27ce0 to 00e27ce7 has its CatchHandler @ 00e27d08 */
        (*(code *)PTR_ZoomPanMenuApp_010c4b1c)(iVar3);
        if (iVar3 == 0) {
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + 0x64a4,PTR_DAT_010c43ec + 0x6484,PTR_DAT_010c43ec + 0x65f0,
                     0x98e);
          (*(code *)PTR_abort_010cc6c0)();
        }
        (*(code *)PTR_Run_010c7470)(iVar3,0,0);
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_hideMenu_010c6a38)(uVar2);
      }
      return 1;
    }
    if ((void *)0xf042 < param_2) {
      if (param_2 == (void *)0xf062) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
        return 1;
      }
      if (param_2 != (void *)0xf075) {
        return 0;
      }
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,1,0,0);
        return 1;
      }
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      iVar3 = (*(code *)PTR_getBackgroundMode_010c8738)(uVar2);
      if (iVar3 == 2) {
        (*(code *)PTR_HideAllShowSubmenu_010cc9f0)(this,1,*(undefined4 *)(this + 0x194));
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_hideBarSubmenuTitle_010c5b9c)(uVar2);
        return 1;
      }
      iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x1ac),2);
      if (iVar3 != 0) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,4,0,0);
        return 1;
      }
      uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar3 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
      if (iVar3 == 1) {
        uVar2 = (*(code *)PTR_getInstance_010cd270)();
        iVar3 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar2);
        if (iVar3 == 1) {
          bVar1 = true;
          goto LAB_00e26fc8;
        }
      }
      bVar1 = false;
LAB_00e26fc8:
      if (bVar1) {
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x198));
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x19c));
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1a0));
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x1ac));
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x180));
      }
      else {
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ac),2,1);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1b8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1bc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c0),2,0);
        uVar2 = (*(code *)PTR_getInstance_010c67ec)();
        iVar3 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar2);
        if (iVar3 == 2) {
          (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c4),2,0);
        }
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1c8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1cc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1d8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1dc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e4),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1e8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1ec),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1f0),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 500),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1f8),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x1fc),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x200),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x204),2,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(this + 0x208),2,0);
        (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1ac));
      }
      (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x184));
      iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),0xf,0xd41);
      iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),0xe,0xc42);
      iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(iVar3 + 0x1cc),6,0x10c6);
      iVar3 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(iVar3 + 0x1cc));
      return 1;
    }
    if (param_2 != (void *)0xf003) {
      return 0;
    }
  }
  if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
    return 0;
  }
  uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar3 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
  if (iVar3 == 1) {
    uVar2 = (*(code *)PTR_getInstance_010cd270)();
    iVar3 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar2);
    if (iVar3 == 1) {
      bVar1 = true;
      goto LAB_00e27b24;
    }
  }
  bVar1 = false;
LAB_00e27b24:
  if (bVar1) {
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x1b0));
  }
  else {
    iVar3 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(this + 0x194),2);
    if (iVar3 == 0) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x198));
    }
    else {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,*(undefined4 *)(this + 0x194));
    }
  }
  return 1;
}

