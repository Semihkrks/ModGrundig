
/* MWidget::DrawBackground(_Rect&, unsigned char) */

void MWidget::DrawBackground(_Rect *param_1,uchar param_2)

{
  uint uVar1;
  int iVar2;
  _IDirectFBSurface *p_Var3;
  MResourceManager *this;
  undefined3 in_register_00000015;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = QueryVisualState((MWidget *)param_1);
  iVar2 = QueryFlag((MWidget *)param_1,'\x01');
  if (iVar2 == 0) {
    iVar2 = QueryFlag((MWidget *)param_1,'\x04');
    uVar1 = (uint)(iVar2 != 0);
  }
  p_Var3 = (_IDirectFBSurface *)GetDFBSurface((MWidget *)param_1);
  ClipDFBSurface((MWidget *)param_1,(_Rect *)CONCAT31(in_register_00000015,param_2));
  uVar4 = *(uint *)(param_1 + (uVar1 + 0x12) * 4 + 4);
  uVar6 = *(uint *)(param_1 + (uVar1 + 0x16) * 4 + 4);
  uVar7 = *(uint *)(param_1 + (uVar1 + 0x1a) * 4 + 4);
  if (param_1[0x39] != (_Rect)0x0) {
    if (param_1[0x3a] == (_Rect)0x1) {
      this = (MResourceManager *)MSystem::GetMResourceManager();
      if (this != (MResourceManager *)0x0) {
        GetAbsRect((MWidget *)param_1,(_Rect *)&local_30);
        local_40 = local_30;
        if (*(int *)(param_1 + 0x1c) <= local_30) {
          local_40 = *(int *)(param_1 + 0x1c);
        }
        local_3c = local_2c;
        if (*(int *)(param_1 + 0x20) <= local_2c) {
          local_3c = *(int *)(param_1 + 0x20);
        }
        local_34 = local_24;
        local_38 = local_28;
        MResourceManager::RenderImageToSurface
                  (this,(MImg *)(param_1 + uVar1 * 0x14 + 0xb8),p_Var3,(DFBRectangle *)&local_40,
                   (MWidget *)param_1);
        DrawBorders((MWidget *)param_1,p_Var3);
        return;
      }
      printf("ASSERT FAIL: %s %s %d\n","./base/MWidget.cpp",
             "virtual void MWidget::DrawBackground(Rect&, BOOL)",0x9fa);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    GetAbsRect((MWidget *)param_1,(_Rect *)&local_30);
    if (*(int *)(param_1 + 0x1c) < local_30) {
      local_30 = *(int *)(param_1 + 0x1c);
    }
    if (*(int *)(param_1 + 0x20) < local_2c) {
      local_2c = *(int *)(param_1 + 0x20);
    }
    iVar2 = 0;
    if (local_30 < 1) {
      iVar2 = local_30;
    }
    iVar5 = 0;
    if (local_2c < 1) {
      iVar5 = local_2c;
    }
    (**(code **)(p_Var3 + 0x54))
              (p_Var3,(uVar4 & 0xffffff) >> 0x10,(uVar4 & 0xffff) >> 8,uVar4 & 0xff,uVar4 >> 0x18);
    (**(code **)(p_Var3 + 0x94))
              (p_Var3,0,0,iVar2 + *(int *)(param_1 + 0x24),iVar5 + *(int *)(param_1 + 0x28));
    (**(code **)(p_Var3 + 0x54))
              (p_Var3,(uVar6 & 0xffffff) >> 0x10,(uVar6 & 0xffff) >> 8,uVar6 & 0xff,uVar6 >> 0x18);
    if (iVar5 == 0) {
      (**(code **)(p_Var3 + 0x94))(p_Var3,0,0,iVar2 + *(int *)(param_1 + 0x24),param_1[0x1a3]);
    }
    if (iVar2 == 0) {
      (**(code **)(p_Var3 + 0x94))(p_Var3,0,0,param_1[0x1a3],iVar5 + *(int *)(param_1 + 0x28));
    }
    (**(code **)(p_Var3 + 0x54))
              (p_Var3,(uVar7 & 0xffffff) >> 0x10,(uVar7 & 0xffff) >> 8,uVar7 & 0xff,uVar7 >> 0x18);
    (**(code **)(p_Var3 + 0x94))
              (p_Var3,0,(iVar5 - (uint)(byte)param_1[0x1a3]) + *(int *)(param_1 + 0x28),
               iVar2 + *(int *)(param_1 + 0x24),(uint)(byte)param_1[0x1a3]);
    (**(code **)(p_Var3 + 0x94))
              (p_Var3,(iVar2 - (uint)(byte)param_1[0x1a3]) + *(int *)(param_1 + 0x24),0,
               (uint)(byte)param_1[0x1a3],iVar5 + *(int *)(param_1 + 0x28));
  }
  DrawBorders((MWidget *)param_1,p_Var3);
  return;
}

