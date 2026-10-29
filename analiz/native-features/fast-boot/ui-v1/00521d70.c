
/* ArServiceSettingsManager::ArTvConf_SetFastBoot(long) */

void __thiscall
ArServiceSettingsManager::ArTvConf_SetFastBoot(ArServiceSettingsManager *this,long param_1)

{
  uchar uVar1;
  
  uVar1 = ArTvManager::GetSystemDatabase();
  MSrv_System_Database::SetFactFastBoot(uVar1);
  return;
}

