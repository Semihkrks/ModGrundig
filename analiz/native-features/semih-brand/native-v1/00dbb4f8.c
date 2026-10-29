
undefined4 FUN_00dbb4f8(MMainFrame *param_1)

{
  uchar uVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined4 uVar7;
  ArVideoManager *pAVar8;
  int *piVar9;
  int iVar10;
  string asStack_34c [4];
  allocator aaStack_348 [4];
  string asStack_344 [4];
  _Rect a_Stack_340 [16];
  undefined4 uStack_330;
  undefined1 auStack_32c [4];
  int iStack_328;
  undefined4 auStack_2fc [157];
  int iStack_88;
  undefined4 uStack_84;
  TimeWidget *pTStack_80;
  HelpWidget *pHStack_7c;
  int iStack_78;
  string *psStack_74;
  string *psStack_70;
  MenuGrid *pMStack_6c;
  Image *pIStack_68;
  TextBox *pTStack_64;
  Image *pIStack_60;
  Image *pIStack_5c;
  AbsContainer *pAStack_58;
  Button *pBStack_54;
  Image *pIStack_50;
  Image *pIStack_4c;
  Image *pIStack_48;
  Image *pIStack_44;
  TextBox *pTStack_40;
  TextBox *pTStack_3c;
  TextBox *pTStack_38;
  AbsContainer *pAStack_34;
  AbsContainer *pAStack_30;
  AbsContainer *pAStack_2c;
  AbsContainer *pAStack_28;
  AbsContainer *pAStack_24;
  
  lVar3 = GetRcEngine::RcGetNum(0x3fed);
  lVar4 = GetRcEngine::RcGetNum(0x3fee);
  lVar5 = GetRcEngine::RcGetNum(0x3fec);
  lVar6 = GetRcEngine::RcGetNum(0x3feb);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_24 = operator_new(0x264);
                    /* try { // try from 00dbb5f4 to 00dbb5fb has its CatchHandler @ 00dbb624 */
  AbsContainer::AbsContainer(pAStack_24,*(MWidget **)(param_1 + 0x38),a_Stack_340,0,0);
  *(AbsContainer **)(param_1 + 0x180) = pAStack_24;
  if (*(int *)(param_1 + 0x180) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0xe7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(6);
  *(undefined4 *)(iVar10 + 0x4c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(6);
  *(undefined4 *)(iVar10 + 0x50) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(6);
  *(undefined4 *)(iVar10 + 0x54) = uVar7;
  iVar10 = *(int *)(param_1 + 0x180);
  uVar7 = GetRcEngine::RcGetColor(6);
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
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x180),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x180),2,0);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  lVar3 = GetRcEngine::RcGetNum(0x3ff5);
  lVar4 = GetRcEngine::RcGetNum(0x3ff6);
  lVar5 = GetRcEngine::RcGetNum(0x3ff4);
  lVar6 = GetRcEngine::RcGetNum(0x3ff3);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_28 = operator_new(0x264);
                    /* try { // try from 00dbb9e4 to 00dbb9eb has its CatchHandler @ 00dbba14 */
  AbsContainer::AbsContainer(pAStack_28,*(MWidget **)(param_1 + 0x38),a_Stack_340,0,1);
  *(AbsContainer **)(param_1 + 0x184) = pAStack_28;
  if (*(int *)(param_1 + 0x184) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0xfe);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar10 = *(int *)(param_1 + 0x184);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x4c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x50) = uVar7;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x54) = uVar7;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar7 = GetRcEngine::RcGetColor(0x12);
  *(undefined4 *)(iVar10 + 0x58) = uVar7;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x184);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x184));
  lVar3 = GetRcEngine::RcGetNum(0x3fe9);
  lVar4 = GetRcEngine::RcGetNum(0x3fea);
  lVar5 = GetRcEngine::RcGetNum(0x3fe8);
  lVar6 = GetRcEngine::RcGetNum(0x3fe7);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_2c = operator_new(0x264);
                    /* try { // try from 00dbbd74 to 00dbbd7b has its CatchHandler @ 00dbbda4 */
  AbsContainer::AbsContainer(pAStack_2c,*(MWidget **)(param_1 + 0x38),a_Stack_340,0,2);
  *(AbsContainer **)(param_1 + 0x188) = pAStack_2c;
  if (*(int *)(param_1 + 0x188) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x111);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar7 = GetRcEngine::RcGetColor(0);
  *(undefined4 *)(iVar10 + 0x4c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar7 = GetRcEngine::RcGetColor(0);
  *(undefined4 *)(iVar10 + 0x50) = uVar7;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar7 = GetRcEngine::RcGetColor(0);
  *(undefined4 *)(iVar10 + 0x54) = uVar7;
  iVar10 = *(int *)(param_1 + 0x188);
  uVar7 = GetRcEngine::RcGetColor(0);
  *(undefined4 *)(iVar10 + 0x58) = uVar7;
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
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x188));
  lVar3 = GetRcEngine::RcGetNum(0x3ff9);
  lVar4 = GetRcEngine::RcGetNum(0x3ffa);
  lVar5 = GetRcEngine::RcGetNum(0x3ff8);
  lVar6 = GetRcEngine::RcGetNum(0x3ff7);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_30 = operator_new(0x264);
                    /* try { // try from 00dbc114 to 00dbc11b has its CatchHandler @ 00dbc144 */
  AbsContainer::AbsContainer(pAStack_30,*(MWidget **)(param_1 + 0x38),a_Stack_340,0,3);
  *(AbsContainer **)(param_1 + 0x18c) = pAStack_30;
  if (*(int *)(param_1 + 0x18c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x125);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x18c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x18c));
  lVar3 = GetRcEngine::RcGetNum(0x3ff1);
  lVar4 = GetRcEngine::RcGetNum(0x3ff2);
  lVar5 = GetRcEngine::RcGetNum(0x3ff0);
  lVar6 = GetRcEngine::RcGetNum(0x3fef);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_34 = operator_new(0x264);
                    /* try { // try from 00dbc430 to 00dbc437 has its CatchHandler @ 00dbc460 */
  AbsContainer::AbsContainer(pAStack_34,*(MWidget **)(param_1 + 0x180),a_Stack_340,0,4);
  *(AbsContainer **)(param_1 + 400) = pAStack_34;
  if (*(int *)(param_1 + 400) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x135);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 400);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 400),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 400),2,0);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 400));
  lVar3 = GetRcEngine::RcGetNum(0x402d);
  lVar4 = GetRcEngine::RcGetNum(0x402e);
  lVar5 = GetRcEngine::RcGetNum(0x402c);
  lVar6 = GetRcEngine::RcGetNum(0x402b);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pTStack_38 = operator_new(0x250);
                    /* try { // try from 00dbc7a0 to 00dbc7a7 has its CatchHandler @ 00dbc7d0 */
  TextBox::TextBox(pTStack_38,*(MWidget **)(param_1 + 0x180),a_Stack_340,0,5);
  *(TextBox **)(param_1 + 0x194) = pTStack_38;
  if (*(int *)(param_1 + 0x194) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x148);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x7c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x80) = uVar7;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x84) = uVar7;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x194) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x194) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x194) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x194) + 0x154) = 0x4ae;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x13a) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x146) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x152) = uVar2;
  iVar10 = *(int *)(param_1 + 0x194);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x194) + 0x128) = 0x41;
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x194));
  lVar3 = GetRcEngine::RcGetNum(0x4031);
  lVar4 = GetRcEngine::RcGetNum(0x4032);
  lVar5 = GetRcEngine::RcGetNum(0x4030);
  lVar6 = GetRcEngine::RcGetNum(0x402f);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pTStack_3c = operator_new(0x250);
                    /* try { // try from 00dbcc2c to 00dbcc33 has its CatchHandler @ 00dbcc5c */
  TextBox::TextBox(pTStack_3c,*(MWidget **)(param_1 + 0x180),a_Stack_340,0,6);
  *(TextBox **)(param_1 + 0x198) = pTStack_3c;
  if (*(int *)(param_1 + 0x198) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x166);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x198) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x198) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x7c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x80) = uVar7;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x84) = uVar7;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x154) = 0x4ae;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x13a) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x146) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x152) = uVar2;
  iVar10 = *(int *)(param_1 + 0x198);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x198));
  lVar3 = GetRcEngine::RcGetNum(0x4025);
  lVar4 = GetRcEngine::RcGetNum(0x4026);
  lVar5 = GetRcEngine::RcGetNum(0x4024);
  lVar6 = GetRcEngine::RcGetNum(0x4023);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pTStack_40 = operator_new(0x250);
                    /* try { // try from 00dbd09c to 00dbd0a3 has its CatchHandler @ 00dbd0cc */
  TextBox::TextBox(pTStack_40,*(MWidget **)(param_1 + 0x180),a_Stack_340,0,7);
  *(TextBox **)(param_1 + 0x19c) = pTStack_40;
  if (*(int *)(param_1 + 0x19c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x182);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x7c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x80) = uVar7;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x84) = uVar7;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x154) = 0x4ae;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x13a) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x146) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x152) = uVar2;
  iVar10 = *(int *)(param_1 + 0x19c);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x19c));
  lVar3 = GetRcEngine::RcGetNum(0x4021);
  lVar4 = GetRcEngine::RcGetNum(0x4022);
  lVar5 = GetRcEngine::RcGetNum(0x4020);
  lVar6 = GetRcEngine::RcGetNum(0x401f);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_44 = operator_new(0x2b4);
                    /* try { // try from 00dbd528 to 00dbd52f has its CatchHandler @ 00dbd558 */
  Image::Image(pIStack_44,*(MWidget **)(param_1 + 0x180),a_Stack_340,0,8);
  *(Image **)(param_1 + 0x1a0) = pIStack_44;
  if (*(int *)(param_1 + 0x1a0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x1a0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0x29c);
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x1a0));
  lVar3 = GetRcEngine::RcGetNum(0x400d);
  lVar4 = GetRcEngine::RcGetNum(0x400e);
  lVar5 = GetRcEngine::RcGetNum(0x400c);
  lVar6 = GetRcEngine::RcGetNum(0x400b);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_48 = operator_new(0x2b4);
                    /* try { // try from 00dbd8c8 to 00dbd8cf has its CatchHandler @ 00dbd8f8 */
  Image::Image(pIStack_48,*(MWidget **)(param_1 + 400),a_Stack_340,0,9);
  *(Image **)(param_1 + 0x1a4) = pIStack_48;
  if (*(int *)(param_1 + 0x1a4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x1b3);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x1a4) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a4);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1a4));
  lVar3 = GetRcEngine::RcGetNum(0x4009);
  lVar4 = GetRcEngine::RcGetNum(0x400a);
  lVar5 = GetRcEngine::RcGetNum(0x4008);
  lVar6 = GetRcEngine::RcGetNum(0x4007);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_4c = operator_new(0x2b4);
                    /* try { // try from 00dbdc74 to 00dbdc7b has its CatchHandler @ 00dbdca4 */
  Image::Image(pIStack_4c,*(MWidget **)(param_1 + 400),a_Stack_340,0,10);
  *(Image **)(param_1 + 0x1a8) = pIStack_4c;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x1c7);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x38) = 0;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1a8);
  uVar2 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1a8));
  lVar3 = GetRcEngine::RcGetNum(0x4019);
  lVar4 = GetRcEngine::RcGetNum(0x401a);
  lVar5 = GetRcEngine::RcGetNum(0x4018);
  lVar6 = GetRcEngine::RcGetNum(0x4017);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_50 = operator_new(0x2b4);
                    /* try { // try from 00dbe02c to 00dbe033 has its CatchHandler @ 00dbe05c */
  Image::Image(pIStack_50,*(MWidget **)(param_1 + 400),a_Stack_340,0,0xb);
  *(Image **)(param_1 + 0x1ac) = pIStack_50;
  if (*(int *)(param_1 + 0x1ac) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x1dc);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x29c);
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1ac);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x1ac));
  lVar3 = GetRcEngine::RcGetNum(0x4001);
  lVar4 = GetRcEngine::RcGetNum(0x4002);
  lVar5 = GetRcEngine::RcGetNum(0x4000);
  lVar6 = GetRcEngine::RcGetNum(0x3fff);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pBStack_54 = operator_new(0x250);
                    /* try { // try from 00dbe3cc to 00dbe3d3 has its CatchHandler @ 00dbe3fc */
  Button::Button(pBStack_54,*(MWidget **)(param_1 + 0x184),a_Stack_340,0,0xc);
  *(Button **)(param_1 + 0x1b0) = pBStack_54;
  if (*(int *)(param_1 + 0x1b0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x1ef);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b0) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x154) = 0x4ae;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar10 + 0x13a) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar10 + 0x146) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar10 + 0x152) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b0);
  uVar2 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar10 + 0x15e) = uVar2;
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1b0),2,0);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1b0));
  lVar3 = GetRcEngine::RcGetNum(0x3ffd);
  lVar4 = GetRcEngine::RcGetNum(0x3ffe);
  lVar5 = GetRcEngine::RcGetNum(0x3ffc);
  lVar6 = GetRcEngine::RcGetNum(0x3ffb);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pAStack_58 = operator_new(0x264);
                    /* try { // try from 00dbe800 to 00dbe807 has its CatchHandler @ 00dbe830 */
  AbsContainer::AbsContainer(pAStack_58,*(MWidget **)(param_1 + 0x18c),a_Stack_340,0,0xd);
  *(AbsContainer **)(param_1 + 0x1b4) = pAStack_58;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x209);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1b4));
  lVar3 = GetRcEngine::RcGetNum(0x4015);
  lVar4 = GetRcEngine::RcGetNum(0x4016);
  lVar5 = GetRcEngine::RcGetNum(0x4014);
  lVar6 = GetRcEngine::RcGetNum(0x4013);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_5c = operator_new(0x2b4);
                    /* try { // try from 00dbeb1c to 00dbeb23 has its CatchHandler @ 00dbeb4c */
  Image::Image(pIStack_5c,*(MWidget **)(param_1 + 0x18c),a_Stack_340,0,0xe);
  *(Image **)(param_1 + 0x1b8) = pIStack_5c;
  if (*(int *)(param_1 + 0x1b8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x219);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x29c);
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1b8);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1b8));
  lVar3 = GetRcEngine::RcGetNum(0x401d);
  lVar4 = GetRcEngine::RcGetNum(0x401e);
  lVar5 = GetRcEngine::RcGetNum(0x401c);
  lVar6 = GetRcEngine::RcGetNum(0x401b);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_60 = operator_new(0x2b4);
                    /* try { // try from 00dbeebc to 00dbeec3 has its CatchHandler @ 00dbeeec */
  Image::Image(pIStack_60,*(MWidget **)(param_1 + 0x18c),a_Stack_340,0,0xf);
  *(Image **)(param_1 + 0x1bc) = pIStack_60;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x22c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x29c);
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1bc);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1bc));
  lVar3 = GetRcEngine::RcGetNum(0x4029);
  lVar4 = GetRcEngine::RcGetNum(0x402a);
  lVar5 = GetRcEngine::RcGetNum(0x4028);
  lVar6 = GetRcEngine::RcGetNum(0x4027);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pTStack_64 = operator_new(0x250);
                    /* try { // try from 00dbf25c to 00dbf263 has its CatchHandler @ 00dbf28c */
  TextBox::TextBox(pTStack_64,*(MWidget **)(param_1 + 0x18c),a_Stack_340,0,0x10);
  *(TextBox **)(param_1 + 0x1c0) = pTStack_64;
  if (*(int *)(param_1 + 0x1c0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x23f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x39) = 0;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x7c) = uVar7;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x80) = uVar7;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar7 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar10 + 0x84) = uVar7;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x130) = 0x4b1;
  *(undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x13c) = 0x4b1;
  *(undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x148) = 0x4b1;
  *(undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x154) = 0x4b1;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x13a) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x146) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x152) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c0);
  uVar2 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar10 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1c0));
  lVar3 = GetRcEngine::RcGetNum(0x4011);
  lVar4 = GetRcEngine::RcGetNum(0x4012);
  lVar5 = GetRcEngine::RcGetNum(0x4010);
  lVar6 = GetRcEngine::RcGetNum(0x400f);
  _Rect::set(a_Stack_340,lVar3,lVar4,lVar5,lVar6);
  pIStack_68 = operator_new(0x2b4);
                    /* try { // try from 00dbf6cc to 00dbf6d3 has its CatchHandler @ 00dbf6fc */
  Image::Image(pIStack_68,*(MWidget **)(param_1 + 0x18c),a_Stack_340,0,0x11);
  *(Image **)(param_1 + 0x1c4) = pIStack_68;
  if (*(int *)(param_1 + 0x1c4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_01003d64,&UNK_010040b8,0x25b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x29c);
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9c) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0x9e) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa0) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar10 + 0xa2) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa4) = uVar2;
  iVar10 = *(int *)(param_1 + 0x1c4);
  uVar2 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar10 + 0xa6) = uVar2;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x1c4));
  _Rect::set(a_Stack_340,0xb5,0x94,0x616,0x146);
  pMStack_6c = operator_new(0x274);
                    /* try { // try from 00dbfa14 to 00dbfa1b has its CatchHandler @ 00dbfb60 */
  MenuGrid::MenuGrid(pMStack_6c,*(MWidget **)(param_1 + 0x38),a_Stack_340,0,0x238c);
  *(MenuGrid **)(param_1 + 0x1c8) = pMStack_6c;
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1c8));
  MenuGrid::SetFocus(*(MenuGrid **)(param_1 + 0x1c8),0x238e);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c8),2,1);
  MWidget::Show();
  MString::Set((short)*(undefined4 *)(param_1 + 0x194) + 0x170);
  psStack_70 = (string *)(*(int *)(param_1 + 0x19c) + 0x170);
  std::allocator<char>::allocator();
                    /* try { // try from 00dbfb30 to 00dbfb37 has its CatchHandler @ 00dbfd34 */
  std::string::string(asStack_344,"12 April 2013 - Friday",aaStack_348);
                    /* try { // try from 00dbfb4c to 00dbfb53 has its CatchHandler @ 00dbfca8 */
  MString::Set(psStack_70);
  psStack_74 = asStack_344;
                    /* try { // try from 00dbfbb0 to 00dbfbb7 has its CatchHandler @ 00dbfd34 */
  std::string::~string(psStack_74);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_348);
  MWidget::Hide();
  MWidget::Hide();
  MWnd::GetParentApp();
  uVar1 = MApplet::GetPrivateData();
  MenuBackgroundFrame::b_isMenuBGActive = 1;
  iVar10 = *(int *)(param_1 + 0x19c);
  ArTvSettingsManager::getInstance();
  ArTvSettingsManager::GetCurrentDateAndTimeString();
                    /* try { // try from 00dbfc94 to 00dbfc9b has its CatchHandler @ 00dbfd78 */
  MString::Set((string *)(iVar10 + 0x170));
  std::string::~string(asStack_34c);
  ArVideoManager::getInstance();
  iVar10 = ArVideoManager::GetMEMC();
  if (iVar10 != 0) {
    ArServiceSettingsManager::getInstance();
    iVar10 = ArServiceSettingsManager::ArPanelConf_GetUrsaSelection();
    if (iVar10 != 0) {
      iStack_78 = 1;
      goto LAB_00dbfdfc;
    }
  }
  iStack_78 = 0;
LAB_00dbfdfc:
  if (iStack_78 != 0) {
    pAVar8 = (ArVideoManager *)ArVideoManager::getInstance();
    ArVideoManager::SetMEMC(pAVar8,'\0');
  }
  pHStack_7c = operator_new(0x144);
                    /* try { // try from 00dbfe5c to 00dbfe63 has its CatchHandler @ 00dbff64 */
  HelpWidget::HelpWidget(pHStack_7c,param_1,(Container *)0x0);
  *(HelpWidget **)(param_1 + 0x1cc) = pHStack_7c;
  pTStack_80 = operator_new(0x34);
                    /* try { // try from 00dbfea8 to 00dbfeaf has its CatchHandler @ 00dbffa4 */
  TimeWidget::TimeWidget(pTStack_80,param_1,*(Container **)(param_1 + 0x1b4));
  *(TimeWidget **)(param_1 + 0x1d0) = pTStack_80;
  MenuBackgroundFrame::openMenu((ulong)param_1,uVar1,(void *)0x0);
  HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x1cc));
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1b0),2,0);
  CommonFrame::EnableShadows((uchar)param_1);
  iStack_88 = MSrv_Control_common::GetMSrvPicture();
  if (iStack_88 == 0) {
    uStack_84 = 0;
  }
  else {
    uStack_84 = __dynamic_cast(iStack_88,&DAT_2da875b8,&DAT_2e027d30,0);
  }
  MSrv_Picture_Customer::IncreaseMenuLockCounter();
  piVar9 = (int *)MSrv_Control::GetInstance();
  uStack_330 = (**(code **)(*piVar9 + 0x84))(piVar9);
  piVar9 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
  (**(code **)(*piVar9 + 0x94))(piVar9,auStack_32c,&uStack_330);
  pAVar8 = (ArVideoManager *)ArVideoManager::getInstance();
  ArVideoManager::SetBacklight(pAVar8,(uchar)auStack_2fc[iStack_328 * 0x11]);
  return 0;
}

