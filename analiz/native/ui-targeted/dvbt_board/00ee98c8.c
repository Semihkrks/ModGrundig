
undefined4 FUN_00ee98c8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_IsTvInFirstTime_010c83c8)();
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_HideAllButtons_010ca694)(*(undefined4 *)(iVar1 + 0x1cc));
    iVar1 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
    (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(iVar1 + 0x1cc));
  }
  else {
    iVar1 = (*(code *)PTR_getFrame_010c8a9c)();
    (*(code *)PTR_HideAllButtons_010ca694)(*(undefined4 *)(iVar1 + 0x1b4));
    iVar1 = (*(code *)PTR_getFrame_010c8a9c)();
    (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(iVar1 + 0x1b4));
  }
  iVar1 = (*(code *)PTR_GetAnimationEnabled_010c6370)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
    uVar2 = (*(code *)PTR_GetAniType_010cb918)(uVar2,1);
    (*(code *)PTR_CloseWithSwipe_010c74d4)(*(undefined4 *)(param_1 + 0x184),uVar2,0xfa,100);
    (*(code *)PTR_StartAnimation_010c81e0)(param_1);
  }
  (*(code *)PTR_operator_delete_010c9e30)(*(undefined4 *)(param_1 + 0x230));
  (*(code *)PTR_operator_delete_010c9e30)(*(undefined4 *)(param_1 + 0x234));
  (*(code *)PTR_operator_delete_010c9e30)(*(undefined4 *)(param_1 + 0x238));
  (*(code *)PTR_operator_delete_010c9e30)(*(undefined4 *)(param_1 + 0x23c));
  (*(code *)PTR_operator_delete_010c9e30)(*(undefined4 *)(param_1 + 0x240));
  return 1;
}

