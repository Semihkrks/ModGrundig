
void sift_ctx_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  (*(code *)PTR_memset_004447f8)(param_1 + 4,0,0xc);
  return;
}

