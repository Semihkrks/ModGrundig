
undefined4 MDrv_GPIO_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_2f413708;
  if (param_1 == 1) {
    PTR_DAT_2f413708[0x3780] = 0;
    *(undefined4 *)(puVar1 + 0x36d0) = 1;
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f413708 + 0x36d0) != 1) {
      (*(code *)PTR_printf_2f413730)
                (PTR___DT_MIPS_BASE_ADDRESS_2f413714 + 0x1e5c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f413714 + 0x1eac,0x1b1);
      return 3;
    }
    (*(code *)PTR_mdrv_gpio_init_2f413734)();
    uVar2 = 1;
    *(undefined4 *)(puVar1 + 0x36d0) = 2;
  }
  else {
    (*(code *)PTR_printf_2f413730)
              (PTR___DT_MIPS_BASE_ADDRESS_2f413714 + 0x1e94,
               PTR___DT_MIPS_BASE_ADDRESS_2f413714 + 0x1eac,0x1b7,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

