
/* MResourcePkg::BuildBoolData() */

undefined4 __thiscall MResourcePkg::BuildBoolData(MResourcePkg *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_t9;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [3];
  
                    /* try { // try from 2e24386c to 2e243873 has its CatchHandler @ 2e243c28 */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x70ab4))(&local_34,*(int *)(in_t9 + 0x700e8) + -0x515c,auStack_58);
                    /* try { // try from 2e243888 to 2e24388f has its CatchHandler @ 2e243bc0 */
  (**(code **)(in_t9 + 0x70288))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x700e8);
                    /* try { // try from 2e2438a8 to 2e2438af has its CatchHandler @ 2e243b8c */
  (**(code **)(in_t9 + 0x70ab4))(&local_2c,iVar4 + -0x4f48,auStack_54);
                    /* try { // try from 2e2438c4 to 2e2438cb has its CatchHandler @ 2e243c0c */
  (**(code **)(in_t9 + 0x70288))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x71470);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x71378) == 0) {
      iVar1 = *(int *)(local_2c + -4);
      *(int *)(local_2c + -4) = iVar1 + -1;
    }
    else {
      SYNC(0);
      iVar1 = *(int *)(local_2c + -4);
      *(int *)(local_2c + -4) = iVar1 + -1;
      SYNC(0);
    }
    if (iVar1 < 1) {
      (**(code **)(in_t9 + 0x70eb8))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x71378) == 0) {
      iVar1 = *(int *)(local_30 + -4);
      *(int *)(local_30 + -4) = iVar1 + -1;
    }
    else {
      SYNC(0);
      iVar1 = *(int *)(local_30 + -4);
      *(int *)(local_30 + -4) = iVar1 + -1;
      SYNC(0);
    }
    if (iVar1 < 1) {
      (**(code **)(in_t9 + 0x70eb8))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x71378) == 0) {
      iVar1 = *(int *)(local_34 + -4);
      *(int *)(local_34 + -4) = iVar1 + -1;
    }
    else {
      SYNC(0);
      iVar1 = *(int *)(local_34 + -4);
      *(int *)(local_34 + -4) = iVar1 + -1;
      SYNC(0);
    }
    if (iVar1 < 1) {
      (**(code **)(in_t9 + 0x70eb8))(local_34 + -0xc,auStack_44);
    }
  }
                    /* try { // try from 2e243910 to 2e24394b has its CatchHandler @ 2e243c04 */
  iVar1 = (**(code **)(in_t9 + 0x713c4))(local_38,*(int *)(in_t9 + 0x700e8) + -0x5160);
  if (iVar1 == 0) {
                    /* try { // try from 2e243a1c to 2e243a23 has its CatchHandler @ 2e243c04 */
    (**(code **)(in_t9 + 0x70620))(*(int *)(in_t9 + 0x700e8) + -0x4f38);
    uVar2 = 0;
  }
  else {
    (**(code **)(in_t9 + 0x70ec4))(iVar1);
    if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e24399c to 2e2439a3 has its CatchHandler @ 2e243bcc */
      (**(code **)(in_t9 + 0x70ab4))(local_28,iVar4 + -0x4f48,auStack_50);
                    /* try { // try from 2e2439b4 to 2e2439bb has its CatchHandler @ 2e243be8 */
      (**(code **)(in_t9 + 0x711f8))(this,&local_38,local_28);
      if (iVar3 != local_28[0] + -0xc) {
        if (*(int *)(in_t9 + 0x71378) == 0) {
          iVar4 = *(int *)(local_28[0] + -4);
          *(int *)(local_28[0] + -4) = iVar4 + -1;
        }
        else {
          SYNC(0);
          iVar4 = *(int *)(local_28[0] + -4);
          *(int *)(local_28[0] + -4) = iVar4 + -1;
          SYNC(0);
        }
        if (iVar4 < 1) {
          (**(code **)(in_t9 + 0x70eb8))(local_28[0] + -0xc,auStack_40);
        }
      }
    }
    uVar2 = (**(code **)(in_t9 + 0x710d0))(this,local_38,0);
  }
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x71378) == 0) {
      iVar3 = *(int *)(local_38 + -4);
      *(int *)(local_38 + -4) = iVar3 + -1;
    }
    else {
      SYNC(0);
      iVar3 = *(int *)(local_38 + -4);
      *(int *)(local_38 + -4) = iVar3 + -1;
      SYNC(0);
    }
    if (iVar3 < 1) {
      (**(code **)(in_t9 + 0x70eb8))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

