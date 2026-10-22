
void png_read_update_info(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x11c) & 0x40) == 0) {
      (*(code *)PTR_FUN_00056200)(param_1);
    }
    else {
      (*(code *)PTR_png_warning_00056460)(param_1,PTR_LAB_00056108 + 0x5470);
    }
    (*(code *)PTR_FUN_00056204)(param_1,param_2);
  }
  return;
}

