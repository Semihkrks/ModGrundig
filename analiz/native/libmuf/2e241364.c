
/* MResourcePkg::SetInitialRcDir(char const*) */

undefined4 MResourcePkg::SetInitialRcDir(char *param_1)

{
  undefined4 uVar1;
  int in_t9;
  
  uVar1 = (**(code **)(in_t9 + 0x73610))();
  (**(code **)(in_t9 + 0x737d8))(*(int *)(in_t9 + 0x72594) + 0x3a90,param_1,uVar1);
  return 1;
}

