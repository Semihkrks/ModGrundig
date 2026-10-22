
byte HAL_AVD_AFEC_GetCoChannelOn(void)

{
  if (PTR_DAT_2efac2f8[-0x3d1c] != '\0') {
    return *(byte *)(*(int *)(PTR_DAT_2efac2f8 + -0x3d20) + 0x6b94) >> 3 & 1;
  }
  return 0;
}

