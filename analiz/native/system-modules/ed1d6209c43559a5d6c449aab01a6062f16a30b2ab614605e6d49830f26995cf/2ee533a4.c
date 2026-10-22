
/* MSrv_DTV_Player_DVBT::EnableChannelFrontEnd(_DVB_PROGRAMINFO const&) */

undefined4 __thiscall
MSrv_DTV_Player_DVBT::EnableChannelFrontEnd(MSrv_DTV_Player_DVBT *this,_DVB_PROGRAMINFO *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [60];
  
  iVar1 = (**(code **)(**(int **)(this + 0x108) + 0x74))(*(int **)(this + 0x108),param_1,auStack_48)
  ;
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*(int *)this + 0x850))(this,auStack_48);
  }
  return uVar2;
}

