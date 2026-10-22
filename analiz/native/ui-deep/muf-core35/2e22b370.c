
/* MAlphaAnimation::ApplyTransformation(unsigned long, MTransformation&, _Rect&, _Rect&) */

bool MAlphaAnimation::ApplyTransformation
               (ulong param_1,MTransformation *param_2,_Rect *param_3,_Rect *param_4)

{
  undefined4 uVar1;
  bool bVar2;
  MLinearInterpolator *this;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  bVar2 = false;
  if (uVar3 < (uint)((int)param_2 * 0x32)) {
    this = *(MLinearInterpolator **)(param_1 + 4);
    if (this == (MLinearInterpolator *)0x0) {
      this = operator_new(4);
                    /* try { // try from 2e22b484 to 2e22b48b has its CatchHandler @ 2e22b498 */
      MLinearInterpolator::MLinearInterpolator(this);
      *(MLinearInterpolator **)(param_1 + 4) = this;
    }
    iVar4 = (int)param_2 - uVar3 / 0x32;
    uVar1 = (**(code **)(*(int *)this + 8))
                      (this,iVar4,*(uint *)(param_1 + 0x10) / 0x32,
                       *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20))
    ;
    *(undefined4 *)(param_3 + 0x24) = uVar1;
    bVar2 = *(uint *)(param_1 + 0x10) <= (uint)(iVar4 * 0x32);
  }
  return bVar2;
}

