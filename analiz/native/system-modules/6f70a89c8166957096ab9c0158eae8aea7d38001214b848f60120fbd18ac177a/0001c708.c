
/* icu_4_2::RunArray::init(int) */

void __thiscall icu_4_2::RunArray::init(RunArray *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_uprv_malloc_4_2_00033d4c)(param_1 << 2);
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

