
/* MResourceManager::DoRenderImageToSurface(unsigned long, _IDirectFBSurface**, unsigned long&) */

undefined4 __thiscall
MResourceManager::DoRenderImageToSurface
          (MResourceManager *this,ulong param_1,_IDirectFBSurface **param_2,ulong *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_58 [16];
  
  iVar1 = MSystem::GetInstance();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
           "BOOL MResourceManager::DoRenderImageToSurface(U32, IDirectFBSurface**, U32&)",0x23e);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar2 = GetDFBImage(this,param_1,param_3);
  if (iVar2 != 0) {
    iVar3 = (**(code **)(iVar2 + 0x10))(iVar2,local_58);
    if (iVar3 == 0) {
      local_58[0] = local_58[0] | 1;
      local_58[1] = 4;
      iVar1 = (**(code **)(iVar1 + 0x20))(iVar1,local_58,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(iVar2 + 0x18))(iVar2,*param_2,0);
        if (iVar1 != 0) {
          (**(code **)(iVar2 + 0xc))(iVar2);
          (**(code **)(*param_2 + 0xc))();
          *param_2 = (_IDirectFBSurface *)0x0;
          return 0;
        }
        (**(code **)(iVar2 + 0xc))(iVar2);
        return 1;
      }
    }
    (**(code **)(iVar2 + 0xc))(iVar2);
  }
  return 0;
}

