
/* MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO, _DVB_MUXINFO, _ST_DVB_SAT_INFO,
   _ST_DVB_NETWORK_INFO>::SaveProgram(_DVB_PROGRAMINFO const&) */

undefined4 __thiscall
MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO,_DVB_MUXINFO,_ST_DVB_SAT_INFO,_ST_DVB_NETWORK_INFO>::SaveProgram
          (MW_DTV_CM_DB_IMPL<_DVB_PROGRAMINFO,_DVB_MUXINFO,_ST_DVB_SAT_INFO,_ST_DVB_NETWORK_INFO>
           *this,_DVB_PROGRAMINFO *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint __n;
  uchar *__s;
  
  __n = (uint)*(ushort *)(this + 0x48);
  iVar3 = *(int *)param_1;
  iVar2 = *(int *)(this + 0x50);
  __s = &stack0xffffffd8 + -(__n + 0xe & 0xfffffff8);
  memset(__s,0,__n);
                    /* try { // try from 2d50ee30 to 2d50eed7 has its CatchHandler @ 2d50eee0 */
  iVar1 = GetSaveData(__s,*(ushort *)(this + 0x48),param_1);
  if (iVar1 == 0) {
    printf("%s:%d,GetSaveData fail.\n",&UNK_2d59cd6c,0x42e);
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0x144))
                      (this,__n * iVar3 + iVar2,__s,*(undefined2 *)(this + 0x48));
    if (iVar1 != 0) {
      return 1;
    }
    printf("%s:%d,pu8Data write data fail.\n",&UNK_2d59cd6c,0x433);
  }
  return 0;
}

