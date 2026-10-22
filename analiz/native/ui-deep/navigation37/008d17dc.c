
/* CommonFrame::HideBubbleHelpOnKillFocus(void*, void*, void*) */

undefined4 CommonFrame::HideBubbleHelpOnKillFocus(void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  
  MEvtHandle::KillTimer((ulong)param_1);
  iVar1 = BubbleHelpFrame::GetBubbleHelpFrame();
  if (iVar1 != 0) {
    BubbleHelpFrame::GetBubbleHelpFrame();
    MWnd::GetParentApp();
    MApplet::Kill();
  }
  return 0;
}

