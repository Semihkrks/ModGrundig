
/* MSrv_MediaBrowser::UpdateFolderDB(MSrv_MediaDatabase*) */

undefined4 __thiscall
MSrv_MediaBrowser::UpdateFolderDB(MSrv_MediaBrowser *this,MSrv_MediaDatabase *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != (MSrv_MediaDatabase *)0x0) && (*(int *)(this + 0xf8) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x2e3a82a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_UpdateFolderDB_2e40f6a8)();
    return uVar1;
  }
  return 0;
}

