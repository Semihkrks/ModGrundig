
undefined4 FUN_00f5db3c(ToolsMenuFrame *param_1)

{
  uchar uVar1;
  ArAudioManager *this;
  
  puts("\n Sound_preset setted ");
  this = (ArAudioManager *)ArAudioManager::getInstance();
  uVar1 = Container::GetFocusedWdgIdx();
  ArAudioManager::SetSoundMode(this,uVar1);
  ToolsMenuFrame::SetFlagsYellow(param_1);
  return 1;
}

