
int candidate_cmd_ncisbl(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 uVar16;
  short *psVar17;
  short *psVar18;
  uint uStack_44;
  uint uStack_40;
  
  iVar3 = func_0x8e374838();
  uVar4 = func_0x8e25a1b8(0x140);
  iVar5 = func_0x8e25a1b8(0x200);
  func_0x8e2878cc(uVar4,iVar3,0x140);
  iVar6 = func_0x8e25a1b8(0x400);
  if (param_3 < 3) {
    func_0x8e2599a0(0x8e3a1d8c);
    func_0x8e259f78(iVar6);
    func_0x8e259f78(iVar5);
    func_0x8e259f78(uVar4);
    func_0x8e2599a0(0x8e3a74b0,*param_1,param_1[4]);
    func_0x8e2599a0(0x8e3a74bc,*param_1);
    if (param_1[5] == 0) {
      func_0x8e259978(0x8e3a74c8);
    }
    else {
      func_0x8e259978();
      func_0x8e259948(10);
    }
    return 1;
  }
  func_0x8e287854(iVar6,0,0x200);
  cVar1 = *(char *)(iVar3 + 0x37);
  if (cVar1 == '\x01') {
    iVar8 = *(int *)(iVar3 + 0x100);
    func_0x8e2878cc(iVar6,iVar8,
                    (uint)*(ushort *)(iVar8 + 0xc) * (uint)*(ushort *)(iVar8 + 0xe) + 0x10);
    uVar14 = *(undefined4 *)(param_4 + 4);
  }
  else {
    uVar14 = *(undefined4 *)(param_4 + 4);
  }
  uVar14 = func_0x8e288154(uVar14,0,0x10);
  uVar7 = func_0x8e288154(*(undefined4 *)(param_4 + 8),0,0x10);
  uVar16 = 0;
  if (param_3 != 3) {
    uVar16 = func_0x8e288154(*(undefined4 *)(param_4 + 0xc),0,0x10);
  }
  uRambf206700 = 1;
  uRambf206704 = 0;
  iVar8 = func_0x8e375d0c(uVar14,uVar7,uVar16,iVar5);
  if (iVar8 == 0) {
    if (*(char *)(iVar3 + 0x37) == '\0') {
      if (5 < param_3) {
        uVar14 = 0x8e3a1e28;
        goto LAB_8e24b140;
      }
      iVar12 = *(int *)(iVar3 + 0x100);
    }
    else {
      iVar12 = *(int *)(iVar3 + 0x100);
    }
    if ((uint)*(ushort *)(iVar12 + 0xc) == (uint)*(ushort *)(iVar6 + 0xc)) {
      psVar18 = (short *)(iVar6 + 0x10);
      for (psVar17 = (short *)(iVar12 + 0x10);
          (int)psVar17 - (iVar12 + 0x10) >> 3 < (int)(uint)*(ushort *)(iVar12 + 0xc);
          psVar17 = psVar17 + 4) {
        if ((((psVar17[2] != psVar18[2]) || (*psVar17 != *psVar18)) || (psVar17[1] != psVar18[1]))
           || (psVar17[3] != psVar18[3])) {
          func_0x8e2599a0(0x8e3a1e9c);
          func_0x8e2599a0(0x8e3a1ee0);
          func_0x8e2599a0(0x8e3a1efc,*psVar18);
          func_0x8e2599a0(0x8e3a1f0c,psVar18[1]);
          func_0x8e2599a0(0x8e3a1f1c,psVar18[2]);
          func_0x8e2599a0(0x8e3a1f2c,psVar18[3]);
          func_0x8e2599a0(0x8e3a1f40);
          func_0x8e2599a0(0x8e3a1efc,*psVar17);
          func_0x8e2599a0(0x8e3a1f0c,psVar17[1]);
          func_0x8e2599a0(0x8e3a1f1c,psVar17[2]);
          func_0x8e2599a0(0x8e3a1f2c,psVar17[3]);
          goto LAB_8e24a974;
        }
        psVar18 = psVar18 + 4;
      }
      iVar12 = *(int *)(iVar3 + 0x100);
    }
    else {
      func_0x8e2599a0(0x8e3a1e44);
LAB_8e24a974:
      func_0x8e25f5d0(0x8e3a1e88,0);
      iVar12 = *(int *)(iVar3 + 0x100);
    }
    for (puVar9 = (ushort *)(iVar12 + 0x10);
        (uVar15 = (int)puVar9 - (iVar12 + 0x10) >> 3,
        (int)uVar15 < (int)(uint)*(ushort *)(iVar12 + 0xc) && (puVar9[2] != 6)); puVar9 = puVar9 + 4
        ) {
    }
    if (uVar15 != *(ushort *)(iVar12 + 0xc)) {
      uVar15 = *puVar9 + 2 + (int)((uint)puVar9[1] + (uint)puVar9[3] + -2) / 2;
      uRambf206704 = 1;
      bVar2 = false;
      goto LAB_8e24aa38;
    }
LAB_8e24a9d8:
    uVar14 = 0x8e3a1de4;
  }
  else if ((*(char *)(iVar3 + 0x14) == -1) || (cVar1 != '\x01')) {
    uVar14 = 0x8e3a1da0;
  }
  else {
    for (puVar9 = (ushort *)(iVar6 + 0x10);
        (uVar15 = (int)puVar9 - (iVar6 + 0x10) >> 3,
        (int)uVar15 < (int)(uint)*(ushort *)(iVar6 + 0xc) && (puVar9[2] != 6)); puVar9 = puVar9 + 4)
    {
    }
    if (uVar15 == *(ushort *)(iVar6 + 0xc)) goto LAB_8e24a9d8;
    uVar15 = *puVar9 + 2 + (int)((uint)puVar9[1] + (uint)puVar9[3] + -2) / 2;
    func_0x8e2599a0(0x8e3a1e00);
    bVar2 = true;
LAB_8e24aa38:
    if (param_3 == 6) {
      uStack_40 = 10;
      while (iVar8 = func_0x8e379a40(uStack_40 & 0xffff), iVar8 == 0) {
        uStack_40 = uStack_40 + 1;
      }
      uVar14 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
      uRambf206700 = 2;
      uRambf206704 = 0;
      func_0x8e2599a0(0x8e3a1f5c,uStack_40);
      iVar8 = func_0x8e376378(uStack_40 << (*(byte *)(iVar3 + 0xaa) & 0x1f),uVar14,0x10000,0);
      uVar10 = uStack_40;
      if (iVar8 == 0) {
        uVar10 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                 (uint)*(byte *)(iVar3 + 0x96);
        uStack_44 = uStack_40;
        for (uVar10 = (1 << (uVar10 & 0x1f)) + 0xffffU >> (uVar10 & 0x1f); uVar10 != 0;
            uVar10 = uVar10 - (iVar8 != 0)) {
          iVar8 = func_0x8e379a40(uStack_44 & 0xffff);
          uStack_44 = uStack_44 + 1;
        }
        while (iVar8 = func_0x8e379a40(uStack_44 & 0xffff), iVar8 == 0) {
          uStack_44 = uStack_44 + 1;
        }
        uVar14 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
        uRambf206700 = 3;
        uRambf206704 = 0;
        func_0x8e2599a0(0x8e3a1fa8,uStack_44);
        iVar8 = func_0x8e376378(uStack_44 << (*(byte *)(iVar3 + 0xaa) & 0x1f),uVar14,0x10000,0);
        uVar10 = uStack_44;
        if (iVar8 == 0) {
          uVar11 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                   (uint)*(byte *)(iVar3 + 0x96);
          for (uVar11 = (1 << (uVar11 & 0x1f)) + 0xffffU >> (uVar11 & 0x1f); uVar11 != 0;
              uVar11 = uVar11 - (iVar8 != 0)) {
            iVar8 = func_0x8e379a40(uVar10 & 0xffff);
            uVar10 = uVar10 + 1;
          }
          while (iVar8 = func_0x8e379a40(uVar10 & 0xffff), iVar8 == 0) {
            uVar10 = uVar10 + 1;
          }
          iVar8 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
          iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x14),0,0x10);
          uRambf206700 = 4;
          uRambf206704 = 0;
          uVar11 = uVar10;
          while (uVar11 < uVar15) {
            iVar13 = func_0x8e379a40(uVar11 & 0xffff);
            if (iVar13 == 1) {
              iVar13 = func_0x8e380eb4(uVar11 << (*(byte *)(iVar3 + 0xaa) & 0x1f));
              if (iVar13 == 0) {
                uVar11 = uVar11 + 1;
              }
              else {
                func_0x8e379d3c(uVar11 & 0xffff);
                uVar11 = uVar11 + 1;
              }
            }
            else {
              uVar11 = uVar11 + 1;
            }
          }
          func_0x8e2599a0(0x8e3a2004,uVar10);
          iVar8 = func_0x8e376378(uVar10 << (*(byte *)(iVar3 + 0xaa) & 0x1f),iVar8 + 0x10000,
                                  iVar12 + -0x10000,0xff);
          if (iVar8 == 0) {
            uVar11 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                     (uint)*(byte *)(iVar3 + 0x96);
            for (uVar11 = (uint)((1 << (uVar11 & 0x1f)) + -1 + iVar12 + -0x10000) >> (uVar11 & 0x1f)
                ; uVar11 != 0; uVar11 = uVar11 - (iVar8 != 0)) {
              iVar8 = func_0x8e379a40(uVar10 & 0xffff);
              uVar10 = uVar10 + 1;
            }
            if (uVar15 <= uVar10 - 1) {
LAB_8e24acd4:
              func_0x8e2599a0(0x8e3a2048);
              iVar8 = 0;
              goto LAB_8e24b1c4;
            }
            while (iVar8 = func_0x8e379a40(uVar15 & 0xffff), iVar8 == 0) {
              uVar15 = uVar15 + 1;
            }
            iVar8 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
            iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x14),0,0x10);
            uRambf206700 = 5;
            uRambf206704 = 0;
            func_0x8e2599a0(0x8e3a2064,uVar15);
            iVar8 = iVar8 + 0x10000;
            iVar13 = uVar15 << (*(byte *)(iVar3 + 0xaa) & 0x1f);
            iVar12 = iVar12 + -0x10000;
            uVar10 = uVar15;
LAB_8e24b0ac:
            iVar8 = func_0x8e376378(iVar13,iVar8,iVar12,0xff);
            if (iVar8 == 0) {
              *(char *)(iVar5 + 0x65) = (char)uStack_40;
              *(char *)(iVar5 + 0x67) = (char)uVar10;
              *(char *)(iVar5 + 0x66) = (char)uStack_44;
              func_0x8e2599a0(0x8e3a20b4,uStack_40 & 0xff,uStack_44 & 0xff,uVar10 & 0xff);
              goto LAB_8e24b110;
            }
            uVar14 = 0x8e3a2084;
          }
          else {
LAB_8e24afd8:
            uVar14 = 0x8e3a2020;
          }
        }
        else {
LAB_8e24aebc:
          uVar14 = 0x8e3a1fd0;
        }
      }
      else {
LAB_8e24ade8:
        uVar14 = 0x8e3a1f7c;
      }
      func_0x8e2599a0(uVar14,uVar10);
      goto LAB_8e24b1c4;
    }
    if (param_3 == 8) {
      uStack_40 = 10;
      while (iVar8 = func_0x8e379a40(uStack_40 & 0xffff), iVar8 == 0) {
        uStack_40 = uStack_40 + 1;
      }
      uVar14 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
      iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x14),0,0x10);
      uRambf206700 = 2;
      uRambf206704 = 0;
      func_0x8e2599a0(0x8e3a1f5c,uStack_40);
      iVar8 = func_0x8e376378(uStack_40 << (*(byte *)(iVar3 + 0xaa) & 0x1f),uVar14,iVar12,0);
      uVar10 = uStack_40;
      if (iVar8 == 0) {
        uVar10 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                 (uint)*(byte *)(iVar3 + 0x96);
        uStack_44 = uStack_40;
        for (uVar10 = (uint)((1 << (uVar10 & 0x1f)) + -1 + iVar12) >> (uVar10 & 0x1f); uVar10 != 0;
            uVar10 = uVar10 - (iVar8 != 0)) {
          iVar8 = func_0x8e379a40(uStack_44 & 0xffff);
          uStack_44 = uStack_44 + 1;
        }
        while (iVar8 = func_0x8e379a40(uStack_44 & 0xffff), iVar8 == 0) {
          uStack_44 = uStack_44 + 1;
        }
        uVar14 = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
        iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x14),0,0x10);
        uRambf206700 = 3;
        uRambf206704 = 0;
        func_0x8e2599a0(0x8e3a1fa8,uStack_44);
        iVar8 = func_0x8e376378(uStack_44 << (*(byte *)(iVar3 + 0xaa) & 0x1f),uVar14,iVar12,0);
        uVar10 = uStack_44;
        if (iVar8 == 0) {
          uVar11 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                   (uint)*(byte *)(iVar3 + 0x96);
          for (uVar11 = (uint)((1 << (uVar11 & 0x1f)) + -1 + iVar12) >> (uVar11 & 0x1f); uVar11 != 0
              ; uVar11 = uVar11 - (iVar8 != 0)) {
            iVar8 = func_0x8e379a40(uVar10 & 0xffff);
            uVar10 = uVar10 + 1;
          }
          while (iVar8 = func_0x8e379a40(uVar10 & 0xffff), iVar8 == 0) {
            uVar10 = uVar10 + 1;
          }
          uVar14 = func_0x8e288154(*(undefined4 *)(param_4 + 0x18),0,0x10);
          iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x1c),0,0x10);
          uRambf206700 = 4;
          uRambf206704 = 0;
          uVar11 = uVar10;
          while (uVar11 < uVar15) {
            iVar8 = func_0x8e379a40(uVar11 & 0xffff);
            if (iVar8 == 1) {
              iVar8 = func_0x8e380eb4(uVar11 << (*(byte *)(iVar3 + 0xaa) & 0x1f));
              if (iVar8 == 0) {
                uVar11 = uVar11 + 1;
              }
              else {
                func_0x8e379d3c(uVar11 & 0xffff);
                uVar11 = uVar11 + 1;
              }
            }
            else {
              uVar11 = uVar11 + 1;
            }
          }
          func_0x8e2599a0(0x8e3a2004,uVar10);
          iVar8 = func_0x8e376378(uVar10 << (*(byte *)(iVar3 + 0xaa) & 0x1f),uVar14,iVar12,0xff);
          if (iVar8 == 0) {
            uVar11 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                     (uint)*(byte *)(iVar3 + 0x96);
            for (uVar11 = (uint)((1 << (uVar11 & 0x1f)) + -1 + iVar12) >> (uVar11 & 0x1f);
                uVar11 != 0; uVar11 = uVar11 - (iVar8 != 0)) {
              iVar8 = func_0x8e379a40(uVar10 & 0xffff);
              uVar10 = uVar10 + 1;
            }
            if (uVar10 - 1 < uVar15) {
              while (iVar8 = func_0x8e379a40(uVar15 & 0xffff), iVar8 == 0) {
                uVar15 = uVar15 + 1;
              }
              iVar8 = func_0x8e288154(*(undefined4 *)(param_4 + 0x18),0,0x10);
              iVar12 = func_0x8e288154(*(undefined4 *)(param_4 + 0x1c),0,0x10);
              uRambf206700 = 5;
              uRambf206704 = 0;
              func_0x8e2599a0(0x8e3a2064,uVar15);
              iVar13 = uVar15 << (*(byte *)(iVar3 + 0xaa) & 0x1f);
              uVar10 = uVar15;
              goto LAB_8e24b0ac;
            }
            goto LAB_8e24acd4;
          }
          goto LAB_8e24afd8;
        }
        goto LAB_8e24aebc;
      }
      goto LAB_8e24ade8;
    }
LAB_8e24b110:
    if (bVar2) {
LAB_8e24b164:
      func_0x8e26b34c(iRam8e3ce9a4 * 0x1b40 + -0x713b3808);
      func_0x8e266a5c();
      uRambf206700 = 0x3697;
      uRambf206704 = 0x2454;
      func_0x8e259f78(uVar4);
      func_0x8e259f78(iVar5);
      func_0x8e259f78(iVar6);
      return 0;
    }
    uRambf206700 = 6;
    uRambf206704 = 0;
    iVar8 = func_0x8e375648(iVar5);
    if (iVar8 == 0) {
      uRambf206704 = 1;
      func_0x8e2599a0(0x8e3a1dd4);
      goto LAB_8e24b164;
    }
    uVar14 = 0x8e3a1dbc;
  }
LAB_8e24b140:
  func_0x8e2599a0(uVar14);
LAB_8e24b1c4:
  func_0x8e2878cc(iVar3,uVar4,0x140);
  func_0x8e3816d8();
  func_0x8e37e950();
  func_0x8e259f78(uVar4);
  func_0x8e259f78(iVar5);
  func_0x8e259f78(iVar6);
  return iVar8;
}

