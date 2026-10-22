
void HAL_COPRO_Init_End(void)

{
  (*(code *)PTR_HAL_COPRO_Enable_2f3b2c70)();
  (*(code *)PTR_MsOS_EnableInterrupt_2f3b2ce8)(0x28);
  return;
}

