
undefined4 msAPI_VDPlayer_BMUpdateDemuxBase(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_m_pBM_Handler_2dbabe78;
  *(undefined4 *)(*(int *)PTR_m_pBM_Handler_2dbabe78 + 0xd4) =
       *(undefined4 *)(*(int *)PTR_m_pBM_Handler_2dbabe78 + 0xd8);
  iVar2 = *(int *)puVar1;
  *(undefined2 *)(iVar2 + 0xe8) = *(undefined2 *)(iVar2 + 0xea);
  return *(undefined4 *)(*(int *)puVar1 + 0xd4);
}

