
undefined4 MDrv_WDT_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_MDrv_TIMER_Exit_2f5d2680;
  puVar1 = PTR_DAT_2f5d2608;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f5d2608 + 0x25d4) = 1;
    puVar1[0x26c0] = 0;
    (*(code *)puVar2)();
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f5d2608 + 0x25d4) != 1) {
      (*(code *)PTR_printf_2f5d2654)
                (PTR___DT_MIPS_BASE_ADDRESS_2f5d2614 + 0x254c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f5d2614 + 0x259c,0x1bd);
      return 3;
    }
    (*(code *)PTR_MDrv_WDT_Init_2f5d2670)(1);
    (*(code *)PTR_MDrv_TIMER_Init_2f5d2630)();
    uVar3 = 1;
    *(undefined4 *)(puVar1 + 0x25d4) = 2;
  }
  else {
    (*(code *)PTR_printf_2f5d2654)
              (PTR___DT_MIPS_BASE_ADDRESS_2f5d2614 + 0x2584,
               PTR___DT_MIPS_BASE_ADDRESS_2f5d2614 + 0x259c,0x1c3,param_1);
    uVar3 = 0;
  }
  return uVar3;
}

