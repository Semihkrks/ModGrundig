
undefined4 InitBP_Recieve(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    local_10 = 0;
  }
  else {
    *param_1 = 0;
    param_1[2] = *param_2;
    uVar1 = (*(code *)PTR__GetBufferLength_000222e8)(*param_2);
    param_1[1] = uVar1;
    local_10 = 1;
  }
  return local_10;
}

