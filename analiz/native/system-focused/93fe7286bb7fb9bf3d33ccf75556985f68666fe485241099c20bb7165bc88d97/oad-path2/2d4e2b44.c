
/* MSrv_DTV_Player_DVB::OAD_AcceptStandbyDownload() */

undefined4 __thiscall MSrv_DTV_Player_DVB::OAD_AcceptStandbyDownload(MSrv_DTV_Player_DVB *this)

{
  int iVar1;
  
  if (*(int *)(this + 0x2b8) != 0) {
    iVar1 = __dynamic_cast(*(int *)(this + 0x2b8),&MSrv_DTV_DVB_OAD::typeinfo,
                           &MSrv_DTV_DVB_OAD_Customer::typeinfo,0);
    if (iVar1 != 0) {
      MSrv_DTV_DVB_OAD_Customer::OAD_AcceptStandbyDownload();
      return 1;
    }
  }
  return 0;
}

