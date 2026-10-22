
void _MDrv_CPU_InitFront(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_MDrv_COPRO_GetBase_2f3b2c64)();
  if (iVar2 != 0) {
    (*(code *)PTR_HAL_COPRO_Init_Front_2f3b2d0c)();
    puVar1 = PTR_DAT_2f3b2c08;
    PTR_DAT_2f3b2c08[0x2d50] = 0;
    puVar1[0x2d58] = 0;
  }
  return;
}

