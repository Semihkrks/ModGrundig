
undefined4 MDrv_PWS_SetPowerState(int param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_2f513d18;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f513d18 + 0x3cd0) = 1;
    puVar1[0x3e40] = 0;
    return 0;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f513d18 + 0x3cd0) != 1) {
      (*(code *)PTR_printf_2f513d94)
                (PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x3054,
                 PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x30f4,0x197);
      return 1;
    }
    (*(code *)PTR_MDrv_PWS_Init_2f513e10)(*(undefined4 *)(PTR_DAT_2f513d18 + 0x3e44));
    *(undefined4 *)(puVar1 + 0x3cd0) = 2;
    return 0;
  }
  (*(code *)PTR_printf_2f513d94)
            (PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x309c,
             PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x30f4,0x19e,param_1);
  return 1;
}

