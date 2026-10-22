
undefined4 FUN_00f5da88(ToolsMenuFrame *param_1)

{
  long lVar1;
  
  lVar1 = ArUSBMediaPlayer::getInstance();
  Container::GetFocusedWdgIdx();
  ArUSBMediaPlayer::SetRepeatMode(lVar1);
  ToolsMenuFrame::SetFlagsYellow(param_1);
  return 1;
}

