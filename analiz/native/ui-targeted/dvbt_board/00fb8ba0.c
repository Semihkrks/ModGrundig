
undefined4 FUN_00fb8ba0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  (*(code *)PTR_KillTimer_010c786c)(param_1,0);
  (*(code *)PTR_SetTimer_010cb058)(param_1,3000,0,0);
  uVar1 = (*(code *)PTR_getInstance_010c909c)();
  (*(code *)PTR_SetMainVolume_010c8dbc)(uVar1,param_3);
  (*(code *)PTR_RefreshVolumeUI_010c5f88)(param_1);
  return 1;
}

