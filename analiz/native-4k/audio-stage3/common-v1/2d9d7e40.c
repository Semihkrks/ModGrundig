
/* MW_DTV_AVMonitor::DoStart(MW_DTV_AVInfo&) */

void __thiscall MW_DTV_AVMonitor::DoStart(MW_DTV_AVMonitor *this,MW_DTV_AVInfo *param_1)

{
  MW_DTV_AVMonitor MVar1;
  undefined2 uVar2;
  MW_DTV_AVMonitor *pMVar3;
  uchar uVar4;
  int iVar5;
  MSAPI_AUDIO_OUTPORT_SOURCE_INFO *pMVar6;
  int *piVar7;
  bool bVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  MW_DTV_AVInfo MVar12;
  MW_DTV_AVInfo *pMVar13;
  MW_DTV_AVMonitor *pMVar14;
  MW_DTV_AVInfo *pMVar15;
  bool bVar16;
  mapi_scope_lock amStack_68 [4];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [Test version = 0x20] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x639);
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [main audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x63a,(uint)*(ushort *)(param_1 + 0x12));
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [AD   audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x63b,(uint)*(ushort *)(param_1 + 0x14));
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [Bma  audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x63c,(uint)*(ushort *)(param_1 + 0x16));
  uVar4 = MSrv_Control_TV::GetMSrvDtv(0);
  if (*(short *)(param_1 + 0x14) == 0x1fff) {
    if (*(short *)(param_1 + 0x16) != 0x1fff) goto LAB_2d9d88d4;
LAB_2d9d7f4c:
    MSrv_DTV_Player_DVB::SetAudLangManualSelect(uVar4);
    MVar1 = this[0x1a0];
  }
  else {
    if (*(short *)(param_1 + 0x16) == 0x1fff) goto LAB_2d9d7f4c;
LAB_2d9d88d4:
    iVar5 = MSrv_DTV_Player_DVB::GetAudLangManualSelect();
    if (iVar5 == 0) {
      if (this[0x1a0] == (MW_DTV_AVMonitor)0x0) {
        printf("\n %s %s %d u16AudPID= %d *** ADAud=%d  \n",&UNK_2da4ab08,&UNK_2da4b8c8,0x654,
               (uint)*(ushort *)(param_1 + 0x12),(uint)*(ushort *)(param_1 + 0x14));
        *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_1 + 0x16);
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x18);
        *(undefined2 *)(param_1 + 0x16) = 0x1fff;
        MSrv_DTV_Player_DVB::SetCurrentAudioIndex(uVar4);
        if (*(short *)(param_1 + 0x12) == *(short *)(param_1 + 0x14)) {
          *(undefined2 *)(param_1 + 0x14) = 0x1fff;
          puts("\n    cCurrAVInfo.u16AudioPID  == cCurrAVInfo.u16ADAudioPID  *****  ");
        }
      }
      else {
        uVar2 = *(undefined2 *)(param_1 + 0x16);
        *(undefined2 *)(param_1 + 0x16) = 0x1fff;
        *(undefined2 *)(param_1 + 0x14) = uVar2;
      }
      goto LAB_2d9d7f4c;
    }
    if (this[0x1a0] == (MW_DTV_AVMonitor)0x0) {
      *(undefined2 *)(param_1 + 0x14) = 0x1fff;
      *(undefined2 *)(param_1 + 0x16) = 0x1fff;
    }
    else {
      *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_1 + 0x16);
      *(undefined2 *)(param_1 + 0x16) = 0x1fff;
    }
    MSrv_DTV_Player_DVB::SetAudLangManualSelect(uVar4);
    MVar1 = this[0x1a0];
  }
  if ((MVar1 == (MW_DTV_AVMonitor)0x1) && (*(short *)(param_1 + 0x14) == 0x1fff)) {
    pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
    mapi_audio::GetOutputSourceInfo(pMVar6);
    local_58 = 0;
    pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
    mapi_audio::SetOutputSourceInfo(pMVar6);
  }
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [modified main audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x673,(uint)*(ushort *)(param_1 + 0x12));
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [modified AD   audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x674,(uint)*(ushort *)(param_1 + 0x14));
  printf("\x1b[0;32m [AUDIO][%s] [%s] [%d] [modified Bma  audio PID = %d] \x1b[0m \n",&UNK_2da4ab08,
         &UNK_2da4b8c8,0x675,(uint)*(ushort *)(param_1 + 0x16));
  if (param_1[0x28] == (MW_DTV_AVInfo)0x0) {
    if ((*(short *)(param_1 + 0x10) == *(short *)(this + 0xb0)) &&
       (*(MW_DTV_AVMonitor *)(param_1 + 0x26) == this[0xc6])) {
      if ((this[0x115] == (MW_DTV_AVMonitor)0x0) || (param_1[0x25] == (MW_DTV_AVInfo)0x0))
      goto LAB_2d9d7ff8;
      piVar7 = *(int **)(this + 0x154);
    }
    else {
      piVar7 = *(int **)(this + 0x154);
    }
    (**(code **)(*piVar7 + 0x18))();
    if (this[0xc6] != *(MW_DTV_AVMonitor *)(param_1 + 0x26)) {
      (**(code **)(**(int **)(this + 0x154) + 0xc))();
    }
    if (*(short *)(param_1 + 0x10) != 0x1fff) {
      (**(code **)(**(int **)(this + 0x154) + 0x28))();
      (**(code **)(**(int **)(this + 0x154) + 0x14))();
      *(undefined4 *)(this + 0x94) = 0xff;
      *(undefined4 *)(this + 0x98) = 0;
    }
    this[0x115] = (MW_DTV_AVMonitor)0x0;
    *(undefined4 *)(this + 0x11c) = 0;
    iVar5 = MSrv_Control_TV::GetMSrvDtv(0);
    uVar9 = 0;
    if (iVar5 != 0) {
      uVar9 = __dynamic_cast(iVar5,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
    }
    MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar9,9,0,0);
  }
  else if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x30) != 0)) {
    mapi_vdec::Stop();
    this[0x92] = (MW_DTV_AVMonitor)0x0;
    DecodeIframe(this,*(ulong *)(param_1 + 0x2c),*(ulong *)(param_1 + 0x30),*(int *)param_1 == 2);
    SetMuteFlag(this,'\0',1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    mapi_scope_lock::mapi_scope_lock
              (amStack_68,(pthread_mutex_t *)(this + 0x50),
               "void MW_DTV_AVMonitor::DoStart(MW_DTV_AVInfo&)",0x698);
    pMVar15 = param_1;
    pMVar3 = this + 0xd8;
    do {
      pMVar14 = pMVar3;
      pMVar13 = pMVar15;
      uVar9 = *(undefined4 *)(pMVar13 + 4);
      uVar10 = *(undefined4 *)(pMVar13 + 8);
      uVar11 = *(undefined4 *)(pMVar13 + 0xc);
      pMVar15 = pMVar13 + 0x10;
      *(undefined4 *)pMVar14 = *(undefined4 *)pMVar13;
      *(undefined4 *)(pMVar14 + 4) = uVar9;
      *(undefined4 *)(pMVar14 + 8) = uVar10;
      *(undefined4 *)(pMVar14 + 0xc) = uVar11;
      pMVar3 = pMVar14 + 0x10;
    } while (pMVar15 != param_1 + 0x30);
    *(undefined4 *)(pMVar14 + 0x10) = *(undefined4 *)pMVar15;
    *(undefined2 *)(pMVar14 + 0x14) = *(undefined2 *)(pMVar13 + 0x14);
    pMVar14[0x16] = *(MW_DTV_AVMonitor *)(pMVar13 + 0x16);
    mapi_scope_lock::~mapi_scope_lock(amStack_68);
  }
LAB_2d9d7ff8:
  if ((*(short *)(param_1 + 0x1e) != *(short *)(this + 0xbe)) ||
     (*(MW_DTV_AVMonitor *)(param_1 + 0x26) != this[0xc6])) {
    (**(code **)(**(int **)(this + 0x160) + 0x18))();
    if (this[0xc6] != *(MW_DTV_AVMonitor *)(param_1 + 0x26)) {
      (**(code **)(**(int **)(this + 0x160) + 0xc))();
    }
    if (((param_1[0x36] != (MW_DTV_AVInfo)0x1) && (*(short *)(param_1 + 0x1e) != 0x1fff)) &&
       ((**(code **)(**(int **)(this + 0x160) + 0x28))(), this[0x1d4] == (MW_DTV_AVMonitor)0x0)) {
      (**(code **)(**(int **)(this + 0x160) + 0x14))();
    }
  }
  if ((*(short *)(param_1 + 0x12) == *(short *)(this + 0xb2)) &&
     (*(MW_DTV_AVMonitor *)(param_1 + 0x26) == this[0xc6])) {
    if ((param_1[0x24] != (MW_DTV_AVInfo)0x0) && (this[0x117] != (MW_DTV_AVMonitor)0x0)) {
      piVar7 = *(int **)(this + 0x158);
      goto LAB_2d9d807c;
    }
LAB_2d9d80c4:
    if (*(short *)(param_1 + 0x14) != *(short *)(this + 0xb4)) goto LAB_2d9d80d4;
LAB_2d9d869c:
    if (*(MW_DTV_AVMonitor *)(param_1 + 0x26) != this[0xc6]) goto LAB_2d9d80d4;
    if (this[0x1a1] != (MW_DTV_AVMonitor)0x0) {
      piVar7 = *(int **)(this + 0x15c);
      goto LAB_2d9d80d8;
    }
  }
  else {
    piVar7 = *(int **)(this + 0x158);
LAB_2d9d807c:
    (**(code **)(*piVar7 + 0x18))();
    if (this[0xc6] != *(MW_DTV_AVMonitor *)(param_1 + 0x26)) {
      (**(code **)(**(int **)(this + 0x158) + 0xc))();
    }
    if (*(short *)(param_1 + 0x12) == 0x1fff) goto LAB_2d9d80c4;
    (**(code **)(**(int **)(this + 0x158) + 0x28))();
    if (*(short *)(param_1 + 0x14) == *(short *)(this + 0xb4)) goto LAB_2d9d869c;
LAB_2d9d80d4:
    piVar7 = *(int **)(this + 0x15c);
LAB_2d9d80d8:
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x18))();
      if (this[0x1a0] == (MW_DTV_AVMonitor)0x0) {
        mapi_demux::FreePidFilter(*(mapi_demux_PID_filter ***)(this + 0x150));
        uVar9 = 2;
        if (*(int *)(this + 0x1c8) != 0) {
          uVar9 = 10;
        }
        *(undefined4 *)(this + 0x15c) = 0;
        iVar5 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),uVar9,0);
        *(int *)(this + 0x15c) = iVar5;
        if (iVar5 == 0) {
          uVar9 = 0x717;
LAB_2d9d8758:
          printf("ASSERT FAIL: %s %s %d\n",&UNK_2da4ab08,&UNK_2da4b898,uVar9);
                    /* WARNING: Subroutine does not return */
          abort();
        }
      }
      else {
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x70))(piVar7,0x25,1);
        mapi_demux::FreePidFilter(*(mapi_demux_PID_filter ***)(this + 0x150));
        *(undefined4 *)(this + 0x15c) = 0;
        iVar5 = mapi_demux::AllocatePidFilter(*(undefined4 *)(this + 0x150),2,0);
        *(int *)(this + 0x15c) = iVar5;
        if (iVar5 == 0) {
          uVar9 = 0x70f;
          goto LAB_2d9d8758;
        }
      }
      if (this[0xc6] != *(MW_DTV_AVMonitor *)(param_1 + 0x26)) {
        (**(code **)(**(int **)(this + 0x15c) + 0xc))();
      }
      if (*(short *)(param_1 + 0x14) != 0x1fff) {
        (**(code **)(**(int **)(this + 0x15c) + 0x28))();
      }
    }
  }
  if (param_1[0x28] == (MW_DTV_AVInfo)0x0) {
    if (*(short *)(param_1 + 0x10) == 0x1fff) {
      if ((this[0x115] != (MW_DTV_AVMonitor)0x0) ||
         ((param_1[0x34] != (MW_DTV_AVInfo)0x0 && (param_1[0x25] != (MW_DTV_AVInfo)0x1))))
      goto LAB_2d9d89a0;
      this[0x110] = (MW_DTV_AVMonitor)0x0;
      SetMuteFlag(this,'\x01',1);
      bVar8 = true;
      mapi_vdec::Stop();
      goto LAB_2d9d81b0;
    }
    if (param_1[0x25] != (MW_DTV_AVInfo)0x0) {
      this[0x1bc] = *(MW_DTV_AVMonitor *)(param_1 + 0x34);
      if (((*(short *)(param_1 + 0x10) != *(short *)(this + 0xb0)) ||
          (*(int *)param_1 != *(int *)(this + 0xa0))) ||
         (bVar8 = true, this[0x110] == (MW_DTV_AVMonitor)0x0)) {
        SetMuteFlag(this,'\x01',1);
        this[0x92] = (MW_DTV_AVMonitor)0x0;
        this[0x114] = (MW_DTV_AVMonitor)0x0;
        this[0x110] = (MW_DTV_AVMonitor)0x0;
        mapi_vdec::Stop();
        this[0x6e] = (MW_DTV_AVMonitor)0x0;
        bVar8 = true;
        if (*(int *)param_1 == 0) {
          this[0x110] = (MW_DTV_AVMonitor)0x0;
        }
        else {
          iVar5 = (**(code **)(**(int **)(this + 0x13c) + 0x44))();
          if (iVar5 != 0) {
            (**(code **)(**(int **)(this + 0x13c) + 0x40))(*(int **)(this + 0x13c),0,0);
          }
          MVar12 = param_1[0x26];
          if (MVar12 == (MW_DTV_AVInfo)0x0) {
            *(undefined4 *)(this + 0x10) = 0;
            *(undefined4 *)(this + 0x28) = 0;
            *(undefined4 *)(this + 0x14) = 0;
            *(undefined4 *)(this + 0x18) = 0;
            *(undefined4 *)(this + 0x1c) = 0;
            *(undefined4 *)(this + 0x20) = 0;
            *(undefined4 *)(this + 0x24) = 0;
            MVar12 = param_1[0x26];
          }
          bVar8 = false;
          mapi_vdec::SetVdecType(*(undefined4 *)(this + 0x138),*(undefined4 *)param_1,MVar12);
          mapi_vdec::SetCallBack
                    (*(ulong *)(this + 0x138),(_func_void_ulong_void_ptr *)0x48,VDEC_EventCb);
          mapi_vdec::Play();
          this[0x110] = (MW_DTV_AVMonitor)0x1;
          local_60 = 1;
          local_64 = 1;
          mapi_vdec::SetControl(*(VDEC_SET_CONTROL **)(this + 0x138));
        }
      }
      if (this[0x1bc] == (MW_DTV_AVMonitor)0x1) {
        SetMuteFlag(this,'\0',1);
      }
      goto LAB_2d9d81b0;
    }
LAB_2d9d89a0:
    bVar8 = true;
    SetPollingChannelChangeStatusFlag('\x01');
    bVar16 = *(int *)(this + 0x1c8) != 0;
    if (*(short *)(param_1 + 0x12) != 0x1fff) goto LAB_2d9d81d0;
LAB_2d9d89c8:
    uVar9 = 0;
    piVar7 = (int *)MSrv_Control::GetInstance();
    iVar5 = (**(code **)(*piVar7 + 0x84))(piVar7);
  }
  else {
    this[0x115] = (MW_DTV_AVMonitor)0x1;
    this[0x110] = (MW_DTV_AVMonitor)0x0;
    bVar8 = true;
LAB_2d9d81b0:
    SetPollingChannelChangeStatusFlag('\x01');
    bVar16 = *(int *)(this + 0x1c8) != 0;
    if (*(short *)(param_1 + 0x12) == 0x1fff) goto LAB_2d9d89c8;
LAB_2d9d81d0:
    if (param_1[0x24] == (MW_DTV_AVInfo)0x0) {
      if (this[0x117] != (MW_DTV_AVMonitor)0x0) {
        (**(code **)(**(int **)(this + 0x158) + 0x18))();
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,0,bVar16);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x44))(piVar7,*(undefined4 *)(param_1 + 4),bVar16);
        mapi_audio_customer::GetInstance();
        mapi_audio_customer::SetDelaysForDTVSource();
        puts("\n SCALE-2 --22222222----------------------------------- ");
        piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
        (**(code **)(*piVar7 + 0x4c))(piVar7,0x1c);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x20))(piVar7);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,1,bVar16);
        (**(code **)(**(int **)(this + 0x158) + 0x14))();
        this[0x117] = (MW_DTV_AVMonitor)0x0;
      }
      goto LAB_2d9d89c8;
    }
    this[0x1bc] = *(MW_DTV_AVMonitor *)(param_1 + 0x34);
    if (*(int *)(param_1 + 4) == 0xff) {
      this[0x111] = (MW_DTV_AVMonitor)0x0;
      goto LAB_2d9d89c8;
    }
    if (((*(int *)(param_1 + 4) == *(int *)(this + 0xa4)) &&
        (*(int *)(param_1 + 8) == *(int *)(this + 0xa8))) &&
       ((*(short *)(param_1 + 0x12) == *(short *)(this + 0xb2) &&
        (this[0x111] != (MW_DTV_AVMonitor)0x0)))) {
      uVar9 = 0;
      (**(code **)(**(int **)(this + 0x158) + 0x14))();
      this[0x111] = (MW_DTV_AVMonitor)0x1;
    }
    else {
      SetMuteFlag(this,'\x01',2);
      (**(code **)(**(int **)(this + 0x158) + 0x18))();
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      (**(code **)(*piVar7 + 100))(piVar7,bVar16,&local_48);
      if (param_1[0x26] == (MW_DTV_AVInfo)0x0) {
        local_38 = *(undefined4 *)(*(int *)(this + 0x150) + 8);
      }
      else {
        local_38 = 0;
      }
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      (**(code **)(*piVar7 + 0x5c))(piVar7,bVar16,&local_48);
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      (**(code **)(*piVar7 + 0x38))(piVar7,0,bVar16);
      if (*(int *)(param_1 + 4) != *(int *)(this + 0xa4)) {
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x44))(piVar7,*(undefined4 *)(param_1 + 4),bVar16);
      }
      uVar9 = local_38;
      mapi_audio_customer::GetInstance();
      mapi_audio_customer::SetDelaysForDTVSource();
      puts("\n SCALE-1 --11111111----------------------------------- ");
      piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
      (**(code **)(*piVar7 + 0x4c))(piVar7,0x1c);
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      (**(code **)(*piVar7 + 0x20))(piVar7);
      if (param_1[0x36] == (MW_DTV_AVInfo)0x1) {
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,3,bVar16);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,7,bVar16);
        printf("filein audio[%s:%d]\n",&UNK_2da4ab08,0x81f);
        piVar7 = *(int **)(this + 0x158);
      }
      else {
        if (*(short *)(param_1 + 0x1e) == 0x1fff) {
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          iVar5 = *piVar7;
          uVar10 = 3;
        }
        else {
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          iVar5 = *piVar7;
          uVar10 = 4;
        }
        (**(code **)(iVar5 + 0x38))(piVar7,uVar10,bVar16);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,1,bVar16);
        piVar7 = *(int **)(this + 0x158);
      }
      (**(code **)(*piVar7 + 0x14))();
      if (*(int *)(param_1 + 8) == 2) {
        uVar10 = mapi_interface_common::Get_mapi_audio();
        mapi_audio::DECODER_SetOutputMode(uVar10,2);
        this[0x111] = (MW_DTV_AVMonitor)0x1;
      }
      else if (*(int *)(param_1 + 8) == 1) {
        uVar10 = mapi_interface_common::Get_mapi_audio();
        mapi_audio::DECODER_SetOutputMode(uVar10,1);
        this[0x111] = (MW_DTV_AVMonitor)0x1;
      }
      else {
        uVar10 = mapi_interface_common::Get_mapi_audio();
        mapi_audio::DECODER_SetOutputMode(uVar10,0);
        this[0x111] = (MW_DTV_AVMonitor)0x1;
      }
    }
    piVar7 = (int *)MSrv_Control::GetInstance();
    iVar5 = (**(code **)(*piVar7 + 0x84))(piVar7);
  }
  if (iVar5 != 0x1c) goto LAB_2d9d89f0;
  if (*(short *)(param_1 + 0x14) == 0x1fff) {
    uVar4 = mapi_interface_common::Get_mapi_audio();
    mapi_audio::DECODER_SetADEnable(uVar4);
    piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar7 + 0x38))(piVar7,0xe,bVar16);
  }
  else {
    if (param_1[0x24] == (MW_DTV_AVInfo)0x0) goto LAB_2d9d89f0;
    if (*(int *)(param_1 + 0xc) != 0xff) {
      if (((*(short *)(this + 0xb4) == *(short *)(param_1 + 0x14)) &&
          (*(int *)(param_1 + 0xc) == *(int *)(this + 0xac))) &&
         ((this[0x112] != (MW_DTV_AVMonitor)0x0 && (this[0x1a1] == (MW_DTV_AVMonitor)0x0)))) {
        if (*(int **)(this + 0x15c) != (int *)0x0) {
          (**(code **)(**(int **)(this + 0x15c) + 0x14))();
        }
        this[0x112] = (MW_DTV_AVMonitor)0x1;
      }
      else {
        puts("\n SCALE-3 --33333333333----------------------------------- ");
        piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
        (**(code **)(*piVar7 + 0x4c))(piVar7,0x1c);
        if (this[0x1a0] == (MW_DTV_AVMonitor)0x0) {
          MApi_AUDIO_SetCommAudioInfo(0x4f,0,0);
          SetMuteFlag(this,'\x01',2);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x38))(piVar7,0xe,bVar16);
          uVar4 = mapi_interface_common::Get_mapi_audio();
          mapi_audio::DECODER_SetADEnable(uVar4);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x38))(piVar7,0xd,bVar16);
          pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
          mapi_audio::GetOutputSourceInfo(pMVar6);
          local_58 = 0;
          pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
          mapi_audio::SetOutputSourceInfo(pMVar6);
        }
        else {
          MApi_AUDIO_SetCommAudioInfo(0x4f,3,0);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x38))(piVar7,0xe,bVar16);
          local_48 = 0;
          local_44 = 0;
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 100))(piVar7,1,&local_48);
          pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
          mapi_audio::GetOutputSourceInfo(pMVar6);
          local_58 = 1;
          pMVar6 = (MSAPI_AUDIO_OUTPORT_SOURCE_INFO *)mapi_interface_common::Get_mapi_audio();
          mapi_audio::SetOutputSourceInfo(pMVar6);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x54))(piVar7,local_30);
          SetMuteFlag(this,'\x01',2);
          local_3c = *(undefined4 *)(param_1 + 0xc);
          local_40 = 0x1c;
          local_44 = 1;
          local_38 = uVar9;
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x50))(piVar7,&local_48);
          mapi_audio_customer::GetInstance();
          mapi_audio_customer::SetDelaysForDTVSource();
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x38))(piVar7,1,1);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x5c))(piVar7,1,&local_48);
        }
        if (*(int **)(this + 0x15c) != (int *)0x0) {
          (**(code **)(**(int **)(this + 0x15c) + 0x14))();
        }
        this[0x1a1] = (MW_DTV_AVMonitor)0x0;
        this[0x112] = (MW_DTV_AVMonitor)0x1;
      }
      goto LAB_2d9d89f0;
    }
  }
  this[0x112] = (MW_DTV_AVMonitor)0x0;
LAB_2d9d89f0:
  if (((*(short *)(param_1 + 0x12) == 0x1fff) || (*(int *)(param_1 + 4) == 0xff)) &&
     (this[0x110] != (MW_DTV_AVMonitor)0x0)) {
    mapi_vdec::SyncOn((uchar)*(undefined4 *)(this + 0x138));
  }
  else {
    mapi_vdec::SyncOn((uchar)*(undefined4 *)(this + 0x138));
  }
  if (((this[0x110] == (MW_DTV_AVMonitor)0x0) && (this[0x111] != (MW_DTV_AVMonitor)0x0)) ||
     ((((bVar8 && ((this[0x111] != (MW_DTV_AVMonitor)0x0 && (this[0x110] != (MW_DTV_AVMonitor)0x0)))
        ) && (this[0x92] != (MW_DTV_AVMonitor)0x0)) && (this[0x6e] == (MW_DTV_AVMonitor)0x0)))) {
    SetMuteFlag(this,'\0',2);
  }
  if ((param_1[0x24] != (MW_DTV_AVInfo)0x0) && (param_1[0x25] == (MW_DTV_AVInfo)0x0)) {
    SetMuteFlag(this,'\0',2);
  }
  if ((this[0x111] != (MW_DTV_AVMonitor)0x0) && (this[0x110] != (MW_DTV_AVMonitor)0x0)) {
    uVar9 = mapi_time_utility::GetTime0();
    *(undefined4 *)(this + 0x84) = uVar9;
  }
  if (this[0x188] != (MW_DTV_AVMonitor)0x0) {
    (**(code **)(this + 0x18c))(0,0,0,*(undefined4 *)(this + 400));
  }
  if (this[0x194] != (MW_DTV_AVMonitor)0x0) {
    bVar8 = false;
    if (this[0x110] != (MW_DTV_AVMonitor)0x0) {
      bVar8 = *(short *)(param_1 + 0x10) != *(short *)(this + 0xb0);
    }
    bVar16 = false;
    if (this[0x111] != (MW_DTV_AVMonitor)0x0) {
      bVar16 = *(short *)(param_1 + 0x12) != *(short *)(this + 0xb2);
    }
    (**(code **)(this + 0x198))(0,bVar8,bVar16,*(undefined4 *)(this + 0x19c));
  }
  pMVar3 = this + 0xa0;
  pMVar15 = param_1;
  do {
    pMVar13 = pMVar15;
    pMVar14 = pMVar3;
    uVar9 = *(undefined4 *)(pMVar13 + 4);
    uVar10 = *(undefined4 *)(pMVar13 + 8);
    uVar11 = *(undefined4 *)(pMVar13 + 0xc);
    pMVar15 = pMVar13 + 0x10;
    *(undefined4 *)pMVar14 = *(undefined4 *)pMVar13;
    *(undefined4 *)(pMVar14 + 4) = uVar9;
    *(undefined4 *)(pMVar14 + 8) = uVar10;
    *(undefined4 *)(pMVar14 + 0xc) = uVar11;
    pMVar3 = pMVar14 + 0x10;
  } while (pMVar15 != param_1 + 0x30);
  *(undefined4 *)(pMVar14 + 0x10) = *(undefined4 *)pMVar15;
  *(undefined2 *)(pMVar14 + 0x14) = *(undefined2 *)(pMVar13 + 0x14);
  pMVar14[0x16] = *(MW_DTV_AVMonitor *)(pMVar13 + 0x16);
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar5 = MSrv_System_Database::GetARCSetting();
  if (iVar5 != 0) {
    piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
    iVar5 = (**(code **)(*piVar7 + 0x78))(piVar7);
    if (iVar5 != 0) {
      piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
      iVar5 = (**(code **)(*piVar7 + 0x7c))(piVar7);
      if (iVar5 != 0) {
        piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
        (**(code **)(*piVar7 + 0x74))(piVar7);
      }
    }
  }
  return;
}

