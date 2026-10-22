
/* MSrv_DTV_Player_DVBC::EnableChannelFrontEnd(_DVB_PROGRAMINFO const&) */

undefined4 __thiscall
MSrv_DTV_Player_DVBC::EnableChannelFrontEnd(MSrv_DTV_Player_DVBC *this,_DVB_PROGRAMINFO *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [56];
  
  iVar1 = (**(code **)(**(int **)(this + 0x108) + 0x74))(*(int **)(this + 0x108),param_1,auStack_48)
  ;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*(int *)this + 0x850))(this,auStack_48);
    return uVar2;
  }
  (*(code *)PTR_printf_2edf48ec)
            (PTR_typeinfo_name_2edf4558 + -0x1420,PTR_typeinfo_name_2edf4558 + -0x13f4,
             PTR_typeinfo_name_2edf4558 + -0xe50,0x17e,0);
  return 0;
}

