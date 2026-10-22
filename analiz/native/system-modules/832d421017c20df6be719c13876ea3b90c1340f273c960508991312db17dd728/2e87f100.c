
void dlinit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_heap_end_2e8ab234;
  *(undefined4 *)PTR_sbrk_top_2e8ab378 = param_1;
  *(undefined4 *)puVar1 = param_2;
  return;
}

