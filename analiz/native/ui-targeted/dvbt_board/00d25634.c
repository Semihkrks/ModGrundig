
/* GeneralSettingsFrame::GeneralSettingsFrame(MApplet*, _Rect&) */

void __thiscall
GeneralSettingsFrame::GeneralSettingsFrame
          (GeneralSettingsFrame *this,MApplet *param_1,_Rect *param_2)

{
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c8308 + 8;
  (*(code *)PTR_vector_010c6d1c)(this + 0x288);
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c43ec + -0x1a60,99);
  *(undefined4 *)(this + 0x118) = 0;
  *(GeneralSettingsFrame **)PTR_pGeneralSettingsFrame_010cacc0 = this;
                    /* try { // try from 00d256f4 to 00d256fb has its CatchHandler @ 00d25730 */
  (*(code *)PTR_ClosePopUp_010c7270)();
  *(undefined4 *)(this + 0x294) = 0;
  *(undefined2 *)(this + 0x298) = 0;
  return;
}

