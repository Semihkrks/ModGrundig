
void MDrv_DDC2BI_Init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  (*(code *)PTR__MDrv_DDC2BI_init_riu_base_2f3d18f4)();
  puVar1 = PTR_rxChkSum_2f3d18f8;
  *PTR_rxLength_2f3d18d4 = 0;
  puVar2 = PTR_rxIndex_2f3d1950;
  *puVar1 = 0;
  *puVar2 = 0;
  puVar2 = PTR_MDrv_DDC2BI_InitRx_2f3d194c;
  puVar1 = PTR_DDC_StatusFlag_2f3d1904;
  *PTR_txLength_2f3d1928 = 0;
  *puVar1 = 0;
  (*(code *)puVar2)();
  puVar3 = PTR_DDC2BI_RIU_BASE_2f3d1938;
  iVar4 = *(int *)PTR_DDC2BI_RIU_BASE_2f3d1938;
  *PTR_txStatus_2f3d18d8 = 0;
  *(undefined1 *)(iVar4 + 0x814) = 0xb7;
  *(undefined1 *)(*(int *)puVar3 + 0x838) = 0x7f;
  *(undefined1 *)(*(int *)puVar3 + 0x838) = 0;
  *(undefined1 *)(*(int *)puVar3 + 0x83c) = 0x7f;
  *(undefined1 *)(*(int *)puVar3 + 0x83c) = 0;
  *(undefined1 *)(*(int *)puVar3 + 0x83d) = 0x7f;
  *(undefined1 *)(*(int *)puVar3 + 0x83d) = 0;
  *(undefined1 *)(*(int *)puVar3 + 0x8ad) = 0x7f;
  *(undefined1 *)(*(int *)puVar3 + 0x8ad) = 0;
  *(undefined1 *)(*(int *)puVar3 + 0x8ad) = 0x7f;
  *(undefined1 *)(*(int *)puVar3 + 0x8ad) = 0;
  puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2f3d18c4;
  *(undefined1 *)(*(int *)puVar3 + 0x811) = 0;
  puVar2 = PTR_MsOS_AttachInterrupt_2f3d190c;
  *(undefined1 *)(*(int *)puVar3 + 0x828) = 0x67;
  *(undefined1 *)(*(int *)puVar3 + 0x82c) = 0x67;
  *(undefined1 *)(*(int *)puVar3 + 0x82d) = 0x67;
  *(undefined1 *)(*(int *)puVar3 + 0x8a9) = 0x67;
  *(undefined1 *)(*(int *)puVar3 + 0x8a9) = 0x67;
  (*(code *)puVar2)(0x1a,puVar1 + 0xeec);
  (*(code *)PTR_MsOS_EnableInterrupt_2f3d193c)(0x1a);
  puVar1 = PTR_DAT_2f3d18b8;
  PTR_DAT_2f3d18b8[0x1995] = 1;
  puVar1[0x1994] = 1;
  return;
}

