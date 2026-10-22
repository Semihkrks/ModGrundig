
/* MSrv_ChannelManager_DVB_Customer::_CompareFav2(ST_CM_SERVICE_QUERY, ST_CM_SERVICE_QUERY) */

bool MSrv_ChannelManager_DVB_Customer::_CompareFav2(int param_1,int param_2)

{
  return *(ushort *)(param_1 + 0xc) < *(ushort *)(param_2 + 0xc);
}

