
undefined4 MDrv_PWM_Init(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [2];
  
  puVar2 = PTR_MDrv_PWM_SetDbgLevel_2f4f5ce4;
  puVar1 = PTR_DAT_2f4f5c68;
  *(undefined4 *)(PTR_DAT_2f4f5c68 + 0x5de4) = param_1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14[0] = 0;
  (*(code *)puVar2)();
  if (puVar1[0x5de0] != '\0') {
    return 0;
  }
  iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f4f5d3c)(&local_20,local_14,0x1032);
  if (((iVar3 != 0) &&
      (iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f4f5d3c)(&local_1c,local_14,0x11), iVar3 != 0)) &&
     (iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f4f5d3c)(&local_18,local_14,300), iVar3 != 0)) {
    (*(code *)PTR_HAL_PWM_SetIOMapBase_2f4f5cf4)(local_20,local_18);
    (*(code *)PTR_HAL_PWM_SetChipTopIOMapBase_2f4f5ce0)(local_1c);
    iVar3 = (*(code *)PTR_HAL_PWM_Init_2f4f5d7c)();
    if (iVar3 != 0) {
      (*(code *)PTR_MDrv_SEM_Init_2f4f5da8)();
      puVar1[0x5de0] = 1;
      return 0;
    }
  }
  return 1;
}

