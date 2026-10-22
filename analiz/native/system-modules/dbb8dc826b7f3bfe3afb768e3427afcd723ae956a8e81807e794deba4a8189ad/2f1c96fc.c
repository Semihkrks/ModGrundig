
/* MSrv_Control_Customer::SetMbootUpgradeComplete(unsigned char) */

undefined4 __thiscall
MSrv_Control_Customer::SetMbootUpgradeComplete(MSrv_Control_Customer *this,uchar param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  piVar1 = (int *)(*(code *)PTR_Instance_2f1e3538)();
  if (param_1 == '\0') {
    puVar3 = PTR_LAB_2f1e34b4 + 0x6cc;
  }
  else {
    puVar3 = PTR_LAB_2f1e34b4 + 0x6d0;
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,PTR_LAB_2f1e34b4 + 0x6d4,puVar3);
    if (iVar2 != 0) {
      (*(code *)PTR_printf_2f1e36c0)
                (PTR_LAB_2f1e34b4 + 0x6ec,PTR_LAB_2f1e34b4 + 0x1418,0x711,param_1);
      (**(code **)(*piVar1 + 0xc))(piVar1);
      return 1;
    }
  }
  return 0;
}

