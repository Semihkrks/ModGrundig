
undefined4 MDrv_PWS_PHYPower(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_socket_2f513db4)(2,1,0);
  if (-1 < iVar1) {
    if (param_1 == 0) {
      iVar2 = (*(code *)PTR_ioctl_2f513db8)(iVar1,0x89f2);
      if (iVar2 == 0) {
LAB_2f501980:
        (*(code *)PTR_close_2f513d84)(iVar1);
        return 1;
      }
      (*(code *)PTR_close_2f513d84)(iVar1);
    }
    else {
      iVar2 = (*(code *)PTR_ioctl_2f513db8)(iVar1,0x89f1);
      if (iVar2 == 0) goto LAB_2f501980;
      (*(code *)PTR_close_2f513d84)(iVar1);
    }
  }
  return 0;
}

