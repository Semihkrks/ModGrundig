
void MHAL_MBXINT_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_00026894;
  puVar1 = PTR_DAT_00026888;
  *(undefined4 *)(PTR_DAT_00026888 + 0x6f04) = param_2;
  *(undefined4 *)(puVar1 + 0x6f00) = param_3;
  (*(code *)(puVar2 + 0x50e4))();
  return;
}

