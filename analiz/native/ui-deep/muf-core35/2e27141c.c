
/* GetRcEngine::RcGetNum(unsigned int) */

void GetRcEngine::RcGetNum(uint param_1)

{
  if (pkg != (MResourcePkg *)0x0) {
    MResourcePkg::GetNum(pkg,param_1);
    return;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/Resource.cpp",
         "static int GetRcEngine::RcGetNum(unsigned int)",0xd6);
                    /* WARNING: Subroutine does not return */
  abort();
}

