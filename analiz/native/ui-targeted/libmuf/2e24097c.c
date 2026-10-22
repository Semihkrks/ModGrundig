
/* MResourcePkg::GetImgPath(unsigned long) */

undefined4 __thiscall MResourcePkg::GetImgPath(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xffff) {
    uVar1 = (*(code *)PTR_GetSTR_2e2b48ac)
                      (this,param_1,*(undefined4 *)(this + 0x44),*(undefined4 *)(this + 0x14),
                       *(undefined4 *)(this + 100),*(undefined4 *)(this + 0x78),
                       PTR_PTR_2e2b3908 + -0x517c);
  }
  return uVar1;
}

