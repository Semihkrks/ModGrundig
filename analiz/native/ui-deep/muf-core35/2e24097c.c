
/* MResourcePkg::GetImgPath(unsigned long) */

undefined4 __thiscall MResourcePkg::GetImgPath(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xffff) {
    uVar1 = GetSTR((ulong)this,(uchar *)param_1,*(ulong *)(this + 0x44),*(ulong *)(this + 0x14),
                   *(ulong **)(this + 100),*(char **)(this + 0x78));
  }
  return uVar1;
}

