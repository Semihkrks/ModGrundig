
undefined4 FUN_00894ff4(void)

{
  int iVar1;
  int *piStack_c;
  
  iVar1 = MApplet::GetMainFrame();
  if (iVar1 == 0) {
    piStack_c = (int *)0x0;
  }
  else {
    piStack_c = (int *)__dynamic_cast(iVar1,&MMainFrame::typeinfo,&ChannelControlFrame::typeinfo,0);
  }
  if (piStack_c == (int *)0x0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff1d58,&UNK_00ff1d94,0xa3);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  if (piStack_c != (int *)0x0) {
    (**(code **)(*piStack_c + 8))(piStack_c);
  }
  return 1;
}

