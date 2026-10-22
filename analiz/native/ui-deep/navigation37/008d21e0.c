
undefined4 FUN_008d21e0(ulong param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  uchar uVar2;
  int *piVar3;
  uint uVar4;
  ST_EPG_EVENT_TIMER_INFO *pSVar5;
  int iVar6;
  ArCecController *pAVar7;
  IdleAppFrame *pIVar8;
  byte bStack_e0;
  char acStack_cc [132];
  int iStack_48;
  int iStack_44;
  MuteControlApp *pMStack_40;
  MuteControlApp *pMStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int *piStack_28;
  uint uStack_20;
  
  if (param_3 != 0xf014) {
    MEvtHandle::KillTimer(param_1);
  }
  uStack_20 = param_3;
  if (param_3 == 0xf04e) {
    ArUIManager::getInstance();
    iVar6 = ArUIManager::isScreenShotActive();
    if (iVar6 != 0) {
      puts("\n TAKE SCREENSHOT ");
      iVar6 = CommonFrame::screenShotID;
      CommonFrame::screenShotID = CommonFrame::screenShotID + 1;
      sprintf(acStack_cc,"ss%d.jpg",iVar6);
      ArUIManager::SaveScreenshotToUSB_JPG(acStack_cc,0);
    }
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar6 = MSrv_System_Database::GetFactCecOn();
    if (iVar6 != 0) {
      pAVar7 = (ArCecController *)ArCecController::getInstance();
      iVar6 = ArCecController::IsARCActive();
      if (((iVar6 == 0) || (iVar6 = ArCecController::IsCECInitCompleted(), iVar6 == 0)) ||
         (iVar6 = ArCecController::GetHDMIDevPlugged(), iVar6 == 0)) {
        iStack_38 = 0;
      }
      else {
        iStack_38 = 1;
      }
      if (iStack_38 != 0) {
        ArCecController::ProccessUserRCInput(pAVar7,0xf04e);
        iVar6 = ArCecController::IsRcKeyProcessedByCec();
        if (iVar6 != 0) {
          iVar6 = MuteControlFrame::GetMuteControlFrame();
          if (iVar6 == 0) {
            pMStack_3c = operator_new(0x3c);
                    /* try { // try from 008d28c0 to 008d28c7 has its CatchHandler @ 008d28e8 */
            MuteControlApp::MuteControlApp(pMStack_3c);
            if (pMStack_3c == (MuteControlApp *)0x0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2858,0x175);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Run((ulong)pMStack_3c,(void *)0x10ff);
          }
          else {
            MuteControlFrame::GetMuteControlFrame();
            MWnd::GetParentApp();
            MApplet::Kill();
          }
          return 1;
        }
      }
    }
    ArAudioManager::getInstance();
    iVar6 = ArAudioManager::IsMuted();
    if (iVar6 == 0) {
      iVar6 = MuteControlFrame::GetMuteControlFrame();
      if (iVar6 == 0) {
        MuteControlFrame::SetMute(true);
        pMStack_40 = operator_new(0x3c);
                    /* try { // try from 008d2ac8 to 008d2acf has its CatchHandler @ 008d2af0 */
        MuteControlApp::MuteControlApp(pMStack_40);
        if (pMStack_40 == (MuteControlApp *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2858,400);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        MApplet::Run((ulong)pMStack_40,(void *)0x10ff);
      }
      else {
        MuteControlFrame::GetMuteControlFrame();
        MWnd::GetParentApp();
        MApplet::Kill();
      }
    }
    else {
      MuteControlFrame::SetMute(false);
      iVar6 = MuteControlFrame::GetMuteControlFrame();
      if (iVar6 != 0) {
        MuteControlFrame::GetMuteControlFrame();
        MWnd::GetParentApp();
        MApplet::Kill();
      }
    }
    return 1;
  }
  if (param_3 < 0xf04f) {
    if (param_3 == 0xf00f) {
      iVar6 = IdleAppFrame::GetIdleAppFrame();
      if (*(char *)(iVar6 + 0x1bd) != '\0') {
        return 0;
      }
      iVar6 = MSystem::GetInstance();
      if (iVar6 == 0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2858,0x138);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      iVar6 = MSystem::GetMWindowManager();
      if (iVar6 == 0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2858,0x13a);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      iVar6 = MWindowManager::GetFocusedApp();
      if (iVar6 == 0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2858,0x13c);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      bVar1 = false;
      bStack_e0 = 0;
      while( true ) {
        piVar3 = (int *)MSrv_Control::GetInstance();
        uVar4 = (**(code **)(*piVar3 + 0x1bc))(piVar3);
        if (uVar4 <= bStack_e0) break;
        piVar3 = (int *)MSrv_Control::GetInstance();
        iStack_2c = (**(code **)(*piVar3 + 0x1b4))(piVar3,bStack_e0);
        if (iStack_2c == 0) {
          piStack_28 = (int *)0x0;
        }
        else {
          piStack_28 = (int *)__dynamic_cast(iStack_2c,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        piVar3 = piStack_28;
        if (piStack_28 != (int *)0x0) {
          iVar6 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
          if (((iVar6 == 1) && (iVar6 = (**(code **)(*piVar3 + 0x524))(piVar3), iVar6 == 0)) &&
             (iVar6 = (**(code **)(*piVar3 + 0x52c))(piVar3), iVar6 == 0)) {
            iStack_30 = 1;
          }
          else {
            iStack_30 = 0;
          }
          if (iStack_30 != 0) {
            bVar1 = true;
          }
        }
        bStack_e0 = bStack_e0 + 1;
      }
      if (bVar1) {
        pIVar8 = (IdleAppFrame *)IdleAppFrame::GetIdleAppFrame();
        iVar6 = IdleAppFrame::ClearScreen(pIVar8,'\x01');
        if ((iVar6 == 1) || (iVar6 = PVRFrame::GetInstance(), iVar6 != 0)) {
          iStack_34 = 1;
        }
        else {
          iStack_34 = 0;
        }
        if (iStack_34 != 0) {
          pSVar5 = (ST_EPG_EVENT_TIMER_INFO *)MSrv_Control_common::GetMSrvTimer();
          uVar2 = MSrv_Timer::GetEPGTimerRecordingProgram(pSVar5);
          pIVar8 = (IdleAppFrame *)IdleAppFrame::GetIdleAppFrame();
          IdleAppFrame::OpenStandByConfirmPopup(pIVar8,uVar2);
          return 1;
        }
      }
      return 0;
    }
    if (param_3 < 0xf00f) {
      return 0;
    }
    if (param_3 < 0xf04c) {
      return 0;
    }
  }
  else {
    if (param_3 == 0xf06d) {
      return 1;
    }
    if (param_3 < 0xf06e) {
      if (param_3 != 0xf06b) {
        return 0;
      }
      return 1;
    }
    if (1 < param_3 - 0xf553) {
      return 0;
    }
  }
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar6 = MSrv_System_Database::GetFactCecOn();
  if (iVar6 != 0) {
    pAVar7 = (ArCecController *)ArCecController::getInstance();
    iVar6 = ArCecController::IsARCActive();
    if (((iVar6 == 0) || (iVar6 = ArCecController::IsCECInitCompleted(), iVar6 == 0)) ||
       (iVar6 = ArCecController::GetHDMIDevPlugged(), iVar6 == 0)) {
      iStack_44 = 0;
    }
    else {
      iStack_44 = 1;
    }
    if (iStack_44 != 0) {
      ArCecController::ProccessUserRCInput(pAVar7,param_3);
      iVar6 = ArCecController::IsRcKeyProcessedByCec();
      if (iVar6 != 0) {
        iVar6 = MuteControlFrame::GetMuteControlFrame();
        if (iVar6 != 0) {
          MuteControlFrame::GetMuteControlFrame();
          MWnd::GetParentApp();
          MApplet::Kill();
        }
        if ((param_3 == 0xf04c) || (param_3 == 0xf554)) {
          VolumeControlApp::Summon(0xff,0xf04c);
        }
        else {
          VolumeControlApp::Summon(0xff,0xf04d);
        }
        return 1;
      }
    }
  }
  iVar6 = MuteControlFrame::GetMuteControlFrame();
  if (iVar6 != 0) {
    MuteControlFrame::GetMuteControlFrame();
    MWnd::GetParentApp();
    MApplet::Kill();
  }
  ArAudioManager::getInstance();
  iVar6 = ArAudioManager::GetTvSpeaker();
  if (iVar6 == 0) {
    ArAudioManager::getInstance();
    iVar6 = ArAudioManager::GetAudioOut();
    if (iVar6 == 1) {
      iStack_48 = 0;
      goto LAB_008d2e58;
    }
  }
  iStack_48 = 1;
LAB_008d2e58:
  if (iStack_48 == 0) {
    pIVar8 = (IdleAppFrame *)IdleAppFrame::GetIdleAppFrame();
    IdleAppFrame::ShowInformationPopup(pIVar8,2,'\0',7,2);
  }
  else if ((param_3 == 0xf04c) || (param_3 == 0xf554)) {
    VolumeControlApp::Summon(0xff,0xf04c);
  }
  else {
    VolumeControlApp::Summon(0xff,0xf04d);
  }
  return 1;
}

