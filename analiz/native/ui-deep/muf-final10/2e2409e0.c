
/* MResourcePkg::GetFontPath(unsigned long) */

void __thiscall MResourcePkg::GetFontPath(MResourcePkg *this,ulong param_1)

{
  GetSTR((ulong)this,(uchar *)param_1,*(ulong *)(this + 0x40),*(ulong *)(this + 0x10),
         *(ulong **)(this + 0x60),*(char **)(this + 0x74));
  return;
}

