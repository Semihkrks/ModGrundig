
int FUN_2eb59cec(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_4 << 1 == 0) {
    trap(7);
  }
  return (param_3 * 0x1fe + 0xff + param_4) / (param_4 << 1);
}

