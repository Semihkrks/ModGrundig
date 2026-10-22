
/* MSrv_Control_Customer::GetARCpowerUpTime() */

undefined4 MSrv_Control_Customer::GetARCpowerUpTime(void)

{
  (*(code *)PTR_GetInstance_2f1e3814)();
  return *(undefined4 *)PTR_ARCpowerUpTimeFlag_2f1e383c;
}

