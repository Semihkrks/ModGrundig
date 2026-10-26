
undefined4 FUN_00fc03e8(ZappMenuFrame *param_1)

{
  ZappMenuFrame ZVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined4 uVar7;
  ulong uVar8;
  ArTvManager *pAVar9;
  int iVar10;
  undefined1 auStack_b0 [100];
  _Rect a_Stack_4c [20];
  Image *pIStack_38;
  Image *pIStack_34;
  TextBox *pTStack_30;
  AbsContainer *pAStack_2c;
  Image *pIStack_28;
  AbsContainer *pAStack_24;
  
  lVar3 = GetRcEngine::RcGetNum(0x5ad0);
  lVar4 = GetRcEngine::RcGetNum(0x5ad1);
  lVar5 = GetRcEngine::RcGetNum(0x5acf);
  lVar6 = GetRcEngine::RcGetNum(0x5ace);
  _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
  pAStack_24 = operator_new(0x264);
                    /* try { // try from 00fc04e4 to 00fc04eb has its CatchHandler @ 00fc0514 */
  AbsContainer::AbsContainer(pAStack_24,*(MWidget **)(param_1 + 0x38),a_Stack_4c,0,0);
  *(AbsContainer **)(param_1 + 0x180) = pAStack_24;
  if (*(int *)(param_1 + 0x180) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,0x137);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x3a) = 1;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x4c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x50) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x54) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x58) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  lVar3 = GetRcEngine::RcGetNum(0x5adc);
  lVar4 = GetRcEngine::RcGetNum(0x5add);
  lVar5 = GetRcEngine::RcGetNum(0x5adb);
  lVar6 = GetRcEngine::RcGetNum(0x5ada);
  _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
  pIStack_28 = operator_new(0x2b4);
                    /* try { // try from 00fc0884 to 00fc088b has its CatchHandler @ 00fc08b4 */
  Image::Image(pIStack_28,*(MWidget **)(param_1 + 0x180),a_Stack_4c,0,1);
  *(Image **)(param_1 + 0x184) = pIStack_28;
  if (*(int *)(param_1 + 0x184) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,0x14b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184));
  lVar3 = GetRcEngine::RcGetNum(0x5acc);
  lVar4 = GetRcEngine::RcGetNum(0x5acd);
  lVar5 = GetRcEngine::RcGetNum(0x5acb);
  lVar6 = GetRcEngine::RcGetNum(0x5aca);
  _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
  pAStack_2c = operator_new(0x264);
                    /* try { // try from 00fc0c3c to 00fc0c43 has its CatchHandler @ 00fc0c6c */
  AbsContainer::AbsContainer(pAStack_2c,*(MWidget **)(param_1 + 0x180),a_Stack_4c,0,2);
  *(AbsContainer **)(param_1 + 0x188) = pAStack_2c;
  if (*(int *)(param_1 + 0x188) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,0x160);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x188));
  lVar3 = GetRcEngine::RcGetNum(0x5ae0);
  lVar4 = GetRcEngine::RcGetNum(0x5ae1);
  lVar5 = GetRcEngine::RcGetNum(0x5adf);
  lVar6 = GetRcEngine::RcGetNum(0x5ade);
  _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
  pTStack_30 = operator_new(0x250);
                    /* try { // try from 00fc0f5c to 00fc0f63 has its CatchHandler @ 00fc0f8c */
  TextBox::TextBox(pTStack_30,*(MWidget **)(param_1 + 0x188),a_Stack_4c,0,3);
  *(TextBox **)(param_1 + 0x18c) = pTStack_30;
  if (*(int *)(param_1 + 0x18c) != 0) {
    MString::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0x170);
    *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x17c) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x17d) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x39) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x38) = 0;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar7 = GetRcEngine::RcGetColor(0x5e);
    *(undefined4 *)(iVar10 + 0x7c) = uVar7;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar7 = GetRcEngine::RcGetColor(0x5e);
    *(undefined4 *)(iVar10 + 0x80) = uVar7;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar7 = GetRcEngine::RcGetColor(0x5e);
    *(undefined4 *)(iVar10 + 0x84) = uVar7;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar7 = GetRcEngine::RcGetColor(0x5e);
    *(undefined4 *)(iVar10 + 0x88) = uVar7;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0x9c) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0x9e) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa0) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa2) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa4) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa6) = uVar2;
    MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xb8);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xcc);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xe0);
    MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xf4);
    *(undefined4 *)(*(int *)(param_1 + 0x18c) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(param_1 + 0x18c) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(param_1 + 0x18c) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(param_1 + 0x18c) + 0x154) = 0x4ae;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x321a);
    *(undefined2 *)(iVar10 + 0x13a) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x3217);
    *(undefined2 *)(iVar10 + 0x146) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x3217);
    *(undefined2 *)(iVar10 + 0x152) = uVar2;
    iVar10 = *(int *)(param_1 + 0x18c);
    uVar2 = GetRcEngine::RcGetNum(0x3217);
    *(undefined2 *)(iVar10 + 0x15e) = uVar2;
    (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
              (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x18c));
    lVar3 = GetRcEngine::RcGetNum(0x5ad4);
    lVar4 = GetRcEngine::RcGetNum(0x5ad5);
    lVar5 = GetRcEngine::RcGetNum(0x5ad3);
    lVar6 = GetRcEngine::RcGetNum(0x5ad2);
    _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
    pIStack_34 = operator_new(0x2b4);
                    /* try { // try from 00fc1418 to 00fc141f has its CatchHandler @ 00fc1448 */
    Image::Image(pIStack_34,*(MWidget **)(param_1 + 0x188),a_Stack_4c,0,4);
    *(Image **)(param_1 + 400) = pIStack_34;
    if (*(int *)(param_1 + 400) == 0) {
      printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,400);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0x260);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0x274);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0x288);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0x29c);
    *(undefined1 *)(*(int *)(param_1 + 400) + 0x39) = 0;
    *(undefined1 *)(*(int *)(param_1 + 400) + 0x38) = 0;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0x9c) = uVar2;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0x9e) = uVar2;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa0) = uVar2;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa2) = uVar2;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa4) = uVar2;
    iVar10 = *(int *)(param_1 + 400);
    uVar2 = GetRcEngine::RcGetNum(0x45dd);
    *(undefined2 *)(iVar10 + 0xa6) = uVar2;
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xb8);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xcc);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xe0);
    MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xf4);
    (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
              (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 400));
    lVar3 = GetRcEngine::RcGetNum(0x5ad8);
    lVar4 = GetRcEngine::RcGetNum(0x5ad9);
    lVar5 = GetRcEngine::RcGetNum(0x5ad7);
    lVar6 = GetRcEngine::RcGetNum(0x5ad6);
    _Rect::set(a_Stack_4c,lVar3,lVar4,lVar5,lVar6);
    pIStack_38 = operator_new(0x2b4);
                    /* try { // try from 00fc17d0 to 00fc17d7 has its CatchHandler @ 00fc1800 */
    Image::Image(pIStack_38,*(MWidget **)(param_1 + 0x188),a_Stack_4c,0,5);
    *(Image **)(param_1 + 0x194) = pIStack_38;
    if (*(int *)(param_1 + 0x194) != 0) {
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x260);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x274);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x288);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x29c);
      *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x39) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x38) = 0;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0x9c) = uVar2;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0x9e) = uVar2;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0xa0) = uVar2;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0xa2) = uVar2;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0xa4) = uVar2;
      iVar10 = *(int *)(param_1 + 0x194);
      uVar2 = GetRcEngine::RcGetNum(0x45dd);
      *(undefined2 *)(iVar10 + 0xa6) = uVar2;
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xb8);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xcc);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xe0);
      MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xf4);
      (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
                (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x194));
      uVar7 = *(undefined4 *)(param_1 + 0x180);
      uVar8 = GetRcEngine::RcGetColor(0x13);
      MWidget::ShowBorder((uchar)uVar7,1,uVar8,'\x01','\0',2);
      param_1[0x20c] = (ZappMenuFrame)0x1;
      pAVar9 = (ArTvManager *)ArTvManager::getInstance();
      ZVar1 = (ZappMenuFrame)ArTvManager::GetCurrentInputSourceType(pAVar9);
      param_1[0x200] = ZVar1;
      ArTvManager::getInstance();
      ZVar1 = (ZappMenuFrame)ArTvManager::GetDtvRoute();
      param_1[0x201] = ZVar1;
      if ((param_1[0x200] == (ZappMenuFrame)0x0) || (param_1[0x200] == (ZappMenuFrame)0x1)) {
        ArChannelManager::getInstance();
        ArChannelManager::GetCurrentChannelInfo((ChannelInfo *)(param_1 + 0x19c),'\0');
      }
      if (param_1[0x200] == (ZappMenuFrame)0x5) {
        pAVar9 = (ArTvManager *)ArTvManager::getInstance();
        uVar7 = ArTvManager::GetSpecificSourceIndex(pAVar9);
        *(undefined4 *)(param_1 + 0x204) = uVar7;
      }
      else {
        *(undefined4 *)(param_1 + 0x204) = 0;
      }
      FUN_00fbed54(auStack_b0,param_1 + 0x19c);
                    /* try { // try from 00fc1c80 to 00fc1c87 has its CatchHandler @ 00fc1cd0 */
      ZappMenuFrame::SetZappChannel
                (param_1,auStack_b0,param_1[0x200],*(undefined4 *)(param_1 + 0x204));
      FUN_00fbe710(auStack_b0);
      return 0;
    }
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,0x1a5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  printf("UI CREATE FAIL: %s %s %d\n",&UNK_0100cd08,&UNK_0100cd60,0x170);
                    /* WARNING: Subroutine does not return */
  abort();
}

