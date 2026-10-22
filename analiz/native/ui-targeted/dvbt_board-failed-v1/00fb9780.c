
undefined4 FUN_00fb9780(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uStack_fc;
  undefined1 auStack_f8 [20];
  undefined1 auStack_e4 [20];
  undefined1 auStack_d0 [20];
  undefined1 auStack_bc [20];
  undefined1 auStack_a8 [16];
  undefined1 auStack_98 [2];
  char cStack_96;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_70;
  int iStack_6c;
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
  
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a59);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5a);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a58);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a57);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_28 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fb9880 to 00fb9887 has its CatchHandler @ 00fb98b0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_28,*(undefined4 *)(param_1 + 0x38),auStack_a8,0,0);
  *(undefined4 *)(param_1 + 0x180) = uStack_28;
  if (*(int *)(param_1 + 0x180) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x1e6);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x180) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x180);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x180) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x180));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a41);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a42);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a40);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a3f);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_2c = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fb9ba0 to 00fb9ba7 has its CatchHandler @ 00fb9bd0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_2c,*(undefined4 *)(param_1 + 0x38),auStack_a8,0,1);
  *(undefined4 *)(param_1 + 0x184) = uStack_2c;
  if (*(int *)(param_1 + 0x184) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x1f6);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x184) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x184);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xb8,0x2ad);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xcc,0x2ad);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xe0,0x2ad);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xf4,0x2ad);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x184));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a48);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a49);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a47);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a46);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_30 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fb9ec0 to 00fb9ec7 has its CatchHandler @ 00fb9ef0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_30,*(undefined4 *)(param_1 + 0x38),auStack_a8,0,2);
  *(undefined4 *)(param_1 + 0x188) = uStack_30;
  if (*(int *)(param_1 + 0x188) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x206);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x188) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
            (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x188));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a64);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a65);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a63);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a52);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_34 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fba1e0 to 00fba1e7 has its CatchHandler @ 00fba210 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_34,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,3);
  *(undefined4 *)(param_1 + 0x18c) = uStack_34;
  if (*(int *)(param_1 + 0x18c) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x216);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x18c) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x18c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xb8,0x2a8);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xcc,0x2a8);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xe0,0x2a8);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x18c) + 0xf4,0x2a8);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x18c));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a55);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a56);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a54);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a53);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_38 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fba500 to 00fba507 has its CatchHandler @ 00fba530 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_38,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,4);
  *(undefined4 *)(param_1 + 400) = uStack_38;
  if (*(int *)(param_1 + 400) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x226);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 400) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 400);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xb8,0x23a);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xcc,0x23a);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xe0,0x23a);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 400) + 0xf4,0x23a);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 400));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5d);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5e);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5c);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5b);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_3c = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fba820 to 00fba827 has its CatchHandler @ 00fba850 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_3c,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,5);
  *(undefined4 *)(param_1 + 0x194) = uStack_3c;
  if (*(int *)(param_1 + 0x194) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x236);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x194) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x194);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xb8,0x23b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xcc,0x23b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xe0,0x23b);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x194) + 0xf4,0x23b);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x194));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4c);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4d);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4b);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4a);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_40 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbab40 to 00fbab47 has its CatchHandler @ 00fbab70 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_40,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,6);
  *(undefined4 *)(param_1 + 0x198) = uStack_40;
  if (*(int *)(param_1 + 0x198) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x246);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x198) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x198);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xb8,0x236);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xcc,0x236);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xe0,0x236);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x198) + 0xf4,0x236);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x198));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a61);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a62);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a60);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a5f);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_44 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbae60 to 00fbae67 has its CatchHandler @ 00fbae90 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_44,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,7);
  *(undefined4 *)(param_1 + 0x19c) = uStack_44;
  if (*(int *)(param_1 + 0x19c) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x256);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x19c) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x19c);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xb8,0x23d);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xcc,0x23d);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xe0,0x23d);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x19c) + 0xf4,0x23d);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x19c));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a50);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a51);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4f);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a4e);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_48 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbb180 to 00fbb187 has its CatchHandler @ 00fbb1b0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_48,*(undefined4 *)(param_1 + 0x180),auStack_a8,0,8);
  *(undefined4 *)(param_1 + 0x1a0) = uStack_48;
  if (*(int *)(param_1 + 0x1a0) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x266);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1a0) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xb8,0x238);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xcc,0x238);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xe0,0x238);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a0) + 0xf4,0x238);
  (**(code **)(**(int **)(param_1 + 0x180) + 0x34))
            (*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x1a0));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a44);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a45);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a43);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a3e);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_4c = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbb4a0 to 00fbb4a7 has its CatchHandler @ 00fbb4d0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_4c,*(undefined4 *)(param_1 + 0x184),auStack_a8,0,9);
  *(undefined4 *)(param_1 + 0x1a4) = uStack_4c;
  if (*(int *)(param_1 + 0x1a4) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x276);
    (*(code *)PTR_abort_010cc6c0)();
  }
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x4c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x50) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x54) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x58) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xb8,0x2a2);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xcc,0x2a2);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xe0,0x2a2);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a4) + 0xf4,0x2a2);
  (**(code **)(**(int **)(param_1 + 0x184) + 0x34))
            (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x1a4));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a68);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a69);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a67);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a66);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_50 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbb830 to 00fbb837 has its CatchHandler @ 00fbb860 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_50,*(undefined4 *)(param_1 + 0x1a4),auStack_a8,0,10);
  *(undefined4 *)(param_1 + 0x1a8) = uStack_50;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x289);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1a8) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f5);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1a8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xb8,0x2aa);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xcc,0x2aa);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xe0,0x2aa);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1a8) + 0xf4,0x2aa);
  (**(code **)(**(int **)(param_1 + 0x1a4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1a8));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a78);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a79);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a77);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a76);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_54 = (*(code *)PTR_operator_new_010c9890)(0x250);
                    /* try { // try from 00fbbb50 to 00fbbb57 has its CatchHandler @ 00fbbb80 */
  (*(code *)PTR_TextBox_010c8c40)(uStack_54,*(undefined4 *)(param_1 + 0x1a4),auStack_a8,0,0xb);
  *(undefined4 *)(param_1 + 0x1ac) = uStack_54;
  if (*(int *)(param_1 + 0x1ac) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x299);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010c61fc)(*(int *)(param_1 + 0x1ac) + 0x170,0x281);
  *(undefined1 *)(*(int *)(param_1 + 0x1ac) + 0x39) = 0;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  *(undefined4 *)(iVar8 + 0x7c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  *(undefined4 *)(iVar8 + 0x80) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  *(undefined4 *)(iVar8 + 0x84) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  *(undefined4 *)(iVar8 + 0x88) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1ac) + 0xf4,0x5cd);
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x154) = 0x4ae;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x13a) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x146) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x152) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1ac);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3215);
  *(undefined2 *)(iVar8 + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + 0x128) = 0x22;
  (**(code **)(**(int **)(param_1 + 0x1a4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1ac));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6c);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6d);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6b);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_58 = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbbff0 to 00fbbff7 has its CatchHandler @ 00fbc020 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_58,*(undefined4 *)(param_1 + 0x1a4),auStack_a8,0,0xc);
  *(undefined4 *)(param_1 + 0x1b0) = uStack_58;
  if (*(int *)(param_1 + 0x1b0) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x2b7);
    (*(code *)PTR_abort_010cc6c0)();
  }
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x4c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x50) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x54) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
  *(undefined4 *)(iVar8 + 0x58) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b0);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b0) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x1a4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1b0));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a70);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a71);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6f);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6e);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_5c = (*(code *)PTR_operator_new_010c9890)(0x264);
                    /* try { // try from 00fbc380 to 00fbc387 has its CatchHandler @ 00fbc3b0 */
  (*(code *)PTR_AbsContainer_010c6d8c)(uStack_5c,*(undefined4 *)(param_1 + 0x1a4),auStack_a8,0,0xd);
  *(undefined4 *)(param_1 + 0x1b4) = uStack_5c;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x2ca);
    (*(code *)PTR_abort_010cc6c0)();
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1b4) + 0x3a) = 1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b4);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xb8,0x2a9);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xcc,0x2a9);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xe0,0x2a9);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b4) + 0xf4,0x2a9);
  (**(code **)(**(int **)(param_1 + 0x1a4) + 0x34))
            (*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1b4));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a74);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a75);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a73);
  uVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a72);
  (*(code *)PTR_set_010c9810)(auStack_a8,uVar2,uVar3,uVar4,uVar5);
  uStack_60 = (*(code *)PTR_operator_new_010c9890)(0x2b4);
                    /* try { // try from 00fbc6a0 to 00fbc6a7 has its CatchHandler @ 00fbc6d0 */
  (*(code *)PTR_Image_010cb80c)(uStack_60,*(undefined4 *)(param_1 + 0x188),auStack_a8,0,0xe);
  *(undefined4 *)(param_1 + 0x1b8) = uStack_60;
  if (*(int *)(param_1 + 0x1b8) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x2da);
    (*(code *)PTR_abort_010cc6c0)();
  }
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x260,4);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x274,4);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x288,4);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0x29c,4);
  *(undefined1 *)(*(int *)(param_1 + 0x1b8) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1b8);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1b8) + 0xf4,0x5cd);
  (**(code **)(**(int **)(param_1 + 0x188) + 0x34))
            (*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x1b8));
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6b);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
  (*(code *)PTR_set_010c9810)(auStack_a8,0,0,uVar2,uVar3);
  uStack_64 = (*(code *)PTR_operator_new_010c9890)(0x4c8);
                    /* try { // try from 00fbca1c to 00fbca23 has its CatchHandler @ 00fbca4c */
  (*(code *)PTR_ProgressBar_010ca03c)(uStack_64,*(undefined4 *)(param_1 + 0x1b0),auStack_a8,0,0xf);
  *(undefined4 *)(param_1 + 0x1bc) = uStack_64;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    (*(code *)PTR_printf_010c9f10)
              (PTR_DAT_010c4460 + -0x3488,PTR_DAT_010c4460 + -0x34ac,PTR_DAT_010c4460 + -0x3438,
               0x2f3);
    (*(code *)PTR_abort_010cc6c0)();
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0);
  *(undefined4 *)(iVar8 + 0x7c) = uVar2;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0);
  *(undefined4 *)(iVar8 + 0x80) = uVar2;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0);
  *(undefined4 *)(iVar8 + 0x84) = uVar2;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0);
  *(undefined4 *)(iVar8 + 0x88) = uVar2;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1bc) + 0x254) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1bc) + 0x254) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1bc) + 0x254) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1bc) + 0x254) + 0x154) = 0x4ae;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320c);
  *(undefined2 *)(iVar8 + 0x13a) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320c);
  *(undefined2 *)(iVar8 + 0x146) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320c);
  *(undefined2 *)(iVar8 + 0x152) = uVar1;
  iVar8 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x254);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x320c);
  *(undefined2 *)(iVar8 + 0x15e) = uVar1;
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x254));
  *(undefined1 *)(*(int *)(param_1 + 0x1bc) + 0x38) = 0;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x24);
  *(undefined4 *)(iVar8 + 0x4c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x24);
  *(undefined4 *)(iVar8 + 0x50) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x24);
  *(undefined4 *)(iVar8 + 0x54) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x24);
  *(undefined4 *)(iVar8 + 0x58) = uVar2;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9c) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0x9e) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa0) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa2) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa4) = uVar1;
  iVar8 = *(int *)(param_1 + 0x1bc);
  uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
  *(undefined2 *)(iVar8 + 0xa6) = uVar1;
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x1bc) + 0xf4,0x5cd);
  (*(code *)PTR_SetCurValue_010caa64)(*(undefined4 *)(param_1 + 0x1bc),0);
  (*(code *)PTR_SetBarSlice_010c63d8)(*(undefined4 *)(param_1 + 0x1bc),8);
  (*(code *)PTR_SetBarStyle_010c9c2c)(*(undefined4 *)(param_1 + 0x1bc),0);
  uStack_68 = *(undefined4 *)(param_1 + 0x1bc);
  (*(code *)PTR_MImg_010c7d68)(auStack_bc,0x5cd);
                    /* try { // try from 00fbcfe0 to 00fbcfe7 has its CatchHandler @ 00fbd518 */
  (*(code *)PTR_MImg_010c7d68)(auStack_d0,0x5cd);
                    /* try { // try from 00fbcffc to 00fbd003 has its CatchHandler @ 00fbd4dc */
  (*(code *)PTR_MImg_010c7d68)(auStack_e4,0x5cd);
                    /* try { // try from 00fbd018 to 00fbd01f has its CatchHandler @ 00fbd0ec */
  (*(code *)PTR_MImg_010c7d68)(auStack_f8,0x5cd);
                    /* try { // try from 00fbd04c to 00fbd053 has its CatchHandler @ 00fbd090 */
  (*(code *)PTR_SetBarImg_010c4a48)(uStack_68,0,auStack_bc,auStack_d0,auStack_e4,auStack_f8);
                    /* try { // try from 00fbd064 to 00fbd06b has its CatchHandler @ 00fbd0ec */
  (*(code *)PTR__MImg_010c8444)(auStack_f8);
                    /* try { // try from 00fbd07c to 00fbd083 has its CatchHandler @ 00fbd4dc */
  (*(code *)PTR__MImg_010c8444)(auStack_e4);
                    /* try { // try from 00fbd0d8 to 00fbd0df has its CatchHandler @ 00fbd518 */
  (*(code *)PTR__MImg_010c8444)(auStack_d0);
  (*(code *)PTR__MImg_010c8444)(auStack_bc);
  uVar9 = *(undefined4 *)(param_1 + 0x1bc);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  uVar4 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  uVar5 = (*(code *)PTR_RcGetColor_010c6aa8)(0x25);
  (*(code *)PTR_SetBarColor_010cc0e8)(uVar9,uVar2,uVar3,uVar4,uVar5);
  (*(code *)PTR_SetDrectionProperty_010c5a90)(*(undefined4 *)(param_1 + 0x1bc),0,0);
  (**(code **)(**(int **)(param_1 + 0x1b0) + 0x34))
            (*(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1bc));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(*(int *)(param_1 + 0x1bc) + 0x254));
  *(undefined1 *)(*(int *)(param_1 + 0x1bc) + 0x251) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x3a) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x188) + 0x39) = 1;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x4c) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x50) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x54) = uVar2;
  iVar8 = *(int *)(param_1 + 0x188);
  uVar2 = (*(code *)PTR_RcGetColor_010c6aa8)(0x1d);
  *(undefined4 *)(iVar8 + 0x58) = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x18c);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x13);
  (*(code *)PTR_ShowBorder_010c9b80)(uVar2,1,uVar3,8,0,2,0xffffffff);
  uVar2 = *(undefined4 *)(param_1 + 0x1a8);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x13);
  (*(code *)PTR_ShowBorder_010c9b80)(uVar2,1,uVar3,8,0,2,0xffffffff);
  uVar2 = *(undefined4 *)(param_1 + 0x188);
  uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x13);
  (*(code *)PTR_ShowBorder_010c9b80)(uVar2,1,uVar3,8,0,2,0xffffffff);
  (*(code *)PTR_SetWindowStackingClass_010cb86c)(param_1,1);
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  iVar8 = (*(code *)PTR_GetMainVolume_010cd110)(uVar2);
  *(uint *)(param_1 + 0x218) = (iVar8 + 4U) / 5 - 1;
  uVar2 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
  uVar2 = (*(code *)PTR_GetPrivateData_010ca218)(uVar2);
  *(undefined4 *)PTR_volumeKeyVal_010c4b08 = uVar2;
  uVar2 = (*(code *)PTR_GetMSrvSystemDatabase_010cb630)();
  (*(code *)PTR_GetFactorySystem_010c904c)(uVar2,auStack_98);
  if (cStack_96 == '\x01') {
    *(undefined4 *)PTR_volumeKeyVal_010c4b08 = 0xf04c;
  }
  if (*(int *)PTR_volumeKeyVal_010c4b08 == 0xf04e) {
    uVar2 = (*(code *)PTR_getInstance_010c538c)();
    iVar8 = (*(code *)PTR_IsARCActive_010c858c)(uVar2);
    if (((iVar8 == 0) || (iVar8 = (*(code *)PTR_IsCECInitCompleted_010cb89c)(uVar2), iVar8 == 0)) ||
       (iVar8 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar2), iVar8 == 0)) {
      iStack_6c = 0;
    }
    else {
      iStack_6c = 1;
    }
    if (iStack_6c == 0) {
      *(undefined4 *)(param_1 + 0x214) = 1;
      (*(code *)PTR_OnKey_010c74f8)(param_1,0,0xf04e,0);
    }
    else {
      *(undefined4 *)(param_1 + 0x214) = 3;
    }
  }
  else {
    uVar2 = (*(code *)PTR_getInstance_010c538c)();
    iVar8 = (*(code *)PTR_IsARCActive_010c858c)(uVar2);
    if (((iVar8 == 0) || (iVar8 = (*(code *)PTR_IsCECInitCompleted_010cb89c)(uVar2), iVar8 == 0)) ||
       (iVar8 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar2), iVar8 == 0)) {
      iStack_70 = 0;
    }
    else {
      iStack_70 = 1;
    }
    if (iStack_70 == 0) {
      *(undefined4 *)(param_1 + 0x214) = 0;
      if (cStack_96 == '\0') {
        (*(code *)PTR_OnKey_010c74f8)(param_1,0,*(undefined4 *)PTR_volumeKeyVal_010c4b08,0);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x214) = 2;
    }
  }
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uStack_fc = (*(code *)PTR_GetMainVolume_010cd110)(uVar2);
  if (*(int *)(param_1 + 0x1bc) != 0) {
    if (uStack_fc == 0) {
      (*(code *)PTR_SetCurValue_010caa64)(*(undefined4 *)(param_1 + 0x1bc),0);
    }
    else {
      if (100 < uStack_fc) {
        uStack_fc = 100;
      }
      (*(code *)PTR_SetCurValue_010caa64)(*(undefined4 *)(param_1 + 0x1bc),uStack_fc);
    }
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(param_1 + 0x1bc));
  }
  (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(param_1 + 0x1bc));
  iVar8 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
  iVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6d);
  iVar7 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
  iVar8 = ((iVar8 + iVar6) - (iVar7 * uStack_fc) / 100) + -10;
  uVar2 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a70);
  uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6f);
  uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6e);
  (*(code *)PTR_set_010c9810)(&uStack_84,uVar2,iVar8,uVar3,uVar4);
  (**(code **)(**(int **)(param_1 + 0x1b4) + 0x24))
            (*(undefined4 *)(param_1 + 0x1b4),uStack_84,uStack_80,&uStack_84);
  *(int *)PTR_oldEllipseY_010c94d0 = iVar8;
  (*(code *)PTR_RefreshVolumeUI_010c5f88)(param_1);
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 400));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x194));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x198));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x19c));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(param_1 + 0x1a0));
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xb8,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xcc,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xe0,0x5cd);
  (*(code *)PTR_Set_010cba00)(*(int *)(param_1 + 0x184) + 0xf4,0x5cd);
  return 0;
}

