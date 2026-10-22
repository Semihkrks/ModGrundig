
/* MW_DTV_Scan_DVBT::_ScanInitFreqTableStatus_AU() */

void __thiscall MW_DTV_Scan_DVBT::_ScanInitFreqTableStatus_AU(MW_DTV_Scan_DVBT *this)

{
  int iVar1;
  
  (*(code *)PTR_SetCurrentBandwidth_2ee76354)(*(undefined4 *)(this + 0xa4),2);
  iVar1 = (*(code *)PTR_GetBandwidthMode_2ee766c4)(*(undefined4 *)(this + 0xa4));
  if (iVar1 != 3) {
    iVar1 = (*(code *)PTR_GetBandwidthMode_2ee766c4)(*(undefined4 *)(this + 0xa4));
    if (iVar1 != 2) {
      iVar1 = (*(code *)PTR_GetBandwidthMode_2ee766c4)(*(undefined4 *)(this + 0xa4));
      if (iVar1 != 1) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x2ee57284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_SetCurrentBandwidth_2ee76354)(*(undefined4 *)(this + 0xa4),3);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x2ee57228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_SetCurrentBandwidth_2ee76354)(*(undefined4 *)(this + 0xa4),2);
  return;
}

