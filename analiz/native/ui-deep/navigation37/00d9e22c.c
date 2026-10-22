
void FUN_00d9e22c(int param_1)

{
  int iVar1;
  
  iVar1 = ArUIManager::GetAnimationEnabled();
  if (iVar1 != 0) {
    MWidget::Show();
    ArUIManager::ShowWithSwipe(*(undefined4 *)(param_1 + 0x184),3,500,100);
    MMainFrame::StartAnimation();
  }
  MWidget::Show();
  return;
}

