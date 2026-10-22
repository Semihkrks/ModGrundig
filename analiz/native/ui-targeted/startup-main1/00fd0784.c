
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00fd0784(float param_1,float param_2,int param_3,char **param_4)

{
  char cVar1;
  uchar uVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  ushort uVar6;
  int *piVar7;
  int iVar8;
  ostream *poVar9;
  int iVar10;
  int iVar11;
  MS_FACTORY_SOURCE_SETTINGS *pMVar12;
  MS_FACTORY_SYSTEM_SETTINGS *pMVar13;
  char *pcVar14;
  FILE *__stream;
  ArTvManager *this;
  undefined4 uVar15;
  byte bVar16;
  byte bStack_4db;
  char acStack_4da [22];
  uint uStack_4c4;
  undefined1 auStack_4c0 [96];
  uint uStack_460;
  undefined4 uStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  undefined1 auStack_3f8 [96];
  uint uStack_398;
  undefined1 auStack_394 [8];
  int iStack_38c;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  uint uStack_18;
  
  InitDebugLevels();
  bStack_4db = 0;
  puts("sn init-chk#1");
  InitCustomerOption(param_3,param_4);
  cVar1 = ProductKey_Initialize();
  MSrv_Control_TV::Build();
  piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar7 + 0x204))(piVar7,0);
  MApi_PNL_SetOutputPattern(1,0,0,0);
  if (g_bConsoleMode != '\x01') {
    LEDControlBoot_Initialize();
  }
  puts("sn init-chk#2");
  if (((g_bConsoleMode != '\x01') && (g_bQuickStart != '\x01')) && (g_bcommand_mode != '\x01')) {
    iVar8 = MDrv_WDT_IsReset();
    if (iVar8 == 0) {
      bStack_4db = 0;
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,"Watchdog Not Occured\n");
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
    }
    else {
      MDrv_WDT_ClearRstFlag();
      bStack_4db = 1;
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,"Watchdog Occured\n");
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
    }
  }
  board_detect::GetInstance();
  iVar8 = board_detect::GetBoardType();
  printf("\n\n\n=================================================  ");
  puts("\n    Board Name   :  SINGLETUNER BOARD");
  printf("\n    Main SW Ver. :  %s",&UNK_0100db98);
  printf("\n    Release Date :  %s",&UNK_0100dbcc);
  printf("\n    HW Ver.      :  %s",&UNK_0100dbe8);
  printf("\n    Compile Date :  %s",&UNK_0100dc08);
  printf("\n    Compile Time :  %s",&UNK_0100dc2c);
  puts("\n================================================= \n\n");
  puts("sn init-chk#3");
  mapi_interface::SetGopForceWrite('\x01',0xffff);
  MSystem::Initialize(param_3,param_4,'\0','\0');
  piVar7 = (int *)ArPanelManager::GetInstance();
  uVar5 = (**(code **)(*piVar7 + 0xa8))(piVar7);
  piVar7 = (int *)ArPanelManager::GetInstance();
  uVar6 = (**(code **)(*piVar7 + 0xb0))(piVar7);
  fprintf(_DAT_2c67c868,"[PANEL] \n \n *****  video width %d, height %d\n",(uint)uVar5,(uint)uVar6);
  if ((uVar5 == 0x556) && (uVar6 == 0x300)) {
    _DAT_2e2b3798 = 0x550;
    _DAT_2e2b379c = 0x300;
    MSystem::InitializeDFBLayer();
    MSystem::GetInstance();
    MSystem::SetFrameScaleRatio(param_1,param_2);
  }
  else {
    MSystem::InitializeDFBLayer();
  }
  iVar10 = MSystem::GetInstance();
  iVar10 = *(int *)(iVar10 + 0xc);
  (**(code **)(iVar10 + 0x28))(iVar10,2);
  (**(code **)(iVar10 + 0xd4))(iVar10,1);
  mapi_interface::SetGopForceWrite('\0',0xffff);
  puts("sn init-chk#4");
  InitMSrvControl();
  if (((g_bConsoleMode != '\x01') && (g_bQuickStart != '\x01')) &&
     ((g_bcommand_mode != '\x01' && (bStack_4db == 1)))) {
    iVar10 = MSrv_Control::GetInstance();
    if (iVar10 == 0) {
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,"!!!! oh no\n");
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
    }
    else {
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,"Set Control Watchdog Occured\n");
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
      MSrv_Control_DVB::SetWatchdogOccured((uchar)iVar10);
    }
  }
  if (g_bQuickStart != '\0') {
    puts("Disable watchdog for debugging purposes ");
    iVar10 = MSrv_Control_common::GetMSrvFactoryMode();
    if (iVar10 == 0) {
      puts("No Factory mode variable");
    }
    else {
      MSrv_Factory_Mode::SetWDT_ONOFF((uchar)iVar10);
    }
    uVar2 = ArTvManager::GetSystemDatabase();
    MSrv_System_Database::SetFactWatchdogOn(uVar2);
    uVar2 = ArTvManager::GetSystemDatabase();
    MSrv_System_Database::SetFactRecoveryMode(uVar2);
  }
  uVar2 = MSrv_Control_common::GetMSrvVideo();
  piVar7 = (int *)ArPanelManager::GetInstance();
  (**(code **)(*piVar7 + 0x5e4))(piVar7);
  MSrv_Video::SetMirrorMode(uVar2);
  iVar10 = mapi_video_customer::GetInstance();
  if (iVar10 == 0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_0100d180,&UNK_0100e230,0xcf8);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  piVar7 = (int *)ArPanelManager::GetInstance();
  (**(code **)(*piVar7 + 0x5e4))(piVar7);
  mapi_video_customer::ARapi_Ursa10SetMirrorFlag((uchar)iVar10);
  if ((uVar5 == 0x556) && (uVar6 == 0x300)) {
    iVar10 = MSystem::GetInstance();
    iVar11 = *(int *)(iVar10 + 0xc);
    (**(code **)(iVar11 + 0x28))(iVar11,2);
    (**(code **)(iVar11 + 0xd4))(iVar11,1);
    uStack_45c = 3;
    uStack_458 = 0x550;
    uStack_454 = 0x300;
    (**(code **)(iVar11 + 0x34))(iVar11,&uStack_45c);
    MSystem::ResetLayerSize(iVar10,6,0);
    MSystem::RecreateLayerSurface(iVar10,6);
  }
  iVar10 = MSrv_Control::GetInstance();
  *(undefined1 *)(iVar10 + 0x17c) = 0;
  if (g_bConsoleMode != '\x01') {
    LEDControl_Initialize();
    Create_IrLed_MonitorThread();
  }
  piVar7 = (int *)IEnvManager::Instance();
  if (piVar7 == (int *)0x0) {
LAB_00fd1264:
    iStack_1c = 0;
  }
  else {
    cVar3 = (**(code **)(*piVar7 + 8))(piVar7);
    if (cVar3 != '\x01') goto LAB_00fd1264;
    iStack_1c = 1;
  }
  if (iStack_1c != 0) {
    if (iVar8 == 0) {
      (**(code **)(*piVar7 + 0x1c))(piVar7,&UNK_0100dd34,&UNK_0100dd40);
      (**(code **)(*piVar7 + 0xc))(piVar7);
    }
    else if (iVar8 == 2) {
      (**(code **)(*piVar7 + 0x1c))(piVar7,&UNK_0100dd34,&UNK_0100dd48);
      (**(code **)(*piVar7 + 0xc))(piVar7);
    }
    else if (iVar8 == 3) {
      (**(code **)(*piVar7 + 0x1c))(piVar7,&UNK_0100dd34,&UNK_0100dd48);
      (**(code **)(*piVar7 + 0xc))(piVar7);
    }
  }
  if (iVar8 == 3) {
    pMVar12 = (MS_FACTORY_SOURCE_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
    MSrv_System_Database::GetFactorySourceSetting(pMVar12);
    if ((char)(uStack_4c4 >> 0x10) < '\0') {
      uStack_4c4 = uStack_4c4 & 0xff7fffff;
      pMVar12 = (MS_FACTORY_SOURCE_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::SetFactorySourceSetting(pMVar12);
    }
  }
  piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar7 + 0x154))(piVar7,auStack_4c0);
  puts("sn init-chk#5");
  cVar3 = IsDirectOn();
  if ((bStack_4db == 0) && (cVar3 == '\0')) {
    uStack_20 = 0;
  }
  else {
    uStack_20 = 1;
  }
  bVar16 = (byte)uStack_20;
  poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
  poVar9 = std::operator<<(poVar9,"[INFO] ");
  poVar9 = std::operator<<(poVar9,"bWatchdogOccured:");
  poVar9 = (ostream *)std::ostream::operator<<(poVar9,(ushort)bStack_4db);
  poVar9 = std::operator<<(poVar9," bDirectOnAllowed:");
  poVar9 = (ostream *)std::ostream::operator<<(poVar9,(ushort)bVar16);
  std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
  piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar7 + 0xdc))(piVar7,acStack_4da);
  if (acStack_4da[0] == '\0') {
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar8 = MSrv_System_Database::GetFactHotelMode();
    if (iVar8 == 0) {
LAB_00fd163c:
      iStack_24 = 0;
    }
    else {
      MSrv_Control_common::GetMSrvSystemDatabase();
      iVar8 = MSrv_System_Database::GetHotelAdmin();
      if (iVar8 == 0) goto LAB_00fd163c;
      iStack_24 = 1;
    }
    if (iStack_24 != 0) {
      uVar2 = MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::SetHotelAdmin(uVar2);
    }
  }
  pMVar13 = (MS_FACTORY_SYSTEM_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::GetFactorySystem(pMVar13);
  piVar7 = (int *)IEnvManager::Instance();
  if (piVar7 == (int *)0x0) {
LAB_00fd1704:
    iStack_28 = 0;
  }
  else {
    cVar3 = (**(code **)(*piVar7 + 8))(piVar7);
    if (cVar3 != '\x01') goto LAB_00fd1704;
    iStack_28 = 1;
  }
  if (iStack_28 != 0) {
    pcVar14 = (char *)(**(code **)(*piVar7 + 0x14))(piVar7,&UNK_0100d7c4);
    if ((pcVar14 != (char *)0x0) && (*pcVar14 == '1')) {
      (**(code **)(*piVar7 + 0x1c))(piVar7,&UNK_0100d7c4,&UNK_0100cf78);
      (**(code **)(*piVar7 + 0xc))(piVar7);
    }
  }
  if (cVar1 == '\x01') {
    piVar7 = (int *)MSrv_Control_common::GetMSrvSSSound();
    (**(code **)(*piVar7 + 0x1ec))(piVar7);
  }
  piVar7 = (int *)MSrv_Control::GetInstance();
  iVar8 = (**(code **)(*piVar7 + 100))(piVar7);
  if (iVar8 == 0) {
    MSrv_AC_Counter::Instance();
    MSrv_AC_Counter::count();
  }
  piVar7 = (int *)MSrv_Control::GetInstance();
  iVar8 = (**(code **)(*piVar7 + 100))(piVar7);
  if (iVar8 == 1) {
    poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
    poVar9 = std::operator<<(poVar9,"[INFO] ");
    poVar9 = std::operator<<(poVar9,
                             "\x1b[0;31m[!] MSrv_Control::GetInstance()->QueryPowerOnMode() : EN_POWER_DC_BOOT \x1b[0m\n"
                            );
    std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
    if (((uStack_460 & 0x1fff) >> 0xc == 1) && ((uStack_460 & 0x3fff) >> 0xd == 1)) {
      memset(&uStack_45c,0,100);
      piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      (**(code **)(*piVar7 + 0x21c))(piVar7,&uStack_45c);
      piVar7 = (int *)MSrv_Control_common::GetMSrvTimer();
      (**(code **)(*piVar7 + 0x40))(piVar7,1);
      iStack_30 = MSrv_Control_common::GetMSrvTimer();
      if (iStack_30 == 0) {
        uStack_2c = 0;
      }
      else {
        uStack_2c = __dynamic_cast(iStack_30,&DAT_2da87e48,&DAT_2e028238,0);
      }
      MSrv_Timer_Customer::SetDateTimeSetStatus(uStack_2c,0);
      iStack_38 = MSrv_Control_common::GetMSrvTimer();
      if (iStack_38 == 0) {
        uStack_34 = 0;
      }
      else {
        uStack_34 = __dynamic_cast(iStack_38,&DAT_2da87e48,&DAT_2e028238,0);
      }
      MSrv_Timer_Customer::ReCalculateManualTimeOffset();
      printf("[%s:%d] Jump to PM\n",&UNK_0100e228,0xd9d);
      printf("[%s:%d] Before calling EnterSleepMode from OAD\n",&UNK_0100e228,0xd9f);
      MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::GetFactCecOn();
      LEDControl_Finalize();
    }
    MSrv_DC_Counter::Instance();
    MSrv_DC_Counter::count();
    goto LAB_00fd207c;
  }
  if (bVar16 == 0) {
    piVar7 = (int *)MSrv_Control::GetInstance();
    iVar8 = (**(code **)(*piVar7 + 100))(piVar7);
    if (iVar8 != 0) goto LAB_00fd1b94;
LAB_00fd1bc4:
    iStack_3c = 1;
  }
  else {
LAB_00fd1b94:
    if (((uStack_460 & 0x1fff) >> 0xc == 1) && ((uStack_460 & 0x3fff) >> 0xd == 1))
    goto LAB_00fd1bc4;
    iStack_3c = 0;
  }
  if (iStack_3c != 0) {
    if ((uStack_460 & 0x1fff) >> 0xc == 1) {
      memset(&uStack_45c,0,100);
      piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      (**(code **)(*piVar7 + 0x21c))(piVar7,&uStack_45c);
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,
                               "main[info]First boot after successfull code installation: sleep system\x1b[0m\n"
                              );
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
    }
    iVar8 = MSrv_Control::GetInstance();
    MSrv_Control_common::GetMSrvSystemDatabase();
    uVar4 = MSrv_System_Database::GetFactAutoOnOffTest();
    *(undefined1 *)(iVar8 + 0x174) = uVar4;
    piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    iVar8 = (**(code **)(*piVar7 + 0x70))(piVar7);
    piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    (**(code **)(*piVar7 + 0xd0))(piVar7,auStack_394);
    if ((iVar8 == 7) && (iStack_38c == 0x1c)) {
      piVar7 = (int *)MSrv_Control::GetInstance();
      uVar2 = (**(code **)(*piVar7 + 0x1b8))(piVar7,0);
      iVar8 = MSrv_Control_common::GetRouteTVMode(uVar2);
      uStack_18 = iVar8 - 1;
      if ((uStack_18 < 0x20) && ((1 << (uStack_18 & 0x1f) & 0x80000003U) != 0)) {
        piVar7 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar7 + 0x25c))(piVar7,2);
        puts("\x1b[0;31m[!]AC BOOT EN_UPDATE_TIME\x1b[0m");
      }
      else {
        puts("\x1b[0;31m[!]AC BOOT EN_UPDATE_NONE\x1b[0m");
      }
    }
    piVar7 = (int *)MSrv_Control_common::GetMSrvTimer();
    (**(code **)(*piVar7 + 0x40))(piVar7,1);
    iStack_44 = MSrv_Control_common::GetMSrvTimer();
    if (iStack_44 == 0) {
      uStack_40 = 0;
    }
    else {
      uStack_40 = __dynamic_cast(iStack_44,&DAT_2da87e48,&DAT_2e028238,0);
    }
    MSrv_Timer_Customer::SetDateTimeSetStatus(uStack_40,0);
    iStack_4c = MSrv_Control_common::GetMSrvTimer();
    if (iStack_4c == 0) {
      uStack_48 = 0;
    }
    else {
      uStack_48 = __dynamic_cast(iStack_4c,&DAT_2da87e48,&DAT_2e028238,0);
    }
    MSrv_Timer_Customer::ReCalculateManualTimeOffset();
    piVar7 = (int *)MSrv_Control::GetInstance();
    iVar8 = (**(code **)(*piVar7 + 0x260))(piVar7);
    if (iVar8 == 2) {
      uVar15 = ArSrvPowerManager::GetInstance();
      ArSrvPowerManager::SetPowerState(uVar15,3,0);
      poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
      poVar9 = std::operator<<(poVar9,"[INFO] ");
      poVar9 = std::operator<<(poVar9,
                               "\x1b[0;31m[!]@@ Do not going to standby try to Update Date&Time @@@\x1b[0m\n"
                              );
      std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
      SetLEDBlinkEvent(6);
    }
  }
LAB_00fd207c:
  if ((uStack_460 & 0x3fff) >> 0xd == 1) {
    memset(&uStack_45c,0,100);
    piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    (**(code **)(*piVar7 + 0x21c))(piVar7,&uStack_45c);
  }
  __stream = fopen("/Customer/coreval","r");
  if (__stream == (FILE *)0x0) {
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar8 = MSrv_System_Database::GetFactRecoveryMode();
    if (iVar8 == 0) {
      system("echo \'1\' > /Customer/coreval");
    }
    else {
      system("echo \'0\' > /Customer/coreval");
    }
    system("sync");
  }
  else {
    fclose(__stream);
  }
  ArSrvPowerManager::GetInstance();
  iVar8 = ArSrvPowerManager::GetPowerState();
  if (iVar8 == 0) {
    piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar7 + 0xc0))(piVar7,0x21,0xff);
    piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar7 + 0xc0))(piVar7,0xf1,0xff);
    piVar7 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar7 + 0xc0))(piVar7,0x101,0xff);
  }
  StartMsrv();
  puts("sn init-chk#6");
  iVar8 = MResourcePkg::ReadResProfile();
  if (iVar8 == 0) {
    puts("Fail to Read ResProfile ");
    uStack_50 = 0;
  }
  else {
    if ((uVar5 == 0x556) && (uVar6 == 0x300)) {
      _DAT_2e2b3798 = 0x550;
      _DAT_2e2b379c = 0x300;
    }
    else {
      _DAT_2e2b3798 = 0x780;
      _DAT_2e2b379c = 0x438;
    }
    RegisterAllHotKey();
    piVar7 = (int *)MAppFactory::GetDefault();
    if (piVar7 == (int *)0x0) {
      puts("[Error]cannot get MApplet creator");
      uStack_50 = 0xffffffff;
    }
    else {
      DefaultApp = (**(code **)(*piVar7 + 8))(piVar7);
      if (DefaultApp == 0) {
        puts("[Error]cannot create MApplet instance");
        uStack_50 = 0xffffffff;
      }
      else {
        MApplet::Run(DefaultApp,(void *)0xfe);
        piVar7 = (int *)MSrv_Control_common::GetMSrvSourceDetect();
        (**(code **)(*piVar7 + 0x20))(piVar7);
        piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
        (**(code **)(*piVar7 + 0x154))(piVar7,auStack_3f8);
        if ((uStack_398 & 0xfff) >> 0xb == 0) {
          SetLEDBlinkEvent(5);
        }
        this = (ArTvManager *)ArTvManager::getInstance();
        ArTvManager::NotifyBootUpCompleted(this);
        ArSrvPowerManager::GetInstance();
        iVar8 = ArSrvPowerManager::GetPowerState();
        if (iVar8 == 0) {
          if (bVar16 == 0) {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"GO TO STR");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
            while( true ) {
              piVar7 = (int *)MSrv_Control::GetInstance();
              iVar8 = (**(code **)(*piVar7 + 0x108))(piVar7);
              if (iVar8 != 0) break;
              usleep(1000);
            }
            uVar15 = ArSrvPowerManager::GetInstance();
            ArSrvPowerManager::SetPowerState(uVar15,2,0);
          }
          else {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"DIRECT ON");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
            MApi_PNL_SetOutputPattern(0,0,0,0);
            uVar15 = ArSrvPowerManager::GetInstance();
            ArSrvPowerManager::SetPowerState(uVar15,4,0);
          }
        }
        _bLedKeepingLoop = 0;
        MSrv_Control_common::GetMSrvSystemDatabase();
        iVar8 = MSrv_System_Database::GetFactBreathingLED();
        if (iVar8 == 0) {
          UpdateLedPWMLevel();
        }
        if (g_bcommand_mode != '\0') {
          poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
          poVar9 = std::operator<<(poVar9,"[INFO] ");
          poVar9 = std::operator<<(poVar9,"Start Customer Test \n");
          std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
          iVar8 = StartCustomerTest();
          if (iVar8 == 0) {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"Start Customer Test returned NOK \n");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
          }
          else {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"Start Customer Test returned OK \n");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
          }
        }
        if ((g_bcommand_mode != '\0') || (g_bswoff_test != '\0')) {
          poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
          poVar9 = std::operator<<(poVar9,"[INFO] ");
          poVar9 = std::operator<<(poVar9,"Start Continuous Test \n");
          std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
          iVar8 = StartContinuousTests();
          if (iVar8 == 0) {
            puts("ERROR:Can not start continuous test");
          }
          else {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"StartContinuousTests returned OK \n");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
          }
        }
        if (g_bConsoleMode == '\0') {
          if (g_btest_mode != '\0') {
            cVar1 = test();
            if (cVar1 != '\x01') {
              puts("Test failed");
              do {
                sleep(1);
              } while( true );
            }
            puts("Test Passed ");
            do {
              sleep(1);
            } while( true );
          }
          if (g_bswoff_test != '\0') {
            poVar9 = std::operator<<((ostream *)&DAT_2c8273e4,MAIN_TAG);
            poVar9 = std::operator<<(poVar9,"[INFO] ");
            poVar9 = std::operator<<(poVar9,"EnableSwitchOffTest\n");
            std::ostream::operator<<(poVar9,std::endl<char,std::char_traits<char>>);
            EnableSwitchOffTest();
          }
          MSystem::GetInstance();
          MSystem::GetMWindowManager();
          MWindowManager::FlushKeyEvents();
          TestAdjustmentFactoryCommads();
          MSystem::Run();
          LEDControl_Finalize();
          MSrv_LoadingLogo::GetInstance();
          MSrv_LoadingLogo::ReleaseResource();
          MSystem::Shutdown();
          uStack_50 = 0;
        }
        else {
          console();
          uStack_50 = 0;
        }
      }
    }
  }
  return uStack_50;
}

