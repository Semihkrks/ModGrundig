
/* MSrv_ChannelManager_DVB_Customer::GetProgramInfo(EN_PROG_INFO_TYPE, ST_CM_PROGRAM_INFO*) */

void __thiscall
MSrv_ChannelManager_DVB_Customer::GetProgramInfo
          (MSrv_ChannelManager_DVB_Customer *this,int param_2,undefined4 param_3)

{
  if (param_2 != 8) {
    MSrv_ChannelManager_DVB::GetProgramInfo();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x2e157e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x114))(this,param_3,0);
  return;
}

