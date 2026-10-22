
/* GetRcEngine::RcGetColor(unsigned int) */

void GetRcEngine::RcGetColor(uint param_1)

{
  if (pkg != (MResourcePkg *)0x0) {
    MResourcePkg::GetColor(pkg,param_1);
    return;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/Resource.cpp",
         "static unsigned int GetRcEngine::RcGetColor(unsigned int)",0xa7);
                    /* WARNING: Subroutine does not return */
  abort();
}

