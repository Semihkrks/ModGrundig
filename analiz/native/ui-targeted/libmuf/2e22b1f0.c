
/* MAccelerateInterpolator::getInterpolator(unsigned long, unsigned long, long, long) */

int __thiscall
MAccelerateInterpolator::getInterpolator
          (MAccelerateInterpolator *this,ulong param_1,ulong param_2,long param_3,long param_4)

{
  if (param_2 != 0) {
    if (param_2 == 0) {
      trap(7);
    }
    if (param_2 == 0) {
      trap(7);
    }
    param_4 = param_4 + ((int)(param_1 * param_1 * param_3) / (int)param_2) / (int)param_2;
  }
  return param_4;
}

