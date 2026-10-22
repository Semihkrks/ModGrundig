
void msAPI_VDPlayer_DemuxFLV_InitTmpIdxBuf(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_g_pstDemuxer_2dbab670;
  *(undefined4 *)(*(int *)(*(int *)PTR_g_pstDemuxer_2dbab670 + 4) + 0x40) = param_1;
  *(undefined4 *)(*(int *)(*(int *)puVar1 + 4) + 0x44) = param_2;
  return;
}

