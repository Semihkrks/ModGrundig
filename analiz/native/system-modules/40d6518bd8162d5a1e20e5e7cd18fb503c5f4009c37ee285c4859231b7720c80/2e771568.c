
/* MW_AutoTest_DVB_SI::Init(MW_DTV_AVMonitor*, MW_DTV_CM_DVB*, MW_DVB_SI_PSI_Parser*,
   MW_DTV_EPG_DVB*, MW_DTV_CM_DB<_DVB_PROGRAMINFO, _DVB_MUXINFO, _ST_DVB_SAT_INFO,
   _ST_DVB_NETWORK_INFO>*) */

void __thiscall
MW_AutoTest_DVB_SI::Init
          (MW_AutoTest_DVB_SI *this,MW_DTV_AVMonitor *param_1,MW_DTV_CM_DVB *param_2,
          MW_DVB_SI_PSI_Parser *param_3,MW_DTV_EPG_DVB *param_4,MW_DTV_CM_DB *param_5)

{
  *(MW_DTV_AVMonitor **)(this + 0x18) = param_1;
  *(MW_DVB_SI_PSI_Parser **)(this + 0x10) = param_3;
  *(MW_DTV_CM_DVB **)(this + 0x14) = param_2;
  *(MW_DTV_CM_DB **)(this + 0xc) = param_5;
  *(MW_DTV_EPG_DVB **)(this + 4) = param_4;
  return;
}

