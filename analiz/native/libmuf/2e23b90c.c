
/* MResourceManager::GetDFBImage(unsigned long, unsigned long&) */

undefined4 __thiscall
MResourceManager::GetDFBImage(MResourceManager *this,ulong param_1,ulong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_t9;
  code *pcVar5;
  undefined4 local_2c;
  ulong local_28 [2];
  int local_20;
  
  iVar4 = *(int *)(in_t9 + 0x79384);
  local_20 = iVar4 + 0xc;
                    /* try { // try from 2e23b948 to 2e23b9f3 has its CatchHandler @ 2e23ba58 */
  iVar1 = (**(code **)(in_t9 + 0x7804c))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == 0) {
    iVar3 = *(int *)(in_t9 + 0x77ffc) + -0x73a0;
    (**(code **)(in_t9 + 0x785d4))
              (iVar3,*(int *)(in_t9 + 0x77ffc) + -0x5610,*(int *)(in_t9 + 0x77ffc) + -0x5524,0x4c9);
    iVar1 = (**(code **)(in_t9 + 0x782bc))();
    uVar2 = 0;
  }
  else {
    local_2c = 0;
    uVar2 = (**(code **)(in_t9 + 0x78e60))(param_1,local_28);
    pcVar5 = *(code **)(iVar1 + 0x48);
    *param_2 = local_28[0];
    iVar1 = (*pcVar5)(iVar1,uVar2,&local_2c);
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = local_2c;
    }
    iVar3 = local_20 + -0xc;
    iVar1 = *(int *)(in_t9 + 0x7928c);
    if (iVar4 == iVar3) {
      return uVar2;
    }
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar3 + 8);
    *(int *)(iVar3 + 8) = iVar1 + -1;
  }
  else {
    SYNC(0);
    iVar1 = *(int *)(iVar3 + 8);
    *(int *)(iVar3 + 8) = iVar1 + -1;
    SYNC(0);
  }
  if (iVar1 < 1) {
    (**(code **)(in_t9 + 0x78dcc))();
  }
  return uVar2;
}

