
/* MW_DTV_AVMonitor::DoStartWithoutDmx(MW_DTV_AVInfo&) */

void __thiscall MW_DTV_AVMonitor::DoStartWithoutDmx(MW_DTV_AVMonitor *this,MW_DTV_AVInfo *param_1)

{
  bool bVar1;
  MW_DTV_AVMonitor *pMVar2;
  uchar uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  MW_DTV_AVMonitor *pMVar11;
  MW_DTV_AVInfo *pMVar12;
  MW_DTV_AVInfo *pMVar13;
  code *pcVar14;
  mapi_scope_lock amStack_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_1[0x28] == (MW_DTV_AVInfo)0x0) {
    sVar7 = *(short *)(param_1 + 0x10);
    if (((*(short *)(this + 0xb0) != sVar7) || (*(MW_DTV_AVMonitor *)(param_1 + 0x26) != this[0xc6])
        ) || ((this[0x115] != (MW_DTV_AVMonitor)0x0 && (param_1[0x25] != (MW_DTV_AVInfo)0x0)))) {
      if (sVar7 != 0x1fff) {
        *(undefined4 *)(this + 0x94) = 0xff;
        *(undefined4 *)(this + 0x98) = 0;
      }
      this[0x115] = (MW_DTV_AVMonitor)0x0;
      goto LAB_2d9d7760;
    }
LAB_2d9d7770:
    if (sVar7 == 0x1fff) {
      if (this[0x115] == (MW_DTV_AVMonitor)0x0) {
        SetMuteFlag(this,'\x01',1);
        this[0x110] = (MW_DTV_AVMonitor)0x0;
        bVar1 = true;
        mapi_vdec::Stop();
      }
      else {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
      if (param_1[0x25] != (MW_DTV_AVInfo)0x0) {
        this[0x1bc] = *(MW_DTV_AVMonitor *)(param_1 + 0x34);
        if (((*(short *)(param_1 + 0x10) != *(short *)(this + 0xb0)) ||
            (*(int *)param_1 != *(int *)(this + 0xa0))) ||
           (bVar1 = true, this[0x110] == (MW_DTV_AVMonitor)0x0)) {
          SetMuteFlag(this,'\x01',1);
          this[0x92] = (MW_DTV_AVMonitor)0x0;
          this[0x114] = (MW_DTV_AVMonitor)0x0;
          mapi_vdec::Stop();
          this[0x6e] = (MW_DTV_AVMonitor)0x0;
          bVar1 = true;
          if (*(int *)param_1 == 0) {
            this[0x110] = (MW_DTV_AVMonitor)0x0;
          }
          else {
            iVar6 = (**(code **)(**(int **)(this + 0x13c) + 0x44))();
            if (iVar6 != 0) {
              (**(code **)(**(int **)(this + 0x13c) + 0x40))(*(int **)(this + 0x13c),0,0);
            }
            *(undefined4 *)(this + 0x10) = 0;
            *(undefined4 *)(this + 0x28) = 0;
            *(undefined4 *)(this + 0x14) = 0;
            *(undefined4 *)(this + 0x18) = 0;
            *(undefined4 *)(this + 0x1c) = 0;
            *(undefined4 *)(this + 0x20) = 0;
            *(undefined4 *)(this + 0x24) = 0;
            bVar1 = false;
            mapi_vdec::SetVdecType
                      (*(undefined4 *)(this + 0x138),*(undefined4 *)param_1,param_1[0x26]);
            mapi_vdec::SetCallBack
                      (*(ulong *)(this + 0x138),(_func_void_ulong_void_ptr *)0x48,VDEC_EventCb);
            mapi_vdec::Play();
            this[0x110] = (MW_DTV_AVMonitor)0x1;
          }
        }
        if (this[0x1bc] == (MW_DTV_AVMonitor)0x1) {
          SetMuteFlag(this,'\0',1);
        }
      }
    }
  }
  else {
    if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x30) != 0)) {
      mapi_vdec::Stop();
      this[0x92] = (MW_DTV_AVMonitor)0x0;
      DecodeIframe(this,*(ulong *)(param_1 + 0x2c),*(ulong *)(param_1 + 0x30),*(int *)param_1 == 2);
      SetMuteFlag(this,'\0',1);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      mapi_scope_lock::mapi_scope_lock
                (amStack_40,(pthread_mutex_t *)(this + 0x50),
                 "void MW_DTV_AVMonitor::DoStartWithoutDmx(MW_DTV_AVInfo&)",0x96f);
      pMVar13 = param_1;
      pMVar2 = this + 0xd8;
      do {
        pMVar11 = pMVar2;
        uVar5 = *(undefined4 *)pMVar13;
        uVar8 = *(undefined4 *)(pMVar13 + 4);
        uVar9 = *(undefined4 *)(pMVar13 + 8);
        uVar10 = *(undefined4 *)(pMVar13 + 0xc);
        pMVar13 = pMVar13 + 0x10;
        *(undefined4 *)pMVar11 = uVar5;
        *(undefined4 *)(pMVar11 + 4) = uVar8;
        *(undefined4 *)(pMVar11 + 8) = uVar9;
        *(undefined4 *)(pMVar11 + 0xc) = uVar10;
        pMVar2 = pMVar11 + 0x10;
      } while (pMVar13 != param_1 + 0x30);
      *(undefined4 *)(pMVar11 + 0x10) = *(undefined4 *)(param_1 + 0x30);
      *(undefined2 *)(pMVar11 + 0x14) = *(undefined2 *)(param_1 + 0x34);
      pMVar11[0x16] = *(MW_DTV_AVMonitor *)(param_1 + 0x36);
      mapi_scope_lock::~mapi_scope_lock(amStack_40);
LAB_2d9d7760:
      if (param_1[0x28] == (MW_DTV_AVInfo)0x0) {
        sVar7 = *(short *)(param_1 + 0x10);
        goto LAB_2d9d7770;
      }
    }
    this[0x115] = (MW_DTV_AVMonitor)0x1;
    this[0x110] = (MW_DTV_AVMonitor)0x0;
    bVar1 = true;
  }
  if (*(short *)(param_1 + 0x12) == 0x1fff) {
LAB_2d9d75d0:
    piVar4 = (int *)MSrv_Control::GetInstance();
    iVar6 = (**(code **)(*piVar4 + 0x84))(piVar4);
  }
  else {
    if (param_1[0x24] != (MW_DTV_AVInfo)0x0) {
      if (*(int *)(param_1 + 4) == 0xff) {
        this[0x111] = (MW_DTV_AVMonitor)0x0;
      }
      else if (((*(int *)(param_1 + 4) == *(int *)(this + 0xa4)) &&
               (*(int *)(param_1 + 8) == *(int *)(this + 0xa8))) &&
              ((*(short *)(this + 0xb2) == *(short *)(param_1 + 0x12) &&
               (this[0x111] != (MW_DTV_AVMonitor)0x0)))) {
LAB_2d9d75c8:
        this[0x111] = (MW_DTV_AVMonitor)0x1;
      }
      else {
        SetMuteFlag(this,'\x01',2);
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 100))(piVar4,0,&local_3c);
        local_2c = 0;
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 0x5c))(piVar4,0,&local_3c);
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 100))(piVar4,1,&local_3c);
        local_2c = 1;
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 0x5c))(piVar4,1,&local_3c);
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 0x34))(piVar4,0);
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 0x40))(piVar4,*(undefined4 *)(param_1 + 4));
        if (param_1[0x36] == (MW_DTV_AVInfo)0x1) {
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x34))(piVar4,3);
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x34))(piVar4,7);
          printf("filein audio[%s:%d]\n",&UNK_2da4ab08,0x9ee);
        }
        else {
          if (*(short *)(param_1 + 0x1e) == 0x1fff) {
            piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
            (**(code **)(*piVar4 + 0x34))(piVar4,3);
          }
          else {
            piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
            (**(code **)(*piVar4 + 0x34))(piVar4,4);
          }
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x34))(piVar4,1);
        }
        if (*(int *)(param_1 + 8) == 2) {
          uVar5 = mapi_interface_common::Get_mapi_audio();
          mapi_audio::DECODER_SetOutputMode(uVar5,2);
          this[0x111] = (MW_DTV_AVMonitor)0x1;
        }
        else {
          if (*(int *)(param_1 + 8) != 1) {
            uVar5 = mapi_interface_common::Get_mapi_audio();
            mapi_audio::DECODER_SetOutputMode(uVar5,0);
            goto LAB_2d9d75c8;
          }
          uVar5 = mapi_interface_common::Get_mapi_audio();
          mapi_audio::DECODER_SetOutputMode(uVar5,1);
          this[0x111] = (MW_DTV_AVMonitor)0x1;
        }
      }
      goto LAB_2d9d75d0;
    }
    if (this[0x117] == (MW_DTV_AVMonitor)0x0) goto LAB_2d9d75d0;
    piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar4 + 0x34))(piVar4,0);
    piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar4 + 0x40))(piVar4,*(undefined4 *)(param_1 + 4));
    piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar4 + 0x34))(piVar4,1);
    this[0x117] = (MW_DTV_AVMonitor)0x0;
    piVar4 = (int *)MSrv_Control::GetInstance();
    iVar6 = (**(code **)(*piVar4 + 0x84))(piVar4);
  }
  if (iVar6 == 0x1c) {
    piVar4 = (int *)MSrv_Control::GetInstance();
    iVar6 = (**(code **)(*piVar4 + 0x114))(piVar4);
    if (iVar6 == 0) {
      if (*(short *)(param_1 + 0x14) == 0x1fff) {
        uVar3 = mapi_interface_common::Get_mapi_audio();
        mapi_audio::DECODER_SetADEnable(uVar3);
        piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar4 + 0x34))(piVar4,0x10);
LAB_2d9d7dd8:
        this[0x112] = (MW_DTV_AVMonitor)0x0;
      }
      else if (param_1[0x24] != (MW_DTV_AVInfo)0x0) {
        if (*(int *)(param_1 + 0xc) == 0xff) goto LAB_2d9d7dd8;
        if (((*(short *)(this + 0xb4) == *(short *)(param_1 + 0x14)) &&
            (*(int *)(param_1 + 0xc) == *(int *)(this + 0xac))) &&
           (this[0x112] != (MW_DTV_AVMonitor)0x0)) {
          this[0x112] = (MW_DTV_AVMonitor)0x1;
        }
        else {
          SetMuteFlag(this,'\x01',2);
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x34))(piVar4,0x10);
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x40))(piVar4,*(undefined4 *)(param_1 + 0xc));
          if (*(short *)(param_1 + 0x1e) == 0x1fff) {
            piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
            (**(code **)(*piVar4 + 0x34))(piVar4,3);
          }
          else {
            piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
            (**(code **)(*piVar4 + 0x34))(piVar4,4);
          }
          uVar3 = mapi_interface_common::Get_mapi_audio();
          mapi_audio::DECODER_SetADEnable(uVar3);
          piVar4 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar4 + 0x34))(piVar4,0x11);
          this[0x112] = (MW_DTV_AVMonitor)0x1;
        }
      }
    }
  }
  if (((*(short *)(param_1 + 0x12) == 0x1fff) || (*(int *)(param_1 + 4) == 0xff)) &&
     (this[0x110] != (MW_DTV_AVMonitor)0x0)) {
    mapi_vdec::SyncOn((uchar)*(undefined4 *)(this + 0x138));
  }
  else {
    mapi_vdec::SyncOn((uchar)*(undefined4 *)(this + 0x138));
  }
  if (((this[0x110] == (MW_DTV_AVMonitor)0x0) && (this[0x111] != (MW_DTV_AVMonitor)0x0)) ||
     ((((bVar1 && ((this[0x111] != (MW_DTV_AVMonitor)0x0 && (this[0x110] != (MW_DTV_AVMonitor)0x0)))
        ) && (this[0x92] != (MW_DTV_AVMonitor)0x0)) && (this[0x6e] == (MW_DTV_AVMonitor)0x0)))) {
    SetMuteFlag(this,'\0',2);
  }
  if ((param_1[0x24] != (MW_DTV_AVInfo)0x0) && (param_1[0x25] == (MW_DTV_AVInfo)0x0)) {
    SetMuteFlag(this,'\0',2);
  }
  if ((this[0x111] == (MW_DTV_AVMonitor)0x0) || (this[0x110] == (MW_DTV_AVMonitor)0x0)) {
    if (this[0x188] == (MW_DTV_AVMonitor)0x0) goto LAB_2d9d76a8;
    pcVar14 = *(code **)(this + 0x18c);
  }
  else {
    uVar5 = mapi_time_utility::GetTime0();
    *(undefined4 *)(this + 0x84) = uVar5;
    if (this[0x188] == (MW_DTV_AVMonitor)0x0) goto LAB_2d9d76a8;
    pcVar14 = *(code **)(this + 0x18c);
  }
  (*pcVar14)(0,0,0,*(undefined4 *)(this + 400));
LAB_2d9d76a8:
  pMVar2 = this + 0xa0;
  pMVar13 = param_1;
  do {
    pMVar12 = pMVar13;
    pMVar11 = pMVar2;
    uVar5 = *(undefined4 *)(pMVar12 + 4);
    uVar8 = *(undefined4 *)(pMVar12 + 8);
    uVar9 = *(undefined4 *)(pMVar12 + 0xc);
    pMVar13 = pMVar12 + 0x10;
    *(undefined4 *)pMVar11 = *(undefined4 *)pMVar12;
    *(undefined4 *)(pMVar11 + 4) = uVar5;
    *(undefined4 *)(pMVar11 + 8) = uVar8;
    *(undefined4 *)(pMVar11 + 0xc) = uVar9;
    pMVar2 = pMVar11 + 0x10;
  } while (pMVar13 != param_1 + 0x30);
  *(undefined4 *)(pMVar11 + 0x10) = *(undefined4 *)pMVar13;
  *(undefined2 *)(pMVar11 + 0x14) = *(undefined2 *)(pMVar12 + 0x14);
  pMVar11[0x16] = *(MW_DTV_AVMonitor *)(pMVar12 + 0x16);
  return;
}

