
undefined4 FUN_00cf58d8(int param_1)

{
  ArTvSettingsManager *this;
  
  this = (ArTvSettingsManager *)ArTvSettingsManager::getInstance();
  ArTvSettingsManager::SetFastZapping
            (this,(uchar)*(undefined4 *)(*(int *)(param_1 + 0x244) + 0x264));
  return 1;
}

