
/* ToolsMenuFrame::OpenSourceSelectionPopup() */

void __thiscall ToolsMenuFrame::OpenSourceSelectionPopup(ToolsMenuFrame *this)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [12];
  
  (*(code *)PTR_vector_010c64c0)(auStack_28);
                    /* try { // try from 00f5be54 to 00f5bebf has its CatchHandler @ 00f5c2a4 */
  piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
  iVar2 = (**(code **)(*piVar1 + 0x84))(piVar1);
  if (iVar2 == 0x1c) {
    (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c4460 + -0x4840);
    (*(code *)PTR_string_010cc890)(auStack_1c);
                    /* try { // try from 00f5becc to 00f5c0a7 has its CatchHandler @ 00f5c0cc */
    uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x9b2);
    (*(code *)PTR_operator__010c90f4)(auStack_1c,uVar3);
    (*(code *)PTR_push_back_010cd044)(auStack_28,auStack_1c);
    uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x9b3);
    (*(code *)PTR_operator__010c90f4)(auStack_1c,uVar3);
    (*(code *)PTR_push_back_010cd044)(auStack_28,auStack_1c);
    uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x9b4);
    (*(code *)PTR_operator__010c90f4)(auStack_1c,uVar3);
    (*(code *)PTR_push_back_010cd044)(auStack_28,auStack_1c);
    uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x9b5);
    (*(code *)PTR_operator__010c90f4)(auStack_1c,uVar3);
    (*(code *)PTR_push_back_010cd044)(auStack_28,auStack_1c);
    (*(code *)PTR_Clean_010c8be8)();
    uVar3 = (*(code *)PTR_RcGetString_010cb7dc)(0x10fa);
    (*(code *)PTR_operator__010c90f4)(PTR_itemSelectData_010cb0d4,uVar3);
    (*(code *)PTR_operator__010c5494)(PTR_itemSelectData_010cb0d4 + 8,auStack_28);
    *(undefined4 *)(PTR_itemSelectData_010cb0d4 + 4) = 0;
    *(ToolsMenuFrame **)PTR_parentFrame_010cbd4c = this;
    *PTR_handleBackInPopUp_010cb2e4 = 1;
    (*(code *)PTR_ShowButton_010c85b0)(0xe,0xc42);
    (*(code *)PTR_Summon_010c5990)(1);
                    /* try { // try from 00f5c0b8 to 00f5c0bf has its CatchHandler @ 00f5c2a4 */
    (*(code *)PTR__string_010c5070)(auStack_1c);
  }
  else if ((((iVar2 == 0x17) || (iVar2 == 0x18)) || (iVar2 == 0x19)) ||
          ((iVar2 == 0x1a || (iVar2 == 0x1e)))) {
                    /* try { // try from 00f5c15c to 00f5c267 has its CatchHandler @ 00f5c2a4 */
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_SwitchToDTVStartDualWatch_010cc960)(uVar3,iVar2);
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_SetDualWatchStatus_010c5648)(uVar3,1,iVar2);
    uVar3 = (*(code *)PTR_getInstance_010cab20)();
    (*(code *)PTR_EnableDualView_010c8704)(uVar3,0x1c,iVar2);
    iVar2 = (*(code *)PTR_GetParentApp_010c98f8)(this);
    if (iVar2 == 0) {
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c4460 + -0x47f8,PTR_DAT_010c4460 + -0x47e0,PTR_DAT_010c4460 + -0x44f8,
                 0xf8f);
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_Kill_010c4dec)(iVar2);
  }
  else {
    (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c4460 + -0x47c4);
  }
  (*(code *)PTR__vector_010c4e7c)(auStack_28);
  return;
}

