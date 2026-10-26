
/* MWidget::DrawSingleLine(_Rect*) */

void __thiscall MWidget::DrawSingleLine(MWidget *this,_Rect *param_1)

{
  uchar *puVar1;
  byte bVar2;
  undefined2 uVar3;
  bool bVar4;
  ulong uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  iconv_t __cd;
  MResourceManager *pMVar11;
  LEFontInstance *pLVar12;
  float *pfVar13;
  int *piVar14;
  int iVar15;
  size_t sVar16;
  ulong *puVar17;
  char *pcVar18;
  byte bVar19;
  MWidget MVar20;
  undefined4 uVar21;
  undefined4 *__s;
  byte *pbVar22;
  int iVar23;
  uint uVar24;
  char *pcVar25;
  int iVar26;
  ulong uVar27;
  undefined4 uVar28;
  uint uVar29;
  int iVar30;
  char *pcVar31;
  undefined2 *puVar32;
  int iVar33;
  LEErrorCode *pLVar34;
  int iVar35;
  LEErrorCode *pLVar36;
  LEErrorCode *pLVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  undefined8 uVar41;
  int aiStack_1f8 [2];
  uchar auStack_1f0 [4];
  undefined4 auStack_1ec [3];
  LEErrorCode aLStack_1e0 [24];
  float afStack_1c8 [4];
  LEErrorCode aLStack_1b8 [16];
  uint auStack_1a8 [2];
  undefined4 uStack_1a0;
  int aiStack_19c [3];
  allocator aaStack_188 [4];
  allocator aaStack_184 [4];
  allocator aaStack_180 [4];
  allocator aaStack_17c [4];
  allocator aaStack_178 [4];
  size_t local_174;
  int local_170;
  char *local_16c;
  byte *local_168;
  int local_164;
  uint local_160;
  int local_15c;
  undefined4 local_158;
  ulong local_154;
  char *local_150;
  string asStack_14c [4];
  string asStack_148 [4];
  undefined4 local_144;
  string asStack_140 [4];
  char local_13c [4];
  char *local_138;
  int local_134;
  string asStack_130 [4];
  ulong local_12c;
  undefined4 local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_10c;
  int local_108;
  uint local_fc;
  uint local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  map amStack_dc [4];
  undefined4 local_d8;
  _Rb_tree_node *local_d4;
  undefined4 *local_d0;
  undefined4 *local_cc;
  undefined4 local_c8;
  uint local_c0;
  uint local_bc;
  int local_b8;
  int *local_b4;
  LEErrorCode *local_b0;
  LEErrorCode *local_ac;
  int local_a8;
  uint local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  undefined4 local_94;
  byte *local_90;
  char *local_8c;
  uint local_88;
  int local_84;
  undefined1 *local_80;
  int local_7c;
  char *local_78;
  int local_74;
  LEErrorCode *local_70;
  LEErrorCode *local_6c;
  uint *local_68;
  int *local_64;
  map *local_60;
  undefined4 *local_5c;
  uint *local_58;
  int *local_54;
  char *local_50;
  string *local_4c;
  LEErrorCode *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  
  local_80 = aLStack_1b8;
  if (this[0x17f] != (MWidget)0x0) {
    if (this[0x198] != (MWidget)0x0) {
      DrawSingleLine_Marquee_Vertical(this,param_1);
      return;
    }
    DrawSingleLine_Marquee(this,param_1);
    return;
  }
                    /* try { // try from 2e255cd0 to 2e255d1f has its CatchHandler @ 2e257ab4 */
  iVar7 = QueryVisualState(this);
  local_84 = GetDFBSurface(this);
  ClipDFBSurface(this,param_1);
  local_88 = *(uint *)(this + 0x128);
  GetAbsRect(this,(_Rect *)&local_10c);
  local_c0 = (uint)*(ushort *)(this + 0x9c);
  uVar29 = (uint)*(ushort *)(this + 0xa0);
  iVar35 = *(int *)(this + 0x1c);
  if (local_10c < *(int *)(this + 0x1c)) {
    iVar35 = local_10c;
  }
  iVar8 = *(int *)(this + 0x20);
  if (local_108 < *(int *)(this + 0x20)) {
    iVar8 = local_108;
  }
  local_74 = (-local_c0 - (uint)*(ushort *)(this + 0x9e)) + *(int *)(this + 0x24);
  if (iVar35 < 0) {
    local_c0 = local_c0 + iVar35;
  }
  uVar24 = uVar29;
  if (iVar8 < 0) {
    uVar24 = iVar8 + uVar29;
  }
  if (local_74 < 2) {
    return;
  }
  iVar35 = (*(int *)(this + 0x28) - (uint)*(ushort *)(this + 0xa2)) - uVar29;
  if (iVar35 < 2) {
    return;
  }
  local_c8 = 0;
  local_d0 = &local_d8;
  local_60 = amStack_dc;
  iVar8 = -(*(int *)(*(int *)(this + 0x174) + -0xc) + 0xfU & 0xfffffff8);
  pcVar31 = &stack0xfffffe70 + iVar8;
  local_d8 = 0;
  local_d4 = (_Rb_tree_node *)0x0;
  local_cc = local_d0;
  local_5c = local_d0;
                    /* try { // try from 2e255df0 to 2e256347 has its CatchHandler @ 2e257aac */
  iVar9 = PreprocessText(this,local_60,pcVar31);
  local_8c = pcVar31;
  if (iVar9 == 0) {
    local_8c = (char *)GetRcEngine::RcGetString((uint)*(ushort *)(this + 0x170));
  }
  sVar10 = strlen(local_8c);
  sVar10 = sVar10 + 1;
  iVar9 = -(sVar10 * 4 + 0xe & 0xfffffff8);
  __s = (undefined4 *)(&stack0xfffffe70 + iVar9 + iVar8);
  memset(__s,0,sVar10);
  sVar16 = sVar10;
  if (0 < (int)sVar10) {
    iVar26 = 0;
    do {
      uVar29 = (uint)local_8c[iVar26];
      if ((uVar29 & 0xe0) == 0xc0) {
        sVar16 = sVar16 - 1;
        *__s = 2;
        iVar26 = iVar26 + 2;
      }
      else if ((uVar29 & 0xf0) == 0xe0) {
        sVar16 = sVar16 - 2;
        *__s = 3;
        iVar26 = iVar26 + 3;
      }
      else {
        if (uVar29 == 10) {
          *__s = 0x11;
        }
        else {
          uVar21 = 0x21;
          if (uVar29 != 0x20) {
            uVar21 = 1;
          }
          *__s = uVar21;
        }
        iVar26 = iVar26 + 1;
      }
      __s = __s + 1;
    } while (iVar26 < (int)sVar10);
  }
  __cd = iconv_open("UTF-16LE","UTF-8");
  local_174 = strlen(local_8c);
  local_170 = local_174 << 1;
  uVar29 = sVar16 << 1;
  local_90 = operator_new__(uVar29,(nothrow_t *)&DAT_2c7f5bd0);
  if (local_90 == (byte *)0x0) goto LAB_2e2563f4;
  local_16c = local_8c;
  local_168 = local_90;
  if (__cd == (iconv_t)0xffffffff) {
    puts("Cannot convert");
LAB_2e256878:
    operator_delete__(local_90);
    goto LAB_2e2563f4;
  }
  memset(local_90,0,uVar29);
  *(int **)((int)auStack_1a8 + iVar9 + iVar8) = &local_170;
  sVar10 = iconv(__cd,&local_16c,&local_174,(char **)&local_168,
                 *(size_t **)((int)auStack_1a8 + iVar9 + iVar8));
  if (sVar10 == 0xffffffff) {
    puts("convert fail");
  }
  iconv_close(__cd);
  local_168 = (byte *)0x0;
  local_16c = (char *)0x0;
  if (0 < (int)uVar29) {
    iVar26 = 2;
    pbVar22 = local_90;
    do {
      bVar2 = *pbVar22;
      if (bVar2 == 0) {
        bVar19 = pbVar22[1];
        if (bVar19 == 0) break;
      }
      else {
        bVar19 = pbVar22[1];
      }
      if (bVar19 == 6) {
LAB_2e256498:
        local_94 = 1;
        local_98 = 2;
        local_9c = 1;
        iVar26 = 1;
        goto LAB_2e256010;
      }
      if (bVar19 == 7) {
        if ((char)bVar2 < '\0') goto LAB_2e255fdc;
        if (0x4f < bVar2) goto LAB_2e256498;
      }
      else if (bVar19 == 5) {
        if (0x90 < bVar2) {
          local_94 = 1;
          local_98 = 0x13;
          local_9c = 7;
          iVar26 = 2;
          goto LAB_2e256010;
        }
      }
      else {
LAB_2e255fdc:
        if ((bVar19 == 0xe) && (bVar2 < 0x60)) {
          local_94 = 0;
          local_98 = 0x26;
          local_9c = 0x19;
          iVar26 = 3;
          goto LAB_2e256010;
        }
      }
      bVar4 = iVar26 < (int)uVar29;
      pbVar22 = pbVar22 + 2;
      iVar26 = iVar26 + 2;
    } while (bVar4);
  }
  local_94 = 0;
  local_98 = 0;
  local_9c = 0;
  iVar26 = 0;
LAB_2e256010:
  pMVar11 = (MResourceManager *)MSystem::GetMResourceManager();
  uVar21 = *(undefined4 *)(this + iVar7 * 0xc + 0x130);
  uVar3 = *(undefined2 *)(this + iVar7 * 0xc + 0x13a);
  uVar28 = *(undefined4 *)(this + iVar7 * 0xc + 0x134);
  *(uint *)((int)auStack_1a8 + iVar9 + iVar8) = (uint)*(ushort *)(this + iVar7 * 0xc + 0x138);
  *(int *)((int)auStack_1a8 + iVar9 + iVar8 + 4) = iVar26;
  local_a0 = MResourceManager::GetDFBFont(pMVar11,uVar21,uVar3,uVar28);
  if (local_a0 == 0) goto LAB_2e256838;
  local_164 = 0;
  (**(code **)(local_a0 + 0x18))(local_a0,&local_164);
  iVar30 = local_164;
  local_68 = &local_fc;
  local_fc = local_c0;
  local_58 = &local_160;
  local_160 = 0;
  local_15c = 0;
  local_f4 = local_74;
  local_f8 = uVar24;
  local_f0 = iVar35;
  local_54 = &local_15c;
  *(uint **)((int)auStack_1a8 + iVar9 + iVar8) = local_58;
  *(undefined4 **)((int)&uStack_1a0 + iVar9 + iVar8) = &local_158;
  *(int **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = &local_15c;
  CalculateTextDrawFlags(this,local_68,local_88,iVar30);
  (**(code **)(local_84 + 0xb4))(local_84,local_a0);
  iVar35 = local_84;
  uVar29 = *(uint *)(this + (iVar7 + 0x1e) * 4 + 4);
  *(uint *)((int)auStack_1a8 + iVar9 + iVar8) = uVar29 >> 0x18;
  (**(code **)(local_84 + 0x54))
            (iVar35,(uVar29 & 0xffffff) >> 0x10,(uVar29 & 0xffff) >> 8,uVar29 & 0xff);
  if (iVar26 != 0) {
    local_128 = 0;
    local_78 = (char *)GetRcEngine::RcGetImage(*(uint *)(this + iVar7 * 0xc + 0x130),(uint *)0x0);
    local_a4 = (uint)*(ushort *)(this + iVar7 * 0xc + 0x13a);
    pLVar12 = (LEFontInstance *)openFont(this,local_78,local_a4);
    if (pLVar12 != (LEFontInstance *)0x0) {
      local_48 = (LEErrorCode *)&local_128;
      pfVar13 = (float *)icu_4_2::LayoutEngine::layoutEngineFactory
                                   (pLVar12,local_98,local_9c,local_48);
      if (pfVar13 != (float *)0x0) {
        local_124 = 0;
        local_120 = 0;
        iVar35 = ubidi_openSized_4_2(sVar16,0,&local_124);
        if (iVar35 == 0) {
LAB_2e256200:
          local_a8 = 0;
          local_ac = (LEErrorCode *)0x0;
        }
        else {
          *(undefined4 *)((int)auStack_1a8 + iVar9 + iVar8) = 0;
          *(int **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = &local_124;
          ubidi_setPara_4_2(iVar35,local_90,sVar16,0xfe);
          if (0 < local_124) goto LAB_2e256200;
                    /* try { // try from 2e256688 to 2e256a97 has its CatchHandler @ 2e257aac */
          iVar7 = ubidi_getDirection_4_2(iVar35);
          if (iVar7 != 2) {
            fVar38 = *pfVar13;
            *(int *)((int)auStack_1a8 + iVar9 + iVar8 + 4) = (int)(char)iVar7;
            *(size_t *)((int)auStack_1a8 + iVar9 + iVar8) = sVar16;
            *(undefined4 *)((int)&uStack_1a0 + iVar9 + iVar8) = 0;
            *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8) = 0;
            *(LEErrorCode **)((int)aiStack_19c + iVar9 + iVar8 + 4) = local_48;
            local_a8 = (**(code **)((int)fVar38 + 0x24))(pfVar13,local_90,0,sVar16);
            uVar29 = (local_a8 + 1) * 8;
            local_ac = operator_new__(uVar29,(nothrow_t *)&DAT_2c7f5bd0);
            if (local_ac != (LEErrorCode *)0x0) {
              memset(local_ac,0,uVar29);
              local_b0 = operator_new__(local_a8 << 2,(nothrow_t *)&DAT_2c7f5bd0);
              if (local_b0 != (LEErrorCode *)0x0) {
                icu_4_2::LayoutEngine::getGlyphs((uint *)pfVar13,local_b0);
                icu_4_2::LayoutEngine::getGlyphPositions(pfVar13,local_ac);
                goto LAB_2e25620c;
              }
LAB_2e2576f8:
              operator_delete__(local_ac);
            }
LAB_2e257708:
            operator_delete__(local_90);
                    /* try { // try from 2e25771c to 2e25784f has its CatchHandler @ 2e257aac */
            (**(code **)((int)*pfVar13 + 4))(pfVar13);
            (**(code **)(*(int *)pLVar12 + 4))(pLVar12);
            goto LAB_2e2563f4;
          }
          local_b8 = ubidi_countRuns_4_2(iVar35,&local_124);
          if (0 < local_124) goto LAB_2e256200;
          if (local_b8 < 1) {
            iVar26 = 0;
            iVar7 = 1;
            uVar29 = 8;
          }
          else {
            local_40 = &local_11c;
            iVar26 = 0;
            iVar7 = 0;
            local_44 = &local_120;
            do {
              cVar6 = ubidi_getVisualRun_4_2(iVar35,iVar7,local_44,local_40);
              iVar33 = local_11c;
              iVar30 = local_120;
              fVar38 = *pfVar13;
              *(int *)((int)auStack_1a8 + iVar9 + iVar8 + 4) = (int)cVar6;
              *(size_t *)((int)auStack_1a8 + iVar9 + iVar8) = sVar16;
              *(undefined4 *)((int)&uStack_1a0 + iVar9 + iVar8) = 0;
              *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8) = 0;
              *(LEErrorCode **)((int)aiStack_19c + iVar9 + iVar8 + 4) = local_48;
              iVar30 = (**(code **)((int)fVar38 + 0x24))(pfVar13,local_90,iVar30,iVar33);
              iVar26 = iVar26 + iVar30;
              (**(code **)((int)*pfVar13 + 0x2c))(pfVar13);
              iVar7 = iVar7 + 1;
            } while (iVar7 < local_b8);
            iVar7 = iVar26 + 1;
            uVar29 = iVar7 * 8;
          }
          local_120 = 0;
          local_ac = operator_new__(uVar29,(nothrow_t *)&DAT_2c7f5bd0);
          if (local_ac == (LEErrorCode *)0x0) goto LAB_2e257708;
          memset(local_ac,0,iVar7 << 3);
          local_b0 = operator_new__(iVar26 << 2,(nothrow_t *)&DAT_2c7f5bd0);
          if (local_b0 == (LEErrorCode *)0x0) goto LAB_2e2576f8;
          local_a8 = 0;
          if (0 < local_b8) {
            local_44 = &local_120;
            local_40 = &local_11c;
            local_a8 = 0;
            iVar26 = 0;
            iVar7 = 0;
            while( true ) {
              cVar6 = ubidi_getVisualRun_4_2(iVar35,iVar7,local_44,local_40);
              iVar33 = local_11c;
              iVar30 = local_120;
              pLVar37 = local_ac + iVar26 * 8;
              fVar38 = *pfVar13;
              *(int *)((int)auStack_1a8 + iVar9 + iVar8 + 4) = (int)cVar6;
              *(size_t *)((int)auStack_1a8 + iVar9 + iVar8) = sVar16;
              uVar21 = *(undefined4 *)pLVar37;
              *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8) = 0;
              pLVar36 = local_48;
              *(undefined4 *)((int)&uStack_1a0 + iVar9 + iVar8) = uVar21;
              *(LEErrorCode **)((int)aiStack_19c + iVar9 + iVar8 + 4) = pLVar36;
              iVar30 = (**(code **)((int)fVar38 + 0x24))(pfVar13,local_90,iVar30,iVar33);
              local_a8 = local_a8 + iVar30;
              icu_4_2::LayoutEngine::getGlyphs((uint *)pfVar13,local_b0 + iVar26 * 4);
              icu_4_2::LayoutEngine::getGlyphPositions(pfVar13,pLVar37);
              (**(code **)((int)*pfVar13 + 0x2c))(pfVar13);
              iVar7 = iVar7 + 1;
              if (local_b8 <= iVar7) break;
              iVar26 = iVar26 + local_11c;
            }
          }
        }
LAB_2e25620c:
        ubidi_close_4_2(iVar35);
        (**(code **)((int)*pfVar13 + 4))(pfVar13);
        (**(code **)(*(int *)pLVar12 + 4))(pLVar12);
        if (local_ac == (LEErrorCode *)0x0) goto LAB_2e256878;
        uVar41 = CONCAT44(*(undefined4 *)(local_ac + local_a8 * 8),*(float *)local_ac);
        piVar14 = operator_new__(local_a8 << 4,(nothrow_t *)&DAT_2c7f5bd0);
        local_b4 = piVar14;
        if (piVar14 == (int *)0x0) {
                    /* try { // try from 2e25747c to 2e257687 has its CatchHandler @ 2e257aac */
          printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
                 "void MWidget::DrawSingleLine(Rect*)",0x114f);
          goto LAB_2e257488;
        }
        iVar35 = local_f4;
        if (local_a8 < 1) {
          iVar33 = 0;
          iVar30 = 0;
          iVar7 = 0;
          iVar26 = 0;
        }
        else {
          local_64 = &local_ec;
          iVar33 = 0;
          iVar26 = 0;
          iVar7 = 0;
          iVar30 = 0;
          pLVar36 = local_b0;
          pLVar37 = local_ac;
          do {
            (**(code **)(local_a0 + 0x2c))(local_a0,*(undefined4 *)pLVar36,local_64,0);
            *piVar14 = local_ec;
            piVar14[1] = local_e8;
            piVar14[2] = local_e4;
            piVar14[3] = local_e0;
            if (iVar30 < 2) {
              fVar38 = (*(float *)pLVar37 - *(float *)local_ac) + (float)local_ec;
              iVar15 = sVar16 - iVar30;
              if (fVar38 < (float)iVar35) {
                iVar35 = (int)fVar38;
              }
            }
            else {
              iVar15 = sVar16 - iVar30;
            }
            if ((iVar15 < 3) &&
               (fVar38 = (*(float *)pLVar37 - *(float *)local_ac) + (float)local_ec +
                         (float)local_e4, (float)iVar33 < fVar38)) {
              iVar33 = (int)fVar38;
            }
            iVar30 = iVar30 + 1;
            if (iVar7 < local_e8 + local_e0) {
              iVar7 = local_e8 + local_e0;
            }
            if (local_e8 < iVar26) {
              iVar26 = local_e8;
            }
            pLVar36 = pLVar36 + 4;
            pLVar37 = pLVar37 + 8;
            piVar14 = piVar14 + 4;
          } while (iVar30 < local_a8);
          iVar30 = iVar7 - iVar26;
        }
        if (local_164 < iVar30) {
          local_164 = iVar30;
        }
        iVar30 = local_164;
        iVar23 = (int)(float)((ulonglong)uVar41 >> 0x20) - (int)(float)uVar41;
        iVar15 = iVar33 - iVar35;
        if (iVar33 - iVar35 < iVar23) {
          iVar15 = iVar23;
        }
        *(uint **)((int)auStack_1a8 + iVar9 + iVar8) = local_58;
        piVar14 = local_54;
        *(int *)((int)&uStack_1a0 + iVar9 + iVar8) = iVar15;
        *(int *)((int)aiStack_19c + iVar9 + iVar8) = iVar7;
        *(int **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = piVar14;
        *(int *)((int)aiStack_19c + iVar9 + iVar8 + 4) = iVar26;
        CalculateGlyphDrawFlags(this,local_68,local_88,iVar30);
        local_118 = 0;
        *(int **)((int)auStack_1a8 + iVar9 + iVar8) = &local_118;
        *(int **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = local_b4;
        *(undefined4 *)((int)&uStack_1a0 + iVar9 + iVar8) = local_94;
        GetAraStringBreak(this,(float *)local_ac,local_a8,local_74,
                          *(int **)((int)auStack_1a8 + iVar9 + iVar8),
                          *(DFBRectangle **)((int)auStack_1a8 + iVar9 + iVar8 + 4),
                          *(uchar *)((int)&uStack_1a0 + iVar9 + iVar8));
        if (((this[0x17c] == (MWidget)0x0) && (*(int *)(this + 0x24c) == 0)) || (local_118 < 1)) {
          if (0 < local_a8) {
            iVar35 = 0;
            pLVar36 = local_ac;
            pLVar37 = local_b0;
            do {
              iVar7 = local_15c;
              uVar29 = local_160;
              fVar39 = *(float *)pLVar36;
              fVar38 = *(float *)local_ac;
              fVar40 = *(float *)(pLVar36 + 4);
              uVar21 = *(undefined4 *)pLVar37;
              *(undefined4 *)((int)auStack_1a8 + iVar9 + iVar8) = 0;
              (**(code **)(local_84 + 0xc0))
                        (local_84,uVar21,(int)((fVar39 - fVar38) + (float)(int)uVar29),
                         (int)((float)iVar7 + fVar40));
              iVar35 = iVar35 + 1;
              pLVar37 = pLVar37 + 4;
              pLVar36 = pLVar36 + 8;
            } while (iVar35 < local_a8);
          }
          goto LAB_2e256ab8;
        }
        puVar32 = (undefined2 *)((int)&uStack_1a0 + iVar9 + iVar8);
        local_70 = aLStack_1b8 + iVar9 + iVar8;
                    /* try { // try from 2e256b3c to 2e256c6f has its CatchHandler @ 2e257aa0 */
        pLVar12 = (LEFontInstance *)openFont(this,local_78,local_a4);
        pLVar36 = local_48;
        iVar7 = local_98;
        iVar35 = local_9c;
        if (pLVar12 == (LEFontInstance *)0x0) {
          operator_delete__(local_90);
          operator_delete__(local_ac);
          if (local_b0 != (LEErrorCode *)0x0) {
            operator_delete__(local_b0);
          }
        }
        else {
          *(undefined2 *)((int)aiStack_19c + iVar9 + iVar8) = 0x2e;
          *puVar32 = 0x2e;
          *(undefined2 *)((int)&uStack_1a0 + iVar9 + iVar8 + 2) = 0x2e;
          pfVar13 = (float *)icu_4_2::LayoutEngine::layoutEngineFactory
                                       (pLVar12,iVar7,iVar35,pLVar36);
          if (pfVar13 != (float *)0x0) {
            fVar38 = *pfVar13;
            cVar6 = (char)local_94;
            local_7c = (int)cVar6;
            *(undefined4 *)((int)aiStack_1f8 + iVar9 + iVar8) = 3;
            *(int *)((int)aiStack_1f8 + iVar9 + iVar8 + 4) = (int)cVar6;
            puVar1 = auStack_1f0 + iVar9 + iVar8;
            puVar1[0] = '\0';
            puVar1[1] = '\0';
            puVar1[2] = '\0';
            puVar1[3] = '\0';
            *(undefined4 *)((int)auStack_1ec + iVar9 + iVar8) = 0;
            *(LEErrorCode **)((int)auStack_1ec + iVar9 + iVar8 + 4) = local_48;
            (**(code **)((int)fVar38 + 0x24))(pfVar13,puVar32,0,3);
            icu_4_2::LayoutEngine::getGlyphs((uint *)pfVar13,local_70);
            icu_4_2::LayoutEngine::getGlyphPositions(pfVar13,aLStack_1e0 + iVar9 + iVar8);
            (**(code **)((int)*pfVar13 + 0x2c))(pfVar13);
            iVar35 = (int)(*(float *)((int)afStack_1c8 + iVar9 + iVar8) -
                          *(float *)(aLStack_1e0 + iVar9 + iVar8));
            (**(code **)(*(int *)pLVar12 + 4))(pLVar12);
            (**(code **)((int)*pfVar13 + 4))(pfVar13);
            *(int **)((int)aiStack_1f8 + iVar9 + iVar8) = &local_118;
            *(undefined4 *)(auStack_1f0 + iVar9 + iVar8) = local_94;
            *(int **)((int)aiStack_1f8 + iVar9 + iVar8 + 4) = local_b4;
            GetAraStringBreak(this,(float *)local_ac,local_a8,local_74 - iVar35,
                              *(int **)((int)aiStack_1f8 + iVar9 + iVar8),
                              *(DFBRectangle **)((int)aiStack_1f8 + iVar9 + iVar8 + 4),
                              auStack_1f0[iVar9 + iVar8]);
            if ((this[0x17c] == (MWidget)0x0) && (*(int *)(this + 0x24c) != 1)) {
LAB_2e256ab8:
              if (local_b0 != (LEErrorCode *)0x0) {
                operator_delete__(local_b0);
              }
              operator_delete__(local_ac);
              operator_delete__(local_b4);
              goto LAB_2e2565d0;
            }
            iVar30 = sVar16 - local_118;
            iVar33 = iVar30 + 3;
            iVar35 = -(iVar33 * 2 + 0xeU & 0xfffffff8);
            iVar7 = -(iVar33 * 4 + 0xeU & 0xfffffff8);
            local_6c = aLStack_1e0 + iVar7 + iVar35 + iVar9 + iVar8;
            iVar26 = -(iVar30 * 8 + 0x28);
            pLVar36 = aLStack_1e0 + iVar26 + iVar7 + iVar35 + iVar9 + iVar8;
                    /* try { // try from 2e256cf4 to 2e256cfb has its CatchHandler @ 2e257a8c */
            pLVar12 = (LEFontInstance *)openFont(this,local_78,local_a4);
            if (pLVar12 == (LEFontInstance *)0x0) {
              operator_delete__(local_90);
              operator_delete__(local_ac);
              if (local_b0 != (LEErrorCode *)0x0) {
                operator_delete__(local_b0);
              }
            }
            else {
              if (0 < iVar33) {
                iVar15 = 0;
                pLVar37 = aLStack_1e0 + iVar35 + iVar9 + iVar8;
                pbVar22 = local_90;
                do {
                  if (iVar15 < iVar30) {
                    *(undefined2 *)pLVar37 = *(undefined2 *)pbVar22;
                  }
                  else {
                    *(undefined2 *)pLVar37 = 0x2e;
                  }
                  iVar15 = iVar15 + 1;
                  pbVar22 = pbVar22 + 2;
                  pLVar37 = pLVar37 + 2;
                } while (iVar15 < iVar33);
              }
                    /* try { // try from 2e257300 to 2e25743b has its CatchHandler @ 2e257a8c */
              pfVar13 = (float *)icu_4_2::LayoutEngine::layoutEngineFactory
                                           (pLVar12,local_98,local_9c,local_48);
              iVar30 = local_7c;
              if (pfVar13 != (float *)0x0) {
                fVar38 = *pfVar13;
                *(int *)((int)aiStack_1f8 + iVar26 + iVar7 + iVar35 + iVar9 + iVar8) = iVar33;
                *(int *)((int)aiStack_1f8 + iVar26 + iVar7 + iVar35 + iVar9 + iVar8 + 4) = iVar30;
                puVar1 = auStack_1f0 + iVar26 + iVar7 + iVar35 + iVar9 + iVar8;
                puVar1[0] = '\0';
                puVar1[1] = '\0';
                puVar1[2] = '\0';
                puVar1[3] = '\0';
                *(undefined4 *)((int)auStack_1ec + iVar26 + iVar7 + iVar35 + iVar9 + iVar8) = 0;
                *(LEErrorCode **)((int)auStack_1ec + iVar26 + iVar7 + iVar35 + iVar9 + iVar8 + 4) =
                     local_48;
                (**(code **)((int)fVar38 + 0x24))
                          (pfVar13,aLStack_1e0 + iVar35 + iVar9 + iVar8,0,iVar33);
                icu_4_2::LayoutEngine::getGlyphs((uint *)pfVar13,local_6c);
                icu_4_2::LayoutEngine::getGlyphPositions(pfVar13,pLVar36);
                (**(code **)(*(int *)pLVar12 + 4))(pLVar12);
                iVar30 = icu_4_2::LayoutEngine::getGlyphCount();
                (**(code **)((int)*pfVar13 + 0x2c))(pfVar13);
                (**(code **)((int)*pfVar13 + 4))(pfVar13);
                if ((local_88 & 1) == 0) {
                  if ((local_88 & 2) == 0) {
                    local_160 = (local_c0 + local_74) -
                                (int)(*(float *)(pLVar36 + iVar30 * 8) - *(float *)pLVar36);
                  }
                  else {
                    local_160 = (local_74 -
                                (int)(*(float *)(pLVar36 + iVar30 * 8) - *(float *)pLVar36)) / 2 +
                                local_c0;
                  }
                }
                else {
                  local_160 = local_c0;
                }
                if (0 < iVar30) {
                  iVar33 = 0;
                  pLVar37 = pLVar36;
                  pLVar34 = local_6c;
                  do {
                    iVar15 = local_15c;
                    uVar29 = local_160;
                    fVar38 = *(float *)pLVar36;
                    fVar39 = *(float *)pLVar37;
                    fVar40 = *(float *)(pLVar37 + 4);
                    uVar21 = *(undefined4 *)pLVar34;
                    *(undefined4 *)((int)aiStack_1f8 + iVar26 + iVar7 + iVar35 + iVar9 + iVar8) = 0;
                    (**(code **)(local_84 + 0xc0))
                              (local_84,uVar21,(int)((fVar39 - fVar38) + (float)(int)uVar29),
                               (int)((float)iVar15 + fVar40));
                    iVar33 = iVar33 + 1;
                    pLVar34 = pLVar34 + 4;
                    pLVar37 = pLVar37 + 8;
                  } while (iVar33 < iVar30);
                }
                goto LAB_2e256ab8;
              }
              operator_delete__(local_90);
              operator_delete__(local_ac);
              if (local_b0 != (LEErrorCode *)0x0) {
                operator_delete__(local_b0);
              }
            }
            operator_delete__(local_b4);
            goto LAB_2e2563f4;
          }
          operator_delete__(local_90);
          operator_delete__(local_ac);
          if (local_b0 != (LEErrorCode *)0x0) {
            operator_delete__(local_b0);
          }
        }
        operator_delete__(local_b4);
        goto LAB_2e2563f4;
      }
    }
LAB_2e256838:
    operator_delete__(local_90);
LAB_2e2563f4:
                    /* try { // try from 2e2563fc to 2e256403 has its CatchHandler @ 2e257ac0 */
    std::
    _Rb_tree<unsigned_short,std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>,std::_Select1st<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
    ::_M_erase((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>,std::_Select1st<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                *)local_60,local_d4);
    return;
  }
  puVar17 = &local_154;
  local_154 = 0;
  local_118 = 0;
  local_150 = (char *)0x0;
  *(int **)((int)auStack_1a8 + iVar9 + iVar8) = &local_118;
  *(ulong **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = puVar17;
  *(char ***)((int)&uStack_1a0 + iVar9 + iVar8) = &local_150;
                    /* try { // try from 2e256514 to 2e256657 has its CatchHandler @ 2e257aac */
  (**(code **)(local_a0 + 0x30))(local_a0,local_8c,0xffffffff,local_74);
  MVar20 = this[0x17c];
  if (MVar20 == (MWidget)0x0) {
    if (((local_150 == (char *)0x0) || (*local_8c == '\0')) || (*local_150 == '\0')) {
      MVar20 = (MWidget)0x0;
    }
    else {
      printf("\x1b[1;31m string \'%s\' is cropped\x1b[0m (l=%d c=%d)\n",local_8c,local_154);
      MVar20 = this[0x17c];
      if (MVar20 != (MWidget)0x0) goto LAB_2e256798;
    }
    if (*(int *)(this + 0x24c) != 0) goto LAB_2e256798;
  }
  else {
LAB_2e256798:
    if (local_150 != (char *)0x0) {
      if ((MVar20 == (MWidget)0x0) && (iVar35 = *(int *)(this + 0x24c), iVar35 != 1)) {
        if (iVar35 == 3) {
          sVar16 = strlen(local_8c);
          local_13c[0] = '.';
          local_13c[1] = '.';
          local_13c[2] = '.';
          local_13c[3] = '\0';
          local_120 = local_118;
                    /* try { // try from 2e256d84 to 2e256d8b has its CatchHandler @ 2e257aac */
          (**(code **)(local_a0 + 0x24))(local_a0,local_13c,0xffffffff,&local_120);
          local_4c = (string *)&local_138;
          local_120 = local_118 - local_120;
                    /* try { // try from 2e256db4 to 2e256dbb has its CatchHandler @ 2e257978 */
          std::string::string(local_4c,"...",aaStack_188);
          if (1 < (int)sVar16) {
            uVar29 = sVar16 - 1;
            local_3c = &local_11c;
            iVar35 = 1;
            local_bc = uVar29;
            do {
              local_144 = 0x2c828ac4;
                    /* try { // try from 2e256e28 to 2e256e2f has its CatchHandler @ 2e2579b4 */
              std::string::string(asStack_14c,local_8c,aaStack_184);
                    /* try { // try from 2e256e44 to 2e256e4b has its CatchHandler @ 2e25795c */
              std::string::assign((string *)&local_144,(uint)asStack_14c,uVar29);
                    /* try { // try from 2e256e54 to 2e256e5b has its CatchHandler @ 2e2579b4 */
              std::string::~string(asStack_14c);
                    /* try { // try from 2e256e6c to 2e256e73 has its CatchHandler @ 2e257914 */
              (**(code **)(local_a0 + 0x24))(local_a0,local_144,0xffffffff,local_3c);
              if (local_120 < local_11c) {
                if (-1 < (int)uVar29) {
                  if (((int)local_8c[uVar29] & 0xe0U) == 0xe0) {
                    iVar35 = iVar35 + -2;
                  }
                  else {
                    iVar35 = iVar35 - (uint)(((int)local_8c[uVar29] & 0xc0U) == 0xc0);
                  }
                }
                if (-1 < (int)(local_bc - iVar35)) {
                  iVar35 = iVar35 - (uint)(((int)local_8c[local_bc - iVar35] & 0xe0U) == 0xe0);
                }
                    /* try { // try from 2e256eec to 2e256ef3 has its CatchHandler @ 2e2579ac */
                std::string::string(asStack_148,local_8c,aaStack_180);
                    /* try { // try from 2e256f0c to 2e256f13 has its CatchHandler @ 2e257990 */
                std::string::assign((string *)&local_144,(uint)asStack_148,(sVar16 + 1) - iVar35);
                    /* try { // try from 2e256f1c to 2e256f23 has its CatchHandler @ 2e2579ac */
                std::string::~string(asStack_148);
                    /* try { // try from 2e256f30 to 2e256f37 has its CatchHandler @ 2e257914 */
                std::string::append(local_4c);
                    /* try { // try from 2e256f40 to 2e256f5b has its CatchHandler @ 2e257984 */
                std::string::~string((string *)&local_144);
                break;
              }
                    /* try { // try from 2e256e00 to 2e256e07 has its CatchHandler @ 2e257984 */
              iVar35 = iVar35 + 1;
              std::string::~string((string *)&local_144);
              uVar29 = uVar29 - 1;
            } while (iVar35 < (int)sVar16);
          }
          std::string::push_back((char)local_4c);
          pcVar31 = operator_new__(*(uint *)(local_138 + -0xc),(nothrow_t *)&DAT_2c7f5bd0);
          if (pcVar31 == (char *)0x0) {
                    /* try { // try from 2e257874 to 2e25787b has its CatchHandler @ 2e257984 */
            printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
                   "void MWidget::DrawSingleLine(Rect*)",0x1021);
LAB_2e257488:
                    /* WARNING: Subroutine does not return */
            abort();
          }
          strncpy(pcVar31,local_138,*(size_t *)(local_138 + -0xc));
          puVar17 = (ulong *)strlen(pcVar31);
                    /* try { // try from 2e256fb0 to 2e256fb7 has its CatchHandler @ 2e257aac */
          std::string::~string(local_4c);
        }
        else {
          pcVar31 = (char *)0x0;
          if (iVar35 == 2) {
            sVar16 = strlen(local_8c);
            uVar29 = sVar16 - 1;
            local_144 = 0x2c828ac4;
            if (-1 < (int)uVar29) {
              if (local_8c[uVar29] != '.') {
                pcVar31 = local_8c + sVar16;
                do {
                  uVar29 = uVar29 - 1;
                  if (uVar29 == 0xffffffff) goto LAB_2e25702c;
                  pcVar18 = pcVar31 + -2;
                  pcVar31 = pcVar31 + -1;
                } while (*pcVar18 != '.');
              }
                    /* try { // try from 2e2576bc to 2e2576c3 has its CatchHandler @ 2e257ae4 */
              std::string::string(asStack_140,local_8c,aaStack_17c);
                    /* try { // try from 2e2576d8 to 2e2576df has its CatchHandler @ 2e257ac8 */
              std::string::assign((string *)&local_144,(uint)asStack_140,uVar29);
                    /* try { // try from 2e2576e8 to 2e2576ef has its CatchHandler @ 2e257ae4 */
              std::string::~string(asStack_140);
            }
LAB_2e25702c:
            local_50 = local_13c;
            local_13c[0] = '.';
            local_13c[1] = '.';
            local_13c[2] = '.';
            local_13c[3] = '\0';
            local_11c = local_118;
                    /* try { // try from 2e257058 to 2e257117 has its CatchHandler @ 2e2579f8 */
            (**(code **)(local_a0 + 0x24))(local_a0,local_50,0xffffffff,&local_11c);
            local_11c = local_118 - local_11c;
            (**(code **)(local_a0 + 0x24))(local_a0,local_144,0xffffffff,&local_120);
            pcVar31 = local_8c;
            iVar35 = local_a0;
            local_11c = local_11c - local_120;
            *(int **)((int)auStack_1a8 + iVar9 + iVar8) = &local_118;
            *(char ***)((int)&uStack_1a0 + iVar9 + iVar8) = &local_150;
            *(ulong **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = puVar17;
            (**(code **)(local_a0 + 0x30))(iVar35,pcVar31,0xffffffff);
            if (((this[0x17c] == (MWidget)0x0) && (local_150 != (char *)0x0)) &&
               ((*local_8c != '\0' && (*local_150 != '\0')))) {
                    /* try { // try from 2e257904 to 2e25790b has its CatchHandler @ 2e2579f8 */
              printf("\x1b[1;31m string \'%s\' is cropped\x1b[0m (l=%d c=%d)\n",local_8c,local_154);
            }
            local_12c = 0;
            *(ulong *)((int)auStack_1a8 + iVar9 + iVar8) = local_154;
            GetStringBytesLength
                      (this,local_8c,&local_12c,(int *)puVar17,
                       *(ulong *)((int)auStack_1a8 + iVar9 + iVar8));
            local_4c = (string *)&local_138;
            strlen(local_50);
            local_138 = (char *)0x2c828ac4;
                    /* try { // try from 2e257154 to 2e257187 has its CatchHandler @ 2e257a60 */
            std::string::reserve((uint)local_4c);
            std::string::append((char *)local_4c,(uint)local_50);
            std::string::append(local_4c);
            uVar27 = local_12c;
            uVar5 = local_154;
            *(char **)((int)auStack_1a8 + iVar9 + iVar8) = local_138;
                    /* try { // try from 2e2571a8 to 2e2571af has its CatchHandler @ 2e257a54 */
            puVar17 = (ulong *)ResetLastLineString(this,local_8c,uVar27 - 1,uVar5,
                                                   *(char **)((int)auStack_1a8 + iVar9 + iVar8));
            local_134 = 0x2c828ac4;
                    /* try { // try from 2e2571d8 to 2e2571df has its CatchHandler @ 2e257a4c */
            std::string::string(asStack_130,local_8c,aaStack_178);
                    /* try { // try from 2e2571f4 to 2e2571fb has its CatchHandler @ 2e257a30 */
            std::string::assign((string *)&local_134,(uint)asStack_130,0);
                    /* try { // try from 2e257204 to 2e25720b has its CatchHandler @ 2e257a4c */
            std::string::~string(asStack_130);
                    /* try { // try from 2e257218 to 2e25728b has its CatchHandler @ 2e2579bc */
            std::string::append((char *)&local_134);
            std::string::append((string *)&local_134);
            pcVar31 = (char *)0x0;
            if (*(int *)(local_134 + -0xc) != 0) {
              pcVar31 = operator_new__(*(uint *)(local_134 + -0xc),(nothrow_t *)&DAT_2c7f5bd0);
              if (pcVar31 == (char *)0x0) {
                printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
                       "void MWidget::DrawSingleLine(Rect*)",0x1066);
                goto LAB_2e257488;
              }
              puVar17 = *(ulong **)(local_134 + -0xc);
              if (puVar17 != (ulong *)0x0) {
                uVar29 = 0;
                do {
                  std::string::_M_leak();
                  pcVar25 = pcVar31 + uVar29;
                  pcVar18 = (char *)(local_134 + uVar29);
                  uVar29 = uVar29 + 1;
                  *pcVar25 = *pcVar18;
                } while (uVar29 < *(uint *)(local_134 + -0xc));
              }
            }
                    /* try { // try from 2e2572c0 to 2e2572c7 has its CatchHandler @ 2e257a54 */
            std::string::~string((string *)&local_134);
                    /* try { // try from 2e2572d0 to 2e2572d7 has its CatchHandler @ 2e2579f8 */
            std::string::~string(local_4c);
                    /* try { // try from 2e2572e0 to 2e2572e7 has its CatchHandler @ 2e257aac */
            std::string::~string((string *)&local_144);
          }
        }
      }
      else {
        local_12c = 0;
        *(ulong *)((int)auStack_1a8 + iVar9 + iVar8) = local_154;
        GetStringBytesLength
                  (this,local_8c,&local_12c,(int *)puVar17,
                   *(ulong *)((int)auStack_1a8 + iVar9 + iVar8));
        uVar5 = local_154;
        uVar27 = local_12c - 1;
        builtin_strncpy(local_13c,"...",4);
        *(char **)((int)auStack_1a8 + iVar9 + iVar8) = local_13c;
        uVar29 = ResetLastLineString(this,local_8c,uVar27,uVar5,
                                     *(char **)((int)auStack_1a8 + iVar9 + iVar8));
        if (0xfffffffb < uVar29) goto LAB_2e256838;
        puVar17 = (ulong *)(uVar29 + 4);
        pcVar31 = operator_new__((uint)puVar17,(nothrow_t *)&DAT_2c7f5bd0);
        if (pcVar31 == (char *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
                 "void MWidget::DrawSingleLine(Rect*)",0xfda);
          goto LAB_2e257488;
        }
        uVar24 = 0;
        do {
          pcVar25 = pcVar31 + uVar24;
          pcVar18 = local_8c + uVar24;
          uVar24 = uVar24 + 1;
          *pcVar25 = *pcVar18;
        } while (uVar24 < uVar29 + 2);
        builtin_strncpy(pcVar31 + uVar29,"...",4);
      }
      *(ulong **)((int)auStack_1a8 + iVar9 + iVar8) = puVar17;
      *(uint **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = local_58;
      *(int **)((int)&uStack_1a0 + iVar9 + iVar8) = local_54;
      *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8 + 4) = 0;
      *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8) = local_158;
      *(map **)((int)aiStack_19c + iVar9 + iVar8 + 8) = local_60;
      DrawString(this,local_84,local_a0,pcVar31);
      if (pcVar31 != (char *)0x0) {
        operator_delete__(pcVar31);
      }
      goto LAB_2e2565d0;
    }
  }
  local_12c = 0;
  *(ulong *)((int)auStack_1a8 + iVar9 + iVar8) = local_154;
  GetStringBytesLength
            (this,local_8c,&local_12c,(int *)puVar17,*(ulong *)((int)auStack_1a8 + iVar9 + iVar8));
  uVar5 = local_154;
  *(uint **)((int)auStack_1a8 + iVar9 + iVar8 + 4) = local_58;
  piVar14 = local_54;
  *(ulong *)((int)auStack_1a8 + iVar9 + iVar8) = uVar5;
  *(int **)((int)&uStack_1a0 + iVar9 + iVar8) = piVar14;
  *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8 + 4) = 0;
  *(undefined4 *)((int)aiStack_19c + iVar9 + iVar8) = local_158;
  *(map **)((int)aiStack_19c + iVar9 + iVar8 + 8) = local_60;
  DrawString(this,local_84,local_a0,local_8c);
LAB_2e2565d0:
  (**(code **)(local_a0 + 0x24))(local_a0,local_8c,0xffffffff,&local_114);
  (**(code **)(local_a0 + 0x18))(local_a0,&local_110);
  *(int *)(this + 0x240) = local_15c;
  *(uint *)(this + 0x244) = local_160;
  *(undefined4 *)(this + 0x238) = local_114;
  *(undefined4 *)(this + 0x23c) = local_110;
  std::
  _Rb_tree<unsigned_short,std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>,std::_Select1st<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
  ::_M_erase((_Rb_tree<unsigned_short,std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>,std::_Select1st<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
              *)local_60,local_d4);
  local_d4 = (_Rb_tree_node *)0x0;
  local_cc = local_5c;
  local_d0 = local_5c;
  local_c8 = 0;
  (**(code **)(local_84 + 0x4c))(local_84,0);
  operator_delete__(local_90);
                    /* try { // try from 2e256670 to 2e256677 has its CatchHandler @ 2e257ab4 */
  std::
  map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
  ::~map((map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
          *)local_60);
  return;
}

