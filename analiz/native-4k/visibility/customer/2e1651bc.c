
/* MSrv_ChannelManager_DVB_Customer::_CheckFilterListProgram(unsigned short, unsigned char) */

undefined4 __thiscall
MSrv_ChannelManager_DVB_Customer::_CheckFilterListProgram
          (MSrv_ChannelManager_DVB_Customer *this,ushort param_1,uchar param_2)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  mapi_scope_lock amStack_28 [12];
  
  iVar3 = GetFavMode();
  if (iVar3 == 0) {
    return 1;
  }
  mapi_scope_lock::mapi_scope_lock
            (amStack_28,(pthread_mutex_t *)(this + 0x118),
             "virtual BOOL MSrv_ChannelManager_DVB_Customer::_CheckFilterListProgram(U16, U8)",0xfc1
            );
                    /* try { // try from 2e16525c to 2e165307 has its CatchHandler @ 2e165350 */
  _UpdateFilterList(this);
  iVar5 = *(int *)(this + 0x108);
  iVar3 = *(int *)(this + 0x10c);
  if (iVar5 != iVar3) {
    do {
      while ((*(ushort *)(iVar5 + 2) != param_1 || (*(uchar *)(iVar5 + 4) != param_2))) {
        iVar5 = iVar5 + 6;
        if (iVar5 == iVar3) goto LAB_2e1652e8;
      }
      uVar1 = *(uchar *)(iVar5 + 5);
      piVar4 = (int *)MSrv_Control::GetInstance();
      uVar2 = (**(code **)(*piVar4 + 0x1b8))(piVar4,0);
      iVar3 = MSrv_Control_Customer::CompareRouteIndex(uVar1,uVar2);
      if (iVar3 != 0) {
        uVar6 = 1;
        goto LAB_2e165318;
      }
      iVar3 = *(int *)(this + 0x10c);
      iVar5 = iVar5 + 6;
    } while (iVar5 != iVar3);
  }
LAB_2e1652e8:
  puts("\n@@@ _CheckFilterListProgram: Set Fav Mode to None @@@");
  SetFavMode(this,0);
  uVar6 = 0;
LAB_2e165318:
  mapi_scope_lock::~mapi_scope_lock(amStack_28);
  return uVar6;
}

