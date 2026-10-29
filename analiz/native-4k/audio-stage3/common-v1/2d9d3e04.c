
/* WARNING: Removing unreachable block (ram,0x2d9d4518) */
/* WARNING: Removing unreachable block (ram,0x2d9d454c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* MW_DTV_AVMonitor::SetMuteFlag(unsigned char, unsigned long) */

void __thiscall MW_DTV_AVMonitor::SetMuteFlag(MW_DTV_AVMonitor *this,uchar param_1,ulong param_2)

{
  FILE *pFVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  allocator aaStack_380 [4];
  allocator aaStack_37c [12];
  mapi_scope_lock amStack_370 [4];
  int local_36c;
  int local_368;
  undefined1 auStack_364 [740];
  char local_80;
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_370,(pthread_mutex_t *)(this + 0x50),
             "void MW_DTV_AVMonitor::SetMuteFlag(MAPI_BOOL, MAPI_U32)",0x3d0);
  if (this[0x1be] == (MW_DTV_AVMonitor)0x0) {
    uVar5 = 0x1abfd;
    uVar7 = 0x1a0ce;
  }
  else {
    uVar5 = 0x15b31;
    uVar7 = 0x15002;
  }
  if (param_1 == '\0') {
    if ((param_2 & *(uint *)(this + 0x68)) == 0) goto LAB_2d9d3f84;
    if (param_2 == 0x6000) {
      param_2 = (uVar5 | uVar7) & 0x6000;
    }
    *(ulong *)(this + 0x68) = ~param_2 & *(uint *)(this + 0x68);
    if ((uVar5 & *(uint *)(this + 0x68)) != 0) goto LAB_2d9d3ea4;
LAB_2d9d3fe8:
    if (this[0x6c] == (MW_DTV_AVMonitor)0x0) goto LAB_2d9d3eb0;
    if (((this[0x110] == (MW_DTV_AVMonitor)0x0) && (this[0x114] == (MW_DTV_AVMonitor)0x0)) &&
       (this[0x1bc] != (MW_DTV_AVMonitor)0x1)) {
      this[0x6c] = (MW_DTV_AVMonitor)0x0;
    }
    else {
                    /* try { // try from 2d9d4010 to 2d9d40d7 has its CatchHandler @ 2d9d455c */
      piVar3 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      (**(code **)(*piVar3 + 0xd0))(piVar3,auStack_364);
      if (local_80 == '\0') {
        iVar2 = GetDebugLevel(5);
        if (2 < iVar2) {
          fprintf(_DAT_2c67c868,"\n[AR_VIDEOMANAGER][INFO] File: %s  Function: %s  Line: %d\n",
                  &UNK_2da4ab08,&UNK_2da4ba80,0x409);
        }
        uVar4 = ArVideoMuteManager::getInstance();
        ArVideoMuteManager::SetVideoMuteStatus(uVar4,7,*(undefined4 *)(this + 0x1c8),0,0);
      }
      pFVar1 = _DAT_2c67c868;
      uVar4 = mapi_time_utility::GetPiuTimer1();
      fprintf(pFVar1,"\x1b[0;31m [DTV channel change][%lu] : Unmute \x1b[0m\n",uVar4);
      pFVar1 = _DAT_2c67c868;
      uVar4 = mapi_time_utility::GetPiuTimer1();
      fprintf(pFVar1,"\x1b[1;31m[AUTO_TEST][channel change]: Unmute [PIU][%lu]\x1b[0m\n",uVar4);
      iVar2 = *(int *)(this + 0xc);
      if (((iVar2 == 0x1c) || (iVar2 == 0x25)) || (iVar2 == 0x27)) {
        iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
        uVar4 = 0;
        if (iVar2 != 0) {
          uVar4 = __dynamic_cast(iVar2,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
        }
        MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar4,0xd,0,0);
      }
                    /* try { // try from 2d9d410c to 2d9d4113 has its CatchHandler @ 2d9d4528 */
      std::string::string((string *)&local_36c,
                          "void MW_DTV_AVMonitor::SetMuteFlag(MAPI_BOOL, MAPI_U32)",aaStack_380);
                    /* try { // try from 2d9d412c to 2d9d4133 has its CatchHandler @ 2d9d4590 */
      std::string::string((string *)&local_368,"unmute video",aaStack_37c);
                    /* try { // try from 2d9d414c to 2d9d4153 has its CatchHandler @ 2d9d4564 */
      profiler::stop(&DAT_2f7b6994,(string *)&local_36c,0x421,(string *)&local_368,0);
      if ((allocator *)(local_368 + -0xc) != (allocator *)&DAT_2c828ab8) {
        SYNC(0);
        iVar2 = *(int *)(local_368 + -4);
        *(int *)(local_368 + -4) = iVar2 + -1;
        SYNC(0);
        if (iVar2 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_368 + -0xc));
        }
      }
      if ((allocator *)(local_36c + -0xc) != (allocator *)&DAT_2c828ab8) {
        SYNC(0);
        iVar2 = *(int *)(local_36c + -4);
        *(int *)(local_36c + -4) = iVar2 + -1;
        SYNC(0);
        if (iVar2 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_36c + -0xc));
          this[0x6c] = (MW_DTV_AVMonitor)0x0;
          goto LAB_2d9d4180;
        }
      }
      this[0x6c] = (MW_DTV_AVMonitor)0x0;
    }
LAB_2d9d4180:
    iVar2 = *(int *)(this + 0x1c8);
  }
  else {
    if ((param_2 & *(uint *)(this + 0x68)) != 0) goto LAB_2d9d3f84;
    *(ulong *)(this + 0x68) = param_2 | *(uint *)(this + 0x68);
    if ((uVar5 & *(uint *)(this + 0x68)) == 0) goto LAB_2d9d3fe8;
LAB_2d9d3ea4:
    if (this[0x6c] == (MW_DTV_AVMonitor)0x0) {
      uVar4 = ArVideoMuteManager::getInstance();
      ArVideoMuteManager::SetVideoMuteStatus(uVar4,6,*(undefined4 *)(this + 0x1c8),0,0);
      iVar2 = *(int *)(this + 0xc);
      if (((iVar2 == 0x1c) || (iVar2 == 0x25)) || (iVar2 == 0x27)) {
        iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
        uVar4 = 0;
        if (iVar2 != 0) {
          uVar4 = __dynamic_cast(iVar2,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
        }
        MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar4,0xc,0,0);
        this[0x6c] = (MW_DTV_AVMonitor)0x1;
      }
      else {
        this[0x6c] = (MW_DTV_AVMonitor)0x1;
      }
    }
LAB_2d9d3eb0:
    iVar2 = *(int *)(this + 0x1c8);
  }
  if (iVar2 == 0) {
                    /* try { // try from 2d9d3ebc to 2d9d3f7b has its CatchHandler @ 2d9d455c */
    piVar3 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar3 + 0x88))(piVar3);
    uVar5 = *(uint *)(this + 0x68);
  }
  else {
                    /* try { // try from 2d9d418c to 2d9d44cb has its CatchHandler @ 2d9d455c */
    piVar3 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar3 + 0x8c))(piVar3);
    uVar5 = *(uint *)(this + 0x68);
  }
  if (((uVar7 & uVar5) == 0) || ((uVar5 & 0x80) != 0)) {
    if ((this[0x111] == (MW_DTV_AVMonitor)0x0) && (this[0x116] == (MW_DTV_AVMonitor)0x0)) {
      if (this[0x1bc] != (MW_DTV_AVMonitor)0x1) goto LAB_2d9d3f84;
      iVar6 = *(int *)(this + 0xc);
    }
    else {
      iVar6 = *(int *)(this + 0xc);
    }
    if (iVar6 == iVar2) {
      if (*(int *)(this + 0x1c8) == 0) {
        piVar3 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar3 + 0x50))(piVar3,0x50,iVar6);
      }
      else {
        piVar3 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar3 + 0x50))(piVar3,0x92,iVar6);
      }
    }
    this[0x6d] = (MW_DTV_AVMonitor)0x0;
    if ((*(int *)(this + 0x1c8) == 0) &&
       (((iVar2 = *(int *)(this + 0xc), iVar2 == 0x1c || (iVar2 == 0x25)) || (iVar2 == 0x27)))) {
      iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
      uVar4 = 0;
      if (iVar2 != 0) {
        uVar4 = __dynamic_cast(iVar2,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
      }
      MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar4,0xf,0,0);
    }
  }
  else {
    iVar6 = *(int *)(this + 0xc);
    if (iVar6 == iVar2) {
      if (*(int *)(this + 0x1c8) == 0) {
        piVar3 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar3 + 0x50))(piVar3,0x51,iVar6);
      }
      else {
        piVar3 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar3 + 0x50))(piVar3,0x93,iVar6);
      }
    }
    this[0x6d] = (MW_DTV_AVMonitor)0x1;
    if ((*(int *)(this + 0x1c8) == 0) &&
       (((iVar2 = *(int *)(this + 0xc), iVar2 == 0x1c || (iVar2 == 0x25)) || (iVar2 == 0x27)))) {
      iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
      uVar4 = 0;
      if (iVar2 != 0) {
        uVar4 = __dynamic_cast(iVar2,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
      }
      MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar4,0xe,0,0);
    }
  }
LAB_2d9d3f84:
  mapi_scope_lock::~mapi_scope_lock(amStack_370);
  return;
}

