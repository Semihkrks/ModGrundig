
void mdrv_gpio_init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR___gpio_2f413748;
  PTR_DAT_2f413708[0x3780] = 1;
  puVar2 = PTR_MDrv_GPIO_SetIOMapBase_2f413764;
  *(undefined **)(PTR_DAT_2f413708 + 0x3788) = puVar1;
  (*(code *)puVar2)();
  (*(code *)PTR_HAL_GPIO_Interrupt_Init_2f413754)();
  return;
}

