
/* MResourcePkg::GetSTR(unsigned long, unsigned char*, unsigned long, unsigned long, unsigned long*,
   char const*) */

int MResourcePkg::GetSTR
              (ulong param_1,uchar *param_2,ulong param_3,ulong param_4,ulong *param_5,char *param_6
              )

{
  int iVar1;
  int in_t9;
  code *pcVar2;
  
  if ((param_3 == 0) || (param_4 <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 + (int)*(ulong **)(param_6 + (int)param_2 * 4);
    if (param_5 <= *(ulong **)(param_6 + (int)param_2 * 4)) {
      (**(code **)(in_t9 + 0x73640))
                (*(int *)(in_t9 + 0x73068) + -0x73a0,*(int *)(in_t9 + 0x73068) + -0x51fc,
                 *(int *)(in_t9 + 0x73068) + -0x4c84,0x261);
      pcVar2 = *(code **)(in_t9 + 0x73328);
      (*pcVar2)();
      iVar1 = (**(code **)(pcVar2 + 0x73f84))();
      return iVar1;
    }
  }
  return iVar1;
}

