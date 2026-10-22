
/* MMainFrame::SwitchFocusTo(MWidget*) */

undefined4 __thiscall MMainFrame::SwitchFocusTo(MMainFrame *this,MWidget *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  MWnd *pMVar8;
  MWnd *pMVar9;
  MWidget *local_res4 [3];
  undefined4 uVar10;
  MWidget *local_50;
  MWnd *local_4c;
  MWnd *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  undefined4 *local_30;
  
  local_50 = *(MWidget **)(this + 0x3c);
  local_res4[0] = param_1;
  if (((param_1 != (MWidget *)0x0) &&
      (piVar1 = (int *)__dynamic_cast(param_1,&MWidget::typeinfo,&Container::typeinfo,0),
      piVar1 != (int *)0x0)) &&
     (local_res4[0] = (MWidget *)(**(code **)(*piVar1 + 0x58))(piVar1),
     local_res4[0] == (MWidget *)0x0)) {
    return 0;
  }
  if (local_50 == (MWidget *)0x0) {
    SetFocus(this,local_res4[0]);
    return 1;
  }
  local_44 = (int *)0x0;
  local_40 = (int *)0x0;
  local_3c = (int *)0x0;
  local_38 = (int *)0x0;
  local_34 = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
                    /* try { // try from 2e234494 to 2e2349af has its CatchHandler @ 2e234a58 */
  std::vector<MWidget*,std::allocator<MWidget*>>::_M_insert_aux
            ((vector<MWidget*,std::allocator<MWidget*>> *)&local_44,0,&local_50);
  if (local_34 == local_30) {
    std::vector<MWidget*,std::allocator<MWidget*>>::_M_insert_aux
              ((vector<MWidget*,std::allocator<MWidget*>> *)&local_38,local_34,local_res4);
  }
  else {
    if (local_34 != (undefined4 *)0x0) {
      *local_34 = (int)local_res4[0];
    }
    local_34 = local_34 + 1;
  }
  MWidget::SetFlag(local_50,4,0);
  MWidget::Invalidate(local_50);
  iVar2 = MWidget::GetID(local_50);
  MEvtHandle::PostEvent((MEvtHandle *)this,0,0x16,iVar2 << 0x10 | 7);
  MWidget::SetFlag(local_res4[0],4,1);
  MWidget::Invalidate(local_res4[0]);
  *(MWidget **)(this + 0x3c) = local_res4[0];
  iVar2 = MWidget::GetID(local_res4[0]);
  uVar10 = 0;
  MEvtHandle::PostEvent((MEvtHandle *)this,0,0x16,iVar2 << 0x10 | 9);
  local_4c = (MWnd *)MWnd::GetParent((MWnd *)local_50);
  local_48 = (MWnd *)MWnd::GetParent((MWnd *)local_res4[0]);
  do {
    if (local_4c == local_48) {
                    /* try { // try from 2e234a10 to 2e234a4f has its CatchHandler @ 2e234a58 */
      std::vector<MWidget*,std::allocator<MWidget*>>::push_back
                ((vector<MWidget*,std::allocator<MWidget*>> *)&local_44,(MWidget **)&local_4c);
      std::vector<MWidget*,std::allocator<MWidget*>>::push_back
                ((vector<MWidget*,std::allocator<MWidget*>> *)&local_38,(MWidget **)&local_48);
      pMVar9 = local_4c;
      break;
    }
    uVar5 = (int)local_40 - (int)local_44 >> 2;
    pMVar8 = (MWnd *)0x0;
    if ((uVar5 != 0) && (pMVar8 = local_48, local_48 != (MWnd *)*local_44)) {
      uVar4 = 0;
      piVar1 = local_44;
      do {
        uVar4 = uVar4 + 1;
        pMVar8 = (MWnd *)0x0;
        if (uVar5 <= uVar4) break;
        piVar3 = piVar1 + 1;
        piVar1 = piVar1 + 1;
        pMVar8 = local_48;
      } while (local_48 != (MWnd *)*piVar3);
    }
    uVar5 = (int)local_34 - (int)local_38 >> 2;
    pMVar9 = pMVar8;
    if ((uVar5 != 0) && (pMVar9 = local_4c, local_4c != (MWnd *)*local_38)) {
      uVar4 = 0;
      piVar1 = local_38;
      do {
        uVar4 = uVar4 + 1;
        pMVar9 = pMVar8;
        if (uVar5 <= uVar4) break;
        piVar3 = piVar1 + 1;
        piVar1 = piVar1 + 1;
        pMVar9 = local_4c;
      } while (local_4c != (MWnd *)*piVar3);
    }
    if (local_4c != (MWnd *)0x0) {
      if (local_3c == local_40) {
        std::vector<MWidget*,std::allocator<MWidget*>>::_M_insert_aux
                  ((vector<MWidget*,std::allocator<MWidget*>> *)&local_44,local_40,&local_4c,uVar5,
                   uVar10);
        piVar1 = local_40;
      }
      else {
        piVar1 = local_40 + 1;
        if (local_40 != (int *)0x0) {
          *local_40 = (int)local_4c;
        }
      }
      local_40 = piVar1;
      local_4c = (MWnd *)MWnd::GetParent(local_4c);
    }
    if (local_48 != (MWnd *)0x0) {
      if (local_34 == local_30) {
        std::vector<MWidget*,std::allocator<MWidget*>>::_M_insert_aux
                  ((vector<MWidget*,std::allocator<MWidget*>> *)&local_38,local_34,&local_48);
        piVar1 = local_34;
      }
      else {
        piVar1 = local_34 + 1;
        if (local_34 != (undefined4 *)0x0) {
          *local_34 = (int)local_48;
        }
      }
      local_34 = piVar1;
      local_48 = (MWnd *)MWnd::GetParent(local_48);
    }
  } while (pMVar9 == (MWnd *)0x0);
  if ((uint)((int)local_40 - (int)local_44 >> 2) < 2) {
LAB_2e234888:
    if ((uint)((int)local_34 - (int)local_38 >> 2) < 2) {
LAB_2e23481c:
      local_34 = local_38;
      local_40 = local_44;
      if (local_38 != (int *)0x0) {
        operator_delete(local_38);
      }
      if (local_44 != (int *)0x0) {
        operator_delete(local_44);
      }
      return 1;
    }
    iVar2 = local_38[1];
    if (iVar2 != 0) {
      uVar5 = 1;
      iVar7 = 4;
      iVar6 = 0;
      do {
        piVar1 = local_38;
        piVar3 = (int *)__dynamic_cast(iVar2,&MWidget::typeinfo,&Container::typeinfo,0);
        if (piVar3 == (int *)0x0) break;
        (**(code **)(*piVar3 + 0x4c))(piVar3,*(undefined4 *)((int)piVar1 + iVar6),0);
        MWidget::Invalidate(*(MWidget **)((int)local_38 + iVar6));
        if (*(MWnd **)((int)local_38 + iVar7) == pMVar9) goto LAB_2e23481c;
        uVar5 = uVar5 + 1;
        iVar7 = uVar5 * 4;
        if ((uint)((int)local_34 - (int)local_38 >> 2) <= uVar5) goto LAB_2e23481c;
        iVar2 = local_38[uVar5];
        iVar6 = iVar6 + 4;
      } while (iVar2 != 0);
    }
    printf("ASSERT FAIL: %s %s %d\n","./base/MMainFrame.cpp",
           "BOOL MMainFrame::SwitchFocusTo(MWidget*)",0x581);
  }
  else {
    iVar2 = local_44[1];
    if (iVar2 != 0) {
      uVar5 = 1;
      iVar7 = 4;
      iVar6 = 0;
      do {
        piVar1 = local_44;
        piVar3 = (int *)__dynamic_cast(iVar2,&MWidget::typeinfo,&Container::typeinfo,0);
        if (piVar3 == (int *)0x0) break;
        (**(code **)(*piVar3 + 0x50))(piVar3,*(undefined4 *)((int)piVar1 + iVar6),0);
        MWidget::Invalidate(*(MWidget **)((int)local_44 + iVar6));
        if (*(MWnd **)((int)local_44 + iVar7) == pMVar9) goto LAB_2e234888;
        uVar5 = uVar5 + 1;
        iVar7 = uVar5 * 4;
        if ((uint)((int)local_40 - (int)local_44 >> 2) <= uVar5) goto LAB_2e234888;
        iVar2 = local_44[uVar5];
        iVar6 = iVar6 + 4;
      } while (iVar2 != 0);
    }
    printf("ASSERT FAIL: %s %s %d\n","./base/MMainFrame.cpp",
           "BOOL MMainFrame::SwitchFocusTo(MWidget*)",0x56e);
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

