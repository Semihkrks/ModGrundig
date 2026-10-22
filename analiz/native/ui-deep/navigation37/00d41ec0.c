
undefined4 FUN_00d41ec0(void *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  MenuBackgroundFrame *this;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  
  iStack_18 = 0;
  iStack_14 = 0;
  piVar1 = (int *)ArUIManager::getInstance();
  iVar2 = ArUIManager::GetCursorPosition(piVar1,&iStack_18);
  if (iVar2 == 0) {
    uStack_10 = 0;
  }
  else {
    if (iStack_14 < 0x3e9) {
      HomePageFrame::OnKey(param_1,param_2,(void *)0xd);
    }
    else {
      this = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      MenuBackgroundFrame::HandleClickOnHelpbar(this,iStack_18,iStack_14);
    }
    uStack_10 = 1;
  }
  return uStack_10;
}

