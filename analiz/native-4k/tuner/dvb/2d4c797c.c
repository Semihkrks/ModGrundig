
/* MSrv_DTV_Player_DVB::_CheckFilterType(unsigned char) */

undefined4 __thiscall MSrv_DTV_Player_DVB::_CheckFilterType(MSrv_DTV_Player_DVB *this,uchar param_1)

{
  int iVar1;
  
  if (param_1 == '\0') {
    iVar1 = (**(code **)(*(int *)this + 0x37c))();
    if (iVar1 != 0) {
      puts("\n@@ _CheckFilterType: Program Change fail reset filter type to all @@");
      (**(code **)(*(int *)this + 0x378))(this,0);
      return 0;
    }
  }
  return 1;
}

