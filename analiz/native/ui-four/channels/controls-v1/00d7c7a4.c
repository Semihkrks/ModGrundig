
/* IdleAppFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
IdleAppFrame::OnKey(IdleAppFrame *this,void *param_1,void *param_2,void *param_3)

{
  bool bVar1;
  char cVar2;
  uchar uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  ArTvManager *pAVar7;
  char *pcVar8;
  ArVideoManager *pAVar9;
  int *piVar10;
  ArChannelManager *pAVar11;
  uint uVar12;
  ArCecController *this_00;
  int iVar13;
  ArProgramInfoFrame *this_01;
  undefined4 uVar14;
  ArTvPlayer *pAVar15;
  MS_FACTORY_SOURCE_SETTINGS *pMVar16;
  ulong uVar17;
  ArScreenCaptureManager *this_02;
  char cStack_6e0;
  byte bStack_6d4;
  byte bStack_6bc;
  undefined4 uStack_618;
  allocator aaStack_5f0 [4];
  string asStack_5ec [4];
  string asStack_5e8 [4];
  string asStack_5e4 [4];
  allocator aaStack_5e0 [4];
  string asStack_5dc [4];
  allocator aaStack_5d8 [4];
  string asStack_5d4 [4];
  allocator aaStack_5d0 [4];
  string asStack_5cc [4];
  vector<std::string,std::allocator<std::string>> avStack_5c8 [12];
  uint uStack_5bc;
  string asStack_5a0 [4];
  undefined1 auStack_59c [96];
  uint uStack_53c;
  ostringstream aoStack_538 [2];
  ushort uStack_536;
  byte bStack_534;
  undefined4 uStack_528;
  char cStack_24b;
  int iStack_1f0;
  int *piStack_1ec;
  int iStack_1e8;
  int *piStack_1e4;
  int iStack_1e0;
  int *piStack_1dc;
  int iStack_1d8;
  undefined4 uStack_1d4;
  int iStack_1d0;
  int *piStack_1cc;
  DMPlayerApp *pDStack_1c8;
  DMPlayerApp *pDStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  ToolsMenuApp *pTStack_1b8;
  ToolsMenuApp *pTStack_1b4;
  ThreeDSelectMenuApp *pTStack_1b0;
  ThreeDSelectMenuApp *pTStack_1ac;
  DMPlayerApp *pDStack_1a8;
  DMPlayerApp *pDStack_1a4;
  int iStack_1a0;
  int *piStack_19c;
  int iStack_198;
  int *piStack_194;
  int iStack_190;
  int iStack_18c;
  int *piStack_188;
  int iStack_184;
  int iStack_180;
  int *piStack_17c;
  int iStack_178;
  int *piStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  int *piStack_15c;
  ScreenCaptureApp *pSStack_158;
  int iStack_154;
  int *piStack_150;
  int iStack_14c;
  int iStack_148;
  int *piStack_144;
  MessageBoxApp *pMStack_140;
  MessageBoxApp *pMStack_13c;
  int iStack_138;
  int *piStack_134;
  uint uStack_130;
  ProgramGuideApp *pPStack_12c;
  ProgramGuideApp *pPStack_128;
  MessageBoxApp *pMStack_124;
  MessageBoxApp *pMStack_120;
  HotkeyControlApp *pHStack_11c;
  ChannelControlApp *pCStack_118;
  ChannelControlApp *pCStack_114;
  undefined4 uStack_110;
  MessageBoxApp *pMStack_10c;
  MessageBoxApp *pMStack_108;
  int iStack_104;
  KeypadMenuApp *pKStack_100;
  KeypadMenuApp *pKStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  int *piStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int *piStack_dc;
  int iStack_d8;
  int iStack_d4;
  ZappMenuApp *pZStack_d0;
  int iStack_cc;
  int *piStack_c8;
  FavoriteSelectionApp *pFStack_c4;
  int iStack_c0;
  MessageBoxApp *pMStack_bc;
  MessageBoxApp *pMStack_b8;
  MessageBoxApp *pMStack_b4;
  MessageBoxApp *pMStack_b0;
  ArChannelListApp *pAStack_ac;
  int iStack_a8;
  MenuBackgroundApp *pMStack_a4;
  MenuBackgroundApp *pMStack_a0;
  MenuBackgroundApp *pMStack_9c;
  int iStack_98;
  int iStack_94;
  undefined4 uStack_90;
  InputSourceSelectApp *pIStack_8c;
  InputSourceSelectApp *pIStack_88;
  int iStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int *piStack_70;
  int iStack_6c;
  int *piStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  string *psStack_58;
  string *psStack_54;
  string *psStack_50;
  int iStack_4c;
  PictureFormatApp *pPStack_48;
  int iStack_44;
  undefined4 uStack_40;
  ToolsMenuApp *pTStack_3c;
  ToolsMenuApp *pTStack_38;
  int iStack_34;
  void *pvStack_28;
  void *pvStack_24;
  int iStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  void *pvStack_14;
  
  piVar4 = (int *)MSrv_Control::GetInstance();
  iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
  piVar4 = (int *)MSrv_Control::GetInstance();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x9c))(piVar4,iVar5);
  if (piVar4 == (int *)0x0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xaed);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar6 = (**(code **)(*piVar4 + 0x78))(piVar4);
  if (iVar6 == 0) {
    if (param_2 == (void *)0xf04f) {
      ArServiceSettingsManager::getInstance();
      iVar6 = ArServiceSettingsManager::ArTvConf_GetRemoteControl();
      if (iVar6 != 4) goto LAB_00d7c920;
      iStack_34 = 1;
    }
    else {
LAB_00d7c920:
      iStack_34 = 0;
    }
    if (iStack_34 != 0) {
      pTStack_38 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
      if (pTStack_38 != (ToolsMenuApp *)0x0) {
                    /* try { // try from 00d7c960 to 00d7c967 has its CatchHandler @ 00d7c97c */
        ToolsMenuApp::ToolsMenuApp(pTStack_38);
      }
      pTStack_3c = pTStack_38;
      if (pTStack_38 != (ToolsMenuApp *)0x0) {
        MApplet::Run((ulong)pTStack_38,(void *)0x0);
        return 1;
      }
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xaf5);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    if (param_2 == (void *)0xf590) {
      ArServiceSettingsManager::getInstance();
      iVar6 = ArServiceSettingsManager::ArTvConf_GetRemoteControl();
      if (iVar6 != 4) goto LAB_00d7ca94;
      iStack_44 = 1;
    }
    else {
LAB_00d7ca94:
      iStack_44 = 0;
    }
    if (iStack_44 != 0) {
      pPStack_48 = operator_new(0x3c);
                    /* try { // try from 00d7cac4 to 00d7cacb has its CatchHandler @ 00d7caec */
      PictureFormatApp::PictureFormatApp(pPStack_48);
      if (pPStack_48 != (PictureFormatApp *)0x0) {
        MApplet::Run((ulong)pPStack_48,(void *)0x0);
        return 1;
      }
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xafc);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    if (param_2 == (void *)0xf203) {
      ArServiceSettingsManager::getInstance();
      iVar6 = ArServiceSettingsManager::ArTvConf_GetRemoteControl();
      if (iVar6 != 4) goto LAB_00d7cbe4;
      iStack_4c = 1;
    }
    else {
LAB_00d7cbe4:
      iStack_4c = 0;
    }
    if (iStack_4c != 0) {
      pAVar7 = (ArTvManager *)ArTvManager::getInstance();
      cVar2 = ArTvManager::GetCurrentInputSourceType(pAVar7);
      if (cVar2 == '\0') {
        std::vector<std::string,std::allocator<std::string>>::vector(avStack_5c8);
        uStack_618 = 0;
                    /* try { // try from 00d7cc4c to 00d7cc53 has its CatchHandler @ 00d7d11c */
        pcVar8 = (char *)GetRcEngine::RcGetString(0xc0f);
        std::allocator<char>::allocator();
                    /* try { // try from 00d7cc8c to 00d7cc93 has its CatchHandler @ 00d7cd90 */
        std::string::string(asStack_5cc,pcVar8,aaStack_5d0);
                    /* try { // try from 00d7ccac to 00d7ccb3 has its CatchHandler @ 00d7cd08 */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_5c8,asStack_5cc);
        psStack_50 = asStack_5cc;
                    /* try { // try from 00d7ccc8 to 00d7cccf has its CatchHandler @ 00d7cd90 */
        std::string::~string(psStack_50);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_5d0);
                    /* try { // try from 00d7ccf4 to 00d7ccfb has its CatchHandler @ 00d7d11c */
        pcVar8 = (char *)GetRcEngine::RcGetString(0xcdd);
        std::allocator<char>::allocator();
                    /* try { // try from 00d7cd7c to 00d7cd83 has its CatchHandler @ 00d7cec4 */
        std::string::string(asStack_5d4,pcVar8,aaStack_5d8);
                    /* try { // try from 00d7cde0 to 00d7cde7 has its CatchHandler @ 00d7ce3c */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_5c8,asStack_5d4);
        psStack_54 = asStack_5d4;
                    /* try { // try from 00d7cdfc to 00d7ce03 has its CatchHandler @ 00d7cec4 */
        std::string::~string(psStack_54);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_5d8);
                    /* try { // try from 00d7ce28 to 00d7ce2f has its CatchHandler @ 00d7d11c */
        pcVar8 = (char *)GetRcEngine::RcGetString(0xece);
        std::allocator<char>::allocator();
                    /* try { // try from 00d7ceb0 to 00d7ceb7 has its CatchHandler @ 00d7cfc8 */
        std::string::string(asStack_5dc,pcVar8,aaStack_5e0);
                    /* try { // try from 00d7cf14 to 00d7cf1b has its CatchHandler @ 00d7cf6c */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_5c8,asStack_5dc);
        psStack_58 = asStack_5dc;
                    /* try { // try from 00d7cf30 to 00d7cf37 has its CatchHandler @ 00d7cfc8 */
        std::string::~string(psStack_58);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_5e0);
                    /* try { // try from 00d7cf58 to 00d7cf5f has its CatchHandler @ 00d7d11c */
        iVar5 = ArChannelManager::GetFilterType();
        if (iVar5 == 1) {
          uStack_618 = 1;
        }
        else if (iVar5 == 2) {
          uStack_618 = 2;
        }
                    /* try { // try from 00d7d030 to 00d7d0f7 has its CatchHandler @ 00d7d11c */
        PopUpManager::Clean();
        pcVar8 = (char *)GetRcEngine::RcGetString(0xd59);
        std::string::operator=((string *)PopUpManager::itemSelectData,pcVar8);
        std::vector<std::string,std::allocator<std::string>>::operator=
                  ((vector<std::string,std::allocator<std::string>> *)
                   (PopUpManager::itemSelectData + 8),(vector *)avStack_5c8);
        PopUpManager::itemSelectData._4_4_ = uStack_618;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::popupID = 0x2a;
        PopUpManager::parentFrame = this;
        PopUpManager::ShowButton(0xe,0xc42);
        PopUpManager::ShowButton(7,0xf37);
        PopUpManager::Summon(1);
        std::vector<std::string,std::allocator<std::string>>::~vector(avStack_5c8);
      }
      else {
        PopUpManager::Clean();
        std::ostringstream::ostringstream(aoStack_538,0x10);
                    /* try { // try from 00d7d194 to 00d7d1d7 has its CatchHandler @ 00d7d2bc */
        pcVar8 = (char *)GetRcEngine::RcGetString(0x11d0);
        std::operator<<((ostream *)aoStack_538,pcVar8);
        std::ostringstream::str();
                    /* try { // try from 00d7d1f0 to 00d7d1f7 has its CatchHandler @ 00d7d260 */
        std::string::operator=((string *)((int)&PopUpManager::informationData + 4),asStack_5e4);
                    /* try { // try from 00d7d208 to 00d7d253 has its CatchHandler @ 00d7d2bc */
        std::string::~string(asStack_5e4);
        PopUpManager::informationData._0_4_ = 2;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::timeout = 2;
        PopUpManager::parentFrame = this;
        PopUpManager::Summon(0xb);
        std::ostringstream::~ostringstream(aoStack_538);
      }
      return 1;
    }
  }
  pAVar9 = (ArVideoManager *)ArVideoManager::getInstance();
  iVar6 = ArVideoManager::GetAppPIPState(pAVar9);
  if ((iVar6 == 1) && (param_2 == (void *)0xf062)) {
    iStack_5c = 1;
  }
  else {
    iStack_5c = 0;
  }
  if (iStack_5c != 0) {
    pAVar9 = (ArVideoManager *)ArVideoManager::getInstance();
    ArVideoManager::ToggleAppPIP(pAVar9);
    return 1;
  }
  piVar10 = (int *)MSrv_Control::GetInstance();
  iVar6 = (**(code **)(*piVar10 + 0x84))(piVar10);
  if (iVar6 == 0x1c) {
    iStack_64 = MSrv_Control_TV::GetMSrvDtv(0);
    if (iStack_64 == 0) {
      iStack_60 = 0;
    }
    else {
      iStack_60 = __dynamic_cast(iStack_64,&DAT_2da86f20,&DAT_2d5d5108,0);
    }
    if (iStack_60 == 0) {
      puts("player is null , this should not happened ");
    }
    else {
      iVar6 = MSrv_DTV_Player_DVB::GetHCTuneOperationStatus();
      if (iVar6 != 0) {
        puts("HC Tune Operation");
        iVar6 = IsKeySuitableForCAMControlledProgram((ulong)param_2);
        if (iVar6 == 0) {
          puts("request hc release");
          MSrv_DTV_Player_DVB::SetCiHcRelease();
          return 1;
        }
      }
    }
  }
  if ((((((this[0x1bc] == (IdleAppFrame)0x1) && (param_2 != (void *)0xf04c)) &&
        (param_2 != (void *)0xf04d)) && ((param_2 != (void *)0xf000 && (param_2 != (void *)0xf001)))
       ) && (param_2 != (void *)0xf002)) &&
     ((param_2 != (void *)0xf003 && (param_2 != (void *)0xf00f)))) {
    if (param_2 == (void *)0xf047) {
      pAVar11 = (ArChannelManager *)ArChannelManager::getInstance();
      iVar6 = ArChannelManager::IsNeighbourChannelRadio(pAVar11,'\x01');
      if (iVar6 == 0) {
        uVar3 = mapi_interface_common::Get_mapi_display();
        mapi_display::OnOff(uVar3);
        this[0x1bc] = (IdleAppFrame)0x0;
        MEvtHandle::KillTimer((ulong)this);
      }
    }
    else if (param_2 == (void *)0xf046) {
      pAVar11 = (ArChannelManager *)ArChannelManager::getInstance();
      iVar6 = ArChannelManager::IsNeighbourChannelRadio(pAVar11,'\x02');
      if (iVar6 == 0) {
        uVar3 = mapi_interface_common::Get_mapi_display();
        mapi_display::OnOff(uVar3);
        this[0x1bc] = (IdleAppFrame)0x0;
        MEvtHandle::KillTimer((ulong)this);
      }
    }
    else {
      uVar3 = mapi_interface_common::Get_mapi_display();
      mapi_display::OnOff(uVar3);
      this[0x1bc] = (IdleAppFrame)0x0;
      MEvtHandle::KillTimer((ulong)this);
    }
  }
  iStack_6c = MSrv_Control::GetInstance();
  if (iStack_6c == 0) {
    piStack_68 = (int *)0x0;
  }
  else {
    piStack_68 = (int *)__dynamic_cast(iStack_6c,&DAT_2eaccd60,&DAT_2f1e3470,0);
  }
  iVar6 = (**(code **)(*piStack_68 + 0x290))(piStack_68);
  if (iVar6 != 0) {
    iStack_74 = MSrv_Control::GetInstance();
    if (iStack_74 == 0) {
      piStack_70 = (int *)0x0;
    }
    else {
      piStack_70 = (int *)__dynamic_cast(iStack_74,&DAT_2eaccd60,&DAT_2f1e3470,0);
    }
    uVar12 = (**(code **)(*piStack_70 + 0x290))(piStack_70);
    printf("%s %d <#> u32Tag=0x%08lX keycode=0x%08lX\n",&UNK_01002370,0xc54,uVar12,param_2);
    if (param_2 == (void *)0xf042) {
      if ((uVar12 & 8) != 0) {
        piVar10 = (int *)mapi_interface_TV::Get_mapi_pcb();
        piVar10 = (int *)(**(code **)(*piVar10 + 0x18))(piVar10,0);
        (**(code **)(*piVar10 + 0x10))(piVar10,0x67,0);
      }
    }
    else if ((param_2 == (void *)0xf043) && ((uVar12 & 8) != 0)) {
      piVar10 = (int *)mapi_interface_TV::Get_mapi_pcb();
      piVar10 = (int *)(**(code **)(*piVar10 + 0x18))(piVar10,0);
      (**(code **)(*piVar10 + 0x10))(piVar10,0x68,0);
    }
  }
  uVar3 = mapi_video_customer::GetInstance();
  mapi_video_customer::ARapi_MegaDCRSetUserInput(uVar3);
  piVar10 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar10 + 0x154))(piVar10,auStack_59c);
  if ((((uStack_53c & 0xfff) >> 0xb == 1) && (iVar5 == 0x1c)) && (param_2 != (void *)0xf00f)) {
    return 1;
  }
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar6 = MSrv_System_Database::GetPowerStatus();
  if (((iVar6 == 0) && (param_2 != (void *)0xf00f)) && (param_2 != (void *)0xf550)) {
    return 1;
  }
  this_00 = (ArCecController *)ArCecController::getInstance();
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar6 = MSrv_System_Database::GetFactCecOn();
  if (iVar6 != 0) {
    iVar6 = ArCecController::GetSelectedDeviceSourceID();
    piVar10 = (int *)MSrv_Control::GetInstance();
    iVar13 = (**(code **)(*piVar10 + 0x84))(piVar10);
    if ((iVar6 == iVar13) && (iVar6 = ArCecController::IsCECInitCompleted(), iVar6 != 0)) {
      iStack_78 = 1;
    }
    else {
      iStack_78 = 0;
    }
    if ((((iStack_78 != 0) && (param_2 != (void *)0xf075)) && (param_2 != (void *)0xf04d)) &&
       ((param_2 != (void *)0xf04c && (param_2 != (void *)0xf04e)))) {
      ArCecController::ProccessUserRCInput(this_00,(ulong)param_2);
      iVar6 = ArCecController::IsRcKeyProcessedByCec();
      if (iVar6 != 0) {
        return 1;
      }
    }
  }
  MSrv_Control::GetInstance();
  iVar6 = MSrv_Control_DVB::IsSourceChanging();
  if (iVar6 == 1) {
    return 1;
  }
  ArTvPlayer::getInstance();
  iVar6 = ArTvPlayer::getTeletextKeyStatus();
  if ((iVar6 == 2) || (param_3 == (void *)0x1)) {
    iStack_7c = 1;
  }
  else {
    iStack_7c = 0;
  }
  if (iStack_7c != 0) {
    if (param_2 == (void *)0xf052) {
      bVar1 = false;
      bStack_6bc = 0;
      pvStack_28 = (void *)0xf052;
      while( true ) {
        piVar10 = (int *)MSrv_Control::GetInstance();
        uVar12 = (**(code **)(*piVar10 + 0x1bc))(piVar10);
        if (uVar12 <= bStack_6bc) {
          if (!bVar1) {
            pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
            iVar5 = ArTvPlayer::OpenTeletextPat(pAVar15);
            if (iVar5 != 0) {
              iVar5 = MuteControlFrame::GetMuteControlFrame();
              if (iVar5 != 0) {
                MuteControlFrame::GetMuteControlFrame();
                uVar17 = MWnd::GetParentApp();
                MApplet::Hide(uVar17);
              }
              if ((piVar4 == (int *)0x0) ||
                 (iVar5 = (**(code **)(*piVar4 + 0x78))(piVar4), iVar5 != 0)) {
                iStack_16c = 0;
              }
              else {
                iStack_16c = 1;
              }
              if (iStack_16c != 0) {
                pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
                ArTvPlayer::setTeletextKeyStatus(pAVar15,2);
                OnEvent_CHANGE_TTX_STATUS(this,(void *)0x0,(void *)0x0);
              }
            }
          }
          return 1;
        }
        piVar10 = (int *)MSrv_Control::GetInstance();
        iStack_168 = (**(code **)(*piVar10 + 0x1b4))(piVar10,bStack_6bc);
        if (iStack_168 == 0) {
          iStack_164 = 0;
        }
        else {
          iStack_164 = __dynamic_cast(iStack_168,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        if (iStack_164 == 0) break;
        iVar5 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
        if (iVar5 == 1) {
          bVar1 = true;
          PopUpManager::Clean();
          pcVar8 = (char *)GetRcEngine::RcGetString(0x11c7);
          std::string::operator=((string *)PopUpManager::yesNoBoxData,pcVar8);
          PopUpManager::yesNoBoxData._8_4_ = 1000;
          PopUpManager::yesNoBoxData._12_4_ = 0x1b8;
          PopUpManager::yesNoBoxData._28_4_ = 1;
          pcVar8 = (char *)GetRcEngine::RcGetString(0xd41);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar8);
          pcVar8 = (char *)GetRcEngine::RcGetString(0xe39);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar8);
          pcVar8 = (char *)GetRcEngine::RcGetString(0x106c);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar8);
          PopUpManager::yesNoBoxData._4_4_ = 0;
          PopUpManager::ShowButton(0xe,0xc66);
          PopUpManager::handleBackInPopUp = 1;
          PopUpManager::timeout = 0;
          PopUpManager::popupID = 0x40;
          PopUpManager::parentFrame = this;
          PopUpManager::Summon(3);
        }
        bStack_6bc = bStack_6bc + 1;
      }
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x1204);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    pvStack_28 = param_2;
    if (param_2 < (void *)0xf053) {
      if (param_2 == (void *)0xf017) {
        pAVar7 = (ArTvManager *)ArTvManager::getInstance();
        iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
        if (iVar5 == 1) {
          OpenDualWatchWarningPopup(this);
          return 1;
        }
        ArServiceSettingsManager::getInstance();
        iVar5 = ArServiceSettingsManager::ArSourceConf_GetUsbAvailable();
        if (iVar5 == 0) {
          return 1;
        }
        bVar1 = false;
        bStack_6d4 = 0;
        do {
          piVar4 = (int *)MSrv_Control::GetInstance();
          uVar12 = (**(code **)(*piVar4 + 0x1bc))(piVar4);
          if (uVar12 <= bStack_6d4) {
LAB_00d8336c:
            if (!bVar1) {
              if (DMPlayerFrame::MMBrowser == 0) {
                pDStack_1c4 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
                if (pDStack_1c4 != (DMPlayerApp *)0x0) {
                    /* try { // try from 00d833b8 to 00d833bf has its CatchHandler @ 00d833d4 */
                  DMPlayerApp::DMPlayerApp(pDStack_1c4);
                }
                pDStack_1c8 = pDStack_1c4;
                if (pDStack_1c4 == (DMPlayerApp *)0x0) {
                  printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x13ee);
                    /* WARNING: Subroutine does not return */
                  abort();
                }
                MApplet::Run((ulong)pDStack_1c4,(void *)0x0);
              }
              else {
                ShowInformationPopup(this,2,'\x01',0x46,2);
              }
            }
            return 1;
          }
          piVar4 = (int *)MSrv_Control::GetInstance();
          iStack_1c0 = (**(code **)(*piVar4 + 0x1b4))(piVar4,bStack_6d4);
          if (iStack_1c0 == 0) {
            iStack_1bc = 0;
          }
          else {
            iStack_1bc = __dynamic_cast(iStack_1c0,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          if (iStack_1bc == 0) {
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x13d8);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          iVar5 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
          if (iVar5 == 1) {
            bVar1 = true;
            goto LAB_00d8336c;
          }
          bStack_6d4 = bStack_6d4 + 1;
        } while( true );
      }
      if (param_2 < (void *)0xf018) {
        if (param_2 != (void *)0xf005) {
          if (param_2 < (void *)0xf006) {
            if (param_2 == (void *)0xf000) {
              ArPIPManager::getInstance();
              iVar5 = ArPIPManager::isPipSupported();
              if (iVar5 != 0) {
                ArPIPManager::getInstance();
                iVar5 = ArPIPManager::isPipRunning();
                if (iVar5 != 0) {
                  piVar4 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
                  (**(code **)(*piVar4 + 0x1f0))(piVar4,aoStack_538);
                  uStack_f4 = uStack_528;
                  uVar3 = ArPIPManager::getInstance();
                  ArPIPManager::setPipSubWindowPosition(uVar3);
                  return 1;
                }
              }
LAB_00d7fc6c:
              ArPIPManager::getInstance();
              iVar5 = ArPIPManager::isPipSupported();
              if (iVar5 != 0) {
                ArPIPManager::getInstance();
                iVar5 = ArPIPManager::isPipRunning();
                if (iVar5 != 0) {
                  piVar4 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
                  (**(code **)(*piVar4 + 0x1f0))(piVar4,aoStack_538);
                  uStack_f8 = uStack_528;
                  uVar3 = ArPIPManager::getInstance();
                  ArPIPManager::setPipSubWindowPosition(uVar3);
                  return 1;
                }
              }
              if (param_2 == (void *)0xf000) {
                MEvtHandle::PostEvent((MEvtHandle *)this,0,0x14,0xf04d);
              }
              else if (param_2 == (void *)0xf001) {
                MEvtHandle::PostEvent((MEvtHandle *)this,0,0x14,0xf04c);
              }
              return 1;
            }
            if ((void *)0xf000 < param_2) {
              if (param_2 == (void *)0xf002) {
                ArPIPManager::getInstance();
                iVar6 = ArPIPManager::isPipSupported();
                if (iVar6 != 0) {
                  ArPIPManager::getInstance();
                  iVar6 = ArPIPManager::isPipRunning();
                  if (iVar6 != 0) {
                    if (bRam010d7bc0 < 2) {
                      bRam010d7bc0 = bRam010d7bc0 + 1;
                      uVar3 = ArPIPManager::getInstance();
                      ArPIPManager::setPipSubWindowSize(uVar3);
                      return 1;
                    }
                    return 1;
                  }
                }
                goto LAB_00d7f4d0;
              }
              if ((void *)0xf001 < param_2) {
                if (param_2 != (void *)0xf003) {
                  return 0;
                }
                ArPIPManager::getInstance();
                iVar6 = ArPIPManager::isPipSupported();
                if (iVar6 != 0) {
                  ArPIPManager::getInstance();
                  iVar6 = ArPIPManager::isPipRunning();
                  if (iVar6 != 0) {
                    if (bRam010d7bc0 != 0) {
                      bRam010d7bc0 = bRam010d7bc0 - 1;
                      uVar3 = ArPIPManager::getInstance();
                      ArPIPManager::setPipSubWindowSize(uVar3);
                      return 1;
                    }
                    return 1;
                  }
                }
                goto LAB_00d7f848;
              }
              goto LAB_00d7fc6c;
            }
            if (param_2 != (void *)0xd) {
              if (param_2 < (void *)0xd) {
                return 0;
              }
              if (9 < (int)param_2 - 0x30U) {
                return 0;
              }
              pMVar16 = (MS_FACTORY_SOURCE_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
              MSrv_System_Database::GetFactorySourceSetting(pMVar16);
              if ((((uStack_5bc & 0x3ffff) >> 0x11 == 0) && ((uStack_5bc & 0x7ffff) >> 0x12 == 0))
                 && ((uStack_5bc & 0xfffff) >> 0x13 == 0)) {
                uStack_110 = 0;
              }
              else {
                uStack_110 = 1;
              }
              if ((char)uStack_110 != '\0') {
                MWidget::Hide();
                MWidget::Hide();
                MWidget::ForceUpdate();
                MWidget::ForceUpdate();
                uVar17 = MWnd::GetParentApp();
                MApplet::Hide(uVar17);
                pCStack_114 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
                if (pCStack_114 != (ChannelControlApp *)0x0) {
                    /* try { // try from 00d8076c to 00d80773 has its CatchHandler @ 00d80788 */
                  ChannelControlApp::ChannelControlApp(pCStack_114);
                }
                pCStack_118 = pCStack_114;
                if (pCStack_114 == (ChannelControlApp *)0x0) {
                  printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xfbf);
                    /* WARNING: Subroutine does not return */
                  abort();
                }
                MApplet::Run((ulong)pCStack_114,(void *)0x0);
                MEvtHandle::PostEvent((MEvtHandle *)this,0,0x14,(ulong)param_2);
              }
              return 1;
            }
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetCurrentInputSourceType(pAVar7);
            if (iVar5 != 0) {
              pAVar7 = (ArTvManager *)ArTvManager::getInstance();
              iVar5 = ArTvManager::GetCurrentInputSourceType(pAVar7);
              if (iVar5 != 1) {
                iStack_a8 = 0;
                goto LAB_00d7ea18;
              }
            }
            iStack_a8 = 1;
LAB_00d7ea18:
            if (iStack_a8 != 0) {
              pAStack_ac = operator_new(0x3c);
                    /* try { // try from 00d7ea44 to 00d7ea4b has its CatchHandler @ 00d7ea6c */
              ArChannelListApp::ArChannelListApp(pAStack_ac);
              if (pAStack_ac == (ArChannelListApp *)0x0) {
                printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xdb6);
                    /* WARNING: Subroutine does not return */
                abort();
              }
              MApplet::Run((ulong)pAStack_ac,(void *)0x1000);
            }
            return 1;
          }
          if (param_2 != (void *)0xf00a) {
            if (param_2 < (void *)0xf00b) {
              if (param_2 == (void *)0xf007) {
                return 0;
              }
              if ((void *)0xf006 < param_2) {
                if (param_2 != (void *)0xf008) {
                  return 0;
                }
                return 0;
              }
              return 0;
            }
            if (param_2 == (void *)0xf011) {
              pTStack_1b4 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
              if (pTStack_1b4 != (ToolsMenuApp *)0x0) {
                    /* try { // try from 00d8308c to 00d83093 has its CatchHandler @ 00d830a8 */
                ToolsMenuApp::ToolsMenuApp(pTStack_1b4);
              }
              pTStack_1b8 = pTStack_1b4;
              if (pTStack_1b4 != (ToolsMenuApp *)0x0) {
                MApplet::Run((ulong)pTStack_1b4,(void *)0x0);
                return 1;
              }
              printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x13be);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            if (param_2 < (void *)0xf012) {
              if (param_2 != (void *)0xf00f) {
                return 0;
              }
              FUN_00d66914(aoStack_538);
                    /* try { // try from 00d81098 to 00d81307 has its CatchHandler @ 00d81328 */
              ArChannelManager::getInstance();
              iVar5 = ArChannelManager::GetCurrentChannelInfo((ChannelInfo *)aoStack_538,'\0');
              if (iVar5 != 0) {
                uStack_130 = (uint)uStack_536;
                uVar14 = std::string::c_str();
                printf("\n\n\n Current Channel Info : %d   name %s \n\n\n",uStack_130,uVar14);
                printf("\n ======> Service for Powersaving mode : %d \n",(uint)bStack_534);
                piVar4 = (int *)MSrv_Control_common::GetMSrvTimer();
                iVar5 = (**(code **)(*piVar4 + 0x6c))(piVar4);
                if (((iVar5 == 0) && (this[0x1bc] == (IdleAppFrame)0x0)) && (bStack_534 == 2)) {
                  MWidget::Hide();
                  PopUpManager::Clean();
                  pcVar8 = (char *)GetRcEngine::RcGetString(0xeb9);
                  std::string::operator=((string *)PopUpManager::yesNoBoxData,pcVar8);
                  PopUpManager::yesNoBoxData._8_4_ = 0x4b0;
                  PopUpManager::yesNoBoxData._12_4_ = 500;
                  PopUpManager::yesNoBoxData._28_4_ = 1;
                  pcVar8 = (char *)GetRcEngine::RcGetString(0xebb);
                  std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar8);
                  pcVar8 = (char *)GetRcEngine::RcGetString(0xffc);
                  std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar8);
                  pcVar8 = (char *)GetRcEngine::RcGetString(0x106c);
                  std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar8);
                  PopUpManager::yesNoBoxData._4_4_ = 2;
                  PopUpManager::ShowButton(0xe,0xc66);
                  PopUpManager::handleBackInPopUp = 1;
                  PopUpManager::timeout = 10;
                  PopUpManager::popupID = 0x3e;
                  PopUpManager::parentFrame = this;
                  PopUpManager::Summon(3);
                  uStack_40 = 1;
                  goto LAB_00d81370;
                }
              }
              uStack_40 = 0;
LAB_00d81370:
              FUN_00d66628(aoStack_538);
              return uStack_40;
            }
            if (param_2 != (void *)0xf012) {
              if (param_2 != (void *)0xf014) {
                return 0;
              }
              piVar4 = (int *)MSrv_Control::GetInstance();
              iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
              if (iVar5 == 0x22) {
                return 1;
              }
              ArProgramInfoApp::Summon(1,'\x01','\x01');
              iVar5 = ArProgramInfoFrame::GetInstance();
              if (iVar5 != 0) {
                this_01 = (ArProgramInfoFrame *)ArProgramInfoFrame::GetInstance();
                ArProgramInfoFrame::OpenedByInfoKey(this_01);
              }
              return 1;
            }
            iStack_94 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_94 == 0) {
              uStack_90 = 0;
            }
            else {
              uStack_90 = __dynamic_cast(iStack_94,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            iVar5 = MSrv_DTV_Player_DVB::IsInCuProgress();
            if (iVar5 != 0) {
              puts("\n\n\nDebug- IdleAppFrame---- MVK_MENU is entered \n\n");
              return 1;
            }
            iVar5 = MenuBackgroundFrame::getMenuBackgroundFrame();
            if (iVar5 != 0) {
              return 1;
            }
            iVar5 = ArChannelManager::ControlAllRecordProcess();
            if (iVar5 == 0) {
              pAVar7 = (ArTvManager *)ArTvManager::getInstance();
              iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
              if (iVar5 == 0) {
                iStack_98 = 0;
                goto LAB_00d7e584;
              }
            }
            iStack_98 = 1;
LAB_00d7e584:
            if (iStack_98 == 0) {
              MenuBackgroundFrame::b_isMenuBGActive = 1;
              MWidget::Hide();
              MWidget::Hide();
              MWidget::ForceUpdate();
              MWidget::ForceUpdate();
              uVar17 = MWnd::GetParentApp();
              MApplet::Hide(uVar17);
              pMStack_a4 = operator_new(0x3c);
                    /* try { // try from 00d7e814 to 00d7e81b has its CatchHandler @ 00d7e83c */
              MenuBackgroundApp::MenuBackgroundApp(pMStack_a4);
              if (pMStack_a4 == (MenuBackgroundApp *)0x0) {
                printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xd8e);
                    /* WARNING: Subroutine does not return */
                abort();
              }
              MApplet::Run((ulong)pMStack_a4,(void *)0x1000);
            }
            else {
              MWidget::Hide();
              MWidget::Hide();
              MWidget::ForceUpdate();
              MWidget::ForceUpdate();
              uVar17 = MWnd::GetParentApp();
              MApplet::Hide(uVar17);
              pMStack_9c = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
              if (pMStack_9c != (MenuBackgroundApp *)0x0) {
                    /* try { // try from 00d7e670 to 00d7e677 has its CatchHandler @ 00d7e68c */
                MenuBackgroundApp::MenuBackgroundApp(pMStack_9c);
              }
              pMStack_a0 = pMStack_9c;
              if (pMStack_9c == (MenuBackgroundApp *)0x0) {
                printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xd78);
                    /* WARNING: Subroutine does not return */
                abort();
              }
              MApplet::Run((ulong)pMStack_9c,(void *)0x1000);
            }
            return 1;
          }
          if ((*(int *)(this + 0x200) != 0) && (*(int *)(this + 0x200) != 9)) {
            return 1;
          }
          ArServiceSettingsManager::getInstance();
          iVar5 = ArServiceSettingsManager::ArTvConf_GetScreenCapture();
          if (iVar5 == 1) {
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
            if ((iVar5 == 0) && (*(int *)(this + 0x200) != 9)) {
              iStack_14c = 1;
              goto LAB_00d817cc;
            }
          }
          iStack_14c = 0;
LAB_00d817cc:
          if (iStack_14c != 0) {
            iStack_154 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_154 == 0) {
              piStack_150 = (int *)0x0;
            }
            else {
              piStack_150 = (int *)__dynamic_cast(iStack_154,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            piVar4 = piStack_150;
            piVar10 = (int *)MSrv_Control::GetInstance();
            iVar5 = (**(code **)(*piVar10 + 0x84))(piVar10);
            ArServiceSettingsManager::getInstance();
            iVar6 = ArServiceSettingsManager::ArTvConf_GetUsbRecording();
            bVar1 = iVar6 == 0;
            if ((0 < iVar5) && (iVar5 < 0x1c)) {
              bVar1 = true;
            }
            if ((iVar5 == 0x1c) && (iVar5 = (**(code **)(*piVar4 + 0x56c))(piVar4), iVar5 == 0)) {
              bVar1 = true;
            }
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetCurrentInputSourceType(pAVar7);
            if (((iVar5 != 0) && (iVar5 != 5)) && (iVar5 != 0xc)) {
              bVar1 = false;
            }
            if (bVar1) {
              this_02 = (ArScreenCaptureManager *)ArScreenCaptureManager::getInstance();
              iVar5 = ArScreenCaptureManager::CheckSharingStatus(this_02);
              if (iVar5 == 0) {
                pSStack_158 = operator_new(0x3c);
                    /* try { // try from 00d819cc to 00d819d3 has its CatchHandler @ 00d819f4 */
                ScreenCaptureApp::ScreenCaptureApp(pSStack_158);
                if (pSStack_158 == (ScreenCaptureApp *)0x0) {
                  printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x1155);
                    /* WARNING: Subroutine does not return */
                  abort();
                }
                MApplet::Run((ulong)pSStack_158,(void *)0x0);
              }
              else {
                uVar14 = std::operator|(0x10,8);
                std::stringstream::stringstream((stringstream *)aoStack_538,uVar14);
                    /* try { // try from 00d81acc to 00d81af3 has its CatchHandler @ 00d81bc0 */
                PopUpManager::Clean();
                std::stringstream::str();
                    /* try { // try from 00d81b0c to 00d81b13 has its CatchHandler @ 00d81b64 */
                std::string::operator=
                          ((string *)((int)&PopUpManager::informationData + 4),asStack_5e8);
                    /* try { // try from 00d81b24 to 00d81b57 has its CatchHandler @ 00d81bc0 */
                std::string::~string(asStack_5e8);
                PopUpManager::informationData._0_4_ = 1;
                PopUpManager::timeout = 3;
                PopUpManager::Summon(0xb);
                std::stringstream::~stringstream((stringstream *)aoStack_538);
              }
              return 1;
            }
          }
          ArServiceSettingsManager::getInstance();
          iVar5 = ArServiceSettingsManager::ArTvConf_GetUsbRecording();
          if (iVar5 == 0) {
            return 1;
          }
          pAVar7 = (ArTvManager *)ArTvManager::getInstance();
          iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
          if (iVar5 == 1) {
            return 1;
          }
          piVar4 = (int *)MSrv_Control::GetInstance();
          iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
          if (iVar5 != 0x1c) {
            return 1;
          }
          iStack_160 = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_160 == 0) {
            piStack_15c = (int *)0x0;
          }
          else {
            piStack_15c = (int *)__dynamic_cast(iStack_160,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          this[0x1d8] = (IdleAppFrame)0x1;
          iVar5 = (**(code **)(*piStack_15c + 0x6c8))(piStack_15c,1,1,0);
          if (iVar5 == 1) {
            *(undefined4 *)(this + 0x1f8) = 0;
            _PVRCIPlusCamPinCode(this);
            puts("     _PVRCIPlusCamPinCode       ");
            return 1;
          }
          puts("     _CIPlusOperatoringModeCheck       ");
          _CIPlusOperatoringModeCheck(this,'\0',0);
          return 1;
        }
        pAVar7 = (ArTvManager *)ArTvManager::getInstance();
        iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
        if (iVar5 == 1) {
          OpenDualWatchWarningPopup(this);
          return 1;
        }
        piVar4 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
        iVar5 = (**(code **)(*piVar4 + 0x514))(piVar4,0xfe);
        if (iVar5 == 0) {
          iStack_198 = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_198 == 0) {
            piStack_194 = (int *)0x0;
          }
          else {
            piStack_194 = (int *)__dynamic_cast(iStack_198,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          iVar5 = (**(code **)(*piStack_194 + 0x520))(piStack_194,0xfe);
          if (iVar5 == 0) {
            iStack_1a0 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_1a0 == 0) {
              piStack_19c = (int *)0x0;
            }
            else {
              piStack_19c = (int *)__dynamic_cast(iStack_1a0,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            iVar5 = (**(code **)(*piStack_19c + 0x428))(piStack_19c);
            if (iVar5 == 0) {
              iStack_190 = 0;
              goto LAB_00d82b30;
            }
          }
        }
        iStack_190 = 1;
LAB_00d82b30:
        if (iStack_190 == 0) {
          pDStack_1a4 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
          if (pDStack_1a4 != (DMPlayerApp *)0x0) {
                    /* try { // try from 00d82b7c to 00d82b83 has its CatchHandler @ 00d82b98 */
            DMPlayerApp::DMPlayerApp(pDStack_1a4);
          }
          pDStack_1a8 = pDStack_1a4;
          if (pDStack_1a4 == (DMPlayerApp *)0x0) {
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x12fc);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          MApplet::Run((ulong)pDStack_1a4,(void *)0x0);
        }
        return 1;
      }
      if (param_2 == (void *)0xf042) {
        return 0;
      }
      if ((void *)0xf042 < param_2) {
        if (param_2 == (void *)0xf047) {
LAB_00d7f848:
          if (iVar5 == 0x1c) {
            iStack_e8 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_e8 == 0) {
              iStack_e4 = 0;
            }
            else {
              iStack_e4 = __dynamic_cast(iStack_e8,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            if (iStack_e4 != 0) {
              MSrv_DTV_Player_DVB::RecordProgChangeEvent(iStack_e4,0,0,0);
            }
          }
          iStack_f0 = MSrv_Control_common::GetMSrvSystemDatabase();
          if (iStack_f0 == 0) {
            piStack_ec = (int *)0x0;
          }
          else {
            piStack_ec = (int *)__dynamic_cast(iStack_f0,&DAT_2e5d1260,&DAT_2e5d17c0,0);
          }
          if (piStack_ec != (int *)0x0) {
            iVar5 = (**(code **)(*piStack_ec + 0x144))(piStack_ec);
            if (iVar5 == 1) {
              uVar14 = mapi_time_utility::GetTime0();
              printf("[%lu ms] [IdleAppFrame::OnKey] MVK_HANNEL_MINUS/MVKP_DOWN\n",uVar14);
            }
            puts("ArChannelManager::ChannelMinus\n\n");
            MWidget::Hide();
            MWidget::Hide();
            MWidget::ForceUpdate();
            MWidget::ForceUpdate();
            uVar17 = MWnd::GetParentApp();
            MApplet::Hide(uVar17);
            ArChannelManager::ChannelMinus();
            ManagePopUp(this,(void *)0x0,(void *)0x0);
            return 1;
          }
          printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xeb2);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if ((void *)0xf047 < param_2) {
          if ((void *)0xf04e < param_2) {
            if (param_2 != (void *)0xf051) {
              return 0;
            }
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
            if (iVar5 == 1) {
              return 1;
            }
            piVar4 = (int *)MSrv_Control::GetInstance();
            iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
            if (iVar5 == 0x1c) {
              MSrv_Control_TV::GetMSrvPVRBrowser();
              MW_PVRFileSystem::GetLastRecordFile();
                    /* try { // try from 00d81eec to 00d81fb7 has its CatchHandler @ 00d81fdc */
              iVar5 = std::string::size();
              if (iVar5 != 0) {
                uVar17 = MWnd::GetParentApp();
                MApplet::Hide(uVar17);
                this[0x1d7] = (IdleAppFrame)0x2;
                PVRApp::Summon(0,2,(IdleAppFrame *)0x0);
                iVar5 = PVRFrame::GetInstance();
                if (iVar5 == 0) {
                  puts(
                      "\n\n **************** PVRFrame cannot play this file most probably because of a CI+ issue. **************** \n"
                      );
                }
                else {
                  iVar5 = PVRFrame::GetInstance();
                  *(undefined1 *)(iVar5 + 0x2e8) = 1;
                }
              }
              std::string::~string(asStack_5a0);
            }
            return 1;
          }
          if ((void *)0xf04b < param_2) {
            return 0;
          }
          if (param_2 != (void *)0xf049) {
            return 0;
          }
          return 0;
        }
        if (param_2 == (void *)0xf044) {
          return 0;
        }
        if (param_2 < (void *)0xf044) {
          ArTvManager::GetSystemDatabase();
          iVar5 = MSrv_System_Database::GetFactNonConnectedMode();
          if (iVar5 == 1) {
            return 1;
          }
          MSrv_Control_common::GetMSrvSystemDatabase();
          iVar5 = MSrv_System_Database::GetFact3RdPartyPortalEnabled();
          if (iVar5 == 0) {
            iVar5 = IsScreenEmpty('\x01');
            if (iVar5 == 0) {
              return 1;
            }
          }
          else {
            iVar5 = IsScreenEmpty('\x01');
            if (iVar5 == 0) {
              return 1;
            }
          }
          return 1;
        }
        if (param_2 != (void *)0xf046) {
          return 0;
        }
LAB_00d7f4d0:
        if (iVar5 == 0x1c) {
          iStack_d8 = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_d8 == 0) {
            iStack_d4 = 0;
          }
          else {
            iStack_d4 = __dynamic_cast(iStack_d8,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          if (iStack_d4 != 0) {
            MSrv_DTV_Player_DVB::RecordProgChangeEvent(iStack_d4,0,0,0);
          }
        }
        iStack_e0 = MSrv_Control_common::GetMSrvSystemDatabase();
        if (iStack_e0 == 0) {
          piStack_dc = (int *)0x0;
        }
        else {
          piStack_dc = (int *)__dynamic_cast(iStack_e0,&DAT_2e5d1260,&DAT_2e5d17c0,0);
        }
        if (piStack_dc != (int *)0x0) {
          iVar5 = (**(code **)(*piStack_dc + 0x144))(piStack_dc);
          if (iVar5 == 1) {
            uVar14 = mapi_time_utility::GetTime0();
            printf("[%lu ms] [IdleAppFrame::OnKey] MVK_CHANNEL_PLUS/MVKP_UP\n",uVar14);
          }
          puts("\n ArChannelManager::ChannelPlus\n\n");
          MWidget::Hide();
          MWidget::Hide();
          MWidget::ForceUpdate();
          MWidget::ForceUpdate();
          uVar17 = MWnd::GetParentApp();
          MApplet::Hide(uVar17);
          ArChannelManager::ChannelPlus();
          ManagePopUp(this,(void *)0x0,(void *)0x0);
          return 1;
        }
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xe7c);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      if (param_2 == (void *)0xf022) {
LAB_00d80fc4:
        piVar4 = (int *)MSrv_Control::GetInstance();
        uVar14 = (**(code **)(*piVar4 + 0x84))(piVar4);
        piVar4 = (int *)MSrv_Control::GetInstance();
        piVar4 = (int *)(**(code **)(*piVar4 + 0x9c))(piVar4,uVar14);
        iVar5 = (**(code **)(*piVar4 + 0x4c))(piVar4);
        if (iVar5 == 0) {
          return 1;
        }
        return 0;
      }
      if ((void *)0xf022 < param_2) {
        if (param_2 != (void *)0xf037) {
          if (param_2 == (void *)0xf03a) {
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
            if (iVar5 == 1) {
              OpenDualWatchWarningPopup(this);
              return 1;
            }
            iVar5 = IsScreenEmpty('\0');
            if (iVar5 == 0) {
              return 1;
            }
            ArVideoManager::getInstance();
            iVar5 = ArVideoManager::Is3DSuitable();
            if (iVar5 == 0) {
              PopUpManager::Clean();
              pcVar8 = (char *)GetRcEngine::RcGetString(0x100a);
              std::string::operator=((string *)((int)&PopUpManager::informationData + 4),pcVar8);
              PopUpManager::informationData._0_4_ = 2;
              PopUpManager::handleBackInPopUp = 1;
              PopUpManager::timeout = 2;
              PopUpManager::parentFrame = this;
              PopUpManager::ShowButton(0xe,0xc66);
              PopUpManager::Summon(0xb);
            }
            else {
              pTStack_1ac = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
              if (pTStack_1ac != (ThreeDSelectMenuApp *)0x0) {
                    /* try { // try from 00d82ed4 to 00d82edb has its CatchHandler @ 00d82ef0 */
                ThreeDSelectMenuApp::ThreeDSelectMenuApp(pTStack_1ac);
              }
              pTStack_1b0 = pTStack_1ac;
              if (pTStack_1ac == (ThreeDSelectMenuApp *)0x0) {
                printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x13a9);
                    /* WARNING: Subroutine does not return */
                abort();
              }
              MApplet::Run((ulong)pTStack_1ac,(void *)0x0);
            }
            return 1;
          }
          if (param_2 != (void *)0xf026) {
            return 0;
          }
          ArTvManager::GetSystemDatabase();
          iVar5 = MSrv_System_Database::GetFactNonConnectedMode();
          if (iVar5 == 1) {
            return 1;
          }
          pcVar8 = (char *)GetRcEngine::RcGetString(0xd6f);
          std::allocator<char>::allocator();
                    /* try { // try from 00d83558 to 00d8355f has its CatchHandler @ 00d835fc */
          std::string::string(asStack_5ec,pcVar8,aaStack_5f0);
                    /* try { // try from 00d83574 to 00d8357b has its CatchHandler @ 00d835c0 */
          ArUIManager::ShowInformationPopup(asStack_5ec,0x59);
                    /* try { // try from 00d8358c to 00d83593 has its CatchHandler @ 00d835fc */
          std::string::~string(asStack_5ec);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_5f0);
          return 1;
        }
        goto LAB_00d80fc4;
      }
      if (param_2 == (void *)0xf01b) {
        pAVar7 = (ArTvManager *)ArTvManager::getInstance();
        iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
        if (iVar5 == 1) {
          OpenDualWatchWarningPopup(this);
          return 1;
        }
        iVar5 = ArChannelManager::IsAnySourceRecording();
        if (iVar5 != 0) {
          PopUpManager::Clean();
          PopUpManager::popupType = 3;
          pcVar8 = (char *)GetRcEngine::RcGetString(0x11c7);
          std::string::operator=((string *)PopUpManager::yesNoBoxData,pcVar8);
          PopUpManager::yesNoBoxData._4_4_ = 0x234;
          PopUpManager::yesNoBoxData._8_4_ = 1000;
          PopUpManager::yesNoBoxData._12_4_ = 0x1b8;
          PopUpManager::yesNoBoxData._28_4_ = 1;
          pcVar8 = (char *)GetRcEngine::RcGetString(0xd0e);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar8);
          pcVar8 = (char *)GetRcEngine::RcGetString(0xe39);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar8);
          pcVar8 = (char *)GetRcEngine::RcGetString(0x106c);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar8);
          PopUpManager::yesNoBoxData._4_4_ = 0;
          PopUpManager::handleBackInPopUp = 1;
          PopUpManager::timeout = 0;
          PopUpManager::parentFrame = this;
          PopUpManager::Summon(3);
          PopUpManager::popupID = 0x1a;
          return 1;
        }
        ArEpgManager::getInstance();
        iVar5 = ArEpgManager::CanStartEPG();
        if (iVar5 != 0) {
          uVar17 = MWnd::GetParentApp();
          MApplet::Hide(uVar17);
          pPStack_128 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
          if (pPStack_128 != (ProgramGuideApp *)0x0) {
                    /* try { // try from 00d80ecc to 00d80ed3 has its CatchHandler @ 00d80ee8 */
            ProgramGuideApp::ProgramGuideApp(pPStack_128);
          }
          pPStack_12c = pPStack_128;
          if (pPStack_128 == (ProgramGuideApp *)0x0) {
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x1057);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          MApplet::Run((ulong)pPStack_128,(void *)0x0);
        }
        return 1;
      }
      if (param_2 == (void *)0xf020) goto LAB_00d7eb10;
      if (param_2 != (void *)0xf019) {
        return 0;
      }
    }
    else {
      if (param_2 == (void *)0xf075) {
        iStack_cc = MSrv_Control_common::GetMSrvSystemDatabase();
        if (iStack_cc == 0) {
          piStack_c8 = (int *)0x0;
        }
        else {
          piStack_c8 = (int *)__dynamic_cast(iStack_cc,&DAT_2e5d1260,&DAT_2e5d17c0,0);
        }
        if (piStack_c8 != (int *)0x0) {
          iVar5 = (**(code **)(*piStack_c8 + 0x144))(piStack_c8);
          if (iVar5 == 1) {
            uVar14 = mapi_time_utility::GetTime0();
            printf("[%lu ms] [IdleAppFrame::OnKey] MVK_CHANNEL_RETURN\n",uVar14);
          }
          iVar5 = ZappMenuFrame::GetZappMenuFrame();
          if (iVar5 == 0) {
            pZStack_d0 = operator_new(0x3c);
                    /* try { // try from 00d7f24c to 00d7f253 has its CatchHandler @ 00d7f274 */
            ZappMenuApp::ZappMenuApp(pZStack_d0);
            if (pZStack_d0 != (ZappMenuApp *)0x0) {
              MApplet::Run((ulong)pZStack_d0,(void *)0x0);
              return 1;
            }
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xe42);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          piVar4 = (int *)MSrv_Control::GetInstance();
          iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
          if ((iVar5 == 1) || (iVar5 == 0x1c)) {
            piVar4 = (int *)MSrv_Control_common::GetMSrvChannelManager();
            iVar5 = (**(code **)(*piVar4 + 0x28))(piVar4);
            if (iVar5 == 0) {
              return 1;
            }
            ArProgramInfoApp::Summon(1,'\x01','\x01');
          }
          return 1;
        }
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xe35);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      if (param_2 < (void *)0xf076) {
        if (param_2 == (void *)0xf06b) {
          return 0;
        }
        if ((void *)0xf06b < param_2) {
          if (param_2 == (void *)0xf070) {
            piVar4 = (int *)MSrv_Control::GetInstance();
            iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
            if (iVar5 == 0x1c) {
              piVar4 = (int *)MSrv_Control::GetInstance();
              piVar4 = (int *)(**(code **)(*piVar4 + 0x9c))(piVar4,0x1c);
              iVar5 = (**(code **)(*piVar4 + 0x4c))(piVar4);
              if (iVar5 != 0) {
                uVar17 = MWnd::GetParentApp();
                MApplet::Hide(uVar17);
                AudioSubtitleSelectFrame::Summon(0);
              }
              return 1;
            }
            if (iVar5 != 1) {
              uVar17 = MWnd::GetParentApp();
              MApplet::Hide(uVar17);
              pMStack_120 = operator_new(0x40,(nothrow_t *)&DAT_2c7f5bd0);
              if (pMStack_120 != (MessageBoxApp *)0x0) {
                    /* try { // try from 00d80b70 to 00d80b77 has its CatchHandler @ 00d80b8c */
                MessageBoxApp::MessageBoxApp(pMStack_120);
              }
              pMStack_124 = pMStack_120;
              if (pMStack_120 != (MessageBoxApp *)0x0) {
                MApplet::Run((ulong)pMStack_120,(void *)0x32);
                return 1;
              }
              printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x100d);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            piVar4 = (int *)MSrv_Control::GetInstance();
            piVar4 = (int *)(**(code **)(*piVar4 + 0x9c))(piVar4,1);
            iVar5 = (**(code **)(*piVar4 + 0x4c))(piVar4);
            if (iVar5 == 0) {
              return 1;
            }
            uVar17 = MWnd::GetParentApp();
            MApplet::Hide(uVar17);
            pHStack_11c = operator_new(0x3c);
                    /* try { // try from 00d80a44 to 00d80a4b has its CatchHandler @ 00d80a6c */
            HotkeyControlApp::HotkeyControlApp(pHStack_11c);
            if (pHStack_11c != (HotkeyControlApp *)0x0) {
              MApplet::Run((ulong)pHStack_11c,(void *)0x1000);
              return 1;
            }
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x1004);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          if (param_2 < (void *)0xf071) {
            if (param_2 == (void *)0xf06d) {
              pAVar7 = (ArTvManager *)ArTvManager::getInstance();
              iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
              if (iVar5 == 1) {
                OpenDualWatchWarningPopup(this);
                return 1;
              }
              StartConnectedApp(this,2);
              return 1;
            }
            if ((void *)0xf06c < param_2) {
              if (param_2 == (void *)0xf06f) {
                return 0;
              }
              return 0;
            }
            piVar4 = (int *)MSrv_Control::GetInstance();
            iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
            if (iVar5 == 0x1c) {
              iStack_138 = MSrv_Control_TV::GetMSrvDtv(0);
              if (iStack_138 == 0) {
                piStack_134 = (int *)0x0;
              }
              else {
                piStack_134 = (int *)__dynamic_cast(iStack_138,&DAT_2da86f20,&DAT_2d5d5108,0);
              }
              iVar5 = (**(code **)(*piStack_134 + 0x56c))(piStack_134);
              if (iVar5 == 0) {
                pMStack_13c = operator_new(0x40,(nothrow_t *)&DAT_2c7f5bd0);
                if (pMStack_13c != (MessageBoxApp *)0x0) {
                    /* try { // try from 00d81498 to 00d8149f has its CatchHandler @ 00d814b4 */
                  MessageBoxApp::MessageBoxApp(pMStack_13c);
                }
                pMStack_140 = pMStack_13c;
                if (pMStack_13c == (MessageBoxApp *)0x0) {
                  printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x10f3);
                    /* WARNING: Subroutine does not return */
                  abort();
                }
                MApplet::Run((ulong)pMStack_13c,(void *)0x0);
              }
            }
            return 1;
          }
          if (param_2 < (void *)0xf074) {
            if (param_2 < (void *)0xf072) {
              return 0;
            }
            return 0;
          }
          goto LAB_00d80fc4;
        }
        if (param_2 == (void *)0xf062) {
          ArPIPManager::getInstance();
          iVar5 = ArPIPManager::isPipSupported();
          if (iVar5 == 0) {
            return 0;
          }
          ArPIPManager::getInstance();
          iVar5 = ArPIPManager::isPipRunning();
          if (iVar5 == 0) {
            return 0;
          }
          ArPIPManager::getInstance();
          ArPIPManager::setPipOff();
          return 1;
        }
        if ((void *)0xf062 < param_2) {
          if (param_2 == (void *)0xf069) {
            ArServiceSettingsManager::getInstance();
            iVar5 = ArServiceSettingsManager::ArTvConf_GetRemoteControl();
            if (iVar5 == 1) {
              MEvtHandle::PostEvent((MEvtHandle *)this,(ulong)this,0x14,0xf026);
            }
            return 1;
          }
          if ((void *)0xf069 < param_2) {
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
            if (iVar5 == 1) {
              OpenDualWatchWarningPopup(this);
              return 1;
            }
            pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
            iVar5 = ArTvPlayer::OpenTeletext(pAVar15);
            if (iVar5 != 0) {
              ArTvPlayer::getInstance();
              iVar5 = ArTvPlayer::getTeletextKeyStatus();
              if (iVar5 == 0) {
                iVar5 = MuteControlFrame::GetMuteControlFrame();
                if (iVar5 != 0) {
                  MuteControlFrame::GetMuteControlFrame();
                  uVar17 = MWnd::GetParentApp();
                  MApplet::Hide(uVar17);
                }
                iVar5 = ZappMenuFrame::GetZappMenuFrame();
                if (iVar5 != 0) {
                  ZappMenuFrame::GetZappMenuFrame();
                  uVar17 = MWnd::GetParentApp();
                  MApplet::Hide(uVar17);
                }
                uVar17 = MWnd::GetParentApp();
                MApplet::Hide(uVar17);
              }
              return 1;
            }
            ArTvPlayer::getInstance();
            iVar5 = ArTvPlayer::isValidTeletextSource();
            if (iVar5 != 0) {
              PopUpManager::Clean();
              pcVar8 = (char *)GetRcEngine::RcGetString(0xe36);
              std::string::operator=((string *)((int)&PopUpManager::informationData + 4),pcVar8);
              PopUpManager::informationData._0_4_ = 0;
              PopUpManager::handleBackInPopUp = 1;
              PopUpManager::timeout = 2;
              PopUpManager::parentFrame = (IdleAppFrame *)GetIdleAppFrame();
              PopUpManager::Summon(0xb);
            }
            return 1;
          }
          if (param_2 != (void *)0xf068) {
            return 0;
          }
          iStack_84 = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_84 == 0) {
            uStack_80 = 0;
          }
          else {
            uStack_80 = __dynamic_cast(iStack_84,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          iVar5 = MSrv_DTV_Player_DVB::IsInCuProgress();
          if (iVar5 == 0) {
            pAVar7 = (ArTvManager *)ArTvManager::getInstance();
            iVar5 = ArTvManager::GetDualWatchStatus(pAVar7);
            if (iVar5 == 1) {
              return 1;
            }
            pIStack_88 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
            if (pIStack_88 != (InputSourceSelectApp *)0x0) {
                    /* try { // try from 00d7e354 to 00d7e35b has its CatchHandler @ 00d7e370 */
              InputSourceSelectApp::InputSourceSelectApp(pIStack_88);
            }
            pIStack_8c = pIStack_88;
            if (pIStack_88 != (InputSourceSelectApp *)0x0) {
              MApplet::Run((ulong)pIStack_88,(void *)0x0);
              uVar17 = MWnd::GetParentApp();
              MApplet::Hide(uVar17);
              return 1;
            }
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xd4e);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          puts("\n\n\nDebug- IdleAppFrame ---- MVK_INPUT_SOURCE is entered \n\n");
          return 1;
        }
        if (param_2 != (void *)0xf05b) {
          if (param_2 == (void *)0xf05c) {
            return 0;
          }
          if (param_2 != (void *)0xf056) {
            return 0;
          }
          ArServiceSettingsManager::getInstance();
          iVar5 = ArServiceSettingsManager::ArTvConf_GetUsbRecording();
          if (iVar5 == 0) {
            return 1;
          }
          piVar4 = (int *)MSrv_Control::GetInstance();
          iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
          if (iVar5 == 0x1c) {
            iStack_148 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_148 == 0) {
              piStack_144 = (int *)0x0;
            }
            else {
              piStack_144 = (int *)__dynamic_cast(iStack_148,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            this[0x1d8] = (IdleAppFrame)0x0;
            iVar5 = (**(code **)(*piStack_144 + 0x6c8))(piStack_144,1,1,0);
            if (iVar5 == 1) {
              *(undefined4 *)(this + 0x1f8) = 0;
              _PVRCIPlusCamPinCode(this);
              return 1;
            }
            _CIPlusOperatoringModeCheck(this,'\0',0);
            return 1;
          }
          return 1;
        }
        piVar4 = (int *)MSrv_Control::GetInstance();
        iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
        if (iVar5 == 0x1c) {
          iStack_178 = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_178 == 0) {
            piStack_174 = (int *)0x0;
          }
          else {
            piStack_174 = (int *)__dynamic_cast(iStack_178,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          iVar5 = (**(code **)(*piStack_174 + 0x428))(piStack_174);
          if (iVar5 != 0) {
            iStack_170 = 1;
            goto LAB_00d824fc;
          }
        }
        iStack_170 = 0;
LAB_00d824fc:
        if (iStack_170 != 0) {
          _PVRFrameSendKey(this,0xf05b);
          return 1;
        }
        piVar4 = (int *)MSrv_Control::GetInstance();
        iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
        if (iVar5 != 0x1c) {
          return 0;
        }
        piVar4 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
        (**(code **)(*piVar4 + 0xd0))(piVar4,aoStack_538);
        if (cStack_24b != '\x01') {
          return 0;
        }
        iStack_180 = MSrv_Control_TV::GetMSrvDtv(0);
        if (iStack_180 == 0) {
          piStack_17c = (int *)0x0;
        }
        else {
          piStack_17c = (int *)__dynamic_cast(iStack_180,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        uVar14 = (**(code **)(*piStack_17c + 0x3f4))(piStack_17c,0xffff,0);
        DoRecordStartUI(this,uVar14,1,1,0,4);
        return 0;
      }
      if (param_2 == (void *)0xf203) {
        return 0;
      }
      if ((void *)0xf203 < param_2) {
        if (param_2 < (void *)0xf555) {
          if ((void *)0xf552 < param_2) {
            return 0;
          }
          if (param_2 == (void *)0xf550) {
            return 0;
          }
          if (param_2 < (void *)0xf550) {
            return 0;
          }
          ArServiceSettingsManager::getInstance();
          iVar5 = ArServiceSettingsManager::ArTvConf_GetKeypad();
          if (iVar5 == 0) {
            iVar5 = ArResourceManager::GetKeypadNavigationStyle();
            if (iVar5 != 0) {
              if (param_2 == (void *)0xf551) {
                VolumeControlApp::Summon(0xff,0xf04c);
              }
              else {
                VolumeControlApp::Summon(0xff,0xf04d);
              }
              return 1;
            }
            if (param_2 == (void *)0xf551) {
              uVar14 = OnKey(this,(void *)0x0,(void *)0xf046,(void *)0x1);
              return uVar14;
            }
            uVar14 = OnKey(this,(void *)0x0,(void *)0xf047,(void *)0x1);
            return uVar14;
          }
          if (param_2 == (void *)0xf551) {
            uVar14 = OnKey(this,(void *)0x0,(void *)0xf046,(void *)0x1);
            return uVar14;
          }
          uVar14 = OnKey(this,(void *)0x0,(void *)0xf047,(void *)0x1);
          return uVar14;
        }
        if (param_2 == (void *)0xf556) {
          iVar5 = IsScreenEmpty('\x01');
          if (iVar5 == 0) {
            return 1;
          }
          pKStack_fc = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
          if (pKStack_fc != (KeypadMenuApp *)0x0) {
                    /* try { // try from 00d7fee8 to 00d7feef has its CatchHandler @ 00d7ff04 */
            KeypadMenuApp::KeypadMenuApp(pKStack_fc);
          }
          pKStack_100 = pKStack_fc;
          if (pKStack_fc != (KeypadMenuApp *)0x0) {
            MApplet::Run((ulong)pKStack_fc,(void *)0x0);
            return 0;
          }
          printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xf21);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if (param_2 < (void *)0xf556) {
          return 0;
        }
        if (param_2 == (void *)0xf557) {
          return 0;
        }
        return 0;
      }
      if (param_2 == (void *)0xf079) {
        return 0;
      }
      if ((void *)0xf079 < param_2) {
        if (param_2 == (void *)0xf07c) {
          piVar4 = (int *)MSrv_Control::GetInstance();
          iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
          if ((iVar5 == 1) || (iVar5 == 0x1c)) {
            return 0;
          }
          uVar17 = MWnd::GetParentApp();
          MApplet::Hide(uVar17);
          pMStack_b8 = operator_new(0x40,(nothrow_t *)&DAT_2c7f5bd0);
          if (pMStack_b8 != (MessageBoxApp *)0x0) {
                    /* try { // try from 00d7ee30 to 00d7ee37 has its CatchHandler @ 00d7ee4c */
            MessageBoxApp::MessageBoxApp(pMStack_b8);
          }
          pMStack_bc = pMStack_b8;
          if (pMStack_b8 != (MessageBoxApp *)0x0) {
            MApplet::Run((ulong)pMStack_b8,(void *)0x32);
            return 1;
          }
          printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xe03);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if (param_2 != (void *)0xf07d) {
          if (param_2 == (void *)0xf07b) {
            return 0;
          }
          return 0;
        }
LAB_00d7eb10:
        uVar17 = MWnd::GetParentApp();
        MApplet::Hide(uVar17);
        piVar10 = (int *)MSrv_Control::GetInstance();
        iVar5 = (**(code **)(*piVar10 + 0x84))(piVar10);
        if (iVar5 == 0x1c) {
          AudioSubtitleSelectFrame::Summon(1);
          return 1;
        }
        iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
        if (iVar5 == 0) {
          pMStack_b0 = operator_new(0x40,(nothrow_t *)&DAT_2c7f5bd0);
          if (pMStack_b0 != (MessageBoxApp *)0x0) {
                    /* try { // try from 00d7ec08 to 00d7ec0f has its CatchHandler @ 00d7ec24 */
            MessageBoxApp::MessageBoxApp(pMStack_b0);
          }
          pMStack_b4 = pMStack_b0;
          if (pMStack_b0 == (MessageBoxApp *)0x0) {
            printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xdd7);
                    /* WARNING: Subroutine does not return */
            abort();
          }
          MApplet::Run((ulong)pMStack_b0,(void *)0x32);
        }
        else {
          iVar5 = (**(code **)(*piVar4 + 0x78))(piVar4);
          if (iVar5 == 0) {
            (**(code **)(*piVar4 + 0x68))(piVar4,4);
          }
          else {
            (**(code **)(*piVar4 + 0x70))(piVar4,0x1f);
          }
        }
        return 1;
      }
      if (param_2 == (void *)0xf077) {
        piVar4 = (int *)MSrv_Control::GetInstance();
        iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
        if (iVar5 == 0x1c) {
          iStack_18c = MSrv_Control_TV::GetMSrvDtv(0);
          if (iStack_18c == 0) {
            piStack_188 = (int *)0x0;
          }
          else {
            piStack_188 = (int *)__dynamic_cast(iStack_18c,&DAT_2da86f20,&DAT_2d5d5108,0);
          }
          iVar5 = (**(code **)(*piStack_188 + 0x428))(piStack_188);
          if (iVar5 != 0) {
            iStack_184 = 1;
            goto LAB_00d82740;
          }
        }
        iStack_184 = 0;
LAB_00d82740:
        if (iStack_184 != 0) {
          _PVRFrameSendKey(this,0xf077);
          return 1;
        }
        piVar4 = (int *)MSrv_Control::GetInstance();
        iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
        if (iVar5 != 0x1c) {
          return 0;
        }
        piVar4 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
        (**(code **)(*piVar4 + 0xd0))(piVar4,aoStack_538);
        if (cStack_24b != '\x01') {
          return 0;
        }
        piVar4 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
        uVar14 = (**(code **)(*piVar4 + 0x3f4))(piVar4,0xffff,0);
        DoRecordStartUI(this,uVar14,1,1,0,4);
        return 0;
      }
      if (param_2 < (void *)0xf078) {
        iVar6 = (**(code **)(*piVar4 + 0x80))(piVar4);
        if ((iVar6 == 0) ||
           (((((iVar5 != 0x1c && (iVar5 != 1)) && ((iVar5 < 2 || (9 < iVar5)))) &&
             ((iVar5 < 0xb || (0xe < iVar5)))) && ((iVar5 < 0x14 || (0xe < iVar5)))))) {
          iStack_104 = 0;
        }
        else {
          iStack_104 = 1;
        }
        if (iStack_104 != 0) {
          (**(code **)(*piVar4 + 0x68))(piVar4,1);
          return 1;
        }
        uVar17 = MWnd::GetParentApp();
        MApplet::Hide(uVar17);
        pMStack_108 = operator_new(0x40,(nothrow_t *)&DAT_2c7f5bd0);
        if (pMStack_108 != (MessageBoxApp *)0x0) {
                    /* try { // try from 00d8052c to 00d80533 has its CatchHandler @ 00d80548 */
          MessageBoxApp::MessageBoxApp(pMStack_108);
        }
        pMStack_10c = pMStack_108;
        if (pMStack_108 != (MessageBoxApp *)0x0) {
          MApplet::Run((ulong)pMStack_108,(void *)0x32);
          return 1;
        }
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xf8f);
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    ArServiceSettingsManager::getInstance();
    iVar5 = ArServiceSettingsManager::ArSystemConf_GetHotel();
    if (iVar5 != 0) {
      ArTvSettingsManager::getInstance();
      iVar5 = ArTvSettingsManager::GetHotelAdmin();
      if (iVar5 == 0) {
        iStack_c0 = 1;
        goto LAB_00d7ef7c;
      }
    }
    iStack_c0 = 0;
LAB_00d7ef7c:
    if (iStack_c0 != 0) {
      return 1;
    }
    piVar4 = (int *)MSrv_Control::GetInstance();
    iVar5 = (**(code **)(*piVar4 + 0x84))(piVar4);
    if ((iVar5 != 0x1c) && (iVar5 != 1)) {
      return 0;
    }
    uVar17 = MWnd::GetParentApp();
    MApplet::Hide(uVar17);
    pFStack_c4 = operator_new(0x3c);
                    /* try { // try from 00d7f03c to 00d7f043 has its CatchHandler @ 00d7f064 */
    FavoriteSelectionApp::FavoriteSelectionApp(pFStack_c4);
    if (pFStack_c4 != (FavoriteSelectionApp *)0x0) {
      MApplet::Run((ulong)pFStack_c4,(void *)0x1000);
      return 1;
    }
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0xe1c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  ArTvPlayer::getInstance();
  iVar5 = ArTvPlayer::getTeletextKeyStatus();
  if (iVar5 == 0) {
    pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
    cVar2 = ArTvPlayer::handleTeletextKey(pAVar15,(ulong)param_2);
    if (cVar2 != '\0') {
      return 1;
    }
    pvStack_24 = param_2;
    if (param_2 == (void *)0xf068) {
      iStack_1f0 = MSrv_Control_common::GetMSrvPicture();
      if (iStack_1f0 == 0) {
        piStack_1ec = (int *)0x0;
      }
      else {
        piStack_1ec = (int *)__dynamic_cast(iStack_1f0,&DAT_2da875b8,&DAT_2e027d30,0);
      }
      (**(code **)(*piStack_1ec + 0x6c))(piStack_1ec,0,0x20);
      (**(code **)(*piVar4 + 0x6c))(piVar4);
      iVar5 = (**(code **)(*piVar4 + 0x78))(piVar4);
      if (iVar5 == 0) {
        pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
        ArTvPlayer::setTeletextKeyStatus(pAVar15,2);
        OnEvent_CHANGE_TTX_STATUS(this,(void *)0x0,(void *)0x0);
      }
      return 1;
    }
    if (param_2 < (void *)0xf069) {
      if (param_2 == (void *)0xf052) {
        uVar14 = MW_TTX::GetInstance();
        MW_TTX::OpenPAT(uVar14,0x24);
        iVar5 = (**(code **)(*piVar4 + 0x78))(piVar4);
        if (iVar5 == 0) {
          iStack_1e8 = MSrv_Control_common::GetMSrvPicture();
          if (iStack_1e8 == 0) {
            piStack_1e4 = (int *)0x0;
          }
          else {
            piStack_1e4 = (int *)__dynamic_cast(iStack_1e8,&DAT_2da875b8,&DAT_2e027d30,0);
          }
          (**(code **)(*piStack_1e4 + 0x6c))(piStack_1e4,0,0x20);
          pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
          ArTvPlayer::setTeletextKeyStatus(pAVar15,2);
          OnEvent_CHANGE_TTX_STATUS(this,(void *)0x0,(void *)0x0);
        }
        return 1;
      }
      if (param_2 == (void *)0xf062) {
LAB_00d83878:
        iStack_1d8 = MSrv_Control_TV::GetMSrvDtv(0);
        if (iStack_1d8 == 0) {
          uStack_1d4 = 0;
        }
        else {
          uStack_1d4 = __dynamic_cast(iStack_1d8,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        iVar5 = MSrv_DTV_Player_DVB::IsInCuProgress();
        if (iVar5 != 0) {
          puts("\n\n\nDebug- IdleAppFrame---- MVK_EXIT is entered \n\n");
          return 1;
        }
        iStack_1e0 = MSrv_Control_common::GetMSrvPicture();
        if (iStack_1e0 == 0) {
          piStack_1dc = (int *)0x0;
        }
        else {
          piStack_1dc = (int *)__dynamic_cast(iStack_1e0,&DAT_2da875b8,&DAT_2e027d30,0);
        }
        (**(code **)(*piStack_1dc + 0x6c))(piStack_1dc,0,0x20);
        (**(code **)(*piVar4 + 0x6c))(piVar4);
        pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
        ArTvPlayer::setTeletextKeyStatus(pAVar15,2);
        OnEvent_CHANGE_TTX_STATUS(this,(void *)0x0,(void *)0x0);
        return 1;
      }
      if (param_2 != (void *)0xf00f) {
        return 1;
      }
    }
    else if (param_2 != (void *)0xf550) {
      if (param_2 != (void *)0xf557) {
        if (param_2 != (void *)0xf06a) {
          return 1;
        }
        iStack_1d0 = MSrv_Control_common::GetMSrvPicture();
        if (iStack_1d0 == 0) {
          piStack_1cc = (int *)0x0;
        }
        else {
          piStack_1cc = (int *)__dynamic_cast(iStack_1d0,&DAT_2da875b8,&DAT_2e027d30,0);
        }
        (**(code **)(*piStack_1cc + 0x6c))(piStack_1cc,0,0x20);
        (**(code **)(*piVar4 + 0x6c))(piVar4);
        iVar5 = (**(code **)(*piVar4 + 0x78))(piVar4);
        if (iVar5 == 0) {
          pAVar15 = (ArTvPlayer *)ArTvPlayer::getInstance();
          ArTvPlayer::setTeletextKeyStatus(pAVar15,2);
          OnEvent_CHANGE_TTX_STATUS(this,(void *)0x0,(void *)0x0);
        }
        return 1;
      }
      goto LAB_00d83878;
    }
    return 0;
  }
  ArTvPlayer::getInstance();
  iVar5 = ArTvPlayer::getTeletextKeyStatus();
  if (iVar5 != 1) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fff778,&UNK_01002378,0x15b6);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  cStack_6e0 = '\0';
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if (((((*(int *)(this + 0x1d0) == 4) || (*(int *)(this + 0x1d0) == 0xe)) ||
       (*(int *)(this + 0x1d0) == 0x22)) ||
      ((*(int *)(this + 0x1d0) == 6 || (*(int *)(this + 0x1d0) == 7)))) ||
     (*(int *)(this + 0x1d0) == 0xff)) {
    iStack_20 = (int)param_2 + -0x30;
    switch(iStack_20) {
    case 0:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x10);
      break;
    case 1:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x11);
      break;
    case 2:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x12);
      break;
    case 3:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x13);
      break;
    case 4:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x14);
      break;
    case 5:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x15);
      break;
    case 6:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x16);
      break;
    case 7:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x17);
      break;
    case 8:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x18);
      break;
    case 9:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x19);
      break;
    default:
      cStack_6e0 = '\0';
    }
  }
  if ((cStack_6e0 == '\0') &&
     (((((*(int *)(this + 0x1d0) == 4 || (*(int *)(this + 0x1d0) == 5)) ||
        ((*(int *)(this + 0x1d0) == 0xe ||
         (((*(int *)(this + 0x1d0) == 0xf || (*(int *)(this + 0x1d0) == 6)) ||
          (*(int *)(this + 0x1d0) == 7)))))) ||
       ((*(int *)(this + 0x1d0) == 0x22 || (*(int *)(this + 0x1d0) == 0x23)))) ||
      (*(int *)(this + 0x1d0) == 0xff)))) {
    pvStack_1c = param_2;
    if (param_2 == (void *)0xf003) {
LAB_00d84188:
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0xb);
    }
    else {
      if (param_2 < (void *)0xf004) {
        if (param_2 != (void *)0xf000) {
          if (param_2 < (void *)0xf001) {
            if (param_2 == (void *)0xd) {
LAB_00d84128:
              cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0xd);
            }
            else {
LAB_00d84218:
              cStack_6e0 = '\0';
            }
          }
          else {
            if (param_2 != (void *)0xf001) {
              if (param_2 == (void *)0xf002) goto LAB_00d84158;
              goto LAB_00d84218;
            }
LAB_00d841e8:
            cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0xf);
          }
          goto LAB_00d8421c;
        }
      }
      else if (param_2 != (void *)0xf553) {
        if (param_2 < (void *)0xf554) {
          if (param_2 == (void *)0xf551) {
LAB_00d84158:
            cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,7);
            goto LAB_00d8421c;
          }
          if (param_2 == (void *)0xf552) goto LAB_00d84188;
        }
        else {
          if (param_2 == (void *)0xf554) goto LAB_00d841e8;
          if (param_2 == (void *)0xf556) goto LAB_00d84128;
        }
        goto LAB_00d84218;
      }
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0xc);
    }
  }
LAB_00d8421c:
  if ((cStack_6e0 == '\0') &&
     ((((*(int *)(this + 0x1d0) == 3 || (*(int *)(this + 0x1d0) == 4)) ||
       ((*(int *)(this + 0x1d0) == 5 ||
        (((*(int *)(this + 0x1d0) == 0xd || (*(int *)(this + 0x1d0) == 0xe)) ||
         (*(int *)(this + 0x1d0) == 0xf)))))) ||
      (((*(int *)(this + 0x1d0) == 0x21 || (*(int *)(this + 0x1d0) == 0x22)) ||
       ((*(int *)(this + 0x1d0) == 0x23 ||
        (((*(int *)(this + 0x1d0) == 6 || (*(int *)(this + 0x1d0) == 7)) ||
         (*(int *)(this + 0x1d0) == 0xff)))))))))) {
    pvStack_18 = param_2;
    if (param_2 == (void *)0xf045) {
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x34);
    }
    else if (param_2 < (void *)0xf046) {
      if (param_2 == (void *)0xf043) {
        cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x1d);
      }
      else if (param_2 < (void *)0xf044) {
        if (param_2 != (void *)0xf042) goto LAB_00d84504;
        cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x1c);
      }
      else {
        cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x33);
      }
    }
    else if (param_2 == (void *)0xf06a) {
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x35);
    }
    else {
      if (param_2 < (void *)0xf06b) {
        if (param_2 == (void *)0xf062) {
LAB_00d84414:
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,9);
          goto LAB_00d84508;
        }
      }
      else if ((param_2 == (void *)0xf075) || (param_2 == (void *)0xf557)) goto LAB_00d84414;
LAB_00d84504:
      cStack_6e0 = '\0';
    }
  }
LAB_00d84508:
  if ((cStack_6e0 == '\0') &&
     (((((*(int *)(this + 0x1d0) == 0xd || (*(int *)(this + 0x1d0) == 0xe)) ||
        (*(int *)(this + 0x1d0) == 0xf)) ||
       ((*(int *)(this + 0x1d0) == 0x21 || (*(int *)(this + 0x1d0) == 0x22)))) ||
      ((*(int *)(this + 0x1d0) == 0x23 || (*(int *)(this + 0x1d0) == 0xff)))))) {
    if (param_2 == (void *)0xf01b) {
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x26);
    }
    else {
      cStack_6e0 = '\0';
    }
  }
  if ((cStack_6e0 == '\0') &&
     (((*(int *)(this + 0x1d0) == 0x21 || (*(int *)(this + 0x1d0) == 0x22)) ||
      ((*(int *)(this + 0x1d0) == 0x23 ||
       ((*(int *)(this + 0x1d0) == 7 || (*(int *)(this + 0x1d0) == 0xff)))))))) {
    if (param_2 == (void *)0xf014) {
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x1b);
    }
    else {
      cStack_6e0 = '\0';
    }
  }
  if ((cStack_6e0 == '\0') &&
     (((*(int *)(this + 0x1d0) == 6 || (*(int *)(this + 0x1d0) == 7)) ||
      (*(int *)(this + 0x1d0) == 0xff)))) {
    pvStack_14 = param_2;
    if (param_2 == (void *)0xf052) {
      cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x71);
    }
    else {
      if (param_2 < (void *)0xf053) {
        if (param_2 == (void *)0xf049) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x74);
          goto LAB_00d848d0;
        }
        if (param_2 == (void *)0xf051) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x61);
          goto LAB_00d848d0;
        }
        if (param_2 == (void *)0xf00a) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x60);
          goto LAB_00d848d0;
        }
      }
      else {
        if (param_2 == (void *)0xf05c) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x72);
          goto LAB_00d848d0;
        }
        if (param_2 == (void *)0xf077) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x75);
          goto LAB_00d848d0;
        }
        if (param_2 == (void *)0xf05b) {
          cStack_6e0 = (**(code **)(*piVar4 + 0x88))(piVar4,0x73);
          goto LAB_00d848d0;
        }
      }
      cStack_6e0 = '\0';
    }
  }
LAB_00d848d0:
  if (cStack_6e0 == '\x01') {
    return 1;
  }
  uVar14 = OnKey(this,(void *)0x0,param_2,(void *)0x1);
  return uVar14;
}

