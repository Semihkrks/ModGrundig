
int candidate_cmd_ncishash(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  short *psVar10;
  ushort *puVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  short *psVar17;
  short sVar18;
  short *psVar19;
  int iVar20;
  int aiStack_60 [7];
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  
  aiStack_60[3] = 0;
  aiStack_60[4] = 0;
  aiStack_60[5] = 0;
  aiStack_60[0] = 0;
  aiStack_60[1] = 0;
  aiStack_60[2] = 0;
  iVar3 = func_0x8e374838();
  uVar4 = func_0x8e25a1b8(0x140);
  iVar5 = func_0x8e25a1b8(0x200);
  iVar6 = func_0x8e25a1b8(0x200);
  if (param_3 < 4) {
    func_0x8e2599a0(0x8e3a1d8c);
    func_0x8e259f78(iVar6);
    func_0x8e259f78(uVar4);
    func_0x8e259f78(iVar5);
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
  func_0x8e2878cc(uVar4,iVar3,0x140);
  func_0x8e287854(iVar6,0,0x200);
  cVar1 = *(char *)(iVar3 + 0x37);
  if (cVar1 == '\x01') {
    iVar9 = *(int *)(iVar3 + 0x100);
    func_0x8e2878cc(iVar6,iVar9,
                    (uint)*(ushort *)(iVar9 + 0xc) * (uint)*(ushort *)(iVar9 + 0xe) + 0x10);
    uVar14 = *(undefined4 *)(param_4 + 4);
  }
  else {
    uVar14 = *(undefined4 *)(param_4 + 4);
  }
  uVar14 = func_0x8e288154(uVar14,0,0x10);
  uVar7 = func_0x8e288154(*(undefined4 *)(param_4 + 8),0,0x10);
  uVar8 = func_0x8e288154(*(undefined4 *)(param_4 + 0xc),0,0x10);
  sRambf206700 = 1;
  uRambf206704 = 0;
  iVar9 = func_0x8e375d0c(uVar14,uVar7,uVar8,iVar5);
  if ((iVar9 == 0) && (*(char *)(iVar3 + 0x37) != '\0')) {
    uVar15 = (uint)*(ushort *)(*(int *)(iVar3 + 0x100) + 0xc);
    if (uVar15 == *(ushort *)(iVar6 + 0xc)) {
      psVar19 = (short *)(iVar6 + 0x10);
      psVar10 = (short *)(*(int *)(iVar3 + 0x100) + 0x10);
      for (psVar17 = psVar10; (int)psVar17 - (int)psVar10 >> 3 < (int)uVar15; psVar17 = psVar17 + 4)
      {
        if ((((psVar17[2] != psVar19[2]) || (*psVar17 != *psVar19)) || (psVar17[1] != psVar19[1]))
           || (psVar17[3] != psVar19[3])) {
          func_0x8e2599a0(0x8e3a1e9c);
          func_0x8e2599a0(0x8e3a1ee0);
          uStack_34 = 0x8e3a0000;
          func_0x8e2599a0(0x8e3a1efc,*psVar19);
          iStack_30 = -0x71c60000;
          func_0x8e2599a0(0x8e3a1f0c,psVar19[1]);
          func_0x8e2599a0(0x8e3a1f1c,psVar19[2]);
          func_0x8e2599a0(0x8e3a1f2c,psVar19[3]);
          func_0x8e2599a0(0x8e3a1f40);
          func_0x8e2599a0(uStack_34 + 0x1efc,*psVar17);
          func_0x8e2599a0(iStack_30 + 0x1f0c,psVar17[1]);
          func_0x8e2599a0(0x8e3a1f1c,psVar17[2]);
          func_0x8e2599a0(0x8e3a1f2c,psVar17[3]);
          goto LAB_8e24b6d0;
        }
        psVar19 = psVar19 + 4;
      }
      iVar9 = *(int *)(iVar3 + 0x100);
    }
    else {
      func_0x8e2599a0(0x8e3a1e44);
LAB_8e24b6d0:
      func_0x8e25f5d0(0x8e3a1e88,0);
      iVar9 = *(int *)(iVar3 + 0x100);
    }
    for (puVar11 = (ushort *)(iVar9 + 0x10);
        (uVar15 = (int)puVar11 - (iVar9 + 0x10) >> 3,
        (int)uVar15 < (int)(uint)*(ushort *)(iVar9 + 0xc) && (puVar11[2] != 6));
        puVar11 = puVar11 + 4) {
    }
    if (uVar15 == *(ushort *)(iVar9 + 0xc)) {
      func_0x8e2599a0(0x8e3a1de4);
LAB_8e24ba84:
      *(undefined1 *)(iVar5 + 0x65) = 0;
      *(undefined1 *)(iVar5 + 0x66) = 0;
      *(undefined1 *)(iVar5 + 0x67) = 0;
      sRambf206700 = 8;
      uRambf206704 = 0;
      iVar9 = func_0x8e375648(iVar5);
      if (iVar9 != 0) {
        uVar14 = 0x8e3a2170;
        goto LAB_8e24bab8;
      }
      uRambf206704 = 1;
    }
    else {
      aiStack_60[6] = *puVar11 + 4 + (int)((uint)puVar11[1] + (uint)puVar11[3] + -4) / 2;
      uRambf206704 = 1;
      iStack_40 = 0;
LAB_8e24b7a0:
      if (7 < param_3) {
        aiStack_60[3] = func_0x8e288154(*(undefined4 *)(param_4 + 0x10),0,0x10);
        aiStack_60[4] = func_0x8e288154(*(undefined4 *)(param_4 + 0x18),0,0x10);
        aiStack_60[5] = aiStack_60[4] + 0x10000;
        aiStack_60[0] = func_0x8e288154(*(undefined4 *)(param_4 + 0x14),0,0x10);
        aiStack_60[1] = 0x10000;
        aiStack_60[2] = func_0x8e288154(*(undefined4 *)(param_4 + 0x1c),0,0x10);
        aiStack_60[2] = aiStack_60[2] + -0x10000;
        uVar15 = 0;
        if (param_3 != 8) {
          uVar15 = func_0x8e288154(*(undefined4 *)(param_4 + 0x20),0,0x10);
        }
        uVar16 = iVar5 + 0x8bU & 3;
        puVar2 = (uint *)((iVar5 + 0x8bU) - uVar16);
        *puVar2 = *puVar2 & -1 << (uVar16 + 1) * 8 | uVar15 >> (3 - uVar16) * 8;
        uVar16 = iVar5 + 0x88U & 3;
        puVar2 = (uint *)((iVar5 + 0x88U) - uVar16);
        *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar16) * 8 | uVar15 << uVar16 * 8;
        sVar18 = 3;
        uVar16 = 0;
        uVar15 = 10;
        iStack_44 = iVar5;
        do {
          while( true ) {
            iVar9 = func_0x8e379a40(uVar15 & 0xffff);
            if (iVar9 != 0) break;
            uVar15 = uVar15 + 1;
          }
          uRambf206704 = 0;
          uVar12 = uVar15;
          sRambf206700 = sVar18 + -1;
          if (uVar16 == 2) {
            while (uVar12 < (uint)aiStack_60[6]) {
              iVar9 = func_0x8e379a40(uVar12 & 0xffff);
              if (iVar9 == 1) {
                iVar9 = func_0x8e380eb4(uVar12 << (*(byte *)(iVar3 + 0xaa) & 0x1f));
                if (iVar9 == 0) {
                  uVar12 = uVar12 + 1;
                }
                else {
                  func_0x8e379d3c(uVar12 & 0xffff);
                  uVar12 = uVar12 + 1;
                }
              }
              else {
                uVar12 = uVar12 + 1;
              }
            }
          }
          func_0x8e2599a0(0x8e3a20f8,uVar16,uVar15);
          iStack_3c = aiStack_60[uVar16 + 3];
          iVar20 = aiStack_60[uVar16];
          uStack_38 = uVar16 & 0x7f | 0x80;
          iVar9 = func_0x8e376378(uVar15 << (*(byte *)(iVar3 + 0xaa) & 0x1f),iStack_3c,iVar20,
                                  uStack_38);
          if (iVar9 != 0) {
            func_0x8e2599a0(0x8e3a2114,uVar16,uVar15);
            goto LAB_8e24bac4;
          }
          *(char *)(iStack_44 + 0x7c) = (char)uVar15;
          uVar12 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                   (uint)*(byte *)(iVar3 + 0x96);
          uVar12 = (uint)((1 << (uVar12 & 0x1f)) + -1 + iVar20) >> (uVar12 & 0x1f);
          while (uVar12 != 0) {
            uStack_34 = uVar12;
            iVar13 = func_0x8e379a40(uVar15 & 0xffff);
            uVar15 = uVar15 + 1;
            uVar12 = uStack_34 - (iVar13 != 0);
          }
          if ((uVar16 == 2) &&
             (uVar12 = uVar15 - 1, uVar15 = aiStack_60[6], (uint)aiStack_60[6] <= uVar12)) {
            uVar14 = 0x8e3a2134;
            goto LAB_8e24bab8;
          }
          while (iVar9 = func_0x8e379a40(uVar15 & 0xffff), iVar9 == 0) {
            uVar15 = uVar15 + 1;
          }
          uRambf206704 = 0;
          sRambf206700 = sVar18;
          func_0x8e2599a0(0x8e3a2150,uVar16,uVar15);
          func_0x8e376378(uVar15 << (*(byte *)(iVar3 + 0xaa) & 0x1f),iStack_3c,iVar20,uStack_38);
          *(char *)(iStack_44 + 0x7d) = (char)uVar15;
          uVar12 = ((uint)*(byte *)(iVar3 + 0xaa) + (uint)*(byte *)(iVar3 + 0xac)) -
                   (uint)*(byte *)(iVar3 + 0x96);
          for (uVar12 = (uint)((1 << (uVar12 & 0x1f)) + -1 + iVar20) >> (uVar12 & 0x1f); uVar12 != 0
              ; uVar12 = uVar12 - (iVar9 != 0)) {
            iVar9 = func_0x8e379a40(uVar15 & 0xffff);
            uVar15 = uVar15 + 1;
          }
          sVar18 = sVar18 + 2;
          iStack_44 = iStack_44 + 2;
          uVar16 = uVar16 + 1;
        } while (uVar16 != 3);
      }
      if (iStack_40 == 0) goto LAB_8e24ba84;
    }
    func_0x8e26b34c(iRam8e3ce9a4 * 0x1b40 + -0x713b3808);
    func_0x8e266a5c();
    sRambf206700 = 0x3697;
    uRambf206704 = 0x2454;
    func_0x8e259f78(uVar4);
    func_0x8e259f78(iVar5);
    func_0x8e259f78(iVar6);
    iVar9 = 0;
  }
  else {
    if (*(char *)(iVar3 + 0x14) == -1) {
      uVar14 = 0x8e3a20c0;
    }
    else if (cVar1 == '\x01') {
      for (puVar11 = (ushort *)(iVar6 + 0x10);
          (uVar15 = (int)puVar11 - (iVar6 + 0x10) >> 3,
          (int)uVar15 < (int)(uint)*(ushort *)(iVar6 + 0xc) && (puVar11[2] != 6));
          puVar11 = puVar11 + 4) {
      }
      if (uVar15 != *(ushort *)(iVar6 + 0xc)) {
        aiStack_60[6] = *puVar11 + 4 + (int)((uint)puVar11[1] + (uint)puVar11[3] + -4) / 2;
        func_0x8e2599a0(0x8e3a1e00);
        iStack_40 = 1;
        goto LAB_8e24b7a0;
      }
      uVar14 = 0x8e3a1de4;
    }
    else {
      uVar14 = 0x8e3a20dc;
    }
LAB_8e24bab8:
    func_0x8e2599a0(uVar14);
LAB_8e24bac4:
    func_0x8e2878cc(iVar3,uVar4,0x140);
    func_0x8e3816d8();
    func_0x8e37e950();
    func_0x8e259f78(uVar4);
    func_0x8e259f78(iVar5);
    func_0x8e259f78(iVar6);
  }
  return iVar9;
}

