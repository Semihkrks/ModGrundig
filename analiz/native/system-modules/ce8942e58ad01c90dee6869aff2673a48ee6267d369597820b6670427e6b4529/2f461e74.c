
undefined4 MDrv_IR_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined1 auStack_1010 [4100];
  
  puVar1 = PTR_DAT_2f4723b8;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f4723b8 + 0x2380) = 1;
    return 0;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f4723b8 + 0x2380) != 1) {
      (*(code *)PTR_printf_2f4723f4)
                (PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x22d4,
                 PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x2344,0x4b6);
      return 1;
    }
    (*(code *)PTR_MDrv_IR_Init_2f4723fc)(auStack_1010);
    *(undefined4 *)(puVar1 + 0x2380) = 2;
    return 0;
  }
  (*(code *)PTR_printf_2f4723f4)
            (PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x230c,
             PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x2344,0x4bc,param_1);
  return 1;
}

