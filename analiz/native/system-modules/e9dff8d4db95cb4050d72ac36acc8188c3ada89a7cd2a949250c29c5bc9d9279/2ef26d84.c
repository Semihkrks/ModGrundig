
undefined4 MDrv_GE_Chip_Proprity_Init(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    (*(code *)PTR_GE_Chip_Proprity_Init_2ef4c3a4)(param_1 + 0x3c);
    *param_2 = *(undefined4 *)(param_1 + 0x40);
    return 1;
  }
  (*(code *)PTR_printf_2ef4c208)(PTR_DAT_2ef4c098 + -0x5bfc,PTR_DAT_2ef4c098 + -0x58a0,0xf24);
  return 0;
}

