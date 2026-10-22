
/* QuickSettingsFrame::QuickSettingsFrame(MApplet*, _Rect&) */

void __thiscall
QuickSettingsFrame::QuickSettingsFrame(QuickSettingsFrame *this,MApplet *param_1,_Rect *param_2)

{
  undefined4 uVar1;
  
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c901c + 8;
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c4460 + -0x703c,99);
  *(undefined4 *)(this + 0x118) = 0;
                    /* try { // try from 00eaa728 to 00eaa74b has its CatchHandler @ 00eaa770 */
  uVar1 = (*(code *)PTR_GetInstance_010c7650)();
  (*(code *)PTR_AddEventRecipient_010c7c08)(uVar1,this);
  return;
}

