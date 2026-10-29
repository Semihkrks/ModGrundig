
/* MW_DVB_SI_PSI_Parser_Customer::_SatelliteSkipService(MW_DVB_PROGRAM_INFO&) */

bool __thiscall
MW_DVB_SI_PSI_Parser_Customer::_SatelliteSkipService
          (MW_DVB_SI_PSI_Parser_Customer *this,MW_DVB_PROGRAM_INFO *param_1)

{
  if (*(int *)(this + 0x170) == 2) {
    if (param_1[0xe] == (MW_DVB_PROGRAM_INFO)0x7) {
      return true;
    }
    if (param_1[0xe] == (MW_DVB_PROGRAM_INFO)0x3) {
      return 0xf < ((byte)param_1[0xd] ^ 0x80);
    }
  }
  return false;
}

