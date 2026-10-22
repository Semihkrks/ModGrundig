
/* VolumeControlFrame::RefreshVolumeUI() */

void __thiscall VolumeControlFrame::RefreshVolumeUI(VolumeControlFrame *this)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int in_t9;
  uint uStack_94;
  undefined1 auStack_90 [4];
  undefined1 auStack_8c [4];
  undefined1 auStack_88 [8];
  undefined4 uStack_80;
  undefined4 uStack_7c;
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
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  iVar3 = (**(code **)(in_t9 + 0x10cfcc))();
  if (iVar3 != 0) {
    uVar4 = (**(code **)(in_t9 + 0x10cfcc))();
    uVar4 = (**(code **)(in_t9 + 0x111be0))(uVar4);
    (**(code **)(in_t9 + 0x10d0d4))(uVar4);
  }
  (**(code **)(in_t9 + 0x10d350))(*(undefined4 *)(this + 0x180));
  (**(code **)(in_t9 + 0x10d350))(*(undefined4 *)(this + 0x184));
  (**(code **)(in_t9 + 0x10d350))(*(undefined4 *)(this + 0x188));
  uVar4 = (**(code **)(in_t9 + 0x111384))();
  uStack_94 = (**(code **)(in_t9 + 0x1153f8))(uVar4);
  uVar4 = (**(code **)(in_t9 + 0x111384))();
  cVar1 = (**(code **)(in_t9 + 0x1127ec))(uVar4);
  uVar4 = (**(code **)(in_t9 + 0x10d674))();
  cVar2 = (**(code **)(in_t9 + 0x111954))(uVar4);
  if (*(int *)(this + 0x214) == 0) {
    (**(code **)(in_t9 + 0x10fb54))(this,0);
    (**(code **)(in_t9 + 0x113340))(this,3000,0,1);
    (**(code **)(in_t9 + 0x114c74))(*(undefined4 *)(this + 0x184));
    (**(code **)(in_t9 + 0x111a9c))(auStack_88,*(int *)(in_t9 + 0x10c748) + -0x348c,uStack_94);
    iStack_24 = *(int *)(this + 0x1ac) + 0x170;
    (**(code **)(in_t9 + 0x10ec08))(auStack_90);
                    /* try { // try from 00fb7f44 to 00fb7f4b has its CatchHandler @ 00fb800c */
    (**(code **)(in_t9 + 0x10d284))(auStack_8c,auStack_88,auStack_90);
                    /* try { // try from 00fb7f60 to 00fb7f67 has its CatchHandler @ 00fb7fd0 */
    (**(code **)(in_t9 + 0x113684))(iStack_24,auStack_8c);
                    /* try { // try from 00fb7f78 to 00fb7f7f has its CatchHandler @ 00fb800c */
    (**(code **)(in_t9 + 0x10d358))(auStack_8c);
    (**(code **)(in_t9 + 0x10cc30))(auStack_90);
    (**(code **)(in_t9 + 0x10d110))(*(undefined4 *)(this + 0x1ac));
    if (*(int *)(this + 0x1bc) != 0) {
      if (uStack_94 == 0) {
        (**(code **)(in_t9 + 0x112d4c))(*(undefined4 *)(this + 0x1bc),0);
      }
      else {
        if (100 < uStack_94) {
          uStack_94 = 100;
        }
        (**(code **)(in_t9 + 0x112d4c))(*(undefined4 *)(this + 0x1bc),uStack_94);
      }
      (**(code **)(in_t9 + 0x10d110))(*(undefined4 *)(this + 0x1bc));
    }
    iVar3 = (**(code **)(in_t9 + 0x110d54))(0x5a6a);
    iVar5 = (**(code **)(in_t9 + 0x110d54))(0x5a6d);
    iVar6 = (**(code **)(in_t9 + 0x110d54))(0x5a6a);
    uVar4 = (**(code **)(in_t9 + 0x110d54))(0x5a70);
    uVar7 = (**(code **)(in_t9 + 0x110d54))(0x5a6f);
    uVar8 = (**(code **)(in_t9 + 0x110d54))(0x5a6e);
    (**(code **)(in_t9 + 0x111af8))
              (&uStack_80,uVar4,((iVar3 + iVar5) - (iVar6 * uStack_94) / 100) + -10,uVar7,uVar8);
    (**(code **)(**(int **)(this + 0x1b4) + 0x24))
              (*(undefined4 *)(this + 0x1b4),uStack_80,uStack_7c,&uStack_80);
    if (cVar1 == '\0') {
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xb8,0x2aa);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xcc,0x2aa);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xe0,0x2aa);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xf4,0x2aa);
    }
    else {
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xb8,0x2a8);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xcc,0x2a8);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xe0,0x2a8);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1a8) + 0xf4,0x2a8);
    }
    (**(code **)(in_t9 + 0x10d110))(*(undefined4 *)(this + 0x1a8));
  }
  else if (*(int *)(this + 0x214) == 1) {
    if (cVar1 == '\0') {
      (**(code **)(in_t9 + 0x10fb54))(this,0);
      (**(code **)(in_t9 + 0x113340))(this,3000,0,1);
    }
    else {
      (**(code **)(in_t9 + 0x114c74))(*(undefined4 *)(this + 0x180));
    }
  }
  else if (*(int *)(this + 0x214) == 3) {
    if (cVar2 == '\0') {
      uVar4 = (**(code **)(in_t9 + 0x1136c0))();
      (**(code **)(in_t9 + 0x1117b4))(uVar4,4,0,0);
      (**(code **)(in_t9 + 0x10fb54))(this,0);
      (**(code **)(in_t9 + 0x1144c4))(this,0,0,0);
    }
    else {
      uVar4 = (**(code **)(in_t9 + 0x1136c0))();
      (**(code **)(in_t9 + 0x1117b4))(uVar4,4,1,0);
      (**(code **)(in_t9 + 0x114c74))(*(undefined4 *)(this + 0x188));
      (**(code **)(in_t9 + 0x10daec))(*(undefined4 *)(this + 0x188),&uStack_70);
      uStack_68 = 0x9e;
      uStack_64 = 0x5a;
      (**(code **)(**(int **)(this + 0x188) + 0x24))
                (*(undefined4 *)(this + 0x188),uStack_70,uStack_6c,&uStack_70);
      (**(code **)(in_t9 + 0x10daec))(*(undefined4 *)(this + 0x1b8),&uStack_60);
      uStack_58 = 0x9e;
      uStack_54 = 0x59;
      (**(code **)(**(int **)(this + 0x1b8) + 0x24))
                (*(undefined4 *)(this + 0x1b8),uStack_60,uStack_5c,&uStack_60);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x260,5);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x274,5);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x288,5);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x29c,5);
      (**(code **)(in_t9 + 0x10d110))(*(undefined4 *)(this + 0x1b8));
      (**(code **)(in_t9 + 0x10fb54))(this,0);
    }
  }
  else {
    (**(code **)(in_t9 + 0x114c74))(*(undefined4 *)(this + 0x188));
    (**(code **)(in_t9 + 0x10fb54))(this,0);
    (**(code **)(in_t9 + 0x113340))(this,3000,0,1);
    uVar4 = (**(code **)(in_t9 + 0x1136c0))();
    (**(code **)(in_t9 + 0x1117b4))(uVar4,4,0,0);
    uVar4 = (**(code **)(in_t9 + 0x110d54))(0x5a48);
    uVar7 = (**(code **)(in_t9 + 0x110d54))(0x5a49);
    uVar8 = (**(code **)(in_t9 + 0x110d54))(0x5a47);
    uVar9 = (**(code **)(in_t9 + 0x110d54))(0x5a46);
    (**(code **)(in_t9 + 0x111af8))(&uStack_50,uVar4,uVar7,uVar8,uVar9);
    (**(code **)(**(int **)(this + 0x188) + 0x24))
              (*(undefined4 *)(this + 0x188),uStack_50,uStack_4c,&uStack_50);
    uVar4 = (**(code **)(in_t9 + 0x110d54))(0x5a74);
    uVar7 = (**(code **)(in_t9 + 0x110d54))(0x5a75);
    uVar8 = (**(code **)(in_t9 + 0x110d54))(0x5a73);
    uVar9 = (**(code **)(in_t9 + 0x110d54))(0x5a72);
    (**(code **)(in_t9 + 0x111af8))(&uStack_40,uVar4,uVar7,uVar8,uVar9);
    (**(code **)(**(int **)(this + 0x1b8) + 0x24))
              (*(undefined4 *)(this + 0x1b8),uStack_40,uStack_3c,&uStack_40);
    iStack_28 = **(int **)(in_t9 + 0x10cdf0);
    if (iStack_28 == 0xf04c) {
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x260,6);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x274,6);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x288,6);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x29c,6);
    }
    else if (iStack_28 == 0xf04d) {
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x260,4);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x274,4);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x288,4);
      (**(code **)(in_t9 + 0x113ce8))(*(int *)(this + 0x1b8) + 0x29c,4);
    }
    (**(code **)(in_t9 + 0x10d110))(*(undefined4 *)(this + 0x1b8));
    uVar4 = (**(code **)(in_t9 + 0x10d674))();
    iVar3 = (**(code **)(in_t9 + 0x110874))(uVar4);
    if (((iVar3 == 0) || (iVar3 = (**(code **)(in_t9 + 0x113b84))(uVar4), iVar3 == 0)) ||
       (iVar3 = (**(code **)(in_t9 + 0x110844))(uVar4), iVar3 == 0)) {
      iStack_2c = 0;
    }
    else {
      iStack_2c = 1;
    }
    if (((iStack_2c != 0) && (uStack_30 = **(uint **)(in_t9 + 0x10cdf0), 0xefff < uStack_30)) &&
       ((uStack_30 < 0xf002 || (uStack_30 - 0xf551 < 4)))) {
      (**(code **)(in_t9 + 0x10d350))(*(undefined4 *)(this + 0x188));
    }
  }
  return;
}

