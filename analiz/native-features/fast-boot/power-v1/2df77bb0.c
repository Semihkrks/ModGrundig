
/* ArSrvPowerManager::TaskOnToFakeStandby() */

void __thiscall ArSrvPowerManager::TaskOnToFakeStandby(ArSrvPowerManager *this)

{
  uchar uVar1;
  int iVar2;
  
  printf("[PowerManager]:%s\n","TaskOnToFakeStandby");
  DisableAV();
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar2 = MSrv_System_Database::GetFactHotelMode();
  if (iVar2 != 0) {
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar2 = MSrv_System_Database::GetHotelAdmin();
    if (iVar2 != 0) {
      uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
                    /* WARNING: Could not recover jumptable at 0x2df77c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      MSrv_System_Database::SetHotelAdmin(uVar1);
      return;
    }
  }
  return;
}

