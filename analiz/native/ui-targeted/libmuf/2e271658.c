
/* GetRcEngine::RcGetImage(unsigned int, unsigned int*) */

int GetRcEngine::RcGetImage(uint param_1,uint *param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_pkg_2e2b3a44;
  if (*(int *)PTR_pkg_2e2b3a44 == 0) {
    uVar4 = 0xad;
    goto LAB_2e271700;
  }
  iVar2 = (*(code *)PTR_GetImgPath_2e2b45b8)(*(int *)PTR_pkg_2e2b3a44,param_1);
  uVar3 = (*(code *)PTR_GetColorKey_2e2b49d4)(*(undefined4 *)puVar1,param_1);
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar3;
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  do {
    uVar4 = 0xb3;
LAB_2e271700:
    (*(code *)PTR_printf_2e2b3ee0)
              (PTR_PTR_2e2b3908 + -0x73a0,PTR_PTR_2e2b3908 + -0x228c,PTR_PTR_2e2b3908 + -0x20f4,
               uVar4);
    (*(code *)PTR_abort_2e2b3bc8)();
  } while( true );
}

