
undefined1 HAL_AUDIO_GET_INIT_FLAG(void)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (*(int *)PTR_g_AudioVars2_2d2321fc != 0) {
    uVar1 = *(undefined1 *)(*(int *)PTR_g_AudioVars2_2d2321fc + 8);
  }
  return uVar1;
}

