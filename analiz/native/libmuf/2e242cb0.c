
/* MResourcePkg::BuildNumData() */

undefined4 __thiscall MResourcePkg::BuildNumData(MResourcePkg *this)

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
  
                    /* try { // try from 2e242cfc to 2e242d03 has its CatchHandler @ 2e243018 */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x71624))(&local_34,*(int *)(in_t9 + 0x70c58) + -0x515c,auStack_58);
                    /* try { // try from 2e242d18 to 2e242d1f has its CatchHandler @ 2e242ffc */
  (**(code **)(in_t9 + 0x70df8))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x70c58);
                    /* try { // try from 2e242d38 to 2e242d3f has its CatchHandler @ 2e243074 */
  (**(code **)(in_t9 + 0x71624))(&local_2c,iVar4 + -0x4f74,auStack_54);
                    /* try { // try from 2e242d54 to 2e242d5b has its CatchHandler @ 2e243048 */
  (**(code **)(in_t9 + 0x70df8))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x71fe0);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x71ee8) == 0) {
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
      (**(code **)(in_t9 + 0x71a28))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x71ee8) == 0) {
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
      (**(code **)(in_t9 + 0x71a28))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x71ee8) == 0) {
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
      (**(code **)(in_t9 + 0x71a28))(local_34 + -0xc,auStack_44);
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e242db0 to 2e242db7 has its CatchHandler @ 2e243040 */
    (**(code **)(in_t9 + 0x71624))(local_28,iVar4 + -0x4f74,auStack_50);
                    /* try { // try from 2e242dc8 to 2e242dcf has its CatchHandler @ 2e243024 */
    (**(code **)(in_t9 + 0x71d68))(this,&local_38,local_28);
    if (iVar3 != local_28[0] + -0xc) {
      if (*(int *)(in_t9 + 0x71ee8) == 0) {
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
        (**(code **)(in_t9 + 0x71a28))(local_28[0] + -0xc,auStack_40);
      }
    }
  }
                    /* try { // try from 2e242dec to 2e242df3 has its CatchHandler @ 2e242fd8 */
  uVar2 = (**(code **)(in_t9 + 0x71c40))(this,local_38,1);
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x71ee8) == 0) {
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
      (**(code **)(in_t9 + 0x71a28))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

