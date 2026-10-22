
void Cyg_Mempool_Status_init(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 10) = 0xff;
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0xffffffff;
  param_1[4] = 0xffffffff;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  *(undefined1 *)(param_1 + 7) = 0xff;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  return;
}

