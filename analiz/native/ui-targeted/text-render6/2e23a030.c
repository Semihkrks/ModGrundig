
/* MResourceManager::GetDFBFont(unsigned long, unsigned short, unsigned long) */

undefined4 __thiscall
MResourceManager::GetDFBFont(MResourceManager *this,ulong param_1,ushort param_2,ulong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_70;
  ulong local_6c;
  ulong local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  ulong local_58;
  uint local_54;
  uint local_50;
  undefined4 local_34;
  
  uVar1 = (uint)param_2;
  uVar2 = GetRcEngine::RcGetImage(param_1,(uint *)0x0);
  puVar7 = *(undefined4 **)this;
  uVar5 = (*(int *)(this + 4) - (int)puVar7 >> 2) * -0x33333333;
  if (uVar5 != 0) {
    uVar6 = 0;
    do {
      if ((((puVar7[1] == param_1) && (*(ushort *)(puVar7 + 4) == uVar1)) && (puVar7[3] == 0)) &&
         ((puVar7[2] == param_3 && (*(short *)((int)puVar7 + 0x12) == 5)))) {
        return *puVar7;
      }
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 5;
    } while (uVar6 < uVar5);
  }
  iVar3 = MSystem::GetInstance();
  iVar3 = *(int *)(iVar3 + 4);
  if (iVar3 == 0) {
    printf("ASSERT FAIL: %s %s %d\n","./base/MResourceManager.cpp",
           "IDirectFBFont* MResourceManager::GetDFBFont(U32, U16, U32)",0xea);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  iVar4 = MSystem::GetInstance();
  uVar5 = (uint)*(byte *)(iVar4 + 0x204);
  local_58 = param_3;
  local_54 = uVar1;
  if ((uVar5 == 100) || (uVar5 == 0)) {
    local_5c = 0x203;
    local_34 = 5;
    iVar3 = (**(code **)(iVar3 + 0x50))(iVar3,uVar2,&local_5c,&local_70);
  }
  else {
    local_5c = 0x207;
    local_34 = 5;
    local_50 = (uint)((ulonglong)((longlong)(int)(uVar1 * uVar5) * 0x51eb851f) >> 0x25);
    iVar3 = (**(code **)(iVar3 + 0x50))(iVar3,uVar2,&local_5c,&local_70);
  }
  if (iVar3 != 0) {
    return 0;
  }
  puVar7 = *(undefined4 **)(this + 4);
  local_60 = CONCAT22(5,param_2);
  local_64 = 0;
  if (puVar7 == *(undefined4 **)(this + 8)) {
    local_6c = param_1;
    local_68 = param_3;
    std::vector<RcFont,std::allocator<RcFont>>::_M_insert_aux
              ((vector<RcFont,std::allocator<RcFont>> *)this,puVar7,&local_70);
  }
  else {
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[1] = param_1;
      *puVar7 = local_70;
      puVar7[2] = param_3;
      puVar7[4] = local_60;
      puVar7[3] = 0;
    }
    *(undefined4 **)(this + 4) = puVar7 + 5;
  }
  return local_70;
}

