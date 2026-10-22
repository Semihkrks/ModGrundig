
undefined4 AESDMA_POWER_SUSPEND(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR__AESDMA_REG32_R_2f37931c)(*(undefined4 *)(PTR_DAT_2f379278 + -0x6dc0));
  *(undefined4 *)(PTR_DAT_2f379278 + -0x5a68) = uVar1;
  return 1;
}

