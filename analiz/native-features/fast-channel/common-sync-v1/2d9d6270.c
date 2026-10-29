
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* MW_DTV_AVMonitor::DoVideoSync() */

void __thiscall MW_DTV_AVMonitor::DoVideoSync(MW_DTV_AVMonitor *this)

{
  bool bVar1;
  FILE *pFVar2;
  MSrv_SrcDetect *pMVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  longlong lVar13;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  if ((this[0x110] == (MW_DTV_AVMonitor)0x1) && (iVar4 = mapi_vdec::GetFrameCnt(), iVar4 != 0)) {
    uVar6 = mapi_audio_customer::GetInstance();
    iVar4 = mapi_audio_customer::DECODER_GetCommand(uVar6,0);
    MApi_VDEC_AVSyncOn(1,0xb9,0x19);
    if ((this[0xc6] != (MW_DTV_AVMonitor)0x0) && (iVar4 != 1)) {
LAB_2d9d6640:
      bVar1 = true;
      pMVar3 = (MSrv_SrcDetect *)MSrv_Control_common::GetMSrvSourceDetect();
      iVar4 = MSrv_SrcDetect::GetForbidDetectionFlag(pMVar3);
      goto joined_r0x2d9d665c;
    }
    local_48 = 0;
    uVar5 = *(uint *)(*(int *)(this + 0x150) + 8);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    if (*(int *)(this + 0x1c8) == 0) {
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      iVar4 = *piVar7;
      uVar6 = 0;
LAB_2d9d6780:
      (**(code **)(iVar4 + 100))(piVar7,uVar6,&local_40);
    }
    else if (*(int *)(this + 0x1c8) == 1) {
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      iVar4 = *piVar7;
      uVar6 = 1;
      goto LAB_2d9d6780;
    }
    if (local_28 == 2) {
      uVar6 = 0xac;
    }
    else {
      uVar6 = 0x7c;
    }
    uVar5 = uVar5 & 0xff;
    uVar12 = MApi_AUDIO_GetCommAudioInfo(uVar6);
    uVar9 = (uint)((ulonglong)uVar12 >> 0x20);
    uVar8 = (uint)uVar12;
    iVar4 = MApi_DMX_Pcr_Eng_Get(uVar5,&local_48,&local_44);
    if ((uVar9 < local_48) || ((local_48 == uVar9 && (uVar8 < local_44)))) {
      uVar10 = local_44 - uVar8;
      bVar1 = local_44 < uVar10;
      iVar11 = local_48 - uVar9;
    }
    else {
      uVar10 = uVar8 - local_44;
      bVar1 = uVar8 < uVar10;
      iVar11 = uVar9 - local_48;
    }
    lVar13 = __divdi3(uVar10,iVar11 - (uint)bVar1,0x5a,0);
    iVar11 = MApi_AUDIO_UNI_Get_OutPCMLevel();
    if ((((iVar4 == 0) && (lVar13 < 0x100000000)) &&
        (((int)((ulonglong)lVar13 >> 0x20) != 0 || ((uint)lVar13 < 0x2711)))) || (iVar11 == 0)) {
      if (iRam2da8dacc == 0) goto LAB_2d9d6640;
      MApi_DMX_STC_UpdateCtrl(uVar5,0);
      bVar1 = true;
      MApi_DMX_Stc_Eng_Set(uVar5,0,0);
      piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
      (**(code **)(*piVar7 + 0x38))(piVar7,4,0);
      MApi_VDEC_AVSyncOn(1,0xb4,0x19);
      iRam2da8dacc = 0;
    }
    else {
      iVar4 = GetVideoStatus(this);
      if ((iVar4 == 1) || (iVar4 = IsMadLock(), iVar4 != 0)) {
        piVar7 = (int *)mapi_interface_TV::Get_mapi_video(0x1c);
        (**(code **)(*piVar7 + 0x90))(piVar7,2,100);
        SetMuteFlag(this,'\0',3);
      }
      if (iRam2da8dacc == 0) {
        bVar1 = false;
        uRam2da8dad0 = MsOS_GetSystemTime();
        iRam2da8dacc = 2;
      }
      else if (iRam2da8dacc == 2) {
        uVar10 = MsOS_Timer_DiffTimeFromNow(uRam2da8dad0);
        if (uVar10 < 0x1f5) goto LAB_2d9d62b4;
        iVar4 = MApi_VDEC_GetActiveCodecType();
        if (iVar4 - 0xbU < 2) {
          uVar6 = 0x78d98;
        }
        else {
          uVar6 = 180000;
        }
        MApi_VDEC_SetAVSyncFreerunThreshold(uVar6);
        piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
        (**(code **)(*piVar7 + 0x38))(piVar7,3,0);
        piVar7 = (int *)MSrv_Control::GetInstance();
        iVar4 = (**(code **)(*piVar7 + 0x114))(piVar7);
        if (iVar4 == 0) {
          MApi_DMX_Stc_Eng_Set(uVar5,uVar9,uVar8);
          MApi_DMX_STC_UpdateCtrl(uVar5,1);
        }
        MApi_VDEC_AVSyncOn(1,0xb9,0x19);
        iVar4 = MApi_VDEC_IsReachSync();
        if (iVar4 == 1) {
          piVar7 = (int *)mapi_interface_TV::Get_mapi_video(0x1c);
          (**(code **)(*piVar7 + 0x90))(piVar7,2,100);
          SetMuteFlag(this,'\0',3);
        }
        iRam2da8dacc = 1;
        bVar1 = true;
      }
      else {
        piVar7 = (int *)MSrv_Control::GetInstance();
        iVar4 = (**(code **)(*piVar7 + 0x114))(piVar7);
        if (iVar4 == 0) {
          MApi_DMX_Stc_Eng_Set(uVar5,uVar9,uVar8);
          piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
          (**(code **)(*piVar7 + 0x38))(piVar7,3,0);
          MApi_VDEC_AVSyncOn(1,0xb9,0x19);
        }
        iRam2da8dacc = 1;
        bVar1 = false;
      }
    }
  }
  else {
LAB_2d9d62b4:
    bVar1 = false;
  }
  pMVar3 = (MSrv_SrcDetect *)MSrv_Control_common::GetMSrvSourceDetect();
  iVar4 = MSrv_SrcDetect::GetForbidDetectionFlag(pMVar3);
joined_r0x2d9d665c:
  if (iVar4 == 1) {
    iVar4 = MSrv_Control_common::GetMSrvSourceDetect();
    if (iVar4 != 0) {
      __dynamic_cast(iVar4,&MSrv_SrcDetect::typeinfo,&DAT_2e028188,0);
    }
    iVar4 = MSrv_SrcDetect_Customer::IsSetInputSourceInProgress();
    if (iVar4 == 0) {
      pMVar3 = (MSrv_SrcDetect *)MSrv_Control_common::GetMSrvSourceDetect();
      MSrv_SrcDetect::SetForbidDetectionFlag(pMVar3,'\0');
    }
  }
  if ((this[0x6e] != (MW_DTV_AVMonitor)0x0) && (bVar1)) {
    uVar5 = mapi_time_utility::TimeDiffFromNow0(*(ulong *)(this + 0x70));
    iVar4 = mapi_vdec::IsSyncDone();
    pFVar2 = _DAT_2c67c868;
    if (cRam2da8dad4 != '\0') {
      uVar6 = mapi_time_utility::GetPiuTimer1();
      fprintf(pFVar2,"[AT][SN][DoVideoSync][PIU][%lu]\n",uVar6);
      pFVar2 = _DAT_2c67c868;
      uVar6 = mapi_time_utility::GetTime0();
      fprintf(pFVar2,"[AT][SN][DoVideoSync][SYS][%lu]\n",uVar6);
      cRam2da8dad4 = '\0';
    }
    pFVar2 = _DAT_2c67c868;
    if (iVar4 == 0) {
      uVar8 = (**(code **)(*(int *)this + 8))(this);
      pFVar2 = _DAT_2c67c868;
      if (uVar5 <= uVar8) {
        return;
      }
      uVar6 = mapi_time_utility::GetPiuTimer1();
      fprintf(pFVar2,"[AT][SN][DoVideoSync Done][PIU][%lu]\n",uVar6);
      pFVar2 = _DAT_2c67c868;
      uVar6 = mapi_time_utility::GetTime0();
      fprintf(pFVar2,"[AT][SN][DoVideoSync Done][SYS][%lu]\n",uVar6);
      cRam2da8dad4 = '\x01';
      iVar4 = GetDebugLevel(7);
      if (3 < iVar4) {
        fwrite(&UNK_2da4aefc,1,0x16,_DAT_2c67c868);
      }
    }
    else {
      uVar6 = mapi_time_utility::GetPiuTimer1();
      fprintf(pFVar2,"[AT][SN][DoVideoSync Done][PIU][%lu]\n",uVar6);
      pFVar2 = _DAT_2c67c868;
      uVar6 = mapi_time_utility::GetTime0();
      fprintf(pFVar2,"[AT][SN][DoVideoSync Done][SYS][%lu]\n",uVar6);
      cRam2da8dad4 = '\x01';
      iVar4 = GetDebugLevel(7);
      if (3 < iVar4) {
        fwrite(&UNK_2da4aeec,1,0xd,_DAT_2c67c868);
      }
    }
    iVar4 = MSrv_Control_TV::GetMSrvDtv(0);
    uVar6 = 0;
    if (iVar4 != 0) {
      uVar6 = __dynamic_cast(iVar4,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
    }
    MSrv_DTV_Player_DVB::RecordProgChangeEvent(uVar6,0xb,0,0);
    mapi_vdec::SetCallBack(*(ulong *)(this + 0x138),(_func_void_ulong_void_ptr *)0x40,VDEC_EventCb);
    if (this[0xfe] == (MW_DTV_AVMonitor)0x1) {
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 10000;
        uVar5 = mapi_vdec::GetFrameCnt();
        if (0xf < uVar5) break;
        usleep(10000);
      } while (iVar4 != 0x1eab90);
      printf("\x1b[0;31m [%s:%s][%d]!!! AVMonitor SLEEP FOR FILEIN STAGE !!!\x1b[0m\n",&UNK_2da4ab08
             ,&UNK_2da4b7d4,0xe71);
    }
    SetMuteFlag(this,'\0',2);
    SetMuteFlag(this,'\0',1);
    if ((this[0x111] != (MW_DTV_AVMonitor)0x0) ||
       ((this[0x1bc] == (MW_DTV_AVMonitor)0x1 && (this[0x116] != (MW_DTV_AVMonitor)0x0)))) {
      SetMuteFlag(this,'\0',2);
    }
    this[0x6e] = (MW_DTV_AVMonitor)0x0;
    piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    iVar4 = (**(code **)(*piVar7 + 0x144))(piVar7);
    if (iVar4 == 1) {
      uVar6 = mapi_time_utility::GetTime0();
      printf("[%lu ms] [MW_DTV_AVMonitor::DoVideoSync] MVD_GOOD_VIDEO\n",uVar6);
    }
  }
  return;
}

