
/* mmrgDrawText_LookUp_Table::GetFontPath() const */

int mmrgDrawText_LookUp_Table::GetFontPath(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int in_a0;
  int *piVar7;
  int *piVar8;
  undefined *puVar9;
  code *pcVar10;
  undefined1 auStack_4b8 [260];
  undefined1 auStack_380 [260];
  undefined1 auStack_250 [260];
  undefined1 local_120 [260];
  
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(PTR_DAT_2f099e1c,PTR_LAB_2f099a48 + 0x6b00);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6b18);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6c40);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6eb4);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x68c8);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6b24);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x68f8);
  piVar2 = (int *)(*(code *)PTR_operator<<_2f099eb4)(uVar1,0x16c);
  piVar7 = *(int **)((int)piVar2 + *(int *)(*piVar2 + -0xc) + 0x7c);
  if (piVar7 != (int *)0x0) {
    iVar5 = 0;
    if ((char)piVar7[7] == '\0') {
      puVar3 = local_120;
      do {
        *puVar3 = (char)iVar5;
        iVar5 = iVar5 + 1;
        puVar3 = local_120 + iVar5;
      } while (iVar5 != 0x100);
      (**(code **)(*piVar7 + 0x1c))(piVar7,local_120,local_120 + 0x100,(int)piVar7 + 0x1d);
      *(undefined1 *)(piVar7 + 7) = 1;
      iVar5 = (*(code *)PTR_memcmp_2f099ea8)(local_120,(int)piVar7 + 0x1d,0x100);
      if (iVar5 != 0) {
        *(undefined1 *)(piVar7 + 7) = 2;
      }
      iVar5 = (**(code **)(*piVar7 + 0x18))(piVar7,10);
    }
    else {
      iVar5 = (int)*(char *)((int)piVar7 + 0x27);
    }
    uVar1 = (*(code *)PTR_put_2f099aa0)(piVar2,iVar5);
    (*(code *)PTR_flush_2f099be0)(uVar1);
    (*(code *)PTR_string_2f099df0)();
    return in_a0;
  }
  puVar9 = PTR___throw_bad_cast_2f099e98;
  (*(code *)PTR___throw_bad_cast_2f099e98)();
  uVar1 = (**(code **)(puVar9 + 0x19470))
                    (*(undefined4 *)(puVar9 + 0x194f0),*(int *)(puVar9 + 0x1911c) + 0x6b00);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x6b18);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x6c58);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x6eb4);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x68c8);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x6b24);
  uVar1 = (**(code **)(puVar9 + 0x19470))(uVar1,*(int *)(puVar9 + 0x1911c) + 0x68f8);
  piVar2 = (int *)(**(code **)(puVar9 + 0x19588))(uVar1,0x15e);
  piVar7 = *(int **)((int)piVar2 + *(int *)(*piVar2 + -0xc) + 0x7c);
  if (piVar7 != (int *)0x0) {
    iVar5 = 0;
    if ((char)piVar7[7] == '\0') {
      puVar3 = auStack_250;
      do {
        *puVar3 = (char)iVar5;
        iVar5 = iVar5 + 1;
        puVar3 = auStack_250 + iVar5;
      } while (iVar5 != 0x100);
      (**(code **)(*piVar7 + 0x1c))(piVar7,auStack_250,auStack_250 + 0x100,(int)piVar7 + 0x1d);
      *(undefined1 *)(piVar7 + 7) = 1;
      iVar5 = (**(code **)(puVar9 + 0x1957c))(auStack_250,(int)piVar7 + 0x1d,0x100);
      if (iVar5 != 0) {
        *(undefined1 *)(piVar7 + 7) = 2;
      }
      iVar5 = (**(code **)(*piVar7 + 0x18))(piVar7,10);
    }
    else {
      iVar5 = (int)*(char *)((int)piVar7 + 0x27);
    }
    uVar1 = (**(code **)(puVar9 + 0x19174))(piVar2,iVar5);
    (**(code **)(puVar9 + 0x192b4))(uVar1);
    return 0;
  }
  pcVar10 = *(code **)(puVar9 + 0x1956c);
  (*pcVar10)();
  uVar1 = (**(code **)(pcVar10 + 0x1928c))
                    (*(undefined4 *)(pcVar10 + 0x1930c),*(int *)(pcVar10 + 0x18f38) + 0x6b00);
  uVar1 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x6b18);
  uVar1 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x6c68);
  uVar1 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x6eb4);
  uVar1 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x68c8);
  uVar1 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x6b24);
  iVar5 = (**(code **)(pcVar10 + 0x1928c))(uVar1,*(int *)(pcVar10 + 0x18f38) + 0x68f8);
  uVar1 = 0x157;
  piVar2 = (int *)(**(code **)(pcVar10 + 0x193a4))(iVar5,0x157);
  piVar7 = *(int **)((int)piVar2 + *(int *)(*piVar2 + -0xc) + 0x7c);
  if (piVar7 != (int *)0x0) {
    iVar5 = 0;
    if ((char)piVar7[7] == '\0') {
      puVar3 = auStack_380;
      do {
        *puVar3 = (char)iVar5;
        iVar5 = iVar5 + 1;
        puVar3 = auStack_380 + iVar5;
      } while (iVar5 != 0x100);
      (**(code **)(*piVar7 + 0x1c))(piVar7,auStack_380,auStack_380 + 0x100,(int)piVar7 + 0x1d);
      *(undefined1 *)(piVar7 + 7) = 1;
      iVar5 = (**(code **)(pcVar10 + 0x19398))(auStack_380,(int)piVar7 + 0x1d,0x100);
      if (iVar5 != 0) {
        *(undefined1 *)(piVar7 + 7) = 2;
      }
      iVar5 = (**(code **)(*piVar7 + 0x18))(piVar7,10);
    }
    else {
      iVar5 = (int)*(char *)((int)piVar7 + 0x27);
    }
    uVar1 = (**(code **)(pcVar10 + 0x18f90))(piVar2,iVar5);
    iVar5 = (**(code **)(pcVar10 + 0x190d0))(uVar1);
    return iVar5;
  }
  pcVar10 = *(code **)(pcVar10 + 0x19388);
  (*pcVar10)();
  uVar4 = (**(code **)(pcVar10 + 0x190ac))
                    (*(undefined4 *)(pcVar10 + 0x1912c),*(int *)(pcVar10 + 0x18d58) + 0x6b00);
  uVar4 = (**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x6b18);
  uVar4 = (**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x6c4c);
  uVar4 = (**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x6eb4);
  uVar4 = (**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x68c8);
  uVar4 = (**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x6b24);
  piVar2 = (int *)(**(code **)(pcVar10 + 0x190ac))(uVar4,*(int *)(pcVar10 + 0x18d58) + 0x68f8);
  piVar7 = (int *)(**(code **)(pcVar10 + 0x191c4))(piVar2,0x165);
  piVar8 = *(int **)((int)piVar7 + *(int *)(*piVar7 + -0xc) + 0x7c);
  if (piVar8 != (int *)0x0) {
    iVar6 = 0;
    if ((char)piVar8[7] == '\0') {
      puVar3 = auStack_4b8;
      do {
        *puVar3 = (char)iVar6;
        iVar6 = iVar6 + 1;
        puVar3 = auStack_4b8 + iVar6;
      } while (iVar6 != 0x100);
      (**(code **)(*piVar8 + 0x1c))(piVar8,auStack_4b8,auStack_4b8 + 0x100,(int)piVar8 + 0x1d);
      *(undefined1 *)(piVar8 + 7) = 1;
      iVar6 = (**(code **)(pcVar10 + 0x191b8))(auStack_4b8,(int)piVar8 + 0x1d,0x100);
      if (iVar6 != 0) {
        *(undefined1 *)(piVar8 + 7) = 2;
      }
      iVar6 = (**(code **)(*piVar8 + 0x18))(piVar8,10);
    }
    else {
      iVar6 = (int)*(char *)((int)piVar8 + 0x27);
    }
    uVar4 = (**(code **)(pcVar10 + 0x18db0))(piVar7,iVar6);
    (**(code **)(pcVar10 + 0x18ef0))(uVar4);
    iVar5 = (**(code **)(pcVar10 + 0x18eac))(iVar5 + 0xc,uVar1);
    return iVar5;
  }
  pcVar10 = *(code **)(pcVar10 + 0x191a8);
  (*pcVar10)();
  iVar5 = *(int *)(pcVar10 + 0x18efc);
  piVar2[1] = 0;
  *piVar2 = iVar5 + 8;
  return iVar5 + 8;
}

