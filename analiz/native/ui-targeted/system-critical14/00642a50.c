
/* ArSoftwareUpdateManager::StartOADUpgrade() */

undefined4 ArSoftwareUpdateManager::StartOADUpgrade(void)

{
  int iVar1;
  int *piStack_c;
  
  iVar1 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iVar1 == 0) {
    piStack_c = (int *)0x0;
  }
  else {
    piStack_c = (int *)__dynamic_cast(iVar1,&DAT_2da86f20,&DAT_2d5d5108,0);
  }
  (**(code **)(*piStack_c + 0x610))(piStack_c);
  return 1;
}

