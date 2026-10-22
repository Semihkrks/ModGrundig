
int g_bit_storage(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 != 0) {
    iVar1 = (LZCOUNT(param_1) ^ 0x1fU) + 1;
  }
  return iVar1;
}

