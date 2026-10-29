
/* PowerOnOffFrame::PowerOff(unsigned char) */

undefined4 PowerOnOffFrame::PowerOff(uchar param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  MEvtHandle *pMVar4;
  int *piVar5;
  undefined4 uVar6;
  ulong uVar7;
  IdleAppFrame *this;
  undefined3 in_register_00000011;
  
  ArSrvPowerManager::GetInstance();
  iVar3 = ArSrvPowerManager::GetPowerState();
  if (iVar3 == 4) {
    ArSrvPowerManager::GetInstance();
    cVar2 = ArSrvPowerManager::IsWakeUpComplete();
    if (cVar2 == '\0') {
      bVar1 = true;
      goto LAB_00ea0250;
    }
  }
  bVar1 = false;
LAB_00ea0250:
  if (bVar1) {
    puts("POWER HOT KEY IS IGNORED: WAKE UP STATE");
  }
  else {
    ArSrvPowerManager::GetInstance();
    iVar3 = ArSrvPowerManager::GetPowerState();
    if (iVar3 == 3) {
      ArTvManager::getInstance();
      ArTvManager::CancelStandby();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
    else {
      puts("POWER HOT KEY");
      pthread_mutex_lock_tracker
                ((pthread_mutex_t *)IdleAppFrame::dlnaMutex,"BOOL PowerOnOffFrame::PowerOff(BOOL)",
                 0x192);
      DMPlayerFrame::CloseDMP();
      pthread_mutex_unlock_tracker((pthread_mutex_t *)IdleAppFrame::dlnaMutex);
      ArTvManager::getInstance();
      iVar3 = ArTvManager::IsStanbyOADProcessing();
      if (iVar3 == 0) {
        piVar5 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
        if (piVar5 == (int *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_01008d80,&UNK_01008e24,0x1b4);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        (**(code **)(*piVar5 + 0x8b0))(piVar5);
        (**(code **)(*piVar5 + 0x508))(piVar5);
        piVar5 = (int *)MSrv_Control::GetInstance();
        uVar6 = (**(code **)(*piVar5 + 0x84))(piVar5);
        piVar5 = (int *)MSrv_Control::GetInstance();
        piVar5 = (int *)(**(code **)(*piVar5 + 0x9c))(piVar5,uVar6);
        if (piVar5 == (int *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_01008d80,&UNK_01008e24,0x1bd);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        iVar3 = (**(code **)(*piVar5 + 0x78))(piVar5);
        if (iVar3 != 0) {
          (**(code **)(*piVar5 + 0x6c))(piVar5);
        }
        SetLEDBlinkEvent(0xb);
        MSrv_Control_common::GetMSrvSystemDatabase();
        iVar3 = MSrv_System_Database::GetFactBreathingLED();
        if (iVar3 == 0) {
          SetLEDBlinkEvent(6);
        }
        if (DMPlayerFrame::MMBrowser != 0) {
          MSrv_MediaBrowser::Deinit();
        }
        ArTvManager::getInstance();
        cVar2 = ArTvManager::StartStandby();
        iVar3 = PVRFrame::GetInstance();
        if (iVar3 != 0) {
          uVar7 = PVRFrame::GetInstance();
          PVRFrame::KillPVRFrame(uVar7);
        }
        iVar3 = VolumeControlFrame::GetVolumeControlFrame();
        if (iVar3 != 0) {
          VolumeControlFrame::GetVolumeControlFrame();
          MWnd::GetParentApp();
          MApplet::Kill();
        }
        if ((*(char *)(CONCAT31(in_register_00000011,param_1) + 0x180) == '\0') && (cVar2 == '\0'))
        {
          *(undefined1 *)(CONCAT31(in_register_00000011,param_1) + 0x180) = 1;
        }
        else {
          MWnd::GetParentApp();
          MApplet::Kill();
          iVar3 = MSystem::GetInstance();
          if ((iVar3 != 0) &&
             ((pMVar4 = (MEvtHandle *)MSystem::GetMWindowManager(), pMVar4 != (MEvtHandle *)0x0 &&
              (iVar3 = MWindowManager::GetFocusedApp(), iVar3 != 0)))) {
            piVar5 = (int *)MSrv_Control::GetInstance();
            iVar3 = (**(code **)(*piVar5 + 0x84))(piVar5);
            if (0x21 < iVar3) {
              uVar7 = MApplet::GetMainFrame();
              MWindowManager::SendEvent(pMVar4,(MEvtHandle *)0x0,uVar7,0x2000200a,0);
            }
          }
        }
        this = (IdleAppFrame *)IdleAppFrame::GetIdleAppFrame();
        IdleAppFrame::ClearScreen(this,'\x01');
        usleep(100000);
        if (cVar2 != '\0') {
          ArTvManager::getInstance();
          ArTvManager::SuspendSystem();
        }
      }
      else {
        pMVar4 = (MEvtHandle *)MSrv_Control_common::GetMSrvCEC();
        MSrv::RemoveEventRecipient(pMVar4);
        MWnd::GetParentApp();
        MApplet::Kill();
      }
    }
  }
  return 1;
}

