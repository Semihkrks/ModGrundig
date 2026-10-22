
/* MSrv_ChannelManager_DVB_Customer::_CompareFav1(ST_CM_SERVICE_QUERY, ST_CM_SERVICE_QUERY) */

bool MSrv_ChannelManager_DVB_Customer::_CompareFav1(int param_1,int param_2)

{
  return *(ushort *)(param_1 + 10) < *(ushort *)(param_2 + 10);
}

