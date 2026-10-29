
/* MW_DVB_SI_PSI_Parser::_UpdateProgInfoByServiceType(unsigned char, _DVB_PROGRAMINFO*,
   MW_DVB_PROGRAM_INFO*) */

void __thiscall
MW_DVB_SI_PSI_Parser::_UpdateProgInfoByServiceType
          (MW_DVB_SI_PSI_Parser *this,uchar param_1,_DVB_PROGRAMINFO *param_2,
          MW_DVB_PROGRAM_INFO *param_3)

{
  int iVar1;
  
  if (((param_1 == '\f') || (param_1 == '\x10')) &&
     (iVar1 = (**(code **)(*(int *)this + 700))(this,3,this + 0x168,0), iVar1 == 0)) {
    if (param_2 != (_DVB_PROGRAMINFO *)0x0) {
      param_2[0x10] = (_DVB_PROGRAMINFO)0x0;
      param_2[0xf] = (_DVB_PROGRAMINFO)0x0;
    }
    if (param_3 != (MW_DVB_PROGRAM_INFO *)0x0) {
      param_3[3] = (MW_DVB_PROGRAM_INFO)0x0;
      param_3[4] = (MW_DVB_PROGRAM_INFO)0x0;
    }
  }
  if ((param_2 != (_DVB_PROGRAMINFO *)0x0) && (param_2[0x1d] == (_DVB_PROGRAMINFO)0x7)) {
    param_2[0x22] = (_DVB_PROGRAMINFO)0x0;
    param_2[0x10] = (_DVB_PROGRAMINFO)0x0;
    param_2[0xf] = (_DVB_PROGRAMINFO)0x0;
  }
  if ((param_3 != (MW_DVB_PROGRAM_INFO *)0x0) && (param_3[0xe] == (MW_DVB_PROGRAM_INFO)0x7)) {
    param_3[8] = (MW_DVB_PROGRAM_INFO)0x0;
    param_3[3] = (MW_DVB_PROGRAM_INFO)0x0;
    param_3[4] = (MW_DVB_PROGRAM_INFO)0x0;
  }
  return;
}

