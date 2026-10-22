
/* MSrv_DTV_Player_DVBC_Customer::GetDefaultNetworkID() */

undefined2 MSrv_DTV_Player_DVBC_Customer::GetDefaultNetworkID(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_GetMSrvSystemDatabase_2ee3642c)();
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR___dynamic_cast_2ee36314)
                      (iVar1,PTR_typeinfo_2ee369ac,PTR_typeinfo_2ee363b4,0);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_GetCableInstallationOperator_2ee3656c)(iVar1);
      iVar4 = 0;
      piVar3 = (int *)PTR_astDefaultOperatorNID_2ee35d70;
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 2;
        if (iVar1 == iVar2) {
          return *(undefined2 *)(PTR_astDefaultOperatorNID_2ee35d70 + iVar4 * 8 + 4);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 6);
      return 0;
    }
  }
  (*(code *)PTR_puts_2ee36008)(PTR_typeinfo_name_0x10_2ee35cf8 + -0x4d0);
  return 0;
}

