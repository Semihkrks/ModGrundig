
ushort Hal_DVI_GetPowerSavingStatus(void)

{
  return *(ushort *)(*(int *)PTR__XC_RIU_BASE_2de2979c + 0x226c00) & 1;
}

