
/* MSrv_DTV_Player_DVBS::UpdateSCIFInfo(MS_SCIF_CONFIG_DB&) */

bool MSrv_DTV_Player_DVBS::UpdateSCIFInfo(MS_SCIF_CONFIG_DB *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x1590) + 0xb8))();
  return iVar1 != 0;
}

