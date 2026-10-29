
/* MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO, _DVB_MUXINFO, _ST_DVB_SAT_INFO,
   _ST_DVB_NETWORK_INFO>::GetByLcn(unsigned short) */

int __thiscall
MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO,_DVB_MUXINFO,_ST_DVB_SAT_INFO,_ST_DVB_NETWORK_INFO>::GetByLcn
          (MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO,_DVB_MUXINFO,_ST_DVB_SAT_INFO,_ST_DVB_NETWORK_INFO>
           *this,ushort param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(this + 4);
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    return 0;
  }
  do {
    iVar2 = iVar1 + 0x1a4;
    if (*(ushort *)(iVar1 + 0x34) == param_1) {
      return iVar1;
    }
    iVar1 = iVar2;
  } while (iVar2 != *(int *)(this + 8));
  return 0;
}

