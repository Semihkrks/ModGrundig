
/* MW_DTV_Scan_DVBT_Customer::_AutoUpdateStoreCurrentProgInfo(unsigned short, unsigned short,
   unsigned short) */

void __thiscall
MW_DTV_Scan_DVBT_Customer::_AutoUpdateStoreCurrentProgInfo
          (MW_DTV_Scan_DVBT_Customer *this,ushort param_1,ushort param_2,ushort param_3)

{
  *(ushort *)(this + 0xdc) = param_3;
  *(ushort *)(this + 0xda) = param_1;
  *(ushort *)(this + 0xd8) = param_2;
  return;
}

