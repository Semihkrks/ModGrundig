
/* MSrv_ChannelManager_DVB_Customer::GetProgramInfoByDisplayNum(unsigned short, unsigned char,
   ST_CM_SERVICE_QUERY&) */

int __thiscall
MSrv_ChannelManager_DVB_Customer::GetProgramInfoByDisplayNum
          (MSrv_ChannelManager_DVB_Customer *this,ushort param_1,uchar param_2,
          ST_CM_SERVICE_QUERY *param_3)

{
  undefined2 uVar1;
  uint uVar2;
  uchar uVar3;
  ST_CM_SERVICE_QUERY SVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  mapi_scope_lock amStack_370 [4];
  undefined1 auStack_36c [15];
  char local_35d;
  ST_CM_SERVICE_QUERY local_34f;
  undefined2 local_33a;
  undefined1 auStack_1c8 [29];
  ST_CM_SERVICE_QUERY local_1ab;
  undefined2 local_196;
  
  uVar2 = (uint)param_1;
  iVar5 = _isFilterListActive();
  if (iVar5 != 0) {
    mapi_scope_lock::mapi_scope_lock
              (amStack_370,(pthread_mutex_t *)(this + 0x118),
               "BOOL MSrv_ChannelManager_DVB_Customer::GetProgramInfoByDisplayNum(U16, U8, ST_CM_SERVICE_QUERY&)"
               ,0xeda);
                    /* try { // try from 2e16429c to 2e1642f3 has its CatchHandler @ 2e16447c */
    _UpdateFilterList(this);
    if ((param_1 == 0) ||
       ((uint)((*(int *)(this + 0x10c) - *(int *)(this + 0x108) >> 1) * -0x55555555) < uVar2)) {
      iVar5 = MSrv_Control_TV::GetMSrvDtv(0);
                    /* try { // try from 2e1643b4 to 2e164473 has its CatchHandler @ 2e16447c */
      if ((iVar5 == 0) ||
         (((piVar6 = (int *)__dynamic_cast(iVar5,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0),
           piVar6 == (int *)0x0 || (iVar5 = (**(code **)(*piVar6 + 0x344))(piVar6), iVar5 != 0)) ||
          (iVar5 = (**(code **)(*piVar6 + 0x364))(piVar6), iVar5 != 1)))) {
        iVar5 = 0;
      }
      else {
        piVar6 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
        iVar5 = (**(code **)(*piVar6 + 0x2f4))(piVar6,param_2,uVar2,0,auStack_36c);
        if (iVar5 != 0) {
          printf("@@@ MSrv_ChannelManager_DVB_Customer::GetProgramInfoByDisplayNum with FindProgramByNumber u16DispNumber:%d Service:%d @@@\n"
                 ,uVar2,(uint)(byte)local_34f);
          *(undefined2 *)(param_3 + 2) = local_33a;
          param_3[9] = local_34f;
          piVar6 = (int *)MSrv_Control::GetInstance();
          SVar4 = (ST_CM_SERVICE_QUERY)(**(code **)(*piVar6 + 0x1b8))(piVar6,0);
          param_3[0x12] = SVar4;
          if (local_35d == '\x01') {
            UpdateFilterListIndexes(this);
          }
        }
      }
    }
    else {
      iVar7 = *(int *)(this + 0x108) + (uVar2 - 1) * 6;
      SVar4 = *(ST_CM_SERVICE_QUERY *)(iVar7 + 5);
      uVar1 = *(undefined2 *)(iVar7 + 2);
      iVar5 = 1;
      param_3[9] = *(ST_CM_SERVICE_QUERY *)(iVar7 + 4);
      param_3[0x12] = SVar4;
      *(undefined2 *)(param_3 + 2) = uVar1;
    }
    mapi_scope_lock::~mapi_scope_lock(amStack_370);
    return iVar5;
  }
  if (param_2 == '\0') {
    if (param_1 != 0) {
      param_1 = param_1 - 1;
    }
    iVar5 = MSrv_Control_TV::GetMSrvAtv();
    uVar3 = '\0';
    if (iVar5 != 0) {
      uVar3 = __dynamic_cast(iVar5,&MSrv_ATV_Player::typeinfo,&MSrv_ATV_Player_Customer::typeinfo,0)
      ;
    }
    iVar5 = MSrv_ATV_Player_Customer::GetProgramActiveByIndex(uVar3);
    if (iVar5 == 0) {
      return 0;
    }
    *(ushort *)(param_3 + 2) = param_1;
    param_3[9] = (ST_CM_SERVICE_QUERY)0x0;
    iVar5 = 1;
  }
  else {
    piVar6 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
    iVar5 = (**(code **)(*piVar6 + 0x2f4))(piVar6,param_2,uVar2,0,auStack_1c8);
    if (iVar5 == 0) {
      return 0;
    }
    *(undefined2 *)(param_3 + 2) = local_196;
    param_3[9] = local_1ab;
  }
  piVar6 = (int *)MSrv_Control::GetInstance();
  SVar4 = (ST_CM_SERVICE_QUERY)(**(code **)(*piVar6 + 0x1b8))(piVar6,0);
  param_3[0x12] = SVar4;
  return iVar5;
}

