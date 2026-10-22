
undefined4 _MDrv_PCMCIA_SetPowerState(int param_1)

{
  if (param_1 != 1) {
    if (param_1 == 2) {
      (*(code *)PTR__MDrv_PCMCIA_InitHW_2f4b6df8)(1);
    }
    return 0;
  }
  (*(code *)PTR__MDrv_PCMCIA_Exit_2f4b6e54)();
  return 0;
}

