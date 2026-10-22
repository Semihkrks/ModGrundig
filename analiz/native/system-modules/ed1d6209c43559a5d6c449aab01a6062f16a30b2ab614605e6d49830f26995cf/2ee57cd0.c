
/* MW_DTV_Scan_DVBT::HandleEvent_AutoUpdateScan(MW_DVBT_ScanInfo const&) */

undefined4 __thiscall
MW_DTV_Scan_DVBT::HandleEvent_AutoUpdateScan(MW_DTV_Scan_DVBT *this,MW_DVBT_ScanInfo *param_1)

{
  undefined4 uVar1;
  
  (*(code *)PTR_puts_2ee7608c)(PTR_s_v_DTV_Player_DVBT_DoNewFrontEnd_2ee60b70_0x10_2ee75d68 + 0x8d4)
  ;
  uVar1 = *(undefined4 *)(this + 8);
  if (*(int *)(param_1 + 8) != 2) {
    if (*(int *)(param_1 + 8) == 3) {
      *(undefined4 *)(this + 0xbc) = uVar1;
      uVar1 = 6;
    }
    return uVar1;
  }
  return 0x18;
}

