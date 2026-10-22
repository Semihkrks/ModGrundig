
void PT_Thread_MutexUnlock(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2f17532c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_pthread_mutex_unlock_tracker_2f18b28c)();
    return;
  }
  return;
}

