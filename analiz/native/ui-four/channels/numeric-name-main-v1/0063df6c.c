
/* ArChannelManager::GetCurrentChannelInfo(ChannelInfo&, unsigned char) */

undefined4 ArChannelManager::GetCurrentChannelInfo(ChannelInfo *param_1,uchar param_2)

{
  ST_CM_SERVICE_QUERY *pSVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  ArTvManager *this;
  char *pcVar6;
  ChannelInfo *pCVar7;
  int *piVar8;
  ulong uVar9;
  undefined4 uVar10;
  int iStack_318;
  byte bStack_314;
  undefined2 uStack_304;
  undefined2 uStack_302;
  ChannelInfo CStack_2fe;
  ChannelInfo CStack_2fb;
  undefined2 uStack_2fa;
  undefined2 uStack_2f8;
  undefined2 uStack_2f6;
  undefined2 uStack_2f4;
  ChannelInfo CStack_2f2;
  string asStack_2f0 [8];
  undefined1 auStack_2e8 [48];
  undefined1 auStack_2b8 [16];
  int iStack_2a8;
  undefined1 auStack_2a4 [8];
  byte bStack_29c;
  byte bStack_299;
  char cStack_28e;
  undefined1 auStack_27c [172];
  ulong auStack_1d0 [96];
  byte bStack_50;
  byte bStack_4f;
  char cStack_4e;
  int iStack_48;
  int *piStack_44;
  int iStack_40;
  int *piStack_3c;
  uint uStack_38;
  uint uStack_34;
  string *psStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  ST_CM_SERVICE_QUERY *pSStack_24;
  undefined4 uStack_20;
  
  MSrv_Control::GetInstance();
  iVar5 = MSrv_Control_DVB::IsSourceChanging();
  if (iVar5 != 0) {
    puts("\n@@@ GetCurrentChannelInfo: Source is being switched, return!!! @@@");
    return 0;
  }
  iStack_28 = MSrv_Control_common::GetMSrvChannelManager();
  if (iStack_28 == 0) {
    pSStack_24 = (ST_CM_SERVICE_QUERY *)0x0;
  }
  else {
    pSStack_24 = (ST_CM_SERVICE_QUERY *)
                 __dynamic_cast(iStack_28,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
  }
  pSVar1 = pSStack_24;
  if (pSStack_24 == (ST_CM_SERVICE_QUERY *)0x0) {
    puts("\n@@@ GetCurrentChannelInfo: return @@@");
    return 0;
  }
  FUN_00627760(&uStack_304);
                    /* try { // try from 0063e0ac to 0063e4c3 has its CatchHandler @ 0063ebc4 */
  iVar5 = MSrv_ChannelManager_DVB_Customer::GetCurrentServiceInfo(pSVar1);
  if (iVar5 == 0) {
    uStack_20 = 0;
    goto LAB_0063ec0c;
  }
  this = (ArTvManager *)ArTvManager::getInstance();
  cVar2 = ArTvManager::GetCurrentInputSourceType(this);
  if (cVar2 == '\0') {
    *(undefined2 *)(param_1 + 2) = uStack_304;
    *(undefined2 *)param_1 = *(undefined2 *)(param_1 + 2);
  }
  else {
    if (cVar2 != '\x01') {
      uStack_20 = 0;
      goto LAB_0063ec0c;
    }
    *(undefined2 *)param_1 = uStack_304;
    *(undefined2 *)(param_1 + 2) = uStack_302;
    std::string::operator=((string *)(param_1 + 0x50),"ATV");
    MSrv_Control_common::GetMSrvSSSound();
    uStack_2c = MSrv_SSSound::GetMtsMode();
    switch(uStack_2c) {
    default:
      std::string::operator=((string *)(param_1 + 0x44),"MONO");
      break;
    case 1:
    case 2:
    case 0xf:
      std::string::operator=((string *)(param_1 + 0x44),"MONO");
      break;
    case 3:
    case 4:
    case 9:
    case 0x12:
      std::string::operator=((string *)(param_1 + 0x44),"STEREO");
      break;
    case 7:
    case 0x10:
      std::string::operator=((string *)(param_1 + 0x44),"DUAL I");
      break;
    case 8:
    case 0x11:
      std::string::operator=((string *)(param_1 + 0x44),"DUAL II");
      break;
    case 10:
      std::string::operator=((string *)(param_1 + 0x44),"NICAM MONO");
      break;
    case 0xb:
    case 0xe:
      std::string::operator=((string *)(param_1 + 0x44),"NICAM STEREO");
      break;
    case 0xc:
      std::string::operator=((string *)(param_1 + 0x44),"NICAM DUAL I");
      break;
    case 0xd:
      std::string::operator=((string *)(param_1 + 0x44),"NICAM DUAL II");
    }
    param_1[0x40] = (ChannelInfo)0x0;
    *(undefined2 *)(param_1 + 0x4a) = 0x3f3;
    param_1[0x4c] = (ChannelInfo)0x0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined2 *)(param_1 + 0x48) = 0x3f3;
  }
  *(undefined2 *)(param_1 + 0x58) = uStack_2fa;
  *(undefined2 *)(param_1 + 0x5a) = uStack_2f8;
  *(undefined2 *)(param_1 + 0x5c) = uStack_2f6;
  *(undefined2 *)(param_1 + 0x5e) = uStack_2f4;
  param_1[5] = CStack_2f2;
  param_1[4] = CStack_2fb;
  param_1[0xc] = CStack_2fe;
  cVar3 = std::string::empty();
  if (cVar3 == '\x01') {
    psStack_30 = (string *)(param_1 + 8);
    pcVar6 = (char *)GetRcEngine::RcGetString(0x29e);
    std::string::operator=(psStack_30,pcVar6);
  }
  else {
    std::string::operator=((string *)(param_1 + 8),asStack_2f0);
  }
  param_1[0x1b] = (ChannelInfo)0x0;
  param_1[0x33] = (ChannelInfo)0x0;
  if ((param_2 != '\0') && (cVar2 == '\0')) {
    FUN_0062ea68(auStack_27c);
                    /* try { // try from 0063e4d8 to 0063e4df has its CatchHandler @ 0063eb74 */
    FUN_0062eac0(auStack_2e8);
                    /* try { // try from 0063e4f4 to 0063e4fb has its CatchHandler @ 0063eb2c */
    FUN_00627810(auStack_2b8);
                    /* try { // try from 0063e504 to 0063ea77 has its CatchHandler @ 0063eac8 */
    pCVar7 = (ChannelInfo *)ArEpgManager::getInstance();
    ArEpgManager::GetPresentFollowingEventItems(pCVar7);
    piVar8 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
    iVar5 = (**(code **)(*piVar8 + 0x1f0))(piVar8,auStack_2b8);
    if (iVar5 != 0) {
      if (cStack_28e == '\0') {
        param_1[0x40] = (ChannelInfo)0x0;
      }
      else {
        param_1[0x40] = (ChannelInfo)0x1;
      }
      uStack_34 = (uint)bStack_29c;
      switch(uStack_34) {
      case 0:
        std::string::operator=((string *)(param_1 + 0x44),"MPEG");
        break;
      case 1:
        std::string::operator=((string *)(param_1 + 0x44),"DOLBY D");
        break;
      default:
        std::string::operator=((string *)(param_1 + 0x44)," ");
        break;
      case 3:
      case 5:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
        uStack_38 = (uint)bStack_299;
        if (uStack_38 < 0x50) {
code_r0x0063e6c4:
          std::string::operator=((string *)(param_1 + 0x44),"HE-AAC");
        }
        else if (uStack_38 < 0x54) {
          std::string::operator=((string *)(param_1 + 0x44),"AAC");
        }
        else {
          if (3 < uStack_38 - 0x58) goto code_r0x0063e6c4;
          std::string::operator=((string *)(param_1 + 0x44),"HE-AAC");
        }
        break;
      case 4:
        std::string::operator=((string *)(param_1 + 0x44),"DOLBY D+");
      }
      iStack_40 = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_40 == 0) {
        piStack_3c = (int *)0x0;
      }
      else {
        piStack_3c = (int *)__dynamic_cast(iStack_40,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      uVar9 = (**(code **)(*piStack_3c + 0x59c))(piStack_3c,auStack_2a4);
      uVar4 = ArResourceManager::GetLanguageStringID(uVar9);
      *(undefined2 *)(param_1 + 0x48) = uVar4;
      iStack_48 = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_48 == 0) {
        piStack_44 = (int *)0x0;
      }
      else {
        piStack_44 = (int *)__dynamic_cast(iStack_48,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      iVar5 = (**(code **)(*piStack_44 + 0x39c))(piStack_44,auStack_1d0);
      if (iVar5 == 0) {
        bStack_314 = 0;
      }
      else {
        bStack_314 = bStack_4f;
      }
      if (bStack_314 == 0) {
        *(undefined2 *)(param_1 + 0x4a) = 0x3f3;
      }
      else if ((cStack_4e == '\0') || (bStack_314 <= bStack_50)) {
        *(undefined2 *)(param_1 + 0x4a) = 0xe4c;
      }
      else {
        uVar4 = ArResourceManager::GetLanguageStringID(auStack_1d0[(uint)bStack_50 * 4]);
        *(undefined2 *)(param_1 + 0x4a) = uVar4;
      }
      param_1[0x4c] = (ChannelInfo)0x0;
      for (iStack_318 = 0; iStack_318 < (int)(uint)bStack_314; iStack_318 = iStack_318 + 1) {
        if ((auStack_1d0[iStack_318 * 4 + 1] == 2) ||
           ((0x1f < (int)auStack_1d0[iStack_318 * 4 + 1] &&
            ((int)auStack_1d0[iStack_318 * 4 + 1] < 0x25)))) {
          param_1[0x4c] = (ChannelInfo)0x1;
          break;
        }
        param_1[0x4c] = (ChannelInfo)0x0;
      }
      if (iStack_2a8 == 2) {
        std::string::operator=((string *)(param_1 + 0x50),"RADIO");
      }
      else if (iStack_2a8 == 3) {
        std::string::operator=((string *)(param_1 + 0x50),"DATA");
      }
      else {
        std::string::operator=((string *)(param_1 + 0x50),"DTV");
      }
      ArVideoManager::getInstance();
      uVar10 = ArVideoManager::IsDTVHD();
      *(undefined4 *)(param_1 + 0x54) = uVar10;
    }
                    /* try { // try from 0063ea98 to 0063ea9f has its CatchHandler @ 0063eb2c */
    FUN_006275b4(auStack_2b8);
                    /* try { // try from 0063eab4 to 0063eabb has its CatchHandler @ 0063eb74 */
    FUN_0062eb8c(auStack_2e8);
                    /* try { // try from 0063eb18 to 0063eb1f has its CatchHandler @ 0063ebc4 */
    FUN_0062edfc(auStack_27c);
  }
  uStack_20 = 1;
LAB_0063ec0c:
  FUN_00627504(&uStack_304);
  return uStack_20;
}

