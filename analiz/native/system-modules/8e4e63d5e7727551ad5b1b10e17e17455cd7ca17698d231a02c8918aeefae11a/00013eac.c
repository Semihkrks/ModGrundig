
void png_init_io(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x104) = param_2;
  }
  return;
}

