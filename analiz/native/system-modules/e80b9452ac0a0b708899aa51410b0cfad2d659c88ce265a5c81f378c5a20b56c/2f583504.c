
void MDrv_VBI_CC_InitYPbYr(undefined1 param_1)

{
  int iVar1;
  undefined1 local_10 [12];
  
  local_10[0] = 0;
  if (*(int *)(PTR_DAT_2f598688 + -0x7730) != 0) {
    local_10[0] = param_1;
    iVar1 = (*(code *)PTR_UtopiaIoctl_2f5987a8)(*(int *)(PTR_DAT_2f598688 + -0x7730),0x65,local_10);
    if (iVar1 != 0) {
      (*(code *)PTR_puts_2f598714)(PTR___DT_MIPS_BASE_ADDRESS_2f598694 + 0x7c88);
    }
    return;
  }
  (*(code *)PTR_puts_2f598714)(PTR___DT_MIPS_BASE_ADDRESS_2f598694 + 0x798c);
  return;
}

