
undefined4 FUN_00cf576c(int param_1)

{
  ArTvSettingsManager *this;
  int iVar1;
  char *pcVar2;
  
  this = (ArTvSettingsManager *)ArTvSettingsManager::getInstance();
  ArTvSettingsManager::SetFastBootMode
            (this,(uchar)*(undefined4 *)(*(int *)(param_1 + 0x260) + 0x264));
  ArTvSettingsManager::getInstance();
  iVar1 = ArTvSettingsManager::GetFastBootMode();
  if (iVar1 != 0) {
    PopUpManager::Clean();
    pcVar2 = (char *)GetRcEngine::RcGetString(0x1106);
    std::string::operator=((string *)PopUpManager::messageBoxData,pcVar2);
    PopUpManager::messageBoxData._4_4_ = 2;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::messageBoxData._8_4_ = 0x352;
    PopUpManager::messageBoxData._12_4_ = 0x1c2;
    PopUpManager::timeout = 5;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(0xe,0xc42);
    PopUpManager::Summon(2);
  }
  return 1;
}

