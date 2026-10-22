
/* MResourcePkg::GetU32(unsigned long, unsigned long const*, unsigned long, char const*, unsigned
   long) */

ulong __thiscall
MResourcePkg::GetU32
          (MResourcePkg *this,ulong param_1,ulong *param_2,ulong param_3,char *param_4,ulong param_5
          )

{
  if ((param_2 != (ulong *)0x0) && (param_1 < param_3)) {
    param_5 = param_2[param_1];
  }
  return param_5;
}

