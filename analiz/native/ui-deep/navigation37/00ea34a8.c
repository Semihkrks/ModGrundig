
undefined4 FUN_00ea34a8(int param_1)

{
  int iVar1;
  PictureAdjustApp *this;
  MenuBackgroundFrame *this_00;
  undefined4 uStack_1c;
  
  iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x3c));
  if (iVar1 == 0) {
    uStack_1c = 0;
  }
  else {
    this = operator_new(0x3c);
                    /* try { // try from 00ea353c to 00ea3543 has its CatchHandler @ 00ea3564 */
    PictureAdjustApp::PictureAdjustApp(this);
    if (this == (PictureAdjustApp *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_01008f88,&UNK_0100903c,0x3cb);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    MApplet::Run((ulong)this,(void *)0x0);
    this_00 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::hideMenu(this_00);
    uStack_1c = 1;
  }
  return uStack_1c;
}

