
/* MResourcePkg::BuildImgPathIndex() */

void __thiscall MResourcePkg::BuildImgPathIndex(MResourcePkg *this)

{
  ulong *puVar1;
  
  puVar1 = operator_new__(*(int *)(this + 0x14) << 2,(nothrow_t *)&DAT_2c7f5bd0);
  *(ulong **)(this + 0x78) = puVar1;
  if (puVar1 != (ulong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x2e2406f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    BuildIndex(this,puVar1,*(ulong *)(this + 0x14),*(uchar **)(this + 0x44));
    return;
  }
  puts("fail to new imgpath_idx memory");
  printf("ASSERT FAIL: %s %s %d\n","./base/MResourcePkg.cpp",
         "BOOL MResourcePkg::BuildImgPathIndex()",0x43c);
                    /* WARNING: Subroutine does not return */
  abort();
}

