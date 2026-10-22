
/* MW_DTV_FrontEnd_DVBS_Customer::UpdateSingleCablePassword(unsigned char, unsigned char) */

undefined4 __thiscall
MW_DTV_FrontEnd_DVBS_Customer::UpdateSingleCablePassword
          (MW_DTV_FrontEnd_DVBS_Customer *this,uchar param_1,uchar param_2)

{
  this[0xd9] = (MW_DTV_FrontEnd_DVBS_Customer)param_2;
  this[0xd8] = (MW_DTV_FrontEnd_DVBS_Customer)param_1;
  return 1;
}

