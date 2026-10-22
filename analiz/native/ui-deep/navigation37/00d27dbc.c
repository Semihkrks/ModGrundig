
undefined4 FUN_00d27dbc(MEvtHandle *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  ulong uVar1;
  
  if (param_4 == 0x52) {
    uVar1 = MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::openMenu(uVar1,'\0',(void *)0x0);
    uVar1 = IdleAppFrame::GetIdleAppFrame();
    MEvtHandle::PostEvent(param_1,uVar1,0x14,0xf068);
  }
  return 1;
}

