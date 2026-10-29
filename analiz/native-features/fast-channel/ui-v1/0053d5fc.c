
/* ArTvSettingsManager::GetFastZapping() */

void ArTvSettingsManager::GetFastZapping(void)

{
  MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::GetFastZapping();
  return;
}

