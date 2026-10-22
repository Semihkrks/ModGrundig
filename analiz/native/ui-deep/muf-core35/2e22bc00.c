
/* MAnimationSet::ApplyTransformation(unsigned long, MTransformation&, _Rect&, _Rect&) */

bool __thiscall
MAnimationSet::ApplyTransformation
          (MAnimationSet *this,ulong param_1,MTransformation *param_2,_Rect *param_3,_Rect *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  MTransformation *pMVar10;
  uint uVar11;
  MTransformation aMStack_90 [52];
  MTransformation local_5c [4];
  undefined4 local_58 [11];
  MTransformation aMStack_2c [4];
  
  if (this[0x20] == (MAnimationSet)0x0) {
    uVar6 = *(uint *)(this + 0xc);
    if (uVar6 < param_1 * 0x32) {
      MTransformation::MTransformation(aMStack_90);
                    /* try { // try from 2e22bd80 to 2e22bd87 has its CatchHandler @ 2e22bef0 */
      MTransformation::MTransformation(local_5c);
      piVar5 = *(int **)(this + 0x28);
      uVar11 = 1;
      if (piVar5 != *(int **)(this + 0x2c)) {
        uVar11 = 1;
        do {
          piVar7 = (int *)*piVar5;
          iVar3 = piVar7[4];
          piVar7[4] = *(int *)(this + 0x10);
                    /* try { // try from 2e22bdc8 to 2e22bdff has its CatchHandler @ 2e22bf14 */
          uVar1 = (**(code **)(*piVar7 + 8))
                            (piVar7,param_1 - uVar6 / 0x32,aMStack_90,param_3,param_4);
          uVar11 = uVar1 & uVar11;
          MTransformation::Compose(local_5c,aMStack_90);
          *(int *)(*piVar5 + 0x10) = iVar3;
          MTransformation::Clear(aMStack_90);
          piVar5 = piVar5 + 1;
        } while (piVar5 != *(int **)(this + 0x2c));
      }
      pMVar10 = local_5c;
      do {
        uVar2 = *(undefined4 *)pMVar10;
        uVar4 = *(undefined4 *)(pMVar10 + 4);
        uVar8 = *(undefined4 *)(pMVar10 + 8);
        uVar9 = *(undefined4 *)(pMVar10 + 0xc);
        pMVar10 = pMVar10 + 0x10;
        *(undefined4 *)param_2 = uVar2;
        *(undefined4 *)(param_2 + 4) = uVar4;
        *(undefined4 *)(param_2 + 8) = uVar8;
        *(undefined4 *)(param_2 + 0xc) = uVar9;
        param_2 = param_2 + 0x10;
      } while (pMVar10 != aMStack_2c);
                    /* try { // try from 2e22be54 to 2e22be5b has its CatchHandler @ 2e22bef0 */
      *(undefined4 *)param_2 = *(undefined4 *)pMVar10;
      MTransformation::~MTransformation(local_5c);
      MTransformation::~MTransformation(aMStack_90);
      return uVar11 != 0;
    }
  }
  else {
    uVar6 = 0;
    if (*(int *)(this + 0x24) != 0) {
      uVar11 = 0;
      do {
        piVar5 = *(int **)(*(int *)(this + 0x28) + uVar11 * 4);
        uVar11 = uVar11 + 1;
        param_1 = param_1 - (uint)piVar5[4] / 0x32;
        (**(code **)(*piVar5 + 8))(piVar5,(uint)piVar5[4] / 0x32,param_2,param_3,param_4);
        uVar6 = *(uint *)(this + 0x24);
      } while (uVar11 < uVar6);
    }
    piVar5 = *(int **)(*(int *)(this + 0x28) + uVar6 * 4);
    if ((uint)piVar5[3] < param_1 * 0x32) {
      iVar3 = (**(code **)(*piVar5 + 8))
                        (piVar5,param_1 - (uint)piVar5[3] / 0x32,param_2,param_3,param_4);
      if (iVar3 == 0) {
        uVar6 = *(uint *)(this + 0x24);
      }
      else {
        uVar6 = *(int *)(this + 0x24) + 1;
        *(uint *)(this + 0x24) = uVar6;
      }
      if (uVar6 < (uint)(*(int *)(this + 0x2c) - *(int *)(this + 0x28) >> 2)) {
        return false;
      }
      *(undefined4 *)(this + 0x24) = 0;
      return iVar3 != 0;
    }
  }
  return false;
}

