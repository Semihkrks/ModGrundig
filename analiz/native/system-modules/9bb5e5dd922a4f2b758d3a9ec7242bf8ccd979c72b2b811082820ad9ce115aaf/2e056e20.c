
undefined4 FT_Get_X11_Font_Format(int param_1)

{
  int *piVar1;
  undefined4 local_18;
  undefined4 local_10;
  
  local_10 = 0;
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x60);
    local_18 = 0;
    if (*(int *)(*piVar1 + 0x20) != 0) {
      local_18 = (**(code **)(*piVar1 + 0x20))(piVar1,PTR_LAB_2e117fcc + 0x1b70);
    }
    local_10 = local_18;
  }
  return local_10;
}

