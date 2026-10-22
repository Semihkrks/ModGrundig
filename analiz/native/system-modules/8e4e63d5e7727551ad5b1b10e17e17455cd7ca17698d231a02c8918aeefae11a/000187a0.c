
int png_get_signature(int param_1,int param_2)

{
  undefined4 local_10;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    local_10 = 0;
  }
  else {
    local_10 = param_2 + 0x20;
  }
  return local_10;
}

