
void MDrv_COPRO_Init_Front(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_pInstantCpu_2f3b2c90;
  if (*(int *)PTR_pInstantCpu_2f3b2c90 != 0) {
    (*(code *)PTR_UtopiaClose_2f3b2c40)();
    *(undefined4 *)puVar1 = 0;
  }
  (*(code *)PTR__MDrv_CPU_InitFront_2f3b2c38)();
  return;
}

