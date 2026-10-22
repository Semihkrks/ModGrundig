
/* ArResourceManager::GetOSDBrandName() */

ArResourceManager * __thiscall ArResourceManager::GetOSDBrandName(ArResourceManager *this)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_getInstance_010cc8bc)();
  iVar2 = (*(code *)PTR_ArTvConf_GetOsdSelection_010cba28)(uVar1);
  (*(code *)PTR_string_010ccce8)(this,PTR_brandName_010c800c + iVar2 * 4);
  return this;
}

