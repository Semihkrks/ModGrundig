
/* WARNING: Removing unreachable block (ram,0x2e23b8ac) */
/* WARNING: Removing unreachable block (ram,0x2e23b8bc) */
/* MResourceManager::GetDFBImage(MImg const&, unsigned long&) const */

undefined4 __thiscall
MResourceManager::GetDFBImage(MResourceManager *this,MImg *param_1,ulong *param_2)

{
  int iVar1;
  int iVar2;
  char *__s;
  undefined4 uVar3;
  undefined4 local_38;
  int local_34;
  uint local_30 [2];
  int local_28;
  
  local_28 = 0x2c828ac4;
                    /* try { // try from 2e23b6cc to 2e23b6d3 has its CatchHandler @ 2e23b8cc */
  iVar1 = MSystem::GetInstance();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 != 0) {
    local_30[0] = 0xffffffff;
    local_38 = 0;
    local_34 = 0x2c828ac4;
                    /* try { // try from 2e23b6fc to 2e23b7e7 has its CatchHandler @ 2e23b8f0 */
    iVar2 = MImg::QueryFlag(param_1,'\x01');
    if (iVar2 == 0) {
      std::string::assign((string *)&local_34);
    }
    else {
      __s = (char *)GetRcEngine::RcGetImage((uint)*(ushort *)param_1,local_30);
      strlen(__s);
      std::string::assign((char *)&local_34,(uint)__s);
    }
    iVar2 = *(int *)(local_34 + -0xc);
    *param_2 = local_30[0];
    uVar3 = 0;
    if ((iVar2 != 0) && (iVar1 = (**(code **)(iVar1 + 0x48))(iVar1,local_34,&local_38), iVar1 == 0))
    {
      uVar3 = local_38;
    }
    if ((allocator *)(local_34 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar1 = *(int *)(local_34 + -4);
      *(int *)(local_34 + -4) = iVar1 + -1;
      SYNC(0);
      if (iVar1 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_34 + -0xc));
      }
    }
    if ((allocator *)(local_28 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar1 = *(int *)(local_28 + -4);
      *(int *)(local_28 + -4) = iVar1 + -1;
      SYNC(0);
      if (iVar1 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_28 + -0xc));
      }
    }
    return uVar3;
  }
                    /* try { // try from 2e23b80c to 2e23b813 has its CatchHandler @ 2e23b8cc */
  printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
         "IDirectFBImageProvider* MResourceManager::GetDFBImage(const MImg&, U32&) const",0x4f5);
                    /* WARNING: Subroutine does not return */
  abort();
}

