
undefined4 FUN_00ea38fc(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uStack_38;
  int iStack_34;
  
  if (param_3 == 0xf014) {
    (*(code *)PTR_EnableBubbleHelp_010cabe8)(param_1);
    return 1;
  }
  if (param_3 == 0xf002) {
    if (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x180)) {
      return 1;
    }
    for (uStack_38 = 0;
        uVar5 = (**(code **)(**(int **)(param_1 + 0x184) + 0x44))(*(undefined4 *)(param_1 + 0x184)),
        uStack_38 < uVar5; uStack_38 = uStack_38 + 1) {
      iStack_34 = (**(code **)(**(int **)(param_1 + 0x184) + 0x40))
                            (*(undefined4 *)(param_1 + 0x184),uStack_38);
      iVar3 = (*(code *)PTR_QueryFlag_010ca574)(iStack_34,2);
      if ((iVar3 == 0) || (*(char *)(iStack_34 + 0x38) != '\x01')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) break;
    }
    iVar3 = (*(code *)PTR_QueryFlag_010ca574)(iStack_34,4);
    if (iVar3 != 0) {
      (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)(param_1 + 0x180));
      uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
      (*(code *)PTR_focusToBar_010c7724)(uVar2,1);
      return 1;
    }
  }
  else if (param_3 < 0xf003) {
    if (param_3 == 0xd) {
      return 0;
    }
    if ((0xc < param_3) && (0xefff < param_3)) {
      if (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x180)) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        uVar2 = (*(code *)PTR_OnKey_010c7538)(uVar2,param_2,param_3,param_4);
        return uVar2;
      }
      iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(param_1 + 0x184));
      iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x188));
      if (iVar3 == iVar4) {
        return 1;
      }
      iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(param_1 + 0x184));
      iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x18c));
      if (iVar3 == iVar4) {
        return 1;
      }
      iVar3 = (*(code *)PTR_GetFocusedWdgIdx_010c71f0)(*(undefined4 *)(param_1 + 0x184));
      iVar4 = (*(code *)PTR_GetChildIdx_010caea4)
                        (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 400));
      if (iVar3 == iVar4) {
        return 1;
      }
    }
  }
  else {
    if (param_3 == 0xf045) {
      if (*(int *)(param_1 + 0x1a8) == 2) {
        (*(code *)PTR_CancelDeviceSearch_010c6420)();
        *(undefined4 *)(param_1 + 0x1a8) = 0;
        (*(code *)PTR_OnNtyClick_Digilink_010c623c)(param_1,0,0,0);
      }
      return 1;
    }
    if (param_3 < 0xf046) {
      if ((param_3 == 0xf003) && (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x180))) {
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_focusToBar_010c7724)(uVar2,0);
        (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)(param_1 + 0x184));
        return 1;
      }
    }
    else {
      if (param_3 == 0xf062) {
        iVar3 = *(int *)(param_1 + 0x1a8);
        if (iVar3 == 1) {
          (*(code *)PTR_ClosePopUp_010c7270)();
          (*(code *)PTR_CancelDeviceSearch_010c6420)();
          *(undefined4 *)(param_1 + 0x1a8) = 0;
        }
        else if (iVar3 == 0) {
          if (*(int *)(param_1 + 0x1ac) != 1) {
            uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
            (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
            return 1;
          }
          (*(code *)PTR_ClosePopUp_010c7270)();
          *(undefined4 *)(param_1 + 0x1ac) = 0;
        }
        else if (iVar3 == 2) {
          (*(code *)PTR_ClosePopUp_010c7270)();
          *(undefined4 *)(param_1 + 0x1a8) = 0;
        }
        uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
        (*(code *)PTR_openMenu_010c57e4)(uVar2,0,0,0);
        return 1;
      }
      if (param_3 == 0xf075) {
        iVar3 = *(int *)(param_1 + 0x1a8);
        if (iVar3 == 1) {
          (*(code *)PTR_ClosePopUp_010c7270)();
          (*(code *)PTR_CancelDeviceSearch_010c6420)();
          *(undefined4 *)(param_1 + 0x1a8) = 0;
        }
        else if (iVar3 == 0) {
          if (*(int *)(param_1 + 0x1ac) != 1) {
            if (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x180)) {
              uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
              (*(code *)PTR_openMenu_010c57e4)(uVar2,1,0,0);
            }
            else {
              uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
              (*(code *)PTR_hideBarSubmenuTitle_010c5b9c)(uVar2);
              uVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
              (*(code *)PTR_openMenu_010c57e4)(uVar2,0xf,0,0);
            }
            return 1;
          }
          (*(code *)PTR_ClosePopUp_010c7270)();
          *(undefined4 *)(param_1 + 0x1ac) = 0;
        }
        else if (iVar3 == 2) {
          (*(code *)PTR_ClosePopUp_010c7270)();
          *(undefined4 *)(param_1 + 0x1a8) = 0;
        }
      }
    }
  }
  return 0;
}

