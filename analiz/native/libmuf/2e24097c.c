
/* MResourcePkg::GetImgPath(unsigned long) */

undefined4 __thiscall MResourcePkg::GetImgPath(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  int in_t9;
  
  uVar1 = 0;
  if (param_1 < 0xffff) {
    uVar1 = (**(code **)(in_t9 + 0x73f30))
                      (this,param_1,*(undefined4 *)(this + 0x44),*(undefined4 *)(this + 0x14),
                       *(undefined4 *)(this + 100),*(undefined4 *)(this + 0x78),
                       *(int *)(in_t9 + 0x72f8c) + -0x517c);
  }
  return uVar1;
}

