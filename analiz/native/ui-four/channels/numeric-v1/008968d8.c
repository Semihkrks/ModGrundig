
/* ChannelControlFrame::OnTimer(void*, void*, void*) */

undefined4 ChannelControlFrame::OnTimer(void *param_1,void *param_2,void *param_3)

{
  if (param_3 == (void *)0x0) {
    MEvtHandle::KillTimer((ulong)param_1);
    *(undefined1 *)((int)param_1 + 0x1a5) = 0;
    ChangeChannel((ushort)param_1);
    *(undefined1 *)((int)param_1 + 0x1a5) = 1;
    *(undefined2 *)((int)param_1 + 0x1a2) = 0;
    *(undefined1 *)((int)param_1 + 0x1a4) = 0;
    MWidget::Hide();
    MWidget::SetFlag(*(undefined4 *)((int)param_1 + 0x188),1,0);
    MWidget::SetFlag(*(undefined4 *)((int)param_1 + 0x188),2,0);
    *(undefined1 *)((int)param_1 + 0x1a5) = 0;
    MWnd::GetParentApp();
    ArProgramInfoApp::Summon(3,'\x01','\x01');
    MApplet::Kill();
  }
  else if (param_3 == (void *)0x1) {
    MEvtHandle::KillTimer((ulong)param_1);
    ChangeChannel((ushort)param_1);
    *(undefined1 *)((int)param_1 + 0x1a5) = 1;
    *(undefined2 *)((int)param_1 + 0x1a2) = 0;
    *(undefined1 *)((int)param_1 + 0x1a4) = 0;
    MWidget::Hide();
    MWidget::SetFlag(*(undefined4 *)((int)param_1 + 0x188),1,0);
    MWidget::SetFlag(*(undefined4 *)((int)param_1 + 0x188),2,0);
    *(undefined1 *)((int)param_1 + 0x1a5) = 0;
    MWnd::GetParentApp();
    ArProgramInfoApp::Summon(3,'\x01','\x01');
    MApplet::Kill();
  }
  return 1;
}

