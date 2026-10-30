
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* MW_DTV_AVMonitor::DoSetMode(unsigned long) */

void __thiscall MW_DTV_AVMonitor::DoSetMode(MW_DTV_AVMonitor *this,ulong param_1)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 uVar3;
  MSrv_Picture *this_00;
  MSrv_Video *pMVar4;
  int *piVar5;
  int *piVar6;
  MSrv_Player *this_01;
  code *pcVar7;
  mapi_scope_lock amStack_d8 [4];
  undefined4 local_d4;
  undefined1 local_d0;
  short local_cc;
  short local_ca;
  short local_c8;
  short local_c6;
  _VDEC_INFO local_c4 [4];
  undefined2 local_c0;
  undefined2 local_be;
  undefined2 local_b8;
  undefined2 local_b6;
  undefined2 local_b4;
  undefined2 local_b2;
  undefined4 local_b0;
  byte local_ac;
  undefined1 local_ab;
  _VDEC_INFO a_Stack_a8 [28];
  mapi_video_dtv_cfg amStack_8c [8];
  undefined2 local_84;
  undefined2 local_82;
  undefined1 local_7e;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined2 local_78;
  undefined2 local_76;
  undefined4 local_74;
  MW_DTV_AVInfo aMStack_64 [32];
  undefined4 local_44;
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_d8,(pthread_mutex_t *)(this + 0x38),
             "void MW_DTV_AVMonitor::DoSetMode(MAPI_U32)",0xa80);
  if (this[0x110] == (MW_DTV_AVMonitor)0x0) {
LAB_2d9d714c:
    printf("** Leave DoSetMode : %lu\n",param_1);
  }
  else {
                    /* try { // try from 2d9d6dcc to 2d9d6dd3 has its CatchHandler @ 2d9d7358 */
    mapi_video_dtv_cfg::mapi_video_dtv_cfg(amStack_8c);
                    /* try { // try from 2d9d6de0 to 2d9d712b has its CatchHandler @ 2d9d7324 */
    mapi_vdec::SetBlueScreen((uchar)*(undefined4 *)(this + 0x138));
    iVar2 = mapi_vdec::GetDispInfo(*(_VDEC_INFO **)(this + 0x138));
    if (iVar2 == 0) {
                    /* try { // try from 2d9d71a8 to 2d9d71af has its CatchHandler @ 2d9d7324 */
      puts("*******************Get display info failed");
    }
    else {
      iVar2 = GetLastDispInfo(this,a_Stack_a8);
      if (iVar2 == 0) {
                    /* try { // try from 2d9d71d0 to 2d9d7297 has its CatchHandler @ 2d9d7324 */
        puts("*******************Get Last display info failed");
      }
      else if ((this[0x92] != (MW_DTV_AVMonitor)0x1) ||
              (iVar2 = CheckDispInfoChg(this,local_c4,a_Stack_a8), iVar2 != 0)) {
        pFVar1 = _DAT_2c67c868;
        uVar3 = mapi_time_utility::GetPiuTimer1();
        fprintf(pFVar1,"[AT][SN][dosetmode][%lu]\n",uVar3);
        SetMuteFlag(this,'\x01',3);
        uVar3 = mapi_time_utility::GetTime0();
        *(undefined4 *)(this + 0x70) = uVar3;
        iVar2 = mapi_vdec::GetActiveVdecType(*(CODEC_TYPE **)(this + 0x138));
        if (iVar2 == 0) {
          puts("*******************Get Vdec codec failed");
        }
        else {
          local_84 = local_c0;
          local_82 = local_be;
          local_7e = local_ab;
          local_7c = local_b8;
          local_7a = local_b6;
          local_78 = local_b4;
          local_76 = local_b2;
          local_74 = local_b0;
          SaveLastDispInfo(this,local_c4);
          this_00 = (MSrv_Picture *)MSrv_Control_common::GetMSrvPicture();
          MSrv_Picture::Off(this_00);
          pMVar4 = (MSrv_Video *)MSrv_Control_common::GetMSrvVideo();
          piVar5 = (int *)MSrv_Control::GetInstance();
          pcVar7 = *(code **)(*piVar5 + 0x9c);
          piVar6 = (int *)MSrv_Control::GetInstance();
          uVar3 = (**(code **)(*piVar6 + 0x84))(piVar6);
          this_01 = (MSrv_Player *)(*pcVar7)(piVar5,uVar3);
          uVar3 = MSrv_Player::GetTiming(this_01);
          MSrv_Video::SetOutputTiming(pMVar4,uVar3,0);
          (**(code **)(**(int **)(this + 0x13c) + 0x20))(*(int **)(this + 0x13c),amStack_8c);
          this[0x92] = (MW_DTV_AVMonitor)0x1;
          (**(code **)(**(int **)(this + 0x13c) + 0xe4))();
          if ((*(code **)(this + 0x1d0) == (code *)0x0) ||
             (iVar2 = (**(code **)(this + 0x1d0))(), iVar2 != 0)) {
LAB_2d9d7014:
            piVar5 = *(int **)(this + 0x13c);
          }
          else {
            if (this[0x89] == (MW_DTV_AVMonitor)0x0) {
              _SetWindow(this);
              *(uint *)(this + 0x94) = (uint)local_ac;
              *(undefined4 *)(this + 0x98) = local_b0;
              goto LAB_2d9d7014;
            }
            piVar5 = (int *)mapi_interface_TV::Get_mapi_video(0x1c);
            (**(code **)(*piVar5 + 0x34))(piVar5,0,0,(ST_MAPI_VIDEO_WINDOW_TYPE *)&local_cc);
            iVar2 = IsUHD_FHDTransitionOccured(this,(ST_MAPI_VIDEO_WINDOW_TYPE *)&local_cc);
            if (((iVar2 != 0) && (local_cc == 0)) && (local_ca == 0)) {
              if (local_c8 == 0xf00) {
                if (local_c6 == 0x870) {
                  *(short *)(this + 0x8a) = *(short *)(this + 0x8a) << 1;
                  *(short *)(this + 0x8c) = *(short *)(this + 0x8c) << 1;
                  *(short *)(this + 0x8e) = *(short *)(this + 0x8e) << 1;
                  *(short *)(this + 0x90) = *(short *)(this + 0x90) << 1;
                }
              }
              else if ((local_c8 == 0x780) && (local_c6 == 0x438)) {
                *(ushort *)(this + 0x8a) = *(ushort *)(this + 0x8a) >> 1;
                *(ushort *)(this + 0x8c) = *(ushort *)(this + 0x8c) >> 1;
                *(ushort *)(this + 0x8e) = *(ushort *)(this + 0x8e) >> 1;
                *(ushort *)(this + 0x90) = *(ushort *)(this + 0x90) >> 1;
              }
            }
            SetWindow(this,this + 0x8a,*(undefined4 *)(this + 0x1c0));
            piVar5 = *(int **)(this + 0x13c);
          }
          (**(code **)(*piVar5 + 0xe8))();
          local_d4 = 0;
          local_d0 = 0;
          uVar3 = Get_Default_Display(this);
          iVar2 = getOutSignalling(&local_d4,local_b0,local_ac,uVar3);
          if (iVar2 != 0) {
            (**(code **)(**(int **)(this + 0x13c) + 0xd4))();
            pFVar1 = _DAT_2c67c868;
            uVar3 = mapi_time_utility::GetPiuTimer1();
            fprintf(pFVar1,"[AT][SN][setwindow][%lu]\n",uVar3);
            piVar5 = (int *)MSrv_Control_common::GetMSrvPicture();
            (**(code **)(*piVar5 + 0x38))(piVar5,0x2a);
            MW_DTV_AVInfo::MW_DTV_AVInfo(aMStack_64);
            local_44 = 0x40;
            mapi_event<MW_DTV_AVInfo>::Send
                      (*(mapi_event<MW_DTV_AVInfo> **)(this + 0x2c),aMStack_64,false);
            SetVideoStatus(this,1);
            *(undefined4 *)(this + 0x84) = 0;
            uVar3 = mapi_time_utility::GetTime0();
            this[0x6e] = (MW_DTV_AVMonitor)0x1;
            *(undefined4 *)(this + 0x128) = uVar3;
                    /* try { // try from 2d9d7140 to 2d9d715f has its CatchHandler @ 2d9d7358 */
            mapi_video_dtv_cfg::~mapi_video_dtv_cfg(amStack_8c);
            goto LAB_2d9d714c;
          }
        }
      }
    }
                    /* try { // try from 2d9d71b8 to 2d9d71bf has its CatchHandler @ 2d9d7358 */
    mapi_video_dtv_cfg::~mapi_video_dtv_cfg(amStack_8c);
  }
  mapi_scope_lock::~mapi_scope_lock(amStack_d8);
  return;
}

