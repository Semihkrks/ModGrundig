
undefined4 BrickTerminatorInfo_init(void)

{
  *(undefined4 *)(PTR_DAT_00021068 + 0x10f0) = 0;
  (*(code *)PTR_MDrv_MMIO_Init_000210b4)();
  (*(code *)PTR_MDrv_MIU_SetIOMapBase_000210c8)();
  (*(code *)PTR_MsOS_Init_00021098)();
  (*(code *)PTR_mdrv_gpio_init_00021094)();
  (*(code *)PTR_MDrv_SYS_Init_000210cc)();
  return 0;
}

