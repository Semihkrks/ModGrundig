
int ares_init_options(undefined4 *param_1,uint *param_2,uint param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  uint *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  byte *pbVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  uint *puVar20;
  uint *puVar21;
  undefined *puVar22;
  byte *pbVar23;
  code *pcVar24;
  char *pcVar25;
  int *piVar26;
  undefined *puVar27;
  int iVar28;
  undefined *puVar29;
  undefined4 *puVar30;
  undefined2 local_f0 [2];
  int local_ec;
  uint local_e8;
  uint local_e4;
  undefined1 auStack_e0 [4];
  uint local_dc [2];
  char local_d4 [16];
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  char local_b0 [32];
  uint local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  undefined2 local_6c;
  int *local_68;
  undefined1 *local_64;
  char *local_60;
  undefined2 *local_5c;
  char *local_58;
  uint *local_54;
  uint *local_50;
  uint *local_4c;
  undefined4 *local_48;
  int *local_44;
  undefined1 *local_40;
  int *local_3c;
  undefined1 *local_38;
  int *local_34;
  undefined1 *local_30;
  
  iVar5 = (*(code *)PTR_LAB_2f0f15e4)();
  if (iVar5 != 0) {
    return 0x15;
  }
  puVar6 = (uint *)(*(code *)PTR_malloc_2f0f167c)(0x9170);
  if (puVar6 == (uint *)0x0) {
    *param_1 = 0;
    return 0xf;
  }
  iVar5 = 0;
  (*(code *)PTR_LAB_2f0f15e8)(local_dc);
  puVar22 = PTR_LAB_2f0f15dc;
  puVar6[0x245b] = 0;
  puVar6[0x2458] = 0;
  puVar6[0x2459] = 0;
  puVar6[0x245a] = 0;
  puVar6[0xc] = 0xffffffff;
  puVar6[0x53] = local_dc[0];
  *puVar6 = 0xffffffff;
  puVar6[1] = 0xffffffff;
  puVar6[2] = 0xffffffff;
  puVar6[3] = 0xffffffff;
  puVar6[4] = 0xffffffff;
  puVar6[5] = 0xffffffff;
  puVar6[6] = 0xffffffff;
  puVar6[7] = 0xffffffff;
  puVar6[8] = 0xffffffff;
  puVar6[0x10] = 0xffffffff;
  puVar6[10] = 0xffffffff;
  puVar6[0x52] = 0;
  puVar6[0xd] = 0;
  puVar6[9] = 0;
  puVar6[0xb] = 0;
  puVar6[0xf] = 0;
  puVar6[0x54] = 0;
  (*(code *)puVar22)(puVar6 + 0x55);
  do {
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + iVar5 * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 1) * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 2) * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 3) * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 4) * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 5) * 3 + 0x58);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 6) * 3 + 0x58);
    iVar17 = iVar5 + 7;
    iVar5 = iVar5 + 8;
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + iVar17 * 3 + 0x58);
  } while (iVar5 != 0x800);
  iVar5 = 0;
  do {
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + iVar5 * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 1) * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 2) * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 3) * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 4) * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 5) * 3 + 0x1858);
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + (iVar5 + 6) * 3 + 0x1858);
    iVar17 = iVar5 + 7;
    uVar16 = iVar17 * 0xc;
    iVar5 = iVar5 + 8;
    (*(code *)PTR_LAB_2f0f15dc)(puVar6 + iVar17 * 3 + 0x1858);
  } while (iVar5 != 0x400);
  if (((param_3 & 1) != 0) && (*puVar6 == 0xffffffff)) {
    uVar16 = *param_2;
    *puVar6 = uVar16;
  }
  if (((param_3 & 0x2000) == 0) || (puVar6[1] != 0xffffffff)) {
    if (((param_3 & 2) != 0) && (puVar6[1] == 0xffffffff)) {
      puVar6[1] = param_2[1] * 1000;
    }
  }
  else {
    puVar6[1] = param_2[1];
  }
  if (((param_3 & 4) != 0) && (puVar6[2] == 0xffffffff)) {
    puVar6[2] = param_2[2];
  }
  if (((param_3 & 8) != 0) && (puVar6[3] == 0xffffffff)) {
    puVar6[3] = param_2[3];
  }
  if (((param_3 & 0x4000) != 0) && (uVar16 = 0xffffffff, puVar6[4] == 0xffffffff)) {
    puVar6[4] = 1;
  }
  if (((param_3 & 0x10) != 0) && (puVar6[5] == 0xffffffff)) {
    puVar6[5] = (uint)(ushort)param_2[4];
  }
  if (((param_3 & 0x20) != 0) && (puVar6[6] == 0xffffffff)) {
    puVar6[6] = (uint)*(ushort *)((int)param_2 + 0x12);
  }
  if (((param_3 & 0x200) != 0) && (puVar6[0x2458] == 0)) {
    uVar19 = param_2[0xd];
    puVar6[0x2458] = param_2[0xc];
    puVar6[0x2459] = uVar19;
  }
  if (((param_3 & 0x800) != 0) && (puVar6[7] == 0xffffffff)) {
    puVar6[7] = param_2[5];
  }
  if (((param_3 & 0x1000) != 0) && (puVar6[8] == 0xffffffff)) {
    uVar16 = param_2[6];
    puVar6[8] = uVar16;
  }
  if (((param_3 & 0x40) != 0) && (puVar6[0x10] == 0xffffffff)) {
    uVar19 = param_2[8];
    if ((int)uVar19 < 1) {
LAB_2f0d86dc:
      puVar6[0x10] = uVar19;
      goto LAB_2f0d7ce0;
    }
    uVar19 = (*(code *)PTR_malloc_2f0f167c)(uVar19 * 0x50);
    puVar6[0xf] = uVar19;
    if (uVar19 != 0) {
      uVar19 = param_2[8];
      if (0 < (int)uVar19) {
        iVar5 = 0;
        iVar17 = 0;
        do {
          uVar15 = puVar6[0xf];
          uVar19 = param_2[7];
          iVar28 = iVar5 * 4;
          *(undefined4 *)(uVar15 + iVar17) = 2;
          iVar5 = iVar5 + 1;
          ((undefined4 *)(uVar15 + iVar17))[1] = *(undefined4 *)(uVar19 + iVar28);
          uVar19 = param_2[8];
          iVar17 = iVar17 + 0x50;
        } while (iVar5 < (int)uVar19);
      }
      goto LAB_2f0d86dc;
    }
    goto LAB_2f0d7ff8;
  }
LAB_2f0d7ce0:
  if (((param_3 & 0x80) != 0) && (puVar6[10] == 0xffffffff)) {
    uVar19 = param_2[10];
    if (0 < (int)uVar19) {
      uVar15 = (*(code *)PTR_malloc_2f0f167c)(uVar19 << 2);
      puVar6[9] = uVar15;
      if (uVar15 == 0) goto LAB_2f0d7ff8;
      uVar19 = param_2[10];
      if (0 < (int)uVar19) {
        uVar12 = 0;
        do {
          puVar22 = PTR___strdup_2f0f1630;
          uVar16 = param_2[9];
          iVar5 = uVar12 * 4;
          uVar9 = *(undefined4 *)(uVar16 + iVar5);
          puVar6[10] = uVar12;
          puVar8 = (undefined4 *)(uVar15 + iVar5);
          uVar9 = (*(code *)puVar22)(uVar9);
          uVar15 = puVar6[9];
          *puVar8 = uVar9;
          uVar12 = uVar12 + 1;
          if (*(int *)(uVar15 + iVar5) == 0) goto LAB_2f0d7ff8;
          uVar19 = param_2[10];
        } while ((int)uVar12 < (int)uVar19);
      }
    }
    puVar6[10] = uVar19;
  }
  if (((param_3 & 0x100) == 0) || (puVar6[0xd] != 0)) {
LAB_2f0d7d14:
    if (((param_3 & 0x400) != 0) && (uVar19 = puVar6[0xc], uVar19 == 0xffffffff)) {
      uVar15 = (*(code *)PTR_malloc_2f0f167c)(param_2[0xf] * 0x28);
      puVar6[0xb] = uVar15;
      if (uVar15 == 0) goto LAB_2f0d7ff8;
      uVar15 = param_2[0xf];
      iVar5 = 0;
      if (0 < (int)uVar15) {
        iVar17 = 0;
        do {
          iVar5 = iVar5 + 1;
          puVar8 = (undefined4 *)(param_2[0xe] + iVar17);
          uVar15 = (int)puVar8 + 0xbU & 3;
          puVar30 = (undefined4 *)(puVar6[0xb] + iVar17);
          uVar9 = puVar8[1];
          uVar18 = puVar8[3];
          uVar12 = (uint)(puVar8 + 2) & 3;
          uVar19 = (*(int *)(((int)puVar8 + 0xbU) - uVar15) << (3 - uVar15) * 8 |
                   uVar19 & 0xffffffffU >> (uVar15 + 1) * 8) & -1 << (4 - uVar12) * 8 |
                   *(uint *)((int)(puVar8 + 2) - uVar12) >> uVar12 * 8;
          *puVar30 = *puVar8;
          puVar30[1] = uVar9;
          puVar30[2] = uVar19;
          puVar30[3] = uVar18;
          uVar15 = (int)puVar8 + 0x1bU & 3;
          uVar9 = puVar8[5];
          uVar18 = puVar8[7];
          uVar12 = (uint)(puVar8 + 6) & 3;
          uVar16 = (*(int *)(((int)puVar8 + 0x1bU) - uVar15) << (3 - uVar15) * 8 |
                   uVar16 & 0xffffffffU >> (uVar15 + 1) * 8) & -1 << (4 - uVar12) * 8 |
                   *(uint *)((int)(puVar8 + 6) - uVar12) >> uVar12 * 8;
          puVar30[4] = puVar8[4];
          puVar30[5] = uVar9;
          puVar30[6] = uVar16;
          puVar30[7] = uVar18;
          uVar9 = puVar8[9];
          puVar30[8] = puVar8[8];
          puVar30[9] = uVar9;
          uVar15 = param_2[0xf];
          iVar17 = iVar17 + 0x28;
        } while (iVar5 < (int)uVar15);
      }
      puVar6[0xc] = uVar15;
    }
    puVar6[0xe] = param_3;
    iVar5 = (*(code *)PTR_getenv_2f0f1700)(PTR_LAB_2f0f15b8 + 0x1018);
    if ((((iVar5 != 0) && (puVar6[10] == 0xffffffff)) &&
        (iVar5 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6b28))(puVar6,iVar5), iVar5 != 0
        )) || ((iVar5 = (*(code *)PTR_getenv_2f0f1700)(PTR_LAB_2f0f15b8 + 0x1024), iVar5 != 0 &&
               (iVar5 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7054))(puVar6,iVar5),
               iVar5 != 0)))) goto LAB_2f0d7ff8;
    local_e8 = 0;
    local_ec = 0;
    local_e4 = 0;
    if ((((puVar6[0xd] == 0) || (((int)puVar6[0xc] < 0 || (uVar16 = puVar6[0x10], (int)uVar16 < 0)))
         ) || ((int)puVar6[10] < 0)) ||
       (((uVar19 = puVar6[3], (int)uVar19 < 0 || (uVar15 = puVar6[1], (int)uVar15 < 0)) ||
        (uVar12 = puVar6[2], (int)uVar12 < 0)))) {
      iVar5 = (*(code *)PTR_fopen64_2f0f162c)(PTR_LAB_2f0f15b8 + 0x1030,PTR_LAB_2f0f15b8 + 0x10c8);
      if (iVar5 == 0) {
        piVar26 = (int *)(*(code *)PTR___errno_location_2f0f1730)();
        if (*piVar26 - 2U < 2) {
          uVar19 = 0;
          uVar16 = 0;
LAB_2f0d88b4:
          uVar15 = puVar6[0xd];
          if (uVar15 == 0) {
            iVar5 = (*(code *)PTR_fopen64_2f0f162c)
                              (PTR_LAB_2f0f15b8 + 0x108c,PTR_LAB_2f0f15b8 + 0x10c8);
            if (iVar5 == 0) {
              iVar17 = 0xe;
              piVar26 = (int *)(*(code *)PTR___errno_location_2f0f1730)();
              if (*piVar26 - 2U < 2) {
                uVar15 = puVar6[0xd];
                goto joined_r0x2f0d8d88;
              }
            }
            else {
              local_44 = &local_ec;
              local_40 = auStack_e0;
              puVar22 = PTR_LAB_2f0f15b8 + 0x10a0;
              puVar27 = PTR_LAB_2f0f15b8 + 0x10a8;
              pcVar24 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260);
              puVar29 = PTR_LAB_2f0f15b8 + 0x10ac;
              while (iVar17 = (*(code *)PTR_LAB_2f0f15bc)(iVar5,local_44,local_40), iVar17 == 0) {
                iVar17 = (*pcVar24)(local_ec);
                if ((iVar17 != 0) && (puVar6[0xd] == 0)) {
                  (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6e0c))
                            (puVar6,iVar17,puVar27,puVar29);
                }
              }
              (*(code *)PTR_fclose_2f0f16b4)(iVar5,puVar22);
              if (iVar17 == 0xd) {
                uVar15 = puVar6[0xd];
                goto joined_r0x2f0d8d88;
              }
            }
          }
          else {
joined_r0x2f0d8d88:
            if (uVar15 == 0) {
              iVar5 = (*(code *)PTR_fopen64_2f0f162c)
                                (PTR_LAB_2f0f15b8 + 0x10b4,PTR_LAB_2f0f15b8 + 0x10c8);
              if (iVar5 != 0) {
                local_3c = &local_ec;
                local_38 = auStack_e0;
                pcVar24 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260);
                puVar22 = PTR_LAB_2f0f15b8 + 0x10c4;
                puVar27 = PTR_LAB_2f0f15b8 + 0x1054;
                puVar29 = PTR_LAB_2f0f15b8 + 0x10cc;
                while (iVar17 = (*(code *)PTR_LAB_2f0f15bc)(iVar5,local_3c,local_38), iVar17 == 0) {
                  iVar17 = (*pcVar24)(local_ec);
                  if ((iVar17 != 0) && (puVar6[0xd] == 0)) {
                    (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6e0c))
                              (puVar6,iVar17,puVar27,puVar29);
                  }
                }
                (*(code *)PTR_fclose_2f0f16b4)(iVar5,puVar22);
                if (iVar17 != 0xd) goto LAB_2f0d8538;
LAB_2f0d8c68:
                uVar15 = puVar6[0xd];
                goto joined_r0x2f0d8c6c;
              }
              piVar26 = (int *)(*(code *)PTR___errno_location_2f0f1730)();
              if (*piVar26 - 2U < 2) goto LAB_2f0d8c68;
LAB_2f0d934c:
              iVar17 = 0xe;
            }
            else {
joined_r0x2f0d8c6c:
              if (uVar15 == 0) {
                iVar5 = (*(code *)PTR_fopen64_2f0f162c)
                                  (PTR_LAB_2f0f15b8 + 0x10d4,PTR_LAB_2f0f15b8 + 0x10c8);
                if (iVar5 == 0) {
                  piVar26 = (int *)(*(code *)PTR___errno_location_2f0f1730)();
                  if (1 < *piVar26 - 2U) goto LAB_2f0d934c;
                  iVar17 = 0xd;
                }
                else {
                  local_34 = &local_ec;
                  local_30 = auStack_e0;
                  puVar22 = PTR_LAB_2f0f15b8 + 0x10e4;
                  pcVar24 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260);
                  puVar27 = PTR_LAB_2f0f15b8 + 0x1054;
                  puVar29 = PTR_LAB_2f0f15b8 + 0x10ec;
                  while (iVar17 = (*(code *)PTR_LAB_2f0f15bc)(iVar5,local_34,local_30), iVar17 == 0)
                  {
                    iVar17 = (*pcVar24)(local_ec);
                    if ((iVar17 != 0) && (puVar6[0xd] == 0)) {
                      (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6e0c))
                                (puVar6,iVar17,puVar27,puVar29);
                    }
                  }
                  (*(code *)PTR_fclose_2f0f16b4)(iVar5,puVar22);
                }
              }
              else {
                iVar17 = 0xd;
              }
            }
          }
        }
        else {
          iVar17 = 0xe;
          uVar19 = 0;
          uVar16 = 0;
        }
      }
      else {
        local_68 = &local_ec;
        local_64 = auStack_e0;
        uVar19 = 0;
        uVar16 = 0;
LAB_2f0d8464:
        do {
          iVar17 = (*(code *)PTR_LAB_2f0f15bc)(iVar5,local_68,local_64);
          if (iVar17 != 0) break;
          pcVar10 = (char *)(*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                                      (local_ec,PTR_LAB_2f0f15b8 + 0x1044);
          if (pcVar10 == (char *)0x0) {
            iVar28 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                               (local_ec,PTR_LAB_2f0f15b8 + 0x104c);
            if ((iVar28 == 0) || (puVar6[0xd] != 0)) {
              pcVar10 = (char *)(*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                                          (local_ec,PTR_LAB_2f0f15b8 + 0x1064);
              if (pcVar10 != (char *)0x0) goto LAB_2f0d8500;
              pbVar11 = (byte *)(*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                                          (local_ec,PTR_LAB_2f0f15b8 + 0x106c);
              if ((pbVar11 == (byte *)0x0) || (puVar6[0x10] != 0xffffffff)) {
                pcVar10 = (char *)(*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                                            (local_ec,PTR_LAB_2f0f15b8 + 0x1078);
                if ((pcVar10 != (char *)0x0) && (puVar6[0xc] == 0xffffffff)) {
                  local_5c = local_f0;
                  local_58 = local_b0;
                  local_54 = local_90;
                  local_50 = &local_e4;
                  local_4c = &local_e8;
                  local_48 = local_80;
                  uVar15 = (uint)*pcVar10;
                  local_60 = local_d4;
                  while ((uVar15 != 0 && (uVar15 != 0x3b))) {
                    pcVar14 = pcVar10;
                    if (uVar15 != 0x2f) {
                      piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                      do {
                        pcVar13 = pcVar14 + 1;
                        if ((((*(ushort *)(*piVar26 + (uVar15 & 0xff) * 2) & 0x2000) != 0) ||
                            (uVar15 = (uint)*pcVar13, pcVar14 = pcVar13, uVar15 == 0)) ||
                           (uVar15 == 0x2f)) break;
                      } while (uVar15 != 0x3b);
                    }
                    (*(code *)PTR_memcpy_2f0f16ac)(local_60,pcVar10,(int)pcVar14 - (int)pcVar10);
                    *(undefined1 *)((int)local_5c + ((int)pcVar14 - (int)pcVar10) + 0x1c) = 0;
                    if (*pcVar14 == '/') {
                      pcVar13 = pcVar14 + 1;
                      piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                      uVar15 = 0x2f;
                      do {
                        pcVar25 = pcVar14 + 1;
                        if (((*(ushort *)(*piVar26 + (uVar15 & 0xff) * 2) & 0x2000) != 0) ||
                           (uVar15 = (uint)*pcVar25, pcVar14 = pcVar25, uVar15 == 0)) break;
                      } while (uVar15 != 0x3b);
                      (*(code *)PTR_memcpy_2f0f16ac)(local_58,pcVar10,(int)pcVar14 - (int)pcVar10);
                      *(undefined1 *)((int)local_5c + ((int)pcVar14 - (int)pcVar10) + 0x40) = 0;
                      pcVar10 = local_58;
                      if (local_b0[0] == '\0') goto LAB_2f0d8e80;
                    }
                    else {
                      local_b0[0] = '\0';
                      pcVar13 = pcVar10;
LAB_2f0d8e80:
                      pcVar10 = local_60;
                    }
                    iVar17 = (*(code *)PTR_LAB_2f0f15f0)(10,pcVar10,local_54,0x10);
                    if (0 < iVar17) {
                      local_80[0] = CONCAT22(local_80[0]._2_2_,(short)iVar17);
                      local_70 = 10;
                      local_6c = 2;
                      iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7664))
                                         (local_50,local_4c,local_54);
                      if (iVar17 != 0) goto LAB_2f0d8ed8;
LAB_2f0d9304:
                      iVar17 = 0xf;
                      goto LAB_2f0d8520;
                    }
LAB_2f0d8ed8:
                    pcVar10 = pcVar14;
                    if ((local_b0[0] == '\0') ||
                       (iVar17 = (*(code *)PTR_LAB_2f0f15f0)(2,local_58,local_54,4), iVar17 < 1)) {
                      iVar28 = (int)pcVar14 - (int)pcVar13;
                      iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7760))
                                         (local_60,iVar28,local_54);
                      if (iVar17 == 0) {
                        if (local_b0[0] == '\0') {
LAB_2f0d8fac:
                          if ((int)(local_90[0] << 0x18 | local_90[0] >> 0x18 |
                                    (local_90[0] & 0xff0000) >> 8 | (local_90[0] & 0xff00) << 8) < 0
                             ) {
                            if ((local_90[0] << 0x18 & 0xc0000000) == 0x80000000) {
                              local_80[0] = 0xffff;
                            }
                            else {
                              local_80[0] = 0xffffff;
                            }
                          }
                          else {
                            local_80[0] = 0xff;
                          }
                        }
                        else {
                          (*(code *)PTR_memcpy_2f0f16ac)(local_60,pcVar13,iVar28);
                          *(undefined1 *)((int)local_5c + iVar28 + 0x1c) = 0;
                          iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7760))
                                             (local_60,iVar28,local_48);
                          if (iVar17 != 0) goto LAB_2f0d8fac;
                        }
                        local_6c = 1;
                        goto LAB_2f0d8f24;
                      }
                      uVar12 = (uint)*pcVar14;
                      if (uVar12 == 0) {
                        piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                        iVar17 = *piVar26;
                        uVar15 = 0;
                      }
                      else if (uVar12 == 0x3b) {
                        uVar15 = 0x3b;
                        piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                        iVar17 = *piVar26;
                      }
                      else {
                        piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                        iVar17 = *piVar26;
                        do {
                          pcVar10 = pcVar14 + 1;
                          if ((*(ushort *)(iVar17 + (uVar12 & 0xff) * 2) & 0x2000) != 0) {
                            uVar15 = (uint)*pcVar14;
                            pcVar10 = pcVar14;
                            goto LAB_2f0d8f58;
                          }
                          uVar12 = (uint)*pcVar10;
                          uVar15 = 0;
                          if (uVar12 == 0) goto LAB_2f0d8f58;
                          pcVar14 = pcVar10;
                        } while (uVar12 != 0x3b);
                        uVar15 = 0x3b;
                      }
                    }
                    else {
                      local_80[0] = CONCAT22(local_80[0]._2_2_,(short)iVar17);
                      local_6c = 2;
LAB_2f0d8f24:
                      local_70 = 2;
                      iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7664))
                                         (local_50,local_4c,local_54);
                      if (iVar17 == 0) goto LAB_2f0d9304;
                      piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                      iVar17 = *piVar26;
                      uVar15 = (uint)*pcVar14;
                    }
LAB_2f0d8f58:
                    while ((*(ushort *)(iVar17 + (uVar15 & 0xff) * 2) & 0x2000) != 0) {
                      uVar15 = (uint)pcVar10[1];
                      pcVar10 = pcVar10 + 1;
                    }
                  }
                  goto LAB_2f0d8464;
                }
                iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7260))
                                   (local_ec,PTR_LAB_2f0f15b8 + 0x1084);
                if (iVar17 == 0) goto LAB_2f0d8464;
                iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x7054))(puVar6,iVar17);
              }
              else {
                do {
                  bVar2 = *pbVar11;
                  uVar15 = (uint)(char)bVar2;
                  if (uVar15 == 0) break;
                  piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
                  pbVar23 = pbVar11;
                  while (((*(ushort *)(*piVar26 + (uint)bVar2 * 2) & 0x2000) != 0 ||
                         (pbVar11 = pbVar23, uVar15 == 0x2c))) {
                    pbVar23 = pbVar23 + 1;
                    bVar2 = *pbVar23;
                    uVar15 = (uint)(char)bVar2;
                    if (uVar15 == 0) goto LAB_2f0d8518;
                  }
                  do {
                    if (((*(ushort *)(*piVar26 + (uVar15 & 0xff) * 2) & 0x2000) != 0) ||
                       (uVar15 == 0x2c)) {
                      *pbVar11 = 0;
                      pbVar11 = pbVar11 + 1;
                      goto LAB_2f0d91a8;
                    }
                    uVar15 = (uint)(char)pbVar11[1];
                    pbVar11 = pbVar11 + 1;
                  } while (uVar15 != 0);
                  pbVar11 = (byte *)0x0;
LAB_2f0d91a8:
                  iVar28 = (*(code *)PTR_ares_inet_pton_2f0f16dc)(2,pbVar23,&local_c0);
                  if (iVar28 == 1) {
                    local_c4 = 2;
LAB_2f0d91d0:
                    uVar12 = uVar19 + 1;
                    uVar15 = (*(code *)PTR_realloc_2f0f170c)(uVar16,uVar12 * 0x50);
                    if (uVar15 == 0) {
                      iVar17 = 0xf;
                      break;
                    }
                    piVar26 = (int *)(uVar15 + uVar19 * 0x50);
                    *piVar26 = local_c4;
                    uVar16 = uVar15;
                    uVar19 = uVar12;
                    if (local_c4 == 2) {
                      piVar26[1] = local_c0;
                    }
                    else {
                      piVar26[1] = local_c0;
                      piVar26[4] = local_b4;
                      piVar26[2] = local_bc;
                      piVar26[3] = local_b8;
                    }
                  }
                  else {
                    iVar28 = (*(code *)PTR_ares_inet_pton_2f0f16dc)(10,pbVar23,&local_c0);
                    if (iVar28 == 1) {
                      local_c4 = 10;
                      goto LAB_2f0d91d0;
                    }
                  }
                } while (pbVar11 != (byte *)0x0);
              }
            }
            else {
              iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6e0c))
                                 (puVar6,iVar28,PTR_LAB_2f0f15b8 + 0x1054,PTR_LAB_2f0f15b8 + 0x105c)
              ;
            }
          }
          else {
            uVar15 = (uint)*pcVar10;
            pcVar14 = pcVar10;
            if (uVar15 != 0) {
              piVar26 = (int *)(*(code *)PTR___ctype_b_loc_2f0f16bc)();
              do {
                pcVar13 = pcVar14 + 1;
                if ((*(ushort *)(*piVar26 + (uVar15 & 0xff) * 2) & 0x2000) != 0) break;
                uVar15 = (uint)*pcVar13;
                pcVar14 = pcVar13;
              } while (uVar15 != 0);
            }
            *pcVar14 = '\0';
LAB_2f0d8500:
            iVar17 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f0f15b4 + 0x6b28))(puVar6,pcVar10);
          }
LAB_2f0d8518:
        } while (iVar17 == 0);
LAB_2f0d8520:
        (*(code *)PTR_fclose_2f0f16b4)(iVar5);
        if (iVar17 == 0xd) goto LAB_2f0d88b4;
      }
LAB_2f0d8538:
      if (local_ec != 0) {
        (*(code *)PTR_free_2f0f16d0)();
      }
      if (iVar17 == 0xd) {
        if (uVar16 != 0) {
          puVar6[0xf] = uVar16;
          puVar6[0x10] = uVar19;
        }
        if (local_e4 != 0) {
          uVar15 = puVar6[1];
          uVar12 = puVar6[2];
          uVar19 = puVar6[3];
          uVar16 = puVar6[0x10];
          puVar6[0xb] = local_e4;
          puVar6[0xc] = local_e8;
          goto LAB_2f0d7de8;
        }
      }
      else {
        if (uVar16 != 0) {
          (*(code *)PTR_free_2f0f16d0)(uVar16);
        }
        if (local_e4 != 0) {
          (*(code *)PTR_free_2f0f16d0)();
        }
      }
LAB_2f0d7ff8:
      uVar15 = puVar6[1];
      goto LAB_2f0d7ffc;
    }
  }
  else {
    uVar19 = (*(code *)PTR___strdup_2f0f1630)(param_2[0xb]);
    puVar6[0xd] = uVar19;
    if (uVar19 != 0) goto LAB_2f0d7d14;
    uVar15 = puVar6[1];
LAB_2f0d7ffc:
    uVar12 = puVar6[2];
    uVar19 = puVar6[3];
    uVar16 = puVar6[0x10];
  }
LAB_2f0d7de8:
  if (*puVar6 == 0xffffffff) {
    *puVar6 = 0;
  }
  if (uVar15 == 0xffffffff) {
    puVar6[1] = 5000;
  }
  if (uVar12 == 0xffffffff) {
    puVar6[2] = 4;
  }
  if (uVar19 == 0xffffffff) {
    puVar6[3] = 1;
  }
  if (puVar6[4] == 0xffffffff) {
    puVar6[4] = 0;
  }
  if (puVar6[5] == 0xffffffff) {
    puVar6[5] = 0x3500;
  }
  if (puVar6[6] == 0xffffffff) {
    puVar6[6] = 0x3500;
  }
  if (uVar16 == 0xffffffff) {
    puVar8 = (undefined4 *)(*(code *)PTR_malloc_2f0f167c)(0x50);
    puVar6[0xf] = (uint)puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      puVar8[1] = 0x100007f;
      *puVar8 = 2;
      puVar6[0x10] = 1;
      goto LAB_2f0d7e58;
    }
    iVar17 = 0xf;
    iVar5 = 0;
  }
  else {
LAB_2f0d7e58:
    puVar22 = PTR_malloc_2f0f167c;
    iVar5 = 0;
    if (puVar6[10] == 0xffffffff) {
      puVar6[10] = 0;
      iVar28 = (*(code *)puVar22)(0x40);
      if (iVar28 == 0) {
LAB_2f0d8c44:
        iVar17 = 0xf;
      }
      else {
        iVar17 = (*(code *)PTR_gethostname_2f0f1678)(iVar28,0x40);
        if (iVar17 == -1) {
          piVar26 = (int *)(*(code *)PTR___errno_location_2f0f1730)();
          if ((*piVar26 != 0x4e) && (*piVar26 != 0x16)) goto LAB_2f0d8c20;
          iVar5 = (*(code *)PTR_realloc_2f0f170c)(iVar28,0x80);
          if (iVar5 == 0) goto LAB_2f0d8c44;
        }
        else {
          iVar5 = iVar28;
          if (iVar17 != 0) {
LAB_2f0d8c20:
            iVar17 = 8;
            goto LAB_2f0d8be0;
          }
        }
        iVar17 = (*(code *)PTR_strchr_2f0f1708)(iVar5,0x2e);
        if (iVar17 == 0) goto LAB_2f0d7e68;
        puVar8 = (undefined4 *)(*(code *)PTR_malloc_2f0f167c)(4);
        puVar6[9] = (uint)puVar8;
        if (puVar8 != (undefined4 *)0x0) {
          uVar9 = (*(code *)PTR___strdup_2f0f1630)(iVar17 + 1);
          piVar26 = (int *)puVar6[9];
          *puVar8 = uVar9;
          if (*piVar26 != 0) {
            puVar6[10] = 1;
            goto LAB_2f0d7e68;
          }
        }
        iVar17 = 0xf;
        iVar28 = iVar5;
      }
    }
    else {
LAB_2f0d7e68:
      if (puVar6[0xc] == 0xffffffff) {
        puVar6[0xb] = 0;
        puVar6[0xc] = 0;
      }
      iVar17 = 0;
      if (puVar6[0xd] != 0) goto LAB_2f0d7e84;
      puVar7 = (undefined1 *)(*(code *)PTR_malloc_2f0f167c)(3);
      puVar22 = PTR_LAB_2f0f15b8;
      if (puVar7 != (undefined1 *)0x0) {
        puVar6[0xd] = (uint)puVar7;
        iVar17 = 0;
        uVar4 = puVar22[0x10f4];
        uVar1 = puVar22[0x10f5];
        puVar7[2] = puVar22[0x10f6];
        *puVar7 = uVar4;
        puVar7[1] = uVar1;
        goto LAB_2f0d7e84;
      }
      puVar6[0xd] = 0;
      iVar17 = 0xf;
      iVar28 = iVar5;
    }
LAB_2f0d8be0:
    iVar5 = iVar28;
    if (puVar6[0xf] != 0) {
      (*(code *)PTR_free_2f0f16d0)();
    }
  }
  if (((int *)puVar6[9] != (int *)0x0) &&
     ((iVar28 = *(int *)puVar6[9], iVar28 == 0 ||
      ((*(code *)PTR_free_2f0f16d0)(iVar28), puVar6[9] != 0)))) {
    (*(code *)PTR_free_2f0f16d0)();
  }
  if (puVar6[0xd] != 0) {
    (*(code *)PTR_free_2f0f16d0)();
  }
LAB_2f0d7e84:
  if (iVar5 != 0) {
    (*(code *)PTR_free_2f0f16d0)(iVar5);
  }
  if (iVar17 == 0) {
    iVar5 = (*(code *)PTR_calloc_2f0f16f8)(1,0x1f);
    if (iVar5 != 0) {
      iVar17 = 0;
      do {
        cVar3 = (char)iVar17;
        *(char *)((int)puVar6 + iVar17 + 0x46) = cVar3;
        iVar28 = iVar17 + 8;
        *(char *)((int)puVar6 + iVar17 + 0x47) = cVar3 + '\x01';
        *(char *)((int)puVar6 + iVar17 + 0x48) = cVar3 + '\x02';
        *(char *)((int)puVar6 + iVar17 + 0x49) = cVar3 + '\x03';
        *(char *)((int)puVar6 + iVar17 + 0x4a) = cVar3 + '\x04';
        *(char *)((int)puVar6 + iVar17 + 0x4b) = cVar3 + '\x05';
        *(char *)((int)puVar6 + iVar17 + 0x4c) = cVar3 + '\x06';
        *(char *)((int)puVar6 + iVar17 + 0x4d) = cVar3 + '\a';
        iVar17 = iVar28;
      } while (iVar28 != 0x100);
      uVar4 = (*(code *)PTR_rand_2f0f164c)();
      *(undefined1 *)((int)puVar6 + 0x46) = uVar4;
      iVar17 = 1;
      do {
        uVar4 = (*(code *)PTR_rand_2f0f164c)();
        *(undefined1 *)((int)puVar6 + iVar17 + 0x46) = uVar4;
        uVar4 = (*(code *)PTR_rand_2f0f164c)();
        puVar22 = PTR_rand_2f0f164c;
        *(undefined1 *)((int)puVar6 + iVar17 + 0x47) = uVar4;
        uVar4 = (*(code *)puVar22)();
        puVar22 = PTR_rand_2f0f164c;
        *(undefined1 *)((int)puVar6 + iVar17 + 0x48) = uVar4;
        uVar4 = (*(code *)puVar22)();
        puVar22 = PTR_rand_2f0f164c;
        *(undefined1 *)((int)puVar6 + iVar17 + 0x49) = uVar4;
        iVar28 = iVar17 + 5;
        uVar4 = (*(code *)puVar22)();
        *(undefined1 *)((int)puVar6 + iVar17 + 0x4a) = uVar4;
        iVar17 = iVar28;
      } while (iVar28 != 0x1f);
      *(undefined1 *)((int)puVar6 + 0x146) = 0;
      *(undefined1 *)((int)puVar6 + 0x147) = 0;
      uVar19 = 0;
      uVar16 = 0;
      puVar20 = puVar6;
      do {
        bVar2 = *(byte *)((int)puVar20 + 0x46);
        uVar16 = uVar16 + bVar2 + (uint)*(byte *)(iVar5 + uVar19) & 0xff;
        *(undefined1 *)((int)puVar20 + 0x46) = *(undefined1 *)((int)puVar6 + uVar16 + 0x46);
        *(byte *)((int)puVar6 + uVar16 + 0x46) = bVar2;
        bVar2 = *(byte *)((int)puVar20 + 0x47);
        puVar21 = puVar20 + 1;
        uVar15 = (uVar19 + 1) % 0x1f;
        uVar19 = uVar16 + bVar2 + (uint)*(byte *)(iVar5 + uVar15) & 0xff;
        *(undefined1 *)((int)puVar20 + 0x47) = *(undefined1 *)((int)puVar6 + uVar19 + 0x46);
        *(byte *)((int)puVar6 + uVar19 + 0x46) = bVar2;
        uVar16 = puVar20[0x12];
        uVar12 = (uVar15 + 1) % 0x1f;
        uVar15 = uVar19 + (byte)uVar16 + (uint)*(byte *)(iVar5 + uVar12) & 0xff;
        *(undefined1 *)(puVar20 + 0x12) = *(undefined1 *)((int)puVar6 + uVar15 + 0x46);
        *(byte *)((int)puVar6 + uVar15 + 0x46) = (byte)uVar16;
        bVar2 = *(byte *)((int)puVar20 + 0x49);
        uVar19 = (uVar12 + 1) % 0x1f;
        uVar16 = uVar15 + bVar2 + (uint)*(byte *)(iVar5 + uVar19) & 0xff;
        *(undefined1 *)((int)puVar20 + 0x49) = *(undefined1 *)((int)puVar6 + uVar16 + 0x46);
        *(byte *)((int)puVar6 + uVar16 + 0x46) = bVar2;
        uVar19 = (uVar19 + 1) % 0x1f;
        puVar20 = puVar21;
      } while (puVar6 + 0x40 != puVar21);
      (*(code *)PTR_free_2f0f16d0)(iVar5);
      local_f0[0] = 0;
      (*(code *)PTR_LAB_2f0f15e0)((int)puVar6 + 0x46,local_f0,2);
      *(undefined2 *)(puVar6 + 0x11) = local_f0[0];
      if (((*puVar6 & 2) != 0) && (1 < (int)puVar6[0x10])) {
        puVar6[0x10] = 1;
      }
      (*(code *)PTR_FUN_2f0f15ec)(puVar6);
      *param_1 = puVar6;
      return 0;
    }
    iVar17 = 0xf;
  }
  if (puVar6[0xf] != 0) {
    (*(code *)PTR_free_2f0f16d0)();
  }
  uVar16 = puVar6[9];
  if (uVar16 != 0) {
    if (0 < (int)puVar6[10]) {
      iVar5 = 0;
      while( true ) {
        iVar28 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        (*(code *)PTR_free_2f0f16d0)(*(undefined4 *)(uVar16 + iVar28));
        if ((int)puVar6[10] <= iVar5) break;
        uVar16 = puVar6[9];
      }
      uVar16 = puVar6[9];
    }
    (*(code *)PTR_free_2f0f16d0)(uVar16);
  }
  if (puVar6[0xb] != 0) {
    (*(code *)PTR_free_2f0f16d0)();
  }
  if (puVar6[0xd] != 0) {
    (*(code *)PTR_free_2f0f16d0)();
  }
  (*(code *)PTR_free_2f0f16d0)(puVar6);
  return iVar17;
}

