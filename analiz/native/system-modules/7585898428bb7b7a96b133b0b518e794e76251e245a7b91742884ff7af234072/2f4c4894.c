
void MDrv_PM_Rtc_DisableInit(undefined1 param_1)

{
  int iVar1;
  
  do {
    iVar1 = (*(code *)PTR_MDrv_SEM_Get_Resource_2f4d612c)(4,3);
  } while (iVar1 == 0);
  (*(code *)PTR_HAL_PM_RTC_DisableInit_2f4d60dc)(param_1);
  (*(code *)PTR_MDrv_SEM_Free_Resource_2f4d6084)(4,3);
  return;
}

