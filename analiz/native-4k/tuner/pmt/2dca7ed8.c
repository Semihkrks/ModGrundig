
/* WARNING: Type propagation algorithm not settling */
/* mapi_si_PMT_parser::ParseSection(unsigned char*, MAPI_SI_TABLE_PMT&) */

undefined4 mapi_si_PMT_parser::ParseSection(uchar *param_1,MAPI_SI_TABLE_PMT *param_2)

{
  MAPI_SI_TABLE_PMT MVar1;
  MAPI_SI_TABLE_PMT MVar2;
  MAPI_SI_TABLE_PMT MVar3;
  undefined2 uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  ushort uVar9;
  char cVar10;
  char *pcVar11;
  uint uVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  MAPI_SI_TABLE_PMT *pMVar17;
  byte bVar18;
  int iVar19;
  MAPI_SI_TABLE_PMT *pMVar20;
  MAPI_SI_TABLE_PMT *pMVar21;
  MAPI_SI_TABLE_PMT *pMVar22;
  uint uVar23;
  uint uVar24;
  MAPI_SI_TABLE_PMT MVar25;
  byte local_2e40;
  MAPI_SI_TABLE_PMT local_2e3f;
  uchar local_2e3e;
  uchar local_2e3d;
  undefined2 local_2e3c [2];
  DESC_SUPPLEMENTARY_AUDIO aDStack_2e38 [8];
  undefined4 local_2e30;
  byte *local_2e2c;
  char local_2e1f;
  MS_SI_DESCRIPTORS aMStack_22c8 [2920];
  byte local_1760 [4];
  MAPI_SI_TABLE_PMT *local_175c;
  byte local_bf8 [5];
  MAPI_SI_TABLE_PMT local_bf3 [2915];
  int local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  MAPI_SI_TABLE_PMT *local_7c;
  MAPI_SI_TABLE_PMT *local_78;
  byte *local_74;
  uchar *local_70;
  DESC_SUPPLEMENTARY_AUDIO *local_6c;
  byte *local_68;
  MAPI_SI_TABLE_PMT *local_64;
  int local_60;
  MAPI_SI_TABLE_PMT *local_5c;
  MAPI_SI_TABLE_PMT *local_58;
  MAPI_SI_TABLE_PMT *local_54;
  uint local_50;
  MAPI_SI_TABLE_PMT *local_4c;
  int local_48;
  MAPI_SI_TABLE_PMT *local_44;
  MAPI_SI_TABLE_PMT *local_40;
  MAPI_SI_TABLE_PMT *local_3c;
  MAPI_SI_TABLE_PMT *local_38;
  byte *local_34;
  MS_SI_DESCRIPTORS *local_30;
  MAPI_SI_TABLE_PMT *local_2c;
  
  local_2e3e = '\0';
  local_2e3d = '\0';
  memset(param_2,0,0x3ac);
  *(undefined2 *)(param_2 + 0x372) = 0x1fff;
  *(undefined2 *)(param_2 + 0x378) = 0xffff;
  *(undefined2 *)(param_2 + 0x374) = 0xffff;
  param_2[0xe] = (MAPI_SI_TABLE_PMT)0x0;
  *(ushort *)(param_2 + 10) = (ushort)param_1[3] * 0x100 + (ushort)param_1[4];
  *(ushort *)(param_2 + 8) = (ushort)param_1[8] * 0x100 + (ushort)param_1[9] & 0x1fff;
  bVar14 = param_1[5];
  *(undefined2 *)(param_2 + 0x10) = 0x1fff;
  param_2[4] = SUB41(((uint)bVar14 << 0x1a) >> 0x1b,0);
  uVar24 = (uint)param_1[10] * 0x100 + (uint)param_1[0xb] & 0xfff;
  pcVar11 = (char *)mapi_si_parser::FindLoopHead(param_1,2,1);
  if ((uVar24 != 0) && (pcVar11 != (char *)0x0)) {
    cVar10 = *pcVar11;
    uVar23 = 0;
    if (cVar10 == 'U') goto LAB_2dca8034;
LAB_2dca7ff8:
    if (cVar10 == '`') {
      iVar19 = mapi_si_parser::GetDescriptorData(0x60,&local_2e30,pcVar11);
      if (iVar19 != 0) {
        *(undefined2 *)(param_2 + 0x1a6) = local_2e30._2_2_;
        *(undefined2 *)(param_2 + 0x1a8) = local_2e2c._0_2_;
        *(short *)(param_2 + 0x1a4) = (short)local_2e30;
        param_2[7] = (MAPI_SI_TABLE_PMT)0x1;
      }
LAB_2dca8008:
      uVar12 = (uint)(byte)pcVar11[1];
    }
    else {
      if (cVar10 != '\t') goto LAB_2dca8008;
      iVar19 = mapi_si_parser::GetDescriptorData(9,&local_2e30,pcVar11);
      if ((iVar19 == 0) || ((short)local_2e30 != 0x2600)) {
        param_2[6] = (MAPI_SI_TABLE_PMT)0x1;
        uVar12 = (uint)(byte)pcVar11[1];
      }
      else {
        param_2[0xf] = (MAPI_SI_TABLE_PMT)0x1;
        param_2[6] = (MAPI_SI_TABLE_PMT)0x1;
        uVar12 = (uint)(byte)pcVar11[1];
      }
    }
    while( true ) {
      uVar23 = uVar12 + 2 + uVar23 & 0xffff;
      if (uVar24 < uVar23) break;
      pcVar11 = pcVar11 + uVar12 + 2;
      while( true ) {
        cVar10 = *pcVar11;
        if (cVar10 != 'U') goto LAB_2dca7ff8;
LAB_2dca8034:
        uVar12 = (uint)(byte)pcVar11[1];
        bVar14 = (byte)pcVar11[1] >> 2;
        if (bVar14 == 0) break;
        pMVar17 = (MAPI_SI_TABLE_PMT *)(pcVar11 + 2);
        bVar18 = 0;
        iVar19 = 0;
        pMVar21 = param_2;
        do {
          iVar13 = iVar19 + 0xde;
          param_2[iVar13 * 4 + 4] = *pMVar17;
          bVar18 = bVar18 + 1;
          param_2[iVar13 * 4 + 5] = pMVar17[1];
          iVar19 = iVar19 + 1;
          param_2[iVar13 * 4 + 6] = pMVar17[2];
          pMVar22 = pMVar17 + 3;
          pMVar17 = pMVar17 + 4;
          pMVar21[0x37f] = *pMVar22;
          pMVar21 = pMVar21 + 4;
          if (bVar14 <= bVar18) break;
        } while (bVar18 != 10);
        uVar23 = (byte)pcVar11[1] + 2 + uVar23 & 0xffff;
        pcVar11 = pcVar11 + (byte)pcVar11[1] + 2;
        if (uVar24 < uVar23) goto LAB_2dca80cc;
      }
    }
  }
LAB_2dca80cc:
  pMVar21 = (MAPI_SI_TABLE_PMT *)mapi_si_parser::FindLoopHead(param_1,2,2);
  if (pMVar21 == (MAPI_SI_TABLE_PMT *)0x0) {
    param_2[5] = (MAPI_SI_TABLE_PMT)0x1;
LAB_2dca82d0:
    iVar19 = mapi_si_dvb_parser::GetCountry();
    if (((iVar19 == 0x32) && (param_2[0xe] == (MAPI_SI_TABLE_PMT)0x0)) &&
       (*(short *)(param_2 + 0xc) != 0)) {
      param_2[0xe] = (MAPI_SI_TABLE_PMT)0x1;
      param_2[0x34] = (MAPI_SI_TABLE_PMT)0x81;
      *(short *)(param_2 + 0x32) = *(short *)(param_2 + 0xc);
      param_2[0x31] = (MAPI_SI_TABLE_PMT)0x1;
      param_2[0x2f] = (MAPI_SI_TABLE_PMT)0x0;
    }
    return 1;
  }
  local_78 = param_2 + 0x2c;
  local_7c = param_2 + 0xe;
  local_34 = &local_2e40;
  local_30 = (MS_SI_DESCRIPTORS *)&local_2e30;
  local_2c = local_bf3;
  local_80 = 0;
  local_84 = 0;
  local_88 = 0;
  uVar24 = 0;
  local_8c = 0;
LAB_2dca8124:
  MVar25 = *pMVar21;
  uVar23 = (uint)(byte)pMVar21[3] * 0x100 + (uint)(byte)pMVar21[4] & 0xfff;
  pMVar17 = pMVar21 + 5;
  if (0xe < (byte)MVar25) {
    if (MVar25 == (MAPI_SI_TABLE_PMT)0x24) {
LAB_2dca8508:
      if (local_80 < 3) {
        iVar19 = local_80 + 2;
        param_2[iVar19 * 8 + 4] = MVar25;
        *(ushort *)(param_2 + iVar19 * 8 + 6) =
             (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
        if (uVar23 != 0) {
          MVar25 = *pMVar17;
          uVar12 = 0;
          do {
            if (MVar25 == (MAPI_SI_TABLE_PMT)0x9) {
              param_2[6] = (MAPI_SI_TABLE_PMT)0x1;
              uVar16 = (uint)(byte)pMVar17[1];
            }
            else if ((byte)MVar25 < 10) {
              if ((MVar25 != (MAPI_SI_TABLE_PMT)0x2) ||
                 (iVar13 = mapi_si_parser::GetDescriptorData(2,local_30,pMVar17), iVar13 == 0))
              goto LAB_2dca8574;
              param_2[iVar19 * 8 + 10] = local_2e2c._0_1_;
              uVar16 = (uint)(byte)pMVar17[1];
            }
            else if (MVar25 == (MAPI_SI_TABLE_PMT)0x28) {
              uVar16 = (uint)(byte)pMVar17[1];
              if (3 < uVar16) {
                param_2[iVar19 * 8 + 9] = pMVar17[4];
                param_2[iVar19 * 8 + 10] = (MAPI_SI_TABLE_PMT)((byte)pMVar17[5] >> 7);
LAB_2dca8574:
                uVar16 = (uint)(byte)pMVar17[1];
              }
            }
            else {
              if ((MVar25 != (MAPI_SI_TABLE_PMT)0x52) ||
                 (iVar13 = mapi_si_parser::GetDescriptorData(0x52,local_30,pMVar17), iVar13 == 0))
              goto LAB_2dca8574;
              param_2[iVar19 * 8 + 8] = local_2e30._0_1_;
              uVar16 = (uint)(byte)pMVar17[1];
            }
            uVar12 = uVar16 + 2 + uVar12 & 0xffff;
            if (uVar23 <= uVar12) break;
            pMVar17 = pMVar17 + uVar16 + 2;
            MVar25 = *pMVar17;
          } while( true );
        }
        local_80 = local_80 + 1 & 0xff;
        pMVar21 = (MAPI_SI_TABLE_PMT *)mapi_si_parser::FindNextLoop(param_1,pMVar21,uVar23,2);
        goto joined_r0x2dca82c4;
      }
      goto LAB_2dca82ac;
    }
    if ((byte)MVar25 < 0x25) {
      if (MVar25 != (MAPI_SI_TABLE_PMT)0x11) {
        if (MVar25 == (MAPI_SI_TABLE_PMT)0x1b) goto LAB_2dca8508;
        if (MVar25 != (MAPI_SI_TABLE_PMT)0xf) goto LAB_2dca82ac;
      }
    }
    else if (MVar25 != (MAPI_SI_TABLE_PMT)0x81) {
      if ((MVar25 != (MAPI_SI_TABLE_PMT)0xea) && (MVar25 != (MAPI_SI_TABLE_PMT)0x42))
      goto LAB_2dca82ac;
      goto LAB_2dca8508;
    }
LAB_2dca8348:
    MVar25 = param_2[0xe];
    local_2e3d = '\0';
    local_2e3e = '\0';
    if (0xf < (byte)MVar25) goto LAB_2dca82ac;
    local_2e3c[0] = 0xffff;
    local_2e40 = 0;
    param_2[((byte)MVar25 + 3) * 0x10 + 4] = *pMVar21;
    local_70 = (uchar *)local_2e3c;
    *(ushort *)(param_2 + (uint)(byte)param_2[0xe] * 0x10 + 0x32) =
         (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
    uVar12 = (uint)(byte)param_2[0xe];
    local_2e3f = MVar25;
    if (uVar23 != 0) {
      local_60 = uVar12 + 1;
      local_64 = param_2 + uVar12 * 0x10;
      local_5c = param_2 + local_60 * 0x10;
      local_58 = param_2 + (uVar12 + 4) * 0x10;
      local_54 = param_2 + (uVar12 + 3) * 0x10;
      local_6c = aDStack_2e38;
      uVar12 = 0;
      bVar5 = false;
      do {
        MVar25 = *pMVar17;
        if (MVar25 == (MAPI_SI_TABLE_PMT)0x52) {
          iVar19 = mapi_si_parser::GetDescriptorData(0x52,local_30,pMVar17);
          if ((iVar19 != 0) && (uVar16 = (uint)local_2e40, uVar16 < 2)) {
            local_2e40 = local_2e40 + 1;
            *(MAPI_SI_TABLE_PMT *)(local_34 + uVar16 + 4) = local_2e30._0_1_;
          }
LAB_2dca8428:
          MVar25 = pMVar17[1];
        }
        else {
          if ((byte)MVar25 < 0x53) {
            if (MVar25 == (MAPI_SI_TABLE_PMT)0x9) {
              param_2[6] = (MAPI_SI_TABLE_PMT)0x1;
            }
            else if ((MVar25 == (MAPI_SI_TABLE_PMT)0xa) &&
                    (iVar19 = mapi_si_parser::GetDescriptorData(10,local_30,pMVar17), iVar19 != 0))
            {
              uVar16 = (uint)(byte)param_2[0xe];
              if (uVar16 < 0x10) {
                __Store_Aud_Iso639Info
                          ((MAPI_SI_AUD_INFO *)local_78,local_30,
                           *(ushort *)(param_2 + uVar16 * 0x10 + 0x32),
                           (uchar)param_2[(uVar16 + 3) * 0x10 + 4],(uchar *)local_7c);
                if ((bVar5) &&
                   (local_64[0x2f] = (MAPI_SI_TABLE_PMT)0x2,
                   local_60 < (int)(uint)(byte)param_2[0xe])) {
                  uVar4 = *(undefined2 *)(local_64 + 0x32);
                  local_5c[0x2f] = (MAPI_SI_TABLE_PMT)0x1;
                  *(undefined2 *)(local_5c + 0x32) = uVar4;
                  bVar5 = true;
                  local_58[4] = local_54[4];
                }
                else {
                  bVar5 = true;
                }
              }
            }
            goto LAB_2dca8428;
          }
          if (MVar25 == (MAPI_SI_TABLE_PMT)0x7c) {
            iVar19 = mapi_si_parser::GetDescriptorData(0x7c,aMStack_22c8,pMVar17);
            if (iVar19 != 0) {
              local_2e3d = '\x01';
            }
            goto LAB_2dca8428;
          }
          if (MVar25 == (MAPI_SI_TABLE_PMT)0x7f) {
            if (((pMVar17[2] == (MAPI_SI_TABLE_PMT)0x6) && ((byte)param_2[0xe] < 0x10)) &&
               (iVar19 = mapi_si_parser::GetDescriptorDataExtend(0x7f,local_6c,pMVar17), iVar19 != 0
               )) {
              local_2e3e = '\x01';
            }
            goto LAB_2dca8428;
          }
          if (MVar25 != (MAPI_SI_TABLE_PMT)0x6a) goto LAB_2dca8428;
          mapi_si_parser::GetDescriptorData(0x6a,local_30,pMVar17);
          MVar25 = pMVar17[1];
        }
        uVar12 = (byte)MVar25 + 2 + uVar12 & 0xffff;
        if (uVar23 <= uVar12) goto LAB_2dca84a4;
        pMVar17 = pMVar17 + (byte)MVar25 + 2;
      } while( true );
    }
    local_6c = aDStack_2e38;
    param_2[0xe] = (MAPI_SI_TABLE_PMT)((char)param_2[0xe] + 1);
    goto LAB_2dca84ac;
  }
  if ((byte)MVar25 < 10) {
    if ((byte)MVar25 < 5) {
      if (2 < (byte)MVar25) goto LAB_2dca8348;
      if (MVar25 != (MAPI_SI_TABLE_PMT)0x0) goto LAB_2dca8508;
    }
    else if (MVar25 == (MAPI_SI_TABLE_PMT)0x5) {
      uVar12 = 0;
      if (uVar23 == 0) {
        if (*(short *)(param_2 + 0xc) == 0) {
          *(ushort *)(param_2 + 0xc) =
               (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
        }
        goto LAB_2dca8d28;
      }
      do {
        if (*pMVar17 == (MAPI_SI_TABLE_PMT)0x6f) {
          iVar19 = mapi_si_parser::GetDescriptorData(0x6f,local_30,pMVar17);
          if (iVar19 != 0) {
            *(ushort *)(param_2 + 0x372) =
                 (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
            uVar16 = (local_2e30 & 0xff) / 3;
            if (uVar16 != 0) {
              *(ushort *)(param_2 + 0x374) =
                   (ushort)*local_2e2c * 0x100 + (ushort)local_2e2c[1] & 0x7fff;
              param_2[0x376] = (MAPI_SI_TABLE_PMT)(local_2e2c[2] & 0x1f);
              if (uVar16 != 1) {
                *(ushort *)(param_2 + 0x378) =
                     (ushort)local_2e2c[4] + (ushort)local_2e2c[3] * 0x100 & 0x7fff;
                param_2[0x37a] = (MAPI_SI_TABLE_PMT)(local_2e2c[5] & 0x1f);
              }
            }
          }
        }
        else if (*pMVar17 == (MAPI_SI_TABLE_PMT)0x74) {
          *(ushort *)(param_2 + 0x12) =
               (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
        }
        uVar12 = (byte)pMVar17[1] + 2 + uVar12 & 0xffff;
        pMVar17 = pMVar17 + (byte)pMVar17[1] + 2;
      } while (uVar12 < uVar23);
    }
    else if (MVar25 == (MAPI_SI_TABLE_PMT)0x6) {
      local_68 = local_1760;
      local_2e3e = '\0';
      memset(local_68,0,0xb68);
      local_74 = local_bf8;
      memset(local_74,0,0xb68);
      if (uVar23 != 0) {
        local_38 = pMVar21 + 2;
        uVar12 = 0;
        MVar25 = (MAPI_SI_TABLE_PMT)0x0;
        pMVar22 = pMVar17;
        do {
          while( true ) {
            MVar1 = *pMVar22;
            if (MVar1 != (MAPI_SI_TABLE_PMT)0x56) break;
LAB_2dca8b1c:
            iVar19 = mapi_si_parser::GetDescriptorData(MVar1,local_74,pMVar22);
            if (iVar19 != 0) {
              if (local_bf8[0] == 0) {
                MVar1 = pMVar21[1];
                MVar2 = pMVar21[2];
                MVar25 = (MAPI_SI_TABLE_PMT)0x0;
                param_2[0x1b1] = (MAPI_SI_TABLE_PMT)0x0;
                *(ushort *)(param_2 + 0x1ac) =
                     (ushort)(byte)MVar1 * 0x100 + (ushort)(byte)MVar2 & 0x1fff;
              }
              else {
                iVar19 = 0;
                pMVar20 = local_2c;
                do {
                  bVar14 = local_34[iVar19 * 5 + 0x224c] & 0x1f;
                  if (((bVar14 == 1) || (bVar14 == 3)) || (bVar14 == 4)) {
                    if (local_88 < 0xc) {
                      iVar13 = iVar19 * 5;
                      iVar8 = local_88 * 0xc;
                      MVar1 = pMVar21[1];
                      MVar2 = pMVar21[2];
                      param_2[iVar8 + 0x1ae] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 1);
                      param_2[iVar8 + 0x1af] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 2);
                      param_2[iVar8 + 0x1b0] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 3);
                      bVar14 = local_34[iVar13 + 0x224c];
                      MVar3 = *pMVar20;
                      *(ushort *)(param_2 + iVar8 + 0x1ac) =
                           (ushort)(byte)MVar1 * 0x100 + (ushort)(byte)MVar2 & 0x1fff;
                      param_2[iVar8 + 0x1b1] = SUB41(((uint)bVar14 << 0x1b) >> 0x1b,0);
                      param_2[iVar8 + 0x1b2] = (MAPI_SI_TABLE_PMT)(bVar14 >> 5);
                      param_2[iVar8 + 0x1b3] = MVar3;
                      param_2[iVar8 + 0x1aa] = MVar25;
                      local_88 = local_88 + 1 & 0xff;
                    }
                  }
                  else if (((bVar14 == 2) || (bVar14 == 5)) && (local_8c < 0xc)) {
                    iVar13 = iVar19 * 5;
                    iVar8 = local_8c * 0xc;
                    MVar1 = pMVar21[1];
                    MVar2 = pMVar21[2];
                    param_2[iVar8 + 0x23e] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 1);
                    param_2[iVar8 + 0x23f] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 2);
                    param_2[iVar8 + 0x240] = *(MAPI_SI_TABLE_PMT *)(local_74 + iVar13 + 3);
                    bVar14 = local_34[iVar13 + 0x224c];
                    MVar3 = *pMVar20;
                    local_8c = local_8c + 1 & 0xff;
                    *(ushort *)(param_2 + iVar8 + 0x23c) =
                         (ushort)(byte)MVar1 * 0x100 + (ushort)(byte)MVar2 & 0x1fff;
                    param_2[iVar8 + 0x241] = SUB41(((uint)bVar14 << 0x1b) >> 0x1b,0);
                    param_2[iVar8 + 0x242] = (MAPI_SI_TABLE_PMT)(bVar14 >> 5);
                    param_2[iVar8 + 0x243] = MVar3;
                    param_2[iVar8 + 0x23a] = MVar25;
                  }
                  iVar19 = iVar19 + 1;
                  pMVar20 = pMVar20 + 5;
                } while (iVar19 < (int)(uint)local_bf8[0]);
LAB_2dca8b14:
                MVar25 = (MAPI_SI_TABLE_PMT)0x0;
              }
            }
LAB_2dca8754:
            uVar12 = (byte)pMVar22[1] + 2 + uVar12 & 0xffff;
            if (uVar23 <= uVar12) goto LAB_2dca8800;
            pMVar22 = pMVar22 + (byte)pMVar22[1] + 2;
          }
          if ((byte)MVar1 < 0x57) {
            if (MVar1 != (MAPI_SI_TABLE_PMT)0x46) {
              if (MVar1 == (MAPI_SI_TABLE_PMT)0x52) {
                iVar19 = mapi_si_parser::GetDescriptorData(0x52,local_30,pMVar22);
                if (iVar19 != 0) {
                  MVar25 = local_2e30._0_1_;
                }
              }
              goto LAB_2dca8754;
            }
            goto LAB_2dca8b1c;
          }
          if (MVar1 == (MAPI_SI_TABLE_PMT)0x59) {
            iVar19 = mapi_si_parser::GetDescriptorData(0x59,local_68,pMVar22);
            if (iVar19 == 0) goto LAB_2dca8754;
            if (local_1760[0] >> 3 != 0) {
              iVar19 = 0;
              pMVar20 = local_175c;
              if (0xb < uVar24) {
                MVar25 = (MAPI_SI_TABLE_PMT)0x0;
                goto LAB_2dca8754;
              }
              do {
                iVar13 = uVar24 * 0xe;
                *(ushort *)(param_2 + iVar13 + 0x2cc) =
                     (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)*local_38 & 0x1fff;
                param_2[iVar13 + 0x2ce] = *pMVar20;
                iVar19 = iVar19 + 1;
                param_2[iVar13 + 0x2cf] = pMVar20[1];
                uVar24 = uVar24 + 1 & 0xff;
                param_2[iVar13 + 0x2d0] = pMVar20[2];
                param_2[iVar13 + 0x2d1] = pMVar20[3];
                *(ushort *)(param_2 + iVar13 + 0x2d2) =
                     (ushort)(byte)pMVar20[4] * 0x100 + (ushort)(byte)pMVar20[5];
                MVar1 = pMVar20[6];
                MVar2 = pMVar20[7];
                param_2[iVar13 + 0x2ca] = MVar25;
                *(ushort *)(param_2 + iVar13 + 0x2d4) =
                     (ushort)(byte)MVar1 * 0x100 + (ushort)(byte)MVar2;
                pMVar20 = pMVar20 + 8;
                if ((int)(uint)(local_1760[0] >> 3) <= iVar19) break;
              } while (uVar24 < 0xc);
            }
            goto LAB_2dca8b14;
          }
          if ((MVar1 != (MAPI_SI_TABLE_PMT)0x98) ||
             (iVar19 = mapi_si_parser::GetDescriptorData(0x98,local_30,pMVar22), iVar19 == 0))
          goto LAB_2dca8754;
          param_2[0x3a8] = local_2e2c._0_1_;
          *(uint *)(param_2 + 0x3a4) = local_2e30;
          *(ushort *)(param_2 + 0x3aa) =
               (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
          uVar12 = (byte)pMVar22[1] + 2 + uVar12 & 0xffff;
          pMVar22 = pMVar22 + (byte)pMVar22[1] + 2;
        } while (uVar12 < uVar23);
      }
LAB_2dca8800:
      uVar9 = (ushort)uVar23;
      iVar19 = mapi_si_parser::FindDescriptorTag((uchar *)pMVar17,'|',uVar9);
      if (iVar19 == 0) {
        iVar19 = mapi_si_parser::FindDescriptorTag((uchar *)pMVar17,'j',uVar9);
        if (iVar19 == 0) {
          iVar19 = mapi_si_parser::FindDescriptorTag((uchar *)pMVar17,'z',uVar9);
          if (iVar19 == 0) {
            iVar19 = mapi_si_parser::FindDescriptorTag((uchar *)pMVar17,0xa0,uVar9);
            if (iVar19 == 0) {
              uVar12 = 0;
              if (uVar23 == 0) {
                if (*(short *)(param_2 + 0xc) == 0) {
                  *(ushort *)(param_2 + 0xc) =
                       (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
                }
              }
              else {
                do {
                  if (((*pMVar17 == (MAPI_SI_TABLE_PMT)0x52) &&
                      (iVar19 = mapi_si_parser::GetDescriptorData(0x52,local_30,pMVar17),
                      iVar19 != 0)) &&
                     (((local_2e30 & 0xff) == 0x30 ||
                      ((((local_2e30 & 0xff) - 0x31 & 0xff) < 7 &&
                       (*(short *)(param_2 + 0x10) == 0x1fff)))))) {
                    *(ushort *)(param_2 + 0x10) =
                         (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
                  }
                  uVar12 = (byte)pMVar17[1] + 2 + uVar12 & 0xffff;
                  pMVar17 = pMVar17 + (byte)pMVar17[1] + 2;
                } while (uVar12 < uVar23);
              }
              goto LAB_2dca82ac;
            }
            bVar6 = false;
            bVar5 = false;
            bVar7 = false;
          }
          else {
            bVar6 = false;
            bVar7 = true;
            bVar5 = false;
          }
        }
        else {
          bVar6 = true;
          bVar7 = false;
          bVar5 = false;
        }
      }
      else {
        bVar6 = false;
        bVar7 = false;
        bVar5 = true;
      }
      MVar25 = param_2[0xe];
      uVar12 = (uint)(byte)MVar25;
      if (uVar12 < 0x10) {
        local_70 = (uchar *)local_2e3c;
        local_2e3d = '\0';
        local_2e3c[0] = 0xffff;
        local_2e40 = 0;
        if (bVar5) {
          param_2[(uVar12 + 3) * 0x10 + 4] = (MAPI_SI_TABLE_PMT)0xf;
        }
        else if (bVar6) {
          param_2[(uVar12 + 3) * 0x10 + 4] = (MAPI_SI_TABLE_PMT)0x81;
        }
        else if (bVar7) {
          param_2[(uVar12 + 3) * 0x10 + 4] = (MAPI_SI_TABLE_PMT)0xff;
        }
        else {
          param_2[(uVar12 + 3) * 0x10 + 4] = (MAPI_SI_TABLE_PMT)0xbd;
        }
        *(ushort *)(param_2 + (uint)(byte)param_2[0xe] * 0x10 + 0x32) =
             (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
        uVar12 = (uint)(byte)param_2[0xe];
        local_2e3f = MVar25;
        if (uVar23 == 0) {
          local_6c = aDStack_2e38;
          param_2[0xe] = (MAPI_SI_TABLE_PMT)((char)param_2[0xe] + 1);
        }
        else {
          local_48 = uVar12 + 1;
          local_40 = param_2 + (uVar12 + 4) * 0x10;
          local_3c = param_2 + (uVar12 + 3) * 0x10;
          local_4c = param_2 + uVar12 * 0x10;
          local_44 = param_2 + local_48 * 0x10;
          local_6c = aDStack_2e38;
          local_50 = (uint)(uVar12 < 0x10);
          uVar16 = 0;
          local_90 = 0;
          do {
            while( true ) {
              MVar25 = *pMVar17;
              if (MVar25 != (MAPI_SI_TABLE_PMT)0x6a) break;
              mapi_si_parser::GetDescriptorData(0x6a,local_30,pMVar17);
LAB_2dca8928:
              uVar16 = (byte)pMVar17[1] + 2 + uVar16 & 0xffff;
              if (uVar23 <= uVar16) goto LAB_2dca89c0;
              pMVar17 = pMVar17 + (byte)pMVar17[1] + 2;
            }
            if ((byte)MVar25 < 0x6b) {
              if (MVar25 == (MAPI_SI_TABLE_PMT)0xa) {
                iVar19 = mapi_si_parser::GetDescriptorData(10,local_30,pMVar17);
                if (iVar19 != 0) {
                  uVar15 = (uint)(byte)param_2[0xe];
                  if (uVar15 < 0x10) {
                    __Store_Aud_Iso639Info
                              ((MAPI_SI_AUD_INFO *)local_78,local_30,
                               *(ushort *)(param_2 + uVar15 * 0x10 + 0x32),
                               (uchar)param_2[(uVar15 + 3) * 0x10 + 4],(uchar *)local_7c);
                    if ((((local_90 == 0) || (local_50 == 0)) ||
                        (local_4c[0x2f] = (MAPI_SI_TABLE_PMT)0x2,
                        (int)(uint)(byte)param_2[0xe] <= local_48)) || (uVar12 == 0xf)) {
                      local_90 = 1;
                    }
                    else {
                      uVar4 = *(undefined2 *)(local_4c + 0x32);
                      local_44[0x2f] = (MAPI_SI_TABLE_PMT)0x1;
                      *(undefined2 *)(local_44 + 0x32) = uVar4;
                      local_40[4] = local_3c[4];
                      local_90 = 1;
                    }
                  }
                }
              }
              else if (MVar25 == (MAPI_SI_TABLE_PMT)0x52) {
                iVar19 = mapi_si_parser::GetDescriptorData(0x52,local_30,pMVar17);
                if ((iVar19 != 0) && (uVar15 = (uint)local_2e40, uVar15 < 2)) {
                  local_2e40 = local_2e40 + 1;
                  *(MAPI_SI_TABLE_PMT *)(local_34 + uVar15 + 4) = local_2e30._0_1_;
                }
              }
              else if (MVar25 == (MAPI_SI_TABLE_PMT)0x9) {
                param_2[6] = (MAPI_SI_TABLE_PMT)0x1;
              }
              goto LAB_2dca8928;
            }
            if (MVar25 == (MAPI_SI_TABLE_PMT)0x7f) {
              if (((pMVar17[2] == (MAPI_SI_TABLE_PMT)0x6) && ((byte)param_2[0xe] < 0x10)) &&
                 (iVar19 = mapi_si_parser::GetDescriptorDataExtend(0x7f,local_6c,pMVar17),
                 iVar19 != 0)) {
                local_2e3e = '\x01';
              }
              goto LAB_2dca8928;
            }
            if (MVar25 == (MAPI_SI_TABLE_PMT)0xa0) {
              iVar19 = mapi_si_parser::GetDescriptorData(0xa0,local_30,pMVar17);
              if (((iVar19 != 0) && ((byte)param_2[0xe] < 0x10)) && (local_2e1f != '\0')) {
                iVar19 = (uint)(byte)param_2[0xe] * 0x10;
                *(undefined2 *)(param_2 + iVar19 + 0x2c) = *(undefined2 *)local_30;
                param_2[iVar19 + 0x2e] = *(MAPI_SI_TABLE_PMT *)(local_30 + 2);
                param_2[(uint)(byte)param_2[0xe] * 0x10 + 0x2f] = (MAPI_SI_TABLE_PMT)0x0;
                param_2[(uint)(byte)param_2[0xe] * 0x10 + 0x30] = (MAPI_SI_TABLE_PMT)0x0;
                param_2[(uint)(byte)param_2[0xe] * 0x10 + 0x31] = (MAPI_SI_TABLE_PMT)0x1;
              }
              goto LAB_2dca8928;
            }
            if ((MVar25 != (MAPI_SI_TABLE_PMT)0x7c) ||
               (iVar19 = mapi_si_parser::GetDescriptorData(0x7c,aMStack_22c8,pMVar17), iVar19 == 0))
            goto LAB_2dca8928;
            local_2e3d = '\x01';
            uVar16 = (byte)pMVar17[1] + 2 + uVar16 & 0xffff;
            pMVar17 = pMVar17 + (byte)pMVar17[1] + 2;
          } while (uVar16 < uVar23);
LAB_2dca89c0:
          if (local_90 == 0) {
            param_2[0xe] = (MAPI_SI_TABLE_PMT)((char)param_2[0xe] + '\x01');
          }
        }
        __UpdateAudio((uchar *)&local_2e3f,param_2,&local_2e3d,&local_2e3e,local_6c,aMStack_22c8,
                      local_34,local_70);
        pMVar21 = (MAPI_SI_TABLE_PMT *)mapi_si_parser::FindNextLoop(param_1,pMVar21,uVar23,2);
        goto joined_r0x2dca82c4;
      }
    }
    goto LAB_2dca82ac;
  }
  if (*(short *)(param_2 + 0x16) == 0) {
    *(undefined2 *)(param_2 + 0x16) = 0x1fff;
  }
  if (9 < local_84) goto LAB_2dca82ac;
  *(ushort *)(param_2 + local_84 * 0xc + 300) =
       (ushort)(byte)pMVar21[1] * 0x100 + (ushort)(byte)pMVar21[2] & 0x1fff;
  if (uVar23 != 0) {
    MVar25 = *pMVar17;
    uVar12 = 0;
    do {
      if (MVar25 == (MAPI_SI_TABLE_PMT)0x13) {
        mapi_si_parser::GetDescriptorData(0x13,local_30,pMVar17);
LAB_2dca81c8:
        uVar16 = (uint)(byte)pMVar17[1];
      }
      else {
        if ((MVar25 != (MAPI_SI_TABLE_PMT)0x66) ||
           (iVar19 = mapi_si_parser::GetDescriptorData(0x66,local_30,pMVar17), iVar19 == 0))
        goto LAB_2dca81c8;
        *(short *)(param_2 + local_84 * 0xc + 0x12e) = (short)local_2e30;
        *(ushort *)(param_2 + local_84 * 0xc + 0x130) =
             (ushort)local_2e2c[1] + (ushort)*local_2e2c * 0x100;
        uVar16 = (uint)(byte)pMVar17[1];
        if ((2 < uVar16) && ((short)local_2e30 == 10)) {
          *(uint *)(param_2 + local_84 * 0xc + 0x134) =
               (uint)(byte)pMVar17[5] << 0x10 | (uint)(byte)pMVar17[6] << 8 | (uint)(byte)pMVar17[7]
          ;
          uVar16 = (uint)(byte)pMVar17[1];
        }
        local_84 = local_84 + 1 & 0xff;
      }
      uVar12 = uVar16 + 2 + uVar12 & 0xffff;
      if (uVar23 <= uVar12) goto LAB_2dca82ac;
      pMVar17 = pMVar17 + uVar16 + 2;
      MVar25 = *pMVar17;
    } while( true );
  }
LAB_2dca8d28:
  pMVar21 = (MAPI_SI_TABLE_PMT *)mapi_si_parser::FindNextLoop(param_1,pMVar21,0,2);
  goto joined_r0x2dca82c4;
LAB_2dca84a4:
  if (!bVar5) {
    param_2[0xe] = (MAPI_SI_TABLE_PMT)((char)param_2[0xe] + '\x01');
  }
LAB_2dca84ac:
  __UpdateAudio((uchar *)&local_2e3f,param_2,&local_2e3d,&local_2e3e,local_6c,aMStack_22c8,local_34,
                local_70);
LAB_2dca82ac:
  pMVar21 = (MAPI_SI_TABLE_PMT *)mapi_si_parser::FindNextLoop(param_1,pMVar21,uVar23,2);
joined_r0x2dca82c4:
  if (pMVar21 == (MAPI_SI_TABLE_PMT *)0x0) goto LAB_2dca82d0;
  goto LAB_2dca8124;
}

