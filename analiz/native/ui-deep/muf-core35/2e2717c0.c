
/* GetRcEngine::RcGetString(unsigned int) */

void GetRcEngine::RcGetString(uint param_1)

{
  if (pkg != (MResourcePkg *)0x0) {
    MResourcePkg::GetString(pkg,param_1);
    return;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/Resource.cpp",
         "static char* GetRcEngine::RcGetString(unsigned int)",0x9f);
                    /* WARNING: Subroutine does not return */
  abort();
}

