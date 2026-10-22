
char mhal_CEC_ReceivedMessageLen(void)

{
  return (*(byte *)(*(int *)PTR_CEC_RIU_BASE_2f31de84 + 0x2210) & 0x1f) + 1;
}

