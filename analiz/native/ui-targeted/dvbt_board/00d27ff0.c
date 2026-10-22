
/* HomePageFrame::HandleFocus(unsigned long, unsigned char, unsigned long) */

undefined4 __thiscall
HomePageFrame::HandleFocus(HomePageFrame *this,ulong param_1,uchar param_2,ulong param_3)

{
  int *piVar1;
  int iVar2;
  int *piStack_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
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
  int *piStack_48;
  int iStack_44;
  int *piStack_40;
  int iStack_3c;
  int *piStack_38;
  int iStack_34;
  int *piStack_30;
  int iStack_2c;
  int *piStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  ulong uStack_10;
  
  if (param_2 == '\0') {
    (*(code *)PTR_GetAbsRect_010cd298)(*(undefined4 *)(this + 0x3c),&iStack_bc);
    piVar1 = *(int **)(this + 0x3c);
    iStack_18 = *(int *)(this + 0x3c);
    if ((iStack_18 == 0) ||
       (iVar2 = (*(code *)PTR___dynamic_cast_010c6984)
                          (iStack_18,PTR_DAT_010c953c,PTR_DAT_010c73f8,0), iVar2 == 0)) {
      iStack_14 = 0;
    }
    else {
      iStack_14 = 1;
    }
    if (iStack_14 != 0) {
      iStack_bc = iStack_bc + 0x3f;
      iStack_b8 = iStack_b8 + 0x3f;
      iStack_b4 = 0xc4;
      iStack_b0 = 0x92;
    }
    if (iStack_bc < 200) {
      iStack_d4 = 0x6b8;
    }
    else {
      iStack_d4 = iStack_bc - iStack_b4 / 2;
    }
    iStack_d0 = iStack_b8 + iStack_b0 / 2;
    if (iStack_bc < 0x641) {
      iStack_dc = iStack_bc + (iStack_b4 / 2) * 3;
    }
    else {
      iStack_dc = 200;
    }
    iStack_d8 = iStack_b8 + iStack_b0 / 2;
    iStack_20 = *(int *)(this + 0x3c);
    if ((iStack_20 == 0) ||
       (iVar2 = (*(code *)PTR___dynamic_cast_010c6984)
                          (iStack_20,PTR_DAT_010c953c,PTR_DAT_010c73f8,0), iVar2 == 0)) {
      iStack_1c = 0;
    }
    else {
      iStack_1c = 1;
    }
    if (iStack_1c == 0) {
      if (iStack_bc < 200) {
        iStack_d4 = 0x6b8;
      }
      else {
        iStack_d4 = iStack_bc + -100;
      }
      iStack_d0 = iStack_b8 + iStack_b0 / 2;
      iStack_c4 = iStack_bc + 0x30c;
      iStack_c0 = iStack_b8 + iStack_b0 * 2;
      if (iStack_bc < 0x321) {
        iStack_dc = iStack_bc + 1000;
        iStack_d8 = iStack_b8 + iStack_b0 / 2;
      }
      else {
        iStack_dc = 200;
        iStack_d8 = iStack_b8 + iStack_b0 / 2;
      }
    }
    else {
      iStack_c4 = iStack_bc + iStack_b4 / 2;
      iStack_c0 = iStack_b8 + iStack_b0 * 2;
    }
    iStack_cc = iStack_bc + iStack_b4 / 2;
    iStack_c8 = iStack_b8 - iStack_b0;
    uStack_10 = param_1;
    if (param_1 == 0xf001) {
      piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                    (*(undefined4 *)(this + 0x38),&iStack_dc);
      if (piStack_e0 == (int *)0x0) {
        if (iStack_d8 < 0x13f) {
          iStack_94 = *(int *)(this + 0x2b4);
          iStack_90 = *(int *)(this + 0x2b8);
        }
        else {
          iStack_94 = *(int *)(this + 0x2d4);
          iStack_90 = *(int *)(this + 0x2d8);
        }
        iStack_90 = iStack_90 + 10;
        iStack_94 = iStack_94 + 10;
        piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                      (*(undefined4 *)(this + 0x38),&iStack_94);
      }
    }
    else if (param_1 < 0xf002) {
      if ((param_1 == 0xf000) &&
         (piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                        (*(undefined4 *)(this + 0x38),&iStack_d4),
         piStack_e0 == (int *)0x0)) {
        if (iStack_d0 < 0x13f) {
          iStack_9c = *(int *)(this + 0x2c4);
          iStack_98 = *(int *)(this + 0x2c8);
        }
        else {
          iStack_9c = *(int *)(this + 0x2e4);
          iStack_98 = *(int *)(this + 0x2e8);
        }
        iStack_98 = iStack_98 + 10;
        iStack_9c = iStack_9c + 10;
        piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                      (*(undefined4 *)(this + 0x38),&iStack_9c);
      }
    }
    else if (param_1 == 0xf002) {
      piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                    (*(undefined4 *)(this + 0x38),&iStack_cc);
      if ((piStack_e0 == (int *)0x0) && (0x41 < iStack_c8)) {
        iStack_ac = *(int *)(this + 0x2c4) + 10;
        iStack_a8 = *(int *)(this + 0x2c8) + 10;
        piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                      (*(undefined4 *)(this + 0x38),&iStack_ac);
      }
    }
    else if (((param_1 == 0xf003) &&
             (piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                            (*(undefined4 *)(this + 0x38),&iStack_c4),
             piStack_e0 == (int *)0x0)) && (iStack_c0 < 0x1d1)) {
      iStack_a4 = *(int *)(this + 0x2e4) + 10;
      iStack_a0 = *(int *)(this + 0x2e8) + 10;
      piStack_e0 = (int *)(*(code *)PTR_FindChildOnPoint_010c7718)
                                    (*(undefined4 *)(this + 0x38),&iStack_a4);
    }
    if (piStack_e0 != (int *)0x0) {
      piStack_28 = piStack_e0;
      if ((piStack_e0 == (int *)0x0) ||
         (iVar2 = (*(code *)PTR___dynamic_cast_010c6984)
                            (piStack_e0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0), iVar2 == 0)) {
        iStack_24 = 0;
      }
      else {
        iStack_24 = 1;
      }
      if (iStack_24 != 0) {
        (**(code **)(**(int **)(this + 0x184) + 0x3c))(*(undefined4 *)(this + 0x184),piStack_e0);
        (**(code **)(**(int **)(this + 0x184) + 0x34))(*(undefined4 *)(this + 0x184),piStack_e0);
      }
      (*(code *)PTR_SwitchFocusTo_010c8c70)(this,piStack_e0);
      piStack_30 = piVar1;
      if ((piVar1 == (int *)0x0) ||
         (iVar2 = (*(code *)PTR___dynamic_cast_010c6984)(piVar1,PTR_DAT_010c953c,PTR_DAT_010c73f8,0)
         , iVar2 == 0)) {
        iStack_2c = 0;
      }
      else {
        iStack_2c = 1;
      }
      if (iStack_2c != 0) {
        (**(code **)(*piVar1 + 0x24))(piVar1,iStack_bc,iStack_b8,&iStack_bc);
      }
      uStack_7c = 0;
      uStack_78 = 0xf;
      uStack_74 = 0xc4;
      uStack_70 = 0x46;
      uStack_8c = 0;
      uStack_88 = 0x60;
      uStack_84 = 0xc4;
      uStack_80 = 0x2d;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0x142;
      uStack_60 = 0x110;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0xc4;
      uStack_50 = 0x92;
      piStack_38 = piVar1;
      if (piVar1 == (int *)0x0) {
        iStack_34 = 0;
      }
      else {
        iStack_34 = (*(code *)PTR___dynamic_cast_010c6984)
                              (piVar1,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
      }
      iVar2 = iStack_34;
      if (iStack_34 != 0) {
        *(undefined2 *)(*(int *)(*(int *)(iStack_34 + 0x250) + 4) + 0x13a) = 0x46;
        *(undefined2 *)(*(int *)(*(int *)(iStack_34 + 0x250) + 4) + 0x146) = 0x46;
        *(undefined2 *)(*(int *)(*(int *)(iStack_34 + 0x250) + 4) + 0x152) = 0x46;
        *(undefined2 *)(*(int *)(*(int *)(iStack_34 + 0x250) + 4) + 0x15e) = 0x46;
        (*(code *)PTR_SetLayOut_010cd200)(iStack_34,&uStack_8c,&uStack_6c);
        (*(code *)PTR_Invalidate_010c4e28)(iVar2);
      }
    }
  }
  else if (param_3 == 0x4a) {
    piStack_e0 = (int *)(*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x4a);
    (**(code **)(**(int **)(this + 0x184) + 0x3c))(*(undefined4 *)(this + 0x184),piStack_e0);
    (**(code **)(**(int **)(this + 0x184) + 0x34))(*(undefined4 *)(this + 0x184),piStack_e0);
    (*(code *)PTR_SetInitialFocus_010c97b8)(this,*(undefined4 *)(this + 0x184));
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,piStack_e0);
  }
  else if (this[0x2b1] == (HomePageFrame)0x1) {
    piStack_e0 = (int *)(*(code *)PTR_GetWdgInsByID_010c6f88)(this,0x3d);
    (**(code **)(**(int **)(this + 0x184) + 0x3c))(*(undefined4 *)(this + 0x184),piStack_e0);
    (**(code **)(**(int **)(this + 0x184) + 0x34))(*(undefined4 *)(this + 0x184),piStack_e0);
    (*(code *)PTR_SetInitialFocus_010c97b8)(this,*(undefined4 *)(this + 0x184));
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,piStack_e0);
  }
  else {
    piStack_e0 = *(int **)(this + 0x248);
    (*(code *)PTR_SetInitialFocus_010c97b8)(this,*(undefined4 *)(this + 0x230));
    (*(code *)PTR_SwitchFocusTo_010c8c70)(this,piStack_e0);
  }
  if (((piStack_e0 == (int *)0x0) || (piStack_40 = piStack_e0, piStack_e0 == (int *)0x0)) ||
     (iVar2 = (*(code *)PTR___dynamic_cast_010c6984)(piStack_e0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0)
     , iVar2 == 0)) {
    iStack_3c = 0;
  }
  else {
    iStack_3c = 1;
  }
  if (iStack_3c != 0) {
    (*(code *)PTR_GetAbsRect_010cd298)(piStack_e0,&iStack_bc);
    iStack_bc = iStack_bc + -0x3f;
    iStack_b8 = iStack_b8 + -0x3f;
    iStack_b4 = 0x142;
    iStack_b0 = 0x110;
    (**(code **)(*piStack_e0 + 0x24))(piStack_e0,iStack_bc,iStack_b8,&iStack_bc);
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0x142;
    uStack_60 = 0x110;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0x142;
    uStack_50 = 0x110;
    uStack_7c = 0;
    uStack_78 = 0x3c;
    uStack_74 = 0x142;
    uStack_70 = 0x5a;
    uStack_8c = 0x34;
    uStack_88 = 0xaf;
    uStack_84 = 0xda;
    uStack_80 = 0x2d;
    piStack_48 = piStack_e0;
    if (piStack_e0 == (int *)0x0) {
      iStack_44 = 0;
    }
    else {
      iStack_44 = (*(code *)PTR___dynamic_cast_010c6984)
                            (piStack_e0,PTR_DAT_010c953c,PTR_DAT_010c73f8,0);
    }
    iVar2 = iStack_44;
    *(undefined2 *)(*(int *)(*(int *)(iStack_44 + 0x250) + 4) + 0x13a) = 0x6e;
    *(undefined2 *)(*(int *)(*(int *)(iStack_44 + 0x250) + 4) + 0x146) = 0x6e;
    *(undefined2 *)(*(int *)(*(int *)(iStack_44 + 0x250) + 4) + 0x152) = 0x6e;
    *(undefined2 *)(*(int *)(*(int *)(iStack_44 + 0x250) + 4) + 0x15e) = 0x6e;
    (*(code *)PTR_SetLayOut_010cd200)(iStack_44,&uStack_8c,&uStack_6c);
    (*(code *)PTR_Invalidate_010c4e28)(iVar2);
  }
  (**(code **)(**(int **)(this + 0x184) + 0x48))(*(undefined4 *)(this + 0x184));
  (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x184));
  return 1;
}

