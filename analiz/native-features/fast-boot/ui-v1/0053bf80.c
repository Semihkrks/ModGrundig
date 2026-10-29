
/* ArTvSettingsManager::SetFastBootMode(unsigned char) */

void __thiscall ArTvSettingsManager::SetFastBootMode(ArTvSettingsManager *this,uchar param_1)

{
  uchar uVar1;
  
  uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::SetFastBootEnabled(uVar1);
  return;
}

