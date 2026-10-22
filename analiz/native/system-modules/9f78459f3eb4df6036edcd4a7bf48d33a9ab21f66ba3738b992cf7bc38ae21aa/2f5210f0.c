
void MDrv_RTC_DeInit(undefined4 param_1)

{
  (*(code *)PTR_HAL_RTC_RESET_2f532c88)(param_1,0);
  (*(code *)PTR_HAL_RTC_Counter_2f532d18)(param_1,0);
  return;
}

