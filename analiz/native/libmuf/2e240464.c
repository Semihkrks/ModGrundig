
/* MResourcePkg::GetColorKey(unsigned long) */

undefined4 __thiscall MResourcePkg::GetColorKey(MResourcePkg *this,ulong param_1)

{
  undefined4 uVar1;
  int in_t9;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0xffff) {
    uVar1 = (**(code **)(in_t9 + 0x73918))
                      (this,param_1,*(undefined4 *)(this + 0x48),*(undefined4 *)(this + 0x18),
                       *(int *)(in_t9 + 0x734a4) + -0x5214,0xffffffff,in_t9 + 0x7b47c);
  }
  return uVar1;
}

