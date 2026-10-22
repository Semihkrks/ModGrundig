
/* MResourcePkg::GetBool(unsigned long) const */

bool __thiscall MResourcePkg::GetBool(MResourcePkg *this,ulong param_1)

{
  if ((*(int *)(this + 0x30) != 0) && (param_1 < *(uint *)this)) {
    return *(char *)(*(int *)(this + 0x30) + param_1) != '\0';
  }
  return false;
}

