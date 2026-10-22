
void _MDrv_DDC2BI_init_riu_base(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c [2];
  
  local_10 = 0;
  local_c[0] = 0;
  iVar1 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f3d1920)(&local_10,local_c,300);
  if (iVar1 != 1) {
    (*(code *)PTR_puts_2f3d18f0)(PTR___DT_MIPS_BASE_ADDRESS_2f3d18c4 + 0x1854);
    return;
  }
  (*(code *)PTR_mhal_DDC2BI_init_riu_base_2f3d192c)(local_10,local_10);
  return;
}

