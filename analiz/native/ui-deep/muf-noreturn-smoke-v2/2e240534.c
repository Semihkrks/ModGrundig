
/* MResourcePkg::BuildIndex(unsigned long*, unsigned long, unsigned char*) */

undefined4 __thiscall
MResourcePkg::BuildIndex(MResourcePkg *this,ulong *param_1,ulong param_2,uchar *param_3)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != (ulong *)0x0) && (param_3 != (uchar *)0x0)) {
    if (param_2 != 0) {
      uVar1 = 0;
      iVar2 = 0;
      while( true ) {
        iVar3 = *(int *)(param_3 + uVar1);
        if (iVar3 == 0) {
          *param_1 = uVar1;
        }
        else {
          *param_1 = uVar1 + 4;
        }
        if (param_2 <= iVar2 + 1U) break;
        param_1 = param_1 + 1;
        iVar2 = iVar2 + 1;
        uVar1 = uVar1 + iVar3 + 4;
      }
    }
    return 1;
  }
  (*(code *)PTR_printf_2e2b3ee0)
            (PTR_PTR_2e2b3908 + -0x73a0,PTR_PTR_2e2b3908 + -0x51fc,PTR_PTR_2e2b3908 + -0x4d90,0x400)
  ;
                    /* WARNING: Subroutine does not return */
  (*(code *)PTR_abort_2e2b3bc8)();
}

