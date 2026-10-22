
undefined4 FUN_00f5d808(MWidget *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Container::GetFocusedWdgIdx();
  iVar2 = ScrollListContainer::GetChildIdx(*(MWidget **)(param_1 + 0x1ac));
  if (iVar1 == iVar2) {
    MWidget::Show();
    MString::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x170);
    MWidget::Invalidate();
    MWidget::Show();
    MMainFrame::SwitchFocusTo(param_1);
  }
  else {
    iVar1 = Container::GetFocusedWdgIdx();
    iVar2 = ScrollListContainer::GetChildIdx(*(MWidget **)(param_1 + 0x1ac));
    if (iVar1 != iVar2) {
      return 1;
    }
    MWidget::Show();
    MString::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x170);
    MWidget::Invalidate();
    MWidget::Show();
    MMainFrame::SwitchFocusTo(param_1);
  }
  ToolsMenuFrame::SetFlagsYellow((ToolsMenuFrame *)param_1);
  return 1;
}

