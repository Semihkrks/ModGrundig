
/* ArSoftwareUpdateManager::ManuelOadScan() */

undefined4 ArSoftwareUpdateManager::ManuelOadScan(void)

{
  bool bVar1;
  uchar uVar2;
  ST_OAD_SETTINGS *pSVar3;
  int *piVar4;
  int iVar5;
  undefined4 uStack_20;
  undefined1 uStack_17;
  
  pSVar3 = (ST_OAD_SETTINGS *)MSrv_Control_common::GetMSrvSystemDatabase();
  MSrv_System_Database::GetOadDownInfo(pSVar3);
  piVar4 = (int *)MSrv_Control::GetInstance();
  uVar2 = (**(code **)(*piVar4 + 0x1b8))(piVar4,0);
  iVar5 = MSrv_Control_common::GetRouteTVMode(uVar2);
  if (iVar5 != 1) {
    piVar4 = (int *)MSrv_Control::GetInstance();
    uVar2 = (**(code **)(*piVar4 + 0x1b8))(piVar4,0);
    iVar5 = MSrv_Control_common::GetRouteTVMode(uVar2);
    if (iVar5 != 0x20) {
      piVar4 = (int *)MSrv_Control::GetInstance();
      uVar2 = (**(code **)(*piVar4 + 0x1b8))(piVar4,0);
      iVar5 = MSrv_Control_common::GetRouteTVMode(uVar2);
      if (iVar5 != 0x80) {
        bVar1 = false;
        goto LAB_00643220;
      }
    }
  }
  bVar1 = true;
LAB_00643220:
  if (bVar1) {
    piVar4 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
    (**(code **)(*piVar4 + 0xf8))(piVar4,uStack_17);
  }
  else {
    piVar4 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
    (**(code **)(*piVar4 + 0xf4))(piVar4,uStack_20);
  }
  return 1;
}

