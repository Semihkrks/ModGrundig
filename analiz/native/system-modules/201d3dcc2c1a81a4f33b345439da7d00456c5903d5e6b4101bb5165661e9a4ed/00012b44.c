
void MDrv_JPD_PowerOn(void)

{
  (*(code *)PTR_HAL_JPD_InitRegBase_00026dd4)();
  (*(code *)PTR_HAL_JPD_PowerOn_00026de8)();
  PTR_DAT_00026d38[0x6eae] = 1;
  return;
}

