
undefined4 FUN_00d9e11c(int param_1)

{
  int iVar1;
  
  iVar1 = ArUIManager::GetAnimationEnabled();
  if (iVar1 != 0) {
    ArUIManager::CloseWithSwipe(*(undefined4 *)(param_1 + 0x184),2,0xfa,100);
    MMainFrame::StartAnimation();
  }
  iVar1 = MSrv_Control_common::GetMSrvPicture();
  if (iVar1 != 0) {
    __dynamic_cast(iVar1,&DAT_2da875b8,&DAT_2e027d30,0);
  }
  MSrv_Picture_Customer::DecreaseMenuLockCounter();
  return 1;
}

