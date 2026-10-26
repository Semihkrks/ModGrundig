
/* GetRcEngine::RcGetFont(unsigned int, unsigned int*) */

void GetRcEngine::RcGetFont(uint param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (pkg == (MResourcePkg *)0x0) {
    uVar2 = 0xc3;
  }
  else {
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
    iVar1 = MResourcePkg::GetFontPath(pkg,param_1);
    if (iVar1 != 0) {
      return;
    }
    uVar2 = 0xca;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/Resource.cpp",
         "static char* GetRcEngine::RcGetFont(unsigned int, unsigned int*)",uVar2);
                    /* WARNING: Subroutine does not return */
  abort();
}

