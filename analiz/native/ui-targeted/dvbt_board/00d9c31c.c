
/* InputSourceSelectFrame::InputSourceChange(unsigned char, unsigned char) */

void InputSourceSelectFrame::InputSourceChange(uchar param_1,uchar param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == '\x14') {
    uVar1 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_OnNtyKey_Button_DTV_010c54f4)(uVar1,0,0,0);
  }
  else if (param_1 == '\x1b') {
    uVar1 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_OnNtyKey_Button_Scart_010c80c4)(uVar1,0,0,0);
  }
  else if (param_1 == '\x1e') {
    uVar1 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_OnNtyKey_Button_Component_010c66f8)(uVar1,0,0,0);
  }
  else if (param_1 == '\x1c') {
    uVar1 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_OnNtyKey_Button_PCRGB_010c98e0)(uVar1,0,0,0);
  }
  else if ((param_1 < 0x15) || (0x19 < param_1)) {
    if (param_1 == '\x1d') {
      uVar1 = (*(code *)PTR_getInstance_010c67ec)();
      (*(code *)PTR_OnNtyKey_Button_AV_010cc3f8)(uVar1,0,0,0);
    }
    else if (param_1 == '\x1a') {
      uVar1 = (*(code *)PTR_getInstance_010c67ec)();
      (*(code *)PTR_OnNtyKey_Button_SV_010c64cc)(uVar1,0,0,0);
    }
    else {
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + 0x3460,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x368c,0x471
                );
      (*(code *)PTR_abort_010cc6c0)();
    }
  }
  else {
    uVar1 = (*(code *)PTR_getInstance_010c67ec)();
    (*(code *)PTR_OnNtyKey_Button_HDMI_010cae4c)(uVar1,param_1 - 0x15,0,0);
  }
  if (param_2 != '\0') {
    iVar2 = (*(code *)PTR_GetInstance_010c7568)();
    if (iVar2 != 0) {
      uVar1 = (*(code *)PTR_GetParentApp_010c98f8)(iVar2);
      (*(code *)PTR_Kill_010c4dec)(uVar1);
    }
    (*(code *)PTR_Summon_010c78d8)(1,1,1);
  }
  return;
}

