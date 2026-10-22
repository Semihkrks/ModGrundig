
undefined4 dlopen(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint unaff_retaddr;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  
  local_14 = param_2;
  if ((param_2 & 3) == 0) {
    local_14 = param_2 | 1;
  }
  local_c = unaff_retaddr & 0xfffffffe;
  local_18 = param_1;
  if (*(undefined4 **)PTR__dlfcn_hook_2f6f2018 == (undefined4 *)0x0) {
    iVar1 = (*(code *)PTR_FUN_2f6f201c)(PTR___DT_MIPS_BASE_ADDRESS_2f6f2014 + 0x1ac0,&local_18);
    uVar2 = 0;
    if (iVar1 == 0) {
      return local_10;
    }
  }
  else {
    uVar2 = (*(code *)**(undefined4 **)PTR__dlfcn_hook_2f6f2018)(param_1,local_14);
  }
  return uVar2;
}

