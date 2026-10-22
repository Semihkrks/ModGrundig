
bool _mhal_mhl_IsCbusBusy(void)

{
  return (*(ushort *)(*(int *)PTR__XC_RIU_BASE_0003128c + 0x7d74) & 0xf0) != 0;
}

