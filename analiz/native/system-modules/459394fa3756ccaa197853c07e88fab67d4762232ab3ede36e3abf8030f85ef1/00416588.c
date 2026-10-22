
undefined4 re_node_set_init_1(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  *param_1 = 1;
  param_1[1] = 1;
  uVar1 = (*(code *)PTR_rpl_malloc_00444828)(4);
  param_1[2] = uVar1;
  if (param_1[2] == 0) {
    param_1[1] = 0;
    *param_1 = param_1[1];
    local_10 = 0xc;
  }
  else {
    *(undefined4 *)param_1[2] = param_2;
    local_10 = 0;
  }
  return local_10;
}

