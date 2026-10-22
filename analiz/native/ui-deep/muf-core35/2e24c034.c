
/* MTimerManager::AddTimer(MEvtHandle*, unsigned long, unsigned long, EN_TIMER_MODE) */

undefined4 __thiscall
MTimerManager::AddTimer(MTimerManager *this,int param_1,uint param_2,int param_3,uint param_5)

{
  int *piVar1;
  int iVar2;
  pthread_mutex_t *__mutex;
  timespec local_48;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  
  __mutex = (pthread_mutex_t *)(this + 0x20);
  pthread_mutex_lock(__mutex);
  piVar1 = *(int **)(this + 4);
  while( true ) {
    if (piVar1 == *(int **)(this + 8)) {
      pthread_mutex_unlock(__mutex);
      local_34 = *(int *)(this + 0x18);
      local_28 = param_5;
      local_48.tv_sec = 0;
      local_48.tv_nsec = 0;
      local_40 = param_1;
      local_3c = param_2;
      local_38 = param_3;
      clock_gettime(mufclockid4timer,&local_48);
      if (param_2 < 1000) {
        local_30 = local_48.tv_sec;
      }
      else {
        local_30 = param_2 / 1000 + local_48.tv_sec;
      }
      local_2c = (param_2 % 1000) * 1000000 + local_48.tv_nsec;
      if (999999999 < local_2c) {
        local_2c = local_2c + 0xc4653600;
        local_30 = local_30 + 1;
      }
      *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
      pthread_mutex_lock(__mutex);
      piVar1 = *(int **)(this + 8);
      if (piVar1 == *(int **)(this + 0xc)) {
        std::vector<ST_TMRMGR_DATUM,std::allocator<ST_TMRMGR_DATUM>>::_M_insert_aux
                  ((vector<ST_TMRMGR_DATUM,std::allocator<ST_TMRMGR_DATUM>> *)(this + 4),piVar1,
                   &local_40);
      }
      else {
        iVar2 = 0;
        if (piVar1 != (int *)0x0) {
          piVar1[1] = local_3c;
          piVar1[6] = local_28;
          *piVar1 = local_40;
          piVar1[2] = local_38;
          piVar1[3] = local_34;
          piVar1[4] = local_30;
          piVar1[5] = local_2c;
          iVar2 = *(int *)(this + 8);
        }
        *(int *)(this + 8) = iVar2 + 0x1c;
      }
      if ((param_5 & 2) != 0) {
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
      }
      std::
      sort_heap<__gnu_cxx::__normal_iterator<ST_TMRMGR_DATUM*,std::vector<ST_TMRMGR_DATUM,std::allocator<ST_TMRMGR_DATUM>>>,bool(*)(ST_TMRMGR_DATUM_const&,ST_TMRMGR_DATUM_const&)>
                (*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),data_cmp);
      pthread_mutex_unlock(__mutex);
      pthread_cond_signal((pthread_cond_t *)(this + 0x38));
      return 1;
    }
    if ((*piVar1 == param_1) && (piVar1[2] == param_3)) break;
    piVar1 = piVar1 + 7;
  }
  pthread_mutex_unlock(__mutex);
  pthread_cond_signal((pthread_cond_t *)(this + 0x38));
  return 0;
}

