
/* MSrv_ATV_Player::TunerSetMedium(unsigned char) */

void __thiscall MSrv_ATV_Player::TunerSetMedium(MSrv_ATV_Player *this,uchar param_1)

{
  *(uint *)(this + 0xfc) = (uint)param_1;
  return;
}

