
/* MEvtHandle::SetTimer(unsigned long, unsigned long, EN_TIMER_MODE) */

undefined4
MEvtHandle::SetTimer(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_GetMTimerManager_2e2b460c)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_AddTimer_2e2b41b0)(iVar1,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  (*(code *)PTR_printf_2e2b3ee0)
            (PTR_PTR_2e2b3908 + -0x73a0,PTR_PTR_2e2b3908 + -0x5d04,PTR_PTR_2e2b3908 + -0x5c6c,0x122)
  ;
                    /* WARNING: Subroutine does not return */
  (*(code *)PTR_abort_2e2b3bc8)();
}

