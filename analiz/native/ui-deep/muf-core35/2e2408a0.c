
/* MResourcePkg::GetSTR(unsigned long, unsigned char*, unsigned long, unsigned long, unsigned long*,
   char const*) */

int MResourcePkg::GetSTR
              (ulong param_1,uchar *param_2,ulong param_3,ulong param_4,ulong *param_5,char *param_6
              )

{
  int iVar1;
  
  if ((param_3 == 0) || (param_4 <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 + (int)*(ulong **)(param_6 + (int)param_2 * 4);
    if (param_5 <= *(ulong **)(param_6 + (int)param_2 * 4)) {
      printf("ASSERT FAIL: %s %s %d\n","./base/MResourcePkg.cpp",
             "U8* MResourcePkg::GetSTR(U32, U8*, U32, U32, U32*, const char*)",0x261);
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  return iVar1;
}

