
undefined4 FUN_00ea3648(void)

{
  PictureFormatApp *this;
  MenuBackgroundFrame *this_00;
  
  this = operator_new(0x3c);
                    /* try { // try from 00ea36a0 to 00ea36a7 has its CatchHandler @ 00ea36c8 */
  PictureFormatApp::PictureFormatApp(this);
  if (this != (PictureFormatApp *)0x0) {
    MApplet::Run((ulong)this,(void *)0x0);
    this_00 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::hideMenu(this_00);
    return 1;
  }
  printf("ASSERT FAIL: %s %s %d\n",&UNK_01008f88,&UNK_01009088,0x3c0);
                    /* WARNING: Subroutine does not return */
  abort();
}

