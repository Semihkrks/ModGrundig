
/* ArScanManager::saveCurrentATVChannelToDB(unsigned long) */

void __thiscall ArScanManager::saveCurrentATVChannelToDB(ArScanManager *this,ulong param_1)

{
  int iVar1;
  int *piVar2;
  int iStack_14;
  int iStack_c;
  
  iVar1 = MSrv_Control_common::GetMSrvChannelManager();
  if (iVar1 == 0) {
    iStack_c = 0;
  }
  else {
    iStack_c = __dynamic_cast(iVar1,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
  }
  if (iStack_c != 0) {
    iVar1 = MSrv_ChannelManager_DVB_Customer::GetMoveMode();
    if (iVar1 == 0) {
      piVar2 = (int *)MSrv_Control_TV::GetMSrvAtv();
      (**(code **)(*piVar2 + 0x168))(piVar2,(param_1 & 0xff) - 1 & 0xff);
    }
    else {
      piVar2 = (int *)MSrv_Control_TV::GetMSrvAtv();
      (**(code **)(*piVar2 + 0x16c))(piVar2);
    }
    iVar1 = MSrv_Control_common::GetMSrvChannelManager();
    if (iVar1 == 0) {
      iStack_14 = 0;
    }
    else {
      iStack_14 = __dynamic_cast(iVar1,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
    }
    if (iStack_14 != 0) {
      MSrv_ChannelManager_DVB_Customer::UpdateFilterListIndexes();
    }
  }
  return;
}

