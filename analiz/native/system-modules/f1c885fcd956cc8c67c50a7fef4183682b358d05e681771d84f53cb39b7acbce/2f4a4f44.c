
undefined4 MDrv_PCMCIA_WaitForStatusBitV2(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined1 local_c;
  
  if (*(int *)PTR_pInstant_2f4b6e34 != 0) {
    local_10 = param_1;
    local_c = param_2;
    iVar1 = (*(code *)PTR_UtopiaIoctl_2f4b6e1c)(*(int *)PTR_pInstant_2f4b6e34,0x18,&local_10);
    if (iVar1 == 0) {
      return 1;
    }
    (*(code *)PTR_printf_2f4b6df0)
              (PTR___DT_MIPS_BASE_ADDRESS_2f4b6d14 + 0x68b4,
               PTR___DT_MIPS_BASE_ADDRESS_2f4b6d14 + 0x694c,iVar1);
  }
  return 0;
}

