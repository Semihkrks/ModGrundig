
/* MSrv_DTV_Player_DVB::EnableVideoOut() */

undefined4 __thiscall MSrv_DTV_Player_DVB::EnableVideoOut(MSrv_DTV_Player_DVB *this)

{
  mapi_event<MS_DTV_PlayerInfo> *this_00;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  MW_DTV_AVMonitor_Customer *pMVar4;
  void *pvVar5;
  void *pvVar6;
  mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> *this_01;
  MW_DVB_SI_PSI_Parser_Customer *this_02;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  code *pcVar11;
  mapi_scope_lock amStack_498 [4];
  undefined4 local_494;
  undefined1 auStack_490 [18];
  char local_47e;
  undefined1 auStack_464 [17];
  char local_453;
  undefined1 auStack_2c0 [588];
  undefined4 local_74;
  
  if (this[0xa9] == (MSrv_DTV_Player_DVB)0x1) {
    return 1;
  }
  this_00 = operator_new(0x50,(nothrow_t *)&DAT_2c7f5bd0);
  if (this_00 == (mapi_event<MS_DTV_PlayerInfo> *)0x0) {
    *(undefined4 *)(this + 0x94) = 0;
    uVar3 = 0x2f42;
  }
  else {
                    /* try { // try from 2d4d39f4 to 2d4d39fb has its CatchHandler @ 2d4d426c */
    mapi_event<MS_DTV_PlayerInfo>::mapi_event(this_00);
    *(mapi_event<MS_DTV_PlayerInfo> **)(this + 0x94) = this_00;
    MSrv_Control_common::SetGpioDeviceStatus(3,'\0');
    MSrv_Control_common::SetGpioDeviceStatus(0x34,'\x01');
    if (*(int *)(this + 0x9c) == 0) {
      iVar1 = mapi_demux::GetAvailableDtvDemux();
      *(int *)(this + 0x9c) = iVar1;
      if (iVar1 == 0) {
        uVar3 = 0x2f4a;
      }
      else {
        iVar1 = mapi_demux::Init();
        if (iVar1 != 1) {
          puts("Error--- demux init!! ");
        }
        iVar1 = mapi_vdec::GetInstance(*(undefined4 *)(this + 0xac));
        if (iVar1 != 0) {
          mapi_vdec::Initialize(iVar1,0);
          mapi_scope_lock::mapi_scope_lock
                    (amStack_498,(pthread_mutex_t *)(this + 0xd8),
                     "virtual BOOL MSrv_DTV_Player_DVB::EnableVideoOut()",0x2f62);
                    /* try { // try from 2d4d3acc to 2d4d3c07 has its CatchHandler @ 2d4d4258 */
          local_494 = 0x1c;
          piVar2 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
          (**(code **)(*piVar2 + 0x98))(piVar2,auStack_2c0,&local_494);
          if (*(int *)(this + 0x520) == 0) {
            iVar1 = 0;
            pvVar5 = operator_new__(0x70,(nothrow_t *)&DAT_2c7f5bd0);
            *(void **)(this + 0x520) = pvVar5;
            if (pvVar5 == (void *)0x0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2f6a);
              goto LAB_2d4d3c88;
            }
            do {
              pvVar6 = operator_new__(0x200,(nothrow_t *)&DAT_2c7f5bd0);
              puVar10 = (undefined4 *)((int)pvVar5 + iVar1);
              pvVar5 = *(void **)(this + 0x520);
              *puVar10 = pvVar6;
              if (*(int *)((int)pvVar5 + iVar1) == 0) {
                    /* try { // try from 2d4d3ec4 to 2d4d3ef7 has its CatchHandler @ 2d4d4258 */
                printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2f6e);
                goto LAB_2d4d3c88;
              }
              iVar1 = iVar1 + 4;
            } while (iVar1 != 0x70);
          }
          if (*(int *)(this + 0x98) == 0) {
            if (*(int *)(this + 0x48) == 0) {
              uVar3 = (**(code **)(*(int *)this + 0x218))(this);
              pMVar4 = operator_new(0x1dc,(nothrow_t *)&DAT_2c7f5bd0);
              if (pMVar4 != (MW_DTV_AVMonitor_Customer *)0x0) {
                    /* try { // try from 2d4d3cfc to 2d4d3d03 has its CatchHandler @ 2d4d428c */
                MW_DTV_AVMonitor_Customer::MW_DTV_AVMonitor_Customer
                          (pMVar4,0,uVar3,*(undefined4 *)(this + 0x9c));
              }
            }
            else {
              uVar3 = (**(code **)(*(int *)this + 0x218))(this);
              pMVar4 = operator_new(0x1dc,(nothrow_t *)&DAT_2c7f5bd0);
              if (pMVar4 != (MW_DTV_AVMonitor_Customer *)0x0) {
                    /* try { // try from 2d4d3e34 to 2d4d3e3b has its CatchHandler @ 2d4d4264 */
                MW_DTV_AVMonitor_Customer::MW_DTV_AVMonitor_Customer
                          (pMVar4,1,uVar3,*(undefined4 *)(this + 0x9c));
              }
            }
            *(MW_DTV_AVMonitor_Customer **)(this + 0x98) = pMVar4;
            if (*(int *)(this + 0x98) == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2f7c);
              goto LAB_2d4d3c88;
            }
                    /* try { // try from 2d4d3d20 to 2d4d3dff has its CatchHandler @ 2d4d4258 */
            (**(code **)(*(int *)this + 0x8d8))(this,1);
            MW_DTV_AVMonitor::SetUsrArc(*(undefined4 *)(this + 0x98),local_74,1);
            MW_DTV_AVMonitor::EnableAFD((uchar)*(undefined4 *)(this + 0x98));
            MW_DTV_AVMonitor::RegisterSwitchChannelWithDelayCallback(*(_func_void **)(this + 0x98));
            iVar1 = *(int *)(this + 300);
          }
          else {
            iVar1 = *(int *)(this + 300);
          }
          if (iVar1 == 0) {
            (**(code **)(*(int *)this + 0x7b8))(this);
            piVar2 = *(int **)(this + 0x108);
          }
          else {
            piVar2 = *(int **)(this + 0x108);
          }
          iVar1 = (**(code **)(*piVar2 + 0x20))(piVar2,auStack_464);
          if ((iVar1 != 0) && (local_453 == '\0')) {
                    /* try { // try from 2d4d3c9c to 2d4d3cc7 has its CatchHandler @ 2d4d4258 */
            (**(code **)(*(int *)this + 0x814))(this,auStack_464);
          }
          this[0x23b] = (MSrv_DTV_Player_DVB)0x0;
          *(undefined4 *)(this + 0x514) = 0;
          iVar1 = 0;
          do {
            iVar9 = iVar1 + 0xe;
            *(undefined2 *)(this + iVar1 + 0x438) = 0x1fff;
            iVar1 = iVar9;
          } while (iVar9 != 0xe0);
          *(undefined4 *)(this + 0x518) = 0;
          this[0x51c] = (MSrv_DTV_Player_DVB)0x0;
          *(undefined2 *)(this + 0x23e) = 0;
          *(undefined2 *)(this + 0x240) = 0;
          *(undefined2 *)(this + 0x242) = 0;
          *(undefined2 *)(this + 0x244) = 0;
          *(undefined2 *)(this + 0x246) = 0;
          *(undefined2 *)(this + 0x248) = 0;
          *(undefined2 *)(this + 0x24a) = 0;
          *(undefined2 *)(this + 0x24c) = 0;
          *(undefined4 *)(this + 0x524) = 0;
          _DoInit_SiPsi(this);
          if (*(int *)(this + 0x130) == 0) {
            pcVar11 = *(code **)(*(int *)this + 0x8c8);
            uVar3 = _GetCountry();
            (*pcVar11)(this,uVar3);
          }
          if (*(int *)(this + 0xfc) == 0) {
            this_01 = operator_new(0x50,(nothrow_t *)&DAT_2c7f5bd0);
            if (this_01 == (mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> *)0x0) {
              *(undefined4 *)(this + 0xd4) = 0;
              printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2fb1);
              goto LAB_2d4d3c88;
            }
                    /* try { // try from 2d4d3f20 to 2d4d3f27 has its CatchHandler @ 2d4d4250 */
            mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo>::mapi_event(this_01);
            *(mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> **)(this + 0xd4) = this_01;
            this_02 = operator_new(0xd3920,(nothrow_t *)&DAT_2c7f5bd0);
            if (this_02 != (MW_DVB_SI_PSI_Parser_Customer *)0x0) {
                    /* try { // try from 2d4d3f54 to 2d4d3f5b has its CatchHandler @ 2d4d4218 */
              MW_DVB_SI_PSI_Parser_Customer::MW_DVB_SI_PSI_Parser_Customer(this_02);
            }
            *(MW_DVB_SI_PSI_Parser_Customer **)(this + 0xfc) = this_02;
            if (this_02 == (MW_DVB_SI_PSI_Parser_Customer *)0x0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2fb4);
              goto LAB_2d4d3c88;
            }
                    /* try { // try from 2d4d3f70 to 2d4d420f has its CatchHandler @ 2d4d4258 */
            pcVar11 = *(code **)(*(int *)this_02 + 8);
            uVar3 = mapi_interface_TV::Get_mapi_si_psi();
            (*pcVar11)(this_02,uVar3,*(undefined4 *)(this + 0x114),this,
                       CIAdaptation::staticCiNotifyPmtUpdate,0,
                       CIAdaptation::staticCIProtectionNotify,SI_EventHandler,0);
            piVar2 = *(int **)(this + 0xfc);
            pcVar11 = *(code **)(*piVar2 + 0xc);
            uVar3 = _GetCountry();
            uVar7 = _GetTimeZone();
            uVar8 = _GetLanguage();
            (*pcVar11)(piVar2,uVar3,uVar7,1,0x7b2,uVar8);
            (**(code **)(**(int **)(this + 0xfc) + 0x20))
                      (*(int **)(this + 0xfc),SIMonitorNotify,this);
            piVar2 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
            (**(code **)(*piVar2 + 0x90))(piVar2,auStack_490);
            piVar2 = (int *)0x0;
            if (*(int *)(this + 0xfc) != 0) {
              piVar2 = (int *)__dynamic_cast(*(int *)(this + 0xfc),&MW_DVB_SI_PSI_Parser::typeinfo,
                                             &MW_DVB_SI_PSI_Parser_Customer::typeinfo,0);
            }
            (**(code **)(*piVar2 + 0x354))(piVar2,local_47e == '\x01');
            piVar2 = *(int **)(this + 0xfc);
            pcVar11 = *(code **)(*piVar2 + 0x24);
            uVar3 = _GetClockMode();
            (*pcVar11)(piVar2,uVar3);
            (**(code **)(*(int *)this + 0x840))(this);
          }
          if (*(int *)(this + 0x264) == 0) {
            iVar1 = MW_TTX::GetInstance();
            *(int *)(this + 0x264) = iVar1;
            if (iVar1 == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2fe1);
              goto LAB_2d4d3c88;
            }
            MW_TTX::KickOff();
            MW_TTX::AllocateTTXFilter(*(mapi_demux **)(this + 0x264));
            iVar1 = *(int *)(this + 0x9c);
          }
          else {
            MW_TTX::KickOff();
            iVar1 = *(int *)(this + 0x9c);
          }
          if (iVar1 != 0) {
            (**(code **)(**(int **)(this + 0xcc) + 0x2c))(*(int **)(this + 0xcc),0);
            this[0x2d3] = (MSrv_DTV_Player_DVB)0xd;
            uVar3 = mapi_time_utility::GetTime0();
            *(undefined4 *)(this + 0x2d8) = uVar3;
            uVar3 = mapi_time_utility::GetTime0();
            *(undefined4 *)(this + 0x2dc) = uVar3;
            mapi_scope_lock::~mapi_scope_lock(amStack_498);
            this[0xa9] = (MSrv_DTV_Player_DVB)0x1;
            this[0x44] = (MSrv_DTV_Player_DVB)0x1;
            return 1;
          }
          printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,0x2fed);
          goto LAB_2d4d3c88;
        }
        uVar3 = 0x2f53;
      }
    }
    else {
      uVar3 = 0x2f48;
    }
  }
  printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d59776c,uVar3);
LAB_2d4d3c88:
                    /* WARNING: Subroutine does not return */
  abort();
}

