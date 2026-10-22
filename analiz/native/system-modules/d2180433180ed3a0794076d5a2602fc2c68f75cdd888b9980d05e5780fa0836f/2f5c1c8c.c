
undefined4 MDrv_WDT_Init(undefined4 param_1)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar2 = PTR_DAT_2f5d2608;
  pcVar1 = PTR_DAT_2f5d2608 + 0x26c0;
  *(undefined4 *)(PTR_DAT_2f5d2608 + 0x25d0) = param_1;
  if (*pcVar1 == '\0') {
    local_c = 0;
    local_10 = 0;
    iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f5d2674)(&local_10,&local_c,300);
    if (iVar3 == 0) {
      return 0;
    }
    (*(code *)PTR_HAL_WDT_SetIOMapBase_2f5d266c)(local_10);
    (*(code *)PTR_HAL_WDT_Start_2f5d2648)();
    puVar2[0x26c0] = 1;
  }
  return 1;
}

