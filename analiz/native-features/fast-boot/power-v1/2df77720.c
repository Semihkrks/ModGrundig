
/* ArSrvPowerManager::TaskFakeStandbyToOn() */

void __thiscall ArSrvPowerManager::TaskFakeStandbyToOn(ArSrvPowerManager *this)

{
  int *piVar1;
  MEvtHandle *pMVar2;
  int iVar3;
  char *__s1;
  undefined4 uVar4;
  undefined2 local_18 [6];
  
  printf("[PowerManager]:%s\n","TaskFakeStandbyToOn");
  SetLEDBlinkEvent(0xc);
  usleep(5000);
  SetLEDBlinkEvent(5);
  piVar1 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar1 + 0x204))(piVar1,0);
  pMVar2 = (MEvtHandle *)MSrv_Control::GetInstance();
  MSrv_Control_Customer::PostUIMessage(pMVar2,0,0x9ffffc38,0);
  piVar1 = (int *)MSrv_Control::GetInstance();
  iVar3 = (**(code **)(*piVar1 + 0x84))(piVar1);
  if (iVar3 == 0x1c) {
    MSrv_Control_TV::GetMSrvDtv(0);
    printf("[PowerManager]:%s DTV Returning original program\n","TaskFakeStandbyToOn");
    MSrv_DTV_Player_DVB::SelectLatestProgram();
    MSrv_DTV_Player_DVB::CIDoFreeAllTSInfo();
  }
  else if (iVar3 == 1) {
    printf("[PowerManager]:%s ATV Returning original program\n","TaskFakeStandbyToOn");
    piVar1 = (int *)MSrv_Control_TV::GetMSrvAtv();
    (**(code **)(*piVar1 + 0x108))(piVar1,local_18);
    (**(code **)(*piVar1 + 0x130))(piVar1,local_18[0],1);
  }
  ArServiceSettingsManager::getInstance();
  __s1 = (char *)ArServiceSettingsManager::ArPanelConf_GetPanelName();
  iVar3 = strcmp(__s1,"32SW4_GR");
  if (iVar3 == 0) {
    ArServiceSettingsManager::getInstance();
    uVar4 = ArServiceSettingsManager::ArPanelConf_GetPanelName();
    printf("\n ******* [%d] panelname = %s ****** \n",0x1e6,uVar4);
    MApi_XC_FPLLCustomerMode(2,0,0x400);
    MApi_XC_FPLLCustomerMode(2,1,0x1200);
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar3 = MSrv_System_Database::GetFactHotelMode();
  }
  else {
    ArServiceSettingsManager::getInstance();
    uVar4 = ArServiceSettingsManager::ArPanelConf_GetPanelName();
    printf("\n [%d] panelname = %s ",0x1ec,uVar4);
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar3 = MSrv_System_Database::GetFactHotelMode();
  }
  if (iVar3 != 0) {
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar3 = MSrv_System_Database::GetHotelLogoEnable();
    if (iVar3 != 0) {
      ShowHotelTVBootLogo();
    }
  }
  EnableAV();
  system("cat /proc/meminfo | grep MemFree");
  return;
}

