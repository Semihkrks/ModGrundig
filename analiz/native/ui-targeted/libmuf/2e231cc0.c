
/* MLinearInterpolator::getInterpolator(unsigned long, unsigned long, long, long) */

int __thiscall
MLinearInterpolator::getInterpolator
          (MLinearInterpolator *this,ulong param_1,ulong param_2,long param_3,long param_4)

{
  if (param_2 != 0) {
    if (param_2 == 0) {
      trap(7);
    }
    param_4 = param_4 + (int)(param_3 * param_1) / (int)param_2;
  }
  return param_4;
}

