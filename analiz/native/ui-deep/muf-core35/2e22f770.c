
/* MDecelerateInterpolator::getInterpolator(unsigned long, unsigned long, long, long) */

long __thiscall
MDecelerateInterpolator::getInterpolator
          (MDecelerateInterpolator *this,ulong param_1,ulong param_2,long param_3,long param_4)

{
  double dVar1;
  double dVar2;
  
  if (param_2 == 0) {
    return param_4;
  }
  dVar2 = (double)(int)param_1;
  if ((int)param_1 < 0) {
    dVar2 = dVar2 + 4294967296.0;
  }
  dVar1 = (double)(int)param_2;
  if ((int)param_2 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  return (int)((double)param_3 * SQRT(dVar2 / dVar1) + (double)param_4);
}

