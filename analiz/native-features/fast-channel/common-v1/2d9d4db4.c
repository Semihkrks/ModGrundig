
/* MW_DTV_AVMonitor::MW_DTV_AVMonitor(MAPI_SCALER_WIN, MAPI_DECODER_PATH, mapi_demux*) */

void __thiscall
MW_DTV_AVMonitor::MW_DTV_AVMonitor
          (MW_DTV_AVMonitor *this,int param_2,undefined4 param_3,ulong param_4)

{
  MW_DTV_AVMonitor MVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  mapi_event<MW_DTV_AVInfo> *this_00;
  char *pcVar5;
  int *piVar6;
  pthread_mutexattr_t pStack_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  pthread_attr_t pStack_40;
  
  *(undefined ***)this = &PTR__MW_DTV_AVMonitor_2da87ee0;
  *(undefined2 *)(this + 0xee) = 0x1fff;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0xff;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = 0xff;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined2 *)(this + 0xb0) = 0x1fff;
  *(undefined2 *)(this + 0xb2) = 0x1fff;
  *(undefined2 *)(this + 0xbe) = 0x1fff;
  *(undefined2 *)(this + 0xb4) = 0x1fff;
  *(undefined2 *)(this + 0xb6) = 0x1fff;
  *(undefined4 *)(this + 0xb8) = 0xff;
  this[0xbc] = (MW_DTV_AVMonitor)0x0;
  this[0xc4] = (MW_DTV_AVMonitor)0x1;
  this[0xc5] = (MW_DTV_AVMonitor)0x1;
  this[0xc6] = (MW_DTV_AVMonitor)0x0;
  this[200] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  this[0xd4] = (MW_DTV_AVMonitor)0x0;
  this[0xd5] = (MW_DTV_AVMonitor)0x0;
  this[199] = (MW_DTV_AVMonitor)0x0;
  this[0xd6] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0xff;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0xff;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined2 *)(this + 0xe8) = 0x1fff;
  *(undefined2 *)(this + 0xea) = 0x1fff;
  *(undefined2 *)(this + 0xf6) = 0x1fff;
  *(undefined2 *)(this + 0xec) = 0x1fff;
  *(undefined4 *)(this + 0xf0) = 0xff;
  this[0xfd] = (MW_DTV_AVMonitor)0x1;
  this[0xf4] = (MW_DTV_AVMonitor)0x0;
  this[0xfc] = (MW_DTV_AVMonitor)0x1;
  this[0xfe] = (MW_DTV_AVMonitor)0x0;
  this[0x100] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  this[0x10c] = (MW_DTV_AVMonitor)0x0;
  this[0x10d] = (MW_DTV_AVMonitor)0x0;
  this[0xff] = (MW_DTV_AVMonitor)0x0;
  this[0x10e] = (MW_DTV_AVMonitor)0x0;
  *(int *)(this + 0x1c8) = param_2;
  if (param_2 == 0) {
    *(undefined4 *)(this + 0xc) = 0x1c;
  }
  else {
    if (param_2 != 1) {
      uVar2 = 0xfa;
      goto LAB_2d9d5230;
    }
    *(undefined4 *)(this + 0xc) = 0x25;
  }
  *(undefined4 *)(this + 0x118) = 4;
  *(undefined4 *)(this + 0x94) = 0xff;
  *(undefined4 *)(this + 0x68) = 3;
  *(undefined2 *)(this + 0x1d6) = 0x32;
  this[0x6d] = (MW_DTV_AVMonitor)0x1;
  *(undefined4 *)(this + 0x9c) = 5;
  this[0x6c] = (MW_DTV_AVMonitor)0x1;
  this[0x1d4] = (MW_DTV_AVMonitor)0x0;
  this[0x110] = (MW_DTV_AVMonitor)0x0;
  this[0x111] = (MW_DTV_AVMonitor)0x0;
  this[0x112] = (MW_DTV_AVMonitor)0x0;
  this[0x113] = (MW_DTV_AVMonitor)0x0;
  this[0x114] = (MW_DTV_AVMonitor)0x0;
  this[0x1bc] = (MW_DTV_AVMonitor)0x0;
  this[0x1be] = (MW_DTV_AVMonitor)0x0;
  this[0x115] = (MW_DTV_AVMonitor)0x0;
  this[0x116] = (MW_DTV_AVMonitor)0x0;
  this[0x117] = (MW_DTV_AVMonitor)0x0;
  this[0x6e] = (MW_DTV_AVMonitor)0x0;
  this[0x88] = (MW_DTV_AVMonitor)0x0;
  this[0x89] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0x98) = 0;
  this[0x92] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  this[0x164] = (MW_DTV_AVMonitor)0x0;
  this[0x170] = (MW_DTV_AVMonitor)0x0;
  this[0x17c] = (MW_DTV_AVMonitor)0x0;
  this[0x34] = (MW_DTV_AVMonitor)0x2;
  this[0x188] = (MW_DTV_AVMonitor)0x0;
  this[0x194] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  this[0x124] = (MW_DTV_AVMonitor)0x0;
  *(undefined4 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  uVar2 = mapi_vdec::GetInstance(param_2 != 0);
  *(undefined4 *)(this + 0x138) = uVar2;
  uVar2 = mapi_interface_TV::Get_mapi_video(*(undefined4 *)(this + 0xc));
  *(undefined4 *)(this + 0x13c) = uVar2;
  uVar2 = mapi_interface_common::Get_mapi_video_out(0);
  *(undefined4 *)(this + 0x140) = uVar2;
  uVar2 = mapi_interface_common::Get_mapi_video_out(1);
  *(undefined4 *)(this + 0x144) = uVar2;
  uVar2 = mapi_interface_common::Get_mapi_pql(param_2);
  *(undefined4 *)(this + 0x148) = uVar2;
  uVar2 = mapi_interface_common::Get_mapi_display();
  *(undefined4 *)(this + 0x14c) = uVar2;
  *(ulong *)(this + 0x150) = param_4;
  if (param_4 == 0) {
    uVar2 = 0x15e;
  }
  else {
    if (param_2 == 0) {
      mapi_demux::SetDemuxStcSelect(param_4);
      uVar2 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),0,0);
      *(undefined4 *)(this + 0x154) = uVar2;
    }
    else {
      if (param_2 != 1) {
        uVar2 = 0x178;
        goto LAB_2d9d5230;
      }
      uVar3 = mapi_demux::GetDemuxStcCount();
      if (uVar3 < 2) {
        mapi_demux::SetDemuxStcSelect(*(ulong *)(this + 0x150));
        uVar2 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),8,0);
        *(undefined4 *)(this + 0x154) = uVar2;
        mapi_vdec::SetSubVdecToSyncMainStc((uchar)*(undefined4 *)(this + 0x138));
      }
      else {
        mapi_demux::SetDemuxStcSelect(*(ulong *)(this + 0x150));
        uVar2 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),8,0);
        *(undefined4 *)(this + 0x154) = uVar2;
        mapi_vdec::SetSubVdecToSyncMainStc((uchar)*(undefined4 *)(this + 0x138));
      }
    }
    if (*(int *)(this + 0x154) == 0) {
      uVar2 = 0x17b;
    }
    else {
      *(undefined2 *)(this + 4) = 0;
      *(undefined2 *)(this + 6) = 0;
      *(undefined2 *)(this + 8) = 0;
      *(undefined2 *)(this + 10) = 0;
      MVar1 = (MW_DTV_AVMonitor)DecideSeperateADValue();
      this[0x1a0] = MVar1;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      if (param_2 == 0) {
        piVar6 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar6 + 100))(piVar6,0,&local_5c);
        iVar4 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),1,0);
        *(int *)(this + 0x158) = iVar4;
        if (iVar4 == 0) {
          uVar2 = 0x1a8;
          goto LAB_2d9d5230;
        }
        iVar4 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),2,0);
        *(int *)(this + 0x15c) = iVar4;
        if (iVar4 == 0) {
          uVar2 = 0x1aa;
          goto LAB_2d9d5230;
        }
        local_4c = 0;
        piVar6 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar6 + 0x5c))(piVar6,0,&local_5c);
      }
      else if (param_2 == 1) {
        piVar6 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar6 + 100))(piVar6,1,&local_5c);
        iVar4 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),1,0);
        *(int *)(this + 0x158) = iVar4;
        if (iVar4 == 0) {
          uVar2 = 0x1b4;
          goto LAB_2d9d5230;
        }
        iVar4 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),2,0);
        *(int *)(this + 0x15c) = iVar4;
        if (iVar4 == 0) {
          puts("\nMAPI_DMX_PID_FILTER_TYPE_AUDIO4 allocate fail!!!!!!!!!");
        }
        local_4c = 1;
        piVar6 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar6 + 0x5c))(piVar6,1,&local_5c);
      }
      iVar4 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),6,0);
      *(int *)(this + 0x160) = iVar4;
      if (iVar4 == 0) {
        uVar2 = 0x1c0;
      }
      else {
        this_00 = operator_new(0x50,(nothrow_t *)&DAT_2c7f5bd0);
        if (this_00 == (mapi_event<MW_DTV_AVInfo> *)0x0) {
          *(undefined4 *)(this + 0x2c) = 0;
          uVar2 = 0x1c4;
        }
        else {
                    /* try { // try from 2d9d5110 to 2d9d5117 has its CatchHandler @ 2d9d5744 */
          mapi_event<MW_DTV_AVInfo>::mapi_event(this_00);
          *(mapi_event<MW_DTV_AVInfo> **)(this + 0x2c) = this_00;
          iVar4 = pthread_mutexattr_init(&pStack_60);
          if ((iVar4 != 0) && (iVar4 != 0x91)) {
            pcVar5 = strerror(iVar4);
            printf("[PTHREAD] %s: %d: %s: %s\n",&UNK_2da4ab08,0x1ce,&UNK_2da414cc,pcVar5);
          }
          iVar4 = pthread_mutexattr_settype(&pStack_60,1);
          if ((iVar4 != 0) && (iVar4 != 0x91)) {
            pcVar5 = strerror(iVar4);
            printf("[PTHREAD] %s: %d: %s: %s\n",&UNK_2da4ab08,0x1cf,&UNK_2da414ec,pcVar5);
          }
          iVar4 = pthread_mutex_init((pthread_mutex_t *)(this + 0x38),&pStack_60);
          if (iVar4 == 0) {
            iVar4 = pthread_mutex_init((pthread_mutex_t *)(this + 0x50),&pStack_60);
            if (iVar4 == 0) {
              SetVideoStatus(this,0);
              pthread_attr_init(&pStack_40);
              pthread_attr_setstacksize(&pStack_40,0x100000);
              iVar4 = pthread_create((pthread_t *)(this + 0x30),&pStack_40,AVMonitorThreadFunc,this)
              ;
              if (iVar4 == 0) {
                *(undefined4 *)(this + 0x10) = 0;
                *(undefined4 *)(this + 0x28) = 0;
                *(undefined4 *)(this + 0x14) = 0;
                *(undefined4 *)(this + 0x18) = 0;
                *(undefined4 *)(this + 0x1c) = 0;
                *(undefined4 *)(this + 0x20) = 0;
                *(undefined4 *)(this + 0x24) = 0;
                uVar2 = mapi_time_utility::GetTime0();
                this[0x1bd] = (MW_DTV_AVMonitor)0x0;
                this[0x134] = (MW_DTV_AVMonitor)0x0;
                *(undefined4 *)(this + 300) = uVar2;
                *(undefined4 *)(this + 0x1d0) = 0;
                *(undefined4 *)(this + 0x1c0) = 0;
                *(undefined4 *)(this + 0x1cc) = 0;
                *(undefined4 *)(this + 0x130) = 0;
                return;
              }
              if (iVar4 != 0x91) {
                pcVar5 = strerror(iVar4);
                printf("[PTHREAD] %s: %d: %s: %s\n",&UNK_2da4ab08,0x1e1,&UNK_2da4ae08,pcVar5);
              }
              uVar2 = 0x1e2;
            }
            else {
              if (iVar4 != 0x91) {
                pcVar5 = strerror(iVar4);
                printf("[PTHREAD] %s: %d: %s: %s\n",&UNK_2da4ab08,0x1d2,&UNK_2da4addc,pcVar5);
              }
              uVar2 = 0x1d3;
            }
          }
          else {
            if (iVar4 != 0x91) {
              pcVar5 = strerror(iVar4);
              printf("[PTHREAD] %s: %d: %s: %s\n",&UNK_2da4ab08,0x1d0,&UNK_2da4adac,pcVar5);
            }
            uVar2 = 0x1d1;
          }
        }
      }
    }
  }
LAB_2d9d5230:
  printf("ASSERT FAIL: %s %s %d\n",&UNK_2da4ab08,&UNK_2da4bcf8,uVar2);
                    /* WARNING: Subroutine does not return */
  abort();
}

