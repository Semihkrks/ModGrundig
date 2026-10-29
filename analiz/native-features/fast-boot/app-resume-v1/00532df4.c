
/* ArTvManager::CancelStandby() */

void ArTvManager::CancelStandby(void)

{
  int iVar1;
  ArASUManager *pAVar2;
  
  ArSrvPowerManager::GetInstance();
  iVar1 = ArSrvPowerManager::GetPowerState();
  if (iVar1 == 3) {
    puts("###ArTvManager::CancelStandby");
    iVar1 = ArASUManager::getInstance();
    if (iVar1 != 0) {
      pAVar2 = (ArASUManager *)ArASUManager::getInstance();
      iVar1 = ArASUManager::IsASUStarted(pAVar2);
      if (iVar1 == 1) {
        SetLEDBlinkEvent(0xc);
        SetLEDBlinkEvent(9);
        pAVar2 = (ArASUManager *)ArASUManager::getInstance();
        ArASUManager::StopExistingASUUpdate(pAVar2);
      }
    }
  }
  return;
}

