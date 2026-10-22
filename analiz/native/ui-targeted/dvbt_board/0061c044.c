
/* ArResourceManager::SetOSDLanguageRCPath() */

undefined4 ArResourceManager::SetOSDLanguageRCPath(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_GetOSDLanguage_010cc6cc)();
  (*(code *)PTR_SetOSDLanguageRCPath_010ca1b0)(uVar1);
  return 1;
}

