
void MDrv_JPD_PowerOff(void)

{
  (*(code *)PTR_HAL_JPD_PowerOff_00026d70)();
  PTR_DAT_00026d38[0x6eae] = 0;
  return;
}

