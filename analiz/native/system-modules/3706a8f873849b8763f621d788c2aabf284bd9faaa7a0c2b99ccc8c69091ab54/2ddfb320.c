
void MODEPARSE_Initialize(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_MApi_XC_ModeParse_Init_U2_2de293bc;
  *(undefined **)(param_1 + 0x5c4) = PTR_MApi_XC_ModeParse_MatchModeEx_U2_2de29574;
  puVar2 = PTR_MApi_XC_ModeParse_MatchMode_U2_2de29740;
  *(undefined **)(param_1 + 0x5bc) = puVar1;
  *(undefined **)(param_1 + 0x5c0) = puVar2;
  return;
}

