
undefined4 FUN_00fc1d18(ZappMenuFrame *param_1,undefined4 param_2,uint param_3)

{
  ZappMenuFrame ZVar1;
  ZappMenuFrame ZVar2;
  ArTvManager *pAVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  MEvtHandle *pMVar7;
  undefined1 auStack_1b4 [100];
  undefined1 auStack_150 [100];
  undefined1 auStack_ec [100];
  ChannelInfo aCStack_88 [8];
  string asStack_80 [96];
  undefined4 uStack_20;
  uint uStack_1c;
  
  FUN_00fbe9fc(aCStack_88);
                    /* try { // try from 00fc1d70 to 00fc231f has its CatchHandler @ 00fc29a8 */
  ArChannelManager::getInstance();
  ArChannelManager::GetCurrentChannelInfo(aCStack_88,'\0');
  pAVar3 = (ArTvManager *)ArTvManager::getInstance();
  ZVar1 = (ZappMenuFrame)ArTvManager::GetCurrentInputSourceType(pAVar3);
  pAVar3 = (ArTvManager *)ArTvManager::getInstance();
  iVar4 = ArTvManager::GetSpecificSourceIndex(pAVar3);
  ArTvManager::getInstance();
  ZVar2 = (ZappMenuFrame)ArTvManager::GetDtvRoute();
  uStack_1c = param_3;
  if (param_3 == 0xf042) goto LAB_00fc2740;
  if (param_3 < 0xf043) {
    if (param_3 != 0xf011) {
      if (param_3 < 0xf012) {
        if (param_3 < 0x3a) {
          if (0x2f < param_3) {
LAB_00fc2814:
            param_1[0x20c] = (ZappMenuFrame)0x0;
            goto LAB_00fc281c;
          }
          if (param_3 == 0xd) {
LAB_00fc2904:
            param_1[0x20c] = (ZappMenuFrame)0x0;
            goto LAB_00fc290c;
          }
        }
        else if (0xefff < param_3) {
          if (param_3 < 0xf004) goto LAB_00fc2814;
          if (param_3 == 0xf00a) goto LAB_00fc2740;
        }
        goto LAB_00fc299c;
      }
      if (param_3 != 0xf019) {
        if (param_3 < 0xf01a) {
          if (param_3 == 0xf012) goto LAB_00fc267c;
          if (param_3 != 0xf014) goto LAB_00fc299c;
LAB_00fc281c:
          iVar4 = ArProgramInfoFrame::GetInstance();
          if (iVar4 == 0) {
            pMVar7 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
            uVar6 = IdleAppFrame::GetIdleAppFrame();
            MEvtHandle::PostEvent(pMVar7,uVar6,0x14,param_3);
            uStack_20 = 1;
          }
          else {
            param_1[0x20c] = (ZappMenuFrame)0x0;
            pMVar7 = (MEvtHandle *)ArProgramInfoFrame::GetInstance();
            uVar6 = ArProgramInfoFrame::GetInstance();
            MEvtHandle::PostEvent(pMVar7,uVar6,0x14,param_3);
            uStack_20 = 1;
          }
          goto LAB_00fc29f0;
        }
        if ((param_3 != 0xf020) && (param_3 != 0xf037)) {
          if (param_3 == 0xf01b) goto LAB_00fc2740;
          goto LAB_00fc299c;
        }
      }
    }
  }
  else {
    if (param_3 < 0xf05d) {
      if ((param_3 < 0xf05b) && (param_3 != 0xf049)) {
        if (param_3 < 0xf04a) {
          if (param_3 - 0xf046 < 2) goto LAB_00fc2814;
        }
        else if ((0xf050 < param_3) && ((param_3 < 0xf053 || (param_3 == 0xf056))))
        goto LAB_00fc2740;
LAB_00fc299c:
        uStack_20 = 0;
      }
      else {
LAB_00fc2740:
        iVar4 = MWnd::GetParentApp();
        if (iVar4 == 0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd94,0xe5);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        MApplet::Kill();
        pMVar7 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
        uVar6 = IdleAppFrame::GetIdleAppFrame();
        MEvtHandle::PostEvent(pMVar7,uVar6,0x14,param_3);
        uStack_20 = 1;
      }
      goto LAB_00fc29f0;
    }
    if (param_3 != 0xf06a) {
      if (param_3 < 0xf06b) {
        if (param_3 == 0xf062) {
LAB_00fc267c:
          iVar4 = ArProgramInfoFrame::GetInstance();
          if (iVar4 == 0) {
            iVar4 = MWnd::GetParentApp();
            if (iVar4 == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd94,0xd0);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Kill();
            uStack_20 = 1;
          }
          else {
                    /* try { // try from 00fc26a0 to 00fc2987 has its CatchHandler @ 00fc29a8 */
            ArProgramInfoApp::KillAPP();
            uStack_20 = 1;
          }
          goto LAB_00fc29f0;
        }
        if (param_3 == 0xf068) goto LAB_00fc2904;
      }
      else if (param_3 == 0xf075) {
        ArTvPlayer::getInstance();
        iVar5 = ArTvPlayer::getTeletextKeyStatus();
        if (iVar5 == 0) {
          uStack_20 = 1;
          goto LAB_00fc29f0;
        }
        iVar5 = ArProgramInfoFrame::GetInstance();
        if (iVar5 != 0) {
          ArProgramInfoApp::KillAPP();
          uStack_20 = 1;
          goto LAB_00fc29f0;
        }
        if ((param_1[0x200] == (ZappMenuFrame)0x0) || (param_1[0x200] == (ZappMenuFrame)0x1)) {
          iVar5 = std::operator==(asStack_80,(string *)(param_1 + 0x1a4));
          if (iVar5 != 0) {
            iVar4 = MWnd::GetParentApp();
            if (iVar4 == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd94,0x83);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Kill();
            uStack_20 = 1;
            goto LAB_00fc29f0;
          }
          if (ZVar2 != param_1[0x201]) {
            if ((param_1[0x201] == (ZappMenuFrame)0x1) || (param_1[0x201] == (ZappMenuFrame)0x20)) {
              pAVar3 = (ArTvManager *)ArTvManager::getInstance();
              ArTvManager::SetDtvRoute(pAVar3,1);
            }
            else if (param_1[0x201] == (ZappMenuFrame)0x2) {
              pAVar3 = (ArTvManager *)ArTvManager::getInstance();
              ArTvManager::SetDtvRoute(pAVar3,2);
            }
            else if ((param_1[0x201] == (ZappMenuFrame)0x4) ||
                    (param_1[0x201] == (ZappMenuFrame)0x40)) {
              pAVar3 = (ArTvManager *)ArTvManager::getInstance();
              ArTvManager::SetDtvRoute(pAVar3,3);
            }
            param_1[0x201] = ZVar2;
          }
          FUN_00fbed54(auStack_ec,aCStack_88);
                    /* try { // try from 00fc2340 to 00fc2347 has its CatchHandler @ 00fc2370 */
          ZappMenuFrame::SetZappChannel(param_1,auStack_ec,ZVar1,iVar4);
                    /* try { // try from 00fc235c to 00fc2363 has its CatchHandler @ 00fc29a8 */
          FUN_00fbe710(auStack_ec);
        }
        else if ((param_1[0x200] == (ZappMenuFrame)0x5) && ((byte)param_1[0x200] < 10)) {
          if ((ZVar1 == param_1[0x200]) && (*(int *)(param_1 + 0x204) == iVar4)) {
                    /* try { // try from 00fc240c to 00fc24a3 has its CatchHandler @ 00fc29a8 */
            iVar4 = MWnd::GetParentApp();
            if (iVar4 == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd94,0xa8);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Kill();
            uStack_20 = 1;
            goto LAB_00fc29f0;
          }
          FUN_00fbed54(auStack_150,aCStack_88);
                    /* try { // try from 00fc24c4 to 00fc24cb has its CatchHandler @ 00fc24f4 */
          ZappMenuFrame::SetZappChannel(param_1,auStack_150,ZVar1,iVar4);
                    /* try { // try from 00fc24e0 to 00fc24e7 has its CatchHandler @ 00fc29a8 */
          FUN_00fbe710(auStack_150);
        }
        else {
          if (ZVar1 == param_1[0x200]) {
                    /* try { // try from 00fc2554 to 00fc25eb has its CatchHandler @ 00fc29a8 */
            iVar4 = MWnd::GetParentApp();
            if (iVar4 == 0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd94,0xb7);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Kill();
            uStack_20 = 1;
            goto LAB_00fc29f0;
          }
          FUN_00fbed54(auStack_1b4,aCStack_88);
                    /* try { // try from 00fc260c to 00fc2613 has its CatchHandler @ 00fc263c */
          ZappMenuFrame::SetZappChannel(param_1,auStack_1b4,ZVar1,iVar4);
                    /* try { // try from 00fc2628 to 00fc262f has its CatchHandler @ 00fc29a8 */
          FUN_00fbe710(auStack_1b4);
        }
      }
      else {
        if (param_3 == 0xf077) goto LAB_00fc2740;
        if (param_3 == 0xf070) goto LAB_00fc290c;
      }
      goto LAB_00fc299c;
    }
  }
LAB_00fc290c:
  uVar6 = MWnd::GetParentApp();
  MApplet::Hide(uVar6);
  pMVar7 = (MEvtHandle *)IdleAppFrame::GetIdleAppFrame();
  uVar6 = IdleAppFrame::GetIdleAppFrame();
  MEvtHandle::PostEvent(pMVar7,uVar6,0x14,param_3);
  uStack_20 = 1;
LAB_00fc29f0:
  FUN_00fbe710(aCStack_88);
  return uStack_20;
}

