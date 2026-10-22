
/* MTranslateAnimation::ApplyTransformation(unsigned long, MTransformation&, _Rect&, _Rect&) */

bool MTranslateAnimation::ApplyTransformation
               (ulong param_1,MTransformation *param_2,_Rect *param_3,_Rect *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  bVar4 = false;
  if (uVar5 < (uint)((int)param_2 * 0x32)) {
    if (*(int *)(param_1 + 4) == 0) {
      uVar3 = (*(code *)PTR_operator_new_2e2b4e34)(4);
                    /* try { // try from 2e24d00c to 2e24d013 has its CatchHandler @ 2e24d044 */
      (*(code *)PTR_MLinearInterpolator_2e2b3aa4)(uVar3);
      *(undefined4 *)(param_1 + 4) = uVar3;
    }
    if (*(int *)(param_1 + 8) == 0) {
      uVar3 = (*(code *)PTR_operator_new_2e2b4e34)(4);
                    /* try { // try from 2e24cfe8 to 2e24cfef has its CatchHandler @ 2e24d020 */
      (*(code *)PTR_MLinearInterpolator_2e2b3aa4)(uVar3);
      *(undefined4 *)(param_1 + 8) = uVar3;
    }
    iVar6 = (int)param_2 - uVar5 / 0x32;
    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 8))
                      (*(int **)(param_1 + 4),iVar6,*(uint *)(param_1 + 0x10) / 0x32,
                       *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20))
    ;
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 8))
                      (*(int **)(param_1 + 8),iVar6,*(uint *)(param_1 + 0x10) / 0x32,
                       *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24))
    ;
    *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + iVar2;
    *(int *)param_4 = *(int *)param_4 + iVar1;
    bVar4 = *(uint *)(param_1 + 0x10) <= (uint)(iVar6 * 0x32);
    *(undefined4 *)(param_3 + 0x20) = 0x10000;
    *(undefined4 *)param_3 = 0x10000;
    *(undefined4 *)(param_3 + 4) = 0;
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(undefined4 *)(param_3 + 0x10) = 0x10000;
    *(undefined4 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
  }
  return bVar4;
}

