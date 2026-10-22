
/* MResourcePkg::BuildMBAPathData() */

undefined4 __thiscall MResourcePkg::BuildMBAPathData(MResourcePkg *this)

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
  
                    /* try { // try from 2e243c80 to 2e243c87 has its CatchHandler @ 2e24403c */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x706a0))(&local_34,*(int *)(in_t9 + 0x6fcd4) + -0x515c,auStack_58);
                    /* try { // try from 2e243c9c to 2e243ca3 has its CatchHandler @ 2e243fd4 */
  (**(code **)(in_t9 + 0x6fe74))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x6fcd4);
                    /* try { // try from 2e243cbc to 2e243cc3 has its CatchHandler @ 2e243fa0 */
  (**(code **)(in_t9 + 0x706a0))(&local_2c,iVar4 + -0x4ef4,auStack_54);
                    /* try { // try from 2e243cd8 to 2e243cdf has its CatchHandler @ 2e244020 */
  (**(code **)(in_t9 + 0x6fe74))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x7105c);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x70f64) == 0) {
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
      (**(code **)(in_t9 + 0x70aa4))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x70f64) == 0) {
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
      (**(code **)(in_t9 + 0x70aa4))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x70f64) == 0) {
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
      (**(code **)(in_t9 + 0x70aa4))(local_34 + -0xc,auStack_44);
    }
  }
                    /* try { // try from 2e243d24 to 2e243d5f has its CatchHandler @ 2e244018 */
  iVar1 = (**(code **)(in_t9 + 0x70fb0))(local_38,*(int *)(in_t9 + 0x6fcd4) + -0x5160);
  if (iVar1 == 0) {
                    /* try { // try from 2e243e30 to 2e243e37 has its CatchHandler @ 2e244018 */
    (**(code **)(in_t9 + 0x7020c))(*(int *)(in_t9 + 0x6fcd4) + -0x4ee8);
    uVar2 = 0;
  }
  else {
    (**(code **)(in_t9 + 0x70ab0))(iVar1);
    if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e243db0 to 2e243db7 has its CatchHandler @ 2e243fe0 */
      (**(code **)(in_t9 + 0x706a0))(local_28,iVar4 + -0x4ef4,auStack_50);
                    /* try { // try from 2e243dc8 to 2e243dcf has its CatchHandler @ 2e243ffc */
      (**(code **)(in_t9 + 0x70de4))(this,&local_38,local_28);
      if (iVar3 != local_28[0] + -0xc) {
        if (*(int *)(in_t9 + 0x70f64) == 0) {
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
          (**(code **)(in_t9 + 0x70aa4))(local_28[0] + -0xc,auStack_40);
        }
      }
    }
    uVar2 = (**(code **)(in_t9 + 0x70cbc))(this,local_38,7);
  }
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x70f64) == 0) {
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
      (**(code **)(in_t9 + 0x70aa4))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

