
/* MWidget::DrawString(_IDirectFBSurface*, _IDirectFBFont*, char const*, int, long&, long&,
   DFBSurfaceTextFlags) */

void __thiscall
MWidget::DrawString(MWidget *this,int param_1,int param_2,int param_3,int param_4,int *param_5,
                   undefined4 *param_6,uint param_8)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  undefined4 uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  code *pcVar16;
  int local_b8;
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
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 auStack_74 [8];
  int local_6c;
  undefined1 auStack_64 [8];
  int local_5c;
  int local_50;
  int local_4c;
  uint local_48;
  undefined1 *local_44;
  undefined1 *local_40;
  int *local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return;
  }
  iVar5 = QueryVisualState(this);
  local_50 = *param_5;
  if (*(short *)(this + iVar5 * 0xc + 0x138) != 5) {
    param_8 = param_8 | 0x20;
  }
  if (param_4 < 0) {
    uVar10 = 0x1724;
  }
  else if (param_3 == 0) {
    uVar10 = 0x1726;
  }
  else {
    puVar6 = operator_new__(param_4 + 1,(nothrow_t *)&DAT_2c7f5bd0);
    if (puVar6 != (undefined1 *)0x0) {
      local_4c = param_4 + -1;
      *puVar6 = 0;
      local_44 = auStack_74;
      local_48 = param_8 | 0x20;
      local_40 = auStack_64;
      local_3c = &local_b8;
      iVar14 = 0;
      iVar15 = 0;
      bVar4 = false;
      uVar12 = 0xc2;
      iVar5 = 10;
      uVar13 = 0xee;
      do {
        pbVar11 = (byte *)(param_3 + iVar14);
        bVar8 = *pbVar11;
        iVar9 = (int)(char)bVar8;
        uVar7 = (uint)bVar8;
        if ((uVar7 == uVar12) && (iVar14 + 1 < local_4c)) {
          bVar2 = pbVar11[1] == 0xad;
        }
        else {
          bVar2 = false;
        }
        if (iVar14 == param_4) {
          if ((iVar9 != 10) && (iVar9 != 0)) {
            puVar6[iVar15] = bVar8;
          }
LAB_2e24eb9c:
          if (bVar4) {
            iVar5 = *param_5;
            uVar10 = *param_6;
            pcVar16 = *(code **)(param_1 + 0xfc);
            local_a8 = 0x10000;
            local_ac = 0;
            local_b0 = 0;
            local_b4 = 0x10000;
LAB_2e24ebd8:
            (*pcVar16)(param_1,puVar6,iVar15,iVar5,uVar10,param_8 | 0x20,0x10000,0,0,0x10000);
          }
          else {
            iVar5 = QueryVisualState(this);
            if (*(short *)(this + iVar5 * 0xc + 0x138) != 5) {
              iVar5 = *param_5;
              uVar10 = *param_6;
              pcVar16 = *(code **)(param_1 + 0xfc);
              local_98 = 0x10000;
              local_9c = 0;
              local_a0 = 0;
              local_a4 = 0x10000;
              goto LAB_2e24ebd8;
            }
            (**(code **)(param_1 + 0xbc))(param_1,puVar6,iVar15,*param_5,*param_6,param_8);
          }
          *puVar6 = 0;
          *param_5 = local_50;
          break;
        }
        if ((iVar9 == iVar5) || (iVar9 == 0)) goto LAB_2e24eb9c;
        if (uVar7 - 0x80 < 0x20) {
          if (uVar7 == uVar13) goto LAB_2e24eb5c;
LAB_2e24ea48:
          bVar3 = false;
LAB_2e24ea50:
          if (uVar7 == 0x86) {
            if (!bVar3) goto LAB_2e24ea78;
            local_38 = uVar12;
            local_34 = iVar5;
            local_30 = uVar13;
            iVar5 = QueryVisualState(this);
            if (*(short *)(this + iVar5 * 0xc + 0x138) == 5) {
              (**(code **)(param_1 + 0xbc))(param_1,puVar6,iVar15,*param_5,*param_6,param_8);
            }
            else {
              local_88 = 0x10000;
              local_8c = 0;
              local_90 = 0;
              local_94 = 0x10000;
              (**(code **)(param_1 + 0xfc))
                        (param_1,puVar6,iVar15,*param_5,*param_6,local_48,0x10000,0,0,0x10000);
            }
            if (iVar15 != 0) {
              local_b8 = 0;
              (**(code **)(param_2 + 0x28))(param_2,puVar6,iVar15,0,local_40);
              (**(code **)(param_2 + 0x2c))
                        (param_2,(int)(char)puVar6[iVar15 + -1],local_44,local_3c);
              *param_5 = *param_5 + ((local_b8 + local_5c) - local_6c);
            }
            *puVar6 = 0;
            iVar15 = 0;
            bVar4 = true;
            uVar12 = local_38;
            iVar5 = local_34;
            uVar13 = local_30;
            if (!bVar2) goto LAB_2e24e934;
            iVar14 = iVar14 + 2;
          }
          else {
LAB_2e24ea60:
            if (uVar7 == 0x87) {
              if (!bVar3) goto LAB_2e24ea78;
              local_78 = 0x10000;
              local_7c = 0;
              local_80 = 0;
              local_84 = 0x10000;
              local_38 = uVar12;
              local_34 = iVar5;
              local_30 = uVar13;
              (**(code **)(param_1 + 0xfc))
                        (param_1,puVar6,iVar15,*param_5,*param_6,local_48,0x10000,0,0,0x10000);
              if (iVar15 != 0) {
                local_b8 = 0;
                (**(code **)(param_2 + 0x28))(param_2,puVar6,iVar15,0,local_44);
                (**(code **)(param_2 + 0x2c))
                          (param_2,(int)(char)puVar6[iVar15 + -1],local_40,local_3c);
                *param_5 = *param_5 + ((local_b8 + local_6c) - local_5c);
              }
              *puVar6 = 0;
              iVar15 = 0;
              bVar4 = false;
              uVar12 = local_38;
              iVar5 = local_34;
              uVar13 = local_30;
            }
            else if (!bVar3) {
LAB_2e24ea78:
              puVar6[iVar15] = bVar8;
              iVar15 = iVar15 + 1;
              if (!bVar2) goto LAB_2e24e934;
              iVar14 = iVar14 + 2;
              goto LAB_2e24e938;
            }
LAB_2e24ea30:
            if (!bVar2) goto LAB_2e24e934;
LAB_2e24ea38:
            iVar14 = iVar14 + 2;
          }
        }
        else {
          if (uVar7 == uVar13) {
LAB_2e24eb5c:
            if (pbVar11[1] != 0x82) goto LAB_2e24ea48;
            bVar1 = pbVar11[2];
            bVar3 = false;
            if (bVar1 != 0) {
              iVar14 = iVar14 + 2;
              bVar3 = true;
              uVar7 = (uint)bVar1;
              bVar8 = bVar1;
              goto LAB_2e24ea50;
            }
            goto LAB_2e24ea60;
          }
          if (uVar7 - 1 < 0x1f && uVar7 != 10) goto LAB_2e24ea30;
          if (bVar2) goto LAB_2e24ea38;
          puVar6[iVar15] = bVar8;
          iVar15 = iVar15 + 1;
LAB_2e24e934:
          iVar14 = iVar14 + 1;
        }
LAB_2e24e938:
      } while (iVar14 <= param_4);
      *param_5 = local_50;
      operator_delete__(puVar6);
      return;
    }
    uVar10 = 0x1733;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
         "void MWidget::DrawString(IDirectFBSurface*, IDirectFBFont*, const char*, int, S32&, S32&, DFBSurfaceTextFlags)"
         ,uVar10);
                    /* WARNING: Subroutine does not return */
  abort();
}

