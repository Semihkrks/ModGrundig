
void ne_debug_init(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_ne_debug_mask_000497a8;
  *(int *)PTR_ne_debug_stream_00049540 = param_1;
  *(undefined4 *)puVar1 = param_2;
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000230a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_setvbuf_0004956c)(param_1,0,2,0);
    return;
  }
  return;
}

