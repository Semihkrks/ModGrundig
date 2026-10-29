
/* MW_DTV_CM_DVB::_IsProgramListable(_DVB_PROGRAMINFO const&) */

bool __thiscall MW_DTV_CM_DVB::_IsProgramListable(MW_DTV_CM_DVB *this,_DVB_PROGRAMINFO *param_1)

{
  if (((param_1[0x15] != (_DVB_PROGRAMINFO)0x1) && (param_1[0x11] != (_DVB_PROGRAMINFO)0x1)) &&
     (param_1[0xf] == (_DVB_PROGRAMINFO)0x1)) {
    return param_1[0x10] == (_DVB_PROGRAMINFO)0x1;
  }
  return false;
}

