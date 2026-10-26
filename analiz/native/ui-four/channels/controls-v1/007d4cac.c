
/* ArProgramInfoFrame::RefreshUI(unsigned char) */

void __thiscall ArProgramInfoFrame::RefreshUI(ArProgramInfoFrame *this,uchar param_1)

{
  char cVar1;
  ArTvManager *pAVar2;
  int iVar3;
  int iVar4;
  ArVideoManager *pAVar5;
  char *pcVar6;
  string *psVar7;
  int *piVar8;
  ulong uVar9;
  ArTvSettingsManager *this_00;
  ArEpgManager *this_01;
  undefined4 uVar10;
  ArTvPlayer *pAVar11;
  long lVar12;
  double in_f0_1;
  double dVar13;
  EventInfo *pEStack_c14;
  byte bStack_c08;
  char cStack_c00;
  allocator aaStack_bec [4];
  string asStack_be8 [4];
  allocator aaStack_be4 [4];
  string asStack_be0 [4];
  string asStack_bdc [4];
  allocator aaStack_bd8 [4];
  string asStack_bd4 [4];
  allocator aaStack_bd0 [4];
  string asStack_bcc [4];
  ArUIManager aAStack_bc8 [4];
  ArUIManager aAStack_bc4 [4];
  ArUIManager aAStack_bc0 [4];
  string asStack_bbc [4];
  string asStack_bb8 [4];
  ArUIManager aAStack_bb4 [4];
  ArUIManager aAStack_bb0 [4];
  string asStack_bac [4];
  string asStack_ba8 [4];
  ArUIManager aAStack_ba4 [4];
  allocator aaStack_ba0 [4];
  string asStack_b9c [4];
  ArUIManager aAStack_b98 [4];
  ArUIManager aAStack_b94 [4];
  string asStack_b90 [4];
  string asStack_b8c [4];
  allocator aaStack_b88 [4];
  string asStack_b84 [4];
  allocator aaStack_b80 [4];
  string asStack_b7c [4];
  ArUIManager aAStack_b78 [4];
  allocator aaStack_b74 [4];
  string asStack_b70 [4];
  allocator aaStack_b6c [4];
  string asStack_b68 [4];
  string asStack_b64 [4];
  allocator aaStack_b60 [4];
  string asStack_b5c [4];
  string asStack_b58 [4];
  undefined4 uStack_b54;
  undefined4 uStack_b50;
  undefined4 uStack_b44;
  int iStack_b40;
  int iStack_b34;
  undefined4 uStack_b30;
  int iStack_b2c;
  int iStack_b24;
  undefined4 uStack_b20;
  int iStack_b1c;
  undefined4 uStack_b14;
  undefined4 uStack_b10;
  int iStack_b0c;
  int iStack_b04;
  undefined4 uStack_b00;
  int iStack_afc;
  int iStack_af4;
  undefined4 uStack_af0;
  int iStack_ae4;
  undefined4 uStack_ae0;
  int iStack_ad4;
  undefined4 uStack_ad0;
  string asStack_ac4 [4];
  PVR_BROWSER_METADATA aPStack_ac0 [4];
  char acStack_abc [16];
  MString aMStack_aac [12];
  undefined4 uStack_aa0;
  undefined4 uStack_a9c;
  undefined4 uStack_a90;
  undefined4 uStack_a8c;
  string asStack_a80 [4];
  undefined4 uStack_a7c;
  undefined4 uStack_a78;
  MString aMStack_a6c [12];
  string asStack_a60 [4];
  MString aMStack_a5c [12];
  char acStack_a50 [64];
  ushort auStack_a10 [6];
  undefined1 uStack_a04;
  EventInfo aEStack_a00 [11];
  char cStack_9f5;
  ulong uStack_9e8;
  int iStack_9e4;
  char cStack_9dd;
  char cStack_9d0;
  char cStack_9c4;
  int iStack_9bc;
  ushort uStack_9b8;
  ushort uStack_9b6;
  ushort uStack_9b4;
  ushort uStack_9b2;
  ostringstream aoStack_9ac [20];
  undefined1 auStack_998 [160];
  ulong auStack_8f8 [96];
  byte bStack_778;
  byte bStack_777;
  char cStack_776;
  ushort uStack_770;
  char cStack_6ee;
  char cStack_66e;
  char acStack_5ee [991];
  byte bStack_20f;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  long lStack_1bc;
  long lStack_1b8;
  long lStack_1b4;
  long lStack_1b0;
  long lStack_1ac;
  long lStack_1a8;
  long lStack_1a4;
  long lStack_1a0;
  long lStack_19c;
  long lStack_198;
  long lStack_194;
  long lStack_190;
  long lStack_18c;
  long lStack_188;
  long lStack_184;
  long lStack_180;
  long lStack_17c;
  long lStack_178;
  long lStack_174;
  long lStack_170;
  long lStack_16c;
  long lStack_168;
  int iStack_164;
  long lStack_160;
  long lStack_15c;
  long lStack_158;
  long lStack_154;
  long lStack_150;
  int iStack_14c;
  long lStack_148;
  long lStack_144;
  long lStack_140;
  long lStack_13c;
  int iStack_138;
  long lStack_134;
  int iStack_130;
  long lStack_12c;
  long lStack_128;
  long lStack_124;
  long lStack_120;
  long lStack_11c;
  long lStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  int iStack_100;
  undefined4 uStack_fc;
  char *pcStack_f8;
  char *pcStack_f4;
  string *psStack_f0;
  string *psStack_ec;
  string *psStack_e8;
  int iStack_e4;
  int iStack_e0;
  string *psStack_dc;
  ulong uStack_d8;
  double dStack_d0;
  string *psStack_c8;
  string *psStack_c4;
  string *psStack_c0;
  string *psStack_bc;
  string *psStack_b8;
  string *psStack_b4;
  char *pcStack_b0;
  int iStack_ac;
  string *psStack_a8;
  string *psStack_a4;
  int iStack_a0;
  long lStack_9c;
  long lStack_98;
  long lStack_94;
  long lStack_90;
  long lStack_8c;
  long lStack_88;
  int iStack_84;
  int iStack_80;
  int *piStack_7c;
  int iStack_78;
  int iStack_74;
  int *piStack_70;
  string *psStack_6c;
  string *psStack_68;
  string *psStack_64;
  string *psStack_60;
  string *psStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  string *psStack_50;
  char *pcStack_4c;
  long lStack_48;
  long lStack_44;
  long lStack_40;
  long lStack_3c;
  int iStack_38;
  int iStack_34;
  int *piStack_30;
  double dStack_20;
  undefined8 uStack_18;
  
  memset(acStack_a50,0,0x40);
  FUN_007d3e44(auStack_a10);
                    /* try { // try from 007d4d24 to 007d511f has its CatchHandler @ 007dadc0 */
  pAVar2 = (ArTvManager *)ArTvManager::getInstance();
  iVar3 = ArTvManager::GetCurrentInputSourceType(pAVar2);
  if (iVar3 == 0xd) goto LAB_007dae08;
  iStack_34 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iStack_34 == 0) {
    piStack_30 = (int *)0x0;
  }
  else {
    piStack_30 = (int *)__dynamic_cast(iStack_34,&DAT_2da86f20,&DAT_2d5d5108,0);
  }
  piVar8 = piStack_30;
  ArTvManager::getInstance();
  iVar4 = ArTvManager::GetCurrentDvbAntennaType();
  if (iVar4 == 3) {
    ArScanManager::getInstance();
    iVar4 = ArScanManager::GetDBSatScanOperatorUIType();
    if (iVar4 != 7) {
      ArScanManager::getInstance();
      iVar4 = ArScanManager::GetDBSatScanOperatorUIType();
      if (iVar4 != 8) goto LAB_007d4e60;
    }
    iStack_38 = 1;
  }
  else {
LAB_007d4e60:
    iStack_38 = 0;
  }
  if (iStack_38 == 0) {
    *(undefined4 *)(this + 0x2d8) = 5000;
  }
  else {
    *(undefined4 *)(this + 0x2d8) = 3000;
  }
  if ((param_1 != '\0') &&
     (MEvtHandle::KillTimer((ulong)this), this[0x2c7] != (ArProgramInfoFrame)0x0)) {
    MEvtHandle::SetTimer(this,*(undefined4 *)(this + 0x2d8),0,1);
  }
  if (this[0x2c8] == (ArProgramInfoFrame)0x0) {
    HelpWidget::HideHelp(*(HelpWidget **)(this + 0x2cc));
  }
  else {
    HelpWidget::ShowHelp(*(HelpWidget **)(this + 0x2cc));
  }
  if ((((iVar3 == 2) || (iVar3 == 3)) || (iVar3 == 0xb)) || (iVar3 == 5)) {
    lStack_3c = GetRcEngine::RcGetNum(0x30a);
    iVar4 = GetRcEngine::RcGetNum(0x30b);
    _Rect::set((_Rect *)&uStack_b54,lStack_3c,iVar4 + -0x1e,0x5c,0x5c);
    (**(code **)(**(int **)(this + 0x1d0) + 0x24))
              (*(undefined4 *)(this + 0x1d0),uStack_b54,uStack_b50,&uStack_b54);
  }
  else {
    lStack_40 = GetRcEngine::RcGetNum(0x30a);
    lStack_44 = GetRcEngine::RcGetNum(0x30b);
    lStack_48 = GetRcEngine::RcGetNum(0x309);
    lVar12 = GetRcEngine::RcGetNum(0x308);
    _Rect::set((_Rect *)&uStack_b54,lStack_40,lStack_44,lStack_48,lVar12);
    (**(code **)(**(int **)(this + 0x1d0) + 0x24))
              (*(undefined4 *)(this + 0x1d0),uStack_b54,uStack_b50,&uStack_b54);
  }
  if ((iVar3 == 0) || (iVar3 == 1)) {
                    /* try { // try from 007d59ec to 007d5a4f has its CatchHandler @ 007dadc0 */
    iVar4 = (**(code **)(*piVar8 + 0x51c))(piVar8);
    if (iVar4 == 0) {
                    /* try { // try from 007d6684 to 007d67bf has its CatchHandler @ 007dadc0 */
      iVar4 = ArChannelManager::GetChannelCount(0);
      if (iVar4 == 0) {
        *(undefined4 *)(this + 0x2c0) = 0;
        SetChannelIcon(this,0x4ac);
        MWidget::SetText((ushort)*(undefined4 *)(this + 0x1c8));
        MWidget::SetText((ushort)*(undefined4 *)(this + 0x1cc));
        MWidget::Hide();
        HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x10d7);
        HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),6,0x10c6);
        HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
      }
      else {
        iVar4 = ArChannelManager::GetCurrentChannelInfo((ChannelInfo *)auStack_a10,'\x01');
        if (iVar4 == 0) {
                    /* try { // try from 007d9930 to 007dadb3 has its CatchHandler @ 007dadc0 */
          printf("error %s %s %d couldn\'t get tv info on atv/dtv sources!\n",&UNK_00fef388,
                 &UNK_00fef60c,0xe2d);
        }
        else {
          iStack_a0 = ArChannelManager::GetChannelListMode();
          if (iStack_a0 == 8) {
            sprintf(acStack_a50,"%d",(uint)uStack_9b6);
          }
          else if (iStack_a0 < 9) {
            if (iStack_a0 == 7) {
              sprintf(acStack_a50,"%d",(uint)uStack_9b8);
            }
            else {
LAB_007d6900:
              sprintf(acStack_a50,"%d",(uint)auStack_a10[0]);
            }
          }
          else if (iStack_a0 == 9) {
            sprintf(acStack_a50,"%d",(uint)uStack_9b4);
          }
          else {
            if (iStack_a0 != 10) goto LAB_007d6900;
            sprintf(acStack_a50,"%d",(uint)uStack_9b2);
          }
          if (*(int *)(this + 0x2c0) == 3) {
            psStack_a4 = (string *)(*(int *)(this + 0x1ac) + 0x170);
            std::allocator<char>::allocator();
                    /* try { // try from 007d6980 to 007d6987 has its CatchHandler @ 007d6a50 */
            std::string::string(asStack_b7c,acStack_a50,aaStack_b80);
                    /* try { // try from 007d699c to 007d69a3 has its CatchHandler @ 007d6a0c */
            MString::Set(psStack_a4);
                    /* try { // try from 007d69b4 to 007d69bb has its CatchHandler @ 007d6a50 */
            std::string::~string(asStack_b7c);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_b80);
                    /* try { // try from 007d69f8 to 007d69ff has its CatchHandler @ 007dadc0 */
            MString::Set((string *)(*(int *)(this + 0x1b4) + 0x170));
          }
          else {
            psStack_a8 = (string *)(*(int *)(this + 0x1c8) + 0x170);
            std::allocator<char>::allocator();
                    /* try { // try from 007d6acc to 007d6ad3 has its CatchHandler @ 007d6b9c */
            std::string::string(asStack_b84,acStack_a50,aaStack_b88);
                    /* try { // try from 007d6ae8 to 007d6aef has its CatchHandler @ 007d6b58 */
            MString::Set(psStack_a8);
                    /* try { // try from 007d6b00 to 007d6b07 has its CatchHandler @ 007d6b9c */
            std::string::~string(asStack_b84);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_b88);
                    /* try { // try from 007d6b44 to 007d6b4b has its CatchHandler @ 007dadc0 */
            MString::Set((string *)(*(int *)(this + 0x1cc) + 0x170));
          }
          if (*(int *)(this + 0x2c0) == 3) {
                    /* try { // try from 007d6bfc to 007d6c77 has its CatchHandler @ 007dadc0 */
            MWidget::Invalidate();
            MWidget::Invalidate();
          }
          else {
            MWidget::Invalidate();
            MWidget::Invalidate();
          }
          std::string::string(asStack_a80);
                    /* try { // try from 007d6c80 to 007d6f3f has its CatchHandler @ 007d98d4 */
          pAVar5 = (ArVideoManager *)ArVideoManager::getInstance();
          cVar1 = ArVideoManager::UpdateResolutionInfo(pAVar5,asStack_a80);
          if ((cVar1 == '\0') || (iVar4 = std::string::size(), iVar4 == 0)) {
            iStack_ac = 0;
          }
          else {
            iStack_ac = 1;
          }
          if (iStack_ac == 0) {
            MWidget::Hide();
            MWidget::Hide();
          }
          else {
            pcStack_b0 = *(char **)(this + 0x1e4);
            std::string::c_str();
            MWidget::SetText(pcStack_b0);
            MWidget::Show();
            MWidget::Show();
          }
          (**(code **)(**(int **)(this + 0x1d4) + 0x48))(*(undefined4 *)(this + 0x1d4));
          MWidget::Invalidate();
          MWidget::Hide();
          MWidget::Hide();
          MWidget::Hide();
          MWidget::Hide();
          this[0x2c6] = (ArProgramInfoFrame)0x0;
          if (this[0x2c5] == (ArProgramInfoFrame)0x0) {
            pEStack_c14 = (EventInfo *)&uStack_9e8;
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Show();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Show();
            MWidget::Show();
            MWidget::Hide();
            MWidget::Hide();
          }
          else {
            pEStack_c14 = aEStack_a00;
            if ((cStack_9f5 == '\0') || (cStack_9dd == '\0')) {
              if (cStack_9dd != '\0') {
                this[0x2c6] = (ArProgramInfoFrame)0x1;
              }
            }
            else {
              this[0x2c6] = (ArProgramInfoFrame)0x1;
              MWidget::Show();
              MWidget::Show();
              MString::Set((string *)(*(int *)(this + 0x218) + 0x170));
              psStack_b4 = (string *)(*(int *)(this + 0x214) + 0x170);
              ArUIManager::ConvertTimeToHour(aAStack_b94,uStack_9e8);
                    /* try { // try from 007d6f60 to 007d6f67 has its CatchHandler @ 007d7124 */
              std::operator+(asStack_b90,(char *)aAStack_b94);
                    /* try { // try from 007d6f88 to 007d6f8f has its CatchHandler @ 007d70c4 */
              ArUIManager::ConvertTimeToHour(aAStack_b98,uStack_9e8 + iStack_9e4);
                    /* try { // try from 007d6fac to 007d6fb3 has its CatchHandler @ 007d7068 */
              std::operator+(asStack_b8c,asStack_b90);
                    /* try { // try from 007d6fc8 to 007d6fcf has its CatchHandler @ 007d700c */
              MString::Set(psStack_b4);
                    /* try { // try from 007d6fe0 to 007d6fe7 has its CatchHandler @ 007d7068 */
              std::string::~string(asStack_b8c);
                    /* try { // try from 007d6ff8 to 007d6fff has its CatchHandler @ 007d70c4 */
              std::string::~string((string *)aAStack_b98);
                    /* try { // try from 007d7054 to 007d705b has its CatchHandler @ 007d7124 */
              std::string::~string(asStack_b90);
                    /* try { // try from 007d70b0 to 007d70b7 has its CatchHandler @ 007d98d4 */
              std::string::~string((string *)aAStack_b94);
                    /* try { // try from 007d7110 to 007d7117 has its CatchHandler @ 007d98d4 */
              MWidget::Show();
                    /* try { // try from 007d7170 to 007d74c7 has its CatchHandler @ 007d98d4 */
              MWidget::Show();
              MWidget::Show();
              MWidget::Show();
              MWidget::Show();
              MWidget::Hide();
              MWidget::Hide();
              MWidget::Hide();
            }
          }
          if (this[0x2c6] == (ArProgramInfoFrame)0x0) {
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
          }
          else {
            MWidget::Show();
            MWidget::Show();
            MWidget::Show();
          }
          if (pEStack_c14[0xb] == (EventInfo)0x0) {
            if (*(int *)(this + 0x2c0) == 3) {
                    /* try { // try from 007d829c to 007d8367 has its CatchHandler @ 007d98d4 */
              MWidget::SetText(*(char **)(this + 0x1b8));
              MString::Set((short)*(undefined4 *)(this + 0x1bc) + 0x170);
            }
            else {
              MWidget::SetText(*(char **)(this + 0x23c));
              MString::Set((short)*(undefined4 *)(this + 0x240) + 0x170);
            }
            MWidget::Hide();
            MWidget::Hide();
            MString::MString(aMStack_a5c);
            std::allocator<char>::allocator();
                    /* try { // try from 007d83a0 to 007d83a7 has its CatchHandler @ 007d84c4 */
            std::string::string(asStack_be0,"",aaStack_be4);
                    /* try { // try from 007d83c0 to 007d83c7 has its CatchHandler @ 007d842c */
            MString::Set((string *)aMStack_a5c);
            psStack_e8 = asStack_be0;
                    /* try { // try from 007d83dc to 007d83e3 has its CatchHandler @ 007d84c4 */
            std::string::~string(psStack_e8);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_be4);
                    /* try { // try from 007d8418 to 007d841f has its CatchHandler @ 007d8660 */
            ScrollTextBox::SetText(*(MString **)(this + 700));
            psStack_ec = (string *)(*(int *)(this + 0x244) + 0x170);
            std::allocator<char>::allocator();
                    /* try { // try from 007d84b0 to 007d84b7 has its CatchHandler @ 007d85e8 */
            std::string::string(asStack_be8,"",aaStack_bec);
                    /* try { // try from 007d8510 to 007d8517 has its CatchHandler @ 007d857c */
            MString::Set(psStack_ec);
            psStack_f0 = asStack_be8;
                    /* try { // try from 007d852c to 007d8533 has its CatchHandler @ 007d85e8 */
            std::string::~string(psStack_f0);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_bec);
                    /* try { // try from 007d8568 to 007d856f has its CatchHandler @ 007d8660 */
            MString::Set((short)*(undefined4 *)(this + 0x26c) + 0x170);
                    /* try { // try from 007d85d4 to 007d863b has its CatchHandler @ 007d8660 */
            MString::Set((short)*(undefined4 *)(this + 0x260) + 0x170);
            MWidget::Hide();
                    /* try { // try from 007d864c to 007d8653 has its CatchHandler @ 007d98d4 */
            MString::~MString(aMStack_a5c);
          }
          else {
            if (*(int *)(this + 0x2c0) == 3) {
              MString::Set((string *)(*(int *)(this + 0x1b8) + 0x170));
            }
            else {
              MString::Set((string *)(*(int *)(this + 0x23c) + 0x170));
            }
            MString::MString(aMStack_a6c);
                    /* try { // try from 007d74e4 to 007d750f has its CatchHandler @ 007d8234 */
            MString::Set((string *)aMStack_a6c);
            ScrollTextBox::SetText(*(MString **)(this + 700));
            psStack_b8 = (string *)(*(int *)(this + 0x244) + 0x170);
            std::allocator<char>::allocator();
                    /* try { // try from 007d7558 to 007d755f has its CatchHandler @ 007d7658 */
            std::string::string(asStack_b9c,"",aaStack_ba0);
                    /* try { // try from 007d7574 to 007d757b has its CatchHandler @ 007d75f4 */
            MString::Set(psStack_b8);
            psStack_bc = asStack_b9c;
                    /* try { // try from 007d7590 to 007d7597 has its CatchHandler @ 007d7658 */
            std::string::~string(psStack_bc);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_ba0);
            psStack_c0 = (string *)(*(int *)(this + 0x26c) + 0x170);
                    /* try { // try from 007d75e0 to 007d75e7 has its CatchHandler @ 007d8234 */
            ArUIManager::ConvertParentalRating(aAStack_ba4,(uint)(byte)pEStack_c14[8]);
                    /* try { // try from 007d7644 to 007d764b has its CatchHandler @ 007d76c8 */
            MString::Set(psStack_c0);
                    /* try { // try from 007d76a0 to 007d76a7 has its CatchHandler @ 007d8234 */
            std::string::~string((string *)aAStack_ba4);
            if (*(int *)(this + 0x2c0) == 3) {
              psStack_c4 = (string *)(*(int *)(this + 0x1bc) + 0x170);
                    /* try { // try from 007d772c to 007d7733 has its CatchHandler @ 007d8234 */
              ArUIManager::ConvertTimeToHour(aAStack_bb0,*(ulong *)pEStack_c14);
                    /* try { // try from 007d7754 to 007d775b has its CatchHandler @ 007d7904 */
              std::operator+(asStack_bac,(char *)aAStack_bb0);
                    /* try { // try from 007d7784 to 007d778b has its CatchHandler @ 007d78c0 */
              ArUIManager::ConvertTimeToHour
                        (aAStack_bb4,*(int *)pEStack_c14 + *(int *)(pEStack_c14 + 4));
                    /* try { // try from 007d77a8 to 007d77af has its CatchHandler @ 007d7864 */
              std::operator+(asStack_ba8,asStack_bac);
                    /* try { // try from 007d77c4 to 007d77cb has its CatchHandler @ 007d7808 */
              MString::Set(psStack_c4);
                    /* try { // try from 007d77dc to 007d77e3 has its CatchHandler @ 007d7864 */
              std::string::~string(asStack_ba8);
                    /* try { // try from 007d77f4 to 007d77fb has its CatchHandler @ 007d78c0 */
              std::string::~string((string *)aAStack_bb4);
                    /* try { // try from 007d7850 to 007d7857 has its CatchHandler @ 007d7904 */
              std::string::~string(asStack_bac);
                    /* try { // try from 007d78ac to 007d78b3 has its CatchHandler @ 007d8234 */
              std::string::~string((string *)aAStack_bb0);
            }
            else {
              psStack_c8 = (string *)(*(int *)(this + 0x240) + 0x170);
                    /* try { // try from 007d7968 to 007d796f has its CatchHandler @ 007d8234 */
              ArUIManager::ConvertTimeToHour(aAStack_bc0,*(ulong *)pEStack_c14);
                    /* try { // try from 007d7990 to 007d7997 has its CatchHandler @ 007d7b40 */
              std::operator+(asStack_bbc,(char *)aAStack_bc0);
                    /* try { // try from 007d79c0 to 007d79c7 has its CatchHandler @ 007d7afc */
              ArUIManager::ConvertTimeToHour
                        (aAStack_bc4,*(int *)pEStack_c14 + *(int *)(pEStack_c14 + 4));
                    /* try { // try from 007d79e4 to 007d79eb has its CatchHandler @ 007d7aa0 */
              std::operator+(asStack_bb8,asStack_bbc);
                    /* try { // try from 007d7a00 to 007d7a07 has its CatchHandler @ 007d7a44 */
              MString::Set(psStack_c8);
                    /* try { // try from 007d7a18 to 007d7a1f has its CatchHandler @ 007d7aa0 */
              std::string::~string(asStack_bb8);
                    /* try { // try from 007d7a30 to 007d7a37 has its CatchHandler @ 007d7afc */
              std::string::~string((string *)aAStack_bc4);
                    /* try { // try from 007d7a8c to 007d7a93 has its CatchHandler @ 007d7b40 */
              std::string::~string(asStack_bbc);
                    /* try { // try from 007d7ae8 to 007d7aef has its CatchHandler @ 007d8234 */
              std::string::~string((string *)aAStack_bc0);
            }
                    /* try { // try from 007d7b80 to 007d7c13 has its CatchHandler @ 007d8234 */
            this_00 = (ArTvSettingsManager *)ArTvSettingsManager::getInstance();
            ArTvSettingsManager::GetCurrentTimeInSecond(this_00);
            dStack_d0 = (double)(*(int *)pEStack_c14 + *(int *)(pEStack_c14 + 4));
            if (*(int *)pEStack_c14 + *(int *)(pEStack_c14 + 4) < 0) {
              dStack_d0 = dStack_d0 + 4294967296.0;
            }
            dVar13 = (dStack_d0 - in_f0_1) / 60.0;
            std::ostringstream::ostringstream(aoStack_9ac,0x10);
            uStack_18 = 0x41e0000000000000;
            if (dVar13 < 2147483648.0) {
              uStack_d8 = (ulong)dVar13;
            }
            else {
              uStack_d8 = (int)(dVar13 - 2147483648.0) | 0x80000000;
            }
            dStack_20 = dVar13;
                    /* try { // try from 007d7c88 to 007d7cc3 has its CatchHandler @ 007d81f0 */
            std::ostream::operator<<((ostream *)aoStack_9ac,uStack_d8);
            psStack_dc = (string *)(*(int *)(this + 0x25c) + 0x170);
            ArUIManager::getInstance();
            pcVar6 = (char *)GetRcEngine::RcGetString(0x1152);
            std::allocator<char>::allocator();
                    /* try { // try from 007d7cfc to 007d7d03 has its CatchHandler @ 007d7fa0 */
            std::string::string(asStack_bcc,pcVar6,aaStack_bd0);
            std::allocator<char>::allocator();
                    /* try { // try from 007d7d3c to 007d7d43 has its CatchHandler @ 007d7f24 */
            std::string::string(asStack_bd4,"[x]",aaStack_bd8);
                    /* try { // try from 007d7d5c to 007d7d63 has its CatchHandler @ 007d7eb4 */
            std::ostringstream::str();
                    /* try { // try from 007d7d84 to 007d7d8b has its CatchHandler @ 007d7e40 */
            ArUIManager::ReplaceString(aAStack_bc8,asStack_bcc,asStack_bd4,asStack_bdc);
                    /* try { // try from 007d7da0 to 007d7da7 has its CatchHandler @ 007d7de4 */
            MString::Set(psStack_dc);
                    /* try { // try from 007d7db8 to 007d7dbf has its CatchHandler @ 007d7e40 */
            std::string::~string((string *)aAStack_bc8);
                    /* try { // try from 007d7dd0 to 007d7dd7 has its CatchHandler @ 007d7eb4 */
            std::string::~string(asStack_bdc);
                    /* try { // try from 007d7e2c to 007d7e33 has its CatchHandler @ 007d7f24 */
            std::string::~string(asStack_bd4);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_bd8);
                    /* try { // try from 007d7ea0 to 007d7ea7 has its CatchHandler @ 007d7fa0 */
            std::string::~string(asStack_bcc);
            std::allocator<char>::~allocator((allocator<char> *)aaStack_bd0);
                    /* try { // try from 007d7f10 to 007d7f17 has its CatchHandler @ 007d81f0 */
            iStack_e4 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_e4 == 0) {
              iStack_e0 = 0;
            }
            else {
              iStack_e0 = __dynamic_cast(iStack_e4,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            if (iStack_e0 == 0) {
                    /* try { // try from 007d8040 to 007d806b has its CatchHandler @ 007d81f0 */
              printf("ASSERT FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef5e0,0xcf4);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            std::string::string(asStack_a60);
                    /* try { // try from 007d8074 to 007d8157 has its CatchHandler @ 007d8194 */
            this_01 = (ArEpgManager *)ArEpgManager::getInstance();
            ArEpgManager::GetGenreTextFromEvent(this_01,pEStack_c14,asStack_a60);
            MString::Set((string *)(*(int *)(this + 0x260) + 0x170));
            iVar4 = std::string::empty();
            if (iVar4 == 0) {
              MWidget::Show();
            }
            else {
              puts("Hiding Genre");
              MWidget::Hide();
            }
            MWidget::Invalidate();
                    /* try { // try from 007d8168 to 007d816f has its CatchHandler @ 007d81f0 */
            std::string::~string(asStack_a60);
                    /* try { // try from 007d8180 to 007d8187 has its CatchHandler @ 007d8234 */
            std::ostringstream::~ostringstream(aoStack_9ac);
                    /* try { // try from 007d81dc to 007d81e3 has its CatchHandler @ 007d98d4 */
            MString::~MString(aMStack_a6c);
          }
                    /* try { // try from 007d86b8 to 007d98af has its CatchHandler @ 007d98d4 */
          MString::Set((short)*(undefined4 *)(this + 0x224) + 0x170);
          MString::Set((short)*(undefined4 *)(this + 0x220) + 0x170);
          MWidget::SetText(*(char **)(this + 0x204));
          if (cStack_9c4 == '\0') {
            MWidget::SetFlag(*(undefined4 *)(this + 0x204),2,0);
            MWidget::Invalidate();
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x204),2,1);
            MWidget::Invalidate();
          }
          MWidget::SetText(*(char **)(this + 0x200));
          if (cStack_9d0 == '\0') {
            MWidget::SetFlag(*(undefined4 *)(this + 0x200),2,0);
            MWidget::Invalidate();
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x200),2,1);
            MWidget::Invalidate();
          }
          MWidget::SetText(*(char **)(this + 500));
          ArAudioManager::getInstance();
          iVar4 = ArAudioManager::GetDualMono();
          if (iVar4 == 0) {
            MWidget::SetFlag(*(undefined4 *)(this + 500),2,0);
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 500),2,1);
          }
          MWidget::SetText(*(char **)(this + 0x1fc));
          ArAudioManager::getInstance();
          iVar4 = ArAudioManager::GetMono();
          if (iVar4 == 0) {
            MWidget::SetFlag(*(undefined4 *)(this + 0x1fc),2,0);
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x1fc),2,1);
          }
          MWidget::SetText(*(char **)(this + 0x1f8));
          ArAudioManager::getInstance();
          iVar4 = ArAudioManager::GetStereo();
          if (iVar4 == 0) {
            MWidget::SetFlag(*(undefined4 *)(this + 0x1f8),2,0);
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x1f8),2,1);
          }
          pcStack_f4 = *(char **)(this + 0x1f0);
          std::string::c_str();
          MWidget::SetText(pcStack_f4);
          pcStack_f8 = *(char **)(this + 0x1ec);
          std::string::c_str();
          MWidget::SetText(pcStack_f8);
          if (iStack_9bc == 1) {
            MWidget::SetText(*(char **)(this + 0x1e8));
          }
          else if (iStack_9bc == 2) {
            MWidget::SetText(*(char **)(this + 0x1e8));
          }
          else {
            MWidget::SetText(*(char **)(this + 0x1e8));
          }
          if (this[0x2c5] == (ArProgramInfoFrame)0x0) {
            if (pEStack_c14[0xb] == (EventInfo)0x0) {
              MWidget::SetFlag(*(undefined4 *)(this + 0x264),2,0);
              MWidget::Invalidate();
            }
            else {
              MWidget::SetFlag(*(undefined4 *)(this + 0x264),2,pEStack_c14[0x14]);
              MWidget::Invalidate();
            }
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x264),2,uStack_a04);
            MWidget::Invalidate();
          }
          if (*(int *)(this + 0x2c0) == 3) {
            HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x11ee);
            ArServiceSettingsManager::getInstance();
            iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
            if (iVar4 == 0) {
LAB_007d8d14:
              uStack_fc = 0;
            }
            else {
              ArTvSettingsManager::getInstance();
              iVar4 = ArTvSettingsManager::GetHotelAdmin();
              if (iVar4 != 0) goto LAB_007d8d14;
              uStack_fc = 1;
            }
            cVar1 = (char)uStack_fc;
            if (((iVar3 == 0) || (iVar3 == 1)) &&
               ((iVar4 = ArChannelManager::GetChannelCount(0), 0 < iVar4 && (cVar1 == '\0')))) {
              iStack_100 = 1;
            }
            else {
              iStack_100 = 0;
            }
            if (iStack_100 != 0) {
              HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),4,0xbfc);
              ArServiceSettingsManager::getInstance();
              iVar4 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
              if (iVar4 == 1) {
                ArTvSettingsManager::getInstance();
                iVar4 = ArTvSettingsManager::GetBasicMode();
                if (iVar4 != 1) goto LAB_007d8e10;
LAB_007d8e3c:
                iStack_104 = 1;
              }
              else {
LAB_007d8e10:
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
                if (iVar4 != 0) goto LAB_007d8e3c;
                iStack_104 = 0;
              }
              if (iStack_104 != 0) {
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
                if (iVar4 == 0) {
                  HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                }
                else {
                  ArTvSettingsManager::getInstance();
                  iVar4 = ArTvSettingsManager::GetHotelAdmin();
                  if (iVar4 != 0) {
                    HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                  }
                }
              }
            }
            HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
          }
          else if (*(int *)(this + 0x2c0) == 1) {
            if (iVar3 == 1) {
              HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x10d7);
            }
            else {
              HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x11ee);
            }
            if (((iVar3 == 0) || (iVar3 == 1)) &&
               (iVar4 = ArChannelManager::GetChannelCount(0), iVar4 != 0)) {
              HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),4,0xbfc);
              ArServiceSettingsManager::getInstance();
              iVar4 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
              if (iVar4 == 1) {
                ArTvSettingsManager::getInstance();
                iVar4 = ArTvSettingsManager::GetBasicMode();
                if (iVar4 != 1) goto LAB_007d9078;
LAB_007d90a4:
                iStack_108 = 1;
              }
              else {
LAB_007d9078:
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
                if (iVar4 != 0) goto LAB_007d90a4;
                iStack_108 = 0;
              }
              if (iStack_108 != 0) {
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
                if (iVar4 == 0) {
                  HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                }
                else {
                  ArTvSettingsManager::getInstance();
                  iVar4 = ArTvSettingsManager::GetHotelAdmin();
                  if (iVar4 != 0) {
                    HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                  }
                }
              }
            }
            ArServiceSettingsManager::getInstance();
            iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
            if (iVar4 == 0) {
LAB_007d91e4:
              iStack_10c = 0;
            }
            else {
              ArTvSettingsManager::getInstance();
              iVar4 = ArTvSettingsManager::GetHotelAdmin();
              if (iVar4 != 0) goto LAB_007d91e4;
              iStack_10c = 1;
            }
            if (iStack_10c != 0) {
              HelpWidget::HideButton(*(HelpWidget **)(this + 0x2cc),4);
            }
            HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),6,0x10c6);
            HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
          }
          else {
            HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x10d7);
            if (((iVar3 == 0) || (iVar3 == 1)) &&
               (iVar4 = ArChannelManager::GetChannelCount(0), iVar4 != 0)) {
              HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),4,0xbfc);
              ArServiceSettingsManager::getInstance();
              iVar4 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
              if (iVar4 == 1) {
                ArTvSettingsManager::getInstance();
                iVar4 = ArTvSettingsManager::GetBasicMode();
                if (iVar4 != 1) goto LAB_007d934c;
LAB_007d9378:
                iStack_110 = 1;
              }
              else {
LAB_007d934c:
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
                if (iVar4 != 0) goto LAB_007d9378;
                iStack_110 = 0;
              }
              if (iStack_110 != 0) {
                ArServiceSettingsManager::getInstance();
                iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
                if (iVar4 == 0) {
                  HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                }
                else {
                  ArTvSettingsManager::getInstance();
                  iVar4 = ArTvSettingsManager::GetHotelAdmin();
                  if (iVar4 != 0) {
                    HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),1,0x1186);
                  }
                }
              }
            }
            ArServiceSettingsManager::getInstance();
            iVar4 = ArServiceSettingsManager::ArSystemConf_GetHotel();
            if (iVar4 == 0) {
LAB_007d94b8:
              iStack_114 = 0;
            }
            else {
              ArTvSettingsManager::getInstance();
              iVar4 = ArTvSettingsManager::GetHotelAdmin();
              if (iVar4 != 0) goto LAB_007d94b8;
              iStack_114 = 1;
            }
            if (iStack_114 != 0) {
              HelpWidget::HideButton(*(HelpWidget **)(this + 0x2cc),4);
            }
            HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),6,0x10c6);
            HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
          }
          ArTvManager::getInstance();
          uVar10 = ArTvManager::GetCurrentDvbAntennaType();
          pAVar11 = (ArTvPlayer *)ArTvPlayer::getInstance();
          iVar4 = ArTvPlayer::IsOpModeByRoute(pAVar11,uVar10);
          if (iVar4 != 0) {
            HelpWidget::HideButton(*(HelpWidget **)(this + 0x2cc),4);
            HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
          }
          if (iVar3 == 1) {
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
            MWidget::Hide();
          }
          if (*(int *)(this + 0x2c0) == 3) {
            lStack_118 = GetRcEngine::RcGetNum(0x2fa);
            lStack_11c = GetRcEngine::RcGetNum(0x357);
            lStack_120 = GetRcEngine::RcGetNum(0x355);
            lVar12 = GetRcEngine::RcGetNum(0x354);
            _Rect::set((_Rect *)&uStack_a7c,lStack_118,lStack_11c,lStack_120,lVar12);
          }
          else {
            lStack_124 = GetRcEngine::RcGetNum(0x30a);
            lStack_128 = GetRcEngine::RcGetNum(0x3c3);
            lStack_12c = GetRcEngine::RcGetNum(0x3c1);
            lVar12 = GetRcEngine::RcGetNum(0x3c0);
            _Rect::set((_Rect *)&uStack_a7c,lStack_124,lStack_128,lStack_12c,lVar12);
          }
          MWidget::Hide();
          MWidget::Hide();
          if (*(int *)(this + 0x2c0) == 3) {
            (**(code **)(**(int **)(this + 0x1b4) + 0x24))
                      (*(undefined4 *)(this + 0x1b4),uStack_a7c,uStack_a78,&uStack_a7c);
          }
          else {
            (**(code **)(**(int **)(this + 0x1cc) + 0x24))
                      (*(undefined4 *)(this + 0x1cc),uStack_a7c,uStack_a78,&uStack_a7c);
          }
                    /* try { // try from 007d98c0 to 007d98c7 has its CatchHandler @ 007dadc0 */
          std::string::~string(asStack_a80);
        }
      }
    }
    else {
      if (*(int *)(this + 0x2c0) == 3) {
        *(undefined4 *)(this + 0x2c0) = 1;
      }
      MSrv_Control_TV::GetMSrvPVRBrowser();
      MW_PVRFileSystem::GetLastPlaybackFile();
                    /* try { // try from 007d5a58 to 007d5bd7 has its CatchHandler @ 007d6640 */
      psVar7 = (string *)MSrv_Control_TV::GetMSrvPVRBrowser();
      MW_PVRFileSystem::GetMetaData(psVar7,aPStack_ac0);
      MWidget::Hide();
      MWidget::Hide();
      MWidget::Hide();
      MWidget::Hide();
      acStack_abc[0] = '\0';
      acStack_abc[1] = '\0';
      acStack_abc[2] = '\0';
      acStack_abc[3] = '\0';
      acStack_abc[4] = '\0';
      acStack_abc[5] = '\0';
      acStack_abc[6] = '\0';
      acStack_abc[7] = '\0';
      acStack_abc[8] = '\0';
      acStack_abc[9] = '\0';
      acStack_abc[10] = '\0';
      acStack_abc[0xb] = '\0';
      acStack_abc[0xc] = '\0';
      acStack_abc[0xd] = '\0';
      acStack_abc[0xe] = '\0';
      acStack_abc[0xf] = '\0';
      if (cStack_66e == '\0') {
        MWidget::SetText((ushort)*(undefined4 *)(this + 0x23c));
      }
      else {
        MWidget::SetText(*(char **)(this + 0x23c));
      }
      if (cStack_6ee == '\0') {
        MWidget::SetText((ushort)*(undefined4 *)(this + 0x1cc));
      }
      else {
        MWidget::SetText(*(char **)(this + 0x1cc));
      }
      MString::MString(aMStack_aac);
      if (acStack_5ee[0] == '\0') {
                    /* try { // try from 007d5c08 to 007d5c4f has its CatchHandler @ 007d65fc */
        printf("\nTODO: %s %s %d Need to get event description !!\n",&UNK_00fef388,&UNK_00fef60c,
               0xbc2);
        MString::Set((ushort)aMStack_aac);
        ScrollTextBox::SetText(*(MString **)(this + 700));
      }
      else {
        std::allocator<char>::allocator();
                    /* try { // try from 007d5c94 to 007d5c9b has its CatchHandler @ 007d5d68 */
        std::string::string(asStack_b70,acStack_5ee,aaStack_b74);
                    /* try { // try from 007d5cb4 to 007d5cbb has its CatchHandler @ 007d5d20 */
        MString::Set((string *)aMStack_aac);
        psStack_68 = asStack_b70;
                    /* try { // try from 007d5cd0 to 007d5cd7 has its CatchHandler @ 007d5d68 */
        std::string::~string(psStack_68);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_b74);
                    /* try { // try from 007d5d0c to 007d5d13 has its CatchHandler @ 007d65fc */
        ScrollTextBox::SetText(*(MString **)(this + 700));
      }
      sprintf(acStack_abc,"%d",(uint)uStack_770);
                    /* try { // try from 007d5de8 to 007d5e23 has its CatchHandler @ 007d65fc */
      MWidget::SetText(*(char **)(this + 0x1c8));
      psStack_6c = (string *)(*(int *)(this + 0x26c) + 0x170);
      ArUIManager::ConvertParentalRating(aAStack_b78,(uint)bStack_20f);
                    /* try { // try from 007d5e38 to 007d5e3f has its CatchHandler @ 007d5e80 */
      MString::Set(psStack_6c);
                    /* try { // try from 007d5e50 to 007d5e73 has its CatchHandler @ 007d65fc */
      std::string::~string((string *)aAStack_b78);
      FUN_007d3830(aoStack_9ac);
                    /* try { // try from 007d5ec4 to 007d655b has its CatchHandler @ 007d659c */
      piVar8 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
      (**(code **)(*piVar8 + 0x1f0))(piVar8,aoStack_9ac);
      iStack_74 = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_74 == 0) {
        piStack_70 = (int *)0x0;
      }
      else {
        piStack_70 = (int *)__dynamic_cast(iStack_74,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      uVar9 = (**(code **)(*piStack_70 + 0x59c))(piStack_70,auStack_998);
      iStack_78 = *(int *)(this + 0x220) + 0x170;
      ArResourceManager::GetLanguageStringID(uVar9);
      MString::Set((ushort)iStack_78);
      iStack_80 = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_80 == 0) {
        piStack_7c = (int *)0x0;
      }
      else {
        piStack_7c = (int *)__dynamic_cast(iStack_80,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      iVar3 = (**(code **)(*piStack_7c + 0x39c))(piStack_7c,auStack_8f8);
      if (iVar3 == 0) {
        bStack_c08 = 0;
      }
      else {
        bStack_c08 = bStack_777;
      }
      if (bStack_c08 == 0) {
        MString::Set((short)*(undefined4 *)(this + 0x224) + 0x170);
      }
      else if ((cStack_776 == '\0') || (bStack_c08 <= bStack_778)) {
        MString::Set((short)*(undefined4 *)(this + 0x224) + 0x170);
      }
      else {
        iStack_84 = *(int *)(this + 0x224) + 0x170;
        ArResourceManager::GetLanguageStringID(auStack_8f8[(uint)bStack_778 * 4]);
        MString::Set((ushort)iStack_84);
      }
      MWidget::SetText(*(char **)(this + 0x260));
      MWidget::SetText(*(char **)(this + 0x240));
      MWidget::SetFlag(*(undefined4 *)(this + 0x260),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x240),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x25c),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 600),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x250),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x230),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x264),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1e4),2,0);
      lStack_88 = GetRcEngine::RcGetNum(0x3d6);
      lStack_8c = GetRcEngine::RcGetNum(0x3d3);
      lStack_90 = GetRcEngine::RcGetNum(0x3d1);
      lVar12 = GetRcEngine::RcGetNum(0x3d0);
      _Rect::set((_Rect *)&uStack_aa0,lStack_88,lStack_8c,lStack_90,lVar12);
      (**(code **)(**(int **)(this + 0x23c) + 0x24))
                (*(undefined4 *)(this + 0x23c),uStack_aa0,uStack_a9c,&uStack_aa0);
      MWidget::Hide();
      lStack_94 = GetRcEngine::RcGetNum(0x30a);
      lStack_98 = GetRcEngine::RcGetNum(0x3c3);
      lStack_9c = GetRcEngine::RcGetNum(0x3c1);
      lVar12 = GetRcEngine::RcGetNum(0x3c0);
      _Rect::set((_Rect *)&uStack_a90,lStack_94,lStack_98,lStack_9c,lVar12);
      (**(code **)(**(int **)(this + 0x1cc) + 0x24))
                (*(undefined4 *)(this + 0x1cc),uStack_a90,uStack_a8c,&uStack_a90);
      MWidget::SetFlag(*(undefined4 *)(this + 0x204),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x200),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1e8),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1ec),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1f0),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 500),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1fc),2,0);
      MWidget::SetFlag(*(undefined4 *)(this + 0x1f8),2,0);
                    /* try { // try from 007d6570 to 007d6577 has its CatchHandler @ 007d65fc */
      FUN_007d372c(aoStack_9ac);
                    /* try { // try from 007d6588 to 007d658f has its CatchHandler @ 007d6640 */
      MString::~MString(aMStack_aac);
                    /* try { // try from 007d65e8 to 007d65ef has its CatchHandler @ 007dadc0 */
      std::string::~string((string *)aPStack_ac0);
    }
  }
  else {
    std::string::string(asStack_ac4);
                    /* try { // try from 007d5128 to 007d545f has its CatchHandler @ 007d599c */
    pAVar5 = (ArVideoManager *)ArVideoManager::getInstance();
    cVar1 = ArVideoManager::UpdateResolutionInfo(pAVar5,asStack_ac4);
    if (cVar1 == '\0') {
      MWidget::Hide();
      MWidget::Hide();
    }
    else {
      pcStack_4c = *(char **)(this + 0x1e4);
      std::string::c_str();
      MWidget::SetText(pcStack_4c);
      MWidget::Show();
      MWidget::Show();
    }
    (**(code **)(**(int **)(this + 0x1d4) + 0x48))(*(undefined4 *)(this + 0x1d4));
    MWidget::Invalidate();
    *(undefined4 *)(this + 0x2c0) = 0;
    cStack_c00 = '\0';
    MWidget::SetText((ushort)*(undefined4 *)(this + 0x1c8));
    switch(iVar3) {
    default:
      printf("error %s %s %d invalid source!\n",&UNK_00fef388,&UNK_00fef60c,0xb81);
      break;
    case 2:
      cStack_c00 = '\b';
      SetChannelIcon(this,0x259);
      break;
    case 3:
      cStack_c00 = '\v';
      SetChannelIcon(this,0x259);
      break;
    case 4:
      cStack_c00 = '\t';
      SetChannelIcon(this,0x28c);
      break;
    case 5:
      cStack_c00 = '\x02';
      SetChannelIcon(this,0x253);
      break;
    case 10:
      cStack_c00 = '\n';
      SetChannelIcon(this,0x262);
      break;
    case 0xb:
      cStack_c00 = '\a';
      SetChannelIcon(this,0x259);
    }
    if (cStack_c00 == '\x02') {
      psStack_50 = (string *)(*(int *)(this + 0x1cc) + 0x170);
      uStack_54 = ArTvManager::getInstance();
      uStack_58 = 2;
      pAVar2 = (ArTvManager *)ArTvManager::getInstance();
      ArTvManager::GetSpecificSourceIndex(pAVar2);
      ArTvManager::GetSourceName((ulong)asStack_b5c);
                    /* try { // try from 007d5470 to 007d5477 has its CatchHandler @ 007d55b0 */
      pcVar6 = (char *)std::string::c_str();
      std::allocator<char>::allocator();
                    /* try { // try from 007d54b0 to 007d54b7 has its CatchHandler @ 007d5574 */
      std::string::string(asStack_b58,pcVar6,aaStack_b60);
                    /* try { // try from 007d54cc to 007d54d3 has its CatchHandler @ 007d552c */
      MString::Set(psStack_50);
      psStack_5c = asStack_b58;
                    /* try { // try from 007d54e8 to 007d54ef has its CatchHandler @ 007d5574 */
      std::string::~string(psStack_5c);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_b60);
                    /* try { // try from 007d5518 to 007d551f has its CatchHandler @ 007d599c */
      std::string::~string(asStack_b5c);
    }
    else {
      psStack_60 = (string *)(*(int *)(this + 0x1cc) + 0x170);
                    /* try { // try from 007d5600 to 007d562b has its CatchHandler @ 007d599c */
      ArTvManager::getInstance();
      ArTvManager::GetSourceName((ulong)asStack_b68);
                    /* try { // try from 007d563c to 007d5643 has its CatchHandler @ 007d577c */
      pcVar6 = (char *)std::string::c_str();
      std::allocator<char>::allocator();
                    /* try { // try from 007d567c to 007d5683 has its CatchHandler @ 007d5740 */
      std::string::string(asStack_b64,pcVar6,aaStack_b6c);
                    /* try { // try from 007d5698 to 007d569f has its CatchHandler @ 007d56f8 */
      MString::Set(psStack_60);
      psStack_64 = asStack_b64;
                    /* try { // try from 007d56b4 to 007d56bb has its CatchHandler @ 007d5740 */
      std::string::~string(psStack_64);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_b6c);
                    /* try { // try from 007d56e4 to 007d56eb has its CatchHandler @ 007d599c */
      std::string::~string(asStack_b68);
    }
                    /* try { // try from 007d57c8 to 007d5977 has its CatchHandler @ 007d599c */
    MWidget::Invalidate();
    MWidget::SetFlag(*(undefined4 *)(this + 0x264),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x1e8),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x1ec),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x1f0),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 500),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x1fc),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x1f8),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x204),2,0);
    MWidget::SetFlag(*(undefined4 *)(this + 0x200),2,0);
    HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),8,0x10d7);
    HelpWidget::ShowButton(*(HelpWidget **)(this + 0x2cc),6,0x10c6);
    HelpWidget::Refresh(*(HelpWidget **)(this + 0x2cc));
                    /* try { // try from 007d5988 to 007d598f has its CatchHandler @ 007dadc0 */
    std::string::~string(asStack_ac4);
  }
  pAVar2 = (ArTvManager *)ArTvManager::getInstance();
  cVar1 = ArTvManager::GetCurrentInputSourceType(pAVar2);
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    ArTvManager::getInstance();
    cVar1 = ArTvManager::GetCurrentDvbAntennaType();
    if (cVar1 == '\x01') {
      if (*(int *)(this + 0x2c0) == 3) {
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x29c);
      }
      else {
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x29c);
      }
    }
    else if (cVar1 == '\x02') {
      if (*(int *)(this + 0x2c0) == 3) {
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x29c);
      }
      else {
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x29c);
      }
    }
    else if (cVar1 == '\x03') {
      if (*(int *)(this + 0x2c0) == 3) {
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1a8) + 0x29c);
      }
      else {
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1c4) + 0x29c);
      }
    }
    if (*(int *)(this + 0x2c0) == 3) {
      MWidget::Show();
      MWidget::Invalidate();
    }
    else {
      MWidget::Show();
      MWidget::Invalidate();
    }
  }
  else {
    MWidget::Hide();
    MWidget::Hide();
  }
  ProgressBar::SetCurValue(*(long *)(this + 0x254));
  MWidget::Invalidate();
  iVar3 = ShowRecordingInfo(this);
  if (iVar3 == 0) {
    MWidget::Hide();
  }
  else {
    MWidget::Show();
  }
  iStack_130 = *(int *)(this + 0x2c0);
  if (iStack_130 == 1) {
    MWidget::Hide();
    MWidget::Show();
    MWidget::HideBorder();
    MWidget::Invalidate();
    MWidget::Show();
    MWidget::Show();
    lStack_140 = GetRcEngine::RcGetNum(0x31e);
    lStack_144 = GetRcEngine::RcGetNum(799);
    lVar12 = GetRcEngine::RcGetNum(0x31d);
    _Rect::set((_Rect *)&uStack_b44,lStack_140,lStack_144,lVar12,0x50);
    (**(code **)(**(int **)(this + 0x18c) + 0x24))
              (*(undefined4 *)(this + 0x18c),uStack_b44,iStack_b40,&uStack_b44);
    MWidget::Invalidate();
    lStack_148 = GetRcEngine::RcGetNum(0x2e6);
    iStack_14c = iStack_b40 + 0x50;
    lStack_150 = GetRcEngine::RcGetNum(0x2e5);
    lVar12 = GetRcEngine::RcGetNum(0x2e4);
    _Rect::set((_Rect *)&uStack_b44,lStack_148,iStack_14c,lStack_150,lVar12);
    (**(code **)(**(int **)(this + 400) + 0x24))
              (*(undefined4 *)(this + 400),uStack_b44,iStack_b40,&uStack_b44);
    MWidget::Invalidate();
    MWidget::Hide();
  }
  else if (iStack_130 == 0) {
    MWidget::Hide();
    MWidget::Show();
    MWidget::Invalidate();
    MWidget::Hide();
    MWidget::Hide();
    lStack_134 = GetRcEngine::RcGetNum(0x352);
    iStack_138 = GetRcEngine::RcGetNum(0x353);
    lStack_13c = GetRcEngine::RcGetNum(0x350);
    lStack_13c = iStack_138 + lStack_13c;
    lVar12 = GetRcEngine::RcGetNum(0x351);
    _Rect::set((_Rect *)&uStack_b44,lStack_134,lStack_13c,lVar12,0x3c);
    (**(code **)(**(int **)(this + 0x194) + 0x24))
              (*(undefined4 *)(this + 0x194),uStack_b44,iStack_b40,&uStack_b44);
    MWidget::Invalidate();
  }
  else if (iStack_130 == 2) {
    MWidget::Hide();
    MWidget::Show();
    MWidget::HideBorder();
    MWidget::Invalidate();
    MWidget::Show();
    lStack_154 = GetRcEngine::RcGetNum(0x31e);
    lStack_158 = GetRcEngine::RcGetNum(799);
    lStack_15c = GetRcEngine::RcGetNum(0x31d);
    lVar12 = GetRcEngine::RcGetNum(0x31c);
    _Rect::set((_Rect *)&uStack_b44,lStack_154,lStack_158,lStack_15c,lVar12);
    (**(code **)(**(int **)(this + 0x18c) + 0x24))
              (*(undefined4 *)(this + 0x18c),uStack_b44,iStack_b40,&uStack_b44);
    lStack_160 = GetRcEngine::RcGetNum(0x352);
    iStack_164 = GetRcEngine::RcGetNum(799);
    lStack_168 = GetRcEngine::RcGetNum(0x31c);
    lStack_168 = iStack_164 + lStack_168;
    lVar12 = GetRcEngine::RcGetNum(0x351);
    _Rect::set((_Rect *)&uStack_b44,lStack_160,lStack_168,lVar12,0x3c);
    MWidget::Hide();
  }
  else if (iStack_130 == 3) {
    MWidget::Show();
    MWidget::Hide();
    MWidget::Hide();
    MWidget::Hide();
  }
  lStack_16c = GetRcEngine::RcGetNum(0x3da);
  lStack_170 = GetRcEngine::RcGetNum(0x3db);
  lStack_174 = GetRcEngine::RcGetNum(0x3d9);
  lVar12 = GetRcEngine::RcGetNum(0x3d8);
  _Rect::set((_Rect *)&iStack_b34,lStack_16c,lStack_170,lStack_174,lVar12);
  lStack_178 = GetRcEngine::RcGetNum(0x3e6);
  lStack_17c = GetRcEngine::RcGetNum(999);
  lStack_180 = GetRcEngine::RcGetNum(0x3e5);
  lVar12 = GetRcEngine::RcGetNum(0x3e4);
  _Rect::set((_Rect *)&iStack_b24,lStack_178,lStack_17c,lStack_180,lVar12);
  lStack_184 = GetRcEngine::RcGetNum(0x3d2);
  lStack_188 = GetRcEngine::RcGetNum(0x3d3);
  lStack_18c = GetRcEngine::RcGetNum(0x3d1);
  lVar12 = GetRcEngine::RcGetNum(0x3d0);
  _Rect::set((_Rect *)&uStack_b14,lStack_184,lStack_188,lStack_18c,lVar12);
  lStack_190 = GetRcEngine::RcGetNum(0x32e);
  lStack_194 = GetRcEngine::RcGetNum(0x32f);
  lStack_198 = GetRcEngine::RcGetNum(0x32d);
  lVar12 = GetRcEngine::RcGetNum(0x32c);
  _Rect::set((_Rect *)&iStack_b04,lStack_190,lStack_194,lStack_198,lVar12);
  lStack_19c = GetRcEngine::RcGetNum(0x38e);
  lStack_1a0 = GetRcEngine::RcGetNum(0x38f);
  lStack_1a4 = GetRcEngine::RcGetNum(0x38d);
  lVar12 = GetRcEngine::RcGetNum(0x38c);
  _Rect::set((_Rect *)&iStack_af4,lStack_19c,lStack_1a0,lStack_1a4,lVar12);
  lStack_1a8 = GetRcEngine::RcGetNum(0x386);
  lStack_1ac = GetRcEngine::RcGetNum(0x387);
  lStack_1b0 = GetRcEngine::RcGetNum(0x385);
  lVar12 = GetRcEngine::RcGetNum(900);
  _Rect::set((_Rect *)&iStack_ae4,lStack_1a8,lStack_1ac,lStack_1b0,lVar12);
  lStack_1b4 = GetRcEngine::RcGetNum(0x3fa);
  lStack_1b8 = GetRcEngine::RcGetNum(0x3fb);
  lStack_1bc = GetRcEngine::RcGetNum(0x3f9);
  lVar12 = GetRcEngine::RcGetNum(0x3f8);
  _Rect::set((_Rect *)&iStack_ad4,lStack_1b4,lStack_1b8,lStack_1bc,lVar12);
  iStack_1c0 = iStack_b2c;
  iVar3 = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x260));
  iVar3 = iStack_1c0 - iVar3;
  iStack_1c4 = iStack_b1c;
  iVar4 = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x25c));
  iVar3 = (iStack_1c4 - iVar4) + iVar3 + -0x10;
  iStack_b2c = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x260));
  iStack_b2c = iStack_b2c + 8;
  iStack_b1c = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x25c));
  iStack_b1c = iStack_b1c + 8;
  iStack_afc = iStack_afc - iVar3;
  iStack_b0c = iStack_b0c + iVar3;
  iStack_b04 = iStack_b04 + iVar3;
  iStack_b34 = iStack_b24 + iStack_b1c + 4;
  iStack_af4 = iStack_af4 - iVar3;
  iStack_ae4 = iStack_ae4 - iVar3;
  iStack_ad4 = iStack_ad4 - iVar3;
  iVar3 = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x23c));
  if (iVar3 + 8 < iStack_b0c) {
    iStack_1c8 = iStack_b0c;
    iVar3 = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x23c));
    iVar3 = (iStack_1c8 - iVar3) + -0x10;
    iStack_b0c = TextBox::GetTextWidth((uchar)*(undefined4 *)(this + 0x23c));
    iStack_b0c = iStack_b0c + 8;
    iStack_b04 = iStack_b04 - iVar3;
    iStack_afc = iStack_afc + iVar3;
    iStack_b1c = iStack_b1c + iVar3 * 2;
    iStack_b34 = iStack_b34 + iVar3;
    iStack_af4 = iStack_af4 + iVar3;
    iStack_ae4 = iStack_ae4 + iVar3;
    iStack_ad4 = iStack_ad4 + iVar3;
  }
  (**(code **)(**(int **)(this + 0x260) + 0x24))
            (*(undefined4 *)(this + 0x260),iStack_b34,uStack_b30,&iStack_b34);
  (**(code **)(**(int **)(this + 0x25c) + 0x24))
            (*(undefined4 *)(this + 0x25c),iStack_b24,uStack_b20,&iStack_b24);
  (**(code **)(**(int **)(this + 0x23c) + 0x24))
            (*(undefined4 *)(this + 0x23c),uStack_b14,uStack_b10,&uStack_b14);
  (**(code **)(**(int **)(this + 0x248) + 0x24))
            (*(undefined4 *)(this + 0x248),iStack_b04,uStack_b00,&iStack_b04);
  (**(code **)(**(int **)(this + 0x264) + 0x24))
            (*(undefined4 *)(this + 0x264),iStack_af4,uStack_af0,&iStack_af4);
  (**(code **)(**(int **)(this + 0x268) + 0x24))
            (*(undefined4 *)(this + 0x268),iStack_ae4,uStack_ae0,&iStack_ae4);
  (**(code **)(**(int **)(this + 0x26c) + 0x24))
            (*(undefined4 *)(this + 0x26c),iStack_ad4,uStack_ad0,&iStack_ad4);
  MWidget::Invalidate();
LAB_007dae08:
  FUN_007d4034(auStack_a10);
  return;
}

