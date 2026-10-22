
/* MW_DTV_FrontEnd_DVBS::UpdateSingleCablePassword(unsigned char, unsigned char) */

undefined4 __thiscall
MW_DTV_FrontEnd_DVBS::UpdateSingleCablePassword
          (MW_DTV_FrontEnd_DVBS *this,uchar param_1,uchar param_2)

{
  this[0x6d] = (MW_DTV_FrontEnd_DVBS)param_2;
  this[0x6c] = (MW_DTV_FrontEnd_DVBS)param_1;
  return 1;
}

