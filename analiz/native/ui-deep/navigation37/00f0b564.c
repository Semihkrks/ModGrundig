
/* SourceSetupFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
SourceSetupFrame::OnKey(SourceSetupFrame *this,void *param_1,void *param_2,void *param_3)

{
  bool bVar1;
  char cVar2;
  ulong uVar3;
  int iVar4;
  undefined3 extraout_var;
  ArTvManager *this_00;
  undefined3 extraout_var_00;
  void *pvVar5;
  undefined4 uVar6;
  MenuBackgroundFrame *pMVar7;
  IdleAppFrame *this_01;
  char *pcVar8;
  ArResourceManager aAStack_100 [12];
  ArResourceManager aAStack_f4 [12];
  ArResourceManager aAStack_e8 [12];
  ArResourceManager aAStack_dc [4];
  allocator aaStack_d8 [4];
  string asStack_d4 [4];
  string asStack_d0 [4];
  allocator aaStack_cc [4];
  string asStack_c8 [4];
  ArResourceManager aAStack_c4 [4];
  ArResourceManager aAStack_c0 [4];
  ArResourceManager aAStack_bc [4];
  ArResourceManager aAStack_b8 [4];
  ArResourceManager aAStack_b4 [4];
  ArResourceManager aAStack_b0 [4];
  allocator aaStack_ac [4];
  string asStack_a8 [40];
  TopLayerApp *pTStack_80;
  TopLayerApp *pTStack_7c;
  TopLayerApp *pTStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  ArResourceManager *pAStack_6c;
  int iStack_68;
  string *psStack_64;
  int iStack_60;
  string *psStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  string *psStack_48;
  int iStack_44;
  string *psStack_40;
  int iStack_3c;
  int iStack_38;
  string *psStack_34;
  string *psStack_30;
  MemoryCloneApp *pMStack_2c;
  MemoryCloneApp *pMStack_28;
  uint uStack_24;
  void *pvStack_1c;
  
  if (param_2 == (void *)0xf014) {
    CommonFrame::EnableBubbleHelp((CommonFrame *)this);
    return 1;
  }
  pvStack_1c = param_2;
  if (param_2 == (void *)0xf00f) {
LAB_00f0ca08:
    MEvtHandle::KillTimer((ulong)this);
    return 0;
  }
  if (param_2 < (void *)0xf010) {
    if ((void *)0xf001 < param_2) {
      if (param_2 == (void *)0xf002) {
        if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
          return 1;
        }
        if (*(int *)(this + 0x3c) != *(int *)(this + 0x19c)) {
          return 0;
        }
        MMainFrame::SwitchFocusTo((MWidget *)this);
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::focusToBar(pMVar7,'\x01');
        return 1;
      }
      if (param_2 != (void *)0xf003) {
        return 0;
      }
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
        return 0;
      }
      MMainFrame::SwitchFocusTo((MWidget *)this);
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::focusToBar(pMVar7,'\0');
      return 1;
    }
    if ((void *)0xefff < param_2) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        pvVar5 = (void *)MenuBackgroundFrame::getMenuBackgroundFrame();
        uVar6 = MenuBackgroundFrame::OnKey(pvVar5,param_1,param_2);
        return uVar6;
      }
      iVar4 = MWidget::GetID();
      if (iVar4 != 0x30) {
        return 0;
      }
      return 1;
    }
    if (param_2 == (void *)0xd) {
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x240)) {
        return 0;
      }
      return 1;
    }
    if (param_2 < (void *)0xd) {
      return 0;
    }
    if (9 < (int)param_2 - 0x30U) {
      return 0;
    }
    *(uint *)(this + 0x2d8) = *(int *)(this + 0x2d8) << 4 | (int)param_2 - 0x30U;
    uStack_24 = *(uint *)(this + 0x2d8) & 0xffff;
    if (uStack_24 != 0x4658) {
      if ((uStack_24 == 0x8547) && (iVar4 = MWidget::GetID(), iVar4 == 0x3f)) {
        MWidget::Show();
        MWidget::Show();
        MWidget::Show();
        (**(code **)(**(int **)(this + 0x198) + 0x48))(*(undefined4 *)(this + 0x198));
      }
      iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 400));
      if (iVar4 != 1) {
        return 0;
      }
      iVar4 = MWidget::GetID();
      if (iVar4 != 0x30) {
        return 0;
      }
      puts("\n StopCurrentProgram ");
      ArScanManager::getInstance();
      ArScanManager::StopCurrentProgram();
      psStack_30 = (string *)(*(int *)(*(int *)(this + 0x244) + 0x260) + 0x170);
      std::allocator<char>::allocator();
                    /* try { // try from 00f0ba58 to 00f0ba5f has its CatchHandler @ 00f0bb3c */
      std::string::string(asStack_a8,"",aaStack_ac);
                    /* try { // try from 00f0ba74 to 00f0ba7b has its CatchHandler @ 00f0bafc */
      MString::Set(psStack_30);
      psStack_34 = asStack_a8;
                    /* try { // try from 00f0ba90 to 00f0ba97 has its CatchHandler @ 00f0bb3c */
      std::string::~string(psStack_34);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_ac);
      MWidget::Invalidate();
      MEvtHandle::SetTimer(this,0x5dc,8,1);
      return 0;
    }
    pMStack_28 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
    if (pMStack_28 != (MemoryCloneApp *)0x0) {
                    /* try { // try from 00f0b7b4 to 00f0b7bb has its CatchHandler @ 00f0b7d0 */
      MemoryCloneApp::MemoryCloneApp(pMStack_28);
    }
    pMStack_2c = pMStack_28;
    if (pMStack_28 == (MemoryCloneApp *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_0100a61c,&UNK_0100aadc,0xe42);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    MApplet::Run((ulong)pMStack_28,(void *)0x0);
    uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::openMenu(uVar3,'\0',(void *)0x0);
    return 1;
  }
  if (param_2 < (void *)0xf048) {
    if ((void *)0xf045 < param_2) {
      iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 400));
      if (iVar4 != 1) {
        return 0;
      }
      ArTvManager::getInstance();
      iVar4 = ArTvManager::GetCurrentDvbAntennaType();
      if (iVar4 != 1) {
        return 0;
      }
      this_01 = (IdleAppFrame *)IdleAppFrame::GetIdleAppFrame();
      IdleAppFrame::OnKey(this_01,(void *)0x0,param_2,(void *)0x1);
      this[0x2e5] = (SourceSetupFrame)0x1;
      ArResourceManager::getInstance();
      ArResourceManager::SetChannelValueNum(0);
      pAStack_6c = (ArResourceManager *)ArResourceManager::getInstance();
      ArResourceManager::getInstance();
      ArResourceManager::GetChannelValueNum(aAStack_c4);
                    /* try { // try from 00f0cb44 to 00f0cb77 has its CatchHandler @ 00f0cbac */
      pcVar8 = (char *)std::string::c_str();
      uVar3 = atoi(pcVar8);
      cVar2 = ArResourceManager::IsVHFChannel(pAStack_6c,uVar3);
      std::string::~string((string *)aAStack_c4);
      if (cVar2 == '\0') {
        MString::Set((short)*(undefined4 *)(*(int *)(this + 0x240) + 0x250) + 0x170);
      }
      else {
        MString::Set((short)*(undefined4 *)(*(int *)(this + 0x240) + 0x250) + 0x170);
      }
      iVar4 = *(int *)(this + 0x230);
      ArResourceManager::getInstance();
      uVar6 = ArResourceManager::GetNordigDSKSelection();
      *(undefined4 *)(iVar4 + 0x264) = uVar6;
      uStack_70 = *(undefined4 *)(this + 0x240);
      std::allocator<char>::allocator();
                    /* try { // try from 00f0ccb8 to 00f0ccbf has its CatchHandler @ 00f0cd88 */
      std::string::string(asStack_c8,"   ",aaStack_cc);
                    /* try { // try from 00f0ccd4 to 00f0ccdb has its CatchHandler @ 00f0cd4c */
      NumberEdit::SetDefaultDigitsAsText(uStack_70,asStack_c8);
                    /* try { // try from 00f0ccec to 00f0ccf3 has its CatchHandler @ 00f0cd88 */
      std::string::~string(asStack_c8);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_cc);
      ArResourceManager::getInstance();
      iVar4 = ArResourceManager::IsNordigCountry();
      if (iVar4 == 0) {
        uVar6 = *(undefined4 *)(this + 0x240);
        ArResourceManager::GetChannelValueNum(aAStack_dc);
                    /* try { // try from 00f0cfb8 to 00f0cfbf has its CatchHandler @ 00f0cfe4 */
        NumberEdit::SetDefaultDigitsAsText(uVar6,aAStack_dc);
        std::string::~string((string *)aAStack_dc);
      }
      else {
        uStack_74 = *(undefined4 *)(this + 0x240);
        ArResourceManager::getInstance();
        ArResourceManager::GetNordigChannelNumberString();
                    /* try { // try from 00f0ce14 to 00f0ce1b has its CatchHandler @ 00f0cf44 */
        pcVar8 = (char *)std::string::c_str();
        std::allocator<char>::allocator();
                    /* try { // try from 00f0ce54 to 00f0ce5b has its CatchHandler @ 00f0cf08 */
        std::string::string(asStack_d0,pcVar8,aaStack_d8);
                    /* try { // try from 00f0ce70 to 00f0ce77 has its CatchHandler @ 00f0cecc */
        NumberEdit::SetDefaultDigitsAsText(uStack_74,asStack_d0);
                    /* try { // try from 00f0ce88 to 00f0ce8f has its CatchHandler @ 00f0cf08 */
        std::string::~string(asStack_d0);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_d8);
        std::string::~string(asStack_d4);
      }
      NumberEdit::SetRightToLeftFlag();
      MWidget::Invalidate();
      MWidget::Invalidate();
      return 1;
    }
    if (param_2 == (void *)0xf043) {
      printf("Green button is pressed ");
      if (PopUpManager::popupID == 0x2d) {
        ArResourceManager::getInstance();
        ArResourceManager::GetTKGSTransponderList(aAStack_f4);
        iVar4 = std::vector<std::string,std::allocator<std::string>>::size
                          ((vector<std::string,std::allocator<std::string>> *)aAStack_f4);
        std::vector<std::string,std::allocator<std::string>>::~vector
                  ((vector<std::string,std::allocator<std::string>> *)aAStack_f4);
        if (iVar4 == 0) {
          return 0;
        }
        pTStack_7c = operator_new(0x3c);
                    /* try { // try from 00f0d2e8 to 00f0d2ef has its CatchHandler @ 00f0d310 */
        TopLayerApp::TopLayerApp(pTStack_7c);
        if (pTStack_7c == (TopLayerApp *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_0100a61c,&UNK_0100aadc,0xf59);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        MApplet::Run((ulong)pTStack_7c,(void *)0x0);
        return 1;
      }
      if (PopUpManager::popupID != 0x2e) {
        return 0;
      }
      ArResourceManager::getInstance();
      ArResourceManager::GetTKGSHiddenTransponderList(aAStack_100);
      iVar4 = std::vector<std::string,std::allocator<std::string>>::size
                        ((vector<std::string,std::allocator<std::string>> *)aAStack_100);
      std::vector<std::string,std::allocator<std::string>>::~vector
                ((vector<std::string,std::allocator<std::string>> *)aAStack_100);
      if (iVar4 != 0) {
        puts("\n\n\n*******  EN_POPUP_SELECTION_TKGS_HIDDEN_LIST  ****************\n\n");
        ArResourceManager::getInstance();
        ArResourceManager::ClearTKGSHiddenLocationList();
        OpenTKGSHiddenTransponderPopup(this);
        return 1;
      }
      return 0;
    }
    if (param_2 == (void *)0xf045) {
      printf("blue button is pressed ");
      if (PopUpManager::popupID != 0x2d) {
        return 0;
      }
      ArResourceManager::getInstance();
      ArResourceManager::GetTKGSTransponderList(aAStack_e8);
      iVar4 = std::vector<std::string,std::allocator<std::string>>::size
                        ((vector<std::string,std::allocator<std::string>> *)aAStack_e8);
      std::vector<std::string,std::allocator<std::string>>::~vector
                ((vector<std::string,std::allocator<std::string>> *)aAStack_e8);
      if (iVar4 != 0) {
        pTStack_78 = operator_new(0x3c);
                    /* try { // try from 00f0d154 to 00f0d15b has its CatchHandler @ 00f0d17c */
        TopLayerApp::TopLayerApp(pTStack_78);
        if (pTStack_78 == (TopLayerApp *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_0100a61c,&UNK_0100aadc,0xf49);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        MApplet::Run((ulong)pTStack_78,(void *)0x0);
        return 1;
      }
      return 0;
    }
    if (param_2 != (void *)0xf042) {
      return 0;
    }
    printf("Red button is pressed ");
    if (PopUpManager::popupID != 0x2d) {
      return 0;
    }
    pTStack_80 = operator_new(0x3c);
                    /* try { // try from 00f0d4f0 to 00f0d4f7 has its CatchHandler @ 00f0d518 */
    TopLayerApp::TopLayerApp(pTStack_80);
    if (pTStack_80 == (TopLayerApp *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_0100a61c,&UNK_0100aadc,0xf71);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    MApplet::Run((ulong)pTStack_80,(void *)0x0);
    return 1;
  }
  if (param_2 == (void *)0xf075) {
    if (((PopUpManager::popupID == 0x2d) || (PopUpManager::popupID == 0x2f)) ||
       (PopUpManager::popupID == 0x2e)) {
      PopUpManager::ClosePopUp();
      return 1;
    }
    if (PopUpManager::popupID == 0x32) {
      return 1;
    }
    if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
      uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::openMenu(uVar3,'\x01',(void *)0x0);
      return 1;
    }
    pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    iVar4 = MenuBackgroundFrame::getBackgroundMode(pMVar7);
    if (iVar4 != 2) {
      iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x1b4));
      if (iVar4 != 0) {
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
        uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::openMenu(uVar3,'\x06',(void *)0x0);
        return 1;
      }
      ArServiceSettingsManager::getInstance();
      iVar4 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
      if (iVar4 == 1) {
        ArTvSettingsManager::getInstance();
        iVar4 = ArTvSettingsManager::GetBasicMode();
        if (iVar4 == 1) {
          iStack_50 = 1;
          goto LAB_00f0c388;
        }
      }
      iStack_50 = 0;
LAB_00f0c388:
      if (iStack_50 == 0) {
        HideAdvancedItems(this);
      }
      else {
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
        uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::openMenu(uVar3,'\x06',(void *)0x0);
      }
      return 1;
    }
    iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 400));
    if (iVar4 != 1) {
      iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x194));
      if (iVar4 == 1) {
        HideAllShowSubmenu(this,1,*(MWidget **)(this + 0x1a4));
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
        return 1;
      }
      iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x198));
      if (iVar4 == 1) {
        HideAllShowSubmenu(this,1,*(MWidget **)(this + 0x1a8));
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
        return 1;
      }
      HideAllShowSubmenu(this,1,*(MWidget **)(this + 0x184));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
      return 1;
    }
    MEvtHandle::KillTimer((ulong)this);
    if (this[0x2dc] != (SourceSetupFrame)0x0) {
      MWidget::Invalidate();
      HideAllShowSubmenu(this,5,*(MWidget **)(this + 0x26c));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      pcVar8 = (char *)GetRcEngine::RcGetString(0xd63);
      MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
      return 1;
    }
    iStack_44 = 0;
    iStack_4c = 0;
                    /* try { // try from 00f0bd8c to 00f0be6f has its CatchHandler @ 00f0bec4 */
    iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x1fc));
    if (iVar4 == 1) {
      ArTvManager::getInstance();
      iVar4 = ArTvManager::GetCurrentDvbAntennaType();
      if (iVar4 == 1) {
        psStack_40 = (string *)(this + 0x2e0);
        ArResourceManager::GetChannelValue(aAStack_b0);
        iStack_44 = 1;
        bVar1 = std::operator!=(psStack_40,(string *)aAStack_b0);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          psStack_48 = (string *)(this + 0x2e0);
          ArResourceManager::GetChannelValue(aAStack_b4);
          iStack_4c = 1;
          cVar2 = std::operator==(psStack_48,(string *)aAStack_b4);
          if ((cVar2 != '\x01') || (this[0x2e4] == (SourceSetupFrame)0x0)) goto LAB_00f0bea4;
        }
        iStack_3c = 1;
        goto LAB_00f0bea8;
      }
    }
LAB_00f0bea4:
    iStack_3c = 0;
LAB_00f0bea8:
    iStack_38 = iStack_3c;
    if (iStack_4c != 0) {
                    /* try { // try from 00f0bf28 to 00f0bf2f has its CatchHandler @ 00f0bf48 */
      std::string::~string((string *)aAStack_b4);
    }
    if (iStack_44 != 0) {
      std::string::~string((string *)aAStack_b0);
    }
    if (iStack_38 != 0) {
      NumberEdit::Clear();
      NumberEdit::SetRightToLeftFlag();
      ArScanManager::getInstance();
      ArScanManager::PlayCurrentProgram();
      HideAllShowSubmenu(this,1,*(MWidget **)(this + 0x1bc));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
      return 1;
    }
    iVar4 = *(int *)(*(int *)(this + 0x244) + 0x260);
    ArResourceManager::GetNetworkValue(aAStack_b8);
                    /* try { // try from 00f0c0b0 to 00f0c0b7 has its CatchHandler @ 00f0c140 */
    MString::Set((string *)(iVar4 + 0x170));
    std::string::~string((string *)aAStack_b8);
    MWidget::Invalidate();
    HideAllShowSubmenu(this,1,*(MWidget **)(this + 0x1bc));
    pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
    return 1;
  }
  if (param_2 == (void *)0xf550) goto LAB_00f0ca08;
  if (param_2 != (void *)0xf062) {
    return 0;
  }
  this_00 = (ArTvManager *)ArTvManager::getInstance();
  iVar4 = ArTvManager::GetCurrentInputSourceType(this_00);
  if (iVar4 != 0) goto LAB_00f0c78c;
  iStack_60 = 0;
  iStack_68 = 0;
                    /* try { // try from 00f0c4c0 to 00f0c5e3 has its CatchHandler @ 00f0c628 */
  iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x1fc));
  if (iVar4 == 1) {
    psStack_5c = (string *)(this + 0x2e0);
    ArResourceManager::GetChannelValue(aAStack_bc);
    iStack_60 = 1;
    bVar1 = std::operator!=(psStack_5c,(string *)aAStack_bc);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      psStack_64 = (string *)(this + 0x2e0);
      ArResourceManager::GetChannelValue(aAStack_c0);
      iStack_68 = 1;
      cVar2 = std::operator==(psStack_64,(string *)aAStack_c0);
      if ((cVar2 != '\x01') || (this[0x2e4] == (SourceSetupFrame)0x0)) goto LAB_00f0c608;
    }
    iVar4 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 400));
    if (iVar4 != 1) goto LAB_00f0c608;
    ArTvManager::getInstance();
    iVar4 = ArTvManager::GetCurrentDvbAntennaType();
    if (iVar4 != 1) goto LAB_00f0c608;
    iStack_58 = 1;
  }
  else {
LAB_00f0c608:
    iStack_58 = 0;
  }
  iStack_54 = iStack_58;
  if (iStack_68 != 0) {
                    /* try { // try from 00f0c68c to 00f0c693 has its CatchHandler @ 00f0c6ac */
    std::string::~string((string *)aAStack_c0);
  }
  if (iStack_60 != 0) {
    std::string::~string((string *)aAStack_bc);
  }
  if (iStack_54 != 0) {
    NumberEdit::Clear();
    NumberEdit::SetRightToLeftFlag();
    ArScanManager::getInstance();
    ArScanManager::PlayCurrentProgram();
  }
LAB_00f0c78c:
  if (((PopUpManager::popupID == 0x2d) || (PopUpManager::popupID == 0x2f)) ||
     (PopUpManager::popupID == 0x2e)) {
    PopUpManager::ClosePopUp();
  }
  if (PopUpManager::popupID != 0x32) {
    uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::openMenu(uVar3,'\0',(void *)0x0);
    return 1;
  }
  return 1;
}

