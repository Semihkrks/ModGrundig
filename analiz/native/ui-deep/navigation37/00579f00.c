
/* ArUIManager::ShowInformationPopup(std::string, unsigned long) */

void ArUIManager::ShowInformationPopup(string *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = MSystem::GetInstance();
  if (iVar1 == 0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe7b34,&UNK_00fe7d34,0x188);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MSystem::GetMWindowManager();
  iVar1 = MWindowManager::GetFocusedApp();
  if (iVar1 == 0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe7b34,&UNK_00fe7d34,0x18b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  PopUpManager::Clean();
  std::string::operator=((string *)((int)&PopUpManager::informationData + 4),param_1);
  PopUpManager::informationData._0_4_ = 2;
  PopUpManager::handleBackInPopUp = 1;
  PopUpManager::parentFrame = MApplet::GetMainFrame();
  PopUpManager::timeout = 3;
  PopUpManager::popupID = param_2;
  PopUpManager::Summon(0xb);
  return;
}

