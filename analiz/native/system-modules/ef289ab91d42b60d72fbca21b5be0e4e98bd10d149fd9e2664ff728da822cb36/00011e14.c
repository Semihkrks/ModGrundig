
undefined4 TEE_UpdateWriteAddress(int *param_1,int param_2)

{
  undefined4 local_10;
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_printf_000222d0)(PTR_000222b4 + 0x2150,PTR_000222b4 + 0x224c,0xe1);
    local_10 = 1;
  }
  else {
    if ((uint)(param_1[1] + *param_1) < (uint)(param_1[2] + param_2)) {
      param_1[2] = *param_1;
    }
    param_1[2] = param_1[2] + param_2;
    local_10 = 0;
  }
  return local_10;
}

