
/* HomePageFrame::HomePageFrame(MApplet*, _Rect&) */

void __thiscall HomePageFrame::HomePageFrame(HomePageFrame *this,MApplet *param_1,_Rect *param_2)

{
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c62d4 + 8;
  (*(code *)PTR_vector_010cc1b0)(this + 0x2a0);
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c43ec + -0x14f8,99);
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x270) = 0;
  this[0x2b1] = (HomePageFrame)0x1;
  this[0x2b2] = (HomePageFrame)0x1;
  this[0x2b0] = (HomePageFrame)0x0;
  return;
}

