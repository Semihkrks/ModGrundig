
undefined4 FUN_00f5deac(ToolsMenuFrame *param_1)

{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  char *pcVar4;
  ArVideoManager *this;
  
  ArServiceSettingsManager::getInstance();
  iVar3 = ArServiceSettingsManager::ArTvConf_GetFactEcoDesign();
  if (iVar3 == 1) {
    ArTvSettingsManager::getInstance();
    iVar3 = ArTvSettingsManager::GetPictureSettingsEcoDesignReminderDisabled();
    if (iVar3 == 0) {
      ArVideoManager::getInstance();
      iVar3 = ArVideoManager::GetUIPictureMode();
      if (iVar3 == 1) {
        iVar3 = Container::GetFocusedWdgIdx();
        if (iVar3 != 1) {
          bVar1 = true;
          goto LAB_00f5dfb4;
        }
      }
    }
  }
  bVar1 = false;
LAB_00f5dfb4:
  if (bVar1) {
    PopUpManager::Clean();
    pcVar4 = (char *)GetRcEngine::RcGetString(0xf3b);
    std::string::operator=((string *)PopUpManager::yesNoBoxData,pcVar4);
    std::string::operator+=((string *)PopUpManager::yesNoBoxData," ");
    pcVar4 = (char *)GetRcEngine::RcGetString(0xcf9);
    std::string::operator+=((string *)PopUpManager::yesNoBoxData,pcVar4);
    PopUpManager::yesNoBoxData._8_4_ = 0x2ee;
    PopUpManager::yesNoBoxData._12_4_ = 0x1e0;
    PopUpManager::yesNoBoxData._28_4_ = 1;
    pcVar4 = (char *)GetRcEngine::RcGetString(0x105d);
    std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar4);
    pcVar4 = (char *)GetRcEngine::RcGetString(0xe39);
    std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar4);
    pcVar4 = (char *)GetRcEngine::RcGetString(0x106c);
    std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar4);
    PopUpManager::yesNoBoxData[0x20] = 1;
    PopUpManager::yesNoBoxData[0x21] = 0;
    pcVar4 = (char *)GetRcEngine::RcGetString(0x10f9);
    std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x24),pcVar4);
    PopUpManager::yesNoBoxData._4_4_ = 0;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::timeout = 0;
    PopUpManager::popupID = 0x25;
    PopUpManager::parentFrame = param_1;
    PopUpManager::Summon(3);
  }
  else {
    this = (ArVideoManager *)ArVideoManager::getInstance();
    uVar2 = Container::GetFocusedWdgIdx();
    ArVideoManager::SetPictureMode(this,uVar2);
    ToolsMenuFrame::SetFlagsYellow(param_1);
  }
  return 1;
}

