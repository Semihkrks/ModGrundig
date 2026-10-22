
/* MResourcePkg::BuildStringData() */

undefined4 __thiscall MResourcePkg::BuildStringData(MResourcePkg *this)

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
  
                    /* try { // try from 2e24218c to 2e242193 has its CatchHandler @ 2e2424a8 */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x72194))(&local_34,*(int *)(in_t9 + 0x717c8) + -0x515c,auStack_58);
                    /* try { // try from 2e2421a8 to 2e2421af has its CatchHandler @ 2e24248c */
  (**(code **)(in_t9 + 0x71968))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x717c8);
                    /* try { // try from 2e2421c8 to 2e2421cf has its CatchHandler @ 2e242504 */
  (**(code **)(in_t9 + 0x72194))(&local_2c,iVar4 + -0x4fa0,auStack_54);
                    /* try { // try from 2e2421e4 to 2e2421eb has its CatchHandler @ 2e2424d8 */
  (**(code **)(in_t9 + 0x71968))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x72b50);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x72a58) == 0) {
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
      (**(code **)(in_t9 + 0x72598))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x72a58) == 0) {
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
      (**(code **)(in_t9 + 0x72598))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x72a58) == 0) {
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
      (**(code **)(in_t9 + 0x72598))(local_34 + -0xc,auStack_44);
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e242240 to 2e242247 has its CatchHandler @ 2e2424d0 */
    (**(code **)(in_t9 + 0x72194))(local_28,iVar4 + -0x4fa0,auStack_50);
                    /* try { // try from 2e242258 to 2e24225f has its CatchHandler @ 2e2424b4 */
    (**(code **)(in_t9 + 0x728d8))(this,&local_38,local_28);
    if (iVar3 != local_28[0] + -0xc) {
      if (*(int *)(in_t9 + 0x72a58) == 0) {
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
        (**(code **)(in_t9 + 0x72598))(local_28[0] + -0xc,auStack_40);
      }
    }
  }
                    /* try { // try from 2e24227c to 2e242283 has its CatchHandler @ 2e242468 */
  uVar2 = (**(code **)(in_t9 + 0x727b0))(this,local_38,3);
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x72a58) == 0) {
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
      (**(code **)(in_t9 + 0x72598))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

