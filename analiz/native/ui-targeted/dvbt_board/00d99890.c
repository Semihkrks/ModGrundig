
/* InputSourceSelectFrame::CreateLayout(ScrollGridContainer*) */

void __thiscall
InputSourceSelectFrame::CreateLayout(InputSourceSelectFrame *this,ScrollGridContainer *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uStack_310;
  uint uStack_30c;
  byte bStack_308;
  byte bStack_307;
  undefined1 auStack_2fc [16];
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined1 auStack_2ac [52];
  undefined4 uStack_278;
  undefined4 auStack_274 [28];
  undefined1 auStack_204 [4];
  undefined4 auStack_200 [24];
  undefined4 auStack_1a0 [5];
  undefined1 auStack_18c [8];
  undefined1 auStack_184 [4];
  undefined1 auStack_180 [4];
  undefined4 auStack_17c [6];
  undefined1 uStack_162;
  undefined1 uStack_161;
  undefined4 uStack_f0;
  undefined1 auStack_e4 [32];
  undefined1 auStack_c4 [20];
  undefined1 *puStack_b0;
  int iStack_a8;
  int iStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_24 = auStack_204;
  puStack_20 = puStack_24;
  for (iStack_28 = 1; iStack_28 != -1; iStack_28 = iStack_28 + -1) {
                    /* try { // try from 00d998ec to 00d998f3 has its CatchHandler @ 00d9992c */
    (*(code *)(PTR_LAB_010c4424 + 0x70ec))(puStack_24);
    puStack_24 = puStack_24 + 0xa0;
  }
  for (bStack_307 = 0; bStack_307 < 2; bStack_307 = bStack_307 + 1) {
    uStack_2c = (uint)bStack_307;
                    /* try { // try from 00d999e4 to 00d9a4fb has its CatchHandler @ 00d9affc */
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_2c * 0x28] = uVar3;
    uStack_30 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_30 * 0x28 + 1] = uVar3;
    uStack_34 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_34 * 0x28 + 2] = uVar3;
    uStack_38 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_38 * 0x28 + 3] = uVar3;
    uStack_3c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_3c * 0x28 + 4] = uVar3;
    uStack_40 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45dd);
    auStack_17c[uStack_40 * 0x28 + 5] = uVar3;
    auStack_200[(uint)bStack_307 * 0x28 + 0x18] = 0x4ae;
    auStack_200[(uint)bStack_307 * 0x28 + 0x1a] = 0x4ae;
    auStack_200[(uint)bStack_307 * 0x28 + 0x19] = 0x4ae;
    auStack_200[(uint)bStack_307 * 0x28 + 0x1b] = 0x4ae;
    uStack_44 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_204 + (uStack_44 * 0x14 + 1) * 8 + 4) = uVar3;
    uStack_48 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_204 + uStack_48 * 0xa0 + 4) = uVar3;
    uStack_4c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    *(undefined4 *)(auStack_204 + (uStack_4c * 0x28 + 1) * 4 + 4) = uVar3;
    uStack_50 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_200[uStack_50 * 0x28 + 3] = uVar3;
    uStack_54 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_200[uStack_54 * 0x28 + 6] = uVar3;
    uStack_58 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    *(undefined4 *)(auStack_204 + (uStack_58 * 10 + 1) * 0x10 + 4) = uVar3;
    uStack_5c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_200[uStack_5c * 0x28 + 5] = uVar3;
    uStack_60 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
    auStack_200[uStack_60 * 0x28 + 7] = uVar3;
    uStack_64 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(3);
    auStack_200[uStack_64 * 0x28 + 10] = uVar3;
    uStack_68 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(7);
    *(undefined4 *)(auStack_204 + (uStack_68 * 5 + 1) * 0x20 + 4) = uVar3;
    uStack_6c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
    auStack_200[uStack_6c * 0x28 + 9] = uVar3;
    uStack_70 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x60);
    auStack_200[uStack_70 * 0x28 + 0xb] = uVar3;
    uStack_74 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_200[uStack_74 * 0x28 + 0xe] = uVar3;
    uStack_78 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_200[uStack_78 * 0x28 + 0xc] = uVar3;
    uStack_7c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_200[uStack_7c * 0x28 + 0xd] = uVar3;
    uStack_80 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
    auStack_200[uStack_80 * 0x28 + 0xf] = uVar3;
    uStack_84 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_200[uStack_84 * 0x28 + 0x12] = uVar3;
    uStack_88 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_200[uStack_88 * 0x28 + 0x10] = uVar3;
    uStack_8c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_200[uStack_8c * 0x28 + 0x11] = uVar3;
    uStack_90 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
    auStack_200[uStack_90 * 0x28 + 0x13] = uVar3;
    auStack_18c[(uint)bStack_307 * 0xa0] = 0;
    auStack_204[(uint)bStack_307 * 0xa0] = 0;
    auStack_204[(uint)bStack_307 * 0xa0 + 1] = 1;
    auStack_180[(uint)bStack_307 * 0xa0] = 0;
    auStack_204[(uint)bStack_307 * 0xa0 + 2] = 1;
    auStack_204[(uint)bStack_307 * 0xa0 + 3] = 1;
    uStack_94 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3214);
    auStack_200[uStack_94 * 0x28 + 0x14] = uVar3;
    uStack_98 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3214);
    auStack_200[uStack_98 * 0x28 + 0x16] = uVar3;
    uStack_9c = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3213);
    auStack_200[uStack_9c * 0x28 + 0x15] = uVar3;
    uStack_a0 = (uint)bStack_307;
    uVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x3214);
    auStack_200[uStack_a0 * 0x28 + 0x17] = uVar3;
  }
  (*(code *)PTR_assign_010cc3b8)(auStack_184,PTR_DAT_010c43ec + 0x345c);
  auStack_1a0[4] = 0x12;
  (*(code *)PTR_assign_010cc3b8)(auStack_e4,PTR_DAT_010c43ec + 0x345c);
  uStack_f0 = 0x22;
  uStack_162 = 1;
  uStack_161 = 1;
  uStack_2ec = 0x14;
  uStack_2e8 = 0x5a;
  uStack_2e4 = 0xa0;
  uStack_2e0 = 0x2e;
  uStack_2dc = 0x14;
  uStack_2d8 = 0x5a;
  uStack_2d4 = 0xa0;
  uStack_2d0 = 0x2e;
  for (bStack_308 = 0; bStack_308 < 2; bStack_308 = bStack_308 + 1) {
    auStack_274[(uint)bStack_308 * 0x15] = 0x5cd;
    auStack_274[(uint)bStack_308 * 0x15 + 2] = 0x5cd;
    auStack_2ac[(uint)bStack_308 * 0x54] = 0;
    auStack_2ac[(uint)bStack_308 * 0x54 + 1] = 1;
    auStack_2ac[(uint)bStack_308 * 0x54 + 2] = 1;
  }
  auStack_274[2] = 0x5cd;
  auStack_274[0] = 0x5cd;
  uStack_278 = 0x5cd;
  auStack_274[1] = 0x5cd;
  uStack_2cc = 0x38;
  uStack_2c8 = 10;
  uStack_2c4 = 0x5a;
  uStack_2c0 = 0x5a;
  auStack_274[0x17] = 0x5cd;
  auStack_274[0x15] = 0x5cd;
  auStack_274[0x14] = 0x5cd;
  auStack_274[0x16] = 0x5cd;
  uStack_2bc = 10;
  uStack_2b8 = 10;
  uStack_2b4 = 0x1e;
  uStack_2b0 = 0x1e;
  (*(code *)PTR_set_010c9810)(auStack_2fc,0,0,1,1);
  for (uStack_30c = 0; uStack_30c < 0xb; uStack_30c = uStack_30c + 1) {
    iVar2 = (*(code *)PTR_IsActiveSource_010ca110)(this,uStack_30c + 0x14);
    if (iVar2 != 0) {
      iStack_a4 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d9a52c to 00d9a533 has its CatchHandler @ 00d9a554 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_a4,param_1,auStack_2fc,0,uStack_30c + 0x14,0);
      iVar2 = iStack_a4;
      if (iStack_a4 == 0) {
                    /* try { // try from 00d9a5ac to 00d9aa7b has its CatchHandler @ 00d9affc */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + 0x3460,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x364c,
                   0x5c6);
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iVar2,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar2,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar2,auStack_204);
      (*(code *)PTR_SetImageContent_010c8414)(iVar2,auStack_2ac);
      (*(code *)PTR_SetLayOut_010cd200)(iVar2,&uStack_2ec,&uStack_2cc);
      *(undefined1 *)(iVar2 + 0x39) = 1;
      *(undefined1 *)(iVar2 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar2,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar2 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar2 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar2 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45f9);
      *(undefined2 *)(iVar2 + 0xa2) = uVar1;
      *(undefined1 *)(iVar2 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xe0,0x227);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xf4,0x227);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xb8,0x25a);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xcc,0x25a);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar2 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar2 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(**(undefined4 **)(iVar2 + 0x250));
      (**(code **)(*(int *)param_1 + 0x34))(param_1,iVar2);
    }
  }
  for (uStack_310 = 0; uStack_310 < 0xb; uStack_310 = uStack_310 + 1) {
    iVar2 = (*(code *)PTR_IsActiveSource_010ca110)(this,uStack_310 + 0x14);
    if (iVar2 == 0) {
      iStack_a8 = (*(code *)PTR_operator_new_010c9890)(0x284);
                    /* try { // try from 00d9aaac to 00d9aab3 has its CatchHandler @ 00d9aad4 */
      (*(code *)PTR_TextImageMixer_010c9cfc)(iStack_a8,param_1,auStack_2fc,0,uStack_310 + 0x14,0);
      iVar2 = iStack_a8;
      if (iStack_a8 == 0) {
                    /* try { // try from 00d9ab2c to 00d9afe3 has its CatchHandler @ 00d9affc */
        (*(code *)PTR_printf_010c9f10)
                  (PTR_DAT_010c43ec + 0x3460,PTR_DAT_010c43ec + 0x3478,PTR_DAT_010c43ec + 0x364c,
                   0x605);
        (*(code *)PTR_abort_010cc6c0)();
      }
      (*(code *)PTR_SetTextAmount_010cc6d4)(iVar2,2);
      (*(code *)PTR_SetImageAmount_010c8ad0)(iVar2,2);
      (*(code *)PTR_SetTextContent_010cc794)(iVar2,auStack_204);
      (*(code *)PTR_SetImageContent_010c8414)(iVar2,auStack_2ac);
      (*(code *)PTR_SetLayOut_010cd200)(iVar2,&uStack_2ec,&uStack_2cc);
      *(undefined1 *)(iVar2 + 0x39) = 1;
      *(undefined1 *)(iVar2 + 0x3a) = 1;
      (*(code *)PTR_SetFlag_010cb13c)(iVar2,0x10,1);
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45e9);
      *(undefined2 *)(iVar2 + 0x9c) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45e9);
      *(undefined2 *)(iVar2 + 0x9e) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45e9);
      *(undefined2 *)(iVar2 + 0xa0) = uVar1;
      uVar1 = (*(code *)PTR_RcGetNum_010c8a6c)(0x45e9);
      *(undefined2 *)(iVar2 + 0xa2) = uVar1;
      *(undefined1 *)(iVar2 + 0x38) = 1;
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xe0,0x227);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xf4,0x227);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xb8,0x251);
      (*(code *)PTR_Set_010cba00)(iVar2 + 0xcc,0x251);
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar2 + 0x58) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0xd);
      *(undefined4 *)(iVar2 + 0x54) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x4c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x50) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 100) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x5c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x60) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x68) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x74) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x6c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x70) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(6);
      *(undefined4 *)(iVar2 + 0x78) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x84) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x7c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x80) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(0x5e);
      *(undefined4 *)(iVar2 + 0x88) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x94) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x8c) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x90) = uVar3;
      uVar3 = (*(code *)PTR_RcGetColor_010c6aa8)(2);
      *(undefined4 *)(iVar2 + 0x98) = uVar3;
      (*(code *)PTR_Hide_010c5068)(**(undefined4 **)(iVar2 + 0x250));
      (**(code **)(*(int *)param_1 + 0x34))(param_1,iVar2);
    }
  }
  (**(code **)(*(int *)param_1 + 0x48))(param_1);
  (*(code *)PTR_Invalidate_010c4e28)(param_1);
  puStack_b0 = auStack_c4;
  while (puStack_b0 != auStack_204) {
    puStack_b0 = puStack_b0 + -0xa0;
    (*(code *)(PTR_LAB_010c4424 + 0x7094))(puStack_b0);
  }
  return;
}

