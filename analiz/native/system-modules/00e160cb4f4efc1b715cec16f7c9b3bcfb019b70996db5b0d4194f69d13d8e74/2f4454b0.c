
bool MDrv_AUTH_InitialVars(void)

{
  undefined *puVar1;
  bool bVar2;
  int iVar3;
  
  puVar1 = PTR_g_IpAuthVars_2f4570cc;
  if (*(int *)PTR_g_IpAuthVars_2f4570cc == 0) {
    iVar3 = (*(code *)PTR_MDrv_AUTH_AllocateVars_2f4570f0)();
    *(int *)puVar1 = iVar3;
    bVar2 = iVar3 != 0;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}

