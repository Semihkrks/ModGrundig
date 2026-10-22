
void msAPI_VDPlayer_DemuxSWF_InitCompressBuf(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_g_pstDemuxer_2dbab670;
  *(undefined4 *)(*(int *)(*(int *)PTR_g_pstDemuxer_2dbab670 + 4) + 0x58) = param_1;
  *(undefined4 *)(*(int *)(*(int *)puVar1 + 4) + 0x5c) = param_2;
  return;
}

