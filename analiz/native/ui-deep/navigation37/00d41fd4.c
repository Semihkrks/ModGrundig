
undefined4 FUN_00d41fd4(void *param_1,void *param_2,int param_3)

{
  ArTvManager *this;
  
  if (param_3 == 0) {
    this = (ArTvManager *)ArTvManager::getInstance();
    ArTvManager::UnlockParental(this);
    if (*(int *)((int)param_1 + 0x3c) == *(int *)((int)param_1 + 0x1c0)) {
      HomePageFrame::OnKey(param_1,param_2,(void *)0xd);
    }
  }
  return 1;
}

