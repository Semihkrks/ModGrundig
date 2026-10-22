
/* MResourcePkg::BuildColorData() */

undefined4 __thiscall MResourcePkg::BuildColorData(MResourcePkg *this)

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
  
                    /* try { // try from 2e24349c to 2e2434a3 has its CatchHandler @ 2e2437b8 */
  uVar4 = *(undefined4 *)(this + 0x28);
  (*(code *)PTR_string_2e2b42d4)(&local_34,PTR_PTR_2e2b3908 + -0x515c,auStack_58);
                    /* try { // try from 2e2434b8 to 2e2434bf has its CatchHandler @ 2e24379c */
  (*(code *)PTR_operator__2e2b3aa8)(&local_30,uVar4,&local_34);
  puVar1 = PTR_PTR_2e2b3908;
                    /* try { // try from 2e2434d8 to 2e2434df has its CatchHandler @ 2e243814 */
  (*(code *)PTR_string_2e2b42d4)(&local_2c,PTR_PTR_2e2b3908 + -0x4f58,auStack_54);
                    /* try { // try from 2e2434f4 to 2e2434fb has its CatchHandler @ 2e2437e8 */
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
                    /* try { // try from 2e243550 to 2e243557 has its CatchHandler @ 2e2437e0 */
    (*(code *)PTR_string_2e2b42d4)(local_28,puVar1 + -0x4f58,auStack_50);
                    /* try { // try from 2e243568 to 2e24356f has its CatchHandler @ 2e2437c4 */
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
                    /* try { // try from 2e24358c to 2e243593 has its CatchHandler @ 2e243778 */
  uVar4 = (*(code *)PTR_BuildData_2e2b48f0)(this,local_38,2);
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

