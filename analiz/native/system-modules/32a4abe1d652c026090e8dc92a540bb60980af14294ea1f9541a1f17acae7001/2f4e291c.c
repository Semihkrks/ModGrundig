
undefined4 MDrv_PWM_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_2f4f5c68;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f4f5c68 + 0x5c30) = 1;
    puVar1[0x5de0] = 0;
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f4f5c68 + 0x5c30) != 1) {
      (*(code *)PTR_printf_2f4f5d0c)
                (PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5700,
                 PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5774,0x331);
      return 3;
    }
    (*(code *)PTR_MDrv_PWM_Init_2f4f5cec)(*(undefined4 *)(PTR_DAT_2f4f5c68 + 0x5de4));
    uVar2 = 1;
    *(undefined4 *)(puVar1 + 0x5c30) = 2;
  }
  else {
    (*(code *)PTR_printf_2f4f5d0c)
              (PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5738,
               PTR___DT_MIPS_BASE_ADDRESS_2f4f5c74 + 0x5774,0x337,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

