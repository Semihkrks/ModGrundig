
/* MMainFrame::SetFocus(MWidget*) */

undefined4 __thiscall MMainFrame::SetFocus(MMainFrame *this,MWidget *param_1)

{
  int *piVar1;
  int iVar2;
  MWidget *this_00;
  MWidget *pMVar3;
  
  if ((param_1 != (MWidget *)0x0) &&
     ((piVar1 = (int *)__dynamic_cast(param_1,&MWidget::typeinfo,&Container::typeinfo,0),
      piVar1 == (int *)0x0 ||
      (param_1 = (MWidget *)(**(code **)(*piVar1 + 0x58))(piVar1), param_1 != (MWidget *)0x0)))) {
    MWidget::SetFlag(param_1,4,1);
    MWidget::Invalidate(param_1);
    iVar2 = MWnd::GetParent((MWnd *)param_1);
    pMVar3 = param_1;
    if (iVar2 != 0) {
      do {
        this_00 = (MWidget *)__dynamic_cast(iVar2,&MWidget::typeinfo,&Container::typeinfo,0);
        if (this_00 == (MWidget *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n","./base/MMainFrame.cpp",
                 "BOOL MMainFrame::SetFocus(MWidget*)",0x82b);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        (**(code **)(*(int *)this_00 + 0x4c))(this_00,pMVar3,0);
        MWidget::Invalidate(this_00);
        iVar2 = MWnd::GetParent((MWnd *)this_00);
        pMVar3 = this_00;
      } while (iVar2 != 0);
      *(MWidget **)(this + 0x3c) = param_1;
      iVar2 = MWidget::GetID(param_1);
      MEvtHandle::PostEvent((MEvtHandle *)this,0,0x16,iVar2 << 0x10 | 9);
      return 1;
    }
  }
  return 0;
}

