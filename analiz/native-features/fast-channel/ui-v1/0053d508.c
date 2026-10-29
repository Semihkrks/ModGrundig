
/* ArTvSettingsManager::SetFastZapping(unsigned char) */

void __thiscall ArTvSettingsManager::SetFastZapping(ArTvSettingsManager *this,uchar param_1)

{
  uchar uVar1;
  int iVar2;
  int iStack_c;
  
  uVar1 = MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::SetFastZapping(uVar1);
  iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iVar2 == 0) {
    iStack_c = 0;
  }
  else {
    iStack_c = __dynamic_cast(iVar2,&DAT_2da86f20,&DAT_2d5d5108,0);
  }
  if (iStack_c != 0) {
    MSrv_DTV_Player_DVB::SetFastZapping((uchar)iStack_c);
  }
  return;
}

