
/* ArServiceSettingsManager::ArTvConf_GetFastBoot() */

void ArServiceSettingsManager::ArTvConf_GetFastBoot(void)

{
  ArTvManager::GetSystemDatabase();
  MSrv_System_Database::GetFactFastBoot();
  return;
}

