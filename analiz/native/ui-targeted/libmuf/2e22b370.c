
/* MAlphaAnimation::ApplyTransformation(unsigned long, MTransformation&, _Rect&, _Rect&) */

bool MAlphaAnimation::ApplyTransformation
               (ulong param_1,MTransformation *param_2,_Rect *param_3,_Rect *param_4)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_1 + 0xc);
  bVar2 = false;
  if (uVar4 < (uint)((int)param_2 * 0x32)) {
    piVar3 = *(int **)(param_1 + 4);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)(*(code *)PTR_operator_new_2e2b4e34)(4);
                    /* try { // try from 2e22b484 to 2e22b48b has its CatchHandler @ 2e22b498 */
      (*(code *)PTR_MLinearInterpolator_2e2b3aa4)(piVar3);
      *(int **)(param_1 + 4) = piVar3;
    }
    iVar5 = (int)param_2 - uVar4 / 0x32;
    uVar1 = (**(code **)(*piVar3 + 8))
                      (piVar3,iVar5,*(uint *)(param_1 + 0x10) / 0x32,
                       *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20))
    ;
    *(undefined4 *)(param_3 + 0x24) = uVar1;
    bVar2 = *(uint *)(param_1 + 0x10) <= (uint)(iVar5 * 0x32);
  }
  return bVar2;
}

