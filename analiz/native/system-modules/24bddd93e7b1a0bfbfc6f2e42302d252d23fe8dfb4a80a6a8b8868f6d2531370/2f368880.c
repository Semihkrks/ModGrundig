
undefined4 AESDMA_POWER_RESUME(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(PTR_DAT_2f379278 + -0x5a68);
  puVar1 = *(undefined2 **)(PTR_DAT_2f379278 + -0x6dc0);
  puVar1[2] = (short)((uint)uVar2 >> 0x10);
  *puVar1 = (short)uVar2;
  return 1;
}

