
/* MWidget::OnAnimationTimer(void*, void*, void*) */

undefined4 MWidget::OnAnimationTimer(void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  MApplet *this;
  
  if (*(char *)((int)param_1 + 0x224) == '\0') {
    return 0;
  }
  if (param_3 != *(void **)((int)param_1 + 0x1ec)) {
    return 0;
  }
  ClearDFBSurface(param_1,(_Rect *)0x0);
  Invalidate(param_1);
  GetAbsRect(param_1,(_Rect *)((int)param_1 + 0x228));
  iVar1 = (**(code **)(**(int **)((int)param_1 + 0x1e4) + 8))
                    (*(int **)((int)param_1 + 0x1e4),*(undefined4 *)((int)param_1 + 0x1e8),
                     (int)param_1 + 0x1f0,(_Rect *)((int)param_1 + 0x228),(int)param_1 + 0x1c);
  iVar2 = QueryFlag(param_1,'\x02');
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)param_1 + 0x1e8);
    if ((uint)(iVar2 * 0x32) <= *(uint *)(*(int *)((int)param_1 + 0x1e4) + 0xc)) goto LAB_2e25a2b8;
    SetFlag(param_1,2,1);
  }
  iVar2 = *(int *)((int)param_1 + 0x1e8);
LAB_2e25a2b8:
  *(int *)((int)param_1 + 0x1e8) = iVar2 + 1;
  Invalidate(param_1);
  pvVar3 = (void *)GetParentMainFrame();
  MMainFrame::OnPaint(pvVar3,(void *)0x0,(void *)0x0);
  if ((iVar1 != 0) && (iVar1 = FinalizeAnimation(param_1,false), iVar1 != 0)) {
    this = (MApplet *)MWnd::GetParentApp(param_1);
    pvVar3 = (void *)MApplet::GetMainFrame(this);
    MMainFrame::OnPaint(pvVar3,(void *)0x0,(void *)0x0);
  }
  return 0;
}

