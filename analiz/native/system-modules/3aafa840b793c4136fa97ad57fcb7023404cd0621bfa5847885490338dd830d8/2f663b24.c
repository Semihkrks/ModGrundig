
/* ArWhiteBalance::UpdateLowLimits(stColorTempParam const&, stColorTempParam&) */

void __thiscall
ArWhiteBalance::UpdateLowLimits
          (ArWhiteBalance *this,stColorTempParam *param_1,stColorTempParam *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  stColorTempParam sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  float in_f0;
  float fVar8;
  float fVar9;
  double dVar10;
  stColorTempParam sVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined1 auStack_80 [64];
  
  puVar1 = PTR_cie_2f670040_2f670978;
  uVar5 = (uint)(byte)*param_1;
  uVar7 = (uint)(byte)param_1[2];
  uVar6 = (uint)(byte)param_1[1];
  if (0x80 < uVar7) {
    uVar7 = 0x80;
  }
  if (0x80 < uVar5) {
    uVar5 = 0x80;
  }
  if (0x80 < uVar6) {
    uVar6 = 0x80;
  }
  (*(code *)PTR_factoryplug_GetRGBGainMaxRatio_2f670b7c)();
  in_f0 = in_f0 - *(float *)(puVar1 + -0x1f28);
  iVar3 = (*(code *)PTR_factoryplug_isRGBGainOffsetLimited_2f670994)();
  if (iVar3 != 0) {
    fVar8 = (float)(int)(short)((short)uVar5 + -0x80) * in_f0 +
            *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
    if (fVar8 < *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)) {
      fVar13 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20);
      fVar9 = (float)(int)(short)((short)uVar6 + -0x80) * in_f0 +
              *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
      uVar5 = (int)fVar8 & 0xff;
      if (fVar9 < fVar13) goto LAB_2f663c38;
LAB_2f6641bc:
      fVar12 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20);
      fVar8 = (float)(int)(short)((short)uVar7 + -0x80) * in_f0 +
              *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
      uVar6 = (int)(fVar9 - fVar13) & 0xff;
      if (fVar8 < fVar12) {
LAB_2f663c6c:
        uVar7 = (int)fVar8 & 0xff;
        goto LAB_2f663c78;
      }
    }
    else {
      fVar13 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20);
      fVar9 = (float)(int)(short)((short)uVar6 + -0x80) * in_f0 +
              *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
      uVar5 = (int)(fVar8 - *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)) & 0xff;
      if (fVar13 <= fVar9) goto LAB_2f6641bc;
LAB_2f663c38:
      fVar12 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20);
      fVar8 = (float)(int)(short)((short)uVar7 + -0x80) * in_f0 +
              *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
      uVar6 = (int)fVar9 & 0xff;
      if (fVar8 < fVar12) goto LAB_2f663c6c;
    }
    uVar7 = (int)(fVar8 - fVar12) & 0xff;
  }
LAB_2f663c78:
  iVar3 = (*(code *)PTR_factoryplug_GetLuminanceTolerance_2f670ae0)();
  fVar8 = (float)((double)iVar3 / *(double *)(PTR_cie_2f670040_2f670978 + -0x1f00));
  iVar3 = (*(code *)PTR_factoryplug_GetWRGBPanelType_2f670af0)();
  puVar2 = PTR_cie_2f670040_2f670978;
  if (iVar3 < 2) {
    fVar8 = fVar8 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f1c);
  }
  fVar13 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f18);
  uVar16 = *(undefined8 *)(PTR_cie_2f670040_2f670978 + -0x1ef8);
  fVar9 = *(float *)(puVar1 + -0x1f28);
  dVar10 = (double)CONCAT44(fVar9,(float)uVar5 * fVar13);
  fVar9 = fVar9 - fVar8;
  (*(code *)PTR_pow_2f670bd4)((double)((float)uVar5 * fVar13),uVar16);
  dVar10 = dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ef0);
  uVar17 = CONCAT44(in_f0,(float)dVar10);
  (*(code *)PTR_pow_2f670bd4)((double)((float)uVar6 * fVar13),uVar16);
  dVar10 = dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ee8);
  dVar14 = (double)((float)uVar7 * fVar13);
  fVar12 = (float)dVar10;
  (*(code *)PTR_pow_2f670bd4)(dVar14,uVar16);
  uVar15 = (undefined4)((ulonglong)dVar14 >> 0x20);
  fVar13 = (float)(dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ee0));
  fVar8 = fVar9 - (fVar12 + fVar13);
  if (0.0 < fVar8) {
    fVar8 = fVar8 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f14);
    dVar10 = (double)(ulonglong)(uint)fVar8;
    dVar14 = (double)fVar8;
    (*(code *)PTR_pow_2f670bd4)(dVar14,*(undefined8 *)(PTR_cie_2f670040_2f670978 + -0x1ed8));
    uVar15 = (undefined4)((ulonglong)dVar14 >> 0x20);
    dVar10 = dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ed0);
    if (*(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8) <= dVar10) {
      sVar11 = SUB41((int)(dVar10 - *(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8)),0);
    }
    else {
      sVar11 = SUB41((int)dVar10,0);
    }
    fVar8 = fVar9 - ((float)uVar17 + fVar13);
    *param_2 = sVar11;
    if (0.0 < fVar8) goto LAB_2f663ddc;
LAB_2f664230:
    fVar9 = fVar9 - ((float)uVar17 + fVar12);
    param_2[1] = (stColorTempParam)0x0;
    if (fVar9 <= 0.0) goto LAB_2f664248;
LAB_2f663e40:
    fVar8 = (float)((ulonglong)uVar17 >> 0x20);
    dVar10 = (double)(ulonglong)(uint)(fVar9 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f0c));
    dVar14 = (double)(fVar9 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f0c));
    (*(code *)PTR_pow_2f670bd4)(dVar14,*(undefined8 *)(PTR_cie_2f670040_2f670978 + -0x1ed8));
    uVar15 = (undefined4)((ulonglong)dVar14 >> 0x20);
    dVar10 = dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ed0);
    if (dVar10 < *(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8)) {
      sVar11 = SUB41((int)dVar10,0);
    }
    else {
      sVar11 = SUB41((int)(dVar10 - *(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8)),0);
    }
    param_2[2] = sVar11;
  }
  else {
    fVar8 = fVar9 - ((float)uVar17 + fVar13);
    *param_2 = (stColorTempParam)0x0;
    if (fVar8 <= 0.0) goto LAB_2f664230;
LAB_2f663ddc:
    dVar10 = (double)(ulonglong)(uint)(fVar8 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f10));
    dVar14 = (double)(fVar8 / *(float *)(PTR_cie_2f670040_2f670978 + -0x1f10));
    (*(code *)PTR_pow_2f670bd4)(dVar14,*(undefined8 *)(PTR_cie_2f670040_2f670978 + -0x1ed8));
    uVar15 = (undefined4)((ulonglong)dVar14 >> 0x20);
    dVar10 = dVar10 * *(double *)(PTR_cie_2f670040_2f670978 + -0x1ed0);
    if (dVar10 < *(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8)) {
      sVar11 = SUB41((int)dVar10,0);
    }
    else {
      sVar11 = SUB41((int)(dVar10 - *(double *)(PTR_cie_2f670040_2f670978 + -0x1ec8)),0);
    }
    fVar9 = fVar9 - ((float)uVar17 + fVar12);
    param_2[1] = sVar11;
    if (0.0 < fVar9) goto LAB_2f663e40;
LAB_2f664248:
    fVar8 = (float)((ulonglong)uVar17 >> 0x20);
    param_2[2] = (stColorTempParam)0x0;
  }
  iVar3 = (*(code *)PTR_factoryplug_isRGBGainOffsetLimited_2f670994)();
  if (iVar3 == 0) goto LAB_2f663ef8;
  fVar9 = fVar8 * *(float *)(PTR_cie_2f670040_2f670978 + -0x1f24);
  if ((float)(byte)*param_2 <= fVar9) {
    fVar13 = (float)(byte)param_2[1];
    if (fVar13 <= fVar9) goto LAB_2f663ee0;
LAB_2f6642ec:
    fVar12 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f04);
    uVar16 = CONCAT44(uVar15,(fVar13 + fVar8 * *(float *)(PTR_cie_2f670040_2f670978 + -0x1f08)) *
                             fVar12 * *(float *)(puVar2 + -0x1f18));
    (*(code *)PTR_ceilf_2f670b40)(uVar16);
    uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
    if (fVar12 < *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)) {
      param_2[1] = SUB41((int)fVar12,0);
    }
    else {
      param_2[1] = SUB41((int)(fVar12 - *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)),0);
    }
    fVar13 = (float)(byte)param_2[2];
    if (fVar13 <= fVar9) goto LAB_2f663ef8;
  }
  else {
    fVar13 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f04);
    uVar16 = CONCAT44(uVar15,((float)(byte)*param_2 +
                             fVar8 * *(float *)(PTR_cie_2f670040_2f670978 + -0x1f08)) * fVar13 *
                             *(float *)(puVar2 + -0x1f18));
    (*(code *)PTR_ceilf_2f670b40)(uVar16);
    uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
    if (fVar13 < *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)) {
      *param_2 = SUB41((int)fVar13,0);
    }
    else {
      *param_2 = SUB41((int)(fVar13 - *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)),0);
    }
    fVar13 = (float)(byte)param_2[1];
    if (fVar9 < fVar13) goto LAB_2f6642ec;
LAB_2f663ee0:
    fVar13 = (float)(byte)param_2[2];
    if (fVar13 <= fVar9) goto LAB_2f663ef8;
  }
  fVar9 = *(float *)(PTR_cie_2f670040_2f670978 + -0x1f04);
  (*(code *)PTR_ceilf_2f670b40)
            (CONCAT44(uVar15,(fVar13 + fVar8 * *(float *)(PTR_cie_2f670040_2f670978 + -0x1f08)) *
                             fVar9 * *(float *)(puVar2 + -0x1f18)));
  if (fVar9 < *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)) {
    param_2[2] = SUB41((int)fVar9,0);
  }
  else {
    param_2[2] = SUB41((int)(fVar9 - *(float *)(PTR_cie_2f670040_2f670978 + -0x1f20)),0);
  }
LAB_2f663ef8:
  sVar11 = *param_2;
  if (0x80 < (byte)sVar11) {
    sVar11 = (stColorTempParam)0x80;
  }
  sVar4 = param_2[1];
  *param_2 = sVar11;
  if (0x80 < (byte)sVar4) {
    sVar4 = (stColorTempParam)0x80;
  }
  sVar11 = param_2[2];
  param_2[1] = sVar4;
  puVar1 = PTR_memset_2f670bcc;
  if (0x80 < (byte)sVar11) {
    sVar11 = (stColorTempParam)0x80;
  }
  param_2[2] = sVar11;
  (*(code *)puVar1)(auStack_80,0,0x3c);
  puVar1 = PTR_outfp_2f6709e4;
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x2448,*param_1);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  (*(code *)PTR_memset_2f670bcc)(auStack_80,0,0x3c);
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x2434,param_1[1]);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  (*(code *)PTR_memset_2f670bcc)(auStack_80,0,0x3c);
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x2420,param_1[2]);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  (*(code *)PTR_memset_2f670bcc)(auStack_80,0,0x3c);
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x240c,*param_2);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  (*(code *)PTR_memset_2f670bcc)(auStack_80,0,0x3c);
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x23f0,param_2[1]);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  (*(code *)PTR_memset_2f670bcc)(auStack_80,0,0x3c);
  (*(code *)PTR_sprintf_2f670c5c)(auStack_80,PTR_cie_2f670040_2f670978 + -0x23d4,param_2[2]);
  if (*(int *)puVar1 != 0) {
    (*(code *)PTR_fwrite_2f670ac4)(auStack_80,1,0x3c);
  }
  return;
}

