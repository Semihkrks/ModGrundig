
/* ToolsMenuFrame::ToolsMenuFrame(MApplet*, _Rect&) */

void __thiscall ToolsMenuFrame::ToolsMenuFrame(ToolsMenuFrame *this,MApplet *param_1,_Rect *param_2)

{
  undefined4 uVar1;
  
  (*(code *)PTR_CommonFrame_010cb1c4)(this,param_1,param_2);
  *(undefined **)this = PTR_vtable_010c53c4 + 8;
  (*(code *)PTR_strncpy_010cbe38)(this + 0x11c,PTR_DAT_010c4460 + -0x456c,99);
  *(undefined4 *)(this + 0x118) = 0;
                    /* try { // try from 00f87148 to 00f8719b has its CatchHandler @ 00f871c0 */
  uVar1 = (*(code *)PTR_GetParentApp_010c98f8)(this);
  uVar1 = (*(code *)PTR_GetPrivateData_010ca218)(uVar1);
  *(undefined4 *)(this + 0x2e0) = uVar1;
  uVar1 = (*(code *)PTR_GetInstance_010c7650)();
  (*(code *)PTR_AddEventRecipient_010c7c08)(uVar1,this);
  return;
}

