
/* WARNING: Removing unreachable block (ram,0x2e23ba48) */
/* MResourceManager::GetDFBImage(unsigned long, unsigned long&) */

undefined4 __thiscall
MResourceManager::GetDFBImage(MResourceManager *this,ulong param_1,ulong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 local_2c;
  ulong local_28 [2];
  int local_20;
  
  local_20 = 0x2c828ac4;
                    /* try { // try from 2e23b948 to 2e23b9f3 has its CatchHandler @ 2e23ba58 */
  iVar1 = MSystem::GetInstance();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 != 0) {
    local_2c = 0;
    uVar2 = GetRcEngine::RcGetImage(param_1,local_28);
    pcVar3 = *(code **)(iVar1 + 0x48);
    *param_2 = local_28[0];
    iVar1 = (*pcVar3)(iVar1,uVar2,&local_2c);
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = local_2c;
    }
    if ((allocator *)(local_20 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar1 = *(int *)(local_20 + -4);
      *(int *)(local_20 + -4) = iVar1 + -1;
      SYNC(0);
      if (iVar1 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_20 + -0xc));
      }
    }
    return uVar2;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
         "IDirectFBImageProvider* MResourceManager::GetDFBImage(U32, U32&)",0x4c9);
                    /* WARNING: Subroutine does not return */
  abort();
}

