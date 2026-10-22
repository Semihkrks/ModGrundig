
undefined4 MDrv_UrDMA_TxInit(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  
  puVar1 = PTR_DAT_000212c8;
  if (1 < *(uint *)(PTR_DAT_000212c8 + 0x1290)) {
    (*(code *)PTR_printf_000212f0)(PTR_000212d4 + 0x1240,param_1,param_2 & 0xffff);
  }
  puVar2 = PTR_DAT_000212c8;
  (*(code *)PTR_MsOS_DisableInterrupt_000212e8)(0x56);
  puVar3 = PTR_000212d4;
  pbVar5 = *(byte **)(puVar2 + 0x1324);
  if (pbVar5 != (byte *)0x0) {
    *pbVar5 = *pbVar5 & 0xfb;
    uVar6 = 0;
    do {
      pbVar5 = *(byte **)(puVar2 + 0x1324);
      do {
        if ((pbVar5[1] >> 4 & 1) == 0) {
          pbVar5[4] = (byte)(param_1 >> 0x10);
          pbVar5[6] = (byte)param_1;
          pbVar5[7] = (byte)(param_1 >> 8);
          pbVar5[8] = 0xff;
          iVar4 = ((param_2 & 0xffff) - 1) + (param_1 & 7);
          pbVar5[9] = pbVar5[9] | 0x1f;
          pbVar5[0xc] = (byte)iVar4;
          pbVar5[0xd] = (byte)((uint)iVar4 >> 8);
          pbVar5[0xe] = pbVar5[0xe] & 0xf0 | 1;
          puVar1 = PTR_MsOS_EnableInterrupt_000212fc;
          pbVar5[0x1b] = pbVar5[0x1b] | 2;
          *pbVar5 = *pbVar5 | 4;
          (*(code *)puVar1)(0x56);
          return uVar6;
        }
        uVar6 = 1;
      } while (*(int *)(puVar1 + 0x1290) == 0);
      (*(code *)PTR_puts_000212ec)(puVar3 + 0x125c);
    } while( true );
  }
  (*(code *)PTR_MsOS_EnableInterrupt_000212fc)(0x56);
  return 5;
}

