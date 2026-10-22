
undefined4 MApi_SWI2C_SetPowerState(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_2f333968;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f333968 + 0x38f4) = 1;
    return 2;
  }
  if (param_1 == 2) {
    if (*(int *)(PTR_DAT_2f333968 + 0x38f4) != 1) {
      return 3;
    }
    (*(code *)PTR_MApi_SWI2C_Init_2f333990)(PTR_DAT_2f333968 + 0x3ad8,PTR_DAT_2f333968[0x39f0]);
    uVar2 = 1;
    *(undefined4 *)(puVar1 + 0x38f4) = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

