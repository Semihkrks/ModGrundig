
undefined4 FUN_007dc104(ArProgramInfoFrame *param_1,undefined4 param_2,ulong param_3)

{
  int iVar1;
  MEvtHandle *pMVar2;
  ulong uVar3;
  ArTvManager *pAVar4;
  undefined4 uVar5;
  ArTvPlayer *pAVar6;
  char *pcVar7;
  ulong auStack_180 [4];
  string asStack_170 [4];
  string asStack_16c [4];
  string asStack_168 [4];
  string asStack_164 [4];
  allocator aaStack_160 [4];
  string asStack_15c [4];
  string asStack_158 [4];
  allocator aaStack_154 [4];
  string asStack_150 [4];
  string asStack_14c [4];
  allocator aaStack_148 [4];
  string asStack_144 [4];
  string asStack_140 [4];
  vector<std::string,std::allocator<std::string>> avStack_13c [12];
  ST_CM_SERVICE_HISTORY_INFO aSStack_130 [8];
  string asStack_128 [4];
  vector<std::string,std::allocator<std::string>> avStack_124 [12];
  vector<unsigned_long,std::allocator<unsigned_long>> avStack_118 [12];
  ostringstream aoStack_10c [180];
  int iStack_58;
  int iStack_54;
  string *psStack_50;
  string *psStack_4c;
  string *psStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  ChannelControlApp *pCStack_38;
  ChannelControlApp *pCStack_34;
  ProgramGuideApp *pPStack_30;
  ProgramGuideApp *pPStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  ulong uStack_20;
  
  iVar1 = PVRFrame::GetInstance();
  if (iVar1 != 0) {
    pMVar2 = (MEvtHandle *)PVRFrame::GetInstance();
    uVar3 = PVRFrame::GetInstance();
    MEvtHandle::PostEvent(pMVar2,uVar3,0x14,param_3);
    return 1;
  }
  iVar1 = ArChannelListFrame::GetInstance();
  if (iVar1 != 0) {
    pMVar2 = (MEvtHandle *)ArChannelListFrame::GetInstance();
    uVar3 = ArChannelListFrame::GetInstance();
    MEvtHandle::PostEvent(pMVar2,uVar3,0x14,param_3);
    return 1;
  }
  param_1[0x2d5] = (ArProgramInfoFrame)0x0;
  MEvtHandle::KillTimer((ulong)param_1);
  if (param_1[0x2c7] != (ArProgramInfoFrame)0x0) {
    MEvtHandle::SetTimer(param_1,*(undefined4 *)(param_1 + 0x2d8),0,1);
  }
  uStack_20 = param_3;
  if (param_3 == 0xf020) goto LAB_007dcc80;
  if (param_3 < 0xf021) {
    if (param_3 < 0xf004) {
      if (0xf001 < param_3) {
        iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
        if (iVar1 != 0) {
          return 0;
        }
        if (*(int *)(param_1 + 0x2c0) != 2) {
          pMVar2 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
          uVar3 = IdleAppFrame::GetIdleAppFrame();
          MEvtHandle::PostEvent(pMVar2,uVar3,0x14,param_3);
          return 1;
        }
        MEvtHandle::KillTimer((ulong)param_1);
        return 0;
      }
      if (param_3 != 0xf000) {
        if (param_3 < 0xf001) {
          if (9 < param_3 - 0x30) {
            return 0;
          }
          pAVar4 = (ArTvManager *)ArTvManager::getInstance();
          iVar1 = ArTvManager::GetCurrentInputSourceType(pAVar4);
          if ((iVar1 == 0) || (iVar1 == 1)) {
            MWnd::GetParentApp();
            pCStack_34 = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
            if (pCStack_34 != (ChannelControlApp *)0x0) {
                    /* try { // try from 007dcd80 to 007dcd87 has its CatchHandler @ 007dcd9c */
              ChannelControlApp::ChannelControlApp(pCStack_34);
            }
            pCStack_38 = pCStack_34;
            if (pCStack_34 != (ChannelControlApp *)0x0) {
              MApplet::Run((ulong)pCStack_34,(void *)0x0);
            }
            MApplet::Kill();
            MEvtHandle::PostEvent((MEvtHandle *)param_1,0,0x14,param_3);
          }
          return 1;
        }
        iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
        if (iVar1 != 0) {
          return 1;
        }
        if (*(int *)(param_1 + 0x2c0) != 3) {
          if ((param_1[0x2c5] != (ArProgramInfoFrame)0x0) &&
             (param_1[0x2c6] != (ArProgramInfoFrame)0x0)) {
            param_1[0x2c5] = (ArProgramInfoFrame)0x0;
            ArProgramInfoFrame::RefreshUI(param_1,'\x01');
          }
          return 1;
        }
        return 1;
      }
      iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
      if (iVar1 != 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x2c0) != 3) {
        if (param_1[0x2c5] == (ArProgramInfoFrame)0x0) {
          param_1[0x2c5] = (ArProgramInfoFrame)0x1;
          ArProgramInfoFrame::RefreshUI(param_1,'\x01');
        }
        return 1;
      }
      return 1;
    }
    if (param_3 == 0xf014) {
      iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
      if (iVar1 == 0) {
        iStack_28 = *(int *)(param_1 + 0x2c0);
        if (iStack_28 == 1) {
          pAVar4 = (ArTvManager *)ArTvManager::getInstance();
          iVar1 = ArTvManager::GetCurrentInputSourceType(pAVar4);
          if (iVar1 == 0) {
            iVar1 = ArChannelManager::GetChannelCount(0);
            if (iVar1 == 0) {
              ArProgramInfoApp::KillAPP();
            }
            else {
              MMainFrame::SwitchFocusTo((MWidget *)param_1);
              *(undefined4 *)(param_1 + 0x2c0) = 2;
              MEvtHandle::SetTimer(param_1,2000,2,0);
              ArProgramInfoFrame::RefreshUI(param_1,'\x01');
            }
          }
          else {
            ArProgramInfoApp::KillAPP();
          }
        }
        else if (iStack_28 == 0) {
          pAVar4 = (ArTvManager *)ArTvManager::getInstance();
          iVar1 = ArTvManager::GetCurrentInputSourceType(pAVar4);
          if (iVar1 == 0) {
            iVar1 = ArChannelManager::GetChannelCount(0);
            if (iVar1 == 0) {
              ArProgramInfoApp::KillAPP();
            }
            else {
              *(undefined4 *)(param_1 + 0x2c0) = 1;
              ArProgramInfoFrame::RefreshUI(param_1,'\x01');
            }
          }
          else {
            ArProgramInfoApp::KillAPP();
          }
        }
        else if (iStack_28 == 2) {
          ArProgramInfoApp::KillAPP();
        }
        else if (iStack_28 == 3) {
          *(undefined4 *)(param_1 + 0x2c0) = 1;
          ArProgramInfoFrame::RefreshUI(param_1,'\x01');
        }
        return 1;
      }
      return 1;
    }
    if (param_3 < 0xf015) {
      if (param_3 != 0xf012) {
        return 0;
      }
      goto LAB_007dc498;
    }
    if (param_3 != 0xf019) {
      if (param_3 != 0xf01b) {
        return 0;
      }
      ArEpgManager::getInstance();
      iVar1 = ArEpgManager::CanStartEPG();
      if (iVar1 == 0) {
        return 0;
      }
      ArProgramInfoApp::KillAPP();
      pPStack_2c = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
      if (pPStack_2c != (ProgramGuideApp *)0x0) {
                    /* try { // try from 007dcb58 to 007dcb5f has its CatchHandler @ 007dcb74 */
        ProgramGuideApp::ProgramGuideApp(pPStack_2c);
      }
      pPStack_30 = pPStack_2c;
      if (pPStack_2c == (ProgramGuideApp *)0x0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef618,0x9c1);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      MApplet::Run((ulong)pPStack_2c,(void *)0x0);
      return 1;
    }
    ArServiceSettingsManager::getInstance();
    iVar1 = ArServiceSettingsManager::ArSystemConf_GetHotel();
    if (iVar1 != 0) {
      ArTvSettingsManager::getInstance();
      iVar1 = ArTvSettingsManager::GetHotelAdmin();
      if (iVar1 == 0) {
        iStack_54 = 1;
        goto LAB_007dda98;
      }
    }
    iStack_54 = 0;
LAB_007dda98:
    if (iStack_54 != 0) {
      return 1;
    }
    pAVar4 = (ArTvManager *)ArTvManager::getInstance();
    iVar1 = ArTvManager::GetCurrentInputSourceType(pAVar4);
    ArTvManager::getInstance();
    uVar5 = ArTvManager::GetCurrentDvbAntennaType();
    if (((iVar1 == 0) || (iVar1 == 1)) && (iVar1 = ArChannelManager::GetChannelCount(0), iVar1 != 0)
       ) {
      iStack_58 = 0;
    }
    else {
      iStack_58 = 1;
    }
    if (iStack_58 == 0) {
      pAVar6 = (ArTvPlayer *)ArTvPlayer::getInstance();
      iVar1 = ArTvPlayer::IsOpModeByRoute(pAVar6,uVar5);
      if (iVar1 == 0) {
        std::vector<std::string,std::allocator<std::string>>::vector(avStack_124);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::vector(avStack_118);
                    /* try { // try from 007ddbe8 to 007ddc0f has its CatchHandler @ 007de098 */
        uVar5 = ArChannelManager::getInstance();
        ArChannelManager::GetFavName(asStack_164,uVar5,0);
                    /* try { // try from 007ddc28 to 007ddc2f has its CatchHandler @ 007ddc64 */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_124,asStack_164);
                    /* try { // try from 007ddc40 to 007ddc57 has its CatchHandler @ 007de098 */
        std::string::~string(asStack_164);
        uVar5 = ArChannelManager::getInstance();
                    /* try { // try from 007ddcb4 to 007ddcbb has its CatchHandler @ 007de098 */
        ArChannelManager::GetFavName(asStack_168,uVar5,1);
                    /* try { // try from 007ddcd4 to 007ddcdb has its CatchHandler @ 007ddd10 */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_124,asStack_168);
                    /* try { // try from 007ddcec to 007ddd03 has its CatchHandler @ 007de098 */
        std::string::~string(asStack_168);
        uVar5 = ArChannelManager::getInstance();
                    /* try { // try from 007ddd60 to 007ddd67 has its CatchHandler @ 007de098 */
        ArChannelManager::GetFavName(asStack_16c,uVar5,2);
                    /* try { // try from 007ddd80 to 007ddd87 has its CatchHandler @ 007dddbc */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_124,asStack_16c);
                    /* try { // try from 007ddd98 to 007dddaf has its CatchHandler @ 007de098 */
        std::string::~string(asStack_16c);
        uVar5 = ArChannelManager::getInstance();
                    /* try { // try from 007dde0c to 007dde13 has its CatchHandler @ 007de098 */
        ArChannelManager::GetFavName(asStack_170,uVar5,3);
                    /* try { // try from 007dde2c to 007dde33 has its CatchHandler @ 007dde80 */
        std::vector<std::string,std::allocator<std::string>>::push_back(avStack_124,asStack_170);
                    /* try { // try from 007dde44 to 007dde73 has its CatchHandler @ 007de098 */
        std::string::~string(asStack_170);
        auStack_180[3] = 0x31;
        std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                  (avStack_118,auStack_180 + 3);
        auStack_180[2] = 0x32;
                    /* try { // try from 007dded8 to 007de053 has its CatchHandler @ 007de098 */
        std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                  (avStack_118,auStack_180 + 2);
        auStack_180[1] = 0x33;
        std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                  (avStack_118,auStack_180 + 1);
        auStack_180[0] = 0x34;
        std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back(avStack_118,auStack_180)
        ;
        PopUpManager::Clean();
        pcVar7 = (char *)GetRcEngine::RcGetString(0xbfc);
        std::string::operator=((string *)(PopUpManager::gridSelectData + 8),pcVar7);
        std::vector<std::string,std::allocator<std::string>>::operator=
                  ((vector<std::string,std::allocator<std::string>> *)
                   (PopUpManager::gridSelectData + 0x28),(vector *)avStack_124);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::operator=
                  ((vector<unsigned_long,std::allocator<unsigned_long>> *)
                   (PopUpManager::gridSelectData + 0x34),(vector *)avStack_118);
        PopUpManager::gridSelectData._16_4_ = 0;
        PopUpManager::gridSelectData._28_4_ = 0x28;
        PopUpManager::gridSelectData._32_4_ = 0x28;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::parentFrame = param_1;
        PopUpManager::ShowButton(0xe,0xc42);
        PopUpManager::ShowButton(7,0xf37);
        PopUpManager::Summon(5);
        PopUpManager::popupID = 0x26;
        MEvtHandle::KillTimer((ulong)param_1);
        uStack_24 = 1;
        std::vector<unsigned_long,std::allocator<unsigned_long>>::~vector(avStack_118);
        std::vector<std::string,std::allocator<std::string>>::~vector(avStack_124);
        return uStack_24;
      }
      return 1;
    }
    return 1;
  }
  if (param_3 == 0xf068) {
LAB_007dcc80:
    pMVar2 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
    uVar3 = IdleAppFrame::GetIdleAppFrame();
    MEvtHandle::PostEvent(pMVar2,uVar3,0x14,param_3);
    ArProgramInfoApp::KillAPP();
    return 1;
  }
  if (0xf068 < param_3) {
    if (param_3 == 0xf075) goto LAB_007dc498;
    if (0xf075 < param_3) {
      if (1 < param_3 - 0xf551) {
        return 0;
      }
      goto LAB_007dc94c;
    }
    if (param_3 == 0xf06d) {
      ArProgramInfoApp::KillAPP();
      uVar5 = IdleAppFrame::GetIdleAppFrame();
      IdleAppFrame::StartConnectedApp(uVar5,2);
      return 1;
    }
    if (param_3 != 0xf070) {
      return 0;
    }
    goto LAB_007dcc80;
  }
  if (0xf047 < param_3) {
    if (param_3 != 0xf062) {
      return 0;
    }
LAB_007dc498:
    iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
    if (iVar1 == 0) {
      ArProgramInfoApp::KillAPP();
      return 1;
    }
    MWidget::Hide();
    HelpWidget::HideButton(*(HelpWidget **)(param_1 + 0x2cc),0xe);
    HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2cc));
    ArProgramInfoFrame::RefreshUI(param_1,'\x01');
    return 1;
  }
  if (0xf045 < param_3) {
LAB_007dc94c:
    iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(param_1 + 0x198));
    if (iVar1 == 0) {
      if (param_1[0x2d6] != (ArProgramInfoFrame)0x0) {
        ArProgramInfoFrame::SuspendIR(param_1);
        pMVar2 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
        uVar3 = IdleAppFrame::GetIdleAppFrame();
        MEvtHandle::PostEvent(pMVar2,uVar3,0x14,param_3);
      }
      return 1;
    }
    return 0;
  }
  if (param_3 == 0xf037) goto LAB_007dcc80;
  if (param_3 != 0xf043) {
    return 0;
  }
  ArServiceSettingsManager::getInstance();
  iVar1 = ArServiceSettingsManager::ArSystemConf_GetHotel();
  if (iVar1 == 0) {
LAB_007dcecc:
    iStack_3c = 0;
  }
  else {
    ArTvSettingsManager::getInstance();
    iVar1 = ArTvSettingsManager::GetHotelAdmin();
    if (iVar1 != 0) goto LAB_007dcecc;
    iStack_3c = 1;
  }
  if (iStack_3c != 0) {
    return 1;
  }
  pAVar4 = (ArTvManager *)ArTvManager::getInstance();
  iVar1 = ArTvManager::GetCurrentInputSourceType(pAVar4);
  if (((iVar1 == 0) || (iVar1 == 1)) && (iVar1 = ArChannelManager::GetChannelCount(0), iVar1 != 0))
  {
    iStack_40 = 0;
  }
  else {
    iStack_40 = 1;
  }
  if (iStack_40 != 0) {
    return 1;
  }
  ArServiceSettingsManager::getInstance();
  iVar1 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
  if (iVar1 == 1) {
    ArTvSettingsManager::getInstance();
    iVar1 = ArTvSettingsManager::GetBasicMode();
    if (iVar1 != 1) goto LAB_007dcfe4;
  }
  else {
LAB_007dcfe4:
    ArServiceSettingsManager::getInstance();
    iVar1 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
    if (iVar1 == 0) {
      iStack_44 = 0;
      goto LAB_007dd024;
    }
  }
  iStack_44 = 1;
LAB_007dd024:
  if (iStack_44 != 0) {
    MEvtHandle::KillTimer((ulong)param_1);
    std::vector<std::string,std::allocator<std::string>>::vector(avStack_13c);
                    /* try { // try from 007dd074 to 007dd07b has its CatchHandler @ 007dd9d8 */
    FUN_007d3884(aSStack_130);
                    /* try { // try from 007dd090 to 007dd0c3 has its CatchHandler @ 007dd998 */
    iVar1 = ArChannelManager::GetPinnedChannel('\0',aSStack_130);
    if (iVar1 == 0) {
                    /* try { // try from 007dd20c to 007dd213 has its CatchHandler @ 007dd998 */
      pcVar7 = (char *)GetRcEngine::RcGetString(0x1188);
      std::allocator<char>::allocator();
                    /* try { // try from 007dd24c to 007dd253 has its CatchHandler @ 007dd2f4 */
      std::string::string(asStack_144,pcVar7,aaStack_148);
                    /* try { // try from 007dd26c to 007dd273 has its CatchHandler @ 007dd2b4 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_144);
      psStack_48 = asStack_144;
                    /* try { // try from 007dd288 to 007dd28f has its CatchHandler @ 007dd2f4 */
      std::string::~string(psStack_48);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_148);
    }
    else {
      std::ostringstream::ostringstream(aoStack_10c,0x10);
                    /* try { // try from 007dd0dc to 007dd127 has its CatchHandler @ 007dd1c8 */
      std::operator<<((ostream *)aoStack_10c,"1. ");
      std::operator<<((ostream *)aoStack_10c,asStack_128);
      std::ostringstream::str();
                    /* try { // try from 007dd140 to 007dd147 has its CatchHandler @ 007dd184 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_140);
                    /* try { // try from 007dd158 to 007dd15f has its CatchHandler @ 007dd1c8 */
      std::string::~string(asStack_140);
                    /* try { // try from 007dd170 to 007dd177 has its CatchHandler @ 007dd998 */
      std::ostringstream::~ostringstream(aoStack_10c);
    }
                    /* try { // try from 007dd340 to 007dd373 has its CatchHandler @ 007dd998 */
    iVar1 = ArChannelManager::GetPinnedChannel('\x01',aSStack_130);
    if (iVar1 == 0) {
                    /* try { // try from 007dd4bc to 007dd4c3 has its CatchHandler @ 007dd998 */
      pcVar7 = (char *)GetRcEngine::RcGetString(0x1189);
      std::allocator<char>::allocator();
                    /* try { // try from 007dd4fc to 007dd503 has its CatchHandler @ 007dd5a4 */
      std::string::string(asStack_150,pcVar7,aaStack_154);
                    /* try { // try from 007dd51c to 007dd523 has its CatchHandler @ 007dd564 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_150);
      psStack_4c = asStack_150;
                    /* try { // try from 007dd538 to 007dd53f has its CatchHandler @ 007dd5a4 */
      std::string::~string(psStack_4c);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_154);
    }
    else {
      std::ostringstream::ostringstream(aoStack_10c,0x10);
                    /* try { // try from 007dd38c to 007dd3d7 has its CatchHandler @ 007dd478 */
      std::operator<<((ostream *)aoStack_10c,"2. ");
      std::operator<<((ostream *)aoStack_10c,asStack_128);
      std::ostringstream::str();
                    /* try { // try from 007dd3f0 to 007dd3f7 has its CatchHandler @ 007dd434 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_14c);
                    /* try { // try from 007dd408 to 007dd40f has its CatchHandler @ 007dd478 */
      std::string::~string(asStack_14c);
                    /* try { // try from 007dd420 to 007dd427 has its CatchHandler @ 007dd998 */
      std::ostringstream::~ostringstream(aoStack_10c);
    }
                    /* try { // try from 007dd5f0 to 007dd623 has its CatchHandler @ 007dd998 */
    iVar1 = ArChannelManager::GetPinnedChannel('\x02',aSStack_130);
    if (iVar1 == 0) {
                    /* try { // try from 007dd76c to 007dd773 has its CatchHandler @ 007dd998 */
      pcVar7 = (char *)GetRcEngine::RcGetString(0x118a);
      std::allocator<char>::allocator();
                    /* try { // try from 007dd7ac to 007dd7b3 has its CatchHandler @ 007dd854 */
      std::string::string(asStack_15c,pcVar7,aaStack_160);
                    /* try { // try from 007dd7cc to 007dd7d3 has its CatchHandler @ 007dd814 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_15c);
      psStack_50 = asStack_15c;
                    /* try { // try from 007dd7e8 to 007dd7ef has its CatchHandler @ 007dd854 */
      std::string::~string(psStack_50);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_160);
    }
    else {
      std::ostringstream::ostringstream(aoStack_10c,0x10);
                    /* try { // try from 007dd63c to 007dd687 has its CatchHandler @ 007dd728 */
      std::operator<<((ostream *)aoStack_10c,"3. ");
      std::operator<<((ostream *)aoStack_10c,asStack_128);
      std::ostringstream::str();
                    /* try { // try from 007dd6a0 to 007dd6a7 has its CatchHandler @ 007dd6e4 */
      std::vector<std::string,std::allocator<std::string>>::push_back(avStack_13c,asStack_158);
                    /* try { // try from 007dd6b8 to 007dd6bf has its CatchHandler @ 007dd728 */
      std::string::~string(asStack_158);
                    /* try { // try from 007dd6d0 to 007dd6d7 has its CatchHandler @ 007dd998 */
      std::ostringstream::~ostringstream(aoStack_10c);
    }
                    /* try { // try from 007dd894 to 007dd957 has its CatchHandler @ 007dd998 */
    PopUpManager::Clean();
    pcVar7 = (char *)GetRcEngine::RcGetString(0x1186);
    std::string::operator=((string *)PopUpManager::itemSelectData,pcVar7);
    std::vector<std::string,std::allocator<std::string>>::operator=
              ((vector<std::string,std::allocator<std::string>> *)(PopUpManager::itemSelectData + 8)
               ,(vector *)avStack_13c);
    PopUpManager::itemSelectData._4_4_ = 0;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::popupID = 0x2b;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(0xe,0xc42);
    PopUpManager::ShowButton(7,0xf37);
    PopUpManager::Summon(1);
                    /* try { // try from 007dd96c to 007dd973 has its CatchHandler @ 007dd9d8 */
    FUN_007d3780(aSStack_130);
    std::vector<std::string,std::allocator<std::string>>::~vector(avStack_13c);
  }
  return 1;
}

