
/* SoundSettingsFrame::SoundSettingsFrame(MApplet*, _Rect&) */

void __thiscall
SoundSettingsFrame::SoundSettingsFrame(SoundSettingsFrame *this,MApplet *param_1,_Rect *param_2)

{
  undefined4 uVar1;
  
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c94b4 + 8;
  *(undefined4 *)(this + 0x248) = 0xffffffff;
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c4460 + -0x5c30,99);
  *(undefined4 *)(this + 0x118) = 0;
                    /* try { // try from 00efd8ec to 00efd90f has its CatchHandler @ 00efd934 */
  uVar1 = (*(code *)PTR_GetInstance_010c7650)();
  (*(code *)PTR_AddEventRecipient_010c7c08)(uVar1,this);
  return;
}

