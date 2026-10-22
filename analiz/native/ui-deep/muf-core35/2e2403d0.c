
/* MResourcePkg::GetNum(unsigned long) */

void __thiscall MResourcePkg::GetNum(MResourcePkg *this,ulong param_1)

{
  GetU32(this,param_1,*(ulong **)(this + 0x34),*(ulong *)(this + 4),"NUM",0);
  return;
}

