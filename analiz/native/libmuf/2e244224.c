
/* MResourcePkg::ChangetRcDir(char const*) */

undefined4 MResourcePkg::ChangetRcDir(char *param_1)

{
  int in_t9;
  code *pcVar1;
  
  pcVar1 = *(code **)(in_t9 + 0x6fc98);
  param_1[0x2c] = '\x01';
  (*pcVar1)();
  param_1[0x2c] = '\0';
  return 1;
}

