
/* MW_DTV_SORTING_DVB_Customer::HasServiceCollidedLCN(_DVB_PROGRAMINFO*) */

uint MW_DTV_SORTING_DVB_Customer::HasServiceCollidedLCN(_DVB_PROGRAMINFO *param_1)

{
  return ((byte)param_1[0x28] & 0x3f) >> 5;
}

