
/* MResourcePkg::GetSTR(unsigned long, unsigned char*, unsigned long, unsigned long, unsigned long*,
   char const*) */

int MResourcePkg::GetSTR
              (ulong param_1,uchar *param_2,ulong param_3,ulong param_4,ulong *param_5,char *param_6
              )

{
  int iVar1;
  undefined *puVar2;
  
  if ((param_3 == 0) || (param_4 <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 + (int)*(ulong **)(param_6 + (int)param_2 * 4);
    if (param_5 <= *(ulong **)(param_6 + (int)param_2 * 4)) {
      (*(code *)PTR_printf_2e2b3ee0)
                (PTR_PTR_2e2b3908 + -0x73a0,PTR_PTR_2e2b3908 + -0x51fc,PTR_PTR_2e2b3908 + -0x4c84,
                 0x261);
      puVar2 = PTR_abort_2e2b3bc8;
      (*(code *)PTR_abort_2e2b3bc8)();
      iVar1 = (**(code **)(puVar2 + 0x73f84))();
      return iVar1;
    }
  }
  return iVar1;
}

