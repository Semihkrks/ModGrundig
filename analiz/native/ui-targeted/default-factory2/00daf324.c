
/* MAppFactory::GetDefault() */

MAppFactory * MAppFactory::GetDefault(void)

{
  int iVar1;
  MAppFactory *pMStack_18;
  
  pMStack_18 = root;
  while( true ) {
    if (pMStack_18 == (MAppFactory *)0x0) {
      return root;
    }
    iVar1 = (**(code **)(*(int *)pMStack_18 + 0xc))(pMStack_18);
    if (iVar1 != 0) break;
    pMStack_18 = (MAppFactory *)Next(pMStack_18);
  }
  return pMStack_18;
}

