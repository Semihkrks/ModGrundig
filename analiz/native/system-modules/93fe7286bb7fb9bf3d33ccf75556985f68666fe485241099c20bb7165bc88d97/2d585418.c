
/* WARB_W_FTA_R_Scramble::ChannelChange_CheckCIConflict(_DVB_PROGRAMINFO*) */

bool __thiscall
WARB_W_FTA_R_Scramble::ChannelChange_CheckCIConflict
          (WARB_W_FTA_R_Scramble *this,_DVB_PROGRAMINFO *param_1)

{
  return param_1[0x14] != (_DVB_PROGRAMINFO)0x0;
}

