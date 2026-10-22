
/* WARNING: Removing unreachable block (ram,0x2e23c898) */
/* MResourceManager::DoRenderImageToSurface(MImg&, _IDirectFBSurface**, unsigned long&) */

undefined4 __thiscall
MResourceManager::DoRenderImageToSurface
          (MResourceManager *this,MImg *param_1,_IDirectFBSurface **param_2,ulong *param_3)

{
  int iVar1;
  int iVar2;
  char *__s;
  FILE *__stream;
  size_t sVar3;
  int iVar4;
  _IDirectFBSurface *p_Var5;
  long local_74;
  void *local_70;
  size_t local_6c;
  char *local_68;
  uint local_64;
  uint local_60 [3];
  size_t local_54;
  
  iVar1 = MSystem::GetInstance();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
           "BOOL MResourceManager::DoRenderImageToSurface(MImg&, IDirectFBSurface**, U32&)",0x283);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar2 = MImg::QueryFlag(param_1,'\x02');
  if (iVar2 == 0) {
    iVar2 = GetDFBImage(this,param_1,param_3);
    if (iVar2 != 0) {
      iVar4 = (**(code **)(iVar2 + 0x10))(iVar2,local_60);
      if (iVar4 == 0) {
        local_60[0] = local_60[0] | 1;
        local_60[1] = 4;
        iVar1 = (**(code **)(iVar1 + 0x20))(iVar1,local_60,param_2);
        if (iVar1 == 0) {
          iVar1 = (**(code **)(iVar2 + 0x18))(iVar2,*param_2,0);
          if (iVar1 == 0) {
            (**(code **)(iVar2 + 0xc))(iVar2);
            return 1;
          }
          (**(code **)(iVar2 + 0xc))(iVar2);
          (**(code **)(*param_2 + 0xc))();
          *param_2 = (_IDirectFBSurface *)0x0;
          return 0;
        }
      }
      (**(code **)(iVar2 + 0xc))(iVar2);
      return 0;
    }
  }
  else {
    local_68 = (char *)0x2c828ac4;
    local_64 = 0xffffffff;
                    /* try { // try from 2e23c4c4 to 2e23c58f has its CatchHandler @ 2e23c874 */
    iVar2 = MImg::QueryFlag(param_1,'\x01');
    if (iVar2 == 0) {
                    /* try { // try from 2e23c6a8 to 2e23c78b has its CatchHandler @ 2e23c874 */
      std::string::assign((string *)&local_68);
    }
    else {
      __s = (char *)GetRcEngine::RcGetImage((uint)*(ushort *)param_1,&local_64);
      strlen(__s);
      std::string::assign((char *)&local_68,(uint)__s);
    }
    *param_3 = local_64;
    __stream = fopen(local_68,"r");
    if (__stream != (FILE *)0x0) {
      memset(local_60,0,0x3c);
      sVar3 = fread(&local_74,4,1,__stream);
      if (((sVar3 == 1) && (iVar2 = fseek(__stream,local_74,1), iVar2 == 0)) &&
         (sVar3 = fread(local_60,0x3c,1,__stream), sVar3 == 1)) {
        (**(code **)(iVar1 + 0x20))(iVar1,local_60,param_2);
        p_Var5 = *param_2;
        if (p_Var5 != (_IDirectFBSurface *)0x0) {
          (**(code **)(p_Var5 + 0x48))(p_Var5,0,0,0,0);
          iVar1 = (**(code **)(*param_2 + 0x34))(*param_2,2,&local_70,&local_6c);
          if (iVar1 == 0) {
            if (((local_6c != 0) && (0 < (int)local_54)) &&
               (sVar3 = fread(local_70,local_6c,local_54,__stream), sVar3 == local_54)) {
                    /* try { // try from 2e23c840 to 2e23c857 has its CatchHandler @ 2e23c874 */
              (**(code **)(*param_2 + 0x3c))();
              fclose(__stream);
              std::string::~string((string *)&local_68);
              return 1;
            }
            (**(code **)(*param_2 + 0x3c))();
          }
        }
      }
      fclose(__stream);
    }
    if ((allocator *)(local_68 + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar1 = *(int *)(local_68 + -4);
      *(int *)(local_68 + -4) = iVar1 + -1;
      SYNC(0);
      if (iVar1 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_68 + -0xc));
        return 0;
      }
    }
  }
  return 0;
}

