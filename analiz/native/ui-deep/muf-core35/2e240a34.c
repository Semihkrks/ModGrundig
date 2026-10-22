
/* MResourcePkg::GetString(unsigned long) */

void __thiscall MResourcePkg::GetString(MResourcePkg *this,ulong param_1)

{
  GetSTR((ulong)this,(uchar *)param_1,*(ulong *)(this + 0x3c),*(ulong *)(this + 0xc),
         *(ulong **)(this + 0x5c),*(char **)(this + 0x70));
  return;
}

