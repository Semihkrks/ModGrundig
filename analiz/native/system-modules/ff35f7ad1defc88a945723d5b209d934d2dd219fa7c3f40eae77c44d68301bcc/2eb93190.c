
/* MSrv_ATV_Player::SetChannelSearchType(MSrv_ATV_Player::EN_CHANNEL_SEARCH_TYPE) */

undefined4 __thiscall
MSrv_ATV_Player::SetChannelSearchType(MSrv_ATV_Player *this,undefined4 param_2)

{
  *(undefined4 *)(this + 0xd8) = param_2;
  return 1;
}

