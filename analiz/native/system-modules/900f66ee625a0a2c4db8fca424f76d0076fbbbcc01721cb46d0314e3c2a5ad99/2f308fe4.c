
void mhal_CEC_SetRetryCount(byte param_1)

{
  *(byte *)(*(int *)PTR_CEC_RIU_BASE_2f31de84 + 0x2201) =
       *(byte *)(*(int *)PTR_CEC_RIU_BASE_2f31de84 + 0x2201) & 0xf8 | param_1;
  return;
}

