
/* ArResourceManager::LoadKeyboardKeymap(char*) */

undefined4 __thiscall ArResourceManager::LoadKeyboardKeymap(ArResourceManager *this,char *param_1)

{
  int iVar1;
  int in_t9;
  int iStack_1c;
  int aiStack_14 [3];
  
  iVar1 = (**(code **)(in_t9 + 0xab2838))();
  iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 0x3c))(*(int *)(iVar1 + 4),0x11,aiStack_14);
  if (iVar1 == 0) {
    if (aiStack_14[0] == 0) {
      iStack_1c = 1;
    }
    else {
      iStack_1c = (**(code **)(aiStack_14[0] + 0x20))(aiStack_14[0],param_1);
    }
    if (iStack_1c == 0) {
      if (aiStack_14[0] != 0) {
        (**(code **)(aiStack_14[0] + 0xc))(aiStack_14[0]);
      }
    }
    else {
      (**(code **)(in_t9 + 0xaadb34))(*(int *)(in_t9 + 0xaaa824) + -0x611c,iStack_1c);
    }
  }
  else {
    (**(code **)(in_t9 + 0xaadb34))(*(int *)(in_t9 + 0xaaa824) + -0x6134,iVar1);
  }
  return 0;
}

