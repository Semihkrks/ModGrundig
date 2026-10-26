
/* MWidget::PreprocessText(std::map<unsigned short, MWidget::CONTROL_FLAG, std::less<unsigned
   short>, std::allocator<std::pair<unsigned short const, MWidget::CONTROL_FLAG> > >*, char*) */

undefined4 __thiscall MWidget::PreprocessText(MWidget *this,map *param_1,char *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  map *pmVar4;
  undefined4 uVar5;
  byte bVar6;
  map *pmVar7;
  map *pmVar8;
  byte *pbVar9;
  uint *puVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  map *pmVar14;
  short local_a8 [2];
  undefined4 local_a4;
  pair apStack_a0 [8];
  short local_98 [2];
  undefined4 local_94;
  pair apStack_90 [8];
  undefined2 local_88 [2];
  undefined4 local_84;
  pair apStack_80 [8];
  undefined2 local_78 [2];
  undefined4 local_74;
  pair apStack_70 [8];
  short local_68 [2];
  undefined4 local_64;
  pair apStack_60 [8];
  map *local_58;
  pair *local_54;
  short *local_50;
  pair *local_4c;
  undefined2 *local_48;
  pair *local_44;
  undefined2 *local_40;
  pair *local_3c;
  short *local_38;
  pair *local_34;
  short *local_30;
  
  if (((param_1 == (map *)0x0) || (param_2 == (char *)0x0)) ||
     (iVar2 = MString::QueryFlag((MString *)(this + 0x170),'\x01'), iVar2 != 0)) {
    uVar5 = 0;
  }
  else {
    iVar2 = *(int *)(this + 0x174);
    puVar10 = (uint *)(iVar2 + -0xc);
    if (*(int *)(iVar2 + -0xc) != 0) {
      local_54 = apStack_60;
      local_50 = local_68;
      local_4c = apStack_70;
      local_48 = local_78;
      local_44 = apStack_80;
      local_40 = local_88;
      local_3c = apStack_90;
      local_38 = local_98;
      pmVar14 = param_1 + 4;
      local_34 = apStack_a0;
      local_30 = local_a8;
      uVar12 = 0;
      iVar13 = 0;
      local_58 = pmVar14;
      do {
        if (-1 < (int)puVar10[2]) {
          std::string::_M_leak_hard();
          iVar2 = *(int *)(this + 0x174);
        }
        pbVar9 = (byte *)(iVar2 + uVar12);
        bVar6 = *pbVar9;
        if (bVar6 == 0) {
          puVar10 = (uint *)(iVar2 + -0xc);
LAB_2e253318:
          uVar3 = puVar10[2];
LAB_2e25331c:
          if (-1 < (int)uVar3) {
            std::string::_M_leak_hard();
            iVar2 = *(int *)(this + 0x174);
            pbVar9 = (byte *)(iVar2 + uVar12);
            puVar10 = (uint *)(iVar2 + -0xc);
          }
          uVar3 = uVar12 + 2;
          sVar1 = (short)iVar13;
          if ((*pbVar9 == 0xee) && ((uVar3 & 0xffff) < *puVar10)) {
            if (-1 < (int)puVar10[2]) {
              std::string::_M_leak_hard();
              iVar2 = *(int *)(this + 0x174);
              pbVar9 = (byte *)(iVar2 + uVar12);
            }
            if (pbVar9[1] != 0x82) {
LAB_2e253550:
              puVar10 = (uint *)(iVar2 + -0xc);
              goto LAB_2e253350;
            }
            std::string::_M_leak();
            iVar2 = *(int *)(this + 0x174);
            if (*(byte *)(iVar2 + uVar3) < 0x80) goto LAB_2e253550;
            std::string::_M_leak();
            iVar2 = *(int *)(this + 0x174);
            bVar6 = *(byte *)(iVar2 + uVar3);
            if (0x9f < bVar6) goto LAB_2e253550;
            if (-1 < *(int *)(iVar2 + -4)) {
              std::string::_M_leak_hard();
              iVar2 = *(int *)(this + 0x174);
              bVar6 = *(byte *)(iVar2 + uVar3);
            }
            if (bVar6 == 0x8a) {
              local_a4 = 3;
              local_a8[0] = sVar1;
              std::
              map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
              ::insert(local_34);
              param_2[iVar13] = '\n';
              iVar13 = iVar13 + 1;
              iVar2 = *(int *)(this + 0x174);
            }
            else {
              if (-1 < *(int *)(iVar2 + -4)) {
                std::string::_M_leak_hard();
                bVar6 = *(byte *)(*(int *)(this + 0x174) + uVar3);
              }
              if (bVar6 == 0x86) {
                local_94 = 0;
                local_98[0] = sVar1;
                std::
                map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                ::insert(local_3c);
                iVar2 = *(int *)(this + 0x174);
              }
              else {
                std::string::_M_leak();
                iVar2 = *(int *)(this + 0x174);
                if (*(char *)(iVar2 + uVar3) == -0x79) {
                  puVar10 = (uint *)(iVar2 + -0xc);
                  uVar12 = uVar3;
                  if (iVar13 == 0) goto LAB_2e2533c4;
                  uVar12 = iVar13 - 1U & 0xffff;
                  uVar11 = (undefined2)(iVar13 - 1U);
                  pmVar7 = pmVar14;
                  pmVar8 = *(map **)(param_1 + 8);
                  if (*(map **)(param_1 + 8) != (map *)0x0) {
                    do {
                      if (*(ushort *)(pmVar8 + 0x10) < uVar12) {
                        pmVar4 = *(map **)(pmVar8 + 0xc);
                      }
                      else {
                        pmVar4 = *(map **)(pmVar8 + 8);
                        pmVar7 = pmVar8;
                      }
                      pmVar8 = pmVar4;
                    } while (pmVar4 != (map *)0x0);
                    if (((pmVar7 != pmVar14) && (*(ushort *)(pmVar7 + 0x10) <= uVar12)) &&
                       (*(int *)(pmVar7 + 0x14) == 0)) {
                      std::
                      map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                      ::erase((map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                               *)param_1,pmVar7,local_48);
                      local_84 = 2;
                      local_88[0] = uVar11;
                      std::
                      map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                      ::insert(local_44);
                    }
                  }
                  local_74 = 1;
                  local_78[0] = uVar11;
                  std::
                  map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                  ::insert(local_4c);
                  iVar2 = *(int *)(this + 0x174);
                }
              }
            }
          }
          else {
LAB_2e253350:
            if (-1 < (int)puVar10[2]) {
              std::string::_M_leak_hard();
              iVar2 = *(int *)(this + 0x174);
              puVar10 = (uint *)(iVar2 + -0xc);
            }
            if ((*(char *)(iVar2 + uVar12) == -0x3e) &&
               (uVar3 = uVar12 + 1, (uVar3 & 0xffff) < *puVar10)) {
              if (-1 < (int)puVar10[2]) {
                std::string::_M_leak_hard();
                iVar2 = *(int *)(this + 0x174);
              }
              puVar10 = (uint *)(iVar2 + -0xc);
              if (*(char *)(iVar2 + uVar3) == -0x53) {
                puVar10 = (uint *)(iVar2 + -0xc);
                uVar12 = uVar3;
                if (iVar13 == 0) goto LAB_2e2533c4;
                local_68[0] = sVar1 + -1;
                local_64 = 4;
                std::
                map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                ::insert(local_54);
                iVar2 = *(int *)(this + 0x174);
                goto LAB_2e2533c0;
              }
            }
            if (-1 < (int)puVar10[2]) {
              std::string::_M_leak_hard();
              iVar2 = *(int *)(this + 0x174);
            }
            param_2[iVar13] = *(char *)(iVar2 + uVar12);
            iVar2 = *(int *)(this + 0x174);
            iVar13 = iVar13 + 1;
            uVar3 = uVar12;
          }
LAB_2e2533c0:
          puVar10 = (uint *)(iVar2 + -0xc);
          uVar12 = uVar3;
        }
        else {
          if (-1 < *(int *)(iVar2 + -4)) {
            std::string::_M_leak_hard();
            iVar2 = *(int *)(this + 0x174);
            pbVar9 = (byte *)(iVar2 + uVar12);
            bVar6 = *pbVar9;
          }
          puVar10 = (uint *)(iVar2 + -0xc);
          if (0x1f < bVar6) goto LAB_2e253318;
          if (-1 < *(int *)(iVar2 + -4)) {
            std::string::_M_leak_hard();
            iVar2 = *(int *)(this + 0x174);
            pbVar9 = (byte *)(iVar2 + uVar12);
            bVar6 = *pbVar9;
            puVar10 = (uint *)(iVar2 + -0xc);
          }
          if (bVar6 == 10) {
            uVar3 = puVar10[2];
            goto LAB_2e25331c;
          }
        }
LAB_2e2533c4:
        uVar12 = uVar12 + 1;
        if (*puVar10 <= uVar12) {
          param_2[iVar13] = '\0';
          if (iVar13 != 0) {
            pmVar7 = *(map **)(param_1 + 8);
            uVar12 = iVar13 - 1U & 0xffff;
            if (pmVar7 != (map *)0x0) {
              do {
                if (*(ushort *)(pmVar7 + 0x10) < uVar12) {
                  pmVar8 = *(map **)(pmVar7 + 0xc);
                }
                else {
                  pmVar8 = *(map **)(pmVar7 + 8);
                  pmVar14 = pmVar7;
                }
                pmVar7 = pmVar8;
              } while (pmVar7 != (map *)0x0);
              if (((local_58 != pmVar14) && (*(ushort *)(pmVar14 + 0x10) <= uVar12)) &&
                 (*(int *)(pmVar14 + 0x14) == 4)) {
                std::
                map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                ::erase((map<unsigned_short,MWidget::CONTROL_FLAG,std::less<unsigned_short>,std::allocator<std::pair<unsigned_short_const,MWidget::CONTROL_FLAG>>>
                         *)param_1);
                return 1;
              }
            }
          }
          return 1;
        }
      } while( true );
    }
    *param_2 = '\0';
    uVar5 = 1;
  }
  return uVar5;
}

