
undefined4 ares_library_init(undefined4 param_1)

{
  if (*(int *)(PTR_DAT_2f0f15a8 + 0x1750) == 0) {
    *(undefined4 *)(PTR_DAT_2f0f15a8 + 0x1750) = 1;
    *(undefined4 *)(PTR_DAT_2f0f15a8 + 0x1754) = param_1;
  }
  return 0;
}

