
/* ArTvSettingsManager::GetFastBootMode() */

void ArTvSettingsManager::GetFastBootMode(void)

{
  MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::GetFastBootEnabled();
  return;
}

