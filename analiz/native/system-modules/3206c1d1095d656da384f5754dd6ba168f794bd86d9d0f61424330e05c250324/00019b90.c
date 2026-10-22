
void ne_ssl_set_verify(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x2d0) = param_3;
  *(undefined4 *)(param_1 + 0x2cc) = param_2;
  return;
}

