
undefined4 FUN_00d9da68(int param_1,undefined4 param_2,uint param_3)

{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uStack_34;
  uint uStack_30;
  undefined1 auStack_28 [8];
  int iStack_20;
  uint uStack_18;
  
  iVar4 = (*(code *)PTR_QueryFlag_010ca574)(*(undefined4 *)(param_1 + 0x180),2);
  if (iVar4 != 0) {
    uVar5 = (*(code *)PTR_RenameHandler_010c7694)(param_1,*(undefined4 *)(param_1 + 0x1d0),param_3);
    return uVar5;
  }
  if (param_3 == 0xf045) {
    uStack_18 = 0xf045;
    for (uStack_30 = 0x15; (int)uStack_30 < 0x1a; uStack_30 = uStack_30 + 1) {
      iVar4 = (*(code *)PTR_GetChildIdx_010cada8)
                        (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x3c));
      iVar6 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,uStack_30 & 0xffff);
      if (iVar4 == iVar6) {
        *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(param_1 + 0x3c);
        (*(code *)PTR_RenameHandler_010c7694)(param_1,*(undefined4 *)(param_1 + 0x1d0),0xf045);
        return 1;
      }
    }
    uStack_34 = 0;
    while( true ) {
      if (4 < (int)uStack_34) {
        return 0;
      }
      iVar4 = (*(code *)PTR_GetChildIdx_010cada8)
                        (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x3c));
      iVar6 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)
                        (param_1,(uStack_34 & 0xffff) + 0x1a & 0xffff);
      if (iVar4 == iVar6) break;
      uStack_34 = uStack_34 + 1;
    }
    *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(param_1 + 0x3c);
    (*(code *)PTR_Clean_010c8be8)();
    uVar5 = (*(code *)PTR_RcGetString_010cb7dc)(0xd38);
    (*(code *)PTR_operator__010c90f4)(PTR_keyboardData_010c4cc8,uVar5);
    uVar5 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_GetSourceName_010cadc8)(auStack_28,uVar5,uStack_34 + 7);
                    /* try { // try from 00d9dd8c to 00d9dd93 has its CatchHandler @ 00d9de50 */
    (*(code *)PTR_operator__010c84b8)(PTR_keyboardData_010c4cc8 + 4,auStack_28);
    (*(code *)PTR__string_010c5070)(auStack_28);
    PTR_keyboardData_010c4cc8[8] = 0;
    PTR_keyboardData_010c4cc8[9] = 1;
    PTR_keyboardData_010c4cc8[10] = 1;
    *(undefined4 *)(PTR_keyboardData_010c4cc8 + 0xc) = 0xb;
    *(undefined4 *)(PTR_keyboardData_010c4cc8 + 0x10) = 0xb;
    *PTR_handleBackInPopUp_010cb2e4 = 1;
    *(int *)PTR_parentFrame_010cbd4c = param_1;
    *(undefined4 *)PTR_timeout_010c6c90 = 0;
    *(undefined4 *)PTR_popupID_010c6d00 = 0x3b;
    (*(code *)PTR_ShowButton_010c85b0)(0xe,0xc66);
    (*(code *)PTR_Summon_010c5990)(8);
    return 1;
  }
  uStack_18 = param_3;
  if (0xf045 < param_3) {
    if (((param_3 != 0xf068) && (param_3 != 0xf075)) && (param_3 != 0xf062)) {
      return 0;
    }
LAB_00d9deb8:
    uVar5 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
    (*(code *)PTR_Kill_010c4dec)(uVar5);
    return 1;
  }
  if (param_3 != 0xf042) {
    if (param_3 == 0xf044) {
      return 1;
    }
    if (param_3 != 0xf012) {
      return 0;
    }
    goto LAB_00d9deb8;
  }
  uVar5 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar4 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar5);
  if (iVar4 == 1) {
    uVar5 = (*(code *)PTR_getInstance_010cd270)();
    iVar4 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar5);
    if (iVar4 != 1) goto LAB_00d9df5c;
  }
  else {
LAB_00d9df5c:
    uVar5 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArTvConf_GetNonConnectedEnabled_010ccb14)(uVar5);
    if (iVar4 == 0) {
      iStack_20 = 0;
      goto LAB_00d9df9c;
    }
  }
  iStack_20 = 1;
LAB_00d9df9c:
  if ((iStack_20 != 0) &&
     (iVar4 = (*(code *)PTR_GetChildIdx_010cada8)
                        (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x3c)),
     iVar4 != -1)) {
    uVar1 = (*(code *)PTR_GetChildIdx_010cada8)
                      (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x3c));
    sVar2 = (*(code *)PTR_ConvertActiveIndexToIndex_010c69ac)(param_1,uVar1);
    uVar5 = (*(code *)PTR_getInstance_010c67ec)();
    uVar5 = (*(code *)PTR_GetFavSource_010c8200)(uVar5);
    sVar3 = (*(code *)PTR_ConvertSourceTypeToIndex_010ca8cc)(param_1,uVar5);
    if ((sVar3 == 0x1f) || (sVar3 != sVar2)) {
      (*(code *)PTR_SetFav_010cce24)(param_1,sVar2);
    }
    else {
      (*(code *)PTR_CancelFav_010cb16c)(param_1,sVar2);
    }
  }
  return 1;
}

