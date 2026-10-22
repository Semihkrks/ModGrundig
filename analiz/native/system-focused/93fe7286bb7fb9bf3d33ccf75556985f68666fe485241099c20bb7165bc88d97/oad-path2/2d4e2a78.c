
/* MSrv_DTV_Player_DVB::OAD_CheckAfterWakeUp() */

undefined4 __thiscall MSrv_DTV_Player_DVB::OAD_CheckAfterWakeUp(MSrv_DTV_Player_DVB *this)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x2b8) != 0) {
    iVar1 = __dynamic_cast(*(int *)(this + 0x2b8),&MSrv_DTV_DVB_OAD::typeinfo,
                           &MSrv_DTV_DVB_OAD_Customer::typeinfo,0);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2d4e2ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = MSrv_DTV_DVB_OAD_Customer::OAD_CheckAfterWakeUp();
      return uVar2;
    }
  }
  return 0;
}

