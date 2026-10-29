
/* ArTvManager::StartStandby() */

undefined4 ArTvManager::StartStandby(void)

{
  uchar uVar1;
  ArScanManager *pAVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  ArASUManager *pAVar6;
  int *piStack_10;
  
  pAVar2 = (ArScanManager *)ArScanManager::getInstance();
  iVar3 = ArScanManager::isSearching(pAVar2);
  if (iVar3 != 0) {
    pAVar2 = (ArScanManager *)ArScanManager::getInstance();
    ArScanManager::stopAutoScan(pAVar2);
  }
  uVar4 = ArSrvPowerManager::GetInstance();
  ArSrvPowerManager::SetPowerState(uVar4,3,0);
  ArCecController::getInstance();
  ArCecController::CecSystemStandby();
  piVar5 = (int *)MSrv_Control_common::GetMSrvSSSound();
  (**(code **)(*piVar5 + 0x1a0))(piVar5);
  uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::SetESD_PvrRecording(uVar1);
  iVar3 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iVar3 == 0) {
    piStack_10 = (int *)0x0;
  }
  else {
    piStack_10 = (int *)__dynamic_cast(iVar3,&DAT_2da86f20,&DAT_2d5d5108,0);
  }
  (**(code **)(*piStack_10 + 0x724))(piStack_10);
  iVar3 = ArASUManager::getInstance();
  if (iVar3 != 0) {
    pAVar6 = (ArASUManager *)ArASUManager::getInstance();
    iVar3 = ArASUManager::StopExistingASUUpdate(pAVar6);
    if (iVar3 == 1) {
      return 0;
    }
    pAVar6 = (ArASUManager *)ArASUManager::getInstance();
    iVar3 = ArASUManager::StartASU(pAVar6);
    if (iVar3 == 1) {
      SetLEDBlinkEvent(0xb);
      MSrv_Control_common::GetMSrvSystemDatabase();
      iVar3 = MSrv_System_Database::GetFactBreathingLED();
      if (iVar3 == 0) {
        SetLEDBlinkEvent(6);
      }
      return 0;
    }
  }
  return 1;
}

