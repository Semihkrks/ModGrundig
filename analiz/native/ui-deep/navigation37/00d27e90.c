
undefined4 FUN_00d27e90(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  ulong uVar2;
  
  if (param_4 == 0x2a) {
    if (param_3 == 1) {
      ArChannelManager::SetFilterType(1,0);
    }
    else if (param_3 == 2) {
      ArChannelManager::SetFilterType(2,0);
    }
    else if (param_3 == 0) {
      ArChannelManager::SetFilterType(0,0);
    }
  }
  else if (param_3 == 0) {
    ArServiceSettingsManager::getInstance();
    cVar1 = ArServiceSettingsManager::ArTvConf_GetMiracastTx();
    if (cVar1 != '\0') {
      uVar2 = MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::openMenu(uVar2,'\f',(void *)0x0);
    }
  }
  return 1;
}

