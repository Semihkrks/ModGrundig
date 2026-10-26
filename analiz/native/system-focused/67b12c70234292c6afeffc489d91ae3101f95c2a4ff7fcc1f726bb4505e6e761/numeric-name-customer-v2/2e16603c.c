
/* WARNING: Removing unreachable block (ram,0x2e16656c) */
/* WARNING: Removing unreachable block (ram,0x2e1665a0) */
/* MSrv_ChannelManager_DVB_Customer::GetProgramSelInfo(unsigned short, unsigned short&, unsigned
   char&, unsigned char&) */

int __thiscall
MSrv_ChannelManager_DVB_Customer::GetProgramSelInfo
          (MSrv_ChannelManager_DVB_Customer *this,ushort param_1,ushort *param_2,uchar *param_3,
          uchar *param_4)

{
  ushort uVar1;
  uint uVar2;
  uchar uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  mapi_scope_lock amStack_3b8 [4];
  undefined1 auStack_3b4 [20];
  undefined1 local_3a0;
  int local_39c;
  int local_398;
  undefined1 auStack_36c [15];
  char local_35d;
  byte local_34f;
  ushort local_33a;
  undefined1 auStack_1c8 [29];
  uchar local_1ab;
  ushort local_196;
  
  uVar2 = (uint)param_1;
  iVar4 = _isFilterListActive();
  if (iVar4 != 0) {
    mapi_scope_lock::mapi_scope_lock
              (amStack_3b8,(pthread_mutex_t *)(this + 0x118),
               "BOOL MSrv_ChannelManager_DVB_Customer::GetProgramSelInfo(U16, U16&, U8&, U8&)",0x720
              );
                    /* try { // try from 2e1660b4 to 2e16610b has its CatchHandler @ 2e16657c */
    _UpdateFilterList(this);
    if ((param_1 == 0) ||
       ((uint)((*(int *)(this + 0x10c) - *(int *)(this + 0x108) >> 1) * -0x55555555) < uVar2)) {
      iVar4 = MSrv_Control_TV::GetMSrvDtv(0);
                    /* try { // try from 2e1663d4 to 2e166497 has its CatchHandler @ 2e16657c */
      if ((iVar4 == 0) ||
         (((piVar5 = (int *)__dynamic_cast(iVar4,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0),
           piVar5 == (int *)0x0 || (iVar4 = (**(code **)(*piVar5 + 0x344))(piVar5), iVar4 != 0)) ||
          (iVar4 = (**(code **)(*piVar5 + 0x364))(piVar5), iVar4 != 1)))) {
        iVar4 = 0;
      }
      else {
        piVar5 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
        iVar4 = (**(code **)(*piVar5 + 0x2f4))(piVar5,1,uVar2,0,auStack_36c);
        if (iVar4 != 0) {
          printf("@@@ MSrv_ChannelManager_DVB_Customer::GetProgramSelInfo with FindProgramByNumber DBNumber:%d Service:%d @@@\n"
                 ,uVar2,(uint)local_34f);
          *param_3 = local_34f;
          *param_2 = local_33a;
          piVar5 = (int *)MSrv_Control::GetInstance();
          uVar3 = (**(code **)(*piVar5 + 0x1b8))(piVar5,0);
          *param_4 = uVar3;
          if (local_35d == '\x01') {
            UpdateFilterListIndexes(this);
          }
        }
      }
    }
    else {
      iVar4 = *(int *)(this + 0x108) + (uVar2 - 1) * 6;
      uVar3 = *(uchar *)(iVar4 + 5);
      uVar1 = *(ushort *)(iVar4 + 2);
      *param_3 = *(uchar *)(iVar4 + 4);
      *param_2 = uVar1;
      iVar4 = 1;
      *param_4 = uVar3;
    }
    mapi_scope_lock::~mapi_scope_lock(amStack_3b8);
    return iVar4;
  }
  piVar5 = (int *)MSrv_Control::GetInstance();
  iVar4 = (**(code **)(*piVar5 + 0x84))(piVar5);
  if (iVar4 == 1) {
    if (param_1 != 0) {
      param_1 = param_1 - 1;
    }
    iVar4 = MSrv_Control_TV::GetMSrvAtv();
    uVar3 = '\0';
    if (iVar4 != 0) {
      uVar3 = __dynamic_cast(iVar4,&MSrv_ATV_Player::typeinfo,&MSrv_ATV_Player_Customer::typeinfo,0)
      ;
    }
    iVar4 = MSrv_ATV_Player_Customer::GetProgramActiveByIndex(uVar3);
    if (iVar4 != 0) {
      *param_3 = '\0';
      iVar4 = 1;
      *param_2 = param_1;
LAB_2e1662b0:
      piVar5 = (int *)MSrv_Control::GetInstance();
      uVar3 = (**(code **)(*piVar5 + 0x1b8))(piVar5,0);
      *param_4 = uVar3;
      return iVar4;
    }
  }
  else if (iVar4 == 0x1c) {
    local_39c = 0x2c828ac4;
    local_398 = local_39c;
                    /* try { // try from 2e16631c to 2e16637b has its CatchHandler @ 2e1665b0 */
    piVar5 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
    iVar4 = (**(code **)(*piVar5 + 0x1b0))(piVar5,auStack_3b4);
    if (iVar4 == 1) {
                    /* try { // try from 2e1664f0 to 2e16651b has its CatchHandler @ 2e1665b0 */
      piVar5 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
      iVar4 = (**(code **)(*piVar5 + 0x2f4))(piVar5,local_3a0,uVar2,0,auStack_1c8);
    }
    else {
      piVar5 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
      iVar4 = (**(code **)(*piVar5 + 0x2f4))(piVar5,1,uVar2,0,auStack_1c8);
    }
    if (iVar4 != 0) {
      *param_3 = local_1ab;
      *param_2 = local_196;
    }
    if ((allocator *)(local_398 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar6 = *(int *)(local_398 + -4);
      *(int *)(local_398 + -4) = iVar6 + -1;
      SYNC(0);
      if (iVar6 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_398 + -0xc));
      }
    }
    if ((allocator *)(local_39c + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar6 = *(int *)(local_39c + -4);
      *(int *)(local_39c + -4) = iVar6 + -1;
      SYNC(0);
      if (iVar6 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_39c + -0xc));
      }
    }
    if (iVar4 != 0) goto LAB_2e1662b0;
  }
  else {
    puts("TODO: We are not in TV source, where should we tune??");
  }
  return 0;
}

