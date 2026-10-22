
/* MResourcePkg::BuildFontPathIndex() */

void __thiscall MResourcePkg::BuildFontPathIndex(MResourcePkg *this)

{
  ulong *puVar1;
  
  puVar1 = operator_new__(*(int *)(this + 0x10) << 2,(nothrow_t *)&DAT_2c7f5bd0);
  *(ulong **)(this + 0x74) = puVar1;
  if (puVar1 != (ulong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    BuildIndex(this,puVar1,*(ulong *)(this + 0x10),*(uchar **)(this + 0x40));
    return;
  }
  puts("fail to new fontpath_idx memory");
  printf("ASSERT FAIL: %s %s %d\n","./base/MResourcePkg.cpp",
         "BOOL MResourcePkg::BuildFontPathIndex()",0x42d);
                    /* WARNING: Subroutine does not return */
  abort();
}

