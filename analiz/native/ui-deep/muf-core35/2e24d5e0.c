
/* MWidget::QueryVisualState() */

undefined4 __thiscall MWidget::QueryVisualState(MWidget *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = QueryFlag(this,'\x01');
  uVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = QueryFlag(this,'\x04');
    uVar2 = 2;
    if (iVar1 == 0) {
      iVar1 = QueryFlag(this,'\b');
      uVar2 = 3;
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      return uVar2;
    }
  }
  return uVar2;
}

