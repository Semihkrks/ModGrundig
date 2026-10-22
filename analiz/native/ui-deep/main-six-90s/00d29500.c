
/* HomePageFrame::LayoutItems() */

void __thiscall HomePageFrame::LayoutItems(HomePageFrame *this)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  int iStack_1ab0;
  int iStack_1aa8;
  int iStack_1aa4;
  int iStack_1aa0;
  int iStack_1a9c;
  byte bStack_1a98;
  byte bStack_1a97;
  uint uStack_1a88;
  int iStack_1a84;
  int iStack_1a78;
  int iStack_1a74;
  byte bStack_1a70;
  byte bStack_1a6f;
  int iStack_1a58;
  int iStack_1a54;
  uint uStack_1a44;
  int iStack_1a40;
  int iStack_1a38;
  int iStack_1a34;
  byte bStack_1a30;
  byte bStack_1a2f;
  undefined1 auStack_1a20 [4];
  undefined1 auStack_1a1c [4];
  undefined1 auStack_1a18 [4];
  undefined1 auStack_1a14 [20];
  undefined1 auStack_1a00 [20];
  undefined1 auStack_19ec [20];
  undefined1 auStack_19d8 [20];
  undefined1 auStack_19c4 [20];
  undefined1 auStack_19b0 [20];
  undefined1 auStack_199c [20];
  undefined1 auStack_1988 [20];
  undefined1 auStack_1974 [20];
  undefined1 auStack_1960 [20];
  undefined1 auStack_194c [20];
  undefined1 auStack_1938 [20];
  undefined1 auStack_1924 [20];
  undefined1 auStack_1910 [20];
  undefined1 auStack_18fc [20];
  undefined1 auStack_18e8 [20];
  undefined1 auStack_18d4 [20];
  undefined1 auStack_18c0 [20];
  undefined1 auStack_18ac [20];
  undefined1 auStack_1898 [20];
  undefined1 auStack_1884 [20];
  undefined1 auStack_1870 [20];
  undefined1 auStack_185c [20];
  undefined1 auStack_1848 [20];
  undefined1 auStack_1834 [20];
  undefined1 auStack_1820 [20];
  undefined1 auStack_180c [20];
  undefined1 auStack_17f8 [20];
  undefined1 auStack_17e4 [20];
  undefined1 auStack_17d0 [20];
  undefined1 auStack_17bc [20];
  undefined1 auStack_17a8 [20];
  undefined1 auStack_1794 [20];
  undefined1 auStack_1780 [20];
  undefined1 auStack_176c [20];
  undefined1 auStack_1758 [20];
  undefined1 auStack_1744 [20];
  undefined1 auStack_1730 [20];
  undefined1 auStack_171c [20];
  undefined1 auStack_1708 [20];
  undefined1 auStack_16f4 [4];
  undefined1 auStack_16f0 [4];
  undefined1 auStack_16ec [20];
  undefined1 auStack_16d8 [20];
  undefined1 auStack_16c4 [20];
  undefined1 auStack_16b0 [20];
  undefined1 auStack_169c [20];
  undefined1 auStack_1688 [20];
  undefined1 auStack_1674 [20];
  undefined1 auStack_1660 [20];
  undefined1 auStack_164c [20];
  undefined1 auStack_1638 [20];
  undefined1 auStack_1624 [20];
  undefined1 auStack_1610 [20];
  undefined1 auStack_15fc [20];
  undefined1 auStack_15e8 [20];
  undefined1 auStack_15d4 [20];
  undefined1 auStack_15c0 [20];
  undefined1 auStack_15ac [20];
  undefined1 auStack_1598 [20];
  undefined1 auStack_1584 [20];
  undefined1 auStack_1570 [20];
  undefined1 auStack_155c [20];
  undefined1 auStack_1548 [20];
  undefined1 auStack_1534 [20];
  undefined1 auStack_1520 [20];
  undefined1 auStack_150c [20];
  undefined1 auStack_14f8 [20];
  undefined1 auStack_14e4 [4];
  undefined1 auStack_14e0 [4];
  undefined1 auStack_14dc [4];
  undefined1 auStack_14d8 [4];
  undefined1 auStack_14d4 [20];
  undefined1 auStack_14c0 [20];
  undefined1 auStack_14ac [20];
  undefined1 auStack_1498 [20];
  undefined1 auStack_1484 [20];
  undefined1 auStack_1470 [20];
  undefined1 auStack_145c [20];
  undefined1 auStack_1448 [20];
  undefined1 auStack_1434 [20];
  undefined1 auStack_1420 [20];
  undefined1 auStack_140c [20];
  undefined1 auStack_13f8 [20];
  undefined1 auStack_13e4 [4];
  undefined1 auStack_13e0 [20];
  undefined1 auStack_13cc [20];
  undefined1 auStack_13b8 [20];
  undefined1 auStack_13a4 [20];
  undefined1 auStack_1390 [20];
  undefined1 auStack_137c [20];
  undefined1 auStack_1368 [20];
  undefined1 auStack_1354 [20];
  undefined1 auStack_1340 [20];
  undefined1 auStack_132c [20];
  undefined1 auStack_1318 [20];
  undefined1 auStack_1304 [20];
  undefined1 auStack_12f0 [20];
  undefined1 auStack_12dc [20];
  undefined1 auStack_12c8 [20];
  undefined1 auStack_12b4 [20];
  undefined1 auStack_12a0 [20];
  undefined1 auStack_128c [20];
  undefined1 auStack_1278 [20];
  undefined1 auStack_1264 [20];
  undefined1 auStack_1250 [20];
  undefined1 auStack_123c [20];
  undefined1 auStack_1228 [20];
  undefined1 auStack_1214 [20];
  undefined1 auStack_1200 [20];
  undefined1 auStack_11ec [20];
  undefined1 auStack_11d8 [20];
  undefined1 auStack_11c4 [20];
  undefined1 auStack_11b0 [20];
  undefined1 auStack_119c [20];
  undefined1 auStack_1188 [20];
  undefined1 auStack_1174 [20];
  undefined1 auStack_1160 [20];
  undefined1 auStack_114c [20];
  undefined1 auStack_1138 [4];
  undefined1 auStack_1134 [20];
  undefined1 auStack_1120 [20];
  undefined1 auStack_110c [20];
  undefined1 auStack_10f8 [20];
  undefined1 auStack_10e4 [20];
  undefined1 auStack_10d0 [20];
  undefined1 auStack_10bc [20];
  undefined1 auStack_10a8 [20];
  undefined1 auStack_1094 [20];
  undefined1 auStack_1080 [20];
  undefined1 auStack_106c [20];
  undefined1 auStack_1058 [20];
  undefined1 auStack_1044 [20];
  undefined1 auStack_1030 [20];
  undefined1 auStack_101c [20];
  undefined1 auStack_1008 [20];
  undefined1 auStack_ff4 [20];
  undefined1 auStack_fe0 [20];
  undefined1 auStack_fcc [20];
  undefined1 auStack_fb8 [20];
  undefined1 auStack_fa4 [20];
  undefined1 auStack_f90 [20];
  undefined1 auStack_f7c [20];
  undefined1 auStack_f68 [20];
  undefined1 auStack_f54 [20];
  undefined1 auStack_f40 [20];
  undefined1 auStack_f2c [20];
  undefined1 auStack_f18 [20];
  undefined1 auStack_f04 [20];
  undefined1 auStack_ef0 [20];
  undefined1 auStack_edc [20];
  undefined1 auStack_ec8 [20];
  undefined1 auStack_eb4 [20];
  undefined1 auStack_ea0 [20];
  undefined1 auStack_e8c [20];
  undefined1 auStack_e78 [20];
  undefined1 auStack_e64 [20];
  undefined1 auStack_e50 [20];
  undefined1 auStack_e3c [20];
  undefined1 auStack_e28 [20];
  undefined1 auStack_e14 [20];
  undefined1 auStack_e00 [20];
  undefined1 auStack_dec [20];
  undefined1 auStack_dd8 [20];
  undefined1 auStack_dc4 [4];
  undefined1 auStack_dc0 [20];
  undefined1 auStack_dac [20];
  undefined1 auStack_d98 [20];
  undefined1 auStack_d84 [20];
  undefined1 auStack_d70 [20];
  undefined1 auStack_d5c [20];
  undefined1 auStack_d48 [20];
  undefined1 auStack_d34 [20];
  undefined1 auStack_d20 [4];
  undefined1 auStack_d1c [4];
  undefined1 auStack_d18 [4];
  undefined1 auStack_d14 [4];
  undefined1 auStack_d10 [20];
  undefined1 auStack_cfc [20];
  undefined1 auStack_ce8 [20];
  undefined1 auStack_cd4 [20];
  undefined1 auStack_cc0 [20];
  undefined1 auStack_cac [20];
  undefined1 auStack_c98 [20];
  undefined1 auStack_c84 [20];
  undefined1 auStack_c70 [20];
  undefined1 auStack_c5c [20];
  undefined1 auStack_c48 [20];
  undefined1 auStack_c34 [20];
  undefined1 auStack_c20 [20];
  undefined1 auStack_c0c [20];
  undefined1 auStack_bf8 [20];
  undefined1 auStack_be4 [20];
  undefined1 auStack_bd0 [20];
  undefined1 auStack_bbc [20];
  undefined1 auStack_ba8 [20];
  undefined1 auStack_b94 [20];
  undefined1 auStack_b80 [20];
  undefined1 auStack_b6c [20];
  undefined1 auStack_b58 [20];
  undefined1 auStack_b44 [20];
  undefined1 auStack_b30 [20];
  undefined1 auStack_b1c [20];
  int aiStack_b08 [4];
  undefined1 auStack_af8 [8];
  undefined1 auStack_af0 [4];
  int aiStack_aec [4];
  undefined1 auStack_adc [8];
  undefined1 auStack_ad4 [4];
  int aiStack_ad0 [4];
  undefined4 uStack_ac0;
  undefined4 uStack_abc;
  undefined4 uStack_ab8;
  undefined4 uStack_ab4;
  undefined4 uStack_ab0;
  undefined4 uStack_aac;
  undefined4 uStack_aa8;
  undefined4 uStack_aa4;
  undefined4 uStack_aa0;
  undefined4 uStack_a9c;
  undefined4 uStack_a98;
  undefined4 uStack_a94;
  undefined4 uStack_a90;
  undefined4 uStack_a8c;
  undefined4 uStack_a88;
  undefined4 uStack_a84;
  undefined1 auStack_a80 [180];
  undefined1 auStack_9cc [4];
  undefined4 auStack_9c8 [24];
  undefined4 auStack_968 [5];
  undefined1 auStack_954 [8];
  undefined1 auStack_94c [4];
  undefined1 auStack_948 [4];
  undefined4 auStack_944 [27];
  undefined4 uStack_8d8;
  undefined4 uStack_8d4;
  undefined4 uStack_8d0;
  undefined4 uStack_8cc;
  undefined4 uStack_8c8;
  undefined4 uStack_8c4;
  undefined4 uStack_8c0;
  undefined4 uStack_8bc;
  undefined4 uStack_8b8;
  undefined1 auStack_8ac [32];
  undefined1 auStack_88c [52];
  undefined1 auStack_858 [20];
  undefined1 auStack_844 [20];
  undefined1 auStack_830 [20];
  undefined1 auStack_81c [152];
  undefined1 auStack_784 [20];
  undefined1 auStack_770 [20];
  undefined1 auStack_75c [20];
  undefined1 auStack_748 [100];
  undefined1 auStack_6e4 [112];
  undefined1 *puStack_674;
  undefined1 *puStack_670;
  undefined1 *puStack_664;
  undefined1 *puStack_660;
  undefined1 *puStack_654;
  undefined1 *puStack_650;
  undefined1 *puStack_644;
  int iStack_640;
  int iStack_63c;
  int iStack_638;
  int iStack_634;
  int iStack_630;
  int iStack_62c;
  int iStack_628;
  int iStack_624;
  int iStack_620;
  int iStack_61c;
  int iStack_618;
  int iStack_614;
  int iStack_610;
  int iStack_60c;
  int iStack_608;
  int iStack_604;
  int iStack_600;
  int iStack_5fc;
  int iStack_5f8;
  int iStack_5f4;
  int iStack_5f0;
  int iStack_5ec;
  int iStack_5e8;
  int iStack_5e4;
  int iStack_5e0;
  int iStack_5dc;
  int iStack_5d8;
  int iStack_5d4;
  int iStack_5d0;
  int iStack_5cc;
  int iStack_5c8;
  int iStack_5c4;
  int iStack_5c0;
  int iStack_5bc;
  int iStack_5b8;
  int iStack_5b4;
  int iStack_5b0;
  int iStack_5ac;
  int iStack_5a8;
  int iStack_5a4;
  int iStack_5a0;
  int iStack_59c;
  int iStack_598;
  int iStack_594;
  int iStack_590;
  int iStack_58c;
  int iStack_588;
  int iStack_584;
  int iStack_580;
  int iStack_57c;
  int iStack_578;
  int iStack_574;
  int iStack_570;
  int iStack_56c;
  int iStack_568;
  int iStack_564;
  int iStack_560;
  int iStack_55c;
  int iStack_558;
  int iStack_554;
  undefined1 *puStack_550;
  int iStack_54c;
  int iStack_548;
  int iStack_544;
  int iStack_540;
  int iStack_53c;
  int iStack_538;
  int iStack_534;
  int iStack_530;
  int iStack_52c;
  int iStack_528;
  int iStack_524;
  int iStack_520;
  int iStack_51c;
  int iStack_518;
  int iStack_514;
  int iStack_510;
  int iStack_50c;
  int iStack_508;
  int iStack_504;
  int iStack_500;
  int iStack_4fc;
  int iStack_4f8;
  int iStack_4f4;
  int iStack_4f0;
  int iStack_4ec;
  int iStack_4e8;
  int iStack_4e4;
  int iStack_4e0;
  int iStack_4dc;
  int iStack_4d8;
  int iStack_4d4;
  undefined1 *puStack_4d0;
  undefined1 *puStack_4cc;
  uint uStack_4c8;
  uint uStack_4c4;
  uint uStack_4c0;
  uint uStack_4bc;
  uint uStack_4b8;
  uint uStack_4b4;
  uint uStack_4b0;
  uint uStack_4ac;
  uint uStack_4a8;
  uint uStack_4a4;
  uint uStack_4a0;
  uint uStack_49c;
  uint uStack_498;
  uint uStack_494;
  uint uStack_490;
  uint uStack_48c;
  uint uStack_488;
  uint uStack_484;
  uint uStack_480;
  uint uStack_47c;
  uint uStack_478;
  uint uStack_474;
  uint uStack_470;
  uint uStack_46c;
  uint uStack_468;
  uint uStack_464;
  uint uStack_460;
  uint uStack_45c;
  uint uStack_458;
  uint uStack_454;
  int iStack_450;
  undefined1 *puStack_44c;
  undefined1 *puStack_448;
  int iStack_444;
  undefined1 *puStack_440;
  undefined1 *puStack_43c;
  int iStack_438;
  undefined1 *puStack_434;
  int iStack_430;
  int iStack_42c;
  int iStack_428;
  int iStack_424;
  int iStack_420;
  int iStack_41c;
  int iStack_418;
  int iStack_414;
  int iStack_410;
  int iStack_40c;
  int iStack_408;
  int iStack_404;
  int iStack_400;
  int iStack_3fc;
  int iStack_3f8;
  int iStack_3f4;
  int iStack_3f0;
  int iStack_3ec;
  int iStack_3e8;
  int iStack_3e4;
  int iStack_3e0;
  int iStack_3dc;
  int iStack_3d8;
  int iStack_3d4;
  int iStack_3d0;
  int iStack_3cc;
  int iStack_3c8;
  int iStack_3c4;
  int iStack_3c0;
  int iStack_3bc;
  int iStack_3b8;
  int iStack_3b4;
  int iStack_3b0;
  int iStack_3ac;
  int iStack_3a8;
  int iStack_3a4;
  int iStack_3a0;
  int iStack_39c;
  int iStack_398;
  int iStack_394;
  int iStack_390;
  int iStack_38c;
  int iStack_388;
  int iStack_384;
  int iStack_380;
  int iStack_37c;
  int iStack_378;
  int iStack_374;
  int iStack_370;
  int iStack_36c;
  int iStack_368;
  int iStack_364;
  int iStack_360;
  int iStack_35c;
  int iStack_358;
  int iStack_354;
  int iStack_350;
  int iStack_34c;
  int iStack_348;
  int iStack_344;
  int iStack_340;
  int iStack_33c;
  int iStack_338;
  int iStack_334;
  undefined1 *puStack_330;
  undefined1 *puStack_32c;
  uint uStack_328;
  uint uStack_324;
  uint uStack_320;
  uint uStack_31c;
  uint uStack_318;
  uint uStack_314;
  uint uStack_310;
  uint uStack_30c;
  uint uStack_308;
  uint uStack_304;
  uint uStack_300;
  uint uStack_2fc;
  uint uStack_2f8;
  uint uStack_2f4;
  uint uStack_2f0;
  uint uStack_2ec;
  uint uStack_2e8;
  uint uStack_2e4;
  uint uStack_2e0;
  uint uStack_2dc;
  uint uStack_2d8;
  uint uStack_2d4;
  uint uStack_2d0;
  uint uStack_2cc;
  uint uStack_2c8;
  uint uStack_2c4;
  uint uStack_2c0;
  uint uStack_2bc;
  uint uStack_2b8;
  uint uStack_2b4;
  int iStack_2b0;
  undefined1 *puStack_2ac;
  undefined1 *puStack_2a8;
  int iStack_2a4;
  undefined1 *puStack_2a0;
  undefined1 *puStack_29c;
  int iStack_298;
  int iStack_294;
  int iStack_290;
  int iStack_28c;
  int iStack_288;
  int iStack_284;
  int iStack_280;
  int iStack_27c;
  int iStack_278;
  int iStack_274;
  int iStack_270;
  int iStack_26c;
  int iStack_268;
  int iStack_264;
  int iStack_260;
  int iStack_25c;
  int iStack_258;
  int iStack_254;
  int iStack_250;
  int iStack_24c;
  int iStack_248;
  int iStack_244;
  int iStack_240;
  int iStack_23c;
  int iStack_238;
  int iStack_234;
  int iStack_230;
  int iStack_22c;
  int iStack_228;
  int iStack_224;
  int iStack_220;
  int iStack_21c;
  int iStack_218;
  int iStack_214;
  int iStack_210;
  int iStack_20c;
  int iStack_208;
  int iStack_204;
  int iStack_200;
  int iStack_1fc;
  int iStack_1f8;
  int iStack_1f4;
  int iStack_1f0;
  int iStack_1ec;
  int iStack_1e8;
  int iStack_1e4;
  int iStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  int iStack_1b8;
  int iStack_1b4;
  int iStack_1b0;
  int iStack_1ac;
  int iStack_1a8;
  int iStack_1a4;
  int iStack_1a0;
  int iStack_19c;
  int iStack_198;
  int iStack_194;
  int iStack_190;
  int iStack_18c;
  int iStack_188;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  int iStack_128;
  undefined1 *puStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  undefined1 *puStack_b0;
  undefined1 *puStack_ac;
  uint uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int iStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar4 = (*(code *)PTR_ArTvConf_GetNonConnectedEnabled_010ccb14)(uVar3);
  if (iVar4 != 1) {
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar3);
    if (iVar4 == 1) {
      uVar3 = (*(code *)PTR_getInstance_010cd270)();
      iVar4 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar3);
      if (iVar4 == 1) {
        iStack_298 = 1;
        goto LAB_00d326c8;
      }
    }
    iStack_298 = 0;
LAB_00d326c8:
    if (iStack_298 == 0) {
      piVar5 = *(int **)(this + 0x184);
      puStack_440 = auStack_9cc;
      puStack_43c = puStack_440;
      for (iStack_444 = 1; iStack_444 != -1; iStack_444 = iStack_444 + -1) {
                    /* try { // try from 00d388e4 to 00d388eb has its CatchHandler @ 00d38938 */
        (*(code *)(PTR_LAB_010c4418 + 0x5f1c))(puStack_440);
        puStack_440 = puStack_440 + 0xa0;
      }
      puStack_44c = auStack_88c;
      puStack_448 = puStack_44c;
      for (iStack_450 = 1; iStack_450 != -1; iStack_450 = iStack_450 + -1) {
                    /* try { // try from 00d389ec to 00d389f3 has its CatchHandler @ 00d38a2c */
        (*(code *)(PTR_LAB_010c441c + -0x6dc0))(puStack_44c);
        puStack_44c = puStack_44c + 0xd4;
      }
      for (bStack_1a97 = 0; bStack_1a97 < 2; bStack_1a97 = bStack_1a97 + 1) {
        uStack_454 = (uint)bStack_1a97;
                    /* try { // try from 00d38af4 to 00d39447 has its CatchHandler @ 00d3e7f8 */
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_454 * 0x28] = uVar3;
        uStack_458 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_458 * 0x28 + 1] = uVar3;
        uStack_45c = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_45c * 0x28 + 2] = uVar3;
        uStack_460 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_460 * 0x28 + 3] = uVar3;
        uStack_464 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_464 * 0x28 + 4] = uVar3;
        uStack_468 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
        auStack_944[uStack_468 * 0x28 + 5] = uVar3;
        auStack_9c8[(uint)bStack_1a97 * 0x28 + 0x18] = 0x4ae;
        auStack_9c8[(uint)bStack_1a97 * 0x28 + 0x1a] = 0x4ae;
        auStack_9c8[(uint)bStack_1a97 * 0x28 + 0x19] = 0x4ae;
        auStack_9c8[(uint)bStack_1a97 * 0x28 + 0x1b] = 0x4ae;
        uStack_46c = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(auStack_9cc + (uStack_46c * 0x14 + 1) * 8 + 4) = uVar3;
        uStack_470 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(auStack_9cc + uStack_470 * 0xa0 + 4) = uVar3;
        uStack_474 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(auStack_9cc + (uStack_474 * 0x28 + 1) * 4 + 4) = uVar3;
        uStack_478 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        auStack_9c8[uStack_478 * 0x28 + 3] = uVar3;
        uStack_47c = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        auStack_9c8[uStack_47c * 0x28 + 6] = uVar3;
        uStack_480 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(auStack_9cc + (uStack_480 * 10 + 1) * 0x10 + 4) = uVar3;
        uStack_484 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        auStack_9c8[uStack_484 * 0x28 + 5] = uVar3;
        uStack_488 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        auStack_9c8[uStack_488 * 0x28 + 7] = uVar3;
        uStack_48c = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(3);
        auStack_9c8[uStack_48c * 0x28 + 10] = uVar3;
        uStack_490 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(7);
        *(undefined4 *)(auStack_9cc + (uStack_490 * 5 + 1) * 0x20 + 4) = uVar3;
        uStack_494 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
        auStack_9c8[uStack_494 * 0x28 + 9] = uVar3;
        uStack_498 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
        auStack_9c8[uStack_498 * 0x28 + 0xb] = uVar3;
        uStack_49c = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        auStack_9c8[uStack_49c * 0x28 + 0xe] = uVar3;
        uStack_4a0 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        auStack_9c8[uStack_4a0 * 0x28 + 0xc] = uVar3;
        uStack_4a4 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        auStack_9c8[uStack_4a4 * 0x28 + 0xd] = uVar3;
        uStack_4a8 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        auStack_9c8[uStack_4a8 * 0x28 + 0xf] = uVar3;
        uStack_4ac = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        auStack_9c8[uStack_4ac * 0x28 + 0x12] = uVar3;
        uStack_4b0 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        auStack_9c8[uStack_4b0 * 0x28 + 0x10] = uVar3;
        uStack_4b4 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        auStack_9c8[uStack_4b4 * 0x28 + 0x11] = uVar3;
        uStack_4b8 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        auStack_9c8[uStack_4b8 * 0x28 + 0x13] = uVar3;
        auStack_954[(uint)bStack_1a97 * 0xa0] = 0;
        auStack_9cc[(uint)bStack_1a97 * 0xa0] = 0;
        auStack_9cc[(uint)bStack_1a97 * 0xa0 + 1] = 1;
        auStack_948[(uint)bStack_1a97 * 0xa0] = 0;
        uStack_4bc = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
        auStack_9c8[uStack_4bc * 0x28 + 0x14] = uVar3;
        uStack_4c0 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
        auStack_9c8[uStack_4c0 * 0x28 + 0x16] = uVar3;
        uStack_4c4 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
        auStack_9c8[uStack_4c4 * 0x28 + 0x15] = uVar3;
        uStack_4c8 = (uint)bStack_1a97;
        uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
        auStack_9c8[uStack_4c8 * 0x28 + 0x17] = uVar3;
      }
      (*(code *)PTR_assign_010cc3b8)(auStack_8ac,PTR_DAT_010c43ec + -0x15dc);
      uStack_8b8 = 0x22;
      uStack_8d8 = 0x46;
      uStack_8d0 = 0x46;
      uStack_8d4 = 0x46;
      uStack_8cc = 0x46;
      uStack_8c8 = 0x4b2;
      uStack_8c0 = 0x4b2;
      uStack_8c4 = 0x4b2;
      uStack_8bc = 0x4b2;
      (*(code *)PTR_assign_010cc3b8)(auStack_94c,PTR_DAT_010c43ec + -0x15d8);
      auStack_968[4] = 0x22;
      uStack_ab0 = 0;
      uStack_aac = 0xf;
      uStack_aa8 = 0xc4;
      uStack_aa4 = 0x46;
      uStack_ac0 = 0;
      uStack_abc = 0x60;
      uStack_ab8 = 0xc4;
      uStack_ab4 = 0x2d;
      for (bStack_1a98 = 0; bStack_1a98 < 2; bStack_1a98 = bStack_1a98 + 1) {
        puStack_4cc = auStack_844 + (uint)bStack_1a98 * 0xd4;
        (*(code *)PTR_MImg_010c7d68)(auStack_14f8,0x5cd);
                    /* try { // try from 00d3945c to 00d39463 has its CatchHandler @ 00d394dc */
        (*(code *)PTR_operator__010cc99c)(puStack_4cc,auStack_14f8);
                    /* try { // try from 00d39474 to 00d394cf has its CatchHandler @ 00d3e7f8 */
        (*(code *)PTR__MImg_010c8444)(auStack_14f8);
        puStack_4d0 = auStack_81c + (uint)bStack_1a98 * 0xd4;
        (*(code *)PTR_MImg_010c7d68)(auStack_150c,0x5cd);
                    /* try { // try from 00d39528 to 00d3952f has its CatchHandler @ 00d395f8 */
        (*(code *)PTR_operator__010cc99c)(puStack_4d0,auStack_150c);
                    /* try { // try from 00d39540 to 00d39547 has its CatchHandler @ 00d3e7f8 */
        (*(code *)PTR__MImg_010c8444)(auStack_150c);
        auStack_88c[(uint)bStack_1a98 * 0xd4] = 0;
        auStack_88c[(uint)bStack_1a98 * 0xd4 + 1] = 1;
        auStack_88c[(uint)bStack_1a98 * 0xd4 + 2] = 1;
      }
                    /* try { // try from 00d39664 to 00d3966b has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR_MImg_010c7d68)(auStack_1520,0x40);
                    /* try { // try from 00d39688 to 00d3968f has its CatchHandler @ 00d396d0 */
      (*(code *)PTR_operator__010cc99c)(auStack_81c,auStack_1520);
                    /* try { // try from 00d396a0 to 00d396c3 has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1520);
      (*(code *)PTR_MImg_010c7d68)(auStack_1534,0x5cd);
                    /* try { // try from 00d39724 to 00d3972b has its CatchHandler @ 00d3976c */
      (*(code *)PTR_operator__010cc99c)(auStack_844,auStack_1534);
                    /* try { // try from 00d3973c to 00d3975f has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1534);
      (*(code *)PTR_MImg_010c7d68)(auStack_1548,0x5cd);
                    /* try { // try from 00d397c0 to 00d397c7 has its CatchHandler @ 00d39808 */
      (*(code *)PTR_operator__010cc99c)(auStack_858,auStack_1548);
                    /* try { // try from 00d397d8 to 00d397fb has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1548);
      (*(code *)PTR_MImg_010c7d68)(auStack_155c,0x5cd);
                    /* try { // try from 00d3985c to 00d39863 has its CatchHandler @ 00d398bc */
      (*(code *)PTR_operator__010cc99c)(auStack_830,auStack_155c);
                    /* try { // try from 00d39874 to 00d398af has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_155c);
      uStack_aa0 = 0;
      uStack_a9c = 0;
      uStack_a98 = 0x142;
      uStack_a94 = 0x110;
      (*(code *)PTR_MImg_010c7d68)(auStack_1570,0x5cd);
                    /* try { // try from 00d39910 to 00d39917 has its CatchHandler @ 00d39958 */
      (*(code *)PTR_operator__010cc99c)(auStack_748,auStack_1570);
                    /* try { // try from 00d39928 to 00d3994b has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1570);
      (*(code *)PTR_MImg_010c7d68)(auStack_1584,0x5cd);
                    /* try { // try from 00d399ac to 00d399b3 has its CatchHandler @ 00d399f4 */
      (*(code *)PTR_operator__010cc99c)(auStack_770,auStack_1584);
                    /* try { // try from 00d399c4 to 00d399e7 has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1584);
      (*(code *)PTR_MImg_010c7d68)(auStack_1598,0x5cd);
                    /* try { // try from 00d39a48 to 00d39a4f has its CatchHandler @ 00d39a90 */
      (*(code *)PTR_operator__010cc99c)(auStack_784,auStack_1598);
                    /* try { // try from 00d39a60 to 00d39a83 has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_1598);
      (*(code *)PTR_MImg_010c7d68)(auStack_15ac,0x5cd);
                    /* try { // try from 00d39ae4 to 00d39aeb has its CatchHandler @ 00d39b40 */
      (*(code *)PTR_operator__010cc99c)(auStack_75c,auStack_15ac);
                    /* try { // try from 00d39afc to 00d39b03 has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR__MImg_010c8444)(auStack_15ac);
      uStack_a90 = 0;
      uStack_a8c = 0;
      uStack_a88 = 0xc4;
      uStack_a84 = 0x92;
      if (this[0x2b1] == (HomePageFrame)0x1) {
        (*(code *)PTR_set_010c9810)(aiStack_ad0,0x40,0x41,0xc4,0x92);
        for (iStack_1a9c = 0; iStack_1a9c < 2; iStack_1a9c = iStack_1a9c + 1) {
                    /* try { // try from 00d39bbc to 00d39bc3 has its CatchHandler @ 00d3e7f8 */
          iStack_4d4 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d39bf8 to 00d39bff has its CatchHandler @ 00d39c20 */
          (*(code *)PTR_TextImageMixer_010c9cfc)
                    (iStack_4d4,piVar5,aiStack_ad0,0,iStack_1a9c + 0x3d,1);
          iVar4 = iStack_4d4;
          if (iStack_4d4 == 0) {
                    /* try { // try from 00d39c78 to 00d3a1eb has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                       PTR_DAT_010c43ec + -0x14d0,0x12a3);
                    /* WARNING: Subroutine does not return */
            (*(code *)PTR_abort_010cc6c0)();
          }
          (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_4d4,2);
          (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
          (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
          (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
          (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
          *(undefined1 *)(iVar4 + 0x39) = 1;
          *(undefined1 *)(iVar4 + 0x3a) = 1;
          (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9c) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9e) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa0) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa2) = uVar1;
          *(undefined1 *)(iVar4 + 0x38) = 1;
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x40);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x28);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x28);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x28);
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x58) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x54) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x4c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x50) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 100) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x5c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x60) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x68) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x74) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x6c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x70) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x78) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x84) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x7c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x80) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x88) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x94) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x8c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x90) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x98) = uVar3;
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
          (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
          aiStack_ad0[0] = aiStack_ad0[0] + 0xe0;
          if (iStack_1a9c == 0) {
            (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2b4);
          }
        }
      }
      else {
        (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x230));
        (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x230),this + 0x2b4);
      }
      if (this[0x2b2] == (HomePageFrame)0x1) {
        (*(code *)PTR_set_010c9810)(aiStack_ad0,0x3dc,0x41,0xc4,0x92);
        for (iStack_1aa0 = 0; iStack_1aa0 < 4; iStack_1aa0 = iStack_1aa0 + 1) {
          iStack_4d8 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d3a220 to 00d3a227 has its CatchHandler @ 00d3a248 */
          (*(code *)PTR_TextImageMixer_010c9cfc)
                    (iStack_4d8,piVar5,aiStack_ad0,0,iStack_1aa0 + 0x41,1);
          iVar4 = iStack_4d8;
          if (iStack_4d8 == 0) {
                    /* try { // try from 00d3a2a0 to 00d3a8c7 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                       PTR_DAT_010c43ec + -0x14d0,0x12e9);
                    /* WARNING: Subroutine does not return */
            (*(code *)PTR_abort_010cc6c0)();
          }
          (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_4d8,2);
          (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
          (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
          (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
          (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
          *(undefined1 *)(iVar4 + 0x39) = 1;
          *(undefined1 *)(iVar4 + 0x3a) = 1;
          (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9c) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9e) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa0) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa2) = uVar1;
          *(undefined1 *)(iVar4 + 0x38) = 1;
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x4f);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x4e);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x4e);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x4e);
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x58) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x54) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x4c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x50) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 100) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x5c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x60) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x68) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x74) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x6c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x70) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x78) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x84) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x7c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x80) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x88) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x94) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x8c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x90) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x98) = uVar3;
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
          (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
          aiStack_ad0[0] = aiStack_ad0[0] + 0xe0;
          if (iStack_1aa0 == 0) {
            (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2c4);
          }
        }
      }
      else {
        (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x234));
        (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x234),this + 0x2c4);
      }
      (*(code *)PTR_set_010c9810)(aiStack_ad0,0x40,0x13f,0xc4,0x92);
      for (iStack_1aa4 = 0; iStack_1aa4 < 6; iStack_1aa4 = iStack_1aa4 + 1) {
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
        if ((iVar4 == 0) && ((iStack_1aa4 == 3 || (iStack_1aa4 == 4)))) {
          iStack_4dc = 1;
        }
        else {
          iStack_4dc = 0;
        }
        if (iStack_4dc == 0) {
          uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
          if ((iVar4 == 0) && (iStack_1aa4 == 3)) {
            iStack_4e0 = 1;
          }
          else {
            iStack_4e0 = 0;
          }
          if (iStack_4e0 == 0) {
            iStack_4e4 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d3a8fc to 00d3a903 has its CatchHandler @ 00d3a924 */
            (*(code *)PTR_TextImageMixer_010c9cfc)
                      (iStack_4e4,piVar5,aiStack_ad0,0,iStack_1aa4 + 0x45,1);
            iVar4 = iStack_4e4;
            if (iStack_4e4 == 0) {
                    /* try { // try from 00d3a97c to 00d3af5b has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR_printf_010c9f10)
                        (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                         PTR_DAT_010c43ec + -0x14d0,0x1333);
                    /* WARNING: Subroutine does not return */
              (*(code *)PTR_abort_010cc6c0)();
            }
            (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_4e4,2);
            (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
            (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
            (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
            (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
            *(undefined1 *)(iVar4 + 0x39) = 1;
            *(undefined1 *)(iVar4 + 0x3a) = 1;
            (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
            uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
            *(undefined2 *)(iVar4 + 0x9c) = uVar1;
            uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
            *(undefined2 *)(iVar4 + 0x9e) = uVar1;
            uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
            *(undefined2 *)(iVar4 + 0xa0) = uVar1;
            uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
            *(undefined2 *)(iVar4 + 0xa2) = uVar1;
            *(undefined1 *)(iVar4 + 0x38) = 1;
            (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
            (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
            (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
            (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
            *(undefined4 *)(iVar4 + 0x58) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
            *(undefined4 *)(iVar4 + 0x54) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x4c) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x50) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 100) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x5c) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x60) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x68) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x74) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x6c) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x70) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
            *(undefined4 *)(iVar4 + 0x78) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
            *(undefined4 *)(iVar4 + 0x84) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
            *(undefined4 *)(iVar4 + 0x7c) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
            *(undefined4 *)(iVar4 + 0x80) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
            *(undefined4 *)(iVar4 + 0x88) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x94) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x8c) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x90) = uVar3;
            uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
            *(undefined4 *)(iVar4 + 0x98) = uVar3;
            (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
            (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
            aiStack_ad0[0] = aiStack_ad0[0] + 0xe0;
            if (iStack_1aa4 == 0) {
              (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2d4);
            }
          }
        }
      }
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
      if (iVar4 == 0) {
        (*(code *)PTR_set_010c9810)(aiStack_ad0,0x3dc,0x13f,0xc4,0x92);
      }
      else {
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
        if (iVar4 == 0) {
          (*(code *)PTR_set_010c9810)(aiStack_ad0,0x4bc,0x13f,0xc4,0x92);
        }
        else {
          (*(code *)PTR_set_010c9810)(aiStack_ad0,0x59c,0x13f,0xc4,0x92);
        }
      }
      iStack_1aa8 = 0;
      while( true ) {
        if (1 < iStack_1aa8) {
          if (this[0x2b2] == (HomePageFrame)0x1) {
            iStack_4f0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x41);
            if (iStack_4f0 == 0) {
              iStack_4ec = 0;
            }
            else {
              iStack_4ec = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_4f0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_4ec;
            iStack_4f4 = *(int *)(*(int *)(iStack_4ec + 0x254) + 4) + 0x29c;
            (*(code *)PTR_MImg_010c7d68)(auStack_15c0,0x94);
                    /* try { // try from 00d3b594 to 00d3b59b has its CatchHandler @ 00d3b5f4 */
            (*(code *)PTR_operator__010cc99c)(iStack_4f4,auStack_15c0);
                    /* try { // try from 00d3b5ac to 00d3b5e7 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_15c0);
            iStack_4f8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
            (*(code *)PTR_MImg_010c7d68)(auStack_15d4,0x94);
                    /* try { // try from 00d3b640 to 00d3b647 has its CatchHandler @ 00d3b6a0 */
            (*(code *)PTR_operator__010cc99c)(iStack_4f8,auStack_15d4);
                    /* try { // try from 00d3b658 to 00d3b693 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_15d4);
            iStack_4fc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
            (*(code *)PTR_MImg_010c7d68)(auStack_15e8,0x94);
                    /* try { // try from 00d3b6ec to 00d3b6f3 has its CatchHandler @ 00d3b74c */
            (*(code *)PTR_operator__010cc99c)(iStack_4fc,auStack_15e8);
                    /* try { // try from 00d3b704 to 00d3b73f has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_15e8);
            iStack_500 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
            (*(code *)PTR_MImg_010c7d68)(auStack_15fc,0x95);
                    /* try { // try from 00d3b798 to 00d3b79f has its CatchHandler @ 00d3b7ec */
            (*(code *)PTR_operator__010cc99c)(iStack_500,auStack_15fc);
                    /* try { // try from 00d3b7b0 to 00d3b7df has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_15fc);
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x1061);
                    /* try { // try from 00d3b838 to 00d3b8bb has its CatchHandler @ 00d3e7f8 */
            iStack_508 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x42);
            if (iStack_508 == 0) {
              iStack_504 = 0;
            }
            else {
              iStack_504 = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_508,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_504;
            iStack_50c = *(int *)(*(int *)(iStack_504 + 0x254) + 4) + 0x29c;
            (*(code *)PTR_MImg_010c7d68)(auStack_1610,0x71);
                    /* try { // try from 00d3b8d0 to 00d3b8d7 has its CatchHandler @ 00d3b930 */
            (*(code *)PTR_operator__010cc99c)(iStack_50c,auStack_1610);
                    /* try { // try from 00d3b8e8 to 00d3b923 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1610);
            iStack_510 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
            (*(code *)PTR_MImg_010c7d68)(auStack_1624,0x71);
                    /* try { // try from 00d3b97c to 00d3b983 has its CatchHandler @ 00d3b9dc */
            (*(code *)PTR_operator__010cc99c)(iStack_510,auStack_1624);
                    /* try { // try from 00d3b994 to 00d3b9cf has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1624);
            iStack_514 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
            (*(code *)PTR_MImg_010c7d68)(auStack_1638,0x71);
                    /* try { // try from 00d3ba28 to 00d3ba2f has its CatchHandler @ 00d3ba88 */
            (*(code *)PTR_operator__010cc99c)(iStack_514,auStack_1638);
                    /* try { // try from 00d3ba40 to 00d3ba7b has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1638);
            iStack_518 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
            (*(code *)PTR_MImg_010c7d68)(auStack_164c,0x72);
                    /* try { // try from 00d3bad4 to 00d3badb has its CatchHandler @ 00d3bb28 */
            (*(code *)PTR_operator__010cc99c)(iStack_518,auStack_164c);
                    /* try { // try from 00d3baec to 00d3bb1b has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_164c);
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x1079);
                    /* try { // try from 00d3bb74 to 00d3bbf7 has its CatchHandler @ 00d3e7f8 */
            iStack_520 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x43);
            if (iStack_520 == 0) {
              iStack_51c = 0;
            }
            else {
              iStack_51c = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_520,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_51c;
            iStack_524 = *(int *)(*(int *)(iStack_51c + 0x254) + 4) + 0x29c;
            (*(code *)PTR_MImg_010c7d68)(auStack_1660,0x9a);
                    /* try { // try from 00d3bc0c to 00d3bc13 has its CatchHandler @ 00d3bc6c */
            (*(code *)PTR_operator__010cc99c)(iStack_524,auStack_1660);
                    /* try { // try from 00d3bc24 to 00d3bc5f has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1660);
            iStack_528 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
            (*(code *)PTR_MImg_010c7d68)(auStack_1674,0x9a);
                    /* try { // try from 00d3bcb8 to 00d3bcbf has its CatchHandler @ 00d3bd18 */
            (*(code *)PTR_operator__010cc99c)(iStack_528,auStack_1674);
                    /* try { // try from 00d3bcd0 to 00d3bd0b has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1674);
            iStack_52c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
            (*(code *)PTR_MImg_010c7d68)(auStack_1688,0x9a);
                    /* try { // try from 00d3bd64 to 00d3bd6b has its CatchHandler @ 00d3bdc4 */
            (*(code *)PTR_operator__010cc99c)(iStack_52c,auStack_1688);
                    /* try { // try from 00d3bd7c to 00d3bdb7 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1688);
            iStack_530 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
            (*(code *)PTR_MImg_010c7d68)(auStack_169c,0x9b);
                    /* try { // try from 00d3be10 to 00d3be17 has its CatchHandler @ 00d3be64 */
            (*(code *)PTR_operator__010cc99c)(iStack_530,auStack_169c);
                    /* try { // try from 00d3be28 to 00d3be57 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_169c);
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x586);
                    /* try { // try from 00d3beb0 to 00d3bf6b has its CatchHandler @ 00d3e7f8 */
            iStack_538 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x44);
            if (iStack_538 == 0) {
              iStack_534 = 0;
            }
            else {
              iStack_534 = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_538,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_534;
            uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
            iVar8 = (*(code *)PTR_ArNetworkConf_GetNetFlixVisible_010c8d84)(uVar3);
            if (iVar8 == 1) {
              iStack_53c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x29c;
              (*(code *)PTR_MImg_010c7d68)(auStack_16b0,0x7a);
                    /* try { // try from 00d3bf80 to 00d3bf87 has its CatchHandler @ 00d3bfe0 */
              (*(code *)PTR_operator__010cc99c)(iStack_53c,auStack_16b0);
                    /* try { // try from 00d3bf98 to 00d3bfd3 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_16b0);
              iStack_540 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
              (*(code *)PTR_MImg_010c7d68)(auStack_16c4,0x7a);
                    /* try { // try from 00d3c02c to 00d3c033 has its CatchHandler @ 00d3c08c */
              (*(code *)PTR_operator__010cc99c)(iStack_540,auStack_16c4);
                    /* try { // try from 00d3c044 to 00d3c07f has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_16c4);
              iStack_544 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
              (*(code *)PTR_MImg_010c7d68)(auStack_16d8,0x7a);
                    /* try { // try from 00d3c0d8 to 00d3c0df has its CatchHandler @ 00d3c138 */
              (*(code *)PTR_operator__010cc99c)(iStack_544,auStack_16d8);
                    /* try { // try from 00d3c0f0 to 00d3c12b has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_16d8);
              iStack_548 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
              (*(code *)PTR_MImg_010c7d68)(auStack_16ec,0x7b);
                    /* try { // try from 00d3c184 to 00d3c18b has its CatchHandler @ 00d3c204 */
              (*(code *)PTR_operator__010cc99c)(iStack_548,auStack_16ec);
                    /* try { // try from 00d3c19c to 00d3c1a3 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_16ec);
              iStack_54c = **(int **)(iVar4 + 0x250) + 0x170;
              (*(code *)PTR_allocator_010c6920)(auStack_16f4);
                    /* try { // try from 00d3c1f0 to 00d3c1f7 has its CatchHandler @ 00d3c2d8 */
              (*(code *)PTR_string_010c4f9c)(auStack_16f0,PTR_DAT_010c43ec + -0x159c,auStack_16f4);
                    /* try { // try from 00d3c250 to 00d3c257 has its CatchHandler @ 00d3c298 */
              (*(code *)PTR_Set_010cb39c)(iStack_54c,auStack_16f0);
              puStack_550 = auStack_16f0;
                    /* try { // try from 00d3c26c to 00d3c273 has its CatchHandler @ 00d3c2d8 */
              (*(code *)PTR__string_010c5070)(puStack_550);
              (*(code *)PTR__allocator_010c4948)(auStack_16f4);
            }
            else {
              iStack_554 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x29c;
                    /* try { // try from 00d3c33c to 00d3c343 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR_MImg_010c7d68)(auStack_1708,0x7c);
                    /* try { // try from 00d3c358 to 00d3c35f has its CatchHandler @ 00d3c3b8 */
              (*(code *)PTR_operator__010cc99c)(iStack_554,auStack_1708);
                    /* try { // try from 00d3c370 to 00d3c3ab has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1708);
              iStack_558 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
              (*(code *)PTR_MImg_010c7d68)(auStack_171c,0x7c);
                    /* try { // try from 00d3c404 to 00d3c40b has its CatchHandler @ 00d3c464 */
              (*(code *)PTR_operator__010cc99c)(iStack_558,auStack_171c);
                    /* try { // try from 00d3c41c to 00d3c457 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_171c);
              iStack_55c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
              (*(code *)PTR_MImg_010c7d68)(auStack_1730,0x7c);
                    /* try { // try from 00d3c4b0 to 00d3c4b7 has its CatchHandler @ 00d3c510 */
              (*(code *)PTR_operator__010cc99c)(iStack_55c,auStack_1730);
                    /* try { // try from 00d3c4c8 to 00d3c503 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1730);
              iStack_560 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
              (*(code *)PTR_MImg_010c7d68)(auStack_1744,0x7d);
                    /* try { // try from 00d3c55c to 00d3c563 has its CatchHandler @ 00d3c5b0 */
              (*(code *)PTR_operator__010cc99c)(iStack_560,auStack_1744);
                    /* try { // try from 00d3c574 to 00d3c5a3 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1744);
              (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x116a);
            }
          }
                    /* try { // try from 00d3c5fc to 00d3c67f has its CatchHandler @ 00d3e7f8 */
          iStack_568 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x45);
          if (iStack_568 == 0) {
            iStack_564 = 0;
          }
          else {
            iStack_564 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_568,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_564;
          iStack_56c = *(int *)(*(int *)(iStack_564 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1758,0x90);
                    /* try { // try from 00d3c694 to 00d3c69b has its CatchHandler @ 00d3c6f4 */
          (*(code *)PTR_operator__010cc99c)(iStack_56c,auStack_1758);
                    /* try { // try from 00d3c6ac to 00d3c6e7 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1758);
          iStack_570 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_176c,0x90);
                    /* try { // try from 00d3c740 to 00d3c747 has its CatchHandler @ 00d3c7a0 */
          (*(code *)PTR_operator__010cc99c)(iStack_570,auStack_176c);
                    /* try { // try from 00d3c758 to 00d3c793 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_176c);
          iStack_574 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_1780,0x90);
                    /* try { // try from 00d3c7ec to 00d3c7f3 has its CatchHandler @ 00d3c84c */
          (*(code *)PTR_operator__010cc99c)(iStack_574,auStack_1780);
                    /* try { // try from 00d3c804 to 00d3c83f has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1780);
          iStack_578 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1794,0x91);
                    /* try { // try from 00d3c898 to 00d3c89f has its CatchHandler @ 00d3c8ec */
          (*(code *)PTR_operator__010cc99c)(iStack_578,auStack_1794);
                    /* try { // try from 00d3c8b0 to 00d3c8df has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1794);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11df);
                    /* try { // try from 00d3c938 to 00d3c9bb has its CatchHandler @ 00d3e7f8 */
          iStack_580 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x46);
          if (iStack_580 == 0) {
            iStack_57c = 0;
          }
          else {
            iStack_57c = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_580,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_57c;
          iStack_584 = *(int *)(*(int *)(iStack_57c + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_17a8,0x8e);
                    /* try { // try from 00d3c9d0 to 00d3c9d7 has its CatchHandler @ 00d3ca30 */
          (*(code *)PTR_operator__010cc99c)(iStack_584,auStack_17a8);
                    /* try { // try from 00d3c9e8 to 00d3ca23 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_17a8);
          iStack_588 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_17bc,0x8e);
                    /* try { // try from 00d3ca7c to 00d3ca83 has its CatchHandler @ 00d3cadc */
          (*(code *)PTR_operator__010cc99c)(iStack_588,auStack_17bc);
                    /* try { // try from 00d3ca94 to 00d3cacf has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_17bc);
          iStack_58c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_17d0,0x8e);
                    /* try { // try from 00d3cb28 to 00d3cb2f has its CatchHandler @ 00d3cb88 */
          (*(code *)PTR_operator__010cc99c)(iStack_58c,auStack_17d0);
                    /* try { // try from 00d3cb40 to 00d3cb7b has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_17d0);
          iStack_590 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_17e4,0x8f);
                    /* try { // try from 00d3cbd4 to 00d3cbdb has its CatchHandler @ 00d3cc28 */
          (*(code *)PTR_operator__010cc99c)(iStack_590,auStack_17e4);
                    /* try { // try from 00d3cbec to 00d3cc1b has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_17e4);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd0e);
                    /* try { // try from 00d3cc74 to 00d3ccf7 has its CatchHandler @ 00d3e7f8 */
          iStack_598 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x47);
          if (iStack_598 == 0) {
            iStack_594 = 0;
          }
          else {
            iStack_594 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_598,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_594;
          iStack_59c = *(int *)(*(int *)(iStack_594 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_17f8,0x8a);
                    /* try { // try from 00d3cd0c to 00d3cd13 has its CatchHandler @ 00d3cd6c */
          (*(code *)PTR_operator__010cc99c)(iStack_59c,auStack_17f8);
                    /* try { // try from 00d3cd24 to 00d3cd5f has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_17f8);
          iStack_5a0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_180c,0x8a);
                    /* try { // try from 00d3cdb8 to 00d3cdbf has its CatchHandler @ 00d3ce18 */
          (*(code *)PTR_operator__010cc99c)(iStack_5a0,auStack_180c);
                    /* try { // try from 00d3cdd0 to 00d3ce0b has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_180c);
          iStack_5a4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_1820,0x8a);
                    /* try { // try from 00d3ce64 to 00d3ce6b has its CatchHandler @ 00d3cec4 */
          (*(code *)PTR_operator__010cc99c)(iStack_5a4,auStack_1820);
                    /* try { // try from 00d3ce7c to 00d3ceb7 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1820);
          iStack_5a8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1834,0x8b);
                    /* try { // try from 00d3cf10 to 00d3cf17 has its CatchHandler @ 00d3cf64 */
          (*(code *)PTR_operator__010cc99c)(iStack_5a8,auStack_1834);
                    /* try { // try from 00d3cf28 to 00d3cf57 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1834);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf16);
                    /* try { // try from 00d3cfa4 to 00d3d09b has its CatchHandler @ 00d3e7f8 */
          uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
          iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
          if (iVar4 != 0) {
            uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
            iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
            if (iVar4 != 0) {
              iStack_5b0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x48);
              if (iStack_5b0 == 0) {
                iStack_5ac = 0;
              }
              else {
                iStack_5ac = (*(code *)PTR___dynamic_cast_010c6984)
                                       (iStack_5b0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
              }
              iVar4 = iStack_5ac;
              iStack_5b4 = *(int *)(*(int *)(iStack_5ac + 0x254) + 4) + 0x29c;
              (*(code *)PTR_MImg_010c7d68)(auStack_1848,0x84);
                    /* try { // try from 00d3d0b0 to 00d3d0b7 has its CatchHandler @ 00d3d110 */
              (*(code *)PTR_operator__010cc99c)(iStack_5b4,auStack_1848);
                    /* try { // try from 00d3d0c8 to 00d3d103 has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1848);
              iStack_5b8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
              (*(code *)PTR_MImg_010c7d68)(auStack_185c,0x84);
                    /* try { // try from 00d3d15c to 00d3d163 has its CatchHandler @ 00d3d1bc */
              (*(code *)PTR_operator__010cc99c)(iStack_5b8,auStack_185c);
                    /* try { // try from 00d3d174 to 00d3d1af has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_185c);
              iStack_5bc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
              (*(code *)PTR_MImg_010c7d68)(auStack_1870,0x84);
                    /* try { // try from 00d3d208 to 00d3d20f has its CatchHandler @ 00d3d268 */
              (*(code *)PTR_operator__010cc99c)(iStack_5bc,auStack_1870);
                    /* try { // try from 00d3d220 to 00d3d25b has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1870);
              iStack_5c0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
              (*(code *)PTR_MImg_010c7d68)(auStack_1884,0x85);
                    /* try { // try from 00d3d2b4 to 00d3d2bb has its CatchHandler @ 00d3d308 */
              (*(code *)PTR_operator__010cc99c)(iStack_5c0,auStack_1884);
                    /* try { // try from 00d3d2cc to 00d3d2fb has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR__MImg_010c8444)(auStack_1884);
              (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x1196);
            }
                    /* try { // try from 00d3d354 to 00d3d3d7 has its CatchHandler @ 00d3e7f8 */
            iStack_5c8 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x49);
            if (iStack_5c8 == 0) {
              iStack_5c4 = 0;
            }
            else {
              iStack_5c4 = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_5c8,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_5c4;
            iStack_5cc = *(int *)(*(int *)(iStack_5c4 + 0x254) + 4) + 0x29c;
            (*(code *)PTR_MImg_010c7d68)(auStack_1898,0x78);
                    /* try { // try from 00d3d3ec to 00d3d3f3 has its CatchHandler @ 00d3d44c */
            (*(code *)PTR_operator__010cc99c)(iStack_5cc,auStack_1898);
                    /* try { // try from 00d3d404 to 00d3d43f has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1898);
            iStack_5d0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
            (*(code *)PTR_MImg_010c7d68)(auStack_18ac,0x78);
                    /* try { // try from 00d3d498 to 00d3d49f has its CatchHandler @ 00d3d4f8 */
            (*(code *)PTR_operator__010cc99c)(iStack_5d0,auStack_18ac);
                    /* try { // try from 00d3d4b0 to 00d3d4eb has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_18ac);
            iStack_5d4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
            (*(code *)PTR_MImg_010c7d68)(auStack_18c0,0x78);
                    /* try { // try from 00d3d544 to 00d3d54b has its CatchHandler @ 00d3d5a4 */
            (*(code *)PTR_operator__010cc99c)(iStack_5d4,auStack_18c0);
                    /* try { // try from 00d3d55c to 00d3d597 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_18c0);
            iStack_5d8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
            (*(code *)PTR_MImg_010c7d68)(auStack_18d4,0x79);
                    /* try { // try from 00d3d5f0 to 00d3d5f7 has its CatchHandler @ 00d3d644 */
            (*(code *)PTR_operator__010cc99c)(iStack_5d8,auStack_18d4);
                    /* try { // try from 00d3d608 to 00d3d637 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_18d4);
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x114e);
          }
                    /* try { // try from 00d3d690 to 00d3d713 has its CatchHandler @ 00d3e7f8 */
          iStack_5e0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4a);
          if (iStack_5e0 == 0) {
            iStack_5dc = 0;
          }
          else {
            iStack_5dc = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_5e0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_5dc;
          iStack_5e4 = *(int *)(*(int *)(iStack_5dc + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_18e8,0x86);
                    /* try { // try from 00d3d728 to 00d3d72f has its CatchHandler @ 00d3d788 */
          (*(code *)PTR_operator__010cc99c)(iStack_5e4,auStack_18e8);
                    /* try { // try from 00d3d740 to 00d3d77b has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_18e8);
          iStack_5e8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_18fc,0x86);
                    /* try { // try from 00d3d7d4 to 00d3d7db has its CatchHandler @ 00d3d834 */
          (*(code *)PTR_operator__010cc99c)(iStack_5e8,auStack_18fc);
                    /* try { // try from 00d3d7ec to 00d3d827 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_18fc);
          iStack_5ec = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_1910,0x86);
                    /* try { // try from 00d3d880 to 00d3d887 has its CatchHandler @ 00d3d8e0 */
          (*(code *)PTR_operator__010cc99c)(iStack_5ec,auStack_1910);
                    /* try { // try from 00d3d898 to 00d3d8d3 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1910);
          iStack_5f0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1924,0x87);
                    /* try { // try from 00d3d92c to 00d3d933 has its CatchHandler @ 00d3d980 */
          (*(code *)PTR_operator__010cc99c)(iStack_5f0,auStack_1924);
                    /* try { // try from 00d3d944 to 00d3d973 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1924);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11a6);
                    /* try { // try from 00d3d9cc to 00d3da4f has its CatchHandler @ 00d3e7f8 */
          iStack_5f8 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4b);
          if (iStack_5f8 == 0) {
            iStack_5f4 = 0;
          }
          else {
            iStack_5f4 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_5f8,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_5f4;
          iStack_5fc = *(int *)(*(int *)(iStack_5f4 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1938,0x8c);
                    /* try { // try from 00d3da64 to 00d3da6b has its CatchHandler @ 00d3dac4 */
          (*(code *)PTR_operator__010cc99c)(iStack_5fc,auStack_1938);
                    /* try { // try from 00d3da7c to 00d3dab7 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1938);
          iStack_600 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_194c,0x8c);
                    /* try { // try from 00d3db10 to 00d3db17 has its CatchHandler @ 00d3db70 */
          (*(code *)PTR_operator__010cc99c)(iStack_600,auStack_194c);
                    /* try { // try from 00d3db28 to 00d3db63 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_194c);
          iStack_604 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_1960,0x8c);
                    /* try { // try from 00d3dbbc to 00d3dbc3 has its CatchHandler @ 00d3dc1c */
          (*(code *)PTR_operator__010cc99c)(iStack_604,auStack_1960);
                    /* try { // try from 00d3dbd4 to 00d3dc0f has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1960);
          iStack_608 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1974,0x8d);
                    /* try { // try from 00d3dc68 to 00d3dc6f has its CatchHandler @ 00d3dcbc */
          (*(code *)PTR_operator__010cc99c)(iStack_608,auStack_1974);
                    /* try { // try from 00d3dc80 to 00d3dcaf has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1974);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11da);
                    /* try { // try from 00d3dd08 to 00d3dd8b has its CatchHandler @ 00d3e7f8 */
          iStack_610 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4c);
          if (iStack_610 == 0) {
            iStack_60c = 0;
          }
          else {
            iStack_60c = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_610,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_60c;
          iStack_614 = *(int *)(*(int *)(iStack_60c + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1988,0x88);
                    /* try { // try from 00d3dda0 to 00d3dda7 has its CatchHandler @ 00d3de00 */
          (*(code *)PTR_operator__010cc99c)(iStack_614,auStack_1988);
                    /* try { // try from 00d3ddb8 to 00d3ddf3 has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_1988);
          iStack_618 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_199c,0x88);
                    /* try { // try from 00d3de4c to 00d3de53 has its CatchHandler @ 00d3deac */
          (*(code *)PTR_operator__010cc99c)(iStack_618,auStack_199c);
                    /* try { // try from 00d3de64 to 00d3de9f has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_199c);
          iStack_61c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_19b0,0x88);
                    /* try { // try from 00d3def8 to 00d3deff has its CatchHandler @ 00d3df58 */
          (*(code *)PTR_operator__010cc99c)(iStack_61c,auStack_19b0);
                    /* try { // try from 00d3df10 to 00d3df4b has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_19b0);
          iStack_620 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_19c4,0x89);
                    /* try { // try from 00d3dfa4 to 00d3dfab has its CatchHandler @ 00d3dff8 */
          (*(code *)PTR_operator__010cc99c)(iStack_620,auStack_19c4);
                    /* try { // try from 00d3dfbc to 00d3dfeb has its CatchHandler @ 00d3e7f8 */
          (*(code *)PTR__MImg_010c8444)(auStack_19c4);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf49);
          if (this[0x2b1] == (HomePageFrame)0x1) {
                    /* try { // try from 00d3e058 to 00d3e123 has its CatchHandler @ 00d3e7f8 */
            iStack_628 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x40);
            if (iStack_628 == 0) {
              iStack_624 = 0;
            }
            else {
              iStack_624 = (*(code *)PTR___dynamic_cast_010c6984)
                                     (iStack_628,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
            }
            iVar4 = iStack_624;
            (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iStack_624 + 0x250) + 4));
            (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
            iStack_62c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x29c;
            (*(code *)PTR_MImg_010c7d68)(auStack_19d8,0x75);
                    /* try { // try from 00d3e138 to 00d3e13f has its CatchHandler @ 00d3e198 */
            (*(code *)PTR_operator__010cc99c)(iStack_62c,auStack_19d8);
                    /* try { // try from 00d3e150 to 00d3e18b has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_19d8);
            iStack_630 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
            (*(code *)PTR_MImg_010c7d68)(auStack_19ec,0x75);
                    /* try { // try from 00d3e1e4 to 00d3e1eb has its CatchHandler @ 00d3e244 */
            (*(code *)PTR_operator__010cc99c)(iStack_630,auStack_19ec);
                    /* try { // try from 00d3e1fc to 00d3e237 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_19ec);
            iStack_634 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
            (*(code *)PTR_MImg_010c7d68)(auStack_1a00,0x75);
                    /* try { // try from 00d3e290 to 00d3e297 has its CatchHandler @ 00d3e2f0 */
            (*(code *)PTR_operator__010cc99c)(iStack_634,auStack_1a00);
                    /* try { // try from 00d3e2a8 to 00d3e2e3 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1a00);
            iStack_638 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
            (*(code *)PTR_MImg_010c7d68)(auStack_1a14,0x76);
                    /* try { // try from 00d3e33c to 00d3e343 has its CatchHandler @ 00d3e390 */
            (*(code *)PTR_operator__010cc99c)(iStack_638,auStack_1a14);
                    /* try { // try from 00d3e354 to 00d3e383 has its CatchHandler @ 00d3e7f8 */
            (*(code *)PTR__MImg_010c8444)(auStack_1a14);
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd57);
            for (iStack_1ab0 = 0; iStack_1ab0 < 3; iStack_1ab0 = iStack_1ab0 + 1) {
                    /* try { // try from 00d3e3f4 to 00d3e473 has its CatchHandler @ 00d3e7f8 */
              iVar4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,iStack_1ab0 + 0x3d);
              iVar8 = (*(code *)PTR_size_010cbda0)(this + 0x2a0);
              if (iStack_1ab0 < iVar8) {
                (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1ab0);
                (*(code *)PTR_ostringstream_010c9ac8)(auStack_a80,0x10);
                puVar6 = (undefined2 *)(*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1ab0);
                    /* try { // try from 00d3e4b4 to 00d3e543 has its CatchHandler @ 00d3e5e0 */
                (*(code *)PTR_operator<<_010cb3b0)(auStack_a80,*puVar6);
                iVar8 = **(int **)(iVar4 + 0x250);
                iVar7 = (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1ab0);
                (*(code *)PTR_Set_010cb39c)(iVar8 + 0x170,iVar7 + 8);
                iStack_63c = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
                (*(code *)PTR_str_010c961c)(auStack_1a18,auStack_a80);
                    /* try { // try from 00d3e558 to 00d3e55f has its CatchHandler @ 00d3e59c */
                (*(code *)PTR_Set_010cb39c)(iStack_63c,auStack_1a18);
                    /* try { // try from 00d3e570 to 00d3e577 has its CatchHandler @ 00d3e5e0 */
                (*(code *)PTR__string_010c5070)(auStack_1a18);
                    /* try { // try from 00d3e588 to 00d3e58f has its CatchHandler @ 00d3e7f8 */
                (*(code *)PTR__ostringstream_010cc6a8)(auStack_a80);
              }
              else {
                    /* try { // try from 00d3e638 to 00d3e63f has its CatchHandler @ 00d3e7f8 */
                (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xe32);
                iStack_640 = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
                (*(code *)PTR_allocator_010c6920)(auStack_1a20);
                    /* try { // try from 00d3e690 to 00d3e697 has its CatchHandler @ 00d3e734 */
                (*(code *)PTR_string_010c4f9c)(auStack_1a1c,PTR_DAT_010c43ec + -0x15a0,auStack_1a20)
                ;
                    /* try { // try from 00d3e6ac to 00d3e6b3 has its CatchHandler @ 00d3e6f4 */
                (*(code *)PTR_Set_010cb39c)(iStack_640,auStack_1a1c);
                puStack_644 = auStack_1a1c;
                    /* try { // try from 00d3e6c8 to 00d3e6cf has its CatchHandler @ 00d3e734 */
                (*(code *)PTR__string_010c5070)(puStack_644);
                (*(code *)PTR__allocator_010c4948)(auStack_1a20);
              }
                    /* try { // try from 00d3e77c to 00d3e7db has its CatchHandler @ 00d3e7f8 */
              (*(code *)PTR_Invalidate_010c4e28)(iVar4);
            }
          }
          (**(code **)(*piVar5 + 0x48))(piVar5);
          (*(code *)PTR_Invalidate_010c4e28)(piVar5);
          puStack_670 = auStack_6e4;
          while (puStack_670 != auStack_88c) {
            puStack_670 = puStack_670 + -0xd4;
                    /* try { // try from 00d3e89c to 00d3e8a3 has its CatchHandler @ 00d3e8c4 */
            (*(code *)(PTR_LAB_010c441c + -0x71f8))(puStack_670);
          }
          puStack_674 = auStack_88c;
          while (puStack_674 != auStack_9cc) {
            puStack_674 = puStack_674 + -0xa0;
            (*(code *)(PTR_LAB_010c4418 + 0x5e04))(puStack_674);
          }
          return;
        }
        iStack_4e8 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d3af90 to 00d3af97 has its CatchHandler @ 00d3afb8 */
        (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_4e8,piVar5,aiStack_ad0,0,iStack_1aa8 + 0x4b,1)
        ;
        iVar4 = iStack_4e8;
        if (iStack_4e8 == 0) break;
        (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_4e8,2);
        (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
        (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
        (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
        (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
        *(undefined1 *)(iVar4 + 0x39) = 1;
        *(undefined1 *)(iVar4 + 0x3a) = 1;
        (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9c) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9e) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa0) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa2) = uVar1;
        *(undefined1 *)(iVar4 + 0x38) = 1;
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x1ce);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x1cd);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x1cd);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x1cd);
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x58) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x54) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x4c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x50) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 100) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x5c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x60) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x68) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x74) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x6c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x70) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x78) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x84) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x7c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x80) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x88) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x94) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x8c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x90) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x98) = uVar3;
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
        (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
        aiStack_ad0[0] = aiStack_ad0[0] + 0xe0;
        if (iStack_1aa8 == 1) {
          (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2e4);
        }
        iStack_1aa8 = iStack_1aa8 + 1;
      }
                    /* try { // try from 00d3b010 to 00d3b57f has its CatchHandler @ 00d3e7f8 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0x1379);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    piVar5 = *(int **)(this + 0x184);
    puStack_2a0 = auStack_9cc;
    puStack_29c = puStack_2a0;
    for (iStack_2a4 = 1; iStack_2a4 != -1; iStack_2a4 = iStack_2a4 + -1) {
                    /* try { // try from 00d3270c to 00d32713 has its CatchHandler @ 00d32760 */
      (*(code *)(PTR_LAB_010c4418 + 0x5f1c))(puStack_2a0);
      puStack_2a0 = puStack_2a0 + 0xa0;
    }
    puStack_2ac = auStack_88c;
    puStack_2a8 = puStack_2ac;
    for (iStack_2b0 = 1; iStack_2b0 != -1; iStack_2b0 = iStack_2b0 + -1) {
                    /* try { // try from 00d32814 to 00d3281b has its CatchHandler @ 00d32854 */
      (*(code *)(PTR_LAB_010c441c + -0x6dc0))(puStack_2ac);
      puStack_2ac = puStack_2ac + 0xd4;
    }
    for (bStack_1a6f = 0; bStack_1a6f < 2; bStack_1a6f = bStack_1a6f + 1) {
      uStack_2b4 = (uint)bStack_1a6f;
                    /* try { // try from 00d3291c to 00d3326f has its CatchHandler @ 00d38720 */
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2b4 * 0x28] = uVar3;
      uStack_2b8 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2b8 * 0x28 + 1] = uVar3;
      uStack_2bc = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2bc * 0x28 + 2] = uVar3;
      uStack_2c0 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2c0 * 0x28 + 3] = uVar3;
      uStack_2c4 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2c4 * 0x28 + 4] = uVar3;
      uStack_2c8 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
      auStack_944[uStack_2c8 * 0x28 + 5] = uVar3;
      auStack_9c8[(uint)bStack_1a6f * 0x28 + 0x18] = 0x4ae;
      auStack_9c8[(uint)bStack_1a6f * 0x28 + 0x1a] = 0x4ae;
      auStack_9c8[(uint)bStack_1a6f * 0x28 + 0x19] = 0x4ae;
      auStack_9c8[(uint)bStack_1a6f * 0x28 + 0x1b] = 0x4ae;
      uStack_2cc = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(auStack_9cc + (uStack_2cc * 0x14 + 1) * 8 + 4) = uVar3;
      uStack_2d0 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(auStack_9cc + uStack_2d0 * 0xa0 + 4) = uVar3;
      uStack_2d4 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(auStack_9cc + (uStack_2d4 * 0x28 + 1) * 4 + 4) = uVar3;
      uStack_2d8 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      auStack_9c8[uStack_2d8 * 0x28 + 3] = uVar3;
      uStack_2dc = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      auStack_9c8[uStack_2dc * 0x28 + 6] = uVar3;
      uStack_2e0 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(auStack_9cc + (uStack_2e0 * 10 + 1) * 0x10 + 4) = uVar3;
      uStack_2e4 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      auStack_9c8[uStack_2e4 * 0x28 + 5] = uVar3;
      uStack_2e8 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      auStack_9c8[uStack_2e8 * 0x28 + 7] = uVar3;
      uStack_2ec = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(3);
      auStack_9c8[uStack_2ec * 0x28 + 10] = uVar3;
      uStack_2f0 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(7);
      *(undefined4 *)(auStack_9cc + (uStack_2f0 * 5 + 1) * 0x20 + 4) = uVar3;
      uStack_2f4 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
      auStack_9c8[uStack_2f4 * 0x28 + 9] = uVar3;
      uStack_2f8 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
      auStack_9c8[uStack_2f8 * 0x28 + 0xb] = uVar3;
      uStack_2fc = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      auStack_9c8[uStack_2fc * 0x28 + 0xe] = uVar3;
      uStack_300 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      auStack_9c8[uStack_300 * 0x28 + 0xc] = uVar3;
      uStack_304 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      auStack_9c8[uStack_304 * 0x28 + 0xd] = uVar3;
      uStack_308 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      auStack_9c8[uStack_308 * 0x28 + 0xf] = uVar3;
      uStack_30c = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      auStack_9c8[uStack_30c * 0x28 + 0x12] = uVar3;
      uStack_310 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      auStack_9c8[uStack_310 * 0x28 + 0x10] = uVar3;
      uStack_314 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      auStack_9c8[uStack_314 * 0x28 + 0x11] = uVar3;
      uStack_318 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      auStack_9c8[uStack_318 * 0x28 + 0x13] = uVar3;
      auStack_954[(uint)bStack_1a6f * 0xa0] = 0;
      auStack_9cc[(uint)bStack_1a6f * 0xa0] = 0;
      auStack_9cc[(uint)bStack_1a6f * 0xa0 + 1] = 1;
      auStack_948[(uint)bStack_1a6f * 0xa0] = 0;
      uStack_31c = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
      auStack_9c8[uStack_31c * 0x28 + 0x14] = uVar3;
      uStack_320 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
      auStack_9c8[uStack_320 * 0x28 + 0x16] = uVar3;
      uStack_324 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
      auStack_9c8[uStack_324 * 0x28 + 0x15] = uVar3;
      uStack_328 = (uint)bStack_1a6f;
      uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
      auStack_9c8[uStack_328 * 0x28 + 0x17] = uVar3;
    }
    (*(code *)PTR_assign_010cc3b8)(auStack_8ac,PTR_DAT_010c43ec + -0x15dc);
    uStack_8b8 = 0x22;
    uStack_8d8 = 0x46;
    uStack_8d0 = 0x46;
    uStack_8d4 = 0x46;
    uStack_8cc = 0x46;
    uStack_8c8 = 0x4b2;
    uStack_8c0 = 0x4b2;
    uStack_8c4 = 0x4b2;
    uStack_8bc = 0x4b2;
    (*(code *)PTR_assign_010cc3b8)(auStack_94c,PTR_DAT_010c43ec + -0x15d8);
    auStack_968[4] = 0x22;
    uStack_a90 = 0;
    uStack_a8c = 0xf;
    uStack_a88 = 0xc4;
    uStack_a84 = 0x46;
    uStack_aa0 = 0;
    uStack_a9c = 0x60;
    uStack_a98 = 0xc4;
    uStack_a94 = 0x2d;
    for (bStack_1a70 = 0; bStack_1a70 < 2; bStack_1a70 = bStack_1a70 + 1) {
      puStack_32c = auStack_844 + (uint)bStack_1a70 * 0xd4;
      (*(code *)PTR_MImg_010c7d68)(auStack_114c,0x5cd);
                    /* try { // try from 00d33284 to 00d3328b has its CatchHandler @ 00d33304 */
      (*(code *)PTR_operator__010cc99c)(puStack_32c,auStack_114c);
                    /* try { // try from 00d3329c to 00d332f7 has its CatchHandler @ 00d38720 */
      (*(code *)PTR__MImg_010c8444)(auStack_114c);
      puStack_330 = auStack_81c + (uint)bStack_1a70 * 0xd4;
      (*(code *)PTR_MImg_010c7d68)(auStack_1160,0x5cd);
                    /* try { // try from 00d33350 to 00d33357 has its CatchHandler @ 00d33420 */
      (*(code *)PTR_operator__010cc99c)(puStack_330,auStack_1160);
                    /* try { // try from 00d33368 to 00d3336f has its CatchHandler @ 00d38720 */
      (*(code *)PTR__MImg_010c8444)(auStack_1160);
      auStack_88c[(uint)bStack_1a70 * 0xd4] = 0;
      auStack_88c[(uint)bStack_1a70 * 0xd4 + 1] = 1;
      auStack_88c[(uint)bStack_1a70 * 0xd4 + 2] = 1;
    }
                    /* try { // try from 00d3348c to 00d33493 has its CatchHandler @ 00d38720 */
    (*(code *)PTR_MImg_010c7d68)(auStack_1174,0x40);
                    /* try { // try from 00d334b0 to 00d334b7 has its CatchHandler @ 00d334f8 */
    (*(code *)PTR_operator__010cc99c)(auStack_81c,auStack_1174);
                    /* try { // try from 00d334c8 to 00d334eb has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_1174);
    (*(code *)PTR_MImg_010c7d68)(auStack_1188,0x5cd);
                    /* try { // try from 00d3354c to 00d33553 has its CatchHandler @ 00d33594 */
    (*(code *)PTR_operator__010cc99c)(auStack_844,auStack_1188);
                    /* try { // try from 00d33564 to 00d33587 has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_1188);
    (*(code *)PTR_MImg_010c7d68)(auStack_119c,0x5cd);
                    /* try { // try from 00d335e8 to 00d335ef has its CatchHandler @ 00d33630 */
    (*(code *)PTR_operator__010cc99c)(auStack_858,auStack_119c);
                    /* try { // try from 00d33600 to 00d33623 has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_119c);
    (*(code *)PTR_MImg_010c7d68)(auStack_11b0,0x5cd);
                    /* try { // try from 00d33684 to 00d3368b has its CatchHandler @ 00d336e4 */
    (*(code *)PTR_operator__010cc99c)(auStack_830,auStack_11b0);
                    /* try { // try from 00d3369c to 00d336d7 has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_11b0);
    uStack_ac0 = 0;
    uStack_abc = 0;
    uStack_ab8 = 0x142;
    uStack_ab4 = 0x110;
    (*(code *)PTR_MImg_010c7d68)(auStack_11c4,0x5cd);
                    /* try { // try from 00d33738 to 00d3373f has its CatchHandler @ 00d33780 */
    (*(code *)PTR_operator__010cc99c)(auStack_748,auStack_11c4);
                    /* try { // try from 00d33750 to 00d33773 has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_11c4);
    (*(code *)PTR_MImg_010c7d68)(auStack_11d8,0x5cd);
                    /* try { // try from 00d337d4 to 00d337db has its CatchHandler @ 00d3381c */
    (*(code *)PTR_operator__010cc99c)(auStack_770,auStack_11d8);
                    /* try { // try from 00d337ec to 00d3380f has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_11d8);
    (*(code *)PTR_MImg_010c7d68)(auStack_11ec,0x5cd);
                    /* try { // try from 00d33870 to 00d33877 has its CatchHandler @ 00d338b8 */
    (*(code *)PTR_operator__010cc99c)(auStack_784,auStack_11ec);
                    /* try { // try from 00d33888 to 00d338ab has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_11ec);
    (*(code *)PTR_MImg_010c7d68)(auStack_1200,0x5cd);
                    /* try { // try from 00d3390c to 00d33913 has its CatchHandler @ 00d33968 */
    (*(code *)PTR_operator__010cc99c)(auStack_75c,auStack_1200);
                    /* try { // try from 00d33924 to 00d3392b has its CatchHandler @ 00d38720 */
    (*(code *)PTR__MImg_010c8444)(auStack_1200);
    uStack_ab0 = 0;
    uStack_aac = 0;
    uStack_aa8 = 0xc4;
    uStack_aa4 = 0x92;
    if (this[0x2b1] == (HomePageFrame)0x1) {
      (*(code *)PTR_set_010c9810)(aiStack_aec,0x40,0x41,0xc4,0x92);
      for (iStack_1a74 = 0; iStack_1a74 < 2; iStack_1a74 = iStack_1a74 + 1) {
                    /* try { // try from 00d339e4 to 00d339eb has its CatchHandler @ 00d38720 */
        iStack_334 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d33a20 to 00d33a27 has its CatchHandler @ 00d33a48 */
        (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_334,piVar5,aiStack_aec,0,iStack_1a74 + 0x3d,1)
        ;
        iVar4 = iStack_334;
        if (iStack_334 == 0) {
                    /* try { // try from 00d33aa0 to 00d34013 has its CatchHandler @ 00d38720 */
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                     PTR_DAT_010c43ec + -0x14d0,0x1000);
                    /* WARNING: Subroutine does not return */
          (*(code *)PTR_abort_010cc6c0)();
        }
        (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_334,2);
        (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
        (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
        (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
        (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
        *(undefined1 *)(iVar4 + 0x39) = 1;
        *(undefined1 *)(iVar4 + 0x3a) = 1;
        (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9c) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9e) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa0) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa2) = uVar1;
        *(undefined1 *)(iVar4 + 0x38) = 1;
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x40);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x28);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x28);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x28);
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x58) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x54) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x4c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x50) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 100) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x5c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x60) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x68) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x74) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x6c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x70) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x78) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x84) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x7c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x80) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x88) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x94) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x8c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x90) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x98) = uVar3;
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
        (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
        aiStack_aec[0] = aiStack_aec[0] + 0xe0;
        if (iStack_1a74 == 0) {
          (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2b4);
        }
      }
    }
    else {
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x230));
      (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x230),this + 0x2b4);
    }
    if (this[0x2b1] == (HomePageFrame)0x1) {
      (*(code *)PTR_set_010c9810)(aiStack_aec,0x3dc,0x41,0xc4,0x92);
      for (iStack_1a78 = 0; iStack_1a78 < 4; iStack_1a78 = iStack_1a78 + 1) {
        iStack_338 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d34048 to 00d3404f has its CatchHandler @ 00d34070 */
        (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_338,piVar5,aiStack_aec,0,iStack_1a78 + 0x4e,1)
        ;
        iVar4 = iStack_338;
        if (iStack_338 == 0) {
                    /* try { // try from 00d340c8 to 00d3461f has its CatchHandler @ 00d38720 */
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                     PTR_DAT_010c43ec + -0x14d0,0x1049);
                    /* WARNING: Subroutine does not return */
          (*(code *)PTR_abort_010cc6c0)();
        }
        (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_338,2);
        (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
        (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
        (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
        (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
        *(undefined1 *)(iVar4 + 0x39) = 1;
        *(undefined1 *)(iVar4 + 0x3a) = 1;
        (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9c) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9e) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa0) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa2) = uVar1;
        *(undefined1 *)(iVar4 + 0x38) = 1;
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x4f);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x4e);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x4e);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x4e);
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x58) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x54) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x4c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x50) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 100) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x5c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x60) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x68) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x74) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x6c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x70) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x78) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x84) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x7c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x80) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x88) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x94) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x8c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x90) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x98) = uVar3;
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
        (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
        aiStack_aec[0] = aiStack_aec[0] + 0xe0;
        if (iStack_1a78 == 1) {
          (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2c4);
        }
      }
    }
    else {
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x260));
      (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x260),this + 0x2b4);
    }
    (*(code *)PTR_set_010c9810)(aiStack_aec,0x40,0x13f,0xc4,0x92);
    iStack_33c = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d34650 to 00d34657 has its CatchHandler @ 00d34678 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_33c,piVar5,aiStack_aec,0,0x4d,1);
    iVar4 = iStack_33c;
    if (iStack_33c == 0) {
                    /* try { // try from 00d346d0 to 00d34b7b has its CatchHandler @ 00d38720 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0x108a);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_33c,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_aec[0] = aiStack_aec[0] + 0xe0;
    (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2d4);
    iStack_340 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d34bac to 00d34bb3 has its CatchHandler @ 00d34bd4 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_340,piVar5,aiStack_aec,0,0x46,1);
    iVar4 = iStack_340;
    if (iStack_340 == 0) {
                    /* try { // try from 00d34c2c to 00d350e7 has its CatchHandler @ 00d38720 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0x10c2);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_340,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_aec[0] = aiStack_aec[0] + 0xe0;
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 != 0) {
      iStack_344 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d35118 to 00d3511f has its CatchHandler @ 00d35140 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_344,piVar5,aiStack_aec,0,0x49,1);
      iVar4 = iStack_344;
      if (iStack_344 == 0) {
                    /* try { // try from 00d35198 to 00d3561f has its CatchHandler @ 00d38720 */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                   0x10fa);
                    /* WARNING: Subroutine does not return */
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_344,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_aec[0] = aiStack_aec[0] + 0xe0;
    }
    iStack_348 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d35650 to 00d35657 has its CatchHandler @ 00d35678 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_348,piVar5,aiStack_aec,0,0x52,1);
    iVar4 = iStack_348;
    if (iStack_348 != 0) {
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_348,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_aec[0] = aiStack_aec[0] + 0xe0;
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
      if (iVar4 == 0) {
        (*(code *)PTR_set_010c9810)(aiStack_aec,0x2fc,0x13f,0xc4,0x92);
      }
      else {
        (*(code *)PTR_set_010c9810)(aiStack_aec,0x3dc,0x13f,0xc4,0x92);
      }
      iStack_34c = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d35c20 to 00d35c27 has its CatchHandler @ 00d35c48 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_34c,piVar5,aiStack_aec,0,0x4c,1);
      iVar4 = iStack_34c;
      if (iStack_34c != 0) {
        (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_34c,2);
        (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
        (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
        (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
        (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_aa0,&uStack_ac0);
        *(undefined1 *)(iVar4 + 0x39) = 1;
        *(undefined1 *)(iVar4 + 0x3a) = 1;
        (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9c) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0x9e) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa0) = uVar1;
        uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
        *(undefined2 *)(iVar4 + 0xa2) = uVar1;
        *(undefined1 *)(iVar4 + 0x38) = 1;
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x1ce);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x1cd);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x1cd);
        (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x1cd);
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x58) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
        *(undefined4 *)(iVar4 + 0x54) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x4c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x50) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 100) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x5c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x60) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x68) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x74) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x6c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x70) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
        *(undefined4 *)(iVar4 + 0x78) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x84) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x7c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x80) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
        *(undefined4 *)(iVar4 + 0x88) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x94) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x8c) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x90) = uVar3;
        uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
        *(undefined4 *)(iVar4 + 0x98) = uVar3;
        (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
        (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
        aiStack_aec[0] = aiStack_aec[0] + 0xe0;
        (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2e4);
        if (this[0x2b1] == (HomePageFrame)0x1) {
          iStack_354 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3d);
          if (iStack_354 == 0) {
            iStack_350 = 0;
          }
          else {
            iStack_350 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_354,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_350;
          iStack_358 = *(int *)(*(int *)(iStack_350 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1214,0x82);
                    /* try { // try from 00d361f8 to 00d361ff has its CatchHandler @ 00d36258 */
          (*(code *)PTR_operator__010cc99c)(iStack_358,auStack_1214);
                    /* try { // try from 00d36210 to 00d3624b has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1214);
          iStack_35c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_1228,0x82);
                    /* try { // try from 00d362a4 to 00d362ab has its CatchHandler @ 00d36304 */
          (*(code *)PTR_operator__010cc99c)(iStack_35c,auStack_1228);
                    /* try { // try from 00d362bc to 00d362f7 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1228);
          iStack_360 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_123c,0x82);
                    /* try { // try from 00d36350 to 00d36357 has its CatchHandler @ 00d363b0 */
          (*(code *)PTR_operator__010cc99c)(iStack_360,auStack_123c);
                    /* try { // try from 00d36368 to 00d363a3 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_123c);
          iStack_364 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1250,0x83);
                    /* try { // try from 00d363fc to 00d36403 has its CatchHandler @ 00d36450 */
          (*(code *)PTR_operator__010cc99c)(iStack_364,auStack_1250);
                    /* try { // try from 00d36414 to 00d36443 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1250);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118b);
                    /* try { // try from 00d3649c to 00d3651f has its CatchHandler @ 00d38720 */
          iStack_36c = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3e);
          if (iStack_36c == 0) {
            iStack_368 = 0;
          }
          else {
            iStack_368 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_36c,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_368;
          iStack_370 = *(int *)(*(int *)(iStack_368 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1264,0x82);
                    /* try { // try from 00d36534 to 00d3653b has its CatchHandler @ 00d36594 */
          (*(code *)PTR_operator__010cc99c)(iStack_370,auStack_1264);
                    /* try { // try from 00d3654c to 00d36587 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1264);
          iStack_374 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_1278,0x82);
                    /* try { // try from 00d365e0 to 00d365e7 has its CatchHandler @ 00d36640 */
          (*(code *)PTR_operator__010cc99c)(iStack_374,auStack_1278);
                    /* try { // try from 00d365f8 to 00d36633 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1278);
          iStack_378 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_128c,0x82);
                    /* try { // try from 00d3668c to 00d36693 has its CatchHandler @ 00d366ec */
          (*(code *)PTR_operator__010cc99c)(iStack_378,auStack_128c);
                    /* try { // try from 00d366a4 to 00d366df has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_128c);
          iStack_37c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_12a0,0x83);
                    /* try { // try from 00d36738 to 00d3673f has its CatchHandler @ 00d3678c */
          (*(code *)PTR_operator__010cc99c)(iStack_37c,auStack_12a0);
                    /* try { // try from 00d36750 to 00d3677f has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_12a0);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118c);
                    /* try { // try from 00d367d8 to 00d3685b has its CatchHandler @ 00d38720 */
          iStack_384 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3f);
          if (iStack_384 == 0) {
            iStack_380 = 0;
          }
          else {
            iStack_380 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_384,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_380;
          iStack_388 = *(int *)(*(int *)(iStack_380 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_12b4,0x82);
                    /* try { // try from 00d36870 to 00d36877 has its CatchHandler @ 00d368d0 */
          (*(code *)PTR_operator__010cc99c)(iStack_388,auStack_12b4);
                    /* try { // try from 00d36888 to 00d368c3 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_12b4);
          iStack_38c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_12c8,0x82);
                    /* try { // try from 00d3691c to 00d36923 has its CatchHandler @ 00d3697c */
          (*(code *)PTR_operator__010cc99c)(iStack_38c,auStack_12c8);
                    /* try { // try from 00d36934 to 00d3696f has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_12c8);
          iStack_390 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_12dc,0x82);
                    /* try { // try from 00d369c8 to 00d369cf has its CatchHandler @ 00d36a28 */
          (*(code *)PTR_operator__010cc99c)(iStack_390,auStack_12dc);
                    /* try { // try from 00d369e0 to 00d36a1b has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_12dc);
          iStack_394 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_12f0,0x83);
                    /* try { // try from 00d36a74 to 00d36a7b has its CatchHandler @ 00d36ac8 */
          (*(code *)PTR_operator__010cc99c)(iStack_394,auStack_12f0);
                    /* try { // try from 00d36a8c to 00d36abb has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_12f0);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118d);
                    /* try { // try from 00d36b14 to 00d36bdf has its CatchHandler @ 00d38720 */
          iStack_39c = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x40);
          if (iStack_39c == 0) {
            iStack_398 = 0;
          }
          else {
            iStack_398 = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_39c,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_398;
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iStack_398 + 0x250) + 4));
          (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
          iStack_3a0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1304,0x75);
                    /* try { // try from 00d36bf4 to 00d36bfb has its CatchHandler @ 00d36c54 */
          (*(code *)PTR_operator__010cc99c)(iStack_3a0,auStack_1304);
                    /* try { // try from 00d36c0c to 00d36c47 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1304);
          iStack_3a4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_1318,0x75);
                    /* try { // try from 00d36ca0 to 00d36ca7 has its CatchHandler @ 00d36d00 */
          (*(code *)PTR_operator__010cc99c)(iStack_3a4,auStack_1318);
                    /* try { // try from 00d36cb8 to 00d36cf3 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1318);
          iStack_3a8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_132c,0x75);
                    /* try { // try from 00d36d4c to 00d36d53 has its CatchHandler @ 00d36dac */
          (*(code *)PTR_operator__010cc99c)(iStack_3a8,auStack_132c);
                    /* try { // try from 00d36d64 to 00d36d9f has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_132c);
          iStack_3ac = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1340,0x76);
                    /* try { // try from 00d36df8 to 00d36dff has its CatchHandler @ 00d36e4c */
          (*(code *)PTR_operator__010cc99c)(iStack_3ac,auStack_1340);
                    /* try { // try from 00d36e10 to 00d36e3f has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1340);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd57);
        }
                    /* try { // try from 00d36e98 to 00d36f1b has its CatchHandler @ 00d38720 */
        iStack_3b4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4d);
        if (iStack_3b4 == 0) {
          iStack_3b0 = 0;
        }
        else {
          iStack_3b0 = (*(code *)PTR___dynamic_cast_010c6984)
                                 (iStack_3b4,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
        }
        iVar4 = iStack_3b0;
        iStack_3b8 = *(int *)(*(int *)(iStack_3b0 + 0x254) + 4) + 0x29c;
        (*(code *)PTR_MImg_010c7d68)(auStack_1354,0x92);
                    /* try { // try from 00d36f30 to 00d36f37 has its CatchHandler @ 00d36f90 */
        (*(code *)PTR_operator__010cc99c)(iStack_3b8,auStack_1354);
                    /* try { // try from 00d36f48 to 00d36f83 has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1354);
        iStack_3bc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
        (*(code *)PTR_MImg_010c7d68)(auStack_1368,0x92);
                    /* try { // try from 00d36fdc to 00d36fe3 has its CatchHandler @ 00d3703c */
        (*(code *)PTR_operator__010cc99c)(iStack_3bc,auStack_1368);
                    /* try { // try from 00d36ff4 to 00d3702f has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1368);
        iStack_3c0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
        (*(code *)PTR_MImg_010c7d68)(auStack_137c,0x92);
                    /* try { // try from 00d37088 to 00d3708f has its CatchHandler @ 00d370e8 */
        (*(code *)PTR_operator__010cc99c)(iStack_3c0,auStack_137c);
                    /* try { // try from 00d370a0 to 00d370db has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_137c);
        iStack_3c4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
        (*(code *)PTR_MImg_010c7d68)(auStack_1390,0x93);
                    /* try { // try from 00d37134 to 00d3713b has its CatchHandler @ 00d37188 */
        (*(code *)PTR_operator__010cc99c)(iStack_3c4,auStack_1390);
                    /* try { // try from 00d3714c to 00d3717b has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1390);
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11e0);
                    /* try { // try from 00d371d4 to 00d37257 has its CatchHandler @ 00d38720 */
        iStack_3cc = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x52);
        if (iStack_3cc == 0) {
          iStack_3c8 = 0;
        }
        else {
          iStack_3c8 = (*(code *)PTR___dynamic_cast_010c6984)
                                 (iStack_3cc,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
        }
        iVar4 = iStack_3c8;
        iStack_3d0 = *(int *)(*(int *)(iStack_3c8 + 0x254) + 4) + 0x29c;
        (*(code *)PTR_MImg_010c7d68)(auStack_13a4,0x90);
                    /* try { // try from 00d3726c to 00d37273 has its CatchHandler @ 00d372cc */
        (*(code *)PTR_operator__010cc99c)(iStack_3d0,auStack_13a4);
                    /* try { // try from 00d37284 to 00d372bf has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_13a4);
        iStack_3d4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
        (*(code *)PTR_MImg_010c7d68)(auStack_13b8,0x90);
                    /* try { // try from 00d37318 to 00d3731f has its CatchHandler @ 00d37378 */
        (*(code *)PTR_operator__010cc99c)(iStack_3d4,auStack_13b8);
                    /* try { // try from 00d37330 to 00d3736b has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_13b8);
        iStack_3d8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
        (*(code *)PTR_MImg_010c7d68)(auStack_13cc,0x90);
                    /* try { // try from 00d373c4 to 00d373cb has its CatchHandler @ 00d37424 */
        (*(code *)PTR_operator__010cc99c)(iStack_3d8,auStack_13cc);
                    /* try { // try from 00d373dc to 00d37417 has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_13cc);
        iStack_3dc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
        (*(code *)PTR_MImg_010c7d68)(auStack_13e0,0x91);
                    /* try { // try from 00d37470 to 00d37477 has its CatchHandler @ 00d374ac */
        (*(code *)PTR_operator__010cc99c)(iStack_3dc,auStack_13e0);
                    /* try { // try from 00d37488 to 00d3749f has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_13e0);
        uVar3 = (*(code *)PTR_getInstance_010c67ec)();
                    /* try { // try from 00d374f0 to 00d375db has its CatchHandler @ 00d38720 */
        iVar8 = (*(code *)PTR_GetFavSource_010c8200)(uVar3);
        if (iVar8 == 0x2a) {
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x110a);
        }
        else {
          sVar2 = (*(code *)PTR_ConvertSourceTypeToIndex_010c9fa4)(this,iVar8);
          if (sVar2 == 0) {
            (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xb0a);
          }
          else {
            iStack_3e0 = **(int **)(iVar4 + 0x250) + 0x170;
            uVar3 = (*(code *)PTR_getInstance_010c67ec)();
            (*(code *)PTR_GetSourceName_010cadc8)(auStack_13e4,uVar3,sVar2);
                    /* try { // try from 00d375f0 to 00d375f7 has its CatchHandler @ 00d3761c */
            (*(code *)PTR_Set_010cb39c)(iStack_3e0,auStack_13e4);
                    /* try { // try from 00d37608 to 00d3760f has its CatchHandler @ 00d38720 */
            (*(code *)PTR__string_010c5070)(auStack_13e4);
          }
        }
                    /* try { // try from 00d37668 to 00d376eb has its CatchHandler @ 00d38720 */
        iStack_3e8 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x46);
        if (iStack_3e8 == 0) {
          iStack_3e4 = 0;
        }
        else {
          iStack_3e4 = (*(code *)PTR___dynamic_cast_010c6984)
                                 (iStack_3e8,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
        }
        iVar4 = iStack_3e4;
        iStack_3ec = *(int *)(*(int *)(iStack_3e4 + 0x254) + 4) + 0x29c;
        (*(code *)PTR_MImg_010c7d68)(auStack_13f8,0x8e);
                    /* try { // try from 00d37700 to 00d37707 has its CatchHandler @ 00d37760 */
        (*(code *)PTR_operator__010cc99c)(iStack_3ec,auStack_13f8);
                    /* try { // try from 00d37718 to 00d37753 has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_13f8);
        iStack_3f0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
        (*(code *)PTR_MImg_010c7d68)(auStack_140c,0x8e);
                    /* try { // try from 00d377ac to 00d377b3 has its CatchHandler @ 00d3780c */
        (*(code *)PTR_operator__010cc99c)(iStack_3f0,auStack_140c);
                    /* try { // try from 00d377c4 to 00d377ff has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_140c);
        iStack_3f4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
        (*(code *)PTR_MImg_010c7d68)(auStack_1420,0x8e);
                    /* try { // try from 00d37858 to 00d3785f has its CatchHandler @ 00d378b8 */
        (*(code *)PTR_operator__010cc99c)(iStack_3f4,auStack_1420);
                    /* try { // try from 00d37870 to 00d378ab has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1420);
        iStack_3f8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
        (*(code *)PTR_MImg_010c7d68)(auStack_1434,0x8f);
                    /* try { // try from 00d37904 to 00d3790b has its CatchHandler @ 00d37958 */
        (*(code *)PTR_operator__010cc99c)(iStack_3f8,auStack_1434);
                    /* try { // try from 00d3791c to 00d3794b has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1434);
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd0e);
                    /* try { // try from 00d37998 to 00d37a5b has its CatchHandler @ 00d38720 */
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
        if (iVar4 != 0) {
          iStack_400 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x49);
          if (iStack_400 == 0) {
            iStack_3fc = 0;
          }
          else {
            iStack_3fc = (*(code *)PTR___dynamic_cast_010c6984)
                                   (iStack_400,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
          }
          iVar4 = iStack_3fc;
          iStack_404 = *(int *)(*(int *)(iStack_3fc + 0x254) + 4) + 0x29c;
          (*(code *)PTR_MImg_010c7d68)(auStack_1448,0x78);
                    /* try { // try from 00d37a70 to 00d37a77 has its CatchHandler @ 00d37ad0 */
          (*(code *)PTR_operator__010cc99c)(iStack_404,auStack_1448);
                    /* try { // try from 00d37a88 to 00d37ac3 has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1448);
          iStack_408 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
          (*(code *)PTR_MImg_010c7d68)(auStack_145c,0x78);
                    /* try { // try from 00d37b1c to 00d37b23 has its CatchHandler @ 00d37b7c */
          (*(code *)PTR_operator__010cc99c)(iStack_408,auStack_145c);
                    /* try { // try from 00d37b34 to 00d37b6f has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_145c);
          iStack_40c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
          (*(code *)PTR_MImg_010c7d68)(auStack_1470,0x78);
                    /* try { // try from 00d37bc8 to 00d37bcf has its CatchHandler @ 00d37c28 */
          (*(code *)PTR_operator__010cc99c)(iStack_40c,auStack_1470);
                    /* try { // try from 00d37be0 to 00d37c1b has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1470);
          iStack_410 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
          (*(code *)PTR_MImg_010c7d68)(auStack_1484,0x79);
                    /* try { // try from 00d37c74 to 00d37c7b has its CatchHandler @ 00d37cc8 */
          (*(code *)PTR_operator__010cc99c)(iStack_410,auStack_1484);
                    /* try { // try from 00d37c8c to 00d37cbb has its CatchHandler @ 00d38720 */
          (*(code *)PTR__MImg_010c8444)(auStack_1484);
          (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x114e);
        }
                    /* try { // try from 00d37d14 to 00d37d97 has its CatchHandler @ 00d38720 */
        iStack_418 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4c);
        if (iStack_418 == 0) {
          iStack_414 = 0;
        }
        else {
          iStack_414 = (*(code *)PTR___dynamic_cast_010c6984)
                                 (iStack_418,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
        }
        iVar4 = iStack_414;
        iStack_41c = *(int *)(*(int *)(iStack_414 + 0x254) + 4) + 0x29c;
        (*(code *)PTR_MImg_010c7d68)(auStack_1498,0x88);
                    /* try { // try from 00d37dac to 00d37db3 has its CatchHandler @ 00d37e0c */
        (*(code *)PTR_operator__010cc99c)(iStack_41c,auStack_1498);
                    /* try { // try from 00d37dc4 to 00d37dff has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_1498);
        iStack_420 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
        (*(code *)PTR_MImg_010c7d68)(auStack_14ac,0x88);
                    /* try { // try from 00d37e58 to 00d37e5f has its CatchHandler @ 00d37eb8 */
        (*(code *)PTR_operator__010cc99c)(iStack_420,auStack_14ac);
                    /* try { // try from 00d37e70 to 00d37eab has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_14ac);
        iStack_424 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
        (*(code *)PTR_MImg_010c7d68)(auStack_14c0,0x88);
                    /* try { // try from 00d37f04 to 00d37f0b has its CatchHandler @ 00d37f64 */
        (*(code *)PTR_operator__010cc99c)(iStack_424,auStack_14c0);
                    /* try { // try from 00d37f1c to 00d37f57 has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_14c0);
        iStack_428 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
        (*(code *)PTR_MImg_010c7d68)(auStack_14d4,0x89);
                    /* try { // try from 00d37fb0 to 00d37fb7 has its CatchHandler @ 00d38004 */
        (*(code *)PTR_operator__010cc99c)(iStack_428,auStack_14d4);
                    /* try { // try from 00d37fc8 to 00d37ff7 has its CatchHandler @ 00d38720 */
        (*(code *)PTR__MImg_010c8444)(auStack_14d4);
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf49);
        if (this[0x2b1] == (HomePageFrame)0x1) {
          for (iStack_1a84 = 0; iStack_1a84 < 4; iStack_1a84 = iStack_1a84 + 1) {
                    /* try { // try from 00d3807c to 00d380fb has its CatchHandler @ 00d38720 */
            iVar4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,iStack_1a84 + 0x4e);
            iVar8 = (*(code *)PTR_size_010cbda0)(this + 0x2a0);
            if (iStack_1a84 < iVar8) {
              (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a84);
              (*(code *)PTR_ostringstream_010c9ac8)(auStack_a80,0x10);
              puVar6 = (undefined2 *)(*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a84);
                    /* try { // try from 00d3813c to 00d381cb has its CatchHandler @ 00d38268 */
              (*(code *)PTR_operator<<_010cb3b0)(auStack_a80,*puVar6);
              iVar8 = **(int **)(iVar4 + 0x250);
              iVar7 = (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a84);
              (*(code *)PTR_Set_010cb39c)(iVar8 + 0x170,iVar7 + 8);
              iStack_42c = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
              (*(code *)PTR_str_010c961c)(auStack_14d8,auStack_a80);
                    /* try { // try from 00d381e0 to 00d381e7 has its CatchHandler @ 00d38224 */
              (*(code *)PTR_Set_010cb39c)(iStack_42c,auStack_14d8);
                    /* try { // try from 00d381f8 to 00d381ff has its CatchHandler @ 00d38268 */
              (*(code *)PTR__string_010c5070)(auStack_14d8);
                    /* try { // try from 00d38210 to 00d38217 has its CatchHandler @ 00d38720 */
              (*(code *)PTR__ostringstream_010cc6a8)(auStack_a80);
            }
            else {
                    /* try { // try from 00d382c0 to 00d382c7 has its CatchHandler @ 00d38720 */
              (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xe32);
              iStack_430 = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
              (*(code *)PTR_allocator_010c6920)(auStack_14e0);
                    /* try { // try from 00d38318 to 00d3831f has its CatchHandler @ 00d383bc */
              (*(code *)PTR_string_010c4f9c)(auStack_14dc,PTR_DAT_010c43ec + -0x15a0,auStack_14e0);
                    /* try { // try from 00d38334 to 00d3833b has its CatchHandler @ 00d3837c */
              (*(code *)PTR_Set_010cb39c)(iStack_430,auStack_14dc);
              puStack_434 = auStack_14dc;
                    /* try { // try from 00d38350 to 00d38357 has its CatchHandler @ 00d383bc */
              (*(code *)PTR__string_010c5070)(puStack_434);
              (*(code *)PTR__allocator_010c4948)(auStack_14e0);
            }
                    /* try { // try from 00d38404 to 00d3847b has its CatchHandler @ 00d38720 */
            (*(code *)PTR_Invalidate_010c4e28)(iVar4);
          }
          for (uStack_1a88 = 0; (int)uStack_1a88 < 3; uStack_1a88 = uStack_1a88 + 1) {
            iVar4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,uStack_1a88 + 0x3d);
            (*(code *)(PTR_LAB_010c4418 + 0x5ec4))(auStack_adc);
                    /* try { // try from 00d38498 to 00d384cb has its CatchHandler @ 00d3867c */
            iVar8 = (*(code *)PTR_GetPinnedChannel_010c4de4)(uStack_1a88 & 0xff,auStack_adc);
            if (iVar8 == 0) {
                    /* try { // try from 00d38628 to 00d38647 has its CatchHandler @ 00d3867c */
              (*(code *)PTR_Set_010c61fc)
                        (**(int **)(iVar4 + 0x250) + 0x170,(uStack_1a88 & 0xffff) + 0x118b & 0xffff)
              ;
            }
            else {
              (*(code *)PTR_ostringstream_010c9ac8)(auStack_a80,0x10);
                    /* try { // try from 00d384e8 to 00d38523 has its CatchHandler @ 00d385c0 */
              (*(code *)PTR_operator<<_010c4a9c)(auStack_a80,auStack_ad4);
              iStack_438 = **(int **)(iVar4 + 0x250) + 0x170;
              (*(code *)PTR_str_010c961c)(auStack_14e4,auStack_a80);
                    /* try { // try from 00d38538 to 00d3853f has its CatchHandler @ 00d3857c */
              (*(code *)PTR_Set_010cb39c)(iStack_438,auStack_14e4);
                    /* try { // try from 00d38550 to 00d38557 has its CatchHandler @ 00d385c0 */
              (*(code *)PTR__string_010c5070)(auStack_14e4);
                    /* try { // try from 00d38568 to 00d3856f has its CatchHandler @ 00d3867c */
              (*(code *)PTR__ostringstream_010cc6a8)(auStack_a80);
            }
            (*(code *)PTR_Invalidate_010c4e28)(iVar4);
                    /* try { // try from 00d3865c to 00d38663 has its CatchHandler @ 00d38720 */
            (*(code *)(PTR_LAB_010c4418 + 0x5dac))(auStack_adc);
          }
        }
                    /* try { // try from 00d386e4 to 00d38703 has its CatchHandler @ 00d38720 */
        (**(code **)(*piVar5 + 0x48))(piVar5);
        (*(code *)PTR_Invalidate_010c4e28)(piVar5);
        puStack_660 = auStack_6e4;
        while (puStack_660 != auStack_88c) {
          puStack_660 = puStack_660 + -0xd4;
                    /* try { // try from 00d387c4 to 00d387cb has its CatchHandler @ 00d387ec */
          (*(code *)(PTR_LAB_010c441c + -0x71f8))(puStack_660);
        }
        puStack_664 = auStack_88c;
        while (puStack_664 != auStack_9cc) {
          puStack_664 = puStack_664 + -0xa0;
          (*(code *)(PTR_LAB_010c4418 + 0x5e04))(puStack_664);
        }
        return;
      }
                    /* try { // try from 00d35ca0 to 00d361e3 has its CatchHandler @ 00d38720 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0x116f);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
                    /* try { // try from 00d356d0 to 00d35bef has its CatchHandler @ 00d38720 */
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
               0x1130);
                    /* WARNING: Subroutine does not return */
    (*(code *)PTR_abort_010cc6c0)();
  }
  piVar5 = *(int **)(this + 0x184);
  puStack_20 = auStack_9cc;
  puStack_1c = puStack_20;
  for (iStack_24 = 1; iStack_24 != -1; iStack_24 = iStack_24 + -1) {
                    /* try { // try from 00d2959c to 00d295a3 has its CatchHandler @ 00d295f0 */
    (*(code *)(PTR_LAB_010c4418 + 0x5f1c))(puStack_20);
    puStack_20 = puStack_20 + 0xa0;
  }
  puStack_2c = auStack_88c;
  puStack_28 = puStack_2c;
  for (iStack_30 = 1; iStack_30 != -1; iStack_30 = iStack_30 + -1) {
                    /* try { // try from 00d296a4 to 00d296ab has its CatchHandler @ 00d296e4 */
    (*(code *)(PTR_LAB_010c441c + -0x6dc0))(puStack_2c);
    puStack_2c = puStack_2c + 0xd4;
  }
  for (bStack_1a2f = 0; bStack_1a2f < 2; bStack_1a2f = bStack_1a2f + 1) {
    uStack_34 = (uint)bStack_1a2f;
                    /* try { // try from 00d297ac to 00d2a0ff has its CatchHandler @ 00d324c0 */
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_34 * 0x28] = uVar3;
    uStack_38 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_38 * 0x28 + 1] = uVar3;
    uStack_3c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_3c * 0x28 + 2] = uVar3;
    uStack_40 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_40 * 0x28 + 3] = uVar3;
    uStack_44 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_44 * 0x28 + 4] = uVar3;
    uStack_48 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_944[uStack_48 * 0x28 + 5] = uVar3;
    auStack_9c8[(uint)bStack_1a2f * 0x28 + 0x18] = 0x4ae;
    auStack_9c8[(uint)bStack_1a2f * 0x28 + 0x1a] = 0x4ae;
    auStack_9c8[(uint)bStack_1a2f * 0x28 + 0x19] = 0x4ae;
    auStack_9c8[(uint)bStack_1a2f * 0x28 + 0x1b] = 0x4ae;
    uStack_4c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_9cc + (uStack_4c * 0x14 + 1) * 8 + 4) = uVar3;
    uStack_50 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_9cc + uStack_50 * 0xa0 + 4) = uVar3;
    uStack_54 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_9cc + (uStack_54 * 0x28 + 1) * 4 + 4) = uVar3;
    uStack_58 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_9c8[uStack_58 * 0x28 + 3] = uVar3;
    uStack_5c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_9c8[uStack_5c * 0x28 + 6] = uVar3;
    uStack_60 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(auStack_9cc + (uStack_60 * 10 + 1) * 0x10 + 4) = uVar3;
    uStack_64 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_9c8[uStack_64 * 0x28 + 5] = uVar3;
    uStack_68 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_9c8[uStack_68 * 0x28 + 7] = uVar3;
    uStack_6c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(3);
    auStack_9c8[uStack_6c * 0x28 + 10] = uVar3;
    uStack_70 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(7);
    *(undefined4 *)(auStack_9cc + (uStack_70 * 5 + 1) * 0x20 + 4) = uVar3;
    uStack_74 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
    auStack_9c8[uStack_74 * 0x28 + 9] = uVar3;
    uStack_78 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
    auStack_9c8[uStack_78 * 0x28 + 0xb] = uVar3;
    uStack_7c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_9c8[uStack_7c * 0x28 + 0xe] = uVar3;
    uStack_80 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_9c8[uStack_80 * 0x28 + 0xc] = uVar3;
    uStack_84 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_9c8[uStack_84 * 0x28 + 0xd] = uVar3;
    uStack_88 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_9c8[uStack_88 * 0x28 + 0xf] = uVar3;
    uStack_8c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_9c8[uStack_8c * 0x28 + 0x12] = uVar3;
    uStack_90 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_9c8[uStack_90 * 0x28 + 0x10] = uVar3;
    uStack_94 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_9c8[uStack_94 * 0x28 + 0x11] = uVar3;
    uStack_98 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_9c8[uStack_98 * 0x28 + 0x13] = uVar3;
    auStack_954[(uint)bStack_1a2f * 0xa0] = 0;
    auStack_9cc[(uint)bStack_1a2f * 0xa0] = 0;
    auStack_9cc[(uint)bStack_1a2f * 0xa0 + 1] = 1;
    auStack_948[(uint)bStack_1a2f * 0xa0] = 0;
    uStack_9c = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
    auStack_9c8[uStack_9c * 0x28 + 0x14] = uVar3;
    uStack_a0 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
    auStack_9c8[uStack_a0 * 0x28 + 0x16] = uVar3;
    uStack_a4 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
    auStack_9c8[uStack_a4 * 0x28 + 0x15] = uVar3;
    uStack_a8 = (uint)bStack_1a2f;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
    auStack_9c8[uStack_a8 * 0x28 + 0x17] = uVar3;
  }
  (*(code *)PTR_assign_010cc3b8)(auStack_8ac,PTR_DAT_010c43ec + -0x15dc);
  uStack_8b8 = 0x22;
  uStack_8d8 = 0x46;
  uStack_8d0 = 0x46;
  uStack_8d4 = 0x46;
  uStack_8cc = 0x46;
  uStack_8c8 = 0x4b2;
  uStack_8c0 = 0x4b2;
  uStack_8c4 = 0x4b2;
  uStack_8bc = 0x4b2;
  (*(code *)PTR_assign_010cc3b8)(auStack_94c,PTR_DAT_010c43ec + -0x15d8);
  auStack_968[4] = 0x22;
  uStack_ab0 = 0;
  uStack_aac = 0xf;
  uStack_aa8 = 0xc4;
  uStack_aa4 = 0x46;
  uStack_ac0 = 0;
  uStack_abc = 0x60;
  uStack_ab8 = 0xc4;
  uStack_ab4 = 0x2d;
  for (bStack_1a30 = 0; bStack_1a30 < 2; bStack_1a30 = bStack_1a30 + 1) {
    puStack_ac = auStack_844 + (uint)bStack_1a30 * 0xd4;
    (*(code *)PTR_MImg_010c7d68)(auStack_b1c,0x5cd);
                    /* try { // try from 00d2a114 to 00d2a11b has its CatchHandler @ 00d2a194 */
    (*(code *)PTR_operator__010cc99c)(puStack_ac,auStack_b1c);
                    /* try { // try from 00d2a12c to 00d2a187 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_b1c);
    puStack_b0 = auStack_81c + (uint)bStack_1a30 * 0xd4;
    (*(code *)PTR_MImg_010c7d68)(auStack_b30,0x5cd);
                    /* try { // try from 00d2a1e0 to 00d2a1e7 has its CatchHandler @ 00d2a2b0 */
    (*(code *)PTR_operator__010cc99c)(puStack_b0,auStack_b30);
                    /* try { // try from 00d2a1f8 to 00d2a1ff has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_b30);
    auStack_88c[(uint)bStack_1a30 * 0xd4] = 0;
    auStack_88c[(uint)bStack_1a30 * 0xd4 + 1] = 1;
    auStack_88c[(uint)bStack_1a30 * 0xd4 + 2] = 1;
  }
                    /* try { // try from 00d2a31c to 00d2a323 has its CatchHandler @ 00d324c0 */
  (*(code *)PTR_MImg_010c7d68)(auStack_b44,0x40);
                    /* try { // try from 00d2a340 to 00d2a347 has its CatchHandler @ 00d2a388 */
  (*(code *)PTR_operator__010cc99c)(auStack_81c,auStack_b44);
                    /* try { // try from 00d2a358 to 00d2a37b has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_b44);
  (*(code *)PTR_MImg_010c7d68)(auStack_b58,0x5cd);
                    /* try { // try from 00d2a3dc to 00d2a3e3 has its CatchHandler @ 00d2a424 */
  (*(code *)PTR_operator__010cc99c)(auStack_844,auStack_b58);
                    /* try { // try from 00d2a3f4 to 00d2a417 has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_b58);
  (*(code *)PTR_MImg_010c7d68)(auStack_b6c,0x5cd);
                    /* try { // try from 00d2a478 to 00d2a47f has its CatchHandler @ 00d2a4c0 */
  (*(code *)PTR_operator__010cc99c)(auStack_858,auStack_b6c);
                    /* try { // try from 00d2a490 to 00d2a4b3 has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_b6c);
  (*(code *)PTR_MImg_010c7d68)(auStack_b80,0x5cd);
                    /* try { // try from 00d2a514 to 00d2a51b has its CatchHandler @ 00d2a574 */
  (*(code *)PTR_operator__010cc99c)(auStack_830,auStack_b80);
                    /* try { // try from 00d2a52c to 00d2a567 has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_b80);
  uStack_aa0 = 0;
  uStack_a9c = 0;
  uStack_a98 = 0x142;
  uStack_a94 = 0x110;
  (*(code *)PTR_MImg_010c7d68)(auStack_b94,0x5cd);
                    /* try { // try from 00d2a5c8 to 00d2a5cf has its CatchHandler @ 00d2a610 */
  (*(code *)PTR_operator__010cc99c)(auStack_748,auStack_b94);
                    /* try { // try from 00d2a5e0 to 00d2a603 has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_b94);
  (*(code *)PTR_MImg_010c7d68)(auStack_ba8,0x5cd);
                    /* try { // try from 00d2a664 to 00d2a66b has its CatchHandler @ 00d2a6ac */
  (*(code *)PTR_operator__010cc99c)(auStack_770,auStack_ba8);
                    /* try { // try from 00d2a67c to 00d2a69f has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_ba8);
  (*(code *)PTR_MImg_010c7d68)(auStack_bbc,0x5cd);
                    /* try { // try from 00d2a700 to 00d2a707 has its CatchHandler @ 00d2a748 */
  (*(code *)PTR_operator__010cc99c)(auStack_784,auStack_bbc);
                    /* try { // try from 00d2a718 to 00d2a73b has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_bbc);
  (*(code *)PTR_MImg_010c7d68)(auStack_bd0,0x5cd);
                    /* try { // try from 00d2a79c to 00d2a7a3 has its CatchHandler @ 00d2a7f8 */
  (*(code *)PTR_operator__010cc99c)(auStack_75c,auStack_bd0);
                    /* try { // try from 00d2a7b4 to 00d2a7bb has its CatchHandler @ 00d324c0 */
  (*(code *)PTR__MImg_010c8444)(auStack_bd0);
  uStack_a90 = 0;
  uStack_a8c = 0;
  uStack_a88 = 0xc4;
  uStack_a84 = 0x92;
  if (this[0x2b1] == (HomePageFrame)0x1) {
    (*(code *)PTR_set_010c9810)(aiStack_b08,0x40,0x41,0xc4,0x92);
    for (iStack_1a34 = 0; iStack_1a34 < 4; iStack_1a34 = iStack_1a34 + 1) {
                    /* try { // try from 00d2a874 to 00d2a87b has its CatchHandler @ 00d324c0 */
      iStack_b4 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2a8b0 to 00d2a8b7 has its CatchHandler @ 00d2a8d8 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_b4,piVar5,aiStack_b08,0,iStack_1a34 + 0x3d,1);
      iVar4 = iStack_b4;
      if (iStack_b4 == 0) {
                    /* try { // try from 00d2a930 to 00d2aea3 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                   0xc44);
                    /* WARNING: Subroutine does not return */
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_b4,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x40);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x28);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x28);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x28);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_b08[0] = aiStack_b08[0] + 0xe0;
      if (iStack_1a34 == 0) {
        (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2b4);
      }
    }
  }
  else {
    (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x230));
    (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x230),this + 0x2b4);
  }
  if (this[0x2b1] == (HomePageFrame)0x1) {
    (*(code *)PTR_set_010c9810)(aiStack_b08,0x3dc,0x41,0xc4,0x92);
    for (iStack_1a38 = 0; iStack_1a38 < 4; iStack_1a38 = iStack_1a38 + 1) {
      iStack_b8 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2aed8 to 00d2aedf has its CatchHandler @ 00d2af00 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_b8,piVar5,aiStack_b08,0,iStack_1a38 + 0x4e,1);
      iVar4 = iStack_b8;
      if (iStack_b8 == 0) {
                    /* try { // try from 00d2af58 to 00d2b517 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                   0xc8d);
                    /* WARNING: Subroutine does not return */
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_b8,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x4f);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x4e);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x4e);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x4e);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_b08[0] = aiStack_b08[0] + 0xe0;
      if (iStack_1a38 == 3) {
        (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2c4);
      }
    }
  }
  else {
    (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x260));
    (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x260),this + 0x2b4);
  }
  if (this[0x2b1] == (HomePageFrame)0x1) {
    iStack_c0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3d);
    if (iStack_c0 == 0) {
      iStack_bc = 0;
    }
    else {
      iStack_bc = (*(code *)PTR___dynamic_cast_010c6984)
                            (iStack_c0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_bc;
    iStack_c4 = *(int *)(*(int *)(iStack_bc + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_be4,0x82);
                    /* try { // try from 00d2b52c to 00d2b533 has its CatchHandler @ 00d2b58c */
    (*(code *)PTR_operator__010cc99c)(iStack_c4,auStack_be4);
                    /* try { // try from 00d2b544 to 00d2b57f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_be4);
    iStack_c8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_bf8,0x82);
                    /* try { // try from 00d2b5d8 to 00d2b5df has its CatchHandler @ 00d2b638 */
    (*(code *)PTR_operator__010cc99c)(iStack_c8,auStack_bf8);
                    /* try { // try from 00d2b5f0 to 00d2b62b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_bf8);
    iStack_cc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_c0c,0x82);
                    /* try { // try from 00d2b684 to 00d2b68b has its CatchHandler @ 00d2b6e4 */
    (*(code *)PTR_operator__010cc99c)(iStack_cc,auStack_c0c);
                    /* try { // try from 00d2b69c to 00d2b6d7 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c0c);
    iStack_d0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_c20,0x83);
                    /* try { // try from 00d2b730 to 00d2b737 has its CatchHandler @ 00d2b784 */
    (*(code *)PTR_operator__010cc99c)(iStack_d0,auStack_c20);
                    /* try { // try from 00d2b748 to 00d2b777 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c20);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118b);
                    /* try { // try from 00d2b7d0 to 00d2b853 has its CatchHandler @ 00d324c0 */
    iStack_d8 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3e);
    if (iStack_d8 == 0) {
      iStack_d4 = 0;
    }
    else {
      iStack_d4 = (*(code *)PTR___dynamic_cast_010c6984)
                            (iStack_d8,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_d4;
    iStack_dc = *(int *)(*(int *)(iStack_d4 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_c34,0x82);
                    /* try { // try from 00d2b868 to 00d2b86f has its CatchHandler @ 00d2b8c8 */
    (*(code *)PTR_operator__010cc99c)(iStack_dc,auStack_c34);
                    /* try { // try from 00d2b880 to 00d2b8bb has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c34);
    iStack_e0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_c48,0x82);
                    /* try { // try from 00d2b914 to 00d2b91b has its CatchHandler @ 00d2b974 */
    (*(code *)PTR_operator__010cc99c)(iStack_e0,auStack_c48);
                    /* try { // try from 00d2b92c to 00d2b967 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c48);
    iStack_e4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_c5c,0x82);
                    /* try { // try from 00d2b9c0 to 00d2b9c7 has its CatchHandler @ 00d2ba20 */
    (*(code *)PTR_operator__010cc99c)(iStack_e4,auStack_c5c);
                    /* try { // try from 00d2b9d8 to 00d2ba13 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c5c);
    iStack_e8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_c70,0x83);
                    /* try { // try from 00d2ba6c to 00d2ba73 has its CatchHandler @ 00d2bac0 */
    (*(code *)PTR_operator__010cc99c)(iStack_e8,auStack_c70);
                    /* try { // try from 00d2ba84 to 00d2bab3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c70);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118c);
                    /* try { // try from 00d2bb0c to 00d2bb8f has its CatchHandler @ 00d324c0 */
    iStack_f0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3f);
    if (iStack_f0 == 0) {
      iStack_ec = 0;
    }
    else {
      iStack_ec = (*(code *)PTR___dynamic_cast_010c6984)
                            (iStack_f0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_ec;
    iStack_f4 = *(int *)(*(int *)(iStack_ec + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_c84,0x82);
                    /* try { // try from 00d2bba4 to 00d2bbab has its CatchHandler @ 00d2bc04 */
    (*(code *)PTR_operator__010cc99c)(iStack_f4,auStack_c84);
                    /* try { // try from 00d2bbbc to 00d2bbf7 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c84);
    iStack_f8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_c98,0x82);
                    /* try { // try from 00d2bc50 to 00d2bc57 has its CatchHandler @ 00d2bcb0 */
    (*(code *)PTR_operator__010cc99c)(iStack_f8,auStack_c98);
                    /* try { // try from 00d2bc68 to 00d2bca3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_c98);
    iStack_fc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_cac,0x82);
                    /* try { // try from 00d2bcfc to 00d2bd03 has its CatchHandler @ 00d2bd5c */
    (*(code *)PTR_operator__010cc99c)(iStack_fc,auStack_cac);
                    /* try { // try from 00d2bd14 to 00d2bd4f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_cac);
    iStack_100 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_cc0,0x83);
                    /* try { // try from 00d2bda8 to 00d2bdaf has its CatchHandler @ 00d2bdfc */
    (*(code *)PTR_operator__010cc99c)(iStack_100,auStack_cc0);
                    /* try { // try from 00d2bdc0 to 00d2bdef has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_cc0);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x118d);
                    /* try { // try from 00d2be48 to 00d2bf13 has its CatchHandler @ 00d324c0 */
    iStack_108 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x40);
    if (iStack_108 == 0) {
      iStack_104 = 0;
    }
    else {
      iStack_104 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_108,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_104;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iStack_104 + 0x250) + 4));
    (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(*(int *)(iVar4 + 0x254) + 4));
    iStack_10c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_cd4,0x75);
                    /* try { // try from 00d2bf28 to 00d2bf2f has its CatchHandler @ 00d2bf88 */
    (*(code *)PTR_operator__010cc99c)(iStack_10c,auStack_cd4);
                    /* try { // try from 00d2bf40 to 00d2bf7b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_cd4);
    iStack_110 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_ce8,0x75);
                    /* try { // try from 00d2bfd4 to 00d2bfdb has its CatchHandler @ 00d2c034 */
    (*(code *)PTR_operator__010cc99c)(iStack_110,auStack_ce8);
                    /* try { // try from 00d2bfec to 00d2c027 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_ce8);
    iStack_114 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_cfc,0x75);
                    /* try { // try from 00d2c080 to 00d2c087 has its CatchHandler @ 00d2c0e0 */
    (*(code *)PTR_operator__010cc99c)(iStack_114,auStack_cfc);
                    /* try { // try from 00d2c098 to 00d2c0d3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_cfc);
    iStack_118 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_d10,0x76);
                    /* try { // try from 00d2c12c to 00d2c133 has its CatchHandler @ 00d2c180 */
    (*(code *)PTR_operator__010cc99c)(iStack_118,auStack_d10);
                    /* try { // try from 00d2c144 to 00d2c173 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d10);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd57);
  }
  if (this[0x2b1] == (HomePageFrame)0x1) {
    for (iStack_1a40 = 0; iStack_1a40 < 4; iStack_1a40 = iStack_1a40 + 1) {
                    /* try { // try from 00d2c1f8 to 00d2c277 has its CatchHandler @ 00d324c0 */
      iVar4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,iStack_1a40 + 0x4e);
      iVar8 = (*(code *)PTR_size_010cbda0)(this + 0x2a0);
      if (iStack_1a40 < iVar8) {
        (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a40);
        (*(code *)PTR_ostringstream_010c9ac8)(auStack_a80,0x10);
        puVar6 = (undefined2 *)(*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a40);
                    /* try { // try from 00d2c2b8 to 00d2c347 has its CatchHandler @ 00d2c3e4 */
        (*(code *)PTR_operator<<_010cb3b0)(auStack_a80,*puVar6);
        iVar8 = **(int **)(iVar4 + 0x250);
        iVar7 = (*(code *)PTR_operator___010cc62c)(this + 0x2a0,iStack_1a40);
        (*(code *)PTR_Set_010cb39c)(iVar8 + 0x170,iVar7 + 8);
        iStack_11c = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
        (*(code *)PTR_str_010c961c)(auStack_d14,auStack_a80);
                    /* try { // try from 00d2c35c to 00d2c363 has its CatchHandler @ 00d2c3a0 */
        (*(code *)PTR_Set_010cb39c)(iStack_11c,auStack_d14);
                    /* try { // try from 00d2c374 to 00d2c37b has its CatchHandler @ 00d2c3e4 */
        (*(code *)PTR__string_010c5070)(auStack_d14);
                    /* try { // try from 00d2c38c to 00d2c393 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__ostringstream_010cc6a8)(auStack_a80);
      }
      else {
                    /* try { // try from 00d2c43c to 00d2c443 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xe32);
        iStack_120 = *(int *)(*(int *)(iVar4 + 0x250) + 4) + 0x170;
        (*(code *)PTR_allocator_010c6920)(auStack_d1c);
                    /* try { // try from 00d2c494 to 00d2c49b has its CatchHandler @ 00d2c538 */
        (*(code *)PTR_string_010c4f9c)(auStack_d18,PTR_DAT_010c43ec + -0x15a0,auStack_d1c);
                    /* try { // try from 00d2c4b0 to 00d2c4b7 has its CatchHandler @ 00d2c4f8 */
        (*(code *)PTR_Set_010cb39c)(iStack_120,auStack_d18);
        puStack_124 = auStack_d18;
                    /* try { // try from 00d2c4cc to 00d2c4d3 has its CatchHandler @ 00d2c538 */
        (*(code *)PTR__string_010c5070)(puStack_124);
        (*(code *)PTR__allocator_010c4948)(auStack_d1c);
      }
                    /* try { // try from 00d2c580 to 00d2c5f7 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_Invalidate_010c4e28)(iVar4);
    }
    for (uStack_1a44 = 0; (int)uStack_1a44 < 3; uStack_1a44 = uStack_1a44 + 1) {
      iVar4 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,uStack_1a44 + 0x3d);
      (*(code *)(PTR_LAB_010c4418 + 0x5ec4))(auStack_af8);
                    /* try { // try from 00d2c614 to 00d2c647 has its CatchHandler @ 00d2c7f8 */
      iVar8 = (*(code *)PTR_GetPinnedChannel_010c4de4)(uStack_1a44 & 0xff,auStack_af8);
      if (iVar8 == 0) {
                    /* try { // try from 00d2c7a4 to 00d2c7c3 has its CatchHandler @ 00d2c7f8 */
        (*(code *)PTR_Set_010c61fc)
                  (**(int **)(iVar4 + 0x250) + 0x170,(uStack_1a44 & 0xffff) + 0x118b & 0xffff);
      }
      else {
        (*(code *)PTR_ostringstream_010c9ac8)(auStack_a80,0x10);
                    /* try { // try from 00d2c664 to 00d2c69f has its CatchHandler @ 00d2c73c */
        (*(code *)PTR_operator<<_010c4a9c)(auStack_a80,auStack_af0);
        iStack_128 = **(int **)(iVar4 + 0x250) + 0x170;
        (*(code *)PTR_str_010c961c)(auStack_d20,auStack_a80);
                    /* try { // try from 00d2c6b4 to 00d2c6bb has its CatchHandler @ 00d2c6f8 */
        (*(code *)PTR_Set_010cb39c)(iStack_128,auStack_d20);
                    /* try { // try from 00d2c6cc to 00d2c6d3 has its CatchHandler @ 00d2c73c */
        (*(code *)PTR__string_010c5070)(auStack_d20);
                    /* try { // try from 00d2c6e4 to 00d2c6eb has its CatchHandler @ 00d2c7f8 */
        (*(code *)PTR__ostringstream_010cc6a8)(auStack_a80);
      }
      (*(code *)PTR_Invalidate_010c4e28)(iVar4);
                    /* try { // try from 00d2c7d8 to 00d2c7df has its CatchHandler @ 00d324c0 */
      (*(code *)(PTR_LAB_010c4418 + 0x5dac))(auStack_af8);
    }
  }
                    /* try { // try from 00d2c84c to 00d2c90f has its CatchHandler @ 00d324c0 */
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar4 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar3);
  if (iVar4 == 1) {
    uVar3 = (*(code *)PTR_getInstance_010cd270)();
    iVar4 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar3);
    if (iVar4 == 1) {
      iStack_12c = 1;
      goto LAB_00d2c8c4;
    }
  }
  iStack_12c = 0;
LAB_00d2c8c4:
  if (iStack_12c == 0) {
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x234));
    (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x234),this + 0x2c4);
    (*(code *)PTR_set_010c9810)(aiStack_b08,0x40,0x13f,0xc4,0x92);
    for (iStack_1a54 = 0; iStack_1a54 < 5; iStack_1a54 = iStack_1a54 + 1) {
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
      if ((iVar4 == 0) && ((iStack_1a54 == 3 || (iStack_1a54 == 4)))) {
        iStack_1c0 = 1;
      }
      else {
        iStack_1c0 = 0;
      }
      if (iStack_1c0 == 0) {
        uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
        iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
        if ((iVar4 == 0) && (iStack_1a54 == 3)) {
          iStack_1c4 = 1;
        }
        else {
          iStack_1c4 = 0;
        }
        if (iStack_1c4 == 0) {
          iStack_1c8 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2f7b8 to 00d2f7bf has its CatchHandler @ 00d2f7e0 */
          (*(code *)PTR_TextImageMixer_010c9cfc)
                    (iStack_1c8,piVar5,aiStack_b08,0,iStack_1a54 + 0x45,1);
          iVar4 = iStack_1c8;
          if (iStack_1c8 == 0) {
                    /* try { // try from 00d2f838 to 00d2fd0b has its CatchHandler @ 00d324c0 */
            (*(code *)PTR_printf_010c9f10)
                      (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,
                       PTR_DAT_010c43ec + -0x14d0,0xe84);
                    /* WARNING: Subroutine does not return */
            (*(code *)PTR_abort_010cc6c0)();
          }
          (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_1c8,2);
          (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
          (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
          (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
          (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
          *(undefined1 *)(iVar4 + 0x39) = 1;
          *(undefined1 *)(iVar4 + 0x3a) = 1;
          (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9c) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0x9e) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa0) = uVar1;
          uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
          *(undefined2 *)(iVar4 + 0xa2) = uVar1;
          *(undefined1 *)(iVar4 + 0x38) = 1;
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
          (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x58) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
          *(undefined4 *)(iVar4 + 0x54) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x4c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x50) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 100) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x5c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x60) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x68) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x74) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x6c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x70) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
          *(undefined4 *)(iVar4 + 0x78) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x84) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x7c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x80) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
          *(undefined4 *)(iVar4 + 0x88) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x94) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x8c) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x90) = uVar3;
          uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
          *(undefined4 *)(iVar4 + 0x98) = uVar3;
          (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
          (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
          aiStack_b08[0] = aiStack_b08[0] + 0xe0;
          if (iStack_1a54 == 0) {
            (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2d4);
          }
        }
      }
    }
    iStack_1cc = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2fd3c to 00d2fd43 has its CatchHandler @ 00d2fd64 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_1cc,piVar5,aiStack_b08,0,0x52,1);
    iVar4 = iStack_1cc;
    if (iStack_1cc == 0) {
                    /* try { // try from 00d2fdbc to 00d3034f has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0xebc);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_1cc,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 == 0) {
      (*(code *)PTR_set_010c9810)(aiStack_b08,0x3dc,0x13f,0xc4,0x92);
    }
    else {
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
      if (iVar4 == 0) {
        (*(code *)PTR_set_010c9810)(aiStack_b08,0x4bc,0x13f,0xc4,0x92);
      }
      else {
        (*(code *)PTR_set_010c9810)(aiStack_b08,0x59c,0x13f,0xc4,0x92);
      }
    }
    for (iStack_1a58 = 0; iStack_1a58 < 2; iStack_1a58 = iStack_1a58 + 1) {
      iStack_1d0 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d30384 to 00d3038b has its CatchHandler @ 00d303ac */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_1d0,piVar5,aiStack_b08,0,iStack_1a58 + 0x4b,1);
      iVar4 = iStack_1d0;
      if (iStack_1d0 == 0) {
                    /* try { // try from 00d30404 to 00d3095f has its CatchHandler @ 00d324c0 */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                   0xf00);
                    /* WARNING: Subroutine does not return */
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_1d0,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x1ce);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x1cd);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x1cd);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x1cd);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_b08[0] = aiStack_b08[0] + 0xe0;
      if (iStack_1a58 == 1) {
        (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2e4);
      }
    }
    iStack_1d8 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x45);
    if (iStack_1d8 == 0) {
      iStack_1d4 = 0;
    }
    else {
      iStack_1d4 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_1d8,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_1d4;
    iStack_1dc = *(int *)(*(int *)(iStack_1d4 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_ec8,0x90);
                    /* try { // try from 00d30974 to 00d3097b has its CatchHandler @ 00d309d4 */
    (*(code *)PTR_operator__010cc99c)(iStack_1dc,auStack_ec8);
                    /* try { // try from 00d3098c to 00d309c7 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_ec8);
    iStack_1e0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_edc,0x90);
                    /* try { // try from 00d30a20 to 00d30a27 has its CatchHandler @ 00d30a80 */
    (*(code *)PTR_operator__010cc99c)(iStack_1e0,auStack_edc);
                    /* try { // try from 00d30a38 to 00d30a73 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_edc);
    iStack_1e4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_ef0,0x90);
                    /* try { // try from 00d30acc to 00d30ad3 has its CatchHandler @ 00d30b2c */
    (*(code *)PTR_operator__010cc99c)(iStack_1e4,auStack_ef0);
                    /* try { // try from 00d30ae4 to 00d30b1f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_ef0);
    iStack_1e8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_f04,0x91);
                    /* try { // try from 00d30b78 to 00d30b7f has its CatchHandler @ 00d30bcc */
    (*(code *)PTR_operator__010cc99c)(iStack_1e8,auStack_f04);
                    /* try { // try from 00d30b90 to 00d30bbf has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f04);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11df);
                    /* try { // try from 00d30c18 to 00d30c9b has its CatchHandler @ 00d324c0 */
    iStack_1f0 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x46);
    if (iStack_1f0 == 0) {
      iStack_1ec = 0;
    }
    else {
      iStack_1ec = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_1f0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_1ec;
    iStack_1f4 = *(int *)(*(int *)(iStack_1ec + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_f18,0x8e);
                    /* try { // try from 00d30cb0 to 00d30cb7 has its CatchHandler @ 00d30d10 */
    (*(code *)PTR_operator__010cc99c)(iStack_1f4,auStack_f18);
                    /* try { // try from 00d30cc8 to 00d30d03 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f18);
    iStack_1f8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_f2c,0x8e);
                    /* try { // try from 00d30d5c to 00d30d63 has its CatchHandler @ 00d30dbc */
    (*(code *)PTR_operator__010cc99c)(iStack_1f8,auStack_f2c);
                    /* try { // try from 00d30d74 to 00d30daf has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f2c);
    iStack_1fc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_f40,0x8e);
                    /* try { // try from 00d30e08 to 00d30e0f has its CatchHandler @ 00d30e68 */
    (*(code *)PTR_operator__010cc99c)(iStack_1fc,auStack_f40);
                    /* try { // try from 00d30e20 to 00d30e5b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f40);
    iStack_200 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_f54,0x8f);
                    /* try { // try from 00d30eb4 to 00d30ebb has its CatchHandler @ 00d30f08 */
    (*(code *)PTR_operator__010cc99c)(iStack_200,auStack_f54);
                    /* try { // try from 00d30ecc to 00d30efb has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f54);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd0e);
                    /* try { // try from 00d30f54 to 00d30fd7 has its CatchHandler @ 00d324c0 */
    iStack_208 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x47);
    if (iStack_208 == 0) {
      iStack_204 = 0;
    }
    else {
      iStack_204 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_208,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_204;
    iStack_20c = *(int *)(*(int *)(iStack_204 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_f68,0x8a);
                    /* try { // try from 00d30fec to 00d30ff3 has its CatchHandler @ 00d3104c */
    (*(code *)PTR_operator__010cc99c)(iStack_20c,auStack_f68);
                    /* try { // try from 00d31004 to 00d3103f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f68);
    iStack_210 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_f7c,0x8a);
                    /* try { // try from 00d31098 to 00d3109f has its CatchHandler @ 00d310f8 */
    (*(code *)PTR_operator__010cc99c)(iStack_210,auStack_f7c);
                    /* try { // try from 00d310b0 to 00d310eb has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f7c);
    iStack_214 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_f90,0x8a);
                    /* try { // try from 00d31144 to 00d3114b has its CatchHandler @ 00d311a4 */
    (*(code *)PTR_operator__010cc99c)(iStack_214,auStack_f90);
                    /* try { // try from 00d3115c to 00d31197 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_f90);
    iStack_218 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_fa4,0x8b);
                    /* try { // try from 00d311f0 to 00d311f7 has its CatchHandler @ 00d31244 */
    (*(code *)PTR_operator__010cc99c)(iStack_218,auStack_fa4);
                    /* try { // try from 00d31208 to 00d31237 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_fa4);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf16);
                    /* try { // try from 00d31284 to 00d3137b has its CatchHandler @ 00d324c0 */
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 != 0) {
      uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar4 = (*(code *)PTR_ArTvConf_GetUsbRecording_010c88d8)(uVar3);
      if (iVar4 != 0) {
        iStack_220 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x48);
        if (iStack_220 == 0) {
          iStack_21c = 0;
        }
        else {
          iStack_21c = (*(code *)PTR___dynamic_cast_010c6984)
                                 (iStack_220,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
        }
        iVar4 = iStack_21c;
        iStack_224 = *(int *)(*(int *)(iStack_21c + 0x254) + 4) + 0x29c;
        (*(code *)PTR_MImg_010c7d68)(auStack_fb8,0x84);
                    /* try { // try from 00d31390 to 00d31397 has its CatchHandler @ 00d313f0 */
        (*(code *)PTR_operator__010cc99c)(iStack_224,auStack_fb8);
                    /* try { // try from 00d313a8 to 00d313e3 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__MImg_010c8444)(auStack_fb8);
        iStack_228 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
        (*(code *)PTR_MImg_010c7d68)(auStack_fcc,0x84);
                    /* try { // try from 00d3143c to 00d31443 has its CatchHandler @ 00d3149c */
        (*(code *)PTR_operator__010cc99c)(iStack_228,auStack_fcc);
                    /* try { // try from 00d31454 to 00d3148f has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__MImg_010c8444)(auStack_fcc);
        iStack_22c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
        (*(code *)PTR_MImg_010c7d68)(auStack_fe0,0x84);
                    /* try { // try from 00d314e8 to 00d314ef has its CatchHandler @ 00d31548 */
        (*(code *)PTR_operator__010cc99c)(iStack_22c,auStack_fe0);
                    /* try { // try from 00d31500 to 00d3153b has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__MImg_010c8444)(auStack_fe0);
        iStack_230 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
        (*(code *)PTR_MImg_010c7d68)(auStack_ff4,0x85);
                    /* try { // try from 00d31594 to 00d3159b has its CatchHandler @ 00d315e8 */
        (*(code *)PTR_operator__010cc99c)(iStack_230,auStack_ff4);
                    /* try { // try from 00d315ac to 00d315db has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__MImg_010c8444)(auStack_ff4);
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x1196);
      }
                    /* try { // try from 00d31634 to 00d316b7 has its CatchHandler @ 00d324c0 */
      iStack_238 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x49);
      if (iStack_238 == 0) {
        iStack_234 = 0;
      }
      else {
        iStack_234 = (*(code *)PTR___dynamic_cast_010c6984)
                               (iStack_238,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
      }
      iVar4 = iStack_234;
      iStack_23c = *(int *)(*(int *)(iStack_234 + 0x254) + 4) + 0x29c;
      (*(code *)PTR_MImg_010c7d68)(auStack_1008,0x78);
                    /* try { // try from 00d316cc to 00d316d3 has its CatchHandler @ 00d3172c */
      (*(code *)PTR_operator__010cc99c)(iStack_23c,auStack_1008);
                    /* try { // try from 00d316e4 to 00d3171f has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_1008);
      iStack_240 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
      (*(code *)PTR_MImg_010c7d68)(auStack_101c,0x78);
                    /* try { // try from 00d31778 to 00d3177f has its CatchHandler @ 00d317d8 */
      (*(code *)PTR_operator__010cc99c)(iStack_240,auStack_101c);
                    /* try { // try from 00d31790 to 00d317cb has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_101c);
      iStack_244 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
      (*(code *)PTR_MImg_010c7d68)(auStack_1030,0x78);
                    /* try { // try from 00d31824 to 00d3182b has its CatchHandler @ 00d31884 */
      (*(code *)PTR_operator__010cc99c)(iStack_244,auStack_1030);
                    /* try { // try from 00d3183c to 00d31877 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_1030);
      iStack_248 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
      (*(code *)PTR_MImg_010c7d68)(auStack_1044,0x79);
                    /* try { // try from 00d318d0 to 00d318d7 has its CatchHandler @ 00d31924 */
      (*(code *)PTR_operator__010cc99c)(iStack_248,auStack_1044);
                    /* try { // try from 00d318e8 to 00d31917 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_1044);
      (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x114e);
    }
                    /* try { // try from 00d31970 to 00d319f3 has its CatchHandler @ 00d324c0 */
    iStack_250 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4b);
    if (iStack_250 == 0) {
      iStack_24c = 0;
    }
    else {
      iStack_24c = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_250,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_24c;
    iStack_254 = *(int *)(*(int *)(iStack_24c + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_1058,0x8c);
                    /* try { // try from 00d31a08 to 00d31a0f has its CatchHandler @ 00d31a68 */
    (*(code *)PTR_operator__010cc99c)(iStack_254,auStack_1058);
                    /* try { // try from 00d31a20 to 00d31a5b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_1058);
    iStack_258 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_106c,0x8c);
                    /* try { // try from 00d31ab4 to 00d31abb has its CatchHandler @ 00d31b14 */
    (*(code *)PTR_operator__010cc99c)(iStack_258,auStack_106c);
                    /* try { // try from 00d31acc to 00d31b07 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_106c);
    iStack_25c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_1080,0x8c);
                    /* try { // try from 00d31b60 to 00d31b67 has its CatchHandler @ 00d31bc0 */
    (*(code *)PTR_operator__010cc99c)(iStack_25c,auStack_1080);
                    /* try { // try from 00d31b78 to 00d31bb3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_1080);
    iStack_260 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_1094,0x8d);
                    /* try { // try from 00d31c0c to 00d31c13 has its CatchHandler @ 00d31c60 */
    (*(code *)PTR_operator__010cc99c)(iStack_260,auStack_1094);
                    /* try { // try from 00d31c24 to 00d31c53 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_1094);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11da);
                    /* try { // try from 00d31cac to 00d31d2f has its CatchHandler @ 00d324c0 */
    iStack_268 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4c);
    if (iStack_268 == 0) {
      iStack_264 = 0;
    }
    else {
      iStack_264 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_268,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_264;
    iStack_26c = *(int *)(*(int *)(iStack_264 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_10a8,0x88);
                    /* try { // try from 00d31d44 to 00d31d4b has its CatchHandler @ 00d31da4 */
    (*(code *)PTR_operator__010cc99c)(iStack_26c,auStack_10a8);
                    /* try { // try from 00d31d5c to 00d31d97 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_10a8);
    iStack_270 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_10bc,0x88);
                    /* try { // try from 00d31df0 to 00d31df7 has its CatchHandler @ 00d31e50 */
    (*(code *)PTR_operator__010cc99c)(iStack_270,auStack_10bc);
                    /* try { // try from 00d31e08 to 00d31e43 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_10bc);
    iStack_274 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_10d0,0x88);
                    /* try { // try from 00d31e9c to 00d31ea3 has its CatchHandler @ 00d31efc */
    (*(code *)PTR_operator__010cc99c)(iStack_274,auStack_10d0);
                    /* try { // try from 00d31eb4 to 00d31eef has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_10d0);
    iStack_278 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_10e4,0x89);
                    /* try { // try from 00d31f48 to 00d31f4f has its CatchHandler @ 00d31f9c */
    (*(code *)PTR_operator__010cc99c)(iStack_278,auStack_10e4);
                    /* try { // try from 00d31f60 to 00d31f8f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_10e4);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf49);
                    /* try { // try from 00d31fe8 to 00d3206b has its CatchHandler @ 00d324c0 */
    iStack_280 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x52);
    if (iStack_280 == 0) {
      iStack_27c = 0;
    }
    else {
      iStack_27c = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_280,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_27c;
    iStack_284 = *(int *)(*(int *)(iStack_27c + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_10f8,0x90);
                    /* try { // try from 00d32080 to 00d32087 has its CatchHandler @ 00d320e0 */
    (*(code *)PTR_operator__010cc99c)(iStack_284,auStack_10f8);
                    /* try { // try from 00d32098 to 00d320d3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_10f8);
    iStack_288 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_110c,0x90);
                    /* try { // try from 00d3212c to 00d32133 has its CatchHandler @ 00d3218c */
    (*(code *)PTR_operator__010cc99c)(iStack_288,auStack_110c);
                    /* try { // try from 00d32144 to 00d3217f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_110c);
    iStack_28c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_1120,0x90);
                    /* try { // try from 00d321d8 to 00d321df has its CatchHandler @ 00d32238 */
    (*(code *)PTR_operator__010cc99c)(iStack_28c,auStack_1120);
                    /* try { // try from 00d321f0 to 00d3222b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_1120);
    iStack_290 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_1134,0x91);
                    /* try { // try from 00d32284 to 00d3228b has its CatchHandler @ 00d322c0 */
    (*(code *)PTR_operator__010cc99c)(iStack_290,auStack_1134);
                    /* try { // try from 00d3229c to 00d322b3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_1134);
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
                    /* try { // try from 00d32304 to 00d323ef has its CatchHandler @ 00d324c0 */
    iVar8 = (*(code *)PTR_GetFavSource_010c8200)(uVar3);
    if (iVar8 == 0x2a) {
      (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x110a);
    }
    else {
      sVar2 = (*(code *)PTR_ConvertSourceTypeToIndex_010c9fa4)(this,iVar8);
      if (sVar2 == 0) {
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xb0a);
      }
      else {
        iStack_294 = **(int **)(iVar4 + 0x250) + 0x170;
        uVar3 = (*(code *)PTR_getInstance_010c67ec)();
        (*(code *)PTR_GetSourceName_010cadc8)(auStack_1138,uVar3,sVar2);
                    /* try { // try from 00d32404 to 00d3240b has its CatchHandler @ 00d32430 */
        (*(code *)PTR_Set_010cb39c)(iStack_294,auStack_1138);
                    /* try { // try from 00d3241c to 00d32423 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__string_010c5070)(auStack_1138);
      }
    }
                    /* try { // try from 00d32484 to 00d324a3 has its CatchHandler @ 00d324c0 */
    (**(code **)(*piVar5 + 0x48))(piVar5);
    (*(code *)PTR_Invalidate_010c4e28)(piVar5);
  }
  else {
    (*(code *)PTR_set_010c9810)(aiStack_b08,0x40,0x13f,0xc4,0x92);
    iStack_130 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2c940 to 00d2c947 has its CatchHandler @ 00d2c968 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_130,piVar5,aiStack_b08,0,0x4d,1);
    iVar4 = iStack_130;
    if (iStack_130 == 0) {
                    /* try { // try from 00d2c9c0 to 00d2ce6b has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0xd1f);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_130,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2d4);
    iStack_134 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2ce9c to 00d2cea3 has its CatchHandler @ 00d2cec4 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_134,piVar5,aiStack_b08,0,0x46,1);
    iVar4 = iStack_134;
    if (iStack_134 == 0) {
                    /* try { // try from 00d2cf1c to 00d2d3d7 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0xd57);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_134,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 != 0) {
      iStack_138 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2d408 to 00d2d40f has its CatchHandler @ 00d2d430 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_138,piVar5,aiStack_b08,0,0x49,1);
      iVar4 = iStack_138;
      if (iStack_138 == 0) {
                    /* try { // try from 00d2d488 to 00d2d90f has its CatchHandler @ 00d324c0 */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                   0xd8f);
                    /* WARNING: Subroutine does not return */
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_138,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
      (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
      (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
      *(undefined1 *)(iVar4 + 0x39) = 1;
      *(undefined1 *)(iVar4 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar4 + 0xa2) = uVar1;
      *(undefined1 *)(iVar4 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
      (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar4 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar4 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar4 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
      (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
      aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    }
    iStack_13c = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2d940 to 00d2d947 has its CatchHandler @ 00d2d968 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_13c,piVar5,aiStack_b08,0,0x52,1);
    iVar4 = iStack_13c;
    if (iStack_13c == 0) {
                    /* try { // try from 00d2d9c0 to 00d2dedf has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0xdc5);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_13c,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x358);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x359);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x359);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 == 0) {
      (*(code *)PTR_set_010c9810)(aiStack_b08,0x2fc,0x13f,0xc4,0x92);
    }
    else {
      (*(code *)PTR_set_010c9810)(aiStack_b08,0x3dc,0x13f,0xc4,0x92);
    }
    iStack_140 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d2df10 to 00d2df17 has its CatchHandler @ 00d2df38 */
    (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_140,piVar5,aiStack_b08,0,0x4c,1);
    iVar4 = iStack_140;
    if (iStack_140 == 0) {
                    /* try { // try from 00d2df90 to 00d2e4bf has its CatchHandler @ 00d324c0 */
      (*(code *)PTR_printf_010c9f10)
                (PTR_DAT_010c43ec + -0x15d0,PTR_DAT_010c43ec + -0x15b8,PTR_DAT_010c43ec + -0x14d0,
                 0xe04);
                    /* WARNING: Subroutine does not return */
      (*(code *)PTR_abort_010cc6c0)();
    }
    (*(code *)PTR_SetTextAmount_010cc6d4)(iStack_140,2);
    (*(code *)PTR_SetImageAmount_010c8ad0)(iVar4,2);
    (*(code *)PTR_SetTextContent_010cc794)(iVar4,auStack_9cc);
    (*(code *)PTR_SetImageContent_010c848c)(iVar4,auStack_88c);
    (*(code *)PTR_SetLayOut_010cd200)(iVar4,&uStack_ac0,&uStack_aa0);
    *(undefined1 *)(iVar4 + 0x39) = 1;
    *(undefined1 *)(iVar4 + 0x3a) = 1;
    (*(code *)PTR_SetFlag_010cb13c)(iVar4,0x10,1);
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9c) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0x9e) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa0) = uVar1;
    uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
    *(undefined2 *)(iVar4 + 0xa2) = uVar1;
    *(undefined1 *)(iVar4 + 0x38) = 1;
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xe0,0x1ce);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xf4,0x1cd);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xb8,0x1cd);
    (*(code *)PTR_Set_010cba00)(iVar4 + 0xcc,0x1cd);
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x58) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
    *(undefined4 *)(iVar4 + 0x54) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x50) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 100) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x5c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x60) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x68) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x74) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x6c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x70) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(iVar4 + 0x78) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x84) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x7c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x80) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    *(undefined4 *)(iVar4 + 0x88) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x94) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x8c) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(iVar4 + 0x98) = uVar3;
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(iVar4 + 0x250) + 4));
    (**(code **)(*piVar5 + 0x34))(piVar5,iVar4);
    aiStack_b08[0] = aiStack_b08[0] + 0xe0;
    (*(code *)PTR_GetRect_010c5804)(iVar4,this + 0x2e4);
    iStack_148 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4d);
    if (iStack_148 == 0) {
      iStack_144 = 0;
    }
    else {
      iStack_144 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_148,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_144;
    iStack_14c = *(int *)(*(int *)(iStack_144 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_d34,0x92);
                    /* try { // try from 00d2e4d4 to 00d2e4db has its CatchHandler @ 00d2e534 */
    (*(code *)PTR_operator__010cc99c)(iStack_14c,auStack_d34);
                    /* try { // try from 00d2e4ec to 00d2e527 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d34);
    iStack_150 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_d48,0x92);
                    /* try { // try from 00d2e580 to 00d2e587 has its CatchHandler @ 00d2e5e0 */
    (*(code *)PTR_operator__010cc99c)(iStack_150,auStack_d48);
                    /* try { // try from 00d2e598 to 00d2e5d3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d48);
    iStack_154 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_d5c,0x92);
                    /* try { // try from 00d2e62c to 00d2e633 has its CatchHandler @ 00d2e68c */
    (*(code *)PTR_operator__010cc99c)(iStack_154,auStack_d5c);
                    /* try { // try from 00d2e644 to 00d2e67f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d5c);
    iStack_158 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_d70,0x93);
                    /* try { // try from 00d2e6d8 to 00d2e6df has its CatchHandler @ 00d2e72c */
    (*(code *)PTR_operator__010cc99c)(iStack_158,auStack_d70);
                    /* try { // try from 00d2e6f0 to 00d2e71f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d70);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x11e0);
                    /* try { // try from 00d2e778 to 00d2e7fb has its CatchHandler @ 00d324c0 */
    iStack_160 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x52);
    if (iStack_160 == 0) {
      iStack_15c = 0;
    }
    else {
      iStack_15c = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_160,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_15c;
    iStack_164 = *(int *)(*(int *)(iStack_15c + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_d84,0x90);
                    /* try { // try from 00d2e810 to 00d2e817 has its CatchHandler @ 00d2e870 */
    (*(code *)PTR_operator__010cc99c)(iStack_164,auStack_d84);
                    /* try { // try from 00d2e828 to 00d2e863 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d84);
    iStack_168 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_d98,0x90);
                    /* try { // try from 00d2e8bc to 00d2e8c3 has its CatchHandler @ 00d2e91c */
    (*(code *)PTR_operator__010cc99c)(iStack_168,auStack_d98);
                    /* try { // try from 00d2e8d4 to 00d2e90f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_d98);
    iStack_16c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_dac,0x90);
                    /* try { // try from 00d2e968 to 00d2e96f has its CatchHandler @ 00d2e9c8 */
    (*(code *)PTR_operator__010cc99c)(iStack_16c,auStack_dac);
                    /* try { // try from 00d2e980 to 00d2e9bb has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_dac);
    iStack_170 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_dc0,0x91);
                    /* try { // try from 00d2ea14 to 00d2ea1b has its CatchHandler @ 00d2ea50 */
    (*(code *)PTR_operator__010cc99c)(iStack_170,auStack_dc0);
                    /* try { // try from 00d2ea2c to 00d2ea43 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_dc0);
    uVar3 = (*(code *)PTR_getInstance_010c67ec)();
                    /* try { // try from 00d2ea94 to 00d2eb7f has its CatchHandler @ 00d324c0 */
    iVar8 = (*(code *)PTR_GetFavSource_010c8200)(uVar3);
    if (iVar8 == 0x2a) {
      (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x110a);
    }
    else {
      sVar2 = (*(code *)PTR_ConvertSourceTypeToIndex_010c9fa4)(this,iVar8);
      if (sVar2 == 0) {
        (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xb0a);
      }
      else {
        iStack_174 = **(int **)(iVar4 + 0x250) + 0x170;
        uVar3 = (*(code *)PTR_getInstance_010c67ec)();
        (*(code *)PTR_GetSourceName_010cadc8)(auStack_dc4,uVar3,sVar2);
                    /* try { // try from 00d2eb94 to 00d2eb9b has its CatchHandler @ 00d2ebc0 */
        (*(code *)PTR_Set_010cb39c)(iStack_174,auStack_dc4);
                    /* try { // try from 00d2ebac to 00d2ebb3 has its CatchHandler @ 00d324c0 */
        (*(code *)PTR__string_010c5070)(auStack_dc4);
      }
    }
                    /* try { // try from 00d2ec0c to 00d2ec8f has its CatchHandler @ 00d324c0 */
    iStack_17c = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x46);
    if (iStack_17c == 0) {
      iStack_178 = 0;
    }
    else {
      iStack_178 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_17c,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_178;
    iStack_180 = *(int *)(*(int *)(iStack_178 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_dd8,0x8e);
                    /* try { // try from 00d2eca4 to 00d2ecab has its CatchHandler @ 00d2ed04 */
    (*(code *)PTR_operator__010cc99c)(iStack_180,auStack_dd8);
                    /* try { // try from 00d2ecbc to 00d2ecf7 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_dd8);
    iStack_184 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_dec,0x8e);
                    /* try { // try from 00d2ed50 to 00d2ed57 has its CatchHandler @ 00d2edb0 */
    (*(code *)PTR_operator__010cc99c)(iStack_184,auStack_dec);
                    /* try { // try from 00d2ed68 to 00d2eda3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_dec);
    iStack_188 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_e00,0x8e);
                    /* try { // try from 00d2edfc to 00d2ee03 has its CatchHandler @ 00d2ee5c */
    (*(code *)PTR_operator__010cc99c)(iStack_188,auStack_e00);
                    /* try { // try from 00d2ee14 to 00d2ee4f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_e00);
    iStack_18c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_e14,0x8f);
                    /* try { // try from 00d2eea8 to 00d2eeaf has its CatchHandler @ 00d2eefc */
    (*(code *)PTR_operator__010cc99c)(iStack_18c,auStack_e14);
                    /* try { // try from 00d2eec0 to 00d2eeef has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_e14);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xd0e);
                    /* try { // try from 00d2ef3c to 00d2efff has its CatchHandler @ 00d324c0 */
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar4 = (*(code *)PTR_ArSourceConf_GetUsbAvailable_010c9bbc)(uVar3);
    if (iVar4 != 0) {
      iStack_194 = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x49);
      if (iStack_194 == 0) {
        iStack_190 = 0;
      }
      else {
        iStack_190 = (*(code *)PTR___dynamic_cast_010c6984)
                               (iStack_194,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
      }
      iVar4 = iStack_190;
      iStack_198 = *(int *)(*(int *)(iStack_190 + 0x254) + 4) + 0x29c;
      (*(code *)PTR_MImg_010c7d68)(auStack_e28,0x78);
                    /* try { // try from 00d2f014 to 00d2f01b has its CatchHandler @ 00d2f074 */
      (*(code *)PTR_operator__010cc99c)(iStack_198,auStack_e28);
                    /* try { // try from 00d2f02c to 00d2f067 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_e28);
      iStack_19c = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
      (*(code *)PTR_MImg_010c7d68)(auStack_e3c,0x78);
                    /* try { // try from 00d2f0c0 to 00d2f0c7 has its CatchHandler @ 00d2f120 */
      (*(code *)PTR_operator__010cc99c)(iStack_19c,auStack_e3c);
                    /* try { // try from 00d2f0d8 to 00d2f113 has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_e3c);
      iStack_1a0 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
      (*(code *)PTR_MImg_010c7d68)(auStack_e50,0x78);
                    /* try { // try from 00d2f16c to 00d2f173 has its CatchHandler @ 00d2f1cc */
      (*(code *)PTR_operator__010cc99c)(iStack_1a0,auStack_e50);
                    /* try { // try from 00d2f184 to 00d2f1bf has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_e50);
      iStack_1a4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
      (*(code *)PTR_MImg_010c7d68)(auStack_e64,0x79);
                    /* try { // try from 00d2f218 to 00d2f21f has its CatchHandler @ 00d2f26c */
      (*(code *)PTR_operator__010cc99c)(iStack_1a4,auStack_e64);
                    /* try { // try from 00d2f230 to 00d2f25f has its CatchHandler @ 00d324c0 */
      (*(code *)PTR__MImg_010c8444)(auStack_e64);
      (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0x114e);
    }
                    /* try { // try from 00d2f2b8 to 00d2f33b has its CatchHandler @ 00d324c0 */
    iStack_1ac = (*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4c);
    if (iStack_1ac == 0) {
      iStack_1a8 = 0;
    }
    else {
      iStack_1a8 = (*(code *)PTR___dynamic_cast_010c6984)
                             (iStack_1ac,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar4 = iStack_1a8;
    iStack_1b0 = *(int *)(*(int *)(iStack_1a8 + 0x254) + 4) + 0x29c;
    (*(code *)PTR_MImg_010c7d68)(auStack_e78,0x88);
                    /* try { // try from 00d2f350 to 00d2f357 has its CatchHandler @ 00d2f3b0 */
    (*(code *)PTR_operator__010cc99c)(iStack_1b0,auStack_e78);
                    /* try { // try from 00d2f368 to 00d2f3a3 has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_e78);
    iStack_1b4 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x274;
    (*(code *)PTR_MImg_010c7d68)(auStack_e8c,0x88);
                    /* try { // try from 00d2f3fc to 00d2f403 has its CatchHandler @ 00d2f45c */
    (*(code *)PTR_operator__010cc99c)(iStack_1b4,auStack_e8c);
                    /* try { // try from 00d2f414 to 00d2f44f has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_e8c);
    iStack_1b8 = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x260;
    (*(code *)PTR_MImg_010c7d68)(auStack_ea0,0x88);
                    /* try { // try from 00d2f4a8 to 00d2f4af has its CatchHandler @ 00d2f508 */
    (*(code *)PTR_operator__010cc99c)(iStack_1b8,auStack_ea0);
                    /* try { // try from 00d2f4c0 to 00d2f4fb has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_ea0);
    iStack_1bc = *(int *)(*(int *)(iVar4 + 0x254) + 4) + 0x288;
    (*(code *)PTR_MImg_010c7d68)(auStack_eb4,0x89);
                    /* try { // try from 00d2f554 to 00d2f55b has its CatchHandler @ 00d2f5a8 */
    (*(code *)PTR_operator__010cc99c)(iStack_1bc,auStack_eb4);
                    /* try { // try from 00d2f56c to 00d2f59b has its CatchHandler @ 00d324c0 */
    (*(code *)PTR__MImg_010c8444)(auStack_eb4);
    (*(code *)PTR_Set_010c61fc)(**(int **)(iVar4 + 0x250) + 0x170,0xf49);
                    /* try { // try from 00d2f5fc to 00d2f783 has its CatchHandler @ 00d324c0 */
    (**(code **)(*piVar5 + 0x48))(piVar5);
    (*(code *)PTR_Invalidate_010c4e28)(piVar5);
  }
  puStack_650 = auStack_6e4;
  while (puStack_650 != auStack_88c) {
    puStack_650 = puStack_650 + -0xd4;
                    /* try { // try from 00d32564 to 00d3256b has its CatchHandler @ 00d3258c */
    (*(code *)(PTR_LAB_010c441c + -0x71f8))(puStack_650);
  }
  puStack_654 = auStack_88c;
  while (puStack_654 != auStack_9cc) {
    puStack_654 = puStack_654 + -0xa0;
    (*(code *)(PTR_LAB_010c4418 + 0x5e04))(puStack_654);
  }
  return;
}

