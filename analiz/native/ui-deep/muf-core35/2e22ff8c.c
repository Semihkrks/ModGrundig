
/* MEvtHandle::SetTimer(unsigned long, unsigned long, EN_TIMER_MODE) */

undefined4
MEvtHandle::SetTimer(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  MTimerManager *pMVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  pMVar1 = (MTimerManager *)MSystem::GetMTimerManager();
  if (pMVar1 != (MTimerManager *)0x0) {
    uVar2 = MTimerManager::AddTimer(pMVar1,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MEvtHandle.cpp",
         "BOOL MEvtHandle::SetTimer(U32, U32, EN_TIMER_MODE)",0x122);
                    /* WARNING: Subroutine does not return */
  abort();
}

