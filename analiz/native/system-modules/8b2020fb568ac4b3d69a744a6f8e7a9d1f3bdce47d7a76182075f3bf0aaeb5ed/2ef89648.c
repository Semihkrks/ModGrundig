
void HAL_AVD_AFEC_SetChannelChange(void)

{
  if (PTR_DAT_2efac2f8[-0x3d1c] != '\0') {
    *(byte *)(*(int *)(PTR_DAT_2efac2f8 + -0x3d20) + 0x6bb0) =
         *(byte *)(*(int *)(PTR_DAT_2efac2f8 + -0x3d20) + 0x6bb0) | 8;
  }
  return;
}

