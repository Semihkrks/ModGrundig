
/* ArChannelManager::SelectChannelByNumber(unsigned long, unsigned char) */

undefined1 ArChannelManager::SelectChannelByNumber(ulong param_1,uchar param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  ArTvManager *pAVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined1 uStack_90;
  ChannelInfo aCStack_8c [4];
  char cStack_88;
  int iStack_28;
  int iStack_20;
  int iStack_1c;
  
  uStack_90 = 0;
  iStack_20 = MSrv_Control_common::GetMSrvChannelManager();
  if (iStack_20 == 0) {
    iStack_1c = 0;
  }
  else {
    iStack_1c = __dynamic_cast(iStack_20,&MSrv_ChannelManager::typeinfo,&DAT_2e1e0f78,0);
  }
  iVar1 = iStack_1c;
  if (iStack_1c == 0) {
    return 0;
  }
  piVar2 = (int *)MSrv_Control::GetInstance();
  iVar3 = (**(code **)(*piVar2 + 0x84))(piVar2);
  if ((iVar3 != 1) && (iVar3 != 0x1c)) {
    iVar3 = IgnoreChannelChange(iVar3);
    if (iVar3 == 0) {
      pAVar4 = (ArTvManager *)ArTvManager::getInstance();
      if (pAVar4 != (ArTvManager *)0x0) {
        uVar6 = ArTvManager::GetCurrentDvbAntennaType();
        ArTvManager::SetAntennaSource(pAVar4,uVar6);
        iVar3 = Check_ProgramSelectByNumber((ushort)param_1);
        if (iVar3 == 0) {
          puts(
              "\n@@@ ArChannelManager::SelectChannelByNumber is blocked by Check_ProgramSelectByNumber @@@"
              );
          return 0;
        }
        uStack_90 = MSrv_ChannelManager_DVB_Customer::ProgramSel((ushort)iVar1);
      }
    }
    else {
      puts("\n\n Do Nothing! \n");
    }
    goto LAB_0063f548;
  }
  iVar3 = Check_ProgramSelectByNumber((ushort)param_1);
  if (iVar3 == 0) {
    puts(
        "\n@@@ ArChannelManager::SelectChannelByNumber is blocked by Check_ProgramSelectByNumber @@@"
        );
    return 0;
  }
  FUN_0062e630(aCStack_8c);
                    /* try { // try from 0063f30c to 0063f3cb has its CatchHandler @ 0063f3f8 */
  GetCurrentChannelInfo(aCStack_8c,'\0');
  if (cStack_88 == '\x02') {
LAB_0063f35c:
    iStack_28 = 1;
  }
  else {
    ArTvManager::getInstance();
    iVar3 = ArTvManager::GetCurrentDvbAntennaType();
    if (iVar3 == 2) goto LAB_0063f35c;
    iStack_28 = 0;
  }
  if (iStack_28 != 0) {
    piVar2 = (int *)mapi_interface_common::Get_mapi_audio();
    (**(code **)(*piVar2 + 0x24))(piVar2,0x14);
  }
  uStack_90 = MSrv_ChannelManager_DVB_Customer::ProgramSel((ushort)iVar1);
  FUN_0062e214(aCStack_8c);
LAB_0063f548:
  if (param_2 != '\0') {
    ArProgramInfoApp::Summon(3,'\x01','\x01');
  }
  uVar5 = getInstance();
  MEvtHandle::KillTimer(uVar5);
  uVar6 = getInstance();
  MEvtHandle::SetTimer(uVar6,5000,0,1);
  return uStack_90;
}

