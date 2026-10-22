
/* MResourcePkg::GetColorKey(unsigned long) */

undefined4 __thiscall MResourcePkg::GetColorKey(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0xffff) {
    uVar1 = (*(code *)PTR_GetU32_2e2b3d7c)
                      (this,param_1,*(undefined4 *)(this + 0x48),*(undefined4 *)(this + 0x18),
                       PTR_PTR_2e2b3908 + -0x5214,0xffffffff);
  }
  return uVar1;
}

