
/* MResourceManager::GetDFBImage(MImg const&, unsigned long&) const */

int __thiscall MResourceManager::GetDFBImage(MResourceManager *this,MImg *param_1,ulong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_t9;
  undefined1 auStack_40 [8];
  int local_38;
  int local_34;
  ulong local_30 [2];
  int local_28;
  
  iVar6 = *(int *)(in_t9 + 0x79608);
  iVar5 = iVar6 + 0xc;
  local_28 = iVar5;
                    /* try { // try from 2e23b6cc to 2e23b6d3 has its CatchHandler @ 2e23b8cc */
  iVar1 = (**(code **)(in_t9 + 0x782d0))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    iVar4 = *(int *)(in_t9 + 0x78280) + -0x73a0;
                    /* try { // try from 2e23b80c to 2e23b813 has its CatchHandler @ 2e23b8cc */
    (**(code **)(in_t9 + 0x78858))
              (iVar4,*(int *)(in_t9 + 0x78280) + -0x5610,*(int *)(in_t9 + 0x78280) + -0x5574,0x4f5);
    iVar1 = (**(code **)(in_t9 + 0x78540))();
  }
  else {
    local_30[0] = 0xffffffff;
    local_38 = 0;
    local_34 = iVar5;
                    /* try { // try from 2e23b6fc to 2e23b7e7 has its CatchHandler @ 2e23b8f0 */
    iVar5 = (**(code **)(in_t9 + 0x7852c))(param_1,1);
    if (iVar5 == 0) {
      (**(code **)(in_t9 + 0x78a88))(&local_34,param_1 + 4);
    }
    else {
      uVar2 = (**(code **)(in_t9 + 0x790e4))(*(undefined2 *)param_1,local_30);
      uVar3 = (**(code **)(in_t9 + 0x792ec))(uVar2);
      (**(code **)(in_t9 + 0x794b4))(&local_34,uVar2,uVar3);
    }
    iVar4 = *(int *)(local_34 + -0xc);
    *param_2 = local_30[0];
    iVar5 = 0;
    if ((iVar4 != 0) && (iVar1 = (**(code **)(iVar1 + 0x48))(iVar1,local_34,&local_38), iVar1 == 0))
    {
      iVar5 = local_38;
    }
    if (iVar6 != local_34 + -0xc) {
      if (*(int *)(in_t9 + 0x79510) == 0) {
        iVar1 = *(int *)(local_34 + -4);
        *(int *)(local_34 + -4) = iVar1 + -1;
      }
      else {
        SYNC(0);
        iVar1 = *(int *)(local_34 + -4);
        *(int *)(local_34 + -4) = iVar1 + -1;
        SYNC(0);
      }
      if (iVar1 < 1) {
        (**(code **)(in_t9 + 0x79050))(local_34 + -0xc,auStack_40);
      }
    }
    iVar4 = local_28 + -0xc;
    iVar1 = *(int *)(in_t9 + 0x79510);
    if (iVar6 == iVar4) {
      return iVar5;
    }
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar4 + 8);
    *(int *)(iVar4 + 8) = iVar1 + -1;
  }
  else {
    SYNC(0);
    iVar1 = *(int *)(iVar4 + 8);
    *(int *)(iVar4 + 8) = iVar1 + -1;
    SYNC(0);
  }
  if (iVar1 < 1) {
    (**(code **)(in_t9 + 0x79050))();
  }
  return iVar5;
}

