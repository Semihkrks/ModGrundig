
void FUN_00e288c8(int param_1)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = ArUIManager::GetAnimationEnabled();
  if (iVar2 != 0) {
    uVar1 = MWnd::GetParentApp();
    uVar3 = MApplet::GetAniType(uVar1);
    MWidget::Show();
    ArUIManager::ShowWithSwipe(*(undefined4 *)(param_1 + 0x184),uVar3,500,100);
    MMainFrame::StartAnimation();
  }
  MWidget::Show();
  return;
}

