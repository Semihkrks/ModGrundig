
undefined4 MDrv_PCMCIA_SetPowerState(undefined4 param_1)

{
  int iVar1;
  undefined4 local_res0 [4];
  
  if (*(int *)PTR_pInstant_2f4b6e34 != 0) {
    local_res0[0] = param_1;
    iVar1 = (*(code *)PTR_UtopiaIoctl_2f4b6e1c)(*(int *)PTR_pInstant_2f4b6e34,0x1e,local_res0);
    if (iVar1 == 0) {
      return 1;
    }
    (*(code *)PTR_printf_2f4b6df0)
              (PTR___DT_MIPS_BASE_ADDRESS_2f4b6d14 + 0x68b4,
               PTR___DT_MIPS_BASE_ADDRESS_2f4b6d14 + 0x6930,iVar1);
  }
  return 0;
}

