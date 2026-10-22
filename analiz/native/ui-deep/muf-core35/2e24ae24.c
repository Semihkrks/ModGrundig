
/* MTimerManager::tmr_mgr_thread(void*) */

void MTimerManager::tmr_mgr_thread(void *param_1)

{
  MWindowManager *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  pthread_mutex_t *__mutex;
  pthread_mutex_t *__mutex_00;
  timespec local_60;
  timespec local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  pthread_cond_t *local_30;
  
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  prctl(0xf,"MUF_MTimerManager");
  prctl(0x10,&local_50);
  printf("Thread name: %s.\n",&local_50);
  if (param_1 == (void *)0x0) {
    uVar4 = 0x22c;
  }
  else {
    this = (MWindowManager *)MSystem::GetMWindowManager();
    if (this == (MWindowManager *)0x0) {
      uVar4 = 0x22e;
    }
    else {
      iVar1 = MSystem::GetMTimerManager();
      if (iVar1 != 0) {
        __mutex = (pthread_mutex_t *)(iVar1 + 0x6c);
        pthread_mutex_lock(__mutex);
        local_30 = (pthread_cond_t *)(iVar1 + 0x38);
        pthread_cond_wait(local_30,__mutex);
        __mutex_00 = (pthread_mutex_t *)(iVar1 + 0x20);
        pthread_mutex_unlock(__mutex);
        do {
          if (*(char *)(iVar1 + 0x14) != '\0') {
                    /* WARNING: Subroutine does not return */
            pthread_exit((void *)0x0);
          }
          local_58.tv_sec = -1;
          local_58.tv_nsec = -1;
          clock_gettime(mufclockid4timer,&local_60);
          pthread_mutex_lock(__mutex_00);
          iVar5 = *(int *)(iVar1 + 4);
          iVar2 = *(int *)(iVar1 + 8);
          if (iVar2 != iVar5) {
            do {
              iVar2 = timespec_cmp(&local_60,(timespec *)(iVar5 + 0x10));
              if (iVar2 == 0) {
LAB_2e24b144:
                iVar2 = timespec_cmp(&local_58,(timespec *)(iVar5 + 0x10));
                if (iVar2 != 0) goto LAB_2e24b104;
              }
              else {
                MWindowManager::PostEvent
                          (this,(MEvtHandle *)0x0,(MEvtHandle *)0x0,0x17,*(ulong *)(iVar5 + 0xc),0);
                uVar3 = *(uint *)(iVar5 + 4);
                if (uVar3 < 1000) {
                  *(__time_t *)(iVar5 + 0x10) = local_60.tv_sec;
                }
                else {
                  *(uint *)(iVar5 + 0x10) = uVar3 / 1000 + local_60.tv_sec;
                }
                uVar3 = (uVar3 % 1000) * 1000000 + local_60.tv_nsec;
                *(uint *)(iVar5 + 0x14) = uVar3;
                if (999999999 < uVar3) {
                  *(uint *)(iVar5 + 0x14) = uVar3 + 0xc4653600;
                  *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
                }
                iVar2 = timespec_cmp(&local_60,&local_58);
                if (iVar2 == 0) goto LAB_2e24b144;
LAB_2e24b104:
                local_58.tv_sec = *(__time_t *)(iVar5 + 0x10);
                local_58.tv_nsec = *(long *)(iVar5 + 0x14);
              }
              iVar5 = iVar5 + 0x1c;
            } while (iVar5 != *(int *)(iVar1 + 8));
            iVar2 = *(int *)(iVar1 + 4);
          }
          std::
          sort_heap<__gnu_cxx::__normal_iterator<ST_TMRMGR_DATUM*,std::vector<ST_TMRMGR_DATUM,std::allocator<ST_TMRMGR_DATUM>>>,bool(*)(ST_TMRMGR_DATUM_const&,ST_TMRMGR_DATUM_const&)>
                    (iVar2,iVar5,data_cmp);
          pthread_mutex_unlock(__mutex_00);
          pthread_mutex_lock(__mutex);
          pthread_cond_timedwait(local_30,__mutex,&local_58);
          pthread_mutex_unlock(__mutex);
          pthread_mutex_lock(__mutex_00);
          if ((*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2) * -0x49249249 == 0) {
            pthread_mutex_unlock(__mutex_00);
            pthread_mutex_lock(__mutex);
            pthread_cond_wait(local_30,__mutex);
            pthread_mutex_unlock(__mutex);
          }
          else {
            pthread_mutex_unlock(__mutex_00);
          }
        } while( true );
      }
      uVar4 = 0x230;
    }
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MTimerManager.cpp",
         "static void* MTimerManager::tmr_mgr_thread(void*)",uVar4);
                    /* WARNING: Subroutine does not return */
  abort();
}

