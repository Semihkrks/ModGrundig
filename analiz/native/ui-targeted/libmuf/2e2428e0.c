
/* MResourcePkg::BuildImgPathData() */

undefined4 __thiscall MResourcePkg::BuildImgPathData(MResourcePkg *this)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
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
  
                    /* try { // try from 2e24292c to 2e242933 has its CatchHandler @ 2e242c48 */
  uVar4 = *(undefined4 *)(this + 0x28);
  (*(code *)PTR_string_2e2b42d4)(&local_34,PTR_PTR_2e2b3908 + -0x515c,auStack_58);
                    /* try { // try from 2e242948 to 2e24294f has its CatchHandler @ 2e242c2c */
  (*(code *)PTR_operator__2e2b3aa8)(&local_30,uVar4,&local_34);
  puVar1 = PTR_PTR_2e2b3908;
                    /* try { // try from 2e242968 to 2e24296f has its CatchHandler @ 2e242ca4 */
  (*(code *)PTR_string_2e2b42d4)(&local_2c,PTR_PTR_2e2b3908 + -0x4f84,auStack_54);
                    /* try { // try from 2e242984 to 2e24298b has its CatchHandler @ 2e242c78 */
  (*(code *)PTR_operator__2e2b3aa8)(&local_38,&local_30,&local_2c);
  puVar2 = PTR_DAT_2e2b4c90;
  if ((undefined *)(local_2c + -0xc) != PTR_DAT_2e2b4c90) {
    if (PTR_pthread_cancel_2e2b4b98 == (undefined *)0x0) {
      iVar3 = *(int *)(local_2c + -4);
      *(int *)(local_2c + -4) = iVar3 + -1;
    }
    else {
      SYNC(0);
      iVar3 = *(int *)(local_2c + -4);
      *(int *)(local_2c + -4) = iVar3 + -1;
      SYNC(0);
    }
    if (iVar3 < 1) {
      (*(code *)PTR__M_destroy_2e2b46d8)((undefined *)(local_2c + -0xc),auStack_4c);
    }
  }
  if (puVar2 != (undefined *)(local_30 + -0xc)) {
    if (PTR_pthread_cancel_2e2b4b98 == (undefined *)0x0) {
      iVar3 = *(int *)(local_30 + -4);
      *(int *)(local_30 + -4) = iVar3 + -1;
    }
    else {
      SYNC(0);
      iVar3 = *(int *)(local_30 + -4);
      *(int *)(local_30 + -4) = iVar3 + -1;
      SYNC(0);
    }
    if (iVar3 < 1) {
      (*(code *)PTR__M_destroy_2e2b46d8)((undefined *)(local_30 + -0xc),auStack_48);
    }
  }
  if (puVar2 != (undefined *)(local_34 + -0xc)) {
    if (PTR_pthread_cancel_2e2b4b98 == (undefined *)0x0) {
      iVar3 = *(int *)(local_34 + -4);
      *(int *)(local_34 + -4) = iVar3 + -1;
    }
    else {
      SYNC(0);
      iVar3 = *(int *)(local_34 + -4);
      *(int *)(local_34 + -4) = iVar3 + -1;
      SYNC(0);
    }
    if (iVar3 < 1) {
      (*(code *)PTR__M_destroy_2e2b46d8)((undefined *)(local_34 + -0xc),auStack_44);
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e2429e0 to 2e2429e7 has its CatchHandler @ 2e242c70 */
    (*(code *)PTR_string_2e2b42d4)(local_28,puVar1 + -0x4f84,auStack_50);
                    /* try { // try from 2e2429f8 to 2e2429ff has its CatchHandler @ 2e242c54 */
    (*(code *)PTR_CheckInitialPath_2e2b4a18)(this,&local_38,local_28);
    if (puVar2 != (undefined *)(local_28[0] + -0xc)) {
      if (PTR_pthread_cancel_2e2b4b98 == (undefined *)0x0) {
        iVar3 = *(int *)(local_28[0] + -4);
        *(int *)(local_28[0] + -4) = iVar3 + -1;
      }
      else {
        SYNC(0);
        iVar3 = *(int *)(local_28[0] + -4);
        *(int *)(local_28[0] + -4) = iVar3 + -1;
        SYNC(0);
      }
      if (iVar3 < 1) {
        (*(code *)PTR__M_destroy_2e2b46d8)((undefined *)(local_28[0] + -0xc),auStack_40);
      }
    }
  }
                    /* try { // try from 2e242a1c to 2e242a23 has its CatchHandler @ 2e242c08 */
  uVar4 = (*(code *)PTR_BuildData_2e2b48f0)(this,local_38,5);
  if (puVar2 != (undefined *)(local_38 + -0xc)) {
    if (PTR_pthread_cancel_2e2b4b98 == (undefined *)0x0) {
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
      (*(code *)PTR__M_destroy_2e2b46d8)((undefined *)(local_38 + -0xc),auStack_3c);
    }
  }
  return uVar4;
}

