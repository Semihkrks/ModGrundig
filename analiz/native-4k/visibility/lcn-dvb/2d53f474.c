
/* MW_DVB_SI_PSI_Parser::_UpdateServiceInfo(MW_DVB_SERVICE_CHANGE_TYPE, MAPI_SI_TABLE_PMT&,
   MW_DVB_SI_ServicelInfo&) */

void __thiscall
MW_DVB_SI_PSI_Parser::_UpdateServiceInfo
          (MW_DVB_SI_PSI_Parser *this,undefined4 param_2,int param_3,undefined1 *param_4)

{
  short *psVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined1 uVar10;
  short sVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined1 *puVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined1 *puVar20;
  undefined4 *puVar21;
  undefined2 *puVar22;
  undefined4 *puVar23;
  undefined2 *puVar24;
  code *pcVar25;
  
  *param_4 = *(undefined1 *)(param_3 + 4);
  if (*(char *)(param_3 + 7) == '\0') {
    *(undefined4 *)(param_4 + 4) = param_2;
  }
  else {
    *(undefined4 *)(param_4 + 4) = 1;
    *(undefined4 *)(param_4 + 0x2da) = *(undefined4 *)(param_3 + 0x1a4);
    *(undefined2 *)(param_4 + 0x2de) = *(undefined2 *)(param_3 + 0x1a8);
  }
  param_4[8] = 0;
  param_4[9] = 0;
  iVar16 = 0;
  iVar12 = param_3;
  while (((iVar16 = iVar16 + 1, *(short *)(iVar12 + 300) == 0 ||
          (((*(short *)(iVar12 + 0x12e) != 0x106 && (*(short *)(iVar12 + 0x12e) != 0xf0)) ||
           (param_4[9] = 1, *(short *)(iVar12 + 0x12e) != 0x106)))) ||
         ((1 < (ushort)(*(short *)(iVar12 + 0x130) - 0x101U) &&
          (*(short *)(iVar12 + 0x130) != 0x505))))) {
    iVar12 = iVar12 + 0xc;
    if (iVar16 == 10) {
LAB_2d53f538:
      param_4[0xc] = *(undefined1 *)(param_3 + 6);
      iVar12 = (**(code **)(*(int *)this + 700))(this,6,this + 0x168,0);
      if (iVar12 == 1) {
        param_4[10] = param_4[0xc] | param_4[0xd];
      }
      else {
        param_4[10] = param_4[0xc];
      }
      param_4[0xb] = *(undefined1 *)(param_3 + 0xf);
      (**(code **)(*(int *)this + 0x1b8))(this,param_4 + 0x10,param_3 + 0x14);
      param_4[1] = *(undefined1 *)(param_3 + 5);
      iVar12 = *(int *)this;
      *(undefined2 *)(param_4 + 0x18) = *(undefined2 *)(param_3 + 8);
      sVar11 = *(short *)(param_3 + 0x10);
      pcVar25 = *(code **)(iVar12 + 0x1bc);
      if (sVar11 == 0) {
        sVar11 = 0x1fff;
      }
      *(short *)(param_4 + 0x2e6) = sVar11;
      uVar10 = (*pcVar25)(this,param_4 + 0x2c,param_3 + 0x2c);
      param_4[0x1a] = uVar10;
      iVar12 = 0;
      iVar16 = param_3;
      do {
        iVar17 = iVar12 + 1;
        param_4[iVar12 + 0x1b] = *(undefined1 *)(iVar16 + 0x35);
        iVar16 = iVar16 + 0x10;
        iVar12 = iVar17;
      } while (iVar17 != 0x10);
      puVar21 = (undefined4 *)(param_3 + 0x1aa);
      puVar22 = (undefined2 *)(param_4 + 0x10e);
      puVar23 = (undefined4 *)(param_3 + 0x23a);
      do {
        uVar2 = *(undefined2 *)puVar21;
        uVar3 = *(undefined2 *)((int)puVar21 + 2);
        uVar4 = *(undefined2 *)(puVar21 + 1);
        uVar5 = *(undefined2 *)((int)puVar21 + 6);
        uVar6 = *(undefined2 *)(puVar21 + 2);
        uVar7 = *(undefined2 *)((int)puVar21 + 10);
        uVar8 = *(undefined2 *)(puVar21 + 3);
        uVar9 = *(undefined2 *)((int)puVar21 + 0xe);
        puVar21 = puVar21 + 4;
        *puVar22 = uVar2;
        puVar22[1] = uVar3;
        puVar22[2] = uVar4;
        puVar22[3] = uVar5;
        puVar22[4] = uVar6;
        puVar22[5] = uVar7;
        puVar22[6] = uVar8;
        puVar22[7] = uVar9;
        puVar22 = puVar22 + 8;
      } while (puVar21 != puVar23);
      param_4[0x10c] = 0;
      puVar20 = param_4;
      do {
        psVar1 = (short *)(puVar20 + 0x110);
        puVar20 = puVar20 + 0xc;
        if (*psVar1 != 0) {
          param_4[0x10c] = param_4[0x10c] + '\x01';
        }
      } while (param_4 + 0x90 != puVar20);
      puVar21 = (undefined4 *)(param_4 + 0x1a0);
      do {
        uVar13 = *puVar23;
        uVar14 = puVar23[1];
        uVar18 = puVar23[2];
        uVar19 = puVar23[3];
        puVar23 = puVar23 + 4;
        *puVar21 = uVar13;
        puVar21[1] = uVar14;
        puVar21[2] = uVar18;
        puVar21[3] = uVar19;
        puVar21 = puVar21 + 4;
      } while (puVar23 != (undefined4 *)(param_3 + 0x2ca));
      param_4[0x19e] = 0;
      puVar15 = param_4;
      do {
        psVar1 = (short *)(puVar15 + 0x1a2);
        puVar15 = puVar15 + 0xc;
        if (*psVar1 != 0) {
          param_4[0x19e] = param_4[0x19e] + '\x01';
        }
      } while (puVar20 != puVar15);
      puVar23 = (undefined4 *)(param_3 + 0x2ca);
      puVar22 = (undefined2 *)(param_4 + 0x232);
      do {
        puVar24 = puVar22;
        puVar21 = puVar23;
        uVar2 = *(undefined2 *)((int)puVar21 + 2);
        uVar3 = *(undefined2 *)(puVar21 + 1);
        uVar4 = *(undefined2 *)((int)puVar21 + 6);
        uVar5 = *(undefined2 *)(puVar21 + 2);
        uVar6 = *(undefined2 *)((int)puVar21 + 10);
        uVar7 = *(undefined2 *)(puVar21 + 3);
        uVar8 = *(undefined2 *)((int)puVar21 + 0xe);
        puVar23 = puVar21 + 4;
        *puVar24 = *(undefined2 *)puVar21;
        puVar24[1] = uVar2;
        puVar24[2] = uVar3;
        puVar24[3] = uVar4;
        puVar24[4] = uVar5;
        puVar24[5] = uVar6;
        puVar24[6] = uVar7;
        puVar24[7] = uVar8;
        puVar22 = puVar24 + 8;
      } while (puVar23 != (undefined4 *)(param_3 + 0x36a));
      uVar2 = *(undefined2 *)((int)puVar21 + 0x16);
      uVar3 = *(undefined2 *)((int)puVar21 + 0x12);
      uVar4 = *(undefined2 *)(puVar21 + 5);
      puVar24[8] = *(undefined2 *)puVar23;
      puVar24[0xb] = uVar2;
      puVar24[9] = uVar3;
      puVar24[10] = uVar4;
      param_4[0x230] = 0;
      puVar20 = param_4;
      do {
        psVar1 = (short *)(puVar20 + 0x234);
        puVar20 = puVar20 + 0xe;
        if (*psVar1 != 0) {
          param_4[0x230] = param_4[0x230] + '\x01';
        }
      } while (param_4 + 0xa8 != puVar20);
      return;
    }
  }
  param_4[8] = 1;
  goto LAB_2d53f538;
}

