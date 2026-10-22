
void MDrv_JPD_PowerOff(void)

{
  (*(code *)PTR_HAL_JPD_PowerOff_2ed332c8)();
  PTR_DAT_2ed33248[0x35ee] = 0;
  return;
}

