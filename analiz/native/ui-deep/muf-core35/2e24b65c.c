
/* MTimerManager::ResetTimer(MEvtHandle const*, unsigned long) */

undefined4 __thiscall
MTimerManager::ResetTimer(MTimerManager *this,MEvtHandle *param_1,ulong param_2)

{
  int *piVar1;
  uint uVar2;
  pthread_mutex_t *__mutex;
  timespec local_20;
  
  __mutex = (pthread_mutex_t *)(this + 0x20);
  pthread_mutex_lock(__mutex);
  piVar1 = *(int **)(this + 4);
  while( true ) {
    if (*(int **)(this + 8) == piVar1) {
      pthread_mutex_unlock(__mutex);
      return 0;
    }
    if (((MEvtHandle *)*piVar1 == param_1) && (piVar1[2] == param_2)) break;
    piVar1 = piVar1 + 7;
  }
  clock_gettime(mufclockid4timer,&local_20);
  if ((uint)piVar1[1] < 1000) {
    piVar1[4] = local_20.tv_sec;
  }
  else {
    piVar1[4] = (uint)piVar1[1] / 1000 + local_20.tv_sec;
  }
  uVar2 = ((uint)piVar1[1] % 1000) * 1000000 + local_20.tv_nsec;
  piVar1[5] = uVar2;
  if (999999999 < uVar2) {
    piVar1[5] = uVar2 + 0xc4653600;
    piVar1[4] = piVar1[4] + 1;
  }
  std::
  sort_heap<__gnu_cxx::__normal_iterator<ST_TMRMGR_DATUM*,std::vector<ST_TMRMGR_DATUM,std::allocator<ST_TMRMGR_DATUM>>>,bool(*)(ST_TMRMGR_DATUM_const&,ST_TMRMGR_DATUM_const&)>
            (*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),data_cmp);
  pthread_mutex_unlock(__mutex);
  pthread_cond_signal((pthread_cond_t *)(this + 0x38));
  return 1;
}

