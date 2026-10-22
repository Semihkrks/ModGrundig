
undefined4 FUN_00f5dd58(ToolsMenuFrame *param_1)

{
  uchar uVar1;
  undefined4 uVar2;
  int iVar3;
  ArVideoManager *this;
  code *pcVar4;
  
  pcVar4 = *(code **)(**(int **)(param_1 + 0x194) + 0x40);
  uVar2 = *(undefined4 *)(param_1 + 0x194);
  ArVideoManager::getInstance();
  iVar3 = ArVideoManager::GetZoomLevel();
  iVar3 = (*pcVar4)(uVar2,iVar3 + -2);
  if (iVar3 != *(int *)(param_1 + 0x3c)) {
    this = (ArVideoManager *)ArVideoManager::getInstance();
    uVar1 = Container::GetFocusedWdgIdx();
    ArVideoManager::SetZoomLevel(this,uVar1);
    ToolsMenuFrame::SetFlagsYellow(param_1);
  }
  return 1;
}

