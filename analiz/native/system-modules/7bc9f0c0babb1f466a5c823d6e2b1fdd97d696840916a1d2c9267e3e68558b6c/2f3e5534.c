
undefined4 MDrv_DSCMB2_Init(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_2f3f8298;
  if (*(int *)(PTR_DAT_2f3f8298 + -0x7bcc) == 0) {
    (*(code *)PTR_DSCMBRegisterToUtopia_2f3f830c)();
    iVar2 = (*(code *)PTR_UtopiaOpen_2f3f83f8)(3,puVar1 + -0x7bcc,0,0);
    if (iVar2 == 1) {
      (*(code *)PTR_puts_2f3f82f0)(PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x7a10);
      return 0;
    }
  }
  iVar2 = (*(code *)PTR_UtopiaIoctl_2f3f8364)(*(undefined4 *)(puVar1 + -0x7bcc),0,0);
  if (iVar2 == 0) {
    return 1;
  }
  (*(code *)PTR_printf_2f3f834c)
            (PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x79a8,
             PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x7f4c,iVar2);
  return 0;
}

