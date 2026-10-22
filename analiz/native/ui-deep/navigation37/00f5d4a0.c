
undefined4 FUN_00f5d4a0(ToolsMenuFrame *param_1)

{
  int iVar1;
  int iVar2;
  ArTvManager *pAVar3;
  
  iVar1 = Container::GetFocusedWdgIdx();
  iVar2 = ScrollListContainer::GetChildIdx(*(MWidget **)(param_1 + 0x1bc));
  if (iVar1 == iVar2) {
    ToolsMenuFrame::OpenSourceSelectionPopup(param_1);
    puts("\n\n\n\n                     Dual_Watch_On                     \n\n\n");
  }
  else {
    iVar1 = Container::GetFocusedWdgIdx();
    iVar2 = ScrollListContainer::GetChildIdx(*(MWidget **)(param_1 + 0x1bc));
    if (iVar1 == iVar2) {
      pAVar3 = (ArTvManager *)ArTvManager::getInstance();
      ArTvManager::SetDualWatchStatus(pAVar3,0,0x17);
      ArVideoManager::getInstance();
      ArVideoManager::DisableDualView();
      puts("\n\n\n\n                     Dual_Watch_Off                     \n\n\n");
      iVar1 = MWnd::GetParentApp();
      if (iVar1 == 0) {
        printf("ASSERT FAIL: %s %s %d\n",&UNK_0100b820,&UNK_0100bb7c,0xe2c);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      MApplet::Kill();
    }
    else {
      iVar1 = Container::GetFocusedWdgIdx();
      iVar2 = ScrollListContainer::GetChildIdx(*(MWidget **)(param_1 + 0x1bc));
      if (iVar1 == iVar2) {
        ArAudioManager::getInstance();
        ArAudioManager::SwapAudioContentsDualWatch();
        puts("\n\n\n\n                     Dual_Watch_Swap                     \n\n\n");
        iVar1 = MWnd::GetParentApp();
        if (iVar1 == 0) {
          printf("ASSERT FAIL: %s %s %d\n",&UNK_0100b820,&UNK_0100bb7c,0xe36);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        MApplet::Kill();
      }
      else {
        puts("\n\n\n\n                     None!                     \n\n\n");
      }
    }
  }
  return 1;
}

