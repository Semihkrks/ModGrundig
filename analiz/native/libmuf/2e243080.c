
/* MResourcePkg::BuildColorKeyData() */

undefined4 __thiscall MResourcePkg::BuildColorKeyData(MResourcePkg *this)

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
  
                    /* try { // try from 2e2430cc to 2e2430d3 has its CatchHandler @ 2e2433e8 */
  uVar2 = *(undefined4 *)(this + 0x28);
  (**(code **)(in_t9 + 0x71254))(&local_34,*(int *)(in_t9 + 0x70888) + -0x515c,auStack_58);
                    /* try { // try from 2e2430e8 to 2e2430ef has its CatchHandler @ 2e2433cc */
  (**(code **)(in_t9 + 0x70a28))(&local_30,uVar2,&local_34);
  iVar4 = *(int *)(in_t9 + 0x70888);
                    /* try { // try from 2e243108 to 2e24310f has its CatchHandler @ 2e243444 */
  (**(code **)(in_t9 + 0x71254))(&local_2c,iVar4 + -0x4f68,auStack_54);
                    /* try { // try from 2e243124 to 2e24312b has its CatchHandler @ 2e243418 */
  (**(code **)(in_t9 + 0x70a28))(&local_38,&local_30,&local_2c);
  iVar3 = *(int *)(in_t9 + 0x71c10);
  if (local_2c + -0xc != iVar3) {
    if (*(int *)(in_t9 + 0x71b18) == 0) {
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
      (**(code **)(in_t9 + 0x71658))(local_2c + -0xc,auStack_4c);
    }
  }
  if (iVar3 != local_30 + -0xc) {
    if (*(int *)(in_t9 + 0x71b18) == 0) {
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
      (**(code **)(in_t9 + 0x71658))(local_30 + -0xc,auStack_48);
    }
  }
  if (iVar3 != local_34 + -0xc) {
    if (*(int *)(in_t9 + 0x71b18) == 0) {
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
      (**(code **)(in_t9 + 0x71658))(local_34 + -0xc,auStack_44);
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e243180 to 2e243187 has its CatchHandler @ 2e243410 */
    (**(code **)(in_t9 + 0x71254))(local_28,iVar4 + -0x4f68,auStack_50);
                    /* try { // try from 2e243198 to 2e24319f has its CatchHandler @ 2e2433f4 */
    (**(code **)(in_t9 + 0x71998))(this,&local_38,local_28);
    if (iVar3 != local_28[0] + -0xc) {
      if (*(int *)(in_t9 + 0x71b18) == 0) {
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
        (**(code **)(in_t9 + 0x71658))(local_28[0] + -0xc,auStack_40);
      }
    }
  }
                    /* try { // try from 2e2431bc to 2e2431c3 has its CatchHandler @ 2e2433a8 */
  uVar2 = (**(code **)(in_t9 + 0x71870))(this,local_38,6);
  if (iVar3 != local_38 + -0xc) {
    if (*(int *)(in_t9 + 0x71b18) == 0) {
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
      (**(code **)(in_t9 + 0x71658))(local_38 + -0xc,auStack_3c);
    }
  }
  return uVar2;
}

