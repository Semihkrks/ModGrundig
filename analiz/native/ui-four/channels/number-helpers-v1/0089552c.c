
/* ChannelControlFrame::TenKeyHandle(unsigned long) */

undefined4 __thiscall ChannelControlFrame::TenKeyHandle(ChannelControlFrame *this,ulong param_1)

{
  int iVar1;
  char acStack_34 [20];
  undefined4 uStack_20;
  undefined4 uStack_18;
  
  iVar1 = param_1 - 0x30;
  MWidget::SetFlag(*(undefined4 *)(this + 0x188),1,1);
  MWidget::SetFlag(*(undefined4 *)(this + 0x188),2,1);
  MWidget::Show();
  this[0x1a4] = (ChannelControlFrame)((char)this[0x1a4] + '\x01');
  if (this[0x1a4] == (ChannelControlFrame)0x1) {
    *(short *)(this + 0x1a2) = (short)iVar1;
    memset(acStack_34,0,2);
    memset((void *)0x10d4d10,0,4);
    snprintf(acStack_34,2,"%d",iVar1);
    strncpy((char *)0x10d4d10,acStack_34,1);
    if ((cRam010d4ce8 == '\0') && (iVar1 = __cxa_guard_acquire(&cRam010d4ce8), iVar1 != 0)) {
      uStack_18 = 0;
                    /* try { // try from 008956d8 to 008956df has its CatchHandler @ 0089572c */
      MString::MString((MString *)0x10d4d04);
      __cxa_guard_release(&cRam010d4ce8);
      __cxa_atexit(MString::~MString,0x10d4d04,&DAT_010cd2a8);
    }
    std::string::operator=((string *)0x10d4d08,(char *)0x10d4d10);
    MWidget::SetText(*(MString **)(this + 0x188));
    MWidget::Invalidate();
    MEvtHandle::SetTimer(this,3000,0,0);
    printf(" \n \x1b[7m @@ AYHANAK : FILE: %s   LINE: %d   \x1b[0m\n",&UNK_00ff1e48,0x36c);
  }
  else if ((byte)this[0x1a4] < 5) {
    MEvtHandle::KillTimer((ulong)this);
    *(short *)(this + 0x1a2) = *(short *)(this + 0x1a2) * 10 + (short)iVar1;
    memset(acStack_34,0,2);
    snprintf(acStack_34,2,"%d",iVar1);
    strncpy((char *)((byte)this[0x1a4] + 0x10d4d0f),acStack_34,1);
    if ((cRam010d4cf0 == '\0') && (iVar1 = __cxa_guard_acquire(&cRam010d4cf0), iVar1 != 0)) {
      uStack_20 = 0;
                    /* try { // try from 00895978 to 0089597f has its CatchHandler @ 008959cc */
      MString::MString((MString *)0x10d4cf8);
      __cxa_guard_release(&cRam010d4cf0);
      __cxa_atexit(MString::~MString,0x10d4cf8,&DAT_010cd2a8);
    }
    std::string::operator=((string *)0x10d4cfc,(char *)0x10d4d10);
    MWidget::SetText(*(MString **)(this + 0x188));
    MWidget::Invalidate();
    if (this[0x1a4] == (ChannelControlFrame)0x4) {
      MEvtHandle::SetTimer(this,2000,1,0);
      this[0x1a5] = (ChannelControlFrame)0x0;
    }
    else {
      MEvtHandle::SetTimer(this,3000,0,0);
    }
  }
  return 1;
}

