
/* MAnimation::SetDuration(unsigned long) */

void __thiscall MAnimation::SetDuration(MAnimation *this,ulong param_1)

{
  *(uint *)(this + 0x10) = (param_1 / 0x32) * 0x32;
  return;
}

