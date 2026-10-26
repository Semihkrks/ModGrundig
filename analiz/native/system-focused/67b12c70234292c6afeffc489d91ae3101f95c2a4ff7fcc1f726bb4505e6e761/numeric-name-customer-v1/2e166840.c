
/* WARNING: Removing unreachable block (ram,0x2e166dc0) */
/* WARNING: Removing unreachable block (ram,0x2e166df4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* MSrv_ChannelManager_DVB_Customer::ProgramSel(unsigned short) */

undefined4 __thiscall
MSrv_ChannelManager_DVB_Customer::ProgramSel(MSrv_ChannelManager_DVB_Customer *this,ushort param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  FILE *__stream;
  uchar uVar4;
  uchar uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  mapi_scope_lock amStack_208 [4];
  undefined1 auStack_204 [24];
  int local_1ec;
  int local_1e8;
  undefined1 auStack_1bc [15];
  char local_1ad;
  byte local_19f;
  
  __stream = _DAT_2c67c868;
  uVar9 = (uint)param_1;
  uVar6 = mapi_time_utility::GetPiuTimer1();
  fprintf(__stream,"\x1b[1;31m[AUTO_TEST][channel change]: ProgramSel [PIU][%lu]\x1b[0m\n",uVar6);
  iVar7 = _isFilterListActive();
  uVar4 = (uchar)param_1;
  if (iVar7 != 0) {
    mapi_scope_lock::mapi_scope_lock
              (amStack_208,(pthread_mutex_t *)(this + 0x118),
               "BOOL MSrv_ChannelManager_DVB_Customer::ProgramSel(U16)",0x66f);
                    /* try { // try from 2e1668e0 to 2e166937 has its CatchHandler @ 2e166dd0 */
    _UpdateFilterList(this);
    if ((param_1 == 0) ||
       ((uint)((*(int *)(this + 0x10c) - *(int *)(this + 0x108) >> 1) * -0x55555555) < uVar9)) {
      iVar7 = MSrv_Control_TV::GetMSrvDtv(0);
                    /* try { // try from 2e166b24 to 2e166c87 has its CatchHandler @ 2e166dd0 */
      if ((iVar7 == 0) ||
         (((piVar8 = (int *)__dynamic_cast(iVar7,&MSrv_DTV_Player::typeinfo,&DAT_2d5d5108,0),
           piVar8 == (int *)0x0 || (iVar7 = (**(code **)(*piVar8 + 0x344))(piVar8), iVar7 != 0)) ||
          (iVar7 = (**(code **)(*piVar8 + 0x364))(piVar8), iVar7 != 1)))) {
        uVar6 = 0;
      }
      else {
        piVar8 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
        iVar7 = (**(code **)(*piVar8 + 0x2f4))(piVar8,1,uVar9,0,auStack_1bc);
        uVar6 = 0;
        if (iVar7 != 0) {
          printf("@@@ MSrv_ChannelManager_DVB_Customer::ProgramSel with FindProgramByNumber DBNumber:%d Service:%d @@@\n"
                 ,uVar9,(uint)local_19f);
          uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,uVar4,(ushort)local_19f,'\0');
          if (local_1ad == '\x01') {
            UpdateFilterListIndexes(this);
          }
        }
      }
    }
    else {
      iVar7 = *(int *)(this + 0x108) + (uVar9 - 1) * 6;
      bVar1 = *(byte *)(iVar7 + 5);
      uVar3 = *(undefined2 *)(iVar7 + 2);
                    /* try { // try from 2e166a48 to 2e166a8b has its CatchHandler @ 2e166dd0 */
      bVar2 = *(byte *)(iVar7 + 4);
      MSrv_Control_common::GetMSrvSystemDatabase();
      iVar7 = MSrv_System_Database::GetFactMultiSourceFav();
      uVar4 = (uchar)uVar3;
      if (iVar7 != 0) {
        piVar8 = (int *)MSrv_Control::GetInstance();
        uVar9 = (**(code **)(*piVar8 + 0x1bc))(piVar8);
        if (bVar1 < uVar9) {
          piVar8 = (int *)MSrv_Control::GetInstance();
          uVar5 = (**(code **)(*piVar8 + 0x1b8))(piVar8,0);
          iVar7 = MSrv_Control_Customer::CompareRouteIndex(bVar1,uVar5);
          if (iVar7 == 0) {
            piVar8 = (int *)MSrv_Control::GetInstance();
            (**(code **)(*piVar8 + 0x98))(piVar8,(uint)bVar1,0,0);
          }
        }
      }
      if (bVar2 == 0) {
        uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,uVar4,0,'\0');
      }
      else {
        uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,uVar4,(ushort)bVar2,'\0');
      }
    }
    mapi_scope_lock::~mapi_scope_lock(amStack_208);
    return uVar6;
  }
  piVar8 = (int *)MSrv_Control::GetInstance();
  iVar7 = (**(code **)(*piVar8 + 0x84))(piVar8);
  if (iVar7 == 1) {
    if (param_1 != 0) {
      uVar9 = uVar9 - 1 & 0xffff;
    }
    iVar7 = MSrv_Control_TV::GetMSrvAtv();
    uVar4 = '\0';
    if (iVar7 != 0) {
      uVar4 = __dynamic_cast(iVar7,&MSrv_ATV_Player::typeinfo,&MSrv_ATV_Player_Customer::typeinfo,0)
      ;
    }
    iVar7 = MSrv_ATV_Player_Customer::GetProgramActiveByIndex(uVar4);
    uVar6 = 1;
    if (iVar7 != 0) {
      uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,(uchar)uVar9);
    }
  }
  else if (iVar7 == 0x1c) {
    local_1ec = 0x2c828ac4;
    local_1e8 = local_1ec;
                    /* try { // try from 2e166cb0 to 2e166d6f has its CatchHandler @ 2e166e04 */
    piVar8 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
    iVar7 = (**(code **)(*piVar8 + 0x1b0))(piVar8,auStack_204);
    if (iVar7 == 1) {
      uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,uVar4);
    }
    else {
      uVar6 = MSrv_ChannelManager_DVB::ProgramSel((ulong)this,uVar4);
    }
    if ((allocator *)(local_1e8 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar7 = *(int *)(local_1e8 + -4);
      *(int *)(local_1e8 + -4) = iVar7 + -1;
      SYNC(0);
      if (iVar7 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_1e8 + -0xc));
      }
    }
    if ((allocator *)(local_1ec + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar7 = *(int *)(local_1ec + -4);
      *(int *)(local_1ec + -4) = iVar7 + -1;
      SYNC(0);
      if (iVar7 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_1ec + -0xc));
      }
    }
  }
  else {
    uVar6 = 1;
    puts("TODO: We are not in TV source, where should we tune??");
  }
  return uVar6;
}

