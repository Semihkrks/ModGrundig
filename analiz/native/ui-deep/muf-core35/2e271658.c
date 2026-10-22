
/* GetRcEngine::RcGetImage(unsigned int, unsigned int*) */

int GetRcEngine::RcGetImage(uint param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (pkg == (MResourcePkg *)0x0) {
    uVar3 = 0xad;
  }
  else {
    iVar1 = MResourcePkg::GetImgPath(pkg,param_1);
    uVar2 = MResourcePkg::GetColorKey(pkg,param_1);
    if (param_2 != (uint *)0x0) {
      *param_2 = uVar2;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = 0xb3;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/Resource.cpp",
         "static char* GetRcEngine::RcGetImage(unsigned int, unsigned int*)",uVar3);
                    /* WARNING: Subroutine does not return */
  abort();
}

