
bool InitBP_Send(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_memset_000222f0)(param_1,0,0xc);
  }
  return param_1 != 0;
}

