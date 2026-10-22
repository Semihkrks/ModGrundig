
/* ArResourceManager::SetActiveAntennaPower(AR_ACTIVE_ANTENNA_POWER) */

undefined4 __thiscall
ArResourceManager::SetActiveAntennaPower(undefined4 param_1,undefined4 param_2)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_c;
  
  arActiveAntennaPower = param_2;
  uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::SetActiveAntenna(uVar1);
  iVar2 = MSrv_Control::GetInstance();
  if (iVar2 == 0) {
    uStack_c = 0;
  }
  else {
    uStack_c = __dynamic_cast(iVar2,&DAT_2eaccd60,&DAT_2f1e3470,0);
  }
  MSrv_Control_common::GetMSrvSystemDatabase();
  uVar3 = MSrv_System_Database::GetActiveAntenna();
  MSrv_Control_Customer::AdjustAntenna5V(uStack_c,uVar3);
  return 1;
}

