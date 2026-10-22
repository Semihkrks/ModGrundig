
/* CommonFrame::EnableBubbleHelp() */

void __thiscall CommonFrame::EnableBubbleHelp(CommonFrame *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined3 extraout_var;
  BubbleHelpFrame *this_00;
  ulong uStack_54;
  __normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
  a_Stack_44 [4];
  __normal_iterator a_Stack_40 [4];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  BubbleHelpApp *pBStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  ArServiceSettingsManager::getInstance();
  iVar2 = ArServiceSettingsManager::ArTvConf_GetBubbleHelp();
  if (iVar2 != 0) {
    ArTvSettingsManager::getInstance();
    iVar2 = ArTvSettingsManager::GetBubbleHelp();
    if (iVar2 != 0) {
      iStack_18 = 0;
      goto LAB_008d1d18;
    }
  }
  iStack_18 = 1;
LAB_008d1d18:
  if (((iStack_18 == 0) && (iVar2 = BubbleHelpFrame::GetBubbleHelpFrame(), iVar2 == 0)) &&
     (*(int *)(this + 0x3c) != 0)) {
    iVar2 = MSystem::GetInstance();
    if (iVar2 == 0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2830,0x235);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    iVar2 = MSystem::GetMWindowManager();
    if (iVar2 == 0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2830,0x237);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    iStack_20 = MWindowManager::GetFocusedApp();
    if ((iStack_20 == 0) ||
       (iVar2 = __dynamic_cast(iStack_20,&MApplet::typeinfo,&IdleAppApp::typeinfo,0), iVar2 == 0)) {
      iStack_1c = 0;
    }
    else {
      iStack_1c = 1;
    }
    if (iStack_1c == 0) {
      iStack_28 = MWindowManager::GetFocusedApp();
      if ((iStack_28 == 0) ||
         (iVar2 = __dynamic_cast(iStack_28,&MApplet::typeinfo,&PictureAdjustApp::typeinfo,0),
         iVar2 == 0)) {
        iStack_24 = 0;
      }
      else {
        iStack_24 = 1;
      }
      if (iStack_24 == 0) {
        iStack_30 = MWindowManager::GetFocusedApp();
        if ((iStack_30 == 0) ||
           (iVar2 = __dynamic_cast(iStack_30,&MApplet::typeinfo,&PopUpManagerApp::typeinfo,0),
           iVar2 == 0)) {
          iStack_2c = 0;
        }
        else {
          iStack_2c = 1;
        }
        if (iStack_2c == 0) {
          iVar2 = MWidget::GetID();
          uStack_54 = 0x380;
          iVar3 = std::vector<bubblehelppair,std::allocator<bubblehelppair>>::size
                            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(this + 0x10c)
                            );
          if (iVar3 != 0) {
            __gnu_cxx::
            __normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
            ::__normal_iterator((__normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
                                 *)&uStack_3c);
            std::vector<bubblehelppair,std::allocator<bubblehelppair>>::begin();
            uStack_3c = uStack_38;
            while( true ) {
              std::vector<bubblehelppair,std::allocator<bubblehelppair>>::end();
              bVar1 = __gnu_cxx::operator!=((__normal_iterator *)&uStack_3c,a_Stack_40);
              if (CONCAT31(extraout_var,bVar1) == 0) break;
              piVar4 = (int *)__gnu_cxx::
                              __normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
                              ::operator->((__normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
                                            *)&uStack_3c);
              if (*piVar4 == iVar2) {
                iVar3 = __gnu_cxx::
                        __normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
                        ::operator->((__normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
                                      *)&uStack_3c);
                uStack_54 = *(ulong *)(iVar3 + 4);
              }
              __gnu_cxx::
              __normal_iterator<bubblehelppair*,std::vector<bubblehelppair,std::allocator<bubblehelppair>>>
              ::operator++(a_Stack_44,(int)&uStack_3c);
            }
          }
          if (uStack_54 != 0x380) {
            pBStack_34 = operator_new(0x3c);
                    /* try { // try from 008d20dc to 008d20e3 has its CatchHandler @ 008d2104 */
            BubbleHelpApp::BubbleHelpApp(pBStack_34);
            if (pBStack_34 == (BubbleHelpApp *)0x0) {
              printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff27d4,&UNK_00ff2830,0x254);
                    /* WARNING: Subroutine does not return */
              abort();
            }
            MApplet::Run((ulong)pBStack_34,(void *)0x1000);
            this_00 = (BubbleHelpFrame *)BubbleHelpFrame::GetBubbleHelpFrame();
            BubbleHelpFrame::Update(this_00,uStack_54);
          }
        }
      }
    }
  }
  return;
}

