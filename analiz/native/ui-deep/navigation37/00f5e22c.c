
undefined4 FUN_00f5e22c(ToolsMenuFrame *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  ArTvSettingsManager *this;
  ulong uVar4;
  code *pcVar5;
  
  pcVar5 = *(code **)(**(int **)(param_1 + 0x198) + 0x40);
  uVar1 = *(undefined4 *)(param_1 + 0x198);
  ArTvSettingsManager::getInstance();
  uVar2 = ArTvSettingsManager::GetSleepTimer();
  iVar3 = (*pcVar5)(uVar1,uVar2);
  if (iVar3 != *(int *)(param_1 + 0x3c)) {
    this = (ArTvSettingsManager *)ArTvSettingsManager::getInstance();
    uVar4 = Container::GetFocusedWdgIdx();
    ArTvSettingsManager::SetSleepTimer(this,uVar4);
    printf("/n setted /n");
    ToolsMenuFrame::SetFlagsYellow(param_1);
  }
  return 1;
}

