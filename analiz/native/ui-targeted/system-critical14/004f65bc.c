
/* ArScanManager::startAutoScan(void*, void*, void*) */

undefined4 ArScanManager::startAutoScan(void *param_1,void *param_2,void *param_3)

{
  uchar uVar1;
  int iVar2;
  int *piVar3;
  ST_CABLE_SETTINGS *pSVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  byte bStack_f4;
  allocator aaStack_dc [6];
  undefined2 uStack_d6;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 uStack_c5;
  string asStack_c0 [4];
  MW_DTV_ScanParam_DVBS aMStack_bc [4];
  undefined2 uStack_b8;
  char cStack_b6;
  byte bStack_b5;
  byte bStack_b4;
  undefined1 uStack_b3;
  byte bStack_94;
  int iStack_90;
  int *piStack_8c;
  int iStack_88;
  int iStack_84;
  undefined4 uStack_80;
  code *pcStack_7c;
  int *piStack_78;
  int iStack_74;
  int *piStack_70;
  undefined *puStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  int iStack_5c;
  int *piStack_58;
  int iStack_54;
  int *piStack_50;
  int iStack_4c;
  int iStack_48;
  int *piStack_44;
  int iStack_40;
  int iStack_3c;
  int *piStack_38;
  uint uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_24;
  int iStack_20;
  
  if (*(char *)((int)param_1 + 0x4d) == '\0') {
    resetInitials();
  }
  iStack_24 = MSrv_Control_common::GetMSrvTimer();
  if (iStack_24 == 0) {
    iStack_20 = 0;
  }
  else {
    iStack_20 = __dynamic_cast(iStack_24,&DAT_2da87e48,&DAT_2e028238,0);
  }
  iVar6 = iStack_20;
  if (iStack_20 == 0) {
    return 0;
  }
  iStack_30 = MSrv_Control_common::GetMSrvChannelManager();
  if (iStack_30 == 0) {
    uStack_2c = 0;
  }
  else {
    uStack_2c = __dynamic_cast(iStack_30,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
  }
  MSrv_ChannelManager_DVB_Customer::UpdateFilterListIndexes();
  uStack_34 = *(uint *)((int)param_1 + 0x6c);
  if (uStack_34 < 2) {
    if (*(int *)((int)param_1 + 0x6c) == 0) {
      piVar7 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
      (**(code **)(*piVar7 + 0x44))(piVar7,1,0,0,0);
      piVar7 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
      (**(code **)(*piVar7 + 0x40))(piVar7,2,0,0,0);
    }
    piVar7 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar7 + 0x84))(piVar7);
    if (iVar2 != 0x1c) {
      piVar7 = (int *)MSrv_Control::GetInstance();
      (**(code **)(*piVar7 + 0x90))(piVar7,0x1c,1,0,0,0,0);
    }
    ArTvManager::getInstance();
    iVar2 = ArTvManager::GetCurrentDvbAntennaType();
    uVar1 = (uchar)iVar6;
    if (iVar2 == 2) {
      iStack_3c = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_3c == 0) {
        piStack_38 = (int *)0x0;
      }
      else {
        piStack_38 = (int *)__dynamic_cast(iStack_3c,&DAT_2da86f20,&DAT_2ee35a10,0);
      }
      piVar7 = piStack_38;
      if (piStack_38 == (int *)0x0) {
        return 0;
      }
      piVar3 = (int *)MSrv_Control::GetInstance();
      (**(code **)(*piVar3 + 0x1b8))(piVar3,0);
      MSrv_Timer_Customer::DelEPGTimerByRoute(uVar1);
      pSVar4 = (ST_CABLE_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::GetCableInstallationSetting(pSVar4);
      uStack_d0 = 0;
      uStack_cc = 0;
      uStack_c5 = 0;
      uStack_d4 = 0xffffffff;
      uStack_d6 = 0;
      uStack_d0 = _GetCableScanOperator(param_1,*(undefined4 *)((int)param_1 + 0x54));
      if (*(int *)((int)param_1 + 0x60) != 0) {
        uStack_c5 = 1;
        uStack_d6 = (undefined2)*(undefined4 *)((int)param_1 + 0x60);
      }
      (**(code **)(*piVar7 + 0x958))(piVar7,uStack_d6);
      (**(code **)(*piVar7 + 0x938))(piVar7,uStack_d0);
      pSVar4 = (ST_CABLE_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::SetCableInstallationSetting(pSVar4);
      (**(code **)(*piVar7 + 0x92c))
                (piVar7,0,5,*(int *)((int)param_1 + 0x5c) * 1000,0,
                 *(uint *)((int)param_1 + 0x60) & 0xffff,0);
      iStack_40 = *(int *)((int)param_1 + 0x58);
      if (iStack_40 == 0) {
        if (*(int *)((int)param_1 + 0x5c) == 0) {
          piVar7 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
          iVar6 = (**(code **)(*piVar7 + 0x70))(piVar7);
          if (((iVar6 == 9) || (*(int *)((int)param_1 + 0x54) == 0x12)) ||
             (*(int *)((int)param_1 + 0x54) == 5)) {
            iStack_4c = 1;
          }
          else {
            iStack_4c = 0;
          }
          if (iStack_4c == 0) {
            SetCableScanType(param_1,1);
            iStack_54 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_54 == 0) {
              piStack_50 = (int *)0x0;
            }
            else {
              piStack_50 = (int *)__dynamic_cast(iStack_54,&DAT_2da86f20,&DAT_2edf3a70,0);
            }
            (**(code **)(*piStack_50 + 0x58c))(piStack_50);
          }
          else {
            piVar7 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
            (**(code **)(*piVar7 + 0xdc))(piVar7);
          }
        }
        else {
          piVar7 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
          (**(code **)(*piVar7 + 0xdc))(piVar7);
        }
      }
      else if (iStack_40 == 1) {
        iStack_48 = MSrv_Control_TV::GetMSrvDtv(0);
        if (iStack_48 == 0) {
          piStack_44 = (int *)0x0;
        }
        else {
          piStack_44 = (int *)__dynamic_cast(iStack_48,&DAT_2da86f20,&DAT_2edf3a70,0);
        }
        (**(code **)(*piStack_44 + 0x58c))(piStack_44);
      }
    }
    else if (iVar2 == 1) {
      piVar7 = (int *)MSrv_Control::GetInstance();
      (**(code **)(*piVar7 + 0x1b8))(piVar7,0);
      MSrv_Timer_Customer::DelEPGTimerByRoute(uVar1);
      piVar7 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
      (**(code **)(*piVar7 + 0xdc))(piVar7);
    }
    else {
      MW_DTV_ScanParam_DVBS::MW_DTV_ScanParam_DVBS(aMStack_bc);
      bStack_b5 = (byte)*(undefined4 *)((int)param_1 + 0x74);
      bStack_b4 = (byte)*(undefined4 *)((int)param_1 + 0x70);
      cStack_b6 = *(char *)((int)param_1 + 0x68);
      uStack_b8 = 0;
      uStack_b3 = 0;
      bStack_94 = *(char *)((int)param_1 + 0xc4) != '\x01';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::clear();
      std::vector<unsigned_short,std::allocator<unsigned_short>>::clear();
                    /* try { // try from 004f6e34 to 004f70f3 has its CatchHandler @ 004f7328 */
      iStack_5c = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_5c == 0) {
        piStack_58 = (int *)0x0;
      }
      else {
        piStack_58 = (int *)__dynamic_cast(iStack_5c,&DAT_2da86f20,&DAT_2ec1c460,0);
      }
      piVar7 = piStack_58;
      if (piStack_58 == (int *)0x0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe4454,&UNK_00fe4804,0x511);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      if (*(char *)((int)param_1 + 0xc4) == '\0') {
        MSrv_Timer_Customer::DelEPGTimerBySatID(uVar1);
      }
      (**(code **)(*piVar7 + 0x92c))(piVar7,aMStack_bc);
      (**(code **)(*piVar7 + 0x9a0))(piVar7,*(uint *)((int)param_1 + 100) & 0xff);
      uStack_60 = (uint)bStack_b5;
      uStack_64 = (uint)bStack_b4;
      uStack_68 = (uint)bStack_94;
      if (cStack_b6 == '\0') {
        puStack_6c = &UNK_00fe4514;
      }
      else {
        puStack_6c = &UNK_00fe450c;
      }
      printf("[dvbs ui] u8ScanMode %u, u8ServiceType %u, Delete:%u,bNetworkSearch %s\n ",uStack_60,
             uStack_64,uStack_68,puStack_6c);
      iStack_74 = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_74 == 0) {
        piStack_70 = (int *)0x0;
      }
      else {
        piStack_70 = (int *)__dynamic_cast(iStack_74,&DAT_2da86f20,&DAT_2ec1c460,0);
      }
      piStack_78 = piStack_70;
      pcStack_7c = *(code **)(*piStack_70 + 0xa10);
      uVar5 = _GetSatScanOperator(param_1,*(undefined4 *)((int)param_1 + 0x54));
      (*pcStack_7c)(piStack_78,uVar5);
      uStack_80 = MSrv_Control_common::GetMSrvSystemDatabase();
      uVar5 = _GetSatScanOperator(param_1,*(undefined4 *)((int)param_1 + 0x54));
      MSrv_System_Database::SetSatOperator(uStack_80,uVar5);
      ClearSearchResults(param_1);
      MSrv_Control_common::GetMSrvSystemDatabase();
      iVar6 = MSrv_System_Database::GetSatOperator();
      if (iVar6 == 8) {
        std::allocator<char>::allocator();
                    /* try { // try from 004f7140 to 004f7147 has its CatchHandler @ 004f7198 */
        std::string::string(asStack_c0,"HD+",aaStack_dc);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_dc);
                    /* try { // try from 004f7174 to 004f7247 has its CatchHandler @ 004f726c */
        bStack_f4 = ArCIModuleManager::FindMenuStr('\0',asStack_c0);
        if ((bStack_f4 == 0) && (iVar6 = ArCIModuleManager::IsSecondCIAvailable(), iVar6 != 0)) {
          iStack_84 = 1;
        }
        else {
          iStack_84 = 0;
        }
        if (iStack_84 != 0) {
          bStack_f4 = ArCIModuleManager::FindMenuStr('\x01',asStack_c0);
        }
        printf("@@@ Sat Search bAstraHDPlusMode:%d @@@\n",(uint)bStack_f4);
                    /* try { // try from 004f7258 to 004f725f has its CatchHandler @ 004f7328 */
        std::string::~string(asStack_c0);
      }
                    /* try { // try from 004f72ac to 004f7303 has its CatchHandler @ 004f7328 */
      uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
      MSrv_System_Database::SetAstraHDPlusMode(uVar1);
      piVar7 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
      (**(code **)(*piVar7 + 0xdc))(piVar7);
      MW_DTV_ScanParam_DVBS::~MW_DTV_ScanParam_DVBS(aMStack_bc);
    }
    if (*(int *)((int)param_1 + 0x6c) == 0) {
      *(undefined1 *)((int)param_1 + 0x95) = 1;
      *(undefined1 *)((int)param_1 + 0x94) = 2;
    }
    else {
      *(undefined1 *)((int)param_1 + 0x95) = 1;
      *(undefined1 *)((int)param_1 + 0x94) = 3;
    }
    return 1;
  }
  if (uStack_34 != 2) {
    return 1;
  }
  *(undefined1 *)((int)param_1 + 0x95) = 2;
  *(undefined1 *)((int)param_1 + 0x94) = 3;
  iVar6 = std::vector<ST_ScanServiceInfo,std::allocator<ST_ScanServiceInfo>>::size
                    ((vector<ST_ScanServiceInfo,std::allocator<ST_ScanServiceInfo>> *)
                     ((int)param_1 + 200));
  if (iVar6 != 0) {
    std::vector<ST_ScanServiceInfo,std::allocator<ST_ScanServiceInfo>>::clear();
  }
  piVar7 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
  (**(code **)(*piVar7 + 0x44))(piVar7,1,0,0,0);
  piVar7 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
  (**(code **)(*piVar7 + 0x40))(piVar7,2,0,0,0);
  piVar7 = (int *)MSrv_Control::GetInstance();
  iVar6 = (**(code **)(*piVar7 + 0x84))(piVar7);
  if (iVar6 == 1) goto LAB_004f7664;
  piVar7 = (int *)MSrv_Control::GetInstance();
  iVar6 = (**(code **)(*piVar7 + 0x84))(piVar7);
  if (iVar6 == 0x1c) {
    piVar7 = (int *)MSrv_Control::GetInstance();
    piVar7 = (int *)(**(code **)(*piVar7 + 0x1d0))(piVar7);
    iVar6 = (**(code **)(*piVar7 + 0x428))(piVar7);
    if (iVar6 == 0) goto LAB_004f7590;
    iStack_88 = 1;
  }
  else {
LAB_004f7590:
    iStack_88 = 0;
  }
  if (iStack_88 != 0) {
    iStack_90 = MSrv_Control_TV::GetMSrvDtv(0);
    if (iStack_90 == 0) {
      piStack_8c = (int *)0x0;
    }
    else {
      piStack_8c = (int *)__dynamic_cast(iStack_90,&DAT_2da86f20,&DAT_2d5d5108,0);
    }
    (**(code **)(*piStack_8c + 0x8b0))(piStack_8c);
  }
  piVar7 = (int *)MSrv_Control::GetInstance();
  (**(code **)(*piVar7 + 0x90))(piVar7,1,1,0,0,0,0);
LAB_004f7664:
  piVar7 = (int *)MSrv_Control_TV::GetMSrvAtv();
  (**(code **)(*piVar7 + 0xe0))(piVar7,800000,45000,860000,0);
  return 1;
}

