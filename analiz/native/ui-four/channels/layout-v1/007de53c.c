
undefined4 FUN_007de53c(ArProgramInfoFrame *param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  ArTvManager *this;
  int *piVar11;
  MEvtHandle *pMVar12;
  int iVar13;
  ulong uVar14;
  byte bStack_608;
  string asStack_600 [4];
  string asStack_5fc [4];
  string asStack_5f8 [4];
  string asStack_5f4 [4];
  allocator aaStack_5f0 [4];
  MImg aMStack_5ec [20];
  MImg aMStack_5d8 [20];
  MImg aMStack_5c4 [20];
  MImg aMStack_5b0 [20];
  MImg aMStack_59c [20];
  MImg aMStack_588 [20];
  MImg aMStack_574 [20];
  MImg aMStack_560 [20];
  MImg aMStack_54c [20];
  MImg aMStack_538 [20];
  MImg aMStack_524 [20];
  MImg aMStack_510 [20];
  MImg aMStack_4fc [20];
  MImg aMStack_4e8 [20];
  MImg aMStack_4d4 [20];
  MImg aMStack_4c0 [20];
  MImg aMStack_4ac [20];
  MImg aMStack_498 [20];
  MImg aMStack_484 [20];
  MImg aMStack_470 [20];
  MImg aMStack_45c [20];
  MImg aMStack_448 [20];
  MImg aMStack_434 [20];
  MImg aMStack_420 [20];
  MImg aMStack_40c [20];
  MImg aMStack_3f8 [20];
  MImg aMStack_3e4 [20];
  MImg aMStack_3d0 [20];
  MImg aMStack_3bc [20];
  MImg aMStack_3a8 [20];
  MImg aMStack_394 [20];
  MImg aMStack_380 [20];
  MImg aMStack_36c [20];
  MImg aMStack_358 [20];
  MImg aMStack_344 [20];
  MImg aMStack_330 [20];
  MImg aMStack_31c [20];
  MImg aMStack_308 [20];
  MImg aMStack_2f4 [20];
  MImg aMStack_2e0 [20];
  MImg aMStack_2cc [20];
  MImg aMStack_2b8 [20];
  MImg aMStack_2a4 [20];
  MImg aMStack_290 [20];
  MImg aMStack_27c [20];
  MImg aMStack_268 [20];
  MImg aMStack_254 [20];
  MImg aMStack_240 [20];
  MImg aMStack_22c [20];
  MImg aMStack_218 [20];
  MImg aMStack_204 [20];
  MImg aMStack_1f0 [20];
  _Rect a_Stack_1dc [16];
  MString aMStack_1cc [12];
  string asStack_1c0 [8];
  undefined4 uStack_1b8;
  string *psStack_1b4;
  string *psStack_1b0;
  string *psStack_1ac;
  string *psStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  TimeWidget *pTStack_19c;
  HelpWidget *pHStack_198;
  ScrollTextBox *pSStack_194;
  MImg *pMStack_190;
  ImageButton *pIStack_18c;
  MImg *pMStack_188;
  ImageButton *pIStack_184;
  MImg *pMStack_180;
  ImageButton *pIStack_17c;
  MImg *pMStack_178;
  ImageButton *pIStack_174;
  ListContainer *pLStack_170;
  TextBox *pTStack_16c;
  TextBox *pTStack_168;
  AbsContainer *pAStack_164;
  TextBox *pTStack_160;
  AbsContainer *pAStack_15c;
  AbsContainer *pAStack_158;
  AbsContainer *pAStack_154;
  AbsContainer *pAStack_150;
  TextBox *pTStack_14c;
  TextBox *pTStack_148;
  AbsContainer *pAStack_144;
  AbsContainer *pAStack_140;
  AbsContainer *pAStack_13c;
  AbsContainer *pAStack_138;
  TextBox *pTStack_134;
  Image *pIStack_130;
  Image *pIStack_12c;
  TextBox *pTStack_128;
  TextBox *pTStack_124;
  Image *pIStack_120;
  undefined4 uStack_11c;
  ProgressBar *pPStack_118;
  Image *pIStack_114;
  MImg *pMStack_110;
  MImg *pMStack_10c;
  MImg *pMStack_108;
  MImg *pMStack_104;
  ScrollBar *pSStack_100;
  AbsContainer *pAStack_fc;
  TextBox *pTStack_f8;
  TextBox *pTStack_f4;
  TextBox *pTStack_f0;
  AbsContainer *pAStack_ec;
  AbsContainer *pAStack_e8;
  Image *pIStack_e4;
  Image *pIStack_e0;
  AbsContainer *pAStack_dc;
  TextBox *pTStack_d8;
  TextBox *pTStack_d4;
  AbsContainer *pAStack_d0;
  TextBox *pTStack_cc;
  TextBox *pTStack_c8;
  AbsContainer *pAStack_c4;
  AbsContainer *pAStack_c0;
  AbsContainer *pAStack_bc;
  TextBox *pTStack_b8;
  TextBox *pTStack_b4;
  TextBox *pTStack_b0;
  TextBox *pTStack_ac;
  TextBox *pTStack_a8;
  TextBox *pTStack_a4;
  TextBox *pTStack_a0;
  TextBox *pTStack_9c;
  TextBox *pTStack_98;
  Image *pIStack_94;
  Image *pIStack_90;
  AbsContainer *pAStack_8c;
  MImg *pMStack_88;
  MImg *pMStack_84;
  MImg *pMStack_80;
  MImg *pMStack_7c;
  ScrollListContainer *pSStack_78;
  AbsContainer *pAStack_74;
  TextBox *pTStack_70;
  TextBox *pTStack_6c;
  Image *pIStack_68;
  AbsContainer *pAStack_64;
  TextBox *pTStack_60;
  TextBox *pTStack_5c;
  TextBox *pTStack_58;
  AbsContainer *pAStack_54;
  TextBox *pTStack_50;
  Image *pIStack_4c;
  AbsContainer *pAStack_48;
  AbsContainer *pAStack_44;
  AbsContainer *pAStack_40;
  AbsContainer *pAStack_3c;
  AbsContainer *pAStack_38;
  AbsContainer *pAStack_34;
  AbsContainer *pAStack_30;
  AbsContainer *pAStack_2c;
  AbsContainer *pAStack_28;
  AbsContainer *pAStack_24;
  
  lVar2 = GetRcEngine::RcGetNum(0x31a);
  lVar3 = GetRcEngine::RcGetNum(0x31b);
  lVar4 = GetRcEngine::RcGetNum(0x319);
  lVar5 = GetRcEngine::RcGetNum(0x318);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_24 = operator_new(0x264);
                    /* try { // try from 007de63c to 007de643 has its CatchHandler @ 007de66c */
  AbsContainer::AbsContainer(pAStack_24,*(MWidget **)(param_1 + 0x38),a_Stack_1dc,0,0);
  *(AbsContainer **)(param_1 + 0x180) = pAStack_24;
  if (*(int *)(param_1 + 0x180) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0xc0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x180);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x180) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  lVar2 = GetRcEngine::RcGetNum(0x2f6);
  lVar3 = GetRcEngine::RcGetNum(0x2f7);
  lVar4 = GetRcEngine::RcGetNum(0x2f5);
  lVar5 = GetRcEngine::RcGetNum(0x2f4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_28 = operator_new(0x264);
                    /* try { // try from 007de958 to 007de95f has its CatchHandler @ 007de988 */
  AbsContainer::AbsContainer(pAStack_28,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,1);
  *(AbsContainer **)(param_1 + 0x184) = pAStack_28;
  if (*(int *)(param_1 + 0x184) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0xd0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar6 = GetRcEngine::RcGetColor(0x51);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar6 = GetRcEngine::RcGetColor(0x51);
  *(undefined4 *)(iVar13 + 0x50) = uVar6;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar6 = GetRcEngine::RcGetColor(0x51);
  *(undefined4 *)(iVar13 + 0x54) = uVar6;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar6 = GetRcEngine::RcGetColor(0x51);
  *(undefined4 *)(iVar13 + 0x58) = uVar6;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x184);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x184) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x184),2,0);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184));
  lVar2 = GetRcEngine::RcGetNum(0x352);
  lVar3 = GetRcEngine::RcGetNum(0x353);
  lVar4 = GetRcEngine::RcGetNum(0x351);
  lVar5 = GetRcEngine::RcGetNum(0x350);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_2c = operator_new(0x264);
                    /* try { // try from 007ded18 to 007ded1f has its CatchHandler @ 007ded48 */
  AbsContainer::AbsContainer(pAStack_2c,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,2);
  *(AbsContainer **)(param_1 + 0x188) = pAStack_2c;
  if (*(int *)(param_1 + 0x188) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0xe5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x188);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x188) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x188));
  lVar2 = GetRcEngine::RcGetNum(0x31e);
  lVar3 = GetRcEngine::RcGetNum(799);
  lVar4 = GetRcEngine::RcGetNum(0x31d);
  lVar5 = GetRcEngine::RcGetNum(0x31c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_30 = operator_new(0x264);
                    /* try { // try from 007df038 to 007df03f has its CatchHandler @ 007df068 */
  AbsContainer::AbsContainer(pAStack_30,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,3);
  *(AbsContainer **)(param_1 + 0x18c) = pAStack_30;
  if (*(int *)(param_1 + 0x18c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0xf5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x18c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x18c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x18c));
  lVar2 = GetRcEngine::RcGetNum(0x2e6);
  lVar3 = GetRcEngine::RcGetNum(0x2e7);
  lVar4 = GetRcEngine::RcGetNum(0x2e5);
  lVar5 = GetRcEngine::RcGetNum(0x2e4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_34 = operator_new(0x264);
                    /* try { // try from 007df354 to 007df35b has its CatchHandler @ 007df384 */
  AbsContainer::AbsContainer(pAStack_34,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,4);
  *(AbsContainer **)(param_1 + 400) = pAStack_34;
  if (*(int *)(param_1 + 400) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x105);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 400);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 400) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 400),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 400),2,0);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 400));
  lVar2 = GetRcEngine::RcGetNum(0x346);
  lVar3 = GetRcEngine::RcGetNum(0x347);
  lVar4 = GetRcEngine::RcGetNum(0x345);
  lVar5 = GetRcEngine::RcGetNum(0x33c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_38 = operator_new(0x264);
                    /* try { // try from 007df6b8 to 007df6bf has its CatchHandler @ 007df6e8 */
  AbsContainer::AbsContainer(pAStack_38,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,5);
  *(AbsContainer **)(param_1 + 0x194) = pAStack_38;
  if (*(int *)(param_1 + 0x194) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x117);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x194);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x194) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x194));
  lVar2 = GetRcEngine::RcGetNum(0x2de);
  lVar3 = GetRcEngine::RcGetNum(0x2df);
  lVar4 = GetRcEngine::RcGetNum(0x2dd);
  lVar5 = GetRcEngine::RcGetNum(0x2d8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_3c = operator_new(0x264);
                    /* try { // try from 007df9d8 to 007df9df has its CatchHandler @ 007dfa08 */
  AbsContainer::AbsContainer(pAStack_3c,*(MWidget **)(param_1 + 0x180),a_Stack_1dc,0,6);
  *(AbsContainer **)(param_1 + 0x198) = pAStack_3c;
  if (*(int *)(param_1 + 0x198) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x127);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x198) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x198);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x198) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x198));
  lVar2 = GetRcEngine::RcGetNum(0x2fe);
  lVar3 = GetRcEngine::RcGetNum(0x2ff);
  lVar4 = GetRcEngine::RcGetNum(0x2fd);
  lVar5 = GetRcEngine::RcGetNum(0x2fc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_40 = operator_new(0x264);
                    /* try { // try from 007dfcf8 to 007dfcff has its CatchHandler @ 007dfd28 */
  AbsContainer::AbsContainer(pAStack_40,*(MWidget **)(param_1 + 0x184),a_Stack_1dc,0,7);
  *(AbsContainer **)(param_1 + 0x19c) = pAStack_40;
  if (*(int *)(param_1 + 0x19c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x137);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x19c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x19c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x19c));
  lVar2 = GetRcEngine::RcGetNum(0x306);
  lVar3 = GetRcEngine::RcGetNum(0x307);
  lVar4 = GetRcEngine::RcGetNum(0x305);
  lVar5 = GetRcEngine::RcGetNum(0x304);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_44 = operator_new(0x264);
                    /* try { // try from 007e0018 to 007e001f has its CatchHandler @ 007e0048 */
  AbsContainer::AbsContainer(pAStack_44,*(MWidget **)(param_1 + 0x184),a_Stack_1dc,0,8);
  *(AbsContainer **)(param_1 + 0x1a0) = pAStack_44;
  if (*(int *)(param_1 + 0x1a0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x147);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1a0) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1a0));
  lVar2 = GetRcEngine::RcGetNum(0x302);
  lVar3 = GetRcEngine::RcGetNum(0x303);
  lVar4 = GetRcEngine::RcGetNum(0x301);
  lVar5 = GetRcEngine::RcGetNum(0x300);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_48 = operator_new(0x264);
                    /* try { // try from 007e0338 to 007e033f has its CatchHandler @ 007e0368 */
  AbsContainer::AbsContainer(pAStack_48,*(MWidget **)(param_1 + 0x184),a_Stack_1dc,0,9);
  *(AbsContainer **)(param_1 + 0x1a4) = pAStack_48;
  if (*(int *)(param_1 + 0x1a4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x157);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar6 = GetRcEngine::RcGetColor(0x14);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar6 = GetRcEngine::RcGetColor(0x14);
  *(undefined4 *)(iVar13 + 0x50) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar6 = GetRcEngine::RcGetColor(0x14);
  *(undefined4 *)(iVar13 + 0x54) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar6 = GetRcEngine::RcGetColor(0x14);
  *(undefined4 *)(iVar13 + 0x58) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a4) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1a4));
  lVar2 = GetRcEngine::RcGetNum(0x376);
  lVar3 = GetRcEngine::RcGetNum(0x377);
  lVar4 = GetRcEngine::RcGetNum(0x375);
  lVar5 = GetRcEngine::RcGetNum(0x374);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_4c = operator_new(0x2b4);
                    /* try { // try from 007e06c8 to 007e06cf has its CatchHandler @ 007e06f8 */
  Image::Image(pIStack_4c,*(MWidget **)(param_1 + 0x19c),a_Stack_1dc,0,10);
  *(Image **)(param_1 + 0x1a8) = pIStack_4c;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x16a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1a8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x1a8));
  lVar2 = GetRcEngine::RcGetNum(0x35a);
  lVar3 = GetRcEngine::RcGetNum(0x35b);
  lVar4 = GetRcEngine::RcGetNum(0x359);
  lVar5 = GetRcEngine::RcGetNum(0x358);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_50 = operator_new(0x250);
                    /* try { // try from 007e0a78 to 007e0a7f has its CatchHandler @ 007e0aa8 */
  TextBox::TextBox(pTStack_50,*(MWidget **)(param_1 + 0x19c),a_Stack_1dc,0,0xb);
  *(TextBox **)(param_1 + 0x1ac) = pTStack_50;
  if (*(int *)(param_1 + 0x1ac) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x17e);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ac) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ac);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x1ac));
  lVar2 = GetRcEngine::RcGetNum(0x2fa);
  lVar3 = GetRcEngine::RcGetNum(0x2fb);
  lVar4 = GetRcEngine::RcGetNum(0x2f9);
  lVar5 = GetRcEngine::RcGetNum(0x2f8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_54 = operator_new(0x264);
                    /* try { // try from 007e0f18 to 007e0f1f has its CatchHandler @ 007e0f48 */
  AbsContainer::AbsContainer(pAStack_54,*(MWidget **)(param_1 + 0x19c),a_Stack_1dc,0,0xc);
  *(AbsContainer **)(param_1 + 0x1b0) = pAStack_54;
  if (*(int *)(param_1 + 0x1b0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x19c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1b0) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x1b0));
  lVar2 = GetRcEngine::RcGetNum(0x356);
  lVar3 = GetRcEngine::RcGetNum(0x357);
  lVar4 = GetRcEngine::RcGetNum(0x355);
  lVar5 = GetRcEngine::RcGetNum(0x354);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_58 = operator_new(0x250);
                    /* try { // try from 007e1238 to 007e123f has its CatchHandler @ 007e1268 */
  TextBox::TextBox(pTStack_58,*(MWidget **)(param_1 + 0x19c),a_Stack_1dc,0,0xd);
  *(TextBox **)(param_1 + 0x1b4) = pTStack_58;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x1ac);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b4);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x34))
            (*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x1b4));
  lVar2 = GetRcEngine::RcGetNum(0x3ba);
  lVar3 = GetRcEngine::RcGetNum(0x3bb);
  lVar4 = GetRcEngine::RcGetNum(0x3b9);
  lVar5 = GetRcEngine::RcGetNum(0x3b8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_5c = operator_new(0x250);
                    /* try { // try from 007e16c8 to 007e16cf has its CatchHandler @ 007e16f8 */
  TextBox::TextBox(pTStack_5c,*(MWidget **)(param_1 + 0x1a0),a_Stack_1dc,0,0xe);
  *(TextBox **)(param_1 + 0x1b8) = pTStack_5c;
  if (*(int *)(param_1 + 0x1b8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x1ca);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1b8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1b8);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1b8));
  lVar2 = GetRcEngine::RcGetNum(0x3be);
  lVar3 = GetRcEngine::RcGetNum(0x3bf);
  lVar4 = GetRcEngine::RcGetNum(0x3bd);
  lVar5 = GetRcEngine::RcGetNum(0x3bc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_60 = operator_new(0x250);
                    /* try { // try from 007e1b58 to 007e1b5f has its CatchHandler @ 007e1b88 */
  TextBox::TextBox(pTStack_60,*(MWidget **)(param_1 + 0x1a0),a_Stack_1dc,0,0xf);
  *(TextBox **)(param_1 + 0x1bc) = pTStack_60;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x1e8);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1bc) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1bc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1bc);
  uVar1 = GetRcEngine::RcGetNum(0x3218);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x1a0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1bc));
  lVar2 = GetRcEngine::RcGetNum(0x34e);
  lVar3 = GetRcEngine::RcGetNum(0x34f);
  lVar4 = GetRcEngine::RcGetNum(0x34d);
  lVar5 = GetRcEngine::RcGetNum(0x34c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_64 = operator_new(0x264);
                    /* try { // try from 007e1fc8 to 007e1fcf has its CatchHandler @ 007e1ff8 */
  AbsContainer::AbsContainer(pAStack_64,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x10);
  *(AbsContainer **)(param_1 + 0x1c0) = pAStack_64;
  if (*(int *)(param_1 + 0x1c0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x204);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c0) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c0),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1c0),2,0);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1c0));
  lVar2 = GetRcEngine::RcGetNum(0x392);
  lVar3 = GetRcEngine::RcGetNum(0x393);
  lVar4 = GetRcEngine::RcGetNum(0x391);
  lVar5 = GetRcEngine::RcGetNum(0x390);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_68 = operator_new(0x2b4);
                    /* try { // try from 007e232c to 007e2333 has its CatchHandler @ 007e235c */
  Image::Image(pIStack_68,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x11);
  *(Image **)(param_1 + 0x1c4) = pIStack_68;
  if (*(int *)(param_1 + 0x1c4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x216);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x1c4) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c4) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1c4));
  lVar2 = GetRcEngine::RcGetNum(0x3c6);
  lVar3 = GetRcEngine::RcGetNum(0x3c7);
  lVar4 = GetRcEngine::RcGetNum(0x3c5);
  lVar5 = GetRcEngine::RcGetNum(0x3c4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_6c = operator_new(0x250);
                    /* try { // try from 007e26dc to 007e26e3 has its CatchHandler @ 007e270c */
  TextBox::TextBox(pTStack_6c,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x12);
  *(TextBox **)(param_1 + 0x1c8) = pTStack_6c;
  if (*(int *)(param_1 + 0x1c8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x22a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45de);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1c8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1c8);
  uVar1 = GetRcEngine::RcGetNum(0x321c);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1c8));
  lVar2 = GetRcEngine::RcGetNum(0x3c2);
  lVar3 = GetRcEngine::RcGetNum(0x3c3);
  lVar4 = GetRcEngine::RcGetNum(0x3c1);
  lVar5 = GetRcEngine::RcGetNum(0x3c0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_70 = operator_new(0x250);
                    /* try { // try from 007e2b7c to 007e2b83 has its CatchHandler @ 007e2bac */
  TextBox::TextBox(pTStack_70,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x13);
  *(TextBox **)(param_1 + 0x1cc) = pTStack_70;
  if (*(int *)(param_1 + 0x1cc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x248);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1cc) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1cc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar1 = GetRcEngine::RcGetNum(0x321d);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1cc));
  lVar2 = GetRcEngine::RcGetNum(0x30a);
  lVar3 = GetRcEngine::RcGetNum(0x30b);
  lVar4 = GetRcEngine::RcGetNum(0x309);
  lVar5 = GetRcEngine::RcGetNum(0x308);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_74 = operator_new(0x264);
                    /* try { // try from 007e2fec to 007e2ff3 has its CatchHandler @ 007e301c */
  AbsContainer::AbsContainer(pAStack_74,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x14);
  *(AbsContainer **)(param_1 + 0x1d0) = pAStack_74;
  if (*(int *)(param_1 + 0x1d0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x264);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1d0) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1d0));
  lVar2 = GetRcEngine::RcGetNum(0x3aa);
  lVar3 = GetRcEngine::RcGetNum(0x3ab);
  lVar4 = GetRcEngine::RcGetNum(0x3a9);
  lVar5 = GetRcEngine::RcGetNum(0x3a8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pSStack_78 = operator_new(0xbf8);
                    /* try { // try from 007e330c to 007e3313 has its CatchHandler @ 007e333c */
  ScrollListContainer::ScrollListContainer
            (pSStack_78,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x15);
  *(ScrollListContainer **)(param_1 + 0x1d4) = pSStack_78;
  if (*(int *)(param_1 + 0x1d4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x274);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1d4) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d4) + 0xf4);
  ScrollListContainer::SetScrollBarWidth(*(ulong *)(param_1 + 0x1d4));
  ScrollListContainer::SetScrollBarWindSize(*(ulong *)(param_1 + 0x1d4));
  pMStack_7c = *(MImg **)(param_1 + 0x1d4);
  MImg::MImg(aMStack_1f0,0x5cd);
                    /* try { // try from 007e35a0 to 007e35a7 has its CatchHandler @ 007e37a4 */
  MImg::MImg(aMStack_204,0x5cd);
                    /* try { // try from 007e35bc to 007e35c3 has its CatchHandler @ 007e3744 */
  MImg::MImg(aMStack_218,0x5cd);
                    /* try { // try from 007e35d8 to 007e35df has its CatchHandler @ 007e36a4 */
  MImg::MImg(aMStack_22c,0x5cd);
                    /* try { // try from 007e3604 to 007e360b has its CatchHandler @ 007e3648 */
  ScrollListContainer::SetScrollbarImage(pMStack_7c,aMStack_1f0,aMStack_204,aMStack_218);
                    /* try { // try from 007e361c to 007e3623 has its CatchHandler @ 007e36a4 */
  MImg::~MImg(aMStack_22c);
                    /* try { // try from 007e3634 to 007e363b has its CatchHandler @ 007e3744 */
  MImg::~MImg(aMStack_218);
                    /* try { // try from 007e3690 to 007e3697 has its CatchHandler @ 007e37a4 */
  MImg::~MImg(aMStack_204);
  MImg::~MImg(aMStack_1f0);
  pMStack_80 = *(MImg **)(param_1 + 0x1d4);
  MImg::MImg(aMStack_240,0x5cd);
                    /* try { // try from 007e3730 to 007e3737 has its CatchHandler @ 007e39c4 */
  MImg::MImg(aMStack_254,0x5cd);
                    /* try { // try from 007e3790 to 007e3797 has its CatchHandler @ 007e3964 */
  MImg::MImg(aMStack_268,0x5cd);
                    /* try { // try from 007e37f8 to 007e37ff has its CatchHandler @ 007e38c4 */
  MImg::MImg(aMStack_27c,0x5cd);
                    /* try { // try from 007e3824 to 007e382b has its CatchHandler @ 007e3868 */
  ScrollListContainer::SetScrollbarUpImage(pMStack_80,aMStack_240,aMStack_254,aMStack_268);
                    /* try { // try from 007e383c to 007e3843 has its CatchHandler @ 007e38c4 */
  MImg::~MImg(aMStack_27c);
                    /* try { // try from 007e3854 to 007e385b has its CatchHandler @ 007e3964 */
  MImg::~MImg(aMStack_268);
                    /* try { // try from 007e38b0 to 007e38b7 has its CatchHandler @ 007e39c4 */
  MImg::~MImg(aMStack_254);
  MImg::~MImg(aMStack_240);
  pMStack_84 = *(MImg **)(param_1 + 0x1d4);
  MImg::MImg(aMStack_290,0x5cd);
                    /* try { // try from 007e3950 to 007e3957 has its CatchHandler @ 007e3be4 */
  MImg::MImg(aMStack_2a4,0x5cd);
                    /* try { // try from 007e39b0 to 007e39b7 has its CatchHandler @ 007e3b84 */
  MImg::MImg(aMStack_2b8,0x5cd);
                    /* try { // try from 007e3a18 to 007e3a1f has its CatchHandler @ 007e3ae4 */
  MImg::MImg(aMStack_2cc,0x5cd);
                    /* try { // try from 007e3a44 to 007e3a4b has its CatchHandler @ 007e3a88 */
  ScrollListContainer::SetScrollbarMiddleImage(pMStack_84,aMStack_290,aMStack_2a4,aMStack_2b8);
                    /* try { // try from 007e3a5c to 007e3a63 has its CatchHandler @ 007e3ae4 */
  MImg::~MImg(aMStack_2cc);
                    /* try { // try from 007e3a74 to 007e3a7b has its CatchHandler @ 007e3b84 */
  MImg::~MImg(aMStack_2b8);
                    /* try { // try from 007e3ad0 to 007e3ad7 has its CatchHandler @ 007e3be4 */
  MImg::~MImg(aMStack_2a4);
  MImg::~MImg(aMStack_290);
  pMStack_88 = *(MImg **)(param_1 + 0x1d4);
  MImg::MImg(aMStack_2e0,0x5cd);
                    /* try { // try from 007e3b70 to 007e3b77 has its CatchHandler @ 007e3eec */
  MImg::MImg(aMStack_2f4,0x5cd);
                    /* try { // try from 007e3bd0 to 007e3bd7 has its CatchHandler @ 007e3e8c */
  MImg::MImg(aMStack_308,0x5cd);
                    /* try { // try from 007e3c38 to 007e3c3f has its CatchHandler @ 007e3d04 */
  MImg::MImg(aMStack_31c,0x5cd);
                    /* try { // try from 007e3c64 to 007e3c6b has its CatchHandler @ 007e3ca8 */
  ScrollListContainer::SetScrollbarBottomImage(pMStack_88,aMStack_2e0,aMStack_2f4,aMStack_308);
                    /* try { // try from 007e3c7c to 007e3c83 has its CatchHandler @ 007e3d04 */
  MImg::~MImg(aMStack_31c);
                    /* try { // try from 007e3c94 to 007e3c9b has its CatchHandler @ 007e3e8c */
  MImg::~MImg(aMStack_308);
                    /* try { // try from 007e3cf0 to 007e3cf7 has its CatchHandler @ 007e3eec */
  MImg::~MImg(aMStack_2f4);
  MImg::~MImg(aMStack_2e0);
  ListContainer::SetDirection(*(undefined4 *)(param_1 + 0x1d4),1);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1d4));
  lVar2 = GetRcEngine::RcGetNum(0x34a);
  lVar3 = GetRcEngine::RcGetNum(0x34b);
  lVar4 = GetRcEngine::RcGetNum(0x349);
  lVar5 = GetRcEngine::RcGetNum(0x348);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_8c = operator_new(0x264);
                    /* try { // try from 007e3e78 to 007e3e7f has its CatchHandler @ 007e3f30 */
  AbsContainer::AbsContainer(pAStack_8c,*(MWidget **)(param_1 + 0x188),a_Stack_1dc,0,0x16);
  *(AbsContainer **)(param_1 + 0x1d8) = pAStack_8c;
  if (*(int *)(param_1 + 0x1d8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x28b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1d8) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1d8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1d8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1d8));
  lVar2 = GetRcEngine::RcGetNum(0x39a);
  lVar3 = GetRcEngine::RcGetNum(0x39b);
  lVar4 = GetRcEngine::RcGetNum(0x399);
  lVar5 = GetRcEngine::RcGetNum(0x398);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_90 = operator_new(0x2b4);
                    /* try { // try from 007e421c to 007e4223 has its CatchHandler @ 007e424c */
  Image::Image(pIStack_90,*(MWidget **)(param_1 + 0x1c0),a_Stack_1dc,0,0x17);
  *(Image **)(param_1 + 0x1dc) = pIStack_90;
  if (*(int *)(param_1 + 0x1dc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x29b);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0x29c);
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1dc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1dc) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1dc));
  lVar2 = GetRcEngine::RcGetNum(0x396);
  lVar3 = GetRcEngine::RcGetNum(0x397);
  lVar4 = GetRcEngine::RcGetNum(0x395);
  lVar5 = GetRcEngine::RcGetNum(0x394);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_94 = operator_new(0x2b4);
                    /* try { // try from 007e45bc to 007e45c3 has its CatchHandler @ 007e45ec */
  Image::Image(pIStack_94,*(MWidget **)(param_1 + 0x1c0),a_Stack_1dc,0,0x18);
  *(Image **)(param_1 + 0x1e0) = pIStack_94;
  if (*(int *)(param_1 + 0x1e0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x2ae);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0x29c);
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e0) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1e0));
  lVar2 = GetRcEngine::RcGetNum(0x406);
  lVar3 = GetRcEngine::RcGetNum(0x407);
  lVar4 = GetRcEngine::RcGetNum(0x405);
  lVar5 = GetRcEngine::RcGetNum(0x404);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_98 = operator_new(0x250);
                    /* try { // try from 007e495c to 007e4963 has its CatchHandler @ 007e498c */
  TextBox::TextBox(pTStack_98,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x19);
  *(TextBox **)(param_1 + 0x1e4) = pTStack_98;
  if (*(int *)(param_1 + 0x1e4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x2c1);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1e4) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1e4) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e4);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1e4));
  lVar2 = GetRcEngine::RcGetNum(0x3de);
  lVar3 = GetRcEngine::RcGetNum(0x3df);
  lVar4 = GetRcEngine::RcGetNum(0x3dd);
  lVar5 = GetRcEngine::RcGetNum(0x3dc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_9c = operator_new(0x250);
                    /* try { // try from 007e4dac to 007e4db3 has its CatchHandler @ 007e4ddc */
  TextBox::TextBox(pTStack_9c,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1a);
  *(TextBox **)(param_1 + 0x1e8) = pTStack_9c;
  if (*(int *)(param_1 + 0x1e8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x2dd);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1e8) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1e8) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1e8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1e8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1e8));
  lVar2 = GetRcEngine::RcGetNum(0x40a);
  lVar3 = GetRcEngine::RcGetNum(0x40b);
  lVar4 = GetRcEngine::RcGetNum(0x409);
  lVar5 = GetRcEngine::RcGetNum(0x408);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_a0 = operator_new(0x250);
                    /* try { // try from 007e51fc to 007e5203 has its CatchHandler @ 007e522c */
  TextBox::TextBox(pTStack_a0,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1b);
  *(TextBox **)(param_1 + 0x1ec) = pTStack_a0;
  if (*(int *)(param_1 + 0x1ec) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x2f9);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1ec) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1ec) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1ec) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1ec);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1ec));
  lVar2 = GetRcEngine::RcGetNum(0x3b6);
  lVar3 = GetRcEngine::RcGetNum(0x3b7);
  lVar4 = GetRcEngine::RcGetNum(0x3b5);
  lVar5 = GetRcEngine::RcGetNum(0x3b4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_a4 = operator_new(0x250);
                    /* try { // try from 007e564c to 007e5653 has its CatchHandler @ 007e567c */
  TextBox::TextBox(pTStack_a4,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1c);
  *(TextBox **)(param_1 + 0x1f0) = pTStack_a4;
  if (*(int *)(param_1 + 0x1f0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x315);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1f0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f0) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f0);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1f0) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1f0));
  lVar2 = GetRcEngine::RcGetNum(0x3ce);
  lVar3 = GetRcEngine::RcGetNum(0x3cf);
  lVar4 = GetRcEngine::RcGetNum(0x3cd);
  lVar5 = GetRcEngine::RcGetNum(0x3cc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_a8 = operator_new(0x250);
                    /* try { // try from 007e5a9c to 007e5aa3 has its CatchHandler @ 007e5acc */
  TextBox::TextBox(pTStack_a8,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1d);
  *(TextBox **)(param_1 + 500) = pTStack_a8;
  if (*(int *)(param_1 + 500) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x331);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 500) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 500) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 500) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 500);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 500) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 500);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 500) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 500));
  lVar2 = GetRcEngine::RcGetNum(0x40e);
  lVar3 = GetRcEngine::RcGetNum(0x40f);
  lVar4 = GetRcEngine::RcGetNum(0x40d);
  lVar5 = GetRcEngine::RcGetNum(0x40c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_ac = operator_new(0x250);
                    /* try { // try from 007e5eec to 007e5ef3 has its CatchHandler @ 007e5f1c */
  TextBox::TextBox(pTStack_ac,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1e);
  *(TextBox **)(param_1 + 0x1f8) = pTStack_ac;
  if (*(int *)(param_1 + 0x1f8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x34d);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1f8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1f8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1f8) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1f8);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1f8) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1f8));
  lVar2 = GetRcEngine::RcGetNum(0x3ea);
  lVar3 = GetRcEngine::RcGetNum(0x3eb);
  lVar4 = GetRcEngine::RcGetNum(0x3e9);
  lVar5 = GetRcEngine::RcGetNum(1000);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_b0 = operator_new(0x250);
                    /* try { // try from 007e633c to 007e6343 has its CatchHandler @ 007e636c */
  TextBox::TextBox(pTStack_b0,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x1f);
  *(TextBox **)(param_1 + 0x1fc) = pTStack_b0;
  if (*(int *)(param_1 + 0x1fc) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x369);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x1fc) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1fc) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x1fc) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x1fc);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1fc) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1fc));
  lVar2 = GetRcEngine::RcGetNum(0x41a);
  lVar3 = GetRcEngine::RcGetNum(0x41b);
  lVar4 = GetRcEngine::RcGetNum(0x419);
  lVar5 = GetRcEngine::RcGetNum(0x418);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_b4 = operator_new(0x250);
                    /* try { // try from 007e678c to 007e6793 has its CatchHandler @ 007e67bc */
  TextBox::TextBox(pTStack_b4,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x20);
  *(TextBox **)(param_1 + 0x200) = pTStack_b4;
  if (*(int *)(param_1 + 0x200) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x385);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x200) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x200) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x200) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x200) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x200);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x200) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x200));
  lVar2 = GetRcEngine::RcGetNum(0x412);
  lVar3 = GetRcEngine::RcGetNum(0x413);
  lVar4 = GetRcEngine::RcGetNum(0x411);
  lVar5 = GetRcEngine::RcGetNum(0x410);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_b8 = operator_new(0x250);
                    /* try { // try from 007e6bdc to 007e6be3 has its CatchHandler @ 007e6c0c */
  TextBox::TextBox(pTStack_b8,*(MWidget **)(param_1 + 0x1d4),a_Stack_1dc,0,0x21);
  *(TextBox **)(param_1 + 0x204) = pTStack_b8;
  if (*(int *)(param_1 + 0x204) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x3a1);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x204) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x204) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x204) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x204) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x204);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x204));
  lVar2 = GetRcEngine::RcGetNum(0x326);
  lVar3 = GetRcEngine::RcGetNum(0x327);
  lVar4 = GetRcEngine::RcGetNum(0x325);
  lVar5 = GetRcEngine::RcGetNum(0x324);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_bc = operator_new(0x264);
                    /* try { // try from 007e702c to 007e7033 has its CatchHandler @ 007e705c */
  AbsContainer::AbsContainer(pAStack_bc,*(MWidget **)(param_1 + 0x18c),a_Stack_1dc,0,0x22);
  *(AbsContainer **)(param_1 + 0x208) = pAStack_bc;
  if (*(int *)(param_1 + 0x208) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x3bd);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x208) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x208);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x208) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x208));
  lVar2 = GetRcEngine::RcGetNum(0x322);
  lVar3 = GetRcEngine::RcGetNum(0x323);
  lVar4 = GetRcEngine::RcGetNum(0x321);
  lVar5 = GetRcEngine::RcGetNum(800);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_c0 = operator_new(0x264);
                    /* try { // try from 007e734c to 007e7353 has its CatchHandler @ 007e737c */
  AbsContainer::AbsContainer(pAStack_c0,*(MWidget **)(param_1 + 0x18c),a_Stack_1dc,0,0x23);
  *(AbsContainer **)(param_1 + 0x20c) = pAStack_c0;
  if (*(int *)(param_1 + 0x20c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x3cd);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x20c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x20c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x20c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x20c));
  lVar2 = GetRcEngine::RcGetNum(0x32a);
  lVar3 = GetRcEngine::RcGetNum(0x32b);
  lVar4 = GetRcEngine::RcGetNum(0x329);
  lVar5 = GetRcEngine::RcGetNum(0x328);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_c4 = operator_new(0x264);
                    /* try { // try from 007e766c to 007e7673 has its CatchHandler @ 007e769c */
  AbsContainer::AbsContainer(pAStack_c4,*(MWidget **)(param_1 + 0x18c),a_Stack_1dc,0,0x24);
  *(AbsContainer **)(param_1 + 0x210) = pAStack_c4;
  if (*(int *)(param_1 + 0x210) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x3dd);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x210);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x210) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x210),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x210),2,0);
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x210));
  lVar2 = GetRcEngine::RcGetNum(0x3f2);
  lVar3 = GetRcEngine::RcGetNum(0x3f3);
  lVar4 = GetRcEngine::RcGetNum(0x3f1);
  lVar5 = GetRcEngine::RcGetNum(0x3f0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_c8 = operator_new(0x250);
                    /* try { // try from 007e79d4 to 007e79db has its CatchHandler @ 007e7a04 */
  TextBox::TextBox(pTStack_c8,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x25);
  *(TextBox **)(param_1 + 0x214) = pTStack_c8;
  if (*(int *)(param_1 + 0x214) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x3ef);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x214) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x214) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x214) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x214);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x214) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x214));
  lVar2 = GetRcEngine::RcGetNum(0x3ee);
  lVar3 = GetRcEngine::RcGetNum(0x3ef);
  lVar4 = GetRcEngine::RcGetNum(0x3ed);
  lVar5 = GetRcEngine::RcGetNum(0x3ec);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_cc = operator_new(0x250);
                    /* try { // try from 007e7e74 to 007e7e7b has its CatchHandler @ 007e7ea4 */
  TextBox::TextBox(pTStack_cc,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x26);
  *(TextBox **)(param_1 + 0x218) = pTStack_cc;
  if (*(int *)(param_1 + 0x218) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x40d);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x218) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x218) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x218) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x218) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar6 = GetRcEngine::RcGetColor(0x31);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x218) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x218) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x218) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x218) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x218) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x218);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x218));
  lVar2 = GetRcEngine::RcGetNum(0x2e2);
  lVar3 = GetRcEngine::RcGetNum(0x2e3);
  lVar4 = GetRcEngine::RcGetNum(0x2e1);
  lVar5 = GetRcEngine::RcGetNum(0x2e0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_d0 = operator_new(0x264);
                    /* try { // try from 007e8324 to 007e832b has its CatchHandler @ 007e8354 */
  AbsContainer::AbsContainer(pAStack_d0,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x27);
  *(AbsContainer **)(param_1 + 0x21c) = pAStack_d0;
  if (*(int *)(param_1 + 0x21c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x42c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x21c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x21c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x21c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x21c));
  lVar2 = GetRcEngine::RcGetNum(0x3b2);
  lVar3 = GetRcEngine::RcGetNum(0x3b3);
  lVar4 = GetRcEngine::RcGetNum(0x3b1);
  lVar5 = GetRcEngine::RcGetNum(0x3b0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_d4 = operator_new(0x250);
                    /* try { // try from 007e8644 to 007e864b has its CatchHandler @ 007e8674 */
  TextBox::TextBox(pTStack_d4,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x28);
  *(TextBox **)(param_1 + 0x220) = pTStack_d4;
  if (*(int *)(param_1 + 0x220) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x43c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x220) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x220) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x220) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x220) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x220);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x220));
  lVar2 = GetRcEngine::RcGetNum(0x416);
  lVar3 = GetRcEngine::RcGetNum(0x417);
  lVar4 = GetRcEngine::RcGetNum(0x415);
  lVar5 = GetRcEngine::RcGetNum(0x414);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_d8 = operator_new(0x250);
                    /* try { // try from 007e8ab4 to 007e8abb has its CatchHandler @ 007e8ae4 */
  TextBox::TextBox(pTStack_d8,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x29);
  *(TextBox **)(param_1 + 0x224) = pTStack_d8;
  if (*(int *)(param_1 + 0x224) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x458);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x224) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x224) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x224) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x224);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x224));
  lVar2 = GetRcEngine::RcGetNum(0x2ce);
  lVar3 = GetRcEngine::RcGetNum(0x2cf);
  lVar4 = GetRcEngine::RcGetNum(0x2cd);
  lVar5 = GetRcEngine::RcGetNum(0x2cc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_dc = operator_new(0x264);
                    /* try { // try from 007e8f24 to 007e8f2b has its CatchHandler @ 007e8f54 */
  AbsContainer::AbsContainer(pAStack_dc,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x2a);
  *(AbsContainer **)(param_1 + 0x228) = pAStack_dc;
  if (*(int *)(param_1 + 0x228) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x474);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x228) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x228);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x228) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x228));
  lVar2 = GetRcEngine::RcGetNum(0x37e);
  lVar3 = GetRcEngine::RcGetNum(0x37f);
  lVar4 = GetRcEngine::RcGetNum(0x37d);
  lVar5 = GetRcEngine::RcGetNum(0x37c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_e0 = operator_new(0x2b4);
                    /* try { // try from 007e9244 to 007e924b has its CatchHandler @ 007e9274 */
  Image::Image(pIStack_e0,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x2b);
  *(Image **)(param_1 + 0x22c) = pIStack_e0;
  if (*(int *)(param_1 + 0x22c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x484);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x22c) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x22c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x22c) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x22c),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x22c),2,0);
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x22c));
  lVar2 = GetRcEngine::RcGetNum(0x38a);
  lVar3 = GetRcEngine::RcGetNum(0x38b);
  lVar4 = GetRcEngine::RcGetNum(0x389);
  lVar5 = GetRcEngine::RcGetNum(0x388);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_e4 = operator_new(0x2b4);
                    /* try { // try from 007e9638 to 007e963f has its CatchHandler @ 007e9668 */
  Image::Image(pIStack_e4,*(MWidget **)(param_1 + 0x208),a_Stack_1dc,0,0x2c);
  *(Image **)(param_1 + 0x230) = pIStack_e4;
  if (*(int *)(param_1 + 0x230) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x49a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x230) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x230);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x230) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x230),2,0);
  (**(code **)(**(int **)(param_1 + 0x208) + 0x34))
            (*(undefined4 *)(param_1 + 0x208),*(undefined4 *)(param_1 + 0x230));
  lVar2 = GetRcEngine::RcGetNum(0x2d2);
  lVar3 = GetRcEngine::RcGetNum(0x2d3);
  lVar4 = GetRcEngine::RcGetNum(0x2d1);
  lVar5 = GetRcEngine::RcGetNum(0x2d0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_e8 = operator_new(0x264);
                    /* try { // try from 007e9a08 to 007e9a0f has its CatchHandler @ 007e9a38 */
  AbsContainer::AbsContainer(pAStack_e8,*(MWidget **)(param_1 + 0x228),a_Stack_1dc,0,0x2d);
  *(AbsContainer **)(param_1 + 0x234) = pAStack_e8;
  if (*(int *)(param_1 + 0x234) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x4af);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x234) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x234);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x234) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x228) + 0x34))
            (*(undefined4 *)(param_1 + 0x228),*(undefined4 *)(param_1 + 0x234));
  lVar2 = GetRcEngine::RcGetNum(0x30e);
  lVar3 = GetRcEngine::RcGetNum(0x30f);
  lVar4 = GetRcEngine::RcGetNum(0x30d);
  lVar5 = GetRcEngine::RcGetNum(0x30c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_ec = operator_new(0x264);
                    /* try { // try from 007e9d28 to 007e9d2f has its CatchHandler @ 007e9d58 */
  AbsContainer::AbsContainer(pAStack_ec,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x2e);
  *(AbsContainer **)(param_1 + 0x238) = pAStack_ec;
  if (*(int *)(param_1 + 0x238) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x4bf);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar13 = *(int *)(param_1 + 0x238);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x50) = uVar6;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x54) = uVar6;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x58) = uVar6;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x238);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x238) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x238),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x238),2,0);
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x238));
  lVar2 = GetRcEngine::RcGetNum(0x3d2);
  lVar3 = GetRcEngine::RcGetNum(0x3d3);
  lVar4 = GetRcEngine::RcGetNum(0x3d1);
  lVar5 = GetRcEngine::RcGetNum(0x3d0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_f0 = operator_new(0x250);
                    /* try { // try from 007ea100 to 007ea107 has its CatchHandler @ 007ea130 */
  TextBox::TextBox(pTStack_f0,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x2f);
  *(TextBox **)(param_1 + 0x23c) = pTStack_f0;
  if (*(int *)(param_1 + 0x23c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x4d4);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x23c) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x23c) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x23c) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x23c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x23c) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x23c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x23c));
  lVar2 = GetRcEngine::RcGetNum(0x3d6);
  lVar3 = GetRcEngine::RcGetNum(0x3d7);
  lVar4 = GetRcEngine::RcGetNum(0x3d5);
  lVar5 = GetRcEngine::RcGetNum(0x3d4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_f4 = operator_new(0x250);
                    /* try { // try from 007ea590 to 007ea597 has its CatchHandler @ 007ea5c0 */
  TextBox::TextBox(pTStack_f4,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x30);
  *(TextBox **)(param_1 + 0x240) = pTStack_f4;
  if (*(int *)(param_1 + 0x240) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x4f2);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x240) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x240) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x240) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x240) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x240);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x240));
  lVar2 = GetRcEngine::RcGetNum(0x3e2);
  lVar3 = GetRcEngine::RcGetNum(0x3e3);
  lVar4 = GetRcEngine::RcGetNum(0x3e1);
  lVar5 = GetRcEngine::RcGetNum(0x3e0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_f8 = operator_new(0x250);
                    /* try { // try from 007eaa00 to 007eaa07 has its CatchHandler @ 007eaa30 */
  TextBox::TextBox(pTStack_f8,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x31);
  *(TextBox **)(param_1 + 0x244) = pTStack_f8;
  if (*(int *)(param_1 + 0x244) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x50e);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x244) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x244) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x244);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x128) = 0x11;
  TextBox::SetMultiline((uchar)*(undefined4 *)(param_1 + 0x244));
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x244));
  lVar2 = GetRcEngine::RcGetNum(0x32e);
  lVar3 = GetRcEngine::RcGetNum(0x32f);
  lVar4 = GetRcEngine::RcGetNum(0x32d);
  lVar5 = GetRcEngine::RcGetNum(0x32c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_fc = operator_new(0x264);
                    /* try { // try from 007eae80 to 007eae87 has its CatchHandler @ 007eaeb0 */
  AbsContainer::AbsContainer(pAStack_fc,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x32);
  *(AbsContainer **)(param_1 + 0x248) = pAStack_fc;
  if (*(int *)(param_1 + 0x248) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x52c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x248) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x248);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x248) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x248));
  lVar2 = GetRcEngine::RcGetNum(0x3a6);
  lVar3 = GetRcEngine::RcGetNum(0x3a7);
  lVar4 = GetRcEngine::RcGetNum(0x3a5);
  lVar5 = GetRcEngine::RcGetNum(0x3a4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pSStack_100 = operator_new(0x950);
                    /* try { // try from 007eb19c to 007eb1a3 has its CatchHandler @ 007eb1cc */
  ScrollBar::ScrollBar(pSStack_100,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x33);
  *(ScrollBar **)(param_1 + 0x24c) = pSStack_100;
  if (*(int *)(param_1 + 0x24c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x53c);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 0x289) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 0x4d9) = 0;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x24c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  ScrollBar::SetScrollMaxPosition(*(ulong *)(param_1 + 0x24c));
  ScrollBar::SetDirection(*(undefined4 *)(param_1 + 0x24c),0);
  ScrollBar::SetScrollPosition(*(ulong *)(param_1 + 0x24c));
  ScrollBar::SetScrollWindowSize(*(ulong *)(param_1 + 0x24c));
  pMStack_104 = *(MImg **)(param_1 + 0x24c);
  MImg::MImg(aMStack_330,0x5cd);
                    /* try { // try from 007eb3ec to 007eb3f3 has its CatchHandler @ 007eb678 */
  MImg::MImg(aMStack_344,0x5cd);
                    /* try { // try from 007eb408 to 007eb40f has its CatchHandler @ 007eb618 */
  MImg::MImg(aMStack_358,0x5cd);
                    /* try { // try from 007eb424 to 007eb42b has its CatchHandler @ 007eb4f0 */
  MImg::MImg(aMStack_36c,0x5cd);
                    /* try { // try from 007eb450 to 007eb457 has its CatchHandler @ 007eb494 */
  ScrollBar::SetScrollbarImage(pMStack_104,aMStack_330,aMStack_344,aMStack_358);
                    /* try { // try from 007eb468 to 007eb46f has its CatchHandler @ 007eb4f0 */
  MImg::~MImg(aMStack_36c);
                    /* try { // try from 007eb480 to 007eb487 has its CatchHandler @ 007eb618 */
  MImg::~MImg(aMStack_358);
                    /* try { // try from 007eb4dc to 007eb4e3 has its CatchHandler @ 007eb678 */
  MImg::~MImg(aMStack_344);
  MImg::~MImg(aMStack_330);
  uVar14 = *(ulong *)(param_1 + 0x24c);
  uVar7 = GetRcEngine::RcGetColor(1);
  uVar8 = GetRcEngine::RcGetColor(1);
  uVar9 = GetRcEngine::RcGetColor(1);
  GetRcEngine::RcGetColor(1);
  ScrollBar::SetScrollbarColor(uVar14,uVar7,uVar8,uVar9);
  pMStack_108 = *(MImg **)(param_1 + 0x24c);
  MImg::MImg(aMStack_380,0x5cd);
                    /* try { // try from 007eb604 to 007eb60b has its CatchHandler @ 007eb920 */
  MImg::MImg(aMStack_394,0x5cd);
                    /* try { // try from 007eb664 to 007eb66b has its CatchHandler @ 007eb8c0 */
  MImg::MImg(aMStack_3a8,0x5cd);
                    /* try { // try from 007eb6cc to 007eb6d3 has its CatchHandler @ 007eb798 */
  MImg::MImg(aMStack_3bc,0x5cd);
                    /* try { // try from 007eb6f8 to 007eb6ff has its CatchHandler @ 007eb73c */
  ScrollBar::SetUpImage(pMStack_108,aMStack_380,aMStack_394,aMStack_3a8);
                    /* try { // try from 007eb710 to 007eb717 has its CatchHandler @ 007eb798 */
  MImg::~MImg(aMStack_3bc);
                    /* try { // try from 007eb728 to 007eb72f has its CatchHandler @ 007eb8c0 */
  MImg::~MImg(aMStack_3a8);
                    /* try { // try from 007eb784 to 007eb78b has its CatchHandler @ 007eb920 */
  MImg::~MImg(aMStack_394);
  MImg::~MImg(aMStack_380);
  uVar14 = *(ulong *)(param_1 + 0x24c);
  uVar7 = GetRcEngine::RcGetColor(0x51);
  uVar8 = GetRcEngine::RcGetColor(0x51);
  uVar9 = GetRcEngine::RcGetColor(0x51);
  GetRcEngine::RcGetColor(0x51);
  ScrollBar::SetUpColor(uVar14,uVar7,uVar8,uVar9);
  pMStack_10c = *(MImg **)(param_1 + 0x24c);
  MImg::MImg(aMStack_3d0,0x5cd);
                    /* try { // try from 007eb8ac to 007eb8b3 has its CatchHandler @ 007ebbc8 */
  MImg::MImg(aMStack_3e4,0x5cd);
                    /* try { // try from 007eb90c to 007eb913 has its CatchHandler @ 007ebb68 */
  MImg::MImg(aMStack_3f8,0x5cd);
                    /* try { // try from 007eb974 to 007eb97b has its CatchHandler @ 007eba40 */
  MImg::MImg(aMStack_40c,0x5cd);
                    /* try { // try from 007eb9a0 to 007eb9a7 has its CatchHandler @ 007eb9e4 */
  ScrollBar::SetBottomImage(pMStack_10c,aMStack_3d0,aMStack_3e4,aMStack_3f8);
                    /* try { // try from 007eb9b8 to 007eb9bf has its CatchHandler @ 007eba40 */
  MImg::~MImg(aMStack_40c);
                    /* try { // try from 007eb9d0 to 007eb9d7 has its CatchHandler @ 007ebb68 */
  MImg::~MImg(aMStack_3f8);
                    /* try { // try from 007eba2c to 007eba33 has its CatchHandler @ 007ebbc8 */
  MImg::~MImg(aMStack_3e4);
  MImg::~MImg(aMStack_3d0);
  uVar14 = *(ulong *)(param_1 + 0x24c);
  uVar7 = GetRcEngine::RcGetColor(0x51);
  uVar8 = GetRcEngine::RcGetColor(0x51);
  uVar9 = GetRcEngine::RcGetColor(0x51);
  GetRcEngine::RcGetColor(0x51);
  ScrollBar::SetBottomColor(uVar14,uVar7,uVar8,uVar9);
  pMStack_110 = *(MImg **)(param_1 + 0x24c);
  MImg::MImg(aMStack_420,0x5cd);
                    /* try { // try from 007ebb54 to 007ebb5b has its CatchHandler @ 007ebf38 */
  MImg::MImg(aMStack_434,0x5cd);
                    /* try { // try from 007ebbb4 to 007ebbbb has its CatchHandler @ 007ebed8 */
  MImg::MImg(aMStack_448,0x5cd);
                    /* try { // try from 007ebc1c to 007ebc23 has its CatchHandler @ 007ebce8 */
  MImg::MImg(aMStack_45c,0x5cd);
                    /* try { // try from 007ebc48 to 007ebc4f has its CatchHandler @ 007ebc8c */
  ScrollBar::SetMiddleImage(pMStack_110,aMStack_420,aMStack_434,aMStack_448);
                    /* try { // try from 007ebc60 to 007ebc67 has its CatchHandler @ 007ebce8 */
  MImg::~MImg(aMStack_45c);
                    /* try { // try from 007ebc78 to 007ebc7f has its CatchHandler @ 007ebed8 */
  MImg::~MImg(aMStack_448);
                    /* try { // try from 007ebcd4 to 007ebcdb has its CatchHandler @ 007ebf38 */
  MImg::~MImg(aMStack_434);
  MImg::~MImg(aMStack_420);
  uVar14 = *(ulong *)(param_1 + 0x24c);
  uVar7 = GetRcEngine::RcGetColor(0x1e);
  uVar8 = GetRcEngine::RcGetColor(0x1e);
  uVar9 = GetRcEngine::RcGetColor(0x1e);
  GetRcEngine::RcGetColor(0x1e);
  ScrollBar::SetMiddleColor(uVar14,uVar7,uVar8,uVar9);
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x24c));
  lVar2 = GetRcEngine::RcGetNum(0x382);
  lVar3 = GetRcEngine::RcGetNum(899);
  lVar4 = GetRcEngine::RcGetNum(0x381);
  lVar5 = GetRcEngine::RcGetNum(0x380);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_114 = operator_new(0x2b4);
                    /* try { // try from 007ebec4 to 007ebecb has its CatchHandler @ 007ebf7c */
  Image::Image(pIStack_114,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x34);
  *(Image **)(param_1 + 0x250) = pIStack_114;
  if (*(int *)(param_1 + 0x250) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x555);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x250) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x250);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x250) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x250),2,0);
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 0x250));
  lVar2 = GetRcEngine::RcGetNum(0x3a2);
  lVar3 = GetRcEngine::RcGetNum(0x3a3);
  lVar4 = GetRcEngine::RcGetNum(0x3a1);
  lVar5 = GetRcEngine::RcGetNum(0x3a0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pPStack_118 = operator_new(0x4c8);
                    /* try { // try from 007ec31c to 007ec323 has its CatchHandler @ 007ec34c */
  ProgressBar::ProgressBar(pPStack_118,*(MWidget **)(param_1 + 0x238),a_Stack_1dc,0,0x35);
  *(ProgressBar **)(param_1 + 0x254) = pPStack_118;
  if (*(int *)(param_1 + 0x254) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x56a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x254) + 0x251) = 0;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x28);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x28);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x28);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x28);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x254) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x254) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x254) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x254) + 0x254) + 0x154) = 0x4ae;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x3208);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x3208);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(*(int *)(param_1 + 0x254) + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x50) = uVar6;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x54) = uVar6;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x58) = uVar6;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x254);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x254) + 0xf4);
  ProgressBar::SetCurValue(*(long *)(param_1 + 0x254));
  ProgressBar::SetBarSlice(*(ulong *)(param_1 + 0x254));
  ProgressBar::SetBarPadding((ushort)*(undefined4 *)(param_1 + 0x254));
  uStack_11c = *(undefined4 *)(param_1 + 0x254);
  MImg::MImg(aMStack_470,0x3f2);
                    /* try { // try from 007ec8c0 to 007ec8c7 has its CatchHandler @ 007ecc88 */
  MImg::MImg(aMStack_484,0x3f2);
                    /* try { // try from 007ec8dc to 007ec8e3 has its CatchHandler @ 007ecc28 */
  MImg::MImg(aMStack_498,0x5cd);
                    /* try { // try from 007ec8f8 to 007ec8ff has its CatchHandler @ 007ec9cc */
  MImg::MImg(aMStack_4ac,0x5cd);
                    /* try { // try from 007ec92c to 007ec933 has its CatchHandler @ 007ec970 */
  ProgressBar::SetBarImg((uchar)uStack_11c,(MImg *)0x0,aMStack_470,aMStack_484,aMStack_498);
                    /* try { // try from 007ec944 to 007ec94b has its CatchHandler @ 007ec9cc */
  MImg::~MImg(aMStack_4ac);
                    /* try { // try from 007ec95c to 007ec963 has its CatchHandler @ 007ecc28 */
  MImg::~MImg(aMStack_498);
                    /* try { // try from 007ec9b8 to 007ec9bf has its CatchHandler @ 007ecc88 */
  MImg::~MImg(aMStack_484);
  MImg::~MImg(aMStack_470);
  uVar14 = *(ulong *)(param_1 + 0x254);
  uVar7 = GetRcEngine::RcGetColor(0x41);
  uVar8 = GetRcEngine::RcGetColor(0x41);
  uVar9 = GetRcEngine::RcGetColor(0x41);
  GetRcEngine::RcGetColor(0x41);
  ProgressBar::SetBarColor(uVar14,uVar7,uVar8,uVar9);
  ProgressBar::SetDrectionProperty(*(undefined4 *)(param_1 + 0x254),1,1);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x254),1,0);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x254),2,0);
  (**(code **)(**(int **)(param_1 + 0x238) + 0x34))
            (*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0x254));
  lVar2 = GetRcEngine::RcGetNum(0x37a);
  lVar3 = GetRcEngine::RcGetNum(0x37b);
  lVar4 = GetRcEngine::RcGetNum(0x379);
  lVar5 = GetRcEngine::RcGetNum(0x378);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_120 = operator_new(0x2b4);
                    /* try { // try from 007ecc14 to 007ecc1b has its CatchHandler @ 007ecccc */
  Image::Image(pIStack_120,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x36);
  *(Image **)(param_1 + 600) = pIStack_120;
  if (*(int *)(param_1 + 600) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x598);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 600) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 600);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 600) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 600));
  lVar2 = GetRcEngine::RcGetNum(0x3e6);
  lVar3 = GetRcEngine::RcGetNum(999);
  lVar4 = GetRcEngine::RcGetNum(0x3e5);
  lVar5 = GetRcEngine::RcGetNum(0x3e4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_124 = operator_new(0x250);
                    /* try { // try from 007ed048 to 007ed04f has its CatchHandler @ 007ed078 */
  TextBox::TextBox(pTStack_124,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x37);
  *(TextBox **)(param_1 + 0x25c) = pTStack_124;
  if (*(int *)(param_1 + 0x25c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x5ac);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x25c) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x25c) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x25c) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar6 = GetRcEngine::RcGetColor(0x1e);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar6 = GetRcEngine::RcGetColor(0x1e);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar6 = GetRcEngine::RcGetColor(0x1e);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar6 = GetRcEngine::RcGetColor(0x1e);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x25c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x25c);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 0x25c));
  lVar2 = GetRcEngine::RcGetNum(0x3da);
  lVar3 = GetRcEngine::RcGetNum(0x3db);
  lVar4 = GetRcEngine::RcGetNum(0x3d9);
  lVar5 = GetRcEngine::RcGetNum(0x3d8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_128 = operator_new(0x250);
                    /* try { // try from 007ed4f8 to 007ed4ff has its CatchHandler @ 007ed528 */
  TextBox::TextBox(pTStack_128,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x38);
  *(TextBox **)(param_1 + 0x260) = pTStack_128;
  if (*(int *)(param_1 + 0x260) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x5cb);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x260) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x260) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x260) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x260) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x45dd);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x260) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x260);
  uVar1 = GetRcEngine::RcGetNum(0x320f);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 0x260));
  lVar2 = GetRcEngine::RcGetNum(0x38e);
  lVar3 = GetRcEngine::RcGetNum(0x38f);
  lVar4 = GetRcEngine::RcGetNum(0x38d);
  lVar5 = GetRcEngine::RcGetNum(0x38c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_12c = operator_new(0x2b4);
                    /* try { // try from 007ed9b8 to 007ed9bf has its CatchHandler @ 007ed9e8 */
  Image::Image(pIStack_12c,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x39);
  *(Image **)(param_1 + 0x264) = pIStack_12c;
  if (*(int *)(param_1 + 0x264) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x5eb);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0x29c);
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x264);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x264) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 0x264));
  lVar2 = GetRcEngine::RcGetNum(0x386);
  lVar3 = GetRcEngine::RcGetNum(0x387);
  lVar4 = GetRcEngine::RcGetNum(0x385);
  lVar5 = GetRcEngine::RcGetNum(900);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_130 = operator_new(0x2b4);
                    /* try { // try from 007edd58 to 007edd5f has its CatchHandler @ 007edd88 */
  Image::Image(pIStack_130,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x3a);
  *(Image **)(param_1 + 0x268) = pIStack_130;
  if (*(int *)(param_1 + 0x268) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x5fe);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0x260);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0x274);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0x288);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0x29c);
  *(undefined1 *)(*(int *)(param_1 + 0x268) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x268);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x268) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 0x268));
  lVar2 = GetRcEngine::RcGetNum(0x3fa);
  lVar3 = GetRcEngine::RcGetNum(0x3fb);
  lVar4 = GetRcEngine::RcGetNum(0x3f9);
  lVar5 = GetRcEngine::RcGetNum(0x3f8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_134 = operator_new(0x250);
                    /* try { // try from 007ee104 to 007ee10b has its CatchHandler @ 007ee134 */
  TextBox::TextBox(pTStack_134,*(MWidget **)(param_1 + 0x248),a_Stack_1dc,0,0x3b);
  *(TextBox **)(param_1 + 0x26c) = pTStack_134;
  if (*(int *)(param_1 + 0x26c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x612);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x26c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x26c) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x26c);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x26c) + 0x128) = 2;
  (**(code **)(**(int **)(param_1 + 0x248) + 0x34))
            (*(undefined4 *)(param_1 + 0x248),*(undefined4 *)(param_1 + 0x26c));
  lVar2 = GetRcEngine::RcGetNum(0x2ee);
  lVar3 = GetRcEngine::RcGetNum(0x2ef);
  lVar4 = GetRcEngine::RcGetNum(0x2ed);
  lVar5 = GetRcEngine::RcGetNum(0x2ec);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_138 = operator_new(0x264);
                    /* try { // try from 007ee588 to 007ee58f has its CatchHandler @ 007ee5b8 */
  AbsContainer::AbsContainer(pAStack_138,*(MWidget **)(param_1 + 400),a_Stack_1dc,0,0x3c);
  *(AbsContainer **)(param_1 + 0x270) = pAStack_138;
  if (*(int *)(param_1 + 0x270) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x62f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x270) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x270);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x270) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x270));
  lVar2 = GetRcEngine::RcGetNum(0x2ea);
  lVar3 = GetRcEngine::RcGetNum(0x2eb);
  lVar4 = GetRcEngine::RcGetNum(0x2e9);
  lVar5 = GetRcEngine::RcGetNum(0x2e8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_13c = operator_new(0x264);
                    /* try { // try from 007ee8a8 to 007ee8af has its CatchHandler @ 007ee8d8 */
  AbsContainer::AbsContainer(pAStack_13c,*(MWidget **)(param_1 + 400),a_Stack_1dc,0,0x3d);
  *(AbsContainer **)(param_1 + 0x274) = pAStack_13c;
  if (*(int *)(param_1 + 0x274) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x63f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x274) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x274);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x274) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x274));
  lVar2 = GetRcEngine::RcGetNum(0x2f2);
  lVar3 = GetRcEngine::RcGetNum(0x2f3);
  lVar4 = GetRcEngine::RcGetNum(0x2f1);
  lVar5 = GetRcEngine::RcGetNum(0x2f0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_140 = operator_new(0x264);
                    /* try { // try from 007eebc8 to 007eebcf has its CatchHandler @ 007eebf8 */
  AbsContainer::AbsContainer(pAStack_140,*(MWidget **)(param_1 + 400),a_Stack_1dc,0,0x3e);
  *(AbsContainer **)(param_1 + 0x278) = pAStack_140;
  if (*(int *)(param_1 + 0x278) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x64f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x278) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x278);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x278) + 0xf4);
  (**(code **)(**(int **)(param_1 + 400) + 0x34))
            (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x278));
  lVar2 = GetRcEngine::RcGetNum(0x312);
  lVar3 = GetRcEngine::RcGetNum(0x313);
  lVar4 = GetRcEngine::RcGetNum(0x311);
  lVar5 = GetRcEngine::RcGetNum(0x310);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_144 = operator_new(0x264);
                    /* try { // try from 007eeee8 to 007eeeef has its CatchHandler @ 007eef18 */
  AbsContainer::AbsContainer(pAStack_144,*(MWidget **)(param_1 + 0x270),a_Stack_1dc,0,0x3f);
  *(AbsContainer **)(param_1 + 0x27c) = pAStack_144;
  if (*(int *)(param_1 + 0x27c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x65f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x27c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x27c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x27c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x270) + 0x34))
            (*(undefined4 *)(param_1 + 0x270),*(undefined4 *)(param_1 + 0x27c));
  lVar2 = GetRcEngine::RcGetNum(0x3ca);
  lVar3 = GetRcEngine::RcGetNum(0x3cb);
  lVar4 = GetRcEngine::RcGetNum(0x3c9);
  lVar5 = GetRcEngine::RcGetNum(0x3c8);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_148 = operator_new(0x250);
                    /* try { // try from 007ef208 to 007ef20f has its CatchHandler @ 007ef238 */
  TextBox::TextBox(pTStack_148,*(MWidget **)(param_1 + 0x270),a_Stack_1dc,0,0x40);
  *(TextBox **)(param_1 + 0x280) = pTStack_148;
  if (*(int *)(param_1 + 0x280) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x66f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x280) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x280) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x280) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x280) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x280);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x270) + 0x34))
            (*(undefined4 *)(param_1 + 0x270),*(undefined4 *)(param_1 + 0x280));
  lVar2 = GetRcEngine::RcGetNum(0x3f6);
  lVar3 = GetRcEngine::RcGetNum(0x3f7);
  lVar4 = GetRcEngine::RcGetNum(0x3f5);
  lVar5 = GetRcEngine::RcGetNum(0x3f4);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_14c = operator_new(0x250);
                    /* try { // try from 007ef638 to 007ef63f has its CatchHandler @ 007ef668 */
  TextBox::TextBox(pTStack_14c,*(MWidget **)(param_1 + 0x278),a_Stack_1dc,0,0x41);
  *(TextBox **)(param_1 + 0x284) = pTStack_14c;
  if (*(int *)(param_1 + 0x284) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x689);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x284) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x284) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x4c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x50) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x54) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x58) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar6 = GetRcEngine::RcGetColor(0x29);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x284) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x284);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x284) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x278) + 0x34))
            (*(undefined4 *)(param_1 + 0x278),*(undefined4 *)(param_1 + 0x284));
  lVar2 = GetRcEngine::RcGetNum(0x332);
  lVar3 = GetRcEngine::RcGetNum(0x333);
  lVar4 = GetRcEngine::RcGetNum(0x331);
  lVar5 = GetRcEngine::RcGetNum(0x330);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_150 = operator_new(0x264);
                    /* try { // try from 007efb58 to 007efb5f has its CatchHandler @ 007efb88 */
  AbsContainer::AbsContainer(pAStack_150,*(MWidget **)(param_1 + 0x278),a_Stack_1dc,0,0x42);
  *(AbsContainer **)(param_1 + 0x288) = pAStack_150;
  if (*(int *)(param_1 + 0x288) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x6ab);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x288) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x288);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x288) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x288) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x288) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x288) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x278) + 0x34))
            (*(undefined4 *)(param_1 + 0x278),*(undefined4 *)(param_1 + 0x288));
  lVar2 = GetRcEngine::RcGetNum(0x33f);
  lVar3 = GetRcEngine::RcGetNum(0x340);
  lVar4 = GetRcEngine::RcGetNum(0x33e);
  lVar5 = GetRcEngine::RcGetNum(0x33d);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_154 = operator_new(0x264);
                    /* try { // try from 007efe78 to 007efe7f has its CatchHandler @ 007efea8 */
  AbsContainer::AbsContainer(pAStack_154,*(MWidget **)(param_1 + 0x194),a_Stack_1dc,0,0x43);
  *(AbsContainer **)(param_1 + 0x28c) = pAStack_154;
  if (*(int *)(param_1 + 0x28c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x6bb);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x28c) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x28c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x28c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x28c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x28c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x28c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x28c));
  lVar2 = GetRcEngine::RcGetNum(0x343);
  lVar3 = GetRcEngine::RcGetNum(0x344);
  lVar4 = GetRcEngine::RcGetNum(0x342);
  lVar5 = GetRcEngine::RcGetNum(0x341);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_158 = operator_new(0x264);
                    /* try { // try from 007f0194 to 007f019b has its CatchHandler @ 007f01c4 */
  AbsContainer::AbsContainer(pAStack_158,*(MWidget **)(param_1 + 0x194),a_Stack_1dc,0,0x44);
  *(AbsContainer **)(param_1 + 0x290) = pAStack_158;
  if (*(int *)(param_1 + 0x290) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x6cb);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x290) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x290);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x290) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x290) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x290) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x290) + 0xf4);
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x290),2,0);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x290));
  lVar2 = GetRcEngine::RcGetNum(0x33a);
  lVar3 = GetRcEngine::RcGetNum(0x33b);
  lVar4 = GetRcEngine::RcGetNum(0x339);
  lVar5 = GetRcEngine::RcGetNum(0x338);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_15c = operator_new(0x264);
                    /* try { // try from 007f04d4 to 007f04db has its CatchHandler @ 007f0504 */
  AbsContainer::AbsContainer(pAStack_15c,*(MWidget **)(param_1 + 0x28c),a_Stack_1dc,0,0x45);
  *(AbsContainer **)(param_1 + 0x294) = pAStack_15c;
  if (*(int *)(param_1 + 0x294) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x6dc);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x294) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x294);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x294) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x294) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x294) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x294) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x28c) + 0x34))
            (*(undefined4 *)(param_1 + 0x28c),*(undefined4 *)(param_1 + 0x294));
  lVar2 = GetRcEngine::RcGetNum(0x402);
  lVar3 = GetRcEngine::RcGetNum(0x403);
  lVar4 = GetRcEngine::RcGetNum(0x401);
  lVar5 = GetRcEngine::RcGetNum(0x400);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_160 = operator_new(0x250);
                    /* try { // try from 007f07f4 to 007f07fb has its CatchHandler @ 007f0824 */
  TextBox::TextBox(pTStack_160,*(MWidget **)(param_1 + 0x28c),a_Stack_1dc,0,0x46);
  *(TextBox **)(param_1 + 0x298) = pTStack_160;
  if (*(int *)(param_1 + 0x298) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x6ec);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x298) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x298) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x298) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x298) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x298) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x298) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x298) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x298) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x298) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x298) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x298);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x28c) + 0x34))
            (*(undefined4 *)(param_1 + 0x28c),*(undefined4 *)(param_1 + 0x298));
  lVar2 = GetRcEngine::RcGetNum(0x336);
  lVar3 = GetRcEngine::RcGetNum(0x337);
  lVar4 = GetRcEngine::RcGetNum(0x335);
  lVar5 = GetRcEngine::RcGetNum(0x334);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pAStack_164 = operator_new(0x264);
                    /* try { // try from 007f0c24 to 007f0c2b has its CatchHandler @ 007f0c54 */
  AbsContainer::AbsContainer(pAStack_164,*(MWidget **)(param_1 + 0x290),a_Stack_1dc,0,0x47);
  *(AbsContainer **)(param_1 + 0x29c) = pAStack_164;
  if (*(int *)(param_1 + 0x29c) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x706);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x29c) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x29c);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x29c) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x29c) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x29c) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x29c) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x290) + 0x34))
            (*(undefined4 *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x29c));
  lVar2 = GetRcEngine::RcGetNum(0x3fe);
  lVar3 = GetRcEngine::RcGetNum(0x3ff);
  lVar4 = GetRcEngine::RcGetNum(0x3fd);
  lVar5 = GetRcEngine::RcGetNum(0x3fc);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_168 = operator_new(0x250);
                    /* try { // try from 007f0f44 to 007f0f4b has its CatchHandler @ 007f0f74 */
  TextBox::TextBox(pTStack_168,*(MWidget **)(param_1 + 0x290),a_Stack_1dc,0,0x48);
  *(TextBox **)(param_1 + 0x2a0) = pTStack_168;
  if (*(int *)(param_1 + 0x2a0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x716);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2a0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2a0) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2a0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a0) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x3210);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a0);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x290) + 0x34))
            (*(undefined4 *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x2a0));
  lVar2 = GetRcEngine::RcGetNum(0x3ae);
  lVar3 = GetRcEngine::RcGetNum(0x3af);
  lVar4 = GetRcEngine::RcGetNum(0x3ad);
  lVar5 = GetRcEngine::RcGetNum(0x3ac);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pTStack_16c = operator_new(0x250);
                    /* try { // try from 007f1374 to 007f137b has its CatchHandler @ 007f13a4 */
  TextBox::TextBox(pTStack_16c,*(MWidget **)(param_1 + 0x198),a_Stack_1dc,0,0x49);
  *(TextBox **)(param_1 + 0x2a4) = pTStack_16c;
  if (*(int *)(param_1 + 0x2a4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x730);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2a4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2a4) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x2a4) + 0x38) = 0;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2a4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2a4) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x2a4));
  lVar2 = GetRcEngine::RcGetNum(0x39e);
  lVar3 = GetRcEngine::RcGetNum(0x39f);
  lVar4 = GetRcEngine::RcGetNum(0x39d);
  lVar5 = GetRcEngine::RcGetNum(0x39c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pLStack_170 = operator_new(0x294);
                    /* try { // try from 007f1794 to 007f179b has its CatchHandler @ 007f17c4 */
  ListContainer::ListContainer(pLStack_170,*(MWidget **)(param_1 + 0x198),a_Stack_1dc,0,0x4a);
  *(ListContainer **)(param_1 + 0x2a8) = pLStack_170;
  if (*(int *)(param_1 + 0x2a8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x74a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x2a8) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2a8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2a8) + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x198) + 0x34))
            (*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x2a8));
  lVar2 = GetRcEngine::RcGetNum(0x360);
  lVar3 = GetRcEngine::RcGetNum(0x361);
  lVar4 = GetRcEngine::RcGetNum(0x35f);
  lVar5 = GetRcEngine::RcGetNum(0x35c);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_174 = operator_new(0x514);
                    /* try { // try from 007f1ab0 to 007f1ab7 has its CatchHandler @ 007f1ae0 */
  ImageButton::ImageButton(pIStack_174,*(MWidget **)(param_1 + 0x2a8),a_Stack_1dc,0,0x4b);
  *(ImageButton **)(param_1 + 0x2ac) = pIStack_174;
  if (*(int *)(param_1 + 0x2ac) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x75a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2ac) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2ac) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2ac) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2ac) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2ac) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2ac) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2ac);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x128) = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 300) = 0x21;
  uVar6 = *(undefined4 *)(param_1 + 0x2ac);
  uVar7 = GetRcEngine::RcGetNum(0x35e);
  GetRcEngine::RcGetNum(0x35d);
  ImageButton::SetImgExpandProperty((uchar)uVar6,0,uVar7);
  pMStack_178 = *(MImg **)(param_1 + 0x2ac);
  MImg::MImg(aMStack_4c0,0x31);
                    /* try { // try from 007f1eb0 to 007f1eb7 has its CatchHandler @ 007f219c */
  MImg::MImg(aMStack_4d4,0x31);
                    /* try { // try from 007f1ecc to 007f1ed3 has its CatchHandler @ 007f213c */
  MImg::MImg(aMStack_4e8,0x31);
                    /* try { // try from 007f1ee8 to 007f1eef has its CatchHandler @ 007f1fb4 */
  MImg::MImg(aMStack_4fc,0x31);
                    /* try { // try from 007f1f14 to 007f1f1b has its CatchHandler @ 007f1f58 */
  ImageButton::SetImg(pMStack_178,aMStack_4c0,aMStack_4d4,aMStack_4e8);
                    /* try { // try from 007f1f2c to 007f1f33 has its CatchHandler @ 007f1fb4 */
  MImg::~MImg(aMStack_4fc);
                    /* try { // try from 007f1f44 to 007f1f4b has its CatchHandler @ 007f213c */
  MImg::~MImg(aMStack_4e8);
                    /* try { // try from 007f1fa0 to 007f1fa7 has its CatchHandler @ 007f219c */
  MImg::~MImg(aMStack_4d4);
  MImg::~MImg(aMStack_4c0);
  ImageButton::SetNonOverlap((uchar)*(undefined4 *)(param_1 + 0x2ac),'\0');
  (**(code **)(**(int **)(param_1 + 0x2a8) + 0x34))
            (*(undefined4 *)(param_1 + 0x2a8),*(undefined4 *)(param_1 + 0x2ac));
  lVar2 = GetRcEngine::RcGetNum(0x366);
  lVar3 = GetRcEngine::RcGetNum(0x367);
  lVar4 = GetRcEngine::RcGetNum(0x365);
  lVar5 = GetRcEngine::RcGetNum(0x362);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_17c = operator_new(0x514);
                    /* try { // try from 007f2128 to 007f212f has its CatchHandler @ 007f21e0 */
  ImageButton::ImageButton(pIStack_17c,*(MWidget **)(param_1 + 0x2a8),a_Stack_1dc,0,0x4c);
  *(ImageButton **)(param_1 + 0x2b0) = pIStack_17c;
  if (*(int *)(param_1 + 0x2b0) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x77a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2b0) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2b0) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b0) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b0) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b0) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b0) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b0);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 0x128) = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x2b0) + 300) = 0x21;
  uVar6 = *(undefined4 *)(param_1 + 0x2b0);
  uVar7 = GetRcEngine::RcGetNum(0x364);
  GetRcEngine::RcGetNum(0x363);
  ImageButton::SetImgExpandProperty((uchar)uVar6,0,uVar7);
  pMStack_180 = *(MImg **)(param_1 + 0x2b0);
  MImg::MImg(aMStack_510,0x32);
                    /* try { // try from 007f25b0 to 007f25b7 has its CatchHandler @ 007f289c */
  MImg::MImg(aMStack_524,0x32);
                    /* try { // try from 007f25cc to 007f25d3 has its CatchHandler @ 007f283c */
  MImg::MImg(aMStack_538,0x32);
                    /* try { // try from 007f25e8 to 007f25ef has its CatchHandler @ 007f26b4 */
  MImg::MImg(aMStack_54c,0x32);
                    /* try { // try from 007f2614 to 007f261b has its CatchHandler @ 007f2658 */
  ImageButton::SetImg(pMStack_180,aMStack_510,aMStack_524,aMStack_538);
                    /* try { // try from 007f262c to 007f2633 has its CatchHandler @ 007f26b4 */
  MImg::~MImg(aMStack_54c);
                    /* try { // try from 007f2644 to 007f264b has its CatchHandler @ 007f283c */
  MImg::~MImg(aMStack_538);
                    /* try { // try from 007f26a0 to 007f26a7 has its CatchHandler @ 007f289c */
  MImg::~MImg(aMStack_524);
  MImg::~MImg(aMStack_510);
  ImageButton::SetNonOverlap((uchar)*(undefined4 *)(param_1 + 0x2b0),'\0');
  (**(code **)(**(int **)(param_1 + 0x2a8) + 0x34))
            (*(undefined4 *)(param_1 + 0x2a8),*(undefined4 *)(param_1 + 0x2b0));
  lVar2 = GetRcEngine::RcGetNum(0x36c);
  lVar3 = GetRcEngine::RcGetNum(0x36d);
  lVar4 = GetRcEngine::RcGetNum(0x36b);
  lVar5 = GetRcEngine::RcGetNum(0x368);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_184 = operator_new(0x514);
                    /* try { // try from 007f2828 to 007f282f has its CatchHandler @ 007f28e0 */
  ImageButton::ImageButton(pIStack_184,*(MWidget **)(param_1 + 0x2a8),a_Stack_1dc,0,0x4d);
  *(ImageButton **)(param_1 + 0x2b4) = pIStack_184;
  if (*(int *)(param_1 + 0x2b4) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x79a);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2b4) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2b4) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b4) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b4) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b4) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b4) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b4);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 0x128) = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x2b4) + 300) = 0x21;
  uVar6 = *(undefined4 *)(param_1 + 0x2b4);
  uVar7 = GetRcEngine::RcGetNum(0x36a);
  GetRcEngine::RcGetNum(0x369);
  ImageButton::SetImgExpandProperty((uchar)uVar6,0,uVar7);
  pMStack_188 = *(MImg **)(param_1 + 0x2b4);
  MImg::MImg(aMStack_560,0x33);
                    /* try { // try from 007f2cb0 to 007f2cb7 has its CatchHandler @ 007f2f9c */
  MImg::MImg(aMStack_574,0x33);
                    /* try { // try from 007f2ccc to 007f2cd3 has its CatchHandler @ 007f2f3c */
  MImg::MImg(aMStack_588,0x33);
                    /* try { // try from 007f2ce8 to 007f2cef has its CatchHandler @ 007f2db4 */
  MImg::MImg(aMStack_59c,0x33);
                    /* try { // try from 007f2d14 to 007f2d1b has its CatchHandler @ 007f2d58 */
  ImageButton::SetImg(pMStack_188,aMStack_560,aMStack_574,aMStack_588);
                    /* try { // try from 007f2d2c to 007f2d33 has its CatchHandler @ 007f2db4 */
  MImg::~MImg(aMStack_59c);
                    /* try { // try from 007f2d44 to 007f2d4b has its CatchHandler @ 007f2f3c */
  MImg::~MImg(aMStack_588);
                    /* try { // try from 007f2da0 to 007f2da7 has its CatchHandler @ 007f2f9c */
  MImg::~MImg(aMStack_574);
  MImg::~MImg(aMStack_560);
  ImageButton::SetNonOverlap((uchar)*(undefined4 *)(param_1 + 0x2b4),'\0');
  (**(code **)(**(int **)(param_1 + 0x2a8) + 0x34))
            (*(undefined4 *)(param_1 + 0x2a8),*(undefined4 *)(param_1 + 0x2b4));
  lVar2 = GetRcEngine::RcGetNum(0x372);
  lVar3 = GetRcEngine::RcGetNum(0x373);
  lVar4 = GetRcEngine::RcGetNum(0x371);
  lVar5 = GetRcEngine::RcGetNum(0x36e);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pIStack_18c = operator_new(0x514);
                    /* try { // try from 007f2f28 to 007f2f2f has its CatchHandler @ 007f2fe0 */
  ImageButton::ImageButton(pIStack_18c,*(MWidget **)(param_1 + 0x2a8),a_Stack_1dc,0,0x4e);
  *(ImageButton **)(param_1 + 0x2b8) = pIStack_18c;
  if (*(int *)(param_1 + 0x2b8) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x7ba);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MString::Set((short)*(undefined4 *)(param_1 + 0x2b8) + 0x170);
  *(undefined1 *)(*(int *)(param_1 + 0x2b8) + 0x3a) = 1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar6 = GetRcEngine::RcGetColor(0x45);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar6 = GetRcEngine::RcGetColor(0x3b);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x4614);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b8) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b8) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b8) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 0x2b8) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 0x2b8);
  uVar1 = GetRcEngine::RcGetNum(0x3215);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 0x128) = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x2b8) + 300) = 0x21;
  uVar6 = *(undefined4 *)(param_1 + 0x2b8);
  uVar7 = GetRcEngine::RcGetNum(0x370);
  GetRcEngine::RcGetNum(0x36f);
  ImageButton::SetImgExpandProperty((uchar)uVar6,0,uVar7);
  pMStack_190 = *(MImg **)(param_1 + 0x2b8);
  MImg::MImg(aMStack_5b0,0x34);
                    /* try { // try from 007f33b0 to 007f33b7 has its CatchHandler @ 007f369c */
  MImg::MImg(aMStack_5c4,0x34);
                    /* try { // try from 007f33cc to 007f33d3 has its CatchHandler @ 007f363c */
  MImg::MImg(aMStack_5d8,0x34);
                    /* try { // try from 007f33e8 to 007f33ef has its CatchHandler @ 007f34b4 */
  MImg::MImg(aMStack_5ec,0x34);
                    /* try { // try from 007f3414 to 007f341b has its CatchHandler @ 007f3458 */
  ImageButton::SetImg(pMStack_190,aMStack_5b0,aMStack_5c4,aMStack_5d8);
                    /* try { // try from 007f342c to 007f3433 has its CatchHandler @ 007f34b4 */
  MImg::~MImg(aMStack_5ec);
                    /* try { // try from 007f3444 to 007f344b has its CatchHandler @ 007f363c */
  MImg::~MImg(aMStack_5d8);
                    /* try { // try from 007f34a0 to 007f34a7 has its CatchHandler @ 007f369c */
  MImg::~MImg(aMStack_5c4);
  MImg::~MImg(aMStack_5b0);
  ImageButton::SetNonOverlap((uchar)*(undefined4 *)(param_1 + 0x2b8),'\0');
  (**(code **)(**(int **)(param_1 + 0x2a8) + 0x34))
            (*(undefined4 *)(param_1 + 0x2a8),*(undefined4 *)(param_1 + 0x2b8));
  lVar2 = GetRcEngine::RcGetNum(0x3e2);
  lVar3 = GetRcEngine::RcGetNum(0x3e3);
  lVar4 = GetRcEngine::RcGetNum(0x3e1);
  lVar5 = GetRcEngine::RcGetNum(0x3e0);
  _Rect::set(a_Stack_1dc,lVar2,lVar3,lVar4,lVar5);
  pSStack_194 = operator_new(0x268);
                    /* try { // try from 007f3628 to 007f362f has its CatchHandler @ 007f36e0 */
  ScrollTextBox::ScrollTextBox(pSStack_194,*(MWidget **)(param_1 + 0x20c),a_Stack_1dc,0,0x4f);
  *(ScrollTextBox **)(param_1 + 700) = pSStack_194;
  if (*(int *)(param_1 + 700) == 0) {
    printf("UI CREATE FAIL: %s %s %d\n",&UNK_00fef388,&UNK_00fef64c,0x7e0);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  *(undefined1 *)(*(int *)(param_1 + 700) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 700) + 0x17d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 700) + 0x17e) = 1;
  *(undefined1 *)(*(int *)(param_1 + 700) + 0x39) = 0;
  iVar13 = *(int *)(param_1 + 700);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x7c) = uVar6;
  iVar13 = *(int *)(param_1 + 700);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x84) = uVar6;
  iVar13 = *(int *)(param_1 + 700);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x88) = uVar6;
  iVar13 = *(int *)(param_1 + 700);
  uVar6 = GetRcEngine::RcGetColor(0x36);
  *(undefined4 *)(iVar13 + 0x80) = uVar6;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9c) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0x9e) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa0) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f5);
  *(undefined2 *)(iVar13 + 0xa2) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa4) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x45f9);
  *(undefined2 *)(iVar13 + 0xa6) = uVar1;
  MImg::Set((short)*(undefined4 *)(param_1 + 700) + 0xb8);
  MImg::Set((short)*(undefined4 *)(param_1 + 700) + 0xcc);
  MImg::Set((short)*(undefined4 *)(param_1 + 700) + 0xe0);
  MImg::Set((short)*(undefined4 *)(param_1 + 700) + 0xf4);
  *(undefined4 *)(*(int *)(param_1 + 700) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 700) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 700) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 700) + 0x154) = 0x4ae;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x13a) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x146) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x152) = uVar1;
  iVar13 = *(int *)(param_1 + 700);
  uVar1 = GetRcEngine::RcGetNum(0x3213);
  *(undefined2 *)(iVar13 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 700) + 0x128) = 0x11;
  *(undefined1 *)(*(int *)(param_1 + 700) + 0x17e) = 1;
  (**(code **)(**(int **)(param_1 + 0x20c) + 0x34))
            (*(undefined4 *)(param_1 + 0x20c),*(undefined4 *)(param_1 + 700));
  MWidget::Hide();
  MString::MString(aMStack_1cc);
  std::allocator<char>::allocator();
                    /* try { // try from 007f3b10 to 007f3b17 has its CatchHandler @ 007f3b80 */
  std::string::string(asStack_1c0,"",aaStack_5f0);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_5f0);
                    /* try { // try from 007f3b48 to 007f3bfb has its CatchHandler @ 007f4690 */
  MString::Set((string *)aMStack_1cc);
  ScrollTextBox::SetText(*(MString **)(param_1 + 700));
  MWidget::SetFlag(*(undefined4 *)(param_1 + 0x244),2,0);
  ArProgramInfoFrame::instance = (MMainFrame *)param_1;
  pHStack_198 = operator_new(0x144);
                    /* try { // try from 007f3c18 to 007f3c1f has its CatchHandler @ 007f3c68 */
  HelpWidget::HelpWidget(pHStack_198,(MMainFrame *)param_1,(Container *)0x0);
  *(HelpWidget **)(param_1 + 0x2cc) = pHStack_198;
                    /* try { // try from 007f3c40 to 007f3c5b has its CatchHandler @ 007f4690 */
  HelpWidget::Refresh(*(HelpWidget **)(param_1 + 0x2cc));
  pTStack_19c = operator_new(0x34);
                    /* try { // try from 007f3cc0 to 007f3cc7 has its CatchHandler @ 007f3d04 */
  TimeWidget::TimeWidget(pTStack_19c,(MMainFrame *)param_1,*(Container **)(param_1 + 0x1d8));
  *(TimeWidget **)(param_1 + 0x2d0) = pTStack_19c;
                    /* try { // try from 007f3cdc to 007f432f has its CatchHandler @ 007f4690 */
  ArAudioManager::getInstance();
  iVar13 = ArAudioManager::GetDualMono();
  if (iVar13 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 500),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 500),2,1);
  }
  ArAudioManager::getInstance();
  iVar13 = ArAudioManager::GetMono();
  if (iVar13 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1fc),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1fc),2,1);
  }
  ArAudioManager::getInstance();
  iVar13 = ArAudioManager::GetStereo();
  if (iVar13 == 0) {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1f8),2,0);
  }
  else {
    MWidget::SetFlag(*(undefined4 *)(param_1 + 0x1f8),2,1);
  }
  ArTvManager::getInstance();
  iVar13 = ArTvManager::GetCurrentDvbAntennaType();
  if (iVar13 == 3) {
    ArScanManager::getInstance();
    iVar13 = ArScanManager::GetDBSatScanOperatorUIType();
    if (iVar13 != 7) {
      ArScanManager::getInstance();
      iVar13 = ArScanManager::GetDBSatScanOperatorUIType();
      if (iVar13 != 8) goto LAB_007f3f50;
    }
    iStack_1a0 = 1;
  }
  else {
LAB_007f3f50:
    iStack_1a0 = 0;
  }
  if (iStack_1a0 == 0) {
    *(undefined4 *)(param_1 + 0x2d8) = 5000;
  }
  else {
    *(undefined4 *)(param_1 + 0x2d8) = 3000;
  }
  MWnd::GetParentApp();
  puVar10 = (undefined4 *)MApplet::GetPrivateData();
  *(undefined4 *)(param_1 + 0x2c0) = *puVar10;
  param_1[0x2c8] = *(ArProgramInfoFrame *)((int)puVar10 + 5);
  ArProgramInfoFrame::EnableTimer(param_1,*(uchar *)(puVar10 + 1));
  param_1[0x2c5] = (ArProgramInfoFrame)0x1;
  param_1[0x2c4] = (ArProgramInfoFrame)0x0;
  ArProgramInfoFrame::RefreshUI(param_1,'\x01');
  this = (ArTvManager *)ArTvManager::getInstance();
  uStack_1a4 = ArTvManager::GetCurrentInputSourceType(this);
  switch(uStack_1a4) {
  case 0:
  case 1:
    MSrv_Control_common::GetMSrvSystemDatabase();
    iVar13 = MSrv_System_Database::GetFactMultiSourceFav();
    if (iVar13 == 0) {
      pMVar12 = (MEvtHandle *)MSrv_Control_TV::GetMSrvDtv(0);
      MSrv::AddEventRecipient(pMVar12);
    }
    else {
      for (bStack_608 = 0; bStack_608 < 4; bStack_608 = bStack_608 + 1) {
        iVar13 = MSrv_Control_common::GetRouteTVMode(bStack_608);
        if (iVar13 != 0) {
          piVar11 = (int *)MSrv_Control::GetInstance();
          pMVar12 = (MEvtHandle *)(**(code **)(*piVar11 + 0x1b4))(piVar11,bStack_608);
          MSrv::AddEventRecipient(pMVar12);
        }
      }
    }
    pMVar12 = (MEvtHandle *)MSrv_Control_TV::GetMSrvAtv();
    MSrv::AddEventRecipient(pMVar12);
    break;
  case 3:
    pMVar12 = (MEvtHandle *)MSrv_Control_TV::GetMSrvComp();
    MSrv::AddEventRecipient(pMVar12);
    break;
  case 5:
    pMVar12 = (MEvtHandle *)MSrv_Control_TV::GetMSrvHdmi();
    MSrv::AddEventRecipient(pMVar12);
    break;
  case 10:
    pMVar12 = (MEvtHandle *)MSrv_Control_TV::GetMSrvAv();
    MSrv::AddEventRecipient(pMVar12);
  }
  MEvtHandle::KillTimer((ulong)param_1);
  MEvtHandle::SetTimer(param_1,*(undefined4 *)(param_1 + 0x2d8),0,1);
  MWidget::Hide();
  MWidget::ShowBorder((uchar)*(undefined4 *)(param_1 + 0x198),2,0xffffffff,'\x0f','\0',2);
  psStack_1a8 = (string *)(*(int *)(param_1 + 0x2ac) + 0x170);
  uVar6 = ArChannelManager::getInstance();
  ArChannelManager::GetFavName(asStack_5f4,uVar6,0);
                    /* try { // try from 007f4344 to 007f434b has its CatchHandler @ 007f4390 */
  MString::Set(psStack_1a8);
                    /* try { // try from 007f435c to 007f4383 has its CatchHandler @ 007f4690 */
  std::string::~string(asStack_5f4);
  psStack_1ac = (string *)(*(int *)(param_1 + 0x2b0) + 0x170);
  uVar6 = ArChannelManager::getInstance();
                    /* try { // try from 007f43e0 to 007f43e7 has its CatchHandler @ 007f4690 */
  ArChannelManager::GetFavName(asStack_5f8,uVar6,1);
                    /* try { // try from 007f43fc to 007f4403 has its CatchHandler @ 007f4448 */
  MString::Set(psStack_1ac);
                    /* try { // try from 007f4414 to 007f443b has its CatchHandler @ 007f4690 */
  std::string::~string(asStack_5f8);
  psStack_1b0 = (string *)(*(int *)(param_1 + 0x2b4) + 0x170);
  uVar6 = ArChannelManager::getInstance();
                    /* try { // try from 007f4498 to 007f449f has its CatchHandler @ 007f4690 */
  ArChannelManager::GetFavName(asStack_5fc,uVar6,2);
                    /* try { // try from 007f44b4 to 007f44bb has its CatchHandler @ 007f4500 */
  MString::Set(psStack_1b0);
                    /* try { // try from 007f44cc to 007f44f3 has its CatchHandler @ 007f4690 */
  std::string::~string(asStack_5fc);
  psStack_1b4 = (string *)(*(int *)(param_1 + 0x2b8) + 0x170);
  uVar6 = ArChannelManager::getInstance();
                    /* try { // try from 007f4550 to 007f4557 has its CatchHandler @ 007f4690 */
  ArChannelManager::GetFavName(asStack_600,uVar6,3);
                    /* try { // try from 007f456c to 007f4573 has its CatchHandler @ 007f45bc */
  MString::Set(psStack_1b4);
                    /* try { // try from 007f4584 to 007f45af has its CatchHandler @ 007f4690 */
  std::string::~string(asStack_600);
  MEvtHandle::SetTimer(param_1,3000,1,0);
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 0x4d9) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x24c) + 0x893) = 0;
  param_1[0x2d5] = (ArProgramInfoFrame)0x0;
                    /* try { // try from 007f4624 to 007f462b has its CatchHandler @ 007f4690 */
  ArProgramInfoFrame::ResumeIR(param_1,'\0');
  uStack_1b8 = 0;
                    /* try { // try from 007f4640 to 007f4647 has its CatchHandler @ 007f46cc */
  std::string::~string(asStack_1c0);
  MString::~MString(aMStack_1cc);
  return uStack_1b8;
}

