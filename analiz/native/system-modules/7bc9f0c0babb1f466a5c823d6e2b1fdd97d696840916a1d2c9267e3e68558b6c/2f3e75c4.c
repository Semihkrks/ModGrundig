
undefined4 HAL_DSCMB_Init(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  (*(code *)PTR__HAL_DSCMB_ClkCtrl_2f3f82bc)(1);
  puVar3 = (undefined4 *)(PTR_DAT_2f3f8298 + -0x7b8c);
  pcVar4 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f3f82a4 + 0x7324);
  iVar1 = 0;
  do {
    *puVar3 = 0xffffffff;
    (*pcVar4)(0,iVar1,0xffffffff,1);
    iVar2 = iVar1 + 1;
    (*pcVar4)(0,iVar1,0xffffffff,2);
    puVar3 = puVar3 + 3;
    iVar1 = iVar2;
  } while (iVar2 != 0x40);
  iVar1 = *(int *)(PTR_DAT_2f3f8298 + -0x7b90);
  *(uint *)(iVar1 + 0x1800) = *(uint *)(iVar1 + 0x1800) & 0xfffffffe;
  *(uint *)(iVar1 + 0x1828) = *(uint *)(iVar1 + 0x1828) & 0xffffefba;
  *(uint *)(iVar1 + 0x1804) = *(uint *)(iVar1 + 0x1804) | 4;
  *(uint *)(iVar1 + 0x27830) = *(uint *)(iVar1 + 0x27830) | 0x100;
  return 1;
}

