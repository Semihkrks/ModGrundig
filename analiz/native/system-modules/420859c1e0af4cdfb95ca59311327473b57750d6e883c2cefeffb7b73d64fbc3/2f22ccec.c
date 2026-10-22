
/* MSrv_System_Database_DVB_Customer::_LoadFactoryChannels() */

void MSrv_System_Database_DVB_Customer::_LoadFactoryChannels(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 auStack_60 [84];
  
  uVar1 = (*(code *)PTR_Get_mapi_storage_atv_cmdb_2f242494)();
  (*(code *)PTR_Finalize_2f242658)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_atv_cmdb_backup_2f242240)();
  (*(code *)PTR_Finalize_2f242658)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_catv_cmdb_2f242164)();
  (*(code *)PTR_Finalize_2f242658)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_catv_cmdb_backup_2f2423a8)();
  (*(code *)PTR_Finalize_2f242658)(uVar1);
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_GetTVInfo_2f242274)();
    if (*(char *)(iVar2 + iVar3 + 0x13) == '\0') break;
    uVar1 = (*(code *)PTR_Get_mapi_storage_dtv_cmdb_2f2427b8)(iVar3);
    (*(code *)PTR_Finalize_2f242658)(uVar1);
    iVar2 = iVar3 + 1;
    uVar1 = (*(code *)PTR_Get_mapi_storage_dtv_cmdb_backup_2f2423ac)(iVar3);
    (*(code *)PTR_Finalize_2f242658)(uVar1);
    iVar3 = iVar2;
  } while (iVar2 != 4);
  (*(code *)PTR_memset_2f2420d4)(auStack_60,0,0x50);
  (*(code *)PTR_snprintf_2f24208c)
            (auStack_60,0x50,PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0xcc);
  iVar3 = (*(code *)PTR_system_2f241fc0)(auStack_60);
  (*(code *)PTR_snprintf_2f24208c)
            (auStack_60,0x50,PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x110);
  iVar2 = (*(code *)PTR_system_2f241fc0)(auStack_60);
  if (iVar2 == 0 && iVar3 == 0) {
    puVar4 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x180;
  }
  else {
    puVar4 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x158;
  }
  (*(code *)PTR_puts_2f242158)(puVar4);
  (*(code *)PTR_sync_2f242314)();
  uVar1 = (*(code *)PTR_Get_mapi_storage_atv_cmdb_2f242494)();
  (*(code *)PTR_Init_2f2426cc)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_atv_cmdb_backup_2f242240)();
  (*(code *)PTR_Init_2f2426cc)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_catv_cmdb_2f242164)();
  (*(code *)PTR_Init_2f2426cc)(uVar1);
  uVar1 = (*(code *)PTR_Get_mapi_storage_catv_cmdb_backup_2f2423a8)();
  (*(code *)PTR_Init_2f2426cc)(uVar1);
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_GetTVInfo_2f242274)();
    if (*(char *)(iVar2 + iVar3 + 0x13) == '\0') {
      return;
    }
    uVar1 = (*(code *)PTR_Get_mapi_storage_dtv_cmdb_2f2427b8)(iVar3);
    (*(code *)PTR_Init_2f2426cc)(uVar1);
    iVar2 = iVar3 + 1;
    uVar1 = (*(code *)PTR_Get_mapi_storage_dtv_cmdb_backup_2f2423ac)(iVar3);
    (*(code *)PTR_Init_2f2426cc)(uVar1);
    iVar3 = iVar2;
  } while (iVar2 != 4);
  return;
}

