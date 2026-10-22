
void MDrv_UrDMA_Init(undefined4 param_1,undefined4 param_2,byte param_3)

{
  uint *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  int local_20;
  undefined1 auStack_1c [8];
  
  iVar6 = (*(code *)PTR_MDrv_MMIO_GetBASE_000212f8)(&local_20,auStack_1c,0x125);
  puVar2 = PTR_DAT_000212c8;
  if (iVar6 != 0) {
    puVar1 = (uint *)(PTR_DAT_000212c8 + 0x1290);
    *(int *)(PTR_DAT_000212c8 + 0x1320) = local_20 + 0x6980;
    if (1 < *puVar1) {
      (*(code *)PTR_printf_000212f0)(PTR_000212d4 + 0x11fc,PTR_000212d4 + 0x1268);
    }
    puVar3 = PTR_DAT_000212c8;
    pbVar7 = *(byte **)(puVar2 + 0x1320);
    *(byte **)(PTR_DAT_000212c8 + 0x1324) = pbVar7;
    *pbVar7 = *pbVar7 & 0xfb;
    *pbVar7 = *pbVar7 & 0xf7;
    *pbVar7 = *pbVar7 | 1;
    *pbVar7 = *pbVar7 & 0xfe;
    *pbVar7 = *pbVar7 & 0xfb;
    *pbVar7 = *pbVar7 & 0xf7;
    do {
      bVar5 = pbVar7[1] >> 5 & 1;
    } while ((pbVar7[1] >> 5 & 1) != 0);
    *pbVar7 = bVar5;
    pbVar7[1] = bVar5;
    pbVar7[0x1b] = pbVar7[0x1b] & 0xfd;
    puVar2 = PTR_MsOS_DisableInterrupt_000212e8;
    pbVar7[0x1a] = pbVar7[0x1a] & 0xfd;
    pbVar7[0x1a] = pbVar7[0x1a] & 0xfb;
    pbVar7[0x1b] = pbVar7[0x1b] | 1;
    pbVar7[0x1a] = pbVar7[0x1a] | 1;
    (*(code *)puVar2)(0x56);
    puVar4 = PTR_MsOS_EnableInterrupt_000212fc;
    puVar2 = PTR_DAT_000212c8;
    *(undefined4 *)(PTR_DAT_000212c8 + 0x132c) = param_2;
    *(undefined4 *)(puVar2 + 0x1328) = param_1;
    (*(code *)puVar4)(0x56);
    puVar2 = PTR_MDrv_UrDMA_SelMode_000212e4;
    *(byte *)(*(int *)(puVar3 + 0x1324) + 1) =
         *(byte *)(*(int *)(puVar3 + 0x1324) + 1) & 0xf7 | (param_3 & 1) << 3;
    (*(code *)puVar2)(1);
    return;
  }
  if (*(int *)(PTR_DAT_000212c8 + 0x1290) == 0) {
    return;
  }
  (*(code *)PTR_printf_000212f0)(PTR_000212d4 + 0x11cc,PTR_000212d4 + 0x1268);
  return;
}

