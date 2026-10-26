
undefined4 FUN_00895b84(MWidget *param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  int iVar7;
  _Rect a_Stack_40 [16];
  TextBox *pTStack_30;
  AbsContainer *pAStack_2c;
  AbsContainer *pAStack_28;
  
  lVar2 = GetRcEngine::RcGetNum(0x991);
  lVar3 = GetRcEngine::RcGetNum(0x992);
  lVar4 = GetRcEngine::RcGetNum(0x990);
  lVar5 = GetRcEngine::RcGetNum(0x98f);
  _Rect::set(a_Stack_40,lVar2,lVar3,lVar4,lVar5);
  pAStack_28 = operator_new(0x264);
                    /* try { // try from 00895c80 to 00895c87 has its CatchHandler @ 00895cb0 */
  AbsContainer::AbsContainer(pAStack_28,*(MWidget **)(param_1 + 0x38),a_Stack_40,0,0);
  *(AbsContainer **)(param_1 + 0x180) = pAStack_28;
  if (*(int *)(param_1 + 0x180) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ff1e48,&UNK_00ff1ec8,0x1b0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x38) = 0;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar6 = GetRcEngine::RcGetColor(2);
  *(undefined4 *)(iVar7 + 0x4c) = uVar6;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar6 = GetRcEngine::RcGetColor(2);
  *(undefined4 *)(iVar7 + 0x50) = uVar6;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar6 = GetRcEngine::RcGetColor(2);
  *(undefined4 *)(iVar7 + 0x54) = uVar6;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar6 = GetRcEngine::RcGetColor(2);
  *(undefined4 *)(iVar7 + 0x58) = uVar6;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar7 + 0x9c) = uVar1;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar7 + 0x9e) = uVar1;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar7 + 0xa0) = uVar1;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar7 + 0xa2) = uVar1;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar7 + 0xa4) = uVar1;
  iVar7 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar7 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x180),0x10,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  lVar2 = GetRcEngine::RcGetNum(0x995);
  lVar3 = GetRcEngine::RcGetNum(0x996);
  lVar4 = GetRcEngine::RcGetNum(0x994);
  lVar5 = GetRcEngine::RcGetNum(0x993);
  _Rect::set(a_Stack_40,lVar2,lVar3,lVar4,lVar5);
  pAStack_2c = operator_new(0x264);
                    /* try { // try from 00896050 to 00896057 has its CatchHandler @ 00896080 */
  AbsContainer::AbsContainer(pAStack_2c,*(MWidget **)(param_1 + 0x180),a_Stack_40,0,1);
  *(AbsContainer **)(param_1 + 0x184) = pAStack_2c;
  if (*(int *)(param_1 + 0x184) != 0) {
    iVar7 = *(int *)(param_1 + 0x184);
    uVar6 = GetRcEngine::RcGetColor(0x12);
    *(undefined4 *)(iVar7 + 0x4c) = uVar6;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar6 = GetRcEngine::RcGetColor(0x12);
    *(undefined4 *)(iVar7 + 0x50) = uVar6;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar6 = GetRcEngine::RcGetColor(0x12);
    *(undefined4 *)(iVar7 + 0x54) = uVar6;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar6 = GetRcEngine::RcGetColor(0x12);
    *(undefined4 *)(iVar7 + 0x58) = uVar6;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f5);
    *(undefined2 *)(iVar7 + 0x9c) = uVar1;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f5);
    *(undefined2 *)(iVar7 + 0x9e) = uVar1;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f5);
    *(undefined2 *)(iVar7 + 0xa0) = uVar1;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f5);
    *(undefined2 *)(iVar7 + 0xa2) = uVar1;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f9);
    *(undefined2 *)(iVar7 + 0xa4) = uVar1;
    iVar7 = *(int *)(param_1 + 0x184);
    uVar1 = GetRcEngine::RcGetNum(0x45f9);
    *(undefined2 *)(iVar7 + 0xa6) = uVar1;
    MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xb8);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xcc);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xe0);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xf4);
    (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
              (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184));
    lVar2 = GetRcEngine::RcGetNum(0x999);
    lVar3 = GetRcEngine::RcGetNum(0x99a);
    lVar4 = GetRcEngine::RcGetNum(0x998);
    lVar5 = GetRcEngine::RcGetNum(0x997);
    _Rect::set(a_Stack_40,lVar2,lVar3,lVar4,lVar5);
    pTStack_30 = operator_new(0x250);
                    /* try { // try from 008963e4 to 008963eb has its CatchHandler @ 00896414 */
    TextBox::TextBox(pTStack_30,*(MWidget **)(param_1 + 0x180),a_Stack_40,0,2);
    *(TextBox **)(param_1 + 0x188) = pTStack_30;
    if (*(int *)(param_1 + 0x188) != 0) {
      MString::Set((short)*(undefined4 *)(param_1 + 0x188) + 0x170);
      *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(2);
      *(undefined4 *)(iVar7 + 0x4c) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(2);
      *(undefined4 *)(iVar7 + 0x50) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(2);
      *(undefined4 *)(iVar7 + 0x54) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(2);
      *(undefined4 *)(iVar7 + 0x58) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(0x5e);
      *(undefined4 *)(iVar7 + 0x7c) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(0x5e);
      *(undefined4 *)(iVar7 + 0x80) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(0x5e);
      *(undefined4 *)(iVar7 + 0x84) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar6 = GetRcEngine::RcGetColor(0x5e);
      *(undefined4 *)(iVar7 + 0x88) = uVar6;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f5);
      *(undefined2 *)(iVar7 + 0x9c) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f5);
      *(undefined2 *)(iVar7 + 0x9e) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f5);
      *(undefined2 *)(iVar7 + 0xa0) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f5);
      *(undefined2 *)(iVar7 + 0xa2) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f9);
      *(undefined2 *)(iVar7 + 0xa4) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x45f9);
      *(undefined2 *)(iVar7 + 0xa6) = uVar1;
      MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xb8);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xcc);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xe0);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xf4);
      *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x130) = 0x4af;
      *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x13c) = 0x4af;
      *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x148) = 0x4af;
      *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x154) = 0x4af;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x321e);
      *(undefined2 *)(iVar7 + 0x13a) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x321e);
      *(undefined2 *)(iVar7 + 0x146) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x321e);
      *(undefined2 *)(iVar7 + 0x152) = uVar1;
      iVar7 = *(int *)(param_1 + 0x188);
      uVar1 = GetRcEngine::RcGetNum(0x321e);
      *(undefined2 *)(iVar7 + 0x15e) = uVar1;
      *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x128) = 0x42;
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x188),2,0);
      MWidget::SetFlag(*(undefined4 *)(param_1 + 0x188),0x10,0);
      (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
                (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x188));
      MMainFrame::SetInitialFocus(param_1);
      return 0;
    }
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ff1e48,&UNK_00ff1ec8,0x1d9);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  printf("UI CREATE FAIL: %s %s %d\n",&UNK_00ff1e48,&UNK_00ff1ec8,0x1c6);
                    /* WARNING: Subroutine does not return */
  abort();
}

