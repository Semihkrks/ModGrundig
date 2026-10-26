
undefined4 FUN_00d01710(MWidget *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined4 uVar7;
  ulong uVar8;
  char *pcVar9;
  ArTvManager *pAVar10;
  uint uVar11;
  MenuBackgroundFrame *this;
  FirstTimeFrame *this_00;
  int iVar12;
  MMainFrame *pMVar13;
  ArAudioManager *pAVar14;
  int iVar15;
  uint uStack_14d0;
  allocator aaStack_14b4 [4];
  string asStack_14b0 [4];
  string asStack_14ac [4];
  allocator aaStack_14a8 [4];
  string asStack_14a4 [4];
  string asStack_14a0 [4];
  allocator aaStack_149c [4];
  string asStack_1498 [4];
  string asStack_1494 [4];
  allocator aaStack_1490 [4];
  string asStack_148c [4];
  allocator aaStack_1488 [4];
  string asStack_1484 [4];
  allocator aaStack_1480 [4];
  string asStack_147c [4];
  allocator aaStack_1478 [4];
  string asStack_1474 [4];
  allocator aaStack_1470 [4];
  string asStack_146c [4];
  allocator aaStack_1468 [4];
  string asStack_1464 [4];
  allocator aaStack_1460 [4];
  string asStack_145c [4];
  allocator aaStack_1458 [4];
  string asStack_1454 [4];
  allocator aaStack_1450 [4];
  string asStack_144c [4];
  allocator aaStack_1448 [4];
  string asStack_1444 [4];
  allocator aaStack_1440 [4];
  string asStack_143c [4];
  allocator aaStack_1438 [4];
  string asStack_1434 [4];
  MImg aMStack_1430 [20];
  MImg aMStack_141c [20];
  MImg aMStack_1408 [20];
  MImg aMStack_13f4 [20];
  MImg aMStack_13e0 [20];
  MImg aMStack_13cc [20];
  MImg aMStack_13b8 [20];
  MImg aMStack_13a4 [20];
  MImg aMStack_1390 [20];
  MImg aMStack_137c [20];
  MImg aMStack_1368 [20];
  MImg aMStack_1354 [20];
  MImg aMStack_1340 [20];
  MImg aMStack_132c [20];
  MImg aMStack_1318 [20];
  MImg aMStack_1304 [20];
  MImg aMStack_12f0 [20];
  MImg aMStack_12dc [20];
  MImg aMStack_12c8 [20];
  MImg aMStack_12b4 [20];
  MImg aMStack_12a0 [20];
  MImg aMStack_128c [20];
  MImg aMStack_1278 [20];
  MImg aMStack_1264 [20];
  MImg aMStack_1250 [20];
  MImg aMStack_123c [20];
  MImg aMStack_1228 [20];
  MImg aMStack_1214 [20];
  MImg aMStack_1200 [20];
  MImg aMStack_11ec [20];
  MImg aMStack_11d8 [20];
  MImg aMStack_11c4 [20];
  MImg aMStack_11b0 [20];
  MImg aMStack_119c [20];
  MImg aMStack_1188 [20];
  MImg aMStack_1174 [20];
  MImg aMStack_1160 [20];
  MImg aMStack_114c [20];
  MImg aMStack_1138 [20];
  MImg aMStack_1124 [20];
  MImg aMStack_1110 [20];
  MImg aMStack_10fc [20];
  MImg aMStack_10e8 [20];
  MImg aMStack_10d4 [20];
  MImg aMStack_10c0 [20];
  MImg aMStack_10ac [20];
  MImg aMStack_1098 [20];
  MImg aMStack_1084 [20];
  MImg aMStack_1070 [20];
  MImg aMStack_105c [20];
  MImg aMStack_1048 [20];
  MImg aMStack_1034 [20];
  MImg aMStack_1020 [20];
  MImg aMStack_100c [20];
  MImg aMStack_ff8 [20];
  MImg aMStack_fe4 [20];
  MImg aMStack_fd0 [20];
  MImg aMStack_fbc [20];
  MImg aMStack_fa8 [20];
  MImg aMStack_f94 [20];
  MImg aMStack_f80 [20];
  MImg aMStack_f6c [20];
  MImg aMStack_f58 [20];
  MImg aMStack_f44 [20];
  MImg aMStack_f30 [20];
  MImg aMStack_f1c [20];
  MImg aMStack_f08 [20];
  MImg aMStack_ef4 [20];
  MImg aMStack_ee0 [20];
  MImg aMStack_ecc [20];
  MImg aMStack_eb8 [20];
  MImg aMStack_ea4 [20];
  MImg aMStack_e90 [20];
  MImg aMStack_e7c [20];
  MImg aMStack_e68 [20];
  MImg aMStack_e54 [20];
  MImg aMStack_e40 [20];
  MImg aMStack_e2c [20];
  MImg aMStack_e18 [20];
  MImg aMStack_e04 [20];
  MImg aMStack_df0 [20];
  MImg aMStack_ddc [20];
  MImg aMStack_dc8 [20];
  MImg aMStack_db4 [20];
  MImg aMStack_da0 [20];
  MImg aMStack_d8c [20];
  MImg aMStack_d78 [20];
  MImg aMStack_d64 [20];
  MImg aMStack_d50 [20];
  MImg aMStack_d3c [20];
  MImg aMStack_d28 [20];
  MImg aMStack_d14 [20];
  MImg aMStack_d00 [20];
  MImg aMStack_cec [20];
  MImg aMStack_cd8 [20];
  MImg aMStack_cc4 [20];
  MImg aMStack_cb0 [20];
  MImg aMStack_c9c [20];
  MImg aMStack_c88 [20];
  MImg aMStack_c74 [20];
  MImg aMStack_c60 [20];
  MImg aMStack_c4c [20];
  MImg aMStack_c38 [20];
  MImg aMStack_c24 [20];
  MImg aMStack_c10 [20];
  MImg aMStack_bfc [20];
  MImg aMStack_be8 [20];
  MImg aMStack_bd4 [20];
  MImg aMStack_bc0 [20];
  MImg aMStack_bac [20];
  MImg aMStack_b98 [20];
  MImg aMStack_b84 [20];
  MImg aMStack_b70 [20];
  MImg aMStack_b5c [20];
  MImg aMStack_b48 [20];
  MImg aMStack_b34 [20];
  MImg aMStack_b20 [20];
  MImg aMStack_b0c [20];
  MImg aMStack_af8 [20];
  MImg aMStack_ae4 [20];
  MImg aMStack_ad0 [20];
  MImg aMStack_abc [20];
  MImg aMStack_aa8 [20];
  MImg aMStack_a94 [20];
  MImg aMStack_a80 [20];
  MImg aMStack_a6c [20];
  MImg aMStack_a58 [20];
  MImg aMStack_a44 [20];
  MImg aMStack_a30 [20];
  MImg aMStack_a1c [20];
  MImg aMStack_a08 [20];
  MImg aMStack_9f4 [20];
  MImg aMStack_9e0 [20];
  MImg aMStack_9cc [20];
  MImg aMStack_9b8 [20];
  MImg aMStack_9a4 [20];
  MImg aMStack_990 [20];
  MImg aMStack_97c [20];
  MImg aMStack_968 [20];
  MImg aMStack_954 [20];
  MImg aMStack_940 [20];
  MImg aMStack_92c [20];
  MImg aMStack_918 [20];
  MImg aMStack_904 [20];
  MImg aMStack_8f0 [20];
  MImg aMStack_8dc [20];
  MImg aMStack_8c8 [20];
  MImg aMStack_8b4 [20];
  MImg aMStack_8a0 [20];
  MImg aMStack_88c [20];
  MImg aMStack_878 [20];
  MImg aMStack_864 [20];
  MImg aMStack_850 [20];
  MImg aMStack_83c [20];
  MImg aMStack_828 [20];
  MImg aMStack_814 [20];
  MImg aMStack_800 [20];
  MImg aMStack_7ec [20];
  MImg aMStack_7d8 [20];
  MImg aMStack_7c4 [20];
  MImg aMStack_7b0 [20];
  MImg aMStack_79c [20];
  MImg aMStack_788 [20];
  MImg aMStack_774 [20];
  MImg aMStack_760 [20];
  MImg aMStack_74c [20];
  MImg aMStack_738 [20];
  MImg aMStack_724 [20];
  MImg aMStack_710 [20];
  MImg aMStack_6fc [20];
  MImg aMStack_6e8 [20];
  MImg aMStack_6d4 [20];
  MImg aMStack_6c0 [20];
  MImg aMStack_6ac [20];
  MImg aMStack_698 [20];
  MImg aMStack_684 [20];
  MImg aMStack_670 [20];
  MImg aMStack_65c [20];
  MImg aMStack_648 [20];
  MImg aMStack_634 [20];
  _Rect a_Stack_620 [16];
  undefined4 uStack_610;
  undefined4 uStack_60c;
  undefined4 uStack_608;
  undefined4 uStack_604;
  undefined4 uStack_600;
  undefined4 uStack_5fc;
  undefined4 uStack_5f8;
  undefined4 uStack_5f4;
  undefined4 uStack_5f0;
  undefined4 uStack_5ec;
  undefined4 uStack_5e8;
  undefined4 uStack_5e4;
  undefined4 uStack_5e0;
  undefined4 uStack_5dc;
  undefined4 uStack_5d8;
  undefined4 uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5c4;
  undefined4 uStack_5c0;
  undefined4 uStack_5bc;
  ostringstream aoStack_5b8 [544];
  int iStack_398;
  int iStack_394;
  int iStack_390;
  int iStack_38c;
  int iStack_388;
  char *pcStack_384;
  string *psStack_380;
  ArResourceManager *pAStack_37c;
  string *psStack_378;
  int iStack_374;
  int iStack_370;
  MString *pMStack_36c;
  MString *pMStack_368;
  undefined4 uStack_364;
  int iStack_360;
  int iStack_35c;
  MString *pMStack_358;
  MString *pMStack_354;
  undefined4 uStack_350;
  int iStack_34c;
  int iStack_348;
  MString *pMStack_344;
  MString *pMStack_340;
  undefined4 uStack_33c;
  int iStack_338;
  int iStack_334;
  MString *pMStack_330;
  MString *pMStack_32c;
  undefined4 uStack_328;
  int iStack_324;
  int iStack_320;
  MString *pMStack_31c;
  MString *pMStack_318;
  undefined4 uStack_314;
  int iStack_310;
  int iStack_30c;
  MString *pMStack_308;
  MString *pMStack_304;
  undefined4 uStack_300;
  int iStack_2fc;
  int iStack_2f8;
  MString *pMStack_2f4;
  MString *pMStack_2f0;
  undefined4 uStack_2ec;
  int iStack_2e8;
  int iStack_2e4;
  MString *pMStack_2e0;
  MString *pMStack_2dc;
  undefined4 uStack_2d8;
  int iStack_2d4;
  int iStack_2d0;
  int iStack_2cc;
  int iStack_2c8;
  MString *pMStack_2c4;
  MString *pMStack_2c0;
  undefined4 uStack_2bc;
  int iStack_2b8;
  MString *pMStack_2b4;
  MString *pMStack_2b0;
  undefined4 uStack_2ac;
  int iStack_2a8;
  MString *pMStack_2a4;
  MString *pMStack_2a0;
  undefined4 uStack_29c;
  int iStack_298;
  MString *pMStack_294;
  MString *pMStack_290;
  undefined4 uStack_28c;
  int iStack_288;
  ostream *poStack_284;
  string *psStack_280;
  ostream *poStack_27c;
  string *psStack_278;
  ostream *poStack_274;
  string *psStack_270;
  int iStack_26c;
  MString *pMStack_268;
  MString *pMStack_264;
  undefined4 uStack_260;
  string *psStack_25c;
  string *psStack_258;
  string *psStack_254;
  string *psStack_250;
  string *psStack_24c;
  string *psStack_248;
  string *psStack_244;
  string *psStack_240;
  string *psStack_23c;
  string *psStack_238;
  string *psStack_234;
  int iStack_230;
  MString *pMStack_22c;
  MString *pMStack_228;
  undefined4 uStack_224;
  int iStack_220;
  MString *pMStack_21c;
  MString *pMStack_218;
  undefined4 uStack_214;
  int iStack_210;
  MString *pMStack_20c;
  MString *pMStack_208;
  undefined4 uStack_204;
  int iStack_200;
  MString *pMStack_1fc;
  MString *pMStack_1f8;
  undefined4 uStack_1f4;
  int iStack_1f0;
  MString *pMStack_1ec;
  MString *pMStack_1e8;
  undefined4 uStack_1e4;
  MImg *pMStack_1e0;
  ImageButton *pIStack_1dc;
  ComboButton *pCStack_1d8;
  MImg *pMStack_1d4;
  ImageButton *pIStack_1d0;
  MImg *pMStack_1cc;
  ImageButton *pIStack_1c8;
  MImg *pMStack_1c4;
  ImageButton *pIStack_1c0;
  MImg *pMStack_1bc;
  ImageButton *pIStack_1b8;
  MImg *pMStack_1b4;
  ImageButton *pIStack_1b0;
  ComboButton *pCStack_1ac;
  MImg *pMStack_1a8;
  ImageButton *pIStack_1a4;
  ComboButton *pCStack_1a0;
  ComboButton *pCStack_19c;
  ComboButton *pCStack_198;
  ComboButton *pCStack_194;
  ComboButton *pCStack_190;
  ComboButton *pCStack_18c;
  ComboButton *pCStack_188;
  ComboButton *pCStack_184;
  ComboButton *pCStack_180;
  TextBox *pTStack_17c;
  TextBox *pTStack_178;
  TextBox *pTStack_174;
  TextBox *pTStack_170;
  TextBox *pTStack_16c;
  MImg *pMStack_168;
  ImageButton *pIStack_164;
  MImg *pMStack_160;
  ImageButton *pIStack_15c;
  MImg *pMStack_158;
  ImageButton *pIStack_154;
  ComboButton *pCStack_150;
  AbsContainer *pAStack_14c;
  ComboButton *pCStack_148;
  AbsContainer *pAStack_144;
  ComboButton *pCStack_140;
  ComboButton *pCStack_13c;
  AbsContainer *pAStack_138;
  SpinButton *pSStack_134;
  ComboButton *pCStack_130;
  AbsContainer *pAStack_12c;
  MImg *pMStack_128;
  ImageButton *pIStack_124;
  AbsContainer *pAStack_120;
  SpinButton *pSStack_11c;
  ComboButton *pCStack_118;
  ComboButton *pCStack_114;
  ComboButton *pCStack_110;
  MImg *pMStack_10c;
  ImageButton *pIStack_108;
  MImg *pMStack_104;
  ImageButton *pIStack_100;
  MImg *pMStack_fc;
  ImageButton *pIStack_f8;
  MImg *pMStack_f4;
  ImageButton *pIStack_f0;
  TextBox *pTStack_ec;
  ComboButton *pCStack_e8;
  ComboButton *pCStack_e4;
  AbsContainer *pAStack_e0;
  MImg *pMStack_dc;
  ImageButton *pIStack_d8;
  MImg *pMStack_d4;
  ImageButton *pIStack_d0;
  MImg *pMStack_cc;
  ImageButton *pIStack_c8;
  MImg *pMStack_c4;
  ImageButton *pIStack_c0;
  MImg *pMStack_bc;
  ImageButton *pIStack_b8;
  MImg *pMStack_b4;
  ImageButton *pIStack_b0;
  TextBox *pTStack_ac;
  MImg *pMStack_a8;
  MImg *pMStack_a4;
  MImg *pMStack_a0;
  MImg *pMStack_9c;
  ScrollListContainer *pSStack_98;
  MImg *pMStack_94;
  MImg *pMStack_90;
  MImg *pMStack_8c;
  MImg *pMStack_88;
  ScrollListContainer *pSStack_84;
  MImg *pMStack_80;
  MImg *pMStack_7c;
  MImg *pMStack_78;
  MImg *pMStack_74;
  ScrollListContainer *pSStack_70;
  MImg *pMStack_6c;
  MImg *pMStack_68;
  MImg *pMStack_64;
  MImg *pMStack_60;
  ScrollListContainer *pSStack_5c;
  MImg *pMStack_58;
  MImg *pMStack_54;
  MImg *pMStack_50;
  MImg *pMStack_4c;
  ScrollListContainer *pSStack_48;
  MImg *pMStack_44;
  MImg *pMStack_40;
  MImg *pMStack_3c;
  MImg *pMStack_38;
  ScrollListContainer *pSStack_34;
  Image *pIStack_30;
  Image *pIStack_2c;
  Button *pBStack_28;
  
  lVar3 = GetRcEngine::RcGetNum(0x3301);
  lVar4 = GetRcEngine::RcGetNum(0x3302);
  lVar5 = GetRcEngine::RcGetNum(0x3300);
  lVar6 = GetRcEngine::RcGetNum(0x32ff);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pBStack_28 = operator_new(0x250);
                    /* try { // try from 00d0180c to 00d01813 has its CatchHandler @ 00d0183c */
  Button::Button(pBStack_28,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,0);
  *(Button **)(param_1 + 0x180) = pBStack_28;
  if (*(int *)(param_1 + 0x180) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xb9);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x180) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  lVar3 = GetRcEngine::RcGetNum(0x33e1);
  lVar4 = GetRcEngine::RcGetNum(0x33e2);
  lVar5 = GetRcEngine::RcGetNum(0x33e0);
  lVar6 = GetRcEngine::RcGetNum(0x33df);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_2c = operator_new(0x2b4);
                    /* try { // try from 00d01c1c to 00d01c23 has its CatchHandler @ 00d01c4c */
  Image::Image(pIStack_2c,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,1);
  *(Image **)(param_1 + 0x184) = pIStack_2c;
  if (*(int *)(param_1 + 0x184) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xd2);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x29c);
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x184),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x184));
  lVar3 = GetRcEngine::RcGetNum(0x33e5);
  lVar4 = GetRcEngine::RcGetNum(0x33e6);
  lVar5 = GetRcEngine::RcGetNum(0x33e4);
  lVar6 = GetRcEngine::RcGetNum(0x33e3);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_30 = operator_new(0x2b4);
                    /* try { // try from 00d01fe0 to 00d01fe7 has its CatchHandler @ 00d02010 */
  Image::Image(pIStack_30,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,2);
  *(Image **)(param_1 + 0x188) = pIStack_30;
  if (*(int *)(param_1 + 0x188) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xe6);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0x29c);
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x188),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x188));
  lVar3 = GetRcEngine::RcGetNum(0x3401);
  lVar4 = GetRcEngine::RcGetNum(0x3402);
  lVar5 = GetRcEngine::RcGetNum(0x3400);
  lVar6 = GetRcEngine::RcGetNum(0x33fb);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_34 = operator_new(0xbf8);
                    /* try { // try from 00d023a4 to 00d023ab has its CatchHandler @ 00d023d4 */
  ScrollListContainer::ScrollListContainer(pSStack_34,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,3)
  ;
  *(ScrollListContainer **)(param_1 + 0x18c) = pSStack_34;
  if (*(int *)(param_1 + 0x18c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xfa);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x18c));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x18c));
  pMStack_38 = *(MImg **)(param_1 + 0x18c);
  MImg::MImg(aMStack_634,0x5cd);
                    /* try { // try from 00d02638 to 00d0263f has its CatchHandler @ 00d0283c */
  MImg::MImg(aMStack_648,0x5cd);
                    /* try { // try from 00d02654 to 00d0265b has its CatchHandler @ 00d027dc */
  MImg::MImg(aMStack_65c,0x5cd);
                    /* try { // try from 00d02670 to 00d02677 has its CatchHandler @ 00d0273c */
  MImg::MImg(aMStack_670,0x5cd);
                    /* try { // try from 00d0269c to 00d026a3 has its CatchHandler @ 00d026e0 */
  ScrollListContainer::SetScrollbarImage(pMStack_38,aMStack_634,aMStack_648,aMStack_65c);
                    /* try { // try from 00d026b4 to 00d026bb has its CatchHandler @ 00d0273c */
  MImg::~MImg(aMStack_670);
                    /* try { // try from 00d026cc to 00d026d3 has its CatchHandler @ 00d027dc */
  MImg::~MImg(aMStack_65c);
                    /* try { // try from 00d02728 to 00d0272f has its CatchHandler @ 00d0283c */
  MImg::~MImg(aMStack_648);
  MImg::~MImg(aMStack_634);
  pMStack_3c = *(MImg **)(param_1 + 0x18c);
  MImg::MImg(aMStack_684,0x5cd);
                    /* try { // try from 00d027c8 to 00d027cf has its CatchHandler @ 00d02a5c */
  MImg::MImg(aMStack_698,0x5cd);
                    /* try { // try from 00d02828 to 00d0282f has its CatchHandler @ 00d029fc */
  MImg::MImg(aMStack_6ac,0x5cd);
                    /* try { // try from 00d02890 to 00d02897 has its CatchHandler @ 00d0295c */
  MImg::MImg(aMStack_6c0,0x5cd);
                    /* try { // try from 00d028bc to 00d028c3 has its CatchHandler @ 00d02900 */
  ScrollListContainer::SetScrollbarUpImage(pMStack_3c,aMStack_684,aMStack_698,aMStack_6ac);
                    /* try { // try from 00d028d4 to 00d028db has its CatchHandler @ 00d0295c */
  MImg::~MImg(aMStack_6c0);
                    /* try { // try from 00d028ec to 00d028f3 has its CatchHandler @ 00d029fc */
  MImg::~MImg(aMStack_6ac);
                    /* try { // try from 00d02948 to 00d0294f has its CatchHandler @ 00d02a5c */
  MImg::~MImg(aMStack_698);
  MImg::~MImg(aMStack_684);
  pMStack_40 = *(MImg **)(param_1 + 0x18c);
  MImg::MImg(aMStack_6d4,0x5cd);
                    /* try { // try from 00d029e8 to 00d029ef has its CatchHandler @ 00d02c7c */
  MImg::MImg(aMStack_6e8,0x5cd);
                    /* try { // try from 00d02a48 to 00d02a4f has its CatchHandler @ 00d02c1c */
  MImg::MImg(aMStack_6fc,0x5cd);
                    /* try { // try from 00d02ab0 to 00d02ab7 has its CatchHandler @ 00d02b7c */
  MImg::MImg(aMStack_710,0x5cd);
                    /* try { // try from 00d02adc to 00d02ae3 has its CatchHandler @ 00d02b20 */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_40,aMStack_6d4,aMStack_6e8,aMStack_6fc);
                    /* try { // try from 00d02af4 to 00d02afb has its CatchHandler @ 00d02b7c */
  MImg::~MImg(aMStack_710);
                    /* try { // try from 00d02b0c to 00d02b13 has its CatchHandler @ 00d02c1c */
  MImg::~MImg(aMStack_6fc);
                    /* try { // try from 00d02b68 to 00d02b6f has its CatchHandler @ 00d02c7c */
  MImg::~MImg(aMStack_6e8);
  MImg::~MImg(aMStack_6d4);
  pMStack_44 = *(MImg **)(param_1 + 0x18c);
  MImg::MImg(aMStack_724,0x5cd);
                    /* try { // try from 00d02c08 to 00d02c0f has its CatchHandler @ 00d02f64 */
  MImg::MImg(aMStack_738,0x5cd);
                    /* try { // try from 00d02c68 to 00d02c6f has its CatchHandler @ 00d02f04 */
  MImg::MImg(aMStack_74c,0x5cd);
                    /* try { // try from 00d02cd0 to 00d02cd7 has its CatchHandler @ 00d02d9c */
  MImg::MImg(aMStack_760,0x5cd);
                    /* try { // try from 00d02cfc to 00d02d03 has its CatchHandler @ 00d02d40 */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_44,aMStack_724,aMStack_738,aMStack_74c);
                    /* try { // try from 00d02d14 to 00d02d1b has its CatchHandler @ 00d02d9c */
  MImg::~MImg(aMStack_760);
                    /* try { // try from 00d02d2c to 00d02d33 has its CatchHandler @ 00d02f04 */
  MImg::~MImg(aMStack_74c);
                    /* try { // try from 00d02d88 to 00d02d8f has its CatchHandler @ 00d02f64 */
  MImg::~MImg(aMStack_738);
  MImg::~MImg(aMStack_724);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x18c));
  lVar3 = GetRcEngine::RcGetNum(0x33fe);
  lVar4 = GetRcEngine::RcGetNum(0x33ff);
  lVar5 = GetRcEngine::RcGetNum(0x33fd);
  lVar6 = GetRcEngine::RcGetNum(0x33fc);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_48 = operator_new(0xbf8);
                    /* try { // try from 00d02ef0 to 00d02ef7 has its CatchHandler @ 00d02fa8 */
  ScrollListContainer::ScrollListContainer(pSStack_48,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,4)
  ;
  *(ScrollListContainer **)(param_1 + 400) = pSStack_48;
  if (*(int *)(param_1 + 400) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x110);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 400));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 400));
  pMStack_4c = *(MImg **)(param_1 + 400);
  MImg::MImg(aMStack_774,0x5cd);
                    /* try { // try from 00d0320c to 00d03213 has its CatchHandler @ 00d03410 */
  MImg::MImg(aMStack_788,0x5cd);
                    /* try { // try from 00d03228 to 00d0322f has its CatchHandler @ 00d033b0 */
  MImg::MImg(aMStack_79c,0x5cd);
                    /* try { // try from 00d03244 to 00d0324b has its CatchHandler @ 00d03310 */
  MImg::MImg(aMStack_7b0,0x5cd);
                    /* try { // try from 00d03270 to 00d03277 has its CatchHandler @ 00d032b4 */
  ScrollListContainer::SetScrollbarImage(pMStack_4c,aMStack_774,aMStack_788,aMStack_79c);
                    /* try { // try from 00d03288 to 00d0328f has its CatchHandler @ 00d03310 */
  MImg::~MImg(aMStack_7b0);
                    /* try { // try from 00d032a0 to 00d032a7 has its CatchHandler @ 00d033b0 */
  MImg::~MImg(aMStack_79c);
                    /* try { // try from 00d032fc to 00d03303 has its CatchHandler @ 00d03410 */
  MImg::~MImg(aMStack_788);
  MImg::~MImg(aMStack_774);
  pMStack_50 = *(MImg **)(param_1 + 400);
  MImg::MImg(aMStack_7c4,0x5cd);
                    /* try { // try from 00d0339c to 00d033a3 has its CatchHandler @ 00d03630 */
  MImg::MImg(aMStack_7d8,0x5cd);
                    /* try { // try from 00d033fc to 00d03403 has its CatchHandler @ 00d035d0 */
  MImg::MImg(aMStack_7ec,0x5cd);
                    /* try { // try from 00d03464 to 00d0346b has its CatchHandler @ 00d03530 */
  MImg::MImg(aMStack_800,0x5cd);
                    /* try { // try from 00d03490 to 00d03497 has its CatchHandler @ 00d034d4 */
  ScrollListContainer::SetScrollbarUpImage(pMStack_50,aMStack_7c4,aMStack_7d8,aMStack_7ec);
                    /* try { // try from 00d034a8 to 00d034af has its CatchHandler @ 00d03530 */
  MImg::~MImg(aMStack_800);
                    /* try { // try from 00d034c0 to 00d034c7 has its CatchHandler @ 00d035d0 */
  MImg::~MImg(aMStack_7ec);
                    /* try { // try from 00d0351c to 00d03523 has its CatchHandler @ 00d03630 */
  MImg::~MImg(aMStack_7d8);
  MImg::~MImg(aMStack_7c4);
  pMStack_54 = *(MImg **)(param_1 + 400);
  MImg::MImg(aMStack_814,0x5cd);
                    /* try { // try from 00d035bc to 00d035c3 has its CatchHandler @ 00d03850 */
  MImg::MImg(aMStack_828,0x5cd);
                    /* try { // try from 00d0361c to 00d03623 has its CatchHandler @ 00d037f0 */
  MImg::MImg(aMStack_83c,0x5cd);
                    /* try { // try from 00d03684 to 00d0368b has its CatchHandler @ 00d03750 */
  MImg::MImg(aMStack_850,0x5cd);
                    /* try { // try from 00d036b0 to 00d036b7 has its CatchHandler @ 00d036f4 */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_54,aMStack_814,aMStack_828,aMStack_83c);
                    /* try { // try from 00d036c8 to 00d036cf has its CatchHandler @ 00d03750 */
  MImg::~MImg(aMStack_850);
                    /* try { // try from 00d036e0 to 00d036e7 has its CatchHandler @ 00d037f0 */
  MImg::~MImg(aMStack_83c);
                    /* try { // try from 00d0373c to 00d03743 has its CatchHandler @ 00d03850 */
  MImg::~MImg(aMStack_828);
  MImg::~MImg(aMStack_814);
  pMStack_58 = *(MImg **)(param_1 + 400);
  MImg::MImg(aMStack_864,0x5cd);
                    /* try { // try from 00d037dc to 00d037e3 has its CatchHandler @ 00d03b5c */
  MImg::MImg(aMStack_878,0x5cd);
                    /* try { // try from 00d0383c to 00d03843 has its CatchHandler @ 00d03afc */
  MImg::MImg(aMStack_88c,0x5cd);
                    /* try { // try from 00d038a4 to 00d038ab has its CatchHandler @ 00d03970 */
  MImg::MImg(aMStack_8a0,0x5cd);
                    /* try { // try from 00d038d0 to 00d038d7 has its CatchHandler @ 00d03914 */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_58,aMStack_864,aMStack_878,aMStack_88c);
                    /* try { // try from 00d038e8 to 00d038ef has its CatchHandler @ 00d03970 */
  MImg::~MImg(aMStack_8a0);
                    /* try { // try from 00d03900 to 00d03907 has its CatchHandler @ 00d03afc */
  MImg::~MImg(aMStack_88c);
                    /* try { // try from 00d0395c to 00d03963 has its CatchHandler @ 00d03b5c */
  MImg::~MImg(aMStack_878);
  MImg::~MImg(aMStack_864);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 400),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 400));
  lVar3 = GetRcEngine::RcGetNum(0x33f1);
  lVar4 = GetRcEngine::RcGetNum(0x33f2);
  lVar5 = GetRcEngine::RcGetNum(0x33f0);
  lVar6 = GetRcEngine::RcGetNum(0x33ef);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_5c = operator_new(0xbf8);
                    /* try { // try from 00d03ae8 to 00d03aef has its CatchHandler @ 00d03ba0 */
  ScrollListContainer::ScrollListContainer(pSStack_5c,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,5)
  ;
  *(ScrollListContainer **)(param_1 + 0x194) = pSStack_5c;
  if (*(int *)(param_1 + 0x194) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x127);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x194));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x194));
  pMStack_60 = *(MImg **)(param_1 + 0x194);
  MImg::MImg(aMStack_8b4,0x5cd);
                    /* try { // try from 00d03e04 to 00d03e0b has its CatchHandler @ 00d04008 */
  MImg::MImg(aMStack_8c8,0x5cd);
                    /* try { // try from 00d03e20 to 00d03e27 has its CatchHandler @ 00d03fa8 */
  MImg::MImg(aMStack_8dc,0x5cd);
                    /* try { // try from 00d03e3c to 00d03e43 has its CatchHandler @ 00d03f08 */
  MImg::MImg(aMStack_8f0,0x5cd);
                    /* try { // try from 00d03e68 to 00d03e6f has its CatchHandler @ 00d03eac */
  ScrollListContainer::SetScrollbarImage(pMStack_60,aMStack_8b4,aMStack_8c8,aMStack_8dc);
                    /* try { // try from 00d03e80 to 00d03e87 has its CatchHandler @ 00d03f08 */
  MImg::~MImg(aMStack_8f0);
                    /* try { // try from 00d03e98 to 00d03e9f has its CatchHandler @ 00d03fa8 */
  MImg::~MImg(aMStack_8dc);
                    /* try { // try from 00d03ef4 to 00d03efb has its CatchHandler @ 00d04008 */
  MImg::~MImg(aMStack_8c8);
  MImg::~MImg(aMStack_8b4);
  pMStack_64 = *(MImg **)(param_1 + 0x194);
  MImg::MImg(aMStack_904,0x5cd);
                    /* try { // try from 00d03f94 to 00d03f9b has its CatchHandler @ 00d04228 */
  MImg::MImg(aMStack_918,0x5cd);
                    /* try { // try from 00d03ff4 to 00d03ffb has its CatchHandler @ 00d041c8 */
  MImg::MImg(aMStack_92c,0x5cd);
                    /* try { // try from 00d0405c to 00d04063 has its CatchHandler @ 00d04128 */
  MImg::MImg(aMStack_940,0x5cd);
                    /* try { // try from 00d04088 to 00d0408f has its CatchHandler @ 00d040cc */
  ScrollListContainer::SetScrollbarUpImage(pMStack_64,aMStack_904,aMStack_918,aMStack_92c);
                    /* try { // try from 00d040a0 to 00d040a7 has its CatchHandler @ 00d04128 */
  MImg::~MImg(aMStack_940);
                    /* try { // try from 00d040b8 to 00d040bf has its CatchHandler @ 00d041c8 */
  MImg::~MImg(aMStack_92c);
                    /* try { // try from 00d04114 to 00d0411b has its CatchHandler @ 00d04228 */
  MImg::~MImg(aMStack_918);
  MImg::~MImg(aMStack_904);
  pMStack_68 = *(MImg **)(param_1 + 0x194);
  MImg::MImg(aMStack_954,0x5cd);
                    /* try { // try from 00d041b4 to 00d041bb has its CatchHandler @ 00d04448 */
  MImg::MImg(aMStack_968,0x5cd);
                    /* try { // try from 00d04214 to 00d0421b has its CatchHandler @ 00d043e8 */
  MImg::MImg(aMStack_97c,0x5cd);
                    /* try { // try from 00d0427c to 00d04283 has its CatchHandler @ 00d04348 */
  MImg::MImg(aMStack_990,0x5cd);
                    /* try { // try from 00d042a8 to 00d042af has its CatchHandler @ 00d042ec */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_68,aMStack_954,aMStack_968,aMStack_97c);
                    /* try { // try from 00d042c0 to 00d042c7 has its CatchHandler @ 00d04348 */
  MImg::~MImg(aMStack_990);
                    /* try { // try from 00d042d8 to 00d042df has its CatchHandler @ 00d043e8 */
  MImg::~MImg(aMStack_97c);
                    /* try { // try from 00d04334 to 00d0433b has its CatchHandler @ 00d04448 */
  MImg::~MImg(aMStack_968);
  MImg::~MImg(aMStack_954);
  pMStack_6c = *(MImg **)(param_1 + 0x194);
  MImg::MImg(aMStack_9a4,0x5cd);
                    /* try { // try from 00d043d4 to 00d043db has its CatchHandler @ 00d04754 */
  MImg::MImg(aMStack_9b8,0x5cd);
                    /* try { // try from 00d04434 to 00d0443b has its CatchHandler @ 00d046f4 */
  MImg::MImg(aMStack_9cc,0x5cd);
                    /* try { // try from 00d0449c to 00d044a3 has its CatchHandler @ 00d04568 */
  MImg::MImg(aMStack_9e0,0x5cd);
                    /* try { // try from 00d044c8 to 00d044cf has its CatchHandler @ 00d0450c */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_6c,aMStack_9a4,aMStack_9b8,aMStack_9cc);
                    /* try { // try from 00d044e0 to 00d044e7 has its CatchHandler @ 00d04568 */
  MImg::~MImg(aMStack_9e0);
                    /* try { // try from 00d044f8 to 00d044ff has its CatchHandler @ 00d046f4 */
  MImg::~MImg(aMStack_9cc);
                    /* try { // try from 00d04554 to 00d0455b has its CatchHandler @ 00d04754 */
  MImg::~MImg(aMStack_9b8);
  MImg::~MImg(aMStack_9a4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x194),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x194));
  lVar3 = GetRcEngine::RcGetNum(0x33f5);
  lVar4 = GetRcEngine::RcGetNum(0x33f6);
  lVar5 = GetRcEngine::RcGetNum(0x33f4);
  lVar6 = GetRcEngine::RcGetNum(0x33f3);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_70 = operator_new(0xbf8);
                    /* try { // try from 00d046e0 to 00d046e7 has its CatchHandler @ 00d04798 */
  ScrollListContainer::ScrollListContainer(pSStack_70,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,6)
  ;
  *(ScrollListContainer **)(param_1 + 0x198) = pSStack_70;
  if (*(int *)(param_1 + 0x198) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x13e);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x198) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x198));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x198));
  pMStack_74 = *(MImg **)(param_1 + 0x198);
  MImg::MImg(aMStack_9f4,0x5cd);
                    /* try { // try from 00d049fc to 00d04a03 has its CatchHandler @ 00d04c00 */
  MImg::MImg(aMStack_a08,0x5cd);
                    /* try { // try from 00d04a18 to 00d04a1f has its CatchHandler @ 00d04ba0 */
  MImg::MImg(aMStack_a1c,0x5cd);
                    /* try { // try from 00d04a34 to 00d04a3b has its CatchHandler @ 00d04b00 */
  MImg::MImg(aMStack_a30,0x5cd);
                    /* try { // try from 00d04a60 to 00d04a67 has its CatchHandler @ 00d04aa4 */
  ScrollListContainer::SetScrollbarImage(pMStack_74,aMStack_9f4,aMStack_a08,aMStack_a1c);
                    /* try { // try from 00d04a78 to 00d04a7f has its CatchHandler @ 00d04b00 */
  MImg::~MImg(aMStack_a30);
                    /* try { // try from 00d04a90 to 00d04a97 has its CatchHandler @ 00d04ba0 */
  MImg::~MImg(aMStack_a1c);
                    /* try { // try from 00d04aec to 00d04af3 has its CatchHandler @ 00d04c00 */
  MImg::~MImg(aMStack_a08);
  MImg::~MImg(aMStack_9f4);
  pMStack_78 = *(MImg **)(param_1 + 0x198);
  MImg::MImg(aMStack_a44,0x5cd);
                    /* try { // try from 00d04b8c to 00d04b93 has its CatchHandler @ 00d04e20 */
  MImg::MImg(aMStack_a58,0x5cd);
                    /* try { // try from 00d04bec to 00d04bf3 has its CatchHandler @ 00d04dc0 */
  MImg::MImg(aMStack_a6c,0x5cd);
                    /* try { // try from 00d04c54 to 00d04c5b has its CatchHandler @ 00d04d20 */
  MImg::MImg(aMStack_a80,0x5cd);
                    /* try { // try from 00d04c80 to 00d04c87 has its CatchHandler @ 00d04cc4 */
  ScrollListContainer::SetScrollbarUpImage(pMStack_78,aMStack_a44,aMStack_a58,aMStack_a6c);
                    /* try { // try from 00d04c98 to 00d04c9f has its CatchHandler @ 00d04d20 */
  MImg::~MImg(aMStack_a80);
                    /* try { // try from 00d04cb0 to 00d04cb7 has its CatchHandler @ 00d04dc0 */
  MImg::~MImg(aMStack_a6c);
                    /* try { // try from 00d04d0c to 00d04d13 has its CatchHandler @ 00d04e20 */
  MImg::~MImg(aMStack_a58);
  MImg::~MImg(aMStack_a44);
  pMStack_7c = *(MImg **)(param_1 + 0x198);
  MImg::MImg(aMStack_a94,0x5cd);
                    /* try { // try from 00d04dac to 00d04db3 has its CatchHandler @ 00d05040 */
  MImg::MImg(aMStack_aa8,0x5cd);
                    /* try { // try from 00d04e0c to 00d04e13 has its CatchHandler @ 00d04fe0 */
  MImg::MImg(aMStack_abc,0x5cd);
                    /* try { // try from 00d04e74 to 00d04e7b has its CatchHandler @ 00d04f40 */
  MImg::MImg(aMStack_ad0,0x5cd);
                    /* try { // try from 00d04ea0 to 00d04ea7 has its CatchHandler @ 00d04ee4 */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_7c,aMStack_a94,aMStack_aa8,aMStack_abc);
                    /* try { // try from 00d04eb8 to 00d04ebf has its CatchHandler @ 00d04f40 */
  MImg::~MImg(aMStack_ad0);
                    /* try { // try from 00d04ed0 to 00d04ed7 has its CatchHandler @ 00d04fe0 */
  MImg::~MImg(aMStack_abc);
                    /* try { // try from 00d04f2c to 00d04f33 has its CatchHandler @ 00d05040 */
  MImg::~MImg(aMStack_aa8);
  MImg::~MImg(aMStack_a94);
  pMStack_80 = *(MImg **)(param_1 + 0x198);
  MImg::MImg(aMStack_ae4,0x5cd);
                    /* try { // try from 00d04fcc to 00d04fd3 has its CatchHandler @ 00d0534c */
  MImg::MImg(aMStack_af8,0x5cd);
                    /* try { // try from 00d0502c to 00d05033 has its CatchHandler @ 00d052ec */
  MImg::MImg(aMStack_b0c,0x5cd);
                    /* try { // try from 00d05094 to 00d0509b has its CatchHandler @ 00d05160 */
  MImg::MImg(aMStack_b20,0x5cd);
                    /* try { // try from 00d050c0 to 00d050c7 has its CatchHandler @ 00d05104 */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_80,aMStack_ae4,aMStack_af8,aMStack_b0c);
                    /* try { // try from 00d050d8 to 00d050df has its CatchHandler @ 00d05160 */
  MImg::~MImg(aMStack_b20);
                    /* try { // try from 00d050f0 to 00d050f7 has its CatchHandler @ 00d052ec */
  MImg::~MImg(aMStack_b0c);
                    /* try { // try from 00d0514c to 00d05153 has its CatchHandler @ 00d0534c */
  MImg::~MImg(aMStack_af8);
  MImg::~MImg(aMStack_ae4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x198),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x198));
  lVar3 = GetRcEngine::RcGetNum(0x33f9);
  lVar4 = GetRcEngine::RcGetNum(0x33fa);
  lVar5 = GetRcEngine::RcGetNum(0x33f8);
  lVar6 = GetRcEngine::RcGetNum(0x33f7);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_84 = operator_new(0xbf8);
                    /* try { // try from 00d052d8 to 00d052df has its CatchHandler @ 00d05390 */
  ScrollListContainer::ScrollListContainer(pSStack_84,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,7)
  ;
  *(ScrollListContainer **)(param_1 + 0x19c) = pSStack_84;
  if (*(int *)(param_1 + 0x19c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x155);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x19c));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x19c));
  pMStack_88 = *(MImg **)(param_1 + 0x19c);
  MImg::MImg(aMStack_b34,0x5cd);
                    /* try { // try from 00d055f4 to 00d055fb has its CatchHandler @ 00d057f8 */
  MImg::MImg(aMStack_b48,0x5cd);
                    /* try { // try from 00d05610 to 00d05617 has its CatchHandler @ 00d05798 */
  MImg::MImg(aMStack_b5c,0x5cd);
                    /* try { // try from 00d0562c to 00d05633 has its CatchHandler @ 00d056f8 */
  MImg::MImg(aMStack_b70,0x5cd);
                    /* try { // try from 00d05658 to 00d0565f has its CatchHandler @ 00d0569c */
  ScrollListContainer::SetScrollbarImage(pMStack_88,aMStack_b34,aMStack_b48,aMStack_b5c);
                    /* try { // try from 00d05670 to 00d05677 has its CatchHandler @ 00d056f8 */
  MImg::~MImg(aMStack_b70);
                    /* try { // try from 00d05688 to 00d0568f has its CatchHandler @ 00d05798 */
  MImg::~MImg(aMStack_b5c);
                    /* try { // try from 00d056e4 to 00d056eb has its CatchHandler @ 00d057f8 */
  MImg::~MImg(aMStack_b48);
  MImg::~MImg(aMStack_b34);
  pMStack_8c = *(MImg **)(param_1 + 0x19c);
  MImg::MImg(aMStack_b84,0x5cd);
                    /* try { // try from 00d05784 to 00d0578b has its CatchHandler @ 00d05a18 */
  MImg::MImg(aMStack_b98,0x5cd);
                    /* try { // try from 00d057e4 to 00d057eb has its CatchHandler @ 00d059b8 */
  MImg::MImg(aMStack_bac,0x5cd);
                    /* try { // try from 00d0584c to 00d05853 has its CatchHandler @ 00d05918 */
  MImg::MImg(aMStack_bc0,0x5cd);
                    /* try { // try from 00d05878 to 00d0587f has its CatchHandler @ 00d058bc */
  ScrollListContainer::SetScrollbarUpImage(pMStack_8c,aMStack_b84,aMStack_b98,aMStack_bac);
                    /* try { // try from 00d05890 to 00d05897 has its CatchHandler @ 00d05918 */
  MImg::~MImg(aMStack_bc0);
                    /* try { // try from 00d058a8 to 00d058af has its CatchHandler @ 00d059b8 */
  MImg::~MImg(aMStack_bac);
                    /* try { // try from 00d05904 to 00d0590b has its CatchHandler @ 00d05a18 */
  MImg::~MImg(aMStack_b98);
  MImg::~MImg(aMStack_b84);
  pMStack_90 = *(MImg **)(param_1 + 0x19c);
  MImg::MImg(aMStack_bd4,0x5cd);
                    /* try { // try from 00d059a4 to 00d059ab has its CatchHandler @ 00d05c38 */
  MImg::MImg(aMStack_be8,0x5cd);
                    /* try { // try from 00d05a04 to 00d05a0b has its CatchHandler @ 00d05bd8 */
  MImg::MImg(aMStack_bfc,0x5cd);
                    /* try { // try from 00d05a6c to 00d05a73 has its CatchHandler @ 00d05b38 */
  MImg::MImg(aMStack_c10,0x5cd);
                    /* try { // try from 00d05a98 to 00d05a9f has its CatchHandler @ 00d05adc */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_90,aMStack_bd4,aMStack_be8,aMStack_bfc);
                    /* try { // try from 00d05ab0 to 00d05ab7 has its CatchHandler @ 00d05b38 */
  MImg::~MImg(aMStack_c10);
                    /* try { // try from 00d05ac8 to 00d05acf has its CatchHandler @ 00d05bd8 */
  MImg::~MImg(aMStack_bfc);
                    /* try { // try from 00d05b24 to 00d05b2b has its CatchHandler @ 00d05c38 */
  MImg::~MImg(aMStack_be8);
  MImg::~MImg(aMStack_bd4);
  pMStack_94 = *(MImg **)(param_1 + 0x19c);
  MImg::MImg(aMStack_c24,0x5cd);
                    /* try { // try from 00d05bc4 to 00d05bcb has its CatchHandler @ 00d05f44 */
  MImg::MImg(aMStack_c38,0x5cd);
                    /* try { // try from 00d05c24 to 00d05c2b has its CatchHandler @ 00d05ee4 */
  MImg::MImg(aMStack_c4c,0x5cd);
                    /* try { // try from 00d05c8c to 00d05c93 has its CatchHandler @ 00d05d58 */
  MImg::MImg(aMStack_c60,0x5cd);
                    /* try { // try from 00d05cb8 to 00d05cbf has its CatchHandler @ 00d05cfc */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_94,aMStack_c24,aMStack_c38,aMStack_c4c);
                    /* try { // try from 00d05cd0 to 00d05cd7 has its CatchHandler @ 00d05d58 */
  MImg::~MImg(aMStack_c60);
                    /* try { // try from 00d05ce8 to 00d05cef has its CatchHandler @ 00d05ee4 */
  MImg::~MImg(aMStack_c4c);
                    /* try { // try from 00d05d44 to 00d05d4b has its CatchHandler @ 00d05f44 */
  MImg::~MImg(aMStack_c38);
  MImg::~MImg(aMStack_c24);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x19c),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x19c));
  lVar3 = GetRcEngine::RcGetNum(0x33ed);
  lVar4 = GetRcEngine::RcGetNum(0x33ee);
  lVar5 = GetRcEngine::RcGetNum(0x33ec);
  lVar6 = GetRcEngine::RcGetNum(0x33eb);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_98 = operator_new(0xbf8);
                    /* try { // try from 00d05ed0 to 00d05ed7 has its CatchHandler @ 00d05f88 */
  ScrollListContainer::ScrollListContainer(pSStack_98,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,8)
  ;
  *(ScrollListContainer **)(param_1 + 0x1a0) = pSStack_98;
  if (*(int *)(param_1 + 0x1a0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x16c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1a0) + 0x39) = 0;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x1a0));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x1a0));
  pMStack_9c = *(MImg **)(param_1 + 0x1a0);
  MImg::MImg(aMStack_c74,0x5cd);
                    /* try { // try from 00d061ec to 00d061f3 has its CatchHandler @ 00d063f0 */
  MImg::MImg(aMStack_c88,0x5cd);
                    /* try { // try from 00d06208 to 00d0620f has its CatchHandler @ 00d06390 */
  MImg::MImg(aMStack_c9c,0x5cd);
                    /* try { // try from 00d06224 to 00d0622b has its CatchHandler @ 00d062f0 */
  MImg::MImg(aMStack_cb0,0x5cd);
                    /* try { // try from 00d06250 to 00d06257 has its CatchHandler @ 00d06294 */
  ScrollListContainer::SetScrollbarImage(pMStack_9c,aMStack_c74,aMStack_c88,aMStack_c9c);
                    /* try { // try from 00d06268 to 00d0626f has its CatchHandler @ 00d062f0 */
  MImg::~MImg(aMStack_cb0);
                    /* try { // try from 00d06280 to 00d06287 has its CatchHandler @ 00d06390 */
  MImg::~MImg(aMStack_c9c);
                    /* try { // try from 00d062dc to 00d062e3 has its CatchHandler @ 00d063f0 */
  MImg::~MImg(aMStack_c88);
  MImg::~MImg(aMStack_c74);
  pMStack_a0 = *(MImg **)(param_1 + 0x1a0);
  MImg::MImg(aMStack_cc4,0x5cd);
                    /* try { // try from 00d0637c to 00d06383 has its CatchHandler @ 00d06610 */
  MImg::MImg(aMStack_cd8,0x5cd);
                    /* try { // try from 00d063dc to 00d063e3 has its CatchHandler @ 00d065b0 */
  MImg::MImg(aMStack_cec,0x5cd);
                    /* try { // try from 00d06444 to 00d0644b has its CatchHandler @ 00d06510 */
  MImg::MImg(aMStack_d00,0x5cd);
                    /* try { // try from 00d06470 to 00d06477 has its CatchHandler @ 00d064b4 */
  ScrollListContainer::SetScrollbarUpImage(pMStack_a0,aMStack_cc4,aMStack_cd8,aMStack_cec);
                    /* try { // try from 00d06488 to 00d0648f has its CatchHandler @ 00d06510 */
  MImg::~MImg(aMStack_d00);
                    /* try { // try from 00d064a0 to 00d064a7 has its CatchHandler @ 00d065b0 */
  MImg::~MImg(aMStack_cec);
                    /* try { // try from 00d064fc to 00d06503 has its CatchHandler @ 00d06610 */
  MImg::~MImg(aMStack_cd8);
  MImg::~MImg(aMStack_cc4);
  pMStack_a4 = *(MImg **)(param_1 + 0x1a0);
  MImg::MImg(aMStack_d14,0x5cd);
                    /* try { // try from 00d0659c to 00d065a3 has its CatchHandler @ 00d06830 */
  MImg::MImg(aMStack_d28,0x5cd);
                    /* try { // try from 00d065fc to 00d06603 has its CatchHandler @ 00d067d0 */
  MImg::MImg(aMStack_d3c,0x5cd);
                    /* try { // try from 00d06664 to 00d0666b has its CatchHandler @ 00d06730 */
  MImg::MImg(aMStack_d50,0x5cd);
                    /* try { // try from 00d06690 to 00d06697 has its CatchHandler @ 00d066d4 */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_a4,aMStack_d14,aMStack_d28,aMStack_d3c);
                    /* try { // try from 00d066a8 to 00d066af has its CatchHandler @ 00d06730 */
  MImg::~MImg(aMStack_d50);
                    /* try { // try from 00d066c0 to 00d066c7 has its CatchHandler @ 00d067d0 */
  MImg::~MImg(aMStack_d3c);
                    /* try { // try from 00d0671c to 00d06723 has its CatchHandler @ 00d06830 */
  MImg::~MImg(aMStack_d28);
  MImg::~MImg(aMStack_d14);
  pMStack_a8 = *(MImg **)(param_1 + 0x1a0);
  MImg::MImg(aMStack_d64,0x5cd);
                    /* try { // try from 00d067bc to 00d067c3 has its CatchHandler @ 00d06b3c */
  MImg::MImg(aMStack_d78,0x5cd);
                    /* try { // try from 00d0681c to 00d06823 has its CatchHandler @ 00d06adc */
  MImg::MImg(aMStack_d8c,0x5cd);
                    /* try { // try from 00d06884 to 00d0688b has its CatchHandler @ 00d06950 */
  MImg::MImg(aMStack_da0,0x5cd);
                    /* try { // try from 00d068b0 to 00d068b7 has its CatchHandler @ 00d068f4 */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_a8,aMStack_d64,aMStack_d78,aMStack_d8c);
                    /* try { // try from 00d068c8 to 00d068cf has its CatchHandler @ 00d06950 */
  MImg::~MImg(aMStack_da0);
                    /* try { // try from 00d068e0 to 00d068e7 has its CatchHandler @ 00d06adc */
  MImg::~MImg(aMStack_d8c);
                    /* try { // try from 00d0693c to 00d06943 has its CatchHandler @ 00d06b3c */
  MImg::~MImg(aMStack_d78);
  MImg::~MImg(aMStack_d64);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1a0),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x1a0));
  lVar3 = GetRcEngine::RcGetNum(0x341d);
  lVar4 = GetRcEngine::RcGetNum(0x341e);
  lVar5 = GetRcEngine::RcGetNum(0x341c);
  lVar6 = GetRcEngine::RcGetNum(0x341b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_ac = operator_new(0x250);
                    /* try { // try from 00d06ac8 to 00d06acf has its CatchHandler @ 00d06b80 */
  TextBox::TextBox(pTStack_ac,*(MWidget **)(param_1 + 0x38),a_Stack_620,0,9);
  *(TextBox **)(param_1 + 0x1a4) = pTStack_ac;
  if (*(int *)(param_1 + 0x1a4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x183);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1a4) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar7 = GetRcEngine::RcGetColor(0x38);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar7 = GetRcEngine::RcGetColor(0x38);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar7 = GetRcEngine::RcGetColor(0x38);
  *(undefined4 *)(iVar15 + 0x88) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x1a4));
  lVar3 = GetRcEngine::RcGetNum(0x339b);
  lVar4 = GetRcEngine::RcGetNum(0x339c);
  lVar5 = GetRcEngine::RcGetNum(0x339a);
  lVar6 = GetRcEngine::RcGetNum(0x3397);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_b0 = operator_new(0x514);
                    /* try { // try from 00d06fd4 to 00d06fdb has its CatchHandler @ 00d07004 */
  ImageButton::ImageButton(pIStack_b0,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,10);
  *(ImageButton **)(param_1 + 0x1a8) = pIStack_b0;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x1a0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1a8);
  uVar8 = GetRcEngine::RcGetNum(0x3399);
  GetRcEngine::RcGetNum(0x3398);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_b4 = *(MImg **)(param_1 + 0x1a8);
  MImg::MImg(aMStack_db4,0x5cd);
                    /* try { // try from 00d073d4 to 00d073db has its CatchHandler @ 00d076a0 */
  MImg::MImg(aMStack_dc8,0x5cd);
                    /* try { // try from 00d073f0 to 00d073f7 has its CatchHandler @ 00d07640 */
  MImg::MImg(aMStack_ddc,0x5cd);
                    /* try { // try from 00d0740c to 00d07413 has its CatchHandler @ 00d074d8 */
  MImg::MImg(aMStack_df0,0x5cd);
                    /* try { // try from 00d07438 to 00d0743f has its CatchHandler @ 00d0747c */
  ImageButton::SetImg(pMStack_b4,aMStack_db4,aMStack_dc8,aMStack_ddc);
                    /* try { // try from 00d07450 to 00d07457 has its CatchHandler @ 00d074d8 */
  MImg::~MImg(aMStack_df0);
                    /* try { // try from 00d07468 to 00d0746f has its CatchHandler @ 00d07640 */
  MImg::~MImg(aMStack_ddc);
                    /* try { // try from 00d074c4 to 00d074cb has its CatchHandler @ 00d076a0 */
  MImg::~MImg(aMStack_dc8);
  MImg::~MImg(aMStack_db4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1a8));
  lVar3 = GetRcEngine::RcGetNum(0x3365);
  lVar4 = GetRcEngine::RcGetNum(0x3366);
  lVar5 = GetRcEngine::RcGetNum(0x3364);
  lVar6 = GetRcEngine::RcGetNum(0x3361);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_b8 = operator_new(0x514);
                    /* try { // try from 00d0762c to 00d07633 has its CatchHandler @ 00d076e4 */
  ImageButton::ImageButton(pIStack_b8,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0xb);
  *(ImageButton **)(param_1 + 0x1ac) = pIStack_b8;
  if (*(int *)(param_1 + 0x1ac) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x1bf);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1ac);
  uVar8 = GetRcEngine::RcGetNum(0x3363);
  GetRcEngine::RcGetNum(0x3362);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_bc = *(MImg **)(param_1 + 0x1ac);
  MImg::MImg(aMStack_e04,0x5cd);
                    /* try { // try from 00d07ab4 to 00d07abb has its CatchHandler @ 00d07d80 */
  MImg::MImg(aMStack_e18,0x5cd);
                    /* try { // try from 00d07ad0 to 00d07ad7 has its CatchHandler @ 00d07d20 */
  MImg::MImg(aMStack_e2c,0x5cd);
                    /* try { // try from 00d07aec to 00d07af3 has its CatchHandler @ 00d07bb8 */
  MImg::MImg(aMStack_e40,0x5cd);
                    /* try { // try from 00d07b18 to 00d07b1f has its CatchHandler @ 00d07b5c */
  ImageButton::SetImg(pMStack_bc,aMStack_e04,aMStack_e18,aMStack_e2c);
                    /* try { // try from 00d07b30 to 00d07b37 has its CatchHandler @ 00d07bb8 */
  MImg::~MImg(aMStack_e40);
                    /* try { // try from 00d07b48 to 00d07b4f has its CatchHandler @ 00d07d20 */
  MImg::~MImg(aMStack_e2c);
                    /* try { // try from 00d07ba4 to 00d07bab has its CatchHandler @ 00d07d80 */
  MImg::~MImg(aMStack_e18);
  MImg::~MImg(aMStack_e04);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1ac));
  lVar3 = GetRcEngine::RcGetNum(0x336b);
  lVar4 = GetRcEngine::RcGetNum(0x336c);
  lVar5 = GetRcEngine::RcGetNum(0x336a);
  lVar6 = GetRcEngine::RcGetNum(0x3367);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_c0 = operator_new(0x514);
                    /* try { // try from 00d07d0c to 00d07d13 has its CatchHandler @ 00d07dc4 */
  ImageButton::ImageButton(pIStack_c0,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0xc);
  *(ImageButton **)(param_1 + 0x1b0) = pIStack_c0;
  if (*(int *)(param_1 + 0x1b0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x1de);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b0) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1b0);
  uVar8 = GetRcEngine::RcGetNum(0x3369);
  GetRcEngine::RcGetNum(0x3368);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_c4 = *(MImg **)(param_1 + 0x1b0);
  MImg::MImg(aMStack_e54,0x5cd);
                    /* try { // try from 00d08194 to 00d0819b has its CatchHandler @ 00d08460 */
  MImg::MImg(aMStack_e68,0x5cd);
                    /* try { // try from 00d081b0 to 00d081b7 has its CatchHandler @ 00d08400 */
  MImg::MImg(aMStack_e7c,0x5cd);
                    /* try { // try from 00d081cc to 00d081d3 has its CatchHandler @ 00d08298 */
  MImg::MImg(aMStack_e90,0x5cd);
                    /* try { // try from 00d081f8 to 00d081ff has its CatchHandler @ 00d0823c */
  ImageButton::SetImg(pMStack_c4,aMStack_e54,aMStack_e68,aMStack_e7c);
                    /* try { // try from 00d08210 to 00d08217 has its CatchHandler @ 00d08298 */
  MImg::~MImg(aMStack_e90);
                    /* try { // try from 00d08228 to 00d0822f has its CatchHandler @ 00d08400 */
  MImg::~MImg(aMStack_e7c);
                    /* try { // try from 00d08284 to 00d0828b has its CatchHandler @ 00d08460 */
  MImg::~MImg(aMStack_e68);
  MImg::~MImg(aMStack_e54);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1b0));
  lVar3 = GetRcEngine::RcGetNum(0x3371);
  lVar4 = GetRcEngine::RcGetNum(0x3372);
  lVar5 = GetRcEngine::RcGetNum(0x3370);
  lVar6 = GetRcEngine::RcGetNum(0x336d);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_c8 = operator_new(0x514);
                    /* try { // try from 00d083ec to 00d083f3 has its CatchHandler @ 00d084a4 */
  ImageButton::ImageButton(pIStack_c8,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0xd);
  *(ImageButton **)(param_1 + 0x1b4) = pIStack_c8;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x1fd);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1b4);
  uVar8 = GetRcEngine::RcGetNum(0x336f);
  GetRcEngine::RcGetNum(0x336e);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_cc = *(MImg **)(param_1 + 0x1b4);
  MImg::MImg(aMStack_ea4,0x5cd);
                    /* try { // try from 00d08874 to 00d0887b has its CatchHandler @ 00d08b40 */
  MImg::MImg(aMStack_eb8,0x5cd);
                    /* try { // try from 00d08890 to 00d08897 has its CatchHandler @ 00d08ae0 */
  MImg::MImg(aMStack_ecc,0x5cd);
                    /* try { // try from 00d088ac to 00d088b3 has its CatchHandler @ 00d08978 */
  MImg::MImg(aMStack_ee0,0x5cd);
                    /* try { // try from 00d088d8 to 00d088df has its CatchHandler @ 00d0891c */
  ImageButton::SetImg(pMStack_cc,aMStack_ea4,aMStack_eb8,aMStack_ecc);
                    /* try { // try from 00d088f0 to 00d088f7 has its CatchHandler @ 00d08978 */
  MImg::~MImg(aMStack_ee0);
                    /* try { // try from 00d08908 to 00d0890f has its CatchHandler @ 00d08ae0 */
  MImg::~MImg(aMStack_ecc);
                    /* try { // try from 00d08964 to 00d0896b has its CatchHandler @ 00d08b40 */
  MImg::~MImg(aMStack_eb8);
  MImg::~MImg(aMStack_ea4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1b4));
  lVar3 = GetRcEngine::RcGetNum(0x335f);
  lVar4 = GetRcEngine::RcGetNum(0x3360);
  lVar5 = GetRcEngine::RcGetNum(0x335e);
  lVar6 = GetRcEngine::RcGetNum(0x335b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_d0 = operator_new(0x514);
                    /* try { // try from 00d08acc to 00d08ad3 has its CatchHandler @ 00d08b84 */
  ImageButton::ImageButton(pIStack_d0,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0xe);
  *(ImageButton **)(param_1 + 0x1b8) = pIStack_d0;
  if (*(int *)(param_1 + 0x1b8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x21c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1b8);
  uVar8 = GetRcEngine::RcGetNum(0x335d);
  GetRcEngine::RcGetNum(0x335c);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_d4 = *(MImg **)(param_1 + 0x1b8);
  MImg::MImg(aMStack_ef4,0x5cd);
                    /* try { // try from 00d08f54 to 00d08f5b has its CatchHandler @ 00d09220 */
  MImg::MImg(aMStack_f08,0x5cd);
                    /* try { // try from 00d08f70 to 00d08f77 has its CatchHandler @ 00d091c0 */
  MImg::MImg(aMStack_f1c,0x5cd);
                    /* try { // try from 00d08f8c to 00d08f93 has its CatchHandler @ 00d09058 */
  MImg::MImg(aMStack_f30,0x5cd);
                    /* try { // try from 00d08fb8 to 00d08fbf has its CatchHandler @ 00d08ffc */
  ImageButton::SetImg(pMStack_d4,aMStack_ef4,aMStack_f08,aMStack_f1c);
                    /* try { // try from 00d08fd0 to 00d08fd7 has its CatchHandler @ 00d09058 */
  MImg::~MImg(aMStack_f30);
                    /* try { // try from 00d08fe8 to 00d08fef has its CatchHandler @ 00d091c0 */
  MImg::~MImg(aMStack_f1c);
                    /* try { // try from 00d09044 to 00d0904b has its CatchHandler @ 00d09220 */
  MImg::~MImg(aMStack_f08);
  MImg::~MImg(aMStack_ef4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1b8));
  lVar3 = GetRcEngine::RcGetNum(0x338f);
  lVar4 = GetRcEngine::RcGetNum(0x3390);
  lVar5 = GetRcEngine::RcGetNum(0x338e);
  lVar6 = GetRcEngine::RcGetNum(0x338b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_d8 = operator_new(0x514);
                    /* try { // try from 00d091ac to 00d091b3 has its CatchHandler @ 00d09264 */
  ImageButton::ImageButton(pIStack_d8,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0xf);
  *(ImageButton **)(param_1 + 0x1bc) = pIStack_d8;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x23b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1bc) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1bc);
  uVar8 = GetRcEngine::RcGetNum(0x338d);
  GetRcEngine::RcGetNum(0x338c);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_dc = *(MImg **)(param_1 + 0x1bc);
  MImg::MImg(aMStack_f44,0x5cd);
                    /* try { // try from 00d09634 to 00d0963b has its CatchHandler @ 00d09900 */
  MImg::MImg(aMStack_f58,0x5cd);
                    /* try { // try from 00d09650 to 00d09657 has its CatchHandler @ 00d098a0 */
  MImg::MImg(aMStack_f6c,0x5cd);
                    /* try { // try from 00d0966c to 00d09673 has its CatchHandler @ 00d09738 */
  MImg::MImg(aMStack_f80,0x5cd);
                    /* try { // try from 00d09698 to 00d0969f has its CatchHandler @ 00d096dc */
  ImageButton::SetImg(pMStack_dc,aMStack_f44,aMStack_f58,aMStack_f6c);
                    /* try { // try from 00d096b0 to 00d096b7 has its CatchHandler @ 00d09738 */
  MImg::~MImg(aMStack_f80);
                    /* try { // try from 00d096c8 to 00d096cf has its CatchHandler @ 00d098a0 */
  MImg::~MImg(aMStack_f6c);
                    /* try { // try from 00d09724 to 00d0972b has its CatchHandler @ 00d09900 */
  MImg::~MImg(aMStack_f58);
  MImg::~MImg(aMStack_f44);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1bc));
  lVar3 = GetRcEngine::RcGetNum(0x32f1);
  lVar4 = GetRcEngine::RcGetNum(0x32f2);
  lVar5 = GetRcEngine::RcGetNum(0x32f0);
  lVar6 = GetRcEngine::RcGetNum(0x32ef);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_e0 = operator_new(0x264);
                    /* try { // try from 00d0988c to 00d09893 has its CatchHandler @ 00d09944 */
  AbsContainer::AbsContainer(pAStack_e0,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0x10);
  *(AbsContainer **)(param_1 + 0x1c0) = pAStack_e0;
  if (*(int *)(param_1 + 0x1c0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x25a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1c0));
  lVar3 = GetRcEngine::RcGetNum(0x3351);
  lVar4 = GetRcEngine::RcGetNum(0x3352);
  lVar5 = GetRcEngine::RcGetNum(0x3350);
  lVar6 = GetRcEngine::RcGetNum(0x334f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_e4 = operator_new(0x270);
                    /* try { // try from 00d09c40 to 00d09c47 has its CatchHandler @ 00d09c70 */
  ComboButton::ComboButton(pCStack_e4,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0x11);
  *(ComboButton **)(param_1 + 0x1c4) = pCStack_e4;
  if (*(int *)(param_1 + 0x1c4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x26b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1c4) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c4) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1c4) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1c4));
  lVar3 = GetRcEngine::RcGetNum(0x3331);
  lVar4 = GetRcEngine::RcGetNum(0x3332);
  lVar5 = GetRcEngine::RcGetNum(0x3330);
  lVar6 = GetRcEngine::RcGetNum(0x332f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_e8 = operator_new(0x270);
                    /* try { // try from 00d0a500 to 00d0a507 has its CatchHandler @ 00d0a530 */
  ComboButton::ComboButton(pCStack_e8,*(MWidget **)(param_1 + 0x18c),a_Stack_620,0,0x12);
  *(ComboButton **)(param_1 + 0x1c8) = pCStack_e8;
  if (*(int *)(param_1 + 0x1c8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x2a7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1c8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1c8));
  lVar3 = GetRcEngine::RcGetNum(0x3419);
  lVar4 = GetRcEngine::RcGetNum(0x341a);
  lVar5 = GetRcEngine::RcGetNum(0x3418);
  lVar6 = GetRcEngine::RcGetNum(0x3417);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_ec = operator_new(0x250);
                    /* try { // try from 00d0adc0 to 00d0adc7 has its CatchHandler @ 00d0adf0 */
  TextBox::TextBox(pTStack_ec,*(MWidget **)(param_1 + 0x1c0),a_Stack_620,0,0x13);
  *(TextBox **)(param_1 + 0x1cc) = pTStack_ec;
  if (*(int *)(param_1 + 0x1cc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x2e3);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1cc) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1cc);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1cc));
  lVar3 = GetRcEngine::RcGetNum(0x33ad);
  lVar4 = GetRcEngine::RcGetNum(0x33ae);
  lVar5 = GetRcEngine::RcGetNum(0x33ac);
  lVar6 = GetRcEngine::RcGetNum(0x33a9);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_f0 = operator_new(0x514);
                    /* try { // try from 00d0b250 to 00d0b257 has its CatchHandler @ 00d0b280 */
  ImageButton::ImageButton(pIStack_f0,*(MWidget **)(param_1 + 400),a_Stack_620,0,0x14);
  *(ImageButton **)(param_1 + 0x1d0) = pIStack_f0;
  if (*(int *)(param_1 + 0x1d0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x300);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1d0) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1d0);
  uVar8 = GetRcEngine::RcGetNum(0x33ab);
  GetRcEngine::RcGetNum(0x33aa);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_f4 = *(MImg **)(param_1 + 0x1d0);
  MImg::MImg(aMStack_f94,0x5cd);
                    /* try { // try from 00d0b650 to 00d0b657 has its CatchHandler @ 00d0b91c */
  MImg::MImg(aMStack_fa8,0x5cd);
                    /* try { // try from 00d0b66c to 00d0b673 has its CatchHandler @ 00d0b8bc */
  MImg::MImg(aMStack_fbc,0x5cd);
                    /* try { // try from 00d0b688 to 00d0b68f has its CatchHandler @ 00d0b754 */
  MImg::MImg(aMStack_fd0,0x5cd);
                    /* try { // try from 00d0b6b4 to 00d0b6bb has its CatchHandler @ 00d0b6f8 */
  ImageButton::SetImg(pMStack_f4,aMStack_f94,aMStack_fa8,aMStack_fbc);
                    /* try { // try from 00d0b6cc to 00d0b6d3 has its CatchHandler @ 00d0b754 */
  MImg::~MImg(aMStack_fd0);
                    /* try { // try from 00d0b6e4 to 00d0b6eb has its CatchHandler @ 00d0b8bc */
  MImg::~MImg(aMStack_fbc);
                    /* try { // try from 00d0b740 to 00d0b747 has its CatchHandler @ 00d0b91c */
  MImg::~MImg(aMStack_fa8);
  MImg::~MImg(aMStack_f94);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1d0));
  lVar3 = GetRcEngine::RcGetNum(0x3377);
  lVar4 = GetRcEngine::RcGetNum(0x3378);
  lVar5 = GetRcEngine::RcGetNum(0x3376);
  lVar6 = GetRcEngine::RcGetNum(0x3373);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_f8 = operator_new(0x514);
                    /* try { // try from 00d0b8a8 to 00d0b8af has its CatchHandler @ 00d0b960 */
  ImageButton::ImageButton(pIStack_f8,*(MWidget **)(param_1 + 400),a_Stack_620,0,0x15);
  *(ImageButton **)(param_1 + 0x1d4) = pIStack_f8;
  if (*(int *)(param_1 + 0x1d4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,799);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1d4) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1d4);
  uVar8 = GetRcEngine::RcGetNum(0x3375);
  GetRcEngine::RcGetNum(0x3374);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_fc = *(MImg **)(param_1 + 0x1d4);
  MImg::MImg(aMStack_fe4,0x5cd);
                    /* try { // try from 00d0bd30 to 00d0bd37 has its CatchHandler @ 00d0bffc */
  MImg::MImg(aMStack_ff8,0x5cd);
                    /* try { // try from 00d0bd4c to 00d0bd53 has its CatchHandler @ 00d0bf9c */
  MImg::MImg(aMStack_100c,0x5cd);
                    /* try { // try from 00d0bd68 to 00d0bd6f has its CatchHandler @ 00d0be34 */
  MImg::MImg(aMStack_1020,0x5cd);
                    /* try { // try from 00d0bd94 to 00d0bd9b has its CatchHandler @ 00d0bdd8 */
  ImageButton::SetImg(pMStack_fc,aMStack_fe4,aMStack_ff8,aMStack_100c);
                    /* try { // try from 00d0bdac to 00d0bdb3 has its CatchHandler @ 00d0be34 */
  MImg::~MImg(aMStack_1020);
                    /* try { // try from 00d0bdc4 to 00d0bdcb has its CatchHandler @ 00d0bf9c */
  MImg::~MImg(aMStack_100c);
                    /* try { // try from 00d0be20 to 00d0be27 has its CatchHandler @ 00d0bffc */
  MImg::~MImg(aMStack_ff8);
  MImg::~MImg(aMStack_fe4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1d4));
  lVar3 = GetRcEngine::RcGetNum(0x33d7);
  lVar4 = GetRcEngine::RcGetNum(0x33d8);
  lVar5 = GetRcEngine::RcGetNum(0x33d6);
  lVar6 = GetRcEngine::RcGetNum(0x33d3);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_100 = operator_new(0x514);
                    /* try { // try from 00d0bf88 to 00d0bf8f has its CatchHandler @ 00d0c040 */
  ImageButton::ImageButton(pIStack_100,*(MWidget **)(param_1 + 400),a_Stack_620,0,0x16);
  *(ImageButton **)(param_1 + 0x1d8) = pIStack_100;
  if (*(int *)(param_1 + 0x1d8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x33e);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1d8) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1d8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1d8);
  uVar8 = GetRcEngine::RcGetNum(0x33d5);
  GetRcEngine::RcGetNum(0x33d4);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_104 = *(MImg **)(param_1 + 0x1d8);
  MImg::MImg(aMStack_1034,0x5cd);
                    /* try { // try from 00d0c410 to 00d0c417 has its CatchHandler @ 00d0c6dc */
  MImg::MImg(aMStack_1048,0x5cd);
                    /* try { // try from 00d0c42c to 00d0c433 has its CatchHandler @ 00d0c67c */
  MImg::MImg(aMStack_105c,0x5cd);
                    /* try { // try from 00d0c448 to 00d0c44f has its CatchHandler @ 00d0c514 */
  MImg::MImg(aMStack_1070,0x5cd);
                    /* try { // try from 00d0c474 to 00d0c47b has its CatchHandler @ 00d0c4b8 */
  ImageButton::SetImg(pMStack_104,aMStack_1034,aMStack_1048,aMStack_105c);
                    /* try { // try from 00d0c48c to 00d0c493 has its CatchHandler @ 00d0c514 */
  MImg::~MImg(aMStack_1070);
                    /* try { // try from 00d0c4a4 to 00d0c4ab has its CatchHandler @ 00d0c67c */
  MImg::~MImg(aMStack_105c);
                    /* try { // try from 00d0c500 to 00d0c507 has its CatchHandler @ 00d0c6dc */
  MImg::~MImg(aMStack_1048);
  MImg::~MImg(aMStack_1034);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1d8));
  lVar3 = GetRcEngine::RcGetNum(0x3395);
  lVar4 = GetRcEngine::RcGetNum(0x3396);
  lVar5 = GetRcEngine::RcGetNum(0x3394);
  lVar6 = GetRcEngine::RcGetNum(0x3391);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_108 = operator_new(0x514);
                    /* try { // try from 00d0c668 to 00d0c66f has its CatchHandler @ 00d0c720 */
  ImageButton::ImageButton(pIStack_108,*(MWidget **)(param_1 + 400),a_Stack_620,0,0x17);
  *(ImageButton **)(param_1 + 0x1dc) = pIStack_108;
  if (*(int *)(param_1 + 0x1dc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x35d);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1dc) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1dc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x1dc);
  uVar8 = GetRcEngine::RcGetNum(0x3393);
  GetRcEngine::RcGetNum(0x3392);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_10c = *(MImg **)(param_1 + 0x1dc);
  MImg::MImg(aMStack_1084,0x5cd);
                    /* try { // try from 00d0caf0 to 00d0caf7 has its CatchHandler @ 00d0cdbc */
  MImg::MImg(aMStack_1098,0x5cd);
                    /* try { // try from 00d0cb0c to 00d0cb13 has its CatchHandler @ 00d0cd5c */
  MImg::MImg(aMStack_10ac,0x5cd);
                    /* try { // try from 00d0cb28 to 00d0cb2f has its CatchHandler @ 00d0cbf4 */
  MImg::MImg(aMStack_10c0,0x5cd);
                    /* try { // try from 00d0cb54 to 00d0cb5b has its CatchHandler @ 00d0cb98 */
  ImageButton::SetImg(pMStack_10c,aMStack_1084,aMStack_1098,aMStack_10ac);
                    /* try { // try from 00d0cb6c to 00d0cb73 has its CatchHandler @ 00d0cbf4 */
  MImg::~MImg(aMStack_10c0);
                    /* try { // try from 00d0cb84 to 00d0cb8b has its CatchHandler @ 00d0cd5c */
  MImg::~MImg(aMStack_10ac);
                    /* try { // try from 00d0cbe0 to 00d0cbe7 has its CatchHandler @ 00d0cdbc */
  MImg::~MImg(aMStack_1098);
  MImg::~MImg(aMStack_1084);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1dc));
  lVar3 = GetRcEngine::RcGetNum(0x3325);
  lVar4 = GetRcEngine::RcGetNum(0x3326);
  lVar5 = GetRcEngine::RcGetNum(0x3324);
  lVar6 = GetRcEngine::RcGetNum(0x3323);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_110 = operator_new(0x270);
                    /* try { // try from 00d0cd48 to 00d0cd4f has its CatchHandler @ 00d0ce00 */
  ComboButton::ComboButton(pCStack_110,*(MWidget **)(param_1 + 0x194),a_Stack_620,0,0x18);
  *(ComboButton **)(param_1 + 0x1e0) = pCStack_110;
  if (*(int *)(param_1 + 0x1e0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x37c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1e0) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e0) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1e0) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e0),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e0),2,0);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1e0));
  lVar3 = GetRcEngine::RcGetNum(0x334d);
  lVar4 = GetRcEngine::RcGetNum(0x334e);
  lVar5 = GetRcEngine::RcGetNum(0x334c);
  lVar6 = GetRcEngine::RcGetNum(0x334b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_114 = operator_new(0x270);
                    /* try { // try from 00d0d6d8 to 00d0d6df has its CatchHandler @ 00d0d708 */
  ComboButton::ComboButton(pCStack_114,*(MWidget **)(param_1 + 0x194),a_Stack_620,0,0x19);
  *(ComboButton **)(param_1 + 0x1e4) = pCStack_114;
  if (*(int *)(param_1 + 0x1e4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x3ba);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1e4) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e4) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e4) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1e4) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e4);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1e4));
  lVar3 = GetRcEngine::RcGetNum(0x3309);
  lVar4 = GetRcEngine::RcGetNum(0x330a);
  lVar5 = GetRcEngine::RcGetNum(0x3308);
  lVar6 = GetRcEngine::RcGetNum(0x3307);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_118 = operator_new(0x270);
                    /* try { // try from 00d0df98 to 00d0df9f has its CatchHandler @ 00d0dfc8 */
  ComboButton::ComboButton(pCStack_118,*(MWidget **)(param_1 + 0x194),a_Stack_620,0,0x1a);
  *(ComboButton **)(param_1 + 0x1e8) = pCStack_118;
  if (*(int *)(param_1 + 0x1e8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x3f6);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1e8) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e8) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1e8) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1e8) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1e8);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1e8));
  lVar3 = GetRcEngine::RcGetNum(0x3405);
  lVar4 = GetRcEngine::RcGetNum(0x3406);
  lVar5 = GetRcEngine::RcGetNum(0x3404);
  lVar6 = GetRcEngine::RcGetNum(0x3403);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_11c = operator_new(0x274);
                    /* try { // try from 00d0e87c to 00d0e883 has its CatchHandler @ 00d0e8ac */
  SpinButton::SpinButton(pSStack_11c,*(MWidget **)(param_1 + 0x194),a_Stack_620,0,0x1b);
  *(SpinButton **)(param_1 + 0x1ec) = pSStack_11c;
  if (*(int *)(param_1 + 0x1ec) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x433);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x260) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x264) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x264) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x264) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1ec) + 0x264) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1ec) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1ec);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1ec));
  lVar3 = GetRcEngine::RcGetNum(0x32e1);
  lVar4 = GetRcEngine::RcGetNum(0x32e2);
  lVar5 = GetRcEngine::RcGetNum(0x32e0);
  lVar6 = GetRcEngine::RcGetNum(0x32df);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_120 = operator_new(0x264);
                    /* try { // try from 00d0f150 to 00d0f157 has its CatchHandler @ 00d0f180 */
  AbsContainer::AbsContainer(pAStack_120,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x1c);
  *(AbsContainer **)(param_1 + 0x1f0) = pAStack_120;
  if (*(int *)(param_1 + 0x1f0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x46f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x1f0));
  lVar3 = GetRcEngine::RcGetNum(0x337d);
  lVar4 = GetRcEngine::RcGetNum(0x337e);
  lVar5 = GetRcEngine::RcGetNum(0x337c);
  lVar6 = GetRcEngine::RcGetNum(0x3379);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_124 = operator_new(0x514);
                    /* try { // try from 00d0f47c to 00d0f483 has its CatchHandler @ 00d0f4ac */
  ImageButton::ImageButton(pIStack_124,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x1d);
  *(ImageButton **)(param_1 + 500) = pIStack_124;
  if (*(int *)(param_1 + 500) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x480);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 500) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 500) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 500);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 500);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 500);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 500) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 500);
  uVar8 = GetRcEngine::RcGetNum(0x337b);
  GetRcEngine::RcGetNum(0x337a);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_128 = *(MImg **)(param_1 + 500);
  MImg::MImg(aMStack_10d4,0x5cd);
                    /* try { // try from 00d0f87c to 00d0f883 has its CatchHandler @ 00d0fb48 */
  MImg::MImg(aMStack_10e8,0x5cd);
                    /* try { // try from 00d0f898 to 00d0f89f has its CatchHandler @ 00d0fae8 */
  MImg::MImg(aMStack_10fc,0x5cd);
                    /* try { // try from 00d0f8b4 to 00d0f8bb has its CatchHandler @ 00d0f980 */
  MImg::MImg(aMStack_1110,0x5cd);
                    /* try { // try from 00d0f8e0 to 00d0f8e7 has its CatchHandler @ 00d0f924 */
  ImageButton::SetImg(pMStack_128,aMStack_10d4,aMStack_10e8,aMStack_10fc);
                    /* try { // try from 00d0f8f8 to 00d0f8ff has its CatchHandler @ 00d0f980 */
  MImg::~MImg(aMStack_1110);
                    /* try { // try from 00d0f910 to 00d0f917 has its CatchHandler @ 00d0fae8 */
  MImg::~MImg(aMStack_10fc);
                    /* try { // try from 00d0f96c to 00d0f973 has its CatchHandler @ 00d0fb48 */
  MImg::~MImg(aMStack_10e8);
  MImg::~MImg(aMStack_10d4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 500));
  lVar3 = GetRcEngine::RcGetNum(0x32e9);
  lVar4 = GetRcEngine::RcGetNum(0x32ea);
  lVar5 = GetRcEngine::RcGetNum(0x32e8);
  lVar6 = GetRcEngine::RcGetNum(0x32e7);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_12c = operator_new(0x264);
                    /* try { // try from 00d0fad4 to 00d0fadb has its CatchHandler @ 00d0fb8c */
  AbsContainer::AbsContainer(pAStack_12c,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x1e);
  *(AbsContainer **)(param_1 + 0x1f8) = pAStack_12c;
  if (*(int *)(param_1 + 0x1f8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x49f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1f8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x1f8));
  lVar3 = GetRcEngine::RcGetNum(0x3341);
  lVar4 = GetRcEngine::RcGetNum(0x3342);
  lVar5 = GetRcEngine::RcGetNum(0x3340);
  lVar6 = GetRcEngine::RcGetNum(0x333f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_130 = operator_new(0x270);
                    /* try { // try from 00d0fe88 to 00d0fe8f has its CatchHandler @ 00d0feb8 */
  ComboButton::ComboButton(pCStack_130,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x1f);
  *(ComboButton **)(param_1 + 0x1fc) = pCStack_130;
  if (*(int *)(param_1 + 0x1fc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x4b0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1fc) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1fc) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x1fc) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1fc) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x1fc);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x1fc));
  lVar3 = GetRcEngine::RcGetNum(0x3409);
  lVar4 = GetRcEngine::RcGetNum(0x340a);
  lVar5 = GetRcEngine::RcGetNum(0x3408);
  lVar6 = GetRcEngine::RcGetNum(0x3407);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pSStack_134 = operator_new(0x274);
                    /* try { // try from 00d1076c to 00d10773 has its CatchHandler @ 00d1079c */
  SpinButton::SpinButton(pSStack_134,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x20);
  *(SpinButton **)(param_1 + 0x200) = pSStack_134;
  if (*(int *)(param_1 + 0x200) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x4ed);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x200) + 0x25c) = 0;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x200) + 0x260) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x264) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x264) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x264) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x200) + 0x264) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x200) + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x200) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x200) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x200);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x200));
  lVar3 = GetRcEngine::RcGetNum(0x32e5);
  lVar4 = GetRcEngine::RcGetNum(0x32e6);
  lVar5 = GetRcEngine::RcGetNum(0x32e4);
  lVar6 = GetRcEngine::RcGetNum(0x32e3);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_138 = operator_new(0x264);
                    /* try { // try from 00d1104c to 00d11053 has its CatchHandler @ 00d1107c */
  AbsContainer::AbsContainer(pAStack_138,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x21);
  *(AbsContainer **)(param_1 + 0x204) = pAStack_138;
  if (*(int *)(param_1 + 0x204) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x52a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x204) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x204) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x204);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x204));
  lVar3 = GetRcEngine::RcGetNum(0x3315);
  lVar4 = GetRcEngine::RcGetNum(0x3316);
  lVar5 = GetRcEngine::RcGetNum(0x3314);
  lVar6 = GetRcEngine::RcGetNum(0x3313);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_13c = operator_new(0x270);
                    /* try { // try from 00d11378 to 00d1137f has its CatchHandler @ 00d113a8 */
  ComboButton::ComboButton(pCStack_13c,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x22);
  *(ComboButton **)(param_1 + 0x208) = pCStack_13c;
  if (*(int *)(param_1 + 0x208) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x53b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x208) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x208) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x208) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x208) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x208) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x208) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x208);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x208));
  lVar3 = GetRcEngine::RcGetNum(0x3329);
  lVar4 = GetRcEngine::RcGetNum(0x332a);
  lVar5 = GetRcEngine::RcGetNum(0x3328);
  lVar6 = GetRcEngine::RcGetNum(0x3327);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_140 = operator_new(0x270);
                    /* try { // try from 00d11c5c to 00d11c63 has its CatchHandler @ 00d11c8c */
  ComboButton::ComboButton(pCStack_140,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x23);
  *(ComboButton **)(param_1 + 0x20c) = pCStack_140;
  if (*(int *)(param_1 + 0x20c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x578);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x20c) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20c) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x20c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x20c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x20c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x20c));
  lVar3 = GetRcEngine::RcGetNum(0x32f5);
  lVar4 = GetRcEngine::RcGetNum(0x32f6);
  lVar5 = GetRcEngine::RcGetNum(0x32f4);
  lVar6 = GetRcEngine::RcGetNum(0x32f3);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_144 = operator_new(0x264);
                    /* try { // try from 00d12540 to 00d12547 has its CatchHandler @ 00d12570 */
  AbsContainer::AbsContainer(pAStack_144,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x24);
  *(AbsContainer **)(param_1 + 0x210) = pAStack_144;
  if (*(int *)(param_1 + 0x210) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x5b5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x210);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x210));
  lVar3 = GetRcEngine::RcGetNum(0x332d);
  lVar4 = GetRcEngine::RcGetNum(0x332e);
  lVar5 = GetRcEngine::RcGetNum(0x332c);
  lVar6 = GetRcEngine::RcGetNum(0x332b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_148 = operator_new(0x270);
                    /* try { // try from 00d1286c to 00d12873 has its CatchHandler @ 00d1289c */
  ComboButton::ComboButton(pCStack_148,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x25);
  *(ComboButton **)(param_1 + 0x214) = pCStack_148;
  if (*(int *)(param_1 + 0x214) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x5c6);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x214) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x214) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x214) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x214) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x214) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x214) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x214));
  lVar3 = GetRcEngine::RcGetNum(0x32f9);
  lVar4 = GetRcEngine::RcGetNum(0x32fa);
  lVar5 = GetRcEngine::RcGetNum(0x32f8);
  lVar6 = GetRcEngine::RcGetNum(0x32f7);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pAStack_14c = operator_new(0x264);
                    /* try { // try from 00d13150 to 00d13157 has its CatchHandler @ 00d13180 */
  AbsContainer::AbsContainer(pAStack_14c,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x26);
  *(AbsContainer **)(param_1 + 0x218) = pAStack_14c;
  if (*(int *)(param_1 + 0x218) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x603);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x218) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x218) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x218);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x218));
  lVar3 = GetRcEngine::RcGetNum(0x3345);
  lVar4 = GetRcEngine::RcGetNum(0x3346);
  lVar5 = GetRcEngine::RcGetNum(0x3344);
  lVar6 = GetRcEngine::RcGetNum(0x3343);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_150 = operator_new(0x270);
                    /* try { // try from 00d1347c to 00d13483 has its CatchHandler @ 00d134ac */
  ComboButton::ComboButton(pCStack_150,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x27);
  *(ComboButton **)(param_1 + 0x21c) = pCStack_150;
  if (*(int *)(param_1 + 0x21c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x614);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x21c) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x21c) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x21c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x21c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x21c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x21c));
  lVar3 = GetRcEngine::RcGetNum(0x33dd);
  lVar4 = GetRcEngine::RcGetNum(0x33de);
  lVar5 = GetRcEngine::RcGetNum(0x33dc);
  lVar6 = GetRcEngine::RcGetNum(0x33d9);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_154 = operator_new(0x514);
                    /* try { // try from 00d13d60 to 00d13d67 has its CatchHandler @ 00d13d90 */
  ImageButton::ImageButton(pIStack_154,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x28);
  *(ImageButton **)(param_1 + 0x220) = pIStack_154;
  if (*(int *)(param_1 + 0x220) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x651);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x220) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x220) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x220);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x220);
  uVar8 = GetRcEngine::RcGetNum(0x33db);
  GetRcEngine::RcGetNum(0x33da);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_158 = *(MImg **)(param_1 + 0x220);
  MImg::MImg(aMStack_1124,0x5cd);
                    /* try { // try from 00d14160 to 00d14167 has its CatchHandler @ 00d1442c */
  MImg::MImg(aMStack_1138,0x5cd);
                    /* try { // try from 00d1417c to 00d14183 has its CatchHandler @ 00d143cc */
  MImg::MImg(aMStack_114c,0x5cd);
                    /* try { // try from 00d14198 to 00d1419f has its CatchHandler @ 00d14264 */
  MImg::MImg(aMStack_1160,0x5cd);
                    /* try { // try from 00d141c4 to 00d141cb has its CatchHandler @ 00d14208 */
  ImageButton::SetImg(pMStack_158,aMStack_1124,aMStack_1138,aMStack_114c);
                    /* try { // try from 00d141dc to 00d141e3 has its CatchHandler @ 00d14264 */
  MImg::~MImg(aMStack_1160);
                    /* try { // try from 00d141f4 to 00d141fb has its CatchHandler @ 00d143cc */
  MImg::~MImg(aMStack_114c);
                    /* try { // try from 00d14250 to 00d14257 has its CatchHandler @ 00d1442c */
  MImg::~MImg(aMStack_1138);
  MImg::~MImg(aMStack_1124);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x220));
  lVar3 = GetRcEngine::RcGetNum(0x33b3);
  lVar4 = GetRcEngine::RcGetNum(0x33b4);
  lVar5 = GetRcEngine::RcGetNum(0x33b2);
  lVar6 = GetRcEngine::RcGetNum(0x33af);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_15c = operator_new(0x514);
                    /* try { // try from 00d143b8 to 00d143bf has its CatchHandler @ 00d14470 */
  ImageButton::ImageButton(pIStack_15c,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x29);
  *(ImageButton **)(param_1 + 0x224) = pIStack_15c;
  if (*(int *)(param_1 + 0x224) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x670);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x224) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x224) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x224);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x224);
  uVar8 = GetRcEngine::RcGetNum(0x33b1);
  GetRcEngine::RcGetNum(0x33b0);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_160 = *(MImg **)(param_1 + 0x224);
  MImg::MImg(aMStack_1174,0x5cd);
                    /* try { // try from 00d14840 to 00d14847 has its CatchHandler @ 00d14b0c */
  MImg::MImg(aMStack_1188,0x5cd);
                    /* try { // try from 00d1485c to 00d14863 has its CatchHandler @ 00d14aac */
  MImg::MImg(aMStack_119c,0x5cd);
                    /* try { // try from 00d14878 to 00d1487f has its CatchHandler @ 00d14944 */
  MImg::MImg(aMStack_11b0,0x5cd);
                    /* try { // try from 00d148a4 to 00d148ab has its CatchHandler @ 00d148e8 */
  ImageButton::SetImg(pMStack_160,aMStack_1174,aMStack_1188,aMStack_119c);
                    /* try { // try from 00d148bc to 00d148c3 has its CatchHandler @ 00d14944 */
  MImg::~MImg(aMStack_11b0);
                    /* try { // try from 00d148d4 to 00d148db has its CatchHandler @ 00d14aac */
  MImg::~MImg(aMStack_119c);
                    /* try { // try from 00d14930 to 00d14937 has its CatchHandler @ 00d14b0c */
  MImg::~MImg(aMStack_1188);
  MImg::~MImg(aMStack_1174);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x224));
  lVar3 = GetRcEngine::RcGetNum(0x3383);
  lVar4 = GetRcEngine::RcGetNum(0x3384);
  lVar5 = GetRcEngine::RcGetNum(0x3382);
  lVar6 = GetRcEngine::RcGetNum(0x337f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_164 = operator_new(0x514);
                    /* try { // try from 00d14a98 to 00d14a9f has its CatchHandler @ 00d14b50 */
  ImageButton::ImageButton(pIStack_164,*(MWidget **)(param_1 + 0x198),a_Stack_620,0,0x2a);
  *(ImageButton **)(param_1 + 0x228) = pIStack_164;
  if (*(int *)(param_1 + 0x228) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x68f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x228) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x228) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x228);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x228);
  uVar8 = GetRcEngine::RcGetNum(0x3381);
  GetRcEngine::RcGetNum(0x3380);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_168 = *(MImg **)(param_1 + 0x228);
  MImg::MImg(aMStack_11c4,0x5cd);
                    /* try { // try from 00d14f20 to 00d14f27 has its CatchHandler @ 00d151ec */
  MImg::MImg(aMStack_11d8,0x5cd);
                    /* try { // try from 00d14f3c to 00d14f43 has its CatchHandler @ 00d1518c */
  MImg::MImg(aMStack_11ec,0x5cd);
                    /* try { // try from 00d14f58 to 00d14f5f has its CatchHandler @ 00d15024 */
  MImg::MImg(aMStack_1200,0x5cd);
                    /* try { // try from 00d14f84 to 00d14f8b has its CatchHandler @ 00d14fc8 */
  ImageButton::SetImg(pMStack_168,aMStack_11c4,aMStack_11d8,aMStack_11ec);
                    /* try { // try from 00d14f9c to 00d14fa3 has its CatchHandler @ 00d15024 */
  MImg::~MImg(aMStack_1200);
                    /* try { // try from 00d14fb4 to 00d14fbb has its CatchHandler @ 00d1518c */
  MImg::~MImg(aMStack_11ec);
                    /* try { // try from 00d15010 to 00d15017 has its CatchHandler @ 00d151ec */
  MImg::~MImg(aMStack_11d8);
  MImg::~MImg(aMStack_11c4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x228));
  lVar3 = GetRcEngine::RcGetNum(0x340d);
  lVar4 = GetRcEngine::RcGetNum(0x340e);
  lVar5 = GetRcEngine::RcGetNum(0x340c);
  lVar6 = GetRcEngine::RcGetNum(0x340b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_16c = operator_new(0x250);
                    /* try { // try from 00d15178 to 00d1517f has its CatchHandler @ 00d15230 */
  TextBox::TextBox(pTStack_16c,*(MWidget **)(param_1 + 0x1f0),a_Stack_620,0,0x2b);
  *(TextBox **)(param_1 + 0x22c) = pTStack_16c;
  if (*(int *)(param_1 + 0x22c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x6ae);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x22c) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x22c);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1f0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1f0),*(undefined4 *)(param_1 + 0x22c));
  lVar3 = GetRcEngine::RcGetNum(0x3415);
  lVar4 = GetRcEngine::RcGetNum(0x3416);
  lVar5 = GetRcEngine::RcGetNum(0x3414);
  lVar6 = GetRcEngine::RcGetNum(0x3413);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_170 = operator_new(0x250);
                    /* try { // try from 00d15690 to 00d15697 has its CatchHandler @ 00d156c0 */
  TextBox::TextBox(pTStack_170,*(MWidget **)(param_1 + 0x1f8),a_Stack_620,0,0x2c);
  *(TextBox **)(param_1 + 0x230) = pTStack_170;
  if (*(int *)(param_1 + 0x230) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x6cb);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x230) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x230) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x230) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x230) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x230) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x230) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x230);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1f8) + 0x34))
            (*(undefined4 *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x230));
  lVar3 = GetRcEngine::RcGetNum(0x3411);
  lVar4 = GetRcEngine::RcGetNum(0x3412);
  lVar5 = GetRcEngine::RcGetNum(0x3410);
  lVar6 = GetRcEngine::RcGetNum(0x340f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_174 = operator_new(0x250);
                    /* try { // try from 00d15b20 to 00d15b27 has its CatchHandler @ 00d15b50 */
  TextBox::TextBox(pTStack_174,*(MWidget **)(param_1 + 0x204),a_Stack_620,0,0x2d);
  *(TextBox **)(param_1 + 0x234) = pTStack_174;
  if (*(int *)(param_1 + 0x234) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x6e8);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x234) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x234) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x234);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x204) + 0x34))
            (*(undefined4 *)(param_1 + 0x204),*(undefined4 *)(param_1 + 0x234));
  lVar3 = GetRcEngine::RcGetNum(0x3421);
  lVar4 = GetRcEngine::RcGetNum(0x3422);
  lVar5 = GetRcEngine::RcGetNum(0x3420);
  lVar6 = GetRcEngine::RcGetNum(0x341f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_178 = operator_new(0x250);
                    /* try { // try from 00d15fb0 to 00d15fb7 has its CatchHandler @ 00d15fe0 */
  TextBox::TextBox(pTStack_178,*(MWidget **)(param_1 + 0x210),a_Stack_620,0,0x2e);
  *(TextBox **)(param_1 + 0x238) = pTStack_178;
  if (*(int *)(param_1 + 0x238) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x705);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x238) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x238) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x238);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x210) + 0x34))
            (*(undefined4 *)(param_1 + 0x210),*(undefined4 *)(param_1 + 0x238));
  lVar3 = GetRcEngine::RcGetNum(0x3425);
  lVar4 = GetRcEngine::RcGetNum(0x3426);
  lVar5 = GetRcEngine::RcGetNum(0x3424);
  lVar6 = GetRcEngine::RcGetNum(0x3423);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pTStack_17c = operator_new(0x250);
                    /* try { // try from 00d16440 to 00d16447 has its CatchHandler @ 00d16470 */
  TextBox::TextBox(pTStack_17c,*(MWidget **)(param_1 + 0x218),a_Stack_620,0,0x2f);
  *(TextBox **)(param_1 + 0x23c) = pTStack_17c;
  if (*(int *)(param_1 + 0x23c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x722);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x23c) + 0x38) = 0;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x4c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x54) = uVar7;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x23c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x218) + 0x34))
            (*(undefined4 *)(param_1 + 0x218),*(undefined4 *)(param_1 + 0x23c));
  lVar3 = GetRcEngine::RcGetNum(0x330d);
  lVar4 = GetRcEngine::RcGetNum(0x330e);
  lVar5 = GetRcEngine::RcGetNum(0x330c);
  lVar6 = GetRcEngine::RcGetNum(0x330b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_180 = operator_new(0x270);
                    /* try { // try from 00d168d0 to 00d168d7 has its CatchHandler @ 00d16900 */
  ComboButton::ComboButton(pCStack_180,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x30);
  *(ComboButton **)(param_1 + 0x240) = pCStack_180;
  if (*(int *)(param_1 + 0x240) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x73f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x240) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x240) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x240) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x240) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x240) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x240) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x240);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x240));
  lVar3 = GetRcEngine::RcGetNum(0x3321);
  lVar4 = GetRcEngine::RcGetNum(0x3322);
  lVar5 = GetRcEngine::RcGetNum(0x3320);
  lVar6 = GetRcEngine::RcGetNum(0x331f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_184 = operator_new(0x270);
                    /* try { // try from 00d17190 to 00d17197 has its CatchHandler @ 00d171c0 */
  ComboButton::ComboButton(pCStack_184,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x31);
  *(ComboButton **)(param_1 + 0x244) = pCStack_184;
  if (*(int *)(param_1 + 0x244) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x77b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x244) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x244) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x244) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x244) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x244);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x244));
  lVar3 = GetRcEngine::RcGetNum(0x3349);
  lVar4 = GetRcEngine::RcGetNum(0x334a);
  lVar5 = GetRcEngine::RcGetNum(0x3348);
  lVar6 = GetRcEngine::RcGetNum(0x3347);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_188 = operator_new(0x270);
                    /* try { // try from 00d17a50 to 00d17a57 has its CatchHandler @ 00d17a80 */
  ComboButton::ComboButton(pCStack_188,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x32);
  *(ComboButton **)(param_1 + 0x248) = pCStack_188;
  if (*(int *)(param_1 + 0x248) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x7b7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x248) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x248) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x248) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x248) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x248) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x248) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x248);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x248));
  lVar3 = GetRcEngine::RcGetNum(0x3339);
  lVar4 = GetRcEngine::RcGetNum(0x333a);
  lVar5 = GetRcEngine::RcGetNum(0x3338);
  lVar6 = GetRcEngine::RcGetNum(0x3337);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_18c = operator_new(0x270);
                    /* try { // try from 00d18310 to 00d18317 has its CatchHandler @ 00d18340 */
  ComboButton::ComboButton(pCStack_18c,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x33);
  *(ComboButton **)(param_1 + 0x24c) = pCStack_18c;
  if (*(int *)(param_1 + 0x24c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x7f3);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24c) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x24c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x24c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x24c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x24c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x24c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x24c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x24c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x24c));
  lVar3 = GetRcEngine::RcGetNum(0x333d);
  lVar4 = GetRcEngine::RcGetNum(0x333e);
  lVar5 = GetRcEngine::RcGetNum(0x333c);
  lVar6 = GetRcEngine::RcGetNum(0x333b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_190 = operator_new(0x270);
                    /* try { // try from 00d18bd0 to 00d18bd7 has its CatchHandler @ 00d18c00 */
  ComboButton::ComboButton(pCStack_190,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x34);
  *(ComboButton **)(param_1 + 0x250) = pCStack_190;
  if (*(int *)(param_1 + 0x250) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x82f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x250) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x250) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x250) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x250) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x250) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x250) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x250);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x250));
  lVar3 = GetRcEngine::RcGetNum(0x3335);
  lVar4 = GetRcEngine::RcGetNum(0x3336);
  lVar5 = GetRcEngine::RcGetNum(0x3334);
  lVar6 = GetRcEngine::RcGetNum(0x3333);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_194 = operator_new(0x270);
                    /* try { // try from 00d19490 to 00d19497 has its CatchHandler @ 00d194c0 */
  ComboButton::ComboButton(pCStack_194,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x35);
  *(ComboButton **)(param_1 + 0x254) = pCStack_194;
  if (*(int *)(param_1 + 0x254) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x86b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x254) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x254) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x254) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x254) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x254) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x254);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x254));
  lVar3 = GetRcEngine::RcGetNum(0x3359);
  lVar4 = GetRcEngine::RcGetNum(0x335a);
  lVar5 = GetRcEngine::RcGetNum(0x3358);
  lVar6 = GetRcEngine::RcGetNum(0x3357);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_198 = operator_new(0x270);
                    /* try { // try from 00d19d50 to 00d19d57 has its CatchHandler @ 00d19d80 */
  ComboButton::ComboButton(pCStack_198,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x36);
  *(ComboButton **)(param_1 + 600) = pCStack_198;
  if (*(int *)(param_1 + 600) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x8a7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 600) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 600) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 600) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 600) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 600) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 600) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 600);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 600));
  lVar3 = GetRcEngine::RcGetNum(0x3311);
  lVar4 = GetRcEngine::RcGetNum(0x3312);
  lVar5 = GetRcEngine::RcGetNum(0x3310);
  lVar6 = GetRcEngine::RcGetNum(0x330f);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_19c = operator_new(0x270);
                    /* try { // try from 00d1a610 to 00d1a617 has its CatchHandler @ 00d1a640 */
  ComboButton::ComboButton(pCStack_19c,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x37);
  *(ComboButton **)(param_1 + 0x25c) = pCStack_19c;
  if (*(int *)(param_1 + 0x25c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x8e3);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x25c) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x25c) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x25c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x25c));
  lVar3 = GetRcEngine::RcGetNum(0x331d);
  lVar4 = GetRcEngine::RcGetNum(0x331e);
  lVar5 = GetRcEngine::RcGetNum(0x331c);
  lVar6 = GetRcEngine::RcGetNum(0x331b);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_1a0 = operator_new(0x270);
                    /* try { // try from 00d1aed0 to 00d1aed7 has its CatchHandler @ 00d1af00 */
  ComboButton::ComboButton(pCStack_1a0,*(MWidget **)(param_1 + 0x19c),a_Stack_620,0,0x38);
  *(ComboButton **)(param_1 + 0x260) = pCStack_1a0;
  if (*(int *)(param_1 + 0x260) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x91f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x260) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x260) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x260) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x260) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x260) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x260) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x260));
  lVar3 = GetRcEngine::RcGetNum(0x33b9);
  lVar4 = GetRcEngine::RcGetNum(0x33ba);
  lVar5 = GetRcEngine::RcGetNum(0x33b8);
  lVar6 = GetRcEngine::RcGetNum(0x33b5);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1a4 = operator_new(0x514);
                    /* try { // try from 00d1b790 to 00d1b797 has its CatchHandler @ 00d1b7c0 */
  ImageButton::ImageButton(pIStack_1a4,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x39);
  *(ImageButton **)(param_1 + 0x264) = pIStack_1a4;
  if (*(int *)(param_1 + 0x264) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x95b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x264) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x264) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x264);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x264);
  uVar8 = GetRcEngine::RcGetNum(0x33b7);
  GetRcEngine::RcGetNum(0x33b6);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1a8 = *(MImg **)(param_1 + 0x264);
  MImg::MImg(aMStack_1214,0x5cd);
                    /* try { // try from 00d1bb90 to 00d1bb97 has its CatchHandler @ 00d1be5c */
  MImg::MImg(aMStack_1228,0x5cd);
                    /* try { // try from 00d1bbac to 00d1bbb3 has its CatchHandler @ 00d1bdfc */
  MImg::MImg(aMStack_123c,0x5cd);
                    /* try { // try from 00d1bbc8 to 00d1bbcf has its CatchHandler @ 00d1bc94 */
  MImg::MImg(aMStack_1250,0x5cd);
                    /* try { // try from 00d1bbf4 to 00d1bbfb has its CatchHandler @ 00d1bc38 */
  ImageButton::SetImg(pMStack_1a8,aMStack_1214,aMStack_1228,aMStack_123c);
                    /* try { // try from 00d1bc0c to 00d1bc13 has its CatchHandler @ 00d1bc94 */
  MImg::~MImg(aMStack_1250);
                    /* try { // try from 00d1bc24 to 00d1bc2b has its CatchHandler @ 00d1bdfc */
  MImg::~MImg(aMStack_123c);
                    /* try { // try from 00d1bc80 to 00d1bc87 has its CatchHandler @ 00d1be5c */
  MImg::~MImg(aMStack_1228);
  MImg::~MImg(aMStack_1214);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x264));
  lVar3 = GetRcEngine::RcGetNum(0x3355);
  lVar4 = GetRcEngine::RcGetNum(0x3356);
  lVar5 = GetRcEngine::RcGetNum(0x3354);
  lVar6 = GetRcEngine::RcGetNum(0x3353);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_1ac = operator_new(0x270);
                    /* try { // try from 00d1bde8 to 00d1bdef has its CatchHandler @ 00d1bea0 */
  ComboButton::ComboButton(pCStack_1ac,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3a);
  *(ComboButton **)(param_1 + 0x268) = pCStack_1ac;
  if (*(int *)(param_1 + 0x268) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x97a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x268) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x268) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x268) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x268) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x268) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x268) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x268) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x268) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x268) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x268) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x268);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x268));
  lVar3 = GetRcEngine::RcGetNum(0x33d1);
  lVar4 = GetRcEngine::RcGetNum(0x33d2);
  lVar5 = GetRcEngine::RcGetNum(0x33d0);
  lVar6 = GetRcEngine::RcGetNum(0x33cd);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1b0 = operator_new(0x514);
                    /* try { // try from 00d1c754 to 00d1c75b has its CatchHandler @ 00d1c784 */
  ImageButton::ImageButton(pIStack_1b0,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3b);
  *(ImageButton **)(param_1 + 0x26c) = pIStack_1b0;
  if (*(int *)(param_1 + 0x26c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x9b7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x26c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x26c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x26c);
  uVar8 = GetRcEngine::RcGetNum(0x33cf);
  GetRcEngine::RcGetNum(0x33ce);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1b4 = *(MImg **)(param_1 + 0x26c);
  MImg::MImg(aMStack_1264,0x5cd);
                    /* try { // try from 00d1cb54 to 00d1cb5b has its CatchHandler @ 00d1ce20 */
  MImg::MImg(aMStack_1278,0x5cd);
                    /* try { // try from 00d1cb70 to 00d1cb77 has its CatchHandler @ 00d1cdc0 */
  MImg::MImg(aMStack_128c,0x5cd);
                    /* try { // try from 00d1cb8c to 00d1cb93 has its CatchHandler @ 00d1cc58 */
  MImg::MImg(aMStack_12a0,0x5cd);
                    /* try { // try from 00d1cbb8 to 00d1cbbf has its CatchHandler @ 00d1cbfc */
  ImageButton::SetImg(pMStack_1b4,aMStack_1264,aMStack_1278,aMStack_128c);
                    /* try { // try from 00d1cbd0 to 00d1cbd7 has its CatchHandler @ 00d1cc58 */
  MImg::~MImg(aMStack_12a0);
                    /* try { // try from 00d1cbe8 to 00d1cbef has its CatchHandler @ 00d1cdc0 */
  MImg::~MImg(aMStack_128c);
                    /* try { // try from 00d1cc44 to 00d1cc4b has its CatchHandler @ 00d1ce20 */
  MImg::~MImg(aMStack_1278);
  MImg::~MImg(aMStack_1264);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x26c));
  lVar3 = GetRcEngine::RcGetNum(0x3389);
  lVar4 = GetRcEngine::RcGetNum(0x338a);
  lVar5 = GetRcEngine::RcGetNum(0x3388);
  lVar6 = GetRcEngine::RcGetNum(0x3385);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1b8 = operator_new(0x514);
                    /* try { // try from 00d1cdac to 00d1cdb3 has its CatchHandler @ 00d1ce64 */
  ImageButton::ImageButton(pIStack_1b8,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3c);
  *(ImageButton **)(param_1 + 0x270) = pIStack_1b8;
  if (*(int *)(param_1 + 0x270) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x9d6);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x270) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x270) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x270);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x270);
  uVar8 = GetRcEngine::RcGetNum(0x3387);
  GetRcEngine::RcGetNum(0x3386);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1bc = *(MImg **)(param_1 + 0x270);
  MImg::MImg(aMStack_12b4,0x5cd);
                    /* try { // try from 00d1d234 to 00d1d23b has its CatchHandler @ 00d1d500 */
  MImg::MImg(aMStack_12c8,0x5cd);
                    /* try { // try from 00d1d250 to 00d1d257 has its CatchHandler @ 00d1d4a0 */
  MImg::MImg(aMStack_12dc,0x5cd);
                    /* try { // try from 00d1d26c to 00d1d273 has its CatchHandler @ 00d1d338 */
  MImg::MImg(aMStack_12f0,0x5cd);
                    /* try { // try from 00d1d298 to 00d1d29f has its CatchHandler @ 00d1d2dc */
  ImageButton::SetImg(pMStack_1bc,aMStack_12b4,aMStack_12c8,aMStack_12dc);
                    /* try { // try from 00d1d2b0 to 00d1d2b7 has its CatchHandler @ 00d1d338 */
  MImg::~MImg(aMStack_12f0);
                    /* try { // try from 00d1d2c8 to 00d1d2cf has its CatchHandler @ 00d1d4a0 */
  MImg::~MImg(aMStack_12dc);
                    /* try { // try from 00d1d324 to 00d1d32b has its CatchHandler @ 00d1d500 */
  MImg::~MImg(aMStack_12c8);
  MImg::~MImg(aMStack_12b4);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x270));
  lVar3 = GetRcEngine::RcGetNum(0x33bf);
  lVar4 = GetRcEngine::RcGetNum(0x33c0);
  lVar5 = GetRcEngine::RcGetNum(0x33be);
  lVar6 = GetRcEngine::RcGetNum(0x33bb);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1c0 = operator_new(0x514);
                    /* try { // try from 00d1d48c to 00d1d493 has its CatchHandler @ 00d1d544 */
  ImageButton::ImageButton(pIStack_1c0,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3d);
  *(ImageButton **)(param_1 + 0x274) = pIStack_1c0;
  if (*(int *)(param_1 + 0x274) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0x9f5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x274) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x274) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x274);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x274);
  uVar8 = GetRcEngine::RcGetNum(0x33bd);
  GetRcEngine::RcGetNum(0x33bc);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1c4 = *(MImg **)(param_1 + 0x274);
  MImg::MImg(aMStack_1304,0x5cd);
                    /* try { // try from 00d1d914 to 00d1d91b has its CatchHandler @ 00d1dbe0 */
  MImg::MImg(aMStack_1318,0x5cd);
                    /* try { // try from 00d1d930 to 00d1d937 has its CatchHandler @ 00d1db80 */
  MImg::MImg(aMStack_132c,0x5cd);
                    /* try { // try from 00d1d94c to 00d1d953 has its CatchHandler @ 00d1da18 */
  MImg::MImg(aMStack_1340,0x5cd);
                    /* try { // try from 00d1d978 to 00d1d97f has its CatchHandler @ 00d1d9bc */
  ImageButton::SetImg(pMStack_1c4,aMStack_1304,aMStack_1318,aMStack_132c);
                    /* try { // try from 00d1d990 to 00d1d997 has its CatchHandler @ 00d1da18 */
  MImg::~MImg(aMStack_1340);
                    /* try { // try from 00d1d9a8 to 00d1d9af has its CatchHandler @ 00d1db80 */
  MImg::~MImg(aMStack_132c);
                    /* try { // try from 00d1da04 to 00d1da0b has its CatchHandler @ 00d1dbe0 */
  MImg::~MImg(aMStack_1318);
  MImg::~MImg(aMStack_1304);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x274));
  lVar3 = GetRcEngine::RcGetNum(0x33c5);
  lVar4 = GetRcEngine::RcGetNum(0x33c6);
  lVar5 = GetRcEngine::RcGetNum(0x33c4);
  lVar6 = GetRcEngine::RcGetNum(0x33c1);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1c8 = operator_new(0x514);
                    /* try { // try from 00d1db6c to 00d1db73 has its CatchHandler @ 00d1dc24 */
  ImageButton::ImageButton(pIStack_1c8,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3e);
  *(ImageButton **)(param_1 + 0x278) = pIStack_1c8;
  if (*(int *)(param_1 + 0x278) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xa14);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x278) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x278) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x278);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x278) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x278);
  uVar8 = GetRcEngine::RcGetNum(0x33c3);
  GetRcEngine::RcGetNum(0x33c2);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1cc = *(MImg **)(param_1 + 0x278);
  MImg::MImg(aMStack_1354,0x5cd);
                    /* try { // try from 00d1dff4 to 00d1dffb has its CatchHandler @ 00d1e2c0 */
  MImg::MImg(aMStack_1368,0x5cd);
                    /* try { // try from 00d1e010 to 00d1e017 has its CatchHandler @ 00d1e260 */
  MImg::MImg(aMStack_137c,0x5cd);
                    /* try { // try from 00d1e02c to 00d1e033 has its CatchHandler @ 00d1e0f8 */
  MImg::MImg(aMStack_1390,0x5cd);
                    /* try { // try from 00d1e058 to 00d1e05f has its CatchHandler @ 00d1e09c */
  ImageButton::SetImg(pMStack_1cc,aMStack_1354,aMStack_1368,aMStack_137c);
                    /* try { // try from 00d1e070 to 00d1e077 has its CatchHandler @ 00d1e0f8 */
  MImg::~MImg(aMStack_1390);
                    /* try { // try from 00d1e088 to 00d1e08f has its CatchHandler @ 00d1e260 */
  MImg::~MImg(aMStack_137c);
                    /* try { // try from 00d1e0e4 to 00d1e0eb has its CatchHandler @ 00d1e2c0 */
  MImg::~MImg(aMStack_1368);
  MImg::~MImg(aMStack_1354);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x278));
  lVar3 = GetRcEngine::RcGetNum(0x33cb);
  lVar4 = GetRcEngine::RcGetNum(0x33cc);
  lVar5 = GetRcEngine::RcGetNum(0x33ca);
  lVar6 = GetRcEngine::RcGetNum(0x33c7);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1d0 = operator_new(0x514);
                    /* try { // try from 00d1e24c to 00d1e253 has its CatchHandler @ 00d1e304 */
  ImageButton::ImageButton(pIStack_1d0,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x3f);
  *(ImageButton **)(param_1 + 0x27c) = pIStack_1d0;
  if (*(int *)(param_1 + 0x27c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xa33);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x27c) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x27c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x27c) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x27c);
  uVar8 = GetRcEngine::RcGetNum(0x33c9);
  GetRcEngine::RcGetNum(0x33c8);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1d4 = *(MImg **)(param_1 + 0x27c);
  MImg::MImg(aMStack_13a4,0x5cd);
                    /* try { // try from 00d1e6d4 to 00d1e6db has its CatchHandler @ 00d1e9a0 */
  MImg::MImg(aMStack_13b8,0x5cd);
                    /* try { // try from 00d1e6f0 to 00d1e6f7 has its CatchHandler @ 00d1e940 */
  MImg::MImg(aMStack_13cc,0x5cd);
                    /* try { // try from 00d1e70c to 00d1e713 has its CatchHandler @ 00d1e7d8 */
  MImg::MImg(aMStack_13e0,0x5cd);
                    /* try { // try from 00d1e738 to 00d1e73f has its CatchHandler @ 00d1e77c */
  ImageButton::SetImg(pMStack_1d4,aMStack_13a4,aMStack_13b8,aMStack_13cc);
                    /* try { // try from 00d1e750 to 00d1e757 has its CatchHandler @ 00d1e7d8 */
  MImg::~MImg(aMStack_13e0);
                    /* try { // try from 00d1e768 to 00d1e76f has its CatchHandler @ 00d1e940 */
  MImg::~MImg(aMStack_13cc);
                    /* try { // try from 00d1e7c4 to 00d1e7cb has its CatchHandler @ 00d1e9a0 */
  MImg::~MImg(aMStack_13b8);
  MImg::~MImg(aMStack_13a4);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x27c));
  lVar3 = GetRcEngine::RcGetNum(0x3319);
  lVar4 = GetRcEngine::RcGetNum(0x331a);
  lVar5 = GetRcEngine::RcGetNum(0x3318);
  lVar6 = GetRcEngine::RcGetNum(0x3317);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pCStack_1d8 = operator_new(0x270);
                    /* try { // try from 00d1e92c to 00d1e933 has its CatchHandler @ 00d1e9e4 */
  ComboButton::ComboButton(pCStack_1d8,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x40);
  *(ComboButton **)(param_1 + 0x280) = pCStack_1d8;
  if (*(int *)(param_1 + 0x280) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xa52);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x280) + 600) = 1;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x25c) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x25c);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(*(int *)(param_1 + 0x280) + 0x25c) + 0x170);
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x52);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x54);
  *(undefined4 *)(iVar15 + 0x80) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar7 = GetRcEngine::RcGetColor(0x55);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x280) + 0x260) + 0x154) = 0x4ae;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(*(int *)(param_1 + 0x280) + 0x260);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  MString::Set((short)*(undefined4 *)(param_1 + 0x280) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x280) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x280);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x280));
  lVar3 = GetRcEngine::RcGetNum(0x33a1);
  lVar4 = GetRcEngine::RcGetNum(0x33a2);
  lVar5 = GetRcEngine::RcGetNum(0x33a0);
  lVar6 = GetRcEngine::RcGetNum(0x339d);
  _Rect::set(a_Stack_620,lVar3,lVar4,lVar5,lVar6);
  pIStack_1dc = operator_new(0x514);
                    /* try { // try from 00d1f298 to 00d1f29f has its CatchHandler @ 00d1f2c8 */
  ImageButton::ImageButton(pIStack_1dc,*(MWidget **)(param_1 + 0x1a0),a_Stack_620,0,0x41);
  *(ImageButton **)(param_1 + 0x284) = pIStack_1dc;
  if (*(int *)(param_1 + 0x284) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ffe50c,&UNK_00ffe7e4,0xa8f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x284) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x284) + 0x3a) = 1;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar7 = GetRcEngine::RcGetColor(0x5e);
  *(undefined4 *)(iVar15 + 0x7c) = uVar7;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar7 = GetRcEngine::RcGetColor(0x4e);
  *(undefined4 *)(iVar15 + 0x84) = uVar7;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x4606);
  *(undefined2 *)(iVar15 + 0x9c) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x4605);
  *(undefined2 *)(iVar15 + 0x9e) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa0) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar15 + 0xa2) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa4) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar15 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x154) = 0x4ae;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x13a) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x146) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x152) = uVar2;
  iVar15 = *(int *)(param_1 + 0x284);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar15 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x128) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 300) = 4;
  uVar7 = *(undefined4 *)(param_1 + 0x284);
  uVar8 = GetRcEngine::RcGetNum(0x339f);
  GetRcEngine::RcGetNum(0x339e);
  ImageButton::SetImgExpandProperty((uchar)uVar7,0,uVar8);
  pMStack_1e0 = *(MImg **)(param_1 + 0x284);
  MImg::MImg(aMStack_13f4,0x5cd);
                    /* try { // try from 00d1f698 to 00d1f69f has its CatchHandler @ 00d1f884 */
  MImg::MImg(aMStack_1408,0x5cd);
                    /* try { // try from 00d1f6b4 to 00d1f6bb has its CatchHandler @ 00d1f848 */
  MImg::MImg(aMStack_141c,0x5cd);
                    /* try { // try from 00d1f6d0 to 00d1f6d7 has its CatchHandler @ 00d1f79c */
  MImg::MImg(aMStack_1430,0x5cd);
                    /* try { // try from 00d1f6fc to 00d1f703 has its CatchHandler @ 00d1f740 */
  ImageButton::SetImg(pMStack_1e0,aMStack_13f4,aMStack_1408,aMStack_141c);
                    /* try { // try from 00d1f714 to 00d1f71b has its CatchHandler @ 00d1f79c */
  MImg::~MImg(aMStack_1430);
                    /* try { // try from 00d1f72c to 00d1f733 has its CatchHandler @ 00d1f848 */
  MImg::~MImg(aMStack_141c);
                    /* try { // try from 00d1f788 to 00d1f78f has its CatchHandler @ 00d1f884 */
  MImg::~MImg(aMStack_1408);
  MImg::~MImg(aMStack_13f4);
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x284));
  if ((cRam010d74c8 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74c8), iVar15 != 0)) {
    uStack_1e4 = 0;
    pMStack_1ec = (MString *)0x10d78dc;
    pMStack_1e8 = pMStack_1ec;
    for (iStack_1f0 = 2; iStack_1f0 != -1; iStack_1f0 = iStack_1f0 + -1) {
                    /* try { // try from 00d1f920 to 00d1f927 has its CatchHandler @ 00d1f998 */
      MString::MString(pMStack_1ec);
      pMStack_1ec = pMStack_1ec + 0xc;
    }
    __cxa_guard_release(&cRam010d74c8);
    __cxa_atexit(FUN_00cf2b8c,0,&DAT_010cd2a8);
  }
  MString::Set(0x78dc);
  MString::Set(0x78e8);
  MString::Set(0x78f4);
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x250) = 0x10d78dc;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x254) = 3;
  MWidget::Hide();
  MWidget::Hide();
  MWidget::Hide();
  if ((cRam010d74d0 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74d0), iVar15 != 0)) {
    uStack_1f4 = 0;
    pMStack_1fc = (MString *)0x10d78c4;
    pMStack_1f8 = pMStack_1fc;
    for (iStack_200 = 1; iStack_200 != -1; iStack_200 = iStack_200 + -1) {
                    /* try { // try from 00d1fbc4 to 00d1fbcb has its CatchHandler @ 00d1fc3c */
      MString::MString(pMStack_1fc);
      pMStack_1fc = pMStack_1fc + 0xc;
    }
    __cxa_guard_release(&cRam010d74d0);
    __cxa_atexit(FUN_00cf2b08,0,&DAT_010cd2a8);
  }
  MString::Set(0x78d0);
  MString::Set(0x78c4);
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x250) = 0x10d78c4;
  *(undefined4 *)(*(int *)(param_1 + 0x20c) + 0x254) = 2;
  iVar15 = *(int *)(param_1 + 0x20c);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetGestureControlMode();
  *(undefined4 *)(iVar15 + 0x264) = uVar7;
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetGestureControl();
  if (iVar15 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x20c),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x20c),2,1);
  }
  if ((cRam010d74d8 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74d8), iVar15 != 0)) {
    uStack_204 = 0;
    pMStack_20c = (MString *)0x10d78a0;
    pMStack_208 = pMStack_20c;
    for (iStack_210 = 2; iStack_210 != -1; iStack_210 = iStack_210 + -1) {
                    /* try { // try from 00d1fea8 to 00d1feaf has its CatchHandler @ 00d1ff20 */
      MString::MString(pMStack_20c);
      pMStack_20c = pMStack_20c + 0xc;
    }
    __cxa_guard_release(&cRam010d74d8);
    __cxa_atexit(FUN_00cf2a84,0,&DAT_010cd2a8);
  }
  MString::Set(0x78a0);
  MString::Set(0x78ac);
  MString::Set(0x78b8);
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x250) = 0x10d78a0;
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x254) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x208) + 0x264) = 2;
  if ((*(int *)(*(int *)(param_1 + 0x208) + 0x264) == 0) ||
     (*(int *)(*(int *)(param_1 + 0x208) + 0x264) == 2)) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x208),1,0);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x20c),1,0);
  }
  if ((cRam010d74e0 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74e0), iVar15 != 0)) {
    uStack_214 = 0;
    pMStack_21c = (MString *)0x10d7780;
    pMStack_218 = pMStack_21c;
    for (iStack_220 = 0x17; iStack_220 != -1; iStack_220 = iStack_220 + -1) {
                    /* try { // try from 00d20178 to 00d2017f has its CatchHandler @ 00d201f0 */
      MString::MString(pMStack_21c);
      pMStack_21c = pMStack_21c + 0xc;
    }
    __cxa_guard_release(&cRam010d74e0);
    __cxa_atexit(FUN_00cf2a00,0,&DAT_010cd2a8);
  }
  MString::Set(0x7780);
  MString::Set(0x778c);
  MString::Set(0x7798);
  MString::Set(0x77a4);
  MString::Set(0x77b0);
  MString::Set(0x77bc);
  MString::Set(0x77c8);
  MString::Set(0x77d4);
  MString::Set(0x77e0);
  MString::Set(0x77ec);
  MString::Set(0x77f8);
  MString::Set(0x7804);
  MString::Set(0x7810);
  MString::Set(0x781c);
  MString::Set(0x7828);
  MString::Set(0x7834);
  MString::Set(0x7840);
  MString::Set(0x784c);
  MString::Set(0x7858);
  MString::Set(0x7864);
  MString::Set(0x7870);
  MString::Set(0x787c);
  MString::Set(0x7888);
  MString::Set(0x7894);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x250) = 0x10d7780;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x254) = 0x18;
  iVar15 = *(int *)(param_1 + 0x214);
  uVar7 = ArResourceManager::GetWirelessKeyboardLanguage();
  *(undefined4 *)(iVar15 + 0x264) = uVar7;
  if ((cRam010d74e8 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74e8), iVar15 != 0)) {
    uStack_224 = 0;
    pMStack_22c = (MString *)0x10d76f0;
    pMStack_228 = pMStack_22c;
    for (iStack_230 = 0xb; iStack_230 != -1; iStack_230 = iStack_230 + -1) {
                    /* try { // try from 00d2062c to 00d20633 has its CatchHandler @ 00d206a4 */
      MString::MString(pMStack_22c);
      pMStack_22c = pMStack_22c + 0xc;
    }
    __cxa_guard_release(&cRam010d74e8);
    __cxa_atexit(FUN_00cf297c,0,&DAT_010cd2a8);
  }
  MString::Set(0x76f0);
  std::allocator<char>::allocator();
                    /* try { // try from 00d207e4 to 00d207eb has its CatchHandler @ 00d208f4 */
  std::string::string(asStack_1434,"0",aaStack_1438);
                    /* try { // try from 00d20804 to 00d2080b has its CatchHandler @ 00d2088c */
  MString::Set((string *)0x10d76fc);
  psStack_234 = asStack_1434;
                    /* try { // try from 00d20820 to 00d20827 has its CatchHandler @ 00d208f4 */
  std::string::~string(psStack_234);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1438);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20878 to 00d2087f has its CatchHandler @ 00d20a1c */
  std::string::string(asStack_143c,"1",aaStack_1440);
                    /* try { // try from 00d208e0 to 00d208e7 has its CatchHandler @ 00d209b4 */
  MString::Set((string *)0x10d7708);
  psStack_238 = asStack_143c;
                    /* try { // try from 00d20948 to 00d2094f has its CatchHandler @ 00d20a1c */
  std::string::~string(psStack_238);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1440);
  std::allocator<char>::allocator();
                    /* try { // try from 00d209a0 to 00d209a7 has its CatchHandler @ 00d20b44 */
  std::string::string(asStack_1444,"2",aaStack_1448);
                    /* try { // try from 00d20a08 to 00d20a0f has its CatchHandler @ 00d20adc */
  MString::Set((string *)0x10d7714);
  psStack_23c = asStack_1444;
                    /* try { // try from 00d20a70 to 00d20a77 has its CatchHandler @ 00d20b44 */
  std::string::~string(psStack_23c);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1448);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20ac8 to 00d20acf has its CatchHandler @ 00d20c6c */
  std::string::string(asStack_144c,"3",aaStack_1450);
                    /* try { // try from 00d20b30 to 00d20b37 has its CatchHandler @ 00d20c04 */
  MString::Set((string *)0x10d7720);
  psStack_240 = asStack_144c;
                    /* try { // try from 00d20b98 to 00d20b9f has its CatchHandler @ 00d20c6c */
  std::string::~string(psStack_240);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1450);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20bf0 to 00d20bf7 has its CatchHandler @ 00d20d94 */
  std::string::string(asStack_1454,"4",aaStack_1458);
                    /* try { // try from 00d20c58 to 00d20c5f has its CatchHandler @ 00d20d2c */
  MString::Set((string *)0x10d772c);
  psStack_244 = asStack_1454;
                    /* try { // try from 00d20cc0 to 00d20cc7 has its CatchHandler @ 00d20d94 */
  std::string::~string(psStack_244);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1458);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20d18 to 00d20d1f has its CatchHandler @ 00d20ebc */
  std::string::string(asStack_145c,"5",aaStack_1460);
                    /* try { // try from 00d20d80 to 00d20d87 has its CatchHandler @ 00d20e54 */
  MString::Set((string *)0x10d7738);
  psStack_248 = asStack_145c;
                    /* try { // try from 00d20de8 to 00d20def has its CatchHandler @ 00d20ebc */
  std::string::~string(psStack_248);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1460);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20e40 to 00d20e47 has its CatchHandler @ 00d20fe4 */
  std::string::string(asStack_1464,"6",aaStack_1468);
                    /* try { // try from 00d20ea8 to 00d20eaf has its CatchHandler @ 00d20f7c */
  MString::Set((string *)0x10d7744);
  psStack_24c = asStack_1464;
                    /* try { // try from 00d20f10 to 00d20f17 has its CatchHandler @ 00d20fe4 */
  std::string::~string(psStack_24c);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1468);
  std::allocator<char>::allocator();
                    /* try { // try from 00d20f68 to 00d20f6f has its CatchHandler @ 00d2110c */
  std::string::string(asStack_146c,"7",aaStack_1470);
                    /* try { // try from 00d20fd0 to 00d20fd7 has its CatchHandler @ 00d210a4 */
  MString::Set((string *)0x10d7750);
  psStack_250 = asStack_146c;
                    /* try { // try from 00d21038 to 00d2103f has its CatchHandler @ 00d2110c */
  std::string::~string(psStack_250);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1470);
  std::allocator<char>::allocator();
                    /* try { // try from 00d21090 to 00d21097 has its CatchHandler @ 00d21234 */
  std::string::string(asStack_1474,"8",aaStack_1478);
                    /* try { // try from 00d210f8 to 00d210ff has its CatchHandler @ 00d211cc */
  MString::Set((string *)0x10d775c);
  psStack_254 = asStack_1474;
                    /* try { // try from 00d21160 to 00d21167 has its CatchHandler @ 00d21234 */
  std::string::~string(psStack_254);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1478);
  std::allocator<char>::allocator();
                    /* try { // try from 00d211b8 to 00d211bf has its CatchHandler @ 00d2135c */
  std::string::string(asStack_147c,"9",aaStack_1480);
                    /* try { // try from 00d21220 to 00d21227 has its CatchHandler @ 00d212f4 */
  MString::Set((string *)0x10d7768);
  psStack_258 = asStack_147c;
                    /* try { // try from 00d21288 to 00d2128f has its CatchHandler @ 00d2135c */
  std::string::~string(psStack_258);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1480);
  std::allocator<char>::allocator();
                    /* try { // try from 00d212e0 to 00d212e7 has its CatchHandler @ 00d21460 */
  std::string::string(asStack_1484,"10",aaStack_1488);
                    /* try { // try from 00d21348 to 00d2134f has its CatchHandler @ 00d21420 */
  MString::Set((string *)0x10d7774);
  psStack_25c = asStack_1484;
                    /* try { // try from 00d213b0 to 00d213b7 has its CatchHandler @ 00d21460 */
  std::string::~string(psStack_25c);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1488);
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x250) = 0x10d76f0;
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x254) = 0xc;
  *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x264) = 0;
  if (*(int *)(*(int *)(param_1 + 0x21c) + 0x264) == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x21c),1,0);
  }
  MWidget::Hide();
  MWidget::Hide();
  MWidget::Hide();
  if ((cRam010d74f0 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74f0), iVar15 != 0)) {
    uStack_260 = 0;
    pMStack_268 = (MString *)0x10d76c0;
    pMStack_264 = pMStack_268;
    for (iStack_26c = 3; iStack_26c != -1; iStack_26c = iStack_26c + -1) {
                    /* try { // try from 00d21588 to 00d2158f has its CatchHandler @ 00d21600 */
      MString::MString(pMStack_268);
      pMStack_268 = pMStack_268 + 0xc;
    }
    __cxa_guard_release(&cRam010d74f0);
    __cxa_atexit(FUN_00cf28f8,0,&DAT_010cd2a8);
  }
  std::ostringstream::ostringstream(aoStack_5b8,0x10);
                    /* try { // try from 00d2171c to 00d21723 has its CatchHandler @ 00d25498 */
  MString::Set(0x76c0);
  std::allocator<char>::allocator();
                    /* try { // try from 00d2175c to 00d21763 has its CatchHandler @ 00d21844 */
  std::string::string(asStack_148c,"",aaStack_1490);
                    /* try { // try from 00d2177c to 00d21783 has its CatchHandler @ 00d217e4 */
  std::ostringstream::str((string *)aoStack_5b8);
  psStack_270 = asStack_148c;
                    /* try { // try from 00d21798 to 00d2179f has its CatchHandler @ 00d21844 */
  std::string::~string(psStack_270);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1490);
                    /* try { // try from 00d217d0 to 00d217d7 has its CatchHandler @ 00d25498 */
  poStack_274 = std::operator<<((ostream *)aoStack_5b8,"10 ");
                    /* try { // try from 00d21830 to 00d218b3 has its CatchHandler @ 00d25498 */
  pcVar9 = (char *)GetRcEngine::RcGetString(0x11aa);
  std::operator<<(poStack_274,pcVar9);
  std::ostringstream::str();
                    /* try { // try from 00d218cc to 00d218d3 has its CatchHandler @ 00d21938 */
  std::string::operator=((string *)0x10d76d0,asStack_1494);
                    /* try { // try from 00d218e4 to 00d218eb has its CatchHandler @ 00d25498 */
  std::string::~string(asStack_1494);
  std::allocator<char>::allocator();
                    /* try { // try from 00d21924 to 00d2192b has its CatchHandler @ 00d21a50 */
  std::string::string(asStack_1498,"",aaStack_149c);
                    /* try { // try from 00d21988 to 00d2198f has its CatchHandler @ 00d219f0 */
  std::ostringstream::str((string *)aoStack_5b8);
  psStack_278 = asStack_1498;
                    /* try { // try from 00d219a4 to 00d219ab has its CatchHandler @ 00d21a50 */
  std::string::~string(psStack_278);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_149c);
                    /* try { // try from 00d219dc to 00d219e3 has its CatchHandler @ 00d25498 */
  poStack_27c = std::operator<<((ostream *)aoStack_5b8,"30 ");
                    /* try { // try from 00d21a3c to 00d21abf has its CatchHandler @ 00d25498 */
  pcVar9 = (char *)GetRcEngine::RcGetString(0x11aa);
  std::operator<<(poStack_27c,pcVar9);
  std::ostringstream::str();
                    /* try { // try from 00d21ad8 to 00d21adf has its CatchHandler @ 00d21b44 */
  std::string::operator=((string *)0x10d76dc,asStack_14a0);
                    /* try { // try from 00d21af0 to 00d21af7 has its CatchHandler @ 00d25498 */
  std::string::~string(asStack_14a0);
  std::allocator<char>::allocator();
                    /* try { // try from 00d21b30 to 00d21b37 has its CatchHandler @ 00d21c5c */
  std::string::string(asStack_14a4,"",aaStack_14a8);
                    /* try { // try from 00d21b94 to 00d21b9b has its CatchHandler @ 00d21bfc */
  std::ostringstream::str((string *)aoStack_5b8);
  psStack_280 = asStack_14a4;
                    /* try { // try from 00d21bb0 to 00d21bb7 has its CatchHandler @ 00d21c5c */
  std::string::~string(psStack_280);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_14a8);
                    /* try { // try from 00d21be8 to 00d21bef has its CatchHandler @ 00d25498 */
  poStack_284 = std::operator<<((ostream *)aoStack_5b8,"60 ");
                    /* try { // try from 00d21c48 to 00d21ccb has its CatchHandler @ 00d25498 */
  pcVar9 = (char *)GetRcEngine::RcGetString(0x11aa);
  std::operator<<(poStack_284,pcVar9);
  std::ostringstream::str();
                    /* try { // try from 00d21ce4 to 00d21ceb has its CatchHandler @ 00d21d50 */
  std::string::operator=((string *)0x10d76e8,asStack_14ac);
                    /* try { // try from 00d21cfc to 00d21d43 has its CatchHandler @ 00d25498 */
  std::string::~string(asStack_14ac);
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x250) = 0x10d76c0;
  *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x254) = 4;
  iStack_288 = *(int *)(param_1 + 0x250);
  ArTvSettingsManager::getInstance();
                    /* try { // try from 00d21d94 to 00d21d9b has its CatchHandler @ 00d25498 */
  uVar7 = ArTvSettingsManager::GetPowerSaveMode();
  *(undefined4 *)(iStack_288 + 0x264) = uVar7;
  if ((cRam010d74f8 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d74f8), iVar15 != 0)) {
    uStack_28c = 0;
    pMStack_294 = (MString *)0x10d76a8;
    pMStack_290 = pMStack_294;
    for (iStack_298 = 1; iStack_298 != -1; iStack_298 = iStack_298 + -1) {
                    /* try { // try from 00d21e14 to 00d21e1b has its CatchHandler @ 00d21e8c */
      MString::MString(pMStack_294);
      pMStack_294 = pMStack_294 + 0xc;
    }
    __cxa_guard_release(&cRam010d74f8);
    __cxa_atexit(FUN_00cf2874,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d21f84 to 00d21fa7 has its CatchHandler @ 00d25498 */
  MString::Set(0x76b4);
  MString::Set(0x76a8);
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x250) = 0x10d76a8;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x254) = 2;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x264) = 0;
  if ((cRam010d7500 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7500), iVar15 != 0)) {
    uStack_29c = 0;
    pMStack_2a4 = (MString *)0x10d7690;
    pMStack_2a0 = pMStack_2a4;
    for (iStack_2a8 = 1; iStack_2a8 != -1; iStack_2a8 = iStack_2a8 + -1) {
                    /* try { // try from 00d22048 to 00d2204f has its CatchHandler @ 00d220c0 */
      MString::MString(pMStack_2a4);
      pMStack_2a4 = pMStack_2a4 + 0xc;
    }
    __cxa_guard_release(&cRam010d7500);
    __cxa_atexit(FUN_00cf27f0,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d221b8 to 00d221db has its CatchHandler @ 00d25498 */
  MString::Set(0x769c);
  MString::Set(0x7690);
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x250) = 0x10d7690;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x254) = 2;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x264) = 0;
  if ((cRam010d7508 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7508), iVar15 != 0)) {
    uStack_2ac = 0;
    pMStack_2b4 = (MString *)0x10d766c;
    pMStack_2b0 = pMStack_2b4;
    for (iStack_2b8 = 2; iStack_2b8 != -1; iStack_2b8 = iStack_2b8 + -1) {
                    /* try { // try from 00d2227c to 00d22283 has its CatchHandler @ 00d222f4 */
      MString::MString(pMStack_2b4);
      pMStack_2b4 = pMStack_2b4 + 0xc;
    }
    __cxa_guard_release(&cRam010d7508);
    __cxa_atexit(FUN_00cf276c,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d223ec to 00d22473 has its CatchHandler @ 00d25498 */
  MString::Set(0x766c);
  MString::Set(0x7678);
  MString::Set(0x7684);
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x250) = 0x10d766c;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x254) = 3;
  ArTvPlayer::getInstance();
  iVar15 = ArTvPlayer::GetSubtitleMode();
  if (iVar15 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x264) = 2;
  }
  else if (iVar15 == 2) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x264) = 0;
  }
  else if (iVar15 == 1) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x264) = 1;
  }
  if ((cRam010d7510 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7510), iVar15 != 0)) {
    uStack_2bc = 0;
    pMStack_2c4 = (MString *)0x10d7648;
    pMStack_2c0 = pMStack_2c4;
    for (iStack_2c8 = 2; iStack_2c8 != -1; iStack_2c8 = iStack_2c8 + -1) {
                    /* try { // try from 00d22550 to 00d22557 has its CatchHandler @ 00d225c8 */
      MString::MString(pMStack_2c4);
      pMStack_2c4 = pMStack_2c4 + 0xc;
    }
    __cxa_guard_release(&cRam010d7510);
    __cxa_atexit(FUN_00cf26e8,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d226c0 to 00d22bd3 has its CatchHandler @ 00d25498 */
  MString::Set(0x7648);
  MString::Set(0x7654);
  MString::Set(0x7660);
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x250) = 0x10d7648;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x254) = 3;
  ArAudioManager::getInstance();
  iVar15 = ArAudioManager::GetAudioDescription();
  if (iVar15 == 2) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x264) = 2;
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
  }
  else {
    ArAudioManager::getInstance();
    iVar15 = ArAudioManager::GetAudioDescription();
    if (iVar15 == 1) {
      *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x264) = 1;
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,1);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x264) = 0;
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
    }
  }
  iStack_2cc = *(int *)(param_1 + 0x1ec);
  ArAudioManager::getInstance();
  uVar7 = ArAudioManager::GetAudioDescriptionVolume();
  *(undefined4 *)(iStack_2cc + 0x268) = uVar7;
  pAVar10 = (ArTvManager *)ArTvManager::getInstance();
  bVar1 = ArTvManager::GetCurrentInputSourceType(pAVar10);
  if ((bVar1 < 0xc) || (0xc < bVar1)) {
    if (bVar1 == 1) {
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e8),1,0);
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
    }
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e8),1,0);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
  }
  pAVar10 = (ArTvManager *)ArTvManager::getInstance();
  iVar15 = ArTvManager::GetDualWatchStatus(pAVar10);
  if (iVar15 == 1) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e8),1,0);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetBluetooth();
  if (iVar15 != 1) {
    MWidget::Hide();
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
  if (iVar15 == 1) {
    MWidget::Hide();
    MWidget::Hide();
    MWidget::Hide();
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetBluetooth();
  if (iVar15 == 0) {
    ArServiceSettingsManager::getInstance();
    iVar15 = ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled();
    if (iVar15 != 1) goto LAB_00d22b7c;
    iStack_2d0 = 1;
  }
  else {
LAB_00d22b7c:
    iStack_2d0 = 0;
  }
  if (iStack_2d0 != 0) {
    MWidget::Hide();
  }
  iStack_2d4 = *(int *)(param_1 + 0x200);
  ArAudioManager::getInstance();
  uVar7 = ArAudioManager::GetVRHeadphoneVolumeVolume();
  *(undefined4 *)(iStack_2d4 + 0x268) = uVar7;
  if ((cRam010d7518 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7518), iVar15 != 0)) {
    uStack_2d8 = 0;
    pMStack_2e0 = (MString *)0x10d760c;
    pMStack_2dc = pMStack_2e0;
    for (iStack_2e4 = 4; iStack_2e4 != -1; iStack_2e4 = iStack_2e4 + -1) {
                    /* try { // try from 00d22c4c to 00d22c53 has its CatchHandler @ 00d22cc4 */
      MString::MString(pMStack_2e0);
      pMStack_2e0 = pMStack_2e0 + 0xc;
    }
    __cxa_guard_release(&cRam010d7518);
    __cxa_atexit(FUN_00cf2664,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d22dbc to 00d22e87 has its CatchHandler @ 00d25498 */
  MString::Set(0x760c);
  MString::Set(0x7618);
  MString::Set(0x7624);
  MString::Set(0x7630);
  MString::Set(0x763c);
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x250) = 0x10d760c;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x254) = 5;
  iStack_2e8 = *(int *)(param_1 + 0x240);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetAutoSleepMode();
  *(undefined4 *)(iStack_2e8 + 0x264) = uVar7;
  if ((cRam010d7520 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7520), iVar15 != 0)) {
    uStack_2ec = 0;
    pMStack_2f4 = (MString *)0x10d75f4;
    pMStack_2f0 = pMStack_2f4;
    for (iStack_2f8 = 1; iStack_2f8 != -1; iStack_2f8 = iStack_2f8 + -1) {
                    /* try { // try from 00d22f00 to 00d22f07 has its CatchHandler @ 00d22f78 */
      MString::MString(pMStack_2f4);
      pMStack_2f4 = pMStack_2f4 + 0xc;
    }
    __cxa_guard_release(&cRam010d7520);
    __cxa_atexit(FUN_00cf25e0,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d23070 to 00d230e7 has its CatchHandler @ 00d25498 */
  MString::Set(0x7600);
  MString::Set(0x75f4);
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x250) = 0x10d75f4;
  *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x254) = 2;
  iStack_2fc = *(int *)(param_1 + 0x248);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetShopMode();
  *(undefined4 *)(iStack_2fc + 0x264) = uVar7;
  if ((cRam010d7528 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7528), iVar15 != 0)) {
    uStack_300 = 0;
    pMStack_308 = (MString *)0x10d75d0;
    pMStack_304 = pMStack_308;
    for (iStack_30c = 2; iStack_30c != -1; iStack_30c = iStack_30c + -1) {
                    /* try { // try from 00d23160 to 00d23167 has its CatchHandler @ 00d231d8 */
      MString::MString(pMStack_308);
      pMStack_308 = pMStack_308 + 0xc;
    }
    __cxa_guard_release(&cRam010d7528);
    __cxa_atexit(FUN_00cf255c,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d232d0 to 00d23363 has its CatchHandler @ 00d25498 */
  MString::Set(0x75d0);
  MString::Set(0x75dc);
  MString::Set(0x75e8);
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x250) = 0x10d75d0;
  *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x254) = 3;
  iStack_310 = *(int *)(param_1 + 0x24c);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetPowerLed();
  *(undefined4 *)(iStack_310 + 0x264) = uVar7;
  if ((cRam010d7530 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7530), iVar15 != 0)) {
    uStack_314 = 0;
    pMStack_31c = (MString *)0x10d75b8;
    pMStack_318 = pMStack_31c;
    for (iStack_320 = 1; iStack_320 != -1; iStack_320 = iStack_320 + -1) {
                    /* try { // try from 00d233dc to 00d233e3 has its CatchHandler @ 00d23454 */
      MString::MString(pMStack_31c);
      pMStack_31c = pMStack_31c + 0xc;
    }
    __cxa_guard_release(&cRam010d7530);
    __cxa_atexit(FUN_00cf24d8,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d2354c to 00d235c3 has its CatchHandler @ 00d25498 */
  MString::Set(0x75b8);
  MString::Set(0x75c4);
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x250) = 0x10d75b8;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x254) = 2;
  iStack_324 = *(int *)(param_1 + 0x244);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetFastZapping();
  *(undefined4 *)(iStack_324 + 0x264) = uVar7;
  if ((cRam010d7538 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7538), iVar15 != 0)) {
    uStack_328 = 0;
    pMStack_330 = (MString *)0x10d75a0;
    pMStack_32c = pMStack_330;
    for (iStack_334 = 1; iStack_334 != -1; iStack_334 = iStack_334 + -1) {
                    /* try { // try from 00d2363c to 00d23643 has its CatchHandler @ 00d236b4 */
      MString::MString(pMStack_330);
      pMStack_330 = pMStack_330 + 0xc;
    }
    __cxa_guard_release(&cRam010d7538);
    __cxa_atexit(FUN_00cf2454,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d237ac to 00d23823 has its CatchHandler @ 00d25498 */
  MString::Set(0x75a0);
  MString::Set(0x75ac);
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x250) = 0x10d75a0;
  *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x254) = 2;
  iStack_338 = *(int *)(param_1 + 0x254);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetPermanentTimeShift();
  *(undefined4 *)(iStack_338 + 0x264) = uVar7;
  if ((cRam010d7540 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7540), iVar15 != 0)) {
    uStack_33c = 0;
    pMStack_344 = (MString *)0x10d7588;
    pMStack_340 = pMStack_344;
    for (iStack_348 = 1; iStack_348 != -1; iStack_348 = iStack_348 + -1) {
                    /* try { // try from 00d2389c to 00d238a3 has its CatchHandler @ 00d23914 */
      MString::MString(pMStack_344);
      pMStack_344 = pMStack_344 + 0xc;
    }
    __cxa_guard_release(&cRam010d7540);
    __cxa_atexit(FUN_00cf23d0,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d23a0c to 00d23a83 has its CatchHandler @ 00d25498 */
  MString::Set(0x7594);
  MString::Set(0x7588);
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x250) = 0x10d7588;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x254) = 2;
  iStack_34c = *(int *)(param_1 + 0x260);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetFastBootMode();
  *(undefined4 *)(iStack_34c + 0x264) = uVar7;
  if ((cRam010d7548 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7548), iVar15 != 0)) {
    uStack_350 = 0;
    pMStack_358 = (MString *)0x10d7570;
    pMStack_354 = pMStack_358;
    for (iStack_35c = 1; iStack_35c != -1; iStack_35c = iStack_35c + -1) {
                    /* try { // try from 00d23afc to 00d23b03 has its CatchHandler @ 00d23b74 */
      MString::MString(pMStack_358);
      pMStack_358 = pMStack_358 + 0xc;
    }
    __cxa_guard_release(&cRam010d7548);
    __cxa_atexit(FUN_00cf234c,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d23c6c to 00d23ce3 has its CatchHandler @ 00d25498 */
  MString::Set(0x757c);
  MString::Set(0x7570);
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x250) = 0x10d7570;
  *(undefined4 *)(*(int *)(param_1 + 600) + 0x254) = 2;
  iStack_360 = *(int *)(param_1 + 600);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetWeatherWidget();
  *(undefined4 *)(iStack_360 + 0x264) = uVar7;
  if ((cRam010d7550 == '\0') && (iVar15 = __cxa_guard_acquire(&cRam010d7550), iVar15 != 0)) {
    uStack_364 = 0;
    pMStack_36c = (MString *)0x10d7558;
    pMStack_368 = pMStack_36c;
    for (iStack_370 = 1; iStack_370 != -1; iStack_370 = iStack_370 + -1) {
                    /* try { // try from 00d23d5c to 00d23d63 has its CatchHandler @ 00d23dd4 */
      MString::MString(pMStack_36c);
      pMStack_36c = pMStack_36c + 0xc;
    }
    __cxa_guard_release(&cRam010d7550);
    __cxa_atexit(FUN_00cf22c8,0,&DAT_010cd2a8);
  }
                    /* try { // try from 00d23ecc to 00d2414b has its CatchHandler @ 00d25498 */
  MString::Set(0x7564);
  MString::Set(0x7558);
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x250) = 0x10d7558;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x254) = 2;
  iStack_374 = *(int *)(param_1 + 0x25c);
  ArTvSettingsManager::getInstance();
  uVar7 = ArTvSettingsManager::GetBubbleHelp();
  *(undefined4 *)(iStack_374 + 0x264) = uVar7;
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetFastBoot();
  if (iVar15 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x260),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x260),2,1);
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetWeatherWidget();
  if (iVar15 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 600),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 600),2,1);
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetBubbleHelp();
  if (iVar15 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x25c),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x25c),2,1);
  }
  psStack_378 = (string *)(*(int *)(*(int *)(param_1 + 0x280) + 0x260) + 0x170);
  pAStack_37c = (ArResourceManager *)ArResourceManager::getInstance();
  ArResourceManager::getInstance();
  uVar7 = ArResourceManager::GetSelectedCountry();
  uVar11 = ArResourceManager::GetCountryStrID(pAStack_37c,uVar7);
  pcVar9 = (char *)GetRcEngine::RcGetString(uVar11);
  std::allocator<char>::allocator();
                    /* try { // try from 00d24184 to 00d2418b has its CatchHandler @ 00d24274 */
  std::string::string(asStack_14b0,pcVar9,aaStack_14b4);
                    /* try { // try from 00d241a0 to 00d241a7 has its CatchHandler @ 00d2420c */
  MString::Set(psStack_378);
  psStack_380 = asStack_14b0;
                    /* try { // try from 00d241bc to 00d241c3 has its CatchHandler @ 00d24274 */
  std::string::~string(psStack_380);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_14b4);
                    /* try { // try from 00d241f8 to 00d241ff has its CatchHandler @ 00d25498 */
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x280),1,0);
  pcStack_384 = *(char **)(*(int *)(param_1 + 0x268) + 0x260);
                    /* try { // try from 00d24260 to 00d2544f has its CatchHandler @ 00d25498 */
  ArTvSettingsManager::getInstance();
  ArTvSettingsManager::GetTVName();
  MWidget::SetText(pcStack_384);
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0xac) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0xac) = *(undefined4 *)(param_1 + 0x1ac);
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0xac) = *(undefined4 *)(param_1 + 0x1b0);
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0xac) = *(undefined4 *)(param_1 + 0x1b4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0xac) = *(undefined4 *)(param_1 + 0x1b8);
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0xac) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0xac) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0xac) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0xac) = *(undefined4 *)(param_1 + 0x1dc);
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0xac) = *(undefined4 *)(param_1 + 0x220);
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0xac) = *(undefined4 *)(param_1 + 0x224);
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0xac) = *(undefined4 *)(param_1 + 0x228);
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0xac) = *(undefined4 *)(param_1 + 0x26c);
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0xac) = *(undefined4 *)(param_1 + 0x270);
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0xac) = *(undefined4 *)(param_1 + 0x264);
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0xac) = *(undefined4 *)(param_1 + 0x284);
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0xa8) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0xa8) = *(undefined4 *)(param_1 + 0x1ac);
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0xa8) = *(undefined4 *)(param_1 + 0x1b0);
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0xa8) = *(undefined4 *)(param_1 + 0x1b4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0xa8) = *(undefined4 *)(param_1 + 0x1b8);
  *(undefined4 *)(*(int *)(param_1 + 0x1d0) + 0xa8) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0xa8) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(*(int *)(param_1 + 0x1d8) + 0xa8) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(*(int *)(param_1 + 0x1dc) + 0xa8) = *(undefined4 *)(param_1 + 0x1dc);
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0xa8) = *(undefined4 *)(param_1 + 0x220);
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0xa8) = *(undefined4 *)(param_1 + 0x224);
  *(undefined4 *)(*(int *)(param_1 + 0x228) + 0xa8) = *(undefined4 *)(param_1 + 0x228);
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0xa8) = *(undefined4 *)(param_1 + 0x26c);
  *(undefined4 *)(*(int *)(param_1 + 0x270) + 0xa8) = *(undefined4 *)(param_1 + 0x270);
  *(undefined4 *)(*(int *)(param_1 + 0x264) + 0xa8) = *(undefined4 *)(param_1 + 0x264);
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0xa8) = *(undefined4 *)(param_1 + 0x284);
  MMainFrame::SetInitialFocus(param_1);
  MWnd::GetParentApp();
  iVar15 = MApplet::GetPrivateData();
  if (iVar15 == 0xb) {
    MMainFrame::SwitchFocusTo(param_1);
    this = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::focusToBar(this,'\0');
  }
  iVar15 = ArTvSettingsManager::IsTvInFirstTime();
  if (iVar15 == 0) {
    iVar15 = MenuBackgroundFrame::getMenuBackgroundFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1cc),0xf,0xd41);
    iVar15 = MenuBackgroundFrame::getMenuBackgroundFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1cc),0xe,0xc42);
    iVar15 = MenuBackgroundFrame::getMenuBackgroundFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1cc),6,0x10c6);
    iVar15 = MenuBackgroundFrame::getMenuBackgroundFrame();
    HelpWidget::Refresh(*(HelpWidget **)(iVar15 + 0x1cc));
  }
  else {
    iVar15 = FirstTimeFrame::getFrame();
    HelpWidget::HideAllButtons(*(HelpWidget **)(iVar15 + 0x1b4));
    iVar15 = FirstTimeFrame::getFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1b4),0xf,0xd41);
    iVar15 = FirstTimeFrame::getFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1b4),3,0xcae);
    iVar15 = FirstTimeFrame::getFrame();
    HelpWidget::ShowButton(*(HelpWidget **)(iVar15 + 0x1b4),0xe,0xc42);
    iVar15 = FirstTimeFrame::getFrame();
    HelpWidget::Refresh(*(HelpWidget **)(iVar15 + 0x1b4));
  }
  MWidget::Hide();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x284),2,0);
  iVar15 = ArTvSettingsManager::IsTvInFirstTime();
  if (iVar15 == 0) {
    MWidget::Hide();
    MEvtHandle::PostEvent((MEvtHandle *)param_1,(ulong)param_1,0xc0000020,0);
  }
  pAVar10 = (ArTvManager *)ArTvManager::getInstance();
  ArTvManager::LockParental(pAVar10);
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetPermanentTimeshift();
  if (iVar15 == 0) {
LAB_00d248f4:
    iStack_388 = 1;
  }
  else {
    ArServiceSettingsManager::getInstance();
    iVar15 = ArServiceSettingsManager::ArTvConf_GetUsbRecording();
    if (iVar15 == 0) goto LAB_00d248f4;
    iStack_388 = 0;
  }
  if (iStack_388 != 0) {
    MWidget::Hide();
  }
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c0),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c4),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c8),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x234),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x234),1,0);
  MWidget::Invalidate();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x204),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x204),1,0);
  MWidget::Invalidate();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x20c),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x20c),2,0);
  MWidget::Invalidate();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x228),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x228),2,0);
  MWidget::Invalidate();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x224),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x224),2,0);
  MWidget::Invalidate();
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x208),2,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x208),1,0);
  MWidget::Invalidate();
  iVar15 = ArTvSettingsManager::IsTvInFirstTime();
  if (iVar15 != 0) {
    iVar15 = FirstTimeFrame::getFrame();
    MWidget::SetText((ushort)*(undefined4 *)(iVar15 + 0x19c));
    FirstTimeFrame::getFrame();
    MWidget::Invalidate();
    this_00 = (FirstTimeFrame *)FirstTimeFrame::getFrame();
    FirstTimeFrame::focusToBar(this_00,'\0');
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x18c),2,0);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x198),2,1);
    (**(code **)(**(int **)(param_1 + 0x198) + 0x48))(*(undefined4 *)(param_1 + 0x198));
    MWidget::Invalidate();
    uVar11 = (**(code **)(**(int **)(param_1 + 0x198) + 0x44))(*(undefined4 *)(param_1 + 0x198));
    for (uStack_14d0 = 0; uStack_14d0 < uVar11; uStack_14d0 = uStack_14d0 + 1) {
      iVar15 = (**(code **)(**(int **)(param_1 + 0x198) + 0x40))
                         (*(undefined4 *)(param_1 + 0x198),uStack_14d0);
      iVar12 = MWidget::QueryFlag((uchar)iVar15);
      if ((iVar12 == 0) || (*(char *)(iVar15 + 0x38) != '\x01')) {
        iStack_38c = 0;
      }
      else {
        iStack_38c = 1;
      }
      if (iStack_38c != 0) {
        MMainFrame::SwitchFocusTo(param_1);
        break;
      }
    }
  }
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x180),2,0);
  pMVar13 = (MMainFrame *)ArUIManager::getInstance();
  ArUIManager::NewUI_Settings(pMVar13);
  CommonFrame::EnableShadows((uchar)param_1);
  uStack_610 = 0x19;
  uStack_60c = 0x10b0;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_610);
  uStack_608 = 0x1a;
  uStack_604 = 0x1089;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_608);
  uStack_600 = 0x30;
  uStack_5fc = 0x108c;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_600);
  uStack_5f8 = 0x31;
  uStack_5f4 = 0x1093;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5f8);
  uStack_5f0 = 0x33;
  uStack_5ec = 0x10a8;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5f0);
  uStack_5e8 = 0x34;
  uStack_5e4 = 0x10a9;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5e8);
  uStack_5e0 = 0x35;
  uStack_5dc = 0x10a5;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5e0);
  uStack_5d8 = 0x36;
  uStack_5d4 = 0x10b7;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5d8);
  uStack_5d0 = 0x37;
  uStack_5cc = 0x1090;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5d0);
  uStack_5c8 = 0x32;
  uStack_5c4 = 0x10ae;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5c8);
  uStack_5c0 = 0x3f;
  uStack_5bc = 0x10ad;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::push_back
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(param_1 + 0x10c),
             (bubblehelppair *)&uStack_5c0);
  pAVar10 = (ArTvManager *)ArTvManager::getInstance();
  iVar15 = ArTvManager::GetCurrentInputSourceType(pAVar10);
  if (iVar15 == 5) {
    pAVar14 = (ArAudioManager *)ArAudioManager::getInstance();
    ArAudioManager::SetAudioDescription(pAVar14,3);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1e8),1,0);
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1ec),1,0);
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetCustomScreenSaver();
  if (iVar15 == 0) {
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArSystemConf_GetHotel();
  if (iVar15 == 0) {
LAB_00d25230:
    iStack_390 = 0;
  }
  else {
    ArTvSettingsManager::getInstance();
    iVar15 = ArTvSettingsManager::GetHotelAdmin();
    if (iVar15 != 0) goto LAB_00d25230;
    iStack_390 = 1;
  }
  if (iStack_390 != 0) {
    MWidget::Hide();
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArSystemConf_GetHotel();
  if (iVar15 == 0) {
LAB_00d252d0:
    iStack_394 = 1;
  }
  else {
    ArTvSettingsManager::getInstance();
    iVar15 = ArTvSettingsManager::GetHotelAdmin();
    if (iVar15 == 0) goto LAB_00d252d0;
    iStack_394 = 0;
  }
  if (iStack_394 != 0) {
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetSettingsRecovery();
  if (iVar15 == 0) {
    MWidget::Hide();
  }
  ArServiceSettingsManager::getInstance();
  iVar15 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
  if (iVar15 == 1) {
    ArTvSettingsManager::getInstance();
    iVar15 = ArTvSettingsManager::GetBasicMode();
    if (iVar15 == 1) {
      iStack_398 = 1;
      goto LAB_00d253d8;
    }
  }
  iStack_398 = 0;
LAB_00d253d8:
  if (iStack_398 != 0) {
    MWidget::Hide();
    MWidget::Hide();
    MWidget::Hide();
    MWidget::Hide();
  }
  std::ostringstream::~ostringstream(aoStack_5b8);
  return 0;
}

