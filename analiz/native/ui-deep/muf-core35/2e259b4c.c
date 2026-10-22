
/* MWidget::StartAnimation() */

undefined4 __thiscall MWidget::StartAnimation(MWidget *this)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  Container *this_00;
  MApplet *this_01;
  _Rect *p_Var4;
  MWidget *this_02;
  uint uVar5;
  uint uVar6;
  void *local_28;
  int local_24;
  undefined4 local_20;
  
  if (*(int *)(this + 0x1e4) != 0) {
    if (*(int *)(*(int *)(this + 0x1e4) + 0x10) == 0) {
      return 0;
    }
    if (this[0x224] == (MWidget)0x0) {
      *(undefined4 *)(this + 0x1e8) = 1;
      SetFlag(this,0x10,0);
      this[0x224] = (MWidget)0x1;
      if (*(char *)(*(int *)(this + 0x1e4) + 0x14) == '\0') {
        GetAbsRect(this,(_Rect *)(this + 0x228));
        *(undefined4 *)(this + 0x1e8) = 1;
        (**(code **)(**(int **)(this + 0x1e4) + 8))
                  (*(int **)(this + 0x1e4),1,this + 0x1f0,(_Rect *)(this + 0x228),this + 0x1c);
        MEvtHandle::SetTimer(this,0x32,*(undefined4 *)(this + 0x1ec),0);
        return 1;
      }
      p_Var4 = (_Rect *)(this + 0x228);
      GetAbsRect(this,p_Var4);
      CaptureSnapshot(this);
      *(undefined4 *)(this + 0x1e8) = 1;
      do {
        ClearDFBSurface(this,(_Rect *)0x0);
        Invalidate(this);
        GetAbsRect(this,p_Var4);
        iVar1 = (**(code **)(**(int **)(this + 0x1e4) + 8))
                          (*(int **)(this + 0x1e4),*(undefined4 *)(this + 0x1e8),this + 0x1f0,p_Var4
                           ,this + 0x1c);
        iVar2 = QueryFlag(this,'\x02');
        if ((iVar2 == 0) &&
           (*(uint *)(*(int *)(this + 0x1e4) + 0xc) < (uint)(*(int *)(this + 0x1e8) * 0x32))) {
          SetFlag(this,2,1);
          CaptureSnapshot(this);
        }
        pvVar3 = (void *)GetParentMainFrame();
        MMainFrame::OnPaint(pvVar3,(void *)0x0,(void *)0x0);
        *(int *)(this + 0x1e8) = *(int *)(this + 0x1e8) + 1;
      } while (iVar1 == 0);
      this_00 = (Container *)__dynamic_cast(this,&typeinfo,&Container::typeinfo,0);
      local_28 = (void *)0x0;
      local_24 = 0;
      local_20 = 0;
                    /* try { // try from 2e259d58 to 2e259e03 has its CatchHandler @ 2e259ed4 */
      SetFlag(this,2,1);
      if (this_00 != (Container *)0x0) {
        Container::RecursiveTraverseChild(this_00,this_00,(vector *)&local_28);
      }
      uVar6 = local_24 - (int)local_28 >> 2;
      if (uVar6 != 0) {
        uVar5 = 0;
        do {
          this_02 = *(MWidget **)(local_24 + -4);
          if (this_02 != (MWidget *)0x0) {
            RecreateDFBSurface(this_02);
            (**(code **)(*(int *)this_02 + 0x28))(this_02);
          }
          local_24 = local_24 + -4;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar6);
      }
      ClearDFBSurface(this,(_Rect *)0x0);
      iVar1 = FinalizeAnimation(this,true);
      if (iVar1 != 0) {
                    /* try { // try from 2e259e98 to 2e259ecb has its CatchHandler @ 2e259ed4 */
        this_01 = (MApplet *)MWnd::GetParentApp((MWnd *)this);
        pvVar3 = (void *)MApplet::GetMainFrame(this_01);
        MMainFrame::OnPaint(pvVar3,(void *)0x0,(void *)0x0);
      }
      if (local_28 == (void *)0x0) {
        return 1;
      }
      operator_delete(local_28);
      return 1;
    }
  }
  return 0;
}

