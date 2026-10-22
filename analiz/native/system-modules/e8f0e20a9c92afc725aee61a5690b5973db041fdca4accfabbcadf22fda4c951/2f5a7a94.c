
void msVifInitial(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  
  puVar4 = PTR_DAT_2f5bda48;
  if (*(int *)(PTR_DAT_2f5bda48 + -0x25cc) == 0) {
    return;
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12200,0,0x7f);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12140,0,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12180,0,1);
  puVar6 = PTR_g_ucVifStatusStep_2f5bdc34;
  iVar8 = *(int *)(puVar4 + -0x25d0);
  *PTR_g_VifZeroDetFlag_2f5bdaf4 = 0;
  puVar5 = PTR_AGC_Change_Index_2f5bdafc;
  *puVar6 = 0;
  puVar10 = PTR_g_ucVifSoundSystemType_2f5bdba4;
  *puVar5 = 0;
  *(undefined1 *)(iVar8 + 0x250dc) = 4;
  puVar6 = PTR_g_bCheckModulationType_2f5bdaf8;
  puVar5 = PTR_g_bCheckIFFreq_2f5bda84;
  if ((byte)(*puVar10 - 9) < 2) {
    cVar2 = *puVar10;
    *PTR_g_bCheckModulationType_2f5bdaf8 = 1;
    *puVar5 = cVar2 != '\t';
  }
  else {
    *PTR_g_bCheckModulationType_2f5bdaf8 = 0;
    *puVar5 = 0;
  }
  if (*puVar6 == '\x01') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12202,0xf,0xf);
    if (*puVar6 == '\x01') goto LAB_2f5a9454;
LAB_2f5a7bd0:
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12306,0);
    puVar10 = PTR_VIFInitialIn_inst_2f5bdbb0;
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12307,0xc,0xf);
    uVar1 = puVar10[0xc];
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12202,0,0xf);
    if (*puVar6 != '\x01') goto LAB_2f5a7bd0;
LAB_2f5a9454:
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12306,0);
    puVar10 = PTR_VIFInitialIn_inst_2f5bdbb0;
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12307,0xb,0xf);
    uVar1 = puVar10[0xd];
  }
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12308,uVar1);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12300,4,0xc);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12302,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12303,0);
  if (*PTR_bEnableUsrNonSteadyAgcK_2f5bdbcc == '\0') {
    if (puVar10[0xc2] == '\x01') {
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1230a,3,7);
    }
    else {
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1230a,2,7);
    }
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1230a,*PTR_u8UsrNonSteadyAgcK_2f5bdb4c,7);
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1230c,0,3);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12318,puVar10[4]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12319,*(ushort *)(puVar10 + 4) >> 8);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12316,puVar10[6]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12317,*(ushort *)(puVar10 + 6) >> 8);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12313,0,0xf);
  if (puVar10[0xc2] == '\x01') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12315,0,0x1f);
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12315,0x1f,0x1f);
  }
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12442,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12443,0x80);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12440,1,4);
  cVar2 = puVar10[3];
  if (((byte)(cVar2 - 2U) < 2) || (cVar2 == '\x06')) {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12440,1,1);
    if (puVar10[3] == '\x03') goto LAB_2f5a9040;
LAB_2f5a7da8:
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x123bb,1,1);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x122f4,0,0x10);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,1,1);
  }
  else {
    if (cVar2 != '\x03') goto LAB_2f5a7da8;
LAB_2f5a9040:
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x123bb,0,1);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x122f4,0,0x10);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,0,1);
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12301,1,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12301,0,8);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12301,0,0x10);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12346,puVar10[4]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12347,(int)(*(ushort *)(puVar10 + 4) - 0x1000) >> 8 & 0xff);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12348,puVar10[10] + -0x14);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12349,puVar10[0xb]);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12300,1,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12214,0x16);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12216,0xff);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12217,0x3f,0x3f);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221a,0x41);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221b,0xc);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221c,0xe9);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221d,0xb);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221e,0x58);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1221f,0);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,1,1);
  puVar7 = PTR_VIFInitialIn_inst_2f5bdbb0;
  if (puVar10[0xc2] == '\x02') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12229,0,0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12228,0,0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12228,0,0xf0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222a,0,0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222a,0,0xf0);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,0,0x40);
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12229,PTR_VIFInitialIn_inst_2f5bdbb0[0x14],0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12228,puVar7[0x15],0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12228,((byte)puVar7[0x16] & 0xf) << 4,0xf0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222a,puVar7[0x17],0xf);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222a,((byte)puVar7[0x18] & 0xf) << 4,0xf0);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,1,0x40);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x122f4,1,2);
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12223,0,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12222,0,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12222,0,0xf0);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12464,1,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12206,0,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12221,0,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12221,1,2);
  if (puVar10[0x2d] == '\0') {
    (*(code *)PTR_msWriteRegsTbl_2f5bdc58)(PTR_VIF_CR_IIR_LPF1_2f5bda8c);
  }
  else {
    (*(code *)PTR_msWriteRegsTbl_2f5bdc58)(PTR_VIF_CR_IIR_LPF2_2f5bdb38);
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,puVar10[0x2c],0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,puVar10[0x2d],2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12206,puVar10[0x2a],1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12220,puVar10[0x2b],4);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1222c,puVar10[0x1c]);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222d,*(ushort *)(puVar10 + 0x1c) >> 8,3);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12234,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12235,0x40);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12236,0,0xf);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12230,puVar10[0x20]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12231,puVar10[0x21]);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12232,puVar10[0x22],0xf);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12208,puVar10[0x1e]);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12209,*(ushort *)(puVar10 + 0x1e) >> 8,0x3f);
  if (puVar10[0xc2] != '\0') goto LAB_2f5a82d8;
  if (*PTR_g_VifShiftClk_2f5bda94 == '\x01') {
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12224,0x6d);
    uVar9 = 0xdb;
LAB_2f5a829c:
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12225,uVar9);
    uVar9 = 0x16;
  }
  else {
    if (*PTR_g_VifShiftClk_2f5bda94 != '\x02') {
      (*(code *)PTR_msWriteByte_2f5bdb30)(0x12224,0xe3);
      uVar9 = 0x38;
      goto LAB_2f5a829c;
    }
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12224,0x22);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12225,0x9f);
    uVar9 = 0x15;
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12226,uVar9,0x1f);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234b,0,1);
LAB_2f5a82d8:
  if (puVar10[2] == '\x02') {
    if (*puVar5 == '\0') {
      (*(code *)PTR_msWriteByte_2f5bdb30)(0x1222e,0xb3);
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222f,2,0xf);
    }
    else {
      (*(code *)PTR_msWriteByte_2f5bdb30)(0x1222e,0x4d);
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222f,0xd,0xf);
    }
  }
  else if (puVar10[2] == '\x01') {
    if (*puVar5 == '\0') {
      (*(code *)PTR_msWriteByte_2f5bdb30)(0x1222e,0x60);
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222f,3,0xf);
    }
    else {
      (*(code *)PTR_msWriteByte_2f5bdb30)(0x1222e,0xa0);
      (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1222f,0xc,0xf);
    }
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123e1,1,0x20);
  if (puVar10[0x8b] != '\0') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12398,8,0xc);
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12398,1,3);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1235e,0,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220b,0,0x80);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12280,1,0x80);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1235c,1,0x80);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1235e,1,0x40);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1235e,1,0x80);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,0,4);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,0,8);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,0,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,0,0x20);
  if (puVar10[0xc2] == '\x01') {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x122f4,1,0x20);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,0,2);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,1,4);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,1,8);
    if ((*(byte *)(*(int *)(puVar4 + -0x25d0) + 0x24695) & 1) != 0) {
      (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,1,1);
    }
  }
  else {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x1234a,0,2);
  }
  if ((puVar10[0x8c] & 2) == 0) {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12400,0,8);
  }
  else {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12400,1,8);
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12400,0,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12403,1,0x40);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12403,0,0x40);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12400,0,4);
  if (*puVar6 == '\x01') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12406,0xb,0x3f);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240a,3,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x1240c,0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240d,0xb,0xf);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12402,puVar10[0x10]);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12403,*(ushort *)(puVar10 + 0x10) >> 8,0x3f);
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12406,puVar10[0xe],0x3f);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240a,0,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x1240c,0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240d,0xc,0xf);
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12400,1,1);
  if ((puVar10[0x8c] & 4) == 0) {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,0,8);
  }
  else {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,1,8);
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,0,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12405,1,0x40);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12405,0,0x40);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,0,4);
  if (*puVar6 == '\x01') {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12407,0xb,0x3f);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240b,3,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x1240e,0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240f,0xb,0xf);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12404,puVar10[0x12]);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12405,*(ushort *)(puVar10 + 0x12) >> 8,0x3f);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,1,1);
    cVar2 = *puVar6;
  }
  else {
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12407,puVar10[0xf],0x3f);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240b,0,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x1240e,0);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1240f,0xc,0xf);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12401,1,1);
    cVar2 = *puVar6;
  }
  if (cVar2 == '\x01') {
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12146,puVar10[0x42]);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12147,*(ushort *)(puVar10 + 0x42) >> 8,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12148,puVar10[0x44]);
    uVar3 = *(ushort *)(puVar10 + 0x44);
  }
  else {
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12146,puVar10[0x3e]);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12147,*(ushort *)(puVar10 + 0x3e) >> 8,7);
    (*(code *)PTR_msWriteByte_2f5bdb30)(0x12148,puVar10[0x40]);
    uVar3 = *(ushort *)(puVar10 + 0x40);
  }
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12149,uVar3 >> 8,7);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12140,0,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12140,puVar10[0x36],8);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12142,puVar10[0x37]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12143,puVar10[0x38]);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12144,puVar10[0x39],7);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12144,((byte)puVar10[0x3a] & 0xf) << 4,0x70);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12152,puVar10[0x4a]);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12153,*(ushort *)(puVar10 + 0x4a) >> 8,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1214a,puVar10[0x46]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1214b,puVar10[0x47]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1214c,puVar10[0x48]);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1214d,puVar10[0x49]);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12145,puVar10[0x3b],1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12145,puVar10[0x3c],2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12140,1,4);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12180,1,2);
  if (*puVar6 == '\x01') {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12480,1,2);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12481,0,7);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12480,0,1);
  }
  else {
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12480,0,2);
    (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12481,4,7);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12480,1,1);
  }
  if (puVar10[0x90] == '\x01') {
    PTR_VIFInitialIn_inst_2f5bdbb0[0x8f] = 0;
  }
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12248,1,2);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12249,0x20,0x7f);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1224a,10);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1224b,0,0xf);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1224c,0x20);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1224d,0);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12248,0,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1239a,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1239b,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1239c,0x28);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1239d,0,0xf);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123b8,1,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123b8,0,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123b9,0,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123b9,0,0x10);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123ba,1,3);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x123bb,1,0x10);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123be,0x59);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123bf,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123e4,4);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123e5,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123e6,0xe0);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123e7,0,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123e8,0);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123e9,0xc,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123ea,4,7);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123eb,0,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123ec,0x80);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123ed,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x123f0,0xff);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x123f1,0xf,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x124a4,0x20,0x70);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x124a5,0x20);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x124a6,0x20);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1242a,0,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1242a,0,0x10);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1243e,4,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1243e,0x40,0xf0);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12204,1,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12205,1,0x10);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x122f6,1,0x10);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12205,0,3);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12470,0x50);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12471,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12472,0x50);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12473,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12474,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12475,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12476,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12477,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12478,0xff);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12479,0xff);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1247a,0xff);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x1247b,0xff);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247c,5,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247c,0x80,0xf0);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247d,4,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247d,0x70,0xf0);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247e,3,0xf);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x1247e,0x60,0xf0);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1247f,0,1);
  puVar4 = PTR_msWriteBit_2f5bdab4;
  *PTR_g_VifHWKpKiFlag_2f5bdb84 = 1;
  (*(code *)puVar4)(0x122f6,1,1);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12272,0);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x12273,0x70);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12274,0x20,0x30);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12280,1,4);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12280,1,8);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,1,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x1220a,1,2);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x122e8,0,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12221,0,0x10);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12200,0x7f,0x7d);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12140,1,1);
  (*(code *)PTR_msWriteBit_2f5bdab4)(0x12180,1,1);
  (*(code *)PTR_msVifTopAdjust_2f5bdc10)();
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x122fa,0x15);
  (*(code *)PTR_msWriteByte_2f5bdb30)(0x122fb,0x61);
  (*(code *)PTR_MAsm_CPU_DelayMs_2f5bdb60)(1);
  (*(code *)PTR_msWriteByteMask_2f5bdb7c)(0x12200,0x7f,0x7f);
  return;
}

