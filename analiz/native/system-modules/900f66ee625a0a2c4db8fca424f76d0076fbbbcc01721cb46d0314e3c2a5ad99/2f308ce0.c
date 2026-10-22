
byte mhal_CEC_IsMessageReceived(void)

{
  return *(byte *)(*(int *)PTR_CEC_RIU_BASE_2f31de84 + 0x2245) & 1;
}

