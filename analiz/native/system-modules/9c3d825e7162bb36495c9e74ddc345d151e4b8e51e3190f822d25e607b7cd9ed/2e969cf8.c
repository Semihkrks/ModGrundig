
/* MW_DTV_FrontEnd_DVBS_Customer::FE_LNBPower_Text(MS_EN_LNBPWR_ONOFF) */

undefined * __thiscall
MW_DTV_FrontEnd_DVBS_Customer::FE_LNBPower_Text(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  
  if (6 < param_2) {
    return PTR_s_rviceListInfo_std_vector<std_b_2e980ff8_0x38_2e99d5a8 + 0x4228;
  }
                    /* WARNING: Could not emulate address calculation at 0x2e969d24 */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = (undefined *)
           (*(code *)(&_gp + *(int *)(PTR_s_rviceListInfo_std_vector<std_b_2e980ff8_0x38_2e99d5a8 +
                                     param_2 * 4 + 0x4ca8)))();
  return puVar1;
}

