
undefined4 FUN_00895108(MMainFrame *param_1)

{
  ChannelControlFrame *pCVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  _Rect *p_Stack_20;
  ChannelControlFrame *pCStack_1c;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_34 = GetRcEngine::RcGetNum(0x52);
  uStack_30 = GetRcEngine::RcGetNum(0x53);
  uStack_2c = GetRcEngine::RcGetNum(0x51);
  uStack_28 = GetRcEngine::RcGetNum(0x50);
  pCStack_1c = operator_new(0x1a8,(nothrow_t *)&DAT_2c7f5bd0);
  if (pCStack_1c != (ChannelControlFrame *)0x0) {
                    /* try { // try from 008951e4 to 008951eb has its CatchHandler @ 00895200 */
    ChannelControlFrame::ChannelControlFrame(pCStack_1c,(MApplet *)param_1,(_Rect *)&uStack_34);
  }
  pCVar1 = pCStack_1c;
  p_Stack_20 = (_Rect *)pCStack_1c;
  if (pCStack_1c != (ChannelControlFrame *)0x0) {
    MApplet::SetMainFrame(param_1);
    MMainFrame::InvalidateClientArea((_Rect *)pCVar1);
    MSystem::GetInstance();
    MMainFrame::CreateDFBWindow((_IDirectFBDisplayLayer *)pCVar1);
    return 1;
  }
  printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff1d58,&UNK_00ff1dc4,0x90);
                    /* WARNING: Subroutine does not return */
  abort();
}

