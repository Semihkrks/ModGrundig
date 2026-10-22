
undefined4 FUN_00d9e300(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  uint uStack_8d8;
  undefined1 auStack_8cc [20];
  undefined1 auStack_8b8 [20];
  undefined1 auStack_8a4 [20];
  undefined1 auStack_890 [20];
  undefined1 auStack_87c [20];
  undefined1 auStack_868 [20];
  undefined1 auStack_854 [20];
  undefined1 auStack_840 [20];
  undefined1 auStack_82c [20];
  undefined1 auStack_818 [20];
  undefined1 auStack_804 [20];
  undefined1 auStack_7f0 [20];
  undefined1 auStack_7dc [20];
  undefined1 auStack_7c8 [20];
  undefined1 auStack_7b4 [20];
  undefined1 auStack_7a0 [20];
  undefined1 auStack_78c [20];
  undefined1 auStack_778 [20];
  undefined1 auStack_764 [20];
  undefined1 auStack_750 [20];
  undefined1 auStack_73c [20];
  undefined1 auStack_728 [20];
  undefined1 auStack_714 [20];
  undefined1 auStack_700 [20];
  undefined1 auStack_6ec [20];
  undefined1 auStack_6d8 [20];
  undefined1 auStack_6c4 [20];
  undefined1 auStack_6b0 [20];
  undefined1 auStack_69c [20];
  undefined1 auStack_688 [20];
  undefined1 auStack_674 [20];
  undefined1 auStack_660 [20];
  undefined1 auStack_64c [20];
  undefined1 auStack_638 [20];
  undefined1 auStack_624 [20];
  undefined1 auStack_610 [20];
  undefined1 auStack_5fc [20];
  undefined1 auStack_5e8 [20];
  undefined1 auStack_5d4 [20];
  undefined1 auStack_5c0 [20];
  undefined1 auStack_5ac [20];
  undefined1 auStack_598 [20];
  undefined1 auStack_584 [20];
  undefined1 auStack_570 [20];
  undefined1 auStack_55c [20];
  undefined1 auStack_548 [20];
  undefined1 auStack_534 [20];
  undefined1 auStack_520 [20];
  undefined1 auStack_50c [20];
  undefined1 auStack_4f8 [20];
  undefined1 auStack_4e4 [20];
  undefined1 auStack_4d0 [20];
  undefined1 auStack_4bc [20];
  undefined1 auStack_4a8 [20];
  undefined1 auStack_494 [20];
  undefined1 auStack_480 [20];
  undefined1 auStack_46c [20];
  undefined1 auStack_458 [20];
  undefined1 auStack_444 [20];
  undefined1 auStack_430 [20];
  undefined1 auStack_41c [20];
  undefined1 auStack_408 [20];
  undefined1 auStack_3f4 [20];
  undefined1 auStack_3e0 [20];
  undefined1 auStack_3cc [20];
  undefined1 auStack_3b8 [20];
  undefined1 auStack_3a4 [20];
  undefined1 auStack_390 [20];
  undefined1 auStack_37c [16];
  undefined4 uStack_36c;
  undefined1 auStack_368 [4];
  int iStack_364;
  uint auStack_338 [156];
  int iStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  uint uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a1);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a2);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a0);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359f);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_24 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00d9e3fc to 00d9e403 has its CatchHandler @ 00d9e42c */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_24,*(undefined4 *)(param_1 + 0x38),auStack_37c,0,0);
  *(undefined4 *)(param_1 + 0x180) = uStack_24;
  if (*(int *)(param_1 + 0x180) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x7f);
    (*(code *)PTR_abort_010cc6c0)();
  }
  iVar8 = *(int *)(param_1 + 0x180);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x4c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x50) = uVar3;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x54) = uVar3;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x58) = uVar3;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xb8,0x391);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xcc,0x391);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xe0,0x391);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xf4,0x391);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3599);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359a);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3598);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3597);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_28 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00d9e78c to 00d9e793 has its CatchHandler @ 00d9e7bc */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_28,*(undefined4 *)(param_1 + 0x38),auStack_37c,0,1);
  *(undefined4 *)(param_1 + 0x184) = uStack_28;
  if (*(int *)(param_1 + 0x184) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x92);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xe);
  *(undefined4 *)(iVar8 + 0x4c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xe);
  *(undefined4 *)(iVar8 + 0x50) = uVar3;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xe);
  *(undefined4 *)(iVar8 + 0x54) = uVar3;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xe);
  *(undefined4 *)(iVar8 + 0x58) = uVar3;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xb8,0x24e);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xcc,0x24e);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xe0,0x24e);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xf4,0x24e);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x184));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e7);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e8);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e6);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e5);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_2c = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00d9eb38 to 00d9eb3f has its CatchHandler @ 00d9eb68 */
  (*(code *)PTR_TextBox_010c8c40)(uStack_2c,*(undefined4 *)(param_1 + 0x180),auStack_37c,0,2);
  *(undefined4 *)(param_1 + 0x188) = uStack_2c;
  if (*(int *)(param_1 + 0x188) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0xa7);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x188) + 0x170,0xd38);
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x80) = uVar3;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x84) = uVar3;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x88) = uVar3;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45ea);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xb8,0x1eb);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xcc,0x1eb);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xe0,0x1eb);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xf4,0x1eb);
  *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x188) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x188));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359d);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359e);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359c);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x359b);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_30 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00d9efcc to 00d9efd3 has its CatchHandler @ 00d9effc */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_30,*(undefined4 *)(param_1 + 0x180),auStack_37c,0,3);
  *(undefined4 *)(param_1 + 0x18c) = uStack_30;
  if (*(int *)(param_1 + 0x18c) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0xc4);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xe0,0x1e7);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x18c));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e3);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e4);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e2);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e1);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_34 = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00d9f2ec to 00d9f2f3 has its CatchHandler @ 00d9f31c */
  (*(code *)PTR_TextBox_010c8c40)(uStack_34,*(undefined4 *)(param_1 + 0x180),auStack_37c,0,4);
  *(undefined4 *)(param_1 + 400) = uStack_34;
  if (*(int *)(param_1 + 400) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0xd4);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 400) + 0x170,0x11ab);
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 400);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 400);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x80) = uVar3;
  iVar8 = *(int *)(param_1 + 400);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x84) = uVar3;
  iVar8 = *(int *)(param_1 + 400);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x88) = uVar3;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 400) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 400) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 400) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 400) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3212);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3212);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3212);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 400);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3212);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 400));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d3);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d4);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d2);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d1);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_38 = (*(code *)PTR_operator_new_010c9890)(0xbf8);
                    /* try { // try from 00d9f788 to 00d9f78f has its CatchHandler @ 00d9f7b8 */
  (*(code *)PTR_ScrollListContainer_010c62b4)
            (uStack_38,*(undefined4 *)(param_1 + 0x180),auStack_37c,0,5);
  *(undefined4 *)(param_1 + 0x194) = uStack_38;
  if (*(int *)(param_1 + 0x194) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0xf2);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x39) = 0;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xf4,0x5cd);
  (*(code *)PTR_SetScrollBarWidth_010c6808)(*(undefined4 *)(param_1 + 0x194),0);
  (*(code *)PTR_SetScrollBarWindSize_010c9af0)(*(undefined4 *)(param_1 + 0x194),5);
  uStack_3c = *(undefined4 *)(param_1 + 0x194);
  (*(code *)PTR_MImg_010c7d68)(auStack_390,0x5cd);
                    /* try { // try from 00d9fa1c to 00d9fa23 has its CatchHandler @ 00d9fc20 */
  (*(code *)PTR_MImg_010c7d68)(auStack_3a4,0x5cd);
                    /* try { // try from 00d9fa38 to 00d9fa3f has its CatchHandler @ 00d9fbc0 */
  (*(code *)PTR_MImg_010c7d68)(auStack_3b8,0x5cd);
                    /* try { // try from 00d9fa54 to 00d9fa5b has its CatchHandler @ 00d9fb20 */
  (*(code *)PTR_MImg_010c7d68)(auStack_3cc,0x5cd);
                    /* try { // try from 00d9fa80 to 00d9fa87 has its CatchHandler @ 00d9fac4 */
  (*(code *)PTR_SetScrollbarImage_010c4b48)
            (uStack_3c,auStack_390,auStack_3a4,auStack_3b8,auStack_3cc);
                    /* try { // try from 00d9fa98 to 00d9fa9f has its CatchHandler @ 00d9fb20 */
  (*(code *)PTR__MImg_010c8444)(auStack_3cc);
                    /* try { // try from 00d9fab0 to 00d9fab7 has its CatchHandler @ 00d9fbc0 */
  (*(code *)PTR__MImg_010c8444)(auStack_3b8);
                    /* try { // try from 00d9fb0c to 00d9fb13 has its CatchHandler @ 00d9fc20 */
  (*(code *)PTR__MImg_010c8444)(auStack_3a4);
  (*(code *)PTR__MImg_010c8444)(auStack_390);
  uStack_40 = *(undefined4 *)(param_1 + 0x194);
  (*(code *)PTR_MImg_010c7d68)(auStack_3e0,0x5cd);
                    /* try { // try from 00d9fbac to 00d9fbb3 has its CatchHandler @ 00d9fe40 */
  (*(code *)PTR_MImg_010c7d68)(auStack_3f4,0x5cd);
                    /* try { // try from 00d9fc0c to 00d9fc13 has its CatchHandler @ 00d9fde0 */
  (*(code *)PTR_MImg_010c7d68)(auStack_408,0x5cd);
                    /* try { // try from 00d9fc74 to 00d9fc7b has its CatchHandler @ 00d9fd40 */
  (*(code *)PTR_MImg_010c7d68)(auStack_41c,0x5cd);
                    /* try { // try from 00d9fca0 to 00d9fca7 has its CatchHandler @ 00d9fce4 */
  (*(code *)PTR_SetScrollbarUpImage_010c7e94)
            (uStack_40,auStack_3e0,auStack_3f4,auStack_408,auStack_41c);
                    /* try { // try from 00d9fcb8 to 00d9fcbf has its CatchHandler @ 00d9fd40 */
  (*(code *)PTR__MImg_010c8444)(auStack_41c);
                    /* try { // try from 00d9fcd0 to 00d9fcd7 has its CatchHandler @ 00d9fde0 */
  (*(code *)PTR__MImg_010c8444)(auStack_408);
                    /* try { // try from 00d9fd2c to 00d9fd33 has its CatchHandler @ 00d9fe40 */
  (*(code *)PTR__MImg_010c8444)(auStack_3f4);
  (*(code *)PTR__MImg_010c8444)(auStack_3e0);
  uStack_44 = *(undefined4 *)(param_1 + 0x194);
  (*(code *)PTR_MImg_010c7d68)(auStack_430,0x5cd);
                    /* try { // try from 00d9fdcc to 00d9fdd3 has its CatchHandler @ 00da0060 */
  (*(code *)PTR_MImg_010c7d68)(auStack_444,0x5cd);
                    /* try { // try from 00d9fe2c to 00d9fe33 has its CatchHandler @ 00da0000 */
  (*(code *)PTR_MImg_010c7d68)(auStack_458,0x5cd);
                    /* try { // try from 00d9fe94 to 00d9fe9b has its CatchHandler @ 00d9ff60 */
  (*(code *)PTR_MImg_010c7d68)(auStack_46c,0x5cd);
                    /* try { // try from 00d9fec0 to 00d9fec7 has its CatchHandler @ 00d9ff04 */
  (*(code *)PTR_SetScrollbarMiddleImage_010cab3c)
            (uStack_44,auStack_430,auStack_444,auStack_458,auStack_46c);
                    /* try { // try from 00d9fed8 to 00d9fedf has its CatchHandler @ 00d9ff60 */
  (*(code *)PTR__MImg_010c8444)(auStack_46c);
                    /* try { // try from 00d9fef0 to 00d9fef7 has its CatchHandler @ 00da0000 */
  (*(code *)PTR__MImg_010c8444)(auStack_458);
                    /* try { // try from 00d9ff4c to 00d9ff53 has its CatchHandler @ 00da0060 */
  (*(code *)PTR__MImg_010c8444)(auStack_444);
  (*(code *)PTR__MImg_010c8444)(auStack_430);
  uStack_48 = *(undefined4 *)(param_1 + 0x194);
  (*(code *)PTR_MImg_010c7d68)(auStack_480,0x5cd);
                    /* try { // try from 00d9ffec to 00d9fff3 has its CatchHandler @ 00da0368 */
  (*(code *)PTR_MImg_010c7d68)(auStack_494,0x5cd);
                    /* try { // try from 00da004c to 00da0053 has its CatchHandler @ 00da0308 */
  (*(code *)PTR_MImg_010c7d68)(auStack_4a8,0x5cd);
                    /* try { // try from 00da00b4 to 00da00bb has its CatchHandler @ 00da0180 */
  (*(code *)PTR_MImg_010c7d68)(auStack_4bc,0x5cd);
                    /* try { // try from 00da00e0 to 00da00e7 has its CatchHandler @ 00da0124 */
  (*(code *)PTR_SetScrollbarBottomImage_010c775c)
            (uStack_48,auStack_480,auStack_494,auStack_4a8,auStack_4bc);
                    /* try { // try from 00da00f8 to 00da00ff has its CatchHandler @ 00da0180 */
  (*(code *)PTR__MImg_010c8444)(auStack_4bc);
                    /* try { // try from 00da0110 to 00da0117 has its CatchHandler @ 00da0308 */
  (*(code *)PTR__MImg_010c8444)(auStack_4a8);
                    /* try { // try from 00da016c to 00da0173 has its CatchHandler @ 00da0368 */
  (*(code *)PTR__MImg_010c8444)(auStack_494);
  (*(code *)PTR__MImg_010c8444)(auStack_480);
  (*(code *)PTR_SetDirection_010c7ef4)(*(undefined4 *)(param_1 + 0x194),1);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x194));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35df);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e0);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35de);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35dd);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_4c = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00da02f4 to 00da02fb has its CatchHandler @ 00da03ac */
  (*(code *)PTR_TextBox_010c8c40)(uStack_4c,*(undefined4 *)(param_1 + 0x18c),auStack_37c,0,6);
  *(undefined4 *)(param_1 + 0x198) = uStack_4c;
  if (*(int *)(param_1 + 0x198) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x109);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x198) + 0x170,0xee1);
  *(undefined1 *)(*(int *)(param_1 + 0x198) + 0x39) = 0;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x80) = uVar3;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x84) = uVar3;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x88) = uVar3;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x198) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x198));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35db);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35dc);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35da);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d9);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_50 = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00da080c to 00da0813 has its CatchHandler @ 00da083c */
  (*(code *)PTR_TextBox_010c8c40)(uStack_50,*(undefined4 *)(param_1 + 0x18c),auStack_37c,0,7);
  *(undefined4 *)(param_1 + 0x19c) = uStack_50;
  if (*(int *)(param_1 + 0x19c) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x126);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x19c) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x39) = 0;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x80) = uVar3;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x84) = uVar3;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x88) = uVar3;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x19c) + 0x128) = 0x24;
  (**(code **)(**(int **)(param_1 + 0x18c) + 0x34))
            (*(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x19c));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a7);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a8);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a6);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a3);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_54 = (*(code *)PTR_operator_new_010c9890)(0x514);
                    /* try { // try from 00da0cac to 00da0cb3 has its CatchHandler @ 00da0cdc */
  (*(code *)PTR_ImageButton_010c9ccc)(uStack_54,*(undefined4 *)(param_1 + 0x194),auStack_37c,0,8);
  *(undefined4 *)(param_1 + 0x1a0) = uStack_54;
  if (*(int *)(param_1 + 0x1a0) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x144);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1a0) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x1a0) + 0x1a3) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1a0) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xb8,0x251);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xcc,0x796);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xe0,0x227);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xf4,0x796);
  *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  uVar5 = *(undefined4 *)(param_1 + 0x1a0);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a5);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a4);
  (*(code *)PTR_SetImgExpandProperty_010c84f4)(uVar5,0,uVar3,uVar4);
  uStack_58 = *(undefined4 *)(param_1 + 0x1a0);
  (*(code *)PTR_MImg_010c7d68)(auStack_4d0,0x279);
                    /* try { // try from 00da1058 to 00da105f has its CatchHandler @ 00da1324 */
  (*(code *)PTR_MImg_010c7d68)(auStack_4e4,0x279);
                    /* try { // try from 00da1074 to 00da107b has its CatchHandler @ 00da12c4 */
  (*(code *)PTR_MImg_010c7d68)(auStack_4f8,0x279);
                    /* try { // try from 00da1090 to 00da1097 has its CatchHandler @ 00da115c */
  (*(code *)PTR_MImg_010c7d68)(auStack_50c,0x278);
                    /* try { // try from 00da10bc to 00da10c3 has its CatchHandler @ 00da1100 */
  (*(code *)PTR_SetImg_010ca8b4)(uStack_58,auStack_4d0,auStack_4e4,auStack_4f8,auStack_50c);
                    /* try { // try from 00da10d4 to 00da10db has its CatchHandler @ 00da115c */
  (*(code *)PTR__MImg_010c8444)(auStack_50c);
                    /* try { // try from 00da10ec to 00da10f3 has its CatchHandler @ 00da12c4 */
  (*(code *)PTR__MImg_010c8444)(auStack_4f8);
                    /* try { // try from 00da1148 to 00da114f has its CatchHandler @ 00da1324 */
  (*(code *)PTR__MImg_010c8444)(auStack_4e4);
  (*(code *)PTR__MImg_010c8444)(auStack_4d0);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1a0));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ad);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ae);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ac);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35a9);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_5c = (*(code *)PTR_operator_new_010c9890)(0x514);
                    /* try { // try from 00da12b0 to 00da12b7 has its CatchHandler @ 00da1368 */
  (*(code *)PTR_ImageButton_010c9ccc)(uStack_5c,*(undefined4 *)(param_1 + 0x194),auStack_37c,0,9);
  *(undefined4 *)(param_1 + 0x1a4) = uStack_5c;
  if (*(int *)(param_1 + 0x1a4) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x160);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1a4) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x1a4) + 0x1a3) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1a4) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xb8,0x251);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xcc,0x796);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xe0,0x227);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xf4,0x796);
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a4) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  uVar5 = *(undefined4 *)(param_1 + 0x1a4);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ab);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35aa);
  (*(code *)PTR_SetImgExpandProperty_010c84f4)(uVar5,0,uVar3,uVar4);
  uStack_60 = *(undefined4 *)(param_1 + 0x1a4);
  (*(code *)PTR_MImg_010c7d68)(auStack_520,0x271);
                    /* try { // try from 00da16e4 to 00da16eb has its CatchHandler @ 00da19b0 */
  (*(code *)PTR_MImg_010c7d68)(auStack_534,0x271);
                    /* try { // try from 00da1700 to 00da1707 has its CatchHandler @ 00da1950 */
  (*(code *)PTR_MImg_010c7d68)(auStack_548,0x271);
                    /* try { // try from 00da171c to 00da1723 has its CatchHandler @ 00da17e8 */
  (*(code *)PTR_MImg_010c7d68)(auStack_55c,0x270);
                    /* try { // try from 00da1748 to 00da174f has its CatchHandler @ 00da178c */
  (*(code *)PTR_SetImg_010ca8b4)(uStack_60,auStack_520,auStack_534,auStack_548,auStack_55c);
                    /* try { // try from 00da1760 to 00da1767 has its CatchHandler @ 00da17e8 */
  (*(code *)PTR__MImg_010c8444)(auStack_55c);
                    /* try { // try from 00da1778 to 00da177f has its CatchHandler @ 00da1950 */
  (*(code *)PTR__MImg_010c8444)(auStack_548);
                    /* try { // try from 00da17d4 to 00da17db has its CatchHandler @ 00da19b0 */
  (*(code *)PTR__MImg_010c8444)(auStack_534);
  (*(code *)PTR__MImg_010c8444)(auStack_520);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1a4));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b3);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b4);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b2);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35af);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_64 = (*(code *)PTR_operator_new_010c9890)(0x514);
                    /* try { // try from 00da193c to 00da1943 has its CatchHandler @ 00da19f4 */
  (*(code *)PTR_ImageButton_010c9ccc)(uStack_64,*(undefined4 *)(param_1 + 0x194),auStack_37c,0,10);
  *(undefined4 *)(param_1 + 0x1a8) = uStack_64;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x17c);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1a8) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x1a3) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xb8,0x251);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xcc,0x796);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xe0,0x227);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xf4,0x796);
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  uVar5 = *(undefined4 *)(param_1 + 0x1a8);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b1);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b0);
  (*(code *)PTR_SetImgExpandProperty_010c84f4)(uVar5,0,uVar3,uVar4);
  uStack_68 = *(undefined4 *)(param_1 + 0x1a8);
  (*(code *)PTR_MImg_010c7d68)(auStack_570,0x275);
                    /* try { // try from 00da1d70 to 00da1d77 has its CatchHandler @ 00da203c */
  (*(code *)PTR_MImg_010c7d68)(auStack_584,0x275);
                    /* try { // try from 00da1d8c to 00da1d93 has its CatchHandler @ 00da1fdc */
  (*(code *)PTR_MImg_010c7d68)(auStack_598,0x275);
                    /* try { // try from 00da1da8 to 00da1daf has its CatchHandler @ 00da1e74 */
  (*(code *)PTR_MImg_010c7d68)(auStack_5ac,0x274);
                    /* try { // try from 00da1dd4 to 00da1ddb has its CatchHandler @ 00da1e18 */
  (*(code *)PTR_SetImg_010ca8b4)(uStack_68,auStack_570,auStack_584,auStack_598,auStack_5ac);
                    /* try { // try from 00da1dec to 00da1df3 has its CatchHandler @ 00da1e74 */
  (*(code *)PTR__MImg_010c8444)(auStack_5ac);
                    /* try { // try from 00da1e04 to 00da1e0b has its CatchHandler @ 00da1fdc */
  (*(code *)PTR__MImg_010c8444)(auStack_598);
                    /* try { // try from 00da1e60 to 00da1e67 has its CatchHandler @ 00da203c */
  (*(code *)PTR__MImg_010c8444)(auStack_584);
  (*(code *)PTR__MImg_010c8444)(auStack_570);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1a8));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b9);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ba);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b8);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b5);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_6c = (*(code *)PTR_operator_new_010c9890)(0x514);
                    /* try { // try from 00da1fc8 to 00da1fcf has its CatchHandler @ 00da2080 */
  (*(code *)PTR_ImageButton_010c9ccc)(uStack_6c,*(undefined4 *)(param_1 + 0x194),auStack_37c,0,0xb);
  *(undefined4 *)(param_1 + 0x1ac) = uStack_6c;
  if (*(int *)(param_1 + 0x1ac) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x198);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1ac) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x1a3) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x39) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xb8,0x251);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xcc,0x796);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xe0,0x227);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xf4,0x796);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  uVar5 = *(undefined4 *)(param_1 + 0x1ac);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b7);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35b6);
  (*(code *)PTR_SetImgExpandProperty_010c84f4)(uVar5,0,uVar3,uVar4);
  uStack_70 = *(undefined4 *)(param_1 + 0x1ac);
  (*(code *)PTR_MImg_010c7d68)(auStack_5c0,0x27d);
                    /* try { // try from 00da240c to 00da2413 has its CatchHandler @ 00da26d8 */
  (*(code *)PTR_MImg_010c7d68)(auStack_5d4,0x27d);
                    /* try { // try from 00da2428 to 00da242f has its CatchHandler @ 00da2678 */
  (*(code *)PTR_MImg_010c7d68)(auStack_5e8,0x27d);
                    /* try { // try from 00da2444 to 00da244b has its CatchHandler @ 00da2510 */
  (*(code *)PTR_MImg_010c7d68)(auStack_5fc,0x27c);
                    /* try { // try from 00da2470 to 00da2477 has its CatchHandler @ 00da24b4 */
  (*(code *)PTR_SetImg_010ca8b4)(uStack_70,auStack_5c0,auStack_5d4,auStack_5e8,auStack_5fc);
                    /* try { // try from 00da2488 to 00da248f has its CatchHandler @ 00da2510 */
  (*(code *)PTR__MImg_010c8444)(auStack_5fc);
                    /* try { // try from 00da24a0 to 00da24a7 has its CatchHandler @ 00da2678 */
  (*(code *)PTR__MImg_010c8444)(auStack_5e8);
                    /* try { // try from 00da24fc to 00da2503 has its CatchHandler @ 00da26d8 */
  (*(code *)PTR__MImg_010c8444)(auStack_5d4);
  (*(code *)PTR__MImg_010c8444)(auStack_5c0);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1ac));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35bf);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c0);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35be);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35bb);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_74 = (*(code *)PTR_operator_new_010c9890)(0x514);
                    /* try { // try from 00da2664 to 00da266b has its CatchHandler @ 00da271c */
  (*(code *)PTR_ImageButton_010c9ccc)(uStack_74,*(undefined4 *)(param_1 + 0x194),auStack_37c,0,0xc);
  *(undefined4 *)(param_1 + 0x1b0) = uStack_74;
  if (*(int *)(param_1 + 0x1b0) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x1b5);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1b0) + 0x170,0xb9b);
  *(undefined1 *)(*(int *)(param_1 + 0x1b0) + 0x1a3) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1b0) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xb8,0x251);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xcc,0x796);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xe0,0x227);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xf4,0x796);
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1b0) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  uVar5 = *(undefined4 *)(param_1 + 0x1b0);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35bd);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35bc);
  (*(code *)PTR_SetImgExpandProperty_010c84f4)(uVar5,0,uVar3,uVar4);
  uStack_78 = *(undefined4 *)(param_1 + 0x1b0);
  (*(code *)PTR_MImg_010c7d68)(auStack_610,0x253);
                    /* try { // try from 00da2a98 to 00da2a9f has its CatchHandler @ 00da2d74 */
  (*(code *)PTR_MImg_010c7d68)(auStack_624,0x253);
                    /* try { // try from 00da2ab4 to 00da2abb has its CatchHandler @ 00da2d14 */
  (*(code *)PTR_MImg_010c7d68)(auStack_638,0x253);
                    /* try { // try from 00da2ad0 to 00da2ad7 has its CatchHandler @ 00da2b9c */
  (*(code *)PTR_MImg_010c7d68)(auStack_64c,0x253);
                    /* try { // try from 00da2afc to 00da2b03 has its CatchHandler @ 00da2b40 */
  (*(code *)PTR_SetImg_010ca8b4)(uStack_78,auStack_610,auStack_624,auStack_638,auStack_64c);
                    /* try { // try from 00da2b14 to 00da2b1b has its CatchHandler @ 00da2b9c */
  (*(code *)PTR__MImg_010c8444)(auStack_64c);
                    /* try { // try from 00da2b2c to 00da2b33 has its CatchHandler @ 00da2d14 */
  (*(code *)PTR__MImg_010c8444)(auStack_638);
                    /* try { // try from 00da2b88 to 00da2b8f has its CatchHandler @ 00da2d74 */
  (*(code *)PTR__MImg_010c8444)(auStack_624);
  (*(code *)PTR__MImg_010c8444)(auStack_610);
  (**(code **)(**(int **)(param_1 + 0x194) + 0x34))
            (*(undefined4 *)(param_1 + 0x194),*(undefined4 *)(param_1 + 0x1b0));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35cf);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d0);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ce);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35cd);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_7c = (*(code *)PTR_operator_new_010c9890)(0x1568);
                    /* try { // try from 00da2d00 to 00da2d07 has its CatchHandler @ 00da2db8 */
  (*(code *)PTR_ScrollGridContainer_010ca5dc)
            (uStack_7c,*(undefined4 *)(param_1 + 0x184),auStack_37c,0,0xd,2,2);
  *(undefined4 *)(param_1 + 0x1b4) = uStack_7c;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x1d1);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xf4,0x5cd);
  (*(code *)PTR_SetScrollBarWidth_010c9c60)(*(undefined4 *)(param_1 + 0x1b4),1,0);
  (*(code *)PTR_SetScrollBarWidth_010c9c60)(*(undefined4 *)(param_1 + 0x1b4),0,0);
  (*(code *)PTR_SetVisiableWindSize_010c993c)(*(undefined4 *)(param_1 + 0x1b4),1,8);
  uStack_80 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_660,0x5cd);
                    /* try { // try from 00da3058 to 00da305f has its CatchHandler @ 00da325c */
  (*(code *)PTR_MImg_010c7d68)(auStack_674,0x5cd);
                    /* try { // try from 00da3074 to 00da307b has its CatchHandler @ 00da31fc */
  (*(code *)PTR_MImg_010c7d68)(auStack_688,0x5cd);
                    /* try { // try from 00da3090 to 00da3097 has its CatchHandler @ 00da315c */
  (*(code *)PTR_MImg_010c7d68)(auStack_69c,0x5cd);
                    /* try { // try from 00da30bc to 00da30c3 has its CatchHandler @ 00da3100 */
  (*(code *)PTR_SetVScrollbarImage_010c9c54)
            (uStack_80,auStack_660,auStack_674,auStack_688,auStack_69c);
                    /* try { // try from 00da30d4 to 00da30db has its CatchHandler @ 00da315c */
  (*(code *)PTR__MImg_010c8444)(auStack_69c);
                    /* try { // try from 00da30ec to 00da30f3 has its CatchHandler @ 00da31fc */
  (*(code *)PTR__MImg_010c8444)(auStack_688);
                    /* try { // try from 00da3148 to 00da314f has its CatchHandler @ 00da325c */
  (*(code *)PTR__MImg_010c8444)(auStack_674);
  (*(code *)PTR__MImg_010c8444)(auStack_660);
  uStack_84 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_6b0,0x5cd);
                    /* try { // try from 00da31e8 to 00da31ef has its CatchHandler @ 00da347c */
  (*(code *)PTR_MImg_010c7d68)(auStack_6c4,0x5cd);
                    /* try { // try from 00da3248 to 00da324f has its CatchHandler @ 00da341c */
  (*(code *)PTR_MImg_010c7d68)(auStack_6d8,0x5cd);
                    /* try { // try from 00da32b0 to 00da32b7 has its CatchHandler @ 00da337c */
  (*(code *)PTR_MImg_010c7d68)(auStack_6ec,0x5cd);
                    /* try { // try from 00da32dc to 00da32e3 has its CatchHandler @ 00da3320 */
  (*(code *)PTR_SetVScrollbarUpImage_010c59bc)
            (uStack_84,auStack_6b0,auStack_6c4,auStack_6d8,auStack_6ec);
                    /* try { // try from 00da32f4 to 00da32fb has its CatchHandler @ 00da337c */
  (*(code *)PTR__MImg_010c8444)(auStack_6ec);
                    /* try { // try from 00da330c to 00da3313 has its CatchHandler @ 00da341c */
  (*(code *)PTR__MImg_010c8444)(auStack_6d8);
                    /* try { // try from 00da3368 to 00da336f has its CatchHandler @ 00da347c */
  (*(code *)PTR__MImg_010c8444)(auStack_6c4);
  (*(code *)PTR__MImg_010c8444)(auStack_6b0);
  uStack_88 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_700,0x5cd);
                    /* try { // try from 00da3408 to 00da340f has its CatchHandler @ 00da369c */
  (*(code *)PTR_MImg_010c7d68)(auStack_714,0x5cd);
                    /* try { // try from 00da3468 to 00da346f has its CatchHandler @ 00da363c */
  (*(code *)PTR_MImg_010c7d68)(auStack_728,0x5cd);
                    /* try { // try from 00da34d0 to 00da34d7 has its CatchHandler @ 00da359c */
  (*(code *)PTR_MImg_010c7d68)(auStack_73c,0x5cd);
                    /* try { // try from 00da34fc to 00da3503 has its CatchHandler @ 00da3540 */
  (*(code *)PTR_SetVScrollbarMiddleImage_010ca758)
            (uStack_88,auStack_700,auStack_714,auStack_728,auStack_73c);
                    /* try { // try from 00da3514 to 00da351b has its CatchHandler @ 00da359c */
  (*(code *)PTR__MImg_010c8444)(auStack_73c);
                    /* try { // try from 00da352c to 00da3533 has its CatchHandler @ 00da363c */
  (*(code *)PTR__MImg_010c8444)(auStack_728);
                    /* try { // try from 00da3588 to 00da358f has its CatchHandler @ 00da369c */
  (*(code *)PTR__MImg_010c8444)(auStack_714);
  (*(code *)PTR__MImg_010c8444)(auStack_700);
  uStack_8c = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_750,0x5cd);
                    /* try { // try from 00da3628 to 00da362f has its CatchHandler @ 00da38bc */
  (*(code *)PTR_MImg_010c7d68)(auStack_764,0x5cd);
                    /* try { // try from 00da3688 to 00da368f has its CatchHandler @ 00da385c */
  (*(code *)PTR_MImg_010c7d68)(auStack_778,0x5cd);
                    /* try { // try from 00da36f0 to 00da36f7 has its CatchHandler @ 00da37bc */
  (*(code *)PTR_MImg_010c7d68)(auStack_78c,0x5cd);
                    /* try { // try from 00da371c to 00da3723 has its CatchHandler @ 00da3760 */
  (*(code *)PTR_SetVScrollbarBottomImage_010ca664)
            (uStack_8c,auStack_750,auStack_764,auStack_778,auStack_78c);
                    /* try { // try from 00da3734 to 00da373b has its CatchHandler @ 00da37bc */
  (*(code *)PTR__MImg_010c8444)(auStack_78c);
                    /* try { // try from 00da374c to 00da3753 has its CatchHandler @ 00da385c */
  (*(code *)PTR__MImg_010c8444)(auStack_778);
                    /* try { // try from 00da37a8 to 00da37af has its CatchHandler @ 00da38bc */
  (*(code *)PTR__MImg_010c8444)(auStack_764);
  (*(code *)PTR__MImg_010c8444)(auStack_750);
  uStack_90 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_7a0,0x5cd);
                    /* try { // try from 00da3848 to 00da384f has its CatchHandler @ 00da3adc */
  (*(code *)PTR_MImg_010c7d68)(auStack_7b4,0x5cd);
                    /* try { // try from 00da38a8 to 00da38af has its CatchHandler @ 00da3a7c */
  (*(code *)PTR_MImg_010c7d68)(auStack_7c8,0x5cd);
                    /* try { // try from 00da3910 to 00da3917 has its CatchHandler @ 00da39dc */
  (*(code *)PTR_MImg_010c7d68)(auStack_7dc,0x5cd);
                    /* try { // try from 00da393c to 00da3943 has its CatchHandler @ 00da3980 */
  (*(code *)PTR_SetHScrollbarImage_010c97c0)
            (uStack_90,auStack_7a0,auStack_7b4,auStack_7c8,auStack_7dc);
                    /* try { // try from 00da3954 to 00da395b has its CatchHandler @ 00da39dc */
  (*(code *)PTR__MImg_010c8444)(auStack_7dc);
                    /* try { // try from 00da396c to 00da3973 has its CatchHandler @ 00da3a7c */
  (*(code *)PTR__MImg_010c8444)(auStack_7c8);
                    /* try { // try from 00da39c8 to 00da39cf has its CatchHandler @ 00da3adc */
  (*(code *)PTR__MImg_010c8444)(auStack_7b4);
  (*(code *)PTR__MImg_010c8444)(auStack_7a0);
  uStack_94 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_7f0,0x5cd);
                    /* try { // try from 00da3a68 to 00da3a6f has its CatchHandler @ 00da3cfc */
  (*(code *)PTR_MImg_010c7d68)(auStack_804,0x5cd);
                    /* try { // try from 00da3ac8 to 00da3acf has its CatchHandler @ 00da3c9c */
  (*(code *)PTR_MImg_010c7d68)(auStack_818,0x5cd);
                    /* try { // try from 00da3b30 to 00da3b37 has its CatchHandler @ 00da3bfc */
  (*(code *)PTR_MImg_010c7d68)(auStack_82c,0x5cd);
                    /* try { // try from 00da3b5c to 00da3b63 has its CatchHandler @ 00da3ba0 */
  (*(code *)PTR_SetHScrollbarUpImage_010c9854)
            (uStack_94,auStack_7f0,auStack_804,auStack_818,auStack_82c);
                    /* try { // try from 00da3b74 to 00da3b7b has its CatchHandler @ 00da3bfc */
  (*(code *)PTR__MImg_010c8444)(auStack_82c);
                    /* try { // try from 00da3b8c to 00da3b93 has its CatchHandler @ 00da3c9c */
  (*(code *)PTR__MImg_010c8444)(auStack_818);
                    /* try { // try from 00da3be8 to 00da3bef has its CatchHandler @ 00da3cfc */
  (*(code *)PTR__MImg_010c8444)(auStack_804);
  (*(code *)PTR__MImg_010c8444)(auStack_7f0);
  uStack_98 = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_840,0x5cd);
                    /* try { // try from 00da3c88 to 00da3c8f has its CatchHandler @ 00da3f1c */
  (*(code *)PTR_MImg_010c7d68)(auStack_854,0x5cd);
                    /* try { // try from 00da3ce8 to 00da3cef has its CatchHandler @ 00da3ebc */
  (*(code *)PTR_MImg_010c7d68)(auStack_868,0x5cd);
                    /* try { // try from 00da3d50 to 00da3d57 has its CatchHandler @ 00da3e1c */
  (*(code *)PTR_MImg_010c7d68)(auStack_87c,0x5cd);
                    /* try { // try from 00da3d7c to 00da3d83 has its CatchHandler @ 00da3dc0 */
  (*(code *)PTR_SetHScrollbarMiddleImage_010c5cac)
            (uStack_98,auStack_840,auStack_854,auStack_868,auStack_87c);
                    /* try { // try from 00da3d94 to 00da3d9b has its CatchHandler @ 00da3e1c */
  (*(code *)PTR__MImg_010c8444)(auStack_87c);
                    /* try { // try from 00da3dac to 00da3db3 has its CatchHandler @ 00da3ebc */
  (*(code *)PTR__MImg_010c8444)(auStack_868);
                    /* try { // try from 00da3e08 to 00da3e0f has its CatchHandler @ 00da3f1c */
  (*(code *)PTR__MImg_010c8444)(auStack_854);
  (*(code *)PTR__MImg_010c8444)(auStack_840);
  uStack_9c = *(undefined4 *)(param_1 + 0x1b4);
  (*(code *)PTR_MImg_010c7d68)(auStack_890,0x5cd);
                    /* try { // try from 00da3ea8 to 00da3eaf has its CatchHandler @ 00da425c */
  (*(code *)PTR_MImg_010c7d68)(auStack_8a4,0x5cd);
                    /* try { // try from 00da3f08 to 00da3f0f has its CatchHandler @ 00da41fc */
  (*(code *)PTR_MImg_010c7d68)(auStack_8b8,0x5cd);
                    /* try { // try from 00da3f70 to 00da3f77 has its CatchHandler @ 00da403c */
  (*(code *)PTR_MImg_010c7d68)(auStack_8cc,0x5cd);
                    /* try { // try from 00da3f9c to 00da3fa3 has its CatchHandler @ 00da3fe0 */
  (*(code *)PTR_SetHScrollbarBottomImage_010cac38)
            (uStack_9c,auStack_890,auStack_8a4,auStack_8b8,auStack_8cc);
                    /* try { // try from 00da3fb4 to 00da3fbb has its CatchHandler @ 00da403c */
  (*(code *)PTR__MImg_010c8444)(auStack_8cc);
                    /* try { // try from 00da3fcc to 00da3fd3 has its CatchHandler @ 00da41fc */
  (*(code *)PTR__MImg_010c8444)(auStack_8b8);
                    /* try { // try from 00da4028 to 00da402f has its CatchHandler @ 00da425c */
  (*(code *)PTR__MImg_010c8444)(auStack_8a4);
  (*(code *)PTR__MImg_010c8444)(auStack_890);
  (**(code **)(**(int **)(param_1 + 0x1b4) + 0x60))(*(undefined4 *)(param_1 + 0x1b4),1,0x14);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1b4),0x10,0);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1b4));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c7);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c8);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c6);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c5);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_a0 = (*(code *)PTR_operator_new_010c9890)(0x2b4);
                    /* try { // try from 00da41e8 to 00da41ef has its CatchHandler @ 00da42a0 */
  (*(code *)PTR_Image_010cb80c)(uStack_a0,*(undefined4 *)(param_1 + 0x184),auStack_37c,0,0xe);
  *(undefined4 *)(param_1 + 0x1b8) = uStack_a0;
  if (*(int *)(param_1 + 0x1b8) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x1ef);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x260,599);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x274,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x288,599);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x29c,599);
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xf4,0x5cd);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1b8),2,0);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1b8));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c3);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c4);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c2);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c1);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_a4 = (*(code *)PTR_operator_new_010c9890)(0x2b4);
                    /* try { // try from 00da4640 to 00da4647 has its CatchHandler @ 00da4670 */
  (*(code *)PTR_Image_010cb80c)(uStack_a4,*(undefined4 *)(param_1 + 0x184),auStack_37c,0,0xf);
  *(undefined4 *)(param_1 + 0x1bc) = uStack_a4;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x204);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0x260,0x254);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0x274,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0x288,0x254);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0x29c,0x254);
  *(undefined1 *)(*(int *)(param_1 + 0x1bc) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xf4,0x5cd);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1bc),2,0);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1bc));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3595);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3596);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3594);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3593);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_a8 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00da4a10 to 00da4a17 has its CatchHandler @ 00da4a40 */
  (*(code *)PTR_AbsContainer_010c6d8c)
            (uStack_a8,*(undefined4 *)(param_1 + 0x184),auStack_37c,0,0x10);
  *(undefined4 *)(param_1 + 0x1c0) = uStack_a8;
  if (*(int *)(param_1 + 0x1c0) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x219);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1c0) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c0);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c0) + 0xb8,0x286);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c0) + 0xcc,0x286);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c0) + 0xe0,0x286);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c0) + 0xf4,0x286);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1c0),0x10,0);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1c0));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35eb);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ec);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ea);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35e9);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_ac = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00da4d5c to 00da4d63 has its CatchHandler @ 00da4d8c */
  (*(code *)PTR_TextBox_010c8c40)(uStack_ac,*(undefined4 *)(param_1 + 0x1c0),auStack_37c,0,0x11);
  *(undefined4 *)(param_1 + 0x1c4) = uStack_ac;
  if (*(int *)(param_1 + 0x1c4) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x22b);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1c4) + 0x170,0xdb0);
  *(undefined1 *)(*(int *)(param_1 + 0x1c4) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1c4) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45de);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c4) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c4) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c4) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c4) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c4) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c4);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1c4),0x10,0);
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1c4));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d7);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d8);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d6);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35d5);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_b0 = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00da51bc to 00da51c3 has its CatchHandler @ 00da51ec */
  (*(code *)PTR_TextBox_010c8c40)(uStack_b0,*(undefined4 *)(param_1 + 0x1c0),auStack_37c,0,0x12);
  *(undefined4 *)(param_1 + 0x1c8) = uStack_b0;
  if (*(int *)(param_1 + 0x1c8) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x247);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1c8) + 0x170,0xeb0);
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 0x17c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 0x39) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1c8) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x45);
  *(undefined4 *)(iVar8 + 0x7c) = uVar3;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45de);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c8) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c8) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c8) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1c8) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320e);
  *(undefined2 *)(iVar8 + 0x13a) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320e);
  *(undefined2 *)(iVar8 + 0x146) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320e);
  *(undefined2 *)(iVar8 + 0x152) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1c8);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320e);
  *(undefined2 *)(iVar8 + 0x15e) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x128) = 0x11;
  (*(code *)PTR_SetMultiline_010c5038)(*(undefined4 *)(param_1 + 0x1c8),1);
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1c8));
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35cb);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35cc);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35ca);
  uVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x35c9);
  (*(code *)PTR_set_010c9810)(auStack_37c,uVar3,uVar4,uVar5,uVar6);
  uStack_b4 = (*(code *)PTR_operator_new_010c9890)(0x2b4);
                    /* try { // try from 00da5638 to 00da563f has its CatchHandler @ 00da5668 */
  (*(code *)PTR_Image_010cb80c)(uStack_b4,*(undefined4 *)(param_1 + 0x1c0),auStack_37c,0,0x13);
  *(undefined4 *)(param_1 + 0x1cc) = uStack_b4;
  if (*(int *)(param_1 + 0x1cc) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c43ec + 0x34f4,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x36cc,0x265);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0x260,0x25b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0x274,0x25b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0x288,0x25b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0x29c,0x25b);
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar2;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1cc) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x1c0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1cc));
  (*(code *)PTR_SetCanGetFocus_010c7b18)(*(undefined4 *)(param_1 + 0x18c),1);
  (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(param_1 + 0x180));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x180));
  (*(code *)PTR_GenerateActiveListMap_010c5630)(param_1);
  uStack_b8 = (*(code *)PTR_operator_new_010c9890)(0x144);
                    /* try { // try from 00da59b4 to 00da59bb has its CatchHandler @ 00da5b64 */
  (*(code *)PTR_HelpWidget_010caa80)(uStack_b8,param_1,*(undefined4 *)(param_1 + 0x184));
  *(undefined4 *)(param_1 + 0x230) = uStack_b8;
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x1c8));
  (*(code *)PTR_CreateLayout_010cac48)(param_1,*(undefined4 *)(param_1 + 0x1b4));
  (*(code *)PTR_FillUIDataOfSources_010c9bb0)(param_1);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1bc),2,1);
  (*(code *)PTR_SetFlag_010cb13c)(*(undefined4 *)(param_1 + 0x1b8),2,1);
  (*(code *)PTR_SetInitialFocus_010c97b8)(param_1,*(undefined4 *)(param_1 + 0x1c4));
  uVar3 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetCurrentInputSourceType_010ca82c)(uVar3);
  *(undefined1 *)(param_1 + 0x22c) = uVar1;
  uVar3 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetSpecificSourceIndex_010c849c)(uVar3);
  *(undefined1 *)(param_1 + 0x22d) = uVar1;
  (*(code *)PTR_printf_010c9f10)
            (PTR_DAT_010c43ec + 0x3510,*(undefined1 *)(param_1 + 0x22c),
             *(undefined1 *)(param_1 + 0x22d));
  uStack_bc = (uint)*(byte *)(param_1 + 0x22c);
  if (uStack_bc < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0x00da5b50 */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)((int)&_gp + *(int *)(PTR_DAT_010c43ec + uStack_bc * 4 + 0x3600)))();
    return uVar3;
  }
  (*(code *)PTR_puts_010c8b64)(PTR_DAT_010c43ec + 0x3548);
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetHDMI1Available_010c5618)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x15);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetHDMI2Available_010c5230)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x16);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetHDMI3Available_010cc27c)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x17);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetHDMI4Available_010c8a70)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x18);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetScartAvailable_010c9914)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x1b);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetPcAvailable_010cce64)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x1c);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetComponentAvailable_010cbc44)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x1e);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArSourceConf_GetSvhsAvailable_010c5f40)(uVar3);
  if (iVar8 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x1a);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
  uVar3 = *(undefined4 *)(param_1 + 0x1b4);
  uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x1d);
  uVar3 = (*pcVar10)(uVar3,uVar4);
  (*(code *)PTR_Hide_010c5068)(uVar3);
  uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar8 = (*(code *)PTR_ArPanelConf_GetUrsaSelection_010c8e4c)(uVar3);
  if (iVar8 != 2) {
    uVar3 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar8 = (*(code *)PTR_ArPanelConf_GetUrsaSelection_010c8e4c)(uVar3);
    if (iVar8 != 3) {
      iStack_c0 = 0;
      goto LAB_00da61cc;
    }
  }
  iStack_c0 = 1;
LAB_00da61cc:
  if (iStack_c0 == 0) {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x19);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Hide_010c5068)(uVar3);
  }
  else {
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x19);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_Show_010cc98c)(uVar3);
  }
  pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
  uVar3 = *(undefined4 *)(param_1 + 0x1b4);
  uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)
                    (param_1,*(byte *)(param_1 + 0x22d) + 0x14);
  uVar3 = (*pcVar10)(uVar3,uVar4);
  iVar8 = (*(code *)PTR_QueryFlag_010ca574)(uVar3,2);
  if (iVar8 == 1) {
    (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,uVar3);
  }
  else {
    (*(code *)PTR_printf_010c9f10)(PTR_DAT_010c43ec + 0x356c,PTR_DAT_010c43ec + 0x3478,0x2f5);
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,0x14);
    uVar3 = (*pcVar10)(uVar3,uVar4);
    (*(code *)PTR_SwitchFocusTo_010c8c70)(param_1,uVar3);
  }
  (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x230),0xb,0xe1e);
  (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x230),7,0xf37);
  (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x230),0xe,0xc42);
  for (uStack_8d8 = 0x15; (int)uStack_8d8 < 0x1a; uStack_8d8 = uStack_8d8 + 1) {
    iVar9 = *(int *)(param_1 + 0x3c);
    pcVar10 = *(code **)(**(int **)(param_1 + 0x1b4) + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)(param_1,uStack_8d8 & 0xffff);
    iVar8 = (*pcVar10)(uVar3,uVar4);
    if (iVar9 == iVar8) {
      (*(code *)PTR_ShowButton_010cb4d4)(*(undefined4 *)(param_1 + 0x230),3,0xee1);
    }
  }
  (*(code *)PTR_Refresh_010c5b88)(*(undefined4 *)(param_1 + 0x230));
  *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(param_1 + 0x3c);
  iVar8 = (*(code *)PTR_GetAnimationEnabled_010c6370)();
  if (iVar8 != 0) {
    (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x184));
    (*(code *)PTR_PostEvent_010cabec)(param_1,param_1,0xc0000020,0,0);
  }
  (*(code *)PTR_EnableShadows_010cb568)(param_1,1);
  iStack_c8 = (*(code *)PTR_GetMSrvPicture_010c5998)();
  if (iStack_c8 == 0) {
    uStack_c4 = 0;
  }
  else {
    uStack_c4 = (*(code *)PTR___dynamic_cast_010c6984)
                          (iStack_c8,PTR_DAT_010c6490,PTR_DAT_010ccfb8,0);
  }
  (*(code *)PTR_IncreaseMenuLockCounter_010c51bc)(uStack_c4);
  piVar7 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
  uStack_36c = (**(code **)(*piVar7 + 0x84))(piVar7);
  piVar7 = (int *)(*(code *)PTR_GetMSrvSystemDatabase_010cb630)();
  (**(code **)(*piVar7 + 0x94))(piVar7,auStack_368,&uStack_36c);
  uVar3 = (*(code *)PTR_getInstance_010cab20)();
  (*(code *)PTR_SetBacklight_010c96b8)(uVar3,auStack_338[iStack_364 * 0x11] & 0xff);
  return 0;
}

