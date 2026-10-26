
/* MWidget::QueryFlag(unsigned char) */

bool __thiscall MWidget::QueryFlag(MWidget *this,uchar param_1)

{
  return (param_1 & (byte)this[0x1a4]) == param_1;
}

