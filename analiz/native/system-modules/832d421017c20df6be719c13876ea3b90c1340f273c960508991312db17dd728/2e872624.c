
void MAsm_CPU_TimerInit(void)

{
  setCopReg(0,Count,0);
  setCopReg(0,Compare,300000);
  return;
}

