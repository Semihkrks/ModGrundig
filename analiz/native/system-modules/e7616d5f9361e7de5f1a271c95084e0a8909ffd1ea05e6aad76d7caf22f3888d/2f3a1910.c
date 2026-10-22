
void _MDrv_CPU_InitEnd(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  (*(code *)PTR_HAL_COPRO_Init_End_2f3b2c88)();
  puVar1 = PTR_DAT_2f3b2c08;
  *(undefined4 *)(PTR_DAT_2f3b2c08 + 0x2d54) = param_1;
  puVar2 = PTR_DAT_2f3b2c08;
  puVar1[0x2d50] = 1;
  puVar2[0x2d58] = 0;
  return;
}

