
undefined4 FUN_0079464c(ArChannelListFrame *param_1,undefined4 param_2,uint param_3)

{
  uchar uVar1;
  ushort uVar2;
  bool bVar3;
  char cVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  ArEpgManager *pAVar8;
  ChannelInfo *pCVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  int *piVar13;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  string *psVar14;
  ulong uVar15;
  ArTvManager *pAVar16;
  uint uVar17;
  code *pcVar18;
  byte bStack_314;
  undefined4 uStack_30c;
  bool bStack_307;
  bool bStack_306;
  undefined4 uStack_300;
  byte bStack_2ec;
  string asStack_2e4 [4];
  string asStack_2e0 [4];
  string asStack_2dc [4];
  allocator aaStack_2d8 [4];
  string asStack_2d4 [4];
  allocator aaStack_2d0 [4];
  string asStack_2cc [4];
  uchar auStack_2c8 [4];
  ulong uStack_2c4;
  allocator aaStack_2c0 [4];
  string asStack_2bc [4];
  byte abStack_2b8 [4];
  ulong uStack_2b4;
  allocator aaStack_2b0 [4];
  string asStack_2ac [4];
  byte abStack_2a8 [4];
  ulong uStack_2a4;
  allocator aaStack_2a0 [4];
  string asStack_29c [4];
  __normal_iterator a_Stack_298 [4];
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined1 auStack_288 [4];
  __normal_iterator a_Stack_284 [4];
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 uStack_278;
  undefined1 auStack_274 [4];
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  allocator aaStack_264 [4];
  string asStack_260 [4];
  allocator aaStack_25c [4];
  string asStack_258 [4];
  allocator aaStack_254 [4];
  string asStack_250 [4];
  allocator aaStack_24c [4];
  string asStack_248 [4];
  allocator aaStack_244 [4];
  string asStack_240 [4];
  allocator aaStack_23c [4];
  string asStack_238 [4];
  allocator aaStack_234 [4];
  string asStack_230 [4];
  allocator aaStack_22c [4];
  string asStack_228 [4];
  allocator aaStack_224 [4];
  string asStack_220 [4];
  allocator aaStack_21c [4];
  string asStack_218 [4];
  allocator aaStack_214 [4];
  string asStack_210 [4];
  string asStack_20c [4];
  string asStack_208 [4];
  allocator aaStack_204 [4];
  string asStack_200 [4];
  allocator aaStack_1fc [4];
  string asStack_1f8 [4];
  allocator aaStack_1f4 [4];
  string asStack_1f0 [4];
  ArUIManager aAStack_1ec [4];
  string asStack_1e8 [4];
  string asStack_1e4 [4];
  vector<AR_EPG_EVENT_TIMER_INFO,std::allocator<AR_EPG_EVENT_TIMER_INFO>> avStack_1e0 [12];
  vector<std::string,std::allocator<std::string>> avStack_1d4 [12];
  vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>> avStack_1c8 [12];
  vector<std::string,std::allocator<std::string>> avStack_1bc [12];
  vector<unsigned_long,std::allocator<unsigned_long>> avStack_1b0 [12];
  vector<unsigned_char,std::allocator<unsigned_char>> avStack_1a4 [12];
  ArUIManager aAStack_198 [4];
  ostringstream aoStack_194 [180];
  ChannelEditorApp *pCStack_e0;
  ChannelEditorApp *pCStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  string *psStack_c0;
  string *psStack_bc;
  string *psStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  int iStack_a4;
  string *psStack_a0;
  string *psStack_9c;
  int iStack_98;
  ArScheduleListApp *pAStack_94;
  string *psStack_90;
  string *psStack_8c;
  string *psStack_88;
  string *psStack_84;
  string *psStack_80;
  string *psStack_7c;
  string *psStack_78;
  string *psStack_74;
  string *psStack_70;
  string *psStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  string *psStack_54;
  int iStack_50;
  int *piStack_4c;
  int iStack_48;
  int *piStack_44;
  int iStack_40;
  int *piStack_3c;
  int iStack_38;
  int *piStack_34;
  ostream *poStack_30;
  int iStack_2c;
  string *psStack_28;
  uint uStack_20;
  
  MEvtHandle::KillTimer((ulong)param_1);
  MEvtHandle::SetTimer(param_1,10000,0,1);
  uStack_20 = param_3;
  if (param_3 == 0xf043) {
    if (*(int *)(param_1 + 0x5c4) == 2) {
      pAStack_94 = operator_new(0x3c);
                    /* try { // try from 00797094 to 0079709b has its CatchHandler @ 007970bc */
      ArScheduleListApp::ArScheduleListApp(pAStack_94);
      if (pAStack_94 == (ArScheduleListApp *)0x0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00feeb6c,&UNK_00feee28,0xbbb);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      MApplet::Run((ulong)pAStack_94,(void *)0x0);
      uVar15 = MWnd::GetParentApp();
      MApplet::Hide(uVar15);
    }
    else if (*(int *)(param_1 + 0x5e0) == 0) {
      uVar10 = ArChannelListFrame::RefreshOPList(param_1);
      *(undefined4 *)(param_1 + 0x5f0) = uVar10;
      iVar11 = std::vector<OPData,std::allocator<OPData>>::size
                         ((vector<OPData,std::allocator<OPData>> *)(param_1 + 0x5c8));
      if ((iVar11 == 0) || (iVar11 = ArChannelManager::IsCurrentAntennaTypeRecording(), iVar11 != 0)
         ) {
        iStack_98 = 0;
      }
      else {
        iStack_98 = 1;
      }
      if (iStack_98 != 0) {
        MWidget::Show();
        (**(code **)(**(int **)(param_1 + 0x2ac) + 0x40))
                  (*(undefined4 *)(param_1 + 0x2ac),*(undefined4 *)(param_1 + 0x5f0));
        MMainFrame::SwitchFocusTo((MWidget *)param_1);
        *(undefined4 *)(param_1 + 0x5ec) = *(undefined4 *)(param_1 + 0x5f0);
        *(undefined4 *)(param_1 + 0x5e0) = 3;
        HelpWidget::PushHelpData();
        HelpWidget::HideAllButtons(*(HelpWidget **)(param_1 + 0x2c0));
        HelpWidget::ShowButton(*(HelpWidget **)(param_1 + 0x2c0),0,0x10f2);
        HelpWidget::ShowButton(*(HelpWidget **)(param_1 + 0x2c0),7,0xf37);
        psStack_9c = (string *)(*(int *)(param_1 + 0x2a8) + 0x170);
        std::allocator<char>::allocator();
                    /* try { // try from 00797368 to 0079736f has its CatchHandler @ 00797444 */
        std::string::string(asStack_260,"",aaStack_264);
                    /* try { // try from 00797384 to 0079738b has its CatchHandler @ 00797404 */
        MString::Set(psStack_9c);
        psStack_a0 = asStack_260;
                    /* try { // try from 007973a0 to 007973a7 has its CatchHandler @ 00797444 */
        std::string::~string(psStack_a0);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_264);
        MWidget::Invalidate();
        HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
      }
    }
    return 1;
  }
  if (0xf043 < param_3) {
    if (0xf047 < param_3) {
      if (param_3 != 0xf062) {
        if (param_3 < 0xf063) {
          if (param_3 != 0xf056) {
            return 0;
          }
          if (*(int *)(param_1 + 0x5e0) != 3) {
            if (*(int *)(param_1 + 0x5b0) != 0) {
              return 1;
            }
            return 1;
          }
          return 1;
        }
        if (param_3 == 0xf06d) {
          if (*(int *)(param_1 + 0x5e0) != 3) {
            MWnd::GetParentApp();
            MApplet::Kill();
            ArProgramInfoApp::KillAPP();
            uVar10 = IdleAppFrame::GetIdleAppFrame();
            IdleAppFrame::StartConnectedApp(uVar10,2);
            return 1;
          }
          return 1;
        }
        if (param_3 != 0xf075) {
          return 0;
        }
      }
      if (*(int *)(param_1 + 0x5e0) != 3) {
        MWnd::GetParentApp();
        MApplet::Kill();
        ArProgramInfoApp::KillAPP();
        return 1;
      }
      *(undefined4 *)(param_1 + 0x5e0) = 0;
      MWidget::Hide();
      HelpWidget::HideAllButtons(*(HelpWidget **)(param_1 + 0x2c0));
      HelpWidget::PopHelpData(*(HelpWidget **)(param_1 + 0x2c0));
      if ((*(int *)(param_1 + 0x5e8) < 7) || (10 < *(int *)(param_1 + 0x5e8))) {
        uVar10 = *(undefined4 *)(param_1 + 0x2a8);
        ArChannelListFrame::FilterTypeToStringID(param_1,*(undefined4 *)(param_1 + 0x5e8));
        MString::Set((short)uVar10 + 0x170);
      }
      else {
        iVar11 = *(int *)(param_1 + 0x2a8);
        uVar10 = ArChannelManager::getInstance();
        ArChannelManager::GetFavName(asStack_1e4,uVar10,*(int *)(param_1 + 0x5e8) + -7);
                    /* try { // try from 0079495c to 00794963 has its CatchHandler @ 00794988 */
        MString::Set((string *)(iVar11 + 0x170));
        std::string::~string(asStack_1e4);
      }
      MWidget::Invalidate();
      HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
      return 1;
    }
    if (0xf045 < param_3) {
LAB_00794cd0:
      if (*(int *)(param_1 + 0x5e0) == 3) {
        return 1;
      }
      if ((param_3 == 0xf000) || (param_3 == 0xf001)) {
        bStack_2ec = 1;
      }
      else {
        if (*(int *)(param_1 + 0x5b0) < 5) {
          return 1;
        }
        bStack_2ec = 5;
      }
      if ((*(int *)(param_1 + 0x5e0) != 1) && (*(int *)(param_1 + 0x5e0) != 2)) {
        if (*(int *)(param_1 + 0x5b0) != 0) {
          FocusMarqueeTextBox::StopMarquee();
          if ((param_3 == 0xf046) || (param_3 == 0xf001)) {
            *(uint *)(param_1 + 0x5ac) = *(int *)(param_1 + 0x5ac) + (uint)bStack_2ec;
            if (*(int *)(param_1 + 0x5b0) <= *(int *)(param_1 + 0x5ac)) {
              *(undefined4 *)(param_1 + 0x5ac) = 0;
            }
          }
          else if (((param_3 == 0xf047) || (param_3 == 0xf000)) &&
                  (*(uint *)(param_1 + 0x5ac) = *(int *)(param_1 + 0x5ac) - (uint)bStack_2ec,
                  *(int *)(param_1 + 0x5ac) < 0)) {
            *(int *)(param_1 + 0x5ac) = *(int *)(param_1 + 0x5b0) + -1;
          }
          if (*(int *)(param_1 + 0x5c4) != 0) {
            std::vector<EventCfg,std::allocator<EventCfg>>::clear();
            pAVar8 = (ArEpgManager *)ArEpgManager::getInstance();
            pCVar9 = (ChannelInfo *)
                     std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                               ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c)
                                ,*(uint *)(param_1 + 0x5ac));
            ArEpgManager::GetAllProgrammeInfo
                      (pAVar8,pCVar9,(vector *)(param_1 + 0x2b4),'\x01',0,0,7);
            uVar10 = std::vector<EventCfg,std::allocator<EventCfg>>::size
                               ((vector<EventCfg,std::allocator<EventCfg>> *)(param_1 + 0x2b4));
            *(undefined4 *)(param_1 + 0x5b8) = uVar10;
          }
          ArChannelListFrame::RefreshChannelList(param_1);
          return 1;
        }
        return 1;
      }
      return 0;
    }
    if (param_3 != 0xf044) {
      if (param_3 != 0xf045) {
        return 0;
      }
      if (*(int *)(param_1 + 0x5e0) == 3) {
        return 1;
      }
      iVar11 = ArChannelManager::IsCurrentAntennaTypeRecording();
      if (iVar11 == 0) {
        pAVar16 = (ArTvManager *)ArTvManager::getInstance();
        iVar11 = ArTvManager::GetDualWatchStatus(pAVar16);
        if (iVar11 != 1) {
          iStack_68 = 0;
          goto LAB_00796040;
        }
      }
      iStack_68 = 1;
LAB_00796040:
      if (iStack_68 != 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x5c4) == 2) {
        iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                           ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                            *(uint *)(param_1 + 0x5ac));
        uVar2 = *(ushort *)(iVar11 + 2);
        iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                           ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                            *(uint *)(param_1 + 0x5ac));
        uVar1 = *(uchar *)(iVar11 + 4);
        iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                           ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                            *(uint *)(param_1 + 0x5ac));
        cVar4 = ArChannelManager::SelectChannel((uint)uVar2,uVar1,*(uchar *)(iVar11 + 5),'\x01');
        if (cVar4 != '\0') {
          *(undefined4 *)(param_1 + 0x5a8) = *(undefined4 *)(param_1 + 0x5ac);
          ArChannelListFrame::RefreshChannelList(param_1);
        }
      }
      else {
        if ((((*(int *)(param_1 + 0x5e8) == 7) || (*(int *)(param_1 + 0x5e8) == 8)) ||
            (*(int *)(param_1 + 0x5e8) == 9)) || (*(int *)(param_1 + 0x5e8) == 10)) {
          return 1;
        }
        std::vector<std::string,std::allocator<std::string>>::vector(avStack_1d4);
        uStack_300 = 0;
                    /* try { // try from 007961d8 to 0079621b has its CatchHandler @ 0079700c */
        ArTvManager::getInstance();
        iVar11 = ArTvManager::GetCurrentDvbAntennaType();
        if (iVar11 == 3) {
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc0f);
          std::allocator<char>::allocator();
                    /* try { // try from 00796254 to 0079625b has its CatchHandler @ 00796358 */
          std::string::string(asStack_210,pcVar12,aaStack_214);
                    /* try { // try from 00796274 to 0079627b has its CatchHandler @ 007962d0 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_210);
          psStack_6c = asStack_210;
                    /* try { // try from 00796290 to 00796297 has its CatchHandler @ 00796358 */
          std::string::~string(psStack_6c);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_214);
                    /* try { // try from 007962bc to 007962c3 has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xcdd);
          std::allocator<char>::allocator();
                    /* try { // try from 00796344 to 0079634b has its CatchHandler @ 0079648c */
          std::string::string(asStack_218,pcVar12,aaStack_21c);
                    /* try { // try from 007963a8 to 007963af has its CatchHandler @ 00796404 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_218);
          psStack_70 = asStack_218;
                    /* try { // try from 007963c4 to 007963cb has its CatchHandler @ 0079648c */
          std::string::~string(psStack_70);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_21c);
                    /* try { // try from 007963f0 to 007963f7 has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xece);
          std::allocator<char>::allocator();
                    /* try { // try from 00796478 to 0079647f has its CatchHandler @ 007965c0 */
          std::string::string(asStack_220,pcVar12,aaStack_224);
                    /* try { // try from 007964dc to 007964e3 has its CatchHandler @ 00796538 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_220);
          psStack_74 = asStack_220;
                    /* try { // try from 007964f8 to 007964ff has its CatchHandler @ 007965c0 */
          std::string::~string(psStack_74);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_224);
                    /* try { // try from 00796524 to 0079652b has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xd64);
          std::allocator<char>::allocator();
                    /* try { // try from 007965ac to 007965b3 has its CatchHandler @ 007966f4 */
          std::string::string(asStack_228,pcVar12,aaStack_22c);
                    /* try { // try from 00796610 to 00796617 has its CatchHandler @ 0079666c */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_228);
          psStack_78 = asStack_228;
                    /* try { // try from 0079662c to 00796633 has its CatchHandler @ 007966f4 */
          std::string::~string(psStack_78);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_22c);
                    /* try { // try from 00796658 to 0079665f has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xf1c);
          std::allocator<char>::allocator();
                    /* try { // try from 007966e0 to 007966e7 has its CatchHandler @ 00796828 */
          std::string::string(asStack_230,pcVar12,aaStack_234);
                    /* try { // try from 00796744 to 0079674b has its CatchHandler @ 007967a0 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_230);
          psStack_7c = asStack_230;
                    /* try { // try from 00796760 to 00796767 has its CatchHandler @ 00796828 */
          std::string::~string(psStack_7c);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_234);
                    /* try { // try from 0079678c to 00796793 has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xf07);
          std::allocator<char>::allocator();
                    /* try { // try from 00796814 to 0079681b has its CatchHandler @ 00796914 */
          std::string::string(asStack_238,pcVar12,aaStack_23c);
                    /* try { // try from 00796878 to 0079687f has its CatchHandler @ 007968d4 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_238);
          psStack_80 = asStack_238;
                    /* try { // try from 00796894 to 0079689b has its CatchHandler @ 00796914 */
          std::string::~string(psStack_80);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_23c);
          if (*(int *)(param_1 + 0x5e8) == 1) {
            uStack_300 = 1;
          }
          else if (*(int *)(param_1 + 0x5e8) == 2) {
            uStack_300 = 2;
          }
          else if (*(int *)(param_1 + 0x5e8) == 4) {
            uStack_300 = 3;
          }
          else if (*(int *)(param_1 + 0x5e8) == 5) {
            uStack_300 = 4;
          }
          else if (*(int *)(param_1 + 0x5e8) == 6) {
            uStack_300 = 5;
          }
        }
        else {
                    /* try { // try from 007969f8 to 007969ff has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc0f);
          std::allocator<char>::allocator();
                    /* try { // try from 00796a38 to 00796a3f has its CatchHandler @ 00796b3c */
          std::string::string(asStack_240,pcVar12,aaStack_244);
                    /* try { // try from 00796a58 to 00796a5f has its CatchHandler @ 00796ab4 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_240);
          psStack_84 = asStack_240;
                    /* try { // try from 00796a74 to 00796a7b has its CatchHandler @ 00796b3c */
          std::string::~string(psStack_84);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_244);
                    /* try { // try from 00796aa0 to 00796aa7 has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xcdd);
          std::allocator<char>::allocator();
                    /* try { // try from 00796b28 to 00796b2f has its CatchHandler @ 00796c70 */
          std::string::string(asStack_248,pcVar12,aaStack_24c);
                    /* try { // try from 00796b8c to 00796b93 has its CatchHandler @ 00796be8 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_248);
          psStack_88 = asStack_248;
                    /* try { // try from 00796ba8 to 00796baf has its CatchHandler @ 00796c70 */
          std::string::~string(psStack_88);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_24c);
                    /* try { // try from 00796bd4 to 00796bdb has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xece);
          std::allocator<char>::allocator();
                    /* try { // try from 00796c5c to 00796c63 has its CatchHandler @ 00796da4 */
          std::string::string(asStack_250,pcVar12,aaStack_254);
                    /* try { // try from 00796cc0 to 00796cc7 has its CatchHandler @ 00796d1c */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_250);
          psStack_8c = asStack_250;
                    /* try { // try from 00796cdc to 00796ce3 has its CatchHandler @ 00796da4 */
          std::string::~string(psStack_8c);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_254);
                    /* try { // try from 00796d08 to 00796d0f has its CatchHandler @ 0079700c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc17);
          std::allocator<char>::allocator();
                    /* try { // try from 00796d90 to 00796d97 has its CatchHandler @ 00796e90 */
          std::string::string(asStack_258,pcVar12,aaStack_25c);
                    /* try { // try from 00796df4 to 00796dfb has its CatchHandler @ 00796e50 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1d4,asStack_258);
          psStack_90 = asStack_258;
                    /* try { // try from 00796e10 to 00796e17 has its CatchHandler @ 00796e90 */
          std::string::~string(psStack_90);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_25c);
          if (*(int *)(param_1 + 0x5e8) == 1) {
            uStack_300 = 1;
          }
          else if (*(int *)(param_1 + 0x5e8) == 2) {
            uStack_300 = 2;
          }
          else if (*(int *)(param_1 + 0x5e8) == 3) {
            uStack_300 = 3;
          }
        }
                    /* try { // try from 00796f20 to 00796fdb has its CatchHandler @ 0079700c */
        PopUpManager::Clean();
        pcVar12 = (char *)GetRcEngine::RcGetString(0xd59);
        std::string::operator=((string *)PopUpManager::itemSelectData,pcVar12);
        std::vector<std::string,std::allocator<std::string>>::operator=
                  ((vector<std::string,std::allocator<std::string>> *)
                   (PopUpManager::itemSelectData + 8),(vector *)avStack_1d4);
        PopUpManager::itemSelectData._4_4_ = uStack_300;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::parentFrame = param_1;
        PopUpManager::ShowButton(0xe,0xc42);
        PopUpManager::ShowButton(7,0xf37);
        PopUpManager::Summon(1);
        *(undefined4 *)(param_1 + 0x5e0) = 1;
        std::vector<std::string,std::allocator<std::string>>::~vector(avStack_1d4);
      }
      return 1;
    }
    if (*(int *)(param_1 + 0x5e0) == 3) {
      return 1;
    }
    if (*(int *)(param_1 + 0x5c4) == 2) {
      return 1;
    }
    ArServiceSettingsManager::getInstance();
    iVar11 = ArServiceSettingsManager::ArSourceConf_GetAirAvailable();
    bStack_306 = iVar11 != 0;
    ArServiceSettingsManager::getInstance();
    iVar11 = ArServiceSettingsManager::ArSourceConf_GetCableAvailable();
    bStack_307 = iVar11 != 0;
    ArServiceSettingsManager::getInstance();
    iVar11 = ArServiceSettingsManager::ArSourceConf_GetSatelliteAvailable();
    bVar3 = iVar11 == 0;
    if (bVar3) {
      iStack_ac = MSrv_Control_TV::GetMSrvDtv(0);
      if (iStack_ac == 0) {
        uStack_a8 = 0;
      }
      else {
        uStack_a8 = __dynamic_cast(iStack_ac,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      iVar11 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
      if (iVar11 != 0) {
        iStack_a4 = 1;
        goto LAB_007975f4;
      }
    }
    iStack_a4 = 0;
LAB_007975f4:
    if (iStack_a4 != 0) {
      return 1;
    }
    if (((!bStack_306) && (!bStack_307)) && (bVar3)) {
      return 1;
    }
    std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::vector(avStack_1c8);
    bStack_314 = 0;
    while( true ) {
      piVar13 = (int *)MSrv_Control::GetInstance();
      uVar7 = (**(code **)(*piVar13 + 0x1bc))(piVar13);
      if (uVar7 <= bStack_314) {
        iVar11 = std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::size
                           (avStack_1c8);
        if (iVar11 != 0) {
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::begin();
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::end();
          uStack_280 = 1;
          std::
          find<__gnu_cxx::__normal_iterator<AR_EN_ANTENNA_TYPE*,std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>>,AR_EN_ANTENNA_TYPE>
                    (auStack_274,uStack_278,uStack_27c,&uStack_280);
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::end();
          bVar5 = __gnu_cxx::operator!=(auStack_274,a_Stack_284);
          if (CONCAT31(extraout_var,bVar5) == 0) {
            std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::begin();
            std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::end();
            uStack_294 = 2;
            std::
            find<__gnu_cxx::__normal_iterator<AR_EN_ANTENNA_TYPE*,std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>>,AR_EN_ANTENNA_TYPE>
                      (auStack_288,uStack_28c,uStack_290,&uStack_294);
            std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::end();
            bVar5 = __gnu_cxx::operator!=(auStack_288,a_Stack_298);
            if (CONCAT31(extraout_var_00,bVar5) != 0) {
              bStack_306 = false;
            }
          }
          else {
            bStack_307 = false;
          }
        }
        std::vector<std::string,std::allocator<std::string>>::vector(avStack_1bc);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::vector(avStack_1b0);
        std::vector<unsigned_char,std::allocator<unsigned_char>>::vector(avStack_1a4);
        uStack_30c = 0;
                    /* try { // try from 00797abc to 00797afb has its CatchHandler @ 00798208 */
        ArServiceSettingsManager::getInstance();
        iVar11 = ArServiceSettingsManager::ArSourceConf_GetAirAvailable();
        if (iVar11 != 0) {
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc0b);
          std::allocator<char>::allocator();
                    /* try { // try from 00797b34 to 00797b3b has its CatchHandler @ 00797c3c */
          std::string::string(asStack_29c,pcVar12,aaStack_2a0);
                    /* try { // try from 00797b54 to 00797b5b has its CatchHandler @ 00797bc4 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1bc,asStack_29c);
          psStack_b8 = asStack_29c;
                    /* try { // try from 00797b70 to 00797b77 has its CatchHandler @ 00797c3c */
          std::string::~string(psStack_b8);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_2a0);
          uStack_2a4 = 0xa5;
                    /* try { // try from 00797bb0 to 00797bb7 has its CatchHandler @ 00798208 */
          std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                    (avStack_1b0,&uStack_2a4);
          abStack_2a8[0] = bStack_306 ^ 1;
                    /* try { // try from 00797c28 to 00797cbb has its CatchHandler @ 00798208 */
          std::vector<unsigned_char,std::allocator<unsigned_char>>::push_back
                    (avStack_1a4,abStack_2a8);
        }
        ArServiceSettingsManager::getInstance();
        iVar11 = ArServiceSettingsManager::ArSourceConf_GetCableAvailable();
        if (iVar11 != 0) {
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc61);
          std::allocator<char>::allocator();
                    /* try { // try from 00797cf4 to 00797cfb has its CatchHandler @ 00797dfc */
          std::string::string(asStack_2ac,pcVar12,aaStack_2b0);
                    /* try { // try from 00797d14 to 00797d1b has its CatchHandler @ 00797d84 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1bc,asStack_2ac);
          psStack_bc = asStack_2ac;
                    /* try { // try from 00797d30 to 00797d37 has its CatchHandler @ 00797dfc */
          std::string::~string(psStack_bc);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_2b0);
          uStack_2b4 = 0x9f;
                    /* try { // try from 00797d70 to 00797d77 has its CatchHandler @ 00798208 */
          std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                    (avStack_1b0,&uStack_2b4);
          abStack_2b8[0] = bStack_307 ^ 1;
                    /* try { // try from 00797de8 to 00797e7b has its CatchHandler @ 00798208 */
          std::vector<unsigned_char,std::allocator<unsigned_char>>::push_back
                    (avStack_1a4,abStack_2b8);
        }
        ArServiceSettingsManager::getInstance();
        iVar11 = ArServiceSettingsManager::ArSourceConf_GetSatelliteAvailable();
        if (iVar11 != 0) {
          pcVar12 = (char *)GetRcEngine::RcGetString(0xf07);
          std::allocator<char>::allocator();
                    /* try { // try from 00797eb4 to 00797ebb has its CatchHandler @ 00797fbc */
          std::string::string(asStack_2bc,pcVar12,aaStack_2c0);
                    /* try { // try from 00797ed4 to 00797edb has its CatchHandler @ 00797f44 */
          std::vector<std::string,std::allocator<std::string>>::push_back(avStack_1bc,asStack_2bc);
          psStack_c0 = asStack_2bc;
                    /* try { // try from 00797ef0 to 00797ef7 has its CatchHandler @ 00797fbc */
          std::string::~string(psStack_c0);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_2c0);
          uStack_2c4 = 0xa3;
                    /* try { // try from 00797f30 to 00797f37 has its CatchHandler @ 00798208 */
          std::vector<unsigned_long,std::allocator<unsigned_long>>::push_back
                    (avStack_1b0,&uStack_2c4);
          auStack_2c8[0] = bVar3;
                    /* try { // try from 00797fa8 to 0079818f has its CatchHandler @ 00798208 */
          std::vector<unsigned_char,std::allocator<unsigned_char>>::push_back
                    (avStack_1a4,auStack_2c8);
        }
        ArTvManager::getInstance();
        iVar11 = ArTvManager::GetCurrentDvbAntennaType();
        if (iVar11 == 1) {
          uStack_30c = 0;
        }
        else if (iVar11 == 2) {
          uStack_30c = 1;
        }
        else if (iVar11 == 3) {
          uStack_30c = 2;
        }
        PopUpManager::Clean();
        pcVar12 = (char *)GetRcEngine::RcGetString(0x1078);
        std::string::operator=((string *)(PopUpManager::gridSelectData + 8),pcVar12);
        std::vector<std::string,std::allocator<std::string>>::operator=
                  ((vector<std::string,std::allocator<std::string>> *)
                   (PopUpManager::gridSelectData + 0x28),(vector *)avStack_1bc);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::operator=
                  ((vector<unsigned_long,std::allocator<unsigned_long>> *)
                   (PopUpManager::gridSelectData + 0x34),(vector *)avStack_1b0);
        std::vector<unsigned_char,std::allocator<unsigned_char>>::operator=
                  ((vector<unsigned_char,std::allocator<unsigned_char>> *)
                   (PopUpManager::gridSelectData + 0x40),(vector *)avStack_1a4);
        PopUpManager::gridSelectData._28_4_ = 0x44;
        PopUpManager::gridSelectData._32_4_ = 0x37;
        PopUpManager::gridSelectData._16_4_ = uStack_30c;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::parentFrame = param_1;
        PopUpManager::ShowButton(0xe,0xc42);
        PopUpManager::ShowButton(7,0xf37);
        PopUpManager::Summon(5);
        *(undefined4 *)(param_1 + 0x5e0) = 2;
        std::vector<unsigned_char,std::allocator<unsigned_char>>::~vector(avStack_1a4);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::~vector(avStack_1b0);
                    /* try { // try from 007981dc to 007981e3 has its CatchHandler @ 00798294 */
        std::vector<std::string,std::allocator<std::string>>::~vector(avStack_1bc);
        std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::~vector(avStack_1c8);
        return 1;
      }
                    /* try { // try from 00797684 to 0079789f has its CatchHandler @ 00798294 */
      piVar13 = (int *)MSrv_Control::GetInstance();
      iStack_b4 = (**(code **)(*piVar13 + 0x1b4))(piVar13,bStack_314);
      if (iStack_b4 == 0) {
        iStack_b0 = 0;
      }
      else {
        iStack_b0 = __dynamic_cast(iStack_b4,&DAT_2da86f20,&DAT_2d5d5108,0);
      }
      if (iStack_b0 == 0) break;
      iVar11 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
      if (iVar11 == 1) {
        iVar11 = MSrv_Control_common::GetTVInfo();
        cVar4 = *(char *)(iVar11 + (uint)bStack_314 + 0x13);
        if (cVar4 == '\x02') {
          uStack_268 = 2;
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::push_back
                    (avStack_1c8,(AR_EN_ANTENNA_TYPE *)&uStack_268);
        }
        else if ((cVar4 == '\x04') || (cVar4 == '@')) {
          uStack_26c = 3;
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::push_back
                    (avStack_1c8,(AR_EN_ANTENNA_TYPE *)&uStack_26c);
        }
        else if ((cVar4 == '\x01') || (cVar4 == ' ')) {
          uStack_270 = 1;
          std::vector<AR_EN_ANTENNA_TYPE,std::allocator<AR_EN_ANTENNA_TYPE>>::push_back
                    (avStack_1c8,(AR_EN_ANTENNA_TYPE *)&uStack_270);
        }
      }
      bStack_314 = bStack_314 + 1;
    }
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00feeb6c,&UNK_00feee28,0xc2a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  if (param_3 == 0xf002) {
    if (*(int *)(param_1 + 0x5e0) == 3) {
      if (*(int *)(param_1 + 0x5ec) != 0) {
        *(int *)(param_1 + 0x5ec) = *(int *)(param_1 + 0x5ec) + -1;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x5b0) != 0) {
      std::vector<EventCfg,std::allocator<EventCfg>>::clear();
      pAVar8 = (ArEpgManager *)ArEpgManager::getInstance();
      pCVar9 = (ChannelInfo *)
               std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5ac));
      ArEpgManager::GetAllProgrammeInfo(pAVar8,pCVar9,(vector *)(param_1 + 0x2b4),'\x01',0,0,7);
      uVar10 = std::vector<EventCfg,std::allocator<EventCfg>>::size
                         ((vector<EventCfg,std::allocator<EventCfg>> *)(param_1 + 0x2b4));
      *(undefined4 *)(param_1 + 0x5b8) = uVar10;
      *(undefined4 *)(param_1 + 0x5c4) = 1;
      ArChannelListFrame::RefreshChannelList(param_1);
      MWidget::Hide();
      return 1;
    }
    return 1;
  }
  if (param_3 < 0xf003) {
    if (param_3 != 0xd) {
      if (param_3 < 0xd) {
        return 0;
      }
      if (param_3 < 0xf000) {
        return 0;
      }
      goto LAB_00794cd0;
    }
    if (*(int *)(param_1 + 0x5e0) == 3) {
      std::vector<AR_EPG_EVENT_TIMER_INFO,std::allocator<AR_EPG_EVENT_TIMER_INFO>>::vector
                (avStack_1e0);
                    /* try { // try from 00794fa8 to 007950b7 has its CatchHandler @ 00795be4 */
      pAVar8 = (ArEpgManager *)ArEpgManager::getInstance();
      ArEpgManager::GetEPGScheduleList(pAVar8,(vector *)avStack_1e0);
      if (*(int *)(param_1 + 0x5ec) == *(int *)(param_1 + 0x5f0)) {
        *(undefined4 *)(param_1 + 0x5e0) = 0;
        MWidget::Hide();
        HelpWidget::HideAllButtons(*(HelpWidget **)(param_1 + 0x2c0));
        HelpWidget::PopHelpData(*(HelpWidget **)(param_1 + 0x2c0));
        if ((*(int *)(param_1 + 0x5e8) < 7) || (10 < *(int *)(param_1 + 0x5e8))) {
          iStack_2c = *(int *)(param_1 + 0x2a8) + 0x170;
                    /* try { // try from 00795158 to 0079520b has its CatchHandler @ 00795be4 */
          ArChannelListFrame::FilterTypeToStringID(param_1,*(undefined4 *)(param_1 + 0x5e8));
          MString::Set((ushort)iStack_2c);
        }
        else {
          psStack_28 = (string *)(*(int *)(param_1 + 0x2a8) + 0x170);
          uVar10 = ArChannelManager::getInstance();
          ArChannelManager::GetFavName(asStack_1e8,uVar10,*(int *)(param_1 + 0x5e8) + -7);
                    /* try { // try from 007950cc to 007950d3 has its CatchHandler @ 007950f8 */
          MString::Set(psStack_28);
                    /* try { // try from 007950e4 to 007950eb has its CatchHandler @ 00795be4 */
          std::string::~string(asStack_1e8);
        }
        MWidget::Invalidate();
        HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
      }
      else {
        iVar11 = std::vector<AR_EPG_EVENT_TIMER_INFO,std::allocator<AR_EPG_EVENT_TIMER_INFO>>::size
                           (avStack_1e0);
        if (iVar11 == 0) {
          if (*(int *)(param_1 + 0x5ec) == 0) {
                    /* try { // try from 007957d0 to 00795abf has its CatchHandler @ 00795be4 */
            iStack_38 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_38 == 0) {
              piStack_34 = (int *)0x0;
            }
            else {
              piStack_34 = (int *)__dynamic_cast(iStack_38,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            iVar11 = (**(code **)(*piStack_34 + 0x710))(piStack_34);
            if (iVar11 != 0) {
              iStack_40 = MSrv_Control_TV::GetMSrvDtv(0);
              if (iStack_40 == 0) {
                piStack_3c = (int *)0x0;
              }
              else {
                piStack_3c = (int *)__dynamic_cast(iStack_40,&DAT_2da86f20,&DAT_2d5d5108,0);
              }
              (**(code **)(*piStack_3c + 0x350))(piStack_3c,1);
              iStack_48 = MSrv_Control_TV::GetMSrvDtv(0);
              if (iStack_48 == 0) {
                piStack_44 = (int *)0x0;
              }
              else {
                piStack_44 = (int *)__dynamic_cast(iStack_48,&DAT_2da86f20,&DAT_2d5d5108,0);
              }
              (**(code **)(*piStack_44 + 0x6dc))(piStack_44);
            }
          }
          else {
            iStack_50 = MSrv_Control_TV::GetMSrvDtv(0);
            if (iStack_50 == 0) {
              piStack_4c = (int *)0x0;
            }
            else {
              piStack_4c = (int *)__dynamic_cast(iStack_50,&DAT_2da86f20,&DAT_2d5d5108,0);
            }
            piVar13 = piStack_4c;
            pcVar18 = *(code **)(*piStack_4c + 0x6d8);
            iVar11 = std::vector<OPData,std::allocator<OPData>>::operator[]
                               ((vector<OPData,std::allocator<OPData>> *)(param_1 + 0x5c8),
                                *(int *)(param_1 + 0x5ec) - 1);
            (*pcVar18)(piVar13,*(uint *)(iVar11 + 4) & 0xff);
          }
          *(undefined4 *)(param_1 + 0x5e0) = 0;
          MWidget::Hide();
          HelpWidget::HideAllButtons(*(HelpWidget **)(param_1 + 0x2c0));
          HelpWidget::PopHelpData(*(HelpWidget **)(param_1 + 0x2c0));
          if ((*(int *)(param_1 + 0x5e8) < 7) || (10 < *(int *)(param_1 + 0x5e8))) {
            iStack_58 = *(int *)(param_1 + 0x2a8) + 0x170;
                    /* try { // try from 00795b60 to 00795bb7 has its CatchHandler @ 00795be4 */
            ArChannelListFrame::FilterTypeToStringID(param_1,*(undefined4 *)(param_1 + 0x5e8));
            MString::Set((ushort)iStack_58);
          }
          else {
            psStack_54 = (string *)(*(int *)(param_1 + 0x2a8) + 0x170);
            uVar10 = ArChannelManager::getInstance();
            ArChannelManager::GetFavName(asStack_20c,uVar10,*(int *)(param_1 + 0x5e8) + -7);
                    /* try { // try from 00795ad4 to 00795adb has its CatchHandler @ 00795b00 */
            MString::Set(psStack_54);
                    /* try { // try from 00795aec to 00795af3 has its CatchHandler @ 00795be4 */
            std::string::~string(asStack_20c);
          }
          MWidget::Invalidate();
          HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
        }
        else {
          PopUpManager::Clean();
          std::ostringstream::ostringstream(aoStack_194,0x10);
                    /* try { // try from 00795218 to 0079521f has its CatchHandler @ 0079577c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0x10f4);
          std::allocator<char>::allocator();
                    /* try { // try from 00795258 to 0079525f has its CatchHandler @ 00795574 */
          std::string::string(asStack_1f0,pcVar12,aaStack_1f4);
          std::allocator<char>::allocator();
                    /* try { // try from 00795298 to 0079529f has its CatchHandler @ 007954f0 */
          std::string::string(asStack_1f8,"[sch_name] ",aaStack_1fc);
          std::allocator<char>::allocator();
                    /* try { // try from 007952d8 to 007952df has its CatchHandler @ 0079544c */
          std::string::string(asStack_200,"",aaStack_204);
                    /* try { // try from 00795300 to 00795307 has its CatchHandler @ 007953d8 */
          ArUIManager::ReplaceString(aAStack_1ec,asStack_1f0,asStack_1f8,asStack_200);
                    /* try { // try from 00795320 to 00795327 has its CatchHandler @ 00795364 */
          std::operator<<((ostream *)aoStack_194,(string *)aAStack_1ec);
                    /* try { // try from 00795338 to 0079533f has its CatchHandler @ 007953d8 */
          std::string::~string((string *)aAStack_1ec);
                    /* try { // try from 00795350 to 00795357 has its CatchHandler @ 0079544c */
          std::string::~string(asStack_200);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_204);
                    /* try { // try from 007953c4 to 007953cb has its CatchHandler @ 007954f0 */
          std::string::~string(asStack_1f8);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_1fc);
                    /* try { // try from 00795438 to 0079543f has its CatchHandler @ 00795574 */
          std::string::~string(asStack_1f0);
          std::allocator<char>::~allocator((allocator<char> *)aaStack_1f4);
                    /* try { // try from 007954dc to 007954e3 has its CatchHandler @ 0079577c */
          poStack_30 = std::operator<<((ostream *)aoStack_194," ");
                    /* try { // try from 00795560 to 007955e3 has its CatchHandler @ 0079577c */
          pcVar12 = (char *)GetRcEngine::RcGetString(0xcf9);
          std::operator<<(poStack_30,pcVar12);
          std::ostringstream::str();
                    /* try { // try from 007955f8 to 007955ff has its CatchHandler @ 0079565c */
          std::string::operator=((string *)PopUpManager::yesNoBoxData,asStack_208);
                    /* try { // try from 00795610 to 0079564f has its CatchHandler @ 0079577c */
          std::string::~string(asStack_208);
          PopUpManager::yesNoBoxData._8_4_ = 1000;
          PopUpManager::yesNoBoxData._12_4_ = 0x1c2;
          PopUpManager::yesNoBoxData._28_4_ = 1;
          pcVar12 = (char *)GetRcEngine::RcGetString(0xca8);
                    /* try { // try from 007956a8 to 0079574b has its CatchHandler @ 0079577c */
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar12);
          pcVar12 = (char *)GetRcEngine::RcGetString(0xc66);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar12);
          pcVar12 = (char *)GetRcEngine::RcGetString(0x106c);
          std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar12);
          PopUpManager::yesNoBoxData._4_4_ = 0;
          PopUpManager::handleBackInPopUp = 1;
          PopUpManager::timeout = 0;
          PopUpManager::parentFrame = param_1;
          PopUpManager::Summon(3);
          *(undefined4 *)(param_1 + 0x5e0) = 5;
                    /* try { // try from 00795768 to 0079576f has its CatchHandler @ 00795be4 */
          std::ostringstream::~ostringstream(aoStack_194);
        }
      }
      std::vector<AR_EPG_EVENT_TIMER_INFO,std::allocator<AR_EPG_EVENT_TIMER_INFO>>::~vector
                (avStack_1e0);
      return 1;
    }
    if ((*(int *)(param_1 + 0x5e0) == 1) || (*(int *)(param_1 + 0x5e0) == 2)) {
      return 0;
    }
    if (*(int *)(param_1 + 0x5b0) == 0) {
      return 1;
    }
    if ((*(int *)(param_1 + 0x5ac) == *(int *)(param_1 + 0x5a8)) &&
       (iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::size
                           ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c)),
       iVar11 != 0)) {
      iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5ac));
      cVar4 = *(char *)(iVar11 + 4);
      iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5a8));
      if (cVar4 == *(char *)(iVar11 + 4)) {
        iStack_5c = 1;
        goto LAB_00795d2c;
      }
    }
    iStack_5c = 0;
LAB_00795d2c:
    if (iStack_5c != 0) {
      MWnd::GetParentApp();
      MApplet::Kill();
      ArProgramInfoApp::KillAPP();
      return 1;
    }
    if (*(int *)(param_1 + 0x5a8) != *(int *)(param_1 + 0x5ac)) {
      piVar13 = (int *)MSrv_Control::GetInstance();
      iVar11 = (**(code **)(*piVar13 + 0x84))(piVar13);
      if (iVar11 == 0x1c) {
        iStack_64 = MSrv_Control_TV::GetMSrvDtv(0);
        if (iStack_64 == 0) {
          iStack_60 = 0;
        }
        else {
          iStack_60 = __dynamic_cast(iStack_64,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        if (iStack_60 != 0) {
          MSrv_DTV_Player_DVB::RecordProgChangeEvent(iStack_60,0,0,0);
        }
      }
      iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5ac));
      uVar2 = *(ushort *)(iVar11 + 2);
      iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5ac));
      uVar1 = *(uchar *)(iVar11 + 4);
      iVar11 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::operator[]
                         ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c),
                          *(uint *)(param_1 + 0x5ac));
      cVar4 = ArChannelManager::SelectChannel((uint)uVar2,uVar1,*(uchar *)(iVar11 + 5),'\x01');
      if (cVar4 != '\0') {
        *(undefined4 *)(param_1 + 0x5a8) = *(undefined4 *)(param_1 + 0x5ac);
        ArChannelListFrame::RefreshChannelList(param_1);
      }
      return 1;
    }
    return 1;
  }
  if (param_3 != 0xf014) {
    if (param_3 < 0xf015) {
      if (param_3 == 0xf003) {
        if (*(int *)(param_1 + 0x5e0) != 3) {
          if (*(int *)(param_1 + 0x5c4) == 1) {
            MWidget::Hide();
            *(undefined4 *)(param_1 + 0x5c4) = 0;
            ArChannelListFrame::RefreshChannelList(param_1);
          }
          return 1;
        }
        uVar17 = *(uint *)(param_1 + 0x5ec);
        uVar7 = std::vector<OPData,std::allocator<OPData>>::size
                          ((vector<OPData,std::allocator<OPData>> *)(param_1 + 0x5c8));
        if (uVar17 < uVar7) {
          *(int *)(param_1 + 0x5ec) = *(int *)(param_1 + 0x5ec) + 1;
        }
        return 0;
      }
    }
    else if (param_3 == 0xf01b) {
      if (*(int *)(param_1 + 0x5e0) == 3) {
        return 1;
      }
      if ((*(int *)(param_1 + 0x5e0) == 0) && (*(int *)(param_1 + 0x5c4) != 2)) {
        piVar13 = (int *)MSrv_Control::GetInstance();
        iVar11 = (**(code **)(*piVar13 + 0x84))(piVar13);
        if ((iVar11 == 0x1c) && (iVar11 = ArChannelManager::GetChannelCount(1), iVar11 != 0)) {
          iStack_cc = 1;
        }
        else {
          iStack_cc = 0;
        }
        if (iStack_cc != 0) {
          MWnd::GetParentApp();
          MApplet::Kill();
          ArProgramInfoApp::KillAPP();
          uVar15 = IdleAppFrame::GetIdleAppFrame();
          MEvtHandle::PostEvent((MEvtHandle *)param_1,uVar15,0x14,0xf01b);
          return 1;
        }
      }
    }
    else if (param_3 == 0xf042) {
      if (*(int *)(param_1 + 0x5e0) == 3) {
        if (*(int *)(param_1 + 0x5ec) == 0) {
          return 1;
        }
        PopUpManager::Clean();
        pcVar12 = (char *)GetRcEngine::RcGetString(0x10f3);
        std::allocator<char>::allocator();
                    /* try { // try from 00798374 to 0079837b has its CatchHandler @ 007986bc */
        std::string::string(asStack_2cc,pcVar12,aaStack_2d0);
        std::allocator<char>::allocator();
                    /* try { // try from 007983b4 to 007983bb has its CatchHandler @ 007985d0 */
        std::string::string(asStack_2d4,"[name]",aaStack_2d8);
        psVar14 = (string *)
                  std::vector<OPData,std::allocator<OPData>>::operator[]
                            ((vector<OPData,std::allocator<OPData>> *)(param_1 + 0x5c8),
                             *(int *)(param_1 + 0x5ec) - 1);
                    /* try { // try from 00798400 to 00798407 has its CatchHandler @ 0079851c */
        std::string::string(asStack_2dc,psVar14);
                    /* try { // try from 00798428 to 0079842f has its CatchHandler @ 0079846c */
        ArUIManager::ReplaceString(aAStack_198,asStack_2cc,asStack_2d4,asStack_2dc);
                    /* try { // try from 00798440 to 00798447 has its CatchHandler @ 007984e0 */
        std::string::~string(asStack_2dc);
                    /* try { // try from 00798458 to 0079845f has its CatchHandler @ 00798594 */
        std::string::~string(asStack_2d4);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_2d8);
                    /* try { // try from 007984cc to 007984d3 has its CatchHandler @ 00798680 */
        std::string::~string(asStack_2cc);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_2d0);
                    /* try { // try from 00798580 to 00798587 has its CatchHandler @ 007987e4 */
        std::string::operator=((string *)PopUpManager::yesNoBoxData,(string *)aAStack_198);
        PopUpManager::yesNoBoxData._4_4_ = 0x234;
        PopUpManager::yesNoBoxData._8_4_ = 700;
        PopUpManager::yesNoBoxData._12_4_ = 0x1b8;
        PopUpManager::yesNoBoxData._28_4_ = 1;
                    /* try { // try from 0079866c to 00798673 has its CatchHandler @ 007987e4 */
        pcVar12 = (char *)GetRcEngine::RcGetString(0xd41);
                    /* try { // try from 00798710 to 007987b3 has its CatchHandler @ 007987e4 */
        std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x10),pcVar12);
        pcVar12 = (char *)GetRcEngine::RcGetString(0xe39);
        std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x18),pcVar12);
        pcVar12 = (char *)GetRcEngine::RcGetString(0x106c);
        std::string::operator=((string *)(PopUpManager::yesNoBoxData + 0x14),pcVar12);
        PopUpManager::yesNoBoxData._4_4_ = 0;
        PopUpManager::handleBackInPopUp = 1;
        PopUpManager::timeout = 0;
        PopUpManager::parentFrame = param_1;
        PopUpManager::Summon(3);
        *(undefined4 *)(param_1 + 0x5e0) = 4;
        std::string::~string((string *)aAStack_198);
      }
      else {
        iStack_c8 = MSrv_Control_TV::GetMSrvDtv(0);
        if (iStack_c8 == 0) {
          uStack_c4 = 0;
        }
        else {
          uStack_c4 = __dynamic_cast(iStack_c8,&DAT_2da86f20,&DAT_2d5d5108,0);
        }
        iVar11 = MSrv_DTV_Player_DVB::_IsRecordingExceptPTimeshift();
        if (iVar11 != 0) {
          uVar6 = ArChannelManager::GetSatFilterID();
          if (param_1[0x5e4] == (ArChannelListFrame)0x0) {
            *(undefined4 *)(param_1 + 0x5e8) = 0xb;
            ArChannelManager::GetChannelInfos
                      (param_1 + 0x59c,param_1 + 0x5ac,0,*(undefined4 *)(param_1 + 0x5e8),uVar6);
            param_1[0x5e4] = (ArChannelListFrame)0x1;
            HelpWidget::ShowButton(*(HelpWidget **)(param_1 + 0x2c0),0,0xc0f);
            if ((*(int *)(param_1 + 0x5e8) < 7) || (10 < *(int *)(param_1 + 0x5e8))) {
              uVar10 = *(undefined4 *)(param_1 + 0x2a8);
              ArChannelListFrame::FilterTypeToStringID(param_1,*(undefined4 *)(param_1 + 0x5e8));
              MString::Set((short)uVar10 + 0x170);
            }
            else {
              iVar11 = *(int *)(param_1 + 0x2a8);
              uVar10 = ArChannelManager::getInstance();
              ArChannelManager::GetFavName(asStack_2e4,uVar10,*(int *)(param_1 + 0x5e8) + -7);
                    /* try { // try from 00798bb4 to 00798bbb has its CatchHandler @ 00798be0 */
              MString::Set((string *)(iVar11 + 0x170));
              std::string::~string(asStack_2e4);
            }
            MWidget::Invalidate();
            HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
          }
          else {
            uVar10 = ArChannelManager::GetChannelListMode();
            *(undefined4 *)(param_1 + 0x5e8) = uVar10;
            ArChannelManager::GetChannelInfos
                      (param_1 + 0x59c,param_1 + 0x5ac,0,*(undefined4 *)(param_1 + 0x5e8),uVar6);
            param_1[0x5e4] = (ArChannelListFrame)0x0;
            HelpWidget::ShowButton(*(HelpWidget **)(param_1 + 0x2c0),0,0xf00);
            if ((*(int *)(param_1 + 0x5e8) < 7) || (10 < *(int *)(param_1 + 0x5e8))) {
              uVar10 = *(undefined4 *)(param_1 + 0x2a8);
              ArChannelListFrame::FilterTypeToStringID(param_1,*(undefined4 *)(param_1 + 0x5e8));
              MString::Set((short)uVar10 + 0x170);
            }
            else {
              iVar11 = *(int *)(param_1 + 0x2a8);
              uVar10 = ArChannelManager::getInstance();
              ArChannelManager::GetFavName(asStack_2e0,uVar10,*(int *)(param_1 + 0x5e8) + -7);
                    /* try { // try from 007989c8 to 007989cf has its CatchHandler @ 007989f4 */
              MString::Set((string *)(iVar11 + 0x170));
              std::string::~string(asStack_2e0);
            }
            MWidget::Invalidate();
            HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2c0));
          }
          if (*(int *)(param_1 + 0x5ac) == -1) {
            *(undefined4 *)(param_1 + 0x5ac) = 0;
          }
          *(undefined4 *)(param_1 + 0x5a8) = *(undefined4 *)(param_1 + 0x5ac);
          uVar10 = std::vector<ChannelInfo,std::allocator<ChannelInfo>>::size
                             ((vector<ChannelInfo,std::allocator<ChannelInfo>> *)(param_1 + 0x59c));
          *(undefined4 *)(param_1 + 0x5b0) = uVar10;
          *(undefined4 *)(param_1 + 0x5c4) = 0;
          ArChannelListFrame::RefreshChannelList(param_1);
          ArChannelListFrame::RefreshProgramGuideList(param_1,*(long *)(param_1 + 0x5ac));
          *(undefined4 *)(param_1 + 0x5e0) = 0;
        }
      }
      return 1;
    }
    return 0;
  }
  if (*(int *)(param_1 + 0x5e0) == 3) {
    return 1;
  }
  iVar11 = ArChannelManager::IsCurrentAntennaTypeRecording();
  if (iVar11 == 0) {
    pAVar16 = (ArTvManager *)ArTvManager::getInstance();
    iVar11 = ArTvManager::GetDualWatchStatus(pAVar16);
    if (iVar11 == 1) goto LAB_00798f98;
    iStack_d0 = 0;
  }
  else {
LAB_00798f98:
    iStack_d0 = 1;
  }
  if (iStack_d0 != 0) {
    return 1;
  }
  ArServiceSettingsManager::getInstance();
  iVar11 = ArServiceSettingsManager::ArSystemConf_GetHotel();
  if (iVar11 == 0) {
LAB_00799030:
    iStack_d4 = 0;
  }
  else {
    ArTvSettingsManager::getInstance();
    iVar11 = ArTvSettingsManager::GetHotelAdmin();
    if (iVar11 != 0) goto LAB_00799030;
    iStack_d4 = 1;
  }
  if (iStack_d4 != 0) {
    return 1;
  }
  ArTvSettingsManager::getInstance();
  iVar11 = ArTvSettingsManager::GetMenuLock();
  if (iVar11 != 0) {
    pAVar16 = (ArTvManager *)ArTvManager::getInstance();
    iVar11 = ArTvManager::IsParentalUnlocked(pAVar16);
    if (iVar11 == 0) {
      iStack_d8 = 1;
      goto LAB_007990bc;
    }
  }
  iStack_d8 = 0;
LAB_007990bc:
  if (iStack_d8 == 0) {
    MWnd::GetParentApp();
    MApplet::Kill();
    ArProgramInfoApp::KillAPP();
    pAVar16 = (ArTvManager *)ArTvManager::getInstance();
    ArTvManager::LockParental(pAVar16);
    pCStack_dc = operator_new(0x3c,(nothrow_t *)&DAT_2c7f5bd0);
    if (pCStack_dc != (ChannelEditorApp *)0x0) {
                    /* try { // try from 007991b4 to 007991bb has its CatchHandler @ 007991d0 */
      ChannelEditorApp::ChannelEditorApp(pCStack_dc);
    }
    pCStack_e0 = pCStack_dc;
    if (pCStack_dc == (ChannelEditorApp *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00feeb6c,&UNK_00feee28,0xd27);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    MApplet::Run((ulong)pCStack_dc,(void *)0x0);
  }
  else {
    PopUpManager::Clean();
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(0xe,0xc42);
    PopUpManager::Summon(6);
  }
  return 1;
}

