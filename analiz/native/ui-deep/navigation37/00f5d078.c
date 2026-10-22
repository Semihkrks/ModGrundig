
/* ToolsMenuFrame::OnNtyClicked_Digilink(void*, void*, void*) */

undefined4 ToolsMenuFrame::OnNtyClicked_Digilink(void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  char *pcVar2;
  allocator aaStack_40 [4];
  string asStack_3c [4];
  undefined4 uStack_38;
  undefined1 auStack_34 [4];
  ArCecController aAStack_30 [16];
  string *psStack_20;
  undefined4 uStack_1c;
  
  if (*(int *)((int)param_1 + 0x2e4) == 0) {
    ArCecController::GetDeviceList(aAStack_30);
    iVar1 = std::vector<std::string,std::allocator<std::string>>::size
                      ((vector<std::string,std::allocator<std::string>> *)aAStack_30);
    if (iVar1 == 0) {
      *(undefined4 *)((int)param_1 + 0x2e4) = 1;
      PopUpManager::Clean();
      pcVar2 = (char *)GetRcEngine::RcGetString(0xde6);
      std::string::operator=((string *)PopUpManager::messageBoxData,pcVar2);
      PopUpManager::messageBoxData._8_4_ = 0x28a;
      PopUpManager::messageBoxData._12_4_ = 300;
      PopUpManager::messageBoxData._4_4_ = 1;
      PopUpManager::handleBackInPopUp = 0;
      PopUpManager::parentFrame = param_1;
      PopUpManager::ShowButton(0xe,0xc68);
      PopUpManager::Summon(2);
      ArCecController::StartDeviceSearch();
    }
    else {
      std::vector<std::string,std::allocator<std::string>>::begin();
                    /* try { // try from 00f5d138 to 00f5d13f has its CatchHandler @ 00f5d438 */
      pcVar2 = (char *)GetRcEngine::RcGetString(0xe4c);
      std::allocator<char>::allocator();
                    /* try { // try from 00f5d178 to 00f5d17f has its CatchHandler @ 00f5d260 */
      std::string::string(asStack_3c,pcVar2,aaStack_40);
                    /* try { // try from 00f5d1a0 to 00f5d1a7 has its CatchHandler @ 00f5d204 */
      std::vector<std::string,std::allocator<std::string>>::insert
                (auStack_34,aAStack_30,uStack_38,asStack_3c);
      psStack_20 = asStack_3c;
                    /* try { // try from 00f5d1bc to 00f5d1c3 has its CatchHandler @ 00f5d260 */
      std::string::~string(psStack_20);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_40);
      *(undefined4 *)((int)param_1 + 0x2e4) = 2;
                    /* try { // try from 00f5d1f0 to 00f5d1f7 has its CatchHandler @ 00f5d438 */
      PopUpManager::Clean();
                    /* try { // try from 00f5d24c to 00f5d40b has its CatchHandler @ 00f5d438 */
      pcVar2 = (char *)GetRcEngine::RcGetString(0x23);
      std::string::operator=((string *)PopUpManager::itemSelectData,pcVar2);
      std::vector<std::string,std::allocator<std::string>>::operator=
                ((vector<std::string,std::allocator<std::string>> *)
                 (PopUpManager::itemSelectData + 8),(vector *)aAStack_30);
      PopUpManager::itemSelectData._4_4_ = 0;
      PopUpManager::handleBackInPopUp = 0;
      PopUpManager::parentFrame = param_1;
      PopUpManager::ShowButton(7,0xf37);
      PopUpManager::ShowButton(0xe,0xc42);
      PopUpManager::ShowButton(3,0x79);
      PopUpManager::Summon(1);
    }
    uStack_1c = 1;
    std::vector<std::string,std::allocator<std::string>>::~vector
              ((vector<std::string,std::allocator<std::string>> *)aAStack_30);
  }
  else {
    uStack_1c = 1;
  }
  return uStack_1c;
}

