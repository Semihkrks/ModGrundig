
/* ArResourceManager::GetOSDBrandName() */

ArResourceManager * __thiscall ArResourceManager::GetOSDBrandName(ArResourceManager *this)

{
  undefined4 uVar1;
  int iVar2;
  int in_t9;
  
  uVar1 = (**(code **)(in_t9 + 0xaa74e0))();
  iVar2 = (**(code **)(in_t9 + 0xaa664c))(uVar1);
  (**(code **)(in_t9 + 0xaa790c))(this,iVar2 * 4 + *(int *)(in_t9 + 0xaa2c30));
  return this;
}

