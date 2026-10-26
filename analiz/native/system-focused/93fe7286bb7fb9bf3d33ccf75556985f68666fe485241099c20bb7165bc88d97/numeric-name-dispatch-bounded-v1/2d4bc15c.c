
/* MSrv_ChannelManager_DVB::GetProgramInfo(EN_PROG_INFO_TYPE, ST_CM_PROGRAM_INFO*) */

undefined4
MSrv_ChannelManager_DVB::GetProgramInfo(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0:
                    /* WARNING: Could not recover jumptable at 0x2d4bc1e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xdc))(param_1,param_3);
    return uVar1;
  case 1:
  case 5:
                    /* WARNING: Could not recover jumptable at 0x2d4bc1a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xe4))(param_1,param_3);
    return uVar1;
  case 2:
  case 6:
                    /* WARNING: Could not recover jumptable at 0x2d4bc1bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xe0))(param_1,param_3);
    return uVar1;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x2d4bc20c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xe8))(param_1,param_3);
    return uVar1;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x2d4bc1d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xec))(param_1,param_3);
    return uVar1;
  case 7:
                    /* WARNING: Could not recover jumptable at 0x2d4bc1f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xf0))(param_1,param_3);
    return uVar1;
  default:
    return 0;
  }
}

