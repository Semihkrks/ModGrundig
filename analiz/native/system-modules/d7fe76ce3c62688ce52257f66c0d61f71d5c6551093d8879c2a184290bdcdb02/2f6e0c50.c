
undefined4 dlopen(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint unaff_retaddr;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  if (*(undefined4 **)PTR__dlfcn_hook_2f6f2018 == (undefined4 *)0x0) {
    local_c = unaff_retaddr & 0xfffffffe;
    local_18 = param_1;
    local_14 = param_2;
    iVar1 = (*(code *)PTR_FUN_2f6f201c)(PTR___DT_MIPS_BASE_ADDRESS_2f6f2014 + 0xcec,&local_18);
    uVar2 = 0;
    if (iVar1 == 0) {
      return local_10;
    }
  }
  else {
    uVar2 = (*(code *)**(undefined4 **)PTR__dlfcn_hook_2f6f2018)
                      (param_1,param_2,unaff_retaddr & 0xfffffffe);
  }
  return uVar2;
}

