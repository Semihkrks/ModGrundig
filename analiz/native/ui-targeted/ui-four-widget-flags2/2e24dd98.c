
/* MWidget::SetFlag(EN_WDG_FLAG, unsigned char) */

void __thiscall MWidget::SetFlag(MWidget *this,int param_2,char param_3)

{
  if ((param_2 - 1U < 0x20) && ((1 << (param_2 - 1U & 0x1f) & 0x8000808bU) != 0)) {
    if (param_3 == '\0') {
      this[0x1a4] = (MWidget)(~(byte)param_2 & (byte)this[0x1a4]);
      return;
    }
    this[0x1a4] = (MWidget)((byte)param_2 | (byte)this[0x1a4]);
    return;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp","void MWidget::SetFlag(EN_WDG_FLAG, BOOL)",
         0x5eb);
                    /* WARNING: Subroutine does not return */
  abort();
}

