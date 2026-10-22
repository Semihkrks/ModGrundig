
void PT_Thread_MutexLock(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2f175358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_pthread_mutex_lock_tracker_2f18b1a0)(param_1,PTR_DAT_2f18aedc + -0x7370,0x6f);
    return;
  }
  return;
}

