
/* Image::Update(_Rect&, unsigned char) */

void Image::Update(_Rect *param_1,uchar param_2)

{
  int iVar1;
  int iVar2;
  _IDirectFBSurface *p_Var3;
  MResourceManager *this;
  undefined3 in_register_00000015;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = MWidget::QueryVisualState((MWidget *)param_1);
  iVar2 = MWidget::QueryFlag((MWidget *)param_1,'\x02');
  if (((iVar2 != 0) && (*(int *)(param_1 + 0x24) != 0)) && (*(int *)(param_1 + 0x28) != 0)) {
    p_Var3 = (_IDirectFBSurface *)MWidget::GetDFBSurface((MWidget *)param_1);
    MWidget::ClipDFBSurface((MWidget *)param_1,(_Rect *)CONCAT31(in_register_00000015,param_2));
    (**(code **)(p_Var3 + 0x78))(p_Var3,1);
    MWidget::GetAbsRect((MWidget *)param_1,(_Rect *)&local_28);
    local_34 = local_24;
    if (*(int *)(param_1 + 0x20) <= local_24) {
      local_34 = *(int *)(param_1 + 0x20);
    }
    local_38 = local_28;
    if (*(int *)(param_1 + 0x1c) <= local_28) {
      local_38 = *(int *)(param_1 + 0x1c);
    }
    local_30 = local_20;
    local_2c = local_1c;
    this = (MResourceManager *)MSystem::GetMResourceManager();
    if (this == (MResourceManager *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n","./widget/Image.cpp",
             "virtual void Image::Update(Rect&, BOOL)",0x173);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    iVar2 = MResourceManager::RenderImageToSurface
                      (this,(MImg *)(param_1 + iVar1 * 0x14 + 0x260),p_Var3,
                       (DFBRectangle *)&local_38,(MWidget *)param_1);
    if (iVar2 == 0) {
      MImg::QueryFlag((MImg *)(param_1 + iVar1 * 0x14 + 0x260),'\x01');
    }
  }
  return;
}

