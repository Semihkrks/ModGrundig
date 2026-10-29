
/* ArTvManager::SuspendSystem() */

void ArTvManager::SuspendSystem(void)

{
  undefined4 uVar1;
  
  uVar1 = ArSrvPowerManager::GetInstance();
  ArSrvPowerManager::SetPowerState(uVar1,2,0);
  return;
}

