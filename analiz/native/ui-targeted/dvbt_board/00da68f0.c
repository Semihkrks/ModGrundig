
/* InputSourceSelectFrame::InputSourceSelectFrame(MApplet*, _Rect&) */

void __thiscall
InputSourceSelectFrame::InputSourceSelectFrame
          (InputSourceSelectFrame *this,MApplet *param_1,_Rect *param_2)

{
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c9934 + 8;
  *(InputSourceSelectFrame **)PTR_pInputSourceSelectFrame_010cb004 = this;
  this[0x22c] = (InputSourceSelectFrame)0x0;
  this[0x22d] = (InputSourceSelectFrame)0x0;
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c43ec + 0x35b4,99);
  *(undefined4 *)(this + 0x118) = 0;
  return;
}

