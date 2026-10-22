
void HAL_COPRO_Init_Front(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_HAL_COPRO_RegReadByte_2f3b2cc0)(0xff0);
  (*(code *)PTR_HAL_COPRO_RegWriteByte_2f3b2cdc)(0xff0,uVar1 & 0xfc);
  (*(code *)PTR_HAL_COPRO_Disable_2f3b2c58)();
  (*(code *)PTR_HAL_COPRO_RegWriteByte_2f3b2cdc)(0x33de,1);
  return;
}

