
/* MAnimationSet::ApplyTransformation(unsigned long, MTransformation&, _Rect&, _Rect&) */

bool __thiscall
MAnimationSet::ApplyTransformation
          (MAnimationSet *this,ulong param_1,MTransformation *param_2,_Rect *param_3,_Rect *param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined1 auStack_90 [52];
  undefined4 local_5c [13];
  
  if (this[0x20] == (MAnimationSet)0x0) {
    uVar7 = *(uint *)(this + 0xc);
    if (uVar7 < param_1 * 0x32) {
      (*(code *)PTR_MTransformation_2e2b3f5c)(auStack_90);
                    /* try { // try from 2e22bd80 to 2e22bd87 has its CatchHandler @ 2e22bef0 */
      (*(code *)PTR_MTransformation_2e2b3f5c)(local_5c);
      piVar6 = *(int **)(this + 0x28);
      uVar12 = 1;
      if (piVar6 != *(int **)(this + 0x2c)) {
        uVar12 = 1;
        do {
          piVar8 = (int *)*piVar6;
          iVar4 = piVar8[4];
          piVar8[4] = *(int *)(this + 0x10);
                    /* try { // try from 2e22bdc8 to 2e22bdff has its CatchHandler @ 2e22bf14 */
          uVar2 = (**(code **)(*piVar8 + 8))
                            (piVar8,param_1 - uVar7 / 0x32,auStack_90,param_3,param_4);
          uVar12 = uVar2 & uVar12;
          (*(code *)PTR_Compose_2e2b3f84)(local_5c,auStack_90);
          puVar1 = PTR_Clear_2e2b3b10;
          *(int *)(*piVar6 + 0x10) = iVar4;
          (*(code *)puVar1)(auStack_90);
          piVar6 = piVar6 + 1;
        } while (piVar6 != *(int **)(this + 0x2c));
      }
      puVar11 = local_5c;
      do {
        uVar3 = *puVar11;
        uVar5 = puVar11[1];
        uVar9 = puVar11[2];
        uVar10 = puVar11[3];
        puVar11 = puVar11 + 4;
        *(undefined4 *)param_2 = uVar3;
        *(undefined4 *)(param_2 + 4) = uVar5;
        *(undefined4 *)(param_2 + 8) = uVar9;
        *(undefined4 *)(param_2 + 0xc) = uVar10;
        puVar1 = PTR__MTransformation_2e2b4db0;
        param_2 = param_2 + 0x10;
      } while (puVar11 != local_5c + 0xc);
                    /* try { // try from 2e22be54 to 2e22be5b has its CatchHandler @ 2e22bef0 */
      *(undefined4 *)param_2 = *puVar11;
      (*(code *)puVar1)(local_5c);
      (*(code *)PTR__MTransformation_2e2b4db0)(auStack_90);
      return uVar12 != 0;
    }
  }
  else {
    uVar7 = 0;
    if (*(int *)(this + 0x24) != 0) {
      uVar12 = 0;
      do {
        piVar6 = *(int **)(*(int *)(this + 0x28) + uVar12 * 4);
        uVar12 = uVar12 + 1;
        param_1 = param_1 - (uint)piVar6[4] / 0x32;
        (**(code **)(*piVar6 + 8))(piVar6,(uint)piVar6[4] / 0x32,param_2,param_3,param_4);
        uVar7 = *(uint *)(this + 0x24);
      } while (uVar12 < uVar7);
    }
    piVar6 = *(int **)(*(int *)(this + 0x28) + uVar7 * 4);
    if ((uint)piVar6[3] < param_1 * 0x32) {
      iVar4 = (**(code **)(*piVar6 + 8))
                        (piVar6,param_1 - (uint)piVar6[3] / 0x32,param_2,param_3,param_4);
      if (iVar4 == 0) {
        uVar7 = *(uint *)(this + 0x24);
      }
      else {
        uVar7 = *(int *)(this + 0x24) + 1;
        *(uint *)(this + 0x24) = uVar7;
      }
      if (uVar7 < (uint)(*(int *)(this + 0x2c) - *(int *)(this + 0x28) >> 2)) {
        return false;
      }
      *(undefined4 *)(this + 0x24) = 0;
      return iVar4 != 0;
    }
  }
  return false;
}

