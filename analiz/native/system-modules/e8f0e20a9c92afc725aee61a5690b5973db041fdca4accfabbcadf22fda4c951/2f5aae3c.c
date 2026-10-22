
void HAL_VIF_RegInit(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 local_10;
  undefined1 auStack_c [8];
  
  iVar5 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f5bdbac)(&local_10,auStack_c,0x133);
  if (iVar5 == 0) {
    (*(code *)PTR_printf_2f5bdb2c)(PTR_DAT_2f5bda58 + -0x42f0);
    local_10 = 0xbf800000;
  }
  puVar4 = PTR_MDrv_MMIO_GetBASE_2f5bdbac;
  puVar3 = PTR_u32PMBankSize_2f5bdba0;
  puVar2 = PTR_u32PMBank_2f5bda90;
  puVar1 = PTR_DAT_2f5bda48;
  *(undefined4 *)(PTR_DAT_2f5bda48 + -0x25cc) = 1;
  *(undefined4 *)(puVar1 + -0x25d0) = local_10;
  iVar5 = (*(code *)puVar4)(puVar2,puVar3,300);
  if (iVar5 == 0) {
    (*(code *)PTR_printf_2f5bdb2c)(PTR_DAT_2f5bda58 + -0x42c8);
    *(undefined4 *)PTR_u32PMBank_2f5bda90 = 0xbf800000;
  }
  return;
}

