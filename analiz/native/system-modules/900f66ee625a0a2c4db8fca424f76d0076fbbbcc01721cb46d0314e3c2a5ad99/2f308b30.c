
uint mhal_CEC_HeaderSwap(uint param_1)

{
  return (param_1 & 0xff) * 0x10 + ((param_1 & 0xff) >> 4) & 0xff;
}

