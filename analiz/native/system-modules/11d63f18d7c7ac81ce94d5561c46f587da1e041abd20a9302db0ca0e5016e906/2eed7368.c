
void MApi_XC_ACE_EX_DNR_Init_Luma(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = *(undefined4 *)PTR_pu32ACEInst_2eeeb7f0;
  }
  else {
    uVar2 = *(undefined4 *)PTR_pu32ACEInst_1_2eeeb804;
  }
  iVar1 = (*(code *)PTR_UtopiaIoctl_2eeeb6fc)(uVar2,0x33,0);
  if (iVar1 != 0) {
    (*(code *)PTR_puts_2eeeb5bc)(PTR_DAT_2eeeb4b8 + -0x51e8);
  }
  return;
}

