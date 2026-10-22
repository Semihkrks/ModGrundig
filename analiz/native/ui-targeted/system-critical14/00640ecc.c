
/* ArASUManager::_StartStandbyUpdate(unsigned long&) */

undefined1 __thiscall ArASUManager::_StartStandbyUpdate(ArASUManager *this,ulong *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 uStack_34;
  int *piStack_2c;
  int *piStack_20;
  int *piStack_14;
  
  uStack_34 = 0;
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar2 = MSrv_System_Database::GetAutoServiceUpdate();
  if (iVar2 == 0) {
    piVar3 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    iVar2 = (**(code **)(*piVar3 + 0x160))(piVar3);
    if (iVar2 != 0) goto LAB_00640f6c;
    bVar1 = true;
  }
  else {
LAB_00640f6c:
    bVar1 = false;
  }
  if (bVar1) {
    MSrv_Control_common::GetMSrvSystemDatabase();
    uVar4 = MSrv_System_Database::GetAutoServiceUpdate();
    printf(" \nsystem_setting.u8AutoServiceUpdates = %d, return here...",uVar4);
    MSrv_Control_common::GetMSrvSystemDatabase();
    uVar4 = MSrv_System_Database::GetAutoServiceUpdate();
    printf("\nsystem_setting.fSoftwareUpdate = %d, return here...",uVar4);
    return 0;
  }
  iVar2 = MSrv_Control_common::GetMSrvTimer();
  if (iVar2 == 0) {
    piStack_14 = (int *)0x0;
  }
  else {
    piStack_14 = (int *)__dynamic_cast(iVar2,&DAT_2da87e48,&DAT_2e028238,0);
  }
  if (piStack_14 != (int *)0x0) {
    iVar2 = (**(code **)(*piStack_14 + 0x58))(piStack_14,0x4b0);
    if (iVar2 != 0) {
      puts("\n@@@ _StartStandbyUpdate: There is scheduled item. Do not start ASU/SSU @@@");
      return 0;
    }
    iVar2 = MSrv_Timer_Customer::IsOnTimerExist((ulong)piStack_14);
    if (iVar2 != 0) {
      puts("\n@@@ _StartStandbyUpdate: There is On Timer. Do not start ASU/SSU @@@");
      return 0;
    }
  }
  if ((*param_1 & 1) == 0) {
    piVar3 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar3 + 0x84))(piVar3);
    if (iVar2 != 0x1c) goto LAB_006411e4;
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar2 = MSrv_System_Database::GetAutoServiceUpdate();
    if ((iVar2 == 0) || (iVar2 = MSrv_Control::GetInstance(), *(char *)(iVar2 + 0x174) != '\0'))
    goto LAB_006411e4;
    bVar1 = true;
  }
  else {
LAB_006411e4:
    bVar1 = false;
  }
  iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iVar2 == 0) {
    piStack_20 = (int *)0x0;
  }
  else {
    piStack_20 = (int *)__dynamic_cast(iVar2,&DAT_2da86f20,&DAT_2d5d5108,0);
  }
  if (piStack_20 == (int *)0x0) {
    puts("\n@@ _StartStandbyUpdate MSrv_DTV_Player_DVB is null @@@");
    return 0;
  }
  iVar2 = (**(code **)(*piStack_20 + 0x710))(piStack_20);
  if (iVar2 != 0) {
    puts("\n@@ _StartStandbyUpdate CI Op Mode is available, so do not start ASU @@");
    bVar1 = false;
  }
  if (bVar1) {
    puts("\x1b[0;31m[_StartStandbyUpdate]:starting asu\x1b[0m");
    iVar2 = MSrv_DTV_Player_DVB::OADIsSheduledOadExists((ulong)piStack_20);
    if (iVar2 != 0) {
      puts("[_StartStandbyUpdate]:There is schedule accepted OAD. So turn of asu");
      iVar2 = (**(code **)(*piStack_20 + 0x604))(piStack_20);
      if (iVar2 == 1) {
        piVar3 = (int *)MSrv_Control::GetInstance();
        (**(code **)(*piVar3 + 0xcc))(piVar3,1);
      }
      return 0;
    }
    printf("\x1b[0;33m[%s:%d] STANDBY UPDATE \x1b[0m\n",&UNK_00fec90c,0xf1);
    iVar2 = (**(code **)(*piStack_20 + 0xe4))(piStack_20);
    if (iVar2 == 0) {
      return 0;
    }
    printf("\x1b[0;33m[%s:%d] STANDBY UPDATE \x1b[0m\n",&UNK_00fec90c,0xf5);
    *param_1 = *param_1 | 1;
    return 1;
  }
  if ((*param_1 & 4) == 0) {
    iVar2 = MSrv_Control_TV::GetMSrvDtv(0);
    if (iVar2 == 0) {
      piStack_2c = (int *)0x0;
    }
    else {
      piStack_2c = (int *)__dynamic_cast(iVar2,&DAT_2da86f20,&DAT_2d5d5108,0);
    }
    iVar2 = (**(code **)(*piStack_2c + 0x604))(piStack_2c);
    if (iVar2 == 1) {
      bVar1 = true;
      goto LAB_006414f4;
    }
  }
  bVar1 = false;
LAB_006414f4:
  if (bVar1) {
    puts("\x1b[0;31m[_StartStandbyUpdate]:starting ssu\x1b[0m");
    piVar3 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
    iVar2 = (**(code **)(*piVar3 + 0xec))(piVar3);
    if (iVar2 != 0) {
      *param_1 = *param_1 | 4;
      uStack_34 = 1;
    }
  }
  else {
    puts("[poweronoff]:nothing to update");
  }
  return uStack_34;
}

