
/* MWidget::DrawString(_IDirectFBSurface*, _IDirectFBFont*, char const*, int, long&, long&,
   DFBSurfaceTextFlags, unsigned short, std::map<unsigned short, MWidget::CONTROL_FLAG,
   std::less<unsigned short>, std::allocator<std::pair<unsigned short const, MWidget::CONTROL_FLAG>
   > >*) */

void __thiscall
MWidget::DrawString(MWidget *this,int param_1,int param_2,char *param_3,uint param_4,int *param_5,
                   undefined4 *param_6,uint param_8,ushort param_9,int param_10)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  int local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 auStack_84 [8];
  int local_7c;
  undefined1 auStack_74 [8];
  int local_6c;
  undefined1 auStack_64 [8];
  int local_5c;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  int *local_34;
  uint local_30;
  
  local_44 = (uint)param_9;
  if ((param_1 == 0) || (param_2 == 0)) {
    return;
  }
  if ((int)param_4 < 0) {
    uVar12 = 0x17f7;
  }
  else if (param_3 == (char *)0x0) {
    uVar12 = 0x17f9;
  }
  else {
    iVar7 = QueryVisualState(this);
    local_48 = *param_5;
    if (*(short *)(this + iVar7 * 0xc + 0x138) != 5) {
      param_8 = param_8 | 0x20;
    }
    pcVar8 = operator_new__(param_4 + 2,(nothrow_t *)&DAT_2c7f5bd0);
    if (pcVar8 != (char *)0x0) {
      local_3c = auStack_64;
      *pcVar8 = '\0';
      local_40 = auStack_84;
      iVar7 = param_10 + 4;
      local_38 = auStack_74;
      local_34 = &local_e8;
      local_30 = param_8 | 0x20;
      iVar15 = 0;
      uVar14 = 0;
      local_4c = 0;
      local_50 = iVar7;
      while( true ) {
        pcVar13 = param_3 + uVar14;
        cVar2 = *pcVar13;
        if ((((cVar2 == -0x12) && ((int)(uVar14 + 2) < (int)param_4)) && (pcVar13[1] == -0x7e)) &&
           (pcVar13[2] == -0x76)) {
          uVar14 = uVar14 + 3;
          goto LAB_2e24e0c4;
        }
        if (((uVar14 == param_4) || (cVar2 == '\n')) || (cVar2 == '\0')) break;
        iVar10 = *(int *)(param_10 + 8);
        uVar11 = local_44 + uVar14 & 0xffff;
        if (iVar10 == 0) {
LAB_2e24e15c:
          iVar10 = iVar15 + 1;
LAB_2e24e0b8:
          pcVar8[iVar15] = cVar2;
          uVar14 = uVar14 + 1;
          iVar15 = iVar10;
        }
        else {
          uVar3 = *(ushort *)(iVar10 + 0x10);
          iVar5 = iVar7;
          while( true ) {
            if (uVar3 < uVar11) {
              iVar6 = *(int *)(iVar10 + 0xc);
            }
            else {
              iVar6 = *(int *)(iVar10 + 8);
              iVar5 = iVar10;
            }
            iVar10 = iVar6;
            if (iVar10 == 0) break;
            uVar3 = *(ushort *)(iVar10 + 0x10);
          }
          if ((iVar5 == iVar7) || (uVar11 < *(ushort *)(iVar5 + 0x10))) goto LAB_2e24e15c;
          iVar10 = *(int *)(iVar5 + 0x14);
          if (iVar10 == 0) {
            iVar10 = QueryVisualState(this);
            if (*(short *)(this + iVar10 * 0xc + 0x138) == 5) {
              (**(code **)(param_1 + 0xbc))(param_1,pcVar8,iVar15,*param_5,*param_6,param_8);
            }
            else {
              local_b8 = 0x10000;
              local_bc = 0;
              local_c0 = 0;
              local_c4 = 0x10000;
              (**(code **)(param_1 + 0xfc))
                        (param_1,pcVar8,iVar15,*param_5,*param_6,local_30,0x10000,0,0,0x10000);
            }
            if (iVar15 != 0) {
              local_e8 = 0;
              (**(code **)(param_2 + 0x28))(param_2,pcVar8,iVar15,local_40,local_3c);
              (**(code **)(param_2 + 0x2c))(param_2,(int)pcVar8[iVar15 + -1],local_38,local_34);
              *param_5 = *param_5 + ((local_e8 + local_7c) - local_6c);
            }
            *pcVar8 = '\0';
            iVar15 = 0;
            local_4c = 1;
            iVar10 = 1;
            goto LAB_2e24e0b8;
          }
          if (iVar10 == 1) {
            pcVar8[iVar15] = cVar2;
            local_a8 = 0x10000;
            local_ac = 0;
            local_b0 = 0;
            local_b4 = 0x10000;
            (**(code **)(param_1 + 0xfc))
                      (param_1,pcVar8,iVar15 + 1,*param_5,*param_6,local_30,0x10000,0,0,0x10000);
            local_e8 = 0;
            (**(code **)(param_2 + 0x28))(param_2,pcVar8,iVar15 + 1,local_3c,local_40);
            uVar14 = uVar14 + 1;
            (**(code **)(param_2 + 0x2c))(param_2,(int)pcVar8[iVar15],local_38,local_34);
            iVar15 = 0;
            *param_5 = *param_5 + ((local_e8 + local_5c) - local_6c);
            *pcVar8 = '\0';
            local_4c = 0;
          }
          else {
            if (iVar10 != 2) goto LAB_2e24e15c;
            iVar10 = QueryVisualState(this);
            if (*(short *)(this + iVar10 * 0xc + 0x138) == 5) {
              (**(code **)(param_1 + 0xbc))(param_1,pcVar8,iVar15,*param_5,*param_6,param_8);
            }
            else {
              local_98 = 0x10000;
              local_9c = 0;
              local_a0 = 0;
              local_a4 = 0x10000;
              (**(code **)(param_1 + 0xfc))
                        (param_1,pcVar8,iVar15,*param_5,*param_6,local_30,0x10000,0,0,0x10000);
            }
            if (iVar15 != 0) {
              local_e8 = 0;
              (**(code **)(param_2 + 0x28))(param_2,pcVar8,iVar15,local_40,local_3c);
              (**(code **)(param_2 + 0x2c))(param_2,(int)pcVar8[iVar15 + -1],local_38,local_34);
              *param_5 = *param_5 + ((local_e8 + local_7c) - local_6c);
            }
            *pcVar8 = cVar2;
            local_88 = 0x10000;
            local_8c = 0;
            local_90 = 0;
            local_94 = 0x10000;
            (**(code **)(param_1 + 0xfc))
                      (param_1,pcVar8,1,*param_5,*param_6,local_30,0x10000,0,0,0x10000);
            local_e8 = 0;
            (**(code **)(param_2 + 0x28))(param_2,pcVar8,1,local_3c,local_40);
            uVar14 = uVar14 + 1;
            (**(code **)(param_2 + 0x2c))(param_2,(int)*pcVar8,local_38,local_34);
            iVar15 = 0;
            *param_5 = *param_5 + ((local_e8 + local_5c) - local_6c);
            *pcVar8 = '\0';
          }
        }
LAB_2e24e0c4:
        if ((int)param_4 < (int)uVar14) goto LAB_2e24e0d0;
      }
      if (local_4c == 0) {
        if (param_4 - 1 == uVar14) {
          iVar10 = *(int *)(param_10 + 8);
          uVar11 = local_44 + (param_4 - 2) & 0xffff;
          if (iVar10 != 0) {
            uVar3 = *(ushort *)(iVar10 + 0x10);
            while( true ) {
              if (uVar3 < uVar11) {
                iVar5 = *(int *)(iVar10 + 0xc);
              }
              else {
                iVar5 = *(int *)(iVar10 + 8);
                iVar7 = iVar10;
              }
              iVar10 = iVar5;
              if (iVar10 == 0) break;
              uVar3 = *(ushort *)(iVar10 + 0x10);
            }
            if ((iVar7 != local_50) && (*(ushort *)(iVar7 + 0x10) <= uVar11)) {
              sVar9 = strlen(param_3);
              if ((param_4 - 1 == sVar9) || (sVar9 <= uVar14)) {
LAB_2e24e724:
                bVar4 = true;
              }
              else {
                cVar2 = *pcVar13;
                while (cVar2 == '\n') {
                  uVar14 = uVar14 + 1;
                  if (sVar9 <= uVar14) goto LAB_2e24e724;
                  pcVar1 = pcVar13 + 1;
                  pcVar13 = pcVar13 + 1;
                  cVar2 = *pcVar1;
                }
                bVar4 = cVar2 == '\0';
              }
              if ((*(int *)(iVar7 + 0x14) == 4) && (!bVar4)) {
                (pcVar8 + iVar15)[1] = -0x53;
                pcVar8[iVar15] = -0x3e;
                iVar15 = iVar15 + 2;
              }
            }
          }
        }
        iVar7 = QueryVisualState(this);
        if (*(short *)(this + iVar7 * 0xc + 0x138) == 5) {
          (**(code **)(param_1 + 0xbc))(param_1,pcVar8,iVar15,*param_5,*param_6,param_8);
        }
        else {
          local_cc = 0;
          local_d0 = 0;
          local_c8 = 0x10000;
          local_d4 = 0x10000;
          (**(code **)(param_1 + 0xfc))
                    (param_1,pcVar8,iVar15,*param_5,*param_6,param_8 | 0x20,0x10000,0,0,0x10000);
        }
      }
      else {
        local_dc = 0;
        local_d8 = 0x10000;
        local_e0 = 0;
        local_e4 = 0x10000;
        (**(code **)(param_1 + 0xfc))
                  (param_1,pcVar8,iVar15,*param_5,*param_6,param_8 | 0x20,0x10000,0,0,0x10000);
      }
      *pcVar8 = '\0';
      *param_5 = local_48;
LAB_2e24e0d0:
      *param_5 = local_48;
      operator_delete__(pcVar8);
      return;
    }
    uVar12 = 0x1810;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
         "void MWidget::DrawString(IDirectFBSurface*, IDirectFBFont*, const char*, int, S32&, S32&, DFBSurfaceTextFlags, U16, std::map<short unsigned int, MWidget::CONTROL_FLAG, std::less<short unsigned int>, std::allocator<std::pair<const short unsigned int, MWidget::CONTROL_FLAG> > >*)"
         ,uVar12);
                    /* WARNING: Subroutine does not return */
  abort();
}

