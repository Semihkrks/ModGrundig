
/* SoftwareUpdateFrame::OnNtyClick_ImageButton_Manual_Item_USB(void*, void*, void*) */

undefined4
SoftwareUpdateFrame::OnNtyClick_ImageButton_Manual_Item_USB
          (void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  char *pcVar2;
  
  ArTvSettingsManager::getInstance();
  iVar1 = ArTvSettingsManager::CheckUSBUpdate();
  if (iVar1 == 0) {
    PopUpManager::Clean();
    pcVar2 = (char *)GetRcEngine::RcGetString(0x1018);
    std::string::operator=((string *)((int)&PopUpManager::informationData + 4),pcVar2);
    PopUpManager::informationData._0_4_ = 2;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::timeout = 3;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(0xe,0xc66);
    PopUpManager::Summon(0xb);
    PopUpManager::popupID = 0x4c;
  }
  else if (iVar1 == 3) {
    PopUpManager::Clean();
    pcVar2 = (char *)GetRcEngine::RcGetString(0x105a);
    std::string::operator=((string *)PopUpManager::messageBoxData,pcVar2);
    PopUpManager::messageBoxData._8_4_ = 800;
    PopUpManager::messageBoxData._12_4_ = 0x1c2;
    PopUpManager::messageBoxData._4_4_ = 2;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::timeout = 3;
    PopUpManager::parentFrame = param_1;
    PopUpManager::Summon(2);
    PopUpManager::popupID = 8;
  }
  else {
    PopUpManager::Clean();
    pcVar2 = (char *)GetRcEngine::RcGetString(0xe44);
    std::string::operator=((string *)((int)&PopUpManager::informationData + 4),pcVar2);
    PopUpManager::informationData._0_4_ = 2;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::timeout = 3;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(0xe,0xc66);
    PopUpManager::Summon(0xb);
    PopUpManager::popupID = 0x4d;
  }
  return 1;
}

