
undefined4 MDrv_UrDMA_RxInit(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte *pbVar4;
  undefined4 uVar5;
  
  puVar1 = PTR_DAT_000212c8;
  if (1 < *(uint *)(PTR_DAT_000212c8 + 0x1290)) {
    (*(code *)PTR_printf_000212f0)(PTR_000212d4 + 0x1218,param_1,param_2 & 0xffff);
  }
  puVar2 = PTR_DAT_000212c8;
  (*(code *)PTR_MsOS_DisableInterrupt_000212e8)(0x56);
  puVar3 = PTR_000212d4;
  pbVar4 = *(byte **)(puVar2 + 0x1324);
  if (pbVar4 != (byte *)0x0) {
    *pbVar4 = *pbVar4 & 0xf7;
    uVar5 = 0;
    do {
      pbVar4 = *(byte **)(puVar2 + 0x1324);
      do {
        if ((pbVar4[1] >> 5 & 1) == 0) {
          pbVar4[0x10] = (byte)((uint)param_1 >> 0x10);
          pbVar4[0x12] = (byte)param_1;
          pbVar4[0x13] = (byte)((uint)param_1 >> 8);
          pbVar4[0x14] = 0xff;
          pbVar4[0x15] = pbVar4[0x15] | 0x1f;
          pbVar4[2] = (byte)param_2;
          pbVar4[3] = pbVar4[3] & 0xf0 | (byte)(param_2 >> 8) & 0xf;
          puVar1 = PTR_MsOS_EnableInterrupt_000212fc;
          pbVar4[0x18] = pbVar4[0x18] & 0xf0 | 10;
          pbVar4[0x1a] = pbVar4[0x1a] | 4;
          *pbVar4 = *pbVar4 | 8;
          (*(code *)puVar1)(0x56);
          return uVar5;
        }
        uVar5 = 2;
      } while (*(int *)(puVar1 + 0x1290) == 0);
      (*(code *)PTR_puts_000212ec)(puVar3 + 0x1234);
    } while( true );
  }
  (*(code *)PTR_MsOS_EnableInterrupt_000212fc)(0x56);
  return 5;
}

