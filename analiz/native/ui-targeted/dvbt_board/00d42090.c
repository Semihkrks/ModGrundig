
undefined4 FUN_00d42090(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_getInstance_010c67ec)();
  (*(code *)PTR_LockParental_010cb594)(uVar1);
  iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
  (*(code *)PTR_HideAllButtons_010ca694)(*(undefined4 *)(iVar2 + 0x1cc));
  iVar2 = (*(code *)PTR_getMenuBackgroundFrame_010c9e88)();
  (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(iVar2 + 0x1cc));
  return 1;
}

