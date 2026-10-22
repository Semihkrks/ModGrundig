
void g_thread_init_with_errorcheck_mutexes(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *local_60 [8];
  undefined *local_40;
  undefined *local_3c;
  
  if (param_1 != 0) {
    (*(code *)PTR_g_log_00023700)(PTR_000236e4 + 0x2d48,4,PTR_000236e4 + 0x34bc);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (*(code *)(PTR_000236e4 + 0x24f4))();
  puVar2 = (undefined4 *)(PTR_DAT_000236d8 + 0x3670);
  ppuVar3 = local_60;
  do {
    puVar6 = (undefined *)*puVar2;
    puVar5 = (undefined *)puVar2[1];
    puVar4 = (undefined *)puVar2[2];
    puVar1 = (undefined *)puVar2[3];
    puVar2 = puVar2 + 4;
    *ppuVar3 = puVar6;
    ppuVar3[1] = puVar5;
    ppuVar3[2] = puVar4;
    ppuVar3[3] = puVar1;
    ppuVar3 = ppuVar3 + 4;
  } while (puVar2 != (undefined4 *)(PTR_DAT_000236d8 + 0x36c0));
  *ppuVar3 = (undefined *)*puVar2;
  local_60[2] = PTR_000236e4 + 0x14dc;
  local_60[3] = PTR_000236e4 + 0x136c;
  local_60[0] = PTR_000236e4 + 0x29d8;
  local_60[1] = PTR_000236e4 + 0x15f4;
  local_60[4] = PTR_000236e4 + 0x1294;
  local_40 = PTR_000236e4 + 0x110c;
  local_3c = PTR_000236e4 + 0xf74;
  (*(code *)PTR_g_thread_init_00023750)(local_60);
  return;
}

