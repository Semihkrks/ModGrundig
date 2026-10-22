
void MDrv_DDC2BI_InitRx(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_rxIndex_2f3d1950;
  *PTR_rxStatus_2f3d1914 = 0;
  puVar1 = PTR_g_ucReceiveCounter_2f3d18e0;
  *puVar2 = 0;
  *puVar1 = 0;
  return;
}

