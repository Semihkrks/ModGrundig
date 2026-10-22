
void fusion_vector_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0x1c001010;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

