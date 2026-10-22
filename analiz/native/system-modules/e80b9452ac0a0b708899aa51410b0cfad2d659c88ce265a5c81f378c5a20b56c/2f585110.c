
void _MDrv_VBI_InitializeTTXSlicer(undefined4 param_1,undefined2 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  (*(code *)PTR_VBI_TTX_InitSlicer_2f5986a4)(param_1,param_2);
  puVar2 = PTR__MDrv_VBI_RingBuffer_Reset_2f59878c;
  puVar1 = PTR_DAT_2f598688;
  *(undefined2 *)(PTR_DAT_2f598688 + -0x7a10) = param_2;
  *(undefined4 *)(puVar1 + -0x7a14) = param_1;
  (*(code *)puVar2)();
  return;
}

