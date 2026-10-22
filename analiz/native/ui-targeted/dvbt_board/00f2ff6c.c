
/* SourceSetupFrame::SourceSetupFrame(MApplet*, _Rect&) */

void __thiscall
SourceSetupFrame::SourceSetupFrame(SourceSetupFrame *this,MApplet *param_1,_Rect *param_2)

{
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010cc3c4 + 8;
  (*(code *)PTR_vector_010c64c0)(this + 0x2a8);
  (*(code *)PTR_vector_010c64c0)(this + 0x2b4);
  (*(code *)PTR_vector_010c64c0)(this + 0x2c0);
  (*(code *)PTR_vector_010c64c0)(this + 0x2cc);
                    /* try { // try from 00f30050 to 00f30057 has its CatchHandler @ 00f300f0 */
  (*(code *)PTR_string_010cc890)(this + 0x2e0);
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c4460 + -0x55f4,99);
  *(undefined4 *)(this + 0x118) = 0;
  *(SourceSetupFrame **)PTR_pSourceSetupFrame_010ca0a0 = this;
  this[0x2dc] = (SourceSetupFrame)0x0;
  this[0x2e5] = (SourceSetupFrame)0x1;
  this[0x2e6] = (SourceSetupFrame)0xff;
  *(undefined2 *)(this + 0x2e8) = 0xffff;
  this[0x2ea] = (SourceSetupFrame)0xff;
  return;
}

