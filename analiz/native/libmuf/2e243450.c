
/* MResourcePkg::BuildColorData() */

undefined4 __thiscall MResourcePkg::BuildColorData(MResourcePkg *this)

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
  
                    /* try { // try from 2e24349c to 2e2434a3 has its CatchHandler @ 2e2437b8 */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x70e84))(&local_34,*(int *)(in_t9 + 0x704b8) + -0x515c,auStack_58);
                    /* try { // try from 2e2434b8 to 2e2434bf has its CatchHandler @ 2e24379c */
  (**(code **)(in_t9 + 0x70658))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x704b8);
                    /* try { // try from 2e2434d8 to 2e2434df has its CatchHandler @ 2e243814 */
  (**(code **)(in_t9 + 0x70e84))(&local_2c,iVar4 + -0x4f58,auStack_54);
                    /* try { // try from 2e2434f4 to 2e2434fb has its CatchHandler @ 2e2437e8 */
  (**(code **)(in_t9 + 0x70658))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x71840);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x71748) == 0) {
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
      (**(code **)(in_t9 + 0x71288))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x71748) == 0) {
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
      (**(code **)(in_t9 + 0x71288))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x71748) == 0) {
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
      (**(code **)(in_t9 + 0x71288))(local_34 + -0xc,auStack_44);
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e243550 to 2e243557 has its CatchHandler @ 2e2437e0 */
    (**(code **)(in_t9 + 0x70e84))(local_28,iVar4 + -0x4f58,auStack_50);
                    /* try { // try from 2e243568 to 2e24356f has its CatchHandler @ 2e2437c4 */
    (**(code **)(in_t9 + 0x715c8))(this,&local_38,local_28);
    if (iVar3 != local_28[0] + -0xc) {
      if (*(int *)(in_t9 + 0x71748) == 0) {
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
        (**(code **)(in_t9 + 0x71288))(local_28[0] + -0xc,auStack_40);
      }
    }
  }
                    /* try { // try from 2e24358c to 2e243593 has its CatchHandler @ 2e243778 */
  uVar2 = (**(code **)(in_t9 + 0x714a0))(this,local_38,2);
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x71748) == 0) {
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
      (**(code **)(in_t9 + 0x71288))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

