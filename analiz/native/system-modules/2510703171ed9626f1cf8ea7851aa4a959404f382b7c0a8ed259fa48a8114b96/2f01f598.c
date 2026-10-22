
undefined4 MDrv_PQ_SetPowerState(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar3 = PTR__s32LastPQIPMemFormatMain_2f0382b8;
  if (param_1 == 1) {
    *(undefined4 *)(PTR_DAT_2f0380d8 + -0x7f5c) = 1;
    return 1;
  }
  if (param_1 == 2) {
    *(undefined4 *)(PTR_DAT_2f0380d8 + -0x7f5c) = 2;
    puVar2 = PTR__s32LastPQIPMADiMain_2f0380f8;
    *(undefined4 *)puVar3 = 0xffffffff;
    puVar3 = PTR__s32LastPQIPHSDCMain_2f0380fc;
    *(undefined4 *)puVar2 = 0xffffffff;
    puVar5 = PTR__stPQ_Info_2f03835c;
    puVar2 = PTR__s32LastPQIPHSDYMain_2f0382c4;
    *(undefined4 *)puVar3 = 0xffffffff;
    *(undefined4 *)puVar2 = 0xffffffff;
    puVar2 = PTR__s32LastPQIPMADiSub_2f038208;
    puVar3 = PTR__u16LastPQSrcType_2f0381b0;
    *(undefined4 *)PTR__s32LastPQIPMemFormatSub_2f0383bc = 0xffffffff;
    *(undefined4 *)puVar2 = 0xffffffff;
    puVar4 = PTR__s32LastPQIPMADiMotMain_2f038320;
    puVar2 = PTR__s32LastPQIPMADiMotSub_2f0381d8;
    bVar1 = puVar5[0x1a];
    *(undefined2 *)(puVar3 + 2) = 0xffff;
    *(undefined4 *)puVar4 = 0xffffffff;
    *(undefined4 *)puVar2 = 0xffffffff;
    *(undefined2 *)puVar3 = 0xffff;
    puVar3 = PTR_stPQBinHeaderInfo_2f03811c;
    if (bVar1 == 0) {
      (*(code *)PTR_MDrv_PQ_LoadCommTable_MAIN_2f038188)();
    }
    else {
      if (2 < bVar1) {
        uVar8 = 2;
        do {
          bVar1 = puVar5[uVar8 * 0xc + 0x20];
          uVar6 = (*(code *)PTR_MDrv_PQBin_GetPanelIdx_2f0381b8)();
          (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(uVar6,puVar3 + (uint)bVar1 * 200);
          uVar8 = uVar8 + 1 & 0xff;
        } while (uVar8 < (byte)puVar5[0x1a]);
      }
      if (puVar5[0x1c] == '\x02') {
        (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)
                  (0,PTR_stPQBinHeaderInfo_2f03811c +
                     (uint)(byte)PTR__stPQ_Info_2f03835c[0x5c] * 200);
      }
      puVar3 = PTR_stPQBinHeaderInfo_2f03811c;
      uVar8 = 0;
      while( true ) {
        uVar7 = (uint)(byte)puVar5[0x1a];
        if (2 < uVar7) {
          uVar7 = 2;
        }
        if (uVar7 <= uVar8) break;
        bVar1 = puVar5[uVar8 * 0xc + 0x20];
        uVar6 = (*(code *)PTR_MDrv_PQBin_GetPanelIdx_2f0381b8)();
        (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)(uVar6,puVar3 + (uint)bVar1 * 200);
        uVar8 = uVar8 + 1 & 0xff;
      }
      if (puVar5[0x1c] != '\0') {
        (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)
                  (0,PTR_stPQBinHeaderInfo_2f03811c +
                     (uint)(byte)PTR__stPQ_Info_2f03835c[0x50] * 200);
      }
      if (puVar5[0x1d] == '\x01') {
        (*(code *)PTR_MDrv_PQBin_LoadCommTable_2f038220)
                  (0,PTR_stPQBinHeaderInfo_2f03811c +
                     (uint)(byte)PTR__stPQ_Info_2f03835c[0x68] * 200);
      }
    }
    (*(code *)PTR_Hal_PQ_set_memfmt_doublebuffer_2f038124)(1);
    (*(code *)PTR_MDrv_BW_LoadInitTable_2f0381c8)();
    return 1;
  }
  (*(code *)PTR_printf_2f038298)(PTR_LAB_2f0380e8 + 0x733c,PTR_LAB_2f0380e8 + 0x7880,0x29d);
  return 0;
}

