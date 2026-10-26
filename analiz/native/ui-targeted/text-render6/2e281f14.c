
/* TextBox::Update(_Rect&, unsigned char) */

void __thiscall TextBox::Update(TextBox *this,_Rect *param_1,uchar param_2)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = MWidget::QueryFlag((MWidget *)this,'\x02');
  if (((iVar1 != 0) && (*(int *)(this + 0x24) != 0)) && (*(int *)(this + 0x28) != 0)) {
    (**(code **)(*(int *)this + 0x30))(this,param_1,param_2);
    if (this[0x17e] == (TextBox)0x0) {
      UNRECOVERED_JUMPTABLE = MWidget::DrawSingleLine;
    }
    else {
      UNRECOVERED_JUMPTABLE = MWidget::DrawMultipleLines;
    }
                    /* WARNING: Could not recover jumptable at 0x2e281fc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(this,param_1);
    return;
  }
  return;
}

