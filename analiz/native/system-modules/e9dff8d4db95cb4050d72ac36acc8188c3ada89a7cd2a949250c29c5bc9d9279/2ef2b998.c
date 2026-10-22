
void GE_Init_HAL_Context(int *param_1,int param_2,char param_3)

{
  (*(code *)PTR_memset_2ef4c338)(param_1,0,0x618);
  if (param_3 != '\0') {
    (*(code *)PTR_memset_2ef4c338)(param_2,0,0x206);
    *(undefined2 *)(param_2 + 2) = 1;
  }
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 0x185) = 0;
  return;
}

