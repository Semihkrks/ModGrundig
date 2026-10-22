
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* factoryapi_switchToMAIN() */

void factoryapi_switchToMAIN(void)

{
  undefined4 uVar1;
  int in_t9;
  
  uVar1 = (**(code **)(in_t9 + 0xc0fe14))();
  (**(code **)(in_t9 + 0xc0eb9c))(uVar1,6,0);
  return;
}

