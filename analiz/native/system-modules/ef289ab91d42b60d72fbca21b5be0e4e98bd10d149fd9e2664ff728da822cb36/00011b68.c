
bool TEE_InitRingBuffer(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_2;
  }
  return param_1 == (undefined4 *)0x0;
}

