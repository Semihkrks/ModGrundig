
void HAL_MVOP_InitMirrorMode(char param_1)

{
  if (param_1 == '\0') {
    *(byte *)(*(int *)(PTR_DAT_2edae5b8 + -0x1578) + 0x28ec) =
         *(byte *)(*(int *)(PTR_DAT_2edae5b8 + -0x1578) + 0x28ec) & 7;
    return;
  }
  *(byte *)(*(int *)(PTR_DAT_2edae5b8 + -0x1578) + 0x28ec) =
       *(byte *)(*(int *)(PTR_DAT_2edae5b8 + -0x1578) + 0x28ec) & 7 | 0xf8;
  return;
}

