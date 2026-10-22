
/* MResourcePkg::GetColor(unsigned long) */

void __thiscall MResourcePkg::GetColor(MResourcePkg *this,ulong param_1)

{
  GetU32(this,param_1,*(ulong **)(this + 0x38),*(ulong *)(this + 8),"COLOR",0xffffffff);
  return;
}

