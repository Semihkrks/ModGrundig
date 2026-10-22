
/* MResourcePkg::GetColorKey(unsigned long) */

undefined4 __thiscall MResourcePkg::GetColorKey(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0xffff) {
    uVar1 = GetU32(this,param_1,*(ulong **)(this + 0x48),*(ulong *)(this + 0x18),"CLRKEY",0xffffffff
                  );
  }
  return uVar1;
}

