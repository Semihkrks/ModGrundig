
/* MWidget::ShowBorder(unsigned char, unsigned long, unsigned long, unsigned char, unsigned char,
   unsigned long) */

void __thiscall
MWidget::ShowBorder(MWidget *this,uchar param_1,ulong param_2,ulong param_3,uchar param_4,
                   uchar param_5,ulong param_6)

{
  MMainFrame *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  pthread_mutex_t *__mutex;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  
  *(ulong *)(this + 0x164) = param_2;
  if (((param_1 == '\x01') && (MSystem::OSD_RESOLUTION_WIDTH != 0x780)) &&
     (MSystem::OSD_RESOLUTION_HEIGHT != 0x438)) {
    this[0x161] = (MWidget)0x2;
    this[0x160] = SUB41(param_3,0);
  }
  else {
    this[0x161] = (MWidget)param_1;
    this[0x160] = SUB41(param_3,0);
  }
  if (param_4 == '\0') {
    *(ulong *)(this + 0x16c) = param_2;
    this[0x168] = (MWidget)param_1;
  }
  else {
    *(ulong *)(this + 0x16c) = param_6;
    this[0x168] = (MWidget)param_5;
  }
  __mutex = (pthread_mutex_t *)(this + 0x1cc);
  this_00 = (MMainFrame *)GetParentMainFrame();
  pthread_mutex_lock(__mutex);
  if ((*(int *)(this + 0x24) != 0) && (*(int *)(this + 0x28) != 0)) {
    GetAbsRect(this,(_Rect *)&iStack_28);
    iVar6 = iStack_28;
    iVar5 = iStack_24;
    iVar2 = iStack_20;
    iVar1 = iStack_1c;
    if (*(int *)(this + 0x1e4) != 0) {
      iVar4 = *(int *)(this + 0x234);
      iVar3 = *(int *)(this + 0x230);
      iVar8 = *(int *)(this + 0x22c);
      iVar7 = *(int *)(this + 0x228);
      if (*(int *)(*(int *)(this + 0x1e4) + 0x1c) == 4) {
        iVar8 = iVar8 + *(int *)(this + 0x1c0);
        iVar7 = iVar7 + *(int *)(this + 0x1bc);
      }
      iVar6 = iVar7;
      iVar5 = iVar8;
      iVar2 = iVar3;
      iVar1 = iVar4;
      if (((iStack_20 != 0) && (iStack_1c != 0)) &&
         ((iVar6 = iStack_28, iVar5 = iStack_24, iVar2 = iStack_20, iVar1 = iStack_1c, iVar3 != 0 &&
          (iVar4 != 0)))) {
        if (iVar7 <= iStack_28) {
          iVar6 = iVar7;
        }
        if (iVar8 <= iStack_24) {
          iVar5 = iVar8;
        }
        iVar1 = iVar8 + iVar4;
        if (iVar8 + iVar4 < iStack_24 + iStack_1c) {
          iVar1 = iStack_24 + iStack_1c;
        }
        iVar2 = iVar7 + iVar3;
        if (iVar7 + iVar3 < iStack_28 + iStack_20) {
          iVar2 = iStack_28 + iStack_20;
        }
        iVar2 = iVar2 - iVar6;
        iVar1 = iVar1 - iVar5;
      }
    }
    iStack_1c = iVar1;
    iStack_20 = iVar2;
    iStack_24 = iVar5;
    iStack_28 = iVar6;
    pthread_mutex_unlock(__mutex);
    MMainFrame::InvalidateClientArea(this_00,(_Rect *)&iStack_28);
    return;
  }
  pthread_mutex_unlock(__mutex);
  return;
}

