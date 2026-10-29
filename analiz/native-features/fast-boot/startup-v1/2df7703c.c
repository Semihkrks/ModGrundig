
/* ArSrvPowerManager::TaskBootingToOn() */

void __thiscall ArSrvPowerManager::TaskBootingToOn(ArSrvPowerManager *this)

{
  int iVar1;
  char *__s1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  
  printf("[PowerManager]:%s\n","TaskBootingToOn");
  SetLEDBlinkEvent(0xc);
  usleep(5000);
  SetLEDBlinkEvent(5);
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar1 = MSrv_System_Database::GetFactHotelMode();
  if (iVar1 != 0) {
    piVar3 = (int *)MSrv_Control::GetInstance();
    iVar1 = (**(code **)(*piVar3 + 0x88))(piVar3);
    if (iVar1 != 0x1c) {
      piVar3 = (int *)MSrv_Control::GetInstance();
      iVar1 = (**(code **)(*piVar3 + 0x88))(piVar3);
      if (iVar1 != 1) goto LAB_2df770d8;
    }
    MSrv_Control_common::GetMSrvSystemDatabase();
    uVar4 = MSrv_System_Database::GetHotelStartSeviceType();
    piVar3 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    iVar1 = (**(code **)(*piVar3 + 0x8c))(piVar3);
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar5 = MSrv_System_Database::GetHotelStartDTVRoute();
    if (iVar1 != iVar5) {
      piVar3 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      pcVar6 = *(code **)(*piVar3 + 0x18c);
      MSrv_Control_common::GetMSrvSystemDatabase();
      uVar2 = MSrv_System_Database::GetHotelStartDTVRoute();
      (*pcVar6)(piVar3,uVar2);
    }
    if (uVar4 == 0) {
      piVar3 = (int *)MSrv_Control::GetInstance();
      (**(code **)(*piVar3 + 0x90))(piVar3,1,1,0,0,0,0);
      piVar3 = (int *)MSrv_Control_common::GetMSrvChannelManager();
      pcVar6 = *(code **)(*piVar3 + 100);
      MSrv_Control_common::GetMSrvSystemDatabase();
      uVar2 = MSrv_System_Database::GetHotelStartSeviceNum();
      (*pcVar6)(piVar3,uVar2,0);
    }
    else {
      piVar3 = (int *)MSrv_Control::GetInstance();
      (**(code **)(*piVar3 + 0x90))(piVar3,0x1c,1,0,0,0,0);
      piVar3 = (int *)MSrv_Control_common::GetMSrvChannelManager();
      pcVar6 = *(code **)(*piVar3 + 100);
      MSrv_Control_common::GetMSrvSystemDatabase();
      uVar2 = MSrv_System_Database::GetHotelStartSeviceNum();
      (*pcVar6)(piVar3,uVar2,uVar4 & 0xff);
    }
  }
LAB_2df770d8:
  ArServiceSettingsManager::getInstance();
  __s1 = (char *)ArServiceSettingsManager::ArPanelConf_GetPanelName();
  iVar1 = strcmp(__s1,"32SW4_GR");
  if (iVar1 == 0) {
    ArServiceSettingsManager::getInstance();
    uVar2 = ArServiceSettingsManager::ArPanelConf_GetPanelName();
    printf("\n ******* [%d] panelname = %s ****** \n",0x251,uVar2);
    MApi_XC_FPLLCustomerMode(2,0,0x400);
    MApi_XC_FPLLCustomerMode(2,1,0x1200);
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar1 = MSrv_System_Database::GetFactHotelMode();
  }
  else {
    ArServiceSettingsManager::getInstance();
    uVar2 = ArServiceSettingsManager::ArPanelConf_GetPanelName();
    printf("\n [%d] panelname = %s ",599,uVar2);
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar1 = MSrv_System_Database::GetFactHotelMode();
  }
  if (iVar1 != 0) {
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar1 = MSrv_System_Database::GetHotelLogoEnable();
    if (iVar1 != 0) {
      ShowHotelTVBootLogo();
                    /* WARNING: Could not recover jumptable at 0x2df77278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      EnableAV();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x2df771c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableAV();
  return;
}

