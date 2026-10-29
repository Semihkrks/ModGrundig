
/* MW_DTV_AVMonitor::Start(MW_DTV_AVInfo const&, unsigned char) */

undefined4 __thiscall
MW_DTV_AVMonitor::Start(MW_DTV_AVMonitor *this,MW_DTV_AVInfo *param_1,uchar param_2)

{
  undefined2 uVar1;
  MW_DTV_AVMonitor *pMVar2;
  MW_DTV_AVInfo *pMVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  mapi_event<MW_DTV_AVInfo> *this_00;
  undefined4 uVar9;
  MW_DTV_AVInfo *pMVar10;
  MW_DTV_AVInfo *pMVar11;
  MW_DTV_AVMonitor *pMVar12;
  MW_DTV_AVInfo *pMVar13;
  mapi_scope_lock amStack_58 [4];
  undefined4 local_54 [4];
  undefined2 local_44;
  undefined2 uStack_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  undefined1 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_58,(pthread_mutex_t *)(this + 0x50),
             "MAPI_BOOL MW_DTV_AVMonitor::Start(const MW_DTV_AVInfo&, MAPI_BOOL)",0x2bd);
                    /* try { // try from 2d9da0d4 to 2d9da12f has its CatchHandler @ 2d9da36c */
  iVar4 = MSrv_Control_TV::GetMSrvDtv(0);
  piVar7 = (int *)0x0;
  if (iVar4 != 0) {
    piVar7 = (int *)__dynamic_cast(iVar4,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0);
  }
  if ((this[0x1be] != (MW_DTV_AVMonitor)0x1) || (param_2 != '\0')) {
                    /* try { // try from 2d9da170 to 2d9da2f7 has its CatchHandler @ 2d9da36c */
    iVar4 = (**(code **)(*piVar7 + 0x568))();
    if (iVar4 == 0) {
      local_3e = 0x1fff;
      local_3c = 0xff;
      local_2f = 1;
      local_54[0] = 0;
      local_54[1] = 0xff;
      local_54[2] = 0;
      local_54[3] = 0xff;
      local_44 = 0x1fff;
      uStack_42 = 0x1fff;
      local_36 = 0x1fff;
      local_40 = 0x1fff;
      local_38 = 0;
      local_30 = 1;
      local_2e = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1f = 0;
      local_2d = 0;
      local_1e = 0;
      pMVar10 = param_1;
      pMVar2 = this + 0xd8;
      do {
        pMVar12 = pMVar2;
        uVar5 = *(undefined4 *)pMVar10;
        uVar6 = *(undefined4 *)(pMVar10 + 4);
        uVar8 = *(undefined4 *)(pMVar10 + 8);
        uVar9 = *(undefined4 *)(pMVar10 + 0xc);
        pMVar10 = pMVar10 + 0x10;
        *(undefined4 *)pMVar12 = uVar5;
        *(undefined4 *)(pMVar12 + 4) = uVar6;
        *(undefined4 *)(pMVar12 + 8) = uVar8;
        *(undefined4 *)(pMVar12 + 0xc) = uVar9;
        pMVar2 = pMVar12 + 0x10;
      } while (pMVar10 != param_1 + 0x30);
      *(undefined4 *)(pMVar12 + 0x10) = *(undefined4 *)(param_1 + 0x30);
      *(undefined2 *)(pMVar12 + 0x14) = *(undefined2 *)(param_1 + 0x34);
      pMVar12[0x16] = *(MW_DTV_AVMonitor *)(param_1 + 0x36);
      pMVar10 = param_1;
      pMVar3 = (MW_DTV_AVInfo *)local_54;
      do {
        pMVar13 = pMVar3;
        pMVar11 = pMVar10;
        uVar5 = *(undefined4 *)(pMVar11 + 4);
        uVar6 = *(undefined4 *)(pMVar11 + 8);
        uVar8 = *(undefined4 *)(pMVar11 + 0xc);
        pMVar10 = pMVar11 + 0x10;
        *(undefined4 *)pMVar13 = *(undefined4 *)pMVar11;
        *(undefined4 *)(pMVar13 + 4) = uVar5;
        *(undefined4 *)(pMVar13 + 8) = uVar6;
        *(undefined4 *)(pMVar13 + 0xc) = uVar8;
        pMVar3 = pMVar13 + 0x10;
      } while (pMVar10 != param_1 + 0x30);
      uVar1 = *(undefined2 *)(pMVar11 + 0x14);
      uVar5 = *(undefined4 *)pMVar10;
      this_00 = *(mapi_event<MW_DTV_AVInfo> **)(this + 0x2c);
      pMVar13[0x16] = pMVar11[0x16];
      *(undefined2 *)(pMVar13 + 0x14) = uVar1;
      *(undefined4 *)(pMVar13 + 0x10) = uVar5;
      local_34 = 1;
      mapi_event<MW_DTV_AVInfo>::Send(this_00,(MW_DTV_AVInfo *)local_54,false);
      if ((param_2 == '\x01') && (this[0x1be] == (MW_DTV_AVMonitor)0x1)) {
                    /* try { // try from 2d9da344 to 2d9da363 has its CatchHandler @ 2d9da36c */
        SetMuteFlag(this,'\0',0x1000);
        SetMuteFlag(this,'\0',0x4000);
      }
      this[0x1be] = (MW_DTV_AVMonitor)param_2;
      MSrv_Control_common::GetMSrvSystemDatabase();
      iVar4 = MSrv_System_Database::GetFastZapping();
      if (iVar4 == 0) {
        *(undefined2 *)(this + 0x1d6) = 2000;
      }
      else {
        *(undefined2 *)(this + 0x1d6) = 200;
      }
      printf("AVMon Start Up Delay = %d \n",(uint)*(ushort *)(this + 0x1d6));
      mapi_scope_lock::~mapi_scope_lock(amStack_58);
      return 1;
    }
  }
  puts("Ignore live pmt change in PVR playback mode !!!");
  mapi_scope_lock::~mapi_scope_lock(amStack_58);
  return 0;
}

