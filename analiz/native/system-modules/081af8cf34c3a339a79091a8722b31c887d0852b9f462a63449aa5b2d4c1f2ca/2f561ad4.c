
bool MDrv_SC_PowerOff(void)

{
  int iVar1;
  undefined4 local_10;
  undefined1 auStack_c [8];
  
  iVar1 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f5785b4)(&local_10,auStack_c,0);
  if (iVar1 != 0) {
    (*(code *)PTR_HAL_SC_HW_RegMap_2f578534)(local_10);
    (*(code *)PTR_HAL_SC_PowerCtrl_2f578610)(0,0);
  }
  return iVar1 != 0;
}

