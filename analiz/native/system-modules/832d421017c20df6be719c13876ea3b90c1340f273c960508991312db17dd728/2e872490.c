
void MAsm_CPU_StatusBEV(uint param_1)

{
  setCopReg(0,Status,Status | (param_1 & 0xff) << 0x16);
  return;
}

