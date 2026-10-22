
void dfb_MMA_Init(void)

{
  if (*(int *)(PTR_DAT_2f12a358 + -0x58b0) != 0) {
                    /* WARNING: Could not recover jumptable at 0x2f108794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(PTR_DAT_2f12a358 + -0x58b0) + 0x18))();
    return;
  }
  return;
}

