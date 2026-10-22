
undefined4 FUN_00f5dc08(ToolsMenuFrame *param_1)

{
  uchar uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  ArVideoManager *this;
  code *pcVar5;
  
  pcVar5 = *(code **)(**(int **)(param_1 + 0x19c) + 0x40);
  uVar2 = *(undefined4 *)(param_1 + 0x19c);
  ArVideoManager::getInstance();
  uVar3 = ArVideoManager::GetPictureFormat();
  iVar4 = (*pcVar5)(uVar2,uVar3);
  if (iVar4 != *(int *)(param_1 + 0x3c)) {
    this = (ArVideoManager *)ArVideoManager::getInstance();
    uVar1 = Container::GetFocusedWdgIdx();
    ArVideoManager::SetPictureFormat(this,uVar1);
    ToolsMenuFrame::SetFlagsYellow(param_1);
  }
  return 1;
}

