
/* MW_DTV_Scan_DVBC_Customer::HandleEvent_StandbyScan(MW_DVBC_ScanInfo const&) */

undefined4 __thiscall
MW_DTV_Scan_DVBC_Customer::HandleEvent_StandbyScan
          (MW_DTV_Scan_DVBC_Customer *this,MW_DVBC_ScanInfo *param_1)

{
  (*(code *)PTR_puts_2ee36008)(PTR_typeinfo_name_0x10_2ee35cf8 + 0x2c8);
  if (*(int *)(param_1 + 8) != 2) {
    return *(undefined4 *)(this + 8);
  }
  (*(code *)PTR_printf_2ee36088)
            (PTR_typeinfo_name_0x10_2ee35cf8 + 0x2f4,PTR_typeinfo_name_0x10_2ee35cf8 + 0x1ac4,0x2ce)
  ;
  return 0x18;
}

