
undefined4 FUN_00f86234(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x180),2);
  if (iVar2 == 0) {
    (*(code *)PTR_SetPanStates_010cbf24)(param_1,param_3);
    return 1;
  }
  if (param_3 != 0xf003) {
    if (param_3 < 0xf004) {
      if (param_3 < 0xf002) {
        if ((0xefff < param_3) || (param_3 == 0xd)) {
          return 0;
        }
      }
      else {
        iVar2 = (*(code *)PTR_GetParent_010cac70)(*(undefined4 *)(param_1 + 0x3c));
        if ((iVar2 == *(int *)(param_1 + 0x198)) ||
           (iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1b8),2),
           iVar2 != 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 1;
        }
        (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)(param_1 + 0x2d4));
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1ec),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1f0),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 500),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1f8),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1fc),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x200),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x204),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x208),1,0);
        (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x20c),1,0);
      }
    }
    else if (param_3 == 0xf045) {
      if (*(int *)(param_1 + 0x2e4) == 2) {
        (*(code *)PTR_CancelDeviceSearch_010c6420)();
        *(undefined4 *)(param_1 + 0x2e4) = 0;
        (*(code *)PTR_OnNtyClicked_Digilink_010c54d8)(param_1,0,0,0);
        return 1;
      }
    }
    else {
      if (param_3 < 0xf046) {
        if (param_3 != 0xf011) {
          if (param_3 != 0xf042) {
            return 0;
          }
          iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x194),2);
          if (iVar2 != 0) {
            (*(code *)PTR_HideAllButtons_010ca694)(*(undefined4 *)(param_1 + 0x2d0));
            (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x2d0),0xe,0xc42);
            (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x2d0),6,0x10c6);
            (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(param_1 + 0x2d0));
            (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x180));
          }
          return 1;
        }
      }
      else if ((param_3 != 0xf062) && (param_3 != 0xf075)) {
        return 0;
      }
      iVar2 = *(int *)(param_1 + 0x2e4);
      if (iVar2 == 1) {
        (*(code *)PTR_ClosePopUp_010c7270)();
        (*(code *)PTR_CancelDeviceSearch_010c6420)();
        *(undefined4 *)(param_1 + 0x2e4) = 0;
      }
      else if (iVar2 == 0) {
        if (*(int *)(param_1 + 0x2e8) != 1) {
          iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1b4),2);
          if (iVar2 == 0) {
            iVar2 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
            if (iVar2 == 0) {
              (*(code *)PTR_printf_010c9f10)
                        (PTR_DAT_010c4460 + -0x47f8,PTR_DAT_010c4460 + -0x47e0,
                         PTR_DAT_010c4460 + -0x440c,0xdf);
              (*(code *)PTR_abort_010cc6c0)();
            }
            (*(code *)PTR_Kill_010c4dec)(iVar2);
            return 1;
          }
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x1b4));
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x1b8));
          (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)(param_1 + 0x2a0));
          return 1;
        }
        (*(code *)PTR_ClosePopUp_010c7270)();
        *(undefined4 *)(param_1 + 0x2e8) = 0;
      }
      else if (iVar2 == 2) {
        (*(code *)PTR_ClosePopUp_010c7270)();
        *(undefined4 *)(param_1 + 0x2e4) = 0;
      }
    }
    return 0;
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar2 = (*(code *)PTR_ArTvConf_GetDualWatch_010ca2e8)(uVar3);
  if (iVar2 == 1) {
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
    iVar2 = (*(code *)PTR_IsDualWatchAllowedOnCurrentSource_010cd28c)(uVar3);
    if (iVar2 == 0) goto LAB_00f8696c;
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar2 = (*(code *)PTR_ArMainScaler_GetPanelParameter_010c9dc0)(uVar3);
    if (iVar2 != 2) goto LAB_00f8696c;
    bVar1 = true;
  }
  else {
LAB_00f8696c:
    bVar1 = false;
  }
  if (!bVar1) {
    uVar3 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
    iVar2 = (*(code *)PTR_GetPrivateData_010ca218)(uVar3);
    if (iVar2 == 1) {
LAB_00f86b80:
      uVar3 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
      iVar2 = (*(code *)PTR_GetPrivateData_010ca218)(uVar3);
      if ((iVar2 == 1) &&
         (iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1b0),2), iVar2 != 0)
         ) goto LAB_00f86be4;
      bVar1 = false;
    }
    else {
      iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1a8),2);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 400),2);
        if (iVar2 != 0) {
          uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar2 = (*(code *)PTR_ArTvConf_GetCec_010cbe9c)(uVar3);
          if (iVar2 == 0) goto LAB_00f86be4;
        }
        goto LAB_00f86b80;
      }
LAB_00f86be4:
      bVar1 = true;
    }
    if (bVar1) {
      return 1;
    }
    goto LAB_00f86c14;
  }
  uVar3 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
  iVar2 = (*(code *)PTR_GetPrivateData_010ca218)(uVar3);
  if (iVar2 == 1) {
LAB_00f86a34:
    uVar3 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
    iVar2 = (*(code *)PTR_GetPrivateData_010ca218)(uVar3);
    if ((iVar2 == 1) &&
       (iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1b0),2), iVar2 != 0))
    goto LAB_00f86a98;
    bVar1 = false;
  }
  else {
    iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1bc),2);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x1bc),2);
      if (iVar2 != 0) {
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar2 = (*(code *)PTR_ArTvConf_GetCec_010cbe9c)(uVar3);
        if (iVar2 == 0) goto LAB_00f86a98;
      }
      goto LAB_00f86a34;
    }
LAB_00f86a98:
    bVar1 = true;
  }
  if (bVar1) {
    return 1;
  }
LAB_00f86c14:
  (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,*(undefined4 *)(param_1 + 0x2d4));
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1ec),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1f0),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 500),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1f8),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1fc),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x200),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x204),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x208),1,0);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x20c),1,0);
  return 0;
}

