
/* InputSourceSelectFrame::FillUIDataOfSources() */

void __thiscall InputSourceSelectFrame::FillUIDataOfSources(InputSourceSelectFrame *this)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  int iStack_20;
  
  uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar3 = (*(code *)PTR_ArSourceConf_GetSatelliteAvailable_010c6538)(uVar2);
  if (iVar3 == 0) {
    *(undefined2 *)(this + 0x1d4) = 0x466;
    *(undefined2 *)(this + 0x1d6) = 0x465;
  }
  else {
    *(undefined2 *)(this + 0x1d4) = 0x25f;
    *(undefined2 *)(this + 0x1d6) = 0x25e;
  }
  *(undefined2 *)(this + 0x1d8) = 0xb0a;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,2,1);
  *(undefined2 *)(this + 0x1da) = uVar1;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,2,0);
  *(undefined2 *)(this + 0x1dc) = uVar1;
  *(undefined2 *)(this + 0x1de) = 0x9b2;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,3,1);
  *(undefined2 *)(this + 0x1e0) = uVar1;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,3,0);
  *(undefined2 *)(this + 0x1e2) = uVar1;
  *(undefined2 *)(this + 0x1e4) = 0x9b3;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,4,1);
  *(undefined2 *)(this + 0x1e6) = uVar1;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,4,0);
  *(undefined2 *)(this + 0x1e8) = uVar1;
  *(undefined2 *)(this + 0x1ea) = 0x9b4;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,5,1);
  *(undefined2 *)(this + 0x1ec) = uVar1;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,5,0);
  *(undefined2 *)(this + 0x1ee) = uVar1;
  *(undefined2 *)(this + 0x1f0) = 0x9b5;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,6,1);
  *(undefined2 *)(this + 0x1f2) = uVar1;
  uVar2 = (*(code *)PTR_getInstance_010c67ec)();
  uVar1 = (*(code *)PTR_GetIconType_010c7b58)(uVar2,6,0);
  *(undefined2 *)(this + 500) = uVar1;
  *(undefined2 *)(this + 0x1f6) = 0x9b6;
  *(undefined2 *)(this + 0x1f8) = 0x259;
  *(undefined2 *)(this + 0x1fa) = 600;
  *(undefined2 *)(this + 0x1fc) = 0xbbf;
  *(undefined2 *)(this + 0x1fe) = 0x259;
  *(undefined2 *)(this + 0x200) = 600;
  *(undefined2 *)(this + 0x202) = 0x9b7;
  *(undefined2 *)(this + 0x204) = 0x28c;
  *(undefined2 *)(this + 0x206) = 0x28b;
  *(undefined2 *)(this + 0x208) = 0x673;
  *(undefined2 *)(this + 0x20a) = 0x262;
  *(undefined2 *)(this + 0x20c) = 0x261;
  *(undefined2 *)(this + 0x20e) = 0x2e3;
  *(undefined2 *)(this + 0x210) = 0x259;
  *(undefined2 *)(this + 0x212) = 600;
  *(undefined2 *)(this + 0x214) = 0x9b8;
  uStack_48 = 0;
  do {
    if (10 < (int)uStack_48) {
      uVar2 = (*(code *)PTR_GetInstance_010c5b58)();
      iVar3 = (*(code *)PTR_GetBoardType_010c83d0)(uVar2);
      if (iVar3 == 3) {
        for (uStack_4c = 0; (int)uStack_4c < 10; uStack_4c = uStack_4c + 1) {
          pcVar6 = *(code **)(**(int **)(this + 0x1b4) + 0x40);
          uVar2 = *(undefined4 *)(this + 0x1b4);
          uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)
                            (this,(uStack_4c & 0xffff) + 0x15 & 0xffff);
          iVar3 = (*pcVar6)(uVar2,uVar4);
          if (uStack_4c == 2) {
            iVar5 = **(int **)(iVar3 + 0x250);
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            (*(code *)PTR_GetSourceName_010cadc8)(auStack_24,uVar2,3);
                    /* try { // try from 00d9bdf4 to 00d9bdfb has its CatchHandler @ 00d9be9c */
            (*(code *)PTR_Set_010cb39c)(iVar5 + 0x170,auStack_24);
            (*(code *)PTR__string_010c5070)(auStack_24);
            iVar3 = *(int *)(*(int *)(iVar3 + 0x250) + 4);
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            (*(code *)PTR_GetSourceName_010cadc8)(auStack_28,uVar2,3);
                    /* try { // try from 00d9be70 to 00d9be77 has its CatchHandler @ 00d9bee0 */
            (*(code *)PTR_Set_010cb39c)(iVar3 + 0x170,auStack_28);
            (*(code *)PTR__string_010c5070)(auStack_28);
          }
          else {
            iVar5 = **(int **)(iVar3 + 0x250);
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            (*(code *)PTR_GetSourceName_010cadc8)(auStack_2c,uVar2,uStack_4c + 2);
                    /* try { // try from 00d9bf80 to 00d9bf87 has its CatchHandler @ 00d9c030 */
            (*(code *)PTR_Set_010cb39c)(iVar5 + 0x170,auStack_2c);
            (*(code *)PTR__string_010c5070)(auStack_2c);
            iVar3 = *(int *)(*(int *)(iVar3 + 0x250) + 4);
            uVar2 = (*(code *)PTR_getInstance_010c67ec)();
            (*(code *)PTR_GetSourceName_010cadc8)(auStack_30,uVar2,uStack_4c + 2);
                    /* try { // try from 00d9c004 to 00d9c00b has its CatchHandler @ 00d9c074 */
            (*(code *)PTR_Set_010cb39c)(iVar3 + 0x170,auStack_30);
            (*(code *)PTR__string_010c5070)(auStack_30);
          }
        }
      }
      else {
        for (uStack_50 = 0; (int)uStack_50 < 10; uStack_50 = uStack_50 + 1) {
          pcVar6 = *(code **)(**(int **)(this + 0x1b4) + 0x40);
          uVar2 = *(undefined4 *)(this + 0x1b4);
          uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)
                            (this,(uStack_50 & 0xffff) + 0x15 & 0xffff);
          iVar3 = (*pcVar6)(uVar2,uVar4);
          iVar5 = **(int **)(iVar3 + 0x250);
          uVar2 = (*(code *)PTR_getInstance_010c67ec)();
          (*(code *)PTR_GetSourceName_010cadc8)(auStack_34,uVar2,uStack_50 + 2);
                    /* try { // try from 00d9c1a8 to 00d9c1af has its CatchHandler @ 00d9c264 */
          (*(code *)PTR_Set_010cb39c)(iVar5 + 0x170,auStack_34);
          (*(code *)PTR__string_010c5070)(auStack_34);
          iVar3 = *(int *)(*(int *)(iVar3 + 0x250) + 4);
          uVar2 = (*(code *)PTR_getInstance_010c67ec)();
          (*(code *)PTR_GetSourceName_010cadc8)(auStack_38,uVar2,uStack_50 + 2);
                    /* try { // try from 00d9c22c to 00d9c233 has its CatchHandler @ 00d9c2a8 */
          (*(code *)PTR_Set_010cb39c)(iVar3 + 0x170,auStack_38);
          (*(code *)PTR__string_010c5070)(auStack_38);
        }
      }
      return;
    }
    pcVar6 = *(code **)(**(int **)(this + 0x1b4) + 0x40);
    uVar2 = *(undefined4 *)(this + 0x1b4);
    uVar4 = (*(code *)PTR_ConvertIndexToActiveIndex_010c58c0)
                      (this,(uStack_48 & 0xffff) + 0x14 & 0xffff);
    iVar3 = (*pcVar6)(uVar2,uVar4);
    (*(code *)PTR_Set_010c61fc)
              (**(int **)(iVar3 + 0x250) + 0x170,*(undefined2 *)(this + uStack_48 * 6 + 0x1d8));
    (*(code *)PTR_Set_010c61fc)
              (*(int *)(*(int *)(iVar3 + 0x250) + 4) + 0x170,
               *(undefined2 *)(this + uStack_48 * 6 + 0x1d8));
    iVar5 = (*(code *)PTR_IsActiveSource_010ca110)(this,uStack_48 + 0x14);
    if (iVar5 == 0) {
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x29c,*(undefined2 *)(this + uStack_48 * 6 + 0x1d6));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x274,*(undefined2 *)(this + uStack_48 * 6 + 0x1d6));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x260,*(undefined2 *)(this + uStack_48 * 6 + 0x1d6));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x288,*(undefined2 *)(this + uStack_48 * 6 + 0x1d6));
    }
    else {
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x29c,*(undefined2 *)(this + uStack_48 * 6 + 0x1d4));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x274,*(undefined2 *)(this + uStack_48 * 6 + 0x1d4));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x260,*(undefined2 *)(this + uStack_48 * 6 + 0x1d4));
      (*(code *)PTR_Set_010cba00)
                (**(int **)(iVar3 + 0x254) + 0x288,*(undefined2 *)(this + uStack_48 * 6 + 0x1d4));
    }
    uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
    iVar5 = (*(code *)PTR_ArTvConf_GetBasicMode_010c9400)(uVar2);
    if (iVar5 == 1) {
      uVar2 = (*(code *)PTR_getInstance_010cd270)();
      iVar5 = (*(code *)PTR_GetBasicMode_010c82e4)(uVar2);
      if (iVar5 != 1) goto LAB_00d9bb9c;
LAB_00d9bbc8:
      iStack_20 = 1;
    }
    else {
LAB_00d9bb9c:
      uVar2 = (*(code *)PTR_getInstance_010cc8bc)();
      iVar5 = (*(code *)PTR_ArTvConf_GetNonConnectedEnabled_010ccb14)(uVar2);
      if (iVar5 != 0) goto LAB_00d9bbc8;
      iStack_20 = 0;
    }
    if ((iStack_20 != 0) &&
       (iVar5 = (*(code *)PTR_IsFavSource_010cb688)(this,uStack_48 + 0x14), iVar5 != 0)) {
      (*(code *)PTR_Set_010cba00)(*(int *)(*(int *)(iVar3 + 0x254) + 4) + 0x29c,0x138);
      (*(code *)PTR_Set_010cba00)(*(int *)(*(int *)(iVar3 + 0x254) + 4) + 0x274,0x138);
      (*(code *)PTR_Set_010cba00)(*(int *)(*(int *)(iVar3 + 0x254) + 4) + 0x260,0x138);
      (*(code *)PTR_Set_010cba00)(*(int *)(*(int *)(iVar3 + 0x254) + 4) + 0x288,0x138);
    }
    uStack_48 = uStack_48 + 1;
  } while( true );
}

