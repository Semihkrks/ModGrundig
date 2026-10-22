
undefined4 FUN_00ea3308(int param_1)

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
                    /* try { // try from 00ea339c to 00ea33a3 has its CatchHandler @ 00ea33c4 */
    PictureAdjustApp::PictureAdjustApp(this);
    if (this == (PictureAdjustApp *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_01008f88,&UNK_01008ff8,0x3d7);
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

