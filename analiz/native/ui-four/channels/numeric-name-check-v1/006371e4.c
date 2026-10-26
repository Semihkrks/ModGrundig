
/* ArChannelManager::Check_ProgramSelectByNumber(unsigned short) */

undefined4 ArChannelManager::Check_ProgramSelectByNumber(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  ushort uStack_24;
  uchar uStack_22;
  uchar uStack_21;
  EN_ROUTE_STATUS aEStack_20 [12];
  int iStack_14;
  int iStack_10;
  
  iVar1 = IsAnySourceRecording();
  if (iVar1 != 0) {
    iStack_14 = MSrv_Control_common::GetMSrvChannelManager();
    if (iStack_14 == 0) {
      iStack_10 = 0;
    }
    else {
      iStack_10 = __dynamic_cast(iStack_14,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
    }
    if (iStack_10 != 0) {
      iVar1 = MSrv_ChannelManager_DVB_Customer::GetProgramSelInfo
                        ((ushort)iStack_10,(ushort *)param_1,(uchar *)&uStack_24,&uStack_22);
      if (iVar1 == 0) {
        puts(
            "\n@@@ ArChannelManager::Check_ProgramSelectByNumber can not get program selection info. @@@\n\n"
            );
        return 0;
      }
      uVar2 = ArPvrManager::CheckRouteForProgChange(uStack_24,uStack_22,uStack_21,aEStack_20);
      return uVar2;
    }
  }
  return 1;
}

